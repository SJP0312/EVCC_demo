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
/*!        \file  Scc_SDP.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements the shared SECCDiscoveryProtocol that is used in Vehicle 2 Grid communication according
 *                to the specifications DIN SPEC 70121, ISO/IEC 15118-2, ISO/IEC 15118-20 and customer specific schemas.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_SDP_H)
# define SCC_SDP_H

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
#define SCC_SDP_RES_PLC_LEN                     28U

#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
#define SCC_SDP_RES_WIRELESS_LEN                67U
#endif /* SCC_WIRELESS_SDP */

#define SCC_SDP_REQ_PLC_LEN                     10U

#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
#define SCC_SDP_REQ_WIRELESS_LEN                69U
#endif /* SCC_WIRELESS_SDP */

#define SCC_SDP_TP_TCP                        0x00U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
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
 *  Scc_SDP_Tx_Init
 *********************************************************************************************************************/
/*! \brief          Initializes the SDP Tx unit
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SDP_Tx_Init(void);

/**********************************************************************************************************************
 *  Scc_SDP_Tx_IsRetransRetriesCntExpired
 *********************************************************************************************************************/
/*! \brief          Checks if SDPRetransRetriesCnt is expired
 *  \details        -
 *  \return         TRUE         Count is expired
 *  \return         FALSE        Count is not expired
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_SDP_Tx_IsRetransRetriesCntExpired(void);

/**********************************************************************************************************************
 *  Scc_SDP_Tx_DecrementRetransRetriesCnt
 *********************************************************************************************************************/
/*! \brief          Decrements SDPRetransRetriesCnt
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SDP_Tx_DecrementRetransRetriesCnt(void);

/**********************************************************************************************************************
 *  Scc_SDP_Tx_SECCDiscoveryProtocolReq
 *********************************************************************************************************************/
/*! \brief          Transmit SECCDiscoveryProtocol message.
 *  \details        Create SECCDiscoveryProtocol and transmit message.
 *  \param[in]      RxConfigPtr     Pointer to the configuration structure to setup
 *  \return         E_OK            Udp send whole message
 *  \return         E_NOT_OK        Udp did not accepted the request
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_SDP_Tx_SECCDiscoveryProtocolReq(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr);

/**********************************************************************************************************************
 *  Scc_SDP_Rx_GetSecurity
 *********************************************************************************************************************/
/*! \brief          Returns the SDPSecurity value.
 *  \details        -
 *  \return         Scc_Security
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_SDPSecurityType, SCC_STATIC_CODE) Scc_SDP_Rx_GetSecurity(void);

/**********************************************************************************************************************
 *  Scc_SDP_Rx_Init
 *********************************************************************************************************************/
/*! \brief          Initializes the SDP Rx unit
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_SDP_Rx_Init(void);

/**********************************************************************************************************************
 *  Scc_SDP_Rx_SECCDiscoveryProtocolResPlc
 *********************************************************************************************************************/
 /*! \brief          Receive SECCDiscoveryProtocol message on physical layer type plc.
  *  \details        Receive and process SECCDiscoveryProtocol message on physical layer type plc.
  *  \param[in]      V2GTpHeaderPtr                          Pointer to V2GTpHeader
  *  \param[in]      RxMsgWSPtr                              Pointer to the Rx message workspace
  *  \return         Scc_ReturnType_InvalidPayloadLen        Length does not match the constraints
  *  \return         Scc_ReturnType_NotOK                    Option for transport protocol and security is not correct
  *  \return         Scc_ReturnType_OK                       Received valid message
  *  \pre            -
  *  \context        TASK
  *  \reentrant      FALSE
  *  \synchronous    FALSE
  *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SDP_Rx_SECCDiscoveryProtocolResPlc(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
/**********************************************************************************************************************
 *  Scc_SDP_Rx_SECCDiscoveryProtocolResWireless
 *********************************************************************************************************************/
 /*! \brief          Receive SECCDiscoveryProtocol message on physical layer type wireless.
  *  \details        Receive and process SECCDiscoveryProtocol message on physical layer type wireless.
  *  \param[in]      V2GTpHeaderPtr              Pointer to V2GTpHeader
  *  \param[in]      RxMsgWSPtr                  Pointer to the Rx message workspace
  *  \return         Scc_ReturnType_NotOK        Option for the transport protocol and security is not correct
  *  \return         Scc_ReturnType_OK           Received valid message
  *  \pre            -
  *  \context        TASK
  *  \config         SCC_SCHEMA_ISO_20WPT || SCC_SCHEMA_ISO_20ACDP
  *  \reentrant      FALSE
  *  \synchronous    FALSE
  *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SDP_Rx_SECCDiscoveryProtocolResWireless(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
#endif /* SCC_WIRELESS_SDP */

/**********************************************************************************************************************
 *  Scc_SDP_Rx_SECCDiscoveryProtocolResCheckHeader
 *********************************************************************************************************************/
 /*! \brief          Check the header of a SECCDiscoveryProtocol message.
  *  \details        Perform a length and type check for the payload information enveloped inside the V2GTp Header.
  *  \param[in]      V2GTpHeaderPtr                          Pointer to V2GTp Header
  *  \param[in]      ComLayerType                            Underlaying physical layer type
  *  \return         Scc_ReturnType_InvalidPayloadLen        Length does not match the constraints
  *  \return         Scc_ReturnType_NotOK                    Payload type does not match PhysComLayerType
  *  \return         Scc_ReturnType_OK                       Length is within constraints
  *  \pre            -
  *  \context        TASK
  *  \reentrant      FALSE
  *  \synchronous    FALSE
  *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SDP_Rx_SECCDiscoveryProtocolResCheckHeader(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  Scc_SDPPhysComLayerType PhysComLayerType);

/**********************************************************************************************************************
 *  Scc_SDP_Rx_SECCDiscoveryProtocolResProcessCommonPayload
 *********************************************************************************************************************/
 /*! \brief          Process shared payload of SECCDiscoveryProtocol response message.
  *  \details        Process payload parameters shared between plc and wireless SDP response message.
  *  \param[in]      RxMsgWSPtr                  Pointer to the Rx message workspace
  *  \return         Scc_ReturnType_NotOK        Processing the parameters was not sucessful
  *  \return         Scc_ReturnType_OK           Received valid message
  *  \pre            -
  *  \context        TASK
  *  \reentrant      FALSE
  *  \synchronous    FALSE
  *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_SDP_Rx_SECCDiscoveryProtocolResProcessCommonPayload(void);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SDP_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_SDP.h
 *********************************************************************************************************************/
