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
/*!        \file  Scc_ISO15118_20CM_Exi.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-20 Common messages
 *                specific parts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_ISO15118_20CM_EXI_H)
# define SCC_ISO15118_20CM_EXI_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if (defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u))

#include "Scc_Exi.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_Init
 *********************************************************************************************************************/
/*! \brief          Initializes global parameters
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_ExiTx_Init(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_DecodeMessagePrepare
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_DecodeMessagePrepare(
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_DecodeMessage
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_DecodeMessage(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

#if ( (defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON) )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_InitXmlSecurityWorkspace
 *********************************************************************************************************************/
/*! \brief          Initializes XmlSecurity workspace for ISO-20CM.
 *  \details        -
 *  \param[in]      MsgPtr                      Pointer to the Received message
 *  \param[in]      Curve                       Certificate signature curve
 *  \return         Scc_ReturnType_OK           Initialization of XMLSecurity workspace was successful
 *  \return         Scc_ReturnType_NotOK        Initialization of XMLSecurity workspace was not successful
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_InitXmlSecurityWorkspace(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr,
  Scc_CertificateCurveEnumType Curve);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_PrepareMessage
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiTx_PrepareMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID
 *********************************************************************************************************************/
/*! \brief          Returns the SelectedEnergyTransferServiceID
 *  \details        -
 *  \return         SelectedEnergyTransferServiceID
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ISO15118_20_ServiceIDType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_Get_SelectedChargingSession
 *********************************************************************************************************************/
/*! \brief          Returns the SelectedChargingSession
 *  \details        -
 *  \return         SelectedChargingSession
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Exi_ISO_20_CM_10_chargingSessionType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_Get_SelectedChargingSession(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_Get_TransmittedChargeProgress
 *********************************************************************************************************************/
/*! \brief          Returns the ChargeProgress that was transmitted in the request message
 *  \details        -
 *  \return         ChargeProgress
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Exi_ISO_20_CM_10_chargeProgressType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_Get_TransmittedChargeProgress(void);


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20 */

#endif /* SCC_ISO15118_20CM_EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20CM_Exi.h
 *********************************************************************************************************************/
