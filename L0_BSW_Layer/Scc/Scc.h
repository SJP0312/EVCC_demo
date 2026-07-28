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
/*!        \file  Scc.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-2,
 *                DIN SPEC 70121 and customer specific schemas.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * REVISION HISTORY
 * --------------------------------------------------------------------------------------------------------------------
 * Version  Date       Author       Change Id     Description
 * --------------------------------------------------------------------------------------------------------------------
 * 01.00.00 2010-01-01 visalr       -             created
 * 01.xx.xx 2013-07-04 visalr       -             removed revision history for version 1.xx.xx
 * 02.xx.xx 2013-08-21 visefa       -             removed revision history for version 2.xx.xx
 * 04.00.00 2012-09-24 visefa       ESCAN00061627 TCP Timeout Handling not functional
 *          2012-10-22 visefa       ESCAN00062434 Implemented EIM AC charging according to ISO15118 DIS
 *          2013-01-18 visefa       ESCAN00064321 Implemented PnC AC charging according to ISO15118 DIS
 *          2013-01-23 visefa       ESCAN00064463 Added compatibility for AUTOSAR4
 * 04.00.01 2013-04-09 visefa       ESCAN00066501 OEM specific: Issues with transmission of COM signals
 *          2013-04-19 visefa       ESCAN00066791 OEM specific: SAScheduleList is not processed correctly
 * 04.00.02 2013-04-24 visefa       ESCAN00066883 OEM specific: Issue with transmission of SAScheduleList over CanTp
 * 04.00.03 2013-05-24 visefa       ESCAN00067642 Compiler error: last line of file ends without a newline
 * 04.01.00 2013-06-11 visefa       ESCAN00067976 Smaller NvM blocks are now read with ReadAll()
 *          2013-06-17 visefa       ESCAN00068105 EVCCID is now read from EthIf
 *          2013-07-01 visefa       ESCAN00068451 OEM specific: Added Vector defined state machine
 *          2013-07-01 visefa       ESCAN00068457 OEM specific: Update of implementation to latest spec (2013-05-02)
 *          2013-07-01 visefa       ESCAN00068458 OEM specific: Update of implementation to latest spec (2013-06-04)
 *          2013-07-01 visefa       ESCAN00068459 Incoming EXI encoded messages are now handled in the MainFunction()
 * 04.01.01 2013-07-29 visefa       ESCAN00069382 Issues with integration of XmlSecurity
 *          2013-08-06 visefa       ESCAN00069621 OEM specific: Issue at transition from ChargingStatus to PowerDelivery
 *          2013-08-08 visefa       ESCAN00069658 Rx and Tx messages now share the same Exi Stream Buffer
 *          2013-08-19 visefa       ESCAN00069936 OEM specific: Incorrect error handling in case of negative SAP response
 *          2013-08-22 visefa       ESCAN00069975 Issues during CertificateInstallation and CertificateUpdate
 *          2013-09-03 visefa       ESCAN00069998 OEM specific: Invalid V2GTP payload type is accepted for SDP responses
 *          2013-09-27 visefa       ESCAN00070685 OEM specific: Extended RTE interface by SCCStatus and ErrorStatus
 *          2013-09-27 visefa       ESCAN00070757 OEM specific: Amount of ChargingProfile entries is now variable
 *          2013-10-10 visefa       ESCAN00071013 OEM specific: Previous message set is not saved to NvM
 * 05.00.00 2013-12-20 visefa       ESCAN00072746 Implemented AC charging according to ISO15118 FDIS
 *          2013-12-20 visefa       ESCAN00072748 OEM specific: Update of implementation to latest spec (2013-12-09)
 * 05.00.01 2014-01-17 visefa       ESCAN00073053 MISRA corrections (2014-01-17)
 * 05.00.02 2014-01-21 visefa       ESCAN00073108 Code Maintenance (2014-01-21)
 * 05.01.00 2014-01-30 visefa       ESCAN00073281 OEM specific: Implemented DC charging according to ISO15118 FDIS
 *          2014-01-30 visefa       ESCAN00073283 OEM specific: Implemented DC charging according to DIN70121 RC6
 * 05.01.01 2014-02-25 visefa       ESCAN00073915 OEM specific: Added "DIN70121 only" support
 * 05.01.02 2014-03-10 visefa       ESCAN00074185 OEM specific: Resolved issues in the OEM StateMachine
 * 05.02.00 2014-03-25 visefa       ESCAN00074546 OEM specific: Added support for additional OEM
 * 05.02.01 2014-04-24 visefa       ESCAN00075209 X509IssuerName is now encoded according to RFC4514
 *          2014-04-29 visefa       ESCAN00075251 OEM specific: Changed the order of the AppProtocols
 * 05.02.02 2014-05-19 visefa       ESCAN00075440 Signatures of CertInstall/Update parameters aren't validated correctly
 *          2014-06-10 visefa       ESCAN00076172 OEM specific: Update of implementation to latest spec (2014-05-23)
 * 05.03.00 2014-06-16 visefa       ESCAN00076292 OEM specific: Implemented IC charging according to customer spec
 *          2014-06-27 visefa       ESCAN00076549 OEM specific: Value of a CAN signal is not correctly set
 *          2014-06-27 visefa       ESCAN00076550 Message Timeout when looping in cyclic messages
 * 05.03.01 2014-07-02 visefa       ESCAN00076652 OEM specific: Compiler error: "undeclared identifier"
 *          2014-07-03 visefa       ESCAN00076719 OEM specific: Retransmission of CANTP packets not working correctly
 *          2014-07-03 visefa       ESCAN00076723 OEM specific: Changed unit of Next Request Delay to 100ms
 * 06.00.00 2014-06-26 visefa       ESCAN00076507 Added support for Tp_TcpIp API of MSR4R8 and higher
 *          2014-07-10 visefa       ESCAN00076909 Added support for encrypted storage of PrivateKeys
 *          2014-07-17 visefa       ESCAN00077168 EXI Stream and one of the two EXI Struct buffers are no longer required
 *          2014-07-18 visefa       ESCAN00077203 OEM specific: Update of implementation to latest spec (2014-07-09)
 *          2014-08-06 visefa       ESCAN00077655 OEM specific: NvM is not included if not used
 * 06.01.00 2014-12-05 visefa       ESCAN00080039 OEM specific: Update of implementation to latest spec (2014-12-02)
 *          2014-12-05 visefa       ESCAN00080040 OEM specific: Next Request Delay is now based on MainFunction cycles
 * 06.02.00 2014-12-17 visefa       ESCAN00079925 Invalidated NvM blocks are not handled correctly
 *          2015-01-09 visefa       ESCAN00080478 OEM specific: SCC does not accept an UDS ACK according to ISO14229
 *          2015-01-19 visefa       ESCAN00080041 OEM specific: Implemented IC charging according to customer spec
 *          2015-01-21 visefa       ESCAN00080714 Added support for TX streaming
 *          2015-02-02 visefa       ESCAN00081707 OEM specific: Added ContrCertPrivKey password callback for CANTP
 *          2015-02-17 visefa       ESCAN00081296 OEM specific: Rework of IEC61851 handling
 *          2015-02-18 visefa       ESCAN00081333 OEM specific: Enumeration was not implemented as specified
 *          2015-02-18 visefa       ESCAN00081336 OEM specific: Parameter was not reset only on edge detection
 *          2015-02-18 visefa       ESCAN00081337 OEM specific: Signal regarding CAN communication was not reset properly
 *          2015-02-18 visefa       ESCAN00081338 OEM specific: Error event not correctly reported to application
 *          2015-02-20 visefa       ESCAN00081389 DC_EVSEChargeParameter were reported before EVSEProcessing == Finished
 * 06.03.00 2015-02-27 visefa       ESCAN00081514 Added support for SLAC handling
 * 06.03.01 2015-03-09 visefa       ESCAN00081668 Reworked NvM handling
 * 06.03.02 2015-03-17 visefa       ESCAN00081865 SLAC doesn't start after Firmware Download since QCA is not responding
 * 07.00.00 2015-04-01 visefa       ESCAN00082090 Added support for Tp_TcpIp API of MSR4R12 and higher
 *          2015-05-11 visefa       ESCAN00082930 OEM specific: Update of implementation to latest spec (2015-04-22)
 *          2015-06-08 visefa       ESCAN00083287 OEM specific: Issue during restart after error in SAP
 *          2015-06-08 visefa       ESCAN00083288 OEM specific: Issue during conversion of ChargingProfile
 *          2015-06-30 visefa       ESCAN00083734 OEM specific: Error event not correctly reported to application
 *          2015-07-15 visefa       ESCAN00084009 Incorporated findings of review
 * 07.00.01 2015-07-20 visefa       ESCAN00084090 Obsolete DET error occurs periodically
 * 07.00.02 2015-07-23 visefa       ESCAN00084190 OEM specific: Update of customer requirement
 * 07.00.03 2015-08-13 visefa       ESCAN00084513 OEM specific: Provisioning Data is not always being sent automatically
 * 07.01.00 2015-08-31 visefa       ESCAN00084887 OEM specific: ChargingProfile can now be stored in internal SCC buffer
 *          2015-08-28 visefa       ESCAN00084838 OEM specific: Provisioning Data API keeps returning E_PENDING
 *          2015-09-11 visefa       ESCAN00085007 MSR4: Scc_Cbk_TL_TCPAccepted callback was removed
 *          2015-09-11 visefa       ESCAN00084956 CPS check is not working
 * 07.01.01 2015-10-13 visefa       ESCAN00085826 OEM specific: ChargingStatus stop condition not met
 *          2015-10-13 visefa       ESCAN00085827 OEM specific: Requirement change of SessionStop error handling
 * 08.00.00 2015-11-20 visefa       ESCAN00086647 OEM specific: Update of implementation to latest spec (2015-10-08)
 *          2015-11-20 visefa       ESCAN00086648 Introduction of Scc_ReturnType
 *          2015-11-20 visefa       ESCAN00086643 Compiler error: ASR4 APIs of TcpIp used for ASR3
 *          2015-11-24 visefa       ESCAN00086707 Extended StackError enumeration by Request(Not)Acknowledged
 *          2016-01-14 visefa       ESCAN00087057 PrivKeys of ContrCert and ProvCert are only read when required
 *          2016-01-14 visefa       ESCAN00087378 SCC keeps trying to decode received response after a decode error
 *          2016-01-14 visefa       ESCAN00087465 OEM specific: SalesTariff without duration element is not being accepted
 *          2016-02-03 visefa       ESCAN00088041 Source of configuration is now configurable
 *          2016-02-03 visefa       ESCAN00088042 OEM specific: Update of implementation to latest spec (2016-02-01)
 *          2016-02-16 visefa       ESCAN00088324 OEM specific: PnC is selected for resumed session even if TLS is not used
 *          2016-02-16 visefa       ESCAN00088325 OEM specific: Single phase not selected if only three phase offered
 * 08.00.01 2016-04-21 visefa       ESCAN00089647 OEM specific: Incorrect calculation of timeouts
 * 08.01.00 2016-06-21 visefa       ESCAN00090581 Configure parameter reporting during EVSEProcessing(Ongoing)
 *          2016-06-24 visefa       ESCAN00090652 OEM specific: Update of implementation to latest spec (2016-05-20)
 *          2016-06-24 visefa       ESCAN00090652 Introduced EMAID validation during CertInstallation & CertUpdate
 *          2016-07-04 visefa       ESCAN00090812 OEM specific: Added Ethernet Test Mode
 * 08.01.01 2016-07-11 visefa       ESCAN00090928 OEM specific: MessageSet selection via SupportedMessageSet not working
 * 08.01.02 2016-08-29 visefa       ESCAN00091627 OEM specific: Compiler error: Pre-processor defines not set correctly
 * 09.00.00 2016-07-18 visefa       ESCAN00090914 Added support for Tp_TcpIp API of MSR4R15 and higher
 *          2016-07-18 visefa       ESCAN00091045 Removed 'V' prefix from internal functions
 * 09.01.00 2016-10-07 visefa       ESCAN00092040 Local static variable used that cannot be mapped using MemMap.h
 *          2016-10-07 visefa       ESCAN00092047 Variable in ZERO_INIT section has no value assignment
 *          2016-12-05 visefa       ESCAN00092926 Empty RootCertificateID sent if not all root cert slots filled
 *          2016-12-05 visefa       ESCAN00092814 TCP FIN cannot be transmitted in case SCC message timeout expires
 *          2016-12-05 visefa       ESCAN00092681 Wrong ResponseCodes are stored in error bit environment data
 *          2016-12-05 visefa       ESCAN00092923 Command to open S2 is sent too early
 *          2016-12-06 visefa       ESCAN00092919 Add option to block V2G communication
 *          2016-12-07 visefa       ESCAN00092842 Add separate MemMap.h sections for NvM RAM/ROM variables/constants
 *          2016-12-07 visefa       ESCAN00093202 OEM specific: Increased signal size
 *          2016-12-07 visefa       ESCAN00092920 eMAID check fails if '-' is used in eMAID
 * 09.02.00 2017-01-16 visefa       ESCAN00093559 OEM specific: Updated RTE wrapper (2017-01-13)
 *          2017-01-16 visefa       ESCAN00093564 OEM specific: EVEnergyCapacity is not sent with the correct Unit value
 *          2017-01-25 visphh       ESCAN00093440 Remove monitoring of TxConfirmation
 *          2017-02-01 visphh       ESCAN00093788 OEM specific: Timeout after ChargeParameterDiscoveryRes
 *          2017-02-02 visphh       ESCAN00093202 EAmount can now handle a uint32
 * 09.03.00 2017-03-22 visphh       ESCAN00092165 Support of Dynamic Length in CopyTxData in TcpIp
 *          2017-03-22 visphh       ESCAN00094084 Return value of EthTrcv_30_Ar7000_Slac_Start() is not evaluated
 * 09.03.01 2017-03-22 visphh       ESCAN00093554 The check for the EVSEMaximumPowerLimit can now be disabled
 * 09.04.00 2017-05-10 visphh       ESCAN00095100 OEM specific: Updated RTE wrapper (2017-05-09)
 * 09.04.01 2017-05-11 visphh       ESCAN00095119 Changed handling of ForceReset in Scc_ResetSessionID
 * 09.05.00 2017-05-29 visphh       ESCAN00095336 Scc_ConfigValue_StateM_AcceptUnsecureConnection undeclared identifier
 *          2017-05-29 visphh       ESCAN00094843 SCC wants to restart without SLAC even if no link is available
 *          2017-06-06 visphh       ESCAN00095186 Compiler warning: comma at end of enumerator list
 *          2017-07-04 visphh       ESCAN00095008 OEM specific: Component TLS can not process other users in addition to component SCC
 *          2017-07-03 visphh       ESCAN00095709 XmlSec_ReturnType is now an enumeration instead of a uint8 using defines
 *          2017-07-12 visefa       ESCAN00095558 OEM specific: RemainingTimeToFullSoC is not sent in case of DIN SPEC 70121
 *          2017-07-12 visefa       ESCAN00095549 OEM specific: Update of implementation to latest spec (2017-04-07)
 *          2017-07-12 visefa       ESCAN00095158 OEM specific: Random values are being sent when CAN signal is SNA
 *          2017-07-12 visefa       ESCAN00095431 OEM specific: PnC is selected instead of EIM
 *          2017-07-12 visefa       ESCAN00095440 Added SessionID to the parameter interface
 *          2017-07-12 visefa       ESCAN00095539 Added V2GRequest and V2GResponse to the parameter interface
 *          2017-07-12 visefa       ESCAN00095161 Invalid SECCDiscoveryProtocolRes are not ignored
 *          2017-07-12 visefa       ESCAN00094502 OEM specific: PCID can't be read from Provisioning Certificate
 *          2017-07-03 visphh       ESCAN00095706 Add CSM (ASR4.3) Support
 *          2017-07-31 visphh       ESCAN00096116 No report of SLAC failure and ReadRootCerts failure via Scc_StackError
 * 09.05.01 2017-08-30 visphh       ESCAN00096485 OEM specific: DIN EVSEProcessing Callback returns RTE-Error
 * 09.06.00 2017-09-07 visphh       STORYC-2437   Extend Scc_GetCertDistinguishedNameObject() for Subject_DomainComponent
 *          2017-09-12 visphh       STORYC-2465   Report Scc_ReportError if Scc_MsgTrig is Scc_MsgTrig_None
 *          2017-09-13 visphh       ESCAN00096642 Function Scc_ChangeProvCertPrivKeyPassword() returns Pending instead of Busy
 *          2017-09-14 visphh       STORYC-2490   Add Callback to report an unknown leaf certificate during TLS handshake
 * 09.06.01 2017-09-21 visphh       ESCAN00096762 Scc_CheckForCpoInDc only available for PnC
 * 10.00.00 2017-09-26 visphh       ESCAN00096831 Write ContractCertificatePrivateKey via Scc_DiagDataWriteAccess() fails
 *          2017-10-06 visphh       ESCAN00096939 Reconnection after CommunicationSetupTimeout if transceiver link was down
 *          2017-10-11 visphh       ESCAN00096996 CertificateInstallation fails if CSM is enabled
 *          2017-11-08 visphh       STORYC-1215   Support TCP/IP API according to ASR (CopyTxData)
 *          2017-11-09 visphh       ESCAN00097342 Removed ASR3 support
 *          2017-11-09 visphh       ESCAN00097162 EMAIDs with a length of 14 bytes cannot be processed
 *          2017-11-13 visphh       ESCAN00097318 OEM specific: Report InvalidTxParameter instead of InvalidRxParameter
 *          2017-11-13 visphh       ESCAN00097320 OEM specific: Used unsigned values instead of signed for Min Max Values
 *          2017-11-13 visphh       ESCAN00097322 OEM specific: Update Rx/Tx-Interface
 *          2017-11-16 visphh       ESCAN00097436 SCC needs Crypto_Types.h if CSM is enabled
 * 10.01.00 2017-12-19 visphh       ESCAN00097796 OEM specific: Wrong maximum value saturation for ISO_DC_EVSEPresentVoltage
 *          2017-12-20 visphh       ESCAN00097816 Missing memory mapping
 *          2017-12-20 visphh       ESCAN00097818 Scc_StateM_TrcvLinkState is not initialized in Scc_StateM_InitMemory()
 *          2017-12-20 visphh       ESCAN00097819 Missing check if TcpRxData fits in Scc_ExiStreamRxPBuf
 *          2017-12-20 visphh       ESCAN00097820 Missing conditions for SLAC failure
 *          2018-01-09 visphh       STORYC-3814   Added Scc_Cbk_SLAC_FirmwareDownloadStart
 *          2018-01-09 visphh       ESCAN00096232 Certificates cannot be loaded properly after being installed via API
 *          2018-01-09 visphh       ESCAN00096184 SCC does send messages with session ID set to 0 in the mid of a session
 *          2018-01-10 visphh       STORYC-2788   Support Wireless Power Transfer (WPT) according to ISO/IEC 15118 ED2 CD2
 *          2018-01-19 visphh       ESCAN00098066 Scc sends invalid V2GTP header
 * 10.01.01 2018-01-22 visphh       ESCAN00098078 OEM specific: Undeclared identifier - Scc_ServiceID_Internet/Certificate
 * 10.01.02 2018-02-01 visphh       ESCAN00098253 Scc_DeleteRootCert() does not return E_NOT_OK if RootCertIdx is invalid
 *          2018-02-09 visphh       ESCAN00098348 Compiler error: undeclared identifier Scc_ExiRx_ISO_MsgPtr (CSM & ISO Ed2)
 *          2018-02-13 visphh       ESCAN00098378 OEM specific: ContrCertInstallTrigger failed - XmlSec WS is not initialized
 *          2018-02-19 visphh       ESCAN00098442 Compiler error: Macro P2CONST does not take 1 argument
 *          2018-02-19 visphh       ESCAN00098441 Compiler warning: unreferenced parameter BufIdxPtr
 *          2018-02-19 visphh       ESCAN00098440 Compiler warning: unreferenced parameter PrivKeyLen/PrivKeyPtr
 * 11.00.00 2018-04-13 visphh       STORYC-3886   Code Refactoring and CDD (Proc3.0)
 *          2018-05-02 visphh       STORYC-3520   Remove Crypto Legacy support. Support only CSM (ASR4.3)
 *          2018-06-13 visphh       ESCAN00099678 Compiler error: ETHTRCV_30_AR7000_SLAC_E_UNKNOWN_STATE is undefined
 *          2018-07-02 visphh       ESCAN00099844 Scc triggers the Tcp to send more data than expected.
 *          2018-07-02 visphh       ESCAN00099796 OEM specific: Wrong SessionID in ServiceDiscoveryReq
 *          2018-08-01 visphh       ESCAN00098360 Compiler error: undefined symbol "Scc_ValidateKeyPair"
 *          2018-08-06 visphh       ESCAN00099799 OEM specific: Incorrect multiplier for EVSEMaximumPowerLimit and EVSEEnergyToBeDelivered
 *          2018-08-07 visphh       ESCAN00097794 SupportedSAPSchemas - Out of bounds array access (corrupt stack)
 *          2021-12-15 visdss       ESCAN00101398 E_OK is returned for invalidly selected Contract Certificate
 * 11.01.00 2018-08-15 visphh       STORYC-6027   OEM specific: Improve process for OEM Add-On
 *          2018-08-20 visphh       ESCAN00100370 Scc does not send SessionStop after ResponseCode "FAILED" was received
 *          2018-08-24 visphh       ESCAN00100511 Scc does not report DEM-ErrorStatusFailed for SCC_DEM_IP_BASE
 *          2018-08-28 visphh       ESCAN00100551 Incorrect message status if SLAC failed
 *          2018-08-29 visphh       ESCAN00100558 OEM specific: Incorrect handling of EVMaximumVoltageLimit for DIN charging
 *          2018-08-29 visphh       ESCAN00100575 Scc reports SLAC failed for ETHTRCV_30_AR7000_SLAC_E_REMOTE_AMP_MAP_RCVD
 * 12.00.00 2018-09-06 visphh       STORYC-1410   Update AC and DC charging according to DIS of ISO/IEC 15118 ED2
 *          2018-09-06 visphh       STORYC-1412   Support Bidirectional Power Transfer (BPT) according to ISO/IEC 15118 ED2
 *          2018-09-06 visphh       STORYC-6588   OEM specific: Improve process for OEM Add-On
 *          2018-09-17 visphh       ESCAN00100767 ServiceDetail will not stop if PnC is disabled
 *          2018-09-20 visphh       ESCAN00100768 Scc fails checking CPO in SECC Certificate if PnC is disabled
 *          2018-09-27 visphh       STORYC-6592   Update WPT according to DIS of ISO/IEC 15118 ED2
 *          2018-10-08 visphh       ESCAN00100959 OEM specific: TLS leaf certificate is not allways reporterd via callback
 *          2018-11-08 visphh       ESCAN00101169 OEM specific: Scc does not detect invalid value of multiplier (3..-3)
 *          2018-11-13 visphh       ESCAN00101315 OEM specific Compiler error: Tx_s_valNorm_HlcScc should be Rx_s_valNorm_HlcScc
 *          2018-11-13 visphh       STORYC-6588   OEM specific: Migration from ASR3 to ASR4
 *          2018-11-23 visphh       STORYC-7136   Changed ISO/DIN to Scc_PhysicalValueType
 *          2018-12-02 visphh       ESCAN00101482 Scc ignores missing reference in SignedInfo
 * 12.01.00 2018-12-20 visphh       ESCAN00101633 OEM specific: Scc does not forward maximum value for sint16-value if received parameter is invalid
 *          2019-01-29 visphh       STORYC-6031   OEM specific: Improve process for OEM Add-On
 *          2019-01-30 visphh       ESCAN00101768 OEM specific: Scc_ExiRx_ISO_CertificateInstallationRes() is not defined
 *          2019-02-01 visphh       ESCAN00101658 Scc reports error if Tcp buffer is not available
 *          2019-02-07 visphh       ESCAN00102041 Scc_SessionIDNvm is not mapped to SEC_VAR_ZERO_INIT_8BIT_NVM
 *          2019-02-08 visphh       ESCAN00102044 Scc_ValidateProvCertKeyPair() uses private key of contract certficate
 * 12.01.01 2019-02-19 visphh       ESCAN00102182 SLAC starts again after DLink is ready
 *          2019-02-20 visphh       ESCAN00102189 Scc_DiagDataWriteAccess returns NotOk for the PrivateKey of ContractCertificate or ProvisioningCertificate
 *          2019-02-25 visphh       STORYC-7773   Add callback for ServiceCategory (DIN)
 * 12.02.00 2019-03-04 visphh       ESCAN00094838 OEM specific: Add the SLAC assoc status call back
 *          2019-03-06 visphh       ESCAN00102370 ECU gets stuck or resets occurs unexpectedly due to a null pointer exception
 *          2019-03-07 visphh       ESCAN00102203 OEM specific: Incorrect mapping of Scc_StateMachineStatus to RTE-Value StMacSts1
 *          2019-03-11 visphh       STORYC-6829   OEM specific: Update Add-On according to SPECDOC46254
 * 13.00.00 2019-03-20 visphh       STORYC-7983   Add CBK SDPTransportProtocol and enabled CallOut for DemReport-API
 *          2019-04-05 visphh       ESCAN00102745 DIN: Scc does not send SessionStopReq after PreCharge completed and ChargingControl is StopCharging
 *          2019-04-09 visphh       ESCAN00102726 DIN: Scc starts ReadyToChargeTimer not after DutyCycle 5% is reached
 * 13.01.00 2019-04-17 visphh       ESCAN00102804 OEM specific: Scc reports error InvalidRxParameter if ContractCertificate is not available
 *          2019-04-30 visphh       STORYC-7469   Support new CSM API according to ASR4.4 to securely install Private Key of Contract Certificate
 *          2019-05-06 visphh       ESCAN00103013 CertificateInstallationUpdate fails if last SccRootCertConfig container is empty
 * 14.00.00 2019-09-10 visdyb       STORYC-8371   Changed to MISRA2012
 *          2019-09-10 visphh       ESCAN00104256 OEM specific: Memory access out of bounds for 'Value Added Services'
 *          2019-09-17 visphh       ESCAN00103379 Scc_StateM_GlobalParamsChecks case Scc_ChargingControl_StopCharging does not work for all messages
 *          2019-09-19 visphh       V2G-235       Continue operation in case of invalid root certificates
 *          2019-09-19 visphh       V2G-264       Search String in DomainComponent(Subject) of TLS-LeafCertificate
 *          2019-09-23 visphh       ESCAN00103794 OEM specific: s_blTupelErhalten_SccHlc is always reported TRUE, even when SAScheduleList is missing
 *          2019-09-23 visphh       ESCAN00103819 OEM specific: PKCS7 containers are not only validated against OEM Root Certificate
 *          2019-09-23 visphh       ESCAN00103633 OEM specific: Signature Check of SalesTariff is not disabled in case Provisioning Certificate is used as Contract Certificate
 *          2019-09-23 visphh       ESCAN00103846 Scc reports error InvalidRxParameter if ContrSubCert1's public key is invalid
 *          2019-09-23 visphh       ESCAN00103778 OEM specific: eMAID check fails when ProvisioningCertificate is used as ContractCertificate
 *          2019-09-23 visphh       ESCAN00103845 OEM specific: Incorrect private environment is reported to the application
 *          2019-09-23 visphh       ESCAN00103478 OEM specific: TLS-check for DomainComponent(Subject) fails for private environment
 *          2019-09-23 visphh       ESCAN00103842 OEM specific: RTE wrapper reports an error in case of invalid / out of bounds value instead of only limiting the output value
 *          2019-09-24 visphh       ESCAN00103661 SalesTariff is not ignored when signature is missing or invalid
 *          2019-09-24 visphh       ESCAN00103610 Multiple domainComponent entries are not supported
 *          2019-09-25 visphh       V2G-1         OEM specific: Update according to SPEC
 *          2019-09-25 visphh       V2G-3         Increase interoperability of SAP for DIN SPEC 70121 SECCs
 * 14.01.00 2019-10-08 visdss       V2G-96        [V2G] Implement SLAC as an independent module - vScc
 * 14.01.01 2019-10-15 visdss       ESCAN00104675 Compiler error: Cannot open include file: 'Slac.h'
 *          2019-10-18 visdss       V2G-284       Scc modifications due to Slac interface changes
 * 15.00.00 2019-11-15 visphh       ESCAN00103715 TCP Connection is never closed when Server never sends a FIN
 *          2019-11-20 visphh       ESCAN00104813 Tls connection establishment with deleted root certificate
 *          2019-11-25 visphh       V2G-345       Added switch for EVSEMaxCurrent (PnC-AC)
 *          2019-11-27 visphh       ESCAN00104929 Error reported for reset-event from TCP
 *          2019-12-03 visdyb       V2G-12        [V2G] Support asynchronous usage of the CSM API for ECDSA
 *          2019-12-18 visdss       V2G-291       [V2G] Support OppCharge
 *          2020-01-08 visphh       ESCAN00105297 Compiler error: 'Scc_State' uses conflicted section name
 *          2020-01-08 visphh       ESCAN00105294 PnC will not be used in case of a free charging service
 *          2020-01-10 visphh       ESCAN00105330 DIN: Wrong SessionID in SessionStopReq after SessionSetupRes FAILED
 *          2020-01-10 visphh       ESCAN00105333 DIN: Scc does not send SessionStopReq after SessionSetupRes FAILED
 * 15.01.00 2020-02-04 visphh       ESCAN00105486 Second signature is not checked for synchronous CsmJobs
 *          2020-02-12 visphh       ESCAN00105525 DIN: Missing Units in PhysicalValues are not accepted by EVSE
 *          2020-02-12 visphh       ESCAN00105468 OEM specific: SAScheduleTupleID not provided to application via RTE
 *          2020-02-13 visdyb       ESCAN00105500 Client random and master secret not sent in specified format
 *          2020-02-20 visdss       V2G-457       [CHARGE] Allow configuration of TLS usage during runtime
 *          2020-02-24 visdyb       ESCAN00105565 Contract certificate private key is not deleted in the API Scc_DeleteContract
 *          2020-03-02 visdyb       ESCAN00105768 TCP Socket State reported in wrong order
 *          2020-03-04 visdyb       ESCAN00105457 Accepts more data than it was defined in the V2GTP-Header (PayloadLength)
 *          2020-03-04 visdyb       ESCAN00107606 DIN: Messages with V2GTP.PayloadLength=0 are discarded
 *          2021-10-08 visdyb       ESCAN00110189 Propagation of unpredictable SECC Discovery Protocol response information
 * 16.00.00 2020-03-17 visdyb       ESCAN00105770 OEM specific: Fetching certificates from an empty PKCS#7 container fails
 *          2020-03-17 visdyb       ESCAN00105875 Compiler warning: Least data type conversion may lead to data loss
 *          2020-04-02 visdyb       ESCAN00106027 MISRA and PCLint warnings when using self assigned dummy statement
 *          2020-04-07 visdyb       ESCAN00106064 Callback V2GRequest reports wrong length information
 * 17.00.00 2020-04-16 visdyb       ESCAN00106124 Out of sequence message may lead to invalid memory access
 *          2020-04-20 visdyb       V2G-459       [SEC][IDPS] IdsM: Support reporting of security events by vSCC
 *          2020-04-24 visdyb       V2G-474       [V2G] Support detailed reporting of errors - vSCC
 * 17.01.00 2020-05-25 visdss       V2G-278       [CHARGE] Support runtime selection of Ethernet interface
 *          2020-05-27 visdyb       ESCAN00106451 Sequence performance timeout is not correctly monitored
 *          2020-06-03 visdyb       ESCAN00106507 Compiler warning: IdsM_SetSecurityEvent - too many parameters
 * 17.01.01 2020-08-04 visdyb       ESCAN00106815 V2G_EVCC_CableCheck_Timeout measured wrong
 *          2020-08-07 visdyb       ESCAN00106915 DIN: Connection not closed if inverse version in V2GTP header is wrong
 *          2020-08-07 visdyb       ESCAN00106917 DIN: Charging is not stopped in time to meet conformance test requirements
 *          2020-08-10 visdyb       ESCAN00106692 Error handling not done for invalid SchemaId
 *          2020-08-25 visdyb       ESCAN00107195 V2G_EVCC_PreCharge_Timeout measured wrong
 * 17.01.02 2020-09-09 visdss       ESCAN00107109 OppCharge: No cable check request is sent
 *          2020-09-09 visdss       ESCAN00106959 Scc_DiagDataReadAccess returns PENDING if no sub contract certificate is available
 *          2020-09-10 visdss       ESCAN00107179 IP connection establishment without Slac being executed
 *          2020-09-17 visdyb       ESCAN00107355 Scc does not update Scc_MsgStatus if communication is shutdown by sending a FIN and an EVSE then sends a RST instead of FIN or transport layer timeout is reached
 * 18.00.00 2020-09-30 visdyb       V2G-1019      Implement Opp Charge testcases to cover at least all Opp Charge specific requirements
 *          2020-09-30 visdyb       ESCAN00107289 OppCharge: SessionStopReq may not be sent in any communication state in case of an error
 *          2020-09-30 visdyb       ESCAN00107442 OppCharge: Missing functionality
 *          2020-10-07 visdyb       ESCAN00107326 OppCharge: Charging session is aborted while disconnecting the pantograph
 *          2020-10-13 visdyb       ESCAN00107242 Usage of Scc in combination with CSM in interrupt mode may lead to data inconsistency in Scc_CsmJobInfo
 *          2020-10-13 visdyb       ESCAN00107243 Usage of Scc in combination with network stack in interrupt mode may lead to data inconsistency
 *          2020-10-16 visdyb       ESCAN00107635 Compiler warning: Wrong datatype in template function Appl_SccCbk_Get_ISO_SelectedServiceListPtr
 *          2020-10-16 visdyb       V2G-1037      [V2G][ETH] Support indirect CSM access
 * 19.00.00 2020-10-26 visdyb       ESCAN00107244 Scc application in conjunction with preemptive tasks may lead to data inconsistency
 *          2020-10-26 visdyb       ESCAN00107712 Compiler error: Variable numOfBytesAvailable not declared
 *          2020-10-27 visdyb       ESCAN00107530 PayloadType of V2GTP entity not checked correctly
 *          2020-10-28 visdyb       V2G-869       Create new statemachine handling (Without any messages)(Basic)
 *          2021-02-09 visdyb       V2G-983       Rework DIN for new statemachine handling (Addon) - Part1
 *          2021-02-09 visdyb       V2G-1172      Rework DIN for new statemachine handling (Addon) - Part2
 *          2021-02-09 visdss       V2G-1270      Rework ISO-2 for new statemachine handling (Addon) - Part2
 *          2021-02-21 visdss       V2G-1311      Parallel message handling (Without any messages)(Addon) - Part1
 *          2021-02-21 visdss       V2G-881       Parallel message handling (Without any messages)(Addon) - Part2
 *          2021-02-21 visdss       V2G-430       [CHARGE] Use AUTOSAR TLS Client instead of vTLS - vScc - Part1 - Development
 *          2021-02-22 visdyb       ESCAN00108266 Scc_Set_Core_V2GRequest is called more often than expected
 *          2021-02-16 visdyb       V2G-598       [CHARGE] vSCC uses KeyM for Certificate Management
 *          2021-03-17 visdyb       V2G-1297      [CHARGE] Support HPC1 Service defined by CharIN
 *          2021-03-22 visdss       V2G-437       Scc Impl&Design: Rework Scc_MsgStates (Tx Path)
 *          2021-09-14 visdyb       ESCAN00107644 API Scc_LoadAllCertificates must be called multiple times to perform the described action
 *          2021-09-14 visdyb       ESCAN00107795 Certificate Installation/Update fails due to an issue while verifying the provisioning chain
 *          2021-09-14 visdyb       ESCAN00108264 Last certificate of a certificate chain is not checked for expiration
 *          2021-09-14 visdyb       ESCAN00108026 Subsequent calls to the API Scc_ValidateContrCertKeyPair() may validate invalid certificate data
 *          2021-09-14 visdyb       ESCAN00109504 Scc_ValidateCertChain() may return old results and skip certificates using a synchronous CSM verify API
 *          2021-09-14 visdyb       ESCAN00110219 Unpredictable behavior due to to unchecked ContractIdx parameter in Scc_DeleteContract
 *          2021-10-14 visdss       ESCAN00108270 Wrong EMAID in payment details request after successful certificate update when EMAID validation is disabled
 *          2021-10-20 visdyb       ESCAN00110205 ISO 15118-2 Contract certificate chain with missing Sub-Ca certificate accepted
 *          2021-10-20 visdyb       ESCAN00108516 DIN70121: Scc establishs a V2G Communication Session with CP state not set to state B
 *          2021-11-30 visiay       ESCAN00108501 DIN70121: Scc_StateM overwrites V2G header error information if StopCharging is set by application
 *          2021-11-30 visiay       ESCAN00107577 Certificate Update -  Scc stores invalid private key
 *          2021-12-02 visiay       ESCAN00108444 Scc_StateM overwrites timeout error information if StopCharging is set by application
 *          2021-12-14 visdss       ESCAN00108518 DIN70121: Scc does not shutdown communication when requested by EVSE
 *          2022-02-24 visdyb       ESCAN00110591 Compiling error due to missing type def when Tls is enabled but XML Security is disabled
 *          2022-02-24 visdyb       ESCAN00111059 Invalid public key element length of a certificate is not properly handled
 *          2022-02-24 visdyb       ESCAN00110230 Out of bounds read access may occur in Scc_DiagDataWriteAccess
 *          2022-02-24 visdyb       ESCAN00110186 E_OK being returned if only partial data could be handled
 *          2022-02-24 visdyb       ESCAN00110643 BER object Tag numbers not evaluated
 *          2022-02-25 visdyb       ESCAN00110183 Unpredictable behavior due to integer underflow while validating certificate chain
 *          2022-02-25 visdyb       ESCAN00108435 NvM_GetErrorStatus is not called before NvM_WriteBlock
 *          2022-02-25 visdyb       ESCAN00110265 DIN70121: Not waiting for response if application is requesting StopCharging while handling cyclic messages
 *          2022-03-29 visdyb       ESCAN00111336 DIN 70121: SessionStop may be send even if no SessionSetupReq was sent
 * 19.01.00 2021-04-26 visdyb       V2G-1592      ISO-20 FDIS: SupportedAppProtocol (Preparation)
 *          2021-04-22 visdss       V2G-1584      ISO-20 FDIS: SECCDiscoveryProtocol - PLC only
 *          2021-04-30 visdyb       V2G-1600      ISO-20 FDIS: SupportedAppProtocol - AC changes
 *          2021-05-05 visdyb       V2G-1696      Update Slac parameters in template file
 *          2021-12-09 visdyb       ESCAN00106938 ISO15118-20 is proposed in SupportedAppProtocolReq without Tls
 * 20.00.00 2021-05-06 visdyb       V2G-1608      ISO-20 FDIS: Common messages up to ServiceDiscovery (StateM) - EIM
 *          2021-05-20 visdss       V2G-1632      ISO-20 FDIS: Common messages (ExiRx + ExiTx) - EIM
 *          2021-05-28 vissop       V2G-1616      ISO-20 FDIS: Common messages for service selection (StateM) - EIM
 *          2021-12-10 visdyb       ESCAN00106931 ServiceDetails for Internet service will always be sent in ISO15118-20
 * 20.01.00 2021-06-11 visdss       V2G-1640      ISO-20 FDIS: Common + AC specific messages (ExiRx + ExiTx) - EIM - DynamicMode
 *          2021-06-18 visiay       V2G-877       ISO-20 FDIS: DC specific messages (ExiRx + ExiTx) - EIM - DynamicMode
 *          2021-06-18 visdss       V2G-1624      ISO-20 FDIS: Common + AC specific messages (StateM) - EIM - DynamicMode
 * 20.02.00 2021-07-07 visiay       V2G-1688      ISO-20 FDIS: Common + DC specific messages (StateM) - EIM - DynamicMode
 *          2021-07-11 visdyb       V2G-1788      Update Scc for dynamic port usage of TcpIp.Tls
 *          2021-07-26 visdss       V2G-873       ISO/FDIS 15118-20: AC/DC Scheduled mode (Addon)
 *          2021-07-26 visdss       V2G-879       ISO/FDIS 15118-20: Schedule Renegotiation (Addon)
 * 20.03.00 2021-08-05 visdss       V2G-1893      Update state machine handling of msg status
 *          2021-08-10 visdyb       V2G-1914      ISO-20: Update Scc to version from 2021-07-16
 *          2021-08-10 visdyb       ESCAN00109935 TcpIp/Tls buffer wrap around not handled properly
 *          2021-08-16 visdyb       V2G-885       ISO/FDIS 15118-20: BPT for AC & DC charging
 *          2021-08-17 visdyb       V2G-1360      Support the new TpcIp.Tls event "TCPIP_TLS_HANDSHAKE_SUCCEEDED"
 * 20.04.00 2021-09-07 visiay       V2G-1943      Use state machine APIs to set the message trigger
 *          2021-09-13 visdss       V2G-1899      ISO-20: Update dynamic configurable parameters - trunk
 *          2021-09-13 visdss       V2G-1820      Update Scc to use the TcpIp_GetAvaiableTxBufferSize() API
 *          2021-09-17 visdss       V2G-1814      Update Scc for new validation callback of TcpIp.Tls
 *          2022-03-29 visdyb       ESCAN00111451 ISO/IEC 15118-2 "Push button mode" may lead to termination of Tls handshake
 * 20.05.00 2021-09-28 visiay       V2G-2041      ISO-20 FDIS: Support pause mechanism
 *          2021-10-12 visiay       V2G-2400      ISO-20 FDIS: Support resume mechanism
 *          2021-10-14 visdss       ESCAN00108404 Certificate validity not checked correctly
 *          2021-10-14 visdss       ESCAN00108268 Invalid contract certificate chain being used after certificate update
 *          2021-10-14 visdyb       ESCAN00109988 RTE values propagated by Scc may be compiler dependent
 *          2021-10-14 visdyb       ESCAN00110119 Unpredictable behavior when receiving multiple responses to a single request
 *          2021-10-14 visdyb       ESCAN00110207 Unpredictable behavior due to integer overflow when processing received data
 *          2021-10-18 visdss       ESCAN00108704 ISO15118-2: SessionStop sent even when PowerDeliveryReq with ChargeProgess set to Stop is not sent
 *          2021-10-19 visiay       ESCAN00110180 Missing DET checks leading to null pointer dereferencing
 * 20.06.00 2021-11-03 visdyb       V2G-2217      Provide an API to process a CertificateInstallationRes message to install certificates
 *          2021-11-05 visdyb       ESCAN00110635 Potential namespace conflict may lead to compile issue
 *          2021-11-15 visiay       ESCAN00108394 DIN70121: [V2G-DC-171] not fulfilled
 *          2021-11-18 visdss       ESCAN00110770 Values of SccDetailedError are used multiple times
 * 21.00.00 2021-11-29 visdyb       V2G-1561      [CHARGE] vSCC uses KeyM for Certificate Management - Production
 *          2021-12-03 visiay       ESCAN00109916 DIN70121: ReadyToCharge Timer is monitored without an active charging session
 *          2021-12-07 visdyb       V2G-2664      Remove OPP Charge for a clean QM release
 *          2021-12-08 visdyb       ESCAN00110575 ISO15118-2 Certificate pre-loading may be skipped
 *          2021-12-09 visdyb       ESCAN00110925 Compiler warning: Local variable appProtocolPtr used before initialization in API Scc_SAP_ExiTx_BuildReqMessage()
 *          2021-12-10 visdyb       ESCAN00109875 ISO15118-2 [V2G-846] not fulfilled
 *          2021-12-14 visdyb       ESCAN00110204 Unpredictable behavior due to buffer overflow while parsing the Issuer element of a root certificate
 * 21.01.00 2022-01-07 visdss       V2G-2228      Allow V2GTP payload to be bigger than the contained EXI stream
 *          2022-01-13 visdyb       V2G-2759      Inform Application about Remaining Contract Validity
 *          2022-01-18 visdyb       V2G-1979      Usage of <Mip>_MemMap
 *          2022-01-24 visdyb       V2G-2299      Usage of 64 bit timestamp
 *          2022-01-31 visdyb       V2G-2556      OEM specific: Update of implementation to latest spec (v12)
 *          2022-01-31 visdyb       V2G-2564      OEM specific: Remove unsopported features
 *          2022-01-31 visdyb       ESCAN00108930 OEM specific: Already sent ServiceDetailReq message is repeated
 *          2022-02-04 visdyb       ESCAN00110226 OEM specific: RTE values propagated by Scc may be compiler dependent
 *          2022-02-04 visdyb       ESCAN00109532 OEM specific: Variable Scc_Rte_CyclicMsgTrig is used without initialization
 *          2022-02-07 visdyb       ESCAN00111186 ISO15118-2: Certificate installation or update for short chain configurations may fail
 * 22.00.00 2022-02-22 visdss       V2G-1190      Enhance IpAssigned handling to handle Assigned/OnHold/Unassigned
 *          2022-02-22 visdyb       V2G-1648      Support of customizable ISO 15118-2 service selection process
 *          2022-02-24 visdyb       V2G-1648      Support of Tls session key transmission
 *          2022-02-25 visdyb       ESCAN00110493 DIN70121: ReadyToCharge timer stopped by DLink Status
 *          2022-03-02 visdyb       ESCAN00110458 ISO15118-2: Sequence Performance Timer may be started delayed
 *          2022-03-02 visdyb       ESCAN00111457 ISO/IEC 15118-2 Internet and Certificate service details are always requested if supported by EVSE
 * 22.01.00 2022-03-17 visdss       V2G-2511      Change all occurences of ISO Ed1 & Ed2 to ISO-2 & -20
 *          2022-03-29 visdyb       ESCAN00111511 Compiler error: Variable Scc_CertUpdateInstallWs undeclared
 *          2022-03-29 visdyb       V2G-1225      Prodution: ISO/FDIS 15118-20: BPT for AC & DC
 * 22.02.00 2022-04-23 visdss       V2G-3047      Add all KeyM return error values to the Scc Detailed error
 *          2022-04-28 visdyb       V2G-1225      Add all CSM return error values to the Scc Detailed error
 *          2022-05-16 visdyb       V2G-2160      ISO 15118-2: Update to new XmlSecurity supporting multiple Algorithm/DigestMethods
 *          2022-05-23 visdyb       V2G-3053      Add all XmlSecurity return error values to the Scc Detailed error
 *          2022-06-01 visdyb       ESCAN00112024 Scc forces the KeyM Det Error KEYM_E_SMALL_BUFFER during CertInstallation or CertUpdate
 * 22.03.00 2022-06-02 visiay       V2G-3200      ISO/FDIS 15118-20: Core - Implement CertificateInstallationReq
 *          2022-06-07 visdss       V2G-3202      ISO/FDIS 15118-20: Core - Implement CertificateInstallationRes
 *          2022-06-09 visdss       V2G-3222      ISO/FDIS 15118-20: Core - PnC for AuthorizationReq (No Signature)
 *          2022-06-28 visdss       V2G-3220      ISO/FDIS 15118-20: Vector StateM - PnC for Authorization
 *          2022-07-08 visdss       V2G-3218      ISO/FDIS 15118-20: Vector StateM - PnC for AuthorizationSetup
 *          2022-07-20 visdss       V2G-875       ISO/FDIS 15118-20: PnC Support multiplexed metering confirmation (no signature)
 *          2022-07-25 visdyb       ESCAN00112088 Single object type support for subject and issuer elements in certificates only
 * 23.00.00 2022-08-17 visdss       ESCAN00112488 TcpIp SocketID 255 cannot be handled
 *          2022-08-17 visdss       ESCAN00112367 Linker error: Unresolved symbol for C_DUMMY_STATEMENT_CONST
 *          2022-08-18 visdss       ESCAN00112422 NotificationMaxDelayRenegotiation timer not stopped in ISO 15118-20
 *          2022-08-18 visdss       ESCAN00112424 Timer values not initialized properly in renegotiation channel in ISO 15118-20
 *          2022-08-19 visdss       ESCAN00111958 Multiple SDRRes messages lead to DET error
 *          2022-08-22 visdss       ESCAN00112568 DIN 70121: EVSEStatusCode in charge loop set to EVSE_Shutdown leads to immediate shutdown
 *          2022-08-22 visiay       V2G-2968      Re-implement deletion of certificates
 * 24.00.00 2022-08-29 visdyb       V2G-1881      Support new XmlSecurity URI dereferencing list based approach and PublicKey handling
 *          2022-09-22 visdyb       ESCAN00112843 ISO 15118-20: OngoingTimeout not stopped in Authorization
 *          2022-09-15 visdss       V2G-3204      ISO/FDIS 15118-20: Vector StateM - CertificateInstallation handling
 * 24.01.00 2022-09-28 visdss       V2G-3565      ISO 15118-20: Ignore message element in case response code contains WARNING
 *          2022-10-04 visdss       V2G-2685      ISO-20: Add error path for Curve448 and TPM2.0 in CertificateInstallation
 * 24.02.00 2022-11-02 visdss       V2G-3255      ISO15118-20: SessionID and hash handling
 *          2022-11-08 visdss       ESCAN00113060 DIN 70121: Communication may not be stopped always in case StopCharging is requested
 *          2022-11-10 visdss       ESCAN00113129 ISO 15118-20: EVPresentVoltage of PreChargeReq may contain random value
 *          2022-11-16 visese       V2G-2226      Add ISO 15118-20 support to API Scc_ProcessCertificateInstallationRes
 * 25.00.00 2022-11-08 visdyb       V2G-3398      ISO15118-20: Impl split ISO-2 and -20 certificate handling (Multicurve)
 *          2022-12-05 visese       V2G-3661      TLS1.2 client Authentication "stub"
 * 25.01.00 2023-01-02 visdss       V2G-1848      Implement/Switch to final ECDSA curve: secp521r1
 *          2023-01-10 visdss       V2G-3224      ISO/FDIS 15118-20: Core - PnC for ScheduleExchangeRes
 * 25.02.00 2023-01-31 leisenbeis   ESCAN00113582 ISO 15118-20: EVSEProcessing not propagated in case of WARNING response code
 *          2023-01-30 visdyb       ESCAN00113481 ISO 15118-2 Scc StateMachine may abort connection when CertificateUpdate is disabled and contract expires soon
 *          2023-02-03 visdyb       ESCAN00113621 ISO 15118-2: Scc StateMachine may gets stuck when CertificateInstallation is disabled and contract is expired
 *          2023-01-24 visdyb       V2G-1174      Core: Rework OPP Charge for new statemachine handling (Addon)
 *          2023-01-24 visdss       V2G-1174      StateM: Rework OPP Charge for new statemachine handling (Addon)
 *          2023-02-06 leisenbeis   V2G-1473      Refactor Scc code
 *          2023-02-01 visdss       V2G-3343      ISO15118-20: Core - CertificateInstallationRes enhanced checks
 *          2023-02-07 viskst       V2G-2319      CAD: Migrate CAD to text-based format
 * 25.03.00 2023-02-20 visdyb       ESCAN00113851 SccDetailedError values may not be unique
 *          2023-02-16 leisenbeis   ESCAN00113861 PnC not possible if SignatureGenerate fails
 *          2023-02-17 viskst       V2G-3359      ISO15118-20: Loop/Retry unaltered messages
 *          2023-03-02 visdyb       V2G-3414      TLS 1.3: client certificates support (Preparation)
 *          2023-03-09 visdyb       ESCAN00114077 Compiler error: Scc in combination with Tls Client Auth callback enabled produces compiler error
 * 25.04.00 2023-03-09 visese       V2G-3759      Check if warning response code is handled as refined in User-Group
 *          2023-03-13 visdss       V2G-3350      ISO15118-20: StateM+Core - Implement new EMAID handling
 *          2023-03-14 visdss       ESCAN00113982 Compiler error: When ISO-20 is enabled and ISO-2 disabled
 *          2023-03-14 visdss       ESCAN00114029: ISO 15118-20 DC: Cable check timer is not stopped
 *          2023-03-17 visdss       V2G-3827      Stop timers that are started
 *          2023-03-17 visdss       ESCAN00114184 DC: Cable check and PreCharge timer is not stopped
 * 25.05.00 2023-04-04 leisenbeis   ESCAN00114314 KEYM_E_BUSY may not be handled correctly while reading OEM provisioning certificate
 *          2023-04-03 leisenbeis   ESCAN00114237 Certificate validity supports only one format but not both
 *          2023-04-01 visdyb       ESCAN00114309 Missing interrupt lock release may block ECU
 * 25.06.00 2023-03-20 viskst       V2G-946       Scc/Slac: Improve Slac handling
 *          2023-04-21 skohl        V2G-3842      OEM specific: Update of charging control between CableCheck and PreCharge
 *          2023-04-21 visdss       V2G-3936      Adapt buffer sizes for big messages
 *          2023-04-28 visdss       ESCAN00114452 KEYM_E_BUSY not handled correctly in case of CertificateInstallationRes or CertificateUpdateRes
 *          2023-04-28 visdss       ESCAN00114476 Failing KeyM_VerifyCertificate API for ROM certificates leads to aborting charging session
 * 25.07.00 2023-05-17 leisenbeis   ESCAN00114592 PaymentOption_None even if EIM and PnC was offered on a TCP connection
 *          2023-05-22 visdss       V2G-1856      ISO/FDIS 15118-20: Core - Implement PrivateKey decryption
 *          2023-05-24 visdss       ESCAN00114694 CertificateInstallation DHpublickey first byte not checked
 *          2023-05-26 visdss       ESCAN00114706 SccSchemaPriorityIso20DC is not recognized by the schema enabled validator
 *          2023-06-02 visdyb       ESCAN00114755 ISO 15118-20: Service selection may not work due to uninitialized variable
 *          2023-06-02 leisenbeis   ESCAN00114742 SLAC protocol execution cannot be stopped
 * 26.00.00 2023-05-25 skohl        V2G-1816      Scc shall use the basic OCSP handling of TcpIp.Tls
 *          2023-07-27 visdyb       V2G-2682      Check/Split: Support TLS 1.3 - Scc - trunk (Basic)
 * 26.01.00 2023-07-31 visdyb       V2G-3593      TLS 1.3: Evaluate TLS validation callout info
 *          2023-08-07 leisenbeis   V2G-2244      Add TLS 1.3 to schemata selection
 *          2023-08-02 skohl        V2G-4185      Changeable TLS handshake fields
 *          2023-08-09 visdyb       ESCAN00115306 ISO 15118-20: Scc reports invalid SessionIdLen during processing of SessionStopRes
 *          2023-08-09 skohl        V2G-4268      Update template files to support OCSP related interfaces
 *          2023-08-03 leisenbeis   V2G-4188      NotBefore/After KeyM_Get: remove death code
 *          2023-08-14 visdss       V2G-4230      ISO-2 EvseCompatibilityMode for GenChallenge and Signature of PnC AuthorizationReq
 *          2023-08-14 leisenbeis   V2G-4281      CPM4PE send root certificate related to Vehicle chain to EVSE
 * 26.02.00 2023-09-14 visdss       V2G-4362      Fix MISRA + PCLINT findings
 *          2023-06-12 visdss       V2G-4140      Add WPT specific items
 *          2023-06-23 leisenbeis   V2G-2049      ISO/FDIS 15118-20: SECC Discovery Protocol for wireless communication
 *          2023-06-20 visdss       V2G-4094      ISO15118-20 WPT message FinePositioningSetup
 *          2023-06-26 visdss       V2G-4096      ISO15118-20 WPT message FinePositioning
 *          2023-07-10 visdss       V2G-4100      ISO15118-20 WPT message ChargeParameterDiscovery
 *          2023-07-11 visdss       V2G-4190      WPT: Create WPT only test variant
 *          2023-07-03 leisenbeis   V2G-4098      ISO15118-20 WPT message Pairing
 *          2023-07-13 leisenbeis   V2G-4102      ISO15118-20 WPT message AlignmentCheck
 *          2023-07-24 leisenbeis   V2G-4194      ISO15118-20 WPT Restrict wireless SDP to WPT messages
 *          2023-07-24 visdss       V2G-4225      ReadContrCertChain before going to FinePositioningSetup in WPT
 *          2023-07-18 skohl        V2G-4104      ISO15118-20 WPT message ChargeLoop
 *          2023-09-01 skohl        V2G-4371      WPT: FinePositioningSetup Warning_Wpt
 *          2023-08-30 skohl        V2G-4106      ISO15118-20 WPT messages for renegotiation channel
 *          2023-09-01 skohl        V2G-4376      WPT: Go to pause ScheduleExchange to PowerDelivery
 *          2023-09-11 visdss       ESCAN00115635 Pause not triggered in ISO15118-20
 *          2023-09-11 visdss       V2G-4210      WPT: Pause & Resume test
 *          2023-09-14 visese       V2G-4388      ISO15118-20: Adapt certificate_authorities check
 *          2023-09-04 leisenbeis   ESCAN00110642 ISO/IEC 15118-2: Certificate validation not according to [V2G2-885] (KeyM impl required) (RFC5280)
 *          2023-10-23 visese       ESCAN00115792 Compiler error: TLS with EIM only: KeyM types are unknown
 *          2023-10-05 visdss       ESCAN00115724 Initialization/Reset of Scc_StateM_Local.RxIndicationFctPtr is missing
 *          2023-10-10 visdss       V2G-4219      ISO15118-20: Implement ServiceRenegotiation for all schemata
 *          2023-10-16 visdss       V2G-4215      Check test cases for private environment after TCPIP OCSP has been fixed
 * 26.03.00 2023-10-24 visdss       V2G-3803      ISO15118-20: Provide Certificate checks for BasicConstraints and KeyUsage
 *          2023-10-31 visdyb       V2G-3376      ISO15118-20: Certificate checks not performed by KeyM
 * 26.04.00 2023-11-23 visdyb       ESCAN00116117 Scc stopps sending PreChargeReq messages if the loop shall be left
 *          2023-10-31 leisenbeis   V2G-1850      ISO15118-20 Ed448: Signed messages
 *          2023-11-16 visdss       V2G-1858      ISO15118-20 Ed448: CertificateInstalltion support (sig + KDF)
 * 26.05.00 2024-01-02 visdss       V2G-4567      TLS1.2 NSS Key Log frame transmission moved to TcpIp
 *          2023-12-14 visdyb       V2G-4462      Add Ed448 related paths to the TLS call backs
 *          2023-12-11 skohl        V2G-1854      ISO15118-20 Ed448: Mechanism to switch EC algorithms
 * 27.00.00 2024-01-17 leisenbeis   V2G-4519      Merge WPT Interface cfg into general ISO_20 Interface cfg
 *          2024-01-15 visdyb       V2G-4713      Fix Vector Coding Rules findings related to Std_ReturnType
 *          2024-01-31 skohl        V2G-3314      Debug variable A2L support
 *          2023-12-11 visdyb       V2G-4259      Add TPM2.0 to the CertificateInstallation EncryptedPrivateKey
 *          2024-01-29 visdyb       ESCAN00116456 SECC Discovery Protocol (SDP) for wireless contains invalid values for parameter P2PS/PPD
 *          2024-02-06 visdyb       ESCAN00116643 Scc_Exi_TempBufUnion alignment error leads to a trap during runtime
 *          2024-01-29 visdss       ESCAN00116485 V2G communication is not stopped after V2G_EVCC_Ongoing_Timeout for ISO 15118-20 schema WPT
 * 28.00.00 2024-02-13 visdyb       ESCAN00100822 External issue (EVSE): SupportedAppProtocolReq handshake fails due to the data is sent within the TCP ACK frame of TCP connection handshake is discard by the EVSE
 *          2024-02-12 skohl        ESCAN00116630 SequencePerformaceTimer not checked in between SupportedAppProtocol and SessionSetup
 *          2024-02-13 skohl        ESCAN00116629 ISO 15118-20: Communication not shutdown in case Application wants to close communication in CertificateInstallation
 *          2024-02-28 skohl        V2G-4920      ISO 15118-20: Update CertificateInstallation parameters
 *          2024-01-04 visdss       V2G-1233      ISO/FDIS 15118-20: Support ACDP main channel messages
 *          2024-02-05 visdyb       V2G-4409      ISO15118-20 ACDP: Add restriction for TLS1.3 only to SupportedAppProtocol processing
 *          2024-02-06 leisenbeis   V2G-2071      ISO/FDIS 15118-20: Support ACDP System Status handling
 *          2024-02-27 visdss       ESCAN00108576 Out of bounds array access may occur during transmission if buffer is configured not appropriate
 *          2024-03-07 visdyb       V2G-1741      Create Tag 28.00.00 (including ACDP)
 *          2024-03-01 visese       V2G-4909      ISO15118-20: Update root certificates before CertificateInstallation is send
 * 28.01.00 2024-03-12 visese       V2G-4789      Add preprocessor switches for usage of Scc_MsgStatus_* and Scc_MsgTrig_*
 *          2024-03-01 skohl        V2G-4808      Fix spelling mistakes in code
 *          2024-03-05 leisenbeis   V2G-4841      Remove all payload type duplicates from Impl
 *          2024-03-15 visdss       V2G-4996      Ensure that large dynamic configuration parameters can be read out
 *          2024-03-12 visdyb       V2G-4628      Add/adapt IP assigned ON_HOLD handling and documentation
 * 28.02.00 2024-04-03 visdyb       V2G-4533      Update to latest CSM interfaces
 *          2024-04-11 visdss       ESCAN00117008 ISO 15118-2 AC EIM requirement V2G-828 not handled correctly by Scc
 *          2024-04-15 visdss       ESCAN00117120 DIN 70121: V2G-DC-649 - SessionStop after failed SessionSetup not possible
 *          2024-04-17 visdss       V2G-3587      ISO15118-20: TLS 1.3 Session Resumption with Session tickets
 *          2024-04-19 visese       V2G-5044      Adapt to new Slac_*Leave
 * 28.03.00 2024-04-25 visese       V2G-5083      Check QAC version 2023.2 on some modules
 *          2024-04-25 visese       ESCAN00117214 ISO 15118-20 PNC: Csm job info not reset after Scc reset
 *          2024-05-10 visdss       V2G-5247      Optimize transmit path to send req in single main function cycle
 * 28.04.00 2024-06-25 leisenbeis   ESCAN00117444 ISO 15118-20 WPT: SessionStopReq not sent after PowerDelivery in case of ResponseCode Warning_WPT
 *          2024-06-26 leisenbeis   ESCAN00117663 ISO 15118-20 WPT: Invalid Sequence Performance Timeout for transition to WPT_FinePositioningSetup
 *          2024-06-28 leisenbeis   ESCAN00117640 ISO 15118-20 ACDP: Possible Det error report in case parallel channel for ACDP SystemStatus is enabled.
 *          2024-07-03 leisenbeis   ESCAN00117683 ISO 15118-20 PnC: MeteringConfirmationReq may be send without Signature element instead of reporting an error.
 *          2024-07-03 visdyb       ESCAN00117554 ISO 15118-2: ServiceID in ServiceDiscoveryRes greater than sizeof Scc_ServiceIDType may not be handled correctly.
 *          2024-06-18 visdss       V2G-4900      Support of buffer pool handling
 * 28.04.01 2025-03-13 mziegler     ESCAN00119392 Scc transmits partial V2G TP headers in case of TX buffer wraparound
 *********************************************************************************************************************/
#if !defined (SCC_H)
#define SCC_H


/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Cfg.h"
#include "Scc_Lcfg.h"
#include "SchM_Scc.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Software Version */
#define SCC_SW_MAJOR_VERSION                0x28u  /* BCD coded version number */
#define SCC_SW_MINOR_VERSION                0x04u  /* BCD coded version number */
#define SCC_SW_PATCH_VERSION                0x01u  /* BCD coded version number */

/* Scc ModuleId */
#define SCC_VENDOR_ID    30u /* Vector ID */
#define SCC_MODULE_ID   255u /* Vector Module ID for Complex Device Drivers */
#define SCC_INSTANCE_ID 111u /* Vector Instance ID for SysService_SswScc */

/* Scc API IDs */
#define SCC_API_ID_MAIN_FUNCTION              0x02u /* Scc_MainFunction() */
#define SCC_API_ID_RX_INDICATION              0x03u /* Scc_Cbk_TL_RxIndication() */
#define SCC_API_ID_IP_ADDRESS_CHG_CBK         0x04u /* Scc_Cbk_LocalIpAssignmentChg() */
#define SCC_API_ID_GET_VERSION_INFO           0x05u /* Scc_GetVersionInfo() */
#define SCC_API_ID_DIAG_DATA_READ_ACCESS      0x06u /* Scc_DynConfigDataReadAccess() */
#define SCC_API_ID_DIAG_DATA_WRITE_ACCESS     0x07u /* Scc_DynConfigDataWriteAccess() */
#define SCC_API_ID_TCP_CONNECTED              0x08u /* Scc_TcpConnected() */
#define SCC_API_ID_TCP_IP_EVENT               0x0Au /* Scc_TcpIpEvent() */
#define SCC_API_ID_TCP_IP_CERT                0x0Bu /* Scc_Cbk_TLS_CertChain() */
#define SCC_API_ID_SET_LOCAL_ADDR_ID          0x0Cu /* Scc_SetLocalAddrId() */
#define SCC_API_ID_GET_CERT_CHAIN_IDX         0x0Du /* Scc_GetContractCertChainIndexInUse() */
#define SCC_API_ID_V_PRC_CERT_INST_RES        0x0Eu /* Scc_ProcessCertificateInstallationRes() */
#define SCC_API_ID_DELETE_CONTRACT            0x0Fu /* Scc_DeleteContract() */
#define SCC_API_ID_TCP_IP_CHANGE_CIPHER       0x10u /* Scc_Cbk_TLS_ChangeableCipher() */
#define SCC_API_ID_TLS_SESSION_TICKET         0x11u /* Scc_Cbk_TLS_SessionTicketInfo() */
#define SCC_API_ID_RELEASE_BUFFER             0x12u /* Scc_BufferPoolRelease() */

#define SCC_API_ID_V_TIMEOUT_HANDLING         0x21u /* Scc_TimeoutHandling() */
#define SCC_API_ID_V_CHECK_V2G_HEADER         0x23u /* Scc_CheckV2GHeader() */

#define SCC_API_ID_V_TRIG_CERTS               0x26u /* Scc_TriggerCerts() */

#define SCC_API_ID_V_CERTIFICATE_UPDATE_RES   0x44u /* Scc_ISO15118_2_ExiRx_CertificateUpdateRes() */
#define SCC_API_ID_V_CERTIFICATE_INSTALL_RES  0x45u /* Scc_ISO15118_2_ExiRx_CertificateInstallationRes() */
#define SCC_API_ID_V_EXI_WRITE_HEADER         0x48u /* Scc_Exi_WriteHeader() */

#define SCC_API_ID_V_CBK_COPY_TX_DATA         0x4Fu /* Scc_Cbk_CopyTxData() */
#define SCC_API_ID_V_POWER_DELIVERY_REQ       0x50u /* Scc_ISO15118_2_ExiTx_PowerDeliveryReq() */
#define SCC_API_ID_V_CBK_CSM_NOTIFICATION     0x51u /* Scc_Cbk_Csm_ApplNotification() */

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )
#define SCC_API_ID_V_STATEM_PREP_SERV_DETAIL  0xA2u /* Scc_ISO15118_2_StateMServiceDetail_Prepare() */
#define SCC_API_ID_V_STATEM_SET_MSG_STATUS    0xA3u /* Scc_StateM_Set_Core_MsgStatus() */
#define SCC_API_ID_V_STATEM_PROC_CHARGE_PARAM 0xA4u /* Scc_ISO15118_2_StateMChargeParameterDiscovery_Process() */
#define SCC_API_ID_V_STATEM_PROC_POW_DEL      0xA6u /* Scc_ISO15118_2_StateMPowerDelivery_Process() */
#define SCC_API_ID_V_STATEM_CORE_GET_CBK      0xA9u /* Scc_StateM_Get_Xyz_Zyx() */
#define SCC_API_ID_V_STATEM_SCHEMA_SPECIFIC   0xAAu /* Scc_StateM_SchemaSpecificState_Prepare() */
#define SCC_API_ID_V_STATEM_SETUP             0xABu /* Scc_StateM_SetupStateFunctions() */
#define SCC_API_ID_V_ISO15118_2_POW_DEL_PREP  0xACu /* Scc_ISO15118_2_StateMPowerDelivery_Prepare() */
#define SCC_API_ID_V_ISO15118_2_CHRGSTAT_PROC 0xADu /* Scc_ISO15118_2_StateMChargingStatus_Process() */
#define SCC_API_ID_V_ISO15118_2_METRECPE_PROC 0xAEu /* Scc_ISO15118_2_StateMMeteringReceipt_Process() */
#define SCC_API_ID_V_ISO15118_2_CURRDEM_PROC  0xAFu /* Scc_ISO15118_2_StateMCurrentDemand_Process() */
#define SCC_API_ID_V_STATEM_TIMER_CHECK       0xB0u /* Scc_StateM_CommonTimerChecks() */

#if ( defined(SCC_SCHEMA_DIN) && SCC_SCHEMA_DIN != 0)
#define SCC_API_ID_V_DIN70121_STATEM_SETUP           0xC0u /* Scc_DIN70121_StateMSetupStateFunctions() */
#define SCC_API_ID_V_DIN70121_STATEM_CHRGPARAM_CBK   0xC1u /* Scc_DIN70121_StateMChargeParameterDiscovery_Prepare() */
#define SCC_API_ID_V_DIN70121_STATEM_READYTOCHRG_CBK 0xC2u /* Scc_DIN70121_StateM_Get_ReadyToChargeState() */
#endif

#define SCC_API_ID_V_STATEMGENERIC_PROCESS    0xB1u /* Scc_StateMachineGeneric_StepProcess() */

#if ( defined(SCC_SCHEMA_ISO) && SCC_SCHEMA_ISO != 0)
#define SCC_API_ID_V_ISO15118_2_STATEM_SETUP              0xD0u /* Scc_ISO15118_2_StateMSetupStateFunctions() */
#define SCC_API_ID_V_ISO15118_2_STATEM_TIMER_CHECK        0xD1u /* Scc_ISO15118_2_StateMGlobalTimerCheck() */
#define SCC_API_ID_V_ISO15118_2_STATEM_ADDVASLISTENTRY    0xD3u /* Scc_ISO15118_2_VASListAddEntry() */
#endif

#if ( defined(SCC_SCHEMA_ISO_20) && SCC_SCHEMA_ISO_20 != 0)
#define SCC_API_ID_V_ISO15118_20_STATEM_SETUP               0xE0u /* Scc_ISO15118_20_StateMSetupStateFunctions() */
#define SCC_API_ID_V_ISO15118_20_STATEM_TIMER_CHECK         0xE1u /* Scc_ISO15118_20_StateMGlobalTimerCheck() */
#define SCC_API_ID_V_ISO15118_20CM_STATEM_SESSION_SETUP     0xE2u /* Scc_ISO15118_20CM_StateMSessionSetup_Process() */
#define SCC_API_ID_V_ISO15118_20CM_STATEM_PROC_POW_DEL      0xE3u /* Scc_ISO15118_20CM_StateMPowerDelivery_Process() */
#define SCC_API_ID_V_ISO15118_20CM_STATEM_SCH_EXCH          0xE4u /* Scc_ISO15118_20CM_StateMScheduleExchange_Process() */
#define SCC_API_ID_V_ISO15118_20_STATEM_RENEG_SETUP         0xE5u /* Scc_ISO15118_20_StateMReneg_SetupStateFunctions() */
#define SCC_API_ID_V_ISO15118_20_STATEM_RENEG_TIMER_CHECK   0xE6u /* Scc_ISO15118_20_StateMReneg_GlobalTimerCheck() */
#define SCC_API_ID_V_ISO15118_20_CERTIFICATE_INSTALL_RES    0xE7u /* Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes() */
#define SCC_API_ID_V_ISO15118_20_STATEM_METER_SETUP         0xE8u /* Scc_ISO15118_20_StateMMeter_SetupStateFunctions() */
#define SCC_API_ID_V_ISO15118_20_STATEM_SYSTEM_STATUS_SETUP 0xEEu /* Scc_ISO15118_20_StateMSysS_SetupStateFunctions() */
#define SCC_API_ID_V_ISO15118_20WPT_STATEM_FINE_POS         0xEDu /* Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Process() */
#define SCC_API_ID_V_ISO15118_20WPT_STATEM_FINE_POS_SETUP   0xEBu /* Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Process() */
#define SCC_API_ID_V_ISO15118_20WPT_STATEM_PAIRING          0xEAu /* Scc_ISO15118_20WPT_StateMWPT_Pairing_Process() */
#define SCC_API_ID_V_ISO15118_20WPT_STATEM_ALIGNMENT_CHECK  0xECu /* Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Process() */
#endif

#define SCC_API_ID_TCP_IP_CLIENTAUTH                       0xE9u /* Scc_Cbk_TLS_ClientAuthenticationRequest() */

#if ( defined(SCC_SCHEMA_OPP_CHARGE) && SCC_SCHEMA_OPP_CHARGE != 0)
#define SCC_API_ID_V_OPPCHARGE_STATEM_SETUP                0xF0u /* Scc_OppCharge_StateMSetupStateFunctions() */
#define SCC_API_ID_V_OPPCHARGE_STATEM_CHRGPARAM_CBK        0xF1u /* Scc_OppCharge_StateMChargeParameterDiscovery_Prepare() */
#define SCC_API_ID_V_OPPCHARGE_STATEM_READYTOCHRG_CBK      0xF2u /* Scc_OppCharge_StateM_Get_ReadyToChargeState() */
#endif

#endif /* SCC_ENABLE_STATE_MACHINE */


#define SCC_API_ID_V_CHANNEL_ENABLED          0xD2u /* Scc_Core_Channel_IsChannelEnabled() */

/* SCC DET errors */
#define SCC_DET_NO_ERROR         0x00u /* No error occurred */
#define SCC_DET_NOT_INITIALIZED  0x01u /* This module is not initialized yet */
#define SCC_DET_INV_POINTER      0x02u /* The provided pointer(s) is/are invalid */
#define SCC_DET_INV_PARAM        0x03u /* The provided parameter(s) is/are invalid */
#define SCC_DET_INV_STATE        0x04u /* The state machine ended up in an invalid state */
#define SCC_DET_EXI              0x05u /* An error occurred during an interaction with Exi */
#define SCC_DET_XML_SEC          0x06u /* An error occurred during an interaction with XmlSecurity */
#define SCC_DET_CRYPTO           0x07u /* An error occurred during an interaction with Crypto */
#define SCC_DET_IP_BASE          0x08u /* An error occurred during an interaction with IpBase */
#define SCC_DET_TL               0x09u /* An error occurred during an interaction with the transport layer (TLS/TCP) */
#define SCC_DET_EXT_CMP_NOT_INIT 0x0Au /* An external component was not initialized */
#define SCC_DET_RX_QUEUE         0x0Bu /* An error occurred during an interaction with the Rx queue */

#define SCC_DET_STATEMGENERIC_INVALIDPROCESSFCT   0x10u /* An error occurred during handling of the generic state machine */
#define SCC_DET_GENERIC_STATEM_PROPAGATE 0x11u /* An error occurred during handling of the generic state machine */

#define SCC_TIMERVALUE_DISABLED  (0u)

#define SCC_ECDH_CURVE_TYPE_X448 1u
#define SCC_ECDH_CURVE_TYPE_TPM  2u
#define SCC_ECDH_CURVE_TYPE_SECP521R1 3u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* Read 3 bytes out of a buffer into a uint32 variable. Implementation is similar to IPBASE_GET_UINT32() and TLS_GET_UINT24. */
/* PRQA S 3473 3 */ /* MD_MSR_FctLikeMacro */
#define SCC_GET_UINT24(Buffer, Offset, Variable) ( (Variable) = (uint32)(((uint32)((Buffer)[(Offset)])    << 16u) | \
                                                                         ((uint32)((Buffer)[(Offset)+1u]) <<  8u) | \
                                                                         ((uint32)((Buffer)[(Offset)+2u]))) )
#ifndef SCC_ENTER_EXCLUSIVE_AREA_0
# define SCC_ENTER_EXCLUSIVE_AREA_0() SchM_Enter_Scc_SCC_EXCLUSIVE_AREA_0()
#endif
#ifndef SCC_LEAVE_EXCLUSIVE_AREA_0
# define SCC_LEAVE_EXCLUSIVE_AREA_0() SchM_Exit_Scc_SCC_EXCLUSIVE_AREA_0()
#endif
#ifndef SCC_ENTER_EXCLUSIVE_AREA_1
# define SCC_ENTER_EXCLUSIVE_AREA_1() SchM_Enter_Scc_SCC_EXCLUSIVE_AREA_1()
#endif
#ifndef SCC_LEAVE_EXCLUSIVE_AREA_1
# define SCC_LEAVE_EXCLUSIVE_AREA_1() SchM_Exit_Scc_SCC_EXCLUSIVE_AREA_1()
#endif
#ifndef SCC_ENTER_EXCLUSIVE_AREA_2
# define SCC_ENTER_EXCLUSIVE_AREA_2() SchM_Enter_Scc_SCC_EXCLUSIVE_AREA_2()
#endif
#ifndef SCC_LEAVE_EXCLUSIVE_AREA_2
# define SCC_LEAVE_EXCLUSIVE_AREA_2() SchM_Exit_Scc_SCC_EXCLUSIVE_AREA_2()
#endif
#ifndef SCC_ENTER_EXCLUSIVE_AREA_3
# define SCC_ENTER_EXCLUSIVE_AREA_3() SchM_Enter_Scc_SCC_EXCLUSIVE_AREA_3()
#endif
#ifndef SCC_LEAVE_EXCLUSIVE_AREA_3
# define SCC_LEAVE_EXCLUSIVE_AREA_3() SchM_Exit_Scc_SCC_EXCLUSIVE_AREA_3()
#endif
#ifndef SCC_ENTER_EXCLUSIVE_AREA_4
# define SCC_ENTER_EXCLUSIVE_AREA_4() SchM_Enter_Scc_SCC_EXCLUSIVE_AREA_4()
#endif
#ifndef SCC_LEAVE_EXCLUSIVE_AREA_4
# define SCC_LEAVE_EXCLUSIVE_AREA_4() SchM_Exit_Scc_SCC_EXCLUSIVE_AREA_4()
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/* 8bit variables - zero init for the NvM */
#define SCC_START_SEC_VAR_CLEARED_8_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, SCC_VAR_ZERO_INIT) Scc_SessionIDNvm[SCC_SESSION_ID_NVM_BLOCK_LEN];

#define SCC_STOP_SEC_VAR_CLEARED_8_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* 8bit variables - const - nvm */
#define SCC_START_SEC_CONST_8_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, SCC_CONST) Scc_SessionIDNvmRomDefault[SCC_SESSION_ID_NVM_BLOCK_LEN];

#define SCC_STOP_SEC_CONST_8_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief          Returns the version information.
 *  \details        Scc_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *                  The versions are BCD-coded.
 *  \param[in]      VersionInfoPtr        pointer for version info
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_VERSION_INFO_API
 *  \trace          CREQ-133185
 *********************************************************************************************************************/
#if ( SCC_VERSION_INFO_API == STD_ON )
FUNC(void, SCC_CODE) Scc_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SCC_APPL_DATA) VersionInfoPtr);
#endif /* SCC_VERSION_INFO_API == STD_ON */

/**********************************************************************************************************************
 *  Scc_InitMemory
 *********************************************************************************************************************/
/*! \brief          initializes global variables
 *  \details        Initializes component variables in *_INIT_* sections at power up.
 *  \pre            has to be called before any other calls to the module
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \note           This function shall be called before Scc_Init.
 *  \trace          CREQ-133183
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_InitMemory(void);

/**********************************************************************************************************************
 *  Scc_Init
 *********************************************************************************************************************/
/*! \brief          Initialization function
 *  \details        This function initializes module global variables at power up. This function initializes the
 *                  variables in *_INIT_* sections. Used in case they are not initialized by the startup code
 *  \pre            Has to be called before useage of the module.
 *  \pre            Interrupts are disabled.
 *  \pre            Module is uninitialized.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \note           Specification of module initialization.
 *  \trace          CREQ-133183
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Init(void);

/**********************************************************************************************************************
 *  Scc_MainFunction
 *********************************************************************************************************************/
/*! \brief          main function of this module, has to be called cyclically
 *  \details        Periodically called MainFunction (typically 10-20 ms) that handles the Scc message triggers,
 *                  re-initialize closed connections and transmit pending data. Make sure to call TcpIp_MainFunction
 *                  twice as often as Scc_MainFunction.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* FUNC(void, SCC_CODE) Scc_MainFunction(void); */

/**********************************************************************************************************************
 *  Scc_ResetSessionID
 *********************************************************************************************************************/
/*! \brief          Resets the SessionID to '0x00'
 *  \details        Reset the SessionID to 0x00 and the length to 0x01 in the NvM.
 *  \pre            will only have effect outside of a V2G session
 *  \param[in]      ForceReset      force the reset, even when a V2G Communication Session is ongoing
 *  \return         E_OK            SessionID has been reset
 *  \return         E_NOT_OK        a V2G session is currently active, please try again later
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          CREQ-174851
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_ResetSessionID(boolean ForceReset);

#if ( SCC_NUM_OF_DYN_CONFIG_PARAMS != 0 )
/**********************************************************************************************************************
 *  Scc_DynConfigDataReadAccess
 *********************************************************************************************************************/
/*! \brief          configuration data read access
 *  \details        Gets the configuration values of the Timer (DIN70121/ISO15118_2/ISO15118_20) and the Vector StateMachine
 *  \param[in]      DataID         data identifier
 *  \param[out]     DataPtr        pointer for diagnostic data
 *  \return         E_OK           configuration data was successfully read
 *  \return         E_NOT_OK       invalid DataID
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          CREQ-163493
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_DynConfigDataReadAccess(Scc_DynConfigParamsType DataID,
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DynConfigDataReadAccessUint32
 *********************************************************************************************************************/
/*! \brief          configuration data read access
 *  \details        Gets the configuration values of the Timer (DIN70121/ISO15118_2/ISO15118_20) and the Vector StateMachine
 *  \param[in]      DataID         data identifier
 *  \param[out]     DataPtr        pointer for diagnostic data
 *  \return         E_OK           configuration data was successfully read
 *  \return         E_NOT_OK       invalid DataID
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          CREQ-163493
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_DynConfigDataReadAccessUint32(Scc_DynConfigParamsType DataID,
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) DataPtr);
#endif /* SCC_NUM_OF_DYN_CONFIG_PARAMS */

#if ( SCC_NUM_OF_DYN_CONFIG_PARAMS != 0 )
/**********************************************************************************************************************
 *  Scc_DynConfigDataWriteAccess
 *********************************************************************************************************************/
/*! \brief          configuration data write access
 *  \details        Sets the configuration values of the Timer (DIN70121/ISO15118_2/ISO15118_20) and the Vector StateMachine
 *  \param[in]      DataID         data identifier
 *  \param[in]      Data           configuration data that shall be written to NVRAM
 *  \return         E_OK           configuration data was successfully written
 *  \return         E_NOT_OK       invalid DataID
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          CREQ-163493
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_DynConfigDataWriteAccess(Scc_DynConfigParamsType DataID, uint16 Data);
#endif /* SCC_NUM_OF_DYN_CONFIG_PARAMS */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_SwapContrCertChain
 *********************************************************************************************************************/
/*! \brief          Swap the used contract certificate chain slot
 *  \details        Swap ContractCertificate and reset read states.
 *  \param[in]      NewContractCertificateChainIndex   new slot index
 *  \param[in]      ForceSwap             force to swap the chain (i.e. reset the current chain status)
 *  \param[in]      IsIso15118_20         TRUE: current schema is ISO15118-20, FALSE: current schema is ISO15118-2
 *  \return         OK                    chain swapped successfully
 *  \return         Busy                  a V2G session is active,  swap is currently not possible
 *  \return         NotOK                 invalid chain index
 *  \pre            not available during an active V2G session, unless ForceSwap is used
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \trace          CREQ-174857
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_SwapContrCertChain(uint8 NewContractCertificateChainIndex, boolean ForceSwap, boolean IsIso15118_20);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_GetContractCertChainIndexInUse
 *********************************************************************************************************************/
/*! \brief          Fetches index of currently used contract certificate chain
 *  \details        -
 *  \param[out]     IndexOfUsedContractCertChain       index of currently used contract certificate chain
 *  \return         E_OK                               index of currently used contract certificate chain stored successfully
 *  \return         E_NOT_OK                           passed invalid pointer
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \trace          CREQ-174857
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_GetContractCertChainIndexInUse(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) IndexOfUsedContractCertChain);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_IPADDR_SELECTION) && (SCC_IPADDR_SELECTION == STD_ON)
/**********************************************************************************************************************
 *  Scc_SetLocalAddrId
 *********************************************************************************************************************/
/*! \brief          Sets the LocalAddrId so that different Ethernet interfaces could be selected
 *  \details        API should be called when no V2G communication session is running. Else a Nok is returned
 *  \param[in]      IpAddressSelection    Enumeration of the Local address Id
 *  \return         OK             Setting the LocalAddrId was successful
 *  \return         NotOK          Setting the LocalAddrId was not successful
 *  \pre            no link is established and no communication is active
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_IPADDR_SELECTION
 *  \trace          CREQ-247710
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_SetLocalAddrId(Scc_IpAddressSelectionEnumType IpAddressSelection);
#endif /* (SCC_IPADDR_SELECTION == STD_ON) */

#if ( defined SCC_ENABLE_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) \
 || (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
/**********************************************************************************************************************
 *  Scc_ProcessCertificateInstallationRes
 *********************************************************************************************************************/
/*! \brief          Processes an Exi encoded certificate installation response message.
 *  \details        Installation is allowed if no communication is currently active only.
 *                  In case an error is detected the reported MsgStatus shall be ignored. Only the stack error
 *                  and, if used, the detailed error code may be used to determine the issue during processing.
 *  \param[in]      ExiStreamPtr    Exi stream containing the certificate installation response to process.
 *  \param[in]      ExiStreamPtrLen Length of the Exi stream.
 *  \param[in]      SchemaToUse     The schema of the certificate installation message.
 *  \param[in]      FirstCall       If this is the first call set this flag to TRUE, otherwise FALSE.
 *  \return         OK             Processing finished and contract is installed.
 *  \return         Pending        Processing is ongoing, call this API again at later point in time.
 *  \return         NotOK          Error occurred.
 *  \pre            No communication is active
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ProcessCertificateInstallationRes(
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ExiStreamPtr,
  CONST(uint16, AUTOMATIC) ExiStreamPtrLen,
  CONST(Scc_ProcessCertInstResEnumType, AUTOMATIC) SchemaToUse,
  CONST(boolean, AUTOMATIC) FirstCall);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_DeleteContract
 *********************************************************************************************************************/
/*! \brief          Deletes the certificate chain.
 *  \details        Deletes all related certificates and the corresponding private key of the passed contract.
 *  \param[in]      ContractId            Contract id reference.
 *  \param[in]      ForceDeletion         Force deletion of the contract certificate even if the session is active.
 *  \param[in]      IsIso15118_20         TRUE: current schema is ISO15118-20, FALSE: current schema is ISO15118-2
 *  \return         OK                    Contract deleted successfully.
 *  \return         Pending               Operation is ongoing.
 *  \return         Busy                  Operation is busy.
 *  \return         NotOK                 Error occurred.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_DeleteContract(
  CONST(Scc_ContractIdType, AUTOMATIC) ContractId,
  CONST(boolean, AUTOMATIC) ForceDeletion,
  boolean IsIso15118_20);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
/**********************************************************************************************************************
 *  Scc_SetOemProvCertChain
 *********************************************************************************************************************/
/*! \brief          Sets the OEM provisioning certificate index to be used in Scc Core.
 *  \details        -
 *  \param[in]      NewProvCertChainIndex      Provisioning certificate index to be used.
 *  \return         E_NOT_OK   An error occurred
 *  \return         E_OK       Value set successfully
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
  *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_SetOemProvCertChain(uint8 NewProvCertChainIndex);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EXCLUSIVE AREA DEFINITION
 **********************************************************************************************************************/
/*!
 * \exclusivearea SCC_EXCLUSIVE_AREA_0
 *                Ensures consistency of a Csm job's state that cannot be accessed atomically in case it is modified in
 *                task context of Scc or Csm interrupt context.
 *                Only needed if an asynchronous Csm job is used.
 * \protects      Scc_CsmJobInfo
 * \usedin        Scc_Reset()
 *                Scc_ISO_Common_VerifySignature()
 *                Scc_ISO_Common_ChargeParameterDiscovery_VerifySignature()
 *                Scc_ISO15118_2_ExiRx_CertificateInstallationRes_Step_StorePublicKey()
 *                Scc_ISO15118_2_ExiRx_CertificateUpdateRes_Step_StorePublicKey()
 *                Scc_ISO15118_2_ExiRx_ChargeParameterDiscoveryRes()
 *                Scc_ISO15118_2_ExiTx_CertificateInstallationReq()
 *                Scc_ISO15118_2_ExiTx_CertificateUpdateReq()
 *                Scc_ISO15118_2_ExiTx_AuthorizationReq()
 *                Scc_ISO15118_2_ExiTx_MeteringReceiptReq()
 *                Scc_InitWorkspaceDecodeExiData()
 *                Scc_ISO15118_20CM_ExiTx_CertificateInstallationReq()
 * \exclude       All other functions provided by Scc.
 * \length        SHORT The Csm job's state is updated.
 * \endexclusivearea
 */

/*!
 * \exclusivearea SCC_EXCLUSIVE_AREA_1
 *                Ensures consistency of a Csm job's state that cannot be accessed atomically and that is
 *                modified in task context of Scc or Csm callout context. In case the CSM is being operated
 *                in polling mode it may happen that the task context of Scc is interrupting the callout of Csm.
 *                Only needed if an asynchronous Csm job is used or Csm is in polling mode and assigned to
 *                another preemptive task than Scc.
 * \protects      Scc_CsmJobInfo
 * \usedin        Scc_Cbk_Csm_ApplNotification()
 * \exclude       All other functions provided by Scc.
 * \length        SHORT The Csm job's state is updated.
 * \endexclusivearea
 */

/*!
 * \exclusivearea SCC_EXCLUSIVE_AREA_2
 *                Ensures consistency of network stack state information which are modified in task context
 *                of Scc or a lower layer callback of the network stack.
 *                Only needed if an interrupt based network stack is being used or the network stack's functions
 *                are assigned to another preemptive task than Scc.
 * \protects      Variables containing network stack related information and Rx queue.
 * \usedin        Scc_MsgStateFct_EA2()
 *                Scc_MainFunction()
 *                Scc_Rx_UdpRelease()
 *                Scc_Cbk_TL_RxIndication()
 *                Scc_Cbk_TL_TCPConnected()
 *                Scc_Cbk_TL_TCPEvent()
 *                Scc_SetLocalAddrId()
 *                Scc_Cbk_IP_AddressAssignmentChange()
 *                Scc_Reset()
 *                Scc_Trigger_V2G()
 *                Scc_TimeoutHandling()
 *                Scc_SDP_Rx_SECCDiscoveryProtocolRes()
 *                Scc_EstablishTLConnection()
 *                Scc_Exi_DecodeSupportedAppProtocolRes()
 *                Scc_ReportError()
 *                Scc_ReportSuccessAndStatus()
 *                Scc_Rx_Queue_GetData()
 *                Scc_Rx_Queue_Consume()
 * \exclude       All other functions provided by Scc.
 * \length        LONG State information is updated and received data is handled in Rx Queue
 * \endexclusivearea
 */

/*!
 * \exclusivearea SCC_EXCLUSIVE_AREA_3
 *                Ensures consistency of variables which are shared between task context of Scc or application context.
 *                Only needed if the application is mapped to a different task than Scc and preemptive task are used and
 *                dynamic parameters are used.
 * \protects      Variables which are shared in Scc_MainFunction and application context.
 * \usedin        Scc_DIN70121_TimerCfg_<DynConfigParamAccess>()
 *                Scc_ISO15118_2_TimerCfg_<DynConfigParamAccess>()
 *                Scc_StateM_ParamCfg_<DynConfigParamAccess>()
 *                Scc_TimerGeneral_TimerCfg_<DynConfigParamAccess>()
 * \exclude       All other functions provided by Scc.
 * \length        SHORT Only dynamic variables are updated
 * \endexclusivearea
 */

/*!
 * \exclusivearea SCC_EXCLUSIVE_AREA_4
 *                Ensures consistency of variables which are shared between task context of Scc and KeyM context.
 *                Only needed if the KeyM or its background task is mapped to a different task than Scc and
 *                preemptive task are used.
 * \protects      Variables which are shared in Scc_MainFunction and KeyM callout context.
 * \usedin        Scc_Core_KeyMUtils_CbkUpdateStatus()
 *                Scc_Core_KeyMUtils_VerifyOemProv()
 *                Scc_Core_KeyMUtils_WriteAndVerifyGroup()
 *                Scc_Core_KeyMUtils_VerifyGroup()
 *                Scc_Core_KeyMUtils_CbkGroupUpdateStatus()
 * \exclude       All other functions provided by Scc.
 * \length        SHORT Only state variables are updated
 * \endexclusivearea
 */

#endif /* SCC_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc.h
 *********************************************************************************************************************/
