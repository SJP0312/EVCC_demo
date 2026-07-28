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
 *            Module: Slac
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Slac_Cfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined (SLAC_CFG_H)
#define SLAC_CFG_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "ComStack_Types.h"
#include "EthIf_Cfg.h"

/**********************************************************************************************************************
 *  LINKTIME / PRECOMPILE CRC
 *********************************************************************************************************************/
#define SLAC_CRC_CHECK                       STD_OFF
#define SLAC_PRECOMPILE_CRC                  0x00000000u

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#ifndef SLAC_USE_DUMMY_STATEMENT
#define SLAC_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SLAC_DUMMY_STATEMENT
#define SLAC_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SLAC_DUMMY_STATEMENT_CONST
#define SLAC_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SLAC_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define SLAC_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef SLAC_ATOMIC_VARIABLE_ACCESS
#define SLAC_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef SLAC_PROCESSOR_TC377T
#define SLAC_PROCESSOR_TC377T
#endif
#ifndef SLAC_COMP_DIAB
#define SLAC_COMP_DIAB
#endif
#ifndef SLAC_GEN_GENERATOR_MSR
#define SLAC_GEN_GENERATOR_MSR
#endif
#ifndef SLAC_CPUTYPE_BITORDER_LSB2MSB
#define SLAC_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef SLAC_CONFIGURATION_VARIANT_PRECOMPILE
#define SLAC_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef SLAC_CONFIGURATION_VARIANT_LINKTIME
#define SLAC_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef SLAC_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define SLAC_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef SLAC_CONFIGURATION_VARIANT
#define SLAC_CONFIGURATION_VARIANT SLAC_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef SLAC_POSTBUILD_VARIANT_SUPPORT
#define SLAC_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
#define SLAC_VERSION_INFO_API                                   STD_OFF
#define SLAC_DEV_ERROR_DETECT                                   STD_ON
#define SLAC_DEV_ERROR_REPORT                                   STD_ON
#define SLAC_CFG_ENABLE_MESSAGE_HOOK                            STD_OFF
#define SLAC_EVSE_COMPATIBILITY_MODE_CHECK_ADDRESS_VALUES       STD_ON
#define SLAC_EVSE_COMPATIBILITY_MODE_CHECK_CONST_VALUES         STD_ON
#define SLAC_EVSE_COMPATIBILITY_MODE_CHECK_RSVD_VALUES          STD_OFF
#define SLAC_NVM_REQUIRED                                       STD_OFF
#define SLAC_DIAG_APIS_REQUIRED                                 STD_OFF
#define SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE                STD_OFF

#define SLAC_CFG_ENABLE_SKIP_WAITING_AFTER_KNOWN_EVSES_DID_SEND_ATTEN_CHAR STD_OFF

#define SLAC_ETHIF_CONTROLLER_IDX                              (uint8)EthIfConf_EthIfController_EthIfController

#define SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS                    5u

#define SLAC_CFG_MAX_EVSE_PROFILES                             5u

#define SLAC_CFG_ENABLE_CALIBRATION                            STD_OFF

/* Local PSD value map for CM_AMP_MAP combination */
#define SLAC_CFG_LPVMS_DISABLED                                0U
#define SLAC_CFG_LPVMS_CALLOUT                                 1U
#define SLAC_CFG_LPVMS_NVM                                     2U
#define SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE                    SLAC_CFG_LPVMS_DISABLED
#define SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE                STD_OFF
#define SLAC_CFG_AMP_MAP_SIZE                                  917u
#define SLAC_CFG_AMP_MAP_NVM_SIZE                              459u

/* Additional states: timers and retries */
#define SLAC_CFG_PREPARE_PLC_CHIP_FOR_SLAC_TIMEOUT_MS          500u
#define SLAC_CFG_PLC_DLINK_DOWN_DELAY_MS                       50u

/* Message timeouts */
#define SLAC_CFG_MSG_TT_MATCH_RESPONSE                         200u
#define SLAC_CFG_MSG_TP_MATCH_SEQUENCE                         100u
#define SLAC_CFG_MSG_TP_EV_BATCH_MSG_INTERVAL                  30u
#define SLAC_CFG_MSG_TT_EV_ATTEN_RESULTS                       1200u
#define SLAC_CFG_MSG_CM_ATTEN_CHAR_TT_MATCH_RESPONSE_OFFSET_MS 50u
#define SLAC_CFG_MSG_CM_VALIDATE_SINGLE_EVSE_RETRY_TIMEOUT_MS  1000u
#define SLAC_CFG_MSG_TP_EV_VALD_STATE_DURATION                 200u
#define SLAC_CFG_MSG_TP_EV_VALD_TOGGLE                         1500u
#define SLAC_CFG_MSG_CM_SET_KEY_TT_MATCH_RESPONSE              1000u
#define SLAC_CFG_MSG_TT_MATCH_JOIN                             12000u
#define SLAC_CFG_MSG_T_CONN_RESUME                             6000u
#define SLAC_CFG_MSG_TP_MATCH_LEAVE                            1000u
#define SLAC_CFG_MSG_TT_AMP_MAP_EXCHANGE                       200u
#define SLAC_CFG_MSG_TP_AMP_MAP_EXCHANGE                       100u
#define SLAC_CFG_MSG_CM_AMP_MAP_RETRY_TT_MATCH_RESPONSE_OFFSET_MS 100u
#define SLAC_CFG_MSG_WAIT_FOR_STABLE_LINK_MS                   100u

/* Message retry counters */
#define SLAC_CFG_MSG_C_EV_MATCH_RETRY                          2u
#define SLAC_CFG_MSG_C_EV_START_ATTEN_CHAR_INDS                3u
#define SLAC_CFG_MSG_C_EV_MATCH_MNBC_MIN                       9u
#define SLAC_CFG_MSG_C_EV_MATCH_MNBC_MAX                       11u
#define SLAC_CFG_MSG_C_EV_MATCH_MNBC_ACCEPT                    7u
#define SLAC_CFG_MSG_VALIDATION_RETRY_CNT                      2u
#define SLAC_CFG_MSG_CM_SET_KEY_C_EV_MATCH_RETRY               3u

/* Message value configurations */
#define SLAC_CFG_C_EV_MATCH_SIGNALATTN_MIN                     10u
#define SLAC_CFG_C_EV_MATCH_SIGNALATTN_OFFSET                  25u
#define SLAC_CFG_C_EV_MATCH_SIGNALATTN_DIRECT                  10u
#define SLAC_CFG_C_EV_MATCH_SIGNALATTN_INDIRECT                20u

/* Message elements - General */
#define SLAC_NID_LEN                                           7u
#define SLAC_NMK_LEN                                           16u


#define SLAC_CFG_MME_CCO_CAPABILITY_VALUE                      0x00u

/* PLC chip addres source */
#define SLAC_CFG_PCAS_CONST   0U
#define SLAC_CFG_PCAS_CALLOUT 1U
#define SLAC_CFG_PCAS_NVM     2U
#define SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE   SLAC_CFG_PCAS_CALLOUT

#define SLAC_CFG_ETHTRCV_LINKSTATE_POLLING_PAUSE_ENABLE        STD_OFF
#define SLAC_CFG_ETHTRCV_LINKSTATE_POLLING_PAUSE_DURATION_MS   4000u  
#define SLAC_ETHTRCV_IDX                                       0u /* symbolic value: EthTrcvConf_EthTrcvConfig_EthTrcvConfig */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  USER CONFIG FILE CONTENT
 *********************************************************************************************************************/

#endif  /* SLAC_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: Slac_Cfg.h
 **********************************************************************************************************************/
