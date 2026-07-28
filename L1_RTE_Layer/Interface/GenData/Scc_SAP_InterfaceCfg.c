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
 *              File: Scc_SAP_InterfaceCfg.c
 *   Generation Time: 2025-08-26 17:17:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_SAP_INTERFACECFG_SOURCE 

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_SAP_InterfaceCfg.h"
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
 *  Scc_SAP_InterfaceCfg_Get_SAPSchemaList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SAP_InterfaceCfg_Get_SAPSchemaList(
  P2VAR(Scc_SAP_SchemaListStructType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ApplicationPending)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSupportedAppProtocol/SccSAPRxParam" && name=="SAPSchemaList" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_Core_SAPSchemaList(DataPtr, ApplicationPending);
}



/**********************************************************************************************************************
 * TX INTERFACE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SAP_InterfaceCfg_Set_SAPResponseCode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SAP_InterfaceCfg_Set_SAPResponseCode(
  Exi_SAP_responseCodeType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSupportedAppProtocol/SccSAPTxParam" && name=="SAPResponseCode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_SAPResponseCode(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_SAP_InterfaceCfg_Set_SAPSchemaID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SAP_InterfaceCfg_Set_SAPSchemaID(
  Scc_SAPSchemaIDType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSupportedAppProtocol/SccSAPTxParam" && name=="SAPSchemaID" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_SAPSchemaID(Data); /*lint !e522 */ /* Application specific implementation */
}



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_SAP_InterfaceCfg.c
 *********************************************************************************************************************/

