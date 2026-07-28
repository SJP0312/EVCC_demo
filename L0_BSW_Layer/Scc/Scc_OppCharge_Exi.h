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
/*!        \file  Scc_OppCharge_Exi.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to OppCharge
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_OPPCHARGE_EXI_H)
# define SCC_OPPCHARGE_EXI_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if (defined(SCC_SCHEMA_OPP_CHARGE) && (SCC_SCHEMA_OPP_CHARGE != 0u))

#include "Scc_Types.h"
#include "Exi_SAP_SchemaTypes.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/
#define SCC_OPPCHARGE_EXI_SAP_PROTOCOL_NAMESPACE     "urn:iso:15118:2:2010:MsgDef" /* [V2G2-OC-167_1] - Table 22_1 */
#define SCC_OPPCHARGE_EXI_SAP_PROTOCOL_NAMESPACE_LEN 27u                           /* [V2G2-OC-167_1] - Table 22_1 */
#define SCC_OPPCHARGE_EXI_SAP_VERSION_NUMBER_MAJOR   1u                            /* [V2G2-OC-167_1] - Table 22_1 */
#define SCC_OPPCHARGE_EXI_SAP_VERSION_NUMBER_MINOR   0u                            /* [V2G2-OC-167_1] - Table 22_1 */

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiTx_SetupTxConfig
 *********************************************************************************************************************/
/*! \brief          Sets up the passed function pointer
 *  \details        -
 *  \param[out]     TxPrepMessagePtr      Function pointer to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_OppCharge_ExiTx_SetupTxConfig(
  P2VAR(Scc_ExiTx_Xyz_PrepareMessageFctType, AUTOMATIC, SCC_APPL_DATA) TxPrepMessagePtr);

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiTx_SAPSetEntry
 *********************************************************************************************************************/
/*! \brief          Sets up the passed AppProtocolPtr with the related SAP information
 *  \details        -
 *  \param[out]     AppProtocolPtr             Pointer to the SAP entry structure to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_OppCharge_ExiTx_SAPSetEntry(
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA) AppProtocolPtr);


/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_SetupRxConfig
 *********************************************************************************************************************/
/*! \brief          Sets up the passed RxConfigPtr Decodes EXI streams
 *  \details        -
 *  \param[out]     RxConfigPtr             Pointer to the configuration structure to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_OppCharge_ExiRx_SetupRxConfig(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_OPP_CHARGE */

#endif /* SCC_OPPCHARGE_EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_OppCharge_Exi.h
 *********************************************************************************************************************/
