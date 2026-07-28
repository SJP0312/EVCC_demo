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
 *            Module: TcpIp
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: TcpIp_Cfg.h
 *   Generation Time: 2025-08-26 17:17:07
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#if !defined(TCPIP_CFG_H)
#define TCPIP_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TCPIP SWITCH DEFINES
 *********************************************************************************************************************/
#define TCPIP_VERSION_INFO_API                     STD_OFF
#define TCPIP_DEV_ERROR_DETECT                     STD_ON
#define TCPIP_DEV_ERROR_REPORT                     STD_ON

#define TCPIP_SUPPORT_DHCPV4                       STD_OFF

#define TCPIP_SUPPORT_DHCPV6                       STD_OFF
#define TCPIP_SUPPORT_DHCPV6_OPTIONS               STD_OFF

#define TCPIP_SUPPORT_TCP                          STD_ON
#define TCPIP_SUPPORT_DNS                          STD_OFF
#define TCPIP_SUPPORT_DEM                          STD_OFF
#define TCPIP_SUPPORT_IPV4                         STD_OFF
#define TCPIP_SUPPORT_IPV6                         STD_ON
#define TCPIP_SUPPORT_SOAD                         STD_OFF
#define TCPIP_SUPPORT_ICMPV4                       STD_OFF
#define TCPIP_SUPPORT_DHCPV4SERVER                 STD_OFF
#define TCPIP_SUPPORT_DIAG_ACCESS_EXTENSIONS       STD_OFF
#define TCPIP_SUPPORT_MEASUREMENT_DATA             STD_OFF
#define TCPIP_SUPPORT_SECURITY_EVENT_REPORTING     STD_OFF
#define TCPIP_SUPPORT_IPSEC                        STD_OFF

#define TCPIP_SUPPORT_ASRTLS                       STD_ON
#define TCPIP_SUPPORT_ASRTLS_VERSION_1_2           STD_ON
#define TCPIP_SUPPORT_ASRTLS_VERSION_1_3           STD_ON
#define TCPIP_SUPPORT_ASRTLSSERVER                 STD_OFF
#define TCPIP_SUPPORT_ASRTLSSERVER_PSK             STD_OFF
#define TCPIP_SUPPORT_ASRTLSCLIENT                 STD_ON
#define TCPIP_SUPPORT_ASRTLSCLIENT_PSK             STD_OFF
#define TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS  STD_ON
#define TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS         STD_OFF
#define TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME     STD_ON
#define TCPIP_SUPPORT_ASRTLS_ECC                   STD_ON
#define TCPIP_SUPPORT_ASRTLS_ERROR_INDICATION      STD_OFF /* Specifies if the TLS connection should trigger the Error Indication callout function. */
#define TCPIP_SUPPORT_ASRTLS_USER_ERROR            STD_ON /* Specifies if the TLS connection should enable User Error reporting. */ 

#define TCPIP_SINGLE_MAIN_FUNCTION_ENABLED         STD_ON

#define TCPIP_MULTICORE_SUPPORT_ENABLED            STD_OFF


#define TCPIP_SUPPORT_TCP_USER_TIMEOUT_OPTION      STD_OFF
#define TCPIP_SUPPORT_TCP_CONGESTION_CONTROL       STD_OFF
#define TCPIP_SUPPORT_TCP_TIMESTAMP_OPTION         STD_OFF
#define TCPIP_SUPPORT_TCP_SELECTIVE_ACK            STD_OFF
#define TCPIP_SUPPORT_TCP_KEEP_ALIVE               STD_OFF
#define TCPIP_SUPPORT_TCP_RX_OOO                   STD_ON
#define TCPIP_SUPPORT_TCP_NAGLE_TIMEOUT            STD_ON

#define TCPIP_TCP_DIAG_READ_ACK_SEQ_NUM_ENABLED    STD_OFF

#define TCPIP_SUPPORT_IPV6_PRIVACY_EXTENSIONS      STD_OFF /* Not supported. */
#define TCPIP_SUPPORT_MLD                          STD_OFF /* Not supported. */
#define TCPIP_SUPPORT_IPV6_RX_FRAGMENTATION        STD_OFF
#define TCPIP_SUPPORT_IPV6_TX_FRAGMENTATION        STD_OFF
#define TCPIP_SUPPORT_NDP_DAD                      STD_ON
#define TCPIP_SUPPORT_NDP_DAD_OPTIMISTIC           STD_OFF
#define TCPIP_SUPPORT_NDP_INV_NS                   STD_OFF
#define TCPIP_SUPPORT_NDP_INV_NA                   STD_OFF
#define TCPIP_SUPPORT_NDP_INV_NA_NC_UPDATE         STD_ON
#define TCPIP_SUPPORT_NDP_NUD                      STD_ON
#define TCPIP_SUPPORT_IPV6_PATH_MTU                STD_OFF
#define TCPIP_SUPPORT_IPV6_DLISTS                  STD_OFF
#define TCPIP_SUPPORT_IPV6_MULTICAST_LOOPBACK      STD_ON
#define TCPIP_SUPPORT_ICMPV6_MSG_PARAM_PROBLEM     STD_ON
#define TCPIP_SUPPORT_ICMPV6_ECHO_REPLY            STD_OFF
#define TCPIP_SUPPORT_ICMPV6_ECHO_REQUEST          STD_OFF
#define TCPIP_SUPPORT_ICMPV6_ERROR_MESSAGES        STD_ON
#define TCPIP_SUPPORT_ICMPV6_MSG_DST_UNREACHABLE   STD_OFF
#define TCPIP_SUPPORT_NDP_OPT_RFC6106_RDNSS        STD_OFF
#define TCPIP_SUPPORT_NDP_ROUTER_SOLICITATIONS     STD_ON
#define TCPIP_SUPPORT_IPV6_ETHIF_ADDR_FILTER_API   STD_ON
#define TCPIP_SUPPORT_IPV6_NVM_ADDR_STORAGE        STD_OFF
#define TCPIP_SUPPORT_IPV6_DYN_REACHABLE_TIME      STD_ON
#define TCPIP_SUPPORT_IPV6_RND_REACHABLE_TIME      STD_ON
#define TCPIP_SUPPORT_IPV6_DYN_RETRANS_TIMER       STD_ON
#define TCPIP_SUPPORT_IPV6_DYN_HOP_LIMIT           STD_ON

#define TCPIP_TLS_CONNECTION_COUNT                 1u

#define TCPIP_MAIN_FCT_PERIOD_MSEC                 10u



/* Overhead to the configured TLS RX buffer due to read max area (see TcpIp_TlsCoreBuffer_Init()),
 * area between readIdx and writeIdx (same size as read max area), maximum expected HMAC size
 * and for TLS 1.3 one byte inner plaintext content type. */
/* This value must be subtracted when calculating the size which is offered in the TLS extension "record_size_limit". */
#define TCPIP_TLS_ADDITIONAL_RX_BUFFER_OVERHEAD    129u

/* The maximum number of client certificates we support for one certificate chain that should be sent.
 * TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsMaxNumCertificates */
#define TCPIP_TLS_MAX_NUM_CERTS    5u

/* The maximum number of distinguished names we can handle in the certificate request message.
*  TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsMaxNumDistinguishedNames */
#define TCPIP_TLS_MAX_NUM_DN       10u

/**********************************************************************************************************************
  GLOBAL DATA TYPES - SIMPLE
**********************************************************************************************************************/
/* Dynamic datatype, can be UInt8 or Uint16, based on the total amount  of UDP and TCP sockets. For internal usages, 4 sockets are reserved. */
typedef uint8  TcpIp_SocketIdType; /* UInt8, total number of UDP and TCP sockets is less than 250.*/
# define TCPIP_SOCKETID_INVALID     0xFFU
# define TCPIP_INV_SOCK_HND         (TCPIP_SOCKETID_INVALID) /* For legacy usage */
# define TCPIP_INV_SOCKET_ID        (TCPIP_SOCKETID_INVALID) /* For legacy usage */
typedef TcpIp_SocketIdType TcpIp_SockHndType;

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES (SNV)
 *********************************************************************************************************************/



/**
 * \defgroup TcpIpHandleIdsLocalAddr Handle IDs of handle space LocalAddr.
 * \brief Parameter: TcpIpAddrId
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define TcpIpConf_TcpIpLocalAddr_TcpIpV6LocalAddr_TcpIpCtrl_AsAn      1u
#define TcpIpConf_TcpIpLocalAddr_TcpIpV6LocalAddr_TcpIpCtrl_LinkLocal 0u
/**\} */



/**
 * \defgroup TcpIpHandleIdsSocketOwner Handle IDs of handle space SocketOwner.
 * \brief Parameter: TcpIpSocketOwnerId
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define TcpIpConf_TcpIpSocketOwner_Scc                                0u
/**\} */



/**
 * \defgroup TcpIpHandleIdsTlsConnection Handle IDs of handle space TlsConnection.
 * \brief Parameter: TcpIpTlsConnectionId
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define TcpIpConf_TcpIpTlsConnection_TlsConnectionConfig_Scc          0u
/**\} */

/**********************************************************************************************************************
 *  MODULE SPECIFIC DEFINES
 *********************************************************************************************************************/
#ifndef TCPIP_USE_DUMMY_STATEMENT
#define TCPIP_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef TCPIP_DUMMY_STATEMENT
#define TCPIP_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef TCPIP_DUMMY_STATEMENT_CONST
#define TCPIP_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef TCPIP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define TCPIP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef TCPIP_ATOMIC_VARIABLE_ACCESS
#define TCPIP_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef TCPIP_PROCESSOR_TC377T
#define TCPIP_PROCESSOR_TC377T
#endif
#ifndef TCPIP_COMP_DIAB
#define TCPIP_COMP_DIAB
#endif
#ifndef TCPIP_GEN_GENERATOR_MSR
#define TCPIP_GEN_GENERATOR_MSR
#endif
#ifndef TCPIP_CPUTYPE_BITORDER_LSB2MSB
#define TCPIP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef TCPIP_CONFIGURATION_VARIANT_PRECOMPILE
#define TCPIP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef TCPIP_CONFIGURATION_VARIANT_LINKTIME
#define TCPIP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef TCPIP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define TCPIP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef TCPIP_CONFIGURATION_VARIANT
#define TCPIP_CONFIGURATION_VARIANT TCPIP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef TCPIP_POSTBUILD_VARIANT_SUPPORT
#define TCPIP_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/* User Config File Start */

/* User Config File End */


#endif /* TCPIP_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Cfg.h
 *********************************************************************************************************************/
