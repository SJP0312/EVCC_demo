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
/**        \file  Exi.c
 *        \brief  Efficient XML Interchange main source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file Exi.h.
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_Exi_1.1_0857 */ /* [L] Number of macro definitions exceeds 1024 - program is non-conforming. */

#define EXI_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_BSEncoder.h"
#include "Exi_BSDecoder.h"
#include "Exi_SchemaEncoder.h"
#include "Exi_SchemaDecoder.h"
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
#include "IpBase.h"
#endif

/*lint -e438 */ /* Suppress ID438 because Config pointer only used in Post-Build Variant */
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
#error "Vendor specific version numbers of Exi.h and Exi.c are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (EXI_LOCAL)
# define EXI_LOCAL static
#endif /* !defined (EXI_LOCAL) */

#if !defined (EXI_LOCAL_INLINE)
# define EXI_LOCAL_INLINE LOCAL_INLINE
#endif /* !defined (EXI_LOCAL_INLINE) */

/**********************************************************************************************************************
*  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

#if EXI_ENABLE_PBUF_SUPPORT == STD_ON
/**********************************************************************************************************************
 *  Exi_CheckPBufConsistency
 *********************************************************************************************************************/
/*! \brief         Check if a PBuf is consistent.
 *  \details       Check if a PBuf is consistent regarding its length.
 *  \param[in]     PBufPtr            Pointer to the PBuf
 *  \return        EXI_E_OK:                      Finished successfully\n
 *                 EXI_E_NOT_OK:                  PBuf is set to NULL_PTR\n
 *                 EXI_E_INCONSISTEN_PBUF         PBuf length is not consistent
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
EXI_LOCAL FUNC(Exi_ReturnType, EXI_CODE) Exi_CheckPBufConsistency(
  P2CONST(IpBase_PbufType, AUTOMATIC, EXI_APPL_DATA) PBufPtr );
#endif /* EXI_ENABLE_PBUF_SUPPORT */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_InitMemory
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EXI_CODE) Exi_InitMemory(void)
{
  /* #10 Function is empty */
}
/**********************************************************************************************************************
 *  Exi_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EXI_CODE) Exi_Init(P2CONST(Exi_ConfigType, AUTOMATIC, EXI_CONST) Exi_ConfigPtr)
{
  /* #10 Function is empty */
  EXI_DUMMY_STATEMENT_CONST(Exi_ConfigPtr);                                                                             /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
}
#if (EXI_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  Exi_GetVersionInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_GetVersionInfo( P2VAR(Std_VersionInfoType, AUTOMATIC, EXI_APPL_DATA) VersionInfoPtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (VersionInfoPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Write version information to the output structure */
    VersionInfoPtr->vendorID = EXI_VENDOR_ID;
    VersionInfoPtr->moduleID = EXI_MODULE_ID;
    VersionInfoPtr->sw_major_version = EXI_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = EXI_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = EXI_SW_PATCH_VERSION;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_GET_VERSION_INFO, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */
}
#endif
  /* EXI_VERSION_INFO_API */

/**********************************************************************************************************************
 *  Exi_MainFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EXI_CODE) Exi_MainFunction(void)
{
  /* #10 Function is empty */
}

/**********************************************************************************************************************
 *  Exi_InitEncodeWorkspace()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6060, 6080 1 */ /* MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(Exi_ReturnType, EXI_CODE) Exi_InitEncodeWorkspace(
  P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(uint8, AUTOMATIC, EXI_APPL_DATA) InBufPtr,
#if EXI_ENABLE_PBUF_SUPPORT == STD_ON
  P2VAR(IpBase_PbufType, AUTOMATIC, EXI_APPL_VAR) OutPBufPtr,
#else
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) OutBufPtr,
  uint32 OutBufLen,
#endif
  uint32 OutBufOfs
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
 ,uint32 StartWriteAtStreamPos
 ,boolean CalculateStreamLength
#endif
  )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_ReturnType retVal;
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
  Exi_BooleanType localCalculateStreamLength = Exi_BT_False;
#endif
  /* #10 Check plausibility of input parameters */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  retVal = EXI_E_NOT_OK;
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (InBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
# if EXI_ENABLE_PBUF_SUPPORT == STD_ON
  else if (OutPBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (OutPBufPtr->payload == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (OutPBufPtr->totLen == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (OutBufOfs >= OutPBufPtr->totLen)
  {
    errorId = EXI_E_INV_PARAM;
  }
# else
  else if (OutBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (OutBufLen == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (OutBufOfs >= OutBufLen)
  {
    errorId = EXI_E_INV_PARAM;
  }
# endif
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
    if (CalculateStreamLength == (boolean)TRUE)
    {
      localCalculateStreamLength = Exi_BT_True;
    }
#endif

    /* #20 Initialize basic encoder workspace */
#if EXI_ENABLE_PBUF_SUPPORT == STD_ON
    retVal = Exi_CheckPBufConsistency(OutPBufPtr);
    if (retVal == EXI_E_OK)
    {
      retVal = Exi_VBSEncodeInitWorkspace(
                              &EncWsPtr->EncWs,
                              OutPBufPtr,
                              OutBufOfs
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
                              ,StartWriteAtStreamPos
                              ,localCalculateStreamLength
#endif
                              );
    }
#else
    retVal = Exi_VBSEncodeInitWorkspace(
                               &EncWsPtr->EncWs,
                               OutBufPtr,
                               OutBufLen,
                               OutBufOfs
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
                              ,StartWriteAtStreamPos
                              ,localCalculateStreamLength
#endif
                               );
#endif /* EXI_ENABLE_PBUF_SUPPORT */
    EncWsPtr->InputData.StoragePtr = InBufPtr;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_INIT_ENCODE_WORKSPACE, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}

/**********************************************************************************************************************
 *  Exi_InitDecodeWorkspace()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6060, 6080, 6030 1 */ /* MD_MSR_STPAR, MD_MSR_STMIF, MD_MSR_STCYC */
FUNC(Exi_ReturnType, EXI_CODE) Exi_InitDecodeWorkspace(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
#if EXI_ENABLE_PBUF_SUPPORT == STD_ON
  P2CONST(IpBase_PbufType, AUTOMATIC, EXI_APPL_DATA) InPBufPtr,
#else
  P2CONST(uint8, AUTOMATIC, EXI_APPL_DATA) InBufPtr,
#endif
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) OutBufPtr,
#if EXI_ENABLE_PBUF_SUPPORT == STD_OFF
  uint32 InBufLen,
#endif
  uint32 OutBufLen,
  uint32 InBufOfs)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_ReturnType retVal;

  /* #10 Check plausibility of input parameters */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  retVal = EXI_E_NOT_OK;
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
#if EXI_ENABLE_PBUF_SUPPORT == STD_ON
  else if (InPBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (InPBufPtr->payload == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (InPBufPtr->totLen == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (InBufOfs >= InPBufPtr->totLen)
  {
    errorId = EXI_E_INV_PARAM;
  }
#else
  else if (InBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (InBufLen == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (InBufOfs >= InBufLen)
  {
    errorId = EXI_E_INV_PARAM;
  }
#endif
  else if (OutBufLen == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (OutBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize basic decoder workspace */
#if EXI_ENABLE_PBUF_SUPPORT == STD_ON
    retVal = Exi_CheckPBufConsistency(InPBufPtr);
    if (retVal == EXI_E_OK)
    {
      retVal = Exi_VBSDecodeInitWorkspace(&DecWsPtr->DecWs, InPBufPtr, InBufOfs);
    }
#else
    retVal = Exi_VBSDecodeInitWorkspace(&DecWsPtr->DecWs, InBufPtr, InBufLen, InBufOfs);
#endif
    if (retVal == EXI_E_OK)
    {
      retVal = Exi_InitMemAllocWorkspace(&DecWsPtr->OutputData.MemAllocWs, OutBufPtr, 0, OutBufLen);
    }
    DecWsPtr->OutputData.RootElementId = EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE;
    DecWsPtr->OutputData.SchemaSetId = EXI_UNKNOWN_SCHEMA_SET_TYPE;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_INIT_DECODE_WORKSPACE, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}

/**********************************************************************************************************************
 *  Exi_Encode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Exi_ReturnType, EXI_CODE) Exi_Encode( P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_ReturnType retVal = EXI_E_NOT_OK;

  /* #10 Check plausibility of input parameters */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EncWsPtr->InputData.StoragePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  else if (EncWsPtr->EncWs.PBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EncWsPtr->EncWs.PBufPtr[EncWsPtr->EncWs.PBufIdx].len == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (EncWsPtr->EncWs.BytePos >= EncWsPtr->EncWs.PBufPtr[EncWsPtr->EncWs.PBufIdx].len)
  {
    errorId = EXI_E_INV_PARAM;
  }
#else
  else if (EncWsPtr->EncWs.BufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EncWsPtr->EncWs.BufLen == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (EncWsPtr->EncWs.BytePos >= EncWsPtr->EncWs.BufLen)
  {
    errorId = EXI_E_INV_PARAM;
  }
#endif
  else if (EncWsPtr->InputData.RootElementId >= EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
#if ( EXI_DEV_ERROR_DETECT == STD_OFF ) /* Already checked in DET if DET is enabled */
    if(EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE > EncWsPtr->InputData.RootElementId)
#endif
    {
      /* #20 Encode EXI header */
      Exi_VBSWriteHeader(&EncWsPtr->EncWs);
      retVal = EncWsPtr->EncWs.StatusCode;
      if(retVal == EXI_E_OK)
      {
        /* #30 Encode EXI schema root element */
        Exi_Encode_SchemaRoot(EncWsPtr);
        retVal = EncWsPtr->EncWs.StatusCode;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_ENCODE, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}

/**********************************************************************************************************************
 *  Exi_EncodeFragment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Exi_ReturnType, EXI_CODE) Exi_EncodeFragment( P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
                                       Exi_NamespaceIdType Namespace )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_ReturnType retVal = EXI_E_NOT_OK;

  /* #10 Check plausibility of input parameters */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EncWsPtr->InputData.StoragePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  else if (EncWsPtr->EncWs.PBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EncWsPtr->EncWs.PBufPtr[EncWsPtr->EncWs.PBufIdx].len == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (EncWsPtr->EncWs.BytePos >= EncWsPtr->EncWs.PBufPtr[EncWsPtr->EncWs.PBufIdx].len)
  {
    errorId = EXI_E_INV_PARAM;
  }
#else
  else if (EncWsPtr->EncWs.BufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EncWsPtr->EncWs.BufLen == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (EncWsPtr->EncWs.BytePos >= EncWsPtr->EncWs.BufLen)
  {
    errorId = EXI_E_INV_PARAM;
  }
#endif
  else if (EncWsPtr->InputData.RootElementId >= EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
#if ( EXI_DEV_ERROR_DETECT == STD_OFF ) /* Already checked in DET if DET is enabled */
    if(EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE > EncWsPtr->InputData.RootElementId)
#endif
    {
      /* #20 Encode EXI header */
      Exi_VBSWriteHeader(&EncWsPtr->EncWs);
      retVal = EncWsPtr->EncWs.StatusCode;
      if(retVal == EXI_E_OK)
      {
        /* #30 Encode EXI schema fragment */
        Exi_Encode_SchemaFragment(EncWsPtr, Namespace);
        retVal = EncWsPtr->EncWs.StatusCode;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_ENCODE_FRAGMENT, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}

/**********************************************************************************************************************
 *  Exi_FinalizeExiStream
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Exi_ReturnType, EXI_CODE) Exi_FinalizeExiStream( P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_ReturnType retVal;

  /* #10 Check plausibility of input parameters */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  retVal = EXI_E_NOT_OK;
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EncWsPtr->InputData.StoragePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
# if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  else if (EncWsPtr->EncWs.PBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EncWsPtr->EncWs.PBufPtr[EncWsPtr->EncWs.PBufIdx].len == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (EncWsPtr->EncWs.BytePos > EncWsPtr->EncWs.PBufPtr[EncWsPtr->EncWs.PBufIdx].len)
  {
    errorId = EXI_E_INV_PARAM;
  }
  /* If BitPos equals zero, no padding is required. Thus, it is OK if BytePos equals the buffer size. */
  else if ((EncWsPtr->EncWs.BitPos == 0u) && (EncWsPtr->EncWs.BytePos > EncWsPtr->EncWs.PBufPtr[EncWsPtr->EncWs.PBufIdx].len))
  {
    errorId = EXI_E_INV_PARAM;
  }
  /* If writing to buffer is active and BitPos is other than zero, padding is required. Thus, BytePos must be smaller than the buffer size. */
  else if (
#  if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
            (EncWsPtr->EncWs.WritingToBufferIsActive == Exi_BT_True) &&
#  endif
            (EncWsPtr->EncWs.BitPos != 0u) && 
            (EncWsPtr->EncWs.BytePos >= EncWsPtr->EncWs.PBufPtr[EncWsPtr->EncWs.PBufIdx].len) )
  {
    errorId = EXI_E_INV_PARAM;
  }
#  if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
  /* If writing to buffer is not active, BytePos must not exceed the buffer size but BitPos is not relevant. (No padding is written) */
  else if (
            (EncWsPtr->EncWs.WritingToBufferIsActive == Exi_BT_False) &&
            (EncWsPtr->EncWs.BytePos > EncWsPtr->EncWs.PBufPtr[EncWsPtr->EncWs.PBufIdx].len) )
  {
    errorId = EXI_E_INV_PARAM;
  }
#  endif
# else
  else if (EncWsPtr->EncWs.BufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EncWsPtr->EncWs.BufLen == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  /* If BitPos equals zero, no padding is required. Thus, it is OK if BytePos equals the buffer size. */
  else if ((EncWsPtr->EncWs.BitPos == 0u) && (EncWsPtr->EncWs.BytePos > EncWsPtr->EncWs.BufLen))
  {
    errorId = EXI_E_INV_PARAM;
  }
  /* If writing to buffer is active and BitPos is other than zero, padding is required. Thus, BytePos must be smaller than the buffer size. */
  else if (
#  if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
            (EncWsPtr->EncWs.WritingToBufferIsActive == Exi_BT_True) &&
#  endif
            (EncWsPtr->EncWs.BitPos != 0u) && 
            (EncWsPtr->EncWs.BytePos >= EncWsPtr->EncWs.BufLen) )
  {
    errorId = EXI_E_INV_PARAM;
  }
#  if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
  /* If writing to buffer is not active, BytePos must not exceed the buffer size but BitPos is not relevant. (No padding is written) */
  else if (
            (EncWsPtr->EncWs.WritingToBufferIsActive == Exi_BT_False) && 
            (EncWsPtr->EncWs.BytePos >= EncWsPtr->EncWs.BufLen) )
  {
    errorId = EXI_E_INV_PARAM;
  }
#  endif
# endif
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Add padding to the end of the stream if required */
    if (EncWsPtr->EncWs.BitPos != 0u)
    {
      EncWsPtr->EncWs.BitPos = 0;
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
      if (EncWsPtr->EncWs.WritingToBufferIsActive == Exi_BT_True)
      {
        EncWsPtr->EncWs.BytePos++;
      }
      else
      {
        EncWsPtr->EncWs.OverallStreamBytePos++;
      }
#else
      EncWsPtr->EncWs.BytePos++;
#endif
    }

    /* #30 Calculate stream length */
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
    /* Check if writing to the EXI stream is currently active -> this is last segment */
    if (EncWsPtr->EncWs.WritingToBufferIsActive == Exi_BT_True)
    {
      /* Writing to buffer is currently active -> Stream segment is shorter than buffer -> add segment length */
# if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
      EncWsPtr->EncWs.OverallStreamBytePos += (EncWsPtr->EncWs.PBufProcessedElementBytes + EncWsPtr->EncWs.BytePos) - EncWsPtr->EncWs.StartOffset;
#else
      EncWsPtr->EncWs.OverallStreamBytePos += EncWsPtr->EncWs.BytePos - EncWsPtr->EncWs.StartOffset;
#endif

      /* This is the last stream segment */
# if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
      EncWsPtr->EncWs.CurrentStreamSegmentLen = (EncWsPtr->EncWs.PBufProcessedElementBytes + EncWsPtr->EncWs.BytePos) - EncWsPtr->EncWs.StartOffset;
# else
      EncWsPtr->EncWs.CurrentStreamSegmentLen = EncWsPtr->EncWs.BytePos - EncWsPtr->EncWs.StartOffset;
# endif
      EncWsPtr->EncWs.TotalStreamLength = EncWsPtr->EncWs.OverallStreamBytePos;
      EncWsPtr->EncWs.StreamComplete = Exi_BT_True;
    }
    else
    {
      /* EncWsPtr->EncWs.CurrentStreamSegmentLen already written in Exi_VBSWriteBits() or nothing was written */
      EncWsPtr->EncWs.StreamComplete = Exi_BT_False;

      /* Check if the stream length should be calculated */
      if (EncWsPtr->EncWs.CalculateStreamLength == Exi_BT_True)
      {
        EncWsPtr->EncWs.TotalStreamLength = EncWsPtr->EncWs.OverallStreamBytePos;
      }
      else
      {
        EncWsPtr->EncWs.TotalStreamLength = 0;
      }
    }
#else
# if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
    EncWsPtr->EncWs.TotalStreamLength = (EncWsPtr->EncWs.PBufProcessedElementBytes + EncWsPtr->EncWs.BytePos) - EncWsPtr->EncWs.StartOffset;
# else
    EncWsPtr->EncWs.TotalStreamLength = EncWsPtr->EncWs.BytePos - EncWsPtr->EncWs.StartOffset;
# endif
#endif
    retVal = E_OK;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_FINALIZE_EXI_STREAM, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}


/**********************************************************************************************************************
 *  Exi_Decode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Exi_ReturnType, EXI_CODE) Exi_Decode( P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_ReturnType retVal;

  /* #10 Check plausibility of input parameters */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  retVal = EXI_E_NOT_OK;
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (DecWsPtr->OutputData.MemAllocWs.BufferPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  else if (DecWsPtr->DecWs.PBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (DecWsPtr->DecWs.PBufPtr[DecWsPtr->DecWs.PBufIdx].len == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (DecWsPtr->DecWs.BytePos >= DecWsPtr->DecWs.PBufPtr[DecWsPtr->DecWs.PBufIdx].len)
  {
    errorId = EXI_E_INV_PARAM;
  }
#else
  else if (DecWsPtr->DecWs.BufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (DecWsPtr->DecWs.BufLen == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (DecWsPtr->DecWs.BytePos >= DecWsPtr->DecWs.BufLen)
  {
    errorId = EXI_E_INV_PARAM;
  }
#endif
  else if (DecWsPtr->OutputData.MemAllocWs.BufferSize == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (DecWsPtr->OutputData.MemAllocWs.BufferOffset >= DecWsPtr->OutputData.MemAllocWs.BufferSize)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (DecWsPtr->OutputData.SchemaSetId >= EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Read EXI header */
    Exi_VBSReadHeader(&DecWsPtr->DecWs);
    retVal = DecWsPtr->DecWs.StatusCode;
    /* #30 If reading was OK, call the decode function of the specific schema set */
    if(retVal == EXI_E_OK)
    {
      if (EXI_UNKNOWN_SCHEMA_SET_TYPE > DecWsPtr->OutputData.SchemaSetId)                                               /* PRQA S 2991, 2995 */ /* MD_Exi_SchemaSetCheck */
      {
        if(Exi_DecoderFcts[DecWsPtr->OutputData.SchemaSetId] != NULL_PTR)
        {
          Exi_DecoderFcts[DecWsPtr->OutputData.SchemaSetId](DecWsPtr);
          retVal = DecWsPtr->DecWs.StatusCode;
        }
        else
        {
          retVal = EXI_E_NOT_OK;
        }
      }
      else
      {
        retVal = EXI_E_NOT_OK;                                                                                          /* PRQA S 2880 */ /* MD_Exi_SchemaSetCheck */
      }
    }
    /* #40 If no error did occur: Calculate the decoded EXI stream length, it may be checked in the calling module */
    if (retVal == EXI_E_OK)
    {
      if(DecWsPtr->DecWs.BitPos != 0u)
      {
        DecWsPtr->DecWs.BitPos = 0;
        DecWsPtr->DecWs.BytePos++;
      }
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
      DecWsPtr->DecWs.TotalStreamLength = (DecWsPtr->DecWs.PBufProcessedElementBytes + DecWsPtr->DecWs.BytePos) - DecWsPtr->DecWs.StartOffset;
#else
      DecWsPtr->DecWs.TotalStreamLength = DecWsPtr->DecWs.BytePos - DecWsPtr->DecWs.StartOffset;
#endif
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_DECODE, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}

/**********************************************************************************************************************
 *  Exi_InitMemAllocWorkspace
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Exi_ReturnType, EXI_CODE) Exi_InitMemAllocWorkspace(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, EXI_APPL_VAR) MemAllocWorkspace,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) BufferPtr,
  uint32 BufferOffset,
  uint32 BufferSize)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_ReturnType retVal = EXI_E_NOT_OK;
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;

  /* #10 Check if input parameters are not plausible */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (MemAllocWorkspace == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (BufferPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (BufferSize == 0u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (BufferOffset >= BufferSize)
  {
    errorId = EXI_E_INV_PARAM;
  }
  /* #20 Otherwise */
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  {
    /* #30 Assign buffer parameters to workspace */
    MemAllocWorkspace->BufferOffset = BufferOffset;
    MemAllocWorkspace->BufferSize = BufferSize;
    MemAllocWorkspace->BufferPtr = BufferPtr;

    retVal = EXI_E_OK;
  }

  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_INIT_MEM_ALLOC_WORKSPACE, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}

/**********************************************************************************************************************
 *  Exi_AllocateElementFromBufferWs
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
FUNC(void*, EXI_CODE) Exi_AllocateElementFromBufferWs(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, EXI_APPL_VAR) BufferWs,
  uint32 ElementSize,
  Exi_BooleanType IncrementStorageBuffer)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  P2VAR(void, AUTOMATIC, EXI_APPL_DATA) outPtr = NULL_PTR;
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;

  /* #10 Check if input parameters are not plausible */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (BufferWs == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (BufferWs->BufferPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #20 Otherwise check if element fits into the given buffer */
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  if (ElementSize < (BufferWs->BufferSize - BufferWs->BufferOffset))
  {
    outPtr = (void*)(&BufferWs->BufferPtr[BufferWs->BufferOffset]);                                                     /* PRQA S 0314 */ /* MD_Exi_VoidCast */
    (void)Exi_ClearMemory(&BufferWs->BufferPtr[BufferWs->BufferOffset], ElementSize);                                   /* PRQA S 0315 */  /* MD_Exi_ImplicitPointerConversion */

    /* #30 Check if storage buffer offset shall be incremented */
    if (IncrementStorageBuffer == Exi_BT_True)
    {
      BufferWs->BufferOffset += ElementSize;
    }
    /* #40 Otherwise */
    else
    {
      /* Keep storage buffer offset */
    }
  }
  /* #50 Otherwise */
  else
  {
    /* outPtr = NULL_PTR already */
  }

  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_MEM_ALLOC, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */

  return outPtr;
}

/**********************************************************************************************************************
 *  Exi_GetRemainingBufferSizeFromBufferWs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint32, EXI_CODE) Exi_GetRemainingBufferSizeFromBufferWs(
  P2CONST(Exi_MemAllocWorkspaceType, AUTOMATIC, EXI_APPL_VAR) BufferWs)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  uint32 remainingBufferSize = 0;
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;

  /* #10 Check if input parameters are not plausible */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (BufferWs == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (BufferWs->BufferPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (BufferWs->BufferOffset > BufferWs->BufferSize)
  {
    errorId = EXI_E_INVALID_PBBUF_POS;
  }
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #20 Otherwise calculate remaining buffer size */
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  {
    remainingBufferSize = BufferWs->BufferSize - BufferWs->BufferOffset;
  }

  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_MEM_ALLOC, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */

  return remainingBufferSize;
}

/**********************************************************************************************************************
 *  Exi_IncrementBufferOffsetInBufferWs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Exi_ReturnType, EXI_CODE) Exi_IncrementBufferOffsetInBufferWs(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, EXI_APPL_VAR) BufferWs,
  uint32 BufferOffsetIncrement)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_ReturnType retVal = EXI_E_NOT_OK;
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;

  /* #10 Check if input parameters are not plausible */
#if ( EXI_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (BufferWs == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (BufferWs->BufferPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #20 Otherwise check if the offset increment does not fit into the given buffer */
  else
#endif /* (EXI_DEV_ERROR_DETECT == STD_ON) */
  if ( BufferOffsetIncrement > (BufferWs->BufferSize - BufferWs->BufferOffset) )
  {
    retVal = EXI_E_BUFFER_SIZE;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 Increment buffer offset */
    BufferWs->BufferOffset += BufferOffsetIncrement;
    retVal = E_OK;
  }

  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_MEM_ALLOC, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#if EXI_ENABLE_PBUF_SUPPORT == STD_ON
/**********************************************************************************************************************
 *  Exi_CheckPBufConsistency
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
EXI_LOCAL FUNC(Exi_ReturnType, EXI_CODE) Exi_CheckPBufConsistency(
  P2CONST(IpBase_PbufType, AUTOMATIC, EXI_APPL_DATA) PBufPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  P2CONST(IpBase_PbufType, AUTOMATIC, EXI_APPL_DATA) currentPBufSegmentPtr = &PBufPtr[0];
  Exi_ReturnType retVal = EXI_E_NOT_OK;
  uint32 processedLength = 0;
  uint32 firstElementTotLen = currentPBufSegmentPtr->totLen;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* 'PBufPtr == NULL_PTR' is already checked in all calling API's */

  /* #10 Loop over all PBuf elements to check if PBuf is consistent */
  while (processedLength < firstElementTotLen)
  {
    retVal = EXI_E_INCONSISTEN_PBUF;
    /* #20 Segment size must not be set to 0 */
    if (currentPBufSegmentPtr->len == 0u)
    {
    }
    /* #30 Payload pointer must not be set to NULL_PTR */
    else if (currentPBufSegmentPtr->payload == NULL_PTR)
    {
    }
    /* #40 Value of totLen must be the same for all segments */
    else if (firstElementTotLen != currentPBufSegmentPtr->totLen)
    {
    }
    /* #50 Size of all segements cannot be bigger than total length */
    else if ( currentPBufSegmentPtr->totLen < (processedLength + currentPBufSegmentPtr->len) )
    {
    }
    /* #60 Segment is OK */
    else
    {
      /* #70 Mark the current segment length as processed */
      processedLength += currentPBufSegmentPtr->len;
      /* #80 Check if switching to next segment is required */
      if (processedLength < firstElementTotLen)
      {
        /* #90 Increment the PBuf to the next element, its existence is ensured by adding all len elements up to the totLen element value */
        currentPBufSegmentPtr = &currentPBufSegmentPtr[1];
      }
      retVal = EXI_E_OK;
    }
    /* #100 Check if the current segment was OK */
    if (retVal != EXI_E_OK)
    {
      /* #110 If not: Report DET, end the loop and return error */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
      (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, (uint8)EXI_API_ID_V_INTERNAL_FUNCTION, EXI_E_INV_PARAM);
#endif
      break;
    }
  }

  return retVal;
}
#endif /* EXI_ENABLE_PBUF_SUPPORT */


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* module specific MISRA deviations:
 MD_Exi_1.1_0857:
      Reason:     Number of macro definitions is huge but improves readability. (rule 0857)
      Risk:       Some compilers might have a problem with too many macro definitions.
      Prevention: Use only compilers supporting more than 1024 macro definitions.
 MD_Exi_1.1:
      Reason:     Nesting of control structures is exceeded because the generated state machine is based on XSD and EXI structure.
      Risk:       No risk.
      Prevention: Covered by code review.
 MD_Exi_1.1_0739_SwitchCase:
      Reason:     Switch case has more than 257 cases. This is required by underlaying schema.
      Risk:       Only compilers are supported that support more than 257 cases.
      Prevention: Covered by test runs with multiple compilers and Vector internal delivery process.
 MD_Exi_5.1:
      Reason:     Identifiers are derived from the XSD schema definition. Therefore some names do not differ within the first 31 characters.
      Risk:       No risk, this is generated code.
      Prevention: Not required.
 MD_Exi_5.6:
      Reason:     Elements with multiple occurrences in the schema need to include a pointer to a structure from the same type. Therefore this typedef is required.
      Risk:       No risk, this is generated code.
      Prevention: Covered by code review.
 MD_Exi_5.6_0781:
      Reason:     Variable name 'errorId' is given by the Vector process, it is only used as local variable in the EXI module.
                  Usage in a struct is related to other modules.
      Risk:       No risk.
      Prevention: Covered by code review.
 MD_Exi_CastingtoDifferentObjectPtr:
      Reason:     EXI data is stored in the EXI workspace storage. Structures are placed inside this storage container and linked
                  using pointers to sub-structures. Casting to the required structure type is required here.
      Risk:       In all cases, it has to be ensured, that the storage size is checked first and when placing structures inside
                  the EXI storage area the memory has to be cleared completely.
      Prevention: Covered by code review.
 MD_Exi_3305:
      Reason:     Structures are cast over an uint8 array. The uint8 Buffer has to be aligned by the EXI user and structure padding shall be
                  enabled in the compiler or optionally in the EXI configuration tool.
      Risk:       Miss-alignment exceptions.
      Prevention: Covered by code review of EXI user components (e.g. SCC).
 MD_Exi_PointerConversion:
      Reason:     Necessary when dealing with memory allocation functions.
      Risk:       Pointer that is not correctly aligned, resulting in undefined behavior.
      Prevention: Covered by code review.
 MD_Exi_13.3_2024:
      Reason:     Exi does not support only one return per function. That is why the final 'case' or 'default' clause in this switch statement contains a "return;" and not a "break;"
      Risk:       No Risk.
      Prevention: Covered by code review.
 MD_Exi_13.7:
      Reason:     This condition is always true based on configuration.
      Risk:       No risk.
      Prevention: Covered by code review.
 MD_Exi_13.7_14.1_Enum:
      Reason:     This condition is always true. An enumeration value may not be out of its range, however it is possible. Since value may be read from bus systems,
                  there may communication errors and therefore invalid values. The 'else' path of this 'if' statement is reported as unreachable.
      Risk:       No risk.
      Prevention: No prevention required, enumeration is just checked to have valid values only.
MD_Exi_14.2:
      Reason:     Control instruction modified inside the body of the loop to set the value to the current elements (multiple occurence element). This allows a max check
      against the schema defined value.
      Risk:       If not followed by a break this could lead to an error.
      Prevention: Covered by code review.
 MD_Exi_14.5:
      Reason:     Continue statement used when EE event already encoded.
      Risk:       No risk.
      Prevention: Covered by code review.
 MD_Exi_14.6_3333:
      Reason:     The break statement is used in an 'if' condition path, the else does contain a return. Due to code generation the content after the 'else'
                  path is used in multiple parts of the code that do not include this 'if' path.
      Risk:       No risk.
      Prevention: Covered by code review.
 MD_Exi_16.2:
      Reason:     Generic elements may include other generic elements. Therefore recursion is required for this elements.
      Risk:       No risk. Debugging code only. Schema deviation support shall be switched off in production code.
      Prevention: Covered by code review.
 MD_Exi_16.3_2020:
      Reason:     Exi does not support only one return per function. That is why the final 'case' or 'default' clause in this switch statement contains a "return;" and not a "break;"
      Risk:       No Risk.
      Prevention: Covered by code review.
 MD_Exi_18.4:
      Reason:     XSD choice elements are represented as unions for optimization reasons. Flags ensure that the application selects the correct type.
      Risk:       No risk, this is generated code.
      Prevention: Covered by code review.
 MD_Exi_19.11_3332:
      Reason:     QA-C MISRA checker does not recognize the pre-processor switch is checked for 'define' first and then for its value.
      Risk:       No Risk.
      Prevention: Covered by code review.
 MD_Exi_19.15_0883:
      Reason:     QA-C MISRA checker does not recognize the protection against multiple header include correctly.
      Risk:       No Risk.
      Prevention: Covered by code review.
 MD_Exi_CircularInclude_0883:
      Reason:     QA-C MISRA checker does complain about a missing include guard which is caused by the design
                  of the Exi include structure: The Exi_Schema<Encoder/Decoder>.h does include all the schema specific
                  header files in the required order which then may cause a circular include of the current file.
                  This is a bug in the static analysis tool since the tools seems to be not able to deal with already activated
                  include guards. The finding is issued at the last line of the file.
                  Therefore the justification is placed at the bottom of the file until the end of the file.
                  Justification at the #include that causes the circular include seems not to be possible.
      Risk:       Other include issues may be hidden by this justification.
      Prevention: Covered by code review.
 MD_Exi_21.1_0291:
      Reason:     Two unsigned integers are subtracted from each other 'BitCount - bitsRemain'. The function ensures
                  that bitsRemain is always smaller than or equal to BitCount.
      Risk:       Possible wrapp arround of the result.
      Prevention: Covered by code review.
 MD_Exi_21.1_3382:
      Reason:     Missing elements are signaled by their flag. In case an element is not present it is required to
                  decrement the event code by the amount of events of the missing element. The flags are previously
                  set according to the event code that is decremented here. There for the event code should never be
                  decremented below 0. Negative event codes are invalid, as well as there are no known schemata with
                  more than 2147483647 event codes. There for an event code below 0 would be threated as the same
                  error than an event code bigger 2147483647.
      Risk:       No risk, independent of the value (-1 or 4294967295) EXI will abort the decoding and report an error.
      Prevention: Covered by code review (make sure that there are no types in the schema with more than 2147483647
                  optional elements).
 MD_Exi_EventCodeCast:
      Reason:     All elements in Exi are read as event code and required to cast them to specific enums.
      Risk:       No Risk.
      Prevention: Covered by code review.
 MD_Exi_MultipleReturnsPaths:
      Reason:     Exi modules does not support unique exit point per function. Code is generated and change to single return
                  would require a complete re-design of the code generator.
      Risk:       No Risk.
      Prevention: Covered by code review.
 MD_Exi_SchemaSetCheck:
      Reason:     Schema set Id can change from configuration to another. Therefore a check if schema set id is valid
                  or not is necessary.
      Risk:       No Risk.
      Prevention: Covered by code review.
 MD_Exi_NextPtrCheck:
      Reason:     Next pointer has always the next element of the list. If the list filled or ended nextPtr shall be set to
                  NULL_PTR. Exi_Encode_{element type} will return NULL_PTR in this case. If list is very long nextPtr != NULL_PTR
                  should be True and error code EXI_E_LIST_TO_LONG is set.
      Risk:       No Risk.
      Prevention: Covered by code review and by test having different list sizes.
 MD_Exi_EndElementTagCheck:
      Reason:     Condition is not always true. "for" loop may break before reaching the end of the list(EXI_MAXOCCURS_{list element type})).
                  Tp prevent some unexpected state. A check is needed to verify that EE of that unbounded list is found.
      Risk:       No Risk.
      Prevention: Covered by code review and by test having max list size.
 MD_Exi_RedundantInitialization:
      Reason:     Value of the object shall be set to prevent other compilers from throwing warnings or failing.
      Risk:       No Risk.
      Prevention: Covered by code review.
 MD_Exi_RedundantAssignement:
      Reason:     The value set is never used. However, we will keep it that way in the code generator just to ensure correct
                  handling of event code when with any new schema.
      Risk:       No Risk.
      Prevention: Covered by code review.
 MD_Exi_NoSpecificEncodeFunction:
      Reason:     Under some configuration(all schema encode disabled for example), a check if no schema specific encode function
                  was called is very important to have. MISRA will always complain about it as long as encode of at least one schema is valid
                  from configuration point of view.
      Risk:       No Risk.
      Prevention: Covered by code review.
 MD_Exi_PointerLifeTime:
      Reason:     Pointer value of the local object in this position has shorter life time but it should be enough until the generic
                  content is decoded.
      Risk:       Wrong/local pointers may be provided to this API, which may lead to later invalid memory accesses.
      Prevention: Covered by code review.
 MD_Exi_FunctionParameter:
      Reason:     In some cases and due to nature of Exi module, function parameters in Exi can be modified.
      Risk:       No Risk because any change in function parameter is intented to be.
      Prevention: Covered by code review.
 MD_Exi_CastingDifferentObject;
      Reason:     Cast from schema BodyBaseType to specific Exi type is safe.
      Risk:       Cast to a type with stricter alignment requirements will result in undefined behavior.
      Prevention: Covered by code review.
 MD_Exi_ImplicitPointerConversion:
      Reason:     Conversion is necessary because data stored under structure  Exi_GenericStringType is cast using pointers to Genereic Element
                  sub element GenericContent or GenericQName both of type void*. .
      Risk:       Pointer that is not correctly aligned, resulting in undefined behaviour.
      Prevention: Covered by code review.
 MD_Exi_VoidCast:
      Reason:     Conversion is necessary because data stored under pointer structure types.
      Risk:       Pointer that is not correctly aligned, resulting in undefined behaviour.
      Prevention: Covered by code review.
 MD_Exi_NoDataChange:
      Reason:     The main type is using XMLSIG types by reference. This means that under some configuration where XMLSIG maybe disabled
                  compeletely from the code, structPtr maybe declared without really being used to modify the data it addresses or contain.
      Risk:       As long as the pointer declared as ponter to const-qualified type, there is always a risk that data referenced may be unintentionally
                  modified in that Api without a proper review.
      Prevention: Covered by code review.
 MD_Exi_DataFlowAnalysisTimeout:
      Reason:     Some APIs are very complex, the reason for that is because they are mostly generated from a schema
                  file, which is defined by the ISO15118 or DIN70121. This schema files cannot be influenced by Vector
                  so the complexity of defined types cannot be changes. Since each type does result in one API
                  for processing this type, the complexity of the APIs is defined by the relevant schema. In the
                  generated code this justification is applyed to all APIs, because the occurence of this finding
                  depends on the machine that runs the MISRA analysis (on slower machines this finding may occur more
                  often than on faster machines).
                  During development, the Dataflow analysis of the following APIs was abort due to the used timeout:
                  - Timeout 60 s (Vector PES QuickTest timeout):
                   -- Exi_VBSDecodeGenericElementContent (static code)
                  - Timeout 4800 s (Vector PES default timeout):
                   -- Currently no known functions
      Risk:       There may be MISRA Dataflow analysis findings that may be found in case the analysis would not time
                  out.
      Prevention: The final test report will only contain the report that was generated during the QuickTest run.
                  How ever the analysis has been executed using the default timeout without additional findings
                  during development.
 MD_Exi_MultipleBreaks:
      Reason:       Multiple break statements used to exit from for-loop immediately in case of next the tag has event code or
                    the EE of parent has been reached.
      Risk:         There is no risk.
      Prevention:   Covered by code review.
 MD_Exi_BufferLengthChecked:
      Reason:       The StrLen which is used as pointer index for StrBufPtr has just been checked in the sorrounding
                    IF to be in range of StrBufLenPtr. This finding seems to be a false positive.
      Risk:         There is no risk.
      Prevention:   Covered by code review.
*/
/**********************************************************************************************************************
 *  END OF FILE: Exi.c
 *********************************************************************************************************************/
