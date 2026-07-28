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
/*!        \file TcpIp_Tls_Types.h
 *        \brief Transport Layer Security (TLS) types header file.
 *
 *      \details This file is part of the TcpIp TLS submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#if !defined (TCPIP_TLS_TYPES_H)
# define TCPIP_TLS_TYPES_H

# include "TcpIp_Cfg.h"
# if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED */
/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#  include "TcpIp_Types.h"
#  include "TcpIp_Priv_Types.h"
#  include "Std_Types.h"

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
#   include "KeyM.h"
#  endif

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

#  define TCPIP_TLS_UINT24_MAX 16777215u /* 2^24 -1 */




typedef uint16 TcpIp_TlsFunctionIdType;
#  define TCPIP_TLS_FCTID_NOT_SET                                      0xFFFFu
/* CORE FUNCTION IDS 0x0000 -  */
/* MAIN FUNCTION IDS 0x0000 - 0x0100 */
#  define TCPIP_TLS_FCTID_INVALID_CONFIG                               0x0000u
#  define TCPIP_TLS_FCTID_CORE_MAINFCT_RXRL                            0x0001u
#  define TCPIP_TLS_FCTID_CORE_MAINFCT_RXHS                            0x0002u
#  define TCPIP_TLS_FCTID_CORE_SA_READSECRET                           0x0003u
#  define TCPIP_TLS_FCTID_CORE_MAINFCT_CCS                             0x0004u
#  define TCPIP_TLS_FCTID_CORE_MAINFCT_AL                              0x0005u
/* RECORD LAYER FUNCTION IDS 0x0100 - 0x0200 */
#  define TCPIP_TLS_FCTID_CORE_RL_CHECKHDR                             0x0100u
#  define TCPIP_TLS_FCTID_CORE_RL_TRANSMIT                             0x0101u
#  define TCPIP_TLS_FCTID_CORE_RL_VERIFYHMACADHS                       0x0102u
#  define TCPIP_TLS_FCTID_CORE_RL_VERIFYHMACAL                         0x0103u
#  define TCPIP_TLS_FCTID_CORE_RL_RXHSADDATA                           0x0104u
/* HANDSHAKE LAYER FUNCTION IDS 0x0200 - 0x0300 */
#  define TCPIP_TLS_FCTID_CORE_CTHS_CHECKFRAMETYPE                     0x0200u
#  define TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_CLIENTHELLO               0x0201u
#  define TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_HS_MSG                    0x0202u
#  define TCPIP_TLS_FCTID_SERVER_HSSTM_PREPARE_SERVERHELLO             0x0203u
#  define TCPIP_TLS_FCTID_SERVER_HSSTM_PREPARE_HS_MSG                  0x0204u
#  define TCPIP_TLS_FCTID_SERVER_HSSTM_PREPARE_SERVERCERT_MSG          0x0205u
#  define TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_HS_MSG                    0x0206u
#  define TCPIP_TLS_FCTID_CLIENT_HSSTM_PREPARE_CLIENTHELLO             0x0207u
#  define TCPIP_TLS_FCTID_CLIENT_HSSTM_PREPARE_HS_MSG                  0x0208u
#  define TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERHELLO               0x0209u
#  define TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERCERT                0x020Au
#  define TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERKEYEXCH             0x020Bu
#  define TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERHELLODONE           0x020Cu
#  define TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERFINISHED            0x020Du
#  define TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_CLIENTKEYEXCHANGE         0x020Eu
#  define TCPIP_TLS_FCTID_CLIENT_HSSTM_RANDOM_NUM_GET_TIME             0x020Fu
#  define TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_CLIENTCERT                0x0210u
/* SERVER ASYNC CTX FUNCTION IDs 0x0300 - 0x0400 */
#  define TCPIP_TLS_FCTID_SERVER_ASYNCCTX_CALC_SIGN_PUBKEY             0x0300u
#  define TCPIP_TLS_FCTID_SERVER_ASYNCCTX_CALC_FINISHED_HASH           0x0301u
#  define TCPIP_TLS_FCTID_SERVER_ASYNCCTX_CALC_CLIENTFINISHED_HASH     0x0302u
#  define TCPIP_TLS_FCTID_SERVER_ASYNCCTX_CALC_CLIENTFINISHED_VERIFY   0x0303u
/* CRYPTO FUNCTION IDs 0x0400 - 0x0500 */
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_CALC_PSHA256                     0x0400u
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_CALC_HMAC                        0x0401u
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_CLEARCSMKEY                      0x0402u
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_GENERATEIVRANDOM                 0x0403u
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_SETAESIVVALUE                    0x0404u
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_CALCMASTERSECRET                 0x0405u
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_DERIVEKEYBLOCK                   0x0406u
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_ENCRYPTADHSBUFAES128CBC          0x0407u
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_ENCRYPTHMACPADDINGAES128CBC      0x0408u
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_REDUCEKEY                        0x0409u
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_ENCRYPTADHSBUFAEADBlock128       0x040Au
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_PSK_CALC_PREMASTERSECRET         0x040Bu
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_DECRYPTALBUFAES128CBC            0x040Cu
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_DECRYPTALBUFBLOCK128             0x040Du
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_HKDF_EXTRACTANDEXPAND            0x040Eu
/* REMOVED DECRYPTAES256GCM                                            0x040Eu */
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_ENCRYPTADHSBUFBLOCK128           0x040Fu
#  define TCPIP_TLS_FCTID_CORE_CRYPTO_PSK_CALC_RESUMPTIONMASTERSECRET  0x0410u
/* CRYPTO FUNCTION IDs SERVER 0x0500 - 0x0600 */
#  define TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYS                     0x0500u
#  define TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSAES128CBC            0x0501u
#  define TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSNULL                 0x0502u
#  define TCPIP_TLS_FCTID_SERVER_CRYPTO_CALCHSFINISHEDHASH             0x0503u
#  define TCPIP_TLS_FCTID_SERVER_CRYPTO_CALCHSFINISHEDDATA             0x0504u
#  define TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSAES128GCM            0x0505u
/* CRYPTO FUNCTION IDs CLIENT 0x0600 - 0x0700 */
#  define TCPIP_TLS_FCTID_CLIENT_CRYPTO_SETCSMKEYS                     0x0600u
#  define TCPIP_TLS_FCTID_CLIENT_CRYPTO_SETCSMKEYSAES128CBC            0x0601u
#  define TCPIP_TLS_FCTID_CLIENT_CRYPTO_SETCSMKEYSNULL                 0x0602u
#  define TCPIP_TLS_FCTID_CLIENT_CRYPTO_CALCHSHASH                     0x0603u
#  define TCPIP_TLS_FCTID_CLIENT_CRYPTO_CALCHSFINISHEDDATA             0x0604u
#  define TCPIP_TLS_FCTID_CLIENT_CRYPTO_SETCSMKEYSAEADBLOCK128         0x0605u
/* CLIENT ASYNC CTX FUNCTION IDs 0x700 - 0x0800 */
#  define TCPIP_TLS_FCTID_CLIENT_ASYNCCTX_VERIFY_SIGN_PUBKEY           0x0700u
#  define TCPIP_TLS_FCTID_CLIENT_ASYNCCTX_CALC_CLIENTFINISHED_HASH     0x0701u
#  define TCPIP_TLS_FCTID_CLIENT_ASYNCCTX_CALC_SERVERFINISHED_HASH     0x0702u
#  define TCPIP_TLS_FCTID_CLIENT_ASYNCCTX_CALC_SERVERFINISHED_VERIFY   0x0703u
#  define TCPIP_TLS_FCTID_CLIENT_ASYNCCTX_VALIDATE_CERT_STATUS         0x0704u
#  define TCPIP_TLS_FCTID_CLIENT_ASYNCCTX_CALC_CERTVERIFY_SIGN         0x0705u
/* CORE ASYNC CTX FUNCTION IDs 0x0800 - 0x0900 */
#  define TCPIP_TLS_FCTID_CORE_ASYNCCTX_CALC_DH_PUBKEY                 0x0800u
#  define TCPIP_TLS_FCTID_CORE_ASYNCCTX_CALC_DH_SHAREDSECRET           0x0801u
#  define TCPIP_TLS_FCTID_CORE_ASYNCCTX_CALC_MASTERSECRET              0x0802u
#  define TCPIP_TLS_FCTID_CORE_ASYNCCTX_CALC_PSKANDBINDER              0x0803u

typedef uint16 TcpIp_TlsUserErrorIdType;
/* GENERIC ERROR IDS 0x0000 - 0x0100 */
#  define TCPIP_TLS_ERRORID_INVALID_CONFIG                             0x0000u
#  define TCPIP_TLS_ERRORID_NOSPACEINBUF                               0x0001u
/* RECORD LAYER ERROR IDS 0x0100 - 0x0200 */
#  define TCPIP_TLS_ERRORID_RXINCORRECTRLFRAME                         0x0100u
#  define TCPIP_TLS_ERRORID_RL_INCORRECT_CT                            0x0101u
#  define TCPIP_TLS_ERRORID_RL_INCORRECT_MAJORVERSNR                   0x0102u
#  define TCPIP_TLS_ERRORID_RL_INCORRECT_MINORVERSNR                   0x0103u
#  define TCPIP_TLS_ERRORID_RL_TXHDR_FAILED                            0x0104u
#  define TCPIP_TLS_ERRORID_RL_CALCHMAC_FAILED                         0x0105u
#  define TCPIP_TLS_ERRORID_RL_TX_FAILED                               0x0106u
/* HANDSHAKE ERROR IDS 0x0200 - 0x0300 */
#  define TCPIP_TLS_ERRORID_RXINCORRECTHSMESSAGE                       0x0200u
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTFRAMETYPE                    0x0201u
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTMAJORVERSION                 0x0202u
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTMINORVERSION                 0x0203u
#  define TCPIP_TLS_ERRORID_CTHS_UNEXPECTEDMSGLEN                      0x0204u
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTHSMSG                        0x0205u
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTSESSIONID                    0x0206u
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTCIPHERLEN                    0x0207u
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTCOMPRESSIONLEN               0x0208u
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTEXTENSIONSLEN                0x0209u
#  define TCPIP_TLS_ERRORID_CTHS_NOMATCHINGCIPHER                      0x020Au
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTCOMPMETHOD                   0x020Bu
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTCURVEINFO                    0x020Cu
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTPUBKEYLEN                    0x020Du
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTSIGNLEN                      0x020Eu
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECTVERIFYDATA                   0x020Fu
#  define TCPIP_TLS_ERRORID_CTHS_NOPSKIDENTITYFOUND                    0x0210u
#  define TCPIP_TLS_ERRORID_CTHS_NOVALIDCIPHERFOUND                    0x0211u
#  define TCPIP_TLS_ERRORID_CTHS_PSKHINTTOLARGE                        0x0212u
#  define TCPIP_TLS_ERRORID_CTHS_PSKHINTNOTINRANGE                     0x0213u
#  define TCPIP_TLS_ERRORID_CTHS_PSKHINTMSGINVALIDLENGTH               0x0214u
#  define TCPIP_TLS_ERRORID_CTHS_INCORRECT_TIME                        0x0215u

/* APPLICATION DATA ERROR IDS 0x0300 - 0x0400 */
/* HEARTBEAT ERROR IDS 0x0500 - 0x05FF */
/* ALERT ERROR IDS 0x0600 - 0x06FF */
#  define TCPIP_TLS_ERRORID_ALERT_LENGTH_INVALID                       0x0600u
/* CRYPTO ERROR IDS 0x0700 - 0x0800 */
#  define TCPIP_TLS_ERRORID_CRYPTO_SET_VALID_FAILED                    0x0700u
#  define TCPIP_TLS_ERRORID_CRYPTO_CSM_CALL_FAILED                     0x0701u
#  define TCPIP_TLS_ERRORID_CRYPTO_CSM_LEN_MISMATCH                    0x0702u
#  define TCPIP_TLS_ERRORID_CRYPTO_CSM_CALC_PRF_FAILED                 0x0703u
#  define TCPIP_TLS_ERRORID_CRYPTO_REDUCESHAREDKEY_FAILED              0x0704u
#  define TCPIP_TLS_ERRORID_CRYPTO_CALCMASTERSECRET_FAILED             0x0705u
#  define TCPIP_TLS_ERRORID_CRYPTO_DERIVEKEYBLOCK_FAILED               0x0706u
#  define TCPIP_TLS_ERRORID_CRYPTO_SERVERFINISHED_HASH_FAILED          0x0707u
#  define TCPIP_TLS_ERRORID_CRYPTO_SERVERFINISHED_VERIFY_FAILED        0x0708u
#  define TCPIP_TLS_ERRORID_CRYPTO_CLIENTFINISHED_HASH_FAILED          0x0709u
#  define TCPIP_TLS_ERRORID_CRYPTO_CLIENTFINISHED_VERIFY_FAILED        0x070Au
#  define TCPIP_TLS_ERRORID_CRYPTO_SETCSMKEYS_FAILED                   0x070Bu
#  define TCPIP_TLS_ERRORID_CRYPTO_CALCHMAC_FAILED                     0x070Cu
#  define TCPIP_TLS_ERRORID_CRYPTO_CLEARCSMKEY_FAILED                  0x070Du
#  define TCPIP_TLS_ERRORID_CRYPTO_GENERATEIVRANDOM_FAILED             0x070Eu
#  define TCPIP_TLS_ERRORID_CRYPTO_SETAESIVVALUE_FAILED                0x070Fu
#  define TCPIP_TLS_ERRORID_CRYPTO_DERIVEKEYS_FAILED                   0x0710u
#  define TCPIP_TLS_ERRORID_CRYPTO_RANDOMGENERATE_FAILED               0x0711u
#  define TCPIP_TLS_ERRORID_CRYPTO_ENCRYPTION_FAILED                   0x0712u
#  define TCPIP_TLS_ERRORID_CRYPTO_MACVERIFY_FAILED                    0x0713u
#  define TCPIP_TLS_ERRORID_CRYPTO_REDUCEKEY_FAILED                    0x0714u
#  define TCPIP_TLS_ERRORID_CRYPTO_GENERATESIGNATURE_FAILED            0x0715u
#  define TCPIP_TLS_ERRORID_CRYPTO_CSM_KEYELEMENTSET_FAILED            0x0716u
#  define TCPIP_TLS_ERRORID_CRYPTO_CSM_KEYELEMENTCOPYPARTIAL_FAILED    0x0717u
#  define TCPIP_TLS_ERRORID_CRYPTO_CSM_KEYELEMENTCOPY_FAILED           0x0718u
#  define TCPIP_TLS_ERRORID_CRYPTO_CALCRESUMPTIONMASTERSECRET_FAILED   0x0719u
/* KEYM ERROR IDS 0x0900 - 0x0A00 */
#  define TCPIP_TLS_ERRORID_KEYM_GETCERTIFICATE_FAILED                 0x0900u
#  define TCPIP_TLS_ERRORID_KEYM_INVALIDCERTSTATUS                     0x0901u
#  define TCPIP_TLS_ERRORID_KEYM_GETCERTIFICATESTATUS_FAILED           0x0902u
#  define TCPIP_TLS_ERRORID_KEYM_SERVICE_OCSP_FAILED                   0x0903u
#  define TCPIP_TLS_ERRORID_KEYM_INVALIDOCSPSTATUS                     0x0904u

#  define TCPIP_TLS_ERRORID_NOT_SET                                    0xFFFFu

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
typedef struct
{
  uint32 KeyId; /* KeyId of the CsmKey */
  uint32 KeyElementId; /* KeyElementId of the crypto driver CryptoKeyElement */
  uint32 KeyLen;
} TcpIp_TlsCsmKeyInfoType;

typedef struct
{
  uint8* DataPtr; /* Pointer to the DataPtr of the first segment */
  uint16 DataLen; /* Length of the DataPtr of the first segment */
} TcpIp_TlsDataSplitType;

typedef TCPIP_P2V(uint8) TcpIp_TlsServerCertPtrType;

#  define TCPIP_TLS_CSM_INV_KEY_ID 0xFFFFFFFFu
#  define TCPIP_TLS_CSM_INV_JOB_ID 0xFFFFFFFFu

typedef void(*TcpIp_TlsGetRandomArrayType)(uint8* DestDataPtr, uint16 DestLen);

typedef struct
{
  TcpIp_TlsFunctionIdType FunctionId;    /* Identifies the function from which the error was reported */
  TcpIp_TlsUserErrorIdType UserErrorId;  /* Identifies the type of error */
  TcpIp_TlsConnectionIdType TlsConId;    /* Current connection on which the error occurred */
} TcpIp_TlsUserErrorType;                /* Used to report errors within the TLS module */

/* User callout function for TLS errors */
typedef void(*TcpIp_TlsUserErrorCalloutFunctionType)(uint32 TlsConIdx, uint32 UserErrorCnt);

/* Start of AsrTls types */


/* AsrTls Server/Client modes for the connection */
typedef enum  eTcpIp_TlsConnectionMode
{
  TCPIP_TLS_SERVER,
  TCPIP_TLS_CLIENT
} TcpIp_TlsConnectionMode; /* Used to determine the mode of the connection */


typedef enum  eTcpIp_TlsConnectionPrio
{
  TCPIP_TLS_CON_PRIO_INVALID = 0,
  TCPIP_TLS_CON_PRIO_FIFTH_HIGHEST,
  TCPIP_TLS_CON_PRIO_FOURTH_HIGHEST,
  TCPIP_TLS_CON_PRIO_THIRD_HIGHEST,
  TCPIP_TLS_CON_PRIO_SECOND_HIGHEST,
  TCPIP_TLS_CON_PRIO_HIGHEST
} TcpIp_TlsConnectionPrioType; /* Used to handle the TLS the selection of a TLS connection by priority via TcpIp_TlsServerListener_GetCurrentTlsConnectionPriority() and TcpIp_Tls12Client_GetCurrentTlsConnectionPriority(). */

/* AsrTls states for the connection */
typedef enum  eTcpIp_TlsConnectionState
{
  TCPIP_TLS_STATE_CONNECTION_HS_INACTIVE = 0u,
  TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE,                                                             /* TLS Handshake is in progress */
  TCPIP_TLS_STATE_CONNECTION_SERVER_HS_FINALIZING,                                                  /* (For TlsServer) TLS Client Finished generating and parsing is under process, but TLS application data could be received */
  TCPIP_TLS_STATE_CONNECTION_ESTABLISHED,                                                           /* Handshake is complete, TLS connection is established */
  TCPIP_TLS_STATE_CONNECTION_TCP_RESET_REQUESTED,                                                   /* TLS received the TCP event RST and the processing of this RST is requested */
  TCPIP_TLS_STATE_CONNECTION_TCP_RESET_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING,               /* Same as TCPIP_TLS_STATE_CONNECTION_TCP_RESET_REQUESTED but without forwarding the events to the upper layer (TLS-Server connection during HS) */
  TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED,                                        /* TLS should close the TCP connection gracefully - triggers FIN on TCP level */
  TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING,    /* Same as TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED but without forwarding the events to the upper layer (TLS-Server connection during HS) */
  TCPIP_TLS_STATE_CONNECTION_CLOSING,                                                               /* TLS Close requested and TLS connection is closing */
  TCPIP_TLS_STATE_CONNECTION_CLOSING_WITHOUT_UPPERLAYER_EVENT_FORWARDING,                           /* Same as TCPIP_TLS_STATE_CONNECTION_CLOSING but without forwarding the events to the upper layer (TLS-Server connection during HS) */
  TCPIP_TLS_STATE_CONNECTION_CLOSED,                                                                /* TLS connection is closed */
  TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT,                                                            /* TCP FIN received and TLS connection is waiting for user to decide how to close (TcpIp_Close()) */
  TCPIP_TLS_STATE_CONNECTION_CLOSE_WITH_CLOSENOTIFY_FIN_REQUESTED,                                  /* TLS connection should close by sending the CloseNotify alert and a TCP FIN */
  TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT,                                                      /* TLS connection waits until requested transmit of CloseNotify is processed */
  TCPIP_TLS_STATE_CONNECTION_USER_RESET_REQUESTED,                                                  /* User called TcpIp_Close with Abort=TRUE - triggers RST on TCP level */
  TCPIP_TLS_STATE_CONNECTION_USER_RESET_WAIT,                                                       /* TLS connection waits until requested transmit of RST is processed */
  TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CANCLED,                                                     /* Active TLS handshake should be canceled (Tls-Listener closed with Abort = TRUE) */
  TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CLOSED,                                                      /* Active TLS handshake should be closed (Tls-Listener closed with Abort = FALSE) */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_SENT,                                                   /* A CloseNotify Alert was sent. For TLS 1.3 connections it is still possible to receive data in this state until a CloseNotify Alert was received. */
  TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_RECEIVED,                                               /* A CloseNotify Alert was received. For TLS 1.3 connections it is still possible to send data in this state until a CloseNotify was sent. */
  TCPIP_TLS_STATE_CONNECTION_13_ACTIVE_CLOSE_REQUESTED,                                             /* An active Close was requested from the upper layer, no FIN will be sent. Next state is TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_SENT */
#  endif
  TCPIP_TLS_STATE_CONNECTION_ALLOCATED                                                              /* TLS connection is assigned to TCP socket, but TCP connection is not yet established */
} TcpIp_TlsConnectionState; /* States of the TLS connection */

typedef uint16 TcpIp_TlsEllipticCurveIdType;
#  define TCPIP_CURVE_ID_LEN        2u
#  define TCPIP_CURVE_ID_AMOUNT     5u       /* Amount of curve Ids currently known to the ECU. Must be updated once new defines are added below. */
#  define TCPIP_CURVE_ID_NO_CURVE   0x0000u  /* ( 0) */
#  define TCPIP_CURVE_ID_SECP256R1  0x0017u  /* (23) */
#  define TCPIP_CURVE_ID_SECP384R1  0x0018u  /* (24) */
#  define TCPIP_CURVE_ID_SECP521R1  0x0019u  /* (25) */
#  define TCPIP_CURVE_ID_X25519     0x001Du  /* (29) */
#  define TCPIP_CURVE_ID_X448       0x001Eu  /* (30) */

typedef enum  eTcpIp_TlsHashAlgorithmType
{
  TCPIP_HASH_ALGORITHM_NO_HASH = 0u,
  TCPIP_HASH_ALGORITHM_SHA256,
  TCPIP_HASH_ALGORITHM_SHA384,
} TcpIp_TlsHashAlgorithmType;

typedef enum  eTcpIp_TlsClientHsTriggerState
{
  TCPIP_TLS_CLIENTHSTRIGGER_INIT = 0u,
  TCPIP_TLS_CLIENTHSTRIGGER_TCPACK_SENDING,
  TCPIP_TLS_CLIENTHSTRIGGER_TCPACK_SENT,
  TCPIP_TLS_CLIENTHSTRIGGER_ACTIVE,
  TCPIP_TLS_CLIENTHSTRIGGER_TRIGGERED
} TcpIp_TlsClientHsTriggerStateType; /* Used to trigger the Tls client handshake hello */

typedef enum  eTcpIp_TlsCertState
{
  TCPIP_TLS_CERT_EMPTY = 0,             /**< Certificate data is not available */
  TCPIP_TLS_CERT_READY_TO_LOAD,         /**< Certificate data is ready to load */
  TCPIP_TLS_CERT_PARSE_IN_PROGRESS,     /**< Certificate data is being parsed */
  TCPIP_TLS_CERT_PARSED,                /**< Certificate data has been parsed */
  TCPIP_TLS_CERT_VERIFY_IN_PROGRESS,    /**< Certificate data is being verified */
  TCPIP_TLS_CERT_VERIFIED,              /**< Certificate data is verified */
  TCPIP_TLS_CERT_INVALID                /**< Certificate data is invalid */
} TcpIp_TlsCertStateType; /* Used to handle the Tls certificate verification state */

/* Status of Server certificate chain validation */
typedef enum  eTcpIp_TlsCertChainState
{
  TCPIP_TLS_CERTCHAIN_INIT = 0u,      /**< Certificate chain init state */
  TCPIP_TLS_CERTCHAIN_IN_PROGRESS,     /**< Certificate chain is parsed and verification is in progress */
  TCPIP_TLS_CERTCHAIN_VERIFY_FAILED,   /**< Certificate chain verification has failed but validation is in progress */
  TCPIP_TLS_CERTCHAIN_FINISHED,        /**< Certificate chain validation is finished */
  TCPIP_TLS_CERTCHAIN_COMPLETE,        /**< Certificate chain processing is complete */
  TCPIP_TLS_CERTCHAIN_INVALID          /**< Invalid state of certificate chain */
} TcpIp_TlsCertChainStateType; /* Used to determine the states of certificate chain processing */

typedef enum eTcpIp_Tls_CertStatusUpdateMode
{
  TCPIP_TLS_UPDATE_CERT_MODE_OCSP = 0u,
  TCPIP_TLS_UPDATE_CERT_MODE_CHAIN
} TcpIp_Tls_CertStatusUpdateModeType;

typedef enum  eTcpIp_TlsSessionTicketStateType
{
  TCPIP_TLS_SESSION_TICKET_EMPTY = 0,
  TCPIP_TLS_SESSION_TICKET_AVAILABLE,
  TCPIP_TLS_SESSION_TICKET_RESERVED,
  TCPIP_TLS_SESSION_TICKET_IN_USE
} TcpIp_TlsSessionTicketStateType;

typedef struct
{
  TcpIp_ConstSegmentType NonceBufferSegment1; /* Buffer segment where the received nonce from the NewSessionTicket is located. */
  TcpIp_ConstSegmentType NonceBufferSegment2; /* Second buffer segment since the nonce might not be linear in the buffer. */
  TcpIp_ConstSegmentType IdentityBufferSegment1; /* Buffer segment where the received identity from the NewSessionTicket is located. */
  TcpIp_ConstSegmentType IdentityBufferSegment2; /* Second buffer segment since the identity might not be linear in the buffer. */
  uint32 LifetimeSec; /* Received maximum ticket age in NewSessionTicket */
  uint32 AgeAddMs; /* Received age add value in NewSessionTicket */
  uint16 IdentityLen; /* Length of the received identity */
  uint8  NonceLen; /* Length of the received nonce */
} TcpIp_TlsNewSessionTicketInfoType;

/* Certificate Group Identifier */
typedef uint16 TcpIp_CertificateGroupIdType;

typedef struct
{
  uint32 certDataLength;
  TCPIP_P2C(uint8) certData;
  uint32 certNameLength;
  TCPIP_P2C(uint8) certName;
} TcpIp_CertDataType;

/* BER types */
#  define TCPIP_TLS_ASN1TAG_TYPEID_LEN   1u
#  define TCPIP_TLS_ASN1LENGTH_MINLEN    1u /* A length field is at least 1 byte large, but can be larger. */

/* BER tag values */
#  define TCPIP_TLS_ASN1TAG_INTEGER_ID   0x02u
#  define TCPIP_TLS_ASN1TAG_SEQUENCE_ID  0x30u

#  define TCPIP_TLS_ASN1_INTEGER_STARTVALUE_LEADINGZERO   0x80u

/* The sequence of the signature must at least include 1 byte type (integer) and 1 byte length field for r and s value,
 * for Secp curves the coordinates must be at least 1 byte large. This is purposely not included in this define.  */
#  define TCPIP_TLS_ASN1_MIN_SEQUENCELENGTH_BERENCODEDSIGNATURE   (2u*(TCPIP_TLS_ASN1TAG_TYPEID_LEN + TCPIP_TLS_ASN1LENGTH_MINLEN))
/* min sequence length + 1 byte type (sequence) + min 1 byte sequence length */
#  define TCPIP_TLS_ASN1_MIN_BERENCODEDSIGNATURE                  (TCPIP_TLS_ASN1_MIN_SEQUENCELENGTH_BERENCODEDSIGNATURE + TCPIP_TLS_ASN1TAG_TYPEID_LEN + TCPIP_TLS_ASN1LENGTH_MINLEN)

#  define TCPIP_TLS_BERENCODED_SIGNATURE_MAX_DEPTH 2u
#  define TCPIP_TLS_BERENCODED_SIGNATURE_DEPTH_ONE 1u
#  define TCPIP_TLS_BERENCODED_SIGNATURE_DEPTH_TWO 2u

#  define TCPIP_CURVE_ID_SECP256R1_SIGN_BERELEM_LEN     32u /* 256 bit equals 32 byte */
#  define TCPIP_CURVE_ID_SECP384R1_SIGN_BERELEM_LEN     48u /* 384 bit equals 48 byte */
#  define TCPIP_CURVE_ID_SECP521R1_SIGN_BERELEM_LEN     66u /* 521 bit needs 66 byte */

#  define TCPIP_TLS_ASN1_SECP256R1_MAX_SEQUENCELENGTH   (TCPIP_TLS_ASN1_MIN_SEQUENCELENGTH_BERENCODEDSIGNATURE + (2u*(TCPIP_CURVE_ID_SECP256R1_SIGN_BERELEM_LEN+1u))) /* maximum signature size for secp256 sequence (each coordinate with coordinate size + 1 because of leading zero) */
#  define TCPIP_TLS_ASN1_SECP521R1_MAX_SEQUENCELENGTH   (TCPIP_TLS_ASN1_MIN_SEQUENCELENGTH_BERENCODEDSIGNATURE + (2u*(TCPIP_CURVE_ID_SECP521R1_SIGN_BERELEM_LEN))) /* maximum signature size for secp521 sequence (each coordinate with coordinate size + no leading zero, since from the first byte only the last bit is used (521th bit) therefore not possible to have first byte >=0x80 -> no leading zero possible) */

/* ECC private key lengths (RFC5114 and RFC8032) */
#  define TCPIP_CURVE_ID_X25519_PRIVKEY_LEN    32u /* see RFC8032 chapter 5.1.5. Key Generation */
/* Secp private keys consist of one coordinate. */
#  define TCPIP_CURVE_ID_SECP256R1_PRIVKEY_LEN TCPIP_CURVE_ID_SECP256R1_SIGN_BERELEM_LEN
#  define TCPIP_CURVE_ID_SECP384R1_PRIVKEY_LEN TCPIP_CURVE_ID_SECP384R1_SIGN_BERELEM_LEN
#  define TCPIP_CURVE_ID_SECP521R1_PRIVKEY_LEN TCPIP_CURVE_ID_SECP521R1_SIGN_BERELEM_LEN

/* ECC public key lengths (RFC5114, RFC7748) */
/* Secp public keys consist of two coordinates. */
#  define TCPIP_CURVE_ID_SECP256R1_PUBKEY_LEN (2u * TCPIP_CURVE_ID_SECP256R1_SIGN_BERELEM_LEN)
#  define TCPIP_CURVE_ID_SECP384R1_PUBKEY_LEN (2u * TCPIP_CURVE_ID_SECP384R1_SIGN_BERELEM_LEN)
#  define TCPIP_CURVE_ID_SECP521R1_PUBKEY_LEN (2u * TCPIP_CURVE_ID_SECP521R1_SIGN_BERELEM_LEN)
#  define TCPIP_CURVE_ID_X25519_PUBKEY_LEN    32u
#  define TCPIP_CURVE_ID_X448_PUBKEY_LEN      56u
/* Maximum public key length, has to be examined whether an adjustment is needed if a new curve is introduced */
#  define TCPIP_MAX_PUBKEY_LEN                TCPIP_CURVE_ID_SECP521R1_PUBKEY_LEN

/* ECC shared value (Diffie-Hellman output) lengths (RFC5114, RFC7748 ) */
#  define TCPIP_CURVE_ID_SECP256R1_SHAREDKEY_LEN                                                     32u
#  define TCPIP_CURVE_ID_SECP384R1_SHAREDKEY_LEN                                                     48u
#  define TCPIP_CURVE_ID_SECP521R1_SHAREDKEY_LEN                                                     66u
#  define TCPIP_CURVE_ID_X25519_SHAREDKEY_LEN                                                        32u
#  define TCPIP_CURVE_ID_X448_SHAREDKEY_LEN                                                          56u
#  define TCPIP_TLS_SHAREDKEY_MAX_LEN                             TCPIP_CURVE_ID_SECP521R1_SHAREDKEY_LEN

/* ECDSA Signature lengths (RFC5114, RFC7748 ) */
#  define TCPIP_CURVE_ID_SECP256R1_SIGNATURE_LEN        (2u*TCPIP_CURVE_ID_SECP256R1_SIGN_BERELEM_LEN)
#  define TCPIP_CURVE_ID_SECP521R1_SIGNATURE_LEN        (2u*TCPIP_CURVE_ID_SECP521R1_SIGN_BERELEM_LEN)
#  define TCPIP_CURVE_ID_ED25519_SIGNATURE_LEN          64u
#  define TCPIP_CURVE_ID_ED448_SIGNATURE_LEN            114u
#  define TCPIP_TLS_MAX_SIGNATURE_LEN                   TCPIP_CURVE_ID_SECP521R1_SIGNATURE_LEN


/* BLOCK128 specific macros */
#  define TCPIP_TLS_BLOCK128_BLOCKSIZE      16u   /* This Blocksize is shared between AES and ChaCha algorithm */

/* NULL specific macros */
#  define TCPIP_TLS_NULL_BLOCKSIZE     1u     /* NULL do not have a blocksize, so the atomic size is 1 Byte */

/* Minimum size of Tls buffer required to start streaming */
#  define TCPIP_TLS_MIN_BUFFER_SIZE      (4u * TCPIP_TLS_BLOCK128_BLOCKSIZE)

#  define TCPIP_TLS_SIGNATURE_ALGO_ANONYMOUS   0u
#  define TCPIP_TLS_SIGNATURE_ALGO_RSA         1u
#  define TCPIP_TLS_SIGNATURE_ALGO_DSA         2u
#  define TCPIP_TLS_SIGNATURE_ALGO_ECDSA       3u

/* For further information on the context handling within the TLS see TLS EAP Design. */
typedef enum e_TcpIp_AsyncCtxStateType
{
  TCPIP_TLS_CTX_NO_ASYNC      = 0u, /* No async/LowPrio operation active */
  TCPIP_TLS_CTX_DONE          = 1u, /* Async/LowPrio operation done - Used in context of TcpIp_Tls12CoreMainFunction_LowPrio (time consuming operation) and TcpIp_Tls12CoreMainFunction_State (wait cycle) */
  TCPIP_TLS_CTX_ASYNC_PENDING = 3u, /* Async/LowPrio operation pending (LowPrioTask active) - Used in context of TcpIp_Tls12CoreMainFunction_State */
  TCPIP_TLS_CTX_WAIT_CYCLE    = 4u  /* Wait cycle - Used if next logical TLS message not received yet - Used in context of TcpIp_Tls12CoreMainFunction_State */
} TcpIp_AsyncCtxStateType;


typedef uint16 TcpIp_TlsHandshakeState;
#  define TCPIP_TLS_STATE_HANDSHAKE_INIT                                                                        0x0000u  /* Initial connection state */
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   define TCPIP_TLS_STATE_HANDSHAKE_INIT_CHANGEABLE_CIPHER_CALLOUT                                             0x0001u  /* Client: Callout to UL to change the order of cipher suites and/or signature algorithms */
#  endif

/* TLS HelloMessage states */
#  define TCPIP_TLS_STATE_SEND_CLIENT_HELLO                                                                     0x1000u  /* Client: Connection state while sending Client_Hello */
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   define TCPIP_TLS_STATE_SEND_CLIENT_HELLO_ADD_KEY_SHARE_EXTENSION                                            0x1002u  /* Client: Sub state of ClientHello - add KeyShare extension, only relevant in TLS 1.3 */
#   define TCPIP_TLS_STATE_SEND_CLIENT_HELLO_KEY_SHARE_WAIT_FOR_ASYNC                                           0x1003u  /* Client: Sub state of ClientHello - wait for async operations, only relevant in TLS 1.3 */
#   define TCPIP_TLS_STATE_SEND_CLIENT_HELLO_PSK_KEY_CALC                                                       0x1004u  /* Client: Sub state of ClientHello - calc pre shared key and binder, only relevant in TLS 1.3 */
#   define TCPIP_TLS_STATE_SEND_CLIENT_HELLO_PSK_KEY_WAIT_FOR_ASYNC                                             0x1005u  /* Client: Sub state of ClientHello - wait for async operations, only relevant in TLS 1.3 */
#  endif
#  define TCPIP_TLS_STATE_SEND_CLIENT_HELLO_ADD_GENERAL_EXTENSIONS                                              0x1006u  /* Client: Sub state of ClientHello - add general extensions */
#  define TCPIP_TLS_STATE_SEND_CLIENT_HELLO_FINALIZE                                                            0x1007u  /* Client: Sub state of ClientHello - finalize the ClientHello message */
#  define TCPIP_TLS_STATE_SEND_CLIENT_HELLO_DONE                                                                0x10FFu  /* Client: Sub state of ClientHello - all Sub states finished */

#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_HELLO                                                                 0x1100u  /* Server: Connection state while waiting for incoming Client_Hello message */

#  define TCPIP_TLS_STATE_SEND_SERVER_HELLO                                                                     0x1200u  /* Server: Connection state while sending Server_Hello */

#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO                                                                 0x1300u  /* Client: Connection state while waiting for incoming Server_Hello message */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_CALC_DH_SHARED_SECRET_AND_HS_KEYS                               0x1301u  /* Client: Sub state of ServerHello - Calculate the shared secret and derive handshake traffic keys */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_WAIT_FOR_ASYNC                                                  0x1302u  /* Client: Sub state of ServerHello - Wait for async operations */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_STATE_CHANGE                                                    0x1303u  /* Client: Sub state of ServerHello - determine next state */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_PARSING_DONE                                                    0x13FFu  /* Client: Sub state of ServerHello - all Sub states finished */
/* TLS junction between CertificateRequest and Certificate of server states */
#  define TCPIP_TLS_STATE_WAIT_FOR_CERT_OR_CERT_REQUEST                                                         0x4000u  /* Client: Connection state while waiting for incoming CertificateRequest or Certificate message */

/* TLS EncryptedExtensions states */
#  define TCPIP_TLS_STATE_WAIT_FOR_ENCRYPTED_EXTENSIONS                                                         0x3500u  /* Client: Connection state while waiting for incoming EncryptedExtensions message */

/* TLS CertificateMessage states */
#  define TCPIP_TLS_STATE_SEND_SERVER_CERTIFICATE                                                               0x1400u  /* Server: Connection state while sending Server_Certificate */

#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE                                                           0x1500u  /* Client: Connection state while waiting for incoming Server_Certificate message */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_LOADCERTS                                                 0x1501u  /* Client: Sub state of ServerCertificate - setting certificates into KeyM certs */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFYGROUP_CHECK                                         0x1502u  /* Client: Sub state of ServerCertificate - check if KeyM has finished the cert chain validation */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFYGROUP_STATUS                                        0x1503u  /* Client: Sub state of ServerCertificate - calc cert and cert chain status */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_DETERMINE_NEXT_STATE                                      0x1504u  /* Client: Sub state of ServerCertificate - determine next state */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_TRIGGER_OCSP_VALIDATION                                   0x1505u  /* Client: Sub state of ServerCertificate - trigger OCSP processing */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_UPDATE_CERT_STATUS                                        0x1506u  /* Client: Sub state of ServerCertificate - update cert status based on OCSP */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_DONE                                                      0x15FFu  /* Client: Connection state server certificates processing done */

/* TLS CertificateStatus state */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_STATUS                                                    0x1600u  /* Client: Connection state while waiting for incoming */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_STATUS_GET_CERT_STATUS                                    0x1601u  /* Client: Sub state of CeritificateStatus */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_STATUS_TRIGGER_OCSP_VALIDATION                            0x1602u  /* Client: Sub state of CeritificateStatus */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_STATUS_UPDATE_CERT_STATUS                                 0x1603u  /* Client: Sub state of CeritificateStatus */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_STATUS_DETERMINE_NEXT_STATE                               0x1604u  /* Client: Sub state of CeritificateStatus */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_STATUS_DONE                                               0x16FFu  /* Client: */

/* TLS KeyExchangeMessage states (only for TLS 1.2) */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE                                                              0x1700u  /* Server: Connection state while sending Server_Key_Exchange */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_HDR                                                      0x1710u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS                                             0x1720u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS_ADD_DH                                      0x1721u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS_ADD_SIGNATURE                               0x1722u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS_DECODE_SIGNATURE                            0x1723u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS_DONE                                        0x172Fu  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_PSK_PARAMS                                               0x1730u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_PSK_PARAMS_ADD_IDENTITY_HINT                             0x1731u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_PSK_PARAMS_DONE                                          0x173Fu  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_TRIGGER_TX                                                   0x1740u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_DONE                                                         0x17FFu  /* Server: */

#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_KEY_EXCHANGE                                                          0x1800u  /* Client: Connection state while waiting for incoming Server_Key_Exchange message */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_KEY_EXCHANGE_GET_SERVER_PARAMS                                        0x1801u  /* Client: get parameters from server key exchange */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_KEY_EXCHANGE_VERIFY_SIGNATURE                                         0x1802u  /* Client: validate signature */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_KEY_EXCHANGE_WAIT_FOR_ASYNC                                           0x1803u  /* Client: Wait for async operations */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_KEY_EXCHANGE_DETERMINE_NEXT_STATE                                     0x1804u  /* Client: */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_KEY_EXCHANGE_DONE                                                     0x18FFu  /* Client: move to next state */

/* only for TLS 1.2 */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_REQUEST                                                   0x1900u  /* Client: */

/* only for TLS 1.2 */
#  define TCPIP_TLS_STATE_SEND_SERVER_CERTIFICATE_REQUEST                                                       0x3700u  /* Server: */

/* only for TLS 1.2 */
#  define TCPIP_TLS_STATE_SEND_SERVER_HELLO_DONE                                                                0x2000u  /* Server: Connection state while sending Hello_Done */

/* only for TLS 1.2 */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_DONE                                                            0x2100u  /* Client: Connection state while waiting for incoming Hello_Done message */

/* TLS Server Certificate Verify (only for TLS 1.3) */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY                                                    0x3600u  /* Client: Connection state while waiting for incoming Server_Certificate_Verify message */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_VERIFY_SIGNATURE                                   0x3601u  /* Client: validate signature */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC                                     0x3602u  /* Client: Wait for async operations */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_DETERMINE_NEXT_STATE                               0x3603u  /* Client: Determine next state */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_DONE                                               0x36FFu  /* Client: move to next state */



/* TLS Client Certificate */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE                                                               0x2200u   /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_ISSUE_CALLOUT                                                 0x2201u   /* Client: Issue the cert request callout periodically until response is available */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_PREPARE_FULL_MESSAGE                                          0x2202u   /* Client: Handle callout result, and fill the cert message */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_PREPARE_EMPTY_MESSAGE                                         0x2203u   /* Client: Handle callout result, and send an empty cert message */

#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY                                                        0x3300u   /* Client: Connection state for sending the certificate verify message */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_ADD_HDR                                                0x3301u   /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_ADD_SIG_ALGORITHM                                      0x3302u   /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE                                         0x3303u   /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC                          0x3304u   /* Client: Wait until async job has finished */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_ENCODE_SIGNATURE                                       0x3305u   /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_TRIGGER_TX                                             0x3306u   /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_DONE                                                   0x3307u   /* Client: */

/* only for TLS 1.2 */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE                                                           0x3800u  /* Server: Connection state while waiting for incoming ClientCertificate message */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_LOADCERTS                                                 0x3801u  /* Server: Sub state of ClientCertificate - setting certificates into KeyM certs */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFYGROUP_CHECK                                         0x3802u  /* Server: Sub state of ClientCertificate - check if KeyM has finished the cert chain validation */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFYGROUP_STATUS                                        0x3803u  /* Server: Sub state of ClientCertificate - calc cert and cert chain status */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_DONE                                                      0x38FFu  /* Server: Connection state client certificates processing done */

/* only for TLS 1.2 */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY                                                    0x3900u  /* Server: Connection state while waiting for incoming ClientCertificateVerify message */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_GET_SERVER_PARAMS                                  0x3901u  /* Server: get parameters from client certificate verify */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_VERIFY_SIGNATURE                                   0x3902u  /* Server: validate signature */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC                                     0x3903u  /* Server: Wait for async operations */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_DONE                                               0x39FFu  /* Server: Connection state client certificate verify processing done */

#  define TCPIP_TLS_STATE_SEND_CLIENT_KEY_EXCHANGE                                                              0x2300u  /* Client: Connection state while sending Client_Key_Exchange */
#  define TCPIP_TLS_STATE_SEND_CLIENT_KEY_EXCHANGE_ADD_DH                                                       0x2301u  /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_KEY_EXCHANGE_ADD_PSK_ID                                                   0x2306u  /* Client */
#  define TCPIP_TLS_STATE_SEND_CLIENT_KEY_EXCHANGE_ADD_MSG_LENGTH                                               0x2302u  /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_KEY_EXCHANGE_CALC_DH_SHARED_SECRET                                        0x2303u  /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_KEY_EXCHANGE_CALC_PSK_SHARED_SECRET                                       0x2307u  /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_KEY_EXCHANGE_CALC_MASTER_SECRET                                           0x2304u  /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_KEY_EXCHANGE_WAIT_FOR_ASYNC                                               0x2305u  /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_KEY_EXCHANGE_DONE                                                         0x23FFu  /* Client: */

#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE                                                          0x2400u  /* Server: Connection state while waiting for incoming Client_Key_Exchange message */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_GET_CLIENT_PARAMS                                        0x2401u  /* only used if PSK not supported */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_CALC_DH_SHARED_SECRET                                    0x2402u  /* only used if PSK not supported */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_ECDHE_ECDSA_CLIENT_PARAMS                        0x2410u
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_ECDHE_ECDSA_CLIENT_PARAMS_GET_PARAMS             0x2411u
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_ECDHE_ECDSA_CLIENT_PARAMS_CALC_DH_SHARED_SECRET  0x2412u
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_ECDHE_ECDSA_CLIENT_PARAMS_DONE                   0x241Fu
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS                                0x2420u
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS_GET_PARAMS                     0x2421u
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS_CALC_PREMASTER_SECRET          0x2422u
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS_DONE                           0x242Fu
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_CALC_MASTER_SECRET                                       0x2430u
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_WAIT_FOR_ASYNC                                           0x2440u
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_DONE                                                     0x24FFu

#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CCS                                                                   0x2500u  /* */
#  define TCPIP_TLS_STATE_SEND_CLIENT_CCS                                                                       0x2600u  /* */

/* TLS ClientFinishedMessage states */
#  define TCPIP_TLS_STATE_SEND_CLIENT_FINISHED                                                                  0x2700u  /* Client: Connection state while sending Client_Finished */
#  define TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_ADD_HDR                                                          0x2701u  /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_CALC_HASH                                                        0x2702u  /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_CALC_FINISHED                                                    0x2703u  /* Client: */
#  define TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_CALC_HASH_AND_FINISHED                                           0x2704u  /* Client: Calculate the HS message hash and calculate the verify data (finished) */
#  define TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX                                                       0x2705u  /* Client: Complete the message and send it */
#  define TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_CALC_RESUMPTION_MASTER_SECRET                                    0x2706u  /* Client: TLS 1.3 session resumption: Calculate the resumption master secret */ /* TLS 1.3 only */
#  define TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET                          0x2707u  /* Client: TLS 1.3 session resumption: Wait for async operation (calculate resumption master secret) */ /* TLS 1.3 only */
#  define TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_DONE                                                             0x27FFu  /* Client: Move to next state */

#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED                                                              0x2800u  /* Server: Connection state while waiting for incoming Client_Finished message */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_GET_CLIENT_PARAMS                                            0x2801u  /* Server: Extract the Verify data */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_CALC_HASH                                                    0x2802u  /* Server: Calculate the Hash */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_CALC_FINISHED                                                0x2803u  /* Server: Calculate the Verify data */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_VERIFY                                                       0x2804u  /* Server: Compare the data */
#  define TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_DONE                                                         0x28FFu  /* Server: Move to next step */

#  define TCPIP_TLS_STATE_SEND_SERVER_CCS                                                                       0x2900u  /* */
/* TLS ServerFinishedMessage states */
#  define TCPIP_TLS_STATE_SEND_SERVER_FINISHED                                                                  0x3000u  /* Server: Connection state while sending Server_Finished */
#  define TCPIP_TLS_STATE_SEND_SERVER_FINISHED_ADD_HDR                                                          0x3001u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_FINISHED_CALC_HASH                                                        0x3002u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_FINISHED_CALC_FINISHED                                                    0x3003u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_FINISHED_TRIGGER_TX                                                       0x3004u  /* Server: */
#  define TCPIP_TLS_STATE_SEND_SERVER_FINISHED_DONE                                                             0x30FFu  /* Server: */

#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_CCS                                                                   0x3100u  /* Server: Wait for server Ccs message */

#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED                                                              0x3200u  /* Client: Connection state while waiting for incoming Server_Finished message */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_GET_CLIENT_PARAMS                                            0x3201u  /* Client: Extract the Verify data */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_HASH                                                    0x3202u  /* Client: Calculate the Hash */ /* TLS 1.2 only */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_FINISHED                                                0x3203u  /* Client: Calculate the Verify data */ /* TLS 1.2 only */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_HASH_AND_FINISHED                                       0x3204u  /* Client: Calculate the Hash and the Verify data */ /* TLS 1.3 only */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_VERIFY                                                       0x3205u  /* Client: Compare the data */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_CLIENT_FINISHED_KEY                                     0x3206u  /* Client: Calculate the FinishedKey for the ClientFinished */ /* TLS 1.3 only */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_FINISHED_KEY                                  0x3207u  /* Client: Wait for async operation (calculate FinishedKey) */ /* TLS 1.3 only */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_APPL_KEYS                                               0x3208u  /* Client: Calculate the application traffic keys */ /* TLS 1.3 only */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_APPL_KEY                                      0x3209u  /* Client: Wait for async operation (calculate application traffic keys) */ /* TLS 1.3 only */
#  define TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_DONE                                                         0x32FFu  /* Client: Move to next step */

#  define TCPIP_TLS_STATE_HANDSHAKE_FINALIZING                                                                  0xFD00u  /* Connection state when handshake is finalizing */
#  define TCPIP_TLS_STATE_HANDSHAKE_DONE                                                                        0xFE00u  /* Connection state when handshake performed successfully */
#  define TCPIP_TLS_STATE_HANDSHAKE_ABORT                                                                       0xFF00u  /* Connection state when handshake failed */


typedef enum eTcpIp_TlsCalcKeyMaterialState
{
  TCPIP_TLS_STATE_CALC_KEY_MATERIAL_INIT               = 0x0u,
  TCPIP_TLS_STATE_CALC_KEY_MATERIAL_REDUCE_SHARED_KEY  = 0x1u,
  TCPIP_TLS_STATE_CALC_KEY_MATERIAL_CALC_MASTER_SECRET = 0x2u,
  TCPIP_TLS_STATE_CALC_KEY_MATERIAL_DERIVE_KEY_BLOCK   = 0x3u,
  TCPIP_TLS_STATE_CALC_KEY_MATERIAL_SET_CSM_KEYS       = 0x4u,
  TCPIP_TLS_STATE_CALC_KEY_MATERIAL_FINALIZE           = 0x5u,
  TCPIP_TLS_STATE_CALC_KEY_MATERIAL_DONE               = 0xEu,
  TCPIP_TLS_STATE_CALC_KEY_MATERIAL_ABORT              = 0xFu
} TcpIp_TlsCalcKeyMaterialState; /* Used to determine the active state of the TLS key material calculation */

typedef P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) TcpIp_TlsDataPtrType; /* Used in RxBufStruct as data pointer Type */

typedef uint8 TcpIp_TlsCipherStreamingModeDataType;
#  define TCPIP_TLS_STREAMING_MODE_NULL                      0u
#  define TCPIP_TLS_STREAMING_MODE_AES_128_CBC               1u
#  define TCPIP_TLS_STREAMING_MODE_AES_128_GCM               2u
#  define TCPIP_TLS_STREAMING_MODE_AES_256_GCM               3u
#  define TCPIP_TLS_STREAMING_MODE_CHACHA20_POLY1305         4u
#  define TCPIP_TLS_STREAMING_MODE_INVALID                0xffu

typedef uint8 TcpIp_TlsKeyExchangeMethodDataType;
#  define TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE                 0u
#  define TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH                  1u
#  define TCPIP_TLS_KEYEXCHANGE_METHOD_RSA                   2u
#  define TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN             3u /* If PSK_DHE or PSK_RSA should be introduced new defines are needed */
#  define TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID            0xffu

typedef uint8 TcpIp_TlsMessageAuthenticationModeDataType;
#  define TCPIP_TLS_MSG_AUTH_MODE_NONE                       0u
#  define TCPIP_TLS_MSG_AUTH_MODE_SHA1                       1u
#  define TCPIP_TLS_MSG_AUTH_MODE_SHA256                     2u
#  define TCPIP_TLS_MSG_AUTH_MODE_SHA384                     3u
#  define TCPIP_TLS_MSG_AUTH_MODE_INVALID                 0xffu

typedef uint8 TcpIp_TlsMessageFinishedType;
/* Index defines are used to access the array TcpIp_Tls_Hs_FinishedLabel - Do not change the order */
#  define TCPIP_TLS_MSG_HASH_SERVER_FINISHED                0u
#  define TCPIP_TLS_MSG_HASH_CLIENT_FINISHED                1u

/* User callout function for TLS get time */
typedef Std_ReturnType (*TcpIp_TlsGetTimeCalloutFunctionType)(TCPIP_CP2V(uint32) GmtUnixTime);

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
typedef Std_ReturnType(*TcpIp_TlsKeyMVerifyGroupFunctionType)(KeyM_CertificateGroupIdType GroupId);

typedef Std_ReturnType(*TcpIp_TlsKeyMSetCertificateInGroupFunctionType)(KeyM_CertificateGroupIdType GroupId,
  TCPIP_P2C(uint8) RequestData,
  uint32 RequestDataLength,
  TCPIP_P2V(KeyM_CertificateIdType) CertId);


typedef Std_ReturnType(*TcpIp_TlsKeyMServiceCertificateFunctionType)(KeyM_ServiceCertificateType Service,
  TCPIP_P2C(uint8) CertNamePtr,
  uint32 CertNameLength,
  TCPIP_P2C(uint8) RequestData,
  uint32 RequestDataLength,
  TCPIP_P2V(uint8) ResponseData,
  uint32 ResponseDataLength);

typedef struct
{
  TCPIP_P2C(uint8)                                     DnPtr;                                         /* Pointer to DN in a received message (TLS RxBuffer) */
  uint16                                               DnLen;                                         /* The length of the DN list */
} TcpIp_TlsDistiguishedNameInfoType;

typedef struct
{
  TCPIP_P2C(uint16)                                   SignatureAndHashAlgoListPtr;                    /* Pointer to the sign and hash algorithm list of the received message in network byte order */
  TcpIp_TlsDistiguishedNameInfoType                   DistinguishedNameListPtr[TCPIP_TLS_MAX_NUM_DN]; /* List of pointers to DN in a received message (each DN has its own length) */
  uint16                                              SignatureAndHashAlgoNum;                        /* Number of SignAndHash elements */
  uint16                                              DistinguishedNamesNum;                          /* Number of distinguished names */
} TcpIp_TlsCertRequestInfoType;

typedef struct
{
  TcpIp_SignatureAlgorithmIdType                      SignatureAndHashAlgo;                           /* SignAndHash algorithm chosen by the socket owner */
  KeyM_CertificateIdType                              CertIdList[TCPIP_TLS_MAX_NUM_CERTS];            /* List of cert IDs, starting with the client leaf cert */
  uint8                                               CertIdListLen;                                  /* In-out-parameter. Length of the cert ID list (number of elements) */
  uint32                                              PrivKeyId;                                      /* Key id of the private key (of leaf cert) */
} TcpIp_TlsClientCertInfoType;

typedef enum eTcpIp_TlsClientCertInfoStatusType
{
  TCPIP_TLS_CLIENT_CERT_INFO_STATUS_READY,           /* A client certificate chain is available and can be read from KeyM */
  TCPIP_TLS_CLIENT_CERT_INFO_STATUS_PENDING,         /* The certificate request is accepted, the processing of the socket owner is still ongoing */
  TCPIP_TLS_CLIENT_CERT_INFO_STATUS_NOT_AVAILABLE,   /* No matching client certificate is available */
  TCPIP_TLS_CLIENT_CERT_INFO_STATUS_ERROR            /* The socket owner can not process the cert request (e.g. erroneous parameters, internal error, ...) */
} TcpIp_TlsClientCertInfoStatusType;                 /* Used to determine the processing state of the client certificate callout */

/* Prototype for Client Authentication Request callout */
typedef Std_ReturnType(*TcpIp_SocketOwnerTlsCertRequestType)(
  TcpIp_SocketIdType                                  SocketId,
  TCPIP_P2C(TcpIp_TlsCertRequestInfoType)             RequestInfoPtr,                                 /* filled by TLS */
  TCPIP_P2V(TcpIp_TlsClientCertInfoType)              ClientCertInfoPtr,                              /* filled by the socket owner */
  TCPIP_P2V(TcpIp_TlsClientCertInfoStatusType)        ClientCertInfoStatusPtr                         /* filled by the socket owner */
  );
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

#  if (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)
typedef struct
{
  TCPIP_P2V(uint8)   MasterSecretPtr;
  TCPIP_P2V(uint8)   SessionIdPtr;
  TCPIP_P2V(uint8)   SessionIdLenPtr;
  TCPIP_P2V(uint8)   ClientRandomPtr;
} TcpIp_Tls12_Secret_Type;

typedef struct
{
  TCPIP_P2V(uint8)   ClientSecretPtr;
  TCPIP_P2V(uint8)   ServerSecretPtr;
  TCPIP_P2V(uint8)   ClientRandomPtr;
} TcpIp_Tls13_Secret_Type;
#  endif /* (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON) */

#  if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
typedef enum eTcpIp_TlsNssFrameSendingType
{
  TCPIP_TLS_NSS_FRAME_SEND_HANDSHAKE_TRAFFIC_SECRETS,
  TCPIP_TLS_NSS_FRAME_SEND_APPLICATION_TRAFFIC_SECRETS
} TcpIp_TlsNssFrameSendingType;
#  endif /* (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON) */

/* Set of keys needed for the HKDF expand calculation */
typedef struct
{
  /* Id of the key which holds the Input Keying Material (IKM) for the calculation.
   * Can be the key which is referenced in the expand job with the Id HkdfExpandJobId.
   * Must have at least two key elements with the Ids CRYPTO_KE_CUSTOM_KEYDERIVATION_ADDITIONAL_INFO and CRYPTO_KE_KEYDERIVATION_PASSWORD.
   * CRYPTO_KE_KEYDERIVATION_PASSWORD shall contain the input key. */
  uint32   InputKeyId;  /* TcpIp_CsmKeyIdType */
  /* Id of the key which is used to store the calculated secret. Must have a key element with Id TargetKeyElementId.
   * Can be the same Id as TempExpandOutKeyId, but then TargetKeyElementId must equal TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY. */
  uint32   TargetKeyId;  /* TcpIp_CsmKeyIdType */
  /* Id of the key element where the output shall be stored, e.g. Key or Iv */
  uint32   TargetKeyElementId;
  /* Desired length for the output keying material. */
  uint16   TargetKeyElementLen;
  /* Id of the temporary output key for the calculation.
   * The output of the job is firstly written into this key. TCPIP_CSM_JobKeyDerive always writes the key value
   * into the key element with Id TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY.
   * Therefore this key must have a key element with Id TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY.
   * The output is then copied to the target key. With this copy operation the output is also shortened
   * if the configured key length is larger than the desired output length.
   * The temporary output key is then cleared at the end of the operation. */
  uint32   TempExpandOutKeyId;  /* TcpIp_CsmKeyIdType */
  /* Id of the CSM expand job. Must reference a key with at least two key elements
   * with the Ids CRYPTO_KE_CUSTOM_KEYDERIVATION_ADDITIONAL_INFO and CRYPTO_KE_KEYDERIVATION_PASSWORD. */
  uint32   HkdfExpandJobId;  /* TcpIp_CsmJobIdType */
  /* Output length of the Hkdf hash algorithm. */
  uint8    HkdfHashLen;
} TcpIp_Tls13_HkdfExpandInput_Type;

/* Set of keys needed for the derive secret calculation */
typedef struct
{
  /* Id of the CSM job for extraction and expansion. Must reference a key with at least three key elements
   * with the Ids AdditionalInfoKeyElementId, CRYPTO_KE_KEYDERIVATION_SALT
   * and CRYPTO_KE_KEYDERIVATION_PASSWORD. */
  uint32   HkdfCalcJobId;  /* TcpIp_CsmJobIdType */
  /* Id of the CSM job for hashing operations. */
  uint32   HashMessagesJobId;  /* TcpIp_CsmJobIdType */
  /* Id of the key which is used to store the calculated secret. Must have a key element with Id CRYPTO_KE_KEYDERIVATION_PASSWORD. */
  uint32   TargetKeyId;  /* TcpIp_CsmKeyIdType */
  /* Id of the key to provide the salt.
   * The salt must be stored in a key element with the Id CRYPTO_KE_KEYDERIVATION_PASSWORD except when this Id
   * is equal to the Id of the referenced key in HkdfCalcJobId.
   * Then it must be stored in the key element with Id CRYPTO_KE_KEYDERIVATION_SALT. */
  uint32   SaltKeyId;  /* TcpIp_CsmKeyIdType */
  /* Id of a temporary key which is needed to shorten the value of TargetKeyId.
   * Must be different to TargetKeyId and must contain a key element with Id TemporaryKeyElementId. */
  uint32   TemporaryKeyId;  /* TcpIp_CsmKeyIdType */
  /* Id of the key element which shall be temporarily used to shorten the value of TargetKeyId.
   * Afterwards this key element is cleared again. */
  uint32   TemporaryKeyElementId;
  /* Id of the key element where additional info shall be stored in the referenced key of HkdfCalcJobId. */
  uint32   AdditionalInfoKeyElementId;
  /* Output length of the Hkdf hash algorithm. */
  uint8    HkdfHashLen;
} TcpIp_Tls13_DeriveSecretInput_Type;

/* End of AsrTls types */
/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
#endif /* TCPIP_TLS_TYPES_H */

/***********************************************************************************************************************
 *  END OF FILE: TcpIp_Tls_Types.h
 **********************************************************************************************************************/
