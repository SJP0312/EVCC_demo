/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Scc
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Scc_SDP_InterfaceCfg.h
 *   Generation Time: 2025-08-26 17:17:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#if !defined(SCC_SDP_INTERFACECFG_H)
#define SCC_SDP_INTERFACECFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_Types.h"


#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * RX INTERFACE - information to be sent is going to be fetched from upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SDP_InterfaceCfg_Get_SDPSecurityRx 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SDP_InterfaceCfg_Get_SDPSecurityRx(P2VAR(Scc_SDPSecurityType, AUTOMATIC, SCC_APPL_DATA) DataPtr);



/**********************************************************************************************************************
 * TX INTERFACE - received information is going to be propagated to upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SDP_InterfaceCfg_Set_SDPTransportProtocol 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SDP_InterfaceCfg_Set_SDPTransportProtocol(Scc_SDPTransportProtocolType Data);

/**********************************************************************************************************************
 *  Scc_SDP_InterfaceCfg_Set_SDPSecurityTx 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SDP_InterfaceCfg_Set_SDPSecurityTx(Scc_SDPSecurityType Data);

/**********************************************************************************************************************
 *  Scc_SDP_InterfaceCfg_Set_SECCIPAddress 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SDP_InterfaceCfg_Set_SECCIPAddress(P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SDP_InterfaceCfg_Set_SECCPort 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SDP_InterfaceCfg_Set_SECCPort(uint16 Data);



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SDP_INTERFACECFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Scc_SDP_InterfaceCfg.h
 *********************************************************************************************************************/

