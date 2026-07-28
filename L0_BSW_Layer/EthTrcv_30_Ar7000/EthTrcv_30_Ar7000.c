/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EthTrcv_30_Ar7000.c
 *        \brief  Ethernet transceiver driver QCA 7005 main source file
 *
 *      \details  Vector static code implementation for the Ethernet transceiver driver QCA 7005 module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file EthTrcv_30_Ar7000.h.
 *********************************************************************************************************************/

#define ETHTRCV_30_AR7000_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0828 ETHTRCV_30_AR7000_C_IF_NESTING */ /* MD_EthTrcv_30_Ar7000_OtherModules */
#include "EthTrcv_30_Ar7000.h"
#include "EthTrcv_30_Ar7000_Priv.h"
#include "EthTrcv_30_Ar7000_Prot.h"
#include "EthIf.h"
#include "IpBase.h"

#if (STD_ON == ETHTRCV_30_AR7000_ENABLE_SM_HOOK_ROUTINE)
#include "_EthTrcv_30_Ar7000_Cbk.h"
#endif
#include "EthTrcv_30_Ar7000_Lcfg.h"
#include "EthTrcv_30_Ar7000_Types.h"

/* PRQA L:ETHTRCV_30_AR7000_C_IF_NESTING */ /* MD_EthTrcv_30_Ar7000_OtherModules */

/**********************************************************************************************************************
 *  Binary Includes
 *********************************************************************************************************************/
#if (defined ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD )
#include "_EthTrcv_30_Ar7000_Memctrl.h"
#include "_EthTrcv_30_Ar7000_Firmware.h"
#include "_EthTrcv_30_Ar7000_Pib.h"
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check consistency of source and header file. */
#if ( (ETHTRCV_30_AR7000_SW_MAJOR_VERSION != 10U) || \
      (ETHTRCV_30_AR7000_SW_MINOR_VERSION != 1U) || \
      (ETHTRCV_30_AR7000_SW_PATCH_VERSION != 1U) )
  #error "EthTrcv_30_Ar7000.c: Source and Header file are inconsistent!"
#endif

/**************************************************************************************************
* Local defines
**************************************************************************************************/
#define ETHTRCV_30_AR7000_UINT32_MAX_VALUE        0xFFFFFFFFUL

#define ETHTRCV_30_AR7000_NO_WAIT_ON_CONF                0x00U
#define ETHTRCV_30_AR7000_WAIT_ON_CONF                   0x01U

#define ETHTRCV_30_AR7000_STATE_NOT_READY                0x00U
#define ETHTRCV_30_AR7000_STATE_READY                    0x01U

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
#define ETHTRCV_30_AR7000_DOWNLSTATUS_MEMCTRL               0U
#define ETHTRCV_30_AR7000_DOWNLSTATUS_PIB                   1U
#define ETHTRCV_30_AR7000_DOWNLSTATUS_FW                    2U
#define ETHTRCV_30_AR7000_DOWNLSTATUS_DONE                  3U

#define ETHTRCV_30_AR7000_NO_HST_ACTION_REQUIRED         0xFFU
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */


/* ETHTRCV Module Operation state */
#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK )
#define ETHTRCV_30_AR7000_MODOP_STATE_NOT_USED           0x00U
#define ETHTRCV_30_AR7000_MODOP_STATE_USED               0x01U
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ||
          ETHTRCV_30_AR7000_ENABLE_MODOP_API ||
          ETHTRCV_30_AR7000_ENABLE_READ_NMK */

#ifndef ETHTRCV_30_AR7000_LOCAL
#define ETHTRCV_30_AR7000_LOCAL static
#endif /* ETHTRCV_30_AR7000_LOCAL */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (   (ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON) \
     && (defined(ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD == STD_ON)) )
typedef P2FUNC(void, ETHTRCV_30_AR7000_CODE, EthTrcv_30_Ar7000_FailedApiCallType) \
                                    (uint8 TrcvIdx, P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr);
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD && ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
typedef struct
{
# if ((defined ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (STD_OFF==ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD))
  boolean NeedToSend;
# endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */
  uint32 TotalLen;
  uint32 CurPartLen;
  uint32 CurPartDestAddr;
  uint32 StartAddr;
  EthTrcv_30_Ar7000_EthernetBufferUnionConstType DataPtr;                                                               /* PRQA S 0759 */ /* MD_EthTrcv_30_Ar7000_BufferAccessUnion */
  uint32 Flags;
  uint32 Checksum;
} EthTrcv_30_Ar7000_MME_WaEA_ParamType;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
#if (((defined ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP)) || \
     (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) || \
     ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK))|| \
     ((defined ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API)))
/* PRQA S 0750 5 */ /* MD_EthTrcv_30_Ar7000_AlignedPibData */
typedef union
{
  uint32 U32[ETHTRCV_30_AR7000_PIB_SIZE / 4u];
  uint8  U8[ETHTRCV_30_AR7000_PIB_SIZE];
} EthTrcv_30_Ar7000_AlignedPibDataType;
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP          ||
          ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB  ||
          ETHTRCV_30_AR7000_ENABLE_WRITE_DAK           ||
          ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
#define ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#if ( (STD_ON==ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP) )
VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_WillResetAfterPibUpload;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD && ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP */

#define ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
VAR(EthTrcv_StateType, ETHTRCV_30_AR7000_VAR_ZERO_INIT) EthTrcv_30_Ar7000_State = ETHTRCV_STATE_UNINIT;
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON */

#define ETHTRCV_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
#define ETHTRCV_30_AR7000_START_SEC_CONST_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

CONST(uint8, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_AtherosODA[6u] = {
  0x00u, 0xb0u, 0x52u, 0x00u, 0x00u, 0x01u
};

#define ETHTRCV_30_AR7000_STOP_SEC_CONST_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
#if (((defined ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP)) || \
     (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) || \
     ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK))|| \
     ((defined ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API)))
ETHTRCV_30_AR7000_LOCAL VAR(boolean, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_PibRamCpyValid;
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP          ||
          ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB  ||
          ETHTRCV_30_AR7000_ENABLE_WRITE_DAK           ||
          ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( ETHTRCV_30_AR7000_ENABLE_READ_NMK == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_Nmk[ETHTRCV_30_AR7000_NMK_SIZE_BYTE];
#endif /* ETHTRCV_30_AR7000_ENABLE_READ_NMK */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_SwVersion[48u];
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_SwMStatus;
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_SetPropertyStatus;
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */

#if (   (ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON) \
     && (defined(ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD == STD_ON)) )
/* PRQA S 3218 1 */ /* MD_EthTrcv_30_Ar7000_LastHeaderVar */
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_LastFrHeader[ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE];
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD && ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */

#define ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
#if (((defined ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP)) || \
     (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) || \
     ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK))|| \
     ((defined ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API)))
/* PRQA S 0759 1 */ /* MD_EthTrcv_30_Ar7000_AlignedPibData */
ETHTRCV_30_AR7000_LOCAL VAR(EthTrcv_30_Ar7000_AlignedPibDataType, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_PibRamCpy;
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP          ||
          ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB  ||
          ETHTRCV_30_AR7000_ENABLE_WRITE_DAK           ||
          ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(EthTrcv_30_Ar7000_MME_WaEA_ParamType, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_MME_WaEA_Params; /* PRQA S 0779 */ /* MD_MSR_IdentifierLength */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if (   (ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON) \
     && (defined(ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD == STD_ON)) )
ETHTRCV_30_AR7000_LOCAL EthTrcv_30_Ar7000_FailedApiCallType EthTrcv_30_Ar7000_FailedApiCall;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD && ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK )
ETHTRCV_30_AR7000_LOCAL VAR (EthTrcv_30_Ar7000_ModOp_Rd_Params, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_ModOpParams;
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ||
          ETHTRCV_30_AR7000_ENABLE_MODOP_API  ||
          ETHTRCV_30_AR7000_ENABLE_READ_NMK */

#if (defined ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD )
ETHTRCV_30_AR7000_LOCAL P2CONST(uint8, ETHTRCV_30_AR7000_VAR_NOINIT,  ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_PIBData;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#define ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

ETHTRCV_30_AR7000_LOCAL VAR(uint32, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_CycleCnt;

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint32, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_ClientSid;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */


#define ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint16, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_FwDownloadAndStartCnt;
ETHTRCV_30_AR7000_LOCAL VAR(uint16, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_FwReadyForSlacCnt;                  /* PRQA S 0779 */ /* MD_MSR_IdentifierLength */
ETHTRCV_30_AR7000_LOCAL VAR(uint16, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_LinkStateLockCnt;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

ETHTRCV_30_AR7000_LOCAL VAR(uint16, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_HeartBeatCnt;

#if ( ETHTRCV_30_AR7000_ENABLE_READ_NMK == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint16, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_ReadNmkCycCnt;
#endif /* ETHTRCV_30_AR7000_ENABLE_READ_NMK */

#if ( ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint16, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_SCConfCycCnt;
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint16, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_GetSwVersionCycCnt;
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint16, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_SetPropertyCycCnt;
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK )
ETHTRCV_30_AR7000_LOCAL VAR(uint16, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_ModOpCycCnt;
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ||
          ETHTRCV_30_AR7000_ENABLE_MODOP_API  ||
          ETHTRCV_30_AR7000_ENABLE_READ_NMK */

#define ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

ETHTRCV_30_AR7000_LOCAL VAR(EthTrcv_LinkStateType, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_LinkState;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_DwldAttempts;
ETHTRCV_30_AR7000_LOCAL VAR(EthTrcv_ModeType, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_ModeState;

#if ( ETHTRCV_30_AR7000_ENABLE_READ_NMK == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_IsReadingNmk;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_NmkReady;
#endif /* ETHTRCV_30_AR7000_ENABLE_READ_NMK */

#if ( ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_IsChangingSCState;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_SCStateConfReady;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_PbAvlnStatus;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_PbMStatus;
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_NMK == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_SetKeyIsChanging;
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_NMK */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_IsReadingSwVersion;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_SWVersionAvailable;
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_IsSettingProperty;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_SetPropertyCnfAvailable;
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_DownlStatus;
# if (defined(ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD == STD_ON))
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_ApiCallRetCnt;
# endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_WriteAppletLockCnt;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_AppletNrLocked;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_HstActionIdx;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_HstActionCnt;
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_HstAction[ETHTRCV_30_AR7000_HST_ACTION_QUEUE_SIZE];

ETHTRCV_30_AR7000_LOCAL VAR(boolean, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_FwDwldStartCbkCalled;
ETHTRCV_30_AR7000_LOCAL VAR(boolean, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_FwStartedCbkCalled;
ETHTRCV_30_AR7000_LOCAL VAR(boolean, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_FwReadyForSlacCbkCalled;           /* PRQA S 0779 */ /* MD_MSR_IdentifierLength */
ETHTRCV_30_AR7000_LOCAL VAR(boolean, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_FwReadyForSlacLastResult;          /* PRQA S 0779 */ /* MD_MSR_IdentifierLength */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */


#if ( ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP == STD_ON ) || \
    ( ETHTRCV_30_AR7000_ENABLE_READ_NMK == STD_ON ) ||\
    ( ETHTRCV_30_AR7000_ENABLE_MODOP_API == STD_ON )
ETHTRCV_30_AR7000_LOCAL VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_ModOpRetryCnt;
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ||
          ETHTRCV_30_AR7000_ENABLE_READ_NMK   ||
          ETHTRCV_30_AR7000_ENABLE_MODOP_API */

#define ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define ETHTRCV_30_AR7000_START_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_GetSwVersion
 **********************************************************************************************************************/
/*!
 * \brief       Sends a get version request MME to the QCA.
 * \details     -
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \return      E_OK           The host has successfully send the request MME.
 * \return      E_NOT_OK       Request a ethernet buffer or ethernet transmission failed.
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_GetSwVersion(
  uint8 TrcvIdx);
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

#if (ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API == STD_ON)
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_SetProperty
 **********************************************************************************************************************/
/*!
 * \brief       Sends a set property request MME to the QCA.
 * \details     -
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \param[in]   SetPropParams  Pointer to valid property parameter block
 * \return      E_OK           The host has successfully send the request MME.
 * \return      E_NOT_OK       Request a ethernet buffer or ethernet transmission failed.
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_SetProperty(
  uint8  TrcvIdx,
  CONSTP2CONST(EthTrcv_30_Ar7000_SetPropertyParamterType, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_CONST)
    SetPropParams);
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */

#if (ETHTRCV_30_AR7000_ENABLE_SET_NMK == STD_ON)
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_SetKey
 **********************************************************************************************************************/
/*!
 * \brief       Sends a set key request MME to the QCA.
 * \details     -
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \param[in]   NmkPtr         Pointer to network membership key
 * \return      E_OK           The host has successfully send the request MME.
 * \return      E_NOT_OK       Request a ethernet buffer or ethernet transmission failed.
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_SET_NMK
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_SetKey(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) NmkPtr);
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetKeyCnfStatus
 **********************************************************************************************************************/
/*!
 * \brief       Read 'set network membership key' result.
 * \details     Rx-Handler for 'set key' confirm MME received from the QCA.
 * \param[in]   TrcvIdx         Zero based index of the transceiver
 * \param[in]   DataPtr         Received Ethernet frame starting at the MME Version
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_SET_NMK
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetKeyCnfStatus(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr);
#endif /* (ETHTRCV_30_AR7000_ENABLE_SET_NMK == STD_ON) */

#if ( ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_ResetDevice
 **********************************************************************************************************************/
/*!
 * \brief       Sends a reset device request MME to the QCA
 * \details     -
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \return      E_OK           The host has successfully send the request MME.
 * \return      E_NOT_OK       Request a ethernet buffer or ethernet transmission failed.
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_ResetDevice(
  uint8 TrcvIdx);
#endif /* ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE */

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetLinkStatus
 **********************************************************************************************************************/
/*!
 * \brief       Read the QCA link-state.
 * \details     Rx-Handler for 'powerline link status' confirm MME received from the QCA. Read the link-state and
 *              reset the heart beat counter if it up.
 * \param[in]   TrcvIdx         Zero based index of the transceiver
 * \param[in]   DataPtr         Received Ethernet frame starting at the MME Version
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetLinkStatus(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr);

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API )
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_PBEncryption
 **********************************************************************************************************************/
/*!
 * \brief       Sends a 'push button encryption' request MME to the QCA.
 * \details     -
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \param[in]   PBAction       Push Button Action
 * \return      E_OK           The host has successfully send the request MME.
 * \return      E_NOT_OK       Request a ethernet buffer or ethernet transmission failed.
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_PBEncryption(
  uint8 TrcvIdx,
  uint8 PBAction);

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_PBEncryption
 **********************************************************************************************************************/
/*!
 * \brief       Triggers a push button encryption MME transmission.
 * \details     Triggering a push button encryption MME request if no request is pending. The function is also used to
 *              poll the communication status and to get the QCA confirmation result.
 * \param[in]   TrcvIdx          Zero based index of the transceiver
 * \param[in]   PBAction         Push Button Action
 *                               range:
 *                                 1=Start Simple Connect
 *                                 2=Randomize NMK
 *                                 3=Read AVLN Membership Status)
 *                                 4=Reset Factory Default
 * \param[out]  MStatus          Received MME confirmation status
 * \param[out]  AVLNStatus       HomePlug AV Logical-Network status
 * \return      ETHTRCV_30_AR7000_RT_OK      Pushbutton encryption action was successful
 * \return      ETHTRCV_30_AR7000_RT_NOT_OK  Pushbutton encryption timeout was expired or a failure occurred during
 *                                           MME sending
 * \return      ETHTRCV_30_AR7000_RT_PENDING QCA MME confirmation is pending
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API
 */
ETHTRCV_30_AR7000_LOCAL FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_PBEncryption(
        uint8                                                          TrcvIdx,
        EthTrcv_30_Ar7000_PBActionType                                 PBAction,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) MStatus,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) AVLNStatus);

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetPBEncryptionStatus
 **********************************************************************************************************************/
/*!
 * \brief       Reads 'push button encryption' MME result.
 * \details     Rx-Handler for 'push button encryption' confirm MME received from the QCA.
 * \param[in]   TrcvIdx         Zero based index of the transceiver
 * \param[in]   DataPtr         Received Ethernet frame starting at the MME Version
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetPBEncryptionStatus(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr);
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetSoftwareVersion
 **********************************************************************************************************************/
/*!
 * \brief       Reads 'get software version' MME result.
 * \details     Rx-Handler for 'get software version' confirm MME received from the QCA.
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \param[in]   DataPtr        Received Ethernet frame starting at the MME Version
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetSoftwareVersion(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr);
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_HandleGetLinkState
 **********************************************************************************************************************/
/*!
 * \brief       Sends a cyclical link state request message
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_HandleGetLinkState(void);

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_HandleFirmwareRestart
 **********************************************************************************************************************/
/*!
 * \brief       Handles restarts of the firmware in error cases
 * \details     Resets the QCA and retries the firmware download.
 * \param[in]   CallFwStartCbk Inform the application about a failed firmware download
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_HandleFirmwareRestart(
  boolean CallFwStartCbk);

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_HstActionRequired
 **********************************************************************************************************************/
/*!
 * \brief       Triggers 'host action' confirm MME.
 * \details     Rx-Handler for 'host action' request MME received from the QCA. Triggering a 'host action' confirm MME
 *              transmission to the QCA and the future host action processing.
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \param[in]   DataPtr        Received Ethernet frame starting at the MME Version
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD
 */
/* PRQA S 0779 2 */ /* MD_MSR_IdentifierLength */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_HstActionRequired(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_HstActionRequiredSecondPhase
 **********************************************************************************************************************/
/*!
 * \brief       Triggers the specific 'host action' MME requested by the 'host action' request MME.
 * \details     Send a specific MME request related on the 'HostAction' after the 'host action confirm' MME was
 *              transmitted to the QCA.
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD
 */
/* PRQA S 0779 2 */ /* MD_MSR_IdentifierLength */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_HstActionRequiredSecondPhase(
  uint8 TrcvIdx);

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet
 **********************************************************************************************************************/
/*!
 * \brief       Sends a 'write and execute applet' request to the QCA.
 * \details     This MME is needed for the firmware download process which includes: softloader applet, PIB block and
 *              the firmware.
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \param[in]   Params         Parameter needed for the downloading process e.g. offset address. This parameter is
 *                             different for each component (softloader applet, PIB block, firmware).
 * \return      E_OK           The host has successfully send the request MME.
 * \return      E_NOT_OK       Request a ethernet buffer or ethernet transmission failed.
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
          uint8                                                                                             TrcvIdx,
  P2CONST(EthTrcv_30_Ar7000_MME_WaEA_ParamType, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_CONST) Params );

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_HostAction
 **********************************************************************************************************************/
/*!
 * \brief       Sends 'host action' response MME to QCA
 * \details     This MME is needed to reply to the 'host action' request MME message.
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \param[in]   HarRequestPtr  Host-Action-Request data received from the QCA
 * \return      E_OK           The host has successfully send the response MME.
 * \return      E_NOT_OK       Request a ethernet buffer or ethernet transmission failed.
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_HostAction(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) HarRequestPtr);

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_WriteAndExecuteApplet
 **********************************************************************************************************************/
/*!
 * \brief       Triggers 'write and execute applet' request MME.
 * \details     Sends data chunks needed for the boot process (softloader applet, PIB block and firmware) to the QCA.
 *              It is also possible to send only the firmware e.g. for firmware update.
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \param[in]   DataPtr        Received Ethernet frame starting at the MME Version
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous FALSE
 * \config      ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_WriteAndExecuteApplet(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_VCalcChecksum
 **********************************************************************************************************************/
/*!
 * \brief       Calculates a checksum.
 * \details     Compute the 32 bit checksum of a memory segment. The calculated checksum is the one's complement of
 *              the XOR of all 32-bit words.
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \param[in]   DataPtr        Memory segment start
 * \param[in]   DataLenByte    Memory segment size in bytes
 * \return      uint32         32bit checksum of a given memory segment
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD
 * \note        The DataLenBytes should be an even multiple of 4-bytes or trailing bytes will be excluded from the
 *              calculation.
 */
ETHTRCV_30_AR7000_LOCAL FUNC(uint32, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_VCalcChecksum(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr,
          uint32                                                           DataLenByte);
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK )   ||   \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API )
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_ModuleOperation
 **********************************************************************************************************************/
/*!
 * \brief       Reads 'module operation' MME result.
 * \details     Rx-Handler for 'module operation' confirm MME received from the QCA. Verify that the received MME
 *              confirmation is OK. Extract the requested QCA module information. This can be a PIB block or a NMK.
 *              Inform the calling application using the dedicated callbacks if there are available.
 * \param[in]   TrcvIdx         Zero based index of the transceiver
 * \param[in]   DataPtr         Received Ethernet frame starting at the MME Version
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous FALSE
 * \config      ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP || ETHTRCV_30_AR7000_ENABLE_READ_NMK ||
 *              ETHTRCV_30_AR7000_ENABLE_MODOP_API
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_ModuleOperation(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr);
#endif /* STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ||
          STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK   ||
          STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API */

#if ( (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) || \
      ( STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK ))
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_VGetPibModuleOffset
 **********************************************************************************************************************/
/*!
 * \brief       Searching a NVM chain for the existence of a PIB module
 * \details     -
 * \param[in]   PibPtr        The NVM chain were the search is done
 * \param[out]  ModOffset     The PIB module image offset
 * \param[out]  ModHdrOffset  The PIB module header offset
 * \return      E_OK          PIB module found within the given NVM chain
 * \return      E_NOT_OK      PIB module not found within the given NVM chain
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE ||
 *              ETHTRCV_30_AR7000_ENABLE_WRITE_DAK
 */
ETHTRCV_30_AR7000_LOCAL FUNC (uint8, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_VGetPibModuleOffset(
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_DATA)                            PibPtr,
  P2VAR(uint8*, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_DATA)                           ModOffset,
  P2VAR(EthTrcv_30_Ar7000_NVMHeaderType*, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_DATA) ModHdrOffset);
#endif /* ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB ||
          STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  MME's
 **********************************************************************************************************************/
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_GetLinkStatus
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_GetLinkStatus(
  uint8 TrcvIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_EthernetBufferType ethBuf;
  uint8  ethBufIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ethBuf.BufLen = (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE;

  /* #10 Request a ethernet frame buffer for the get link status request MME frame */
  if (BUFREQ_OK == ETHTRCV_30_AR7000_ETH_PROVIDE_TX_BUFFER(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), &ethBufIdx, &(ethBuf.Buffer.Native), &(ethBuf.BufLen)))
  {
    /* #20 Verify requested buffer size */
    if (ethBuf.BufLen >= (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE)
    {
      /* #30 Fill ethernet frame buffer with MME frame header and initialize ethernet frame with zeros
       *       Transmit ethernet frame
       */
      /* This MME doesn't require any further data */
      EthTrcv_30_Ar7000_VFrameHeader(TrcvIdx, (ETHTRCV_30_AR7000_MME_VS_PL_LNK_STATUS | ETHTRCV_30_AR7000_MME_REQ), &ethBuf);
      /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      if (E_OK == ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE,
                    (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE, (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]))
      {
        retVal = E_OK;
      }
    }

    /* #40 Verify transmission and release ethernet buffer if it fails */
    if (E_NOT_OK == retVal)
    {
      /* Release buffer */
      /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u,
                                   (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
    }
  }
  return(retVal);
} /* EthTrcv_30_Ar7000_MME_GetLinkStatus() */

#if (ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON)
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_GetSwVersion
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_GetSwVersion(
  uint8 TrcvIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_EthernetBufferType ethBuf;
  uint8  ethBufIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ethBuf.BufLen = (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE;

  /* #10 Request a ethernet frame buffer for the get software version request MME frame */
  if (BUFREQ_OK == ETHTRCV_30_AR7000_ETH_PROVIDE_TX_BUFFER(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), &ethBufIdx, &(ethBuf.Buffer.Native), &(ethBuf.BufLen)))
  {
    /* #20 Verify requested buffer size */
    if (ethBuf.BufLen >= (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE)
    {
      /* #30 Fill ethernet frame buffer with MME frame header and initialize ethernet frame with zeros
       *       Transmit ethernet frame
       */
      /* This MME doesn't require any further data */
      EthTrcv_30_Ar7000_VFrameHeader(TrcvIdx, (ETHTRCV_30_AR7000_MME_VS_SW_VER | ETHTRCV_30_AR7000_MME_REQ), &ethBuf);
      /* Do not use cookie - already null initialized by EthTrcv_30_Ar7000_VFrameHeader */

      /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      if (E_OK == ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE,
                    (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]))
      {
        /* successful */
        retVal = E_OK;
      }
    }

    /* #40 Verify transmission and release ethernet buffer if it fails */
    if (E_NOT_OK == retVal)
    {
      /* Release buffer */
       /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u,
                                    (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
    }
  }

  return retVal;
} /* EthTrcv_30_Ar7000_MME_GetSwVersion() */
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

#if (ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API == STD_ON)
 /***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_SetProperty
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_SetProperty(
  uint8 TrcvIdx,
  CONSTP2CONST(EthTrcv_30_Ar7000_SetPropertyParamterType, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_CONST) SetPropParams)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) bufPtrSetProperty;
  EthTrcv_30_Ar7000_EthernetBufferType ethBuf;
  uint8  ethBufIdx;
  uint8 u8Idx = 0u;
  Std_ReturnType retVal = E_NOT_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ethBuf.BufLen = (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE + (uint16)SetPropParams->PropDataLength;

  /* #10 Request a ethernet frame buffer for the set property request MME frame */
  if (BUFREQ_OK == ETHTRCV_30_AR7000_ETH_PROVIDE_TX_BUFFER(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), &ethBufIdx, &(ethBuf.Buffer.Native), &(ethBuf.BufLen)))
  {
    /* #20 Verify requested buffer size */
    if (ethBuf.BufLen >= ((uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE + SetPropParams->PropDataLength))
    {
      /* #30 Fill ethernet frame buffer with MME frame header and initialize ethernet frame with zeros */
      EthTrcv_30_Ar7000_VFrameHeader(TrcvIdx, (ETHTRCV_30_AR7000_MME_VS_SET_PROPERTY | ETHTRCV_30_AR7000_MME_REQ), &ethBuf);

      /* #40 Fill ethernet frame with set property request specific portion */
      bufPtrSetProperty = &(ethBuf.Buffer.U8[6]);
      /* Do not use cookie - already null initialized by EthTrcv_30_Ar7000_VFrameHeader */

      /* Option field */
      bufPtrSetProperty[4u] = SetPropParams->Option;
      /* 3 bytes reserved */

      /* Property version field */
      bufPtrSetProperty[8u]  = (uint8) (SetPropParams->PropVersion & 0x000000FFu);
      bufPtrSetProperty[9u]  = (uint8)((SetPropParams->PropVersion & 0x0000FF00u) >> 8u);
      bufPtrSetProperty[10u] = (uint8)((SetPropParams->PropVersion & 0x00FF0000u) >> 16u);
      bufPtrSetProperty[11u] = (uint8)((SetPropParams->PropVersion & 0xFF000000u) >> 24u);

      /* Proprety ID field */
      bufPtrSetProperty[12u] = (uint8) (SetPropParams->PropId & 0x000000FFu);
      bufPtrSetProperty[13u] = (uint8)((SetPropParams->PropId & 0x0000FF00u) >> 8u);
      bufPtrSetProperty[14u] = (uint8)((SetPropParams->PropId & 0x00FF0000u) >> 16u);
      bufPtrSetProperty[15u] = (uint8)((SetPropParams->PropId & 0xFF000000u) >> 24u);

      /* Property Data Length field */
      bufPtrSetProperty[16u] = (uint8) (SetPropParams->PropDataLength & 0x000000FFu);
      bufPtrSetProperty[17u] = (uint8)((SetPropParams->PropDataLength & 0x0000FF00u) >> 8u);
      bufPtrSetProperty[18u] = (uint8)((SetPropParams->PropDataLength & 0x00FF0000u) >> 16u);
      bufPtrSetProperty[19u] = (uint8)((SetPropParams->PropDataLength & 0xFF000000u) >> 24u);

      /* Data field */
      while ( u8Idx < SetPropParams->PropDataLength )
      {
        bufPtrSetProperty[u8Idx + 20u] = SetPropParams->PropData[u8Idx];
        u8Idx++;
      }

      /* #50 Transmit ethernet frame */
      /* PRQA S 0311 4 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      if(E_OK == ETHTRCV_30_AR7000_ETH_TRANSMIT(
                    EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE,
                   (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE + (uint16)SetPropParams->PropDataLength,
                   (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]))
      {
        /* successful */
        retVal = E_OK;
      }
    }

    /* #60 Verify transmission and release ethernet buffer if it fails */
    if (E_NOT_OK == retVal)
    {
      /* Release buffer */
       /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u,
                                    (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
    }
  }

  return(retVal);
} /* EthTrcv_30_Ar7000_MME_SetProperty() */
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet
 **********************************************************************************************************************/
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
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
          uint8                                                                                             TrcvIdx,
  P2CONST(EthTrcv_30_Ar7000_MME_WaEA_ParamType, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_CONST) Params)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) bufPtrWaEA;
  EthTrcv_30_Ar7000_EthernetBufferType ethBuf;
  uint8  ethBufIdx;
  Std_ReturnType retVal = E_NOT_OK;
  /* The Session ID is used if the server (PLC Chip) sends data to the host. 
     For the WriteAndExecuteApplet response MME the server copies the value from the same field in the request MME.
     Therefore, it will not change and stays always 0 */
  uint32 EthTrcv_30_Ar7000_ServerSid = 0u;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 If ETHTRCV_30_AR7000_APPL_CBK_FW_DOWNLOAD_START is enabled
   *       Verify we are enter the function the first time
   *         Inform application that firmware download has been started by using the callback
   */
  if ( FALSE == EthTrcv_30_Ar7000_FwDwldStartCbkCalled)
  {
    EthTrcv_30_Ar7000_FwDwldStartCbkCalled = TRUE;
#if defined(ETHTRCV_30_AR7000_APPL_CBK_FW_DOWNLOAD_START)
    ETHTRCV_30_AR7000_APPL_CBK_FW_DOWNLOAD_START();
#endif
  }

  ethBuf.BufLen = (uint16)(Params->CurPartLen + ETHTRCV_30_AR7000_MME_WAE_HEADER_LEN);

  /* #20 Request a ethernet frame buffer for the set network membership key request MME frame */
  if (BUFREQ_OK == ETHTRCV_30_AR7000_ETH_PROVIDE_TX_BUFFER(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), &ethBufIdx, &(ethBuf.Buffer.Native), &(ethBuf.BufLen)))
  {
    /* #30 Verify requested buffer size */
    if ( ethBuf.BufLen >= ((uint16)(Params->CurPartLen + ETHTRCV_30_AR7000_MME_WAE_HEADER_LEN)) )
    {
      /* #40 Fill ethernet frame buffer with MME frame header and initialize ethernet frame with zeros */
      EthTrcv_30_Ar7000_VFrameHeader(TrcvIdx, (ETHTRCV_30_AR7000_MME_VS_WRITE_AND_EXECUTE_APPLET | ETHTRCV_30_AR7000_MME_REQ), &ethBuf);

      /* #50 Fill ethernet frame with write and execute applet request specific portion */
      bufPtrWaEA = &(ethBuf.Buffer.U8[6]);

      /* VS_WRITE_AND_EXECUTE_APPLET:
       * Fiel offset [Byte] | Field size [Byte] |    Field name       |
       *          0 --------+-------------------+---------------------+
       *                    |         4         |  CLIENT_SESSION_ID  |
       *          4 --------+-------------------+---------------------+
       *                    |         4         |  SERVER_SESSION_ID  |
       *          8 --------+-------------------+---------------------+
       *                    |         4         |       FLAGS         |
       *         12 --------+-------------------+---------------------+
       *                    |         8         |  ALLOWED_MEM_TYPES  |
       *         20 --------+-------------------+---------------------+
       *                    |         4         |    TOTAL_LENGTH     |
       *         24 --------+-------------------+---------------------+
       *                    |         4         |   CURR_PART_LENGTH  |
       *         28 --------+-------------------+---------------------+
       *                    |         4         | CURR_PART_DEST_ADDR |
       *         32 --------+-------------------+---------------------+
       *                    |         4         |     START_ADDR      |
       *         36 --------+-------------------+---------------------+
       *                    |         4         |      CHECKSUM       |
       *         40 --------+-------------------+---------------------+
       *                    |         8         |      RESERVED       |
       *         48 --------+-------------------+---------------------+
       *                    |      variable     |        EXE          |
       *            --------+-------------------+---------------------+
       */

      /* Client Session ID */
      bufPtrWaEA[0u] = (uint8) (EthTrcv_30_Ar7000_ClientSid & 0x000000FFu);
      bufPtrWaEA[1u] = (uint8)((EthTrcv_30_Ar7000_ClientSid & 0x0000FF00u) >> 8u);
      bufPtrWaEA[2u] = (uint8)((EthTrcv_30_Ar7000_ClientSid & 0x00FF0000u) >> 16u);
      bufPtrWaEA[3u] = (uint8)((EthTrcv_30_Ar7000_ClientSid & 0xFF000000u) >> 24u);

      /* Server Session ID */
      bufPtrWaEA[4u] = (uint8) (EthTrcv_30_Ar7000_ServerSid & 0x000000FFu);
      bufPtrWaEA[5u] = (uint8)((EthTrcv_30_Ar7000_ServerSid & 0x0000FF00u) >> 8u);
      bufPtrWaEA[6u] = (uint8)((EthTrcv_30_Ar7000_ServerSid & 0x00FF0000u) >> 16u);
      bufPtrWaEA[7u] = (uint8)((EthTrcv_30_Ar7000_ServerSid & 0xFF000000u) >> 24u);

      /* Flags */
      bufPtrWaEA[8u]  = (uint8) (Params->Flags & 0x000000FFu);
      bufPtrWaEA[9u]  = (uint8)((Params->Flags & 0x0000FF00u) >> 8u);
      bufPtrWaEA[10u] = (uint8)((Params->Flags & 0x00FF0000u) >> 16u);
      bufPtrWaEA[11u] = (uint8)((Params->Flags & 0xFF000000u) >> 24u);

      /* Allowed Mem Types - 8 bytes */
      bufPtrWaEA[12u] = 0x01u; /* Server decides which memory is best */
      bufPtrWaEA[13u] = 0x00u;
      bufPtrWaEA[14u] = 0x00u;
      bufPtrWaEA[15u] = 0x00u;
      bufPtrWaEA[16u] = 0x00u;
      bufPtrWaEA[17u] = 0x00u;
      bufPtrWaEA[18u] = 0x00u;
      bufPtrWaEA[19u] = 0x00u;

      /* Total Length */
      bufPtrWaEA[20u] = (uint8) (Params->TotalLen & 0x000000FFu);
      bufPtrWaEA[21u] = (uint8)((Params->TotalLen & 0x0000FF00u) >> 8u);
      bufPtrWaEA[22u] = (uint8)((Params->TotalLen & 0x00FF0000u) >> 16u);
      bufPtrWaEA[23u] = (uint8)((Params->TotalLen & 0xFF000000u) >> 24u);

      /* Current Part Length */
      bufPtrWaEA[24u] = (uint8) (Params->CurPartLen & 0x000000FFu);
      bufPtrWaEA[25u] = (uint8)((Params->CurPartLen & 0x0000FF00u) >> 8u);
      bufPtrWaEA[26u] = (uint8)((Params->CurPartLen & 0x00FF0000u) >> 16u);
      bufPtrWaEA[27u] = (uint8)((Params->CurPartLen & 0xFF000000u) >> 24u);

      /* Current Part Destination Address */
      bufPtrWaEA[28u] = (uint8) (Params->CurPartDestAddr & 0x000000FFu);
      bufPtrWaEA[29u] = (uint8)((Params->CurPartDestAddr & 0x0000FF00u) >> 8u);
      bufPtrWaEA[30u] = (uint8)((Params->CurPartDestAddr & 0x00FF0000u) >> 16u);
      bufPtrWaEA[31u] = (uint8)((Params->CurPartDestAddr & 0xFF000000u) >> 24u);

      /* Start Address */
      bufPtrWaEA[32u] = (uint8) (Params->StartAddr & 0x000000FFu);
      bufPtrWaEA[33u] = (uint8)((Params->StartAddr & 0x0000FF00u) >> 8u);
      bufPtrWaEA[34u] = (uint8)((Params->StartAddr & 0x00FF0000u) >> 16u);
      bufPtrWaEA[35u] = (uint8)((Params->StartAddr & 0xFF000000u) >> 24u);

      /* Checksum */
      if ( ( Params->Flags & ETHTRCV_30_AR7000_MME_WAE_FLAG_EXECUTE) == ETHTRCV_30_AR7000_MME_WAE_FLAG_EXECUTE )
      {
          bufPtrWaEA[36u] = (uint8) (Params->Checksum & 0x000000FFu);
          bufPtrWaEA[37u] = (uint8)((Params->Checksum & 0x0000FF00u) >> 8u);
          bufPtrWaEA[38u] = (uint8)((Params->Checksum & 0x00FF0000u) >> 16u);
          bufPtrWaEA[39u] = (uint8)((Params->Checksum & 0xFF000000u) >> 24u);
      }

      /* Reserved: 8 bytes already set to zero in EthTrcv_30_Ar7000_VFrameHeader() */

      /* Data */
      /* PRQA S 0314 5 */ /* MD_MSR_VStdLib */
      IpBase_Copy(
        (P2VAR(void, AUTOMATIC, VSTDLIB_VAR_FAR))&bufPtrWaEA[48u],
        (P2CONST(void, AUTOMATIC, VSTDLIB_VAR_FAR))&Params->DataPtr.U8[0u],
        Params->CurPartLen
        );

      /* #60 Transmit ethernet frame */
      /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      if (E_OK == ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)Params->CurPartLen + ETHTRCV_30_AR7000_MME_WAE_HEADER_LEN,
                                            (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]))
      {
        retVal = E_OK;
      }
    }

    /* #70 Verify transmission and release ethernet buffer if it fails */
    if (E_NOT_OK == retVal)
    {
      /* Release buffer */
       /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u,
                                    (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
    }
  }
  return retVal;
} /* EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet() */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if (ETHTRCV_30_AR7000_ENABLE_SET_NMK == STD_ON)
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_SetKey
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_SetKey(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) NmkPtr)
{
   /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_EthernetBufferType ethBuf;
  uint8_least nmkIdx;
  uint8  ethBufIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ethBuf.BufLen = (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE;

  /* #10 Request a ethernet frame buffer for the set network membership key request MME frame */
  if (BUFREQ_OK == ETHTRCV_30_AR7000_ETH_PROVIDE_TX_BUFFER(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), &ethBufIdx, &(ethBuf.Buffer.Native), &(ethBuf.BufLen)))
  {
    /* #20 Verify requested buffer size */
    if (ethBuf.BufLen >= (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE)
    {
      /* #30 Fill ethernet frame buffer with MME frame header and initialize ethernet frame with zeros */
      EthTrcv_30_Ar7000_VFrameHeader(TrcvIdx, (ETHTRCV_30_AR7000_MME_VS_SET_KEY | ETHTRCV_30_AR7000_MME_REQ), &ethBuf);

      /* #40 Fill ethernet frame with set key request specific portion */
      ethBuf.Buffer.U8[6u] = (uint8)0x01u;
      for (nmkIdx = 0u; nmkIdx < ETHTRCV_30_AR7000_NMK_SIZE_BYTE; nmkIdx++)
      { /* Copy NMK */
        ethBuf.Buffer.U8[7u + nmkIdx] = NmkPtr[nmkIdx];
      }
      /* Local Set */
      ethBuf.Buffer.U8[23u] = 0x0fu;

      /* #50 Transmit ethernet frame */
      /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      if(E_OK == ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, \
                                (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE, (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u])
        )
      {
        /* successful */
       EthTrcv_30_Ar7000_SetKeyIsChanging = ETHTRCV_30_AR7000_WAIT_ON_CONF;
        retVal = E_OK;
      }
    }

    /* #60 Verify transmission and release ethernet buffer if it fails */
    if (E_NOT_OK == retVal)
    {
      /* Release buffer */
       /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u,
                                    (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
    }
  }
  return retVal;
} /* EthTrcv_30_Ar7000_MME_SetKey() */
#endif /* (ETHTRCV_30_AR7000_ENABLE_SET_NMK == STD_ON) */

#if ( ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_ResetDevice
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_ResetDevice(
  uint8 TrcvIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_EthernetBufferType ethBuf;
  uint8  ethBufIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ethBuf.BufLen = (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE;

  /* #10 Request a ethernet frame buffer for the reset device MME frame */
  if (BUFREQ_OK == ETHTRCV_30_AR7000_ETH_PROVIDE_TX_BUFFER(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), &ethBufIdx, &(ethBuf.Buffer.Native), &(ethBuf.BufLen)))
  {
    /* #20 Verify requested buffer size */
    if (ethBuf.BufLen >= (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE)
    {
      /* #30 Fill ethernet frame buffer with MME frame header and initialize ethernet frame with zeros
       *       Transmit ethernet frame
       */
      /* This MME doesn't require any further data */
      /* PRQA S 0311 3 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      EthTrcv_30_Ar7000_VFrameHeader(TrcvIdx, (ETHTRCV_30_AR7000_MME_VS_RS_DEV | ETHTRCV_30_AR7000_MME_REQ), &ethBuf);
      if (E_OK == ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, \
                                 (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE, (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u])
      )
      {
        retVal = E_OK;
      }
    }

    /* #40 Verify transmission and release ethernet buffer if it fails */
    if ( E_NOT_OK == retVal )
    {
      /* Release buffer */
      /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u, \
                             (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
    }
  }
  return retVal;
} /* EthTrcv_30_Ar7000_MME_ResetDevice() */
#endif /* ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_HostAction
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_HostAction(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) HarRequestPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_EthernetBufferType ethBuf;
  uint8  ethBufIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ethBuf.BufLen = (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE;
  /* Host Action Response */
  /* #10 Request a ethernet frame buffer for the host action response MME frame */
  if (BUFREQ_OK == ETHTRCV_30_AR7000_ETH_PROVIDE_TX_BUFFER(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), &ethBufIdx, &(ethBuf.Buffer.Native), &(ethBuf.BufLen)))
  {
    /* #20 Verify requested buffer size */
    if (ethBuf.BufLen >= (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE)
    {
      /* #30 Fill ethernet frame buffer with MME frame header and initialize ethernet frame with zeros */
      EthTrcv_30_Ar7000_VFrameHeader(TrcvIdx, (ETHTRCV_30_AR7000_MME_VS_HST_ACTION | ETHTRCV_30_AR7000_MME_RSP), &ethBuf);
      /* #40 Fill ethernet frame with response content */
      ethBuf.Buffer.U8[ETHTRCV_30_AR7000_MME_MSTATUS] = 0x00u;
      /* Following data fields:
       * - ETHTRCV_30_AR7000_MME_HARES_MAJOR_VERSION
       * - ETHTRCV_30_AR7000_MME_HARES_MINOR_VERSION
       * - ETHTRCV_30_AR7000_MME_HARES_HOST_ACTION_REQ
       * - ETHTRCV_30_AR7000_MME_HARES_SESSION_ID
       * - ETHTRCV_30_AR7000_MME_HARES_OUTSTANDING_RETRIES
       * are only required for the following MME frames (introduced with QCA7005 firmware version 1.2.1):
       * - ETHTRCV_30_AR7000_HST_ACT_DEVICE_REBOOTED
       * - ETHTRCV_30_AR7000_HST_ACT_DEVICE_READY_FOR_HIF_COM
       * - ETHTRCV_30_AR7000_HST_ACT_DEVICE_READY_FOR_PLC_COM
       * - ETHTRCV_30_AR7000_HST_ACT_MEMBER_OF_AVLN_WITH_PEERS
       * In older requests this positions are not used in the request and shall be set to 0x00, there for they can be just copied for all responses.
       */
      ethBuf.Buffer.U8[ETHTRCV_30_AR7000_MME_HARES_MAJOR_VERSION]            = HarRequestPtr[ETHTRCV_30_AR7000_MME_HAREQ_MAJOR_VERSION];
      ethBuf.Buffer.U8[ETHTRCV_30_AR7000_MME_HARES_MINOR_VERSION]            = HarRequestPtr[ETHTRCV_30_AR7000_MME_HAREQ_MINOR_VERSION];
      ethBuf.Buffer.U8[ETHTRCV_30_AR7000_MME_HARES_HOST_ACTION_REQ]          = HarRequestPtr[ETHTRCV_30_AR7000_MME_HAREQ_HOST_ACTION_REQ];
      ethBuf.Buffer.U8[ETHTRCV_30_AR7000_MME_HARES_SESSION_ID]               = HarRequestPtr[ETHTRCV_30_AR7000_MME_HAREQ_SESSION_ID];
      ethBuf.Buffer.U8[ETHTRCV_30_AR7000_MME_HARES_OUTSTANDING_RETRIES]      = HarRequestPtr[ETHTRCV_30_AR7000_MME_HAREQ_OUTSTANDING_RETRIES];
      ethBuf.Buffer.U8[ETHTRCV_30_AR7000_MME_HARES_OUTSTANDING_RETRIES + 1u] = HarRequestPtr[ETHTRCV_30_AR7000_MME_HAREQ_OUTSTANDING_RETRIES + 1u];

      /* #50 Transmit ethernet frame */
      /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      if(E_OK == ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, \
                                (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE, (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u])
      )
      {
        retVal = E_OK;
      }
    }

    /* #60 Verify transmission and release ethernet buffer if it fails */
    if (E_NOT_OK == retVal)
    {
      /* Release buffer */
       /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u,
                                    (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
    }
  }
  return retVal;
} /* EthTrcv_30_Ar7000_MME_HostAction() */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_PBEncryption
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_PBEncryption(
  uint8 TrcvIdx,
  uint8 PBAction )
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_EthernetBufferType ethBuf;
  uint8_least  pbEncIdx;
  uint8  ethBufIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  ethBuf.BufLen = (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE;

  /* #10 Request a ethernet frame buffer for the push button encryption MME frame */
  if (BUFREQ_OK == ETHTRCV_30_AR7000_ETH_PROVIDE_TX_BUFFER(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), &ethBufIdx, &(ethBuf.Buffer.Native), &(ethBuf.BufLen)))
  {
    /* #20 Verify requested buffer size */
    if (ethBuf.BufLen >= (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE)
    {
      /* #30 Initialize ethernet buffer with zeros */
      /* default block size is of type '1 byte' and ethBuf.Buffer.Native of type '4 byte' */
      for (pbEncIdx = 0u; pbEncIdx < ((uint8_least)(ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE >> 2u)); pbEncIdx++)
      {
        ethBuf.Buffer.Native[pbEncIdx] = 0u;
      }

      /* #40 Fill ethernet frame with push button encryption data */
      ethBuf.Buffer.U8[0] = (uint8)0x00u; /* MMV */
      ethBuf.Buffer.U8[1] = (uint8)((uint16)(ETHTRCV_30_AR7000_MME_MS_PB_ENC | ETHTRCV_30_AR7000_MME_REQ) & 0x00FFu); /* MMTYPE */
      ethBuf.Buffer.U8[2] = (uint8)((uint16)(ETHTRCV_30_AR7000_MME_MS_PB_ENC | ETHTRCV_30_AR7000_MME_REQ) >> 8u);
      ethBuf.Buffer.U8[3] = (uint8)PBAction; /* PBACTION */

      /* #50 Transmit ethernet frame */
      /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      if(E_OK == ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, \
                                (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE, (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u])
      )
      {
        retVal = E_OK;
      }
    }

    /* #60 Verify transmission and release ethernet buffer if it fails */
    if (E_NOT_OK == retVal)
    {
      /* Release buffer */
      /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
      (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u,
                                    (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
    }
  }
  return retVal;
} /* EthTrcv_30_Ar7000_MME_PBEncryption() */
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK )
 /***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_ModuleOperation
 **********************************************************************************************************************/
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
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_ModuleOperation(
        uint8                                                                                   TrcvIdx,
        uint16                                                                                  ModOp,
  P2VAR(EthTrcv_30_Ar7000_ModOp_Params, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) Params )
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) bufPtrModOp;
  EthTrcv_30_Ar7000_EthernetBufferType ethBuf;
  uint8  ethBufIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Verify that module operation total length is a multiple of 4 */
  if ((Params->ModOpTotLen & 3u) == 0u )
  {
    ethBuf.BufLen = (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE;

    /* #20 Request a ethernet frame buffer for the module operation MME frame */
    if (BUFREQ_OK == ETHTRCV_30_AR7000_ETH_PROVIDE_TX_BUFFER(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), &ethBufIdx, &(ethBuf.Buffer.Native), &(ethBuf.BufLen)))
    {
      /* #30 Verify requested buffer size */
      if (ethBuf.BufLen >= (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE)
      {
        /* #40 Fill ethernet frame buffer with MME frame header and initialize ethernet frame with zeros */
        EthTrcv_30_Ar7000_VFrameHeader(
          TrcvIdx,
          (ETHTRCV_30_AR7000_MME_VS_MODULE_OPERATION | ETHTRCV_30_AR7000_MME_REQ),
          &ethBuf);

        /* #50 Fill ethernet frame with module operation specific portion */
        if (ETHTRCV_30_AR7000_MODOP_RD_MEM == ModOp)
        {
          /* Set NUM_OP_DATA field to one */
          ethBuf.Buffer.U8[10u] = 0x01u;

          /* Set pointer to module operation specific offset */
          bufPtrModOp = &(ethBuf.Buffer.U8[11u]);

          /* Fields are not aligned and must be accessed bytewise */
          bufPtrModOp[0u] = (uint8) (ModOp & 0x00FFu);
          bufPtrModOp[1u] = (uint8)((ModOp & 0xFF00u) >> 8u);

          bufPtrModOp[2u] = (uint8) (Params->ModOpFrameLen & 0x00FFu);
          bufPtrModOp[3u] = (uint8)((Params->ModOpFrameLen & 0xFF00u) >> 8u);

          /* PRQA S 0310 14 */ /* MD_EthTrcv_30_Ar7000_0310 */
          bufPtrModOp[8u] = (uint8) (((EthTrcv_30_Ar7000_ModOp_Rd_Params*)Params)->ModOpModuleId & 0x00FFu);
          bufPtrModOp[9u] = (uint8)((((EthTrcv_30_Ar7000_ModOp_Rd_Params*)Params)->ModOpModuleId & 0xFF00u) >> 8u);

          bufPtrModOp[10u] = (uint8) (((EthTrcv_30_Ar7000_ModOp_Rd_Params*)Params)->ModOpModuleSubId & 0x00FFu);
          bufPtrModOp[11u] = (uint8)((((EthTrcv_30_Ar7000_ModOp_Rd_Params*)Params)->ModOpModuleSubId & 0xFF00u) >> 8u);

          bufPtrModOp[12u] = (uint8) (((EthTrcv_30_Ar7000_ModOp_Rd_Params*)Params)->ModOpDataLenTx & 0x00FFu);
          bufPtrModOp[13u] = (uint8)((((EthTrcv_30_Ar7000_ModOp_Rd_Params*)Params)->ModOpDataLenTx & 0xFF00u) >> 8u);

          bufPtrModOp[14u] = (uint8) (((EthTrcv_30_Ar7000_ModOp_Rd_Params*)Params)->ModOpCurOffset & 0x000000FFu);
          bufPtrModOp[15u] = (uint8)((((EthTrcv_30_Ar7000_ModOp_Rd_Params*)Params)->ModOpCurOffset & 0x0000FF00u) >>  8u);
          bufPtrModOp[16u] = (uint8)((((EthTrcv_30_Ar7000_ModOp_Rd_Params*)Params)->ModOpCurOffset & 0x00FF0000u) >> 16u);
          bufPtrModOp[17u] = (uint8)((((EthTrcv_30_Ar7000_ModOp_Rd_Params*)Params)->ModOpCurOffset & 0xFF000000u) >> 24u);

          /* #60 Transmit ethernet frame */
          /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
          if(E_OK == ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, \
                                    (uint16)ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE, (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u])
          )
          {
            EthTrcv_30_Ar7000_ModOpCycCnt = 1u;
            Params->ModOpState = ETHTRCV_30_AR7000_MODOP_STATE_USED;
            retVal = E_OK;
          }
          else
          {
           /* Release buffer */
            /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
           (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u, \
                             (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
          }
        }
        /* #70 Release buffer if the ModOp is not supported */
        else
        {
          /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
          (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u, \
                               (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
          /* E_NOT_OK */
        }
      }
      /* #80 Release buffer if the size is too small */
      else
      {
        /* PRQA S 0311 2 */ /* MD_EthTrcv_30_Ar7000_CastConstAddressToVar */
        (void)ETHTRCV_30_AR7000_ETH_TRANSMIT(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ethBufIdx, (Eth_FrameType)ETHTRCV_30_AR7000_MTYPE, FALSE, (uint16)0u, \
                             (P2VAR(uint8, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST))&EthTrcv_30_Ar7000_AtherosODA[0u]);
        /* E_NOT_OK */
      }
    }
  }

  return retVal;
} /* EthTrcv_30_Ar7000_MME_ModuleOperation() */
#endif /* ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) ||
          ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API )  ||
          ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK ) */

/**********************************************************************************************************************
 *  MME Requests and Indications
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetLinkStatus
 **********************************************************************************************************************/
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
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetLinkStatus(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */


  if (   (EthTrcv_30_Ar7000_ModeState == ETHTRCV_MODE_DOWN)
#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
      || (EthTrcv_30_Ar7000_LinkStateLockCnt > 0u)
      || (EthTrcv_30_Ar7000_DownlStatus != ETHTRCV_30_AR7000_DOWNLSTATUS_DONE)
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */
     )
  {
    EthTrcv_30_Ar7000_LinkState = ETHTRCV_LINK_STATE_DOWN;
  }
  /* #10 Verify that received confirmation MME is OK */
  else if( 0x00u == DataPtr[ETHTRCV_30_AR7000_MME_MSTATUS] )
  {
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
    /* #20 Set local link state */
    EthTrcv_30_Ar7000_LinkState = DataPtr[ETHTRCV_30_AR7000_MME_LINKSTATUS];

    /* #30 Response received -> reset heart beat */
    EthTrcv_30_Ar7000_HeartBeatCnt = 0u;

    /* #40 Response received -> reset download attempts to initial value */
    EthTrcv_30_Ar7000_DwldAttempts = ETHTRCV_30_AR7000_FW_DWLD_ATTEMPTS;
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
  }
  /* #50 Received confirmation MME is NOT_OK */
  else
  {
    /* #60 MStatus is FAILURE. Ignore and wait for next link state MME */
  }

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
  /* #70 If CALLBACKS are enabled
   *       Inform application using the CALLBACKS
   */
  /* First heart beat indication received - firmware is running. Inform user callback function */
  ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
  if ( FALSE == EthTrcv_30_Ar7000_FwStartedCbkCalled )
  {
    /* Reset FW download start call back info */
    EthTrcv_30_Ar7000_FwDwldStartCbkCalled = FALSE;
    /* Set FW started to true and call the call back if enabled */
    EthTrcv_30_Ar7000_FwStartedCbkCalled = TRUE;
    EthTrcv_30_Ar7000_FwDownloadAndStartCnt = 0u;
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
#if defined ( ETHTRCV_30_AR7000_APPL_CBK_FW_START )
    ETHTRCV_30_AR7000_APPL_CBK_FW_START(TRUE);
#endif /* ETHTRCV_30_AR7000_APPL_CBK_FW_START */
  }
  else
  {
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
  }
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */
} /* EthTrcv_30_Ar7000_SetLinkStatus() */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_NMK == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetKeyCnfStatus
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetKeyCnfStatus(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  /* #10 Reset timeout counter
   *     Save 'set network membership key' result
   */
  ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
  if ( ETHTRCV_30_AR7000_WAIT_ON_CONF == EthTrcv_30_Ar7000_SetKeyIsChanging )
  {
    EthTrcv_30_Ar7000_SetKeyIsChanging = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
    ETHTRCV_30_AR7000_DUMMY_STATEMENT(DataPtr);
  }
  ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
} /* EthTrcv_30_Ar7000_SetKeyCnfStatus() */
#endif
  /* ETHTRCV_30_AR7000_ENABLE_SET_NMK */
#if ( ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetPBEncryptionStatus
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetPBEncryptionStatus(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
  /* #10 Reset timeout counter */
  EthTrcv_30_Ar7000_IsChangingSCState = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
  EthTrcv_30_Ar7000_SCStateConfReady = ETHTRCV_30_AR7000_STATE_READY;
  EthTrcv_30_Ar7000_SCConfCycCnt = 0u;

  /* #20 Save 'push button encryption' status and logical network status */
  EthTrcv_30_Ar7000_PbMStatus = DataPtr[ETHTRCV_30_AR7000_MME_MS_MSTATUS];
  EthTrcv_30_Ar7000_PbAvlnStatus = DataPtr[ETHTRCV_30_AR7000_MME_MS_AVLNSTATUS];

  ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

  /* #30 If ETHTRCV_30_AR7000_APPL_CBK_SIMPLE_CONNECT is defined
   *       Inform application using the callback
   */
#if defined ( ETHTRCV_30_AR7000_APPL_CBK_SIMPLE_CONNECT )
  ETHTRCV_30_AR7000_APPL_CBK_SIMPLE_CONNECT();
#endif /* ETHTRCV_30_AR7000_APPL_CBK_SIMPLE_CONNECT */
} /* EthTrcv_30_Ar7000_SetPBEncryptionStatus() */
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetSoftwareVersion
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetSoftwareVersion(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8_least versionIdx;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
  /* #10 Reset software version confirmation timeout counter */
  EthTrcv_30_Ar7000_IsReadingSwVersion = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
  EthTrcv_30_Ar7000_SWVersionAvailable = ETHTRCV_30_AR7000_STATE_READY;
  EthTrcv_30_Ar7000_GetSwVersionCycCnt = 0u;

  /* #20 Read software version confirm MME status */
  EthTrcv_30_Ar7000_SwMStatus = DataPtr[ETHTRCV_30_AR7000_MME_VS_MSTATUS];

  /* #30 Extract software version  */
  for (versionIdx = 0u; versionIdx < DataPtr[ETHTRCV_30_AR7000_MME_VS_MVERLENGTH];  versionIdx++)
  {
    /* Copy Software Version */
    if (versionIdx < sizeof(EthTrcv_30_Ar7000_SwVersion))
    {
      EthTrcv_30_Ar7000_SwVersion[versionIdx] = DataPtr[ETHTRCV_30_AR7000_MME_VS_MVERSION + versionIdx];
    }
    else
    {
      break;
    }
  }
  ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
} /* EthTrcv_30_Ar7000_SetSoftwareVersion() */
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_HandleGetLinkState
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_HandleGetLinkState(void)
{
  ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
  /* #10 Decrement the counter and check if a link state request shall be send */
  EthTrcv_30_Ar7000_CycleCnt--;
  if(0u == EthTrcv_30_Ar7000_CycleCnt)
  {
    /* #20 Yes: Reset the counter and send a link state request */
    EthTrcv_30_Ar7000_CycleCnt = ETHTRCV_30_AR7000_LINKSTATEPOLLINGFREQ;
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

    (void)EthTrcv_30_Ar7000_MME_GetLinkStatus(0u);
  }
  else
  {
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
  }
}

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_HandleFirmwareRestart
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_HandleFirmwareRestart(boolean CallFwStartCbk)
{
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
  /* #10 Reset all relevant variables */
  EthTrcv_30_Ar7000_LinkState = ETHTRCV_LINK_STATE_DOWN;
#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
  EthTrcv_30_Ar7000_WriteAppletLockCnt = 0u;
  EthTrcv_30_Ar7000_AppletNrLocked = ETHTRCV_30_AR7000_NO_APPLET_LOCKED;

  EthTrcv_30_Ar7000_FwDwldStartCbkCalled = FALSE;
  EthTrcv_30_Ar7000_FwStartedCbkCalled = FALSE;
  EthTrcv_30_Ar7000_FwReadyForSlacCbkCalled = FALSE;
  EthTrcv_30_Ar7000_FwDownloadAndStartCnt = ETHTRCV_30_AR7000_FIRMWARE_DOWNLOAD_AND_START_CYCLES;
  EthTrcv_30_Ar7000_FwReadyForSlacCnt = ETHTRCV_30_AR7000_FIRMWARE_READY_FOR_SLAC_TIMEOUT_CYCLES;
  EthTrcv_30_Ar7000_LinkStateLockCnt = ETHTRCV_30_AR7000_LINKSTATE_LOCK_CYCLES;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

  /* #20 Thow a runtime DET if it is enabled */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
#if ( ETHTRCV_30_AR7000_ENABLE_DET_ON_FW_OR_COM_ERROR == STD_ON )
  (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_MAINFUNCTION, ETHTRCV_30_AR7000_E_TRCV_CONNECTION_LOST_OR_OVERLOADED);
#endif /* ETHTRCV_30_AR7000_ENABLE_DET_ON_FW_OR_COM_ERROR */
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_REPORT */
#if defined(ETHTRCV_30_AR7000_APPL_CBK_FW_ERROR_TRIGGER_RESET)
  ETHTRCV_30_AR7000_APPL_CBK_FW_ERROR_TRIGGER_RESET();
#endif /* ETHTRCV_30_AR7000_APPL_CBK_FW_ERROR_TRIGGER_RESET */

  /* #30 Handle the retry counter */
  EthTrcv_30_Ar7000_DwldAttempts--;
  if (0u == EthTrcv_30_Ar7000_DwldAttempts)
  {
    EthTrcv_30_Ar7000_DwldAttempts = ETHTRCV_30_AR7000_FW_DWLD_ATTEMPTS;
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

    if (CallFwStartCbk == TRUE)
    {
#if defined ( ETHTRCV_30_AR7000_APPL_CBK_FW_START )
      /* Application callout */
      ETHTRCV_30_AR7000_APPL_CBK_FW_START(FALSE);
#endif /* ETHTRCV_30_AR7000_APPL_CBK_FW_START */
    }
#if ( ETHTRCV_30_AR7000_DEM_ERROR_DETECT == STD_ON )
    ETHTRCV_30_AR7000_DEM_REPORT_ERROR_STATUS(ETHTRCV_30_AR7000_E_ACCESS);
#endif /* ETHTRCV_30_AR7000_DEM_ERROR_DETECT */
  }
  else
  {
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
    /* #40 Reset QCA via SPI register if retries are left */
    if ( E_NOT_OK == ETHTRCV_30_AR7000_ETH_WRITESPI(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ETHTRCV_30_AR7000_ETH_SPI_REG_CONFIG, ETHTRCV_30_AR7000_SPI_SOC_CORE_RESET))
    {
      /* DEM Error */
#if ( ETHTRCV_30_AR7000_DEM_ERROR_DETECT == STD_ON )
      ETHTRCV_30_AR7000_DEM_REPORT_ERROR_STATUS(ETHTRCV_30_AR7000_E_ACCESS);
#endif /* ETHTRCV_30_AR7000_DEM_ERROR_DETECT */
    }
  }
}

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_HstActionRequired
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_HstActionRequired(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Std_ReturnType resVal; /* Result value of called functions */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Answer Host-Action-Required (HAR) requests */
  resVal = EthTrcv_30_Ar7000_MME_HostAction(TrcvIdx, &DataPtr[0u]);

  /* #20 Verify confirm MME was successful transmitted */
  if (E_OK == resVal)
  {
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
    /* #30 Verify that HostAction queue has a free element available */
    if (ETHTRCV_30_AR7000_HST_ACTION_QUEUE_SIZE > EthTrcv_30_Ar7000_HstActionCnt)
    {
      /* #40 Verify that the we don't push the same event to queue which is already stored as last element */
      if (0u == EthTrcv_30_Ar7000_HstActionCnt)
      {
        /* Queue is empty, store new HAR request */
        EthTrcv_30_Ar7000_HstAction[EthTrcv_30_Ar7000_HstActionCnt] = DataPtr[ETHTRCV_30_AR7000_MME_HAREQ_HOST_ACTION_REQ];
        EthTrcv_30_Ar7000_HstActionCnt++;
      }
      else
      {
        /* Check last queue element */
        if (EthTrcv_30_Ar7000_HstAction[EthTrcv_30_Ar7000_HstActionCnt - 1u] != DataPtr[ETHTRCV_30_AR7000_MME_HAREQ_HOST_ACTION_REQ])
        {
          /* Store new HAR request */
          EthTrcv_30_Ar7000_HstAction[EthTrcv_30_Ar7000_HstActionCnt] = DataPtr[ETHTRCV_30_AR7000_MME_HAREQ_HOST_ACTION_REQ];
          EthTrcv_30_Ar7000_HstActionCnt++;
        }
        else
        {
          /* This HAR request is already stored, do not store multiple same event in a row */
        }
      }
    }
    else
    {
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
      (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_HST_ACTION_REQ, ETHTRCV_30_AR7000_E_QUEUE_SIZE_TOO_SMALL);
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_REPORT */
    }
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
  }
} /* EthTrcv_30_Ar7000_HstActionRequired() */

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_HstActionRequiredSecondPhase
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STIMF */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_HstActionRequiredSecondPhase(              
    uint8 TrcvIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Std_ReturnType resVal = E_OK; /* Result value of called functions, clear host action in case error handling is not required */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Process all received host action requests */
  while (EthTrcv_30_Ar7000_HstActionIdx < EthTrcv_30_Ar7000_HstActionCnt)
  {
    switch ( EthTrcv_30_Ar7000_HstAction[EthTrcv_30_Ar7000_HstActionIdx] )
    {
    case ETHTRCV_30_AR7000_HST_ACT_LOADER_READY_FOR_SDRAM:
      /* QCA7005 has just been (re-)booted and requires a (new) firmware download */
      /* Reset link information */
      EthTrcv_30_Ar7000_LinkStateLockCnt = ETHTRCV_30_AR7000_LINKSTATE_LOCK_CYCLES;
      EthTrcv_30_Ar7000_LinkState        = ETHTRCV_LINK_STATE_DOWN;

      /* Send Write and Execute Applet with
        * - absolute adresses
        * - absolute entry point address
        * - Memctrl applet data
        */
      if (ETHTRCV_30_AR7000_HST_ACT_LOADER_READY_FOR_SDRAM != EthTrcv_30_Ar7000_AppletNrLocked)
      {
        ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
        /* state of firmware download state machine is "MEMCTRL download" */
        EthTrcv_30_Ar7000_DownlStatus = ETHTRCV_30_AR7000_DOWNLSTATUS_MEMCTRL;

        EthTrcv_30_Ar7000_FwStartedCbkCalled = FALSE;
        EthTrcv_30_Ar7000_FwReadyForSlacCbkCalled = FALSE;
        EthTrcv_30_Ar7000_FwReadyForSlacLastResult = FALSE;
        /* Reset timeouts */
        EthTrcv_30_Ar7000_FwDownloadAndStartCnt = ETHTRCV_30_AR7000_FIRMWARE_DOWNLOAD_AND_START_CYCLES;
        EthTrcv_30_Ar7000_FwReadyForSlacCnt = ETHTRCV_30_AR7000_FIRMWARE_READY_FOR_SLAC_TIMEOUT_CYCLES;

#if (   (defined ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) \
     && (STD_OFF == ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) \
     && (defined ETHTRCV_30_AR7000_APPL_CBK_TRIG_DWLD_REQ))
        /* Do not call application inside a critical section */
        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
        (void)ETHTRCV_30_AR7000_APPL_CBK_TRIG_DWLD_REQ();
        ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
#endif /* ETHTRCV_30_AR7000_APPL_CBK_TRIG_DWLD_REQ */

        EthTrcv_30_Ar7000_WriteAppletLockCnt              = ETHTRCV_30_AR7000_WRITE_APPLET_LOCK_CYCLES;
        EthTrcv_30_Ar7000_AppletNrLocked                  = ETHTRCV_30_AR7000_HST_ACT_LOADER_READY_FOR_SDRAM;

        EthTrcv_30_Ar7000_MME_WaEA_Params.TotalLen        = ETHTRCV_30_AR7000_MEMCTL_LENGTH;
        EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartLen      = ETHTRCV_30_AR7000_ETHBLOCKSIZE;
        EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartDestAddr = ETHTRCV_30_AR7000_MEMCTL_OFFSET;
        EthTrcv_30_Ar7000_MME_WaEA_Params.StartAddr       = ETHTRCV_30_AR7000_MEMCTL_START;
        EthTrcv_30_Ar7000_MME_WaEA_Params.DataPtr.U8      = MemctrlData;
        EthTrcv_30_Ar7000_MME_WaEA_Params.Flags           = ETHTRCV_30_AR7000_MME_WAE_FLAG_ABS_ADDR;
        EthTrcv_30_Ar7000_MME_WaEA_Params.Checksum        = ETHTRCV_30_AR7000_MEMCTL_CRC;

        resVal = EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
          EthTrcv_30_Ar7000_VCfgGetEthIfCtrlIdx(),
          &EthTrcv_30_Ar7000_MME_WaEA_Params);
        if (E_NOT_OK == resVal)
        {
          EthTrcv_30_Ar7000_WriteAppletLockCnt = 0u;
          EthTrcv_30_Ar7000_AppletNrLocked = ETHTRCV_30_AR7000_NO_APPLET_LOCKED;
        }
        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
      }
      break;
    case ETHTRCV_30_AR7000_HST_ACT_LOADER_READY:
      ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
      if ( ETHTRCV_30_AR7000_DOWNLSTATUS_PIB == EthTrcv_30_Ar7000_DownlStatus )
      {
        /* Send Write and Execute PIB block with:
         * - absolute adresses
         * - a entry point address of zero, since PIB does not have a executable entry point function
         * - PIB data
         */
        if (ETHTRCV_30_AR7000_HST_ACT_LOADER_READY != EthTrcv_30_Ar7000_AppletNrLocked)
        {
          EthTrcv_30_Ar7000_WriteAppletLockCnt = ETHTRCV_30_AR7000_WRITE_APPLET_LOCK_CYCLES;
          EthTrcv_30_Ar7000_AppletNrLocked = ETHTRCV_30_AR7000_HST_ACT_LOADER_READY;

#if (((defined ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP)          && (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP))          || \
     (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB)                                     || \
     ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)           && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK))           || \
     ((defined ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API)    && (STD_ON == ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API)))
          if ( TRUE == EthTrcv_30_Ar7000_PibRamCpyValid )
          {
            EthTrcv_30_Ar7000_MME_WaEA_Params.TotalLen        = (uint32) ETHTRCV_30_AR7000_PIB_SIZE;
            EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartLen      = ETHTRCV_30_AR7000_ETHBLOCKSIZE;
            EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartDestAddr = (uint32) ETHTRCV_30_AR7000_PIB_OFFSET;
            EthTrcv_30_Ar7000_MME_WaEA_Params.StartAddr       = 0x00u;
            EthTrcv_30_Ar7000_MME_WaEA_Params.DataPtr.U8      = &EthTrcv_30_Ar7000_PibRamCpy.U8[0];
            EthTrcv_30_Ar7000_MME_WaEA_Params.Flags           = ETHTRCV_30_AR7000_MME_WAE_FLAG_ABS_ADDR;
            EthTrcv_30_Ar7000_MME_WaEA_Params.Checksum        = 0x00u;

            resVal = EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
              TrcvIdx,
              &EthTrcv_30_Ar7000_MME_WaEA_Params);
          }
          else
#endif /* (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP))          || \
          (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) || \
          (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK))           || \
          (STD_ON == ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API))) */
          {
            EthTrcv_30_Ar7000_MME_WaEA_Params.TotalLen        = (uint32) ETHTRCV_30_AR7000_PIB_SIZE;
            EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartLen      = ETHTRCV_30_AR7000_ETHBLOCKSIZE;
            EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartDestAddr = (uint32) ETHTRCV_30_AR7000_PIB_OFFSET;
            EthTrcv_30_Ar7000_MME_WaEA_Params.StartAddr       = 0x00u;
            EthTrcv_30_Ar7000_MME_WaEA_Params.DataPtr.U8      = EthTrcv_30_Ar7000_PIBData;
            EthTrcv_30_Ar7000_MME_WaEA_Params.Flags           = ETHTRCV_30_AR7000_MME_WAE_FLAG_ABS_ADDR;
            EthTrcv_30_Ar7000_MME_WaEA_Params.Checksum        = 0x00u;

            resVal = EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
              TrcvIdx,
              &EthTrcv_30_Ar7000_MME_WaEA_Params);
          }
          if (E_NOT_OK == resVal)
          {
            EthTrcv_30_Ar7000_WriteAppletLockCnt = 0u;
            EthTrcv_30_Ar7000_AppletNrLocked = ETHTRCV_30_AR7000_NO_APPLET_LOCKED;
          }
        }
      }
      else if ( ETHTRCV_30_AR7000_DOWNLSTATUS_FW == EthTrcv_30_Ar7000_DownlStatus )
      {
        /* Send Write and Execute firmware with
         * - absolute adresses
         * - the absolute entry point address
         * - firmware data
         */
        EthTrcv_30_Ar7000_MME_WaEA_Params.TotalLen        = (uint32) ETHTRCV_30_AR7000_FIRMWARE_LENGTH;
        EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartLen      = ETHTRCV_30_AR7000_ETHBLOCKSIZE;
        EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartDestAddr = (uint32) ETHTRCV_30_AR7000_FIRMWARE_OFFSET;
        EthTrcv_30_Ar7000_MME_WaEA_Params.StartAddr       = (uint32) ETHTRCV_30_AR7000_FIRMWARE_START;
        EthTrcv_30_Ar7000_MME_WaEA_Params.DataPtr.U8      = FirmwareData;
        EthTrcv_30_Ar7000_MME_WaEA_Params.Flags           = ETHTRCV_30_AR7000_MME_WAE_FLAG_ABS_ADDR;
        EthTrcv_30_Ar7000_MME_WaEA_Params.Checksum        = (uint32) ETHTRCV_30_AR7000_FIRMWARE_CRC;

        resVal = EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
          TrcvIdx,
          &EthTrcv_30_Ar7000_MME_WaEA_Params);
        if (E_NOT_OK == resVal)
        {
          /* No special applet has been locked for this status, so no release is required for a retry */
        }
      }
      else
      {
        /* Unknown state - response Host Action Required frame to stop broadcasting */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
        (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_HST_ACTION_REQ_SECOND_PHASE, ETHTRCV_30_AR7000_E_FW_DWLD);
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_REPORT */
      }
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
      break;
#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP )
    case ETHTRCV_30_AR7000_HST_ACT_PIB_UPDATE_READY:
    case ETHTRCV_30_AR7000_HST_ACT_FW_PIB_READY:
    case ETHTRCV_30_AR7000_HST_ACT_BGR_PIB_UPDATE_READY:

      ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
      if (ETHTRCV_30_AR7000_HST_ACT_PIB_UPDATE_READY != EthTrcv_30_Ar7000_AppletNrLocked)
      {
        EthTrcv_30_Ar7000_WriteAppletLockCnt = ETHTRCV_30_AR7000_WRITE_APPLET_LOCK_CYCLES;
        EthTrcv_30_Ar7000_AppletNrLocked = ETHTRCV_30_AR7000_HST_ACT_PIB_UPDATE_READY;

        if ( EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState == ETHTRCV_30_AR7000_MODOP_STATE_NOT_USED)
        {
          /* Send Module Operation Frame for Read Request */
          EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpFrameLen = ETHTRCV_30_AR7000_MODOP_RD_HDR_LEN;
          EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpBufPtr   = &EthTrcv_30_Ar7000_PibRamCpy.U8[0];
          EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpTotLen   = (uint16) ETHTRCV_30_AR7000_PIB_SIZE;
          EthTrcv_30_Ar7000_ModOpParams.ModOpModuleId            = ETHTRCV_30_AR7000_MOD_ID_PIB;
          EthTrcv_30_Ar7000_ModOpParams.ModOpModuleSubId         = 0x0000u;
          EthTrcv_30_Ar7000_ModOpParams.ModOpDataLenTx           = ETHTRCV_30_AR7000_MODOP_MAX_DATA_SIZE;
          EthTrcv_30_Ar7000_ModOpParams.ModOpStartOffset         = 0x00000000u;
          EthTrcv_30_Ar7000_ModOpParams.ModOpCurOffset           = 0x00000000u;

          if (ETHTRCV_30_AR7000_HST_ACT_BGR_PIB_UPDATE_READY != EthTrcv_30_Ar7000_HstAction[EthTrcv_30_Ar7000_HstActionIdx])
          {
            EthTrcv_30_Ar7000_WillResetAfterPibUpload = TRUE;
          }

          resVal = EthTrcv_30_Ar7000_MME_ModuleOperation(
            TrcvIdx,
            ETHTRCV_30_AR7000_MODOP_RD_MEM,
            (P2VAR(EthTrcv_30_Ar7000_ModOp_Params, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT))&EthTrcv_30_Ar7000_ModOpParams); /* PRQA S 0310 */ /* MD_EthTrcv_30_Ar7000_ModOpParams */
        }
        else
        {
          resVal = E_NOT_OK;
        }
        if (E_OK == resVal)
        {
#if (   (defined ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) \
     && (STD_OFF == ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) \
     && (defined ETHTRCV_30_AR7000_APPL_CBK_TRIG_DWLD_REQ) )
          /* Do not call application inside a critical section */
          ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
          (void)ETHTRCV_30_AR7000_APPL_CBK_TRIG_DWLD_REQ();
          ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
#endif /* ETHTRCV_30_AR7000_APPL_CBK_TRIG_DWLD_REQ */
        }
        else
        {
          EthTrcv_30_Ar7000_WriteAppletLockCnt = 0u;
          EthTrcv_30_Ar7000_AppletNrLocked = ETHTRCV_30_AR7000_NO_APPLET_LOCKED;
        }
      }
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
      break;
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP */

    case ETHTRCV_30_AR7000_HST_ACT_DEVICE_READY_FOR_HIF_COM:
      /* Firmware is sucessfully started, but is currently bussy. Wait for ETHTRCV_30_AR7000_HST_ACT_DEVICE_READY_FOR_PLC_COM */
#if (STD_ON == ETHTRCV_30_AR7000_ENABLE_DEVICE_READY_FOR_HIF_COM_EVENT)
      ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
      /* Reset download attempts to initial value */
      EthTrcv_30_Ar7000_DwldAttempts = ETHTRCV_30_AR7000_FW_DWLD_ATTEMPTS;

      /* Stop timer */
      EthTrcv_30_Ar7000_FwDownloadAndStartCnt = 0u;
      /* Inform user callback function */
      if (EthTrcv_30_Ar7000_FwStartedCbkCalled == FALSE)
      {
        /* Reset FW download start call back info */
        EthTrcv_30_Ar7000_FwDwldStartCbkCalled = FALSE;
        EthTrcv_30_Ar7000_FwStartedCbkCalled = TRUE;
        /* Do not call application inside a critical section */
        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
# if defined ( ETHTRCV_30_AR7000_APPL_CBK_FW_START )
        ETHTRCV_30_AR7000_APPL_CBK_FW_START(TRUE);
# endif /* ETHTRCV_30_AR7000_APPL_CBK_FW_START */
      }
      else
      {
        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
      }
# else
# if (ETHTRCV_30_AR7000_ENABLE_DET_ON_DISABLED_HST_ACT_EVENTS == STD_ON)
      /* This event is enabled in the PIB file, but disabled in the ECU configuration.
       * It is recommended to enable this event in the ECU confugration.
       */
      (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_HST_ACTION_REQ_SECOND_PHASE, ETHTRCV_30_AR7000_E_DISABLED_FEATURE);
# endif
#endif /* ETHTRCV_30_AR7000_ENABLE_DEVICE_READY_FOR_HIF_COM_EVENT */
      break;
    case ETHTRCV_30_AR7000_HST_ACT_DEVICE_READY_FOR_PLC_COM:
      /* QCA is ready for SLAC communication, inform application. */

#if (STD_ON == ETHTRCV_30_AR7000_ENABLE_DEVICE_READY_FOR_SLAC_COM_EVENT)
      /* Stop timer */
      EthTrcv_30_Ar7000_FwReadyForSlacCnt = 0u;

      /* Inform user callback function */
      ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
      if ( FALSE == EthTrcv_30_Ar7000_FwReadyForSlacCbkCalled )
      {
        EthTrcv_30_Ar7000_FwReadyForSlacCbkCalled = TRUE;
        EthTrcv_30_Ar7000_FwReadyForSlacLastResult = TRUE;
        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
# if defined ( ETHTRCV_30_AR7000_APPL_CBK_FW_READY_FOR_SLAC )
        ETHTRCV_30_AR7000_APPL_CBK_FW_READY_FOR_SLAC(EthTrcv_30_Ar7000_FwReadyForSlacLastResult);
# endif
      }
      else
      {
        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
      }
#else
# if (ETHTRCV_30_AR7000_ENABLE_DET_ON_DISABLED_HST_ACT_EVENTS == STD_ON)
      /* This event is enabled in the PIB file, but disabled in the ECU configuration.
       * It is recommended to enable this event in the ECU confugration. It may speed up the start up process until SLAC can be started.
       */
      (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_HST_ACTION_REQ_SECOND_PHASE, ETHTRCV_30_AR7000_E_DISABLED_FEATURE);
# endif
#endif /* ETHTRCV_30_AR7000_ENABLE_DEVICE_READY_FOR_SLAC_COM_EVENT */
      break;
    case ETHTRCV_30_AR7000_HST_ACT_MEMBER_OF_AVLN_WITH_PEERS:
      /* Link state changed to 1 */

#if (STD_ON == ETHTRCV_30_AR7000_ENABLE_MEMBER_OF_AVLN_WITH_PEERS_EVENT)
      ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
      /* Set local link state */
      EthTrcv_30_Ar7000_LinkState = ETHTRCV_LINK_STATE_ACTIVE;
      EthTrcv_30_Ar7000_LinkStateLockCnt = 0u;

      /* Set heart beat count to zero */
      EthTrcv_30_Ar7000_HeartBeatCnt = 0u;
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
#else
# if (ETHTRCV_30_AR7000_ENABLE_DET_ON_DISABLED_HST_ACT_EVENTS == STD_ON)
      /* This event is enabled in the PIB file, but disabled in the ECU configuration.
       * It is recommended to enable this event in the ECU confugration. It may speed up the start up process until SLAC can be started.
       */
      (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_HST_ACTION_REQ_SECOND_PHASE, ETHTRCV_30_AR7000_E_DISABLED_FEATURE);
# endif
#endif /* ETHTRCV_30_AR7000_ENABLE_MEMBER_OF_AVLN_WITH_PEERS_EVENT */

      break;

    default:
      /* Ignore unknown host actions that may be sent by newer firmware versions. */
      break;
    }

    /* #20 Verify that host action is successfully answered */
    if (E_OK == resVal)
    {
      ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
      /* #30 Host action request successfully processed, go to next request */
      EthTrcv_30_Ar7000_HstAction[EthTrcv_30_Ar7000_HstActionIdx] = ETHTRCV_30_AR7000_NO_HST_ACTION_REQUIRED;
      EthTrcv_30_Ar7000_HstActionIdx++;
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
    }
    /* #40 Host action isn't successfully answered */
    else
    {
      /* #50 Host action not processed, move current HAR to first postition in queue. */
      if (0u != EthTrcv_30_Ar7000_HstActionIdx)
      {
        uint8_least TmpDestIdx = 0u;
        uint8_least TmpSrcIdx;
        uint8 NewQueueEndIdx;

        ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

        /* Move all HAR's to beginning of the queue */
        TmpSrcIdx = EthTrcv_30_Ar7000_HstActionIdx;
        for (; TmpSrcIdx < EthTrcv_30_Ar7000_HstActionCnt; TmpSrcIdx++)
        {
          EthTrcv_30_Ar7000_HstAction[TmpDestIdx] = EthTrcv_30_Ar7000_HstAction[TmpSrcIdx];
          TmpDestIdx++;
        }
        NewQueueEndIdx = (uint8)TmpDestIdx;
        /* Reset free elements */
        for (; TmpDestIdx < EthTrcv_30_Ar7000_HstActionCnt; TmpDestIdx++)
        {
          EthTrcv_30_Ar7000_HstAction[TmpDestIdx] = ETHTRCV_30_AR7000_NO_HST_ACTION_REQUIRED;
        }
        /* Set queue position to remaining elements */
        EthTrcv_30_Ar7000_HstActionIdx = 0u;
        EthTrcv_30_Ar7000_HstActionCnt = NewQueueEndIdx;

        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
      }
      break;
    }
  } /* while (EthTrcv_30_Ar7000_HstActionIdx < EthTrcv_30_Ar7000_HstActionCnt) */

  /* #60 Verify if queue can be reset */
  ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
  if (EthTrcv_30_Ar7000_HstActionIdx == EthTrcv_30_Ar7000_HstActionCnt)
  {
    EthTrcv_30_Ar7000_HstActionIdx = 0u;
    EthTrcv_30_Ar7000_HstActionCnt = 0u;
  }
  ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
} /* EthTrcv_30_Ar7000_HstActionRequiredSecondPhase() */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_WriteAndExecuteApplet
 **********************************************************************************************************************/
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
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_WriteAndExecuteApplet(                     /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint32 waeFlags = ETHTRCV_30_AR7000_MME_WAE_FLAG_ABS_ADDR;
  uint32 status;
  uint32 pibChecksum = 0u;
  uint32 totalLen = 0u;
  uint32 bufCurAddrOffs = 0u;
  uint32 bufEndAddr = 0u;
  uint32 bytesTx = 0u;
  uint32 bytesDone = 0u;
  boolean errorReturn = FALSE;

#if ((defined ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (STD_ON==ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD))
  uint8 u8Idx;
  Std_ReturnType resVal = E_OK; /* Result value of called functions */
#endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Parse the 'write and execute applet response' MME header */
  /* Set working buffer to the STATUS field */
  P2CONST(uint8, AUTOMATIC, ETHTRCV_30_AR7000_CONST) BufPtrWaEA = &(DataPtr)[6u];

  /* status -> 4 Byte */
  status = ETHTRCV_30_AR7000_U8PTRDATA_TO_VAL32(BufPtrWaEA, 0u);

  /* Client Session ID -> of no interest -> 4 Byte */
  /* Server Session ID -> of no interest -> 4 Byte */
  /* Flags -> of no interest -> 4 Byte */
  /* Allowed Mem Types -> of no interest -> 8 Byte */
  /* Total Length -> of no interest -> 4 Byte */
  /* Current Part Length -> of no interest -> 4 Byte */
  /* Current Part Destination Address -> of no interest -> 4 Byte */
  /* Start Address -> of no interest -> 4 Byte */
  /* Checksum -> of no interest -> 4 Byte */
  /* Reserved -> of no interest -> 8 Byte */
  /* Current Part Absolute Address -> of no interest -> 4 Byte */
  /* Absolute Start Address -> of no interest -> 4 Byte */


  /* calculate start address for next junk */
  /* Verify that no wrapping occurs during the calculation */
  if ((ETHTRCV_30_AR7000_UINT32_MAX_VALUE - EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartDestAddr) >= EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartLen)
  {
    /* No wrapping is verified */
    bufCurAddrOffs = EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartDestAddr + EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartLen;
  }
  else
  {
    /* Wrapping will occur therefore an error will be returned */
    /* PRQA S 2982 2 */ /* MD_EthTrcv_30_Ar7000_OtherTools */
    errorReturn = TRUE;
  }

  switch (EthTrcv_30_Ar7000_DownlStatus)
  {
  case ETHTRCV_30_AR7000_DOWNLSTATUS_MEMCTRL:
    bufEndAddr = ETHTRCV_30_AR7000_MEMCTL_OFFSET + ETHTRCV_30_AR7000_MEMCTL_LENGTH;
    totalLen = ETHTRCV_30_AR7000_MEMCTL_LENGTH;
    /* Verify the result to ensure the calculated address is in the correct address range */
    if(ETHTRCV_30_AR7000_MEMCTL_OFFSET > bufCurAddrOffs)
    {
      errorReturn = TRUE;
    }
    break;
  case ETHTRCV_30_AR7000_DOWNLSTATUS_PIB:
    bufEndAddr = ((uint32) ETHTRCV_30_AR7000_PIB_OFFSET) + ((uint32) ETHTRCV_30_AR7000_PIB_SIZE);
    totalLen = ((uint32) ETHTRCV_30_AR7000_PIB_SIZE);
    /* Verify the result to ensure the calculated address is in the correct address range */
    if(((uint32) ETHTRCV_30_AR7000_PIB_OFFSET) > bufCurAddrOffs)
    {
      errorReturn = TRUE;
    }
    break;
  case ETHTRCV_30_AR7000_DOWNLSTATUS_FW:
    bufEndAddr = ((uint32) ETHTRCV_30_AR7000_FIRMWARE_OFFSET) + ((uint32) ETHTRCV_30_AR7000_FIRMWARE_LENGTH);
    totalLen = ((uint32) ETHTRCV_30_AR7000_FIRMWARE_LENGTH);
    /* Verify the result to ensure the calculated address is in the correct address range */
    if(((uint32) ETHTRCV_30_AR7000_FIRMWARE_OFFSET) > bufCurAddrOffs)
    {
      errorReturn = TRUE;
    }
    break;
  default:
    /* Ignore */
    /* PRQA S 2983 1 */ /* MD_EthTrcv_30_Ar7000_OtherTools */
    errorReturn = TRUE;
    break;
  }
  if (errorReturn == FALSE)
  {
    /* #20 Calculate amount of data to be transmitted and finished */
    /* Verify that no wrapping occurs during the calculation */
    if (bufEndAddr >= bufCurAddrOffs)
    {
      /* No wrapping is verified */
      bytesTx = bufEndAddr - bufCurAddrOffs;
    } 
    else 
    {
      /* Wrapping will occur therefore an error will be returned */
      errorReturn = TRUE;
    }

    /* Verify that no wrapping occurs during the calculation */
    if (totalLen >= bytesTx)
    {
      /* No wrapping is verified */
      bytesDone = totalLen - bytesTx;
    } 
    else 
    {
      /* Wrapping will occur therefore an error will be returned */
      errorReturn = TRUE;
    }


  }

  if (errorReturn == TRUE)
  {
    /* PRQA S 2982 2 */ /* MD_EthTrcv_30_Ar7000_OtherTools */
    bytesTx = 0u;
    bytesDone = 0u;
  }

  /* #30 Do some error checks:
   *       Verify the response MME status
   *       Verify that the read bytes not exceed the bytes totally available
   */
  if ( (errorReturn == FALSE) && (status != 0u) )
  {
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
# if ( ETHTRCV_30_AR7000_ENABLE_DET_ON_FW_OR_COM_ERROR == STD_ON )
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_WRITE_AND_EXECUTE_APPLET, ETHTRCV_30_AR7000_E_FW_DWLD);
# endif /* ETHTRCV_30_AR7000_ENABLE_DET_ON_FW_OR_COM_ERROR */
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_REPORT */

    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

    EthTrcv_30_Ar7000_DwldAttempts--;
    if (0u == EthTrcv_30_Ar7000_DwldAttempts)
    {
      EthTrcv_30_Ar7000_DwldAttempts = ETHTRCV_30_AR7000_FW_DWLD_ATTEMPTS;

      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

#if defined ( ETHTRCV_30_AR7000_APPL_CBK_FW_START )
      /* Application callout */
      ETHTRCV_30_AR7000_APPL_CBK_FW_START(FALSE);
#endif /* ETHTRCV_30_AR7000_APPL_CBK_FW_START */
      /* DEM Error */
#if ( ETHTRCV_30_AR7000_DEM_ERROR_DETECT == STD_ON )
      ETHTRCV_30_AR7000_DEM_REPORT_ERROR_STATUS(ETHTRCV_30_AR7000_E_ACCESS);
#endif /* ETHTRCV_30_AR7000_DEM_ERROR_DETECT */

    }
    else
    {
      /* reset */
      EthTrcv_30_Ar7000_WriteAppletLockCnt = 0u;
      EthTrcv_30_Ar7000_AppletNrLocked = ETHTRCV_30_AR7000_NO_APPLET_LOCKED;

      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

      if ( E_NOT_OK == ETHTRCV_30_AR7000_ETH_WRITESPI(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ETHTRCV_30_AR7000_ETH_SPI_REG_CONFIG, ETHTRCV_30_AR7000_SPI_SOC_CORE_RESET))
      {
      /* DEM Error */
#if ( ETHTRCV_30_AR7000_DEM_ERROR_DETECT == STD_ON )
        ETHTRCV_30_AR7000_DEM_REPORT_ERROR_STATUS(ETHTRCV_30_AR7000_E_ACCESS);
#endif /* ETHTRCV_30_AR7000_DEM_ERROR_DETECT */
      }
    }
    errorReturn = TRUE;
  }
  else
  {
    /* nothing to do */
  }

  /* #40 Verify that we have finished transmission  */
  if ( (errorReturn == FALSE) && (bytesTx == 0u) )
  {
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

    EthTrcv_30_Ar7000_DownlStatus++;
    EthTrcv_30_Ar7000_ClientSid++;
    /* Release the locked applet */
    EthTrcv_30_Ar7000_WriteAppletLockCnt = 0u;
    EthTrcv_30_Ar7000_AppletNrLocked     = ETHTRCV_30_AR7000_NO_APPLET_LOCKED;

    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

    if (ETHTRCV_30_AR7000_DOWNLSTATUS_FW == EthTrcv_30_Ar7000_DownlStatus)
    {
      /* Prepare firmware download */
      bytesTx        = (uint32) ETHTRCV_30_AR7000_FIRMWARE_LENGTH;
      bufCurAddrOffs = (uint32) ETHTRCV_30_AR7000_FIRMWARE_OFFSET;
      bytesDone      = 0u;
    }
    else if ( ETHTRCV_30_AR7000_DOWNLSTATUS_FW < EthTrcv_30_Ar7000_DownlStatus )
    {
      /* finished firmware download process */
      EthTrcv_30_Ar7000_LinkState          = ETHTRCV_LINK_STATE_DOWN;
      EthTrcv_30_Ar7000_LinkStateLockCnt   = 0u;
    }
    else
    {
      /* Nothing to do */
    }
  }

  /* #50 Verify that we have remaining data chunks */
  if ( (errorReturn == FALSE) && (bytesTx > 0u) )
  {
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
    /* #60 Determine maximum transmission data size */
    if (bytesTx > ETHTRCV_30_AR7000_ETHBLOCKSIZE)
    {
      bytesTx = ETHTRCV_30_AR7000_ETHBLOCKSIZE;
    }
    else
    {
      /* #70 Set execute flag for last data chunk transfer if it is a executable (fw or softloader applet) */
      if ( ETHTRCV_30_AR7000_DOWNLSTATUS_PIB != EthTrcv_30_Ar7000_DownlStatus )
      {
        waeFlags |= ETHTRCV_30_AR7000_MME_WAE_FLAG_EXECUTE;
      }
      /* #80 Calculate PIB checksum if the data chunk was of type PIB */
      else
      {
#if (   ((defined ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP)         && (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP)) \
     || (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) \
     || ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)          && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)) \
     || ((defined ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API)   && (STD_ON == ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API)))
        /* Calculate Checksum for Pib */
        if ( TRUE == EthTrcv_30_Ar7000_PibRamCpyValid )
        {
          pibChecksum = EthTrcv_30_Ar7000_VCalcChecksum(TrcvIdx, &EthTrcv_30_Ar7000_PibRamCpy.U8[0], ((uint32) ETHTRCV_30_AR7000_PIB_SIZE));
        }
        else
#endif /*    (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP)
          || (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB)
          || (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)
          || (STD_ON == ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API) */
        {
          pibChecksum = EthTrcv_30_Ar7000_VCalcChecksum(TrcvIdx, EthTrcv_30_Ar7000_PIBData, ((uint32) ETHTRCV_30_AR7000_PIB_SIZE));
        }
      }
    }

    /* #90 Transmit data chunk to QCA */
    switch (EthTrcv_30_Ar7000_DownlStatus)
    {
    case ETHTRCV_30_AR7000_DOWNLSTATUS_MEMCTRL:
      /* Transmit MemCtrl */
      EthTrcv_30_Ar7000_MME_WaEA_Params.TotalLen        = ETHTRCV_30_AR7000_MEMCTL_LENGTH;
      EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartLen      = bytesTx;
      EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartDestAddr = bufCurAddrOffs;
      EthTrcv_30_Ar7000_MME_WaEA_Params.StartAddr       = ETHTRCV_30_AR7000_MEMCTL_START;
      EthTrcv_30_Ar7000_MME_WaEA_Params.DataPtr.U8      = &(MemctrlData[bytesDone]);
      EthTrcv_30_Ar7000_MME_WaEA_Params.Flags           = waeFlags;
      EthTrcv_30_Ar7000_MME_WaEA_Params.Checksum        = ETHTRCV_30_AR7000_MEMCTL_CRC;

#if ((defined ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (STD_OFF==ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD))
      EthTrcv_30_Ar7000_MME_WaEA_Params.NeedToSend = TRUE;
#else
      resVal = EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
        TrcvIdx,
        &EthTrcv_30_Ar7000_MME_WaEA_Params);
#endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */
      break;
    case ETHTRCV_30_AR7000_DOWNLSTATUS_PIB:
      /* Transmit PIB */

#if (((defined ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP)         && (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP))           || \
     (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB)                                     || \
     ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)          && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK))            || \
     ((defined ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API)   && (STD_ON == ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API)))
      if ( TRUE == EthTrcv_30_Ar7000_PibRamCpyValid )
      {
        EthTrcv_30_Ar7000_MME_WaEA_Params.TotalLen        = (uint32) ETHTRCV_30_AR7000_PIB_SIZE;
        EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartLen      = bytesTx;
        EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartDestAddr = bufCurAddrOffs;
        EthTrcv_30_Ar7000_MME_WaEA_Params.StartAddr       = 0x0u;
        EthTrcv_30_Ar7000_MME_WaEA_Params.DataPtr.U8      = &(EthTrcv_30_Ar7000_PibRamCpy.U8[bytesDone]);
        EthTrcv_30_Ar7000_MME_WaEA_Params.Flags           = waeFlags;
        EthTrcv_30_Ar7000_MME_WaEA_Params.Checksum        = pibChecksum;
#if ((defined ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (STD_OFF==ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD))
        EthTrcv_30_Ar7000_MME_WaEA_Params.NeedToSend = TRUE;
#else
        resVal = EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
          TrcvIdx,
          &EthTrcv_30_Ar7000_MME_WaEA_Params);
#endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */
      }
      else
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP, ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE, ETHTRCV_30_AR7000_ENABLE_WRITE_DAK */
      {
        EthTrcv_30_Ar7000_MME_WaEA_Params.TotalLen        = (uint32) ETHTRCV_30_AR7000_PIB_SIZE;
        EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartLen      = bytesTx;
        EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartDestAddr = bufCurAddrOffs;
        EthTrcv_30_Ar7000_MME_WaEA_Params.StartAddr       = 0x0u;
        EthTrcv_30_Ar7000_MME_WaEA_Params.DataPtr.U8      = &(EthTrcv_30_Ar7000_PIBData[bytesDone]);
        EthTrcv_30_Ar7000_MME_WaEA_Params.Flags           = waeFlags;
        EthTrcv_30_Ar7000_MME_WaEA_Params.Checksum        = pibChecksum;
#if ((defined ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (STD_OFF==ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD))
        EthTrcv_30_Ar7000_MME_WaEA_Params.NeedToSend = TRUE;
#else
        resVal = EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
          TrcvIdx,
          &EthTrcv_30_Ar7000_MME_WaEA_Params);
#endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */
      }
      break;
    case ETHTRCV_30_AR7000_DOWNLSTATUS_FW:
      /* Transmit FW */
      EthTrcv_30_Ar7000_MME_WaEA_Params.TotalLen        = (uint32) ETHTRCV_30_AR7000_FIRMWARE_LENGTH;
      EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartLen      = bytesTx;
      EthTrcv_30_Ar7000_MME_WaEA_Params.CurPartDestAddr = bufCurAddrOffs;
      EthTrcv_30_Ar7000_MME_WaEA_Params.StartAddr       = (uint32) ETHTRCV_30_AR7000_FIRMWARE_START;
      EthTrcv_30_Ar7000_MME_WaEA_Params.DataPtr.U8      = &(FirmwareData[bytesDone]);
      EthTrcv_30_Ar7000_MME_WaEA_Params.Flags           = waeFlags;
      EthTrcv_30_Ar7000_MME_WaEA_Params.Checksum        = (uint32) ETHTRCV_30_AR7000_FIRMWARE_CRC;

#if ((defined ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (STD_OFF==ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD))
      EthTrcv_30_Ar7000_MME_WaEA_Params.NeedToSend = TRUE;
#else
      resVal = EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
        TrcvIdx,
        &EthTrcv_30_Ar7000_MME_WaEA_Params);
#endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */
      break;
    default:
      /* Firmware download is already done, nothing to do. */
      break;
    }
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
  }

  /* #100 If ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD is enabled
   *       If data chunk transmission status is NOT_OK
   *         Safe the failed frame
   *         Re-Trigger WriteAndExecuteApplet() by set FailedApiCall (See MainFunction())
   */
#if ((defined ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD == STD_ON))
  if ( (errorReturn == FALSE) && (E_NOT_OK == resVal) )
  {
    /* Copy frame for later use */
    u8Idx = 0u;
    while ( u8Idx < ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE )
    {
      EthTrcv_30_Ar7000_LastFrHeader[u8Idx] = DataPtr[u8Idx];
      u8Idx++;
    }

    EthTrcv_30_Ar7000_FailedApiCall = EthTrcv_30_Ar7000_WriteAndExecuteApplet;
  }
#endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */
} /* EthTrcv_30_Ar7000_WriteAndExecuteApplet() */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK)    || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API)
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_ModuleOperation
 **********************************************************************************************************************/
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
 */
ETHTRCV_30_AR7000_LOCAL FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_ModuleOperation(                           /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2CONST(uint8, AUTOMATIC, ETHTRCV_30_AR7000_CONST) bufPtrModOp = &DataPtr[ETHTRCV_30_AR7000_MME_VS_MSTATUS];

  uint32 ethBufIdx;
  uint16 modOp;
  uint16 mStatus;
  Std_ReturnType resVal = E_NOT_OK; /* Result value of called functions */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  mStatus = ETHTRCV_30_AR7000_U8PTRDATA_TO_VAL16(bufPtrModOp, 0u);

  ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

  /* #10 Verify that received MME confirmation packet status is ok */
  if ( ETHTRCV_30_AR7000_MSTATUS_OK == mStatus)
  {
    /* #20 Set data pointer to Module Operation Header */
    bufPtrModOp = &DataPtr[15u];

    modOp = ETHTRCV_30_AR7000_U8PTRDATA_TO_VAL16(bufPtrModOp, 0u);

    /* #30 Verify that module operation was 'read module from QCA memory' (we only send read request's) */
    if ( ETHTRCV_30_AR7000_MODOP_RD_MEM == modOp )
    {
      /* Get the length and offset values from the received MME frame. */
      EthTrcv_30_Ar7000_ModOpParams.ModOpDataLenTx = ETHTRCV_30_AR7000_U8PTRDATA_TO_VAL16(bufPtrModOp, 12u);
      EthTrcv_30_Ar7000_ModOpParams.ModOpCurOffset = ETHTRCV_30_AR7000_U8PTRDATA_TO_VAL32(bufPtrModOp, 14u);
      /* Calculate the current start position (validation of the values is done below). */
      ethBufIdx = EthTrcv_30_Ar7000_ModOpParams.ModOpCurOffset - EthTrcv_30_Ar7000_ModOpParams.ModOpStartOffset;

      /* #40 Copy received module data */
      if (   /* Check if the ethBufIdx calucation did not produce an underflow. */
             (EthTrcv_30_Ar7000_ModOpParams.ModOpStartOffset <= EthTrcv_30_Ar7000_ModOpParams.ModOpCurOffset)
             /* Check that "ethBufIdx + ModOpDataLenTx" does not produce an overflow. */
          && (ethBufIdx <= (ETHTRCV_30_AR7000_UINT32_MAX_VALUE - EthTrcv_30_Ar7000_ModOpParams.ModOpDataLenTx))
             /* Check if the received data is smaller than or equal to the buffer size. */
          && (EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpTotLen >= (ethBufIdx + EthTrcv_30_Ar7000_ModOpParams.ModOpDataLenTx)) )
      {
        /* #50 First data chunk */
        /* Mask the ethBufIdx, because ModOpBufPtr was of type uint32 before and has now been changed to uint8. This is done to get the exact same behavior. */
        /* PRQA S 0314 5 */ /* MD_MSR_VStdLib */
        IpBase_Copy(
          (P2VAR(void, AUTOMATIC, IPBASE_APPL_DATA))&EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpBufPtr[ethBufIdx & 0xFFFFFFFCu],
          (P2CONST(void, AUTOMATIC, IPBASE_APPL_DATA))&bufPtrModOp[18u],
          EthTrcv_30_Ar7000_ModOpParams.ModOpDataLenTx
        );

        /* #60 Verify if more data chunks must be read */
        if (EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpTotLen > (ethBufIdx + EthTrcv_30_Ar7000_ModOpParams.ModOpDataLenTx) )
        {
          EthTrcv_30_Ar7000_ModOpParams.ModOpCurOffset += EthTrcv_30_Ar7000_ModOpParams.ModOpDataLenTx;
          resVal = EthTrcv_30_Ar7000_MME_ModuleOperation(
            TrcvIdx,
            modOp,
            (P2VAR(EthTrcv_30_Ar7000_ModOp_Params, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT))&EthTrcv_30_Ar7000_ModOpParams); /* PRQA S 0310 */ /* MD_EthTrcv_30_Ar7000_ModOpParams */
        }

        /* #70 Reading data chunks finished
         *        Reset ModOp-timeout counter
         *        If ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP is enabled
         *          Verify that received data indicates a PIB block
         *            Set RamCpy Indication to valid
         *        If ETHTRCV_30_AR7000_ENABLE_READ_NMK is enabled
         *          Verify that received data indicates a NMK
         *            Reset NMK timeout counter
         */
        else
        {
          EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState = ETHTRCV_30_AR7000_MODOP_STATE_NOT_USED;
          EthTrcv_30_Ar7000_ModOpRetryCnt = 0u;

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP )
          if (EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpBufPtr == &EthTrcv_30_Ar7000_PibRamCpy.U8[0])
          {
            EthTrcv_30_Ar7000_PibRamCpyValid = TRUE;

            /* Callback */
#if defined ( ETHTRCV_30_AR7000_APPL_CBK_PIB_CHANGE )
            ETHTRCV_30_AR7000_APPL_CBK_PIB_CHANGE();
#endif /* ETHTRCV_30_AR7000_APPL_CBK_PIB_CHANGE */

            if (TRUE == EthTrcv_30_Ar7000_WillResetAfterPibUpload)
            {
              resVal = EthTrcv_30_Ar7000_ResetDevice(TrcvIdx);
            }
            else
            {
              resVal = E_OK;
            }
          }
          else
          {
            resVal = E_OK;
          }
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP */
#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK )
          if ( EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpBufPtr == &EthTrcv_30_Ar7000_Nmk[0] )
          {
            EthTrcv_30_Ar7000_IsReadingNmk = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
            EthTrcv_30_Ar7000_NmkReady = ETHTRCV_30_AR7000_STATE_READY;
            EthTrcv_30_Ar7000_ReadNmkCycCnt = 0u;

            EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState = ETHTRCV_30_AR7000_MODOP_STATE_NOT_USED;
            /* Callback */
#if defined ( ETHTRCV_30_AR7000_APPL_CBK_READ_NMK )
            ETHTRCV_30_AR7000_APPL_CBK_READ_NMK();
#endif /* ETHTRCV_30_AR7000_APPL_CBK_READ_NMK */
          }
#endif /* ETHTRCV_30_AR7000_ENABLE_READ_NMK */
        }
      }
      else
      {
        resVal = E_NOT_OK;
      }
    }
  }
  else
  {
    resVal = E_NOT_OK;
  }

  /* #80 Retry the module operation 'NMK read' or 'PIB read' if a failure occurred in the previously sequence */
  if ( E_NOT_OK == resVal)
  {
    /* try again */
#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP )
    if (EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpBufPtr == &EthTrcv_30_Ar7000_PibRamCpy.U8[0])
    {
      EthTrcv_30_Ar7000_ModOpParams.ModOpDataLenTx    = ETHTRCV_30_AR7000_MODOP_MAX_DATA_SIZE;
      EthTrcv_30_Ar7000_ModOpParams.ModOpCurOffset    = 0x00000000u;
      EthTrcv_30_Ar7000_ModOpParams.ModOpStartOffset  = 0x00000000u;
    }
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP */
#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK )
    if ( EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpBufPtr == &EthTrcv_30_Ar7000_Nmk[0] )
    {
      EthTrcv_30_Ar7000_ModOpParams.ModOpDataLenTx    = ETHTRCV_30_AR7000_NMK_SIZE_BYTE;
      EthTrcv_30_Ar7000_ModOpParams.ModOpCurOffset    = ETHTRCV_30_AR7000_NMK_PIB_OFFSET;
      EthTrcv_30_Ar7000_ModOpParams.ModOpStartOffset  = ETHTRCV_30_AR7000_NMK_PIB_OFFSET;
    }
#endif /* ETHTRCV_30_AR7000_ENABLE_READ_NMK */

    EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState = ETHTRCV_30_AR7000_MODOP_STATE_NOT_USED;

    /* update module operation timeout counter and send the module operation MME request again */
    if ( ETHTRCV_30_AR7000_MODOP_MAX_RETRANS >= EthTrcv_30_Ar7000_ModOpRetryCnt )
    {
      EthTrcv_30_Ar7000_ModOpRetryCnt++;
      resVal = EthTrcv_30_Ar7000_MME_ModuleOperation(
        TrcvIdx,
        ETHTRCV_30_AR7000_MODOP_RD_MEM,
        (P2VAR(EthTrcv_30_Ar7000_ModOp_Params, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT))&EthTrcv_30_Ar7000_ModOpParams); /* PRQA S 0310 */ /* MD_EthTrcv_30_Ar7000_ModOpParams */

      if ( E_NOT_OK == resVal )
      {
        /* no further retransmissions at this point */
        EthTrcv_30_Ar7000_ModOpRetryCnt = 0u;
      }
    }
    else
    {
      /* No further retransmissions at this point - try again later */
      EthTrcv_30_Ar7000_ModOpRetryCnt = 0u;
    }
  }

  ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
} /* EthTrcv_30_Ar7000_ModuleOperation() */
#endif /* ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) ||
          ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK)    ||
          ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API) */

#if ( ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_PBEncryption
 **********************************************************************************************************************/
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
 */
ETHTRCV_30_AR7000_LOCAL FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_PBEncryption(
        uint8                                                          TrcvIdx,
        EthTrcv_30_Ar7000_PBActionType                                 PBAction,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) MStatus,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) AVLNStatus)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_ReturnType retVal = ETHTRCV_30_AR7000_RT_NOT_OK; /* Return value of this function */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

  /* #10 Verify timeout counter (see MainFunction()) not exceeded */
  if ( ETHTRCV_30_AR7000_CONFTIMEOUT <= EthTrcv_30_Ar7000_SCConfCycCnt )
  {
    EthTrcv_30_Ar7000_SCStateConfReady = ETHTRCV_30_AR7000_STATE_NOT_READY;
    EthTrcv_30_Ar7000_IsChangingSCState = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
    EthTrcv_30_Ar7000_SCConfCycCnt = 0u;

    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

    /* ETHTRCV_30_AR7000_RT_NOT_OK */
  }

  /* #20 Verify QCA confirmation
   *       Inform caller if it is still pending
   */
  else if ( ETHTRCV_30_AR7000_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsChangingSCState )
  {
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

    retVal = ETHTRCV_30_AR7000_RT_PENDING;
  }

  /* #30 Verify received QCA confirmation
   *       Fill output parameter with network status information and received MME confirmation status
   */
  else if (ETHTRCV_30_AR7000_STATE_READY == EthTrcv_30_Ar7000_SCStateConfReady)
  {
    /* (ETHTRCV_30_AR7000_NO_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsChangingSCState) */
    EthTrcv_30_Ar7000_SCStateConfReady = ETHTRCV_30_AR7000_STATE_NOT_READY;
    *MStatus = EthTrcv_30_Ar7000_PbMStatus;
    *AVLNStatus = EthTrcv_30_Ar7000_PbAvlnStatus;

    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

    retVal = ETHTRCV_30_AR7000_RT_OK;
  }

  /* #40 No PBEncrytion() call pending
   *       Send push button encryption MME request to QCA
   *         Activate the timeout counter
   *         Inform the caller that QCA confirmation is pending
   */
  else
  {
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
    if ( E_OK == EthTrcv_30_Ar7000_MME_PBEncryption(TrcvIdx, PBAction) )
    {
      EthTrcv_30_Ar7000_IsChangingSCState = ETHTRCV_30_AR7000_WAIT_ON_CONF;
      EthTrcv_30_Ar7000_SCStateConfReady = ETHTRCV_30_AR7000_STATE_NOT_READY;
#if (defined ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD )
      /* NMK will be randomized, set link information to DOWN and activate LinkStateLockCnt, to prevent link state toggling.
       * Else QCA7005 may indicate a link during NMK change process even if there is no link available.
       */
      EthTrcv_30_Ar7000_LinkStateLockCnt = ETHTRCV_30_AR7000_LINKSTATE_LOCK_CYCLES;
      EthTrcv_30_Ar7000_LinkState        = ETHTRCV_LINK_STATE_DOWN;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

      retVal = ETHTRCV_30_AR7000_RT_PENDING;
    }
    else
    {
      /* ETHTRCV_30_AR7000_RT_NOT_OK */
    }
  }

  return retVal;
} /* EthTrcv_30_Ar7000_PBEncryption() */
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON */

/**********************************************************************************************************************
 *  Others
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_VFrameHeader
 **********************************************************************************************************************/
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
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_VFrameHeader(
    uint8                                                                                                     TrcvIdx,
    uint16                                                                                                    MMType,
    P2CONST(EthTrcv_30_Ar7000_EthernetBufferType, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_CONST) EthBufPtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (EthBufPtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else if (EthBufPtr->BufLen < ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_CONFIG;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

    /* #20 Initialize the given Ethernet buffer to zero */
    /* PRQA S 0314 1 */ /* MD_EthTrcv_30_Ar7000_VStdLibBuffer */
    IpBase_Fill((P2VAR(void, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR))&EthBufPtr->Buffer.U8[6u], 0x00u, ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE - 6u);

    /* #30 Set MME-Header
     *       MME-Version: 0
     *       MME-Type: MMType
     *       Atheros-OUI
     */
    EthBufPtr->Buffer.U8[0u] = (uint8)0x00u;          /* MMV */
    EthBufPtr->Buffer.U8[1u] = (uint8) MMType;        /* MMTYPE */
    EthBufPtr->Buffer.U8[2u] = (uint8)(MMType >> 8u); /* MMTYPE */
    EthBufPtr->Buffer.U8[3u] = (uint8)0x00u;          /* Atheros OUI */
    EthBufPtr->Buffer.U8[4u] = (uint8)0xb0u;          /* Atheros OUI */
    EthBufPtr->Buffer.U8[5u] = (uint8)0x52u;          /* Atheros OUI */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_V_FRAME_HEADER, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
} /* EthTrcv_30_Ar7000_VFrameHeader() */


#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_VCalcChecksum
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC(uint32, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_VCalcChecksum(
    uint8 TrcvIdx,
    P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr,
    uint32 DataLenByte)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_EthernetBufferUnionConstType srcBuffer;                                                             /* PRQA S 0759 */ /* MD_EthTrcv_30_Ar7000_BufferAccessUnion */
  uint32 v32BitXor = 0u;
  uint32 u32Idx;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  /* #10 Access the buffer with 32 bit value for better performance */
  srcBuffer.U8 = DataPtr;
  u32Idx = DataLenByte >> 2u;

  /* #20 Iterate over the data array and XOR each element */
  while ( 0u < u32Idx)
  {
    u32Idx--;
    v32BitXor ^= srcBuffer.U32[u32Idx];/* XOR each word */
  }

  /* #30 The finally checksum is the one's complement of the previous XOR iteration */
  v32BitXor = ~v32BitXor;

  return v32BitXor;
} /* EthTrcv_30_Ar7000_VCalcChecksum() */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) || \
      ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)) )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_VGetPibModuleOffset
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
ETHTRCV_30_AR7000_LOCAL FUNC (uint8, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_VGetPibModuleOffset(
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_DATA)                            PibPtr,              /* PRQA S 3673 */ /* MD_EthTrcv_30_Ar7000_AssignedToVarLater */
  P2VAR(uint8*, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_DATA)                           ModOffset,
  P2VAR(EthTrcv_30_Ar7000_NVMHeaderType*, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_DATA) ModHdrOffset)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(EthTrcv_30_Ar7000_NVMHeaderType, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_DATA) curModHeader;         /* PRQA S 3678 */ /* MD_EthTrcv_30_Ar7000_AssignedToVarLater */
  Std_ReturnType retVal = E_NOT_OK; /* Return value of this function */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* PRQA S 0310, 3305 1 */ /* MD_EthTrcv_30_Ar7000_PibFileHeaderAccess */
  curModHeader = (P2VAR(EthTrcv_30_Ar7000_NVMHeaderType, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_DATA)) PibPtr;

  /* #10 Iterate over the NVM chain to find the PIB module header
   *     Iteration is done if we found the header or if we reached the last element in the chain
   */
  /* PRQA S 3415 2 */ /* MD_EthTrcv_30_Ar7000_SwapValueForCompare */
  while ( (ETHTRCV_30_AR7000_HTOLIEN32(curModHeader->EntryType) != ETHTRCV_30_AR7000_ENTRY_TYPE_PIB) &&
         ( ETHTRCV_30_AR7000_HTOLIEN32(curModHeader->NextNvmHeaderPtr) != 0xFFFFFFFFu) )
  {
    /* PRQA S 0310, 3305 1 */ /* MD_EthTrcv_30_Ar7000_PibFileHeaderAccess */
    curModHeader = (P2VAR(EthTrcv_30_Ar7000_NVMHeaderType, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_DATA))&PibPtr[ETHTRCV_30_AR7000_HTOLIEN32(curModHeader->NextNvmHeaderPtr)];
  }

  /* #20 Inform calling routine if PIB module was found within the chain */
  if ( ETHTRCV_30_AR7000_ENTRY_TYPE_PIB == ETHTRCV_30_AR7000_HTOLIEN32(curModHeader->EntryType) )
  {
    /* PIB Module Header found */
    *ModOffset = &PibPtr[ETHTRCV_30_AR7000_HTOLIEN32(curModHeader->ImageNvmAddress)];
    *ModHdrOffset = (P2VAR(EthTrcv_30_Ar7000_NVMHeaderType, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_DATA))curModHeader;

    retVal = E_OK;
  }

  return retVal;
} /* EthTrcv_30_Ar7000_VGetPibModuleOffset() */
#endif /* ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB ||
          STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK */


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_InitMemory
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_InitMemory(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  /* #10 If DET is enabled set state to UNINIT */
  EthTrcv_30_Ar7000_State = ETHTRCV_STATE_UNINIT;
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON */


  return;
} /* EthTrcv_30_Ar7000_InitMemory() */

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_Init
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_Init(
    P2CONST(EthTrcv_30_Ar7000_ConfigType, AUTOMATIC, AUTOMATIC) CfgPtr)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(CfgPtr);                                                                            /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  EthTrcv_30_Ar7000_CycleCnt = ETHTRCV_30_AR7000_LINKSTATEPOLLINGFREQ;

#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  EthTrcv_30_Ar7000_State = ETHTRCV_STATE_INIT;
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON */

  /* #10 Set PIB data block */
#if (defined ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD )
  EthTrcv_30_Ar7000_PIBData = PIBData;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */
} /* EthTrcv_30_Ar7000_Init() */

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_TransceiverInit
 **********************************************************************************************************************/
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
 */
/* PRQA S 6080, 6050 1 */ /* MD_MSR_STMIF, MD_MSR_STCAL */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_TransceiverInit(
    uint8 TrcvIdx,
    uint8 CfgIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
#if (   (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) \
     || ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)) )
  P2VAR(EthTrcv_30_Ar7000_NVMHeaderType, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) moduleHdrOffset;
  P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) pibModuleOffset;
  uint32 pibChecksum;
#endif /* (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIBS) ||
          (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function */
  Std_ReturnType resVal; /* Result value of called functions */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (EthTrcv_30_Ar7000_State == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (CfgIdx >= ETHTRCV_30_AR7000_MAX_CFGS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_CONFIG;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 trigger start of runtime measurement
     *     Set link-state and mode-state to down as default
     *     Initialize all transceiver related variables and structs
     */
    EthTrcv_30_Ar7000_Rtm_Start(TransceiverInit);

#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
    EthTrcv_30_Ar7000_State = ETHTRCV_STATE_ACTIVE;
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON */

    /* Link-State is per default down */
    EthTrcv_30_Ar7000_LinkState = ETHTRCV_LINK_STATE_DOWN;
    EthTrcv_30_Ar7000_HeartBeatCnt = 0u;
    EthTrcv_30_Ar7000_DwldAttempts = ETHTRCV_30_AR7000_FW_DWLD_ATTEMPTS;

    /* Mode state is also down */
    /* Init controller and CPU mode */
    resVal = EthTrcv_30_Ar7000_SetTransceiverMode(TrcvIdx, ETHTRCV_MODE_DOWN);

    if (E_OK == resVal)
    {

#if ( ETHTRCV_30_AR7000_ENABLE_READ_NMK == STD_ON )
      EthTrcv_30_Ar7000_IsReadingNmk  = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
      EthTrcv_30_Ar7000_NmkReady      = ETHTRCV_30_AR7000_STATE_NOT_READY;
      EthTrcv_30_Ar7000_ReadNmkCycCnt = 0u;
#endif /* ETHTRCV_30_AR7000_ENABLE_READ_NMK */

#if ( ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON )
      EthTrcv_30_Ar7000_IsChangingSCState = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
      EthTrcv_30_Ar7000_SCStateConfReady  = ETHTRCV_30_AR7000_STATE_NOT_READY;
      EthTrcv_30_Ar7000_SCConfCycCnt      = 0u;
      EthTrcv_30_Ar7000_PbAvlnStatus      = 0u;
      EthTrcv_30_Ar7000_PbMStatus         = 0u;
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_NMK == STD_ON )
      EthTrcv_30_Ar7000_SetKeyIsChanging = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON )
      EthTrcv_30_Ar7000_IsReadingSwVersion = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
      EthTrcv_30_Ar7000_SWVersionAvailable = ETHTRCV_30_AR7000_STATE_NOT_READY;
      EthTrcv_30_Ar7000_GetSwVersionCycCnt = 0u;
      EthTrcv_30_Ar7000_SwMStatus          = 0u;
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API == STD_ON )
      EthTrcv_30_Ar7000_IsSettingProperty       = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
      EthTrcv_30_Ar7000_SetPropertyCnfAvailable = ETHTRCV_30_AR7000_STATE_NOT_READY;
      EthTrcv_30_Ar7000_SetPropertyCycCnt       = 0u;
      EthTrcv_30_Ar7000_SetPropertyStatus       = 0u;
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
      EthTrcv_30_Ar7000_DownlStatus                = ETHTRCV_30_AR7000_DOWNLSTATUS_MEMCTRL;
      EthTrcv_30_Ar7000_ClientSid                  = 0u;
#if (defined(ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD == STD_ON))
      EthTrcv_30_Ar7000_FailedApiCall              = (EthTrcv_30_Ar7000_FailedApiCallType)NULL_PTR; /*lint !e611 */
      EthTrcv_30_Ar7000_ApiCallRetCnt              = 0u;
#endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */
      EthTrcv_30_Ar7000_WriteAppletLockCnt         = 0u;
      EthTrcv_30_Ar7000_AppletNrLocked             = ETHTRCV_30_AR7000_NO_APPLET_LOCKED;
      EthTrcv_30_Ar7000_LinkStateLockCnt           = ETHTRCV_30_AR7000_LINKSTATE_LOCK_CYCLES;

      EthTrcv_30_Ar7000_FwDwldStartCbkCalled       = FALSE;
      EthTrcv_30_Ar7000_FwStartedCbkCalled         = FALSE;
      EthTrcv_30_Ar7000_FwReadyForSlacCbkCalled    = FALSE;
      EthTrcv_30_Ar7000_FwReadyForSlacLastResult   = FALSE;
      EthTrcv_30_Ar7000_FwDownloadAndStartCnt      = ETHTRCV_30_AR7000_FIRMWARE_DOWNLOAD_AND_START_CYCLES;
      EthTrcv_30_Ar7000_FwReadyForSlacCnt          = ETHTRCV_30_AR7000_FIRMWARE_READY_FOR_SLAC_TIMEOUT_CYCLES;
      {
        uint8_least hstActionIdx;
        for (hstActionIdx = 0u; hstActionIdx < ETHTRCV_30_AR7000_HST_ACTION_QUEUE_SIZE; hstActionIdx++)
        {
          EthTrcv_30_Ar7000_HstAction[hstActionIdx] = ETHTRCV_30_AR7000_NO_HST_ACTION_REQUIRED;
        }
        EthTrcv_30_Ar7000_HstActionIdx = 0u;
        EthTrcv_30_Ar7000_HstActionCnt = 0u;
      }
# if ((defined ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (STD_OFF==ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD))
      EthTrcv_30_Ar7000_MME_WaEA_Params.NeedToSend = FALSE;
# endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */


#if (   (ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP == STD_ON) \
     || (ETHTRCV_30_AR7000_ENABLE_READ_NMK == STD_ON) \
     || (ETHTRCV_30_AR7000_ENABLE_MODOP_API == STD_ON) )
      EthTrcv_30_Ar7000_ModOpRetryCnt                       = 0u;
      EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState   = ETHTRCV_30_AR7000_MODOP_STATE_NOT_USED;
      EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpLockCnt = 0u;
      EthTrcv_30_Ar7000_ModOpCycCnt                         = 0u;
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP || ETHTRCV_30_AR7000_ENABLE_MODOP_API ||
        * ETHTRCV_30_AR7000_ENABLE_READ_NMK */

#if (   (STD_ON == ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD) \
     && (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP) )
      EthTrcv_30_Ar7000_WillResetAfterPibUpload = FALSE;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD && ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP */

#if (   (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) \
     || ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)) )

      ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
      /* #30 Copy PIB to RAM */
      /* PRQA S 0314 5 */ /* MD_MSR_VStdLib */
      IpBase_Copy(
            (P2VAR(void, AUTOMATIC, IPBASE_APPL_DATA))&EthTrcv_30_Ar7000_PibRamCpy.U8[0],
            (P2CONST(void, AUTOMATIC, IPBASE_APPL_DATA))EthTrcv_30_Ar7000_PIBData,
            (uint32)ETHTRCV_30_AR7000_PIB_SIZE
          );

      resVal = EthTrcv_30_Ar7000_VGetPibModuleOffset(&EthTrcv_30_Ar7000_PibRamCpy.U8[0], &pibModuleOffset, &moduleHdrOffset);

      if ( E_OK == resVal )
      {
# if (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB)
#  if (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_CONST)
        /* Copy MAC address from constant config to the used variable */
        EthTrcv_30_Ar7000_VCfgGetPhysAddr()[0] = EthTrcv_30_Ar7000_VCfgGetPhysAddrDefault()[0];
        EthTrcv_30_Ar7000_VCfgGetPhysAddr()[1] = EthTrcv_30_Ar7000_VCfgGetPhysAddrDefault()[1];
        EthTrcv_30_Ar7000_VCfgGetPhysAddr()[2] = EthTrcv_30_Ar7000_VCfgGetPhysAddrDefault()[2];
        EthTrcv_30_Ar7000_VCfgGetPhysAddr()[3] = EthTrcv_30_Ar7000_VCfgGetPhysAddrDefault()[3];
        EthTrcv_30_Ar7000_VCfgGetPhysAddr()[4] = EthTrcv_30_Ar7000_VCfgGetPhysAddrDefault()[4];
        EthTrcv_30_Ar7000_VCfgGetPhysAddr()[5] = EthTrcv_30_Ar7000_VCfgGetPhysAddrDefault()[5];
#  endif
        /* Set MAC address */
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 0u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[0u];
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 1u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[1u];
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 2u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[2u];
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 3u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[3u];
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 4u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[4u];
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 5u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[5u];
# endif /* ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB */

# if (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)
        /* Write DAK */
        /* PRQA S 0314 5 */ /* MD_MSR_VStdLib */
        IpBase_Copy(
            (P2VAR(void, AUTOMATIC, IPBASE_APPL_DATA))&pibModuleOffset[ETHTRCV_30_AR7000_DAK_PIB_OFFSET],
            (P2VAR(void, AUTOMATIC, IPBASE_APPL_DATA))EthTrcv_30_Ar7000_VCfgGetDak(),
            ETHTRCV_30_AR7000_DAK_SIZE_BYTE
          );
# endif /* ETHTRCV_30_AR7000_ENABLE_WRITE_DAK */

        /* Checksum module */
        moduleHdrOffset->ImageChecksum = 0x00000000u;
        pibChecksum = EthTrcv_30_Ar7000_VCalcChecksum(TrcvIdx, pibModuleOffset, ETHTRCV_30_AR7000_LIENTOH32(moduleHdrOffset->ImageLength));
        moduleHdrOffset->ImageChecksum = pibChecksum;

        /* Checksum header */
        moduleHdrOffset->HeaderChecksum = 0x00000000u;

        pibChecksum = EthTrcv_30_Ar7000_VCalcChecksum(TrcvIdx,
          (P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT))moduleHdrOffset, sizeof(*moduleHdrOffset));
        moduleHdrOffset->HeaderChecksum = pibChecksum;

        EthTrcv_30_Ar7000_PibRamCpyValid = TRUE;
      }
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
#else
# if ((defined ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP))
      EthTrcv_30_Ar7000_PibRamCpyValid = FALSE;
# endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP */

#endif /* (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) || ETHTRCV_30_AR7000_ENABLE_WRITE_DAK */
    }

    /* Set return value */
    retVal = resVal;

    /* #40 trigger stop of runtime measurement */
    EthTrcv_30_Ar7000_Rtm_Stop(TransceiverInit);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_TRANSCEIVER_INIT, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(CfgIdx);                                                                            /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_TransceiverInit() */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_TRCV_MODE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetTransceiverMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetTransceiverMode(
  uint8            TrcvIdx,
  EthTrcv_ModeType TrcvMode)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function */
  Std_ReturnType resVal; /* Result value of called functions */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Enable/disable transceiver
     *     Verify that enable/disable was OK
     *       Set ModeState
     *       Set LinkState to down if transceiver was disabled
     */
    if ( ETHTRCV_MODE_ACTIVE == TrcvMode )
    {
      /* enable core */
      resVal = ETHTRCV_30_AR7000_ETH_WRITESPI(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ETHTRCV_30_AR7000_ETH_SPI_REG_CONFIG, ETHTRCV_30_AR7000_SPI_IO_ENABLE);
    }
    else
    {
      /* disable core */
      resVal = ETHTRCV_30_AR7000_ETH_WRITESPI(EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx(), ETHTRCV_30_AR7000_ETH_SPI_REG_CONFIG, ETHTRCV_30_AR7000_SPI_IO_DISABLE);
    }

    if (E_OK == resVal)
    {
      EthTrcv_30_Ar7000_ModeState = TrcvMode;
      if (ETHTRCV_MODE_DOWN == TrcvMode)
      {
        EthTrcv_30_Ar7000_LinkState = ETHTRCV_LINK_STATE_DOWN;
      }
    }

    /* Set return value */
    retVal = resVal;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_SET_TRANSCEIVER_MODE, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_SetTransceiverMode() */
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_TRCV_MODE */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_TRCV_MODE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetTransceiverMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetTransceiverMode(
        uint8                                   TrcvIdx,
  P2VAR(EthTrcv_ModeType, AUTOMATIC, AUTOMATIC) TrcvModePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (TrcvModePtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Inform calling application about mode state */
    *TrcvModePtr = EthTrcv_30_Ar7000_ModeState;

    /* Set return value */
    retVal = E_OK;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_GET_TRANSCEIVER_MODE, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif


  return retVal;
} /* EthTrcv_30_Ar7000_GetTransceiverMode() */
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_TRCV_MODE */

#if ( ETHTRCV_30_AR7000_ENABLE_START_AUTO_NEG == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_StartAutoNegotiation
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_StartAutoNegotiation(
  uint8 TrcvIdx)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* Return value of this function */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else
#endif
  {
    /* Auto-Negotiation is not supported by QCA */
    /* Return E_NOT_OK, this is not supported */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_START_AUTO_NEG, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_StartAutoNegotiation() */
#endif /* ETHTRCV_30_AR7000_ENABLE_START_AUTO_NEG */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_LINK_STATE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetLinkState
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetLinkState(
        uint8                                        TrcvIdx,
  P2VAR(EthTrcv_LinkStateType, AUTOMATIC, AUTOMATIC) LinkStatePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (LinkStatePtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Inform calling application about link state */
    if(ETHTRCV_LINK_STATE_DOWN == EthTrcv_30_Ar7000_LinkState)
    {
      *LinkStatePtr = ETHTRCV_LINK_STATE_DOWN;
    }
    else
    {
      *LinkStatePtr = ETHTRCV_LINK_STATE_ACTIVE;
    }
    /* Set return value */
    retVal = E_OK;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_GET_LINK_STATE, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_GetLinkState() */
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_LINK_STATE */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_BAUD_RATE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetBaudRate
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetBaudRate(
        uint8                                       TrcvIdx,
  P2VAR(EthTrcv_BaudRateType, AUTOMATIC, AUTOMATIC) BaudRatePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (BaudRatePtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Inform calling application */
    /* Baudrate of 100MBit with QCA7005 not possible */
    *BaudRatePtr = ETHTRCV_BAUD_RATE_10MBIT;
    /* Set return value */
    retVal = E_OK;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_GET_BAUD_RATE, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_GetBaudRate() */
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_BAUD_RATE */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_DUPLEX_MODE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetDuplexMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetDuplexMode(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_DuplexModeType, AUTOMATIC, AUTOMATIC) DuplexModePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (DuplexModePtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Inform calling application */
    *DuplexModePtr = ETHTRCV_DUPLEX_MODE_FULL;
    /* Set return value */
    retVal = E_OK;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_GET_DUPLEX_MODE, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_GetDuplexMode() */
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_DUPLEX_MODE */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_NMK == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetNmk
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetNmk(
    uint8 TrcvIdx,
    P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) NmkPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function */
  Std_ReturnType resVal; /* Result value of called functions */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (NmkPtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Just send the network membership key to the QCA (not permanently). */
    resVal = EthTrcv_30_Ar7000_MME_SetKey(TrcvIdx, NmkPtr);

#if (    ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON \
      && ETHTRCV_30_AR7000_ENABLE_LINK_STATE_POLLING_PAUSE_AFTER_SET_NMK == STD_ON )
    /* #30 Check if successfull, if yes pause the link state polling. */
    if (resVal == E_OK)
    {
      EthTrcv_30_Ar7000_PauseLinkStatePolling(TrcvIdx, ETHTRCV_30_AR7000_LINKSTATE_LOCK_CYCLES * ETHTRCV_30_AR7000_MAINFUNC_CYCLE_TIME);
    }
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON 
       && ETHTRCV_30_AR7000_ENABLE_LINK_STATE_POLLING_PAUSE_AFTER_SET_NMK == STD_ON  */

    /* Set return value */
    retVal = resVal;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_SET_NMK, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_SetNmk() */                                                                                      /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_NMK */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_PauseLinkStatePolling
 **********************************************************************************************************************/
 /*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_PauseLinkStatePolling(
  uint8                                                            TrcvIdx,
  uint16                                                           PauseDurationMs)
{
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
  */
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Set variable values so that the polling will be paused. */
    EthTrcv_30_Ar7000_LinkStateLockCnt = (uint16)(PauseDurationMs / ETHTRCV_30_AR7000_MAINFUNC_CYCLE_TIME);
    EthTrcv_30_Ar7000_HeartBeatCnt = 0u;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_PAUSE_LINK_STATE_POLLING, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
} /* EthTrcv_30_Ar7000_PauseLinkStatePolling() */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( ETHTRCV_30_AR7000_ENABLE_READ_NMK == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_ReadNmk
 **********************************************************************************************************************/
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
 */
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_ReadNmk(                                   /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
    uint8 TrcvIdx,
    P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) NmkPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8_least nmkIdx;
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  EthTrcv_30_Ar7000_ReturnType retVal = ETHTRCV_30_AR7000_RT_NOT_OK; /* Return value of this function */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (NmkPtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
    /* #20 Verify timeout counter (see MainFunction()) not exceeded */
    if ( ETHTRCV_30_AR7000_CONFTIMEOUT <= EthTrcv_30_Ar7000_ReadNmkCycCnt )
    {
      EthTrcv_30_Ar7000_NmkReady = ETHTRCV_30_AR7000_STATE_NOT_READY;
      EthTrcv_30_Ar7000_IsReadingNmk = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
      EthTrcv_30_Ar7000_ReadNmkCycCnt = 0u;

      /* ETHTRCV_30_AR7000_RT_NOT_OK */
    }

    /* #30 Inform calling application that QCA confirmation is pending */
    else if ( ETHTRCV_30_AR7000_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsReadingNmk )
    {
      retVal = ETHTRCV_30_AR7000_RT_PENDING;
    }

    /* #40 Got QCA confirmation
     *       Return current set network membership key
     */
    else if (ETHTRCV_30_AR7000_STATE_READY == EthTrcv_30_Ar7000_NmkReady)
    {
      /* (ETHTRCV_30_AR7000_NO_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsReadingNmk) */
      /* Copy NMK */
      for(nmkIdx = 0u; nmkIdx < ETHTRCV_30_AR7000_NMK_SIZE_BYTE; nmkIdx++)
      {
        NmkPtr[nmkIdx] = EthTrcv_30_Ar7000_Nmk[nmkIdx];
      }
      EthTrcv_30_Ar7000_NmkReady = ETHTRCV_30_AR7000_STATE_NOT_READY;

      retVal = ETHTRCV_30_AR7000_RT_OK;
    }

    /* #50 No ReadNmk() pending
     *       Get lock for module operation
     *       Set the module operation related data for reading the whole pib (which contain the nmk)
     *       Send MME request to QCA
     *         Activate the timeout counter
     *         Inform the calling application that QCA confirmation is pending
     */
    else
    {
      /* Get ModOp Lock */
      EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpLockCnt++;

      if (1u == EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpLockCnt)
      {
        /* Send Module Operation Frame for Read Request */
        if (EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState == ETHTRCV_30_AR7000_MODOP_STATE_NOT_USED)
        {
          EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState = ETHTRCV_30_AR7000_MODOP_STATE_USED;

          ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

          EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpFrameLen = ETHTRCV_30_AR7000_MODOP_RD_HDR_LEN;
          EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpBufPtr   = &EthTrcv_30_Ar7000_Nmk[0u];
          EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpTotLen   = ETHTRCV_30_AR7000_NMK_SIZE_BYTE;
          EthTrcv_30_Ar7000_ModOpParams.ModOpModuleId            = ETHTRCV_30_AR7000_MOD_ID_PIB;
          EthTrcv_30_Ar7000_ModOpParams.ModOpModuleSubId         = 0x0000u;
          EthTrcv_30_Ar7000_ModOpParams.ModOpDataLenTx           = ETHTRCV_30_AR7000_NMK_SIZE_BYTE;
          EthTrcv_30_Ar7000_ModOpParams.ModOpCurOffset           = ETHTRCV_30_AR7000_PIB_MODULE_OFFSET + ETHTRCV_30_AR7000_NMK_PIB_OFFSET;
          EthTrcv_30_Ar7000_ModOpParams.ModOpStartOffset         = ETHTRCV_30_AR7000_PIB_MODULE_OFFSET + ETHTRCV_30_AR7000_NMK_PIB_OFFSET;

          /* PRQA S 0310 1 */ /* MD_EthTrcv_30_Ar7000_ModOpParams */
          if(E_OK == EthTrcv_30_Ar7000_MME_ModuleOperation(TrcvIdx, ETHTRCV_30_AR7000_MODOP_RD_MEM, (EthTrcv_30_Ar7000_ModOp_Params*)&EthTrcv_30_Ar7000_ModOpParams))
          {
            ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
            /* successful */
            EthTrcv_30_Ar7000_IsReadingNmk = ETHTRCV_30_AR7000_WAIT_ON_CONF;
            EthTrcv_30_Ar7000_NmkReady = ETHTRCV_30_AR7000_STATE_NOT_READY;
            retVal = ETHTRCV_30_AR7000_RT_PENDING;
          }
          else
          {
            ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
            /* ETHTRCV_30_AR7000_RT_NOT_OK */
          }
        }
        else
        {
          /* ETHTRCV_30_AR7000_RT_NOT_OK */
        }
      }
      else
      {
        /* ETHTRCV_30_AR7000_RT_NOT_OK */
      }
      EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpLockCnt--;
    }

    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_READ_NMK, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_ReadNmk() */
#endif /* ETHTRCV_30_AR7000_ENABLE_READ_NMK */

#if (ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON)
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetSwVersion
 **********************************************************************************************************************/
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
 */
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetSwVersion(                              /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
    uint8 TrcvIdx,
    P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) SwVersionPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8_least swVersionIdx;
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  EthTrcv_30_Ar7000_ReturnType retVal = ETHTRCV_30_AR7000_RT_NOT_OK; /* Return value of this function */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  /* SwVersionPtr == NULL_PTR is allowed */
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

    /* #20 Verify timeout counter (see MainFunction()) not exceeded */
    if ( ETHTRCV_30_AR7000_CONFTIMEOUT <= EthTrcv_30_Ar7000_GetSwVersionCycCnt )
    {
      EthTrcv_30_Ar7000_SWVersionAvailable = ETHTRCV_30_AR7000_STATE_NOT_READY;
      EthTrcv_30_Ar7000_IsReadingSwVersion = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
      EthTrcv_30_Ar7000_GetSwVersionCycCnt = 0u;

      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

      /* ETHTRCV_30_AR7000_RT_NOT_OK */
    }

    /* #30 Inform calling application that QCA confirmation is pending */
    else if ( ETHTRCV_30_AR7000_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsReadingSwVersion )
    {
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

      retVal = ETHTRCV_30_AR7000_RT_PENDING;
    }

    /* #40 Got QCA confirmation
     *       Verify that confirmation status was 'success'
     *         Return QCA software version
     */
    else if (ETHTRCV_30_AR7000_STATE_READY == EthTrcv_30_Ar7000_SWVersionAvailable)
    {
      /* (ETHTRCV_30_AR7000_NO_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsReadingSwVersion) */
      if ( ETHTRCV_30_AR7000_MSTATUS_OK == EthTrcv_30_Ar7000_SwMStatus )
      {
        if ( NULL_PTR != SwVersionPtr )
        {
          /* Copy SW Version */
          for (swVersionIdx = 0u; swVersionIdx < sizeof(EthTrcv_30_Ar7000_SwVersion); swVersionIdx++)
          {
            SwVersionPtr[swVersionIdx] = EthTrcv_30_Ar7000_SwVersion[swVersionIdx];
          }
        }
        EthTrcv_30_Ar7000_SWVersionAvailable = ETHTRCV_30_AR7000_STATE_NOT_READY;

        retVal = ETHTRCV_30_AR7000_RT_OK;
      }
      else
      {
        /* ETHTRCV_30_AR7000_RT_NOT_OK */
      }
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
    }

    /* #50 No GetSwVersion() call pending
     *       Send MME request to QCA
     *         Activate the timeout counter
     *         Inform the calling application that QCA confirmation is pending
     */
    else
    {
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

      if ( E_OK == EthTrcv_30_Ar7000_MME_GetSwVersion(TrcvIdx) )
      {
        /* successful */
        EthTrcv_30_Ar7000_IsReadingSwVersion = ETHTRCV_30_AR7000_WAIT_ON_CONF;
        EthTrcv_30_Ar7000_SWVersionAvailable = ETHTRCV_30_AR7000_STATE_NOT_READY;
        retVal = ETHTRCV_30_AR7000_RT_PENDING;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_GET_SW_VERSION, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_GetSwVersion() */
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

#if ( ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_ResetDevice
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_ResetDevice(
    uint8 TrcvIdx)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function */
  Std_ReturnType resVal; /* Result value of called functions */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else
#endif
  {
#if (ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON)
    EthTrcv_30_Ar7000_WriteAppletLockCnt = 0u;
    EthTrcv_30_Ar7000_AppletNrLocked = ETHTRCV_30_AR7000_NO_APPLET_LOCKED;
# if(STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP)
    EthTrcv_30_Ar7000_WillResetAfterPibUpload = FALSE;
# endif
#endif

    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Reset the QCA7000 */
    resVal = EthTrcv_30_Ar7000_MME_ResetDevice(TrcvIdx);

    /* Set return value */
    retVal = resVal;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_RESET_DEVICE, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_ResetDevice() */
#endif /* ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE */

#if ( ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_JoinScState
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_JoinScState(
        uint8                                                          TrcvIdx,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) MStatus)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 AVLNStatus;
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  EthTrcv_30_Ar7000_ReturnType retVal; /* Return value of this function */
  EthTrcv_30_Ar7000_ReturnType resVal; /* Result value of called functions */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = ETHTRCV_30_AR7000_RT_NOT_OK;
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (MStatus == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Join a SimpleConnect Logical Network is done by a 'pushbutton simple connect' MME request */
    resVal = EthTrcv_30_Ar7000_PBEncryption(TrcvIdx, ETHTRCV_30_AR7000_PBACTION_JOIN, MStatus, &AVLNStatus);

    /* Set return value */
    retVal = resVal;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_JOIN_SC_STATE, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
  return retVal;

} /* EthTrcv_30_Ar7000_JoinScState() */

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_LeaveScState
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_LeaveScState(
        uint8                                                          TrcvIdx,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) MStatus)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 AVLNStatus;
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  EthTrcv_30_Ar7000_ReturnType retVal; /* Return value of this function */
  EthTrcv_30_Ar7000_ReturnType resVal; /* Result value of called functions */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = ETHTRCV_30_AR7000_RT_NOT_OK;
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (MStatus == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Leave a SimpleConnect Logical Network is done by a 'pushbutton simple connect' MME request */
    resVal = EthTrcv_30_Ar7000_PBEncryption(TrcvIdx, ETHTRCV_30_AR7000_PBACTION_LEAVE, MStatus, &AVLNStatus);

    /* Set return value */
    retVal = resVal;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_LEAVE_SC_STATE, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
  return retVal;
} /* EthTrcv_30_Ar7000_LeaveScState() */

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_ReadAVLNStatus
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_ReadAVLNStatus(
        uint8                                                          TrcvIdx,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) MStatus,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) AVLNStatus)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  EthTrcv_30_Ar7000_ReturnType retVal; /* Return value of this function */
  EthTrcv_30_Ar7000_ReturnType resVal; /* Result value of called functions */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = ETHTRCV_30_AR7000_RT_NOT_OK;
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (MStatus == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else if (AVLNStatus == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Request HomePlug AV Logical Network (AVLN) status is done by a 'pushbutton simple connect' MME request */
    resVal = EthTrcv_30_Ar7000_PBEncryption(TrcvIdx, ETHTRCV_30_AR7000_PBACTION_STATUS, MStatus, AVLNStatus);

    /* Set return value */
    retVal = resVal;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_READ_AVLN_STATUS, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_ReadAVLNStatus() */
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_NVM)
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_WritePhysAddr
 **********************************************************************************************************************/
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
/* PRQA S 6050, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_WritePhysAddr(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) PhysAddr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(EthTrcv_30_Ar7000_NVMHeaderType, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) moduleHdrOffset;
  P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) pibModuleOffset;
  P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) localPhysAddrPtr;
  uint32 pibChecksum;
  uint8 status;
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function */
  Std_ReturnType resVal; /* Result value of called functions */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (EthTrcv_30_Ar7000_State == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (PhysAddr == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

    /* #20 Get MAC address NvM block */
    status = NVM_REQ_PENDING;
    resVal = NvM_GetErrorStatus(EthTrcv_30_Ar7000_VCfgGetPhysAddrBlockId(TrcvIdx), &status);

    if ((E_OK == resVal) && (status != NVM_REQ_PENDING))
    {
      localPhysAddrPtr = &(EthTrcv_30_Ar7000_VCfgGetPhysAddr()[0]);
      /* #30 Update the host memory NvM block */
      localPhysAddrPtr[0u] = PhysAddr[0u];
      localPhysAddrPtr[1u] = PhysAddr[1u];
      localPhysAddrPtr[2u] = PhysAddr[2u];
      localPhysAddrPtr[3u] = PhysAddr[3u];
      localPhysAddrPtr[4u] = PhysAddr[4u];
      localPhysAddrPtr[5u] = PhysAddr[5u];
      {
        /* #40 Get PIB RAM copy */
        resVal = EthTrcv_30_Ar7000_VGetPibModuleOffset(&EthTrcv_30_Ar7000_PibRamCpy.U8[0], &pibModuleOffset, &moduleHdrOffset);
      }

      if ( E_OK == resVal )
      {

        /* #50 Update PIB block */
        /* Set new MAC for the QCA7000 */
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 0u] = PhysAddr[0u];
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 1u] = PhysAddr[1u];
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 2u] = PhysAddr[2u];
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 3u] = PhysAddr[3u];
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 4u] = PhysAddr[4u];
        pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 5u] = PhysAddr[5u];

        /* Checksum module */
        moduleHdrOffset->ImageChecksum = 0x00000000;
        pibChecksum = EthTrcv_30_Ar7000_VCalcChecksum(TrcvIdx, pibModuleOffset, ETHTRCV_30_AR7000_LIENTOH32(moduleHdrOffset->ImageLength));
        moduleHdrOffset->ImageChecksum = pibChecksum;

         /* Checksum header */
        moduleHdrOffset->HeaderChecksum = 0x00000000u;
        pibChecksum = EthTrcv_30_Ar7000_VCalcChecksum(TrcvIdx, (P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT))moduleHdrOffset, sizeof(*moduleHdrOffset));
        moduleHdrOffset->HeaderChecksum = pibChecksum;

        /* #60 Indicate PIB block and NvM RAM block as valid */
        EthTrcv_30_Ar7000_PibRamCpyValid = TRUE;

        /* set block status to true */
        resVal = NvM_SetRamBlockStatus(EthTrcv_30_Ar7000_VCfgGetPhysAddrBlockId(TrcvIdx), TRUE);

        /* Restart firmware if already running */
        if (EthTrcv_30_Ar7000_DownlStatus == ETHTRCV_30_AR7000_DOWNLSTATUS_DONE)
        {
          resVal |= EthTrcv_30_Ar7000_ResetDevice(TrcvIdx);
        }
      }
    }
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

    /* Set return value */
    retVal = resVal;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_WRITE_PHYS_ADDR, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_WritePhysAddr() */
#endif /* ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_NVM */

#if ( ETHTRCV_30_AR7000_ENABLE_WRITE_DAK == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_WriteDak
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_WriteDak(
               uint8                                                             TrcvIdx,
  CONSTP2CONST(uint8, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_DATA) Dak)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(EthTrcv_30_Ar7000_NVMHeaderType, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) moduleHdrOffset;
  P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) pibModuleOffset;
  uint32 pibChecksum;
  uint8 nvMStatus;
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function */
  Std_ReturnType resVal; /* Result value of called functions */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (EthTrcv_30_Ar7000_State == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (Dak == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

    /* #20 Get DAK NvM RAM block */
    nvMStatus = NVM_REQ_PENDING;
    resVal = NvM_GetErrorStatus(EthTrcv_30_Ar7000_VCfgGetDakBlockId(TrcvIdx), &nvMStatus);

    if((E_OK == resVal) && (nvMStatus != NVM_REQ_PENDING))
    {
      /* #30 Copy application given Device Access Key into NvM RAM block */
      /* PRQA S 0314 5 */ /* MD_MSR_VStdLib */
      IpBase_Copy(
        (P2VAR(void, AUTOMATIC, IPBASE_APPL_DATA))EthTrcv_30_Ar7000_VCfgGetDak(),
        (P2CONST(void, AUTOMATIC, IPBASE_APPL_DATA))Dak,
        ETHTRCV_30_AR7000_DAK_SIZE_BYTE
      );

      resVal = EthTrcv_30_Ar7000_VGetPibModuleOffset(&EthTrcv_30_Ar7000_PibRamCpy.U8[0], &pibModuleOffset, &moduleHdrOffset);

      if ( E_OK == resVal )
      {

        /* #40 Copy application given Device Access Key into local PIB file */
        /* PRQA S 0314 5 */ /* MD_MSR_VStdLib */
        IpBase_Copy(
          (P2VAR(void, AUTOMATIC, IPBASE_APPL_DATA))&pibModuleOffset[ETHTRCV_30_AR7000_DAK_PIB_OFFSET],
          (P2CONST(void, AUTOMATIC, IPBASE_APPL_DATA))Dak,
          ETHTRCV_30_AR7000_DAK_SIZE_BYTE
        );

        /* Checksum module */
        moduleHdrOffset->ImageChecksum = 0x00000000u;
        pibChecksum = EthTrcv_30_Ar7000_VCalcChecksum(TrcvIdx, pibModuleOffset, ETHTRCV_30_AR7000_LIENTOH32(moduleHdrOffset->ImageLength));
        moduleHdrOffset->ImageChecksum = pibChecksum;

          /* Checksum header */
        moduleHdrOffset->HeaderChecksum = 0x00000000u;
        pibChecksum = EthTrcv_30_Ar7000_VCalcChecksum(TrcvIdx, (P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT))moduleHdrOffset, sizeof(*moduleHdrOffset));
        moduleHdrOffset->HeaderChecksum = pibChecksum;

        /* #50 Indicate local PIB copy and NvM RAM block as valid */
        EthTrcv_30_Ar7000_PibRamCpyValid = TRUE;

        /* Restart firmware if already running */
        if (EthTrcv_30_Ar7000_DownlStatus == ETHTRCV_30_AR7000_DOWNLSTATUS_DONE)
        {
          resVal = EthTrcv_30_Ar7000_ResetDevice(TrcvIdx);
        }

        /* set block status to true */
        resVal |= NvM_SetRamBlockStatus(EthTrcv_30_Ar7000_VCfgGetDakBlockId(TrcvIdx), TRUE);
      }
    }
    else
    {
      resVal = E_NOT_OK;
    }
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

    /* Set return value */
    retVal = resVal;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_WRITE_DAK, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_WriteDak() */
#endif /* ETHTRCV_30_AR7000_ENABLE_WRITE_DAK */

#if (ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API == STD_ON)
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetProperty
 **********************************************************************************************************************/
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
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetProperty(                               /* PRQA S 6080 */ /* MD_MSR_STMIF */
  uint8 TrcvIdx,
  CONSTP2CONST(EthTrcv_30_Ar7000_SetPropertyParamterType, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_CONST) SetPropParams,
  P2VAR(EthTrcv_30_Ar7000_SetPropType, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) MStatus)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  EthTrcv_30_Ar7000_ReturnType retVal = ETHTRCV_30_AR7000_RT_NOT_OK; /* Return value of this function */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (EthTrcv_30_Ar7000_State == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  else if (SetPropParams == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

    /* #20 Verify timeout counter (see MainFunction()) not exceeded */
    if ( ETHTRCV_30_AR7000_CONFTIMEOUT <= EthTrcv_30_Ar7000_SetPropertyCycCnt )
    {
      EthTrcv_30_Ar7000_SetPropertyCnfAvailable = ETHTRCV_30_AR7000_STATE_NOT_READY;
      EthTrcv_30_Ar7000_IsSettingProperty       = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
      EthTrcv_30_Ar7000_SetPropertyCycCnt       = 0u;

      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

      /* ETHTRCV_30_AR7000_RT_NOT_OK */
    }

    /* #30 Inform calling application that QCA confirmation is pending */
    else if ( ETHTRCV_30_AR7000_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsSettingProperty )
    {
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

      retVal = ETHTRCV_30_AR7000_RT_PENDING;
    }

    /* #40 Got QCA confirmation
     *     Verify that confirmation status was 'success'
     *       Return QCA confirmation status to calling application.
     */
    else if (ETHTRCV_30_AR7000_STATE_READY == EthTrcv_30_Ar7000_SetPropertyCnfAvailable)
    {
      /* (ETHTRCV_30_AR7000_NO_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsSettingProperty) */
      EthTrcv_30_Ar7000_SetPropertyCnfAvailable = ETHTRCV_30_AR7000_STATE_NOT_READY;
      /* Set out value MStatus */
      *MStatus = (EthTrcv_30_Ar7000_SetPropType)EthTrcv_30_Ar7000_SetPropertyStatus;
      /* Set return value according to MStatus */
      if ( ETHTRCV_30_AR7000_SETPROP_SUCCESS == EthTrcv_30_Ar7000_SetPropertyStatus )
      {
        retVal = ETHTRCV_30_AR7000_RT_OK;
      }
      else
      {
        /* ETHTRCV_30_AR7000_RT_NOT_OK */
      }

      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
    }

    /* #50 No SetProperty() pending
     *       Send set property MME request
     *       Activate the timeout counter
     *       Inform calling application that QCA confirmation is pending
     */
    else
    {
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

      if ( E_OK == EthTrcv_30_Ar7000_MME_SetProperty(TrcvIdx, SetPropParams) )
      {
        /* successful */
        EthTrcv_30_Ar7000_IsSettingProperty = ETHTRCV_30_AR7000_WAIT_ON_CONF;
        EthTrcv_30_Ar7000_SetPropertyCnfAvailable = ETHTRCV_30_AR7000_STATE_NOT_READY;
        retVal = ETHTRCV_30_AR7000_RT_PENDING;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_SET_PROPERTY, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_SetProperty() */
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */

#if (ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API == STD_ON)
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetPibData
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetPibData(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) Pib)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
#if (   (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) \
     || ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)           && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)) )
  P2VAR(EthTrcv_30_Ar7000_NVMHeaderType, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) moduleHdrOffset;
  P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT) pibModuleOffset;
  uint32 pibChecksum;
  Std_ReturnType resVal; /* Result value of called functions */
#endif /* (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) ||
          (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)          */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* Return value of this function */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (EthTrcv_30_Ar7000_State == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (TrcvIdx >= ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_TRCV_IDX;
  }
  /* Pib == NULL_PTR is allowed */
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Determine the PIB update base data */
    if ( NULL_PTR == Pib )
    {
      /* Restore default */
      EthTrcv_30_Ar7000_PIBData = PIBData;
    }
    else
    {
      EthTrcv_30_Ar7000_PIBData = Pib;
    }

#if (   (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) \
     || ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)) )
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
    EthTrcv_30_Ar7000_PibRamCpyValid = FALSE;

    /* #30 Copy PIB to RAM */
    /* PRQA S 0314 5 */ /* MD_MSR_VStdLib */
    IpBase_Copy(
      (P2VAR(void, AUTOMATIC, IPBASE_APPL_DATA))&EthTrcv_30_Ar7000_PibRamCpy.U8[0],
      (P2CONST(void, AUTOMATIC, IPBASE_APPL_DATA))EthTrcv_30_Ar7000_PIBData,
      (uint32)ETHTRCV_30_AR7000_PIB_SIZE
    );

    resVal = EthTrcv_30_Ar7000_VGetPibModuleOffset(&EthTrcv_30_Ar7000_PibRamCpy.U8[0], &pibModuleOffset, &moduleHdrOffset);

    /* #40 Update the PIB RAM copy */
    if ( E_OK == resVal )
    {
# if (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB)
      /* Set MAC address */
      pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 0u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[0u];
      pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 1u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[1u];
      pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 2u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[2u];
      pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 3u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[3u];
      pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 4u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[4u];
      pibModuleOffset[ETHTRCV_30_AR7000_MAC_PIB_OFFSET + 5u] = EthTrcv_30_Ar7000_VCfgGetPhysAddr()[5u];
# endif /* ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB */

# if (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)
      /* Write DAK */
      /* PRQA S 0314 5 */ /* MD_MSR_VStdLib */
      IpBase_Copy(
        (P2VAR(void, AUTOMATIC, IPBASE_APPL_DATA))&pibModuleOffset[ETHTRCV_30_AR7000_DAK_PIB_OFFSET],
        (P2VAR(void, AUTOMATIC, IPBASE_APPL_DATA))EthTrcv_30_Ar7000_VCfgGetDak(),
        ETHTRCV_30_AR7000_DAK_SIZE_BYTE
      );
# endif /* ETHTRCV_30_AR7000_ENABLE_WRITE_DAK */

      /* Checksum module */
      moduleHdrOffset->ImageChecksum = 0x00000000u;
      pibChecksum = EthTrcv_30_Ar7000_VCalcChecksum(TrcvIdx, pibModuleOffset, ETHTRCV_30_AR7000_LIENTOH32(moduleHdrOffset->ImageLength));
      moduleHdrOffset->ImageChecksum = pibChecksum;

        /* Checksum header */
      moduleHdrOffset->HeaderChecksum = 0x00000000u;
      pibChecksum = EthTrcv_30_Ar7000_VCalcChecksum(TrcvIdx, (P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_VAR_NOINIT))moduleHdrOffset, sizeof(*moduleHdrOffset));
      moduleHdrOffset->HeaderChecksum = pibChecksum;

      /* #50 Set PIB RAM copy to valid state for future use */
      EthTrcv_30_Ar7000_PibRamCpyValid = TRUE;

      /* Set return value */
      retVal = E_OK;
    }
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
#else
    EthTrcv_30_Ar7000_PibRamCpyValid = FALSE;
    retVal = E_OK;
#endif /* (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) ||
          (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_SET_PIB_DATA, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Ar7000_SetPibData() */                                                                                  /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD ) && ( STD_OFF == ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD)
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_TriggerDwld
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_TriggerDwld(
    uint8 TrcvIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Std_ReturnType resValWaEA;
  EthTrcv_30_Ar7000_ReturnType retVal; /* Return value of this function */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
  /* #10 Get lock for module operation */
  EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpLockCnt++;

  /* #20 Verify valid lock request */
  if (1u == EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpLockCnt)
  {
    /* #30 Verify that a firmware has been transfered previously or MME_ModuleOperation() was called previously */
    if (   (ETHTRCV_30_AR7000_MODOP_STATE_USED == EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState)
        || (ETHTRCV_30_AR7000_DOWNLSTATUS_FW >= EthTrcv_30_Ar7000_DownlStatus))
    {
      /* #40 Verify that TriggerDwld() wasn't called previously */
      if (TRUE == EthTrcv_30_Ar7000_MME_WaEA_Params.NeedToSend)
      {
        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

        /* #50 Trigger firmware download process. */
        resValWaEA = EthTrcv_30_Ar7000_MME_WriteAndExecuteApplet(
          TrcvIdx,
          &EthTrcv_30_Ar7000_MME_WaEA_Params);

        if ( E_NOT_OK == resValWaEA )
        {
          retVal = ETHTRCV_30_AR7000_RT_NOT_OK;
        }
        else
        {
          retVal = ETHTRCV_30_AR7000_RT_PENDING;
        }
        ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

        EthTrcv_30_Ar7000_MME_WaEA_Params.NeedToSend = FALSE;
      }
      else
      {
        retVal = ETHTRCV_30_AR7000_RT_PENDING;
      }
    }
    else
    {
      retVal = ETHTRCV_30_AR7000_RT_OK;
    }
  }
  else
  {
    retVal = ETHTRCV_30_AR7000_RT_PENDING;
  }
  EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpLockCnt--;

  ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

  return retVal;
} /* EthTrcv_30_Ar7000_TriggerDwld() */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD, ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */

#if ( ETHTRCV_30_AR7000_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetVersionInfo
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) VersionInfoPtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (VersionInfoPtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    VersionInfoPtr->vendorID = ETHTRCV_30_AR7000_VENDOR_ID;
    VersionInfoPtr->moduleID = ETHTRCV_30_AR7000_MODULE_ID;
    VersionInfoPtr->sw_major_version = ETHTRCV_30_AR7000_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = ETHTRCV_30_AR7000_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = ETHTRCV_30_AR7000_SW_PATCH_VERSION;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_GET_VERSION_INFO, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
} /* EthTrcv_30_Ar7000_GetVersionInfo() */
#endif /* ETHTRCV_30_AR7000_VERSION_INFO_API == STD_ON */

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MainFunction
 **********************************************************************************************************************/
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
 */
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MainFunction(void)                                                 /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
#if (ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON)
#if (defined(ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD == STD_ON))
  EthTrcv_30_Ar7000_FailedApiCallType tmpRetryCallFct;
#endif /* ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Verify that transceiver is enabled */
  if ( ETHTRCV_MODE_ACTIVE == EthTrcv_30_Ar7000_ModeState )
  {
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
    /* Check if the firmware download is pending */
    if (EthTrcv_30_Ar7000_FwStartedCbkCalled == FALSE)
    {
      /* Handle the firmware download timeout */
      if (0u < EthTrcv_30_Ar7000_FwDownloadAndStartCnt)
      {
        /* Check if the timer has been elapsed */
        if (1u == EthTrcv_30_Ar7000_FwDownloadAndStartCnt)
        {
          /* Stop timer and continue */
          EthTrcv_30_Ar7000_FwDownloadAndStartCnt = 0u;
          /* Stop critical section befor calling other modules */
          ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

          /* Firmware download timed out */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
         (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_MAINFUNCTION, ETHTRCV_30_AR7000_E_FW_DOWNLOAD_TIMEOUT);
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_REPORT */

          /* Reset the QCA to restart the firmware download */
          EthTrcv_30_Ar7000_HandleFirmwareRestart(TRUE);
        }
        else
        {
          EthTrcv_30_Ar7000_FwDownloadAndStartCnt--;
          /* Check if the firmware download is finished */
          if (EthTrcv_30_Ar7000_DownlStatus == ETHTRCV_30_AR7000_DOWNLSTATUS_DONE)
          {
            /* Do not call external APIs with an active critical section */
            ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
            /* Send a link state request to check if the firmware has already been started */
            EthTrcv_30_Ar7000_HandleGetLinkState();
          }
          else
          {
            ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
          }
        }
      }
    }
    else if (   (EthTrcv_30_Ar7000_FwStartedCbkCalled == TRUE)
             && (EthTrcv_30_Ar7000_FwReadyForSlacCbkCalled == FALSE) )
    {
      if (0u < EthTrcv_30_Ar7000_FwReadyForSlacCnt)
      {
        /* Firmware download is active */
        if (1u == EthTrcv_30_Ar7000_FwReadyForSlacCnt)
        {
          /* Stop timer and continue */
          EthTrcv_30_Ar7000_FwReadyForSlacCnt = 0u;
          /* Stop critical section befor calling other modules */

          /* Firmware download timed out */
#if (ETHTRCV_30_AR7000_ENABLE_DEVICE_READY_FOR_SLAC_COM_EVENT == STD_ON) /* FW 1.2.1 and later with enabled HST ACTION events */
          ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
          /* Error QCA did time out */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
          (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_MAINFUNCTION, ETHTRCV_30_AR7000_E_FW_READY_FOR_PLC_COM_TIMEOUT);
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_REPORT */

          /* Inform user about the timeout */
          EthTrcv_30_Ar7000_FwReadyForSlacLastResult = FALSE;
#if defined ( ETHTRCV_30_AR7000_APPL_CBK_FW_READY_FOR_SLAC )
          ETHTRCV_30_AR7000_APPL_CBK_FW_READY_FOR_SLAC(EthTrcv_30_Ar7000_FwReadyForSlacLastResult);
#endif /* ETHTRCV_30_AR7000_APPL_CBK_FW_READY_FOR_SLAC */

          /* Reset the QCA to restart the firmware download */
          EthTrcv_30_Ar7000_HandleFirmwareRestart(FALSE);
#else /* FW 1.1.0.x and 1.1.3.x or 1.2.x with disabled HST action events */
          /* Success QCA does not forward the "ready for SLAC" HST action event, so just wait some time */
          EthTrcv_30_Ar7000_FwReadyForSlacCbkCalled = TRUE;
          EthTrcv_30_Ar7000_FwReadyForSlacLastResult = TRUE;
          ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
#if defined ( ETHTRCV_30_AR7000_APPL_CBK_FW_READY_FOR_SLAC )
          ETHTRCV_30_AR7000_APPL_CBK_FW_READY_FOR_SLAC(EthTrcv_30_Ar7000_FwReadyForSlacLastResult);
#endif /* ETHTRCV_30_AR7000_APPL_CBK_FW_READY_FOR_SLAC */
#endif /* ETHTRCV_30_AR7000_ENABLE_DEVICE_READY_FOR_SLAC_COM_EVENT == STD_ON */
        }
        else
        {
          EthTrcv_30_Ar7000_FwReadyForSlacCnt--;
          ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
        }
      }
      else
      {
        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
      }
    }
    else if (EthTrcv_30_Ar7000_LinkStateLockCnt == 0u)
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */
    {
      /* #20 Reset the QCA hardware if it does not answer the MME_GetLinkStatus() requested with a valid response
       *      Increase heart beat counter, reseted by a link response of the QCA7000
       */
      EthTrcv_30_Ar7000_HeartBeatCnt++;
      if ( EthTrcv_30_Ar7000_HeartBeatCnt > ETHTRCV_30_AR7000_HEARTBEAT_TIMEOUT )
      {
        EthTrcv_30_Ar7000_HeartBeatCnt = 0u;

        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

        EthTrcv_30_Ar7000_HandleFirmwareRestart(TRUE);
      }
      else
      {
        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

        /* #30 Cyclically request Link-State. Only required in case the
         *      EthTrcv_30_Ar7000_HeartBeatCnt is not expired. If it is expired, the QCA7000 is not responding anyway.
         */
        EthTrcv_30_Ar7000_HandleGetLinkState();
      }
    }
#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
    else
    {
      ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
    }
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON */

    /* #40 Start: Handle timeout counters for different services, perform checks and increment/decremnt operations in critical sections */
    ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();

#if ( ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON )
    if ( ETHTRCV_30_AR7000_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsChangingSCState )
    {
      EthTrcv_30_Ar7000_SCConfCycCnt++;
    }
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON )
    if ( ETHTRCV_30_AR7000_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsReadingSwVersion )
    {
      EthTrcv_30_Ar7000_GetSwVersionCycCnt++;
    }
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API == STD_ON )
    if ( ETHTRCV_30_AR7000_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsSettingProperty )
    {
      EthTrcv_30_Ar7000_SetPropertyCycCnt++;
    }
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
    if (EthTrcv_30_Ar7000_LinkStateLockCnt > 0u)
    {
      EthTrcv_30_Ar7000_LinkStateLockCnt--;
    }

    if ( 0u < EthTrcv_30_Ar7000_WriteAppletLockCnt )
    {
      EthTrcv_30_Ar7000_WriteAppletLockCnt--;
      if ( 0u == EthTrcv_30_Ar7000_WriteAppletLockCnt )
      {

        /* Error applet timed out, just release the applet. Firmware download retry is done by timer EthTrcv_30_Ar7000_HeartBeatCnt */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
        /* Do not call other modules within critical sections */
        ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
        (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_MAINFUNCTION, ETHTRCV_30_AR7000_E_APPLET_TIMEOUT);
        ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_REPORT */
        EthTrcv_30_Ar7000_AppletNrLocked = ETHTRCV_30_AR7000_NO_APPLET_LOCKED;
      }
    }
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK )
    if ( ETHTRCV_30_AR7000_MODOP_STATE_USED == EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState )
    {
      if (EthTrcv_30_Ar7000_ModOpCycCnt > 0u)
      {
        EthTrcv_30_Ar7000_ModOpCycCnt++;
        if ( (ETHTRCV_30_AR7000_CONFTIMEOUT + 1u) < EthTrcv_30_Ar7000_ModOpCycCnt)
        {
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
          /* Do not call other modules within critical sections */
          ETHTRCV_30_AR7000_END_CRITICAL_SECTION();
          (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_MAINFUNCTION, ETHTRCV_30_AR7000_E_MODOP_TIMEOUT);
          ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION();
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_REPORT */
          /* Timeout - set to not used */
          EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState = ETHTRCV_30_AR7000_MODOP_STATE_NOT_USED;
        }
      }

#if ( ETHTRCV_30_AR7000_ENABLE_READ_NMK == STD_ON )
      if ( ETHTRCV_30_AR7000_WAIT_ON_CONF == EthTrcv_30_Ar7000_IsReadingNmk )
      {
        EthTrcv_30_Ar7000_ReadNmkCycCnt++;
        /* Reset locked state regardless of user polling EthTrcv_30_Ar7000_ReadNmk() */
        if ( ETHTRCV_30_AR7000_CONFTIMEOUT < EthTrcv_30_Ar7000_ModOpCycCnt)
        {
          EthTrcv_30_Ar7000_ModOpParams.BaseParams.ModOpState = ETHTRCV_30_AR7000_MODOP_STATE_NOT_USED;
        }
      }
#endif /* ETHTRCV_30_AR7000_ENABLE_READ_NMK */
    }
#endif /* ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ||
          ETHTRCV_30_AR7000_ENABLE_MODOP_API  ||
          ETHTRCV_30_AR7000_ENABLE_READ_NMK */

    /* #50 End: Handle timeout counters */
    ETHTRCV_30_AR7000_END_CRITICAL_SECTION();

    /* #60 Handle WriteAndExecutionApplet() call failures during firmware download. Try to execute
     *      WriteAndExecutionApplet() command again till it was successful or the limit
     *      ETHTRCV_30_AR7000_MAX_API_CALL_RET_CNT is reached
     */
#if (   (ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON) \
     && (defined(ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD) && (ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD == STD_ON)) )
    if ( (EthTrcv_30_Ar7000_FailedApiCallType)NULL_PTR != EthTrcv_30_Ar7000_FailedApiCall ) /*lint !e611 */
    {
      tmpRetryCallFct = (EthTrcv_30_Ar7000_FailedApiCallType)EthTrcv_30_Ar7000_FailedApiCall;
      EthTrcv_30_Ar7000_FailedApiCall = (EthTrcv_30_Ar7000_FailedApiCallType)NULL_PTR; /*lint !e611 */
      tmpRetryCallFct(0, EthTrcv_30_Ar7000_LastFrHeader);
      if ( (EthTrcv_30_Ar7000_FailedApiCallType)NULL_PTR != EthTrcv_30_Ar7000_FailedApiCall ) /*lint !e611 */
      {
        EthTrcv_30_Ar7000_ApiCallRetCnt++;
        if ( ETHTRCV_30_AR7000_MAX_API_CALL_RET_CNT <= EthTrcv_30_Ar7000_ApiCallRetCnt )
        {
#if ( ETHTRCV_30_AR7000_DEM_ERROR_DETECT == STD_ON )
          ETHTRCV_30_AR7000_DEM_REPORT_ERROR_STATUS(ETHTRCV_30_AR7000_E_ACCESS);
#endif /* ETHTRCV_30_AR7000_DEM_ERROR_DETECT */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
          (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_MAINFUNCTION, ETHTRCV_30_AR7000_E_TRCV_CONNECTION_LOST_OR_OVERLOADED);
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_REPORT */
        }
      }
      else
      {
        EthTrcv_30_Ar7000_ApiCallRetCnt = 0u;
      }
    }
#endif /* (ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON) && (ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD == STD_ON) */
  }

  /* #70 Some Request<->Confirm Pairs need some more well defined flow sequences */
#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
  if (ETHTRCV_30_AR7000_NO_HST_ACTION_REQUIRED != EthTrcv_30_Ar7000_HstAction[EthTrcv_30_Ar7000_HstActionIdx])
  {
    EthTrcv_30_Ar7000_HstActionRequiredSecondPhase(0u);
  }
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */
} /* EthTrcv_30_Ar7000_MainFunction() */

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_RxIndication
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_RxIndication(                                                  /* PRQA S 6030, 6050, 6060 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR */
        uint8                                                          EthIfCtrlIdx,
        Eth_FrameType                                                  FrameType,
        boolean                                                        IsBroadcast,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) PhysAddrPtr,                                     /* PRQA S 3673 */ /* MD_EthTrcv_30_Ar7000_AutosarParameter */
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) DataU8Ptr,                                       /* PRQA S 3673 */ /* MD_EthTrcv_30_Ar7000_AutosarParameter */
        uint16                                                         LenByte )
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint16 mmType;
  uint8  trcvIdx;
  EthTrcv_30_Ar7000_DetErrorType errorId = ETHTRCV_30_AR7000_E_NO_ERROR;

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (EthTrcv_30_Ar7000_State != ETHTRCV_STATE_ACTIVE)
  {
    errorId = ETHTRCV_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (EthIfCtrlIdx != EthTrcv_30_Ar7000_VCfgGetEthIfCtrlIdx())
  {
    errorId = ETHTRCV_30_AR7000_E_INV_CONFIG;
  }
  else if (DataU8Ptr == NULL_PTR)
  {
    errorId = ETHTRCV_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* Parameters are defined by AUTOSAR, but are not required in this API. */
    ETHTRCV_30_AR7000_DUMMY_STATEMENT(FrameType);                                                                       /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
    ETHTRCV_30_AR7000_DUMMY_STATEMENT(IsBroadcast);                                                                     /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
    ETHTRCV_30_AR7000_DUMMY_STATEMENT(PhysAddrPtr);                                                                     /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

    trcvIdx = 0u;
    /* #20 Parse Vendor specific Management Message Type from received packets and call the specific handle routines. */
    mmType  =          ((uint16)DataU8Ptr[ETHTRCV_30_AR7000_MME_MMTYPE]);
    mmType |= (uint16)(((uint16)DataU8Ptr[ETHTRCV_30_AR7000_MME_MMTYPE + 1u]) << 8u);


    switch(mmType)
    {
    case ETHTRCV_30_AR7000_MME_VS_PL_LNK_STATUS | ETHTRCV_30_AR7000_MME_CNF:                    /* Link Status */
      EthTrcv_30_Ar7000_SetLinkStatus(
        trcvIdx,
        DataU8Ptr);
      break;

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
    case ETHTRCV_30_AR7000_MME_VS_WRITE_AND_EXECUTE_APPLET | ETHTRCV_30_AR7000_MME_CNF:         /* Write and Execute Applet */
      EthTrcv_30_Ar7000_WriteAndExecuteApplet(
        trcvIdx,
        DataU8Ptr);
      break;

    case ETHTRCV_30_AR7000_MME_VS_HST_ACTION | ETHTRCV_30_AR7000_MME_IND:                       /* Host Action Required */
      EthTrcv_30_Ar7000_HstActionRequired(
        trcvIdx,
        DataU8Ptr);
      break;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP) || \
      (STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK)   || \
      (STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API) )
    case ETHTRCV_30_AR7000_MME_VS_MODULE_OPERATION | ETHTRCV_30_AR7000_MME_CNF:               /* Module Operation */
      EthTrcv_30_Ar7000_ModuleOperation(
        trcvIdx,
        DataU8Ptr);
      break;
#endif /* (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP) ||
          (STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK)   ||
          (STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API) ) */
#if ( ETHTRCV_30_AR7000_ENABLE_SET_NMK == STD_ON )
    case ETHTRCV_30_AR7000_MME_VS_SET_KEY | ETHTRCV_30_AR7000_MME_CNF:                          /* Set NMK */
      EthTrcv_30_Ar7000_SetKeyCnfStatus(
        trcvIdx,
        (P2CONST(uint8, AUTOMATIC, ETHTRCV_30_AR7000_CONST))DataU8Ptr);
      break;
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_NMK */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API )
    case ETHTRCV_30_AR7000_MME_MS_PB_ENC | ETHTRCV_30_AR7000_MME_CNF:                           /* Pushbutton Encryption */
      EthTrcv_30_Ar7000_SetPBEncryptionStatus(
        trcvIdx,
        DataU8Ptr);
      break;
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON )
    case ETHTRCV_30_AR7000_MME_VS_SW_VER | ETHTRCV_30_AR7000_MME_CNF:                          /* Software version */
      EthTrcv_30_Ar7000_SetSoftwareVersion(
        trcvIdx,
        DataU8Ptr);
      break;
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )                                  /* Reset device */
    case ETHTRCV_30_AR7000_MME_VS_RS_DEV | ETHTRCV_30_AR7000_MME_CNF:
      EthTrcv_30_Ar7000_FwDwldStartCbkCalled = FALSE;
      EthTrcv_30_Ar7000_FwStartedCbkCalled = FALSE;
      EthTrcv_30_Ar7000_FwReadyForSlacCbkCalled = FALSE;
      EthTrcv_30_Ar7000_FwDownloadAndStartCnt = ETHTRCV_30_AR7000_FIRMWARE_DOWNLOAD_AND_START_CYCLES;
      EthTrcv_30_Ar7000_FwReadyForSlacCnt = ETHTRCV_30_AR7000_FIRMWARE_READY_FOR_SLAC_TIMEOUT_CYCLES;

      EthTrcv_30_Ar7000_LinkStateLockCnt = ETHTRCV_30_AR7000_LINKSTATE_LOCK_CYCLES;
      EthTrcv_30_Ar7000_LinkState        = ETHTRCV_LINK_STATE_DOWN;
      /* Reset firmware download information to prepare for the next required firmware download */
      EthTrcv_30_Ar7000_WriteAppletLockCnt = 0u;
      EthTrcv_30_Ar7000_AppletNrLocked = ETHTRCV_30_AR7000_NO_APPLET_LOCKED;
      break;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API == STD_ON )                                   /* Set Property */
    case ETHTRCV_30_AR7000_MME_VS_SET_PROPERTY | ETHTRCV_30_AR7000_MME_CNF:
      EthTrcv_30_Ar7000_IsSettingProperty       = ETHTRCV_30_AR7000_NO_WAIT_ON_CONF;
      EthTrcv_30_Ar7000_SetPropertyCnfAvailable = ETHTRCV_30_AR7000_STATE_READY;
      EthTrcv_30_Ar7000_SetPropertyCycCnt       = 0u;
      EthTrcv_30_Ar7000_SetPropertyStatus = DataU8Ptr[ETHTRCV_30_AR7000_MME_VS_MSTATUS];
      break;
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */

    default:
      /* Nothing to do, MME Frame is not handled by this module, it may be handled by the application via the callout hook. */
      break;
    }

    /* #30 Call user defined application handler if ETHTRCV_30_AR7000_ENABLE_SM_HOOK_ROUTINE is enabled. */
#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_SM_HOOK_ROUTINE )
    Appl_TrcvHookRoutine(DataU8Ptr, LenByte);
#else 
    ETHTRCV_30_AR7000_DUMMY_STATEMENT(LenByte);                                                                       /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* ETHTRCV_30_AR7000_ENABLE_SM_HOOK_ROUTINE */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_AR7000_MODULE_ID, ETHTRCV_30_AR7000_INSTANCE_ID_DET, ETHTRCV_30_AR7000_API_ID_RXINDICATION, errorId);
  }
#else
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(EthIfCtrlIdx);                                                                      /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
} /* EthTrcv_30_Ar7000_MME_RxIndication() */

/**********************************************************************************************************************
 * EthTrcv_30_Ar7000_SetPhyTxMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetPhyTxMode(
  uint8                 TrcvIdx,
  EthTrcv_PhyTxModeType Mode)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Use dummy statements on in-parameters */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(Mode);                                                                              /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  /* #20 Return NOT_OK */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * EthTrcv_30_Ar7000_GetCableDiagnosticsResult
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetCableDiagnosticsResult (
        uint8                                                               TrcvIdx,
  P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, ETHTRCV_30_AR7000_APPL_VAR) ResultPtr)                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Use dummy statements on in-parameters */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(ResultPtr);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  /* #20 Return NOT_OK */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * EthTrcv_30_Ar7000_SetPhyTestMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetPhyTestMode(
  uint8                    TrcvIdx,
  EthTrcv_PhyTestModeType  Mode)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Use dummy statements on in-parameters */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(Mode);                                                                              /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  /* #20 Return NOT_OK */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * EthTrcv_30_Ar7000_GetPhySignalQuality
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetPhySignalQuality(
        uint8                                         TrcvIdx,
  P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_APPL_VAR) ResultPtr)                                                        /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Use dummy statements on in-parameters */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(TrcvIdx);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(ResultPtr);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  /* #20 Return NOT_OK */
  return E_NOT_OK;
}

#define ETHTRCV_30_AR7000_STOP_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/* module specific MISRA deviations:
 MD_EthTrcv_30_Ar7000_BufferAccessUnion:
      Reason:     The union simplifies the access to the different bit wide data types e.g. Ethernet buffers. Without
                  an union the buffer would need to be cast between types. This would always require a cast and a
                  justification of message 3305 and 0310. The union enables an easy byte-by-byte access that is
                  necessary to process the buffers.
      Risk:       Some coding standards advocate that unions should be avoided.
      Prevention: There is no known compiler that does not support unions.
 MD_EthTrcv_30_Ar7000_AlignedPibData:
      Reason:     The PIB ram copy must be 32 bit alligned, to calculate the checksums inside. Therefore its data type
                  is a union including a 32 and a 8 bit data type.
      Risk:       Some coding standards advocate that unions should be avoided.
      Prevention: There is no known compiler that does not support unions.
 MD_EthTrcv_30_Ar7000_CastConstAddressToVar:
      Reason:     Required by AUTOSAR API of the Ethernet Interface. The MAC address is not defined as const.
      Risk:       There is no risk since the EthIf component does not change the MAC.
      Prevention: Covered by code review.
 MD_EthTrcv_30_Ar7000_ModOpParams:
      Reason:     Casting is used to support C-style inheritance. A pointer to a EthTrcv_30_Ar7000_ModOp_Rd_Params
                  object is always a pointer to a EthTrcv_30_Ar7000_ModOp_Params object, too. The
                  EthTrcv_30_Ar7000_ModOp_Params object is the first element in the
                  EthTrcv_30_Ar7000_ModOp_Rd_Params.
      Risk:       There is no risk since the array is a continuous data buffer.
      Prevention: Covered by code review. The size of Memory Ctrl, PIB and FW is checked by preprocessor directive.
 MD_EthTrcv_30_Ar7000_PibFileHeaderAccess:
      Reason:     Cast PIB data block to NvMHeaderType structure to simplify the access to the module fields.
                  The PIB data block is very extensive and a offset-based access is hard to interpret.
      Risk:       There is no known risk.
      Prevention: Covered by code review.
 MD_EthTrcv_30_Ar7000_MmtypeTraceVar
      Reason:     Debugging variable is global to simplify the access via debugger.
      Risk:       There is no risk. Debugging variables are switched off in productive systems.
      Prevention: Covered by code review.
 MD_EthTrcv_30_Ar7000_LastHeaderVar
      Reason:     This variable is used to store the header of a previous message, there for it cannot be a normal
                  local variable. It must not be a local static variable, because local static variables cannot be
                  mapped using the ASR memory mapping. Therefore this variable must be a global staic variable,
                  because these ones can be mapped.
      Risk:       There is no risk.
      Prevention: Covered by code review.
 MD_EthTrcv_30_Ar7000_SwapValueForCompare
      Reason:     The called API does only perform a swap operation for the comparison, therefore its execution does
                  not have any effects on the following code.
      Risk:       There is no risk.
      Prevention: Covered by code review.
 MD_EthTrcv_30_Ar7000_AutosarParameter
      Reason:     Parameter definition of this API is done by AUTOSAR, directly or indirectly by specifying it as
                  an API or callout of another module. Therefore the parameter cannot be changed to const.
      Risk:       There is no risk.
      Prevention: Covered by code review.
 MD_EthTrcv_30_Ar7000_AssignedToVarLater:
      Reason:     This pointer cannot be const, because it is assigned to a variable pointer later on. If it would
                  be const, the tool would complain out a const to var cast.
      Risk:       There is no risk
      Prevention: No prevention necessary.
 MD_EthTrcv_30_Ar7000_VStdLibBuffer:
      Reason:     The VStdLib functions are using void pointers to be multi functional. Therefore source and
                  destination buffers are cast to void*.
      Risk:       There is no risk
      Prevention: Covered by code review.
 MD_EthTrcv_30_Ar7000_OtherModules:
      Reason:     In some constellation it may happen that the nesting of #if statements exceeds the given limit.
                  This module cannot ensure that this does not happen within other modules include files, which
                  may include this module again.
      Risk:       There is no risk. If nessting level is to high the compiler complains.
      Prevention: No prevention necessary.
 MD_EthTrcv_30_Ar7000_OtherTools:
      Reason:     In case this assignment is not done there will be warnings in other tools and compilers
                  (e.g. PClint, DiabData, Tasking). Since compilers cannot be justified, it is justified for
                  MISRA only.
      Risk:       No risk, this is an useless assignment, in worst case it may take some additional run time.
      Prevention: Not required.
*/

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ar7000.c
 *********************************************************************************************************************/

