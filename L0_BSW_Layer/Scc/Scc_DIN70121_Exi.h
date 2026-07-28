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
/*!        \file  Scc_DIN70121_Exi.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to DIN SPEC 70121
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_DIN70121_EXI_H)
# define SCC_DIN70121_EXI_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if (defined(SCC_SCHEMA_DIN) && (SCC_SCHEMA_DIN != 0u))

#include "Scc_Types.h"
#include "Exi_SAP_SchemaTypes.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/
#define SCC_DIN70121_EXI_SAP_PROTOCOL_NAMESPACE     "urn:din:70121:2012:MsgDef" /* [V2G-DC-229] */
#define SCC_DIN70121_EXI_SAP_PROTOCOL_NAMESPACE_LEN 25u                         /* [V2G-DC-229] */
#define SCC_DIN70121_EXI_SAP_VERSION_NUMBER_MAJOR   2u                          /* [V2G-DC-229] */
#define SCC_DIN70121_EXI_SAP_VERSION_NUMBER_MINOR   0u                          /* [V2G-DC-229] */

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
/* 16bit variables */
#define SCC_START_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
extern VAR(uint16, SCC_VAR_NOINIT) Scc_DIN70121_ExiRx_ServiceID;
#endif /* SCC_SCHEMA_DIN */

#define SCC_STOP_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_SetupTxConfig
 *********************************************************************************************************************/
/*! \brief          Sets up the passed function pointer
 *  \details        -
 *  \param[out]     TxPrepMessagePtr      Function pointer to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_ExiTx_SetupTxConfig(
  P2VAR(Scc_ExiTx_Xyz_PrepareMessageFctType, AUTOMATIC, SCC_APPL_DATA) TxPrepMessagePtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_SAPSetEntry
 *********************************************************************************************************************/
/*! \brief          Sets up the passed AppProtocolPtr with the related SAP information
 *  \details        -
 *  \param[out]     AppProtocolPtr             Pointer to the SAP entry structure to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_ExiTx_SAPSetEntry(
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA) AppProtocolPtr);


/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_SetupRxConfig
 *********************************************************************************************************************/
/*! \brief          Sets up the passed RxConfigPtr Decodes EXI streams
 *  \details        -
 *  \param[out]     RxConfigPtr             Pointer to the configuration structure to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_ExiRx_SetupRxConfig(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_DIN */

#endif /* SCC_DIN70121_EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_DIN70121_Exi.h
 *********************************************************************************************************************/
