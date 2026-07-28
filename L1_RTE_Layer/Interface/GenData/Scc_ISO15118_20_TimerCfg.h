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
 *              File: Scc_ISO15118_20_TimerCfg.h
 *   Generation Time: 2025-08-26 17:17:04
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

 
#if !defined(SCC_ISO15118_20_TIMERCFG_H)
#define SCC_ISO15118_20_TIMERCFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Scc_ISO15118_20_TimerCfg_ConfigType_SequencePerformanceTimeout             SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_CommunicationSetupTimeout              SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_SessionSetupMessageTimeout             SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationSetupMessageTimeout       SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_AuthorizationMessageTimeout            SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_CertificateInstallationMessageTimeout  SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDiscoveryMessageTimeout         SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_ServiceDetailMessageTimeout            SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_ServiceSelectionMessageTimeout         SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_ChargeParameterDiscoveryMessageTimeout SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_ScheduleExchangeMessageTimeout         SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_PowerDeliveryMessageTimeout            SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_MeteringConfirmationMessageTimeout     SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_SessionStopMessageTimeout              SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_CableCheckMessageTimeout               SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_PreChargeMessageTimeout                SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopMessageTimeout               SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_WeldingDetectionMessageTimeout         SCC_CFG_TYPE_STATIC 
#define Scc_ISO15118_20_TimerCfg_ConfigType_ChargeLoopSequencePerformanceTimeout   SCC_CFG_TYPE_STATIC 



#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Timer
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_CommunicationSetupTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_CommunicationSetupTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_SessionSetupMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_SessionSetupMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_AuthorizationSetupMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_AuthorizationSetupMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_AuthorizationMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_AuthorizationMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_CertificateInstallationMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_CertificateInstallationMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_ServiceDiscoveryMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_ServiceDiscoveryMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_ServiceDetailMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_ServiceDetailMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_ServiceSelectionMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_ServiceSelectionMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_ScheduleExchangeMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_ScheduleExchangeMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_PowerDeliveryMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_PowerDeliveryMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_MeteringConfirmationMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_MeteringConfirmationMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_SessionStopMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_SessionStopMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_CableCheckMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_CableCheckMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_PreChargeMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_PreChargeMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_ChargeLoopMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_ChargeLoopMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_WeldingDetectionMessageTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_WeldingDetectionMessageTimeout(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_TimerCfg_Get_ChargeLoopSequencePerformanceTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_ISO15118_20_TimerCfg_Get_ChargeLoopSequencePerformanceTimeout(void);



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* SCC_ISO15118_20_TIMERCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_TimerCfg.h
 *********************************************************************************************************************/

