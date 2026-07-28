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
 *              File: Scc_StateM_ParamsCfg.h
 *   Generation Time: 2025-08-26 17:17:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

 
#if !defined(SCC_STATEM_PARAMSCFG_H)
#define SCC_STATEM_PARAMSCFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Scc_StateM_ParamCfg_ConfigType_AcceptUnsecureConnection               SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_AcceptFreeCertificateServicesOnly      SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ReconnectRetries                       SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ReconnectDelay                         SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_RequestInternetDetails                 SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_TLConnectedWaitTime                    SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_AuthorizationNextReqDelay              SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryNextReqDelay   SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_AuthorizationOngoingTimeout            SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ChargeParameterDiscoveryOngoingTimeout SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeOngoingTimeout         SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_CableCheckOngoingTimeout               SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_CableCheckTimeout                      SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_PreChargeTimeout                       SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ISO_20_PreChargeTimeout                SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_CableCheckNextReqDelay                 SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ChargeLoopNextReqDelay                 SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_PreChargeNextReqDelay                  SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ScheduleExchangeNextReqDelay           SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_PowerDeliveryNextReqDelay              SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ServiceDetailNextReqDelay              SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_CurrentDemandNextReqDelay              SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_WeldingDetectionNextReqDelay           SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ChargingStatusNextReqDelay             SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_PaymentPrioritization                  SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ContractCertificateChainIndexInUse     SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_CertificateExpireThreshold             SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_RequestCertificateDetails              SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_RequestCertificateInstallation         SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_RequestCertificateUpdate               SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_SLACAmpMapMode                         SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_IsTlsInSdpPossible                     SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_CertificateInstallationNextReqDelay    SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_CertificateInstallationOngoingTimeout  SCC_CFG_TYPE_STATIC 
#define Scc_StateM_ParamCfg_ConfigType_ServiceRenegotiation                   SCC_CFG_TYPE_DYNAMIC 



#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Timeout values
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_AuthorizationOngoingTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_AuthorizationOngoingTimeout(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryOngoingTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryOngoingTimeout(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ScheduleExchangeOngoingTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ScheduleExchangeOngoingTimeout(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CableCheckOngoingTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CableCheckOngoingTimeout(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CableCheckTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CableCheckTimeout(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_PreChargeTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_PreChargeTimeout(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ISO_20_PreChargeTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ISO_20_PreChargeTimeout(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CertificateInstallationOngoingTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CertificateInstallationOngoingTimeout(void);




/**********************************************************************************************************************
 * Delay values
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ReconnectDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ReconnectDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_AuthorizationNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_AuthorizationNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CableCheckNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CableCheckNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ChargeLoopNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ChargeLoopNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_PreChargeNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_PreChargeNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ScheduleExchangeNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ScheduleExchangeNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_PowerDeliveryNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_PowerDeliveryNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ServiceDetailNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ServiceDetailNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CurrentDemandNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CurrentDemandNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_WeldingDetectionNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_WeldingDetectionNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ChargingStatusNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ChargingStatusNextReqDelay(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CertificateInstallationNextReqDelay 
 *********************************************************************************************************************/
/*! \brief          Returns the configured delay time in main function cycles
 *  \details        -
 *  \return         The configured delay time
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CertificateInstallationNextReqDelay(void);



/**********************************************************************************************************************
 * Other values
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_AcceptUnsecureConnection 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_AcceptUnsecureConnection(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_AcceptFreeCertificateServicesOnly 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_AcceptFreeCertificateServicesOnly(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ReconnectRetries 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ReconnectRetries(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_RequestInternetDetails 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_RequestInternetDetails(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_TLConnectedWaitTime 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_TLConnectedWaitTime(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_PaymentPrioritization 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_PaymentPrioritization(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ContractCertificateChainIndexInUse 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ContractCertificateChainIndexInUse(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CertificateExpireThreshold 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CertificateExpireThreshold(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_RequestCertificateDetails 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_RequestCertificateDetails(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_RequestCertificateInstallation 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_RequestCertificateInstallation(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_RequestCertificateUpdate 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_RequestCertificateUpdate(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_SLACAmpMapMode 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_SLACAmpMapMode(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_IsTlsInSdpPossible 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_IsTlsInSdpPossible(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ServiceRenegotiation 
 *********************************************************************************************************************/
/*! \brief          Returns the configured numeric value
 *  \details        -
 *  \return         The configured numeric value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ServiceRenegotiation(void);

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Set_ServiceRenegotiation 
 *********************************************************************************************************************/
/*! \brief          Sets the dynamic configurable numeric value.
 *  \details        -
 *  \param[in]      ValueToSet New numeric value to set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_ParamCfg_Set_ServiceRenegotiation(uint16 ValueToSet);



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_STATEM_PARAMSCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Scc_StateM_ParamsCfg.h
 *********************************************************************************************************************/

