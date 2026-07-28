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
 *            Module: EthTrcv_Ar7000
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthTrcv_30_Ar7000_PrivateCfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/



#if !defined(ETHTRCV_30_AR7000_PRIVATE_CFG_H)
#define ETHTRCV_30_AR7000_PRIVATE_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Slac_Cbk.h"
#include "Appl_IntegrationStubs.h"



/**********************************************************************************************************************
 *  ETHERNET CONTROLLER API ABSTRACTION
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_ETH_WRITESPI   Eth_30_Ar7000_WriteSpi
#define ETHTRCV_30_AR7000_ETH_READSPI    Eth_30_Ar7000_ReadSpi
#define ETHTRCV_30_AR7000_ETH_PROVIDE_TX_BUFFER    Eth_30_Ar7000_ProvideTxBuffer
#define ETHTRCV_30_AR7000_ETH_TRANSMIT    Eth_30_Ar7000_Transmit


/**********************************************************************************************************************
 *  CALLBACK FUNCTIONS
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_APPL_CBK_FW_DOWNLOAD_START              Slac_Cbk_FirmwareDownloadBegin
#define ETHTRCV_30_AR7000_APPL_CBK_FW_START                       Slac_Cbk_FirmwareDownloadEnd

#define ETHTRCV_30_AR7000_APPL_CBK_GET_PHYS_ADDR                  Appl_Callout_GetMacAddress   


/**********************************************************************************************************************
 *  SLAC
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SLAC - CALLBACK FUNCTIONS
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_APPL_CBK_FW_READY_FOR_SLAC              Slac_Cbk_ReadyForSlac



#endif /* ETHTRCV_30_AR7000_PRIVATE_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ar7000_PrivateCfg.h
 *********************************************************************************************************************/
 
