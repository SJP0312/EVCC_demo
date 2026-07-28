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
/*!     \file   TcpIp_TlsPriv.c
 *      \brief  Transport Layer Security (TLS) private functions implementation.
 *
 *    \details  This file is part of the TcpIp TLS submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#define TCPIP_TLS_PRIV_SOURCE

#include "TcpIp_Cfg.h"
#if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                    /* COV_MSR_UNSUPPORTED */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "TcpIp_TlsPriv.h"
# include "TcpIp_Tls.h"
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  include "TcpIp_Tls12Core.h"
# endif
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  include "TcpIp_Tls13Core.h"
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#   include "TcpIp_Tls13Client.h"
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  include "TcpIp_TlsClientCommon.h"
# endif
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  include "TcpIp_TlsServer.h"
# endif
# include "TcpIp_TlsCoreCommon.h"
# include "TcpIp_Lcfg.h"

# if (TCPIP_DEV_ERROR_REPORT == STD_ON)
#  include "Det.h"
# endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

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
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION
 *********************************************************************************************************************/
# define TCPIP_START_SEC_CODE
# include "TcpIp_MemMap.h"                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_AddHsHdr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsMsg_AddHsHdr(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsMsgHandshakeType, AUTOMATIC) HsType)
{
  /*         HS HEADER FORMAT
   *      +-------------------+
   *      | HS |      HS      |
   *      |TYPE|    LENGTH    |
   *      +-------------------+
   * BYTE   0    1    2    3
   */
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType adHsWriteTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);


  /* ----- Implementation ----------------------------------------------- */
  if (adHsWriteTlsBufferTxIdx < TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx))
  {
    /* #10 Write the handshake type to the first Byte of the TLS handshake header */
    IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(adHsWriteTlsBufferTxIdx), 0, HsType);

    /* Skip the length information - this will be set later (see function TcpIp_TlsMsg_AddLenToHsHdr) */

    /* Increment the write index by the consumed length (4 Byte) */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_HSHDRLEN);
  }
} /* TcpIp_TlsMsg_AddHsHdr() */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_AddLenToHsHdr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsMsg_AddLenToHsHdr(
  TcpIp_TlsBufferTxIterType   HsHdrStartTlsBufferTxIdx,
  CONST(uint32, AUTOMATIC)    Length)
{

  /* ----- Implementation ----------------------------------------------- */
  /* Runtime check to write 3 bytes into the TLS TxBuffer */
  if ((HsHdrStartTlsBufferTxIdx + 3u) < TcpIp_GetSizeOfTlsBufferTx())
  {
     /* #10 Write the length into the buffer at the specific offset */
    IpBase_PutUint24(TcpIp_GetAddrTlsBufferTx(HsHdrStartTlsBufferTxIdx), TCPIP_TLS_HSHDRLEN_OFFSET, Length);
  }
} /* TcpIp_TlsMsg_AddLenToHsHdr() */

/**********************************************************************************************************************
 *  HELLO MESSAGE HANDLING
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsHelloMsg_AddSessionId
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
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsHelloMsg_AddSessionId(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType sessionIdLenTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Session Id not supported by this Implementation of TLS 1.2 - Set the length to zero for now. */
  uint8 sessionIdLen = 0;

  /* Do not set the length of the sessionId yet. The index of the buffer is saved in sessionIdLenTlsBufferTxIdx.
   * Increment the write index by the length (1 Byte). */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_SESSIONIDLEN_LEN);

  /* #20 Set the SessionId Start index */
  /* #30 Store the index of the SessionId - Index needed for possible master secret access */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
  {
    /* Mode == TCPIP_TLS_SERVER */
    TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_SetTlsBufferTxServerSessionIdIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
      TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
    TcpIp_SetServerHelloSessionIdLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u); /* Session ID not supported, so length is always 0 */
  }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Mode == TCPIP_TLS_CLIENT */
    TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_SetTlsBufferTxClientSessionIdIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
      TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_13) == TRUE)
    {
      /* RFC8446 chapter 4.1.2 states that "A client which has a cached session ID set by a pre-TLS 1.3 server
       * SHOULD set this field to that value" referring to the legacy_session_id.
       * Since Session Id is not supported by this implementation in the default 1.3 case the session Id is empty.
       * But the RFC also states that in compatibility mode (see Appendix D.4), this field MUST be non-empty,
       * so a client not offering a pre-TLS 1.3 session MUST generate a new 32-byte value.
       * In this case a random 32-byte value is send. */
      if (TcpIp_IsMiddleboxCompatibilityModeOfTlsConnection(TlsConIdx) == TRUE)
      {
        /* #40 TLS 1.3 compatibility mode: Add a random session id and set the length accordingly. */
        sessionIdLen = TCPIP_TLS13_LEGACYSESSIONIDLEN;
        retVal = TcpIp_TlsHelloMsg_AddRandomStructureGetRandom(TlsConIdx, sessionIdLen);
      }
    }
#  endif
  }
# endif

  /* #50 Set the length information in the Tx buffer. */
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(sessionIdLenTlsBufferTxIdx), 0, sessionIdLen);

  return retVal;
} /* TcpIp_TlsHelloMsg_AddSessionId() */

/**********************************************************************************************************************
 *  TcpIp_TlsHelloMsg_AddProtocolVersionNr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsHelloMsg_AddProtocolVersionNr(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* For TLS 1.3 as for 1.2 0x0303 is added here, even though this is only the version number for TLS 1.2.
   * The actual possible versions in TLS 1.3 are indicated in the supported_versions extension (RFC8446 chapter 4.1.2). */
  /* #10 Add the major version (3) to the TLS TxBuffer at the current write position */
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0u,
                  TCPIP_TLS_PROTOCOL_MAJOR_VERSION_3);

  /* Increment the write index by the consumed length (1 Byte) */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_MAJORVERS_LEN);

  /* #20 Add the minor version (3) to the TLS TxBuffer at the current write position + 1 */
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0u,
                  TCPIP_TLS_PROTOCOL_MINOR_VERSION_3);

  /* Increment the write index by the consumed length (1 Byte) */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_MINORVERS_LEN);

} /* TcpIp_TlsHelloMsg_AddProtocolVersionNr() */

/**********************************************************************************************************************
 *  TcpIp_TlsHelloMsg_AddRandomStructure
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsHelloMsg_AddRandomStructure(
  TcpIp_TlsConnectionIterType              TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  boolean addUserTimeStamp = TRUE;
  uint32 randomLength = TCPIP_TLS_RANDOM_LEN;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* Hello Random Structure Format - RFC 5246 7.4.1.2.Client Hello (is the same for Server Hello)
   * Byte 0 - 3  : GMT Unix Time stamp
   * Byte 4 - 33 : Random Bytes
   */

/* Write index is pointing to the location within the TxBuffer where the random value is stored */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
  {
    /* Mode == TCPIP_TLS_SERVER */
    /* Update the TLS-Server TX random index (Location in the TxBuffer where the random value is stored) */
    TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_SetTlsBufferTxServerRandomIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
      TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
  }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Mode == TCPIP_TLS_CLIENT */
    /* Update the TLS-Client TX random index (Location in the TxBuffer where the random value is stored) */
    TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_SetTlsBufferTxClientRandomIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
      TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_13) == TRUE)
    {
      /* When the connection supports 1.3 the userTimeStamp is not added to the ClientHello (see RFC8446 chapter 4.1.2).
       * The full 32 byte are filled with random bytes. */
      addUserTimeStamp = FALSE;
    }
#  endif
  }
# endif

  if (addUserTimeStamp == TRUE)                                                                                         /* PRQA S 2991, 2995 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
  {
    /* #10 Only in Tls 1.2: Add the GMT Unix userTimeStamp stamp */
    TcpIp_TlsHelloMsg_AddRandomStructureGetTime(TlsConIdx);
    /* Since the userTimeStamp is added the length of the random bytes is not the full 32, but 28 byte instead.
     * The GMT Unix userTimeStamp is added at Bytes 0-3, the random bytes are added at bytes 4-32. */
    randomLength = TCPIP_TLS_RANDOM_LEN - TCPIP_TLS_UNIXTIMESTAMP_LEN;
  }

  /* #20 Add the random bytes. */
  retVal = TcpIp_TlsHelloMsg_AddRandomStructureGetRandom(TlsConIdx, randomLength);                                      /* PRQA S 2986 */ /* MD_TCPIP_Rule2.2_2986 */

  return retVal;
} /* TcpIp_TlsHelloMsg_AddRandomStructure() */

/**********************************************************************************************************************
 *  TcpIp_TlsHelloMsg_AddRandomStructureGetTime
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
FUNC(void, TCPIP_CODE) TcpIp_TlsHelloMsg_AddRandomStructureGetTime(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsGetTimeCalloutFunctionType timeCalloutFunction = TcpIp_GetTimeCalloutFuncOfTlsConnection(TlsConIdx);
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType adHsWriteTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TCPIP_P2V(uint8) txBufferRandomTimePtr = TcpIp_GetAddrTlsBufferTx(adHsWriteTlsBufferTxIdx);
  uint32 userTimeStamp = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if a GetTimeCallout function is configured for this connection. */
  if (timeCalloutFunction != NULL_PTR)
  {
    /* #20 Get the userTimeStamp provided by the callout function. If it failed set the userTimeStamp to 0 for
       further processing and report the error. */
    if (timeCalloutFunction(&userTimeStamp) != E_OK)
    {
      /* Report the error to the user. */
      TcpIp_TlsUserErrorType userError;
      userError.FunctionId = TCPIP_TLS_FCTID_CLIENT_HSSTM_RANDOM_NUM_GET_TIME;
      userError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECT_TIME;
      userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

      TcpIp_TlsCoreError_ReportUserError(userError);

      /* If the callout function returns an error, reset the userTimeStamp to 0 and continue the handshake. */
      userTimeStamp = 0u;
    }
  }

  /* #30 Write the provided times to the next 4 Bytes. */
  IpBase_PutUint32(txBufferRandomTimePtr, 0, userTimeStamp);

  /* #40 Increment the write index by the consumed length (4 Byte). */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, (TCPIP_TLS_UNIXTIMESTAMP_LEN));

} /* TcpIp_TlsHelloMsg_AddRandomStructureGetTime() */

/**********************************************************************************************************************
 *  TcpIp_TlsHelloMsg_AddRandomStructureGetRandom
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsHelloMsg_AddRandomStructureGetRandom(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  uint32                                   RequiredRndLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType bufferWriteTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TCPIP_P2V(uint8) txBufferPtr = TcpIp_GetAddrTlsBufferTx(bufferWriteTlsBufferTxIdx);

  Std_ReturnType                csmRetVal;
  TcpIp_TlsFunctionIdType       apiId;

  uint32                        csmRandomLength  = RequiredRndLen;
  Std_ReturnType                retVal           = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Select the function Id depending on the connection mode. */

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
  {
    /* Mode == TCPIP_TLS_SERVER */
    apiId = TCPIP_TLS_FCTID_SERVER_HSSTM_PREPARE_SERVERHELLO;
  }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Mode == TCPIP_TLS_CLIENT */
    apiId = TCPIP_TLS_FCTID_CLIENT_HSSTM_PREPARE_CLIENTHELLO;
  }
# endif

  /* #20 Generate the random value and place it inside the TLS TxBuffer */
  csmRetVal = TCPIP_CSM_RandomGenerate(TcpIp_GetTlsRandomGenerateCsmJobId(),
    txBufferPtr, &csmRandomLength);

  /* #30 Check the return value from the CSM call and the length of the generated random value */
  if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, csmRandomLength, RequiredRndLen, apiId) == E_OK)
  {
    /* Random value successfully generated so increment the write index by the consumed length */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      (TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType)RequiredRndLen);

    retVal = E_OK;
  }
  else
  {
    /* CSM random generation failed, report error to the user */
    TcpIp_TlsUserErrorType userError;

    userError.FunctionId = apiId;
    userError.UserErrorId = TCPIP_TLS_ERRORID_CRYPTO_RANDOMGENERATE_FAILED;
    userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(userError);
  }

  return retVal;
} /* TcpIp_TlsHelloMsg_AddRandomStructureGetRandom() */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_ExtractReceivedExtensions
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_ExtractReceivedExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 ExtensionsLen,
  TcpIp_TlsBufferRxIterType MsgEndIdx,
  TCPIP_P2V(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  TCPIP_P2V(uint8) ReceivedExtensionCntPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint16 consumedExtensionLen = 0u;
  uint8 extensionListIter = 0u;
  Std_ReturnType retVal = E_NOT_OK;
  boolean stopProcessing = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over the TLS-RxBuffer until all extensions are consumed */
  while ((consumedExtensionLen < ExtensionsLen) && (stopProcessing != TRUE))
  {
    /* #20 Check if there is enough space in the list to add the next extension */
    if (extensionListIter < TCPIP_TLS_MAX_EXTENSION_LIST_LENGTH)
    {
      /* Check that we receive at least 4 bytes ( 2 bytes extension type + 2 bytes extension length) */
      if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
           (TCPIP_TLS_EXTENSION_TYPE_LEN + TCPIP_TLS_EXTENSION_LENGTH_LEN), MsgEndIdx))
      {
        /* #30 Add current extension to the list of all received extensions */
        /* Read Extension Type */
        ReceivedExtensionListPtr[extensionListIter].Type = IpBase_GetUint16(
          TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0u);
        TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);
        consumedExtensionLen += TCPIP_TLS_EXTENSION_TYPE_LEN;

        /* Read Extension Len */
        ReceivedExtensionListPtr[extensionListIter].Length = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(
          TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0u);
        TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);
        consumedExtensionLen += TCPIP_TLS_EXTENSION_LENGTH_LEN;

        /* Read Extension Data */
        ReceivedExtensionListPtr[extensionListIter].StartIdx = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
        TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, ReceivedExtensionListPtr[extensionListIter].Length);
        consumedExtensionLen += ReceivedExtensionListPtr[extensionListIter].Length;

        /* Check that the received length of this extension is still in range of the message */
        /* Start index of the extension + length of the extension must be smaller or equal the message end index */
        if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(ReceivedExtensionListPtr[extensionListIter].StartIdx,                       /* PRQA S 2995 2 */ /* MD_TcpIp_Tls_2995 */
          ReceivedExtensionListPtr[extensionListIter].Length, MsgEndIdx))
        {
          extensionListIter++;
        }
        else
        {
          /* Not sufficient space in buffer - skip the processing and return E_NOT_OK */
          stopProcessing = TRUE;
        }
      }
      else
      {
        /* Not sufficient space in buffer - skip the processing and return E_NOT_OK */
        stopProcessing = TRUE;
      }
    }
    else
    {
      /* Not enough space in extension list - skip the processing and return E_NOT_OK */
      stopProcessing = TRUE;
    }
  }

  /* Check if all extension data is consumed */
  if (ExtensionsLen != consumedExtensionLen)
  {
    /* #40 If there is unprocessed data or an invalid extension length - return E_NOT_OK */
    retVal = E_NOT_OK;
  }
  else
  {
    /* #50 Update the counter of the overall received extensions */
    *ReceivedExtensionCntPtr = extensionListIter;
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsMsg_ExtractReceivedExtensions() */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_CheckDuplicatedReceivedExtensions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_CheckDuplicatedReceivedExtensions(
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8 ReceivedExtensionCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 firstExtensionIter;
  uint8 secondExtensionIter;

  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Compare each element of the received extension list again each other */
  for (firstExtensionIter = 0u; firstExtensionIter < ReceivedExtensionCnt; firstExtensionIter++)
  {
    for (secondExtensionIter = firstExtensionIter + 1u; secondExtensionIter < ReceivedExtensionCnt; secondExtensionIter++)
    {
      /* Check if we receive the same extension type twice */
      /* No additional need to check the length or data of the extension */
      if (ReceivedExtensionListPtr[firstExtensionIter].Type == ReceivedExtensionListPtr[secondExtensionIter].Type)
      {
        /* #20 If same extension type is received twice - set retVal to E_NOT_OK */
        retVal = E_NOT_OK;
      }
    }
  }

  return retVal;
} /* TcpIp_TlsMsg_CheckDuplicatedReceivedExtensions() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerMsgValidateExtensionListForSourceMessageAndTlsVersion
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerMsgValidateExtensionListForSourceMessageAndTlsVersion(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8 ReceivedExtensionCnt,
  TcpIp_TlsMsgHandshakeType SourceMessage)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  uint8 rxExtensionIter;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case of Tls version 1.2 - check if extension is received in ServerHello */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (   (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
      && (SourceMessage != TCPIP_TLS_HSTYPE_SERVERHELLO))
  {
    /* According to RFC5246 Section 7.4.1.4., in TLS Version 1.2 extensions are only allowed in the hello messages.
     * Since this is a function to parse the server hello, it is sufficient to check if the SourceMessage is
     * a server hello message */
    retVal = E_NOT_OK;
  }
# endif

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  /* If Tls version is 1.2 and message is not server hello, do not continue checking - return E_NOT_OK */
  if (retVal == E_OK)
# endif
  {
    /* #20 Iterate over all received server extensions */
    for (rxExtensionIter = 0u; rxExtensionIter < ReceivedExtensionCnt; rxExtensionIter++)
    {
      /* Get the next received extension type and parse it depending on the type */
      uint16 currentReceivedExtensionType = ReceivedExtensionListPtr[rxExtensionIter].Type;

      /* #30 Check if specific extension is supported in active Tls version and is allowed in source message */
      retVal = TcpIp_TlsClientMsg_ServerMsgExtensionValidateSourceMessageAndTlsVersion(TlsConIdx,
        currentReceivedExtensionType, SourceMessage);
      if (retVal != E_OK)
      {
        /* Skip checking of all other received extensions */
        break;
      }
    }
  }
  return retVal;
} /* TcpIp_TlsClientMsg_ServerMsgValidateExtensionListForSourceMessageAndTlsVersion() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerMsgExtensionValidateSourceMessageAndTlsVersion
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
 */
/* PRQA S 6030 1 */ /* MD_TcpIp_TlsStatemachine_STCYC_6030 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerMsgExtensionValidateSourceMessageAndTlsVersion(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 CurrentReceivedExtensionType,
  TcpIp_TlsMsgHandshakeType SourceMessage
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  switch (CurrentReceivedExtensionType)
  {
    case TCPIP_TLS_EXTENSION_SUPPORTED_GROUPS:
    {
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      /* #10 In case of extension type elliptic_curves/supported_groups(10) - check source message */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif
      {
        if (SourceMessage == TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS)
        {
          /* The encrypted extensions message only exists in TLS version 1.3.
           * Servers are permitted to send this extension to the client
           * and the message needs to be parsed */
          retVal = E_OK;
        }
        else
        {
          /* In TLS 1.3 this extension is only allowed to be sent in the encrypted extension message.
           * If the message is contained in any other message, the handshake must be aborted with an
           * illegal_parameter(47) alert. */
          retVal = E_NOT_OK;
        }
      }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      else
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
      {
        /* According to RFC8422 Section 5.2 the extension is not allowed to be sent by the server in TLS Version 1.2:
         * RFC defines only one ec extension which MUST be received by the client which is ec_point_Formats (11).
         * Therefore the elliptic_curves(10) Supported Elliptic Curves Extension is not allowed to be sent by the server. */
        retVal = E_NOT_OK;
      }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      break;
    }
    case TCPIP_TLS_EXTENSION_EC_POINT_FORMAT:
    {
      /* #20 In case of extension type ec_point_formats(11) - check active TLS version */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      {
        /* According to RFC8446 Section 4.2.8.2. the extension is removed in TLS Version 1.3 */
        retVal = E_NOT_OK;
      }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      else
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
      {
        retVal = E_OK;
      }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      break;
    }
    case TCPIP_TLS_EXTENSION_SIGNATURE_ALGORITHMS:
    {
      /* #30 In case of extension type signature_algorithms(13) - return E_NOT_OK */
      /* RFC5246 - 7.4.1.4.1.  Signature Algorithms
         RFC8422 - 5.1.3.  The signature_algorithms Extension and EdDSA
         Servers MUST NOT send this extension. */
      retVal = E_NOT_OK;
      break;
    }
    case TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST:
    {
      /* #40 In case of extension type certificate_status_request(5) - check active TLS version and source message */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      {
        if (   (SourceMessage == TCPIP_TLS_HSTYPE_CERTIFICATE)
            || (SourceMessage == TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST))
        {
          retVal = E_OK;
        }
        else
        {
          /* Extension has been sent in the wrong server message */
          retVal = E_NOT_OK;
        }
      }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      else
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
      {
        retVal = E_OK;
      }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      break;
    }
    case TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION:
    {
      /* #50 In case of extension type trusted_ca_indication(3) - check active TLS version and source message */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      {
        /* This extension is not used in TLS 1.3, so it may not appear in any received message. */
        retVal = E_NOT_OK;
      }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      else
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
      {
        retVal = E_OK;
      }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      break;
    }
    case TCPIP_TLS_EXTENSION_SERVER_NAME_INDICATION:
    {
      /* #60 In case of extension type server_name(0) - check active TLS version and source message */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      {
        if (SourceMessage == TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS)
        {
          retVal = E_OK;
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      else
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
      {
        retVal = E_OK;
      }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      break;
    }
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    case TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS:
    {
      /* #70 In case of extension type supported_versions(43) - check active TLS version and source message */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      {
        if (   (SourceMessage == TCPIP_TLS_HSTYPE_SERVERHELLO)
            || (SourceMessage == TCPIP_TLS_HSTYPE_HELLOREQUEST))
        {
          retVal = E_OK;
        }
        else
        {
          /* Extension is not in ServerHello or HelloRetryRequest */
          retVal = E_NOT_OK;
        }
      }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      else
      {
        /* Extension is not supported in TLS Version 1.2 */
        retVal = E_NOT_OK;
      }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      break;
    }
    case TCPIP_TLS_EXTENSION_KEY_SHARE:
    {
      /* #80 In case of extension type key_share(51) - check active TLS version and source message */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      {
        if (   (SourceMessage == TCPIP_TLS_HSTYPE_SERVERHELLO)
            || (SourceMessage == TCPIP_TLS_HSTYPE_HELLOREQUEST))
        {
          retVal = E_OK;
        }
        else
        {
          /* Extension is not in ServerHello or HelloRetryRequest */
          retVal = E_NOT_OK;
        }
      }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      else
      {
        /* Extension is not supported in TLS Version 1.2 */
        retVal = E_NOT_OK;
      }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      break;
    }
    case TCPIP_TLS_EXTENSION_PRE_SHARED_KEY:
    {
      /* #90 In case of extension type pre_shared_key(41) - check active TLS version and source message */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      {
        if (SourceMessage == TCPIP_TLS_HSTYPE_SERVERHELLO)
        {
          retVal = E_OK;
        }
        else
        {
          /* Extension is not in ServerHello */
          retVal = E_NOT_OK;
        }
      }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      else
      {
        /* Extension is not supported in TLS Version 1.2 */
        retVal = E_NOT_OK;
      }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      break;
    }
    case TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES:
    {
      /* #100 In case of extension type certificate_authorities(47) - check active TLS version and source message */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      {
        if (SourceMessage == TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST)
        {
          retVal = E_OK;
        }
        else
        {
          /* Extension has been sent in the wrong server message */
          retVal = E_NOT_OK;
        }
      }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      else
      {
        retVal = E_NOT_OK;
      }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      break;
    }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
    default:
    {
      /* This case should never be executed since we already checked that every received extension was sent in the
       * ClientHello and therefore, should also be supported. */
      retVal = E_NOT_OK;
      break;
    }
  }

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_OFF)
  TCPIP_DUMMY_STATEMENT_CONST(SourceMessage);                                                                           /* PRQA S 1338, 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
# endif
# if ((TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_OFF) || (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_OFF))
  TCPIP_DUMMY_STATEMENT_CONST(TlsConIdx);                                                                               /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}/* TcpIp_TlsClientMsg_ServerMsgExtensionValidateSourceMessageAndTlsVersion() */

/**********************************************************************************************************************
 *  TcpIp_TlsHs_CheckExpectedMsgLen
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsHs_CheckExpectedMsgLen(
  CONST(uint32, AUTOMATIC) MsgLen,
  CONST(uint32, AUTOMATIC) ExpectedMsgLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that the received message length has the minimum expected message length */
  if (MsgLen >= ExpectedMsgLen)
  {
   retVal = E_OK;
  }
  else
  {
    /* #20 otherwise, nothing to do - error handling in caller function */
    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsHs_CheckExpectedMsgLen() */

/**********************************************************************************************************************
 *  TcpIp_TlsHsStm_ErrorHandlingAndStateTransition
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsHsStm_ErrorHandlingAndStateTransition(
  TcpIp_TlsConnectionIterType      TlsConIdx,
  Std_ReturnType                   IntRetVal,
  TcpIp_TlsHandshakeState          NextHsState)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the parameter IntRetVal indicates an occurred error */
  if (IntRetVal == E_OK)
  {
    /* #20 Parameter indicates no error in previous function, set the TLS handshake state to the next state */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, NextHsState);
  }
  else
  {
    /* #30 Parameter indicates an error in previous function, report the error and trigger the transmit of a TLS alert */
    TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
  }
} /* TcpIp_TlsHsStm_ErrorHandlingAndStateTransition() */

/**********************************************************************************************************************
 *  TcpIp_TlsHsStm_HandlesUnexpectedHsInformation
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
FUNC(void, TCPIP_CODE) TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
   /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorType hsUserError;
  TcpIp_TlsAlertLevelType alertLevel;
  TcpIp_TlsAlertDescriptionType alertDescription;

  /* ----- Implementation ----------------------------------------------- */

   /* #10 set the corresponding error id */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
  {
    /* Mode == TCPIP_TLS_SERVER */
    hsUserError.FunctionId  = TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_HS_MSG;
  }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Mode == TCPIP_TLS_CLIENT */
    hsUserError.FunctionId  = TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_HS_MSG;
  }
# endif

  hsUserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTHSMSG;
  hsUserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

  /* #20 Report the error to the user */
  TcpIp_TlsCoreError_ReportUserError(hsUserError);

  /* #30 Set the corresponding alert level and description */
  alertLevel       = TCPIP_TLS_ALERT_LEVEL_FATAL;
  alertDescription = TCPIP_TLS_ALERT_DESC_DECODE_ERROR;

  /* #40 Trigger the transmission of the occurred alert */
  TcpIp_TlsCoreAlert_Set(TlsConIdx, alertLevel, alertDescription);

  /* #50 Change the state to HANDSHAKE_ABORT */
  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);

} /* TcpIp_TlsHsStm_HandlesUnexpectedHsInformation() */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_HelloMsgGetVersionNr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_HelloMsgGetVersionNr(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx  = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint8                         rcvdMajorVersNr;
  uint8                         rcvdMinorVersNr;
  TcpIp_TlsUserErrorIdType      internalUserError = TCPIP_TLS_ERRORID_NOT_SET;                                          /* PRQA S 2981 */ /* MD_TCPIP_Rule2.2_RedundantAssignment */
  Std_ReturnType                retVal            = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the received version numbers of the client_hello message */
  rcvdMajorVersNr = TcpIp_GetTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
  /* Let the read index point to the minor version */
  TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_MAJORVERS_LEN);

  rcvdMinorVersNr = TcpIp_GetTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
  /* Let the read index point to the next field */
  TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_MINORVERS_LEN);

  /* RFC5246 p. 87 - E.1.  Compatibility with TLS 1.0/1.1 and SSL 3.0 */
  /* #20 Check that the received major version number matches */
  if (rcvdMajorVersNr == TCPIP_TLS_PROTOCOL_MAJOR_VERSION_3)
  {
    /* #30 If the major Version number matches, check that the received minor version number matches */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
    {
      /* Mode == TCPIP_TLS_SERVER */
      /* Received TLS-Client minor version number MUST at least support our minor number */
      if (rcvdMinorVersNr >= TCPIP_TLS_PROTOCOL_MINOR_VERSION_3)
      {
        /* Version numbers OK, reset the error value */
        retVal = E_OK;
      }
      else
      {
        /* Received minor version number does NOT match with our minor number, set user error */
        internalUserError = TCPIP_TLS_ERRORID_CTHS_INCORRECTMINORVERSION;
      }
    }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    {
      /* Mode == TCPIP_TLS_CLIENT */

      /* In TLS 1.2 received TLS-Server minor version number MUST exactly support our minor version.
       * We only support TLS 1.2 and/or TLS 1.3, and for both versions the minor version must be the same.
       * In TLS 1.3 this is called the legacy_version and MUST be set to 0x0303 (RFC8446 chapter 4.1.3). */
      if (rcvdMinorVersNr == TCPIP_TLS_PROTOCOL_MINOR_VERSION_3)
      {
        /* Version numbers OK, reset the error value */
        retVal = E_OK;
      }
      else
      {
        /* Received minor version number does NOT match with our minor number, set user error */
        internalUserError = TCPIP_TLS_ERRORID_CTHS_INCORRECTMINORVERSION;
      }
    }
# endif
  }
  else
  {
    /* Received major version number does NOT match with our major number, set user error */
    internalUserError = TCPIP_TLS_ERRORID_CTHS_INCORRECTMAJORVERSION;
  }

  /* #40 in case of an mismatch with the version numbers, report an error to the user and trigger an TLS alert */
  if (retVal != E_OK)
  {

    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId = TCPIP_TLS_USERERROR_PARSEHELLO(TlsConIdx);
    UserError.UserErrorId = internalUserError;
    UserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    /* Trigger alert protocol_version in case of invalid version numbers */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_PROT_VERSION);
  }

  return retVal;
} /* TcpIp_TlsMsg_HelloMsgGetVersionNr() */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_HelloMsgGetAndCheckRandom
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_HelloMsgGetAndCheckRandom(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  TcpIp_TlsBufferMgmtDynIterType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the start index of the received random value, depending on the connection mode (Server/Client) */

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
  {
    /* Mode == TCPIP_TLS_SERVER */
    TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_SetTlsBufferRxClientRandomIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
      TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

    /* In case of TLS server - no checks need to be done */
  }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Mode == TCPIP_TLS_CLIENT */
    TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_SetTlsBufferRxServerRandomIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
      TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

    /* #20 In case our Client did offer 1.3 in the ClientHello and the Server chose Tls version 1.2 - check for downgrade values */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    if (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_13) == TRUE)
    {
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
      {
        /* #30 Check ServerRandom's last 8 bytes for the downgrade value to lower TLS versions */
        retVal = TcpIp_Tls13ClientMsg_ServerHelloMsgCheckRandomForDowngrade(TlsConIdx);
      }
    }
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#   endif
    {
      /* #40 Check ServerRandom for the special value of the HelloRetryRequest */
      if (TcpIp_Tls13ClientMsg_ServerHelloMsgCheckRandomForHelloRetryRequest(TlsConIdx) == TRUE)
      {
        /* We do not support HelloRetryRequests in our implementation. Therefore we abort the handshake with an
         * unexpected_message alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
        retVal = E_NOT_OK;
      }
    }
#  endif
  }
# endif

  TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_RANDOM_LEN);

  return retVal;
} /* TcpIp_TlsMsg_HelloMsgGetAndCheckRandom() */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_HelloMsgGetAndCheckSessionId
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
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_HelloMsgGetAndCheckSessionId(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) HelloEndIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
    (TcpIp_TlsBufferRxIterType)TCPIP_TLS_SESSIONIDLEN_LEN, HelloEndIdx))
  {
    /* #10 ReadIdx points to the SessionIdLen field */
    CONST(uint8, AUTOMATIC) sessionIdLen
      = TcpIp_GetTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_SESSIONIDLEN_LEN);

    /* #20 Check the max length of the received session id, and check that the received session length is in range of the TLS RxBuffer */
    if (   (sessionIdLen <= TCPIP_TLS_SESSIONIDMAX_LEN)
        && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),        /* PRQA S 3415, 2995 2 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly, MD_TcpIp_Tls_2995 */
                                            (TcpIp_TlsBufferRxIterType)sessionIdLen, HelloEndIdx)))
    {
      /* #30 Store the start index of the received Session Id depending on the connection mode */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
      {
        /* In case of Tls Server - no checks need to be done */
        TcpIp_TlsServerMsg_ClientHelloStoreSessionIdBufferIndex(TlsConIdx, sessionIdLen);
        retVal = E_OK;
      }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
      else
#  endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
      {
        /* In case of Tls Client - check that received session Id is valid */
        retVal = TcpIp_TlsClientMsg_ServerHelloCheckSessionIdAndStoreBufferIndex(TlsConIdx, sessionIdLen);
      }

# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
      /* #40 Session ID currently not supported by this implementation - skip the actual session ID length in the received buffer */
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, sessionIdLen);
    }
    else
    {
      /* #50 Report an error to the user */
      TcpIp_TlsUserErrorType UserError;
      UserError.FunctionId  = TCPIP_TLS_USERERROR_PARSEHELLO(TlsConIdx);
      UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTSESSIONID;
      UserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

      TcpIp_TlsCoreError_ReportUserError(UserError);

      /* retVal is already E_NOT_OK */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }

  return retVal;
} /* TcpIp_TlsMsg_HelloMsgGetAndCheckSessionId() */
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsMsg_CheckIfCipherSuiteIdMatches
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_MSR_STMIF */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_CheckIfCipherSuiteIdMatches(
  TcpIp_TlsConnectionIterType                                    TlsConIdx,
  CONST(TcpIp_TlsCipherDataType, AUTOMATIC)                      CipherSuiteSelected)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_TlsCipherWorkerIndIterType tlsCipherWorkerIndIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured cipher workers and check if their cipher suite matches with the given one */
  for (tlsCipherWorkerIndIdx = TcpIp_GetTlsCipherWorkerIndStartIdxOfTlsConnection(TlsConIdx);
       tlsCipherWorkerIndIdx < TcpIp_GetTlsCipherWorkerIndEndIdxOfTlsConnection(TlsConIdx);
       tlsCipherWorkerIndIdx++)
  {
    TcpIp_TlsCipherWorkerIndType tlsCipherWorkerIdx
      = TcpIp_GetTlsCipherWorkerInd(tlsCipherWorkerIndIdx);
    TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
      = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
    TcpIp_CipherSuiteIdOfTlsCipherDefinitionType cipherSuiteId
      = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx);

    /* Only check if cipher suite is contained in working set if callout is configured */
    if (   (TcpIp_IsTlsUseChangeableCipherCallbackOfTlsConnection(TlsConIdx) == FALSE)
        || (TcpIp_TlsClient_IsCipherSuiteInWorkingSet(TlsConIdx, cipherSuiteId) == TRUE))                               /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
    {
      /* #20 Only check for cipher worker in the working set */
      if (cipherSuiteId == CipherSuiteSelected)
      {
        /* #30 Found matching cipher suite. */
#  if ((TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) && (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON))
        TcpIp_TlsVersionType cipherSuiteTlsVersion
          = TcpIp_GetTlsVersionOfTlsCipherDefinition(tlsCipherDefinitionIdx);
        /* Tls version of CipherSuite must be equal to active Tls version */
        if (cipherSuiteTlsVersion == TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx))
#  endif
        {
          /* #40 Tls version matches, return E_OK. */
          /* Since there can only be one PSK handshake configured
           * this cipherworker must reference the handshake used by the peer. This might not be the case with
           * an ECC handshake where multiple cipherworkers might reference the received cipher suite
           * but not all of them might reference the handshake the peer wants to perform.
           * For example there are two cipherworkers referencing the received ciphersuite,
           * one cipherworker references a handshake with the Secp256 curve,
           * the other cipherworker references a handshake with the Secp521 curve.
           * If we already select one of them, we might choose the one with the Secp256,
           * but we receive a Secp521 certificate later.
           * Therefore set the active cipher worker to the current cipher worker only when it's key exchange is PSK. */
          if (TcpIp_TlsCoreUtil_ReturnCipherSpecificKeyExchangeMethod(cipherSuiteId)
            == TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN)
          {
            TcpIp_SetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx, tlsCipherWorkerIdx);
          }
          retVal = E_OK;
          break;
        }
#  if ((TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) && (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON))
        else
        {
          /* If the active version is 1.2 when both versions are possible,
           * the server did not send a supported_versions extension.
           * Since we received a ciphersuite which was included in the working set
           * but does not match the active version, we received a 1.3 ciphersuite.
           * To establish a 1.3 handshake the supported_versions extension MUST be send (see RFC8446 chapter 4.2.1).
           * It was therefore decided that a missing_extension alert is fitting here (see RFC8446 chapter 6.2). */
          if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
          {
            TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_MISSING_EXT);
          } /* else - 1.2 ciphersuite received even though supported_versions extension with 1.3 parameter was received
             * retVal already E_NOT_OK, illegal_parameter alert is set in invoking function. */
        }
#  endif
      }
    }
  }

  return retVal;
} /* TcpIp_TlsMsg_CheckIfCipherSuiteIdMatches() */


/**********************************************************************************************************************
 *  TcpIp_TlsMsg_SelectDefaultHandshakeReference
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsMsg_SelectDefaultHandshakeReference(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  if (activeTlsCipherWorkerIdx < TcpIp_GetSizeOfTlsCipherWorker())
  {
    TcpIp_TlsHandshakeIndStartIdxOfTlsCipherWorkerType handshakeStartTlsHandshakeIndIdx =
      TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx);

    TcpIp_TlsHandshakeIndType handshakeStartIdx = TcpIp_GetTlsHandshakeInd(handshakeStartTlsHandshakeIndIdx);

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Select the handshake start index as active one */
    TcpIp_SetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx, handshakeStartIdx);
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsMsg_SelectDefaultHandshakeReference() */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_SelectDefaultPskIdentity
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsMsg_SelectDefaultPskIdentity(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsPskIdentityDefaultIdxOfTlsConnectionType tlsPskIdentityDefaultIdx = TcpIp_GetTlsPskIdentityDefaultIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the configured default PSK Identity as active */
  TcpIp_SetTlsPskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx, tlsPskIdentityDefaultIdx);


} /* TcpIp_TlsMsg_SelectDefaultPskIdentity() */
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_CheckMsgForRemainingData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_CheckMsgForRemainingData(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC)  MsgEndIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the current read position is equal to the end position */
  if (TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) == MsgEndIdx)
  {
    /* #20 when the indexes are equal, there is no remaining data. Return E_OK */
    retVal = E_OK;
  }
  else
  {
    /* #30 If the indexes are not equal there is remaining data - Report an error to the user */
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId = TCPIP_TLS_USERERROR_PARSEHELLO(TlsConIdx);
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_UNEXPECTEDMSGLEN;
    UserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);
    retVal = E_NOT_OK;
  }
  return retVal;
} /* TcpIp_TlsMsg_CheckMsgForRemainingData() */

/**********************************************************************************************************************
 *  TcpIp_VIsPortUsedByAsrTls
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_VIsPortUsedByAsrTls(
  uint16                    Port,
  TcpIp_TlsConnectionMode   Mode)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Iterate over all configured TLS connections. */
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
  {
    /* #20 Check if the configured port is equivalent to the given Port */
    if (   (TcpIp_GetPortOfTlsConnection(tlsConIdx) == Port)                                                            /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
        && (TcpIp_GetModeOfTlsConnection(tlsConIdx) == Mode))
    {
      /* #30 if valid, return TRUE and exit the loop */
      retVal = TRUE;
      break;
    }
  }

  return retVal;
} /* TcpIp_VIsPortUsedByAsrTls() */

# define TCPIP_STOP_SEC_CODE
# include "TcpIp_MemMap.h"                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COVERAGE JUSTIFICATIONS
 *********************************************************************************************************************/
#endif /*(TCPIP_SUPPORT_ASRTLS == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: TcpIp_TlsPriv.c
 *********************************************************************************************************************/
