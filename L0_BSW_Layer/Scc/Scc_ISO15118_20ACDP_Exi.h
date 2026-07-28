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
/*!        \file  Scc_ISO15118_20ACDP_Exi.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO15118-20 SPEC for ACDP schema specific parts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_ISO15118_20ACDP_EXI_H)
# define SCC_ISO15118_20ACDP_EXI_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))

#include "Scc_Exi.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/
#define SCC_ISO15118_20ACDP_EXI_SAP_PROTOCOL_NAMESPACE     "urn:iso:std:iso:15118:-20:ACDP" /* [V2G20-4107] */
#define SCC_ISO15118_20ACDP_EXI_SAP_PROTOCOL_NAMESPACE_LEN 30u                              /* [V2G20-4107] */
#define SCC_ISO15118_20ACDP_EXI_SAP_VERSION_NUMBER_MAJOR   1u                               /* [V2G20-4107] */
#define SCC_ISO15118_20ACDP_EXI_SAP_VERSION_NUMBER_MINOR   0u                               /* [V2G20-4107] */

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiTx_SAPSetEntry
 *********************************************************************************************************************/
/*! \brief          Sets up the passed AppProtocolPtr with the related SAP information
 *  \details        -
 *  \param[out]     AppProtocolPtr             Pointer to the SAP entry structure to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20ACDP_ExiTx_SAPSetEntry(
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA) AppProtocolPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiTx_PrepareMessage
 *********************************************************************************************************************/
/*! \brief          Prepares the EXI request message to be transmitted
 *  \details        -
 *  \param[in]      TxMsgWSPtr                  Pointer to the Tx message workspace
 *  \return         Scc_ReturnType_OK           Exi preparation was successful
 *  \return         Scc_ReturnType_NotOK        Exi preparation was not successful or timeout happened
 *  \return         Scc_ReturnType_Pending      Message handling is pending, try again later
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20ACDP_ExiTx_PrepareMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*! \brief          Prepares the decoding of an EXI stream
 *  \details        -
 *  \param[in]      RxMsgWSPtr                         Pointer to the Rx message workspace
 *  \return         Scc_ReturnType_OK                  Preparation succeeded
 *  \return         Scc_ReturnType_InvalidSessionId    The SessionId is invalid
 *  \return         Scc_ReturnType_NotOK               Preparation failed due to either initializing or decoding Exi
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20ACDP_ExiRx_DecodeMessagePrepare(
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiRx_DecodeMessage
 *********************************************************************************************************************/
/*! \brief          Decodes EXI streams
 *  \details        -
 *  \param[in]      RxMsgWSPtr                  Pointer to the Rx message workspace
 *  \return         Scc_ReturnType_OK           Exi decode was successful
 *  \return         Scc_ReturnType_NotOK        Exi decode was not successful or timeout happened
 *  \return         Scc_ReturnType_Pending      Message handling is pending, try again later
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20ACDP_ExiRx_DecodeMessage(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20ACDP */

#endif /* SCC_ISO15118_20ACDP_EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20ACDP_Exi.h
 *********************************************************************************************************************/
