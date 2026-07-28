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
/*!        \file  Scc_SDP_Rx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements the shared SECCDiscoveryProtocol that is used in Vehicle 2 Grid communication according
 *                to the specifications DIN SPEC 70121, ISO/IEC 15118-2 and customer specific schemas.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_SDP_RX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_SDP.h"
#include "Scc_SAP_Exi.h"
#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_SDP_InterfaceCfg.h"
#include "TcpIp.h"
#include "Scc_Core_InterfaceCfg.h"

#if (SCC_IDSM_REPORT == STD_ON)
# include "IdsM.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_SDPSecurityType, SCC_VAR_NOINIT) Scc_SDP_Rx_Security;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SDP_Rx_GetSecurity
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_SDPSecurityType, SCC_STATIC_CODE) Scc_SDP_Rx_GetSecurity(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the Security value */
  return Scc_SDP_Rx_Security;
}

/**********************************************************************************************************************
 *  Scc_SDP_Rx_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_SDP_Rx_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset the Security value */
  Scc_SDP_Rx_Security = Scc_SDPSecurity_None;
}

/**********************************************************************************************************************
 *  Scc_SDP_Rx_SECCDiscoveryProtocolResPlc
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
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SDP_Rx_SECCDiscoveryProtocolResPlc(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(RxMsgWSPtr);                                                                                /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  retVal = Scc_SDP_Rx_SECCDiscoveryProtocolResCheckHeader(V2GTpHeaderPtr, Scc_SDPPhysComLayer_PLC);

  /* #10 Check if the V2G Header is OK */
  if (retVal == Scc_ReturnType_OK)
  {

    retVal = Scc_SDP_Rx_SECCDiscoveryProtocolResProcessCommonPayload();

    /* #20 Check if the payload contains valid SECC parameters */
    if (retVal == Scc_ReturnType_OK)
    {
      /* #30 Reset the retry counter */
      Scc_SDP_Tx_Init();

      SCC_ENTER_EXCLUSIVE_AREA_2();
      /* #40 Set the new state */
      Scc_State = Scc_State_SDPComplete;
      SCC_LEAVE_EXCLUSIVE_AREA_2();

      /* #50 Report reception of valid response to StateM */
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_SECCDiscoveryProtocol_OK);

      /* #60 Set the new rx config to handle supported app protocol */
      Scc_SAP_ExiRx_SetupRxConfig(&Scc_RxConfig);

      /* #70 Close the SDP socket */
      (void)TcpIp_Close(Scc_SDPSocket, FALSE);
      Scc_SDPSocket = (Scc_SocketType)TCPIP_INV_SOCKET_ID;
    }
  }

  return retVal;
}

#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
/**********************************************************************************************************************
 *  Scc_SDP_Rx_SECCDiscoveryProtocolResWireless
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
 */
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SDP_Rx_SECCDiscoveryProtocolResWireless(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) messagePtr = &Scc_ExiStreamRxPBuf[0].payload[SCC_V2GTP_HDR_LEN];
  Scc_SDPDiagDataType diagStatus = Scc_SDPDiagDataType_Error_No_Secc;
  uint16 evseIdLength = 0;
  uint16 evseIdIndex;

  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(RxMsgWSPtr);                                                                                /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  retVal = Scc_SDP_Rx_SECCDiscoveryProtocolResCheckHeader(V2GTpHeaderPtr, Scc_SDPPhysComLayer_Wireless);

  /* #10 Check if the V2G Header is OK */
  if (retVal == Scc_ReturnType_OK)
  {
    retVal = Scc_SDP_Rx_SECCDiscoveryProtocolResProcessCommonPayload();

    /* #20 Check if the payload contains valid SECC parameters */
    if (retVal == Scc_ReturnType_OK)
    {
      /* #30 Retrieve wireless specific parameters from the message and propagate them to StateM  */

      diagStatus = (Scc_SDPDiagDataType)messagePtr[SCC_SDPRESOFFSETS_DIAGSTATUS];                                       /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */

      /* #40 Determine length of evseId by finding 0 termination */
      for (evseIdIndex = SCC_SDPRESOFFSETS_EVSEID; evseIdIndex < (SCC_SDP_RES_WIRELESS_LEN - SCC_V2GTP_HDR_LEN); evseIdIndex++)
      {
        if (messagePtr[evseIdIndex] == 0x00u)
        {
          evseIdLength = (evseIdIndex - SCC_SDPRESOFFSETS_EVSEID);
          break;
        }
      }

      Scc_SDP_InterfaceCfg_Set_SDPEvseIdTx(&messagePtr[SCC_SDPRESOFFSETS_EVSEID], evseIdLength);

      Scc_SDP_InterfaceCfg_Set_SDPDiagData(diagStatus);

      Scc_SDP_InterfaceCfg_Set_SDPCouplingTypeTx((Scc_SDPCouplingType)messagePtr[SCC_SDPRESOFFSETS_COUPLINGTYPE]);      /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */

      /* #50 Check if the DiagStatus is set to ongoing */
      if (diagStatus == Scc_SDPDiagDataType_Ongoing)
      {
        /* #60 Report reception of valid response to StateM  */
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SECCDiscoveryProtocol_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      }
      /* #70 Otherwise check if DiagStatus is set to finished */
      else if (   (diagStatus == Scc_SDPDiagDataType_Finished_With_EvseId)
               || (diagStatus == Scc_SDPDiagDataType_Finished_Without_EvseId) )
      {
        SCC_ENTER_EXCLUSIVE_AREA_2();
        /* #80 Set the new state */
        Scc_State = Scc_State_SDPComplete;
        SCC_LEAVE_EXCLUSIVE_AREA_2();

        /* #90 Set the new rx config to handle supported app protocol */
        Scc_SAP_ExiRx_SetupRxConfig(&Scc_RxConfig);

        /* #100 Report reception of valid response to StateM  */
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SECCDiscoveryProtocol_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      }
      /* #110 Otherwise */
      else
      {
        /* #120 diagStatus == Scc_SDPDiagDataType_Error_No_Secc */
        retVal = Scc_ReturnType_NotOK;
        Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerSdpDiagStatusNoSecc);

        /* #130 Report reception of invalid response to StateM  */
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SECCDiscoveryProtocol_Failed);
      }

      /* #140 [V2G20-4101] Reset the retry counter */
      Scc_SDP_Tx_Init();

      /* #150 Close the SDP socket */
      (void)TcpIp_Close(Scc_SDPSocket, FALSE);
      Scc_SDPSocket = (Scc_SocketType)TCPIP_INV_SOCKET_ID;
    }
    /* #160 Otherwise */
    else
    {
      /* #170 Ignore the message */
    }
  }
  /* #180 Otherwise */
  else
  {
    /* #190 Do nothing further - retVal has already been set */
  }

  return retVal;
}
#endif /* SCC_WIRELESS_SDP */

/**********************************************************************************************************************
 *  Scc_SDP_Rx_SECCDiscoveryProtocolResCheckHeader
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
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SDP_Rx_SECCDiscoveryProtocolResCheckHeader(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  Scc_SDPPhysComLayerType PhysComLayerType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8 expectedSdpResPayloadLength = 0xFFu;
  uint16 expectedSdpResPayloadType = 0x0000u;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Check if physical layer type is set to plc */
  if (PhysComLayerType == Scc_SDPPhysComLayer_PLC)
  {
    /* #20 Set expected payload length and type to plc defaults */
    expectedSdpResPayloadLength = (SCC_SDP_RES_PLC_LEN - SCC_V2GTP_HDR_LEN);
    expectedSdpResPayloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_PLC_RES;
  }
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
  /* #30 Otherwise check if physical layer type is set to wireless */
  else if (PhysComLayerType == Scc_SDPPhysComLayer_Wireless)
  {
    /* #40 Set expected payload length and type to plc defaults */
    expectedSdpResPayloadLength = (SCC_SDP_RES_WIRELESS_LEN - SCC_V2GTP_HDR_LEN);
    expectedSdpResPayloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_WIRELESS_RES;
  }
#endif /* SCC_WIRELESS_SDP */
  /* #50 Otherwise */
  else
  {
    /* PhysComLayerType == Scc_SDPPhysComLayer_Undefined */
    /* Do nothing, retVal is already set to Scc_ReturnType_NotOK */
  }

  /* #60 Check if expected payload length has been set to valid value */
  if (expectedSdpResPayloadLength != 0xFFu)
  {
    /* #70 Check if payload length is less than expected */
    if (V2GTpHeaderPtr->PayloadLength < expectedSdpResPayloadLength)
    {
      /* #80 The payload length is too small to handle the message */
      retVal = Scc_ReturnType_InvalidPayloadLen;
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
#if (defined(SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD) && (SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD == STD_ON))
    /* Do not perform the length check as too big payload information in header should be ignored */
#else
    /* #90 Check if the payload length is unequal the expected payload length */
    else if (V2GTpHeaderPtr->PayloadLength != expectedSdpResPayloadLength)
    {
      /* #100 The payload length is too big the message is going to be ignored */
      retVal = Scc_ReturnType_InvalidPayloadLen;
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
#endif /* SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD */
    /* #110 Check if the payload type is unequal the expected type  */
    else if (V2GTpHeaderPtr->PayloadType != expectedSdpResPayloadType)
    {
      retVal = Scc_ReturnType_NotOK;
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
    /* #120 Otherwise */
    else
    {
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_SDP_Rx_SECCDiscoveryProtocolResProcessCommonPayload
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SDP_Rx_SECCDiscoveryProtocolResProcessCommonPayload(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) messagePtr = &Scc_ExiStreamRxPBuf[0].payload[SCC_V2GTP_HDR_LEN];

  /* ----- Implementation ----------------------------------------------- */

  /* #10 provide the TransportProtocol information to the application */
  Scc_SDP_InterfaceCfg_Set_SDPTransportProtocol((Scc_SDPTransportProtocolType)messagePtr[Scc_SDPResOffsets_Protocol]);  /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */

  /* #20 provide the security information to the application */
  Scc_SDP_Rx_Security = (Scc_SDPSecurityType)messagePtr[Scc_SDPResOffsets_Security];                                    /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
  Scc_SDP_InterfaceCfg_Set_SDPSecurityTx(Scc_SDP_Rx_Security);

  /* #30 check if the option for the transport protocol and security are correct, else ignore this message */
  if ((uint8)SCC_SDP_TP_TCP != messagePtr[Scc_SDPResOffsets_Protocol])
  {
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_SDP_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else if ((Scc_SDPSecurity_Tls != Scc_SDP_Rx_Security)
    && (Scc_SDPSecurity_None != Scc_SDP_Rx_Security))
  {
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_SDP_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    uint16 Port;

    Port = (uint16)((uint16)messagePtr[Scc_SDPResOffsets_Port] << 8u);
    Port |= (uint16)messagePtr[Scc_SDPResOffsets_Port + 1u];

    /* #40 set the server socket address struct */
    Scc_ServerSockAddr.domain = SCC_IPvX_IPV6;
    Scc_ServerSockAddr.port = (uint16)(IPBASE_HTON16(Port));
    /* #50 copy the IP address of the server socket */
    /* PRQA S 0310,3305,0315 2 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy  */
    IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) & Scc_ServerSockAddr.addr[0u],
      (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) & messagePtr[Scc_SDPResOffsets_IPAddress], 16u);

    /* provide the socket to the application */
    Scc_SDP_InterfaceCfg_Set_SECCIPAddress(&messagePtr[Scc_SDPResOffsets_IPAddress]);
    Scc_SDP_InterfaceCfg_Set_SECCPort(Port);

    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_SDP_Rx.c
 *********************************************************************************************************************/
