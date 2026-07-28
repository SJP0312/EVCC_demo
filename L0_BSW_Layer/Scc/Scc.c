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
/*!        \file  Scc.c
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
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#define SCC_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_Cbk.h"
#include "Scc_Cfg.h"
#include "Scc_Lcfg.h"
#include "Scc_Exi.h"
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_TimerGeneral_TimerCfg.h"
#include "Scc_SDP_InterfaceCfg.h"
#include "Scc_SDP_TimerCfg.h"
#include "Scc_Core_Channel.h"
#include "Scc_SAP_Exi.h"
#include "Scc_SAP_TimerCfg.h"
#include "Scc_BufferPool.h"


#include "SchM_Scc.h"

#if ( (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
  ||  (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)) )
# include "XmlSecurity.h"
# include "Csm.h"
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */
#if ( (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
  ||  (defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)) )
# include "KeyM.h"
# include "Scc_Core_KeyMUtils.h"
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_TLS */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */
#include "EthIf_Types.h"
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
# include "Slac.h"
#endif /* SCC_ENABLE_SLAC_HANDLING */
#include "IpBase.h"
#include "TcpIp_IpV6.h"
#include "NvM.h"
#include "TcpIp.h"
#include "Scc_SDP.h"

#if (SCC_IDSM_REPORT == STD_ON)
# include "IdsM.h"
#endif

#if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
# include "Scc_DIN70121_Exi.h"
# include "Scc_DIN70121_TimerCfg.h"
#endif

#if (defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO  != 0u))
# include "Scc_ISO15118_2_Exi.h"
# include "Scc_ISO15118_2_TimerCfg.h"
#endif

#if (defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20  != 0u))
# include "Scc_ISO15118_20_TimerCfg.h"
# include "Scc_ISO15118_20CM_Exi.h"
#endif

#if ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0 )
# include "Scc_OppCharge_Exi.h"
# include "Scc_OppCharge_TimerCfg.h"
#endif

#if ( defined SCC_ENABLE_STATE_MACHINE) && (SCC_ENABLE_STATE_MACHINE == STD_ON)
# include "Scc_StateM_ParamsCfg.h"
# include "Scc_StateM_Vector.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check consistency of source and header file. */
#if ( (SCC_SW_MAJOR_VERSION != 0x28u) || (SCC_SW_MINOR_VERSION != 0x04u) || (SCC_SW_PATCH_VERSION != 0x01u) )
# error "Scc.c: Source and Header file are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
typedef enum
{
  SCC_ISO20VEHICLECHAINSELECTION_PROCESS,     /**< Process Tls data */
  SCC_ISO20VEHICLECHAINSELECTION_CHECKAPPL    /**< Check application on how to proceed */
}Scc_ISO20VehicleChainSelectionState;

typedef struct
{
  Scc_ISO20PotentialVehicleChainList VehicleChainList[SCC_ISO15118_20_VEHICLE_CERT_CNT]; /**< Matching information of each vehicle cert */
  uint8 VehicleChainListLen;                                          /**< Length of valid VehicleChainList */
  Scc_Core_KeyMUtils_VehicleIssuerContextStructType KeyMUtilsContext; /**< Context used during Tls parsing */
  Scc_ISO20VehicleChainSelectionState CurrentState;                   /**< Current processing state */
  boolean PreferredVehicleChainIdxChosen;                            /**< Flag indicating if Scc was able to select a preferred vehicle chain */
  uint8 PreferredVehicleChainIdx;                                     /**< Scc's preferred vehicle chain index */
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) TmpKeyMBufferPtr;            /**< Temporary buffer, may be used e.g. for KeyM operations */
  uint32 TmpKeyMBufferLen;                                            /**< Temporary buffer length */
}Scc_ISO20VehicleChainSelectionContext;
#endif /* SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL_INLINE)
# define SCC_LOCAL_INLINE LOCAL_INLINE
#endif

#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

 /* [V2G20 - 1003] [...] at most two Sub - CA levels can be used. */
#define SCC_CERT_CHAIN_SUB_CA_MAX_CNT     2u
#define SCC_CERT_CHAIN_SUB_CA_MIN_CNT     1u
#define SCC_CERT_ROOT_AND_LEAF_CNT        2u

#define SCC_MIN_TLS_CERT_CNT              4u /* Leaf + SubCa1 + SubCa2 + Root */

#define SCC_MAX_MSG_STATE_TRANSMIT        4u /* Scc_MsgState_WaitForNextRequest, Scc_MsgState_PrepareMessageData,
                                              * Scc_MsgState_ReadyToSendRequest, Scc_MsgState_SendRequest */

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/
/* 8bit variables - no init */
#define SCC_START_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL volatile VAR(boolean, SCC_VAR_NOINIT) Scc_V2GSocketInUse;

VAR(boolean, SCC_VAR_NOINIT) Scc_TxStreamingActive;

/* Flag indicating the usage of the shadow buffer */
SCC_LOCAL volatile VAR(boolean, SCC_VAR_NOINIT)   Scc_RxUDPShadowBufferUsed;
/* Shadow buffer for UDP receiving */


#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
SCC_LOCAL VAR(uint8, SCC_VAR_NOINIT)   Scc_RxUDPShadowBuffer[SCC_SDP_RES_WIRELESS_LEN];                                 /* PRQA S 3218 */ /* MD_Scc_3218 */
#else
SCC_LOCAL VAR(uint8, SCC_VAR_NOINIT)   Scc_RxUDPShadowBuffer[SCC_SDP_RES_PLC_LEN];                                      /* PRQA S 3218 */ /* MD_Scc_3218 */
#endif /* SCC_WIRELESS_SDP */

SCC_LOCAL volatile VAR(uint8, SCC_VAR_NOINIT) Scc_IPAddressState;

#define SCC_STOP_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* 16bit variables no init */
#define SCC_START_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint16, SCC_VAR_NOINIT) Scc_TimeoutCnt[SCC_CHANNEL_MAX];

#define SCC_STOP_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL volatile VAR(Scc_MsgStateType, SCC_VAR_NOINIT) Scc_ReceiveMsgState;

volatile VAR(Scc_MsgStatusType, SCC_VAR_NOINIT)   Scc_MsgStatus;
volatile VAR(Scc_StackErrorType, SCC_VAR_NOINIT)  Scc_StackError;
VAR(Scc_SDPSecurityType, SCC_VAR_NOINIT) Scc_SelectedConnectionType;                                                    /* PRQA S 1514 */ /* MD_Scc_VariantDependent */

VAR(Scc_PbufType, SCC_VAR_NOINIT)   Scc_ExiStreamRxPBuf[SCC_EXI_RX_STREAM_PBUF_ELEMENTS];

VAR(Scc_SockAddrIn6Type, SCC_VAR_NOINIT) Scc_ServerSockAddr;

VAR(TcpIp_SocketIdType, SCC_VAR_NOINIT) Scc_SDPSocket;
volatile VAR(TcpIp_SocketIdType, SCC_VAR_NOINIT) Scc_V2GSocket;

#if ( (defined SCC_SCHEMA_ISO ) && (SCC_SCHEMA_ISO != 0))
#if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) || (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)
VAR(Scc_CertificateResWSStructType, SCC_VAR_NOINIT) Scc_CertUpdateInstallWs;
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE  */
VAR(Scc_ChargeParameterDiscoveryResWSStructType , SCC_VAR_NOINIT) Scc_ChrgParamDiscWS;
#endif /* SCC_SCHEMA_ISO */

/* Data type to be used with the TCP rx queue */
SCC_LOCAL VAR(Scc_PbufType, SCC_VAR_NOINIT) Scc_RxStreamBuffer_TCP_PBuf[SCC_EXI_RX_STREAM_PBUF_ELEMENTS];               /* PRQA S 3218 */ /* MD_Scc_3218 */
SCC_LOCAL VAR(Scc_RxDataQueueStructType, SCC_VAR_NOINIT) Scc_RxStreamBuffer_TCP;
/* Data type to be used with the UDP rx queue */
SCC_LOCAL VAR(Scc_PbufType, SCC_VAR_NOINIT) Scc_RxStreamBuffer_UDP_PBuf[SCC_EXI_RX_STREAM_UDP_PBUF_ELEMENTS];           /* PRQA S 3218 */ /* MD_Scc_3218 */
SCC_LOCAL VAR(Scc_RxDataQueueStructType, SCC_VAR_NOINIT) Scc_RxStreamBuffer_UDP;
/* Pointer to the rx queue to use */
SCC_LOCAL P2VAR(Scc_RxDataQueueStructType, AUTOMATIC, SCC_VAR_NOINIT) Scc_V2GTpRxQueuePtr;                              /* PRQA S 3218 */ /* MD_Scc_3218 */
/* V2GTP Header of the current message */
SCC_LOCAL VAR(Scc_V2GTPHeaderStructType, SCC_VAR_NOINIT) Scc_V2GTpHeader;                                               /* PRQA S 3218 */ /* MD_Scc_3218 */
/* Current rx configuration */
VAR(Scc_RxConfigStructType, SCC_VAR_NOINIT) Scc_RxConfig;
/* Variable for choosing LocalAddrId */
VAR(TcpIp_LocalAddrIdType, SCC_VAR_NOINIT) Scc_LocalAddrId;

#if (defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
SCC_LOCAL VAR(Scc_ISO20VehicleChainSelectionContext, SCC_VAR_NOINIT) Scc_ISO20VehicleChainCtx;
#endif /* SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* 8bit variables - zero init */
#define SCC_START_SEC_VAR_CLEARED_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
SCC_LOCAL volatile VAR(Slac_DLinkStatusType, SCC_VAR_ZERO_INIT)          Scc_DLinkReady = Slac_DLS_NoLink;
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if (defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) \
 || (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
SCC_LOCAL VAR(uint8, SCC_VAR_ZERO_INIT) Scc_ProcCertInstResHeaderByteArray[SCC_V2GTP_HDR_LEN] = { 0 };                  /* PRQA S 3218 */ /* MD_Scc_3218 */
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#define SCC_STOP_SEC_VAR_CLEARED_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* 8bit variables - zero init for the NvM */
#define SCC_START_SEC_VAR_CLEARED_8_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, SCC_VAR_ZERO_INIT) Scc_SessionIDNvm[SCC_SESSION_ID_NVM_BLOCK_LEN] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#define SCC_STOP_SEC_VAR_CLEARED_8_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* 16 bit variables - zero init */
#define SCC_START_SEC_VAR_CLEARED_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL volatile VAR(uint16, SCC_VAR_NOINIT) Scc_TimeoutCntOnHold = 0u;

#define SCC_STOP_SEC_VAR_CLEARED_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* unspecified variables - zero init */
#define SCC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
SCC_LOCAL volatile VAR(Scc_PlcChipFirmwareStatusType, SCC_VAR_ZERO_INIT) Scc_PlcChipFirmwareStatus = Scc_PlcChipFirmwareStatus_Unknown;
#endif /* SCC_ENABLE_SLAC_HANDLING */

volatile VAR(Scc_StateType, SCC_VAR_ZERO_INIT) Scc_State = Scc_State_Uninitialized;

#if (SCC_ENABLE_PNC_CHARGING == STD_ON)
SCC_LOCAL VAR(Scc_Core_KeyMUtils_UpdateStateEnumType, SCC_VAR_ZERO_INIT) Scc_OEMProvUpdateState = SCC_CORE_KEYMUTILS_IDLE;
#endif /* SCC_ENABLE_PNC_CHARGING */

#define SCC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* 8bit variables - const - nvm */
#define SCC_START_SEC_CONST_8_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(uint8, SCC_CONST) Scc_SessionIDNvmRomDefault[SCC_SESSION_ID_NVM_BLOCK_LEN] = {                                    /* PRQA S 1502 */ /* MD_SCC_NvmArrayNotUsed */
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#define SCC_STOP_SEC_CONST_8_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_TLS == STD_ON )
#define SCC_START_SEC_CONST_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u)
SCC_LOCAL CONST(Scc_StringStructType, SCC_CONST) Scc_SECCLeafCPOValue =                                                 /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  3u,
  (const uint8*) "CPO"
};
#endif /* SCC_SCHEMA_ISO */
# if (defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u))
SCC_LOCAL CONST(Scc_StringStructType, SCC_CONST) Scc_SECCLeafCSOValue =                                                 /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  3u,
  (const uint8*) "CSO"
};
# endif /* SCC_SCHEMA_ISO_20 */

#define SCC_STOP_SEC_CONST_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* SCC_ENABLE_TLS */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3458 MACROS_BRACES */ /* MD_Scc_20.4 */
/* PRQA S 3473 FCT_LIKE_MACROS */ /* MD_MSR_FctLikeMacro */

#define Scc_MsgStateFct(MsgStateNew) \
  { Scc_Core_Channel_Set_MsgState(MsgStateNew); Scc_Core_InterfaceCfg_Set_MsgState(MsgStateNew); }


#define Scc_MsgStateFct_EA2(MsgStateNew) \
  { SCC_ENTER_EXCLUSIVE_AREA_2(); Scc_Core_Channel_Set_MsgState(MsgStateNew); SCC_LEAVE_EXCLUSIVE_AREA_2(); Scc_Core_InterfaceCfg_Set_MsgState((MsgStateNew)); }

/* PRQA L:MACROS_BRACES */
/* PRQA L:FCT_LIKE_MACROS */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_Reset
 *********************************************************************************************************************/
/*! \brief         Reset the Scc Module and all global parameters.
 *  \details        Close UDP and TCP socket and reset all state and message relevant parameters
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_Reset(void);

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_TriggerSLAC
 *********************************************************************************************************************/
/*! \brief         Starts SLAC handling
 *  \details        Checks if link is established and firmware download is finished and starts then SLAC.
 *  \param[in]      MsgTrig     Message trigger
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_TriggerSLAC(Scc_MsgTrigType MsgTrig);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON ) || (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_TriggerCerts
 *********************************************************************************************************************/
/*! \brief          Read the certificates from the NvM
 *  \details        Read the root, contract and provisioning certificates from the NvM, depending on the Message Trigger.
 *  \param[in]      MsgTrig     Message trigger
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_TriggerCerts(Scc_MsgTrigType MsgTrig);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_TriggerV2G
 *********************************************************************************************************************/
/*! \brief         Triggers the transmit of a V2G Message
 *  \details        Transmit the V2G message depending on the Message Trigger
 *  \param[in]      MsgTrig     Message trigger
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_TriggerV2G(Scc_MsgTrigType MsgTrig);

/**********************************************************************************************************************
 *  Scc_EstablishTLConnection
 *********************************************************************************************************************/
/*! \brief         Configure the Tcp socket
 *  \details        Configure the Rx/Tx buffer for TCP or TLS. Binds the socket and starts connection.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_EstablishTLConnection(void);

/**********************************************************************************************************************
 *  Scc_TcpTransmit
 *********************************************************************************************************************/
/*! \brief         Trigger TcpIp transmit
 *  \details        Transmit the whole message or return pending if message needs to be streamed.
 *  \return         E_OK            Tcp send whole message
 *  \return         PENDING         message did not fit into first Tcp package
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_TcpTransmit(void);

/**********************************************************************************************************************
 *  Scc_Rx_TcpRelease
 *********************************************************************************************************************/
/*! \brief         Releases the TCP buffer
 *  \details        -
 *  \param[in]      Length   The amount of consumed bytes
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_Rx_TcpRelease(
  CONST(uint32, AUTOMATIC) Length);

/**********************************************************************************************************************
 *  Scc_Rx_UdpRelease
 *********************************************************************************************************************/
/*! \brief         Releases the UDP shadow buffer
 *  \details        -
 *  \param[in]      Length   The amount of consumed bytes
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_Rx_UdpRelease(
  CONST(uint32, AUTOMATIC) Length);

/**********************************************************************************************************************
 *  Scc_PrepareMessageData
 *********************************************************************************************************************/
/*! \brief          Helper function for the state Scc_MsgState_PrepareMessageData
 *  \details        -
 *  \param[in]      MsgTrig     Message trigger
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_PrepareMessageData(Scc_MsgTrigType MsgTrig);

/**********************************************************************************************************************
 *  Scc_ProcessTransmissionData
 *********************************************************************************************************************/
/*! \brief          Checks and triggers a request message transmission based on the state machine.
 *  \details        -
 *  \param[in]      MsgTrig     Message trigger
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessTransmissionData(Scc_MsgTrigType MsgTrig);

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_WaitingForV2GTpHeader
 *********************************************************************************************************************/
/*! \brief          Waits for V2GTpHeader. If received then changes state to CheckV2GTpHeader.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData_WaitingForV2GTpHeader(void);

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_CheckV2GTpHeader
 *********************************************************************************************************************/
/*! \brief          Check the received V2GTPHeader for validity
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData_CheckV2GTpHeader(void);

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_WaitingForMessageData
 *********************************************************************************************************************/
/*! \brief          Waits for message data. If received then changes state to HandleResponseData.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData_WaitingForMessageData(void);

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_HandleResponseData
 *********************************************************************************************************************/
/*! \brief          Processes response messages from received message queue.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_CODE) Scc_ProcessReceptionData_HandleResponseData(void);

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_DiscardV2GTpHeader
 *********************************************************************************************************************/
/*! \brief          Discards a V2GTPHeader from the Rx queue (excluding message data).
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData_DiscardV2GTpHeader(void);

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_DiscardMessageData
 *********************************************************************************************************************/
/*! \brief          Discards a V2G message from the Rx queue (excluding the header).
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData_DiscardMessageData(void);

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData
 *********************************************************************************************************************/
/*! \brief          Processes response messages from received message queue.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData(void);

#if ( defined SCC_ENABLE_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) \
 || (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
/**********************************************************************************************************************
 *  Scc_ProcessCertificateInstallationResDecode
 *********************************************************************************************************************/
/*! \brief          Prepares message processing and decodes the passed exi stream as a certificate
 *                  installation response message
 *  \details        -
 *  \param[in]      ExiStreamPtr      Pointer to Exi stream to decode
 *  \param[in]      ExiStreamPtrLen   Length of Exi stream
 *  \param[in]      SchemaToUse       Schema to use
 *  \param[in,out]  RxWsPtr           Rx workspace to use. Pointer to decoded message is stored in this workspace.
 *  \return         Ok                Message decoded
 *  \return         NotOk             Error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ProcessCertificateInstallationResDecode(
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ExiStreamPtr,
  CONST(uint16, AUTOMATIC) ExiStreamPtrLen,
  CONST(Scc_ProcessCertInstResEnumType, AUTOMATIC) SchemaToUse,
  CONSTP2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxWsPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ( SCC_ENABLE_TLS == STD_ON )
# if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
/**********************************************************************************************************************
 *  Scc_CompareSessionResumeHash
 *********************************************************************************************************************/
/*! \brief          Checks if Hashes match. If not then resumeSession is set to FALSE
 *  \details        -
 *  \param[in]      CalculatedHashPtr      Pointer to calculated Hash
 *  \param[in]      CalculatedHashLen      Length of the Hash
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS, SCC_SCHEMA_ISO_20
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_CompareSessionResumeHash(
  CONSTP2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) CalculatedHashPtr,
  uint32 CalculatedHashLen);

/**********************************************************************************************************************
 *  Scc_ComputeSessionResume_Helper
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_ComputeSessionResume.
 *  \details        -
 *  \param[in]      CalculatedHashPtr      Pointer to the calculated hash
 *  \param[in]      CalculatedHashLen      Length of the caluculated hash
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS, SCC_SCHEMA_ISO_20
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ComputeSessionResume_Helper(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) CalculatedHashPtr,
  uint32 CalculatedHashLen);

/**********************************************************************************************************************
 *  Scc_ComputeSessionResume
 *********************************************************************************************************************/
/*! \brief          Checks if Hashes match in case session resume was set to true.
 *  \details        -
 *  \param[in]      CertId      CertId of the leaf contract certificate used in Tls handshake
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS, SCC_SCHEMA_ISO_20
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ComputeSessionResume(TcpIp_CertificateIdType CertId);
# endif

/**********************************************************************************************************************
 *  Scc_TLS_HandleConnectionInfo
 *********************************************************************************************************************/
/*! \brief          Checks if the TLS connection parameters are as expected.
 *  \details        -
 *  \param[in]      TlsConnectionInfoPtr  Pointer to the TLS connection parameter.
 *  \param[in,out]  ValidationResultPtr   Result of the parameter check.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_TLS_HandleConnectionInfo(
  P2CONST(TcpIp_TlsConnectionInfoType, AUTOMATIC, SCC_APPL_DATA)  TlsConnectionInfoPtr,
  P2VAR(TcpIp_CertValidationResultType, AUTOMATIC, SCC_APPL_DATA) ValidationResultPtr);

/**********************************************************************************************************************
 *  Scc_TLS_CheckIfPECert
 *********************************************************************************************************************/
/*! \brief          Checks if the received TLS certificates are private environment certificates.
 *  \details        -
 *  \param[in]      NumCerts               Number of certificates received in Tls handshake
 *  \param[in]      CertChainStatusPtr     Pointer to the certificate chain(KeyM certId etc)
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_CODE) Scc_TLS_CheckIfPECert(
  uint32                                      NumCerts,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA)   CertChainStatusPtr);
#endif /* SCC_ENABLE_TLS */

#if (defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
/**********************************************************************************************************************
 *  Scc_InitISO20VehicleChainContext
 *********************************************************************************************************************/
/*! \brief          Initializes the context used to handle vehicle chain selection.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_InitISO20VehicleChainContext(void);

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_Clear
 *********************************************************************************************************************/
/*! \brief          Clears/resets the passed vehicle chain list.
 *  \details        -
 *  \param[in,out]  VehicleChainPtr      List to clear/reset.
 *  \param[in]      VehicleChainLen      List length.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO20VehicleChainList_Clear(
  P2VAR(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainPtr,
  uint8 VehicleChainLen);

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_ContainsAtLeastOneUsable
 *********************************************************************************************************************/
/*! \brief          Checks whether at least one entry is present that could be used in Tls handshake.
 *  \details        -
 *  \param[in]      VehicleChainPtr      List to check.
 *  \param[in]      VehicleChainLen      List length.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_CODE) Scc_ISO20VehicleChainList_ContainsAtLeastOneUsable(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainPtr,
  uint8 VehicleChainLen);

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_FilterOnSignatureHash
 *********************************************************************************************************************/
/*! \brief          Filters available vehicle chain entries based on passed signature and hash algos.
 *  \details        -
 *  \param[in]      VehicleChainPtr               Pointer to a single list entry that is tested.
 *  \param[in]      SignatureAndHashAlgoListPtr   List of EVSE supported signature and hash algos.
 *  \param[in]      SignatureAndHashAlgoNum       Number of algos contained in list.
 *  \return         TRUE      Vehicle chain matches at least one supported algorithm.
 *  \return         FALSE     No matching algorithm found.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_CODE) Scc_ISO20VehicleChainList_FilterOnSignatureHash(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainPtr,
  P2CONST(uint16, AUTOMATIC, SCC_CONST) SignatureAndHashAlgoListPtr,
  uint16 SignatureAndHashAlgoNum);

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_FilterOnProvidedCAs
 *********************************************************************************************************************/
/*! \brief          Filters available vehicle chain entries based on passed known EVSE CAs.
 *  \details        -
 *  \param[in,out]  ContextPtr         Context to use.
 *  \param[in]      AuthorityListPtr   List of CAs known by EVSE.
 *  \param[in]      AuthorityListLen   Number of entries in list.
 *  \return         Scc_ReturnType_OK     Operation has finished.
 *  \return         Scc_ReturnType_NotOK  Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO20VehicleChainList_FilterOnProvidedCAs(
  P2VAR(Scc_ISO20VehicleChainSelectionContext, AUTOMATIC, SCC_APPL_DATA) ContextPtr,
  P2CONST(TcpIp_TlsDistiguishedNameInfoType, AUTOMATIC, SCC_CONST) AuthorityListPtr,
  uint16 AuthorityListLen);

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_Process
 *********************************************************************************************************************/
/*! \brief          Process the vehicle chain parameters based on data received in Tls handshake.
 *  \details        -
 *  \param[in,out]  ContextPtr          Context to use.
 *  \param[in]      RequestInfoPtr      Data received in Tls handshake.
 *  \param[in]      MaxLenOfOutputCert  Maximum number of certificates Tls is able to handle.
 *  \return         Scc_ReturnType_OK      Operation succeeded.
 *  \return         Scc_ReturnType_NotOK   Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO20VehicleChainList_Process(
  P2VAR(Scc_ISO20VehicleChainSelectionContext, AUTOMATIC, SCC_APPL_DATA) ContextPtr,
  P2CONST(TcpIp_TlsCertRequestInfoType, AUTOMATIC, SCC_CONST) RequestInfoPtr,
  uint8 MaxLenOfOutputCert);

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_RemoveRejectedEllipticCurvesFromVehicleChainList
 *********************************************************************************************************************/
/*! \brief          Removes certificate chains based on a rejected elliptic curve from the potential vehicle chain list.
 *  \details        -
 *  \param[in,out]  VehicleChainListPtr  List to select from.
 *  \param[in,out]  VehicleChainListLen  List length.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO20VehicleChainList_RemoveRejectedEllipticCurvesFromVehicleChainList(
  P2VAR(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainListPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) VehicleChainListLen);

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_SelectPreferredVehicleChain
 *********************************************************************************************************************/
/*! \brief          Selects the preferred chain by Scc.
 *  \details        -
 *  \param[in]      VehicleChainListPtr  List to select from.
 *  \param[in]      VehicleChainListLen  List length.
 *  \param[out]     PreferredChosen      TRUE: A selection was done. FALSE: No selection possible.
 *  \param[out]     PreferredIdx         Id of selected vehicle chain.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO20VehicleChainList_SelectPreferredVehicleChain(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainListPtr,
  uint8 VehicleChainListLen,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) PreferredChosen,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) PreferredIdx);

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_HandlePushButtonMode
 *********************************************************************************************************************/
/*! \brief          Add root certificate to vehicle chain if push button mode is active
 *  \details        -
 *  \param[in]      SelectedVehicleChain   Vehicle chain selected previously.
 *  \param[in,out]  TlsCertsPtr            Tls cert pointer to setup.
 *  \return         Scc_ReturnType_OK      Operation succeeded. Root cert is added to TlsCertsPtr.
 *  \return         Scc_ReturnType_NotOK   Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO20VehicleChainList_HandlePushButtonMode(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) SelectedVehicleChain,
  P2VAR(TcpIp_TlsClientCertInfoType, AUTOMATIC, SCC_APPL_DATA) TlsCertsPtr);

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_HandleApplication
 *********************************************************************************************************************/
/*! \brief          Ask application on how to proceed.
 *  \details        -
 *  \param[in]      VehicleChainListPtr  List to select from.
 *  \param[in]      VehicleChainListLen  List length.
 *  \param[in]      PreferredIdxChosen  Flag indicating if PreferredIdx contains valid data.
 *  \param[in]      PreferredIdx         Id of preferred vehicle chain.
 *  \param[in,out]  TlsCertsPtr          Tls cert pointer to setup.
 *  \return         Scc_ReturnType_OK      Operation succeeded. TlsCertsPtr is filled with chosen vehicle chain.
 *  \return         Scc_ReturnType_Pending Operation is ongoing, try again later.
 *  \return         Scc_ReturnType_NotOK   Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO20VehicleChainList_HandleApplication(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainListPtr,
  uint8 VehicleChainListLen,
  boolean PreferredIdxChosen,
  uint8 PreferredIdx,
  P2VAR(TcpIp_TlsClientCertInfoType, AUTOMATIC, SCC_APPL_DATA) TlsCertsPtr);
#endif /* SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_LeavePLCNetwork
 *********************************************************************************************************************/
/*! \brief         Leaves the PLC network
 *  \details        Leaves the PLC network if the application tells to do so.
 *  \param[in]      MsgTrig                   Message trigger
 *                  MsgState_IfSuccessful     Message state if Leaving was successful.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_LeavePLCNetwork(
  Scc_MsgTrigType MsgTrig,
  Scc_MsgStatusType MsgState_IfSuccessful);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if (SCC_ENABLE_OCSP == STD_ON)
/**********************************************************************************************************************
 *  Scc_CheckOcspValidity
 *********************************************************************************************************************/
/*! \brief          Checks the Ocsp validity for a server certificate chain.
 *  \details        Checks the Ocsp information and differs further between Ocsp mode single and multi.
 *  \param[in]      tlsLeafCertCfgPtr      Pointer to the received leaf certificate in Tls handshake.
 *  \param[in]      NumCerts               Number of certificates received in Tls handshake
 *  \param[in]      CertChainStatusPtr     Pointer to the certificate chain(KeyM certId etc)
 *  \param[in,out]  validationResultPtr    Validation result (VALIDATION_OK etc.)
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_OCSP
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_CheckOcspValidity(
  P2CONST(Scc_TlsCertStructType, AUTOMATIC, SCC_CONST)                  tlsLeafCertCfgPtr,
  uint32                                                                NumCerts,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA)     CertChainStatusPtr,
  P2VAR(TcpIp_CertValidationResultType, AUTOMATIC, SCC_APPL_DATA)       ValidationResultPtr);
#endif /* SCC_ENABLE_OCSP == STD_ON */

#if ( ( (defined SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON) ) && ( (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u) ) )
/**********************************************************************************************************************
 *  Scc_CheckTlsCertsForRejectedEllipticCurves
 *********************************************************************************************************************/
/*! \brief          Checks if any of the active Tls certificates use a rejected elliptic curve.
 *  \details        Checks if any of the active Tls certificates use a rejected elliptic curve.
 *  \param[in,out]  validationResultPtr    Validation result (VALIDATION_OK etc.)
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS, SCC_SCHEMA_ISO_20
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_CheckTlsCertsForRejectedEllipticCurves(
  P2VAR(TcpIp_CertValidationResultType, AUTOMATIC, SCC_APPL_DATA) ValidationResultPtr);
#endif /* SCC_ENABLE_TLS, SCC_SCHEMA_ISO_20 */

/**********************************************************************************************************************
 *  Scc_TimeoutHandling_SECCDiscoveryProtocol
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_TimeoutHandling
 *  \details        Check if a timeout occured and report the timeout.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_TimeoutHandling_SECCDiscoveryProtocol(void);

/**********************************************************************************************************************
 *  Scc_OnHoldTimeoutHandling
 *********************************************************************************************************************/
/*! \brief          Check if a timeout occured while onHold is active.
 *  \details        Check if a timeout occured and report the timeout.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_OnHoldTimeoutHandling(void);

#if ((defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) || \
     (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON)))
/**********************************************************************************************************************
 *  Scc_ProcessCertificateInstallationRes_HelperFirstCall
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_ProcessCertificateInstallationRes. Decodes message in case FirstCall
 *  \details        -
 *  \param[in]      ExiStreamPtr    Exi stream containing the certificate installation response to process.
 *  \param[in]      ExiStreamPtrLen Length of the Exi stream.
 *  \param[in]      SchemaToUse     The schema of the certificate installation message.
 *  \param[in]      FirstCall       If this is the first call set this flag to TRUE, otherwise FALSE.
 *  \return         OK             Processing finished and contract is installed.
 *  \return         Pending        Processing is ongoing, call this API again at later point in time.
 *  \return         NotOK          Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ProcessCertificateInstallationRes_HelperFirstCall(
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ExiStreamPtr,
  CONST(uint16, AUTOMATIC) ExiStreamPtrLen,
  CONST(Scc_ProcessCertInstResEnumType, AUTOMATIC) SchemaToUse,
  CONST(boolean, AUTOMATIC) FirstCall);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_GetVersionInfo
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
#if ( defined SCC_VERSION_INFO_API ) && ( SCC_VERSION_INFO_API == STD_ON )
FUNC(void, SCC_CODE) Scc_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SCC_APPL_DATA) VersionInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters. */
  if ( VersionInfoPtr == NULL_PTR )
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else if ( Scc_State == Scc_State_Uninitialized )
  {
    errorId = SCC_DET_NOT_INITIALIZED;
  }
  else
# endif /* SCC_DEV_ERROR_DETECT == STD_ON */
  {
  /* ----- Implementation ----------------------------------------------- */

    /* #20 Set VersionInfo structure with corresponding macros. */
    VersionInfoPtr->vendorID   = SCC_VENDOR_ID;
    VersionInfoPtr->moduleID   = SCC_MODULE_ID;
    VersionInfoPtr->sw_major_version = SCC_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = SCC_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = SCC_SW_PATCH_VERSION;
  }
  /* ----- Development Error Report --------------------------------------- */
# if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #30 Report default errors if any occurred. */
  if ( errorId != SCC_DET_NO_ERROR )
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_GET_VERSION_INFO, errorId);
  }
# else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif /* SCC_DEV_ERROR_REPORT */
}  /*lint !e438 */ /* MD_MSR_DummyStmt */
#endif /* SCC_VERSION_INFO_API */

/**********************************************************************************************************************
 *  Scc_InitMemory
 *********************************************************************************************************************/
  /*!
   *
   * Internal comment removed.
 *
 *
 *
 *
   */
FUNC(void, SCC_CODE) Scc_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set module state to uninitialized. */
  Scc_State = Scc_State_Uninitialized;

  /* #20 Initialize local data. */
  Scc_IPAddressState = TCPIP_IPADDR_STATE_UNASSIGNED;
  Scc_TimeoutCntOnHold = 0u;

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
  Scc_PlcChipFirmwareStatus = Scc_PlcChipFirmwareStatus_Unknown;
  Scc_DLinkReady                  = Slac_DLS_NoLink;
#endif /* SCC_ENABLE_SLAC_HANDLING */

  /* #30 call InitMemory for StateMachine. */
#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )
  Scc_StateM_InitMemory();
#endif /* SCC_ENABLE_STATE_MACHINE */
}

/**********************************************************************************************************************
 *  Scc_Init
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
 */
FUNC(void, SCC_CODE) Scc_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize general data. */
  Scc_V2GSocketInUse = FALSE;
  Scc_SDPSocket      = (Scc_SocketType)TCPIP_INV_SOCKET_ID;
  Scc_V2GSocket      = (Scc_SocketType)TCPIP_INV_SOCKET_ID;
  Scc_LocalAddrId    = (TcpIp_LocalAddrIdType)SCC_IPV6_ADDRESS1;

#if (SCC_ENABLE_PNC_CHARGING == STD_ON) || (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
  {
    uint8_least jobIndex;
    for (jobIndex = 0; jobIndex < (uint8_least)(sizeof(Scc_CsmJobInfo) / sizeof(Scc_CsmJobInfo[0])); jobIndex++)
    {
      Scc_CsmJobInfo[jobIndex].State = SCC_CSMJOBSTATE_IDLE;
      Scc_CsmJobInfo[jobIndex].Usage = SCC_CSMJOBUSAGE_SCC;
      Scc_CsmJobInfo[jobIndex].IsCancelled = FALSE;
    }
  }
#endif

  /* #20 initialize the core parameters */
  Scc_Reset();

  /* #30 initialize the contract certificate chain */
#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
  (void) Scc_SwapContrCertChain(0, TRUE, TRUE);
#endif

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
  (void) Scc_SwapContrCertChain(0, TRUE, FALSE);
#endif

  /* #40 initialize Scc_Priv. */
  Scc_Priv_Init();
  /* #50 initialize Scc_Exi_TempBufPos. */
  Scc_Exi_Init();
#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )                                                               /* PRQA S 3332 */ /* MD_Scc_3332 */
  /* #60 initialize the message pointer for ISO-2 */
  Scc_ISO15118_2_ExiTx_Init();
#endif /* SCC_SCHEMA_ISO */
#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )                                                         /* PRQA S 3332 */ /* MD_Scc_3332 */
  Scc_ISO15118_20CM_ExiTx_Init();
#endif /* SCC_SCHEMA_ISO_20 */

#if ( defined SCC_ENABLE_STATE_MACHINE ) && ( SCC_ENABLE_STATE_MACHINE == STD_ON )
  Scc_StateM_Init();
#endif /* SCC_ENABLE_STATE_MACHINE */

#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
# if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING != 0 )
  Scc_ChosenCert.OemCertId = 0;
# endif
#endif

#if (defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
  Scc_InitISO20VehicleChainContext();
#endif /* SCC_ENABLE_TLS_ISO20_CLIENTAUTH */
}

#if (defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
/**********************************************************************************************************************
 *  Scc_InitISO20VehicleChainContext
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_InitISO20VehicleChainContext(void)
{
  /* #10 Initalize context */
  Scc_ISO20VehicleChainCtx.CurrentState = SCC_ISO20VEHICLECHAINSELECTION_PROCESS;
  /* Exi temp buffer can be used as at the point in time client auth is handled
   * No Exi messages are exchanged as transport layer connection is not yet
   * established. */
  Scc_ISO20VehicleChainCtx.TmpKeyMBufferPtr = &Scc_Exi_TempBufUnion.Buf8[0];
  Scc_ISO20VehicleChainCtx.TmpKeyMBufferLen = sizeof(Scc_Exi_TempBufUnion.Buf8);
  Scc_ISO20VehicleChainList_Clear(&Scc_ISO20VehicleChainCtx.VehicleChainList[0], SCC_ISO15118_20_VEHICLE_CERT_CNT);
  Scc_ISO20VehicleChainCtx.VehicleChainListLen = SCC_ISO15118_20_VEHICLE_CERT_CNT;
  Scc_Core_KeyMUtils_InitVehicleChainContext(&Scc_ISO20VehicleChainCtx.KeyMUtilsContext);
}
#endif /* SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

/**********************************************************************************************************************
 *  Scc_MainFunction
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
/* PRQA S 6030,6050,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
FUNC(void, SCC_CODE) Scc_MainFunction(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least     index = 0;
  boolean         cyclicMsgTrig = FALSE;
  Scc_MsgTrigType msgTrig = Scc_MsgTrig_None;
  Scc_CoreChannelType channel;

  /* ----- Implementation ----------------------------------------------- */
  if ( Scc_State != Scc_State_Uninitialized )
  {
    /* Check if timeout is not elapsed and process reception path */
    Scc_ProcessReceptionData();

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )
    Scc_StateM_MainFunction();
#endif

    /* #10 Iterate for number of channels */
    for (; index < (uint8_least)SCC_CHANNEL_MAX; index++)
    {
      channel = (Scc_CoreChannelType)index;                                                                             /* PRQA S 4342 */ /* MD_SCC_CORE_CHANNEL_ENUM */

      if (Scc_Core_Channel_IsChannelEnabled(channel) == TRUE)
      {
        Scc_Core_Channel_Set_CurrentChannel((uint8)index);

        /* #20 get the current message trigger. */
        Scc_Core_InterfaceCfg_Get_MsgTrig(&msgTrig);
        Scc_Core_InterfaceCfg_Get_CyclicMsgTrigRx(&cyclicMsgTrig);
        Scc_Core_Channel_Set_CyclicMsgTrig(cyclicMsgTrig);

        /* #30 Check if message triggers are valid for parallel channels */
        if (Scc_Core_Channel_IsMessageTrigValid(channel, msgTrig) == FALSE)
        {
#if(SCC_DEV_ERROR_REPORT == STD_ON)
          /* Set Det error since message trigger is invalid */
          (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_MAIN_FUNCTION, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
        }
        else
        {
          switch (msgTrig)
          {
            /* #40 check if the SCC should be reset */
          case Scc_MsgTrig_None:
            /* check if this trigger is new */
            if ( (Scc_Core_Channel_Get_MsgTrig() != msgTrig)
              || (TRUE == cyclicMsgTrig) )
            {
              /* accept the new trigger */
              Scc_Core_Channel_Set_MsgTrig(msgTrig);
              /* Check if the channel is the default channel */
              if (channel == SCC_CHANNEL_DEFAULT)                                                                       /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
              {
                /* reset the core module */
                Scc_Reset();
              }
              /* reset the cyclic message trigger at the application */
              Scc_Core_InterfaceCfg_Set_CyclicMsgTrigTx(FALSE);
            }
            break;

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
          case Scc_MsgTrig_SLAC:
            Scc_TriggerSLAC(msgTrig);
            break;
#endif /* SCC_ENABLE_SLAC_HANDLING */

            /* #50 read certificates from NvM. */
#if ( (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) \
   || (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON) \
   || (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON) )
          case Scc_MsgTrig_ReadRootCerts:
          case Scc_MsgTrig_ReadOemProvCert:
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#if (SCC_ENABLE_PNC_CHARGING == STD_ON) || (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
          case Scc_MsgTrig_ReadContrCertChain:
            Scc_TriggerCerts(msgTrig);
            break;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
          case Scc_MsgTrig_LeavePLCNetwork:
            Scc_LeavePLCNetwork(msgTrig, Scc_MsgStatus_LeavePLCNetwork_OK);
            break;
          case Scc_MsgTrig_Error_LeavePLCNetwork:
            Scc_LeavePLCNetwork(msgTrig, Scc_MsgStatus_Error_LeavePLCNetwork_OK);
            break;
#endif /* SCC_ENABLE_SLAC_HANDLING */

            /* #60 handle V2G messages. */
          default:
            /* only check V2G message triggers if an IP address is assigned */
            SCC_ENTER_EXCLUSIVE_AREA_2();
            /* PRQA S 3415 2  */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
            if ( (Scc_State_Initialized <= Scc_State)
              && (Scc_IPAddressState == TCPIP_IPADDR_STATE_ASSIGNED) )
            {
              Scc_MsgStateType msgState = Scc_Core_Channel_Get_MsgState(channel);
              /* #70 Perform timeout monitoring when waiting for a message */
              /* PRQA S 3415 1 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
              if ( (msgState == Scc_MsgState_WaitingForV2GTpHeader)
                || (msgState == Scc_MsgState_CheckV2GTpHeader)
                || (msgState == Scc_MsgState_WaitingForMessageData) )
              {
                SCC_LEAVE_EXCLUSIVE_AREA_2();
                Scc_Core_Channel_TimeoutHandling();
              }
              else
              {
                SCC_LEAVE_EXCLUSIVE_AREA_2();
              }

              if (Scc_Core_Channel_Get_TimeoutRetval() == E_OK)
              {
                /* No Timeout occurred */
                Scc_ProcessTransmissionData(msgTrig);
              }
            }
            else
            {
              SCC_LEAVE_EXCLUSIVE_AREA_2();
            }
            break;
          }
        }
        Scc_Core_InterfaceCfg_Set_FinishProcessingCurrentChannel(channel);
      }
    }

    Scc_OnHoldTimeoutHandling();
  }
}

/**********************************************************************************************************************
 *  Scc_PrepareMessageData
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
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_PrepareMessageData(Scc_MsgTrigType MsgTrig)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  Scc_CoreChannelType currentChannel = Scc_Core_Channel_Get_CurrentChannel();
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) txMsgWS = Scc_Core_Channel_Get_TxMsgWSPtr(currentChannel);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the message to be sent */
  /* #20 Check if message trigger is SAP message */
  if (MsgTrig == Scc_MsgTrig_SupportedAppProtocol)
  {
    /* #30 Prepare SAP */
    retVal = Scc_SAP_ExiTx_PrepareSupportedAppProtocolReq(txMsgWS);
  }
  /* #40 Otherwise prepare EXI message */
  else
  {
    retVal = (*Scc_ExiTx_Xyz_PrepareMessageFctPtr)(txMsgWS);
  }
  /* #50 Check if preparing the message was successful */
  if (retVal == Scc_ReturnType_OK)
  {
    /* #60 Since a new message trigger was received, go to state SendRequest */
    Scc_MsgStateFct_EA2(Scc_MsgState_ReadyToSendRequest)
  }
  /* #70 Check if preparing the message was not successfull */
  else if (retVal == Scc_ReturnType_NotOK)
  {
    uint8 bufferPoolId = Scc_Core_Channel_Get_BufferPoolId();
    if (bufferPoolId != SCC_INVALID_BUFFER_POOL_ID)
    {
      Scc_BufferPoolRelease(bufferPoolId);
      Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
    }
    /* #80 Reset MsgState */
    Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest)
  }
  else
  {
    /* Nothing to do */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ProcessTransmissionData
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
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessTransmissionData(Scc_MsgTrigType MsgTrig)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  uint8_least    maxLoopCount = 0u;
  uint8_least    index = 0u;
  const Scc_CoreChannelType currentChannel = Scc_Core_Channel_Get_CurrentChannel();
  const Scc_MsgStateType msgState = Scc_Core_Channel_Get_MsgState(currentChannel);

  /* ----- Implementation ----------------------------------------------- */
  maxLoopCount = (uint8_least)SCC_NUM_STATES_IN_PROCESS_TRANSMIT;
  /* #10 Limit the number of states that can be processed per main function */
  if (maxLoopCount > (uint8_least)SCC_MAX_MSG_STATE_TRANSMIT)                                                           /* PRQA S 2992, 2996 */ /* MD_Scc_VariantDependent */
  {
    maxLoopCount = (uint8_least)SCC_MAX_MSG_STATE_TRANSMIT;                                                             /* PRQA S 2880 */ /* MD_Scc_VariantDependent */
  }

  /* #20 Iterate number of states */
  for (; index < maxLoopCount; index++)
  {
    switch (Scc_Core_Channel_Get_MsgState(currentChannel))
    {
      /* #30 Wait till next request is to be sent */
    case Scc_MsgState_WaitForNextRequest:
      /* #40 Check if another channel is not sending a request message */
      Scc_TriggerV2G(MsgTrig);
      break;

    case Scc_MsgState_PrepareMessageData:
      retVal = Scc_PrepareMessageData(MsgTrig);
      break;

    case Scc_MsgState_ReadyToSendRequest:
      /* #50 Check if the previous channel message is completely sent */
      if (Scc_Exi_Get_SendDataState() == Scc_SendDataState_Done)
      {
        /* #60 reset the length of the transmitted data and SendDataState */
        Scc_Core_Channel_Set_TxDataSent(0);
        Scc_Exi_Set_SendDataState(Scc_SendDataState_Init);
        /* #70 Since a new message trigger was received, go to state SendRequest */
        Scc_MsgStateFct_EA2(Scc_MsgState_SendRequest)
      }
      break;

    case Scc_MsgState_SendRequest:
      /* #80 Check if sending the data was successful */
      if (Scc_ReturnType_OK == Scc_TcpTransmit())
      {
        /* #90 Move to state WaitingForV2GTpHeader */
        Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader)
      }
      break;

      /* check if a request was sent and the response is still pending */
    default:
      /* Nothing to do */
      break;
    }

    /* #100 Check if message state is not changed OR something went wrong in PrepareMessageData */
    if ( (msgState == Scc_Core_Channel_Get_MsgState(currentChannel))
      || (retVal != Scc_ReturnType_OK) )
    {
      /* #110 Break the for loop */
      break;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_WaitingForV2GTpHeader
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
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData_WaitingForV2GTpHeader(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  Scc_V2GTpRxQueuePtr = NULL_PTR;

  SCC_ENTER_EXCLUSIVE_AREA_2();
  /* #10 Fetch data from input queue */
  if (Scc_Rx_Queue_GetNumOfBytes(&Scc_RxStreamBuffer_TCP) >= SCC_V2GTP_HDR_LEN)
  {
    Scc_V2GTpRxQueuePtr = &Scc_RxStreamBuffer_TCP;
  }
  else if (Scc_Rx_Queue_GetNumOfBytes(&Scc_RxStreamBuffer_UDP) >= SCC_V2GTP_HDR_LEN)
  {
    Scc_V2GTpRxQueuePtr = &Scc_RxStreamBuffer_UDP;
  }
  else
  {
    /* No enough data received wait for more */
  }
  SCC_LEAVE_EXCLUSIVE_AREA_2();

  /* Data was received on an open socket */
  /* #20 Check if enough data was received to handle the header */
  if (Scc_V2GTpRxQueuePtr != NULL_PTR)
  {
    /* #30 Parse the header */
    if (E_OK != Scc_Rx_V2GTP_ParseHeader(Scc_V2GTpRxQueuePtr, &Scc_V2GTpHeader))
    {
      /* Error occurred -> error handling */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_General_MainRxMessageHeaderParsingFailed);
      Scc_ReceiveMsgState = Scc_MsgState_RxFatalError;
    }
    else
    {
      /* #40 Forward message to processing */
      Scc_ReceiveMsgState = Scc_MsgState_CheckV2GTpHeader;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_CheckV2GTpHeader
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
 */ /* PRQA S 6050 1 */ /* MD_MSR_STCAL */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData_CheckV2GTpHeader(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_V2GTPHeaderCheckResultEnumType headerCheckResult;


  /* ----- Implementation ------------------------------------------------------------ */
  Scc_Core_Channel_SetRxChannelByPayloadType(Scc_V2GTpHeader.PayloadType);

  /* #10 Check the V2GTP header */
  headerCheckResult = Scc_Rx_V2GTP_CheckHeader(&Scc_V2GTpHeader,
                        Scc_RxConfig.SupportedPayloadTypeList, Scc_RxConfig.SupportedPayloadTypeListLen);

  /* #20 Check if header contained an invalid information */
  if (headerCheckResult != SCC_V2GTPHEADER_OK)
  {
    /* #30 Proceeed with freeing message data */
    Scc_ReceiveMsgState = Scc_MsgState_DiscardV2GTpHeader;

#if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
    /* [V2G-DC-169], [V2G2-800], [V2G20-800]  */
    /* DIN70121 requires to terminate the connection if the protocol and inverse
     * protocol version are erroneous. In contrast both ISO15118-2 and ISO15118-20
     * requires to just ignore the message.
     * CAUTION: This does not apply for the SupportedAppProtocol(SAP), because it
     *          can not be determined which version is going to be selected by SAP.
     *          Therefore, the error can only be reported, when SAP has finished. */
    if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_DIN)
    {
      /* [V2G-DC-171] */
      /* Check if an unsupported payload type is found, if yes skip it */
      if (headerCheckResult == SCC_V2GTPHEADER_UNSUPPORTEDPAYLOADTYPE)
      {
        Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader);
      }
      else
      {
        /* Since in DIN only 1 channel is present, release the default channel buffer */
        Scc_BufferPoolRelease(Scc_Core_Channel_Get_BufferPoolId());
        Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_General_MainRxMessageDinInvalidV2gtpHeaderProtocol);
        /* Enable SessionStopReq to be sent */
        Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest);
      }
    }
    else
#endif /* SCC_SCHEMA_DIN */
#if ((defined SCC_SCHEMA_OPP_CHARGE) && (SCC_SCHEMA_OPP_CHARGE != 0))
    /* ISO-DIS: [V2G2-095] */
    if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_OppCharge)
    {
      /* Since in OppCharge only 1 channel is present, release the default channel buffer */
      Scc_BufferPoolRelease(Scc_Core_Channel_Get_BufferPoolId());
      Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_General_MainRxMessageOppChargeInvalidV2gtpHeaderProtocol);
      /* Enable SessionStopReq to be sent */
      Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest);
    }
    else
#endif /* SCC_SCHEMA_OPP_CHARGE */
    {
      /* Wait for the next message to handle */
      Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader);
    }
  }
  /* #40 Check if the response message was unexpected */
  else if (FALSE == Scc_Core_Channel_IsReceivedMessageExpected())
  {
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
    /* #50 Report the unexpected message, ignore the received message and enable another message to be sent */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_General_MainRxMessageUnexpectedMessage);
    /* Ignore the message */
    Scc_ReceiveMsgState = Scc_MsgState_DiscardV2GTpHeader;
    /* Enable another request to be sent
     * This may be necessary for parallel channels if it is asked to retry the parallel channel. */
    Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest);
    /* Do not release buffer here with Scc_BufferPoolRelease since this message was not expected.
     * Hence buffer was not requested in the first place */
  }
  /* #60 Check if V2G payload length exceeds supported limits */
  else if (Scc_V2GTpHeader.PayloadLength > (SCC_UINT32_MAX_NUM - SCC_V2GTP_HDR_LEN))
  {
    Scc_BufferPoolRelease(Scc_Core_Channel_Get_BufferPoolId());
    Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
    /* Due to limitations in implementation Scc is not able to handle more data
     * than the check above allows. E.g. PBufs are not able to store more than
     * UINT32_MAX data lengths. Therefore this restriction is present currently */
    /* #70 Discard the message */
    Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest);
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_General_MainRxMessageUnsupportedPayloadLen);
    Scc_ReceiveMsgState = Scc_MsgState_DiscardV2GTpHeader;
  }
  /* #80 Otherwise */
  else
  {
    /* #90 Forward message to processing */
    Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForMessageData);
    Scc_ReceiveMsgState = Scc_MsgState_WaitingForMessageData;
  }
}

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_WaitingForMessageData
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */ /* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData_WaitingForMessageData(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 numOfBytesAvailable;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  numOfBytesAvailable = Scc_Rx_Queue_GetNumOfBytes(Scc_V2GTpRxQueuePtr);
  SCC_LEAVE_EXCLUSIVE_AREA_2();

  /* #10 Wait until the message is completely received */
  if (numOfBytesAvailable >= (Scc_V2GTpHeader.PayloadLength + SCC_V2GTP_HDR_LEN))
  {
    /* Message received */
    /* #20 Fetch data associated with the message */
    if (E_OK != Scc_Rx_Queue_GetData(Scc_V2GTpRxQueuePtr, Scc_V2GTpHeader.PayloadLength + SCC_V2GTP_HDR_LEN,
                                     &Scc_ExiStreamRxPBuf[0], SCC_EXI_RX_STREAM_PBUF_ELEMENTS))
    {
      /* Sth. went wrong */
      Scc_ReportError(Scc_StackError_RxQueue, SccDetailedError_General_MainRxMessageQueueDataFetchingFailed);
      Scc_ReceiveMsgState = Scc_MsgState_RxFatalError;
    }
    /* #30 Prepare message handling */
    else
    {
      Scc_ReturnType retValPrepare = Scc_ReturnType_OK;
      Scc_CoreChannelType currentChannel = Scc_Core_Channel_Get_CurrentChannel();
      P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) rxMsgWSPtr = Scc_Core_Channel_Get_RxMsgWSPtr(currentChannel);

      /* Prepare the message decoding if necessary */
      if (Scc_RxConfig.DecodePrepareFct != NULL_PTR)
      {
        retValPrepare = Scc_RxConfig.DecodePrepareFct(&Scc_V2GTpHeader, rxMsgWSPtr);
      }

      if (retValPrepare != Scc_ReturnType_OK)
      {
        Scc_ReceiveMsgState = Scc_MsgState_DiscardV2GTpHeader;

#if ((defined SCC_SCHEMA_DIN) && (SCC_SCHEMA_DIN != 0))
        if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_DIN)
        {
          /* Let the application do the error handling */
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_General_MainRxMessageDinInvalidPayloadLen);
        }
        else
#endif /* SCC_SCHEMA_DIN */
#if ((defined SCC_SCHEMA_OPP_CHARGE) && (SCC_SCHEMA_OPP_CHARGE != 0))
        if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_OppCharge)
        {
          /* [V2G2-OC-722] - Ignore invalid SessionId */
          if (retValPrepare == Scc_ReturnType_InvalidSessionId)
          {
            /* Wait for another message */
            Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader);
          }
          else
          {
            Scc_BufferPoolRelease(Scc_Core_Channel_Get_BufferPoolId());
            Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
            /* Enable SessionStopReq to be sent */
            Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest);
            Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_General_MainRxMessageOppChargeInvalidPayloadLen);
          }
        }
        else
#endif /* SCC_SCHEMA_DIN */
        {
          /* Sth. went wrong ignore this message */
          Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader);
        }
      }
      else
      {
        Scc_Core_InterfaceCfg_Set_MsgRxIndication();
        Scc_MsgStateFct_EA2(Scc_MsgState_HandleResponseData);
        Scc_ReceiveMsgState = Scc_MsgState_HandleResponseData;
      }
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_HandleResponseData
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
 */
/* PRQA S 6030,6050,6080 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
SCC_LOCAL FUNC(boolean, SCC_CODE) Scc_ProcessReceptionData_HandleResponseData(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 numOfBytesAvailable;
  boolean newMessagePresent = FALSE;
  Scc_ReturnType retValDecode = Scc_ReturnType_NotOK;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  numOfBytesAvailable = Scc_Rx_Queue_GetNumOfBytes(Scc_V2GTpRxQueuePtr);
  SCC_LEAVE_EXCLUSIVE_AREA_2();

  /* #10 Check if state is as expected */
  /* PRQA S 3415 4 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
  if ((Scc_State == Scc_State_Initialized)
    || (Scc_State == Scc_State_TLConnected)
    || (Scc_State == Scc_State_SAPComplete)
    || (Scc_State == Scc_State_Connected))
  {
    Scc_CoreChannelType currentChannel = Scc_Core_Channel_Get_CurrentChannel();
    P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) rxMsgWSPtr = Scc_Core_Channel_Get_RxMsgWSPtr(currentChannel);

    /* #20 Decode and process the received message */
    retValDecode = Scc_RxConfig.DecodeFct(&Scc_V2GTpHeader, rxMsgWSPtr);

    /* #30 Check if the decode function is pending */
    if (retValDecode == Scc_ReturnType_Pending)
    {
      /* The message is still being processed */
    }
    /* #40 Check if payload length is invalid */
    else if (retValDecode == Scc_ReturnType_InvalidPayloadLen)
    {
      /* #50 Discard the message data */
      Scc_ReceiveMsgState = Scc_MsgState_DiscardV2GTpHeader;

#if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
      /* [V2G-DC-173], [V2G2-800], [V2G20-800]  */
      /* DIN70121 requires to terminate the connection if the payload size cannot
      * be processed. In contrast both ISO15118-2 and ISO15118-20 requires to just
      * ignore the message.
      * CAUTION: This does not apply for the SupportedAppProtocol(SAP), because it
      *          can not be determined which version is going to be selected by SAP.
      *          Therefore, the error can only be reported, when SAP has finished. */
      /* #60 Check if DIN is selected */
      if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_DIN)
      {
        /* #70 Report error */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_General_MainRxMessageDinInvalidV2gtpHeaderPayloadlength);
        Scc_BufferPoolRelease(Scc_Core_Channel_Get_BufferPoolId());
        Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
        /* Enable SessionStopReq to be sent */
        Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest);
      }
      else
#endif /* SCC_SCHEMA_DIN */
      if (Scc_MsgTrig_SECCDiscoveryProtocol == Scc_Core_Channel_Get_MsgTrig())
      {
        /* In case of SDP the complete buffer needs to be flushed as otherwise the
         * UDP shadow buffer may still be in use */
        Scc_V2GTpHeader.PayloadLength = numOfBytesAvailable - SCC_V2GTP_HDR_LEN;
        Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader);
      }
      else
      {
        /* #80 Otherwise wait for the next message to handle */
        Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader);
      }
    }
    /* #90 Otherwise */
    else
    {
      /* Message was handled */
      /* #100 Check if decode was not ok for SECCDiscoveryProtocol */
      if ((retValDecode == Scc_ReturnType_NotOK) && (Scc_MsgTrig_SECCDiscoveryProtocol == Scc_Core_Channel_Get_MsgTrig()))/* PRQA S 3415 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
      {
        /* #110 Invalid message is ignored */
        Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader);
      }
      else
      {
        Scc_BufferPoolRelease(Scc_Core_Channel_Get_BufferPoolId());
        Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
        /* #120 Otherwise set state ready for the next request */
        Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest);
      }

      if (Scc_RxConfig.PropagteMessage == TRUE)
      {
        Scc_TxRxBufferPointerType V2GResponse;
        /* make the received message available to the application */
        /* create and set the rx buffer pointer */
        V2GResponse.PbufPtr = &Scc_ExiStreamRxPBuf[0];
        V2GResponse.FirstPart = TRUE;
        V2GResponse.StreamComplete = TRUE;
        /* provide the buffer to the application */
        Scc_Core_InterfaceCfg_Set_V2GResponse(&V2GResponse);
      }

      /* #130 Calculate if some data is present after the current V2G message */
      if (numOfBytesAvailable > (SCC_V2GTP_HDR_LEN + Scc_V2GTpHeader.PayloadLength))
      {
        /* Data exists which needs to be processed for another channel. */
        newMessagePresent = TRUE;
      }

      /* #140 Proceed with freeing the buffer */
      Scc_ReceiveMsgState = Scc_MsgState_DiscardV2GTpHeader;
    }
  }
  else
  {
    /* Unexpected message is ignored, data discarded */
    Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader);
    Scc_ReceiveMsgState = Scc_MsgState_DiscardV2GTpHeader;
  }

  return newMessagePresent;
}

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_DiscardV2GTpHeader
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData_DiscardV2GTpHeader(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Free the Rx queue by amount of V2GTP header */
  if (E_OK != Scc_Rx_Queue_Consume(Scc_V2GTpRxQueuePtr, SCC_V2GTP_HDR_LEN))
  {
    Scc_ReportError(Scc_StackError_RxQueue, SccDetailedError_General_MainRxMessageInvalidV2gtpHeaderReleaseMsgFailed);
    Scc_ReceiveMsgState = Scc_MsgState_RxFatalError;
  }
  else
  {
    Scc_ReceiveMsgState = Scc_MsgState_DiscardResponseData;
  }
}

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData_DiscardMessageData
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
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData_DiscardMessageData(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 bytesToFree;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  bytesToFree = Scc_Rx_Queue_GetNumOfBytes(Scc_V2GTpRxQueuePtr);
  SCC_LEAVE_EXCLUSIVE_AREA_2();

  /* #10 Check if more data than current message is present */
  /* For large messages it may be that some data may be still to be received.
   * Therefore, it may take several calls to completly free the message */
  if (bytesToFree > Scc_V2GTpHeader.PayloadLength)
  {
    /* #20 Limit length to current message data */
    /* Free/discard max. the current message */
    bytesToFree = Scc_V2GTpHeader.PayloadLength;
  }

  if (bytesToFree == 0u)
  {
    /* Wait for more data */
  }
  /* #30 Free the Rx queue */
  else if (E_OK != Scc_Rx_Queue_Consume(Scc_V2GTpRxQueuePtr, bytesToFree))
  {
    Scc_ReportError(Scc_StackError_RxQueue, SccDetailedError_General_MainRxMessageReleaseMsgFailed);
    Scc_ReceiveMsgState = Scc_MsgState_RxFatalError;
  }
  else
  {
    /* Processing can be continued */
  }

  /* #40 Check if complete message data was freed */
  Scc_V2GTpHeader.PayloadLength -= bytesToFree;
  if (Scc_V2GTpHeader.PayloadLength != 0u)
  {
    /* #50 No: More data needs to be freed/discarded, wait for partial data to be received */
  }
  else
  {
    /* #60 Yes: Everything was freed/discarded, accept new message */
    Scc_ReceiveMsgState = Scc_MsgState_WaitingForV2GTpHeader;
  }
}

/**********************************************************************************************************************
 *  Scc_ProcessReceptionData
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
 */
/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ProcessReceptionData(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0u;
  uint8       maxNumRes = 0u;
  boolean     exitLoop = FALSE;
  boolean     propagateFinish = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  maxNumRes = SCC_NUM_OF_RES_PER_MAIN_FUNCTION;
  /* #10 Limit the number of responses that can be processed per main function */
  if (maxNumRes > (uint8)SCC_CHANNEL_MAX)                                                                               /* PRQA S 2992, 2996 */ /* MD_Scc_VariantDependent */
  {
    maxNumRes = (uint8)SCC_CHANNEL_MAX;                                                                                 /* PRQA S 2880 */ /* MD_Scc_VariantDependent */
  }

  /* #20 Iterate number of responses to process the same */
  for (index = 0; index < maxNumRes; index++)
  {
    exitLoop = TRUE;
    /* #30 Wait for message header to be received */
    if (Scc_ReceiveMsgState == Scc_MsgState_WaitingForV2GTpHeader)
    {
      Scc_ProcessReceptionData_WaitingForV2GTpHeader();
    }

    /* #40 Check the V2G header */
    if (Scc_ReceiveMsgState == Scc_MsgState_CheckV2GTpHeader)
    {
      Scc_ProcessReceptionData_CheckV2GTpHeader();
    }
    /* #50 Otherwise if the state is in any reception path then reset the reception channel */
    else if(Scc_ReceiveMsgState > Scc_MsgState_WaitingForV2GTpHeader)
    {
      /* In case the header was received earlier but the packet was not processed then the Scc_CurrentChannel is mostly overwritten in the Transmission path
         in the Scc_MainFunction. Hence reset the Scc_CurrentChannel here */
      Scc_Core_Channel_ActualizeReceptionChannel();
    }
    else
    {
      /* Do nothing since it is in transmission path */
    }

    /* #60 Wait for message data to be received */
    if (Scc_ReceiveMsgState == Scc_MsgState_WaitingForMessageData)
    {
      Scc_ProcessReceptionData_WaitingForMessageData();
      /* In case header was got and message data is awaited for, then CurrentChannel is propogated to Application. Hence set varaible to true */
      propagateFinish = TRUE;
    }

    /* #70 Handle the received message */
    if (Scc_ReceiveMsgState == Scc_MsgState_HandleResponseData)
    {
      if (Scc_ProcessReceptionData_HandleResponseData() == TRUE)
      {
        exitLoop = FALSE;
      }
      /* In case header was got and message data is processed, then CurrentChannel is propogated to Application. Hence set varaible to true */
      propagateFinish = TRUE;
    }

    /* #80 Check if message header shall be discarded/freed */
    if (Scc_ReceiveMsgState == Scc_MsgState_DiscardV2GTpHeader)
    {
      Scc_ProcessReceptionData_DiscardV2GTpHeader();
      /* In case only partial data was freed */
      propagateFinish = TRUE;
    }

    /* #90 Check if message data shall be discarded/freed */
    if (Scc_ReceiveMsgState == Scc_MsgState_DiscardResponseData)
    {
      Scc_ProcessReceptionData_DiscardMessageData();
      /* In case only partial data was freed */
      propagateFinish = TRUE;
    }

    /* #100 Check if a fatal error was detected in rx path */
    if (Scc_ReceiveMsgState == Scc_MsgState_RxFatalError)
    {
      /* #110 Do nothing - reset needed */
      propagateFinish = TRUE;
    }

    /* #120 Check if FinishProcessingCurrentChannel needs to be propogated */
    if (propagateFinish == TRUE)
    {
      Scc_Core_InterfaceCfg_Set_FinishProcessingCurrentChannel(Scc_Core_Channel_Get_CurrentChannel());
    }

    /* #130 Check if no other processing needs to be done and the loop needs to exit */
    if (exitLoop == TRUE)
    {
      break;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_TcpTransmit
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_TcpTransmit(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal;
  uint32 availableTxBufferSize = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the number of bytes available in TcpIp for transmitting a message */
  retVal = (Scc_ReturnType)TcpIp_GetAvailableTxBufferSize(Scc_V2GSocket, &availableTxBufferSize);                       /* PRQA S 4342 */ /* MD_Scc_ReturnType */

  if (retVal == Scc_ReturnType_OK)
  {
    /* #20 send the message and check if it failed */
    /* PRQA S 4342 1 */ /* MD_Scc_ReturnType */
    retVal = (Scc_ReturnType)TcpIp_TcpTransmit(Scc_V2GSocket, NULL_PTR,
      availableTxBufferSize, TRUE);
  }

  if (Scc_ReturnType_OK != retVal)
  {
    /* #30 The request has not been accepted, e.g. due to a lack of buffer space or the socket is not connected.  */
    retVal = Scc_ReturnType_Pending;
  }
  else
  {
    /* #40 check if the whole message did not fit into the first packet */
    if (Scc_TxStreamingActive == TRUE)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else
    {
      retVal = Scc_ReturnType_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_Rx_TcpRelease
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_Rx_TcpRelease(
  CONST(uint32, AUTOMATIC) Length)
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  /* #10 Release the tcp data if the socket is open. */
  if (Scc_V2GSocket != TCPIP_INV_SOCKET_ID)
  {
    SCC_LEAVE_EXCLUSIVE_AREA_2();
    /* release buffer in transport layer */
    (void)TcpIp_TcpReceived(Scc_V2GSocket, Length);
  }
  else
  {
    SCC_LEAVE_EXCLUSIVE_AREA_2();
  }
}

/**********************************************************************************************************************
 *  Scc_Rx_UdpRelease
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_Rx_UdpRelease(
  CONST(uint32, AUTOMATIC) Length)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Release the UDP shadow buffer */
  SCC_DUMMY_STATEMENT_CONST(Length);

  SCC_ENTER_EXCLUSIVE_AREA_2();
  Scc_RxUDPShadowBufferUsed = FALSE;
  SCC_LEAVE_EXCLUSIVE_AREA_2();
}

/**********************************************************************************************************************
 *  GLOBAL CALLBACKS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_Cbk_TL_RxIndication
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
 */
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
FUNC(void, SCC_CODE) Scc_Cbk_TL_RxIndication(
  Scc_SocketType SockHnd,
  P2VAR(Scc_SockAddrType, AUTOMATIC, SCC_APPL_DATA) SourcePtr,                                                          /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  uint16 DataLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;

  /* create a pseudo pbuf and a pointer to it */
  Scc_PbufType Pbuf;

  /* ----- Development Error Checks ------------------------------------- */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters. */
  if ( Scc_State == Scc_State_Uninitialized )
  {
    errorId = SCC_DET_NOT_INITIALIZED;
  }
  else if ( DataPtr == NULL_PTR )
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else if ( SourcePtr == NULL_PTR )
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else
#endif /* SCC_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    SCC_DUMMY_STATEMENT(SourcePtr);                                                                                     /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

    /* set the pbuf */
    Pbuf.payload = DataPtr;
    Pbuf.len     = DataLen;
    Pbuf.totLen  = DataLen;

    SCC_ENTER_EXCLUSIVE_AREA_2();
    /* set the pbuf pointer */
    /* #20 Check if data was received on the TCP socket */
    if (Scc_V2GSocket == SockHnd)
    {
      /* #30 Forward message to TCP rx queue */
      if (E_OK != Scc_Rx_Queue_AddData(&Scc_RxStreamBuffer_TCP, DataPtr, DataLen))
      {
        Scc_ReceiveMsgState = Scc_MsgState_RxFatalError;
        SCC_LEAVE_EXCLUSIVE_AREA_2();
#if(SCC_DEV_ERROR_REPORT == STD_ON)
        (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_RX_INDICATION, SCC_DET_RX_QUEUE);
#endif /* SCC_DEV_ERROR_REPORT */

        Scc_ReportError(Scc_StackError_RxQueue, SccDetailedError_RxIndication_RxQueueTooSmall);
      }
      else
      {
        SCC_LEAVE_EXCLUSIVE_AREA_2();
      }
    }
    /* #40 Check if data was received on the UDP socket and if a SDP message is expected. */
    /* PRQA S 3415 2 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
    else if (     ( Scc_SDPSocket == SockHnd )
              &&  ( Scc_MsgTrig_SECCDiscoveryProtocol == Scc_Core_Channel_Get_MsgTrig()))
    {
      /* #50 Use the UDP shadow buffer to forward message to UDP rx queue */
      /* Copy data to shadow buffer */
      if ((Scc_RxUDPShadowBufferUsed == TRUE) || (Pbuf.totLen > sizeof(Scc_RxUDPShadowBuffer)) )
      {
        SCC_LEAVE_EXCLUSIVE_AREA_2();
      }
      else if (E_OK != IpBase_CopyPbuf2String(&Scc_RxUDPShadowBuffer[0], &Pbuf, (uint16)Pbuf.totLen, 0u))
      {
        SCC_LEAVE_EXCLUSIVE_AREA_2();
#if(SCC_DEV_ERROR_REPORT == STD_ON)
        (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_RX_INDICATION, SCC_DET_IP_BASE);
#endif /* SCC_DEV_ERROR_REPORT */
      }
      else
      {
        Std_ReturnType retVal;

        Scc_RxUDPShadowBufferUsed = TRUE;
        retVal = Scc_Rx_Queue_AddData(&Scc_RxStreamBuffer_UDP, Scc_RxUDPShadowBuffer, DataLen);
        SCC_LEAVE_EXCLUSIVE_AREA_2();

        /* Data can now be handled by the main function */
        if (retVal != E_OK)
        {
#if(SCC_DEV_ERROR_REPORT == STD_ON)
          (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_RX_INDICATION, SCC_DET_RX_QUEUE);
#endif /* SCC_DEV_ERROR_REPORT */
        }
      }
    }
    /* #60 If no message was expected, ignore it. */
    else
    {
      /* #70 UDP data is automatically ignored by leaving this function */
      SCC_LEAVE_EXCLUSIVE_AREA_2();
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #80 Report default errors if any occurred. */
  if ( errorId != SCC_DET_NO_ERROR )
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_RX_INDICATION, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */

  return; /*lint !e438 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_Cbk_TL_TCPConnected
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Cbk_TL_TCPConnected(Scc_SocketType SockHnd)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters. */
  if ( Scc_State == Scc_State_Uninitialized )
  {
    errorId = SCC_DET_NOT_INITIALIZED;
  }
  else
#endif /* SCC_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    SCC_ENTER_EXCLUSIVE_AREA_2();
    if ( SockHnd != Scc_V2GSocket )
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();
      errorId = SCC_DET_INV_PARAM;
    }
    /* #20 Update states and report to status. */
    else if ( Scc_State_TLConnecting == Scc_State )
    {
      /* update the states */
      Scc_State = Scc_State_TLConnected;
      SCC_LEAVE_EXCLUSIVE_AREA_2();
      Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest)
      /* report it to the application */
      Scc_Core_InterfaceCfg_Set_TCPSocketState(Scc_TCPSocketState_Connected);
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_TransportLayer_OK);
    }
    /* illegal state for this callback */
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();
      /* ignore */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      errorId = SCC_DET_INV_STATE;
#endif /* SCC_DEV_ERROR_REPORT */
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #30 Report default errors if any occurred. */
  if ( errorId != SCC_DET_NO_ERROR )
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_TCP_CONNECTED, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */
} /*lint !e438 */ /* MD_MSR_DummyStmt */

/**********************************************************************************************************************
 *  Scc_Cbk_TL_TCPEvent
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6030,6050,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
FUNC(void, SCC_CODE) Scc_Cbk_TL_TCPEvent(Scc_SocketType SockHnd, IpBase_TcpIpEventType Event)
{
  /* ----- Implementation ----------------------------------------------- */
  if ( Scc_State == Scc_State_Uninitialized )
  {
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_TCP_IP_EVENT, SCC_DET_NOT_INITIALIZED);
#endif /* SCC_DEV_ERROR_REPORT */
  }

  /* check if this callback does concern the TL (TCP/TLS) socket */
  else if ( Scc_V2GSocket == SockHnd )
  {
    SCC_ENTER_EXCLUSIVE_AREA_2();

    /* #10 Set variables if TCP connection is closed/reset. */
    switch ( Event )
    {
      /* check if the connection was closed */
    case IPBASE_TCP_EVENT_CLOSED:
    case IPBASE_TCP_EVENT_RESET:
      /* update the flag */
      Scc_V2GSocketInUse = FALSE;
      Scc_V2GSocket = (Scc_SocketType)TCPIP_INV_SOCKET_ID;
      /* report it to the application */
      SCC_LEAVE_EXCLUSIVE_AREA_2();
      Scc_Core_InterfaceCfg_Set_TCPSocketState(Scc_TCPSocketState_Closed);
      SCC_ENTER_EXCLUSIVE_AREA_2();
      break;

    default:
      /* ignore other events */
      break;
    }

    /* #20 Check if charging session exist and report status.  */
    if (( Scc_State_TLConnecting <= Scc_State ) && ( Scc_State_ShuttingDown >= Scc_State ))                             /* PRQA S 3415 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
    {
      switch ( Event )
      {
      case IPBASE_TCP_EVENT_FIN_RECEIVED:
      case IPBASE_TCP_EVENT_RESET:
        /* [V2G2-UG-050-2] After sending the SessionStopRes message, the SECC shall wait for the termination of the TLS/TCP connection by the EVCC for =5s. */
        /* [V2G2-UG-050-3] If the EVCC did not terminate the TLS/TCP connection after =5s, the SECC shall terminate the connection. */

        /* check if we want to shutdown the communication but EVSE issued a rst after fin was sent or
         * transport layer reset or FIN occurred */
        if (Scc_State_ShuttingDown == Scc_State)
        {
          Scc_State = Scc_State_ShutDown;
          SCC_LEAVE_EXCLUSIVE_AREA_2();
          Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest)
          Scc_ReportSuccessAndStatus(Scc_MsgStatus_StopCommunicationSession_OK);
        }
        /* check if SessionStopRes was not received */
        else if ( Scc_MsgStatus < Scc_MsgStatus_SessionStop_OK )
        {
          SCC_LEAVE_EXCLUSIVE_AREA_2();
          /* the SECC is not allowed to close the connection */
          Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerSeccClosedConnection);
        }
        else
        {
          SCC_LEAVE_EXCLUSIVE_AREA_2();
        }
        break;

      case IPBASE_TCP_EVENT_CLOSED:
      {
        Scc_StateType tempState = Scc_State;
        /* TL connection was disconnected, module will be shut down */
        Scc_State = Scc_State_ShutDown;
        /* check if this shutdown was correctly triggered */
        if (Scc_State_ShuttingDown == tempState)
        {
          SCC_LEAVE_EXCLUSIVE_AREA_2();
          Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest)
          Scc_ReportSuccessAndStatus(Scc_MsgStatus_StopCommunicationSession_OK);
        }
        /* the connection was closed although there was still an active V2G session */
        else
        {
          SCC_LEAVE_EXCLUSIVE_AREA_2();
          /* the SECC is not allowed to close the connection */
          Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerShutdownSeccClosedConnection);
        }
        break;
      }

      case TCPIP_TLS_HANDSHAKE_SUCCEEDED:
        /* Ignore tls handshake event as the tcp connected callback is currently being used */
        SCC_LEAVE_EXCLUSIVE_AREA_2();
        break;

      default:
        SCC_LEAVE_EXCLUSIVE_AREA_2();
  #if(SCC_DEV_ERROR_REPORT == STD_ON)
        (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_TCP_IP_EVENT, SCC_DET_INV_PARAM);
  #endif /* SCC_DEV_ERROR_REPORT */
        break;
      }
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();
    }
  }
  else if (Scc_SDPSocket == SockHnd)
  {
    /* Do nothing */
  }
  else
  {
    /* Do nothing */
    /* Removed Det_ReportError due to ESCAN00103972 in TCP */
  }
}

#if (defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON))
# if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
/**********************************************************************************************************************
 *  Scc_CompareSessionResumeHash
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_CompareSessionResumeHash(
  CONSTP2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) CalculatedHashPtr,
  uint32 CalculatedHashLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 storedHash[SCC_LEN_HASH_512] = { 0 };
  uint32 storedHashLen = SCC_LEN_HASH_512;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if Hash cannot be fetched and Report passed error code for error accessing Csm */
  if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYELEMENTGET(SCC_CSM_SESSION_KEY_ID,
                                             SCC_CRYPTO_KEY_ELEM_SESSION_HASH,
                                             &storedHash[0], &storedHashLen),
                                             TRUE, Scc_StackError_Crypto, SccDetailedError_General_TransportLayerHashReadFailed))
  {
    /* Error already reported above */
  }
  /* #20 Otherwise */
  else
  {
    uint8 hashMatches = IPBASE_CMP_NOT_EQUAL;

    /* #30 Check if the lengths match */
    if (CalculatedHashLen == storedHashLen)
    {
      /* #40 Compute compare for hashes */
      hashMatches = IpBase_StrCmpLen(CalculatedHashPtr, &storedHash[0], (uint16)CalculatedHashLen);
    }

    /* #50 [V2G20-2559] Check if the Hash is unequal */
    if (hashMatches != IPBASE_CMP_EQUAL)
    {
      /* #60 Reset the resumeSession */
      uint8 resumeSession = 0;

      /* #70 Check if resumeSession cannot be written and Report passed error code for error accessing Csm */
      if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYELEMENTSET(
                                                 SCC_CSM_SESSION_KEY_ID, SCC_CRYPTO_KEY_ELEM_SESSION_RESUME,
                                                 &resumeSession, 1),
                                                 TRUE, Scc_StackError_Crypto, SccDetailedError_General_TransportLayerResumeSessionWriteFailed))
      {
        /* Error already reported above */
      }
      /* #80 Otherwise check if data cannot be written and Report passed error code for error accessing Csm */
      else if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYSETVALID(SCC_CSM_SESSION_KEY_ID),
                                                      TRUE, Scc_StackError_Crypto, SccDetailedError_General_TransportLayerResumeSessionValidWriteFailed))
      {
        /* Error already reported above */
      }
      else
      {
        /* Nothing to do */
      }
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ComputeSessionResume_Helper
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
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ComputeSessionResume_Helper(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) CalculatedHashPtr,
  uint32 CalculatedHashLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 resumeSessionLen = 1u;
  uint8 resumeSession = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if Resume session cannot be fetched and Report passed error code for error accessing Csm */
  if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYELEMENTGET(SCC_CSM_SESSION_KEY_ID,
                                             SCC_CRYPTO_KEY_ELEM_SESSION_RESUME,
                                             &resumeSession, &resumeSessionLen),
                                             TRUE, Scc_StackError_Crypto, SccDetailedError_General_TransportLayerResumeSessionReadFailed))
  {
    /* Error already reported above */
  }
  /* #20 Otherwise check if session needs to be resumed */
  else if (resumeSession == (uint8)TRUE)                                                                                /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
  {
    /* #30 Compare the Hashes */
    Scc_CompareSessionResumeHash(CalculatedHashPtr, CalculatedHashLen);
  }
  else
  {
    /* Nothing to do */
  }

  /* #40 [V2G20-2557] Store the Hash */
  /* #50 Check if Hash cannot be written and Report passed error code for error accessing Csm */
  if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYELEMENTSET(
                                             SCC_CSM_SESSION_KEY_ID, SCC_CRYPTO_KEY_ELEM_SESSION_HASH,
                                             CalculatedHashPtr, CalculatedHashLen),
                                             TRUE, Scc_StackError_Crypto, SccDetailedError_General_TransportLayerHashWriteFailed))
  {
    /* Error already reported above */
  }
  /* #60 Otherwise check if data cannot be written and Report passed error code for error accessing Csm */
  else if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYSETVALID(SCC_CSM_SESSION_KEY_ID), TRUE,
                                                  Scc_StackError_Crypto, SccDetailedError_General_TransportLayerHashValidWriteFailed))
  {
    /* Error already reported above */
  }
  else
  {
    /* Nothing to do */
  }
}

/**********************************************************************************************************************
 *  Scc_ComputeSessionResume
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
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ComputeSessionResume(TcpIp_CertificateIdType CertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 calculatedHash[SCC_LEN_HASH_512] = { 0 };
  uint32 calculatedHashLen = SCC_LEN_HASH_512;
  KeyM_CertDataType certData = { 0, NULL_PTR };
  uint8 buffPoolId = 0;
  P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(SCC_CHANNEL_DEFAULT);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get MsgPtr and MsgPtrSize */
  if (Scc_BufferPoolRequestGetBuffer(SCC_POOL_BUFF_LARGE, &buffPoolWsPtr->MsgPtr, &buffPoolWsPtr->MsgPtrSize, &buffPoolId) != E_OK)
  {
    /* Do nothing. Error already reported */
  }
  else
  {
    certData.certData = buffPoolWsPtr->MsgPtr;
    certData.certDataLength = buffPoolWsPtr->MsgPtrSize;

    /* #20 Check if certificate cannot be fetched and Report passed error code for error accessing KeyM */
    if (E_OK != Scc_ReportErrorCompSpecific(SCC_KEYM_GETCERTIFICATE(CertId, &certData), TRUE,
                                               Scc_StackError_KeyM, SccDetailedError_General_TransportLayerCertificateReadFailed))
    {
      /* Error already reported above */
    }
    else
    {
      /* #30 [V2G20-2635] Check if Hash generation is unsuccessful and Report passed error code for error accessing Csm */
      if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_HASH(Scc_ISO20SHA512Job.Id, CRYPTO_OPERATIONMODE_SINGLECALL,
                                                 &certData.certData[0], certData.certDataLength,
                                                 &calculatedHash[0], &calculatedHashLen),
                                                 TRUE, Scc_StackError_Crypto, SccDetailedError_General_TransportLayerHashGenerationFailed))
      {
        /* Error already reported above */
      }
      /* #40 Otherwise */
      else
      {
        Scc_ComputeSessionResume_Helper(&calculatedHash[0], calculatedHashLen);
      }
    }
    Scc_BufferPoolRelease(buffPoolId);
  }

}
# endif /* SCC_SCHEMA_ISO_20 */


/**********************************************************************************************************************
 *  Scc_TLS_HandleConnectionInfo
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
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_TLS_HandleConnectionInfo(
  P2CONST(TcpIp_TlsConnectionInfoType, AUTOMATIC, SCC_APPL_DATA)  TlsConnectionInfoPtr,
  P2VAR(TcpIp_CertValidationResultType, AUTOMATIC, SCC_APPL_DATA) ValidationResultPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Propagate the TLS connection parameters to configurable interface */
  Scc_Core_InterfaceCfg_Set_TLS_VersionUsed(TlsConnectionInfoPtr->TlsVersion);
  Scc_Core_InterfaceCfg_Set_TLS_SignatureAlgorithmUsed(TlsConnectionInfoPtr->SigAlgoId);
  Scc_Core_InterfaceCfg_Set_TLS_CipherSuiteUsed(TlsConnectionInfoPtr->CipherSuiteId);
  Scc_Core_InterfaceCfg_Set_TLS_RootCertId(TlsConnectionInfoPtr->RootCertId);

  /* #20 Store the TLS connection information for later usage */
  Scc_Priv_TLSParamSetTlsVersionUsed(TlsConnectionInfoPtr->TlsVersion);

  /* Below the validation result is only set to not ok and not to ok
   * as otherwise the validation result from earlier steps may be
   * overwritten. But a negative validation result shall be preserved */
#if ( SCC_SCHEMA_ISO != 0 )
  /* #30 Check if current TLS version is 1.2 which is used for ISO-2 */
  if (TlsConnectionInfoPtr->TlsVersion == TCPIP_TLSVERSION_12)
  {
    /* #40 Ensure that cipher suite is according to [V2G2-603] */
    switch (TlsConnectionInfoPtr->CipherSuiteId)
    {
      case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256:
      case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:
      {
        if (TlsConnectionInfoPtr->SigAlgoId != TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256)
        {
          /* Signature algorithm must match too */
          *ValidationResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;
        }
        break;
      }

      default:
      {
        /* Reject all other cipher suites as they are not specified by ISO-2 */
        *ValidationResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;
        break;
      }
    }
  }
#endif /* SCC_SCHEMA_ISO */

#if ( SCC_SCHEMA_ISO_20 != 0 )
  /* #50 Check if current TLS version is 1.3 which is used for ISO-20 */
  if (TlsConnectionInfoPtr->TlsVersion == TCPIP_TLSVERSION_13)
  {
    /* #60 Ensure that cipher suite is according to [V2G20-2459] */
    switch (TlsConnectionInfoPtr->CipherSuiteId)
    {
      case TCPIP_TLS_AES_256_GCM_SHA384:
      case TCPIP_TLS_CHACHA20_POLY1305_SHA256:
      {
        if (   (TlsConnectionInfoPtr->SigAlgoId != TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512)
            && (TlsConnectionInfoPtr->SigAlgoId != TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC))
        {
          /* Signature algorithm must match too */
          *ValidationResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;
        }
        /* Only these are allowed */
        break;
      }

      default:
      {
        /* Reject all other cipher suites as they are not specified by ISO-20 */
        *ValidationResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;
        break;
      }
    }
  }
#endif /* SCC_SCHEMA_ISO_20 */
}

/**********************************************************************************************************************
 *  Scc_TLS_CheckIfPECert
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
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(boolean, SCC_CODE) Scc_TLS_CheckIfPECert(
  uint32                                      NumCerts,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA)   CertChainStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isPECert = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this is a private environment root certificate installation (ISO15118-20 calls it CPM4PE) */
  if ((CertChainStatusPtr[NumCerts - 1u].IsSelfSigned == TRUE)) /*lint -e{661} */ /* LD_SCC_POINTER_TO_ARRAY */
  {
    /* #20 This is a PE certificate */
    isPECert = TRUE;
  }

  /* #30 Check if more detailed checks to detect a private environment are required */
  if (isPECert == FALSE)
  {
    /* Since PE root certificates must not be known by Scc, a check if Scc knows the root certificate can be
     * used to determine if this is a PE use case.
     * Note: A self signed certificate should reference itself as issuer. */
    KeyM_CertificateIdType certIdIssuer = 0;
    boolean idFound = FALSE;

    /* #40 Get issuer of last certificate in chain */
    if (SCC_KEYM_GETISSUERCERTID(CertChainStatusPtr[NumCerts - 1u].CertId, &certIdIssuer) == E_OK)
    {
      uint8_least rootCertIdx = 0;
#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
      /* #50 Check if the issuer is known to Scc */
      for (rootCertIdx = 0; rootCertIdx < Scc_ISO20CertConfig.RootCertCnt; rootCertIdx++)
      {
        /* #60 Check if issuer matches a ISO15118-20 root certificate */
        if (Scc_ISO20CertConfig.RootCertsPtr[rootCertIdx].KeyMCertId == certIdIssuer)
        {
          /* #70 Set flag to TRUE */
          idFound = TRUE;
          break;
        }
      }
#endif /* SCC_SCHEMA_ISO_20 */

#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
      /* #80 Check if flag was set previously */
      if (idFound == FALSE)                                                                                             /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
      {
        /* #90 Check if the issuer is known to Scc */
        for (rootCertIdx = 0; rootCertIdx < Scc_ISO2CertConfig.RootCertCnt; rootCertIdx++)
        {
          /* #100 Check if issuer matches a ISO15118-2 root certificate */
          if (Scc_ISO2CertConfig.RootCertsPtr[rootCertIdx].KeyMCertId == certIdIssuer)
          {
            /* #110 Set flag to TRUE */
            idFound = TRUE;
            break;
          }
        }
      }
#endif /* SCC_SCHEMA_ISO */

      /* #120 Check if the issuer is unknown to Scc */
      if (idFound == FALSE)
      {
        /* #130 This is a PE certificate */
        isPECert = TRUE;
      }
    }
  }

  return isPECert;
}

/**********************************************************************************************************************
 *  Scc_Cbk_TLS_CertChain
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
 */
/* PRQA S 6010,6030,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */
FUNC(void, SCC_CODE) Scc_Cbk_TLS_CertChain(
  Scc_SocketType                              SockHnd,
  uint32                                      NumCerts,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA)   CertChainStatusPtr,
  P2VAR(TcpIp_CertValidationResultType, AUTOMATIC, SCC_APPL_DATA)     ValidationResultPtr,
  P2CONST(TcpIp_TlsConnectionInfoType, AUTOMATIC, SCC_APPL_DATA)      TlsConnectionInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;
  boolean isPECert = FALSE;

  /* ----- Development Error Checks ------------------------------------- */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters. */
  if (Scc_State == Scc_State_Uninitialized)
  {
    errorId = SCC_DET_NOT_INITIALIZED;
  }
  else if (Scc_V2GSocket != SockHnd)
  {
    errorId = SCC_DET_INV_PARAM;
  }
  else if (ValidationResultPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else if (CertChainStatusPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else if (TlsConnectionInfoPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else
#else /* SCC_DEV_ERROR_DETECT */
  SCC_DUMMY_STATEMENT(SockHnd);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_DETECT */
  if (NumCerts == 0u)
  {
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
    errorId = SCC_DET_INV_POINTER;
#endif /* SCC_DEV_ERROR_DETECT */
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    isPECert = Scc_TLS_CheckIfPECert(NumCerts, CertChainStatusPtr);
    Scc_Core_InterfaceCfg_Set_TLS_CertChainIsPrivate(isPECert);

    switch (*ValidationResultPtr)
    {
      /* #20 Check if Tls validation was ok */
    case TCPIP_TLS_VALIDATION_OK:
    {
      P2CONST(Scc_TlsCertStructType, AUTOMATIC, SCC_CONST) tlsLeafCertCfgPtr
        = Scc_Core_KeyMUtils_GetTlsCertConfigPtr(CertChainStatusPtr[0].CertId);

      /* #30 Check if KeyMCertId is found */
      if (tlsLeafCertCfgPtr != NULL_PTR)
      {
        boolean additonalDCIdsFound = FALSE;

        /* #40 Check if the received certificates were not PE certificates including root certificate */
        if (isPECert == FALSE)
        {
          P2CONST(Scc_StringStructType, AUTOMATIC, SCC_CONST) leafStringPtr = NULL_PTR;
          Scc_StringCompareMode leafValueCompareMode = Scc_StrCmp_Strict;

# if defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u)
          leafStringPtr = &Scc_SECCLeafCPOValue;
          leafValueCompareMode = Scc_StrCmp_Strict;
# endif
# if defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
          if (tlsLeafCertCfgPtr->Curve != Scc_CertCurve_secp256r1)
          {
            leafStringPtr = &Scc_SECCLeafCSOValue;
            leafValueCompareMode = Scc_StrCmp_EndsWith;
          }
# endif /* SCC_SCHEMA_ISO_20 */

          *ValidationResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;

          if(leafStringPtr != NULL_PTR)                                                                                 /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
          {
            if (TRUE == Scc_Core_KeyMUtils_CertElementContainsStr(
                            tlsLeafCertCfgPtr->KeyMCertId,
                            &tlsLeafCertCfgPtr->KeyMSubjectDCElemts,
                            leafStringPtr, 1u,
                            leafValueCompareMode))
            {
              /* CPO was set in Domain Component(Subject) */
              *ValidationResultPtr = TCPIP_TLS_VALIDATION_OK;
            }
          }
        }

# if defined(SCC_PRIVENV_NUMOFIDS) && (SCC_PRIVENV_NUMOFIDS != 0)
        if (TRUE == Scc_Core_KeyMUtils_CertElementContainsStr(
          tlsLeafCertCfgPtr->KeyMCertId,
          &tlsLeafCertCfgPtr->KeyMSubjectDCElemts,
          &Scc_SECCLeafAdditionalDCIds[0], SCC_PRIVENV_NUMOFIDS,
          Scc_StrCmp_Strict))
        {
          additonalDCIdsFound = TRUE;
        }
# endif /* SCC_PRIVENV_NUMOFIDS != 0 */
        Scc_Core_InterfaceCfg_Set_SECCLeafDCIdentifierFound(additonalDCIdsFound);

#if defined(SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON)
        if (*ValidationResultPtr == TCPIP_TLS_VALIDATION_OK)
        {
          Scc_Core_KeyMUtils_CheckTlsChainCertExtensions(CertChainStatusPtr, ValidationResultPtr, NumCerts, TlsConnectionInfoPtr);
        }
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION != 0 */

#if (SCC_ENABLE_OCSP == STD_ON)
        if (*ValidationResultPtr == TCPIP_TLS_VALIDATION_OK)
        {
          /* #50 Check the OCSP status of the certificates only in the case that until now everything was fine */
          Scc_CheckOcspValidity(tlsLeafCertCfgPtr, NumCerts, CertChainStatusPtr, ValidationResultPtr);
        }
#endif /* SCC_ENABLE_OCSP */

# if (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
        if (*ValidationResultPtr == TCPIP_TLS_VALIDATION_OK)
        {
          /* #60 Check if any certificate of the Tls chain (including OCSP certificates) uses a rejected elliptic curve */
          Scc_CheckTlsCertsForRejectedEllipticCurves(ValidationResultPtr);
        }
#endif /* SCC_SCHEMA_ISO_20 */

        Scc_TLS_HandleConnectionInfo(TlsConnectionInfoPtr, ValidationResultPtr);
      }
      else
      {
        *ValidationResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
        /* #70 Report error. */
        (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_TCP_IP_CERT, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      }

      /* #80 Report leaf certificate and validation result to application */
      Scc_Core_InterfaceCfg_Set_TLS_CertChain(NumCerts, CertChainStatusPtr, ValidationResultPtr);

#if (SCC_IDSM_REPORT == STD_ON)
      /* Validation result may be overwritten by the user */
      if (*ValidationResultPtr != TCPIP_TLS_VALIDATION_OK)
      {
        IdsM_SetSecurityEvent(SCC_IDSMEVENT_TLS_SERVER_CERT_INVALID);
      }
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
      break;

      /* #90 Check if Tls validation was not ok */
    case TCPIP_TLS_VALIDATION_NOT_OK:
      /* #100 Report leaf certificate and validation result to application */
      Scc_TLS_HandleConnectionInfo(TlsConnectionInfoPtr, ValidationResultPtr);
      Scc_Core_InterfaceCfg_Set_TLS_CertChain(NumCerts, CertChainStatusPtr, ValidationResultPtr);

#if (SCC_IDSM_REPORT == STD_ON)
      /* Validation result may be overwritten by the user */
      if (*ValidationResultPtr != TCPIP_TLS_VALIDATION_OK)
      {
        IdsM_SetSecurityEvent(SCC_IDSMEVENT_TLS_SERVER_CERT_INVALID);
      }
#endif /* SCC_IDSM_REPORT == STD_ON */
      break;

    default:
      Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerUnsupportedTlsValidationResult);
      break;
    }

#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
    /* #110 Check if a successful Tls communication is established */
    if (*ValidationResultPtr == TCPIP_TLS_VALIDATION_OK)
    {
      /* #120 Compute the resume session parameters */
      Scc_ComputeSessionResume(CertChainStatusPtr[0].CertId);
    }
#endif /* SCC_SCHEMA_ISO_20 != 0 */
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #130 Report default errors if any occurred. */
  if (errorId != SCC_DET_NO_ERROR)
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_TCP_IP_CERT, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */
} /*lint !e438 */ /* MD_MSR_DummyStmt */


/**********************************************************************************************************************
 * Scc_Cbk_TLS_ChangeableCipher
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
 */
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
FUNC(Std_ReturnType, SCC_CODE) Scc_Cbk_TLS_ChangeableCipher(
  Scc_SocketType                                                             SocketId,
  P2VAR(TcpIp_TlsCipherSuiteWorkingSetType, AUTOMATIC, SCC_APPL_DATA)        CipherSuiteWorkingSetPtr,
  P2VAR(TcpIp_TlsSignatureAlgorithmWorkingSetType, AUTOMATIC, SCC_APPL_DATA) SignatureAlgorithmWorkingSetPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA)                                   SccPushButtonModePtr,
  P2VAR(TcpIp_TlsChangeCipherStatusType, AUTOMATIC, SCC_APPL_DATA)           ChangeableCipherStatusPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = SCC_DET_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters */
  if (Scc_State == Scc_State_Uninitialized)
  {
    errorId = SCC_DET_NOT_INITIALIZED;
  }
  else if (Scc_V2GSocket != SocketId)
  {
    errorId = SCC_DET_INV_PARAM;
  }
  else if (CipherSuiteWorkingSetPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else if (SignatureAlgorithmWorkingSetPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else if (SccPushButtonModePtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else if (ChangeableCipherStatusPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else
# else /* SCC_DEV_ERROR_DETECT */
  SCC_DUMMY_STATEMENT(SocketId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif /* SCC_DEV_ERROR_DETECT */
  {
    uint8 cipherSuiteMaxLen = CipherSuiteWorkingSetPtr->workingSetLen;
    uint8 sigAlgoMaxLen = SignatureAlgorithmWorkingSetPtr->workingSetLen;;

    /* #20 Fetch from application if push button mode is active */
    *SccPushButtonModePtr = FALSE;
    Scc_Core_InterfaceCfg_Get_IsPushButtonModeInUsage(SccPushButtonModePtr);

    /* #30 Remove from signature algorithms all elliptic curves which were rejected by application */
# if (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
    Scc_Priv_RemoveRejectedEllipticCurvesFromWorkingSet(SignatureAlgorithmWorkingSetPtr);
#endif /* SCC_SCHEMA_ISO_20 */

    /* Update sigAlgoMaxLen, since it might was shorten because of a rejected elliptic curve */
    sigAlgoMaxLen = SignatureAlgorithmWorkingSetPtr->workingSetLen;

    /* #40 Fetch from application rearanged cipher suites, signature algorithm and state */
    *ChangeableCipherStatusPtr = TCPIP_TLS_CHANGE_CHIPHER_STATUS_READY;
    Scc_Core_InterfaceCfg_Get_PrioritizationCipherAndSignature(
      &(CipherSuiteWorkingSetPtr->workingSet[0]),
      &(CipherSuiteWorkingSetPtr->workingSetLen),
      &(SignatureAlgorithmWorkingSetPtr->workingSet[0]),
      &(SignatureAlgorithmWorkingSetPtr->workingSetLen),
      ChangeableCipherStatusPtr);

    /* #50 Check the current status of changing the priorities equals ready */
    if (*ChangeableCipherStatusPtr == TCPIP_TLS_CHANGE_CHIPHER_STATUS_READY)
    {

      /* #60 Check if the length of selected CipherSuites and SignatureAlgorithms is correct */
      if (   ((CipherSuiteWorkingSetPtr->workingSetLen) > 0u)
          && ((CipherSuiteWorkingSetPtr->workingSetLen) <= cipherSuiteMaxLen)
          && ((SignatureAlgorithmWorkingSetPtr->workingSetLen) > 0u)
          && ((SignatureAlgorithmWorkingSetPtr->workingSetLen) <= sigAlgoMaxLen)
         )
      {
        /* #70 Length check is ok */
        retVal = E_OK;
      }
      /* #80 Otherwise */
      else
      {
        /* #90 Report Error about incorrect length */
        retVal = E_NOT_OK;
        *ChangeableCipherStatusPtr = TCPIP_TLS_CHANGE_CHIPHER_STATUS_ERROR;
        Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerChangeCipherSuiteOrSignatureInvalidLength);
      }
    }
    /* #100 Otherwise: check if status equals pending */
    else if (*ChangeableCipherStatusPtr == TCPIP_TLS_CHANGE_CHIPHER_STATUS_PENDING)
    {
      /* #110 keep pending and set retVal to E_OK */
      retVal = E_OK;
    }
    /* #120 Otherwise: */
    else
    {
      /* #130 nothing to do, result equals already NOT_OK */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #140 Report default errors if any occurred */
  if (errorId != SCC_DET_NO_ERROR)
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_TCP_IP_CHANGE_CIPHER, errorId);
  }
# else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif /* SCC_DEV_ERROR_REPORT */

  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
} /* Scc_Cbk_TLS_ChangeableCipher */
#endif /* (SCC_ENABLE_TLS == STD_ON) */

#if ( SCC_ENABLE_TLS_RESUMPTION == STD_ON )
/**********************************************************************************************************************
 * Scc_Cbk_TLS_SessionTicketInfo
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Cbk_TLS_SessionTicketInfo(
  Scc_SocketType                                                        SocketId,
  P2CONST(TcpIp_TlsSessionTicketUserInfoType, AUTOMATIC, SCC_APPL_DATA) SessionTicketInfoPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters */
  if (Scc_State == Scc_State_Uninitialized)
  {
    errorId = SCC_DET_NOT_INITIALIZED;
  }
  else if (Scc_V2GSocket != SocketId)
  {
    errorId = SCC_DET_INV_PARAM;
  }
  else if (Scc_V2GSocketInUse == FALSE)
  {
    errorId = SCC_DET_INV_PARAM;
  }
  else if (SessionTicketInfoPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else
# endif /* SCC_DEV_ERROR_DETECT */
  {
    /* #20 Forward data to Application */
    Scc_Core_InterfaceCfg_Set_TlsSessionTicketInfo(SocketId, SessionTicketInfoPtr);
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #30 Report default errors if any occurred */
  if (errorId != SCC_DET_NO_ERROR)
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_TLS_SESSION_TICKET, errorId);
  }
# else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif /* SCC_DEV_ERROR_REPORT */
} /* Scc_Cbk_TLS_SessionTicketInfo */ /*lint !e438 */ /* MD_MSR_DummyStmt */
#endif /* (SCC_ENABLE_TLS_RESUMPTION == STD_ON) */

#if (defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_Clear
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO20VehicleChainList_Clear(
  P2VAR(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainPtr,
  uint8 VehicleChainLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least i = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear all entries of the list */
  for (i = 0u; i < (uint8_least)VehicleChainLen; i++)
  {
    VehicleChainPtr[i].ChainCfg = &Scc_ISO20CertConfig.VehicleCertsPtr[i];
    VehicleChainPtr[i].ChainState = SCC_ISO20VEHICLECHAINSTATE_UNUSEABLE;
  }
}

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_ContainsAtLeastOneUsable
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_CODE) Scc_ISO20VehicleChainList_ContainsAtLeastOneUsable(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainPtr,
  uint8 VehicleChainLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least i = 0u;
  boolean usableChainFound = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each entry of the list */
  for (i = 0u; i < (uint8_least)VehicleChainLen; i++)
  {
    /* #20 Check if usable chain is found */
    if (VehicleChainPtr[i].ChainState > SCC_ISO20VEHICLECHAINSTATE_FITSINTOTLSBUFFER)
    {
      usableChainFound = TRUE;
      break;
    }
  }

  return usableChainFound;
}

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_FilterOnSignatureHash
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
SCC_LOCAL FUNC(boolean, SCC_CODE) Scc_ISO20VehicleChainList_FilterOnSignatureHash(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainPtr,
  P2CONST(uint16, AUTOMATIC, SCC_CONST) SignatureAndHashAlgoListPtr,
  uint16 SignatureAndHashAlgoNum)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16_least i = 0u;
  boolean matchesAlgo = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each passed signature and hash algorithm */
  for (i = 0u; i < (uint16_least)SignatureAndHashAlgoNum; i++)
  {
    /* #20 Compare certificate curve against signature hash
     *      Match: Store match algorithm */
    if ( (VehicleChainPtr->ChainCfg->LeafCert.Curve == Scc_CertCurve_secp521r1)
      && ((uint16)TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512 == IPBASE_NTOH16(SignatureAndHashAlgoListPtr[i])))
    {
      matchesAlgo = TRUE;
    }
    else if (  (VehicleChainPtr->ChainCfg->LeafCert.Curve == Scc_CertCurve_curve448)
            && ((uint16)TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC == IPBASE_NTOH16(SignatureAndHashAlgoListPtr[i])))
    {
      matchesAlgo = TRUE;
    }
    else
    {
      /* Nothing to do */
    }

    /* #30 If one matching algorithm was found stop the search */
    if (matchesAlgo == TRUE)
    {
      break;
    }
  }

  return matchesAlgo;
}

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_FilterOnProvidedCAs
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
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO20VehicleChainList_FilterOnProvidedCAs(
  P2VAR(Scc_ISO20VehicleChainSelectionContext, AUTOMATIC, SCC_APPL_DATA) ContextPtr,
  P2CONST(TcpIp_TlsDistiguishedNameInfoType, AUTOMATIC, SCC_CONST) AuthorityListPtr,
  uint16 AuthorityListLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  uint16_least caIdx = 0u;
  uint16_least certIdx = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* [V2G20-2404] list may be empty, this is no error */
  /* #10 For each provided authority entry */
  for (caIdx = 0u; caIdx < (uint16_least)AuthorityListLen; caIdx++)
  {
    retVal = Scc_ReturnType_NotOK;

    /* #20 For each configured vehicle certificate */
    for (certIdx = 0u; certIdx  < (uint16_least)Scc_ISO20CertConfig.VehicleCertCnt; certIdx++)
    {
      P2VAR(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_CONST) vehicleChainPtr
        = &ContextPtr->VehicleChainList[certIdx];

      /* #30 If cert is useable, check if chain may be issued by authority */
      if (vehicleChainPtr->ChainState == SCC_ISO20VEHICLECHAINSTATE_MATCHESALGORITHM)
      {
        P2CONST(Scc_ISO20VehicleSubCaCertificateStructType, AUTOMATIC, SCC_CONST) subCaPtr = NULL_PTR;
        boolean matchesRoot = FALSE;

        /* #40 Select sub-CA cert to use based on configuration */
        if (vehicleChainPtr->ChainCfg->SubCaCnt >= 2u)
        {
          subCaPtr = &vehicleChainPtr->ChainCfg->SubCa1;
        }
        else
        {
          subCaPtr = &vehicleChainPtr->ChainCfg->SubCa2;
        }

        /* #50 Check if sub-CA cert is issued by the passed authority */
        if (E_OK == Scc_Core_KeyMUtils_CompareVehicleAgainstAuthority(
                      subCaPtr,
                      AuthorityListPtr[caIdx].DnPtr, AuthorityListPtr[caIdx].DnLen,
                      ContextPtr->TmpKeyMBufferPtr, ContextPtr->TmpKeyMBufferLen,
                      &matchesRoot))
        {
          if (matchesRoot == TRUE)
          {
            vehicleChainPtr->ChainState = SCC_ISO20VEHICLECHAINSTATE_MATCHESROOT;
          }
          retVal = Scc_ReturnType_OK;
        }
      }
      else
      {
        /* Continue with next vehicle certificate */
        retVal = Scc_ReturnType_OK;
      }
    }

    if (retVal != Scc_ReturnType_OK)
    {
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_Process
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO20VehicleChainList_Process(
  P2VAR(Scc_ISO20VehicleChainSelectionContext, AUTOMATIC, SCC_APPL_DATA) ContextPtr,
  P2CONST(TcpIp_TlsCertRequestInfoType, AUTOMATIC, SCC_CONST) RequestInfoPtr,
  uint8 MaxLenOfOutputCert)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8_least i = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear vehicle chain info list */
  Scc_ISO20VehicleChainList_Clear(&ContextPtr->VehicleChainList[0], SCC_ISO15118_20_VEHICLE_CERT_CNT);
  ContextPtr->VehicleChainListLen = SCC_ISO15118_20_VEHICLE_CERT_CNT;

  /* #20 For each configured vehicle certificate */
  for (i = 0u; i < (uint8_least)Scc_ISO20CertConfig.VehicleCertCnt; i++)
  {
    P2VAR(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_CONST) vehicleChainPtr
      = &ContextPtr->VehicleChainList[i];

    /* #30 Check if Tls outbuffer is big enough */
    if ((vehicleChainPtr->ChainCfg->SubCaCnt + 1u) <= MaxLenOfOutputCert)
    {
      vehicleChainPtr->ChainState = SCC_ISO20VEHICLECHAINSTATE_FITSINTOTLSBUFFER;
    }

    /* #40 Check if Chain is available */
    if (vehicleChainPtr->ChainState == SCC_ISO20VEHICLECHAINSTATE_FITSINTOTLSBUFFER)
    {
      boolean available = FALSE;

      /* #50 Update chain availability */
      retVal = Scc_Core_KeyMUtils_IsVehicleChainAvailable(
                vehicleChainPtr->ChainCfg,
                &available);

      if (   (retVal == Scc_ReturnType_OK)
          && (available == TRUE))
      {
        vehicleChainPtr->ChainState = SCC_ISO20VEHICLECHAINSTATE_AVAILABLE;
      }
    }
    else
    {
      retVal = Scc_ReturnType_OK;
    }

    /* #60 Check if chain matches signature and hash algorithm */
    if (vehicleChainPtr->ChainState == SCC_ISO20VEHICLECHAINSTATE_AVAILABLE)
    {
      if (TRUE == Scc_ISO20VehicleChainList_FilterOnSignatureHash(
                    vehicleChainPtr,
                    RequestInfoPtr->SignatureAndHashAlgoListPtr,
                    RequestInfoPtr->SignatureAndHashAlgoNum))
      {
        vehicleChainPtr->ChainState = SCC_ISO20VEHICLECHAINSTATE_MATCHESALGORITHM;
      }
    }

    if (retVal != Scc_ReturnType_OK)
    {
      break;
    }
  }

  /* #70 Check the vehicle chains against the received distinguished name of the authority */
  if (retVal == Scc_ReturnType_OK)
  {
      retVal = Scc_ISO20VehicleChainList_FilterOnProvidedCAs(
                ContextPtr,
                RequestInfoPtr->DistinguishedNameListPtr,
                RequestInfoPtr->DistinguishedNamesNum);
  }


  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_RemoveRejectedEllipticCurvesFromVehicleChainList
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO20VehicleChainList_RemoveRejectedEllipticCurvesFromVehicleChainList(
  P2VAR(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainListPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) VehicleChainListLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0u;
  uint8_least index_delete = 0u;
  uint8_least numOfCerts = (uint8_least)*VehicleChainListLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each vehicle certificate */
  for (index = 0u; index < numOfCerts; index++)
  {
    /* #20 Check if elliptic curve of certificate is rejected. If yes, then delete from list. */
    if (Scc_Priv_VehicleCertChainContainsRejectedEllipticCurve(VehicleChainListPtr[index].ChainCfg) == TRUE)
    {
      /* Iterate for (num of certs - 1) */
      for (index_delete = index; index_delete < (uint8_least)(numOfCerts - 1u); index_delete++)
      {
        /* Shift the later entry forwards to delete the current entry from list */
        VehicleChainListPtr[index_delete] = VehicleChainListPtr[index_delete + 1u];                                     /* PRQA S 2841 */ /* MD_SCC_ARRAY_OUT_OF_BOUND */
      }
      /* Decrement the list */
      (*VehicleChainListLen)--;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_SelectPreferredVehicleChain
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO20VehicleChainList_SelectPreferredVehicleChain(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainListPtr,
  uint8 VehicleChainListLen,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) PreferredChosen,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) PreferredIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least i = 0u;
  Scc_ISO20VehicleChainState rank = SCC_ISO20VEHICLECHAINSTATE_UNUSEABLE;

  /* ----- Implementation ----------------------------------------------- */
  *PreferredChosen = FALSE;
  *PreferredIdx = 0u;

  /* #10 For each vehicle certificate */
  for (i = 0u; i < (uint8_least)VehicleChainListLen; i++)
  {
    Scc_ISO20VehicleChainState tmpRank = VehicleChainListPtr[i].ChainState;
    boolean ellipticCurveIsRejected = Scc_Priv_VehicleCertChainContainsRejectedEllipticCurve(VehicleChainListPtr[i].ChainCfg);

    /* [V2G20-2427], [V2G20-2428], [V2G20-2429] */
    /* #20 Select an available vehicle certificate based on useability, matching algorithm and EVSE root */
    if (   (tmpRank >= SCC_ISO20VEHICLECHAINSTATE_MATCHESALGORITHM)
        && (rank < tmpRank)
        && (ellipticCurveIsRejected == FALSE))
    {
      rank = tmpRank;
      *PreferredChosen = TRUE;
      *PreferredIdx = (uint8)i;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_HandlePushButtonMode
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO20VehicleChainList_HandlePushButtonMode(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) SelectedVehicleChain,
  P2VAR(TcpIp_TlsClientCertInfoType, AUTOMATIC, SCC_APPL_DATA) TlsCertsPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  KeyM_CertificateIdType issuerCertId = 0u;
  /* Vehicle cert chain consists of Sub-Cas, Leaf and Root */
  uint8 requiredVehicleCertChainSize = SelectedVehicleChain->ChainCfg->SubCaCnt + SCC_CERT_ROOT_AND_LEAF_CNT;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the whole chain fits into buffer */
  if (TlsCertsPtr->CertIdListLen < requiredVehicleCertChainSize)
  {
    Scc_ReportError(Scc_StackError_InvalidTxParameter,
      SccDetailedError_Core_ISO20VehicleChainListHandlePushButtonModeListLengthInsufficient);
  }
  /* #20 Check if SubCa1 is certificate on highest hierarchical level and determine issuing certificate */
  else if ( SelectedVehicleChain->ChainCfg->SubCaCnt >= SCC_CERT_CHAIN_SUB_CA_MAX_CNT)
  {
    /* #30 Check if issuer certificate can be determined */
    if (Scc_ReportErrorCompSpecific(
          SCC_KEYM_GETISSUERCERTID(SelectedVehicleChain->ChainCfg->SubCa1.KeyMCertId, &issuerCertId),
          TRUE, Scc_StackError_KeyM,
          SccDetailedError_Core_ISO20VehicleChainListHandlePushButtonModeSubCa1IssuerNotAvailable) == E_OK )
    {
      /* #40 Add issuing certificate to Tls cert chain */
      TlsCertsPtr->CertIdList[requiredVehicleCertChainSize - 1u] = issuerCertId;  /*lint !e415 */                       /* PRQA S 2840 */ /* MD_SCC_TlsLenCheck */
      TlsCertsPtr->CertIdListLen = requiredVehicleCertChainSize;
      retVal = Scc_ReturnType_OK;
    }
  }
  /* #50 Check if SubCa2 is certificate on highest hierarchical level */
  else if ( SelectedVehicleChain->ChainCfg->SubCaCnt == SCC_CERT_CHAIN_SUB_CA_MIN_CNT)
  {
    /* #60 Check if issuer certificate can be determined */
    if (Scc_ReportErrorCompSpecific(
          SCC_KEYM_GETISSUERCERTID(SelectedVehicleChain->ChainCfg->SubCa2.KeyMCertId, &issuerCertId),
          TRUE, Scc_StackError_KeyM,
          SccDetailedError_Core_ISO20VehicleChainListHandlePushButtonModeSubCa2IssuerNotAvailable) == E_OK)
    {
      /* #70 Add issuing certificate to Tls cert chain */
      TlsCertsPtr->CertIdList[requiredVehicleCertChainSize - 1u] = issuerCertId;
      TlsCertsPtr->CertIdListLen = requiredVehicleCertChainSize;
      retVal = Scc_ReturnType_OK;
    }
  }
  /* #80 Otherwise */
  else
  {
    /* #90 Do nothing, error has been reported already and retVal is already set to E_NOT_OK */
  }

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_ISO20VehicleChainList_HandleApplication
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
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIG */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO20VehicleChainList_HandleApplication(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainListPtr,
  uint8 VehicleChainListLen,
  boolean PreferredIdxChosen,
  uint8 PreferredIdx,
  P2VAR(TcpIp_TlsClientCertInfoType, AUTOMATIC, SCC_APPL_DATA) TlsCertsPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 applSelection = PreferredIdx;
  uint8 prefIdx = PreferredIdx;
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) prefIdxPtr = NULL_PTR;
  Scc_ISO20VehicleChainSelectionType applState = SCC_ISO20VEHICLECHAINSELECTION_DONE;

  /* ----- Implementation ----------------------------------------------- */
  if (PreferredIdxChosen == TRUE)
  {
    prefIdxPtr = &prefIdx;
  }

  /* #10 Ask application on how to proceed */
  Scc_Core_InterfaceCfg_Get_SccTlsClientAuthParam(
    VehicleChainListPtr, VehicleChainListLen, prefIdxPtr,
    &applState, &applSelection);

  /* #20 Check if application is pending */
  if (applState == SCC_ISO20VEHICLECHAINSELECTION_PENDING)
  {
    /* #30 Yes: Try again later */
    retVal = Scc_ReturnType_Pending;
  }
  /* #40 Check if application has aborted */
  else if (applState != SCC_ISO20VEHICLECHAINSELECTION_DONE)
  {
    /* #50 Yes: Application aborted selection process */
  }
  /* #60 Check if selected chain index is valid */
  else if (applSelection >= (uint8)VehicleChainListLen)
  {
    /* #70 No: Report invalid application selection error */
    Scc_ReportError(Scc_StackError_InvalidTxParameter,
      SccDetailedError_Core_ISO20VehicleChainListHandleApplInvalidChainIdSelection);
  }
  /* #80 Check if selected chain is useable */
  else if (VehicleChainListPtr[applSelection].ChainState < SCC_ISO20VEHICLECHAINSTATE_MATCHESALGORITHM)
  {
    /* #90 No: Report error as unavailable cert can not be transmitted */
    Scc_ReportError(Scc_StackError_InvalidTxParameter,
      SccDetailedError_Core_ISO20VehicleChainListHandleApplInvalidChainSelection);
  }
  /* #100 Otherwise */
  else
  {
    /* #110 Provide the vehicle chain [V2G20-2424] */
    P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) selectedChain
      = &VehicleChainListPtr[applSelection];
    boolean isPushbuttonModeActive = FALSE;

    TlsCertsPtr->CertIdList[0u] = selectedChain->ChainCfg->LeafCert.KeyMCertId;
    TlsCertsPtr->PrivKeyId = selectedChain->ChainCfg->LeafCert.CsmPrivateKeyId;

    switch (selectedChain->ChainCfg->LeafCert.Curve)
    {
    case Scc_CertCurve_secp521r1:
      TlsCertsPtr->SignatureAndHashAlgo = TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512;
      retVal = Scc_ReturnType_OK;
      break;

    case Scc_CertCurve_curve448:
      TlsCertsPtr->SignatureAndHashAlgo = TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC;
      retVal = Scc_ReturnType_OK;
      break;

    default:
      retVal = Scc_ReturnType_NotOK;
      break;
    }

    TlsCertsPtr->CertIdList[1u] = selectedChain->ChainCfg->SubCa2.KeyMCertId;

    if (selectedChain->ChainCfg->SubCaCnt >= SCC_CERT_CHAIN_SUB_CA_MAX_CNT)
    {
      TlsCertsPtr->CertIdList[2u] = selectedChain->ChainCfg->SubCa1.KeyMCertId;
    }

    Scc_Core_InterfaceCfg_Get_IsPushButtonModeInUsage(&isPushbuttonModeActive);

    /* #120 Check if push button mode is active */
    if (isPushbuttonModeActive)
    {
      /* #130 Add root cert to Tls cert chain */
      retVal = Scc_ISO20VehicleChainList_HandlePushButtonMode(selectedChain, TlsCertsPtr);
    }
    /* #140 Otherwise */
    else
    {
      /* #150 Set chain length information excluding root */
      TlsCertsPtr->CertIdListLen = 1u + selectedChain->ChainCfg->SubCaCnt;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_Cbk_TLS_ClientAuthenticationRequest
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
/* PRQA S 6010,6030,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */
FUNC(Std_ReturnType, SCC_CODE) Scc_Cbk_TLS_ClientAuthenticationRequest(
  TcpIp_SocketIdType SocketId,
  P2CONST(TcpIp_TlsCertRequestInfoType, AUTOMATIC, SCC_CONST) RequestInfoPtr,
  P2VAR(TcpIp_TlsClientCertInfoType, AUTOMATIC, SCC_APPL_DATA) VehicleCertChainInfoPtr,
  P2VAR(TcpIp_TlsClientCertInfoStatusType, AUTOMATIC, SCC_APPL_DATA) VehicleCertChainInfoStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = SCC_DET_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters */
  if (Scc_State == Scc_State_Uninitialized)
  {
    errorId = SCC_DET_NOT_INITIALIZED;
  }
  else if (Scc_V2GSocket != SocketId)
  {
    errorId = SCC_DET_INV_PARAM;
  }
  else if (RequestInfoPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else if (VehicleCertChainInfoPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else if (VehicleCertChainInfoStatusPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else
# else /* SCC_DEV_ERROR_DETECT */
  SCC_DUMMY_STATEMENT(SocketId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif /* SCC_DEV_ERROR_DETECT */
  {
    Scc_ReturnType retValTmp = Scc_ReturnType_NotOK;

    *VehicleCertChainInfoStatusPtr = TCPIP_TLS_CLIENT_CERT_INFO_STATUS_ERROR;

    /* Perform selection to satisfy [V2G20-2424], [V2G20-2426], [V2G20-2427], [V2G20-2428], [V2G20-2429] */
    /* #20 Process Tls data */
    if (Scc_ISO20VehicleChainCtx.CurrentState == SCC_ISO20VEHICLECHAINSELECTION_PROCESS)
    {
      if (Scc_ReturnType_OK == Scc_ISO20VehicleChainList_Process(
                                &Scc_ISO20VehicleChainCtx, RequestInfoPtr,
                                VehicleCertChainInfoPtr->CertIdListLen))
      {
        /* #30 Sort out Tls data which uses a rejected elliptic curve */
        Scc_ISO20VehicleChainList_RemoveRejectedEllipticCurvesFromVehicleChainList(
          &Scc_ISO20VehicleChainCtx.VehicleChainList[0],
          &Scc_ISO20VehicleChainCtx.VehicleChainListLen);

        /* #40 Pre-select preferred chain */
        Scc_ISO20VehicleChainList_SelectPreferredVehicleChain(
          &Scc_ISO20VehicleChainCtx.VehicleChainList[0],
          Scc_ISO20VehicleChainCtx.VehicleChainListLen,
          &Scc_ISO20VehicleChainCtx.PreferredVehicleChainIdxChosen,
          &Scc_ISO20VehicleChainCtx.PreferredVehicleChainIdx);

        Scc_ISO20VehicleChainCtx.CurrentState = SCC_ISO20VEHICLECHAINSELECTION_CHECKAPPL;
      }
    }

    /* #50 Handle application selection of certs */
    if (Scc_ISO20VehicleChainCtx.CurrentState == SCC_ISO20VEHICLECHAINSELECTION_CHECKAPPL)
    {
      retValTmp = Scc_ISO20VehicleChainList_HandleApplication(
                    &Scc_ISO20VehicleChainCtx.VehicleChainList[0],
                    Scc_ISO20VehicleChainCtx.VehicleChainListLen,
                    Scc_ISO20VehicleChainCtx.PreferredVehicleChainIdxChosen,
                    Scc_ISO20VehicleChainCtx.PreferredVehicleChainIdx,
                    VehicleCertChainInfoPtr);
    }

    /*#60 Evaluate result of preceding operations */
    if (retValTmp == Scc_ReturnType_OK)
    {
      /* #70 Ok: Client cert found and forward to Tls */
      *VehicleCertChainInfoStatusPtr = TCPIP_TLS_CLIENT_CERT_INFO_STATUS_READY;
      retVal = E_OK;
    }
    else if (retValTmp == Scc_ReturnType_Pending)
    {
      /* #80 Ongoing: Try again later */
      *VehicleCertChainInfoStatusPtr = TCPIP_TLS_CLIENT_CERT_INFO_STATUS_PENDING;
      retVal = E_OK;
    }
    else if (TRUE == Scc_ISO20VehicleChainList_ContainsAtLeastOneUsable(
                      &Scc_ISO20VehicleChainCtx.VehicleChainList[0],
                      Scc_ISO20VehicleChainCtx.VehicleChainListLen))
    {
      /* #90 No vehicle: Indicate unavailable cert to Tls */
      *VehicleCertChainInfoStatusPtr = TCPIP_TLS_CLIENT_CERT_INFO_STATUS_NOT_AVAILABLE;
      VehicleCertChainInfoPtr->CertIdListLen = 0u;
    }
    else
    {
      /* #100 Error: Indicate error to Tls */
      *VehicleCertChainInfoStatusPtr = TCPIP_TLS_CLIENT_CERT_INFO_STATUS_ERROR;
      VehicleCertChainInfoPtr->CertIdListLen = 0u;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #110 Report default errors if any occurred */
  if (errorId != SCC_DET_NO_ERROR)
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_TCP_IP_CLIENTAUTH, errorId);
  }
# else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif /* SCC_DEV_ERROR_REPORT */

  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}
#endif /* SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_FirmwareDownloadComplete
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Cbk_SLAC_FirmwareDownloadComplete(boolean DownloadSuccessful)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if firmware download was successful and set global variable. */
  if ( TRUE == DownloadSuccessful )
  {
    /* firmware download is complete */
    Scc_PlcChipFirmwareStatus = Scc_PlcChipFirmwareStatus_DownloadDone;
  }
  else
  {
    /* firmware download did not complete successfully */
    Scc_PlcChipFirmwareStatus = Scc_PlcChipFirmwareStatus_ErrorOccurred;
  }
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_FirmwareDownloadStart
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */

FUNC(void, SCC_CODE) Scc_Cbk_SLAC_FirmwareDownloadStart(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Firmware download started, reset to Scc_PlcChipFirmwareStatus_Unknown. */
  Scc_PlcChipFirmwareStatus = Scc_PlcChipFirmwareStatus_Unknown;
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_AssociationStatus
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Cbk_SLAC_AssociationStatus(
  CONST(Slac_AssocStatusType, AUTOMATIC) AssocStatus)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if SLAC failed completely and report status to application. */
  if (AssocStatus.IsError == Slac_BT_True)
  {
    /* report the failure to the application */
    Scc_ReportError(Scc_StackError_SLAC, SccDetailedError_General_SlacAssociationStatusError);
  }

  /* provide detailed information to the application */
  Scc_SLAC_InterfaceCfg_Set_AssociationStatus(AssocStatus);

  return;
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_DLinkReady
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(void, SCC_CODE) Scc_Cbk_SLAC_DLinkReady(Slac_DLinkStatusType DLinkReady,
  Slac_BooleanType InfoValid,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) NMKPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) NIDPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) EvseMacPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_BufferPointerType BufPtr;

  /* ----- Implementation ----------------------------------------------- */
  Scc_DLinkReady = DLinkReady;

  /* provide the DLinkReady to the application */
  Scc_SLAC_InterfaceCfg_Set_DLinkReady(DLinkReady);
  /* #10 check if NMK and NID are valid report them to the application. */
  if (InfoValid == Slac_BT_True)
  {
    /* provide the NMK to the application */
    BufPtr.BufferLen = SLAC_MME_NMK_LEN;
    BufPtr.BufferPtr = NMKPtr;
    Scc_SLAC_InterfaceCfg_Set_NMK(&BufPtr);
    /* provide the NID to the application */
    BufPtr.BufferLen = SLAC_MME_NID_LEN;
    BufPtr.BufferPtr = NIDPtr;
    Scc_SLAC_InterfaceCfg_Set_NID(&BufPtr);
    /* provide the EvseMac to the application */
    BufPtr.BufferLen = ETH_PHYS_ADDR_LEN_BYTE;
    BufPtr.BufferPtr = EvseMacPtr;
    Scc_SLAC_InterfaceCfg_Set_EvseMac(&BufPtr);
  }
  else
  {
    BufPtr.BufferLen = 0;
    BufPtr.BufferPtr = NULL_PTR;

    /* provide the NMK to the application */
    Scc_SLAC_InterfaceCfg_Set_NMK(&BufPtr);
    /* provide the NID to the application */
    Scc_SLAC_InterfaceCfg_Set_NID(&BufPtr);
    /* provide the EvseMac to the application */
    Scc_SLAC_InterfaceCfg_Set_EvseMac(&BufPtr);
  }

  /* #20 check if SLAC was successful and report to the application. */
  if (Slac_DLS_Link == Scc_DLinkReady)
  {
    /* set the next state */
    Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest)
    /* report the success to the application */
    Scc_ReportSuccessAndStatus(Scc_MsgStatus_SLAC_OK);
  }
  /* check if no link could be established during SLAC */
  else if ( Scc_MsgTrig_SLAC == Scc_Core_Channel_Get_MsgTrig() )                                                        /* PRQA S 2004 */ /* MD_Scc_2004 */
  {
    /* report the failure to the application */
    Scc_ReportError(Scc_StackError_SLAC, SccDetailedError_General_SlacNoLinkEstablished);
  }
  /* if the link was lost, the module will be informed via the TrcvLinkStateChg callback */

  return;
} /*lint !e550 */ /* MD_Scc_VariantDependent */
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_GetRandomizedDataBuffer
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Cbk_SLAC_GetRandomizedDataBuffer(
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) RandomDataPtr,
  uint16 RandomDataLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_BufferPointerType exchangeData;

  /* ----- Implementation ----------------------------------------------- */
  exchangeData.BufferPtr = RandomDataPtr;
  exchangeData.BufferLen = RandomDataLen;
  /* #10 provide random data for the NMK and RunId. */
  Scc_SLAC_InterfaceCfg_Get_RandomData(&exchangeData);

  return;
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_GetValidateToggles
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(uint8, SCC_CODE) Scc_Cbk_SLAC_GetValidateToggles(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_BufferPointerType exchangeData;
  uint8 toggleNum;

  /* ----- Implementation ----------------------------------------------- */
  exchangeData.BufferPtr = &toggleNum;
  exchangeData.BufferLen = sizeof(toggleNum);
  /* #10 provide random data for toggle number. */
  Scc_SLAC_InterfaceCfg_Get_RandomData(&exchangeData);

  /* value might only be between 1 and 3 */
  return (( toggleNum % 3u ) + 1u );
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_SetBcbToggleState
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Cbk_SLAC_SetBcbToggleState(
  Slac_ControlPilotStateType NewCpState)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 inform the application that toggling shall be started. */
  Scc_SLAC_InterfaceCfg_Set_BcbToggleState(NewCpState);

  return;
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_GetExecuteValidationInfo
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Slac_ValidationExecutionType, SCC_CODE) Scc_Cbk_SLAC_GetExecuteValidationInfo(
  Slac_ValidationInfoType ValidationInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  Slac_ValidationExecutionType validationExecution = Slac_VE_DoNotValidate;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the ValidationInfo from Slac. */
  Scc_SLAC_InterfaceCfg_Set_ExecuteValidationInfo(ValidationInfo);

  /* #20 Return ValidationInfo got from application. */
  Scc_SLAC_InterfaceCfg_Get_ValidationInfo(&validationExecution);

  return validationExecution;
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_SetReadyForSlac
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
FUNC(void, SCC_CODE) Scc_Cbk_SLAC_SetReadyForSlac(boolean ReadyForSlac)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Indicate to the application if PLC chip is ready for slac. */
  Scc_SLAC_InterfaceCfg_Set_ReadyForSlac(ReadyForSlac);

  /* #20 Check if ReadyForSlac is TRUE. */
  if (ReadyForSlac == TRUE)
  {
    /* #30 Set Scc_PlcChipFirmwareStatus to ReadyForSlac. */
    Scc_PlcChipFirmwareStatus = Scc_PlcChipFirmwareStatus_ReadyForSlac;
  }
  /* #40 Otherwise set Scc_PlcChipFirmwareStatus to error occurred. */
  else
  {
    Scc_PlcChipFirmwareStatus = Scc_PlcChipFirmwareStatus_ErrorOccurred;
  }
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

/**********************************************************************************************************************
 *  Scc_Cbk_Eth_TransceiverLinkStateChange
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Cbk_Eth_TransceiverLinkStateChange(
  uint8 CtrlIdx,
  EthTrcv_LinkStateType TrcvLinkState)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 tcpIpCtrlIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this callback is for this controller. The CtrlIdx is checked against the currently set controller */
  (void)TcpIp_GetCtrlIdx(Scc_LocalAddrId, &tcpIpCtrlIdx);
  if ( tcpIpCtrlIdx == CtrlIdx )
  {
    /* #20 report the transceiver link state to the application. */
    if ( ETHTRCV_LINK_STATE_ACTIVE == TrcvLinkState )
    {
      /* link state is up */
      /* inform the application */
      Scc_Core_InterfaceCfg_Set_TrcvLinkState(TRUE);
    }
    else
    {
      /* link state is down */
      /* reset IP address state */
      Scc_IPAddressState = TCPIP_IPADDR_STATE_UNASSIGNED;
      /* inform the application */
      Scc_Core_InterfaceCfg_Set_TrcvLinkState(FALSE);
    }
  }

  return;
}

#if (defined SCC_IPADDR_SELECTION) && (SCC_IPADDR_SELECTION == STD_ON)
/**********************************************************************************************************************
 *  Scc_SetLocalAddrId
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
FUNC(Std_ReturnType, SCC_CODE) Scc_SetLocalAddrId(
  Scc_IpAddressSelectionEnumType IpAddressSelection)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters. */
  if (Scc_State == Scc_State_Uninitialized)
  {
    errorId = SCC_DET_NOT_INITIALIZED;
  }
  else
# endif /* SCC_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    SCC_ENTER_EXCLUSIVE_AREA_2();
    /* #20 Check if the SCC state allows setting of Scc_LocalAddrId */
    /* PRQA S 3415 2 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
    if ((Scc_State == Scc_State_Initialized)
      || (Scc_State > Scc_State_ShuttingDown))
    {
      /* #30 Set Scc_LocalAddrId */
      if (IpAddressSelection == SCC_IPADDR_SELECTION_ADDRESS1)
      {
        Scc_LocalAddrId = (uint8)SCC_IPV6_ADDRESS1;
        retVal = E_OK;
      }
      else if (IpAddressSelection == SCC_IPADDR_SELECTION_ADDRESS2)
      {
        Scc_LocalAddrId = (uint8)SCC_IPV6_ADDRESS2;
        retVal = E_OK;
      }
      else
      {
        /* Invalid value. Not Ok is already set */
      }

      /* #40 Check if IPAddressCnt is not 0 */
      if ((Scc_IPAddressState != TCPIP_IPADDR_STATE_UNASSIGNED) && (retVal == E_OK))
      {
        /* #50 Stop connection with charge point, reset state to init */
        Scc_State = Scc_State_Initialized;
        Scc_IPAddressState = TCPIP_IPADDR_STATE_UNASSIGNED;
        SCC_LEAVE_EXCLUSIVE_AREA_2();
        /* #60 inform the application about the loss of the IP addresses. */
        Scc_Core_InterfaceCfg_Set_IPAssigned(FALSE);
        Scc_Core_InterfaceCfg_Set_TrcvLinkState(FALSE);
      }
      else
      {
        SCC_LEAVE_EXCLUSIVE_AREA_2();
      }
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #70 Report default errors if any occurred. */
  if (errorId != SCC_DET_NO_ERROR)
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_SET_LOCAL_ADDR_ID, errorId);
  }
# else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif /* SCC_DEV_ERROR_REPORT */

  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}
#endif /* (SCC_IPADDR_SELECTION == STD_ON) */

/**********************************************************************************************************************
 *  Scc_Cbk_IP_AddressAssignmentChange
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
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
FUNC(void, SCC_CODE) Scc_Cbk_IP_AddressAssignmentChange(
  TcpIp_LocalAddrIdType LocalAddrId,
  TcpIp_IpAddrStateType State)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters. */
  if ( Scc_State == Scc_State_Uninitialized )
  {
    errorId = SCC_DET_NOT_INITIALIZED;
  }
  else
#endif /* SCC_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* It may happen that this callback is called in main function context of TcpIp.
     * And if Scc and TcpIp are assigned to different preemeptive tasks, this callback may be
     * interrupted by Scc main function context. */
    SCC_ENTER_EXCLUSIVE_AREA_2();
    /* check if this is the assigned address */
    if ( Scc_LocalAddrId == LocalAddrId )
    {
      /* check if the SCC was already initialized */
      if ( Scc_State_Initialized <= Scc_State )
      {
        switch (State)
        {
        case TCPIP_IPADDR_STATE_ASSIGNED:
        {
          boolean newIpAssigned = FALSE;

          /* Check if previous state was unassigned and not OnHold */
          if ( Scc_IPAddressState == TCPIP_IPADDR_STATE_UNASSIGNED )
          {
            newIpAssigned = TRUE;
          }

          /* Stop the onHold timer */
          Scc_TimeoutCntOnHold = 0;

          SCC_LEAVE_EXCLUSIVE_AREA_2();

          /* #20 inform the application about the IP assignment. */
          if (newIpAssigned == TRUE)
          {
            Scc_Core_InterfaceCfg_Set_IPAssigned(TRUE);
          }
          break;
        }

        case TCPIP_IPADDR_STATE_UNASSIGNED:
        {
          /* the IP address was lost */
          Scc_StateType tempState = Scc_State;

          /* stop connection with charge point, reset state to init */
          Scc_State = Scc_State_Initialized;
          SCC_LEAVE_EXCLUSIVE_AREA_2();

          /* #30 inform the application about the loss of the IP addresses. */
          Scc_Core_InterfaceCfg_Set_IPAssigned(FALSE);

          SCC_ENTER_EXCLUSIVE_AREA_2();

          /* Stop the onHold timer */
          Scc_TimeoutCntOnHold = 0;

          /* check if a V2G communication session was running */
          if (   (Scc_State_SDPComplete <= tempState)
              && (Scc_State_Disconnected >= tempState))
          {
            /* stop the timeout counter */
            Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = 0;
            SCC_LEAVE_EXCLUSIVE_AREA_2();

            /* reset the message state */
            Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest)
            /* report the error to the application */
            Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerIpAddressLost);
          }
          else
          {
            SCC_LEAVE_EXCLUSIVE_AREA_2();
          }
          break;
        }

        case TCPIP_IPADDR_STATE_ONHOLD:
        {
          uint16 onHoldTimerVal = 0u;
          /* OnHold. Start the related timer */
          SCC_LEAVE_EXCLUSIVE_AREA_2();

          onHoldTimerVal = Scc_TimerGeneral_TimerCfg_Get_OnHoldTimeout();

          SCC_ENTER_EXCLUSIVE_AREA_2();
          Scc_TimeoutCntOnHold = onHoldTimerVal;
          SCC_LEAVE_EXCLUSIVE_AREA_2();
          break;
        }

        default:
          SCC_LEAVE_EXCLUSIVE_AREA_2();
          break;
        }

        SCC_ENTER_EXCLUSIVE_AREA_2();
        Scc_IPAddressState = State;
        SCC_LEAVE_EXCLUSIVE_AREA_2();
      }
      else
      {
        SCC_LEAVE_EXCLUSIVE_AREA_2();
      }
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #40 Report default errors if any occurred. */
  if ( errorId != SCC_DET_NO_ERROR )
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_IP_ADDRESS_CHG_CBK, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */
}  /*lint !e438 */ /* MD_MSR_DummyStmt */


#if ( SCC_NUM_OF_DYN_CONFIG_PARAMS != 0 )
/**********************************************************************************************************************
 *  Scc_DynConfigDataReadAccess
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010,6030,6050 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL */
FUNC(Std_ReturnType, SCC_CODE) Scc_DynConfigDataReadAccess(
  Scc_DynConfigParamsType DataID,
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint32 localData = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if data could be read for given DataId */
  if (Scc_DynConfigDataReadAccessUint32(DataID, &localData) == E_OK)
  {
    /* #20 Check if Data is within uint16 limits */
    if (localData <= SCC_UINT16_MAX_NUM)
    {
      /* #30 Return Ok */
      *DataPtr = (uint16)localData;
      retVal = E_OK;
    }
  }

  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_DynConfigDataReadAccessUint32
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
/* PRQA S 6010,6030,6050 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL */
FUNC(Std_ReturnType, SCC_CODE) Scc_DynConfigDataReadAccessUint32(
  Scc_DynConfigParamsType DataID,
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;
  Std_ReturnType RetVal = E_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters. */
  if ( Scc_State == Scc_State_Uninitialized )
  {
    errorId = SCC_DET_NOT_INITIALIZED;
    RetVal = E_NOT_OK;
  }
  else if ( DataPtr == NULL_PTR )
  {
    errorId = SCC_DET_INV_POINTER;
    RetVal = E_NOT_OK;
  }
  else
#endif /* SCC_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    switch ( DataID )
    {

    /* #20 get value for Timer General */

  #if ( defined Scc_TimerGeneral_TimerCfg_ConfigType_IPAddressWaitTimeout ) && ( Scc_TimerGeneral_TimerCfg_ConfigType_IPAddressWaitTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_TimerGeneral_TimerCfg_IPAddressWaitTimeout:
      *DataPtr = (uint32)Scc_TimerGeneral_TimerCfg_Get_IPAddressWaitTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_TimerGeneral_TimerCfg_ConfigType_IPAddressWaitTimeout */

  #if ( defined Scc_TimerGeneral_TimerCfg_ConfigType_TransportLayerTimeout ) && ( Scc_TimerGeneral_TimerCfg_ConfigType_TransportLayerTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_TimerGeneral_TimerCfg_TransportLayerTimeout:
      *DataPtr = (uint32)Scc_TimerGeneral_TimerCfg_Get_TransportLayerTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_TimerGeneral_TimerCfg_ConfigType_TransportLayerTimeout */

#if ( defined Scc_TimerGeneral_TimerCfg_ConfigType_OnHoldTimeout ) && ( Scc_TimerGeneral_TimerCfg_ConfigType_OnHoldTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_TimerGeneral_TimerCfg_OnHoldTimeout:
      *DataPtr = (uint32)Scc_TimerGeneral_TimerCfg_Get_OnHoldTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_TimerGeneral_TimerCfg_ConfigType_OnHoldTimeout */

  #if ( defined Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolRetries ) && ( Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolRetries == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_SDP_TimerCfg_SECCDiscoveryProtocolRetries:
      *DataPtr = (uint32)Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolRetries();
      break;
  #endif /* Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolRetries */

  #if ( defined Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTlsRetries ) && ( Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTlsRetries == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_SDP_TimerCfg_SECCDiscoveryProtocolTlsRetries:
      *DataPtr = (uint32)Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolTlsRetries();
      break;
  #endif /* Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTlsRetries */

  #if ( defined Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTimeout ) && ( Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_SDP_TimerCfg_SECCDiscoveryProtocolTimeout:
      *DataPtr = (uint32)Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTimeout */

  #if ( defined Scc_SAP_TimerCfg_ConfigType_SupportedAppProtocolMessageTimeout ) && ( Scc_SAP_TimerCfg_ConfigType_SupportedAppProtocolMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_SAP_TimerCfg_SupportedAppProtocolMessageTimeout:
      *DataPtr = (uint32)Scc_SAP_TimerCfg_Get_SupportedAppProtocolMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_SAP_TimerCfg_ConfigType_SupportedAppProtocolMessageTimeout */

    /* #30 get value for Timer ISO */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_SequencePerformanceTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_SequencePerformanceTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_SequencePerformanceTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_SequencePerformanceTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_SequencePerformanceTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_CommunicationSetupTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_CommunicationSetupTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_CommunicationSetupTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_CommunicationSetupTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_CommunicationSetupTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_AuthorizationMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_AuthorizationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_AuthorizationMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_AuthorizationMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_AuthorizationMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_CableCheckMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_CableCheckMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_CableCheckMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_CableCheckMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_CableCheckMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_CertificateInstallationMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_CertificateInstallationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_CertificateInstallationMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_CertificateInstallationMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_CertificateInstallationMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_CertificateUpdateMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_CertificateUpdateMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_CertificateUpdateMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_CertificateUpdateMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_CertificateUpdateMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_ChargeParameterDiscoveryMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_ChargingStatusMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_ChargingStatusMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_ChargingStatusMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_ChargingStatusMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_ChargingStatusMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_CurrentDemandMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_CurrentDemandMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_CurrentDemandMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_CurrentDemandMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_CurrentDemandMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_MeteringReceiptMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_MeteringReceiptMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_MeteringReceiptMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_MeteringReceiptMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_MeteringReceiptMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_PaymentDetailsMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_PaymentDetailsMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_PaymentDetailsMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_PaymentDetailsMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_PaymentDetailsMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_PaymentServiceSelectionMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_PaymentServiceSelectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_PaymentServiceSelectionMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_PaymentServiceSelectionMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_PaymentServiceSelectionMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_PowerDeliveryMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_PowerDeliveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_PowerDeliveryMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_PowerDeliveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_PowerDeliveryMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_PreChargeMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_PreChargeMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_PreChargeMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_PreChargeMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_PreChargeMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDetailMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDetailMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_ServiceDetailMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_ServiceDetailMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDetailMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_ServiceDiscoveryMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_ServiceDiscoveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_SessionSetupMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_SessionSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_SessionSetupMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_SessionSetupMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_SessionSetupMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_SessionStopMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_SessionStopMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_SessionStopMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_SessionStopMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_SessionStopMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_WeldingDetectionMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_WeldingDetectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_WeldingDetectionMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_2_TimerCfg_Get_WeldingDetectionMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_WeldingDetectionMessageTimeout */


    /* #40 get value for Timer ISO15118-20 FDIS */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_SequencePerformanceTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_SequencePerformanceTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_SequencePerformanceTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_SequencePerformanceTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_CommunicationSetupTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_CommunicationSetupTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_CommunicationSetupTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_CommunicationSetupTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_CommunicationSetupTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_SessionSetupMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_SessionSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_SessionSetupMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_SessionSetupMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_SessionSetupMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationSetupMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_AuthorizationSetupMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_AuthorizationSetupMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationSetupMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_AuthorizationMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_AuthorizationMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationMessageTimeout */

#if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_CertificateInstallationMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_CertificateInstallationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_CertificateInstallationMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_CertificateInstallationMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_ISO15118_20_TimerCfg_ConfigType_CertificateInstallationMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ServiceDiscoveryMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_ServiceDiscoveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDetailMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDetailMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ServiceDetailMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_ServiceDetailMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDetailMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ServiceSelectionMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ServiceSelectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ServiceSelectionMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_ServiceSelectionMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ServiceSelectionMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ChargeParameterDiscoveryMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ScheduleExchangeMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ScheduleExchangeMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ScheduleExchangeMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_ScheduleExchangeMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ScheduleExchangeMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_PowerDeliveryMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_PowerDeliveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_PowerDeliveryMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_PowerDeliveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_PowerDeliveryMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_MeteringConfirmationMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_MeteringConfirmationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_MeteringConfirmationMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_MeteringConfirmationMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_MeteringConfirmationMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_SessionStopMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_SessionStopMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_SessionStopMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_SessionStopMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_SessionStopMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_CableCheckMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_CableCheckMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_CableCheckMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_CableCheckMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_CableCheckMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_PreChargeMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_PreChargeMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_PreChargeMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_PreChargeMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_PreChargeMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ChargeLoopMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_ChargeLoopMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_WeldingDetectionMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_WeldingDetectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_WeldingDetectionMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_WeldingDetectionMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_WeldingDetectionMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopSequencePerformanceTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopSequencePerformanceTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ChargeLoopSequencePerformanceTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_ChargeLoopSequencePerformanceTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopSequencePerformanceTimeout */


    /* #50 get value for Timer ISO15118-20WPT FDIS */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningSetupMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_FinePositioningSetupMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_FinePositioningSetupMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningSetupMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_FinePositioningMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_FinePositioningMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_PairingMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_PairingMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_PairingMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_PairingMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_PairingMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_AlignmentCheckMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_AlignmentCheckMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_AlignmentCheckMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_AlignmentCheckMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_AlignmentCheckMessageTimeout */

    /* #60 get value for Timer ISO15118-20ACDP FDIS */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_VehiclePositioningMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_VehiclePositioningMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_VehiclePositioningMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_VehiclePositioningMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_VehiclePositioningMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ConnectMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ConnectMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ConnectMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_ConnectMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ConnectMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_DisconnectMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_DisconnectMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_DisconnectMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_DisconnectMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_DisconnectMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_SystemStatusMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_SystemStatusMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_SystemStatusMessageTimeout:
      *DataPtr = (uint32)Scc_ISO15118_20_TimerCfg_Get_SystemStatusMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_SystemStatusMessageTimeout */

    /* #70 get value for Timer DIN */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_SequencePerformanceTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_SequencePerformanceTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_SequencePerformanceTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_SequencePerformanceTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType__SequencePerformanceTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_CommunicationSetupTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_CommunicationSetupTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_CommunicationSetupTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_CommunicationSetupTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_CommunicationSetupTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_ReadyToChargeTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_ReadyToChargeTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_ReadyToChargeTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_ReadyToChargeTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_ReadyToChargeTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_ContractAuthenticationMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_ContractAuthenticationMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_CableCheckMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_CableCheckMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_CableCheckMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_CableCheckMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_CableCheckMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_ChargeParameterDiscoveryMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_CurrentDemandMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_CurrentDemandMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_CurrentDemandMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_CurrentDemandMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_CurrentDemandMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_ServicePaymentSelectionMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_ServicePaymentSelectionMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_PowerDeliveryMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_PowerDeliveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_PowerDeliveryMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_PowerDeliveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_PowerDeliveryMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_PreChargeMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_PreChargeMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_PreChargeMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_PreChargeMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_PreChargeMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_ServiceDiscoveryMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_ServiceDiscoveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_SessionSetupMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_SessionSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_SessionSetupMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_SessionSetupMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_SessionSetupMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_SessionStopMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_SessionStopMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_SessionStopMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_SessionStopMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_SessionStopMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_WeldingDetectionMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_WeldingDetectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_WeldingDetectionMessageTimeout:
      *DataPtr = (uint32)Scc_DIN70121_TimerCfg_Get_WeldingDetectionMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_WeldingDetectionMessageTimeout */


      /* #80 get value for Timer OppCharge */
#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutChargeParameterDiscovery ) && ( Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutChargeParameterDiscovery == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SequencePerformanceTimeoutChargeParameterDiscovery:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_SequencePerformanceTimeoutChargeParameterDiscovery() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutChargeParameterDiscovery */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutCableCheck ) && ( Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutCableCheck == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SequencePerformanceTimeoutCableCheck:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_SequencePerformanceTimeoutCableCheck() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutCableCheck */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPreCharge ) && ( Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPreCharge == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SequencePerformanceTimeoutPreCharge:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_SequencePerformanceTimeoutPreCharge() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPreCharge */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPowerDelivery ) && ( Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPowerDelivery == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SequencePerformanceTimeoutPowerDelivery:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_SequencePerformanceTimeoutPowerDelivery() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPowerDelivery */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_ContractAuthenticationMessageTimeout:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_ContractAuthenticationMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_CableCheckMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_CableCheckMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_CableCheckMessageTimeout:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_CableCheckMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_CableCheckMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_ChargeParameterDiscoveryMessageTimeout:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_CurrentDemandMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_CurrentDemandMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_CurrentDemandMessageTimeout:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_CurrentDemandMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_CurrentDemandMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_ServicePaymentSelectionMessageTimeout:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_ServicePaymentSelectionMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_PowerDeliveryMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_PowerDeliveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_PowerDeliveryMessageTimeout:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_PowerDeliveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_PowerDeliveryMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_PreChargeMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_PreChargeMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_PreChargeMessageTimeout:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_PreChargeMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_PreChargeMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_ServiceDiscoveryMessageTimeout:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_ServiceDiscoveryMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SessionSetupMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_SessionSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SessionSetupMessageTimeout:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_SessionSetupMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SessionSetupMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SessionStopMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_SessionStopMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SessionStopMessageTimeout:
      *DataPtr = (uint32)Scc_OppCharge_TimerCfg_Get_SessionStopMessageTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SessionStopMessageTimeout */


  #if ( defined SCC_ENABLE_STATE_MACHINE )

    /* #90 get value for OEM Vector - State Machine */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_AcceptUnsecureConnection ) && ( Scc_StateM_ParamCfg_ConfigType_AcceptUnsecureConnection == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Accept Unsecure Connection */
    case Scc_DynConfigParam_StateM_ParamCfg_AcceptUnsecureConnection:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_AcceptUnsecureConnection();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_AcceptUnsecureConnection */

#if ( defined Scc_StateM_ParamCfg_ConfigType_AcceptFreeCertificateServicesOnly ) && ( Scc_StateM_ParamCfg_ConfigType_AcceptFreeCertificateServicesOnly == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Accept Free Certificate Services Only */
    case Scc_DynConfigParam_StateM_ParamCfg_AcceptFreeCertificateServicesOnly:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_AcceptFreeCertificateServicesOnly();
      break;
#endif /* Scc_StateM_ParamCfg_ConfigType_AcceptFreeCertificateServicesOnly */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ReconnectRetries ) && ( Scc_StateM_ParamCfg_ConfigType_ReconnectRetries == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Reconnect Retries */
    case Scc_DynConfigParam_StateM_ParamCfg_ReconnectRetries:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ReconnectRetries();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ReconnectRetries */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ReconnectDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ReconnectDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Reconnect Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_ReconnectDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ReconnectDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ReconnectDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_RequestInternetDetails ) && ( Scc_StateM_ParamCfg_ConfigType_RequestInternetDetails == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Request Internet Details */
    case Scc_DynConfigParam_StateM_ParamCfg_RequestInternetDetails:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_RequestInternetDetails();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_RequestInternetDetails */

#if ( defined Scc_StateM_ParamCfg_ConfigType_TLConnectedWaitTime ) && ( Scc_StateM_ParamCfg_ConfigType_TLConnectedWaitTime == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* TLConnectedWaitTime */
    case Scc_DynConfigParam_StateM_ParamCfg_TLConnectedWaitTime:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_TLConnectedWaitTime() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
#endif /* Scc_StateM_ParamCfg_ConfigType_TLConnectedWaitTime */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_AuthorizationOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_AuthorizationOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Authorization Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_AuthorizationOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_AuthorizationOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_AuthorizationOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_VehiclePositioningNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_VehiclePositioningNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* ACDP_VehiclePositioning Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_VehiclePositioningNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_VehiclePositioningNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_VehiclePositioningNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_VehiclePositioningOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_VehiclePositioningOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* ACDP_VehiclePositioning Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_VehiclePositioningOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_VehiclePositioningOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_VehiclePositioningOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ConnectNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ConnectNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* ACDP_Connect Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_ConnectNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ConnectNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ConnectNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ConnectOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_ConnectOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* ACDP_Connect Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_ConnectOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ConnectOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ConnectOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_DisconnectNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_DisconnectNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* ACDP_Disconnect Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_DisconnectNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_DisconnectNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_DisconnectNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_DisconnectOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_DisconnectOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* ACDP_Disconnect Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_DisconnectOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_DisconnectOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_DisconnectOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Charge Parameter Discovery Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_ChargeParameterDiscoveryOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Charge Parameter Discovery Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_ScheduleExchangeOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ScheduleExchangeOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_CableCheckOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_CableCheckOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */

      /* CableCheck Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_CableCheckOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_CableCheckOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CableCheckOngoingTimeout */



  #if ( defined Scc_StateM_ParamCfg_ConfigType_CableCheckTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_CableCheckTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* CableCheck Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_CableCheckTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_CableCheckTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CableCheckTimeout */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_PreChargeTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_PreChargeTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* PreCharge Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_PreChargeTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_PreChargeTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PreChargeTimeout */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_ISO_20_PreChargeTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_ISO_20_PreChargeTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* PreCharge Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_ISO_20_PreChargeTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ISO_20_PreChargeTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ISO_20_PreChargeTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_AuthorizationNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_AuthorizationNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */

      /* Authorization Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_AuthorizationNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_AuthorizationNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_AuthorizationNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_CertificateInstallationNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_CertificateInstallationNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Certificate Installation Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_CertificateInstallationNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_CertificateInstallationNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CertificateInstallationNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_CertificateInstallationOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_CertificateInstallationOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Certificate Installation Ongoing Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_CertificateInstallationOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_CertificateInstallationOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CertificateInstallationOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_SessionStopNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_SessionStopNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_SessionStopNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_SessionStopNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_SessionStopNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_FinePositioningSetupNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_FinePositioningSetupNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_FinePositioningSetupNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_FinePositioningSetupNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_FinePositioningSetupNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_FinePositioningNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_FinePositioningNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_FinePositioningNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_FinePositioningNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_FinePositioningNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_PairingNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_PairingNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_PairingNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_PairingNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PairingNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */

      /* Charge Parameter Discovery Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_ChargeParameterDiscoveryNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_AlignmentCheckNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_AlignmentCheckNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_AlignmentCheckNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_AlignmentCheckNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_AlignmentCheckNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_ChargingStatusNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ChargingStatusNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Charging Status Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_ChargingStatusNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ChargingStatusNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ChargingStatusNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_CableCheckNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_CableCheckNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Cable Check Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_CableCheckNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_CableCheckNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CableCheckNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_ChargeLoopNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ChargeLoopNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* ChargeLoop Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_ChargeLoopNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ChargeLoopNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ChargeLoopNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_PreChargeNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_PreChargeNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Pre Charge Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_PreChargeNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_PreChargeNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PreChargeNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* ScheduleExchange Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_ScheduleExchangeNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ScheduleExchangeNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_PowerDeliveryNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_PowerDeliveryNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* PowerDelivery Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_PowerDeliveryNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_PowerDeliveryNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PowerDeliveryNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_ServiceDetailNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ServiceDetailNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* ServiceDetail Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_ServiceDetailNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ServiceDetailNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ServiceDetailNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_CurrentDemandNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_CurrentDemandNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Current Demand Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_CurrentDemandNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_CurrentDemandNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CurrentDemandNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* SECCDiscoveryProtocol Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_SECCDiscoveryProtocolNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_SECCDiscoveryProtocolNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolDiagStatusOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolDiagStatusOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* SECCDiscoveryProtocol Diag Status Ongoing Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_SECCDiscoveryProtocolDiagStatusOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_SECCDiscoveryProtocolDiagStatusOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolDiagStatusOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_FinePositioningOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_FinePositioningOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* FinePositioning Ongoing Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_FinePositioningOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_FinePositioningOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_FinePositioningOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_PairingOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_PairingOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Pairing Ongoing Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_PairingOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_PairingOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PairingOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_AlignmentCheckOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_AlignmentCheckOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* AlignmentCheck Ongoing Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_AlignmentCheckOngoingTimeout:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_AlignmentCheckOngoingTimeout() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_AlignmentCheckOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ServiceRenegotiation ) && ( Scc_StateM_ParamCfg_ConfigType_ServiceRenegotiation == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* ServiceRenegotiation */
    case Scc_DynConfigParam_StateM_ParamCfg_ServiceRenegotiation:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ServiceRenegotiation();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ServiceRenegotiation */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_WeldingDetectionNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_WeldingDetectionNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Welding Detection Next Request Delay */
    case Scc_DynConfigParam_StateM_ParamCfg_WeldingDetectionNextReqDelay:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_WeldingDetectionNextReqDelay() * SCC_MAIN_FUNCTION_PERIOD_MS;
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_WeldingDetectionNextReqDelay */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_PaymentPrioritization ) && ( Scc_StateM_ParamCfg_ConfigType_PaymentPrioritization == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Payment Priorisation */
    case Scc_DynConfigParam_StateM_ParamCfg_PaymentPrioritization:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_PaymentPrioritization();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PaymentPrioritization */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_ContractCertificateChainIndexInUse ) && ( Scc_StateM_ParamCfg_ConfigType_ContractCertificateChainIndexInUse == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Selected Contract Certificate Slot */
    case Scc_DynConfigParam_StateM_ParamCfg_ContractCertificateChainIndexInUse:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_ContractCertificateChainIndexInUse();
      break;
  #endif /* Scc_DynConfigParam_StateM_ParamCfg_ContractCertificateChainIndexInUse */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_CertificateExpireThreshold ) && ( Scc_StateM_ParamCfg_ConfigType_CertificateExpireThreshold == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Certificate Expire Threshold */
    case Scc_DynConfigParam_StateM_ParamCfg_CertificateExpireThreshold:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_CertificateExpireThreshold();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CertificateExpireThreshold */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_RequestCertificateDetails ) && ( Scc_StateM_ParamCfg_ConfigType_RequestCertificateDetails == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Request Certificate Details */
    case Scc_DynConfigParam_StateM_ParamCfg_RequestCertificateDetails:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_RequestCertificateDetails();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_RequestCertificateDetails */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_RequestCertificateInstallation ) && ( Scc_StateM_ParamCfg_ConfigType_RequestCertificateInstallation == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Request Certificate Install */
    case Scc_DynConfigParam_StateM_ParamCfg_RequestCertificateInstallation:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_RequestCertificateInstallation();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_RequestCertificateInstallation */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_RequestCertificateUpdate ) && ( Scc_StateM_ParamCfg_ConfigType_RequestCertificateUpdate == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Request Certificate Update */
    case Scc_DynConfigParam_StateM_ParamCfg_RequestCertificateUpdate:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_RequestCertificateUpdate();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_RequestCertificateUpdate */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_SLACAmpMapMode ) && ( Scc_StateM_ParamCfg_ConfigType_SLACAmpMapMode == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* SLACAmpMapMode */
    case Scc_DynConfigParam_StateM_ParamCfg_SLACAmpMapMode:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_SLACAmpMapMode();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_SLACAmpMapMode */


  #if ( defined Scc_StateM_ParamCfg_ConfigType_IsTlsInSdpPossible ) && ( Scc_StateM_ParamCfg_ConfigType_IsTlsInSdpPossible == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* IsTlsInSdpPossible */
    case Scc_DynConfigParam_StateM_ParamCfg_IsTlsInSdpPossible:
      *DataPtr = (uint32)Scc_StateM_ParamCfg_Get_IsTlsInSdpPossible();
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_IsTlsInSdpPossible */


  #endif /* SCC_ENABLE_STATE_MACHINE */

      /* invalid DataID */
    default:
      RetVal = E_NOT_OK;
      break;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #100 Report default errors if any occurred. */
  if ( errorId != SCC_DET_NO_ERROR )
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_DIAG_DATA_READ_ACCESS, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */

  return RetVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}
#endif /* SCC_NUM_OF_DYN_CONFIG_PARAMS */


#if ( SCC_NUM_OF_DYN_CONFIG_PARAMS != 0 )
/**********************************************************************************************************************
 *  Scc_DynConfigDataWriteAccess
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
/* PRQA S 6010,6030,6050 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL */
FUNC(Std_ReturnType, SCC_CODE) Scc_DynConfigDataWriteAccess(
  Scc_DynConfigParamsType DataID,
  uint16 Data)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;
  Std_ReturnType RetVal = E_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters. */
  if ( Scc_State == Scc_State_Uninitialized )
  {
    errorId = SCC_DET_NOT_INITIALIZED;
    RetVal = E_NOT_OK;
  }
  else
#endif /* SCC_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */

    switch ( DataID )
    {

    /* #20 set value for Timer General */

  #if ( defined Scc_TimerGeneral_TimerCfg_ConfigType_IPAddressWaitTimeout ) && ( Scc_TimerGeneral_TimerCfg_ConfigType_IPAddressWaitTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_TimerGeneral_TimerCfg_IPAddressWaitTimeout:
      Scc_TimerGeneral_TimerCfg_Set_IPAddressWaitTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_TimerGeneral_TimerCfg_ConfigType_IPAddressWaitTimeout */

  #if ( defined Scc_TimerGeneral_TimerCfg_ConfigType_TransportLayerTimeout ) && ( Scc_TimerGeneral_TimerCfg_ConfigType_TransportLayerTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_TimerGeneral_TimerCfg_TransportLayerTimeout:
      Scc_TimerGeneral_TimerCfg_Set_TransportLayerTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_TimerGeneral_TimerCfg_ConfigType_TransportLayerTimeout */

#if ( defined Scc_TimerGeneral_TimerCfg_ConfigType_OnHoldTimeout ) && ( Scc_TimerGeneral_TimerCfg_ConfigType_OnHoldTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_TimerGeneral_TimerCfg_OnHoldTimeout:
      Scc_TimerGeneral_TimerCfg_Set_OnHoldTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_TimerGeneral_TimerCfg_ConfigType_OnHoldTimeout */

  #if ( defined Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolRetries ) && ( Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolRetries == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_SDP_TimerCfg_SECCDiscoveryProtocolRetries:
      Scc_SDP_TimerCfg_Set_SECCDiscoveryProtocolRetries(Data);
      break;
  #endif /* Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolRetries */

  #if ( defined Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTlsRetries ) && ( Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTlsRetries == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_SDP_TimerCfg_SECCDiscoveryProtocolTlsRetries:
      Scc_SDP_TimerCfg_Set_SECCDiscoveryProtocolTlsRetries(Data);
      break;
  #endif /* Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTlsRetries */

  #if ( defined Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTimeout ) && ( Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_SDP_TimerCfg_SECCDiscoveryProtocolTimeout:
      Scc_SDP_TimerCfg_Set_SECCDiscoveryProtocolTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_SDP_TimerCfg_ConfigType_SECCDiscoveryProtocolTimeout */

  #if ( defined Scc_SAP_TimerCfg_ConfigType_SupportedAppProtocolMessageTimeout ) && ( Scc_SAP_TimerCfg_ConfigType_SupportedAppProtocolMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_SAP_TimerCfg_SupportedAppProtocolMessageTimeout:
      Scc_SAP_TimerCfg_Set_SupportedAppProtocolMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_SAP_TimerCfg_ConfigType_SupportedAppProtocolMessageTimeout */

    /* #30 set value for Timer ISO */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_SequencePerformanceTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_SequencePerformanceTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_SequencePerformanceTimeout:
      Scc_ISO15118_2_TimerCfg_Set_SequencePerformanceTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_SequencePerformanceTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_CommunicationSetupTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_CommunicationSetupTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_CommunicationSetupTimeout:
      Scc_ISO15118_2_TimerCfg_Set_CommunicationSetupTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_CommunicationSetupTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_AuthorizationMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_AuthorizationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_AuthorizationMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_AuthorizationMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_AuthorizationMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_CableCheckMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_CableCheckMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_CableCheckMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_CableCheckMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_CableCheckMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_CertificateInstallationMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_CertificateInstallationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_CertificateInstallationMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_CertificateInstallationMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_CertificateInstallationMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_CertificateUpdateMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_CertificateUpdateMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_CertificateUpdateMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_CertificateUpdateMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_CertificateUpdateMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_ChargeParameterDiscoveryMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_ChargeParameterDiscoveryMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_ChargingStatusMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_ChargingStatusMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_ChargingStatusMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_ChargingStatusMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_ChargingStatusMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_CurrentDemandMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_CurrentDemandMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_CurrentDemandMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_CurrentDemandMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_CurrentDemandMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_MeteringReceiptMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_MeteringReceiptMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_MeteringReceiptMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_MeteringReceiptMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_MeteringReceiptMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_PaymentDetailsMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_PaymentDetailsMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_PaymentDetailsMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_PaymentDetailsMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_PaymentDetailsMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_PaymentServiceSelectionMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_PaymentServiceSelectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_PaymentServiceSelectionMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_PaymentServiceSelectionMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_PaymentServiceSelectionMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_PowerDeliveryMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_PowerDeliveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_PowerDeliveryMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_PowerDeliveryMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_PowerDeliveryMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_PreChargeMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_PreChargeMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_PreChargeMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_PreChargeMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_PreChargeMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDetailMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDetailMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_ServiceDetailMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_ServiceDetailMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDetailMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_ServiceDiscoveryMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_ServiceDiscoveryMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_SessionSetupMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_SessionSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_SessionSetupMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_SessionSetupMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_SessionSetupMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_SessionStopMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_SessionStopMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_SessionStopMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_SessionStopMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_SessionStopMessageTimeout */

  #if ( defined Scc_ISO15118_2_TimerCfg_ConfigType_WeldingDetectionMessageTimeout ) && ( Scc_ISO15118_2_TimerCfg_ConfigType_WeldingDetectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_2_TimerCfg_WeldingDetectionMessageTimeout:
      Scc_ISO15118_2_TimerCfg_Set_WeldingDetectionMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_2_TimerCfg_ConfigType_WeldingDetectionMessageTimeout */


    /* #40 set value for Timer ISO15118-20 FDIS */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_SequencePerformanceTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_SequencePerformanceTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_SequencePerformanceTimeout:
      Scc_ISO15118_20_TimerCfg_Set_SequencePerformanceTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_SequencePerformanceTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_CommunicationSetupTimeout ) && ( Scc_ISO15118_20_TimerCfg_ConfigType_CommunicationSetupTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_CommunicationSetupTimeout:
      Scc_ISO15118_20_TimerCfg_Set_CommunicationSetupTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_CommunicationSetupTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_SessionSetupMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_SessionSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_SessionSetupMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_SessionSetupMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_SessionSetupMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationSetupMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_AuthorizationSetupMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_AuthorizationSetupMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationSetupMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_AuthorizationMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_AuthorizationMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_CertificateInstallationMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_CertificateInstallationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_CertificateInstallationMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_CertificateInstallationMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_CertificateInstallationMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ServiceDiscoveryMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_ServiceDiscoveryMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDetailMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDetailMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ServiceDetailMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_ServiceDetailMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDetailMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ServiceSelectionMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ServiceSelectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ServiceSelectionMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_ServiceSelectionMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ServiceSelectionMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ChargeParameterDiscoveryMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_ChargeParameterDiscoveryMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ScheduleExchangeMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ScheduleExchangeMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ScheduleExchangeMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_ScheduleExchangeMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ScheduleExchangeMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_PowerDeliveryMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_PowerDeliveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_PowerDeliveryMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_PowerDeliveryMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_PowerDeliveryMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_MeteringConfirmationMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_MeteringConfirmationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_MeteringConfirmationMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_MeteringConfirmationMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_MeteringConfirmationMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_SessionStopMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_SessionStopMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_SessionStopMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_SessionStopMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_SessionStopMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_CableCheckMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_CableCheckMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_CableCheckMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_CableCheckMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_CableCheckMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_PreChargeMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_PreChargeMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_PreChargeMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_PreChargeMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_PreChargeMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ChargeLoopMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_ChargeLoopMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_WeldingDetectionMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_WeldingDetectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_WeldingDetectionMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_WeldingDetectionMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_WeldingDetectionMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopSequencePerformanceTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopSequencePerformanceTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ChargeLoopSequencePerformanceTimeout:
      Scc_ISO15118_20_TimerCfg_Set_ChargeLoopSequencePerformanceTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopSequencePerformanceTimeout */

    /* #50 set value for Timer ISO15118-20WPT FDIS */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningSetupMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_FinePositioningSetupMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_FinePositioningSetupMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningSetupMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_FinePositioningMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_FinePositioningMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_FinePositioningMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_PairingMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_PairingMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_PairingMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_PairingMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_PairingMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_AlignmentCheckMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_AlignmentCheckMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_AlignmentCheckMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_AlignmentCheckMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_AlignmentCheckMessageTimeout */

    /* #60 set value for Timer ISO15118-20ACDP FDIS */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_VehiclePositioningMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_VehiclePositioningMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_VehiclePositioningMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_VehiclePositioningMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_VehiclePositioningMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_ConnectMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_ConnectMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_ConnectMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_ConnectMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_ConnectMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_DisconnectMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_DisconnectMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_DisconnectMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_DisconnectMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_DisconnectMessageTimeout */

  #if ( defined Scc_ISO15118_20_TimerCfg_ConfigType_SystemStatusMessageTimeout) && ( Scc_ISO15118_20_TimerCfg_ConfigType_SystemStatusMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_ISO15118_20_TimerCfg_SystemStatusMessageTimeout:
      Scc_ISO15118_20_TimerCfg_Set_SystemStatusMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_ISO15118_20_TimerCfg_ConfigType_SystemStatusMessageTimeout */

    /* #70 set value for Timer DIN */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_SequencePerformanceTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_SequencePerformanceTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_SequencePerformanceTimeout:
      Scc_DIN70121_TimerCfg_Set_SequencePerformanceTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_SequencePerformanceTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_CommunicationSetupTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_CommunicationSetupTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_CommunicationSetupTimeout:
      Scc_DIN70121_TimerCfg_Set_CommunicationSetupTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_CommunicationSetupTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_ReadyToChargeTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_ReadyToChargeTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_ReadyToChargeTimeout:
      Scc_DIN70121_TimerCfg_Set_ReadyToChargeTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_ReadyToChargeTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_ContractAuthenticationMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_ContractAuthenticationMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_CableCheckMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_CableCheckMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_CableCheckMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_CableCheckMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_CableCheckMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_ChargeParameterDiscoveryMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_ChargeParameterDiscoveryMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_CurrentDemandMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_CurrentDemandMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_CurrentDemandMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_CurrentDemandMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_CurrentDemandMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_ServicePaymentSelectionMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_ServicePaymentSelectionMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_PowerDeliveryMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_PowerDeliveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_PowerDeliveryMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_PowerDeliveryMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_PowerDeliveryMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_PreChargeMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_PreChargeMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_PreChargeMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_PreChargeMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_PreChargeMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_ServiceDiscoveryMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_ServiceDiscoveryMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_SessionSetupMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_SessionSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_SessionSetupMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_SessionSetupMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_SessionSetupMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_SessionStopMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_SessionStopMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_SessionStopMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_SessionStopMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_SessionStopMessageTimeout */

  #if ( defined Scc_DIN70121_TimerCfg_ConfigType_WeldingDetectionMessageTimeout ) && ( Scc_DIN70121_TimerCfg_ConfigType_WeldingDetectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_DIN70121_TimerCfg_WeldingDetectionMessageTimeout:
      Scc_DIN70121_TimerCfg_Set_WeldingDetectionMessageTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_DIN70121_TimerCfg_ConfigType_WeldingDetectionMessageTimeout */


      /* #80 set value for Timer OppCharge */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutChargeParameterDiscovery ) && ( Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutChargeParameterDiscovery == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SequencePerformanceTimeoutChargeParameterDiscovery:
      Scc_OppCharge_TimerCfg_Set_SequencePerformanceTimeoutChargeParameterDiscovery(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutChargeParameterDiscovery */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutCableCheck ) && ( Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutCableCheck == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SequencePerformanceTimeoutCableCheck:
      Scc_OppCharge_TimerCfg_Set_SequencePerformanceTimeoutCableCheck(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutCableCheck */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPreCharge ) && ( Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPreCharge == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SequencePerformanceTimeoutPreCharge:
      Scc_OppCharge_TimerCfg_Set_SequencePerformanceTimeoutPreCharge(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPreCharge */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPowerDelivery ) && ( Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPowerDelivery == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SequencePerformanceTimeoutPowerDelivery:
      Scc_OppCharge_TimerCfg_Set_SequencePerformanceTimeoutPowerDelivery(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SequencePerformanceTimeoutPowerDelivery */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_ContractAuthenticationMessageTimeout:
      Scc_OppCharge_TimerCfg_Set_ContractAuthenticationMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_ContractAuthenticationMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_CableCheckMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_CableCheckMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_CableCheckMessageTimeout:
      Scc_OppCharge_TimerCfg_Set_CableCheckMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_CableCheckMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_ChargeParameterDiscoveryMessageTimeout:
      Scc_OppCharge_TimerCfg_Set_ChargeParameterDiscoveryMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_CurrentDemandMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_CurrentDemandMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_CurrentDemandMessageTimeout:
      Scc_OppCharge_TimerCfg_Set_CurrentDemandMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_CurrentDemandMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_ServicePaymentSelectionMessageTimeout:
      Scc_OppCharge_TimerCfg_Set_ServicePaymentSelectionMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_ServicePaymentSelectionMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_PowerDeliveryMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_PowerDeliveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_PowerDeliveryMessageTimeout:
      Scc_OppCharge_TimerCfg_Set_PowerDeliveryMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_PowerDeliveryMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_PreChargeMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_PreChargeMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_PreChargeMessageTimeout:
      Scc_OppCharge_TimerCfg_Set_PreChargeMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_PreChargeMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_ServiceDiscoveryMessageTimeout:
      Scc_OppCharge_TimerCfg_Set_ServiceDiscoveryMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SessionSetupMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_SessionSetupMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SessionSetupMessageTimeout:
      Scc_OppCharge_TimerCfg_Set_SessionSetupMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SessionSetupMessageTimeout */

#if ( defined Scc_OppCharge_TimerCfg_ConfigType_SessionStopMessageTimeout ) && ( Scc_OppCharge_TimerCfg_ConfigType_SessionStopMessageTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_OppCharge_TimerCfg_SessionStopMessageTimeout:
      Scc_OppCharge_TimerCfg_Set_SessionStopMessageTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
#endif /* Scc_OppCharge_TimerCfg_ConfigType_SessionStopMessageTimeout */


#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )

    /* #90 set value for OEM Vector - State Machine */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_AcceptUnsecureConnection ) && ( Scc_StateM_ParamCfg_ConfigType_AcceptUnsecureConnection == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_AcceptUnsecureConnection:
      Scc_StateM_ParamCfg_Set_AcceptUnsecureConnection(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_AcceptUnsecureConnection */

#if ( defined Scc_StateM_ParamCfg_ConfigType_AcceptFreeCertificateServicesOnly ) && ( Scc_StateM_ParamCfg_ConfigType_AcceptFreeCertificateServicesOnly == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* Accept Free Certificate Services Only */
    case Scc_DynConfigParam_StateM_ParamCfg_AcceptFreeCertificateServicesOnly:
      Scc_StateM_ParamCfg_Set_AcceptFreeCertificateServicesOnly(Data);
      break;
#endif /* Scc_StateM_ParamCfg_ConfigType_AcceptFreeCertificateServicesOnly */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ReconnectRetries ) && ( Scc_StateM_ParamCfg_ConfigType_ReconnectRetries == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ReconnectRetries:
      Scc_StateM_ParamCfg_Set_ReconnectRetries(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ReconnectRetries */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ReconnectDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ReconnectDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ReconnectDelay:
      Scc_StateM_ParamCfg_Set_ReconnectDelay( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ReconnectDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_RequestInternetDetails ) && ( Scc_StateM_ParamCfg_ConfigType_RequestInternetDetails == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_RequestInternetDetails:
      Scc_StateM_ParamCfg_Set_RequestInternetDetails(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_RequestInternetDetails */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_TLConnectedWaitTime ) && ( Scc_StateM_ParamCfg_ConfigType_TLConnectedWaitTime == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_TLConnectedWaitTime:
      Scc_StateM_ParamCfg_Set_TLConnectedWaitTime(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_TLConnectedWaitTime */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_AuthorizationOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_AuthorizationOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_AuthorizationOngoingTimeout:
      Scc_StateM_ParamCfg_Set_AuthorizationOngoingTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_AuthorizationOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_VehiclePositioningNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_VehiclePositioningNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_VehiclePositioningNextReqDelay:
      Scc_StateM_ParamCfg_Set_VehiclePositioningNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_VehiclePositioningNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_VehiclePositioningOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_VehiclePositioningOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_VehiclePositioningOngoingTimeout:
      Scc_StateM_ParamCfg_Set_VehiclePositioningOngoingTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_VehiclePositioningOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ConnectNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ConnectNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ConnectNextReqDelay:
      Scc_StateM_ParamCfg_Set_ConnectNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ConnectNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ConnectOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_ConnectOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ConnectOngoingTimeout:
      Scc_StateM_ParamCfg_Set_ConnectOngoingTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ConnectOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_DisconnectNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_DisconnectNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_DisconnectNextReqDelay:
      Scc_StateM_ParamCfg_Set_DisconnectNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_DisconnectNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_DisconnectOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_DisconnectOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_DisconnectOngoingTimeout:
      Scc_StateM_ParamCfg_Set_DisconnectOngoingTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_DisconnectOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ChargeParameterDiscoveryOngoingTimeout:
      Scc_StateM_ParamCfg_Set_ChargeParameterDiscoveryOngoingTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ScheduleExchangeOngoingTimeout:
      Scc_StateM_ParamCfg_Set_ScheduleExchangeOngoingTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_CableCheckOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_CableCheckOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */

    case Scc_DynConfigParam_StateM_ParamCfg_CableCheckOngoingTimeout:
      Scc_StateM_ParamCfg_Set_CableCheckOngoingTimeout( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CableCheckOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_CableCheckTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_CableCheckTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* CableCheck Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_CableCheckTimeout:
      Scc_StateM_ParamCfg_Set_CableCheckTimeout((Data / SCC_MAIN_FUNCTION_PERIOD_MS));
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CableCheckTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_PreChargeTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_PreChargeTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* PreCharge Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_PreChargeTimeout:
      Scc_StateM_ParamCfg_Set_PreChargeTimeout((Data / SCC_MAIN_FUNCTION_PERIOD_MS));
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PreChargeTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ISO_20_PreChargeTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_ISO_20_PreChargeTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
      /* PreCharge Cycle Timeout */
    case Scc_DynConfigParam_StateM_ParamCfg_ISO_20_PreChargeTimeout:
      Scc_StateM_ParamCfg_Set_ISO_20_PreChargeTimeout((Data / SCC_MAIN_FUNCTION_PERIOD_MS));
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ISO_20_PreChargeTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_AuthorizationNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_AuthorizationNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_AuthorizationNextReqDelay:
      Scc_StateM_ParamCfg_Set_AuthorizationNextReqDelay( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_AuthorizationNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_CertificateInstallationNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_CertificateInstallationNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_CertificateInstallationNextReqDelay:
      Scc_StateM_ParamCfg_Set_CertificateInstallationNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CertificateInstallationNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_CertificateInstallationOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_CertificateInstallationOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_CertificateInstallationOngoingTimeout:
      Scc_StateM_ParamCfg_Set_CertificateInstallationOngoingTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CertificateInstallationOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_SessionStopNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_SessionStopNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_SessionStopNextReqDelay:
      Scc_StateM_ParamCfg_Set_SessionStopNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_SessionStopNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_FinePositioningSetupNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_FinePositioningSetupNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_FinePositioningSetupNextReqDelay:
      Scc_StateM_ParamCfg_Set_FinePositioningSetupNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_FinePositioningSetupNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_FinePositioningNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_FinePositioningNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_FinePositioningNextReqDelay:
      Scc_StateM_ParamCfg_Set_FinePositioningNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_FinePositioningNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_PairingNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_PairingNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_PairingNextReqDelay:
      Scc_StateM_ParamCfg_Set_PairingNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PairingNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ChargeParameterDiscoveryNextReqDelay:
      Scc_StateM_ParamCfg_Set_ChargeParameterDiscoveryNextReqDelay( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_AlignmentCheckNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_AlignmentCheckNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_AlignmentCheckNextReqDelay:
      Scc_StateM_ParamCfg_Set_AlignmentCheckNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_AlignmentCheckNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ChargingStatusNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ChargingStatusNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ChargingStatusNextReqDelay:
      Scc_StateM_ParamCfg_Set_ChargingStatusNextReqDelay( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ChargingStatusNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_CableCheckNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_CableCheckNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_CableCheckNextReqDelay:
      Scc_StateM_ParamCfg_Set_CableCheckNextReqDelay( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CableCheckNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ChargeLoopNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ChargeLoopNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ChargeLoopNextReqDelay:
      Scc_StateM_ParamCfg_Set_ChargeLoopNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ChargeLoopNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_PreChargeNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_PreChargeNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_PreChargeNextReqDelay:
      Scc_StateM_ParamCfg_Set_PreChargeNextReqDelay( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PreChargeNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ScheduleExchangeNextReqDelay:
      Scc_StateM_ParamCfg_Set_ScheduleExchangeNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_PowerDeliveryNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_PowerDeliveryNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_PowerDeliveryNextReqDelay:
      Scc_StateM_ParamCfg_Set_PowerDeliveryNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PowerDeliveryNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ServiceDetailNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_ServiceDetailNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ServiceDetailNextReqDelay:
      Scc_StateM_ParamCfg_Set_ServiceDetailNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ServiceDetailNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_CurrentDemandNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_CurrentDemandNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_CurrentDemandNextReqDelay:
      Scc_StateM_ParamCfg_Set_CurrentDemandNextReqDelay( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CurrentDemandNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_SECCDiscoveryProtocolNextReqDelay:
      Scc_StateM_ParamCfg_Set_SECCDiscoveryProtocolNextReqDelay(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolDiagStatusOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolDiagStatusOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_SECCDiscoveryProtocolDiagStatusOngoingTimeout:
      Scc_StateM_ParamCfg_Set_SECCDiscoveryProtocolDiagStatusOngoingTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_SECCDiscoveryProtocolDiagStatusOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_FinePositioningOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_FinePositioningOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_FinePositioningOngoingTimeout:
      Scc_StateM_ParamCfg_Set_FinePositioningOngoingTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_FinePositioningOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_PairingOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_PairingOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_PairingOngoingTimeout:
      Scc_StateM_ParamCfg_Set_PairingOngoingTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PairingOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_AlignmentCheckOngoingTimeout ) && ( Scc_StateM_ParamCfg_ConfigType_AlignmentCheckOngoingTimeout == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_AlignmentCheckOngoingTimeout:
      Scc_StateM_ParamCfg_Set_AlignmentCheckOngoingTimeout(Data / SCC_MAIN_FUNCTION_PERIOD_MS);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_AlignmentCheckOngoingTimeout */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ServiceRenegotiation ) && ( Scc_StateM_ParamCfg_ConfigType_ServiceRenegotiation == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ServiceRenegotiation:
      Scc_StateM_ParamCfg_Set_ServiceRenegotiation(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ServiceRenegotiation */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_WeldingDetectionNextReqDelay ) && ( Scc_StateM_ParamCfg_ConfigType_WeldingDetectionNextReqDelay == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_WeldingDetectionNextReqDelay:
      Scc_StateM_ParamCfg_Set_WeldingDetectionNextReqDelay( Data / SCC_MAIN_FUNCTION_PERIOD_MS );
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_WeldingDetectionNextReqDelay */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_PaymentPrioritization ) && ( Scc_StateM_ParamCfg_ConfigType_PaymentPrioritization == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_PaymentPrioritization:
      Scc_StateM_ParamCfg_Set_PaymentPrioritization(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_PaymentPrioritization */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_ContractCertificateChainIndexInUse ) && ( Scc_StateM_ParamCfg_ConfigType_ContractCertificateChainIndexInUse == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_ContractCertificateChainIndexInUse:
      Scc_StateM_ParamCfg_Set_ContractCertificateChainIndexInUse(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_ContractCertificateChainIndexInUse */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_CertificateExpireThreshold ) && ( Scc_StateM_ParamCfg_ConfigType_CertificateExpireThreshold == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_CertificateExpireThreshold:
      Scc_StateM_ParamCfg_Set_CertificateExpireThreshold(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_CertificateExpireThreshold */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_RequestCertificateDetails ) && ( Scc_StateM_ParamCfg_ConfigType_RequestCertificateDetails == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_RequestCertificateDetails:
      Scc_StateM_ParamCfg_Set_RequestCertificateDetails(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_RequestCertificateDetails */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_RequestCertificateInstallation ) && ( Scc_StateM_ParamCfg_ConfigType_RequestCertificateInstallation == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_RequestCertificateInstallation:
      Scc_StateM_ParamCfg_Set_RequestCertificateInstallation(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_RequestCertificateInstallation */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_RequestCertificateUpdate ) && ( Scc_StateM_ParamCfg_ConfigType_RequestCertificateUpdate == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_RequestCertificateUpdate:
      Scc_StateM_ParamCfg_Set_RequestCertificateUpdate(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_RequestCertificateUpdate */

  #if ( defined Scc_StateM_ParamCfg_ConfigType_SLACAmpMapMode ) && ( Scc_StateM_ParamCfg_ConfigType_SLACAmpMapMode == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_SLACAmpMapMode:
      Scc_StateM_ParamCfg_Set_SLACAmpMapMode(Data);
      break;
  #endif /* Scc_StateM_ParamCfg_ConfigType_SLACAmpMapMode */

#if ( defined Scc_StateM_ParamCfg_ConfigType_IsTlsInSdpPossible ) && ( Scc_StateM_ParamCfg_ConfigType_IsTlsInSdpPossible == SCC_CFG_TYPE_DYNAMIC )/* PRQA S 3332 */ /* MD_Scc_3332 */
    case Scc_DynConfigParam_StateM_ParamCfg_IsTlsInSdpPossible:
      Scc_StateM_ParamCfg_Set_IsTlsInSdpPossible(Data);
      break;
#endif /* Scc_StateM_ParamCfg_ConfigType_IsTlsInSdpPossible */

  #endif /* SCC_ENABLE_STATE_MACHINE */

      /* invalid DataID */
    default:
      RetVal = E_NOT_OK;
      break;
    }

    if ( RetVal == E_OK )
    {
      /* inform the NvM to update the NVRAM */
      (void) NvM_SetRamBlockStatus((NvM_BlockIdType)SCC_DIAG_PARAMETERS_NVM_BLOCK, TRUE);
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #100 Report default errors if any occurred. */
  if ( errorId != SCC_DET_NO_ERROR )
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_DIAG_DATA_WRITE_ACCESS, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */

  return RetVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}
#endif /* SCC_NUM_OF_DYN_CONFIG_PARAMS */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_GetContractCertChainIndexInUse
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_GetContractCertChainIndexInUse(
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) IndexOfUsedContractCertChain)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;
  Std_ReturnType retVal = E_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if ( SCC_DEV_ERROR_DETECT == STD_ON )

  /* #10 Check plausibility of input parameters. */
  if (IndexOfUsedContractCertChain == NULL_PTR)
  {
    retVal = E_NOT_OK;
    errorId = SCC_DET_INV_POINTER;
  }
  else
# endif /* SCC_DEV_ERROR_DETECT == STD_ON */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Copy index of currently used contract certificate chain */
    *IndexOfUsedContractCertChain = Scc_ChosenCert.ContrCertChainId;
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #30 Report default errors if any occurred. */
  if (errorId != SCC_DET_NO_ERROR)
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_GET_CERT_CHAIN_IDX, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */

  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_Reset
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
/* PRQA S 6010,6030,6050 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_Reset(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index;

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
  boolean slacResetDesired = FALSE;
#endif /* SCC_ENABLE_SLAC_HANDLING */

  /* ----- Implementation ----------------------------------------------- */
  /* check if an UDP socket is opened */
  if ( (Scc_SocketType)TCPIP_INV_SOCKET_ID != Scc_SDPSocket )
  {
    /* #10 close the UDP socket */
    (void) TcpIp_Close(Scc_SDPSocket, FALSE);
  }

  /* check if a TL connection is established */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  if ( TRUE == Scc_V2GSocketInUse )
  {
    /* Prepare shutdown */
    Scc_State = Scc_State_ShuttingDown;
    SCC_LEAVE_EXCLUSIVE_AREA_2();
    /* report it to the application */
    Scc_Core_InterfaceCfg_Set_TCPSocketState(Scc_TCPSocketState_Disconnecting);
    /* #20 close the TL connection */
    (void) TcpIp_Close(Scc_V2GSocket, TRUE);
  }
  else
  {
    SCC_LEAVE_EXCLUSIVE_AREA_2();
    /* report to the application that the socket is closed */
    Scc_Core_InterfaceCfg_Set_TCPSocketState(Scc_TCPSocketState_Closed);
  }

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
  /* Get from application if Slac module should be reset */
  Scc_SLAC_InterfaceCfg_Get_ExecuteLeave(&slacResetDesired);

  /* Check if the reset should be executed */
  if (slacResetDesired == TRUE)
  {
    /* #30 Try to reset the Slac module */
    if (Slac_Reset() == Slac_RT_Ok)
    {
      /* Reset successful, do nothing further */
    }
    else
    {
      /* Report the failure to the application */
      Scc_ReportError(Scc_StackError_SLAC, SccDetailedError_General_SlacResetFailedDuringSccReset);
    }
  }
#endif /* SCC_ENABLE_SLAC_HANDLING */

  SCC_ENTER_EXCLUSIVE_AREA_2();
  /* #40 reset all state and message relevant parameters */
  Scc_State                     = Scc_State_Initialized;
  Scc_MsgStatus                 = Scc_MsgStatus_None;
  Scc_StackError                = Scc_StackError_NoError;
  Scc_ReceiveMsgState           = Scc_MsgState_WaitingForV2GTpHeader;

  /* Reset the timeouts */
  for (index = 0; index < (uint8_least)SCC_CHANNEL_MAX; index++)
  {
    Scc_TimeoutCnt[index] = 0;
  }

  Scc_Core_Channel_Init();
  Scc_BufferPool_Init();

  /* Reset the totLen and len elements of all PBufs */
  for (index = 0; index < SCC_EXI_RX_STREAM_PBUF_ELEMENTS; index++ )
  {
    Scc_ExiStreamRxPBuf[index].totLen = 0;
    Scc_ExiStreamRxPBuf[index].len = 0;
  }

  /* Reset rx queue */
  Scc_RxUDPShadowBufferUsed = FALSE;
  Scc_Rx_Queue_Init(&Scc_RxStreamBuffer_TCP, &Scc_RxStreamBuffer_TCP_PBuf[0],
    sizeof(Scc_RxStreamBuffer_TCP_PBuf)/sizeof(Scc_RxStreamBuffer_TCP_PBuf[0]), &Scc_Rx_TcpRelease);
  Scc_Rx_Queue_Init(&Scc_RxStreamBuffer_UDP, &Scc_RxStreamBuffer_UDP_PBuf[0],
    sizeof(Scc_RxStreamBuffer_UDP_PBuf) / sizeof(Scc_RxStreamBuffer_UDP_PBuf[0]), &Scc_Rx_UdpRelease);
  SCC_LEAVE_EXCLUSIVE_AREA_2();

  Scc_TxStreamingActive         = FALSE;
  Scc_SDPSocket                 = (Scc_SocketType)TCPIP_INV_SOCKET_ID;

#if (SCC_ENABLE_PNC_CHARGING == STD_ON) || (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
  {
    uint32_least jobIndex;
    /* Cancel all currently active csm jobs */
    SCC_ENTER_EXCLUSIVE_AREA_0();
    for (jobIndex = 0; jobIndex < (sizeof(Scc_CsmJobInfo)/sizeof(Scc_CsmJobInfo[0])); jobIndex++)
    {
      if (   (Scc_CsmJobInfo[jobIndex].State == SCC_CSMJOBSTATE_PENDING)
          || (Scc_CsmJobInfo[jobIndex].Usage == SCC_CSMJOBUSAGE_XML_SIGGEN)
          || (Scc_CsmJobInfo[jobIndex].Usage == SCC_CSMJOBUSAGE_XML_SIGVER))
      {
        Std_ReturnType retValCsm = E_OK;

        Scc_CsmJobInfo[jobIndex].IsCancelled = TRUE;

        SCC_LEAVE_EXCLUSIVE_AREA_0();

        retValCsm = SCC_CSM_CANCELJOB(Scc_CsmJobInfoIndirection[jobIndex], 0);

        if (retValCsm != E_OK )
        {
          (void)Scc_ReportErrorCompSpecific(retValCsm, FALSE, Scc_StackError_Crypto, SccDetailedError_General_ResetCsmJobCancelFailed);
          SCC_ENTER_EXCLUSIVE_AREA_0();
        }
        else
        {
          SCC_ENTER_EXCLUSIVE_AREA_0();
        }
      }
    }

    for (jobIndex = 0; jobIndex  < (sizeof(Scc_CsmJobInfo) / sizeof(Scc_CsmJobInfo[0])); jobIndex++)
    {
      Scc_CsmJobInfo[jobIndex].State = SCC_CSMJOBSTATE_IDLE;
      Scc_CsmJobInfo[jobIndex].Usage = SCC_CSMJOBUSAGE_SCC;
      Scc_CsmJobInfo[jobIndex].IsCancelled = FALSE;
    }
    SCC_LEAVE_EXCLUSIVE_AREA_0();

  }

  Scc_Core_KeyMUtils_Init();

# if (SCC_ENABLE_PNC_CHARGING == STD_ON)
  Scc_OEMProvUpdateState = SCC_CORE_KEYMUTILS_IDLE;
# endif /* SCC_ENABLE_PNC_CHARGING */

#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */
  Scc_SAP_ExiRx_Init();
  Scc_SAP_ExiTx_Init();
  Scc_SDP_Tx_Init();
  Scc_SDP_Rx_Init();
  Scc_Exi_Init();

#if (defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
  Scc_InitISO20VehicleChainContext();
#endif /* SCC_ENABLE_TLS_ISO20_CLIENTAUTH */
}

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_TriggerSLAC
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
 */
/* PRQA S 6050,6080,6030 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF,MD_MSR_STCYC */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_TriggerSLAC(
  Scc_MsgTrigType MsgTrig)
{
  /* ----- Local Variables ---------------------------------------------- */
  Slac_AmpMapModeType SLACAmpMapMode;
  boolean stop = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* Check if this is the initial trigger */
  if ( TRUE == Scc_Core_Channel_Get_CyclicMsgTrig())
  {
    SCC_ENTER_EXCLUSIVE_AREA_2();
    /* Accept the new trigger */
    Scc_Core_Channel_Set_MsgTrig(MsgTrig);
    /* Reset the StackError */
    Scc_StackError = Scc_StackError_NoError;
    SCC_LEAVE_EXCLUSIVE_AREA_2();
    /* Reset the cyclic message trigger at the application */
    Scc_Core_InterfaceCfg_Set_CyclicMsgTrigTx(FALSE);
  }

  if ( Scc_MsgState_WaitForNextRequest == Scc_Core_Channel_Get_MsgState(Scc_Core_Channel_Get_CurrentChannel()) )
  {
    /* #10 Check if the link is already established. */
    if (Slac_DLS_Link == Scc_DLinkReady)
    {
      /* Check if it was not already reported to the application that SLAC is done */
      if ( Scc_MsgStatus_SLAC_OK != Scc_MsgStatus )
      {
        /* Report the success to the application */
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SLAC_OK);
      }

      stop = TRUE;
    }

    if (stop == FALSE)
    {
      /* #20 Check if the firmware download is not finished. */
      /* PRQA S 3415 4 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
      if ( (Scc_PlcChipFirmwareStatus != Scc_PlcChipFirmwareStatus_ReadyForSlac)
        && (Scc_PlcChipFirmwareStatus != Scc_PlcChipFirmwareStatus_ErrorOccurred) )
      {
        /* Wait for Scc_PlcChipFirmwareStatus_ReadyForSlac */
      }
      /* #30 Check if an error occurred during the download of the firmware to the QCA. */
      else if (Scc_PlcChipFirmwareStatus_ErrorOccurred == Scc_PlcChipFirmwareStatus)
      {
        /* Check if it was not already reported to the application that SLAC has failed */
        if (Scc_MsgStatus_SLAC_Failed != Scc_MsgStatus)
        {
          /* Report the failure to the application */
          Scc_ReportError(Scc_StackError_SLAC, SccDetailedError_General_SlacFirmwareDownloadFailed);
        }
      }
      /* #40 Firmware download was successful. */
      else /* if ( Scc_PlcChipFirmwareStatus_ReadyForSlac == Scc_PlcChipFirmwareStatus ) */
      {
        boolean resumeSLAC = FALSE;
        /* #50 Reset SLAC. */
        if (Slac_Reset() == Slac_RT_Ok)
        {
          /* Get from application if SLAC session should be resumed */
          Scc_SLAC_InterfaceCfg_Get_IsResume(&resumeSLAC);
          /* Get the start or resume type */
          Scc_SLAC_InterfaceCfg_Get_AmpMapMode(&SLACAmpMapMode);

          /* #60 Check if SLAC session should be resumed. */
          if (resumeSLAC == TRUE)
          {
            /* #70 Resume SLAC handling and get parameters from application. */
            uint8 NMKBuf[SLAC_MME_NMK_LEN];
            uint8 NIDBuf[SLAC_MME_NID_LEN];
            uint8 EvseMacBuf[ETH_PHYS_ADDR_LEN_BYTE];

            Scc_BufferPointerType NMK;
            Scc_BufferPointerType NID;
            Scc_BufferPointerType EvseMac;

            NMK.BufferPtr = &NMKBuf[0];
            NMK.BufferLen = SLAC_MME_NMK_LEN;
            NID.BufferPtr = &NIDBuf[0];
            NID.BufferLen = SLAC_MME_NID_LEN;
            EvseMac.BufferPtr = &EvseMacBuf[0];
            EvseMac.BufferLen = ETH_PHYS_ADDR_LEN_BYTE;

            /* Get the parameters for resuming */
            Scc_SLAC_InterfaceCfg_Get_ResumeNMK(&NMK);
            Scc_SLAC_InterfaceCfg_Get_ResumeNID(&NID);
            Scc_SLAC_InterfaceCfg_Get_ResumeEvseMac(&EvseMac);

            /* #80 Resume SLAC session */
            if (Slac_RT_Ok == Slac_SessionResume(SLACAmpMapMode, NID.BufferPtr, NMK.BufferPtr, EvseMac.BufferPtr))
            {
              /* #90 If successful: go to the next state */
              Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader);
            }
            else
            {
              /* #100 Otherwise: report error to the application */
              /* Check if it was not already reported to the application that SLAC has failed */
              if (Scc_MsgStatus_SLAC_Failed != Scc_MsgStatus)
              {
                /* Report the failure to the application */
                Scc_ReportError(Scc_StackError_SLAC, SccDetailedError_General_SlacSessionResumeFailed);
              }
            }
          }
          else
          {
            /* #110 Otherwise: start SLAC handling. */
            if (Slac_RT_Ok == Slac_Start(SLACAmpMapMode))
            {
              /* #120 If successful: go to the next state */
              Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader)
            }
            else
            {
              /* #130 Otherwise: report error to the application */
              /* Check if it was not already reported to the application that SLAC has failed */
              if (Scc_MsgStatus_SLAC_Failed != Scc_MsgStatus)
              {
                /* Report the failure to the application */
                Scc_ReportError(Scc_StackError_SLAC, SccDetailedError_General_SlacStartFailed);
              }
            }
          }
        }
        else
        {
          /* #140 If Slac_reset failed: report error to the application */
          /* Check if it was not already reported to the application that SLAC has failed */
          if (Scc_MsgStatus_SLAC_Failed != Scc_MsgStatus)
          {
            /* Report the failure to the application */
            Scc_ReportError(Scc_StackError_SLAC, SccDetailedError_General_SlacResetFailed);
          }
        }
      }
    }
  }
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/**********************************************************************************************************************
 *  Scc_LeavePLCNetwork
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
 /* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_LeavePLCNetwork(
  Scc_MsgTrigType MsgTrig,
  Scc_MsgStatusType MsgState_IfSuccessful)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean LeavePLCDesired = FALSE;
  Slac_BooleanType FirstCall = Slac_BT_False;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this is the initial trigger */
  if (TRUE == Scc_Core_Channel_Get_CyclicMsgTrig())
  {
    /* Save that this was the first call */
    FirstCall = Slac_BT_True;

    SCC_ENTER_EXCLUSIVE_AREA_2();
    /* Accept the new trigger */
    Scc_Core_Channel_Set_MsgTrig(MsgTrig);
    /* Reset the StackError */
    Scc_StackError = Scc_StackError_NoError;
    SCC_LEAVE_EXCLUSIVE_AREA_2();
    /* Reset the cyclic message trigger at the application */
    Scc_Core_InterfaceCfg_Set_CyclicMsgTrigTx(FALSE);
  }

  if (Scc_MsgState_WaitForNextRequest == Scc_Core_Channel_Get_MsgState(Scc_Core_Channel_Get_CurrentChannel()))
  {
    /* #20 Check if it was not already reported to the application that SLAC is done */
    if (MsgState_IfSuccessful != Scc_MsgStatus)
    {

      /* #30 Get from application if exit PLC network should be executed */
      Scc_SLAC_InterfaceCfg_Get_ExecuteLeave(&LeavePLCDesired);

      /* #40 Check if the leaving should be executed */
      if (LeavePLCDesired == TRUE)
      {
#if (defined (SCC_ENABLE_SLAC_CHANGEABLE_NMK_FOR_LEAVE) && (SCC_ENABLE_SLAC_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
        /* #50 Get the NKM and NID from the application. */

        /* Create buffers to store them. */
        uint8 NMKBuf[SLAC_MME_NMK_LEN];
        uint8 NIDBuf[SLAC_MME_NID_LEN];

        Scc_BufferPointerType NMK;
        Scc_BufferPointerType NID;

        NMK.BufferPtr = &NMKBuf[0];
        NMK.BufferLen = SLAC_MME_NMK_LEN;
        NID.BufferPtr = &NIDBuf[0];
        NID.BufferLen = SLAC_MME_NID_LEN;

        /* Get them from the application. */
        Scc_SLAC_InterfaceCfg_Get_ResetAndLeaveNMK(&NMK);
        Scc_SLAC_InterfaceCfg_Get_ResetAndLeaveNID(&NID);
#endif /* SCC_ENABLE_SLAC_CHANGEABLE_NMK_FOR_LEAVE */

        /* #60 Perform the leaving of the PLC network */
        Slac_ReturnType ResultFromSlac = Slac_ResetAndLeave(
          FirstCall
#if (defined (SCC_ENABLE_SLAC_CHANGEABLE_NMK_FOR_LEAVE) && (SCC_ENABLE_SLAC_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
          , NID.BufferPtr
          , NMK.BufferPtr
#endif /* SCC_ENABLE_SLAC_CHANGEABLE_NMK_FOR_LEAVE */
          );

        /* #70 Check if leaving was successful */
        if (ResultFromSlac == Slac_RT_Ok)
        {
          /* #80 If successful, go to the next state */
          Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest);

          /* Report the success to the application */
          Scc_ReportSuccessAndStatus(MsgState_IfSuccessful);
        }
        else if (ResultFromSlac == Slac_RT_NotOk)
        {
          /* #90 Slac was not successful. Report to application */

          /* Check if it was not already reported to the application that SLAC has failed */
          if (Scc_MsgStatus_LeavePLCNetwork_Failed != Scc_MsgStatus)
          {
            /* Report the failure to the application */
            Scc_ReportError(Scc_StackError_SLAC, SccDetailedError_General_SlacLeavePLCNetworkFailed);
          }
        }
        else
        {
          /* #100 Slac is pending. Check ResetAndLeave at a later point */
        }
      }
      else
      {
        /* #110 Otherwise: go immediately to the next state */
        Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest);

        /* Report the success to the application */
        Scc_ReportSuccessAndStatus(MsgState_IfSuccessful);
      }
    }
  }
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON ) || (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_TriggerCerts
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
 *
 *
 *
 *
 */
/* PRQA S 6010,6030,6050,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_TriggerCerts(
  Scc_MsgTrigType MsgTrig)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this is the initial trigger */
  /* PRQA S 3415 2 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
  if (   (Scc_Core_Channel_Get_MsgTrig() != MsgTrig)
      || (TRUE == Scc_Core_Channel_Get_CyclicMsgTrig()))
  {
    /* #20 Accept the new trigger */
    Scc_Core_Channel_Set_MsgTrig(MsgTrig);
    /* #30 Reset the StackError */
    Scc_StackError = Scc_StackError_NoError;

    /* #40 Based on the message trigger */
    switch (Scc_Core_Channel_Get_MsgTrig())
    {
      /* #50 Scc_MsgTrig_ReadContrCertChain */
      case Scc_MsgTrig_ReadContrCertChain:
      {
        P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr = NULL_PTR;

        switch (Scc_SAP_ExiRx_GetChosenSchema())
        {
  #if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
        case Scc_SAPSchemaIDs_ISO15118_2:
          {
            chosenContrPtr = &Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId].ContrCertCfg;
            break;
          }
  #endif /* SCC_SCHEMA_ISO */

  #if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
  #if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
        case Scc_SAPSchemaIDs_ISO15118_20AC:
  #endif /* SCC_SCHEMA_ISO_20AC */
  #if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
        case Scc_SAPSchemaIDs_ISO15118_20DC:
  #endif /* SCC_SCHEMA_ISO_20DC */
  #if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
        case Scc_SAPSchemaIDs_ISO15118_20WPT:
  #endif /* SCC_SCHEMA_ISO_20WPT */
  #if ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 )
        case Scc_SAPSchemaIDs_ISO15118_20ACDP:
  #endif /* SCC_SCHEMA_ISO_20ACDP */
          {
            chosenContrPtr = &Scc_ISO20CertConfig.EMSPCertsPtr[Scc_ChosenCert.ContrCertChainId];
            break;
          }
  #endif /* SCC_SCHEMA_ISO_20 */

        default:
          /* Do nothing. retVal already set to NotOk */
          break;
        }

        if (chosenContrPtr != NULL_PTR)
        {
          /* #60 Wait till contract certificate chain is updated by KeyM */
          retVal = Scc_Core_KeyMUtils_UpdateContract(chosenContrPtr);
        }

        /* #70 Check if everything is ready */
        if (retVal == Scc_ReturnType_OK)
        {
          /* #80 Report success to application */
          Scc_ReportSuccessAndStatus(Scc_MsgStatus_ReadContrCertChain_OK);
        }
        /* #90 Check if operation is pending */
        else if (retVal == Scc_ReturnType_Pending)
        {
          /* #100 Operation is pending */
        }
        /* #110 Otherwise */
        else
        {
          /* #120 Nothing to do. Error is reported in Scc_Core_KeyMUtils_UpdateContract */
        }
        break;
      }

#if ( (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) \
   || (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON) \
   || (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON) )
      /* #130 Scc_MsgTrig_ReadRootCerts */
      case Scc_MsgTrig_ReadRootCerts:
      {
        Std_ReturnType keyMRetVal = E_OK;
        P2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) chosenRootCertPtr = NULL_PTR;
        Scc_CertArraySizeType chosenRootCertCnt = 0u;

        switch (Scc_SAP_ExiRx_GetChosenSchema())
        {
  #if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
          case Scc_SAPSchemaIDs_ISO15118_2:
            chosenRootCertPtr = Scc_ISO2CertConfig.RootCertsPtr;
            chosenRootCertCnt = Scc_ISO2CertConfig.RootCertCnt;
            break;
  #endif /* SCC_SCHEMA_ISO */

  #if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
  #if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
          case Scc_SAPSchemaIDs_ISO15118_20AC:
  #endif /* SCC_SCHEMA_ISO_20AC */
  #if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
          case Scc_SAPSchemaIDs_ISO15118_20DC:
  #endif /* SCC_SCHEMA_ISO_20DC */
  #if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
          case Scc_SAPSchemaIDs_ISO15118_20WPT:
  #endif /* SCC_SCHEMA_ISO_20WPT */
  #if ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 )
          case Scc_SAPSchemaIDs_ISO15118_20ACDP:
  #endif /* SCC_SCHEMA_ISO_20ACDP */
            chosenRootCertPtr = Scc_ISO20CertConfig.RootCertsPtr;
            chosenRootCertCnt = Scc_ISO20CertConfig.RootCertCnt;
            break;
  #endif /* SCC_SCHEMA_ISO_20 */

          default:
             /* This should not happen */
            break;
        }

        if (chosenRootCertPtr != NULL_PTR)
        {
          /* #140 Wait till RootCertificates is updated by KeyM. */
          retVal = Scc_Core_KeyMUtils_UpdateV2GRoots(chosenRootCertPtr, chosenRootCertCnt, &keyMRetVal);

          /* #150 Check if everything is ready */
          if (retVal == Scc_ReturnType_OK)
          {
            /* #160 Check if at least one root certificate is available */
            if (Scc_Core_KeyMUtils_CountValidV2GRoots(chosenRootCertPtr, chosenRootCertCnt) != 0u)
            {
              /* #170 Report success to application */
              Scc_ReportSuccessAndStatus(Scc_MsgStatus_ReadRootCerts_OK);
            }
            /* #180 Otherwise */
            else
            {
              /* #190 Indicate error */
              retVal = Scc_ReturnType_NotOK;
            }
          }
        }
        else
        {
          retVal = Scc_ReturnType_NotOK;
        }

        /* #200 Check if operation is pending */
        if (retVal == Scc_ReturnType_Pending)
        {
          /* #210 Operation is pending */
        }
        /* #220 Check if operation failed */
        else if (retVal == Scc_ReturnType_NotOK)
        {
          /* #230 Report keyM error to application */
          (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_General_TriggerReadRootCertsFailed);
        }
        else
        {
          /* Nothing to do */
        }
        break;
      }
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) || (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON)
      /* #240 Scc_MsgTrig_ReadOemProvCert */
      case Scc_MsgTrig_ReadOemProvCert:
      {
        Std_ReturnType keyMRetVal = E_OK;
        /* #250 Choose based on Schema */
        switch (Scc_SAP_ExiRx_GetChosenSchema())
        {
  #if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
        case Scc_SAPSchemaIDs_ISO15118_2:
        {
        CONSTP2CONST(Scc_ISO2ContrCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr =
                                            &Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId];

          /* #260 Wait till ProvisioningCertificate is updated by KeyM. */
          retVal = Scc_Core_KeyMUtils_VerifyOemProv(
            chosenContrPtr->OEMProvCertPtr->KeyMGroupId,
            &Scc_OEMProvUpdateState,
            &keyMRetVal);
          break;
        }
  #endif /* SCC_SCHEMA_ISO */

  #if (   ((defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )) \
       && (( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )))
  #if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
        case Scc_SAPSchemaIDs_ISO15118_20AC:
  #endif /* SCC_SCHEMA_ISO_20AC */
  #if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
        case Scc_SAPSchemaIDs_ISO15118_20DC:
  #endif /* SCC_SCHEMA_ISO_20DC */
  #if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
        case Scc_SAPSchemaIDs_ISO15118_20WPT:
  #endif /* SCC_SCHEMA_ISO_20WPT */
  #if ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 )
        case Scc_SAPSchemaIDs_ISO15118_20ACDP:
  #endif /* SCC_SCHEMA_ISO_20ACDP */
        {
          CONSTP2CONST(Scc_ISO20OEMCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr =
                                             &Scc_ISO20CertConfig.OEMProvCertsPtr[Scc_ChosenCert.OemCertId];

          /* #270 Wait till ProvisioningCertificate is updated by KeyM. */
          retVal = Scc_Core_KeyMUtils_UpdateISO20OEMProvCert(chosenContrPtr, &keyMRetVal);
          break;
        }
  #endif /* SCC_SCHEMA_ISO_20 && SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

        default:
          /* Do nothing. retVal already set to NotOk */
          break;
        }

        /* #280 Check if everything is ready */
        if (Scc_ReturnType_OK == retVal)
        {
          /* #290 Report success to application */
          Scc_ReportSuccessAndStatus(Scc_MsgStatus_ReadOemProvCert_OK);
        }
        /* #300 Check if operation is pending */
        else if (retVal == Scc_ReturnType_Pending)
        {
          /* #310 Operation is pending */
        }
        /* #320 Otherwise */
        else
        {
          /* #330 Report keyM error to application */
          (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_General_TriggerReadOEMProvCertFailed);
        }
        break;
      }
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

      /* #340 Otherwise */
      default:
        /* #350 If SCC_DEV_ERROR_REPORT: Report DET error due to invalid message trigger */
    #if(SCC_DEV_ERROR_REPORT == STD_ON)
        (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_TRIG_CERTS, SCC_DET_INV_PARAM);
    #endif /* SCC_DEV_ERROR_REPORT */
        break;
    }

    if (retVal != Scc_ReturnType_Pending)
    {
      /* #360 Reset the cyclic message trigger at the application */
      Scc_Core_InterfaceCfg_Set_CyclicMsgTrigTx(FALSE);
    }
  }
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_TriggerV2G
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
 */
/* PRQA S 6030,6050,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_TriggerV2G(
  Scc_MsgTrigType MsgTrig)
{
  /* ----- Implementation ----------------------------------------------- */
  /* check if it is allowed to send a request */
  /* PRQA S 3415 2 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
  if (   (Scc_Core_Channel_Get_MsgTrig() != MsgTrig)
      || ( TRUE == Scc_Core_Channel_Get_CyclicMsgTrig()))
  {
    SCC_ENTER_EXCLUSIVE_AREA_2();
    /* #10 check if there is still an open connection */
    /* PRQA S 3415 2 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
    if (   ( Scc_MsgTrig_TransportLayer == MsgTrig)
        && ( TRUE == Scc_V2GSocketInUse ))
    {
      /* Prepare shutdown */
      Scc_State = Scc_State_ShuttingDown;
      SCC_LEAVE_EXCLUSIVE_AREA_2();
      /* report it to the application */
      Scc_Core_InterfaceCfg_Set_TCPSocketState(Scc_TCPSocketState_Disconnecting);
      /* close the connection before opening a new one */
      (void) TcpIp_Close(Scc_V2GSocket, TRUE);
    }
    else
    {
      /* accept the new trigger */
      Scc_Core_Channel_Set_MsgTrig(MsgTrig);
      /* reset the StackError */
      Scc_StackError = Scc_StackError_NoError;
      SCC_LEAVE_EXCLUSIVE_AREA_2();

      /* reset the cyclic message trigger at the application */
      Scc_Core_InterfaceCfg_Set_CyclicMsgTrigTx(FALSE);

      SCC_ENTER_EXCLUSIVE_AREA_2();

      /* #20 check if a secc discovery protocol request shall be sent */
      if ( Scc_MsgTrig_SECCDiscoveryProtocol == MsgTrig)
      {
        uint8 ChangeParameterParam = 1;
        uint16 Port = TCPIP_PORT_ANY;

        SCC_LEAVE_EXCLUSIVE_AREA_2();

        /* check if the UDP socket is not already bound to SCC */
        if ( (Scc_SocketType)TCPIP_INV_SOCKET_ID == Scc_SDPSocket )
        {
          /* get the socket */
          if ( (Std_ReturnType)E_OK !=
            TcpIp_SccGetSocket(TCPIP_AF_INET6, TCPIP_IPPROTO_UDP, &Scc_SDPSocket) )
          {
            Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerSdpGetSocketFailed);
          }
          /* set the tx confirmation list */
          else if ( (Std_ReturnType)E_OK !=
            TcpIp_ChangeParameter(Scc_SDPSocket, TCPIP_PARAMID_V_UDP_TXREQLISTSIZE, &ChangeParameterParam) )
          {
            Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerSdpChangeParameterFailed);
          }
          /* bind the socket */
          else if ( (Std_ReturnType)E_OK != TcpIp_Bind(Scc_SDPSocket, Scc_LocalAddrId, &Port) )
          {
            Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerSdpBindFailed);
          }
          /* try to send a SDP request and check if it was successful */
          else if ( (Std_ReturnType)E_OK == Scc_SDP_Tx_SECCDiscoveryProtocolReq(&Scc_RxConfig) )                        /* PRQA S 2004 */ /* MD_Scc_2004 */
          {
            Scc_MsgStateFct(Scc_MsgState_WaitingForV2GTpHeader)
            /* start the timer */
            Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolTimeout();
          }
        }
      }

      /* #30 check if the transport layer connection shall be established */
      else if (   ( Scc_State_SDPComplete == Scc_State )
               && ( Scc_MsgTrig_TransportLayer == MsgTrig))
      {
        SCC_LEAVE_EXCLUSIVE_AREA_2();
        Scc_EstablishTLConnection();
      }

      /* #40 check if a SupportedAppProtocolReq shall be sent */
      else if (   ( Scc_State_TLConnected == Scc_State )
               && ( Scc_MsgTrig_SupportedAppProtocol == MsgTrig))
      {
        SCC_LEAVE_EXCLUSIVE_AREA_2();

        /* #50 Since a new message trigger was received, go to state PrepareMessageData */
        Scc_MsgStateFct_EA2(Scc_MsgState_PrepareMessageData)
      }

      /* #60 check if a charging session is started */
      /* PRQA S 3415 6  */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
      else if (   (   ( Scc_State_SAPComplete == Scc_State )
                   && ( Scc_MsgTrig_SessionSetup == MsgTrig))
               || (   ( Scc_State_Connected == Scc_State )
                   && (   ( Scc_MsgTrig_ServiceDiscovery <= MsgTrig)
                       && ( Scc_MsgTrig_SessionStop >= MsgTrig)))
               || ( Scc_MsgTrig_SessionStop == MsgTrig) )
      {
        SCC_LEAVE_EXCLUSIVE_AREA_2();

        /* #70 Since a new message trigger was received, go to state PrepareMessageData */
        Scc_MsgStateFct_EA2(Scc_MsgState_PrepareMessageData)
      }

      /* #80 check if the tcp connection should be closed */
      else if (   ( Scc_State_Disconnected == Scc_State )
               && ( Scc_MsgTrig_StopCommunicationSession == MsgTrig))
      {
        SCC_LEAVE_EXCLUSIVE_AREA_2();

        if ( (Std_ReturnType)E_OK == TcpIp_Close(Scc_V2GSocket, FALSE) )
        {
          SCC_ENTER_EXCLUSIVE_AREA_2();
          Scc_State = Scc_State_ShuttingDown;
          SCC_LEAVE_EXCLUSIVE_AREA_2();

          /* start the timeout (if value is 0, timeout will not be started) */
          Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_TimerGeneral_TimerCfg_Get_TransportLayerTimeout();

          Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader)
          /* inform the application */
          Scc_Core_InterfaceCfg_Set_TCPSocketState(Scc_TCPSocketState_Disconnecting);
        }
        else
        {
          /* write the error */
          Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerV2gCloseFailed);
        }
      }
      /* if the trigger was not valid */
      else
      {
        SCC_LEAVE_EXCLUSIVE_AREA_2();
        /* report a V2G error of the current trigger */
        Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_General_TriggerV2gMsgTriggerInvalid);
      }
    }
  }
}

/**********************************************************************************************************************
 *  Scc_TimeoutHandling_SECCDiscoveryProtocol
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_TimeoutHandling_SECCDiscoveryProtocol(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if RetransRetriesCnt is expired */
  if (Scc_SDP_Tx_IsRetransRetriesCntExpired() == FALSE)
  {
    uint8 bufferPoolId = Scc_Core_Channel_Get_BufferPoolId();
    /* Release the default channel buffer since SDP is always on main channel */
    if (bufferPoolId != SCC_INVALID_BUFFER_POOL_ID)
    {
      Scc_BufferPoolRelease(bufferPoolId);
      Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
    }
    /* #20 Decrement the SDP retries */
    Scc_SDP_Tx_DecrementRetransRetriesCnt();
    SCC_LEAVE_EXCLUSIVE_AREA_2();

    /* #30 Try to send another SDP request and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_SDP_Tx_SECCDiscoveryProtocolReq(&Scc_RxConfig))
    {
      Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader)
      /* set the timer */
      Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolTimeout();
    }
    else
    {
      /* if the packet was not transmitted (completely) */
      retVal = E_NOT_OK;
    }
  }
  /* #40 Otherwise */
  else
  {
    SCC_LEAVE_EXCLUSIVE_AREA_2();
    /* no retries left */
    /* #50 Report the timeout to the application */
    Scc_ReportError(Scc_StackError_Timeout, SccDetailedError_General_TimeoutSdp);
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_TimeoutHandling
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_TimeoutHandling(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  /* #10 check if the timer is active */
  if (0u < Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT])
  {
    /* decrement the timer */
    Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT]--;                                                                              /* PRQA S 3387 */ /* MD_SCC_VOLATILE_INCR_DECR */

    /* #20 check if a timeout occurred */
    if (0u == Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT])
    {
      /* #30 check if the timeout happened during the SDP */
      if (Scc_MsgTrig_SECCDiscoveryProtocol == Scc_Core_Channel_Get_MsgTrig())
      {
        retVal = Scc_TimeoutHandling_SECCDiscoveryProtocol();
      }
      /* #40 check if timeout happened while trying to close the TCP connection */
      else if (Scc_MsgTrig_StopCommunicationSession == Scc_Core_Channel_Get_MsgTrig())
      {
        /* Prepare shutdown */
        Scc_State = Scc_State_ShuttingDown;
        /* close the connection */
        SCC_LEAVE_EXCLUSIVE_AREA_2();

        (void)TcpIp_Close(Scc_V2GSocket, TRUE);
        retVal = E_NOT_OK;
      }
      else
      {
#if ( ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0 ) \
   || ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ) )
        Scc_SAPSchemaIDType sapSchemaID = Scc_SAP_ExiRx_GetChosenSchema();
#endif
        SCC_LEAVE_EXCLUSIVE_AREA_2();

#if ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0 )
        /* #50 Check if OppCharge charging mode is active */
        if (sapSchemaID == Scc_SAPSchemaIDs_OppCharge)
        {
          uint8 bufferPoolId = Scc_Core_Channel_Get_BufferPoolId();
          /* Since in OppCharge only 1 channel is present, release the default channel buffer */
          if (bufferPoolId != SCC_INVALID_BUFFER_POOL_ID)
          {
            Scc_BufferPoolRelease(bufferPoolId);
            Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
          }
          /* [V2G2-OC-488_1], [V2G2-OC-492_1], [V2G2-OC-504_1], [V2G2-OC-506_1],
           * [V2G2-OC-507_1], [V2G2-OC-524_1], [V2G2-OC-526_1], [V2G2-OC-529_1],
           * [V2G2-OC-532_1] */
          /* In case of a timeout, we need to reset the MsgState to allow SessionStop processing */
          Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest)
          retVal = E_OK;
        }
        else
#endif /* SCC_SCHEMA_OPP_CHARGE */
#if ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 )
        /* #60 [V2G20-4026] Check if ACDP is active and EV is already connected */
        if (   (Scc_Core_Channel_Get_MsgTrig() >= Scc_MsgTrig_ACDP_Connect)
            && (sapSchemaID == Scc_SAPSchemaIDs_ISO15118_20ACDP) )
        {
          uint8 bufferPoolId = Scc_Core_Channel_Get_BufferPoolId();
          /* Since this timeout handling function is on main channel, release the main channel buffer */
          if (bufferPoolId != SCC_INVALID_BUFFER_POOL_ID)
          {
            Scc_BufferPoolRelease(bufferPoolId);
            Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
          }
          /* [V2G20-4026] */
          /* In case of a timeout, we need to reset the MsgState to allow Disconnect & SessionStop processing */
          Scc_MsgStateFct_EA2(Scc_MsgState_WaitForNextRequest)
          retVal = E_OK;
        }
        else
#endif /* SCC_SCHEMA_ISO_20ACDP */
        {
          retVal = E_NOT_OK;
        }

        /* report the timeout to the application */
        Scc_ReportError(Scc_StackError_Timeout, SccDetailedError_GeneralTimeout);
      }
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();
    }
  }
  else
  {
    SCC_LEAVE_EXCLUSIVE_AREA_2();
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OnHoldTimeoutHandling
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
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_OnHoldTimeoutHandling(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean timeoutOccured = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Monitor onHold timeout */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  if (Scc_TimeoutCntOnHold > 0u)
  {
    /* #20 Decrement the timer */
    Scc_TimeoutCntOnHold--;                                                                                             /* PRQA S 3387 */ /* MD_SCC_VOLATILE_INCR_DECR */

    /* #30 Check if a timeout occurred */
    if (0u == Scc_TimeoutCntOnHold)
    {
      timeoutOccured = TRUE;
    }
  }
  SCC_LEAVE_EXCLUSIVE_AREA_2();

  /* #40 If a timeout occurred */
  if (timeoutOccured == TRUE)
  {
    /* #50 Report the OnHoldTimeout to the application */
    Scc_Core_InterfaceCfg_Set_OnHoldTimeout();
  }
}

#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
/**********************************************************************************************************************
 *  Scc_TimeoutHandlingReneg
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_TimeoutHandlingReneg(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  /* [V2G20-1041] */
  /* #10 check if the timer is active */
  if (0u < Scc_TimeoutCnt[SCC_CHANNEL_RENEGOTIATION])
  {
    /* decrement the timer */
    Scc_TimeoutCnt[SCC_CHANNEL_RENEGOTIATION]--;                                                                        /* PRQA S 3387 */ /* MD_SCC_VOLATILE_INCR_DECR */

    /* #20 check if a timeout occurred */
    if (0u == Scc_TimeoutCnt[SCC_CHANNEL_RENEGOTIATION])
    {
      uint8 bufferPoolId = Scc_Core_Channel_Get_BufferPoolId();
      SCC_LEAVE_EXCLUSIVE_AREA_2();

      if (bufferPoolId != SCC_INVALID_BUFFER_POOL_ID)
      {
        Scc_BufferPoolRelease(bufferPoolId);
        Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
      }

      retVal = E_NOT_OK;
      /* report the timeout to the application */
      Scc_ReportError(Scc_StackError_Timeout, SccDetailedError_GeneralTimeout);
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();
    }
  }
  else
  {
    SCC_LEAVE_EXCLUSIVE_AREA_2();
  }

  return retVal;
}
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */

#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_TimeoutHandlingMetering
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_TimeoutHandlingMetering(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  /* [V2G20-1041], [V2G20-434] */
  /* #10 check if the timer is active */
  if (0u < Scc_TimeoutCnt[SCC_CHANNEL_METERING])
  {
    /* decrement the timer */
    Scc_TimeoutCnt[SCC_CHANNEL_METERING]--;                                                                             /* PRQA S 3387 */ /* MD_SCC_VOLATILE_INCR_DECR */

    /* #20 check if a timeout occurred */
    if (0u == Scc_TimeoutCnt[SCC_CHANNEL_METERING])
    {
      uint8 bufferPoolId = Scc_Core_Channel_Get_BufferPoolId();

      SCC_LEAVE_EXCLUSIVE_AREA_2();
      if (bufferPoolId != SCC_INVALID_BUFFER_POOL_ID)
      {
        Scc_BufferPoolRelease(bufferPoolId);
        Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
      }

      retVal = E_NOT_OK;
      /* report the timeout to the application */
      Scc_ReportError(Scc_StackError_Timeout, SccDetailedError_GeneralTimeout);
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();
    }
  }
  else
  {
    SCC_LEAVE_EXCLUSIVE_AREA_2();
  }

  return retVal;
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
/**********************************************************************************************************************
 *  Scc_TimeoutHandlingSystemStatus
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_TimeoutHandlingSystemStatus(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  /* [V2G20-1041], [V2G20-4020] */
  /* #10 check if the timer is active */
  if (0u < Scc_TimeoutCnt[SCC_CHANNEL_SYSTEM_STATUS])
  {
    /* decrement the timer */
    Scc_TimeoutCnt[SCC_CHANNEL_SYSTEM_STATUS]--;                                                                        /* PRQA S 3387 */ /* MD_SCC_VOLATILE_INCR_DECR */

    /* #20 check if a timeout occurred */
    if (0u == Scc_TimeoutCnt[SCC_CHANNEL_SYSTEM_STATUS])
    {
      uint8 bufferPoolId = Scc_Core_Channel_Get_BufferPoolId();

      SCC_LEAVE_EXCLUSIVE_AREA_2();
      if (bufferPoolId != SCC_INVALID_BUFFER_POOL_ID)
      {
        Scc_BufferPoolRelease(bufferPoolId);
        Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
      }

      retVal = E_NOT_OK;
      /* report the timeout to the application */
      Scc_ReportError(Scc_StackError_Timeout, SccDetailedError_GeneralTimeout);
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();
    }
  }
  else
  {
    SCC_LEAVE_EXCLUSIVE_AREA_2();
  }

  return retVal;
}
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */

/**********************************************************************************************************************
 *  Scc_EstablishTLConnection
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
/* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_EstablishTLConnection(void)
{
  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SocketIdType tempV2GSocket;

  /* #10 get the socket from the TcpIp */
  if ( (Std_ReturnType)E_OK != TcpIp_SccGetSocket(TCPIP_AF_INET6, TCPIP_IPPROTO_TCP, &tempV2GSocket) )
  {
    Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerV2gGetSocketFailed);
  }
  else
  {
    uint32 u32TxBufferLen = SCC_TCP_TX_BUF_LEN;
    uint32 u32RxBufferLen = SCC_TCP_RX_BUF_LEN;

    Scc_V2GSocket = tempV2GSocket;

# if (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
    /* #20 get possible insecure elliptic curves from application */
    Scc_Priv_GetAndSetRejectedEllipticCurve();
#endif /* SCC_SCHEMA_ISO_20 */

    /* #30 set the TCP Tx buffer */
    if ( (Std_ReturnType)E_OK != TcpIp_ChangeParameter(Scc_V2GSocket, TCPIP_PARAMID_V_TCP_TXBUFSIZE,                    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
      (P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA))&u32TxBufferLen) )
    {
      /* Prepare shutdown */
      Scc_State = Scc_State_ShuttingDown;
      /* close the connection */
      (void) TcpIp_Close(Scc_V2GSocket, TRUE);
      Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerV2gChangeParameterTxBufferSizeFailed);
    }
    /* #40 set the TCP Rx buffer */
    else if ( (Std_ReturnType)E_OK != TcpIp_ChangeParameter(Scc_V2GSocket, TCPIP_PARAMID_TCP_RXWND_MAX,                 /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
      (P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA))&u32RxBufferLen) )
    {
      /* Prepare shutdown */
      Scc_State = Scc_State_ShuttingDown;
      /* close the connection */
      (void) TcpIp_Close(Scc_V2GSocket, TRUE);
      Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerV2gChangeParameterRxBufferSizeFailed);
    }
    else
    {
#if ( SCC_ENABLE_TLS == STD_ON )
      Std_ReturnType retVal = E_OK;
      uint16 uTlsConnection = (uint16)SCC_TLS_CONNECTION_ID;

      /* get the SDPSecurity from the application */
      Scc_SDP_InterfaceCfg_Get_SDPSecurityRx(&Scc_SelectedConnectionType);
      if (Scc_SelectedConnectionType == Scc_SDPSecurity_Tls)
      {
        /* #50 set the TCP Rx buffer */
        if ((Std_ReturnType)E_OK != TcpIp_ChangeParameter(Scc_V2GSocket, TCPIP_PARAMID_TLS_CONNECTION_ASSIGNMENT,       /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
          (P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA))&uTlsConnection))
        {
          retVal = E_NOT_OK;
          /* Prepare shutdown */
          Scc_State = Scc_State_ShuttingDown;
          /* close the connection */
          (void)TcpIp_Close(Scc_V2GSocket, TRUE);
          Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerV2gChangeParameterUseTlsFailed);
        }
      }
      if ( retVal == E_OK )                                                                                             /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
#endif /* SCC_ENABLE_TLS */
      {
        uint16 Port = TCPIP_PORT_ANY;
        /* #60 bind the socket */
        if ( (Std_ReturnType)E_OK != TcpIp_Bind(Scc_V2GSocket, Scc_LocalAddrId, &Port) )
        {
          /* Prepare shutdown */
          Scc_State = Scc_State_ShuttingDown;
          /* close the connection */
          (void) TcpIp_Close(Scc_V2GSocket, TRUE);
          Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerV2gBindFailed);
        }
        else
        {
          /* #70 start the TLS/TCP connection */
          if ( (Std_ReturnType)E_OK == TcpIp_TcpConnect(Scc_V2GSocket, (P2VAR(Scc_SockAddrType, AUTOMATIC, SCC_APPL_DATA))&Scc_ServerSockAddr) )/* PRQA S 0310,3305 */ /* MD_Scc_0310_0314_0316_3305 */
          {
            SCC_ENTER_EXCLUSIVE_AREA_2();
            /* socket is now in use */
            Scc_V2GSocketInUse = TRUE;
            /* update the states */
            Scc_State = Scc_State_TLConnecting;
            SCC_LEAVE_EXCLUSIVE_AREA_2();

            /* start the timeout (if value is 0, timeout will not be started) */
            Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_TimerGeneral_TimerCfg_Get_TransportLayerTimeout();

            Scc_MsgStateFct_EA2(Scc_MsgState_WaitingForV2GTpHeader)
            /* report it to the application */
            Scc_Core_InterfaceCfg_Set_TCPSocketState(Scc_TCPSocketState_Connecting);
          }
          else
          {
            /* report the error */
            Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerV2gConnectFailed);
            /* Prepare shutdown */
            Scc_State = Scc_State_ShuttingDown;
            /* close the connection */
            /* close the transport layer connection */
            (void) TcpIp_Close(Scc_V2GSocket, TRUE);
          }
        }
      }
    }
  }
}

/**********************************************************************************************************************
 *  Scc_Cbk_CopyTxData
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(BufReq_ReturnType, SCC_CODE) Scc_Cbk_CopyTxData(
    TcpIp_SocketIdType SocketId,
    P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) BufPtr,
    P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) BufLengthPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
  Scc_ReturnType retVal_Scc;
  Scc_PbufType TxPbuf;
  uint8 errorId = SCC_DET_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters. */
  if ( SocketId != Scc_V2GSocket )
  {
    errorId = SCC_DET_INV_PARAM;
    retVal = BUFREQ_E_NOT_OK;
  }
  else if ( BufPtr == NULL_PTR )
  {
    errorId = SCC_DET_INV_POINTER;
    retVal = BUFREQ_E_NOT_OK;
  }
  else if ( BufLengthPtr == NULL_PTR )
  {
    errorId = SCC_DET_INV_POINTER;
    retVal = BUFREQ_E_NOT_OK;
  }
  else if (*BufLengthPtr == 0u)
  {
    errorId = SCC_DET_INV_PARAM;
    retVal = BUFREQ_E_NOT_OK;
  }
  else
#endif /* SCC_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    Scc_CoreChannelType currentChannel = Scc_Core_Channel_Get_CurrentChannel();
    P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) txMsgWS = Scc_Core_Channel_Get_TxMsgWSPtr(currentChannel);

    SCC_DUMMY_STATEMENT(SocketId);                                                                                      /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

    /* EXI needs Pbuf */
    TxPbuf.payload = BufPtr;
    TxPbuf.len = *BufLengthPtr;
    TxPbuf.totLen = *BufLengthPtr;

    retVal_Scc = Scc_Exi_EncodeReq(BufPtr, BufLengthPtr, &TxPbuf, txMsgWS);

    /* Convert the return type from Scc_ReturnType to BufReq_ReturnType */
    if(retVal_Scc == Scc_ReturnType_OK)
    {
      retVal = BUFREQ_OK;
    }
    else
    {
      *BufLengthPtr = 0;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #20 Report default errors if any occurred. */
  if ( errorId != SCC_DET_NO_ERROR )
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_CBK_COPY_TX_DATA, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */

  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}

#if ((defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) || \
     (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON)))
/**********************************************************************************************************************
 *  Scc_ProcessCertificateInstallationRes_HelperFirstCall
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ProcessCertificateInstallationRes_HelperFirstCall(
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ExiStreamPtr,
  CONST(uint16, AUTOMATIC) ExiStreamPtrLen,
  CONST(Scc_ProcessCertInstResEnumType, AUTOMATIC) SchemaToUse,
  CONST(boolean, AUTOMATIC) FirstCall)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if it is the first call */
  if (FirstCall == TRUE)
  {
    uint8 buffPoolId = 0;
    P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* #20 Get MsgPtr and MsgPtrSize */
    if (Scc_BufferPoolRequestGetBuffer(SCC_POOL_BUFF_LARGE, &buffPoolWsPtr->MsgPtr, &buffPoolWsPtr->MsgPtrSize, &buffPoolId) != E_OK)
    {
      /* Do nothing. Error already reported */
    }
    else
    {
      P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) rxWsPtr = Scc_Core_Channel_Get_RxMsgWSPtr(SCC_CHANNEL_DEFAULT);
      Scc_Core_Channel_Set_BufferPoolId(buffPoolId);
      /* #30 Decode the passed message */
      retVal = Scc_ProcessCertificateInstallationResDecode(ExiStreamPtr, ExiStreamPtrLen, SchemaToUse, rxWsPtr);
    }
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Decoding already succeeded in earlier call */
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ProcessCertificateInstallationRes
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
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ProcessCertificateInstallationRes(
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ExiStreamPtr,
  CONST(uint16, AUTOMATIC) ExiStreamPtrLen,
  CONST(Scc_ProcessCertInstResEnumType, AUTOMATIC) SchemaToUse,
  CONST(boolean, AUTOMATIC) FirstCall)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8 errorId = SCC_DET_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of runtime parameters. */
  if (ExiStreamPtr == NULL_PTR)
  {
    errorId = SCC_DET_INV_POINTER;
  }
  else
#endif /* SCC_DEV_ERROR_DETECT */
  /* ----- Implementation ----------------------------------------------- */
  {
    /* #20 Check if Scc is idle */
    SCC_ENTER_EXCLUSIVE_AREA_2();
    /* PRQA S 3415 2 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
    if ((Scc_State == Scc_State_Initialized)
      || (Scc_State > Scc_State_ShuttingDown))
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();

      /* #30 Decode message */
      retVal = Scc_ProcessCertificateInstallationRes_HelperFirstCall(ExiStreamPtr,
                                            ExiStreamPtrLen, SchemaToUse, FirstCall);

      /* #40 If decoding succeeded */
      if (retVal == Scc_ReturnType_OK)
      {
        /* #50 Process decoded certificate installation response message */
        switch (SchemaToUse)
        {
# if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON))
          case SCC_PROCCERTINSTRES_ISO15118_2:
          {
            P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
              Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
            retVal = Scc_ISO15118_2_ExiRx_CertificateInstallationRes((P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA)) buffPoolWsPtr->MsgPtr); /* PRQA S 0310,3305 */ /* MD_Scc_Exi_Generic */
          }
            break;
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */
# if (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
          case SCC_PROCCERTINSTRES_ISO15118_20:
          {
            P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) rxWsPtr = Scc_Core_Channel_Get_RxMsgWSPtr(SCC_CHANNEL_DEFAULT);
            retVal = Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes((P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA)) rxWsPtr);
          }
            break;
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

          default:
            retVal = Scc_ReturnType_NotOK;
            break;
        }
      }

      /* #60 Check if an error occurred */
      if (retVal == Scc_ReturnType_NotOK)
      {
        /* #70 Reset stored error so that a later detected error can be reported too */
        Scc_StackError = Scc_StackError_NoError;
      }

      if (retVal != Scc_ReturnType_Pending)
      {
        Scc_BufferPoolRelease(Scc_Core_Channel_Get_BufferPoolId());
      }
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_2();
      retVal = Scc_ReturnType_NotOK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #80 Report development errors if any occurred. */
  if (errorId != SCC_DET_NO_ERROR)
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_PRC_CERT_INST_RES, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */


  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_ProcessCertificateInstallationResDecode
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ProcessCertificateInstallationResDecode(
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ExiStreamPtr,
  CONST(uint16, AUTOMATIC) ExiStreamPtrLen,
  CONST(Scc_ProcessCertInstResEnumType, AUTOMATIC) SchemaToUse,
  CONSTP2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxWsPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Scc_V2GTPHeaderStructType v2gHeader = { 0 }; /* Only used as a dummy statement for ISO15118-2 inside
                                                  Scc_ISO15118_2_ExiRx_DecodeMessagePrepare */
  uint32_least idx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset all csm job states */
  SCC_ENTER_EXCLUSIVE_AREA_0();
  for (idx = 0; idx < (sizeof(Scc_CsmJobInfo) / sizeof(Scc_CsmJobInfo[0])); idx++)
  {
    Scc_CsmJobInfo[idx].State = SCC_CSMJOBSTATE_IDLE;
    Scc_CsmJobInfo[idx].IsCancelled = FALSE;
  }
  SCC_LEAVE_EXCLUSIVE_AREA_0();

  /* The minimum size of 2 for Scc_ExiStreamRxPBuf is ensured by a validator in Cfg5 */
  /* Use a dummy header so that the already existing functions can be reused */
  Scc_ExiStreamRxPBuf[0].payload = &Scc_ProcCertInstResHeaderByteArray[0];
  Scc_ExiStreamRxPBuf[0].totLen = SCC_V2GTP_HDR_LEN + (uint32)ExiStreamPtrLen;
  Scc_ExiStreamRxPBuf[0].len = SCC_V2GTP_HDR_LEN;
  /* #20 Store reference to passed message data */
  Scc_ExiStreamRxPBuf[1].payload = &ExiStreamPtr[0];
  Scc_ExiStreamRxPBuf[1].totLen = SCC_V2GTP_HDR_LEN + (uint32)ExiStreamPtrLen;
  Scc_ExiStreamRxPBuf[1].len = ExiStreamPtrLen;

  /* #30 Process message based on the passed schema */
  switch (SchemaToUse)
  {
# if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON))
    /* #40 Initialize the XmlSecurity workspace and decode message */
    case SCC_PROCCERTINSTRES_ISO15118_2:
      /* #50 ISO 15118-2 */
      Scc_ISO15118_2_ExiRx_InitXmlSecurityWorkspace(NULL_PTR);
      retVal = Scc_ISO15118_2_ExiRx_DecodeMessagePrepare(&v2gHeader,
                                                         RxWsPtr,
                                                         TRUE); /* Perform no SessionIdCheck as currently no session is
                                                                   active */
      break;
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */
# if (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
    case SCC_PROCCERTINSTRES_ISO15118_20:
      /* #60 ISO 15118-20 */
      v2gHeader.PayloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_CM; /* 0x8002 */
      retVal = Scc_ISO15118_20_ExiRx_DecodeMessagePrepare(&v2gHeader, RxWsPtr);
      break;
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
    /* #70 Unsupported schema */
    default:
      /* #80 Indicate error */
      /* Keep retVal as Scc_ReturnType_NotOK */
      break;
  }

  /* #90 Release stream buffer as data is already processed */
  for (idx = 0; idx < (sizeof(Scc_ExiStreamRxPBuf) / sizeof(Scc_ExiStreamRxPBuf[0])); idx++)
  {
    Scc_ExiStreamRxPBuf[idx].totLen = 0u;
    Scc_ExiStreamRxPBuf[idx].len = 0u;
    Scc_ExiStreamRxPBuf[idx].payload = NULL_PTR;
  }

  return retVal;
}

#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_DeleteContract
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_DeleteContract(
  CONST(Scc_ContractIdType, AUTOMATIC) ContractId,
  CONST(boolean, AUTOMATIC) ForceDeletion,
  boolean IsIso15118_20)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8 errorId = SCC_DET_NO_ERROR;
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
  Scc_ContractIdType contractIdCnt = 0;

  /* ----- Development Error Checks ------------------------------------- */
#if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING != 0 )
  /* #10 Check if IsIso15118_20 is set to TRUE */
  if (IsIso15118_20 == TRUE)
  {
    /* #20 Choose -20 EMSPCertCnt */
    contractIdCnt = Scc_ISO20CertConfig.EMSPCertCnt;
  }
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
#if ( defined SCC_ENABLE_PNC_CHARGING ) && ( SCC_ENABLE_PNC_CHARGING != 0 )
  /* #30 Check if IsIso15118_20 is set to FALSE */
  if (IsIso15118_20 == FALSE)
  {
    /* #40 Choose -2 ContrCertChainCnt */
    contractIdCnt = Scc_ISO2CertConfig.ContrCertChainCnt;
  }
#endif /* SCC_ENABLE_PNC_CHARGING */
  /* #50 Check plausibility of runtime parameters. */
  if (ContractId >= contractIdCnt)
  {
    errorId = SCC_DET_INV_PARAM;
  }
  else
#endif /* SCC_DEV_ERROR_DETECT */
  /* ----- Implementation ----------------------------------------------- */
  /* #60 Check session is active. */
  if ((Scc_State_TLConnecting <= Scc_State) && (Scc_State_Connected >= Scc_State) && (ForceDeletion == FALSE))          /* PRQA S 3415 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
  {
    retVal = Scc_ReturnType_Busy;
  }
  else
  {
    P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) contrCertCfgPtr = NULL_PTR;
#if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING != 0 )
    /* Check if IsIso15118_20 is set to TRUE */
    if (IsIso15118_20 == TRUE)                                                                                          /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
    {
      /* Choose -20 EMSPCertsPtr */
      contrCertCfgPtr = &Scc_ISO20CertConfig.EMSPCertsPtr[ContractId];
    }
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
#if ( defined SCC_ENABLE_PNC_CHARGING ) && ( SCC_ENABLE_PNC_CHARGING != 0 )
    /* Check if IsIso15118_20 is set to FALSE */
    if (IsIso15118_20 == FALSE)                                                                                         /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
    {
      /* #70 Choose -2 ContrCert */
      contrCertCfgPtr = &Scc_ISO2CertConfig.ContrCertChainsPtr[ContractId].ContrCertCfg;
    }
#endif /* SCC_ENABLE_PNC_CHARGING */

    if (contrCertCfgPtr != NULL_PTR)
    {
      /* #80 Contract Certificate deletion. */
      retVal = Scc_Core_KeyMUtils_ContractCertDelete(
                   contrCertCfgPtr,
                   SccDetailedError_DeleteContract_PrivKeyCsmDeleteFailed,
                   SccDetailedError_DeleteContract_ContrCertDeleteFailed,
                   SccDetailedError_DeleteContract_MoSubCa2DeleteFailed,
                   SccDetailedError_DeleteContract_MoSubCa1DeleteFailed,
                   TRUE);
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #90 Report development errors if any occurred. */
  if (errorId != SCC_DET_NO_ERROR)
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_DELETE_CONTRACT, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */

  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_Cbk_Csm_ApplNotification
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
/* PRQA S 6080 2 */ /* MD_MSR_STMIF */
/* PRQA S 3673, 3408 3 */ /* MD_MSR_Rule8.13, MD_SCC_AsyncCbk */
FUNC(void, SCC_CODE) Scc_Cbk_Csm_ApplNotification(
  uint32 jobId,
  Crypto_ResultType result)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Fetch the associated job workspace */
  P2CONST(Scc_CsmJobType, AUTOMATIC, SCC_VAR_INIT) jobWs = Scc_CsmLut_GetJobWs(jobId);

  /* ----- Implementation ----------------------------------------------- */
  if (jobWs != NULL_PTR)
  {
    SCC_ENTER_EXCLUSIVE_AREA_1();

    /* #20 Check if the csm job was cancelled, if it was reset its state */
    if (Scc_IsCsmJobCancelledPtr(jobWs) == TRUE)
    {
      Scc_SetCsmJobStatePtr(jobWs, SCC_CSMJOBSTATE_IDLE);
      Scc_SetCsmJobCancelledPtr(jobWs, FALSE);

      SCC_LEAVE_EXCLUSIVE_AREA_1();
    }
    /* #30 Forward the workspace to xml security for signature verification */
    else if (Scc_GetCsmJobUsagePtr(jobWs) == SCC_CSMJOBUSAGE_XML_SIGVER)
    {
      SCC_LEAVE_EXCLUSIVE_AREA_1();
      /* Forward csm callback to xml security */
      XmlSecurity_SigVerWS_UpdateStateAsync(&Scc_Exi_XmlSecSigVerWs, (Csm_ResultType) result);
    }
    /* #40 Forward the workspace to xml security for signature generation */
    else if (Scc_GetCsmJobUsagePtr(jobWs) == SCC_CSMJOBUSAGE_XML_SIGGEN)
    {
      SCC_LEAVE_EXCLUSIVE_AREA_1();
      /* Forward csm callback to xml security */
      XmlSecurity_SigGenWS_UpdateStateAsync(&Scc_Exi_XmlSecSigGenWs, (Csm_ResultType) result);
    }
    else
    {
      /* #50 The csm job is handled by Scc directly */
      if ((jobWs->Mode != SCC_CSMJOBMODE_ASYNCHRONOUS) || (Scc_GetCsmJobStatePtr(jobWs) != SCC_CSMJOBSTATE_PENDING))
      {
        /* There is something wrong */
        Scc_SetCsmJobStatePtr(jobWs, SCC_CSMJOBSTATE_FAILED);
      }
      else
      {
        /* Proceed the jobWs state */
        if (result == E_OK)
        {
          Scc_SetCsmJobStatePtr(jobWs, SCC_CSMJOBSTATE_DONE);
        }
        else
        {
          Scc_SetCsmJobStatePtr(jobWs, SCC_CSMJOBSTATE_FAILED);
        }
      }
      SCC_LEAVE_EXCLUSIVE_AREA_1();
    }
  }
  else
  {
    /* There is something wrong in the config */
# if ( SCC_DEV_ERROR_REPORT == STD_ON )
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_CBK_CSM_NOTIFICATION, SCC_DET_INV_PARAM);
# endif /* SCC_DEV_ERROR_REPORT */
  }
}
#endif /* SCC_ENABLE_PNC_CHARGING == STD_ON || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if (SCC_ENABLE_OCSP == STD_ON)
/**********************************************************************************************************************
 *  Scc_CheckOcspValidity
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
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_CheckOcspValidity(
  P2CONST(Scc_TlsCertStructType, AUTOMATIC, SCC_CONST)                  tlsLeafCertCfgPtr,
  uint32                                                                NumCerts,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA)     CertChainStatusPtr,
  P2VAR(TcpIp_CertValidationResultType, AUTOMATIC, SCC_APPL_DATA)       ValidationResultPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 maxNumCertsToCheck = NumCerts;
  uint32 idx = 0;
  boolean OcspValid = TRUE;
# if defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u)
  boolean OcspConnectionOnlyRequested = TRUE;
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the OCSP informations have been sucessfully received */
  if (CertChainStatusPtr[0].CertStatusResponse.OcspConnectionState == TCPIP_TLS_OCSP_CONNECTION_STATE_STATUS_RECEIVED)
  {
    /* #20 If TRUE: get the maximum number of certificates to consider based on the leaf certificate */
    if (CertChainStatusPtr[0].CertStatusResponse.OcspMode == TCPIP_TLS_OCSP_MODE_NONE)
    {
      /* If no OCSP mode is activated do not check ANY certificate. */
      maxNumCertsToCheck = 0;
    }
    else if (CertChainStatusPtr[0].CertStatusResponse.OcspMode == TCPIP_TLS_OCSP_MODE_SINGLE)
    {
      /* In case of single mode check only the first certificate */
      maxNumCertsToCheck = 1;
    }
    else
    {
      /* The maximum number of certificates does not need to be adjusted.
       * It already equals the number of certificates. */
    }
  }
  else
  {
    /* #30 Otherwise: consider no certificates towards their OCSP status */
    OcspValid = FALSE;
    maxNumCertsToCheck = 0;
    if (CertChainStatusPtr[0].CertStatusResponse.OcspConnectionState == TCPIP_TLS_OCSP_CONNECTION_STATE_INACTIVE)
    {
# if defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u)
      OcspConnectionOnlyRequested = FALSE;
# endif
    }

  }

  /* #40 Check all relevant certificates towards their OCSP status */
  for (idx = 0; idx < maxNumCertsToCheck; idx++)
  {
    /* #50 Check if OCSP status was received */
    if (CertChainStatusPtr[idx].CertStatusResponse.OcspConnectionState == TCPIP_TLS_OCSP_CONNECTION_STATE_STATUS_RECEIVED)
    {
# if defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u)
      OcspConnectionOnlyRequested = FALSE;
# endif

      /* #60 Check if OCSP returns a invalid certificate or was not successful */
      if ((CertChainStatusPtr[idx].CertStatusResponse.OcspCertStatus != KEYM_CERTIFICATE_VALID)
        || (CertChainStatusPtr[idx].CertStatusResponse.OcspResponseStatus != TCPIP_TLS_OCSP_RESPONSE_STATUS_SUCCESSFUL))
      {
        OcspValid = FALSE;
      }
    }
    /* #70 check if at least OCSP was requested */
    else if (CertChainStatusPtr[idx].CertStatusResponse.OcspConnectionState == TCPIP_TLS_OCSP_CONNECTION_STATE_REQUESTED)
    {
      /* #80 If TRUE: a validation was requested but the OCSP validity could not be checked */
      OcspValid = FALSE;
    }
    else
    {
      /* #90 If FALSE: no connection should be established */
      OcspValid = FALSE;
# if defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u)
      OcspConnectionOnlyRequested = FALSE;
# endif
      break;
    }
  }

  /* #100 Save the Ocsp result into workspace */
  Scc_Core_InterfaceCfg_Set_OcspValid(OcspValid);

# if defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
  if (tlsLeafCertCfgPtr->Curve != Scc_CertCurve_secp256r1)
  {
    /* #110 In case of ISO 15118-20: ask the application if an invalid OCSP
     *      status may be proceeded in case of an private environment */

    /* #120 Get from application if PrivateEnvironment is active */
    boolean PrivateEnvironmentInUsage = FALSE;
    Scc_Core_InterfaceCfg_Get_SccTlsPEUsage(&PrivateEnvironmentInUsage);

    /* #130 Check if no PrivateEnvironment is in usage and OCSP was successful */
    if ((PrivateEnvironmentInUsage == FALSE)
      && (OcspValid == FALSE))
    {
      /* #140 If false: no connection should be established */
      *ValidationResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;
    }
    else
    {
      /* #150 Otherwise: a TLS connection may be established */
    }
  }
  else
# endif /* SCC_SCHEMA_ISO_20 */
  {
# if defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u)
    /* #160 In case of ISO 15118-2: if the Ocsp check was not successful
     *      and was not only requested, no connection should be established */
    if ((OcspValid == FALSE) && (OcspConnectionOnlyRequested == FALSE))
    {
      *ValidationResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;
    }
    else
    {
      /* #170 Otherwise: a TLS connection may be established */
    }
# endif /* SCC_SCHEMA_ISO_2 */
  }
}
#endif /* SCC_ENABLE_OCSP == STD_ON */

#if ( ( (defined SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON) ) && ( (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u) ) )
/**********************************************************************************************************************
 *  Scc_CheckTlsCertsForRejectedEllipticCurves
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
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_CheckTlsCertsForRejectedEllipticCurves(
  P2VAR(TcpIp_CertValidationResultType, AUTOMATIC, SCC_APPL_DATA) ValidationResultPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32_least tlsCertIdx = 0;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Iterate over all tls certificates */
  for (tlsCertIdx = 0; tlsCertIdx < SCC_TLS_CERT_CNT; tlsCertIdx++)
  {
    KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
    Std_ReturnType retValKeyM = E_NOT_OK;

    /* #20 Get certificate status inside KeyM */
    retValKeyM = SCC_KEYM_CERTGETSTATUS(Scc_TlsCertConfig[tlsCertIdx].KeyMCertId, &certStatus);

    /* #30 Check if current certificate is valid */
    if ((retValKeyM == E_OK) && (certStatus == KEYM_CERTIFICATE_VALID))
    {
      /* #40 Check if the elliptic curve is rejected by application */
      if (Scc_Priv_IsEllipticCurveRejected(Scc_TlsCertConfig[tlsCertIdx].Curve) == TRUE)
      {
        /* #50 The current elliptic curve has been rejected, report error and establish no connection */
        Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_ISO20_TransportLayerTlsCertChainEllipticCurveRejected);
        *ValidationResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;
        break;
      }
    }
  }
}
#endif /* SCC_ENABLE_TLS, SCC_SCHEMA_ISO_20 */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Cbk_KeyM_OEMProvGroupVerifyResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */ /* PRQA S 3408 1 */ /* MD_Scc_VariantDependent */
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Cbk_KeyM_OEMProvGroupVerifyResult(
  KeyM_CertificateGroupIdType GroupId,
  KeyM_CertificateGroupStatusType Result)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward KeyM callback to KeyM utils */
  if (GroupId == Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId].OEMProvCertPtr->KeyMGroupId)
  {
    Scc_Core_KeyMUtils_CbkUpdateStatus(&Scc_OEMProvUpdateState, Result);
  }

  return E_OK;
}
#endif /* SCC_ENABLE_PNC_CHARGING == STD_ON */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Cbk_KeyM_GroupUpdateStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Cbk_KeyM_GroupUpdateStatus(
  KeyM_CertificateGroupIdType GroupId,
  KeyM_CertificateGroupStatusType Result)
{
  /* #10 Forward to KeyM utils unit */
  return Scc_Core_KeyMUtils_CbkGroupUpdateStatus(GroupId, Result);
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
/**********************************************************************************************************************
 *  Scc_SetOemProvCertChain
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_SetOemProvCertChain(uint8 NewProvCertChainIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the selected chain exists */
  if (NewProvCertChainIndex < Scc_ISO20CertConfig.OEMProvCertCnt)
  {
    /* #20 Set OemCertId */
    Scc_ChosenCert.OemCertId = NewProvCertChainIndex;

    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/

/* Justification for module specific MISRA deviations:

  MD_Scc_0310_0314_0316_3305:
    Reason:     Cast is necessary to better use the resources.
    Risk:       Alignment issues may occur.
    Prevention: Covered by code review.

  MD_Scc_0770:
    Reason:     While searching, the code after the continue must not be executed.
    Risk:       Statements that follow the continue are not executed, code could behave unexpected.
    Prevention: Covered by code review.

  MD_Scc_0771:
    Reason:     The code after the break must not be executed.
    Risk:       Statements that follow the break are not executed, code could behave unexpected.
    Prevention: Covered by code review.

  MD_Scc_0781:
    Reason:     Name of atomic parameter is also used as a name of a struct parameter.
    Risk:       None.
    Prevention: Covered by code review.

  MD_Scc_2002:
    Reason:     No default handling required.
    Risk:       Missing default handling.
    Prevention: Covered by test cases and code review.

  MD_Scc_2004:
    Reason:     Missing else path in if-condition.
    Risk:       Missing default handling.
    Prevention: Covered by test cases and code review.

  MD_Scc_2742_2880_2991_2995:
    Reason:     The statement will not be reached in this configuration. But there are other configuration variants
                  in which this statement will be reached. E.g. other post-build configuration or different use-case.
    Risk:       None.
    Prevention: Already correctly handled, but not detected by PRQA.

  MD_Scc_2992_2996:
    Reason:     In this configuration, the condition will always return TRUE or FALSE. But there are other configuration variants
                  in which this condition result may change. E.g. other post-build configuration or different use-case.
    Risk:       None.
    Prevention: Already correctly handled, but not detected by PRQA.

  MD_Scc_1514:
    Reason:     Local static variables are forbidden due to memory mapping, therefore variable has to be file static.
    Risk:       Small, parameters are already file-local and variable may be accessed from other functions.
    Prevention: Covered by code review.

  MD_Scc_3218:
    Reason:     Local static variables are forbidden due to memory mapping, therefore variable has to be file static.
    Risk:       Small, parameters are already file-local and variable may be accessed from other functions.
    Prevention: Covered by code review.

  MD_Scc_3332:
    Reason:     It is checked if the macro is defined.
    Risk:       None.
    Prevention: Already correctly handled, but not detected by PRQA.

  MD_Scc_3333:
    Reason:     The loop/case is used to search for something. If it was found,
                  the loop/case can be quit (by using break).
    Risk:       Statements that follow the break are not executed, code could behave unexpected.
    Prevention: Covered by code review.

  MD_Scc_QAC_Mistaken:
    Reason:     MISRA detected an issue where there is none. The code does not violate any rules.
    Risk:       None.
    Prevention: Covered by code review.

  MD_Scc_Exi_Generic:
    Reason:     The Exi component provides and consumes information in a generic way. Scc uses type safe storage.
                  Therefore, the values must be converted.
    Risk:       Alignment issues may occur.
    Prevention: Covered by code review.

  MD_Scc_Nvm_Generic:
    Reason:     The Nvm component takes information in a generic way. Scc uses type safe storage.
                  Therefore, the values must be converted.
    Risk:       None.
    Prevention: Covered by code review.

  MD_Scc_Interface_Generic:
    Reason:     Scc uses a generated generic interface but Scc uses specialized types.
                  Therefore, the values must be converted.
    Risk:       None.
    Prevention: Covered by code review.

  MD_Scc_Empty_Statement:
    Reason:     If macros are used in different code variants it may happen that after resolving
                  the macro only a null statement remains. This happens typically if a callback is not set.
    Risk:       Wrong macro implementations could remain undetected.
    Prevention: Covered by code review and component test suite.

  MD_Scc_20.4:
    Reason:     Since efficiency is a primary implementation target it is necessary to use macros.
    Risk:       Resulting code is difficult to understand or may not work as expected.
    Prevention: Covered by code review and component test suite.

  MD_Scc_15.5:
    Reason:     A single exit point may lead to an inefficient or more difficult to understand
                  code because the structure of the function can become more complex.
                  Therefore it may be necessary to violate this rule for runtime and maintenance
                  efficiency reasons.
    Risk:       Function may e.g. terminate with locked interrupts. Control and data flow have
                  multiple paths -> increased risk of adding errors during maintenance activities.
    Prevention: Product design defines two "blocks" in each function, one block is
                  "checking/validity action like DET checks", and another block is "functional
                  behavior". "Checking/validity actions" are allowed to terminate immediately
                  resulting in more than one exit in the function. "Functional behavior" checks
                  are expected to terminate at the end of the function in one single exit.
                  Based on this design rule, a justification is necessary for each deviating
                  function.

  MD_Scc_ReturnType:
    Reason:     The Scc_StdReturnType includes the Std_ReturnType values.
    Risk:       Wrong mapping of return values.
    Prevention: Covered by code review and component test suite.

  MD_Scc_VariantDependent:
    Reason:     The variable usage depends on the actual variant.
    Risk:       None.
    Prevention: Covered by code review.

  MD_SCC_DummyCallback:
    Reason:     The callback is used to enable compiling but does not contain any functionality.
    Risk:       None.
    Prevention: Covered by code review.

  MD_SCC_ResetFlagUnion:
    Reason:     This assignment clears all flags of the union. The specialized flags then are accessed via the struct.
    Risk:       None.
    Prevention: Covered by code review.

  MD_SCC_AsyncCbk:
    Reason:     This callback may be used by the csm if a callback is configured.
    Risk:       Unused code.
    Prevention: Covered by code review.

  MD_SCC_RX_QUEUE_LEN_NOT_ZERO:
    Reason:     The length of the buffer is not zero. Therefore a division by zero does not occur.
    Risk:       Failing division.
    Prevention: Covered by test suite.

  MD_SCC_VOLATILE_INCR_DECR:
    Reason:     The ++ of -- operator is used on a volatile variable.
    Risk:       None because the volatile variable access is protected by a exclusive area.
    Prevention: Covered by code review.

  MD_SCC_VOLATILE_NO_SIDE_EFFECT:
    Reason:     The volatile variable is not used on a hardware register where the access would may trigger some
                actions like setting or resetting a bit in the associated register. In context of Scc it is only
                used to ensure that the data set in interrupt context is propagated to main function context and
                vice versa. Therefore, we expect no side effects here.
    Risk:       Decreased performance due to limited optimization options for the compiler.
    Prevention: Covered by code review.

  MD_SCC_VOLATILE_EA_PROTECTED:
    Reason:     The volatile variable being accessed is protected by an exclusive area. Therefore it is not possible
                that the execution is being interrupted between the sequence points.
    Risk:       Missing exclusive area may lead to data inconsistency.
    Prevention: Covered by code review.

  MD_SCC_GENERIC_STATE_MACHINE_PARAMETER:
    Reason:     The function prototype is defined by the generic state machine. But the parameter may not be used in
                all available states and depending on the dummy statement configuration a MISRA warning may be issued.
    Risk:       Parameter is not used eventhough it may be should be used.
    Prevention: Covered by code review.

  MD_SCC_GENERIC_CFG_PARAMETER:
    Reason:     The configuration parameter is always an integer value but may be casted to different data types
                in configuration abstraction layer.
    Risk:       Invalid value in context of casted data type
    Prevention: None. Customer has to make sure he is providing correct values.

  MD_SCC_CORE_CHANNEL_ENUM:
    Reason:     The enum represents channels being used. As the enum it self and the number it self is configuration dependent
                as SCC_CHANNEL_RENEGOTIATION is only used when SCC_ENABLE_RENEGOTIATION_CHANNEL is enabled.
                Therefore, relational operations that are some times needed are accepted.
    Risk:       None.
    Prevention: None.

  MD_SCC_CORE_GENERIC_INTERFACE:
    Reason:     The interface is defined for multiple schemas. Some may not use all parameters.
    Risk:       Unused parameters.
    Prevention: None.

  MD_SCC_DETAILED_ERROR:
    Reason:     The detailed error is required to also carry the KeyM, Csm etc return value. Hence addition with enum is done
    Risk:       None.
    Prevention: Covered by code review.

  MD_SCC_ARRAY_OUT_OF_BOUND:
    Reason:     The for loop before array access takes into consideration the array size
    Risk:       Array out of bounds access might occur.
    Prevention: Covered by code review.

  MD_SCC_BigStructure:
    Reason:     Messages above 64kB might be received and customer could configure values lesser than 64kB too
    Risk:       Program does not conform strictly to ISO:C99..
    Prevention: Covered by code review.

  MD_SCC_BerGet:
    Reason:     Assignment is redundant according to misra. But the IpBase_BerGetElement uses this value
    Risk:       None.
    Prevention: Covered by code review.

  MD_SCC_MultiplePaymentPossible:
    Reason:     If condition is always false. But multiple payment options are possible due to which it could be true too
    Risk:       None.
    Prevention: Covered by code review.

  MD_SCC_Initialization:
    Reason:     This assignment is redundant. Since it is better to Initialize all variables at definition this Initialization is needed
    Risk:       None.
    Prevention: Covered by code review.

  MD_SCC_LongNames:
    Reason:     This rule is not followed since function and detailed error names should be better readable than being short
    Risk:       None.
    Prevention: Covered by code review.

  MD_SCC_TlsLenCheck:
    Reason:     Tls CertIdListLen is checked before array is accessed
    Risk:       Dereference of an invalid pointer value.
    Prevention: Covered by code review.

  MD_SCC_ArrayReadFromKeyM:
    Reason:     Array is read out from KeyM, so value need not be false always at runtime
    Risk:       Condition is always false.
    Prevention: Covered by code review.

  MD_SCC_Uint16ToBool:
    Reason:     Value is written only if it is TRUE or FALSE which is checked in the previous condition.
                Hence typecasting to Boolean should not be an issue
    Risk:       Values could be cut off.
    Prevention: Covered by code review.

 MD_SCC_NvmArrayNotUsed:
    Reason:     QAC gives the notice that the array is not used in the project - but it is used by generated NvM
                objects like the block descriptor table.
    Risk:       None.
    Prevention: Covered by code review.
*/

/* module specific LINT deviations:
  LD_SCC_POINTER_TO_ARRAY:
    Reason:     Passed pointer is a pointer to array and length check is done before accessing the array index
    Risk:       Array out of bound access
    Prevention: Covered by code review

  LD_SCC_NULL_ACCESS:
    Reason:     NULL_PTR is used to initialize a pointer. Writing the pointer is done in a different sub-scope (e.g. an
                if block) than reading from it (e.g. another if block) - but the reading block only is executed when
                the writing block is executed before, so a null pointer access cannot happen.
    Risk:       Null pointer access
    Prevention: Covered by code review
*/

/**********************************************************************************************************************
 *  END OF FILE: Scc.c
 *********************************************************************************************************************/
