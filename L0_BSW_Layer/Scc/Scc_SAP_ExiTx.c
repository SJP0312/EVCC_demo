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
/*!        \file  Scc_SAP_ExiTx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements the shared SupportedAppProtocol that is used in Vehicle 2 Grid communication according
 *                to the specifications DIN SPEC 70121, ISO/IEC 15118-2 and ISO/IEC 15118-20.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_SAP_EXITX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_SAP_Exi.h"
#include "Scc_SAP_TimerCfg.h"
#include "Scc_SAP_InterfaceCfg.h"
#include "Scc_SDP.h"
#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_BufferPool.h"
#include "Scc_Core_Channel.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

#if (defined(SCC_SCHEMA_DIN) && (SCC_SCHEMA_DIN  != 0u))
# include "Scc_DIN70121_Exi.h"
#endif

#if (defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO  != 0u))
# include "Scc_ISO15118_2_Exi.h"
#endif

#if (defined(SCC_SCHEMA_ISO_20AC) && (SCC_SCHEMA_ISO_20AC  != 0u))
# include "Scc_ISO15118_20AC_Exi.h"
#endif

#if (defined(SCC_SCHEMA_ISO_20DC) && (SCC_SCHEMA_ISO_20DC  != 0u))
# include "Scc_ISO15118_20DC_Exi.h"
#endif

#if (defined(SCC_SCHEMA_ISO_20WPT) && (SCC_SCHEMA_ISO_20WPT  != 0u))
# include "Scc_ISO15118_20WPT_Exi.h"
#endif

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
# include "Scc_ISO15118_20ACDP_Exi.h"
#endif

#if (defined(SCC_SCHEMA_OPP_CHARGE) && (SCC_SCHEMA_OPP_CHARGE  != 0u))
# include "Scc_OppCharge_Exi.h"
#endif

#include "Exi.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_SAP_EXITX_PRIORANGE_MIN ( 1u) /* [V2G-DC-221], [V2G2-167], [V2G20-167] */
#define SCC_SAP_EXITX_PRIORANGE_MAX (20u) /* [V2G-DC-221], [V2G2-167], [V2G20-167] */

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/

/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Variable to manage the supported app protocol related information */
SCC_LOCAL VAR(Scc_SAP_ExiTx_WorkspaceStructType, SCC_VAR_NOINIT)  Scc_SAP_ExiTxWs;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_BuildReqMessage
 *********************************************************************************************************************/
/*! \brief          Builds the SAP request message based on the passed supported schema list
 *  \details        -
 *  \param[in]      SchemaListPtr           A list of supported schemas. Must not be NULL_PTR
 *  \param[in,out]  TxMsgWSPtr              Workspace that is used to assemble the message. Must not be NULL_PTR
 *  \return         Scc_ReturnType_OK       Message was built
 *  \return         Scc_ReturnType_Not_OK   An error occurred during message build. Message is not build
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SAP_ExiTx_BuildReqMessage(
  P2CONST(Scc_SAP_SchemaListStructType, AUTOMATIC, SCC_APPL_DATA) SchemaListPtr,
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_BuildReqMessage_CreateBaseMessage
 *********************************************************************************************************************/
/*! \brief          Builds the base SAP request message.
 *  \details        -
 *  \param[in,out]  TxMsgWSPtr              Workspace that is used to assemble the message. Must not be NULL_PTR
 *  \param[out]     BodyPtr                 Pointer which stores the created message.
 *  \return         Scc_ReturnType_OK       Message was build
 *  \return         Scc_ReturnType_Not_OK   An error occurred during message build. Message is not build.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SAP_ExiTx_BuildReqMessage_CreateBaseMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr,
  P2VAR(Exi_SAP_supportedAppProtocolReqType*, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr);

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_BuildReqMessage_ProcessEntry
 *********************************************************************************************************************/
/*! \brief          Process a SAP entry.
 *  \details        Creates the protocol namespace and dispatches the creation to schema specific APIs.
 *  \param[in,out]  TxMsgWSPtr              Workspace that is used to assemble the message. Must not be NULL_PTR.
 *  \param[in]      EntryToProcessPtr       Pointer to the entry that should be set in the SAP entry.
 *  \param[in,out]  AppProtocolEntryPtr     Pointer to the entry that should be processed.
 *  \return         Scc_ReturnType_OK       Entry was build.
 *  \return         Scc_ReturnType_Not_OK   An error occurred during build.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SAP_ExiTx_BuildReqMessage_ProcessEntry(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr,
  P2CONST(Scc_SAP_SchemaInfoStructType, AUTOMATIC, SCC_VAR_NOINIT) EntryToProcessPtr,
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_VAR_NOINIT) AppProtocolEntryPtr);

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_CreateDefaultList
 *********************************************************************************************************************/
/*! \brief          Builds the default list that Scc wants to transmit in the SAP request message
 *  \details        -
 *  \param[in,out]  SchemaListPtr      Pointer to a list that is going to be build. Must not be NULL_PTR
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_SAP_ExiTx_CreateDefaultList(
  P2VAR(Scc_SAP_SchemaListStructType, AUTOMATIC, SCC_APPL_DATA) SchemaListPtr);

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_CheckSchemaList
 *********************************************************************************************************************/
/*! \brief          Check if the passed list contains invalid entries
 *  \details        At least one entry must be present to consider the list as valid. The schema dependencies
 *                  are not checked by this function. It is only checked if the SchemaIds and priorities are
 *                  valid according to their value ranges.
 *  \param[in,out]  SchemaListPtr      A schema list to be checked. Must not be NULL_PTR
 *  \return         Scc_ReturnType_OK      List is ok
 *  \return         Scc_ReturnType_Not_OK  List is not ok (Containing errorneous entries or no entries at all)
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SAP_ExiTx_CheckSchemaList(
  P2CONST(Scc_SAP_SchemaListStructType, AUTOMATIC, SCC_APPL_DATA) SchemaListPtr);



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_SAP_ExiTx_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset the state of the Tx path */
  Scc_SAP_ExiTxWs.State = Scc_SAP_ExiTx_StateCreateDefaultList;
}

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_PrepareSupportedAppProtocolReq
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
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_SAP_ExiTx_PrepareSupportedAppProtocolReq(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_Pending;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the default list shall be created */
  if (Scc_SAP_ExiTxWs.State == Scc_SAP_ExiTx_StateCreateDefaultList)
  {
    /* [V2G-DC-220], [V2G2-166], [V2G20-166] */
    /* #20 Create the default list */
    Scc_SAP_ExiTx_CreateDefaultList(&Scc_SAP_ExiTxWs.SupportedSchemaList);
    /* #30 Proceed with list propagation */
    Scc_SAP_ExiTxWs.State = Scc_SAP_ExiTx_StatePropagateList;
  }

  /* #40 Check if the list shall be propagated */
  if (Scc_SAP_ExiTxWs.State == Scc_SAP_ExiTx_StatePropagateList)
  {
    boolean applPending = FALSE;

    /* #50 Propagate list to configured callout */
    Scc_SAP_InterfaceCfg_Get_SAPSchemaList(&Scc_SAP_ExiTxWs.SupportedSchemaList, &applPending);

    /* #60 Check if configured callout is pending */
    if (applPending == FALSE)
    {
      /* #70 No: */
      /* #80 Check if the changed list is still valid */
      retVal = Scc_SAP_ExiTx_CheckSchemaList(&Scc_SAP_ExiTxWs.SupportedSchemaList);
      if (retVal == Scc_ReturnType_OK)
      {
        /* #90 Proceed with building the message */
        Scc_SAP_ExiTxWs.State = Scc_SAP_ExiTx_StateBuildReqMessage;
      }
      /* #100 Otherwise */
      else
      {
        /* #110 Reset state to create the default list */
        Scc_SAP_ExiTxWs.State = Scc_SAP_ExiTx_StateCreateDefaultList;
        /* #120 Report an error indicating the invalid schema list provided by configured callout */
        Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Common_SupportedAppProtocolReqUnsupportedForcedSchema);
      }
    }
  }

  /* #130 Check if the request message shall be build */
  if (Scc_SAP_ExiTxWs.State == Scc_SAP_ExiTx_StateBuildReqMessage)
  {
    /* [V2G-DC-221], [V2G2-167], [V2G20-167] */
    /* #140 Build the request message based on list */
    retVal = Scc_SAP_ExiTx_BuildReqMessage(&Scc_SAP_ExiTxWs.SupportedSchemaList, TxMsgWSPtr);

    /* #150 Reset state to create the default list */
    Scc_SAP_ExiTxWs.State = Scc_SAP_ExiTx_StateCreateDefaultList;

    /* #160 Check if the message was built successful */
    if (retVal == Scc_ReturnType_OK)
    {
      /* [V2G-DC-359], [V2G2-436], [V2G20-436] */
      /* #170 Start the timeout counter */
      Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_SAP_TimerCfg_Get_SupportedAppProtocolMessageTimeout();
    }
  }

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_ChosenSchemaSupported
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
FUNC(boolean, SCC_STATIC_CODE) Scc_SAP_ExiTx_ChosenSchemaSupported(
  Scc_SAPSchemaIDType ChosenSAPSchema)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;
  uint8_least listIdx;
  boolean continueSearch;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each list entry of the supported schema list that was sent to EVSE */
  for (listIdx = 0; listIdx < (uint8_least)(SCC_SCHEMALIST_SIZE); listIdx++)
  {
    continueSearch = FALSE;

    /* #20 Check if the list is terminated by None */
    if (Scc_SAP_ExiTxWs.SupportedSchemaList.SchemaList[listIdx].Schema == Scc_SAPSchemaIDs_None)
    {
      /* #30 End of list found */
    }
    /* #40 Check if the the passed schema matches the current list entry */
    else if (Scc_SAP_ExiTxWs.SupportedSchemaList.SchemaList[listIdx].Schema == ChosenSAPSchema)
    {
      /* #50 Set return value to TRUE */
      retVal = TRUE;
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Continue the search */
      continueSearch = TRUE;
    }

    /* #80 Check if the search should not be continued */
    if (continueSearch == FALSE)
    {
      /* #90 Stop the search */
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_CreateDefaultList
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
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_SAP_ExiTx_CreateDefaultList(
  P2VAR(Scc_SAP_SchemaListStructType, AUTOMATIC, SCC_APPL_DATA) SchemaListPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 schemaIdx = 0u;
  Scc_SDPSecurityType sdpSecurity = Scc_SDP_Rx_GetSecurity();
  Scc_SDPPhysComLayerType physComLayer = Scc_SDPPhysComLayer_PLC;
#if (defined SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)
  TcpIp_TlsVersionType tlsVersion =  Scc_Priv_TLSParamGetTlsVersionUsed();
#endif /* SCC_ENABLE_TLS */

  /* ----- Implementation ----------------------------------------------- */
#if ( (defined SCC_WIRELESS_SDP) && (SCC_WIRELESS_SDP == STD_ON) )
  Scc_Core_InterfaceCfg_Get_PhysicalLayerTypeRx(&physComLayer);
#endif /* SCC_WIRELESS_SDP */

  switch(physComLayer)
  {
#if ( (defined SCC_WIRELESS_SDP) && (SCC_WIRELESS_SDP == STD_ON) )
    /* #10 If SCC_WIRELESS_SDP enabled: Check if physical layer type is set to 'wireless'. */
    case Scc_SDPPhysComLayer_Wireless:
    {
       /* #20 Check if Tls was set in SDP response and TLS version matches required version */
      if (   (sdpSecurity == Scc_SDPSecurity_Tls)
          && (tlsVersion == TCPIP_TLSVERSION_13) )
      {
# if (( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 ))
        /* #30 If SCC_SCHEMA_ISO_20WPT is enabled: Add ISO15118-20WPT to schema list */
        SchemaListPtr->SchemaList[schemaIdx].Schema = Scc_SAPSchemaIDs_ISO15118_20WPT;
        SchemaListPtr->SchemaList[schemaIdx].Priority = SCC_SCHEMA_ISO_20WPT;
        schemaIdx++;
# endif /* SCC_SCHEMA_ISO_20WPT */
# if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
        /* #40 If SCC_SCHEMA_ISO_20ACDP is enabled: Add ISO15118-20ACDP to schema list */
        SchemaListPtr->SchemaList[schemaIdx].Schema = Scc_SAPSchemaIDs_ISO15118_20ACDP;
        SchemaListPtr->SchemaList[schemaIdx].Priority = SCC_SCHEMA_ISO_20ACDP;
        schemaIdx++;
# endif /* SCC_SCHEMA_ISO_20ACDP */
      }
      break;
    }
#endif /* SCC_WIRELESS_SDP */
#if (  (( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )) \
    || (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )) \
    || (( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0 )) \
    ||((   (( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )) || (( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 ))) \
        && (( defined SCC_ENABLE_TLS ) && ( SCC_ENABLE_TLS == STD_ON ))))
    /* #50 If PLC based schemas are supported. Check if physical layer type is set to 'PLC'. */
    case Scc_SDPPhysComLayer_PLC:
    {
# if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
      /* [V2G-DC-CharIN-043]: EV shall not send an "AppProtocol" element referring to DIN in
       * SupportedAppProtocolReq if a TLS connection is established. */
      /* [V2G-DC-CharIN-045]: EV shall send the "AppProtocol" element referring to DIN as first
       * element in the list.*/
      /* #60 If SCC_SCHEMA_DIN enabled: Check if SDP indicates no security */
      if (sdpSecurity == Scc_SDPSecurity_None)
      {
        /* #70 Then add DIN70121 to schema list */
        SchemaListPtr->SchemaList[schemaIdx].Schema = Scc_SAPSchemaIDs_DIN;
        SchemaListPtr->SchemaList[schemaIdx].Priority = SCC_SCHEMA_DIN;
        schemaIdx++;
      }
# endif /* SCC_SCHEMA_DIN */

# if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
      /* #80 If SCC_SCHEMA_ISO enabled: Check if Security is enabled but TLS-Version does not match required version */
#  if ( defined SCC_ENABLE_TLS ) && ( SCC_ENABLE_TLS == STD_ON )
      if (   ((sdpSecurity == Scc_SDPSecurity_Tls) && (tlsVersion == TCPIP_TLSVERSION_12))
          || (sdpSecurity == Scc_SDPSecurity_None) )
#  endif /* SCC_ENABLE_TLS */
      {
        /* #90 Add ISO15118-2 to schema list */
        SchemaListPtr->SchemaList[schemaIdx].Schema = Scc_SAPSchemaIDs_ISO15118_2;
        SchemaListPtr->SchemaList[schemaIdx].Priority = SCC_SCHEMA_ISO;
        schemaIdx++;
      }
# endif /* SCC_SCHEMA_ISO */

# if ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0 )
      /* #100 If SCC_SCHEMA_OPP_CHARGE enabled: Check if no SDP security is set. */
      if (sdpSecurity == Scc_SDPSecurity_None)
      {
        /* OppCharge restricts Tls and certificate usage */
        /* #110 Then add OppCharge to schema list. */
        SchemaListPtr->SchemaList[schemaIdx].Schema = Scc_SAPSchemaIDs_OppCharge;
        SchemaListPtr->SchemaList[schemaIdx].Priority = SCC_SCHEMA_OPP_CHARGE;
        schemaIdx++;
      }
# endif /* SCC_SCHEMA_OPP_CHARGE */

# if (  ((( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )) || (( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 ))) \
     && (( defined SCC_ENABLE_TLS ) && ( SCC_ENABLE_TLS == STD_ON )) )
      /* [V2G20-1805], [V2G20-1237] */
      /* #120 If SCC_SCHEMA_ISO_20 enabled: Check that Tls was set in SDP response and TLS version matches required version */
      if (   (sdpSecurity == Scc_SDPSecurity_Tls)
          && (tlsVersion == TCPIP_TLSVERSION_13) )
      {
#  if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
        /* #130 If SCC_SCHEMA_ISO_20AC enabled: Add ISO15118-20AC to schema list */
        SchemaListPtr->SchemaList[schemaIdx].Schema = Scc_SAPSchemaIDs_ISO15118_20AC;
        SchemaListPtr->SchemaList[schemaIdx].Priority = SCC_SCHEMA_ISO_20AC;
        schemaIdx++;
#  endif /* SCC_SCHEMA_ISO_20AC */

#  if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
        /* #140 If SCC_SCHEMA_ISO_20DC enabled: Add ISO15118-20DC to schema list */
        SchemaListPtr->SchemaList[schemaIdx].Schema = Scc_SAPSchemaIDs_ISO15118_20DC;
        SchemaListPtr->SchemaList[schemaIdx].Priority = SCC_SCHEMA_ISO_20DC;
        schemaIdx++;
#  endif /* SCC_SCHEMA_ISO_20DC */
      }
# endif /* (SCC_SCHEMA_ISO_20AC || SCC_SCHEMA_ISO_20DC) && SCC_ENABLE_TLS) */
      break;
    }
#endif /* SCC_SCHEMA_DIN || SCC_SCHEMA_ISO || SCC_SCHEMA_OPP_CHARGE || ((SCC_SCHEMA_ISO_20AC || SCC_SCHEMA_ISO_20DC) && SCC_ENABLE_TLS) */
    default:
      /* Invalid selection, do not create list entries. */
      break;
  }

  SchemaListPtr->SchemaList[schemaIdx].Schema = Scc_SAPSchemaIDs_None;
  SchemaListPtr->SchemaList[schemaIdx].Priority = 0xFFu;
}

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_CheckSchemaList
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SAP_ExiTx_CheckSchemaList(
  P2CONST(Scc_SAP_SchemaListStructType, AUTOMATIC, SCC_APPL_DATA) SchemaListPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8_least listIdx;
  boolean continueLoop;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each list entry of the passed schema list */
  for (listIdx = 0; listIdx < (uint8_least)SCC_SCHEMALIST_SIZE; listIdx++)
  {
    continueLoop = FALSE;

    /* #20 Check if the list is terminated by None */
    if (SchemaListPtr->SchemaList[listIdx].Schema == Scc_SAPSchemaIDs_None)
    {
      /* #30 End of list found */
    }
    /* #40 Check if the current list entry is an invalid schema */
    else if (SchemaListPtr->SchemaList[listIdx].Schema >= Scc_SAPSchemaIDs_TerminationEntry)
    {
      /* #50 Invalid entry */
      retVal = Scc_ReturnType_NotOK;
    }
    /* #60 Check if the priority is outside the priority range */
    else if (   (SchemaListPtr->SchemaList[listIdx].Priority < SCC_SAP_EXITX_PRIORANGE_MIN)
             || (SchemaListPtr->SchemaList[listIdx].Priority > SCC_SAP_EXITX_PRIORANGE_MAX))
    {
      /* #70 Invalid entry */
      retVal = Scc_ReturnType_NotOK;
    }
    /* #80 Otherwise */
    else
    {
      /* #90 Valid entry */
      retVal = Scc_ReturnType_OK;
      continueLoop = TRUE;
    }

    /* #100 Check if an invalid entry was detected */
    if ((retVal != Scc_ReturnType_OK) || (continueLoop == FALSE))
    {
      /* #110 Stop the search */
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_BuildReqMessage
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SAP_ExiTx_BuildReqMessage(
  P2CONST(Scc_SAP_SchemaListStructType, AUTOMATIC, SCC_APPL_DATA) SchemaListPtr,
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2VAR(Exi_SAP_supportedAppProtocolReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr = NULL_PTR;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Create the base message */
  retVal = Scc_SAP_ExiTx_BuildReqMessage_CreateBaseMessage(TxMsgWSPtr, &bodyPtr);

  /* #20 Check if the message was created */
  if (retVal == Scc_ReturnType_OK)
  {
    P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_VAR_NOINIT) appProtocolPtr = bodyPtr->AppProtocol;
    uint8_least counter = 0u;

    /* #30 Set the supportedAppProtocolReq as root element */
    TxMsgWSPtr->RootElementId = EXI_SAP_SUPPORTED_APP_PROTOCOL_REQ_TYPE;
    TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_SAP;

    /* #40 For each schema of the passed schema list */
    for (counter = 0u; counter < (uint8_least)(SCC_SCHEMALIST_SIZE - 1u); counter++)
    {
      /* #50 Process the current schema entry */
      retVal = Scc_SAP_ExiTx_BuildReqMessage_ProcessEntry(TxMsgWSPtr, &SchemaListPtr->SchemaList[counter], appProtocolPtr);

      /* #60 Check if the entry was processed successfully */
      if (retVal == Scc_ReturnType_OK)
      {
        /* #70 Clear the next pointer of the current entry */
        appProtocolPtr->NextAppProtocolPtr = (P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA))NULL_PTR;

        /* #80 Check if the passed list is not terminated by None */
        if (Scc_SAPSchemaIDs_None != SchemaListPtr->SchemaList[counter + 1u].Schema)
        {
          /* #90 Build up the linked list */
          appProtocolPtr->NextAppProtocolPtr
            = (P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_VAR_NOINIT))                                               /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(&TxMsgWSPtr->Exi_AllocWs, sizeof(Exi_SAP_AppProtocolType), Exi_BT_True);
          if (appProtocolPtr->NextAppProtocolPtr != NULL_PTR)
          {
            appProtocolPtr = appProtocolPtr->NextAppProtocolPtr;                                                        /* PRQA S 2983 */ /* MD_Scc_VariantDependent */
          }
          else
          {
            retVal = Scc_ReturnType_NotOK;
          }
        }
      }

      /* #100 Check if error occurred or the passed list is terminated by None */
      if ((retVal == Scc_ReturnType_NotOK) || (Scc_SAPSchemaIDs_None == SchemaListPtr->SchemaList[counter + 1u].Schema))
      {
        /* #110 Stop creation of further SAP message entries */
        break;
      }
    }
  }

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_BuildReqMessage_CreateBaseMessage
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SAP_ExiTx_BuildReqMessage_CreateBaseMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr,
  P2VAR(Exi_SAP_supportedAppProtocolReqType*, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8 bufferPoolId = 0;
  P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get MsgPtr and MsgPtrSize */
  if (Scc_BufferPoolRequestGetBuffer(SCC_POOL_BUFF_LARGE, &buffPoolWsPtr->MsgPtr, &buffPoolWsPtr->MsgPtrSize, &bufferPoolId) != E_OK)
  {
    /* Do nothing. Error already reported */
  }
  else
  {
    /* #20 Store the bufferPoolId */
    Scc_Core_Channel_Set_BufferPoolId(bufferPoolId);
    /* #30 Check if EXI alloc workspace can be initialized */
    if (Exi_InitMemAllocWorkspace(&TxMsgWSPtr->Exi_AllocWs, buffPoolWsPtr->MsgPtr, 0u, buffPoolWsPtr->MsgPtrSize) == EXI_E_OK)
    {
      /* #40 Fetch the memory for the SAP request message */
      *BodyPtr = (P2VAR(Exi_SAP_supportedAppProtocolReqType, AUTOMATIC, SCC_VAR_NOINIT))                                /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(&TxMsgWSPtr->Exi_AllocWs, sizeof(Exi_SAP_supportedAppProtocolReqType), Exi_BT_True);

      /* #50 Check if body was created */
      if (*BodyPtr != NULL_PTR)
      {
        /* #60 Fetch the memory for the first app protocol pointer */
        (*BodyPtr)->AppProtocol = (P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_VAR_NOINIT))                           /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(&TxMsgWSPtr->Exi_AllocWs, sizeof(Exi_SAP_AppProtocolType), Exi_BT_True);

        /* #70 Check if first app protocol type was created */
        if ((*BodyPtr)->AppProtocol != NULL_PTR)
        {
          /* #80 Indicate success */
          retVal = Scc_ReturnType_OK;
        }
      }
    }
    else
    {
      /* Do nothing */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_BuildReqMessage_ProcessEntry
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SAP_ExiTx_BuildReqMessage_ProcessEntry(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr,
  P2CONST(Scc_SAP_SchemaInfoStructType, AUTOMATIC, SCC_VAR_NOINIT) EntryToProcessPtr,
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_VAR_NOINIT) AppProtocolEntryPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch the memory for the protocol namespace */
  AppProtocolEntryPtr->ProtocolNamespace
    = (P2VAR(Exi_SAP_protocolNamespaceType, AUTOMATIC, SCC_VAR_NOINIT))                                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(&TxMsgWSPtr->Exi_AllocWs, sizeof(Exi_SAP_protocolNamespaceType), Exi_BT_True);

  /* #20 Check if the protocol namespace was created */
  if (AppProtocolEntryPtr->ProtocolNamespace != NULL_PTR)
  {
    retVal = Scc_ReturnType_OK;

    /* #30 Set the schema id */
    AppProtocolEntryPtr->SchemaID = (uint8)EntryToProcessPtr->Schema;
    /* #40 Set the priority */
    AppProtocolEntryPtr->Priority = EntryToProcessPtr->Priority;

    /* #50 Setup the current SAP entry based on the schema */
    switch (EntryToProcessPtr->Schema)
    {
#if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
      case Scc_SAPSchemaIDs_DIN:
        Scc_DIN70121_ExiTx_SAPSetEntry(AppProtocolEntryPtr);
        break;
#endif /* SCC_SCHEMA_DIN */

#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
      case Scc_SAPSchemaIDs_ISO15118_2:
        Scc_ISO15118_2_ExiTx_SAPSetEntry(AppProtocolEntryPtr);
        break;
#endif /* SCC_SCHEMA_ISO */

#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
      case Scc_SAPSchemaIDs_ISO15118_20AC:
        Scc_ISO15118_20AC_ExiTx_SAPSetEntry(AppProtocolEntryPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20AC */

#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
      case Scc_SAPSchemaIDs_ISO15118_20DC:
        Scc_ISO15118_20DC_ExiTx_SAPSetEntry(AppProtocolEntryPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20DC */

#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
      case Scc_SAPSchemaIDs_ISO15118_20WPT:
        Scc_ISO15118_20WPT_ExiTx_SAPSetEntry(AppProtocolEntryPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20WPT */

#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
      case Scc_SAPSchemaIDs_ISO15118_20ACDP:
        Scc_ISO15118_20ACDP_ExiTx_SAPSetEntry(AppProtocolEntryPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20ACDP */

#if ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0 )
      case Scc_SAPSchemaIDs_OppCharge:
        Scc_OppCharge_ExiTx_SAPSetEntry(AppProtocolEntryPtr);
        break;
#endif /* SCC_SCHEMA_OPP_CHARGE */

      default:
        /* This should never happen as the list is validated by Scc_SAP_ExiTx_CheckSchemaList
        * before this function is called */
        retVal = Scc_ReturnType_NotOK;
        break;
    }
  }

  return retVal;
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: Scc_SAP_ExiTx.c
 *********************************************************************************************************************/
