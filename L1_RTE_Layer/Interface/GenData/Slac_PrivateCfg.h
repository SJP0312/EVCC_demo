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
 *            Module: Slac
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Slac_PrivateCfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined (SLAC_PRIVATE_CFG_H)
#define SLAC_PRIVATE_CFG_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "Slac_Types.h"

/* Generated include headers */
// #include "EVCC.h"
#include "_ApplScc_CbkStubs.h"
#include "Scc_Cbk.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* Forwarding call backs */
#define SLAC_APPL_CBK_FIRMWARE_DOWNLOAD_BEGIN     Scc_Cbk_SLAC_FirmwareDownloadStart
#define SLAC_APPL_CBK_FIRMWARE_DOWNLOAD_END       Scc_Cbk_SLAC_FirmwareDownloadComplete
#define SLAC_APPL_CBK_READY_FOR_SLAC              Scc_Cbk_SLAC_SetReadyForSlac

#define SLAC_APPL_CBK_GET_RANDOM_ARRAY            Scc_Cbk_SLAC_GetRandomizedDataBuffer
#define SLAC_APPL_CBK_ASSOC_STATUS                Scc_Cbk_SLAC_AssociationStatus
#define SLAC_APPL_CBK_DLINK_READY                 Scc_Cbk_SLAC_DLinkReady
#define SLAC_APPL_CBK_GET_EXECUTE_VALIDATION_INFO Scc_Cbk_SLAC_GetExecuteValidationInfo
#define SLAC_APPL_CBK_GET_VALIDATE_TOGGLE_NUM     Scc_Cbk_SLAC_GetValidateToggles
#define SLAC_APPL_CBK_SET_BCB_TOGGLE_STATE        Scc_Cbk_SLAC_SetBcbToggleState
#define SLAC_APPL_CBK_GET_PLC_CHIP_MAC_ADDRESS    Appl_GetPlcChipMacAddress

/* Lower layer APIs */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif  /* SLAC_PRIVATE_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: Slac_PrivateCfg.h
 **********************************************************************************************************************/

