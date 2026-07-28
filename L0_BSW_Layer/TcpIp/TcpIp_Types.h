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
 *  -------------------------------------------------------------------------------------------------------------------
 *         \file  TcpIp_Types.h
 *        \brief  Implementation of TcpIp Module - Type Definitions
 *
 *      \details  This file is part of the TcpIp module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#ifndef TCPIP_TYPES_H
# define TCPIP_TYPES_H

/**************************************************************************************************
 * Include files
 **************************************************************************************************/
# include "ComStack_Types.h"
# include "Std_Types.h"
# include "IpBase_Types.h"

# include "TcpIp_Cfg.h"

/**************************************************************************************************
 * Global defines
 **************************************************************************************************/
# define TCPIP_PHYS_ADDR_LEN_BYTE   6

# define TCPIP_IPSEC_GMAC_NONCE_LEN     12u  /* Length in bytes of the Nonce for Gmac */

# define TCPIP_LOCALADDRID_INV 0xFFU
# define TCPIP_LOCALADDRID_ANY 0xFEU /* Any IP address on any IPvX controller */

# define TCPIP_IP_ADDR_ID_ANY  0xFFU

# define TCPIP_NDP_ENTRY_STATIC  0x00U
# define TCPIP_NDP_ENTRY_VALID   0x01U
# define TCPIP_NDP_ENTRY_STALE   0x02U

# define TCPIP_IPV4_TIME_MS          1000uL
# define TCPIP_IPV4_TIME_MAX         0xFFFFFFFFuL
# define TCPIP_IPSEC_SECSELAPSED     0xFFFFu

# define VSTDLIB_MEM_CMP_RES_EQ      0     /* Corresponds to the define VSTDLIB_MEM_CMP_RES_EQ in vstdlib.c. It means that the two strings are equal. */

# define TCPIP_PORT_ANY              0x0000u

/**************************************************************************************************
 * Macros
 **************************************************************************************************/
# define TCPIP_P2V(ptrtype) P2VAR(ptrtype, AUTOMATIC, TCPIP_APPL_VAR)                                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define TCPIP_P2C(ptrtype) P2CONST(ptrtype, AUTOMATIC, TCPIP_APPL_DATA)                                                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define TCPIP_CP2V(ptrtype) CONSTP2VAR(ptrtype, AUTOMATIC, TCPIP_APPL_DATA)                                            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/**************************************************************************************************
 * Global data types and structures
 **************************************************************************************************/
/* new types for ASR 4.2.1 -- start ----------------------------- */

typedef uint8  TcpIp_TlsConnectionIdType; /* uint8 and uint16 is allowed */

/* start ENUMERATION types */
typedef uint16 TcpIp_DomainType;
# define TCPIP_AF_UNDEFINED       0x0000U
# define TCPIP_AF_INET            0x0002U  /* IPv4 */
# define TCPIP_AF_INET6           0x001CU  /* IPv6 */

typedef uint8 TcpIp_ProtocolType;  /* enum */
# define TCPIP_IPPROTO_TCP        0x06U
# define TCPIP_IPPROTO_UDP        0x11U

typedef IpBase_TcpIpEventType TcpIp_EventType;  /* uint8 */
# define TCPIP_TCP_RESET                  0x01U  /* TCP connection was reset, TCP socket and all related resources have been released. */
# define TCPIP_TCP_CLOSED                 0x02U  /* TCP connection was closed successfully, TCP socket and all related resources have been released. */
# define TCPIP_TCP_FIN_RECEIVED           0x03U  /* A FIN signal was received on the TCP connection, TCP socket is still valid. */
# define TCPIP_UDP_CLOSED                 0x04U  /* UDP socket and all related resources have been released. */
# define TCPIP_TLS_HANDSHAKE_SUCCEEDED    0x05U  /* TLS handshake successfully established, TLS connection available. */

typedef uint8 TcpIp_ReturnType;
# define TCPIP_OK                 0x00U  /* operation completed successfully */
# define TCPIP_E_NOT_OK           0x01U  /* operation failed */
# define TCPIP_E_PHYS_ADDR_MISS   0x02U  /* operation failed because of an ARP cache miss */

typedef uint8 TcpIp_ParamIdType;
# define TCPIP_PARAMID_TCP_RXWND_MAX             0x00U  /* uint32 */ /* Specifies the maximum TCP receive window for the socket. */
# define TCPIP_PARAMID_FRAMEPRIO                 0x01U  /* uint8 */  /* Specifies the frame priority for outgoing frames on the socket. */
# define TCPIP_PARAMID_TCP_NAGLE                 0x02U  /* uint8 */  /* Specifies if the Nagle Algorithm according to IETF RFC 896 is enabled or not. */
# define TCPIP_PARAMID_TCP_KEEPALIVE             0x03U  /* uint8 */  /* Specifies if TCP Keep Alive Probes are sent on the socket connection. (default = false) */
# define TCPIP_PARAMID_TTL                       0x04U  /* uint8 */  /* Specifies the time to live value for outgoing frames on the socket. */
# define TCPIP_PARAMID_TCP_KEEPALIVE_TIME        0x05U  /* uint32 */ /* Specifies the time in [s] between the last data packet sent (simple ACKs are not considered data) and the first keep-alive probe. (0..INV, default = 7200) */
# define TCPIP_PARAMID_TCP_KEEPALIVE_PROBES_MAX  0x06U  /* uint16 */ /* Specifies the maximum number of times that a keep-alive probe is retransmitted. (0..65535) */
# define TCPIP_PARAMID_TCP_KEEPALIVE_INTERVAL    0x07U  /* uint32 */ /* Specifies the interval in [s] between subsequent keep-alive probes. (0..INV) */
# define TCPIP_PARAMID_UDP_CHECKSUM              0x0cU  /* BOOL */   /* Specifies if UDP checksum handling shall be enabled (TRUE) or skipped (FALSE) on the related socket. */
/* AUTOSAR missed to specify (SWS_TcpIp) the type used for the TLS connection ID. We define it as uint16. */
# define TCPIP_PARAMID_TLS_CONNECTION_ASSIGNMENT 0x0DU  /* uint16 */ /* Specifies the TLS connection reference assigned to the TCP socket. */
# define TCPIP_PARAMID_TLS_CONNECTIONBASED_SESSION_RESUMPTION    0x0EU  /* uint32 */ /* Requests the usage of session resumption (connection based) and specifies the new socket Id. */

/* TCPIP_PARAMID_VENDOR_SPECIFIC             0x80U     Start of vendor specific range of parameter IDs. */
# define TCPIP_PARAMID_V_TCP_UTOUPDATE           0x80U  /* uint16 */ /* new value for user timeout */
# define TCPIP_PARAMID_V_TCP_UTOENABLED          0x81U  /* BOOL */   /* enable usage of user timeout option */
# define TCPIP_PARAMID_V_TCP_UTOCHANGEABLE       0x82U  /* BOOL */   /* allow change of user timeout by received option */
# define TCPIP_PARAMID_V_TCP_TXBUFSIZE           0x83U  /* uint32 */ /* Specifies the TCP tx buffer size (to choose the matching buffer) */
# define TCPIP_PARAMID_V_IPV4_TYPE_OF_SERVICE    0x84U  /* uint8 */  /* specify the 'type of service' value used for sending IPv4 messages */
# define TCPIP_PARAMID_V_IPV6_FLOW_LABEL         0x85U  /* uint32 */ /* specify the 'flow label' value used for sending IPv6 messages */
# define TCPIP_PARAMID_V_IPV6_TRAFFIC_CLASS      0x86U  /* uint8 */  /* specify the 'traffic class' value used for sending IPv6 messages */
# define TCPIP_PARAMID_V_UDP_TXREQLISTSIZE       0x87U  /* uint8 */  /* choose the desired TxRequestList size */
# define TCPIP_PARAMID_V_UDP_TXRETRYLISTSIZE     0x88U  /* uint8 */  /* set the number of Eth tx buffers used in case of PhysAddrMiss */
# define TCPIP_PARAMID_V_PHYS_DEST_ADDR          0x89U  /* uint8[6] */ /* set physical destination address for outgoing packets (override ARP). */
# define TCPIP_PARAMID_TCP_MSL                   0x8AU  /* uint32 */ /* set the MSL value of a TCP socket. */
# define TCPIP_PARAMID_TCP_RETRANSMIT_TIMEOUT    0x8BU  /* uint32 */ /* set the retransmission timeout value of a TCP socket. */

# define TCPIP_PARAMID_V_USE_TLS                 0xFFU  /* DEPRECATED SINCE VERSION 15.00.00 */
# define TCPIP_PARAMID_V_TLS_TXBUFSIZE           0xFFU  /* DEPRECATED SINCE VERSION 15.00.00 */
# define TCPIP_PARAMID_V_TLS_RXBUFSIZE           0xFFU  /* DEPRECATED SINCE VERSION 15.00.00 */
# define TCPIP_PARAMID_V_TLS_SELECT_OCSP_REQEST  0xFFU  /* DEPRECATED SINCE VERSION 15.00.00 */
# define TCPIP_PARAMID_V_TLS_HEARTBEAT_MODE      0xFFU  /* DEPRECATED SINCE VERSION 15.00.00 */
# define TCPIP_PARAMID_V_TLS_HEARTBEAT_PERIOD_S  0xFFU  /* DEPRECATED SINCE VERSION 15.00.00 */

# define DHCPV4_SRCPORT_OFS    0u
# define DHCPV4_TGTPORT_OFS    2u
# define DHCPV4_LEN_BYTE_OFS   4u
# define DHCPV4_CHECKSUM_OFS   6u

/* UDP header field Offset */
# define UDP_HDR_OFF_SRCPORT             0u
# define UDP_HDR_OFF_TGTPORT             (UDP_HDR_OFF_SRCPORT + 2u)
# define UDP_HDR_OFF_LENBYTE             (UDP_HDR_OFF_TGTPORT + 2u)
# define UDP_HDR_OFF_CHKSUM              (UDP_HDR_OFF_LENBYTE + 2u)

/* new types for ASR 4.2.1 -- end ----------------------------- */

/* define used for single core support */
# define TCPIP_SINGLECORE_APPLID             0u

typedef uint32         TcpIp_NetAddrType;

typedef uint8          TcpIp_LocalAddrIdType;

/* Values of TcpIp_IpAddrStateType */
# define TCPIP_IPADDR_STATE_ASSIGNED   0U
# define TCPIP_IPADDR_STATE_ONHOLD     1U
# define TCPIP_IPADDR_STATE_UNASSIGNED 2U
typedef uint8          TcpIp_IpAddrStateType;

typedef uint16      TcpIp_TcpIpErrorType;

/* Certificate Id type. */
typedef uint16 TcpIp_CertificateIdType;

# define TCPIP_TLS_OCSP_ASN1_CERT_STATUS_REVOKED  0xa1u
# define TCPIP_TLS_OCSP_ASN1_CERT_STATUS_GOOD     0x80u
# define TCPIP_TLS_OCSP_ASN1_CERT_STATUS_UNKOWN   0x82u

# define TCPIP_TLS_OCSP_CERTIFICATE_STATUS_UNKOWN 0x82u


/* Enumeration of the result type of verification operations. */
typedef uint8 TcpIp_CertificateStatusType;

/* define use in callback TcpIp_SocketOwnerTlsValidationResult */
# define TCPIP_TLS_VALIDATION_OK                 0x00u  /* The certificate chain is validated and ok, or the socket owner accepts the connection explicitly */
# define TCPIP_TLS_VALIDATION_NOT_OK             0x01u  /* The certificate chain is NOT valid and TLS will not accept the connection */
# define TCPIP_TLS_VALIDATION_UNKNOWN            0xFFu  /* The certificate chain has not been processed */
/* Enumeration of the result type for TcpIp_SocketOwnerTlsValidationResult */
typedef uint8 TcpIp_CertValidationResultType;


typedef uint8 TcpIp_OcspModeType;
# define TCPIP_TLS_OCSP_MODE_SINGLE    0x00u /* RFC6066 TLS Certificate Status Request */
# define TCPIP_TLS_OCSP_MODE_MULTI     0x01u /* RFC6961 TLS Multiple Certificate Status Request Extension */
# define TCPIP_TLS_OCSP_MODE_TLS13     0x02u /* RFC6960 TLS Certificate Status Request extension used for TLS 1.3 */
# define TCPIP_TLS_OCSP_MODE_NONE      0xFFu /* No Certificate Status Request received (Init value) */


typedef uint8 TcpIp_OcspConnectionStateType;
# define TCPIP_TLS_OCSP_CONNECTION_STATE_INACTIVE           0u /* (default) No OCSP Request active */
# define TCPIP_TLS_OCSP_CONNECTION_STATE_REQUESTED          1u /* Certificate status requested by the client */
# define TCPIP_TLS_OCSP_CONNECTION_STATE_STATUS_RECEIVED    2u /* Certificate status received from the server */

typedef uint8 TcpIp_OcspResponseStatusType;
# define TCPIP_TLS_OCSP_RESPONSE_STATUS_SUCCESSFUL          0x00u
# define TCPIP_TLS_OCSP_RESPONSE_STATUS_MALFORMEDREQUEST    0x01u
# define TCPIP_TLS_OCSP_RESPONSE_STATUS_INTERNALERROR       0x02u
# define TCPIP_TLS_OCSP_RESPONSE_STATUS_TRYLATER            0x03u
# define TCPIP_TLS_OCSP_RESPONSE_STATUS_SIGREQUIRED         0x05u
# define TCPIP_TLS_OCSP_RESPONSE_STATUS_UNAUTHORIZED        0x06u
# define TCPIP_TLS_OCSP_RESPONSE_STATUS_INVALID             0xFFu

/* Received OCSP status information - part of TcpIp_CertValidationStatusType */
typedef struct
{
  TcpIp_CertificateStatusType OcspCertStatus;        /* OCSP certificate status. Only valid if OcspConnectionState != TCPIP_TLS_OCSP_CONNECTION_STATE_INACTIVE */
  TcpIp_OcspResponseStatusType OcspResponseStatus;   /* Status of the received OCSP response */
  TcpIp_OcspModeType OcspMode;                       /* Received OCSP mode (Single/Multi) */
  TcpIp_OcspConnectionStateType OcspConnectionState; /* OCSP state during the TLS handshake */
} TcpIp_CertificateStatusResponseType;

/* Certificate Status in KeyM */
typedef struct
{
  TcpIp_CertificateIdType             CertId;             /* Certificate Id in KeyM */
  TcpIp_CertificateStatusType         CertStatus;         /* Certificate Status in KeyM */
  TcpIp_CertificateStatusResponseType CertStatusResponse; /* Received certificate status information (only updated if OCSP status response received) */
  boolean                             IsSelfSigned;       /* Self-signed flag */
} TcpIp_CertValidationStatusType;

typedef struct
{
  TcpIp_DomainType   domain;
} TcpIp_SockAddrType;
typedef TCPIP_P2V(TcpIp_SockAddrType)           TcpIp_SockAddrTypeP2V;

typedef struct
{
  TcpIp_DomainType   domain;
  uint16             port;
  uint32             addr[1];                                                                                           /* PRQA S 1039 */ /* MD_TCPIP_Rule1.2_1039 */
} TcpIp_SockAddrInetType;

typedef struct
{
  TcpIp_DomainType   domain;
  uint16             port;
  uint32             addr[4];
} TcpIp_SockAddrInet6Type;

# define TCPIP_STATE_OFFLINE                    0u       /* module is offline / not initialized */
# define TCPIP_STATE_ONHOLD                     1u       /* module is shutting down, all sockets are about to being closed */
# define TCPIP_STATE_ONLINE                     2u       /* module is initialized and ready for communication (if an IP address is available) */
# define TCPIP_STATE_STARTUP                    0xFFu    /* This state is currently not used */
# define TCPIP_STATE_SHUTDOWN                   0xFFu    /* This state is currently not used */
typedef uint8          TcpIp_StateType;  /* module state */

typedef IpBase_SockAddrIn6Type TcpIp_SockAddrInXType; /* Still used by Etm. */

typedef struct
{
  TcpIp_DomainType   domain;
  uint16             port;
} TcpIp_SockDomainAndPortType;

typedef union
{ /* PRQA S 750 */ /* MD_MSR_Union */
  IpBase_FamilyType           sa_family;
  IpBase_SockAddrType         SockAddr;
  IpBase_SockAddrInType       SockAddrIn;
  IpBase_SockAddrIn6Type      SockAddrIn6;
  TcpIp_SockDomainAndPortType DomainAndPort;
  TcpIp_SockAddrType          TcpIpSockAddr;
} TcpIp_SockAddrBaseType;

typedef void (*TcpIp_SocketOwnerRxIndicationType)(
  TcpIp_SocketIdType            SocketId,
  TCPIP_P2V(TcpIp_SockAddrType) RemoteAddrPtr,
  TCPIP_P2V(uint8)              BufPtr,
  uint16                        Length);

typedef void (*TcpIp_SocketOwnerTxConfirmationType)(
  TcpIp_SocketIdType            SocketId,
  uint16                        Length);

typedef Std_ReturnType (*TcpIp_SocketOwnerTcpAcceptedType)(
  TcpIp_SocketIdType            SocketId,
  TcpIp_SocketIdType            SocketIdConnected,
  TCPIP_P2V(TcpIp_SockAddrType) RemoteAddrPtr);

typedef void (*TcpIp_SocketOwnerTcpConnectedType)(
  TcpIp_SocketIdType            SocketId);

typedef void (*TcpIp_SocketOwnerTcpIpEventType)(
  TcpIp_SocketIdType            SocketId,
  IpBase_TcpIpEventType         Event);

typedef uint8 TcpIp_TlsDecryptAlgoType;
# define TCPIP_TLS_DECRYPT_ALGO_TYPE_NULL     0u
# define TCPIP_TLS_DECRYPT_ALGO_TYPE_CBC      1u
# define TCPIP_TLS_DECRYPT_ALGO_TYPE_AEAD     2u

typedef uint8 TcpIp_TlsMsgHandshakeType;
# define TCPIP_TLS_HSTYPE_HELLOREQUEST                  0u /* TLS handshake type HelloRequest */
# define TCPIP_TLS_HSTYPE_CLIENTHELLO                   1u /* TLS handshake type ClientHello */
# define TCPIP_TLS_HSTYPE_SERVERHELLO                   2u /* TLS handshake type ServerHello */
# define TCPIP_TLS_HSTYPE_NEWSESSIONTICKET              4u /* TLS handshake type NewSessionTicket */
# define TCPIP_TLS_HSTYPE_ENDOFEARLYDATA                5u /* TLS handshake type EndOfEarlyData */
# define TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS           8u /* TLS handshake type EncryptedExtensions */
# define TCPIP_TLS_HSTYPE_CERTIFICATE                  11u /* TLS handshake type Certificate (server and client) */
# define TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE            12u /* TLS handshake type ServerKeyExchange */
# define TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST           13u /* TLS handshake type CertificateRequest */
# define TCPIP_TLS_HSTYPE_SERVERHELLODONE              14u /* TLS handshake type ServerHelloDone */
# define TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY            15u /* TLS handshake type CerficateVerify */
# define TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE            16u /* TLS handshake type ClientKeyExchange */
# define TCPIP_TLS_HSTYPE_FINISHED                     20u /* TLS handshake type HsFinished */
# define TCPIP_TLS_HSTYPE_CERTIFICATESTATUS            22u /* TLS handshake type CertificateStatus */
# define TCPIP_TLS_HSTYPE_KEYUPDATE                    24u /* TLS handshake type KeyUpdate */
# define TCPIP_TLS_HSTYPE_MESSAGEHASH                 254u /* TLS handshake type MessageHash */
# define TCPIP_TLS_HSTYPE_INVALID                    0xffu

# define TCPIP_TLS_CIPHERSUITE_AMOUNT                  20u     /* Amount of cipher suites currently known to the ECU. Must be updated once new defines are added below. */
/* Use IANA names */
typedef uint16 TcpIp_TlsCipherDataType;
# define TCPIP_TLS_CIPHERSUITEID_LEN                   2u
/* COMMON */
# define TCPIP_TLS_NULL_WITH_NULL_NULL                 0x0000u /* Used during HS */
# define TCPIP_TLS_CIPHER_INVALID                      0xFFFFu /* INVALID */

/* ECDHE_ECDSA */
# define TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256 0xC023u
# define TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA    0xC009u
# define TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256 0xC02Bu
# define TCPIP_TLS_ECDHE_ECDSA_WITH_NULL_SHA           0xC006u

/* ECDH_ECDSA */
# define TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256  0xC025u
# define TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA     0xC004u
# define TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256  0xC02Du
# define TCPIP_TLS_ECDH_ECDSA_WITH_NULL_SHA            0xC001u

/* PSK */
# define TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA256         0x00AEu
# define TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA            0x008Cu
# define TCPIP_TLS_PSK_WITH_AES_128_GCM_SHA256         0x00A8u
# define TCPIP_TLS_PSK_WITH_AES_256_GCM_SHA384         0x00A9u
# define TCPIP_TLS_PSK_WITH_NULL_SHA                   0x002Cu
# define TCPIP_TLS_PSK_WITH_NULL_SHA256                0x00B0u

/* TLS 1.3 */
# define TCPIP_TLS_AES_128_GCM_SHA256                  0x1301u
# define TCPIP_TLS_AES_256_GCM_SHA384                  0x1302u
# define TCPIP_TLS_CHACHA20_POLY1305_SHA256            0x1303u
# define TCPIP_TLS_AES_128_CCM_SHA256                  0x1304u
# define TCPIP_TLS_AES_128_CCM_8_SHA256                0x1305u

# define TCPIP_TLS_SIGNATURE_ALGO_AMOUNT     9u       /* Amount of signature algos currently known to the ECU. Must be updated once new defines are added below. */
typedef enum e_TcpIp_SignatureAlgorithmIdType
{
  TCPIP_SIG_ALGO_ID_NONE                    = 0x0000,
  TCPIP_SIG_ALGO_ID_RSA_PKCS1_SHA256        = 0x0401,
  TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256  = 0x0403,
  TCPIP_SIG_ALGO_ID_RSA_PKCS1_SHA384        = 0x0501,
  TCPIP_SIG_ALGO_ID_ECDSA_SECP384R1_SHA384  = 0x0503,
  TCPIP_SIG_ALGO_ID_RSA_PKCS1_SHA512        = 0x0601,
  TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512  = 0x0603,
  TCPIP_SIG_ALGO_ID_ECDSA_ED25519_INTRINSIC = 0x0807,
  TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC   = 0x0808
}TcpIp_SignatureAlgorithmIdType;

typedef enum  eTcpIp_TlsVersion
{
  TCPIP_TLSVERSION_NOTSET = 0,
  TCPIP_TLSVERSION_12,
  TCPIP_TLSVERSION_13
} TcpIp_TlsVersionType;

typedef struct
{
  TcpIp_CertificateIdType                     RootCertId;
  TcpIp_TlsCipherDataType                     CipherSuiteId;
  TcpIp_SignatureAlgorithmIdType              SigAlgoId;
  TcpIp_TlsVersionType                        TlsVersion;
} TcpIp_TlsConnectionInfoType;

typedef void (*TcpIp_SocketOwnerTlsValidationResultType)(
  TcpIp_SocketIdType                          SocketId,
  uint32                                      NumCerts,
  TCPIP_P2C(TcpIp_CertValidationStatusType)   CertChainStatusPtr,
  TCPIP_P2V(TcpIp_CertValidationResultType)   ValidationResultPtr,
  TCPIP_P2C(TcpIp_TlsConnectionInfoType)      TlsConnectionInfoPtr);

typedef enum eTcpIp_TlsClientChangeCipherStatusType
{
  TCPIP_TLS_CHANGE_CHIPHER_STATUS_READY,             /* The cipher suites + signature algorithms have been prioritized (deleted) by the user and are now ready to use */
  TCPIP_TLS_CHANGE_CHIPHER_STATUS_PENDING,           /* The processing of the socket owner is still ongoing */
  TCPIP_TLS_CHANGE_CHIPHER_STATUS_ERROR              /* The socket owner can not prioritize or delete cipher suites/signature algorithms */
} TcpIp_TlsChangeCipherStatusType;                   /* Used to determine the processing state of the changeable order of ciphers */

typedef enum eTcpIp_TlsKeyUpdateType
{
  TCPIP_TLS_KEYUPDATE_NONE_TO_HANDSHAKE,
  TCPIP_TLS_KEYUPDATE_NONE_TO_APPLICATION,
  TCPIP_TLS_KEYUPDATE_HANDSHAKE_TO_APPLICATION,
  TCPIP_TLS_KEYUPDATE_APPLICATION_TO_APPLICATION
} TcpIp_TlsKeyUpdateType;

typedef struct
{
  /* It was defined that the upper layer gets an uint16 array as working set. */
  uint16                                              workingSet[TCPIP_TLS_CIPHERSUITE_AMOUNT];
  uint8                                               workingSetLen;
} TcpIp_TlsCipherSuiteWorkingSetType;

typedef struct
{
  /* It was defined that the upper layer gets an uint16 array as working set. */
  uint16                                              workingSet[TCPIP_TLS_SIGNATURE_ALGO_AMOUNT];
  uint8                                               workingSetLen;
} TcpIp_TlsSignatureAlgorithmWorkingSetType;

typedef Std_ReturnType(*TcpIp_SocketOwnerTlsChangeableCipherType)(
  TcpIp_SocketIdType                                   SocketId,
  TCPIP_P2V(TcpIp_TlsCipherSuiteWorkingSetType)        CipherSuiteWorkingSetPtr,
  TCPIP_P2V(TcpIp_TlsSignatureAlgorithmWorkingSetType) SignatureAlgorithmWorkingSetPtr,
  TCPIP_P2V(boolean)                                   SccPushButtonModePtr,
  TCPIP_P2V(TcpIp_TlsChangeCipherStatusType)           ChangeableCipherStatusPtr         /* filled by the socket owner */
  );

typedef struct
{
  uint32 currentlyAvailableTicketsNum;   /* The number of session tickets which are currently available */
} TcpIp_TlsSessionTicketUserInfoType;                   /* Used to inform the user about session tickets */

typedef void(*TcpIp_SocketOwnerTlsSessionTicketUpdateType)(
  TcpIp_SocketIdType                            SocketId,
  TCPIP_P2C(TcpIp_TlsSessionTicketUserInfoType) SessionTicketInfoPtr
  );

typedef void (*TcpIp_SocketOwnerTlsKeyUpdateType)(
  TcpIp_SocketIdType            SocketId,
  TcpIp_TlsKeyUpdateType        KeyUpdateType);

typedef BufReq_ReturnType (*TcpIp_SocketOwnerCopyTxDataType)(
  TcpIp_SocketIdType            SocketId,
  TCPIP_P2V(uint8)              BufPtr,
  uint16                        BufLength);

typedef BufReq_ReturnType (*TcpIp_SocketOwnerCopyTxDataDynType)(
  TcpIp_SocketIdType            SocketId,
  TCPIP_P2V(uint8)              BufPtr,
  TCPIP_P2V(uint16)             BufLengthPtr);

typedef void (*TcpIp_SocketOwnerLocalIpAddrAssignmentChgType)(
  TcpIp_LocalAddrIdType         LocalAddrId,
  TcpIp_IpAddrStateType         State);

typedef void (*TcpIp_PhysAddrTableChgCbkType)(
  uint8                         CtrlIdx,
  TCPIP_P2V(TcpIp_SockAddrType) IpAddrPtr,
  TCPIP_P2V(uint8)              PhysAddrPtr,
  boolean                       Valid);

typedef void (*TcpIp_DuplicateAddrDetectionCbkType)(
  TcpIp_LocalAddrIdType         LocalAddrId,
  TCPIP_P2C(TcpIp_SockAddrType) IpAddrPtr,
  TCPIP_P2C(uint8)              LocalPhysAddrPtr,
  TCPIP_P2C(uint8)              RemotePhysAddrPtr);

typedef void (*TcpIp_IcmpMsgHandlerCbkType)(
  TcpIp_LocalAddrIdType         LocalAddrId,
  TCPIP_P2C(TcpIp_SockAddrType) RemoteAddrPtr,
  uint8                         Ttl,
  uint8                         Type,
  uint8                         Code,
  uint16                        DataLength,
  TCPIP_P2V(uint8)              DataPtr);

typedef void (*TcpIp_IcmpMultiPartMsgHandlerCbkType)(
  TcpIp_LocalAddrIdType         LocalAddrId,
  TCPIP_P2C(TcpIp_SockAddrType) RemoteAddrPtr,
  uint8                         Ttl,
  uint8                         Type,
  uint8                         Code,
  uint16                        DataLength,
  TCPIP_P2V(uint8)              DataPtr,
  uint16                        MultiPartDataLength,
  TCPIP_P2V(uint8)              MultiPartDataPtr);

typedef uint16 (*TcpIp_GetRandomNumberType)(void);

typedef struct
{
  TcpIp_SocketOwnerRxIndicationType          RxIndicationFuncPtr;
  TcpIp_SocketOwnerTxConfirmationType        TxConfirmationFuncPtr;
  TcpIp_SocketOwnerTcpAcceptedType           TcpAcceptedFuncPtr;
  TcpIp_SocketOwnerTcpConnectedType          TcpConnectedFuncPtr;
  TcpIp_SocketOwnerTcpIpEventType            TcpIpEventFuncPtr;
  TcpIp_SocketOwnerTlsValidationResultType   TlsValidationResultFuncPtr;
  TcpIp_SocketOwnerCopyTxDataType            CopyTxDataFuncPtr;
  TcpIp_SocketOwnerCopyTxDataDynType         CopyTxDataDynFuncPtr;
} TcpIp_SocketOwnerCfgType;

typedef struct
{
  IpBase_PortType SrcPort;
  IpBase_PortType TgtPort;
  uint16          LenByte;
  uint16          Checksum;
} TcpIp_Udp_HdrType;

typedef IpBase_PbufType        TcpIp_PbufType;

typedef uint8 TcpIp_DhcpV4_OptSelectorType;

/* Specification of IP address assignment policy. */
typedef uint8 TcpIp_IpAddrAssignmentType;
# define TCPIP_IPADDR_ASSIGNMENT_NONE             0u
# define TCPIP_IPADDR_ASSIGNMENT_STATIC           1u  /* Static configured IPv4/IPv6 address */
# define TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL        2u  /* Linklocal IPv4/IPv6 address assignment. */
# define TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP   2u  /* Linklocal IPv4/IPv6 address assignment using DoIP parameters.
                                                        (same value as TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL because TcpIp
                                                        internal handling is identical) */
# define TCPIP_IPADDR_ASSIGNMENT_DHCP             3u  /* Dynamic configured IPv4/IPv6 address by DHCP. */
# define TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER      4u  /* Dynamic configured IPv4/IPv6 address by Router Advertisement. */
# define TCPIP_IPADDR_ASSIGNMENT_ANY           0xFFu  /* Specifies ANY address assignment type for use with Vector specific API TcpIp_ReleaseSpecificIpAddrAssignment(). */

/* Parameter IDs for diagnostic read access */
typedef uint32 TcpIp_DiagParamsType;
# define TCPIP_DP_SOCKET_LOCAL_PORT               0x00U
# define TCPIP_DP_SOCKET_TCP_CURRENT_ACK_NUM      0x01U
# define TCPIP_DP_SOCKET_TCP_NEXT_SEQ_NUM         0x02U
# define TCPIP_DP_INVALID                         0x03U  /* this id is the highest supported parameter id */


typedef uint8 TcpIp_DListIdxType;

/* DList element (array of elements is managed by descriptor) */
typedef struct
{
  TcpIp_DListIdxType             PrevIdx; /* index of the predecessor */
  TcpIp_DListIdxType             NextIdx; /* index of the successor */
} TcpIp_DListNodeType;

/* DList descriptor (can be shared by multiple instances) */
typedef struct
{
  TcpIp_DListIdxType             FirstFreeIdx;      /* index of first element in free list */
  TcpIp_DListIdxType             LastFreeIdx;       /* index of last element in free list */
  uint8                          ElementFreeCount;  /* number of elements in free list */
  uint8                          ElementTotalCount; /* number of elements at NodePtr */
  TCPIP_P2V(TcpIp_DListNodeType) NodePtr;           /* pointer to element array of this list */
} TcpIp_DListDescType;

/* DList instance */
typedef struct
{
  TcpIp_DListIdxType             FirstIdx;     /* index of first element in list */
  TcpIp_DListIdxType             LastIdx;      /* index of last element in list */
  uint8                          ElementCount; /* number of elements in list */
  TCPIP_P2V(TcpIp_DListDescType) DescPtr;      /* pointer to list descriptor of the list */
} TcpIp_DListType;

/* Struct for function TcpIp_GetArpCacheEntries */
typedef struct
{
  uint32   InetAddr[1];   /* IpV4 address in Network byte order */
  uint8    PhysAddr[6];   /* Physical address in Network byte order */
  uint8    State;         /* State of the address Entry */
} TcpIp_ArpCacheEntryType;

# define TCPIP_ARP_ENTRY_STATIC  0u
# define TCPIP_ARP_ENTRY_VALID   1u
# define TCPIP_ARP_ENTRY_STALE   2u

/* Struct to store echo reply message info */
typedef struct
{
  IpBase_AddrInType           Dest;                            /* Destination address */
  uint16                      Identifier;                      /* Identifier */
  uint16                      SeqNum;                          /* Sequence number */
  uint16                      IpV4_Icmp_EchoReplyDataLen;      /* Length of echo reply data */
  boolean                     IpV4_Icmp_EchoReplyIsPending;    /* Echo reply pending flag */
} TcpIp_IcmpV4_PendingMsgInfoType;

/* Struct to store destination unreachable message info */
typedef struct
{
  IpBase_AddrInType           Dest;                                       /* Destination address */
  uint16                      IpV4_Icmp_DestUnreachMsgLen;                /* Length of destination unreachable message */
  uint8                       Code;                                       /* Icmp code */
  boolean                     IpV4_Icmp_DestinationUnreachablePending;    /* Destination unreachable pending flag */
} TcpIp_IcmpV4_DestUnreachableInfoType;

typedef struct
{
  uint32 Inet6Addr[4]; /* IPv6 address in network byte order */
  uint8  PhysAddr[6];  /* physical address in network byte order */
  uint8  State;        /* state of the address entry */
} TcpIp_NdpCacheEntryType;

typedef uint8 TcpIp_DhcpEventType;
# define TCPIP_DHCP_EVENT_TX_DISCOVER_SOLICIT    0u
# define TCPIP_DHCP_EVENT_RX_OFFER_ADVERTISE     1u
# define TCPIP_DHCP_EVENT_TX_REQUEST             2u
# define TCPIP_DHCP_EVENT_RX_ACK_REPLY           3u
# define TCPIP_DHCP_EVENT_TX_V6_CONFIRM          4u
# define TCPIP_DHCP_EVENT_TX_V6_RENEW            5u
# define TCPIP_DHCP_EVENT_TX_V6_REBIND           6u
# define TCPIP_DHCP_EVENT_TX_V6_RELEASE          7u
# define TCPIP_DHCP_EVENT_TX_V6_DECLINE          8u
# define TCPIP_DHCP_EVENT_INVALID                255u

typedef uint8 TcpIp_DhcpUserOptionDirectionType;
# define TCPIP_DHCP_USER_OPTION_RX                0u
# define TCPIP_DHCP_USER_OPTION_TX                1u
# define TCPIP_DHCP_USER_OPTION_RX_REQUESTED      2u

typedef void (*TcpIp_SocketOwnerDhcpEventType)(
  TcpIp_LocalAddrIdType LocalIpAddrId,
  TcpIp_DhcpEventType   Event);

# define TCPIP_IPSEC_SPI_ANY                  0u

/* Presently only a single traffic selector is supported */
# define TCPIP_IPSEC_TRAFFICSEL_INDEX         0u

typedef uint8 TcpIp_IpSecPolicyType;
/* IP Security policy */
# define TCPIP_IPSEC_POLICY_BYPASS            0u    /* Bypass security policy */
# define TCPIP_IPSEC_POLICY_PROTECT           1u    /* Protect security policy */
# define TCPIP_IPSEC_POLICY_OPTIONAL          2u    /* Optional security policy */
# define TCPIP_IPSEC_POLICY_DISCARD           3u    /* Discard security policy */
# define TCPIP_IPSEC_POLICY_INVALID           4u

typedef uint8 TcpIp_SaDirectionType;
/* IpSec traffic direction */
# define TCPIP_IPSEC_TRAFFIC_INBOUND          0u    /* Inbound traffic */
# define TCPIP_IPSEC_TRAFFIC_OUTBOUND         1u    /* Outbound traffic */
# define TCPIP_IPSEC_TRAFFIC_INVALID          255u  /* Invalid traffic */

typedef uint8 TcpIp_IpSecHeaderType;
/* IpSec header types */
# define TCPIP_IPSEC_HDR_NONE       0u      /* invalid value */
# define TCPIP_IPSEC_HDR_AH_ESP     1u      /* support both AH and ESP - not supported */
# define TCPIP_IPSEC_HDR_AH         2u      /* only AH  */
# define TCPIP_IPSEC_HDR_ESP        3u      /* only ESP */

typedef uint8 TcpIp_IpSecIntegrityTransformJobStatusType;
/* Status of the JobPair */
# define TCPIP_IPSEC_STATUS_JOBPAIR_UNUSED     0u /* Job pair is unused */
# define TCPIP_IPSEC_STATUS_JOBPAIR_ALLOCATED  1u /* Job pair has been allocated */

typedef uint8 TcpIp_IpSecEventType;
/* IpSec events */
# define TCPIP_IPSEC_NO_EVENT                0u /* No IpSec Auditable event */
# define TCPIP_IPSEC_EVENT_INVALID_HDR       1u /* Invalid IpSec header  */
# define TCPIP_IPSEC_EVENT_DISCARD_POLICY    2u /* Discard IpSec security policy */
# define TCPIP_IPSEC_EVENT_SEQ_OVERFLOW      3u /* AH sequence number overflow */
# define TCPIP_IPSEC_EVENT_ANTIREPLAY        4u /* AH anti replay attack */
# define TCPIP_IPSEC_EVENT_VERIFY_FAILED     5u /* AH authentication data verification failed */
# define TCPIP_IPSEC_EVENT_GEN_FAILED        6u /* AH authentication data generation failed */
# define TCPIP_IPSEC_EVENT_FRAGMENT          7u /* Fragmented IpSec Ip packet */
# define TCPIP_IPSEC_EVENT_SAENTRY_NOTFOUND  8u /* SA entry lookup failure */

typedef uint8 TcpIp_IpProtocolType;

typedef uint16 TcpIp_IpSecEncrTransformType;
/* Encryption Algorithm Transform IDs according to IANA */
# define TCPIP_IPSEC_TRANSFORM_ENCR_DES_IV64               1u  /**< encr_des_iv64 */
# define TCPIP_IPSEC_TRANSFORM_ENCR_DES                    2u  /**< encr_des      */
# define TCPIP_IPSEC_TRANSFORM_ENCR_3DES                   3u  /**< encr_3des     */
# define TCPIP_IPSEC_TRANSFORM_ENCR_RC5                    4u  /**< encr_rc5      */
# define TCPIP_IPSEC_TRANSFORM_ENCR_IDEA                   5u  /**< encr_idea     */
# define TCPIP_IPSEC_TRANSFORM_ENCR_CAST                   6u  /**< encr_cast     */
# define TCPIP_IPSEC_TRANSFORM_ENCR_BLOWFISH               7u  /**< encr_blowfish */
# define TCPIP_IPSEC_TRANSFORM_ENCR_3IDEA                  8u  /**< encr_3idea    */
# define TCPIP_IPSEC_TRANSFORM_ENCR_DES_IV32               9u  /**< encr_des_iv32 */
# define TCPIP_IPSEC_TRANSFORM_ENCR_NULL                   11u /**< encr_null     */
# define TCPIP_IPSEC_TRANSFORM_ENCR_AES_CBC                12u /**< encr_aes_cbc  */
# define TCPIP_IPSEC_TRANSFORM_ENCR_AES_CTR                13u /**< encr_aes_ctr  */

typedef uint16 TcpIp_IpSecIntegrityTransformType;
/* Integrity Algorithm Transform IDs according to IANA */
# define TCPIP_IPSEC_TRANSFORM_AUTH_NONE                   0u /**< No authentication algorithm  */
# define TCPIP_IPSEC_TRANSFORM_AUTH_HMAC_MD5_96            1u /**< Hmac MD5 algorithm           */
# define TCPIP_IPSEC_TRANSFORM_AUTH_HMAC_SHA1_96           2u /**< Hmac sha1 96 algorithm       */
# define TCPIP_IPSEC_TRANSFORM_AUTH_DES_MAC                3u /**< Des algorithm                */
# define TCPIP_IPSEC_TRANSFORM_AUTH_KPDK_MD5               4u /**< Kpdk MD5 algorithm           */
# define TCPIP_IPSEC_TRANSFORM_AUTH_AES_XCBC_96            5u /**< Aes XCBC 96 algorithm        */
# define TCPIP_IPSEC_TRANSFORM_AUTH_HMAC_MD5_128           6u /**< Hmac MD5 algorithm           */
# define TCPIP_IPSEC_TRANSFORM_AUTH_HMAC_SHA1_160          7u /**< Hmac sha1 algorithm          */
# define TCPIP_IPSEC_TRANSFORM_AUTH_AES_CMAC_96            8u /**< Aes Cmac algorithm           */
# define TCPIP_IPSEC_TRANSFORM_AUTH_AES_128_GMAC           9u /**< Aes Gmac 128 algorithm       */
# define TCPIP_IPSEC_TRANSFORM_AUTH_AES_192_GMAC           10u /**< Aes Gmac 192 algorithm      */
# define TCPIP_IPSEC_TRANSFORM_AUTH_AES_256_GMAC           11u /**< Aes Gmac 256 algorithm      */
# define TCPIP_IPSEC_TRANSFORM_AUTH_HMAC_SHA2_256_128      12u /**< Hmac sha2 256/128 algorithm */
# define TCPIP_IPSEC_TRANSFORM_AUTH_HMAC_SHA2_384_192      13u /**< Hmac sha2 384/192 algorithm */
# define TCPIP_IPSEC_TRANSFORM_AUTH_HMAC_SHA2_512_256      14u /**< Hmac sha2 512/256 algorithm */

typedef struct {
  uint8 Nonce[TCPIP_IPSEC_GMAC_NONCE_LEN];
}TcpIp_IpSec_GmacNonceType;


typedef struct
{
  TCPIP_P2C(TcpIp_SockAddrType)            RemoteAddr;           /**< Remote Ip address (in network byte order) */
  uint16                                   LocalPortRangeStart;  /**< Local port range start (in host byte order) */
  uint16                                   LocalPortRangeEnd;    /**< Local port range start (in host byte order) */
  uint16                                   RemotePortRangeStart; /**< Remote port range start (in host byte order) */
  uint16                                   RemotePortRangeEnd;   /**< Remote port range start (in host byte order) */
  TcpIp_IpProtocolType                     IpProtocol;           /**< Upper layer protocols supported */
} TcpIp_IpSecTrafficSelectorType;

typedef struct
{
  TCPIP_P2C(uint8)                         InboundKeyMatPtr;  /**< Key material for inbound job */
  TCPIP_P2C(uint8)                         OutboundKeyMatPtr; /**< Key material for outbound job */
  uint16                                   InboundKeyMatLen;  /**< Key length for inbound job */
  uint16                                   OutboundKeyMatLen; /**< Key length for outbound job */
} TcpIp_IpSecKeyMaterialInfoType;

typedef struct
{
  TcpIp_IpSecIntegrityTransformType        IntegTransformIdent;    /**< Transform identifier for the integrity transform  */
  TcpIp_IpSecEncrTransformType             EncryptTransformIdent;  /**< Transform identifier for the encryption transform */
  boolean                                  EsnEnabled;             /**< Esn support flag                                  */
} TcpIp_IpSecTransformInfoType;

typedef struct
{
  TcpIp_IpSecKeyMaterialInfoType              KeyMaterial;         /**< struct for storing key materials     */
  TcpIp_IpSecTransformInfoType                SecurityTransform;   /**< struct containing ipsec transform    */
  uint32                                      InboundSpi;          /**< inbound Spi                          */
  uint32                                      OutboundSpi;         /**< Outbound Spi                         */
  TCPIP_P2C(TcpIp_IpSecTrafficSelectorType)   TrafficSelectors;    /**< struct for storing traffic selectors */
  uint16                                      NumTrafficSelectors; /**< Number of traffic selectors          */
  TcpIp_IpSecHeaderType                       IpsecHdrType;        /**< Ipsec header type                    */
} TcpIp_IpSecSaInfoType;

typedef struct
{
  uint32                                      InboundSpi;          /**< inbound Spi                          */
  uint32                                      OutboundSpi;         /**< Outbound Spi                         */
  uint32                                      IncomingPktCnt;      /**< Incoming packet count                */
  uint32                                      OutgoingPktCnt;      /**< Outgoing packet count                */
  uint16                                      SecsSinceLastRx;     /**< Seconds since last Rx                */
  uint16                                      SecsSinceLastTx;     /**< Seconds since last Tx                */
  TcpIp_IpSecHeaderType                       IpsecProtocol;       /**< Ipsec protocol type                  */
} TcpIp_IpSecSaStatusType;

typedef void (*TcpIp_IpSecSpdCalloutFunctionType)(
  TCPIP_P2V(TcpIp_IpSecPolicyType)   SecurityPolicyPtr,
  uint8                              Protocol,
  TCPIP_P2C(TcpIp_SockAddrType)      RemSock,
  TCPIP_P2C(TcpIp_SockAddrType)      LocSock);

typedef void (*TcpIp_IpSecAuditEventCalloutFunctionType)(
  uint32                         Spi,
  uint32                         SeqNum,
  TCPIP_P2C(TcpIp_SockAddrType)  RemSock,
  TCPIP_P2C(TcpIp_SockAddrType)  LocSock,
  TcpIp_IpSecEventType           ErrorId);

/* datatype for function TcpIp_GetAndResetMeasurementData */
typedef uint8 TcpIp_MeasurementIdxType;
# define TCPIP_MEAS_DROP_TCP         0x01u
# define TCPIP_MEAS_DROP_UDP         0x02u
# define TCPIP_MEAS_DROP_IPV4        0x03u
# define TCPIP_MEAS_DROP_IPV6        0x04u

/* datatypes for security event reporting */
# define TCPIP_INV_IDSM_ID                          0xFFu

typedef uint8 TcpIp_SecurityEventIdType;
# define TCPIP_SECURITY_EVENT_ARP_IP_ADDR_CONFLICT  0x01u
# define TCPIP_SECURITY_EVENT_INV_IPV4_ADDR         0x02u
# define TCPIP_SECURITY_EVENT_INV_IPV6_ADDR         0x03u
# define TCPIP_SECURITY_EVENT_INV_PORT_TCP          0x04u
# define TCPIP_SECURITY_EVENT_INV_PORT_UDP          0x05u

/* datatype for the IPsec status */
typedef uint8 TcpIp_IpSecStateType;
# define TCPIP_IPSEC_STATUS_UNSET   0x00u
# define TCPIP_IPSEC_STATUS_TX_RX   0x01u
# define TCPIP_IPSEC_STATUS_RX_ONLY 0x02u
# define TCPIP_IPSEC_STATUS_STALE   0x03u

/* Vendor specific measurement indices */
# define TCPIP_MEAS_VENDOR_SPECIFIC_DROP_LAYER3_IPV6     0x80u
# define TCPIP_MEAS_VENDOR_SPECIFIC_DROP_LAYER4          0x81u

# define TCPIP_MEAS_VENDOR_SPECIFIC_DROP_INSUFF_TCP_TX_BUFFER            0x84u
# define TCPIP_MEAS_VENDOR_SPECIFIC_DROP_INSUFF_TCP_RX_BUFFER            0x85u
# define TCPIP_MEAS_VENDOR_SPECIFIC_DROP_INSUFF_IPV4_FRAGMENT_RX_BUFFER  0x086u

/* IPsec Diagnostic measurement indices */
# define TCPIP_MEAS_VENDOR_SPECIFIC_NR_SA_PAIRS          0x82u
# define TCPIP_MEAS_VENDOR_SPECIFIC_SA_PAIRS             0x83u

# define TCPIP_MEAS_ALL              0xFFu

# define TCPIP_MEASUREMENTDATA_IDX   0u
# define TCPIP_MEASUREMENTDATA_MAX   0xFFFFFFFFuL


/* TcpIp TLS-Alert level type  */
typedef uint8 TcpIp_TlsAlertLevelType;
# define TCPIP_TLS_ALERT_LEVEL_WARNING                   0x01u /* warning */
# define TCPIP_TLS_ALERT_LEVEL_FATAL                     0x02u /* fatal */

/* TcpIp TLS-Alert description type */
/* Alerts marked with and 'f' are FATALE errors */
typedef uint8 TcpIp_TlsAlertDescriptionType;
# define TCPIP_TLS_ALERT_DESC_CLOSE_NOTIFY                0u /* close_notify */
# define TCPIP_TLS_ALERT_DESC_UNEXP_MSG                  10u /* f, unexpected_message */
# define TCPIP_TLS_ALERT_DESC_BAD_RECORD_MAC             20u /* f, bad_record_mac */
# define TCPIP_TLS_ALERT_DESC_DECR_FAILED_RESERVED       21u /* decryption_failed_RESERVED - old */
# define TCPIP_TLS_ALERT_DESC_RECORD_OVERFLOW            22u /* f, record_overflow */
# define TCPIP_TLS_ALERT_DESC_DECOMP_FAILURE             30u /* f, decompression_failure */
# define TCPIP_TLS_ALERT_DESC_HANDSHAKE_FAILURE          40u /* f, handshake_failure */
# define TCPIP_TLS_ALERT_DESC_NO_CERT_RESERVED           41u /* no_certificate_RESERVED - old */
# define TCPIP_TLS_ALERT_DESC_BAD_CERT                   42u /* bad_certificate */
# define TCPIP_TLS_ALERT_DESC_UNSUP_CERT                 43u /* unsupported_certificate */
# define TCPIP_TLS_ALERT_DESC_CERT_REVOKED               44u /* certificate_revoked */
# define TCPIP_TLS_ALERT_DESC_CERT_EXPIRED               45u /* certificate_expired */
# define TCPIP_TLS_ALERT_DESC_CERT_UNKNOWN               46u /* certificate_unknown */
# define TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM              47u /* f, illegal_parameter */
# define TCPIP_TLS_ALERT_DESC_UNKNOWN_CA                 48u /* f, unknown_ca */
# define TCPIP_TLS_ALERT_DESC_ACCESS_DENIED              49u /* f, access_denied */
# define TCPIP_TLS_ALERT_DESC_DECODE_ERROR               50u /* f, decode_error */
# define TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR              51u /* f, decrypt_error */
# define TCPIP_TLS_ALERT_DESC_EXP_RESTR_FAILURE          60u /* export_restriction_RESERVED - old */
# define TCPIP_TLS_ALERT_DESC_PROT_VERSION               70u /* f, protocol_version */
# define TCPIP_TLS_ALERT_DESC_INSUF_SEC                  71u /* f, insufficient_security */
# define TCPIP_TLS_ALERT_DESC_INT_ERROR                  80u /* f, internal_error */
# define TCPIP_TLS_ALERT_DESC_USER_CANCELED              90u /* user_canceled */
# define TCPIP_TLS_ALERT_DESC_NO_RENEGOT                100u /* no_renegotiation */
# define TCPIP_TLS_ALERT_DESC_MISSING_EXT               109u /* f, missing_extension - only TLS 1.3 */
# define TCPIP_TLS_ALERT_DESC_UNSUP_EXT                 110u /* f, unsupported_extension */
# define TCPIP_TLS_ALERT_DESC_CERT_UNOBTAINABLE         111u /* f, certificate_unobtainable */
# define TCPIP_TLS_ALERT_DESC_UNRECOGNIZED_NAME         112u /* f, unrecognized_name */
# define TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP      113u /* f, bad_certificate_status_response */
# define TCPIP_TLS_ALERT_DESC_BAD_CERT_HASH_VALUE       114u /* f, bad_certificate_hash_value */
# define TCPIP_TLS_ALERT_DESC_UNKNOWN_PSK_IDENTITY      115u /* f, unknown_psk_identity */
# define TCPIP_TLS_ALERT_UNSET                         0xffu /* Alert description unset, used for initialization */


/* TcpIp TLS error indication type */
typedef uint8 TcpIp_Tls_ErrorIndicationType;
/* Required by customer */
# define TCPIP_TLS_E_NOT_SET             0x00u    /* No error indication is set */
# define TCPIP_TLS_E_SERVER_CERT_EXPIRED 0x01u    /* The server's certificate has expired */
# define TCPIP_TLS_E_OCSP_RESP_NOT_GOOD  0x02u    /* The server's OCSP response contains a certificate which is not 'good' */
# define TCPIP_TLS_E_UNKNOWN_CA          0x03u    /* The issuing CA of the received server certificate is unknown */
# define TCPIP_TLS_E_SERVER_TERMINATED   0x04u    /* The server terminated */
/* Vector specific */
# define TCPIP_TLS_E_CLIENT_CERT_EXPIRED 0x05u    /* The client's certificate has expired */
# define TCPIP_TLS_E_TX_ALERT            0x80u    /* Parameter 'AlertDescription' is set to the transmitted alert */
# define TCPIP_TLS_E_RX_ALERT            0x81u    /* Parameter 'AlertDescription' is set to the received alert */

typedef uint8 TcpIp_TlsEventType;
/* TcpIp TLS close event */
# define TCPIP_TLS_EVENT_CLOSENOTIFY_RECEIVED 0x00u /* Received a close notify */

/* TCPIP address assignment trigger */
# define TCPIP_AUTOMATIC 0x00u                    /*  The address become assigned when the controller startup. */
# define TCPIP_MANUAL    0x01u                    /*  The address stay unassigned till it is requested. */


typedef uint8 TcpIp_IpProtocolChecksumType;
# define TCPIP_IP_PROTOCOL_CHECKSUM_CHECK_HW_OR_NOT_REQ   0u /* The UDP/TCP/ICMP checksum will not calculated or by HW. */
# define TCPIP_IP_PROTOCOL_CHECKSUM_CHECK_COPY            1u /* The checksum will be calculated by SW while copy. */
# define TCPIP_IP_PROTOCOL_CHECKSUM_CHECK_COMPLETE        2u /* The checksum will be calculated by SW after packet is finish. */
#endif
/* TCPIP_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Types.h
 *********************************************************************************************************************/
