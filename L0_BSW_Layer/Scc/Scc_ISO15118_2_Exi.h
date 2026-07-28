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
/*!        \file  Scc_ISO15118_2_Exi.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO15118-2 SPEC
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_ISO15118_2_EXI_H)
# define SCC_ISO15118_2_EXI_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if (defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u))

#include "Scc_Types.h"
#include "Scc_Exi.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/
#define SCC_ISO15118_2_EXI_SAP_PROTOCOL_NAMESPACE     "urn:iso:15118:2:2013:MsgDef" /* [V2G2-098] */
#define SCC_ISO15118_2_EXI_SAP_PROTOCOL_NAMESPACE_LEN 27u                           /* [V2G2-098] */
#define SCC_ISO15118_2_EXI_SAP_VERSION_NUMBER_MAJOR   2u                            /* [V2G2-098] */
#define SCC_ISO15118_2_EXI_SAP_VERSION_NUMBER_MINOR   0u                            /* [V2G2-098] */

#ifndef SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_URI
# define SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_URI       "http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha256"
#endif
#define SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_URI_LEN   (sizeof(SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_URI) - 1u)
#ifndef SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_SIGSIZE
# define SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_SIGSIZE   64u
#endif

#ifndef SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_URI
# define SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_URI      "http://www.w3.org/2001/04/xmlenc#sha256"
#endif
#define SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_URI_LEN  (sizeof(SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_URI) - 1u)
#ifndef SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_DIGSIZE
# define SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_DIGSIZE  32u
#endif

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_Init
 *********************************************************************************************************************/
/*! \brief          initializes global parameters
 *  \details        -
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiTx_Init(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_SetupTxConfig
 *********************************************************************************************************************/
/*! \brief          Sets up the passed function pointer
 *  \details        -
 *  \param[out]     TxPrepMessagePtr      Function pointer to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiTx_SetupTxConfig(
  P2VAR(Scc_ExiTx_Xyz_PrepareMessageFctType, AUTOMATIC, SCC_APPL_DATA) TxPrepMessagePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_SAPSetEntry
 *********************************************************************************************************************/
/*! \brief          Sets up the passed AppProtocolPtr with the related SAP information
 *  \details        -
 *  \param[out]     AppProtocolPtr             Pointer to the SAP entry structure to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiTx_SAPSetEntry(
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA) AppProtocolPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_SetupRxConfig
 *********************************************************************************************************************/
/*! \brief          Sets up the passed RxConfigPtr Decodes EXI streams
 *  \details        -
 *  \param[out]     RxConfigPtr             Pointer to the configuration structure to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiRx_SetupRxConfig(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_PrepareMessage
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiTx_PrepareMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_InitXmlSecurityWorkspace
 *********************************************************************************************************************/
/*! \brief          Initializes XmlSecurity workspace for ISO-2.
 *  \details        -
 *  \param[in]      MsgPtr                      Pointer to the Received message
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiRx_InitXmlSecurityWorkspace(P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
#endif /* SCC_ENABLE_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*! \brief          Prepares the decoding of an EXI stream
 *  \details        -
 *  \param[in]      V2GTpHeaderPtr                     Pointer to a v2gtp header
 *  \param[in]      RxMsgWSPtr                         Pointer to the Rx message workspace
 *  \param[in]      SkipSessionIdCheck                 True: Do not perform SessionIdCheck, False: Perform SessionId check.
 *  \return         Scc_ReturnType_OK                  Preparation succeeded
 *  \return         Scc_ReturnType_InvalidSessionId    The SessionId is invalid
 *  \return         Scc_ReturnType_NotOK               Preparation failed due to either initializing or decoding Exi
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_DecodeMessagePrepare(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr,
  CONST(boolean, AUTOMATIC) SkipSessionIdCheck);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO */

#endif /* SCC_ISO15118_2_EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_2_Exi.h
 *********************************************************************************************************************/
