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
/*!        \file  Scc_SAP_Exi.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements the shared SupportedAppProtocol that is used in Vehicle 2 Grid communication according
 *                to the specifications DIN SPEC 70121, ISO/IEC 15118-2 and ISO/IEC 15118-20.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_SAP_EXI_H)
# define SCC_SAP_EXI_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Types.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  Scc_SAP_ExiTx_StateCreateDefaultList,   /**< In this state the default schema list being build */
  Scc_SAP_ExiTx_StatePropagateList,       /**< In this state the list is propagated to application and may be overwritten */
  Scc_SAP_ExiTx_StateBuildReqMessage      /**< In this state the request message is build based on the list */
}Scc_SAP_ExiTxStatesEnumType;

typedef struct
{
  Scc_SAP_SchemaListStructType SupportedSchemaList; /**< The list of supported schemas */
  Scc_SAP_ExiTxStatesEnumType State;                /**< The current state of the Tx path */
} Scc_SAP_ExiTx_WorkspaceStructType;


/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_Init
 *********************************************************************************************************************/
/*! \brief          Initializes the SAP ExiTx unit
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SAP_ExiTx_Init(void);

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_PrepareSupportedAppProtocolReq
 *********************************************************************************************************************/
/*! \brief          Prepares the SAP request message to be transmitted
 *  \details        -
 *  \param[in]      TxMsgWSPtr            Pointer to the Tx message workspace
 *  \return         Scc_ReturnType_OK     SAP preparation was successful
 *  \return         Scc_ReturnType_NotOK  SAP preparation was not successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_SAP_ExiTx_PrepareSupportedAppProtocolReq(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_SAP_ExiTx_ChosenSchemaSupported
 *********************************************************************************************************************/
/*! \brief          Checks whether the passed supported app protocol schema is supported or not.
 *  \details        Checks if the passed schema is contained in supported schema list that was sent to the EVSE.
 *  \param[in]      ChosenSAPSchema            The chosen schema to be tested
 *  \return         TRUE  Passed schema is supported
 *  \return         FALSE Passed schema is not supported
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_STATIC_CODE) Scc_SAP_ExiTx_ChosenSchemaSupported(
  Scc_SAPSchemaIDType ChosenSAPSchema);

/**********************************************************************************************************************
 *  Scc_SAP_ExiRx_Init
 *********************************************************************************************************************/
/*! \brief          Initializes the SAP ExiRx unit
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \note           Is called in the Scc_Init()
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SAP_ExiRx_Init(void);

/**********************************************************************************************************************
 *  Scc_SAP_ExiRx_SetupRxConfig
 *********************************************************************************************************************/
/*! \brief          Sets up the passed RxConfigPtr pointer
 *  \details        -
 *  \param[in]      RxConfigPtr             Pointer to the configuration structure to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SAP_ExiRx_SetupRxConfig(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr);

/**********************************************************************************************************************
 *  Scc_SAP_ExiRx_GetChosenSchema
 *********************************************************************************************************************/
/*! \brief          Returns the chosen schema of the received SupportedAppProtocolRes message
 *  \details        -
 *  \return         The chosen schema
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_SAPSchemaIDType, SCC_CODE) Scc_SAP_ExiRx_GetChosenSchema(void);


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SAP_EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_SAP_Exi.h
 *********************************************************************************************************************/
