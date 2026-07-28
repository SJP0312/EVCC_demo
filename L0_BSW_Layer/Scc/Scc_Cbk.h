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
/*!        \file  Scc_Cbk.h
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
#if !defined (SCC_CBK_H)
# define SCC_CBK_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "TcpIp.h"
#include "EthIf_Types.h"
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
#include "Slac.h"
#endif /* ( SCC_ENABLE_SLAC_HANDLING == STD_ON ) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "Scc_MemMap.h"

/**********************************************************************************************************************
 *  Scc_Cbk_TL_RxIndication
 *********************************************************************************************************************/
/*! \brief       receive indication
 *  \details     -
 *  \param[in]   SockHnd               socket handle
 *  \param[in]   SourcePtr             source network address and port
 *  \param[in]   DataPtr               pointer to the received data
 *  \param[in]   DataLen               length of to the received data
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Cbk_TL_RxIndication(
  Scc_SocketType SockHnd,
  P2VAR(Scc_SockAddrType, AUTOMATIC, SCC_APPL_DATA) SourcePtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  uint16 DataLen);

/**********************************************************************************************************************
 *  Scc_Cbk_CopyTxData
 *********************************************************************************************************************/
/*! \brief       receive indication
 *  \details      -
 *  \param[in]   SocketId              socket handle
 *  \param[in]   BufPtr                pointer to the output buffer
 *  \param[in]   BufLengthPtr             Length of the output buffer
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, SCC_CODE) Scc_Cbk_CopyTxData(
    TcpIp_SocketIdType SocketId,
    P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) BufPtr,
    P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) BufLengthPtr
);

/**********************************************************************************************************************
 *  Scc_Cbk_TL_TCPConnected
 *********************************************************************************************************************/
/*! \brief       TCP connected
 *  \details     -
 *  \param[in]   SockHnd            socket handle
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_TL_TCPConnected(Scc_SocketType SockHnd);

/**********************************************************************************************************************
 *  Scc_Cbk_TL_TCPEvent
 *********************************************************************************************************************/
/*! \brief       TCP event handling
 *  \details     -
 *  \param[in]   SockHnd            socket handle
 *  \param[in]   Event              socket event
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_TL_TCPEvent(Scc_SocketType SockHnd, IpBase_TcpIpEventType Event);

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_FirmwareDownloadComplete
 *********************************************************************************************************************/
/*! \brief       callback that is called after the firmware download was processed and the firmware was started
 *  \details     -
 *  \param[in]   DownloadSuccessful           indicates if Firmware download was successful
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_SLAC_FirmwareDownloadComplete(boolean DownloadSuccessful);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_FirmwareDownloadStart
 *********************************************************************************************************************/
/*! \brief       callback that is called after the firmware download was started
 *  \details     -
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_SLAC_FirmwareDownloadStart(void);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_AssociationStatus
 *********************************************************************************************************************/
/*! \brief       callback function for ongoing association errors and status information
 *  \details     -
 *  \param[in]   AssocStatus    Association status from Slac
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_SLAC_AssociationStatus(CONST(Slac_AssocStatusType, SCC_CONST) AssocStatus);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_DLinkReady
 *********************************************************************************************************************/
/*! \brief       D-LINK READY indication informs higher layers about a change of PLC link status
 *  \details     -
 *  \param[in]   DLinkReady      the power line link state after SLAC was finished
 *  \param[in]   InfoValid       Indicates if the parameters Nmk, Nid and EvseMac are valid
 *  \param[in]   NMKPtr          the network membership key (NMK) that was established during the SLAC session
 *  \param[in]   NIDPtr          the network identifier (NID) that was established during the SLAC session
 *  \param[in]   EvseMacPtr      EVSE MAC address this PLC link was established to
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_SLAC_DLinkReady(Slac_DLinkStatusType DLinkReady,
  Slac_BooleanType InfoValid, P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) NMKPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) NIDPtr, P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) EvseMacPtr);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_GetRandomizedDataBuffer
 *********************************************************************************************************************/
/*! \brief       the callback is used by the SLAC component to gain a random byte array
 *  \details     -
 *  \param[out]  RandomDataPtr      the buffer that must be randomized
 *  \param[in]   RandomDataLen      the length of the buffer
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_SLAC_GetRandomizedDataBuffer(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) RandomDataPtr, uint16 RandomDataLen);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_GetValidateToggles
 *********************************************************************************************************************/
/*! \brief       callback function to generate a random number of validation toggles
 *  \details     -
 *  \return      [1,2,3]      random number of validation toggles
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(uint8, SCC_CODE) Scc_Cbk_SLAC_GetValidateToggles(void);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_SetBcbToggleState
 *********************************************************************************************************************/
/*! \brief       callback to request the toggle of CP state to the desired state
 *  \details     -
 *  \param[in]   NewCpState     Control pilot state that shall be applied
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_SLAC_SetBcbToggleState(Slac_ControlPilotStateType NewCpState);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_GetExecuteValidationInfo
 *********************************************************************************************************************/
/*! \brief      This callout optionally is called after the CM_ATTEN_CHAR.IND of all attending EVSEs is collected. The
 *              application can decide if the validation process shall be executed or not.
 *  \details     -
 *  \param[in]   ValidationInfo             The validation information evaluated by the Slac module
 *  \return      Slac_VE_DoNotValidate, Slac_VE_OptionalValidation, Slac_VE_ForceValidation, Slac_VE_DecisionPending
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Slac_ValidationExecutionType, SCC_CODE) Scc_Cbk_SLAC_GetExecuteValidationInfo(Slac_ValidationInfoType ValidationInfo);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
/**********************************************************************************************************************
 *  Scc_Cbk_SLAC_SetReadyForSlac
 *********************************************************************************************************************/
/*! \brief      Indicates if the PLC chip is ready to start the SLAC process
 *  \details     -
 *  \param[in]   ReadyForSlac      Indicates if the PLC chip is ready to start the SLAC process
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Cbk_SLAC_SetReadyForSlac(boolean ReadyForSlac);
#endif /* SCC_ENABLE_SLAC_HANDLING */

/**********************************************************************************************************************
 *  Scc_Cbk_Eth_TransceiverLinkStateChange
 **********************************************************************************************************************/
/*! \brief        Called by lower layer (e.g. EthIf) to indicate a change of the transceiver link state
 *  \details      -
 *  \param[in]    CtrlIdx         index of the ethernet controller
 *  \param[in]    TrcvLinkState   new state of the tranceiver
 *  \pre          -
 *  \context      TASK|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 **********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_Eth_TransceiverLinkStateChange(
  uint8 CtrlIdx,
  EthTrcv_LinkStateType TrcvLinkState);

/**********************************************************************************************************************
 *  Scc_Cbk_IP_AddressAssignmentChange
 *********************************************************************************************************************/
/*! \brief       IP address assignment change callback
 *  \details     -
 *  \param[in]   LocalAddrId           ID of the local address
 *  \param[in]   State                 state of the local address
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_IP_AddressAssignmentChange(TcpIp_LocalAddrIdType LocalAddrId,
  TcpIp_IpAddrStateType State);

#if (defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON))
/**********************************************************************************************************************
 *  Scc_Cbk_TLS_CertChain
 *********************************************************************************************************************/
/*! \brief          TLS validation result for a server certificate chain
 *  \details        -
 *  \param[in]      SockHnd                socket handle
 *  \param[in]      NumCerts               Number of certificates received in Tls handshake
 *  \param[in]      CertChainStatusPtr     Pointer to the certificate chain(KeyM certId etc)
 *  \param[in,out]  ValidationResultPtr    Validation result (VALIDATION_OK etc.)
 *  \param[in]      TlsConnectionInfoPtr   TLS connection information
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS
 **********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_TLS_CertChain(
  Scc_SocketType                              SockHnd,
  uint32                                      NumCerts,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA)   CertChainStatusPtr,
  P2VAR(TcpIp_CertValidationResultType, AUTOMATIC, SCC_APPL_DATA)     ValidationResultPtr,
  P2CONST(TcpIp_TlsConnectionInfoType, AUTOMATIC, SCC_APPL_DATA)      TlsConnectionInfoPtr);


/**********************************************************************************************************************
 *  Scc_Cbk_TLS_ChangeableCipher
 *********************************************************************************************************************/
/*! \brief          TLS callback to change prioritization of cipher suites and signature algorithms.
 *  \details        -
 *  \param[in]      SocketId                           Socket ID
 *  \param[in,out]  CipherSuiteWorkingSetPtr           Pointer to cipher suites
 *  \param[in,out]  SignatureAlgorithmWorkingSetPtr    Pointer to signature algorithms
 *  \param[in,out]  SccPushButtonModePtr               Pointer to Scc push button mode
 *  \param[in,out]  ChangeableCipherStatusPtr          Pointer to changeable cipher status
 *  \return         E_OK                               Callback processed successful
 *  \return         E_NOT_OK                           Internal error inside callback
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, SCC_CODE) Scc_Cbk_TLS_ChangeableCipher(
  Scc_SocketType                                                             SocketId,
  P2VAR(TcpIp_TlsCipherSuiteWorkingSetType, AUTOMATIC, SCC_APPL_DATA)        CipherSuiteWorkingSetPtr,
  P2VAR(TcpIp_TlsSignatureAlgorithmWorkingSetType, AUTOMATIC, SCC_APPL_DATA) SignatureAlgorithmWorkingSetPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA)                                   SccPushButtonModePtr,
  P2VAR(TcpIp_TlsChangeCipherStatusType, AUTOMATIC, SCC_APPL_DATA)           ChangeableCipherStatusPtr
);
#endif /* ( SCC_ENABLE_TLS == STD_ON ) */

#if ( SCC_ENABLE_TLS_RESUMPTION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Cbk_TLS_SessionTicketInfo
 *********************************************************************************************************************/
/*! \brief          TLS callback to inform about the session ticket.
 *  \details        -
 *  \param[in]      SocketId             Socket ID
 *  \param[in]      SessionTicketInfoPtr Pointer to session ticket info
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS_RESUMPTION
 **********************************************************************************************************************/
extern FUNC(void, SCC_CODE) Scc_Cbk_TLS_SessionTicketInfo(
  Scc_SocketType                                                        SocketId,
  P2CONST(TcpIp_TlsSessionTicketUserInfoType, AUTOMATIC, SCC_APPL_DATA) SessionTicketInfoPtr
);
#endif /* SCC_ENABLE_TLS_RESUMPTION */

#if (defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
/**********************************************************************************************************************
 *  Scc_Cbk_TLS_ClientAuthenticationRequest
 *********************************************************************************************************************/
 /*! \brief          Callback returns the configured VehicleCert chain IDs.
  *  \details        -
  *  \param[in]      SocketId                      TcpIp socket ID
  *  \param[in]      RequestInfoPtr                Received server parameters
  *  \param[in,out]  VehicleCertChainInfoPtr       Configured client parameters
  *  \param[out]     VehicleCertChainInfoStatusPtr Status of the VehicleCert chain
  *  \return         E_OK         Vehicle certificate is selected or selection is ongoing.
  *  \return         E_NOT_OK     Error occurred.
  *  \pre            -
  *  \context        TASK|ISR2
  *  \reentrant      FALSE
  *  \synchronous    TRUE
  *  \config         SCC_ENABLE_TLS_ISO20_CLIENTAUTH
  **********************************************************************************************************************/
extern FUNC(Std_ReturnType, SCC_CODE) Scc_Cbk_TLS_ClientAuthenticationRequest(
  TcpIp_SocketIdType SocketId,
  P2CONST(TcpIp_TlsCertRequestInfoType, AUTOMATIC, SCC_CONST) RequestInfoPtr,
  P2VAR(TcpIp_TlsClientCertInfoType, AUTOMATIC, SCC_APPL_DATA) VehicleCertChainInfoPtr,
  P2VAR(TcpIp_TlsClientCertInfoStatusType, AUTOMATIC, SCC_APPL_DATA) VehicleCertChainInfoStatusPtr);
#endif /* SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Cbk_KeyM_GroupUpdateStatus
 *********************************************************************************************************************/
/*! \brief          KeyM validation result for a certificate group
 *  \details        -
 *  \param[in]      GroupId                Group id that was verified
 *  \param[in]      Result                 Result of verify operation
 *  \return         E_OK
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 **********************************************************************************************************************/
/* Declared by KeyM generator in KeyM_Cfg.h */
/*
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Cbk_KeyM_GroupUpdateStatus(
  KeyM_CertificateGroupIdType GroupId,
  KeyM_CertificateGroupStatusType Result);
 */
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING  */

#define SCC_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "Scc_MemMap.h"

#endif  /* SCC_CBK_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_Cbk.h
 *********************************************************************************************************************/
