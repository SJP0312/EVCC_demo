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
/**        \file  EthTrcv_30_Ar7000_Priv.h
 *        \brief  Ethernet transceiver driver QCA 7005 private header file
 *
 *      \details  Vector static code private header file for the Ethernet transceiver driver QCA 7005 module. This 
 *                header file contains module internal declarations.
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

#if !defined (ETHTRCV_30_AR7000_PRIV_H)
# define ETHTRCV_30_AR7000_PRIV_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#if (ETHTRCV_30_AR7000_DEM_ERROR_DETECT == STD_ON)
#include "Dem.h"
#endif /* ETHTRCV_30_AR7000_DEM_ERROR_DETECT */
#if (   (ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON) \
     || (   defined(ETHTRCV_30_AR7000_ENABLE_DET_ON_DISABLED_HST_ACT_EVENTS) \
         && (ETHTRCV_30_AR7000_ENABLE_DET_ON_DISABLED_HST_ACT_EVENTS == STD_ON)) )
#include "Det.h"
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_DETECT || ETHTRCV_30_AR7000_ENABLE_DET_ON_DISABLED_HST_ACT_EVENTS */
#include "EthTrcv_30_Ar7000_Trcv.h"
#include "EthTrcv_30_Ar7000_PrivateCfg.h"
#include "EthTrcv_30_Ar7000_Types.h"
#include "SchM_EthTrcv_30_Ar7000.h"

/**********************************************************************************************************************
 *  GLOBAL CONSISTENCY CHECKS
 *********************************************************************************************************************/
#if (ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL != 1)
#error "AR7000 transceiver driver does only support 1 transceiver instance"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#if defined ETHTRCV_MMTYPE_TRACE
/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MMTypeTxTrace
 **********************************************************************************************************************/
/*!
 * \brief       Test function to trace the transmitted MME frames.
 * \details     -
 * \param[in]   MMType          MM type that shall be added to the trace
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      ETHTRCV_MMTYPE_TRACE
 */
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MMTypeTxTrace(uint16 MMType);
#endif /* ETHTRCV_MMTYPE_TRACE */

/**********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_GetLinkStatus
 **********************************************************************************************************************/
/*!
 * \brief       Sends a VS_PL_LNK_STATUS.REQ to the QCA7005.
 * \details     Does send a VS_PL_LNK_STATUS.REQ to the local QCA7005 to retriev the current link state
 * \param[in]     TrcvIdx         Transceiver index
 * \return      E_OK       success
 * \return      E_NOT_OK   Transmission not successful
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      -
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_GetLinkStatus(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/
#define ETHTRCV_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#if ( ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON )
extern VAR(EthTrcv_StateType, ETHTRCV_30_AR7000_VAR_ZERO_INIT) EthTrcv_30_Ar7000_State;
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_DETECT == STD_ON */

#define ETHTRCV_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#if ( (STD_ON==ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP) )
extern VAR(uint8, ETHTRCV_30_AR7000_VAR_NOINIT) EthTrcv_30_Ar7000_WillResetAfterPibUpload;
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD && ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP */

#define ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

extern CONST(uint8, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_AtherosODA[6];

#define ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  GLOBAL DEFINES
 **********************************************************************************************************************/
/* only one transceiver is supported */
#define ETHTRCV_30_AR7000_MAX_CFGS_TOTAL             1U
/* value for pre-compile time config variant */
#define ETHTRCV_30_AR7000_CONFIG_VARIANT_PRECOMPILE  1U
/* value for the transmission priority */
#define ETHTRCV_30_AR7000_TX_PRIO                    0U

/**********************************************************************************************************************
 *  GLOBAL MACROS
 **********************************************************************************************************************/
#if !defined(ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION)
# define ETHTRCV_30_AR7000_BEGIN_CRITICAL_SECTION() SchM_Enter_EthTrcv_30_Ar7000_ETHTRCV_30_AR7000_EXCLUSIVE_AREA_0()
#endif
#if !defined(ETHTRCV_30_AR7000_END_CRITICAL_SECTION)
# define ETHTRCV_30_AR7000_END_CRITICAL_SECTION()   SchM_Exit_EthTrcv_30_Ar7000_ETHTRCV_30_AR7000_EXCLUSIVE_AREA_0()
#endif

/* Diagnostic Event Manager */
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define ETHTRCV_30_AR7000_DEM_REPORT_ERROR_STATUS(ErrId)   ((void) Dem_ReportErrorStatus((ErrId), DEM_EVENT_STATUS_FAILED))

/* Development Error Tracer */
#if !defined(ETHTRCV_30_AR7000_DEV_ERROR_REPORT)
#define ETHTRCV_30_AR7000_DEV_ERROR_REPORT  ETHTRCV_30_AR7000_DEV_ERROR_DETECT
#endif
/* PRQA S 3453 5 */ /* MD_MSR_FctLikeMacro */
#if ( ETHTRCV_30_AR7000_DEV_ERROR_REPORT == STD_ON )
#define ETHTRCV_30_AR7000_SET_ERROR_ID(errorId, value) (errorId) = (value)
#else
#define ETHTRCV_30_AR7000_SET_ERROR_ID(errorId, value) ETHTRCV_30_AR7000_DUMMY_STATEMENT(errorId)
#endif /* ETHTRCV_30_AR7000_DEV_ERROR_REPORT */

/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#define ETHTRCV_30_AR7000_HTOLIEN32(Data)  IPBASE_LE2HE32(Data)
#define ETHTRCV_30_AR7000_LIENTOH32(Data)  IPBASE_LE2HE32(Data)

/* PRQA S 3453 4 */ /* MD_MSR_FctLikeMacro */
#define ETHTRCV_30_AR7000_U8PTRDATA_TO_VAL32(U8DataPtr, Idx)  (uint32)(   (uint32)(U8DataPtr)[(Idx)]              \
                                                                       | ((uint32)(U8DataPtr)[(Idx) + 1u] <<  8u) \
                                                                       | ((uint32)(U8DataPtr)[(Idx) + 2u] << 16u) \
                                                                       | ((uint32)(U8DataPtr)[(Idx) + 3u] << 24u) )

/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#define ETHTRCV_30_AR7000_U8PTRDATA_TO_VAL16(U8DataPtr, Idx)  (uint16)(   (uint32)(U8DataPtr)[(Idx)]              \
                                                                       | ((uint32)(U8DataPtr)[(Idx) + 1u] <<  8u) )

/* Configuration access (depending on configuration variant)*/
#define EthTrcv_30_Ar7000_VCfgGetEthIfCtrlIdx()             ((uint8)ETHTRCV_30_AR7000_ETHIF_CTRL)
#define EthTrcv_30_Ar7000_VCfgGetEthCtrlIdx()               ((uint8)ETHTRCV_30_AR7000_HW_IDX)
#if (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_NVM)
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define EthTrcv_30_Ar7000_VCfgGetPhysAddrBlockId(TrcvIdx)  ((NvM_BlockIdType)ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_NVM_BLOCK_ID)
# define EthTrcv_30_Ar7000_VCfgGetPhysAddr()                (EthTrcv_30_Ar7000_PhysAddr)
#else
# if (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_CONST)
#  define EthTrcv_30_Ar7000_VCfgGetPhysAddrDefault()        (EthTrcv_30_Ar7000_PhysAddrRomDefault)
#  define EthTrcv_30_Ar7000_VCfgGetPhysAddr()               (EthTrcv_30_Ar7000_PhysAddr)
# else
#  if (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_CALLOUT)
#   define EthTrcv_30_Ar7000_VCfgGetPhysAddr()                (ETHTRCV_30_AR7000_APPL_CBK_GET_PHYS_ADDR())
#  endif /* ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_CALLOUT */
# endif /* ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_CONST */
#endif /* ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_NVM */


#if ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) && (ETHTRCV_30_AR7000_ENABLE_WRITE_DAK == STD_ON))
#define EthTrcv_30_Ar7000_VCfgGetDak()                      (EthTrcv_30_Ar7000_Dak)
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define EthTrcv_30_Ar7000_VCfgGetDakBlockId(TrcvIdx)        (EthTrcv_30_Ar7000_DakBlockIds[TrcvIdx])
#endif /* ETHTRCV_30_AR7000_ENABLE_WRITE_DAK */

#endif
  /* ETHTRCV_30_AR7000_PRIV_H */
/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ar7000_Priv.h
 *********************************************************************************************************************/

