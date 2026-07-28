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
 *              File: Scc_ISO15118_2_TimerCfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

 
#if !defined(SCC_ISO15118_2_TIMERCFG_H)
#define SCC_ISO15118_2_TIMERCFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Scc_ISO15118_2_TimerCfg_ConfigType_SequencePerformanceTimeout             SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_CommunicationSetupTimeout              SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_AuthorizationMessageTimeout            SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_CableCheckMessageTimeout               SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_CertificateInstallationMessageTimeout  SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_CertificateUpdateMessageTimeout        SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_ChargingStatusMessageTimeout           SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_CurrentDemandMessageTimeout            SCC_CFG_TYPE_EXTERN 
#define Scc_ISO15118_2_TimerCfg_ConfigType_MeteringReceiptMessageTimeout          SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_PaymentDetailsMessageTimeout           SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_PaymentServiceSelectionMessageTimeout  SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_PowerDeliveryMessageTimeout            SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_PreChargeMessageTimeout                SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDetailMessageTimeout            SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout         SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_SessionSetupMessageTimeout             SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_SessionStopMessageTimeout              SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_2_TimerCfg_ConfigType_WeldingDetectionMessageTimeout         SCC_CFG_TYPE_STATIC 



#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Timer
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_SequencePerformanceTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_SequencePerformanceTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_CommunicationSetupTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_CommunicationSetupTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_AuthorizationMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_AuthorizationMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_CableCheckMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_CableCheckMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_CertificateInstallationMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_CertificateInstallationMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_CertificateUpdateMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_CertificateUpdateMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_ChargingStatusMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_ChargingStatusMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_CurrentDemandMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_CurrentDemandMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_MeteringReceiptMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_MeteringReceiptMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_PaymentDetailsMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_PaymentDetailsMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_PaymentServiceSelectionMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_PaymentServiceSelectionMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_PowerDeliveryMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_PowerDeliveryMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_PreChargeMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_PreChargeMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_ServiceDetailMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_ServiceDetailMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_ServiceDiscoveryMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_ServiceDiscoveryMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_SessionSetupMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_SessionSetupMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_SessionStopMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_SessionStopMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_WeldingDetectionMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_WeldingDetectionMessageTimeout(void);



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* SCC_ISO15118_2_TIMERCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_2_TimerCfg.h
 *********************************************************************************************************************/

