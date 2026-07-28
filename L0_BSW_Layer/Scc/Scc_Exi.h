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
/*!        \file  Scc_Exi.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-2,
 *                DIN SPEC 70121 and customer specific schemas.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_EXI_H)
# define SCC_EXI_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
#define Scc_Exi_TempBuf   Scc_Exi_TempBufUnion.Buf8
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
/* 8bit variables */
#define SCC_START_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 ))                                                             /* PRQA S 3332 */ /* MD_Scc_3332 */
extern VAR(uint8, SCC_VAR_NOINIT) Scc_Exi_SAScheduleTupleID;
#endif /* SCC_SCHEMA_ISO */

#define SCC_STOP_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* 16bit variables */
#define SCC_START_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
extern VAR(uint16, SCC_VAR_NOINIT) Scc_Exi_TempBufPos;
#endif /* SCC_ENABLE_PNC_CHARGING */

#define SCC_STOP_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
extern VAR(XmlSecurity_SigGenWorkspaceType, SCC_VAR_NOINIT) Scc_Exi_XmlSecSigGenWs;
extern VAR(XmlSecurity_SigVerWorkspaceType, SCC_VAR_NOINIT) Scc_Exi_XmlSecSigVerWs;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u))
extern VAR(Exi_ISO_EnergyTransferModeType, SCC_VAR_NOINIT) Scc_ISO15118_2_ExiTx_EnergyTransferMode;
#endif /* SCC_SCHEMA_ISO */

#if (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 ))                                                             /* PRQA S 3332 */ /* MD_Scc_3332 */
extern VAR(Scc_ISO_PaymentOptionType, SCC_VAR_NOINIT)      Scc_Exi_PaymentOption;
extern VAR(Scc_ISO_ChargingSessionType, SCC_VAR_NOINIT)    Scc_Exi_ChargingSession;
#endif /* SCC_SCHEMA_ISO */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0))
extern VAR(Scc_Exi_TempBufType, SCC_VAR_NOINIT)   Scc_Exi_TempBufUnion;                                                 /* PRQA S 0759 */ /* MD_MSR_Union */
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_SCHEMA_ISO_20 */

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_Exi_Init
 *********************************************************************************************************************/
/*! \brief          Initializes global parameters.
 *  \details        Reset the position of the Scc_Exi_TempBuf.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \note           Is called in the Scc_Init()
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Exi_Init(void);

#if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_Exi_IsExiTempBufInUse
 *********************************************************************************************************************/
/*! \brief          Returns if ExiTempBuf is used or not
 *  \details        -
 *  \return         ExiTempBufInUse
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_STATIC_CODE) Scc_Exi_IsExiTempBufInUse(void);

/**********************************************************************************************************************
 *  Scc_Exi_SetExiTempBufInUse
 *********************************************************************************************************************/
/*! \brief          Sets if ExiTempBuf is used or not
 *  \details        -
 *  \param[in]      ExiTempBufInUse                 If the ExiTempBuf is used currently or not
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_Exi_SetExiTempBufInUse(boolean ExiTempBufInUse);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_Exi_InitDecodingWorkspace
 *********************************************************************************************************************/
/*! \brief          initialize dencoding workspace (Common - DIN, ISO-2 and ISO-20)
 *  \details        add data to the post buffer and transmit the encoded data
 *  \param[in]      RxMsgWSPtr            Pointer to the Rx message workspace
 *  \return         E_OK                  Exi initialize dencoding workspace was successful
 *  \return         E_NOT_OK              Exi initialize dencoding workspace was not successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Exi_InitDecodingWorkspace(P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_Exi_EncodeReq
 *********************************************************************************************************************/
/*! \brief          Call back function from TcpIp to copy data into TcpIp buffer for request message
 *  \details        -
 *  \param[in]      BufPtr                pointer to the output buffer
 *  \param[in]      BufLengthPtr          Length of the output buffer
 *  \param[in]      PBufPtr               pointer to tx data
 *  \param[in]      TxMsgWSPtr            Pointer to the Tx message workspace
 *  \param[in]      Exi_EncWsPtr          Pointer to the encode workspace
 *  \return         E_OK                  Exi encode was successful
 *  \return         E_NOT_OK              Exi encode was not successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_Exi_EncodeReq(
    P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) BufPtr,
    P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) BufLengthPtr,
    P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) PBufPtr,
    P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr
);

/**********************************************************************************************************************
 *  Scc_Exi_Get_SendDataState
 *********************************************************************************************************************/
/*! \brief          Gets the SendDataState
 *  \details        -
 *  \return         SendDataState
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_SendDataStateType, SCC_CODE) Scc_Exi_Get_SendDataState(void);

/**********************************************************************************************************************
 *  Scc_Exi_Set_SendDataState
 *********************************************************************************************************************/
/*! \brief          Sets the SendDataState
 *  \details        -
 *  \param[in]      SendDataState                State to be set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Exi_Set_SendDataState(Scc_SendDataStateType SendDataState);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_Exi.h
 *********************************************************************************************************************/
