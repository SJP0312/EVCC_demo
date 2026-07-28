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
 *            Module: Scc
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Scc_SDP_InterfaceCfg.c
 *   Generation Time: 2025-08-26 17:17:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_SDP_INTERFACECFG_SOURCE 

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_SDP_InterfaceCfg.h"
#include "Scc_StateM_Vector.h"
/* The following includes are based on configuration parameter /MICROSAR/Scc/SccParameterMapping/SccCbkIncludeHeader */
#include "_ApplScc_CbkStubs.h"

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* PRQA S 3673 EOF */ /* MD_Scc_VariantDependent */


#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * RX INTERFACE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SDP_InterfaceCfg_Get_SDPSecurityRx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SDP_InterfaceCfg_Get_SDPSecurityRx(
  P2VAR(Scc_SDPSecurityType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSECCDiscoveryProtocol/SccSDPRxParam" && name=="SDPSecurityRx" */
  /* Call the state machine related callback function */
  Scc_StateM_Get_SDP_SDPSecurityRx(DataPtr);
}



/**********************************************************************************************************************
 * TX INTERFACE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SDP_InterfaceCfg_Set_SDPTransportProtocol 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SDP_InterfaceCfg_Set_SDPTransportProtocol(
  Scc_SDPTransportProtocolType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSECCDiscoveryProtocol/SccSDPTxParam" && name=="SDPTransportProtocol" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(Data); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_SDP_InterfaceCfg_Set_SDPSecurityTx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SDP_InterfaceCfg_Set_SDPSecurityTx(
  Scc_SDPSecurityType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSECCDiscoveryProtocol/SccSDPTxParam" && name=="SDPSecurityTx" */
  /* Call the related state machine callback */
  Scc_StateM_Set_SDP_SDPSecurityTx(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_SDPSecurityTx(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_SDP_InterfaceCfg_Set_SECCIPAddress 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SDP_InterfaceCfg_Set_SECCIPAddress(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSECCDiscoveryProtocol/SccSDPTxParam" && name=="SECCIPAddress" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(DataPtr); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_SDP_InterfaceCfg_Set_SECCPort 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SDP_InterfaceCfg_Set_SECCPort(
  uint16 Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSECCDiscoveryProtocol/SccSDPTxParam" && name=="SECCPort" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(Data); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_SDP_InterfaceCfg.c
 *********************************************************************************************************************/

