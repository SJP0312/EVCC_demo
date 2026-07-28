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
/*!        \file  Scc_ISO15118_20_ExiTx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-20.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20_EXITX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
#include "Scc_ISO15118_20_Exi.h"
#include "Scc_Core_Channel.h"
#include "Scc_Priv.h"
#include "Scc_ISO15118_20_InterfaceCfg.h"

#include "IpBase.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

#if (defined SCC_SCHEMA_ISO_20AC) && (SCC_SCHEMA_ISO_20AC != 0)
# include "Scc_ISO15118_20AC_Exi.h"
#endif

#if (defined SCC_SCHEMA_ISO_20DC) && (SCC_SCHEMA_ISO_20DC != 0)
# include "Scc_ISO15118_20DC_Exi.h"
#endif

#if (defined SCC_SCHEMA_ISO_20WPT) && (SCC_SCHEMA_ISO_20WPT != 0)
# include "Scc_ISO15118_20WPT_Exi.h"
#endif

#if (defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0)
# include "Scc_ISO15118_20ACDP_Exi.h"
#endif

# include "Scc_ISO15118_20CM_Exi.h"


/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiTx_PrepareMessage
 *********************************************************************************************************************/
/*! \brief          Prepares the EXI request message to be transmitted
 *  \details        -
 *  \param[in]      TxMsgWSPtr                  Pointer to the Tx message workspace
 *  \return         Scc_ReturnType_OK           Exi preparation was successful
 *  \return         Scc_ReturnType_NotOK        Exi preparation was not successful or timeout happened
 *  \return         Scc_ReturnType_Pending      Message handling is pending, try again later
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20_ExiTx_PrepareMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiTx_SetupTxConfig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_ExiTx_SetupTxConfig(
  P2VAR(Scc_ExiTx_Xyz_PrepareMessageFctType, AUTOMATIC, SCC_APPL_DATA) TxPrepMessagePtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup the passed prepare message function pointer */
  *TxPrepMessagePtr = &Scc_ISO15118_20_ExiTx_PrepareMessage;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiTx_WriteSessionId
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
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20_ExiTx_WriteSessionId(
  P2VAR(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, SCC_APPL_DATA) SessionIdPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the SessionID */
  /* [V2G20-1541] */
  /* #20 Check if Scc_SessionIDNvm is empty */
  if ((Scc_SessionIDNvm[0] == 1u) && (Scc_SessionIDNvm[1] == 0u))
  {
    CONST(uint8, AUTOMATIC) zeroSessionID[SCC_SESSION_ID_NVM_BLOCK_LEN] = { 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    SessionIdPtr->Length = zeroSessionID[0];
    /* #30 Copy empty SessionID to the buffer */
    /* PRQA S 0315 2 */ /* MD_MSR_VStdLibCopy */
    IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &SessionIdPtr->Buffer[0],
      (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &zeroSessionID[1], (uint32)zeroSessionID[0]);
  }
  /* [V2G20-747], Otherwise */
  else
  {
    uint8 tmpLen = Scc_SessionIDNvm[0];
    /* Limit the amount of data to be copied with respect to destination buffer size to avoid buffer overflow in IpBase_Copy */
    if (tmpLen > sizeof(SessionIdPtr->Buffer))
    {
      tmpLen = sizeof(SessionIdPtr->Buffer);
    }
    /* Limit the amount of data to be copied with respect to source buffer size to avoid read outside of buffer in IpBase_Copy */
    if (tmpLen > (uint8)(sizeof(Scc_SessionIDNvm) - 1u))                                                                /* PRQA S 2992,2996 */ /* MD_Scc_VariantDependent */
    {
      tmpLen = sizeof(Scc_SessionIDNvm) - 1u;                                                                           /* PRQA S 2880 */ /* MD_Scc_VariantDependent */
    }

    /* #40 Copy the SessionID to the buffer */
    SessionIdPtr->Length = tmpLen;
    /* PRQA S 0315 2 */ /* MD_MSR_VStdLibCopy */
    IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &SessionIdPtr->Buffer[0],
      (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_SessionIDNvm[1], (uint32)tmpLen);
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiTx_WriteHeader
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
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_ExiTx_WriteHeader(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_20_CT_10_MessageHeaderType*, AUTOMATIC, SCC_APPL_DATA) MessageHeaderPtrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* Setup header according to [V2G20-2676] */
  /* #10 Create the message header pointer */
  *MessageHeaderPtrPtr
    = (P2VAR(Exi_ISO_20_CT_10_MessageHeaderType, AUTOMATIC, SCC_VAR_NOINIT))                                            /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_MessageHeaderType), Exi_BT_True);

  /* #20 Check if the header was created */
  if (*MessageHeaderPtrPtr != NULL_PTR)
  {
    /* #30 Create the buffer of the SessionID */
    (*MessageHeaderPtrPtr)->SessionID
      = (P2VAR(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, SCC_VAR_NOINIT))                                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_sessionIDType), Exi_BT_True);

    /* #40 Check if the SessionId was created */
    if ((*MessageHeaderPtrPtr)->SessionID != NULL_PTR)
    {
      /* #50 Write the SessionId */
      Scc_ISO15118_20_ExiTx_WriteSessionId((*MessageHeaderPtrPtr)->SessionID);

      /* #60 Fetch TimeStamp from application */
      Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_TimeStamp(&(*MessageHeaderPtrPtr)->TimeStamp);
      (*MessageHeaderPtrPtr)->SignatureFlag = (Exi_BitType)0u;

      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiTx_CreateRationaleNumberType
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_ExiTx_CreateRationaleNumberType(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) ValuePtr,
  P2VAR(Exi_ISO_20_CT_10_RationalNumberType*, AUTOMATIC, SCC_VAR_NOINIT) RationaleNumberTypePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT) typePtr
    = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                           /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if physical value type element was created */
  if (typePtr != NULL_PTR)
  {
    /* #20 Setup physical value type */
    Scc_Conv_Scc20ToISO_PhysicalValue(ValuePtr, typePtr);

    *RationaleNumberTypePtr = typePtr;
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiTx_PrepareMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20_ExiTx_PrepareMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 create request message and set MessageTimeout */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
    case Scc_MsgTrig_SessionSetup:
    case Scc_MsgTrig_AuthorizationSetup:
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
    case Scc_MsgTrig_CertificateInstallation:
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
    case Scc_MsgTrig_Authorization:
    case Scc_MsgTrig_ServiceDiscovery:
    case Scc_MsgTrig_ServiceDetail:
    case Scc_MsgTrig_PaymentServiceSelection:
    case Scc_MsgTrig_ScheduleExchange:
    case Scc_MsgTrig_PowerDelivery:
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
    case Scc_MsgTrig_MeteringReceipt:
#endif
    case Scc_MsgTrig_SessionStop:
      retVal = Scc_ISO15118_20CM_ExiTx_PrepareMessage(TxMsgWSPtr);
      break;

    case Scc_MsgTrig_ChargeParameterDiscovery:
    case Scc_MsgTrig_ChargeLoop:
    {
      switch (Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID())
      {
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
        case Scc_ISO15118_20_SID_AC:
# if(defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
        case Scc_ISO15118_20_SID_AC_BPT:
#endif /* SCC_CHARGING_BPT */
          retVal = Scc_ISO15118_20AC_ExiTx_PrepareMessage(TxMsgWSPtr);
          break;
#endif /* SCC_SCHEMA_ISO_20AC */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
        case Scc_ISO15118_20_SID_DC:
# if(defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
        case Scc_ISO15118_20_SID_DC_BPT:
# endif /* SCC_CHARGING_BPT */
#if (defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0)
        case Scc_ISO15118_20_SID_DC_ACDP:
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
        case Scc_ISO15118_20_SID_DC_ACDP_BPT:
# endif /* SCC_CHARGING_BPT */
#endif
          retVal = Scc_ISO15118_20DC_ExiTx_PrepareMessage(TxMsgWSPtr);
          break;
#endif /* SCC_SCHEMA_ISO_20DC */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
        case Scc_ISO15118_20_SID_WPT:
          retVal = Scc_ISO15118_20WPT_ExiTx_PrepareMessage(TxMsgWSPtr);
          break;
#endif /* SCC_SCHEMA_ISO_20WPT */
        default:
          /* retVal already set to NotOk */
          break;
      }
      break;
    }
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
    case Scc_MsgTrig_CableCheck:
    case Scc_MsgTrig_PreCharge:
    case Scc_MsgTrig_WeldingDetection:
    {
      switch (Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID())
      {
        case Scc_ISO15118_20_SID_DC:
# if(defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
        case Scc_ISO15118_20_SID_DC_BPT:
# endif /* SCC_CHARGING_BPT */
# if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
        case Scc_ISO15118_20_SID_DC_ACDP:
#  if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
        case Scc_ISO15118_20_SID_DC_ACDP_BPT:
#  endif /* SCC_CHARGING_BPT */
# endif /* SCC_SCHEMA_ISO_20ACDP */
          retVal = Scc_ISO15118_20DC_ExiTx_PrepareMessage(TxMsgWSPtr);
          break;

        default:
          /* retVal already set to NotOk */
          break;
      }
      break;
    }
#endif /* SCC_SCHEMA_ISO_20DC */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
    case Scc_MsgTrig_FinePositioningSetup:
    case Scc_MsgTrig_FinePositioning:
    case Scc_MsgTrig_Pairing:
    case Scc_MsgTrig_AlignmentCheck:
      retVal = Scc_ISO15118_20WPT_ExiTx_PrepareMessage(TxMsgWSPtr);
      break;
#endif /* SCC_SCHEMA_ISO_20WPT */
#if ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 )
    case Scc_MsgTrig_ACDP_VehiclePositioning:
    case Scc_MsgTrig_ACDP_Connect:
    case Scc_MsgTrig_ACDP_Disconnect:
#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
    case Scc_MsgTrig_ACDP_SystemStatus:
#endif
      retVal = Scc_ISO15118_20ACDP_ExiTx_PrepareMessage(TxMsgWSPtr);
      break;
#endif /* SCC_SCHEMA_ISO_20ACDP */

    default:
      /* Report a V2G error of the current trigger */
      Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20_EncodeMessageInvalidMsgTrigger);
      retVal = Scc_ReturnType_NotOK;
      break;
  }

  if (retVal == Scc_ReturnType_NotOK)
  {
    /* Make sure that mem alloc issues are at least reported here */
    Scc_ReportError(Scc_StackError_Unspecified, SccDetailedError_Iso_20_EncodeMessageFailed);
  }

  return retVal;
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20 */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_ExiTx.c
 *********************************************************************************************************************/
