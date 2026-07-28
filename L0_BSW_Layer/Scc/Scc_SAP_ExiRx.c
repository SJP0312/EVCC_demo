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
/*!        \file  Scc_SAP_ExiRx.c
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

#define SCC_SAP_EXIRX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
 /*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_SAP_Exi.h"
#include "Scc_SAP_InterfaceCfg.h"
#include "Scc_SAP_TimerCfg.h"
#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_ExiRx_Common.h"
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

#if (defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20  != 0u))
# include "Scc_ISO15118_20_Exi.h"
#endif

#if (defined(SCC_SCHEMA_OPP_CHARGE) && (SCC_SCHEMA_OPP_CHARGE  != 0u))
# include "Scc_OppCharge_Exi.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_SAP_V2GTP_HDR_PAYLOAD_TYPE_LEN (1u)

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Variable to manage the supported app protocol related information */
SCC_LOCAL VAR(Scc_SAPSchemaIDType, SCC_VAR_NOINIT) Scc_SAP_ExiRx_ChosenSchema;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_START_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* [V2G-DC-165], [V2G2-087], [V2G20-087] */
SCC_LOCAL CONST(uint16, SCC_CONST) Scc_SAP_ExiRx_SupportedPayloadTypes[SCC_SAP_V2GTP_HDR_PAYLOAD_TYPE_LEN] = {          /* PRQA S 3218 */ /* MD_Scc_3218 */
  (uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_SAP
};

#define SCC_STOP_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_SAP_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*! \brief          Prepares the decoding of an EXI stream
 *  \details        -
 *  \param[in]      V2GTpHeaderPtr                     Pointer to a v2gtp header
 *  \param[in]      RxMsgWSPtr                         Pointer to the Rx message workspace
 *  \return         Scc_ReturnType_OK                  Preparation succeeded
 *  \return         Scc_ReturnType_InvalidSessionId    The SessionId is invalid
 *  \return         Scc_ReturnType_NotOK               Preparation failed due to either initializing or decoding Exi
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_SAP_ExiRx_DecodeMessagePrepare(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_SAP_ExiRx_DecodeSupportedAppProtocolRes
 *********************************************************************************************************************/
/*! \brief          Decode SupportedAppProtocol Response and set the Schema (DIN, ISO-2 or ISO-20)
 *  \details        -
 *  \param[in]      V2GTpHeaderPtr      Pointer to a v2gtp header
 *  \param[in]      RxMsgWSPtr          Pointer to the Rx message workspace
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_SAP_ExiRx_DecodeSupportedAppProtocolRes(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SAP_ExiRx_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_SAP_ExiRx_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the chosen schema to None */
  Scc_SAP_ExiRx_ChosenSchema = Scc_SAPSchemaIDs_None;

  return;
}

/**********************************************************************************************************************
 *  Scc_SAP_ExiRx_SetupRxConfig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_SAP_ExiRx_SetupRxConfig(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup the passed Rx configuration structure */
  RxConfigPtr->DecodePrepareFct = &Scc_SAP_ExiRx_DecodeMessagePrepare;
  RxConfigPtr->DecodeFct = &Scc_SAP_ExiRx_DecodeSupportedAppProtocolRes;
  RxConfigPtr->SupportedPayloadTypeList = Scc_SAP_ExiRx_SupportedPayloadTypes;
  RxConfigPtr->SupportedPayloadTypeListLen = SCC_SAP_V2GTP_HDR_PAYLOAD_TYPE_LEN;
}


/**********************************************************************************************************************
 *  Scc_SAP_ExiRx_GetChosenSchema
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_SAPSchemaIDType, SCC_CODE) Scc_SAP_ExiRx_GetChosenSchema(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the chosen schema */
  return Scc_SAP_ExiRx_ChosenSchema;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SAP_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_SAP_ExiRx_DecodeMessagePrepare(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(V2GTpHeaderPtr);                                                                            /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Prepare the message handling */
  return Scc_ExiRx_Common_DecodeMessagePrepare(EXI_SCHEMA_SET_SAP_TYPE, NULL_PTR, RxMsgWSPtr);
}

/**********************************************************************************************************************
 *  Scc_SAP_ExiRx_DecodeSupportedAppProtocolRes
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
/* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_SAP_ExiRx_DecodeSupportedAppProtocolRes(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
#if (defined(SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD) && (SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD == STD_ON))
  /* Do not perform the length check as too big payload information in header should be ignored */
  SCC_DUMMY_STATEMENT_CONST(V2GTpHeaderPtr);                                                                            /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#else
  /* [V2G-DC-172], [V2G2-094], [V2G20-094] */
  /* #10 Check if the stream length does not match with payload length */
  if (RxMsgWSPtr->Exi_DecWs.DecWs.TotalStreamLength != V2GTpHeaderPtr->PayloadLength)
  {
    /* #20 Indicate wrong payload length */
    retVal = Scc_ReturnType_InvalidPayloadLen;
  }
  /* #30 Otherwise */
  else
#endif  /* SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD */
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* #40 Fetch the exi message pointer */
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_SAP_supportedAppProtocolResType, AUTOMATIC, SCC_VAR_NOINIT) exiSapMsgPtr =
      (P2CONST(Exi_SAP_supportedAppProtocolResType, AUTOMATIC, SCC_VAR_NOINIT)) & buffPoolWsPtr->MsgPtr[0];

    /* [V2G20-1747], [V2G20-1090] */
    /* #50 Check if the response is negative */
    if (EXI_SAP_RESPONSE_CODE_TYPE_FAILED_NO_NEGOTIATION <= exiSapMsgPtr->ResponseCode)
    {
      /* #60 Report the negative response code */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Common_SupportedAppProtocolResNegativeResponseCode);
      /* #70 Provide the response code to the application */
      Scc_SAP_InterfaceCfg_Set_SAPResponseCode(exiSapMsgPtr->ResponseCode);
    }
    /* #80 Otherwise */
    else
    {
      /* #90 Check if no schema id was chosen */
      if (exiSapMsgPtr->SchemaIDFlag == 0u)
      {
        /* #100 Report the missing schema id information */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Common_SupportedAppProtocolResMissingSchemaId);
      }
      /* #110 Check if the chosen schema was none of the provided ones */
      else if (FALSE == Scc_SAP_ExiTx_ChosenSchemaSupported((Scc_SAPSchemaIDType)exiSapMsgPtr->SchemaID))               /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
      {
        /* #120 Report that an invalid schema id was chosen by EVSE */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Common_SupportedAppProtocolResInvalidSchemaSelection);
      }
      /* #130 Otherwise */
      else
      {
        Scc_SAPSchemaIDType sapSchemaID = (Scc_SAPSchemaIDType)exiSapMsgPtr->SchemaID;                                  /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */

        /* #140 Propagate the received schema id to configured callout */
        Scc_SAP_InterfaceCfg_Set_SAPSchemaID(sapSchemaID);

        /* Store the chosen schema id for later usage */
        Scc_SAP_ExiRx_ChosenSchema = sapSchemaID;

        /* #150 Setup Rx and Tx configuration based on selected schema */
        switch (sapSchemaID)
        {
#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
        case Scc_SAPSchemaIDs_ISO15118_2:
          Scc_ISO15118_2_ExiTx_SetupTxConfig(&Scc_ExiTx_Xyz_PrepareMessageFctPtr);
          Scc_ISO15118_2_ExiRx_SetupRxConfig(&Scc_RxConfig);
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
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
        case Scc_SAPSchemaIDs_ISO15118_20ACDP:
#endif /* SCC_SCHEMA_ISO_20ACDP */
          Scc_ISO15118_20_ExiTx_SetupTxConfig(&Scc_ExiTx_Xyz_PrepareMessageFctPtr);
          Scc_ISO15118_20_ExiRx_SetupRxConfig(&Scc_RxConfig, sapSchemaID);
          break;
#endif /* SCC_SCHEMA_ISO_20 */

#if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
        case Scc_SAPSchemaIDs_DIN:
          Scc_DIN70121_ExiTx_SetupTxConfig(&Scc_ExiTx_Xyz_PrepareMessageFctPtr);
          Scc_DIN70121_ExiRx_SetupRxConfig(&Scc_RxConfig);

          /* Reset the SessionID as DIN has no "pause" mode to resume sessions */
          Scc_SessionIDNvm[0] = 0x01;
          Scc_SessionIDNvm[1] = 0x00;
          break;
#endif /* SCC_SCHEMA_DIN */

#if ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0 )
        case Scc_SAPSchemaIDs_OppCharge:
          Scc_OppCharge_ExiTx_SetupTxConfig(&Scc_ExiTx_Xyz_PrepareMessageFctPtr);
          Scc_OppCharge_ExiRx_SetupRxConfig(&Scc_RxConfig);

          /* Reset the SessionID as OppCharge has no "pause" mode to resume sessions */
          Scc_SessionIDNvm[0] = 0x01;
          Scc_SessionIDNvm[1] = 0x00;
          break;
#endif /* SCC_SCHEMA_OPP_CHARGE */

        default:
          /* This should never happen as the SchemaId is already checked
           * by Scc_SAP_ExiTx_ChosenSchemaSupported() before the switch is entered */
          break;
        }

        /* #160 Provide the response code to the application */
        Scc_SAP_InterfaceCfg_Set_SAPResponseCode(exiSapMsgPtr->ResponseCode);

        /* #170 Set the new state and report the success */
        SCC_ENTER_EXCLUSIVE_AREA_2();
        Scc_State = Scc_State_SAPComplete;
        SCC_LEAVE_EXCLUSIVE_AREA_2();
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SupportedAppProtocol_OK);

        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_SAP_ExiRx.c
 *********************************************************************************************************************/
