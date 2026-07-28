/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Exi_DIN_SchemaTypes.h
 *        \brief  Efficient XML Interchange DIN types header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component DIN types.
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file Exi.h.
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_Exi_1.1_0857 */ /* [L] Number of macro definitions exceeds 1024 - program is non-conforming. */

#if !defined (EXI_DIN_SCHEMA_TYPES_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_DIN_SCHEMA_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_Types.h"

/* PRQA S 0779 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* PRQA S 0780 NAMESPACE */ /* MD_Exi_5.6 */
/* PRQA S 0750 UNION */ /* MD_Exi_18.4 */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Root elements */
#define EXI_DIN_AC_EVCHARGE_PARAMETER_TYPE                                               (Exi_RootElementIdType)0U
#define EXI_DIN_AC_EVSECHARGE_PARAMETER_TYPE                                             (Exi_RootElementIdType)1U
#define EXI_DIN_AC_EVSESTATUS_TYPE                                                       (Exi_RootElementIdType)2U
#define EXI_DIN_BODY_BASE_TYPE                                                           (Exi_RootElementIdType)3U
#define EXI_DIN_CABLE_CHECK_REQ_TYPE                                                     (Exi_RootElementIdType)4U
#define EXI_DIN_CABLE_CHECK_RES_TYPE                                                     (Exi_RootElementIdType)5U
#define EXI_DIN_CERTIFICATE_INSTALLATION_REQ_TYPE                                        (Exi_RootElementIdType)6U
#define EXI_DIN_CERTIFICATE_INSTALLATION_RES_TYPE                                        (Exi_RootElementIdType)7U
#define EXI_DIN_CERTIFICATE_UPDATE_REQ_TYPE                                              (Exi_RootElementIdType)8U
#define EXI_DIN_CERTIFICATE_UPDATE_RES_TYPE                                              (Exi_RootElementIdType)9U
#define EXI_DIN_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE                                      (Exi_RootElementIdType)10U
#define EXI_DIN_CHARGE_PARAMETER_DISCOVERY_RES_TYPE                                      (Exi_RootElementIdType)11U
#define EXI_DIN_CHARGING_STATUS_REQ_TYPE                                                 (Exi_RootElementIdType)12U
#define EXI_DIN_CHARGING_STATUS_RES_TYPE                                                 (Exi_RootElementIdType)13U
#define EXI_DIN_CONTRACT_AUTHENTICATION_REQ_TYPE                                         (Exi_RootElementIdType)14U
#define EXI_DIN_CONTRACT_AUTHENTICATION_RES_TYPE                                         (Exi_RootElementIdType)15U
#define EXI_DIN_CURRENT_DEMAND_REQ_TYPE                                                  (Exi_RootElementIdType)16U
#define EXI_DIN_CURRENT_DEMAND_RES_TYPE                                                  (Exi_RootElementIdType)17U
#define EXI_DIN_DC_EVCHARGE_PARAMETER_TYPE                                               (Exi_RootElementIdType)18U
#define EXI_DIN_DC_EVPOWER_DELIVERY_PARAMETER_TYPE                                       (Exi_RootElementIdType)19U
#define EXI_DIN_DC_EVSECHARGE_PARAMETER_TYPE                                             (Exi_RootElementIdType)20U
#define EXI_DIN_DC_EVSESTATUS_TYPE                                                       (Exi_RootElementIdType)21U
#define EXI_DIN_DC_EVSTATUS_TYPE                                                         (Exi_RootElementIdType)22U
#define EXI_DIN_EVCHARGE_PARAMETER_TYPE                                                  (Exi_RootElementIdType)23U
#define EXI_DIN_EVPOWER_DELIVERY_PARAMETER_TYPE                                          (Exi_RootElementIdType)24U
#define EXI_DIN_EVSECHARGE_PARAMETER_TYPE                                                (Exi_RootElementIdType)25U
#define EXI_DIN_EVSESTATUS_TYPE                                                          (Exi_RootElementIdType)26U
#define EXI_DIN_EVSTATUS_TYPE                                                            (Exi_RootElementIdType)27U
#define EXI_DIN_ENTRY_TYPE                                                               (Exi_RootElementIdType)28U
#define EXI_DIN_INTERVAL_TYPE                                                            (Exi_RootElementIdType)29U
#define EXI_DIN_METERING_RECEIPT_REQ_TYPE                                                (Exi_RootElementIdType)30U
#define EXI_DIN_METERING_RECEIPT_RES_TYPE                                                (Exi_RootElementIdType)31U
#define EXI_DIN_PMAX_SCHEDULE_ENTRY_TYPE                                                 (Exi_RootElementIdType)32U
#define EXI_DIN_PAYMENT_DETAILS_REQ_TYPE                                                 (Exi_RootElementIdType)33U
#define EXI_DIN_PAYMENT_DETAILS_RES_TYPE                                                 (Exi_RootElementIdType)34U
#define EXI_DIN_POWER_DELIVERY_REQ_TYPE                                                  (Exi_RootElementIdType)35U
#define EXI_DIN_POWER_DELIVERY_RES_TYPE                                                  (Exi_RootElementIdType)36U
#define EXI_DIN_PRE_CHARGE_REQ_TYPE                                                      (Exi_RootElementIdType)37U
#define EXI_DIN_PRE_CHARGE_RES_TYPE                                                      (Exi_RootElementIdType)38U
#define EXI_DIN_RELATIVE_TIME_INTERVAL_TYPE                                              (Exi_RootElementIdType)39U
#define EXI_DIN_SASCHEDULE_LIST_TYPE                                                     (Exi_RootElementIdType)40U
#define EXI_DIN_SASCHEDULES_TYPE                                                         (Exi_RootElementIdType)41U
#define EXI_DIN_SALES_TARIFF_ENTRY_TYPE                                                  (Exi_RootElementIdType)42U
#define EXI_DIN_SERVICE_CHARGE_TYPE                                                      (Exi_RootElementIdType)43U
#define EXI_DIN_SERVICE_DETAIL_REQ_TYPE                                                  (Exi_RootElementIdType)44U
#define EXI_DIN_SERVICE_DETAIL_RES_TYPE                                                  (Exi_RootElementIdType)45U
#define EXI_DIN_SERVICE_DISCOVERY_REQ_TYPE                                               (Exi_RootElementIdType)46U
#define EXI_DIN_SERVICE_DISCOVERY_RES_TYPE                                               (Exi_RootElementIdType)47U
#define EXI_DIN_SERVICE_PAYMENT_SELECTION_REQ_TYPE                                       (Exi_RootElementIdType)48U
#define EXI_DIN_SERVICE_PAYMENT_SELECTION_RES_TYPE                                       (Exi_RootElementIdType)49U
#define EXI_DIN_SESSION_SETUP_REQ_TYPE                                                   (Exi_RootElementIdType)50U
#define EXI_DIN_SESSION_SETUP_RES_TYPE                                                   (Exi_RootElementIdType)51U
#define EXI_DIN_SESSION_STOP_REQ_TYPE                                                    (Exi_RootElementIdType)52U
#define EXI_DIN_SESSION_STOP_RES_TYPE                                                    (Exi_RootElementIdType)53U
#define EXI_DIN_V2G_MESSAGE_TYPE                                                         (Exi_RootElementIdType)54U
#define EXI_DIN_WELDING_DETECTION_REQ_TYPE                                               (Exi_RootElementIdType)55U
#define EXI_DIN_WELDING_DETECTION_RES_TYPE                                               (Exi_RootElementIdType)56U

#if (defined(EXI_ENABLE_DIN_MESSAGE_SET) && (EXI_ENABLE_DIN_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* Elements */
#define EXI_DIN_BODY_TYPE                                                                (Exi_RootElementIdType)255U
#define EXI_DIN_BODY_ELEMENT_TYPE                                                        (Exi_RootElementIdType)256U
#define EXI_DIN_BULK_CHARGING_COMPLETE_TYPE                                              (Exi_RootElementIdType)257U
#define EXI_DIN_BULK_SOC_TYPE                                                            (Exi_RootElementIdType)258U
#define EXI_DIN_CERTIFICATE_TYPE                                                         (Exi_RootElementIdType)259U
#define EXI_DIN_CHARGE_SERVICE_TYPE                                                      (Exi_RootElementIdType)260U
#define EXI_DIN_CHARGING_COMPLETE_TYPE                                                   (Exi_RootElementIdType)261U
#define EXI_DIN_CHARGING_PROFILE_TYPE                                                    (Exi_RootElementIdType)262U
#define EXI_DIN_CHARGING_PROFILE_ENTRY_MAX_POWER_TYPE                                    (Exi_RootElementIdType)263U
#define EXI_DIN_CHARGING_PROFILE_ENTRY_START_TYPE                                        (Exi_RootElementIdType)264U
#define EXI_DIN_CONSUMPTION_COST_TYPE                                                    (Exi_RootElementIdType)265U
#define EXI_DIN_CONTRACT_ID_TYPE                                                         (Exi_RootElementIdType)266U
#define EXI_DIN_CONTRACT_SIGNATURE_CERT_CHAIN_TYPE                                       (Exi_RootElementIdType)267U
#define EXI_DIN_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_TYPE                            (Exi_RootElementIdType)268U
#define EXI_DIN_COST_TYPE                                                                (Exi_RootElementIdType)269U
#define EXI_DIN_DHPARAMS_TYPE                                                            (Exi_RootElementIdType)270U
#define EXI_DIN_DATE_TIME_NOW_TYPE                                                       (Exi_RootElementIdType)271U
#define EXI_DIN_DEPARTURE_TIME_TYPE                                                      (Exi_RootElementIdType)272U
#define EXI_DIN_EAMOUNT_TYPE                                                             (Exi_RootElementIdType)273U
#define EXI_DIN_EPRICE_LEVEL_TYPE                                                        (Exi_RootElementIdType)274U
#define EXI_DIN_EVCCID_TYPE                                                              (Exi_RootElementIdType)275U
#define EXI_DIN_EVCABIN_CONDITIONING_TYPE                                                (Exi_RootElementIdType)276U
#define EXI_DIN_EVENERGY_CAPACITY_TYPE                                                   (Exi_RootElementIdType)277U
#define EXI_DIN_EVENERGY_REQUEST_TYPE                                                    (Exi_RootElementIdType)278U
#define EXI_DIN_EVERROR_CODE_TYPE                                                        (Exi_RootElementIdType)279U
#define EXI_DIN_EVMAX_CURRENT_TYPE                                                       (Exi_RootElementIdType)280U
#define EXI_DIN_EVMAX_VOLTAGE_TYPE                                                       (Exi_RootElementIdType)281U
#define EXI_DIN_EVMAXIMUM_CURRENT_LIMIT_TYPE                                             (Exi_RootElementIdType)282U
#define EXI_DIN_EVMAXIMUM_POWER_LIMIT_TYPE                                               (Exi_RootElementIdType)283U
#define EXI_DIN_EVMAXIMUM_VOLTAGE_LIMIT_TYPE                                             (Exi_RootElementIdType)284U
#define EXI_DIN_EVMIN_CURRENT_TYPE                                                       (Exi_RootElementIdType)285U
#define EXI_DIN_EVRESSCONDITIONING_TYPE                                                  (Exi_RootElementIdType)286U
#define EXI_DIN_EVRESSSOC_TYPE                                                           (Exi_RootElementIdType)287U
#define EXI_DIN_EVREADY_TYPE                                                             (Exi_RootElementIdType)288U
#define EXI_DIN_EVREQUESTED_ENERGY_TRANSFER_TYPE_TYPE                                    (Exi_RootElementIdType)289U
#define EXI_DIN_EVSECURRENT_LIMIT_ACHIEVED_TYPE                                          (Exi_RootElementIdType)290U
#define EXI_DIN_EVSECURRENT_REGULATION_TOLERANCE_TYPE                                    (Exi_RootElementIdType)291U
#define EXI_DIN_EVSEENERGY_TO_BE_DELIVERED_TYPE                                          (Exi_RootElementIdType)292U
#define EXI_DIN_EVSEID_TYPE                                                              (Exi_RootElementIdType)293U
#define EXI_DIN_EVSEISOLATION_STATUS_TYPE                                                (Exi_RootElementIdType)294U
#define EXI_DIN_EVSEMAX_CURRENT_TYPE                                                     (Exi_RootElementIdType)295U
#define EXI_DIN_EVSEMAX_VOLTAGE_TYPE                                                     (Exi_RootElementIdType)296U
#define EXI_DIN_EVSEMAXIMUM_CURRENT_LIMIT_TYPE                                           (Exi_RootElementIdType)297U
#define EXI_DIN_EVSEMAXIMUM_POWER_LIMIT_TYPE                                             (Exi_RootElementIdType)298U
#define EXI_DIN_EVSEMAXIMUM_VOLTAGE_LIMIT_TYPE                                           (Exi_RootElementIdType)299U
#define EXI_DIN_EVSEMIN_CURRENT_TYPE                                                     (Exi_RootElementIdType)300U
#define EXI_DIN_EVSEMINIMUM_CURRENT_LIMIT_TYPE                                           (Exi_RootElementIdType)301U
#define EXI_DIN_EVSEMINIMUM_VOLTAGE_LIMIT_TYPE                                           (Exi_RootElementIdType)302U
#define EXI_DIN_EVSENOTIFICATION_TYPE                                                    (Exi_RootElementIdType)303U
#define EXI_DIN_EVSEPEAK_CURRENT_RIPPLE_TYPE                                             (Exi_RootElementIdType)304U
#define EXI_DIN_EVSEPOWER_LIMIT_ACHIEVED_TYPE                                            (Exi_RootElementIdType)305U
#define EXI_DIN_EVSEPRESENT_CURRENT_TYPE                                                 (Exi_RootElementIdType)306U
#define EXI_DIN_EVSEPRESENT_VOLTAGE_TYPE                                                 (Exi_RootElementIdType)307U
#define EXI_DIN_EVSEPROCESSING_TYPE                                                      (Exi_RootElementIdType)308U
#define EXI_DIN_EVSESTATUS_CODE_TYPE                                                     (Exi_RootElementIdType)309U
#define EXI_DIN_EVSEVOLTAGE_LIMIT_ACHIEVED_TYPE                                          (Exi_RootElementIdType)310U
#define EXI_DIN_EVTARGET_CURRENT_TYPE                                                    (Exi_RootElementIdType)311U
#define EXI_DIN_EVTARGET_VOLTAGE_TYPE                                                    (Exi_RootElementIdType)312U
#define EXI_DIN_ENERGY_TRANSFER_TYPE_TYPE                                                (Exi_RootElementIdType)313U
#define EXI_DIN_FAULT_CODE_TYPE                                                          (Exi_RootElementIdType)314U
#define EXI_DIN_FAULT_MSG_TYPE                                                           (Exi_RootElementIdType)315U
#define EXI_DIN_FREE_SERVICE_TYPE                                                        (Exi_RootElementIdType)316U
#define EXI_DIN_FULL_SOC_TYPE                                                            (Exi_RootElementIdType)317U
#define EXI_DIN_GEN_CHALLENGE_TYPE                                                       (Exi_RootElementIdType)318U
#define EXI_DIN_HEADER_TYPE                                                              (Exi_RootElementIdType)319U
#define EXI_DIN_LIST_OF_ROOT_CERTIFICATE_IDS_TYPE                                        (Exi_RootElementIdType)320U
#define EXI_DIN_METER_ID_TYPE                                                            (Exi_RootElementIdType)321U
#define EXI_DIN_METER_INFO_TYPE                                                          (Exi_RootElementIdType)322U
#define EXI_DIN_METER_READING_TYPE                                                       (Exi_RootElementIdType)323U
#define EXI_DIN_METER_STATUS_TYPE                                                        (Exi_RootElementIdType)324U
#define EXI_DIN_MULTIPLIER_TYPE                                                          (Exi_RootElementIdType)325U
#define EXI_DIN_NOTIFICATION_TYPE                                                        (Exi_RootElementIdType)326U
#define EXI_DIN_NOTIFICATION_MAX_DELAY_TYPE                                              (Exi_RootElementIdType)327U
#define EXI_DIN_NUM_EPRICE_LEVELS_TYPE                                                   (Exi_RootElementIdType)328U
#define EXI_DIN_OEMPROVISIONING_CERT_TYPE                                                (Exi_RootElementIdType)329U
#define EXI_DIN_PMAX_TYPE                                                                (Exi_RootElementIdType)330U
#define EXI_DIN_PMAX_SCHEDULE_TYPE                                                       (Exi_RootElementIdType)331U
#define EXI_DIN_PMAX_SCHEDULE_ID_TYPE                                                    (Exi_RootElementIdType)332U
#define EXI_DIN_PARAMETER_TYPE                                                           (Exi_RootElementIdType)333U
#define EXI_DIN_PARAMETER_SET_TYPE                                                       (Exi_RootElementIdType)334U
#define EXI_DIN_PARAMETER_SET_ID_TYPE                                                    (Exi_RootElementIdType)335U
#define EXI_DIN_PAYMENT_OPTION_TYPE                                                      (Exi_RootElementIdType)336U
#define EXI_DIN_PAYMENT_OPTIONS_TYPE                                                     (Exi_RootElementIdType)337U
#define EXI_DIN_POWER_SWITCH_CLOSED_TYPE                                                 (Exi_RootElementIdType)338U
#define EXI_DIN_PROFILE_ENTRY_TYPE                                                       (Exi_RootElementIdType)339U
#define EXI_DIN_RCD_TYPE                                                                 (Exi_RootElementIdType)340U
#define EXI_DIN_READY_TO_CHARGE_STATE_TYPE                                               (Exi_RootElementIdType)341U
#define EXI_DIN_RECEIPT_REQUIRED_TYPE                                                    (Exi_RootElementIdType)342U
#define EXI_DIN_REMAINING_TIME_TO_BULK_SO_C_TYPE                                         (Exi_RootElementIdType)343U
#define EXI_DIN_REMAINING_TIME_TO_FULL_SO_C_TYPE                                         (Exi_RootElementIdType)344U
#define EXI_DIN_RESPONSE_CODE_TYPE                                                       (Exi_RootElementIdType)345U
#define EXI_DIN_RETRY_COUNTER_TYPE                                                       (Exi_RootElementIdType)346U
#define EXI_DIN_ROOT_CERTIFICATE_ID_TYPE                                                 (Exi_RootElementIdType)347U
#define EXI_DIN_SASCHEDULE_TUPLE_TYPE                                                    (Exi_RootElementIdType)348U
#define EXI_DIN_SASCHEDULE_TUPLE_ID_TYPE                                                 (Exi_RootElementIdType)349U
#define EXI_DIN_SALES_TARIFF_TYPE                                                        (Exi_RootElementIdType)350U
#define EXI_DIN_SALES_TARIFF_DESCRIPTION_TYPE                                            (Exi_RootElementIdType)351U
#define EXI_DIN_SALES_TARIFF_ID_TYPE                                                     (Exi_RootElementIdType)352U
#define EXI_DIN_SELECTED_PAYMENT_OPTION_TYPE                                             (Exi_RootElementIdType)353U
#define EXI_DIN_SELECTED_SERVICE_TYPE                                                    (Exi_RootElementIdType)354U
#define EXI_DIN_SELECTED_SERVICE_LIST_TYPE                                               (Exi_RootElementIdType)355U
#define EXI_DIN_SERVICE_TYPE                                                             (Exi_RootElementIdType)356U
#define EXI_DIN_SERVICE_CATEGORY_TYPE                                                    (Exi_RootElementIdType)357U
#define EXI_DIN_SERVICE_ID_TYPE                                                          (Exi_RootElementIdType)358U
#define EXI_DIN_SERVICE_LIST_TYPE                                                        (Exi_RootElementIdType)359U
#define EXI_DIN_SERVICE_NAME_TYPE                                                        (Exi_RootElementIdType)360U
#define EXI_DIN_SERVICE_PARAMETER_LIST_TYPE                                              (Exi_RootElementIdType)361U
#define EXI_DIN_SERVICE_SCOPE_TYPE                                                       (Exi_RootElementIdType)362U
#define EXI_DIN_SERVICE_TAG_TYPE                                                         (Exi_RootElementIdType)363U
#define EXI_DIN_SESSION_ID_TYPE                                                          (Exi_RootElementIdType)364U
#define EXI_DIN_SIG_METER_READING_TYPE                                                   (Exi_RootElementIdType)365U
#define EXI_DIN_SIGNATURE_TYPE                                                           (Exi_RootElementIdType)366U
#define EXI_DIN_SUB_CERTIFICATES_TYPE                                                    (Exi_RootElementIdType)367U
#define EXI_DIN_TMETER_TYPE                                                              (Exi_RootElementIdType)368U
#define EXI_DIN_TIME_INTERVAL_TYPE                                                       (Exi_RootElementIdType)369U
#define EXI_DIN_UNIT_TYPE                                                                (Exi_RootElementIdType)370U
#define EXI_DIN_VALUE_TYPE                                                               (Exi_RootElementIdType)371U
#define EXI_DIN_AMOUNT_TYPE                                                              (Exi_RootElementIdType)372U
#define EXI_DIN_AMOUNT_MULTIPLIER_TYPE                                                   (Exi_RootElementIdType)373U
#define EXI_DIN_BOOL_VALUE_TYPE                                                          (Exi_RootElementIdType)374U
#define EXI_DIN_BYTE_VALUE_TYPE                                                          (Exi_RootElementIdType)375U
#define EXI_DIN_COST_KIND_TYPE                                                           (Exi_RootElementIdType)376U
#define EXI_DIN_DURATION_TYPE                                                            (Exi_RootElementIdType)377U
#define EXI_DIN_INT_VALUE_TYPE                                                           (Exi_RootElementIdType)378U
#define EXI_DIN_PHYSICAL_VALUE_TYPE                                                      (Exi_RootElementIdType)379U
#define EXI_DIN_SHORT_VALUE_TYPE                                                         (Exi_RootElementIdType)380U
#define EXI_DIN_START_TYPE                                                               (Exi_RootElementIdType)381U
#define EXI_DIN_START_VALUE_TYPE                                                         (Exi_RootElementIdType)382U
#define EXI_DIN_STRING_VALUE_TYPE                                                        (Exi_RootElementIdType)383U
#define EXI_SCHEMA_SET_DIN_TYPE                                                          (Exi_RootElementIdType)2U
#ifndef EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTEID
  #define EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTEID EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTENAME
  #define EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTENAME EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_DIN_GENCHALLENGE
  #define EXI_MAX_BUFFER_SIZE_DIN_GENCHALLENGE EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif

/**********************************************************************************************************************
 *  ELEMENT IDENTIFIER DEFINES
**********************************************************************************************************************/
#define EXI_DIN_EI_DEPARTURE_TIME                                     (uint16)0U
#define EXI_DIN_EI_DEPARTURE_TIME_SE                                  (uint16)1U
#define EXI_DIN_EI_DEPARTURE_TIME_CT                                  (uint16)2U
#define EXI_DIN_EI_DEPARTURE_TIME_EE                                  (uint16)3U
#define EXI_DIN_EI_DEPARTURE_TIME_AT                                  (uint16)4U
#define EXI_DIN_EI_EAMOUNT                                            (uint16)5U
#define EXI_DIN_EI_EAMOUNT_SE                                         (uint16)6U
#define EXI_DIN_EI_EAMOUNT_CT                                         (uint16)7U
#define EXI_DIN_EI_EAMOUNT_EE                                         (uint16)8U
#define EXI_DIN_EI_EAMOUNT_AT                                         (uint16)9U
#define EXI_DIN_EI_EVMAX_VOLTAGE                                      (uint16)10U
#define EXI_DIN_EI_EVMAX_VOLTAGE_SE                                   (uint16)11U
#define EXI_DIN_EI_EVMAX_VOLTAGE_CT                                   (uint16)12U
#define EXI_DIN_EI_EVMAX_VOLTAGE_EE                                   (uint16)13U
#define EXI_DIN_EI_EVMAX_VOLTAGE_AT                                   (uint16)14U
#define EXI_DIN_EI_EVMAX_CURRENT                                      (uint16)15U
#define EXI_DIN_EI_EVMAX_CURRENT_SE                                   (uint16)16U
#define EXI_DIN_EI_EVMAX_CURRENT_CT                                   (uint16)17U
#define EXI_DIN_EI_EVMAX_CURRENT_EE                                   (uint16)18U
#define EXI_DIN_EI_EVMAX_CURRENT_AT                                   (uint16)19U
#define EXI_DIN_EI_EVMIN_CURRENT                                      (uint16)20U
#define EXI_DIN_EI_EVMIN_CURRENT_SE                                   (uint16)21U
#define EXI_DIN_EI_EVMIN_CURRENT_CT                                   (uint16)22U
#define EXI_DIN_EI_EVMIN_CURRENT_EE                                   (uint16)23U
#define EXI_DIN_EI_EVMIN_CURRENT_AT                                   (uint16)24U
#define EXI_DIN_EI_AC_EVCHARGE_PARAMETER                              (uint16)25U
#define EXI_DIN_EI_AC_EVCHARGE_PARAMETER_SE                           (uint16)26U
#define EXI_DIN_EI_AC_EVCHARGE_PARAMETER_CT                           (uint16)27U
#define EXI_DIN_EI_AC_EVCHARGE_PARAMETER_EE                           (uint16)28U
#define EXI_DIN_EI_AC_EVCHARGE_PARAMETER_AT                           (uint16)29U
#define EXI_DIN_EI_AC_EVSESTATUS                                      (uint16)30U
#define EXI_DIN_EI_AC_EVSESTATUS_SE                                   (uint16)31U
#define EXI_DIN_EI_AC_EVSESTATUS_CT                                   (uint16)32U
#define EXI_DIN_EI_AC_EVSESTATUS_EE                                   (uint16)33U
#define EXI_DIN_EI_AC_EVSESTATUS_AT                                   (uint16)34U
#define EXI_DIN_EI_EVSEMAX_VOLTAGE                                    (uint16)35U
#define EXI_DIN_EI_EVSEMAX_VOLTAGE_SE                                 (uint16)36U
#define EXI_DIN_EI_EVSEMAX_VOLTAGE_CT                                 (uint16)37U
#define EXI_DIN_EI_EVSEMAX_VOLTAGE_EE                                 (uint16)38U
#define EXI_DIN_EI_EVSEMAX_VOLTAGE_AT                                 (uint16)39U
#define EXI_DIN_EI_EVSEMAX_CURRENT                                    (uint16)40U
#define EXI_DIN_EI_EVSEMAX_CURRENT_SE                                 (uint16)41U
#define EXI_DIN_EI_EVSEMAX_CURRENT_CT                                 (uint16)42U
#define EXI_DIN_EI_EVSEMAX_CURRENT_EE                                 (uint16)43U
#define EXI_DIN_EI_EVSEMAX_CURRENT_AT                                 (uint16)44U
#define EXI_DIN_EI_EVSEMIN_CURRENT                                    (uint16)45U
#define EXI_DIN_EI_EVSEMIN_CURRENT_SE                                 (uint16)46U
#define EXI_DIN_EI_EVSEMIN_CURRENT_CT                                 (uint16)47U
#define EXI_DIN_EI_EVSEMIN_CURRENT_EE                                 (uint16)48U
#define EXI_DIN_EI_EVSEMIN_CURRENT_AT                                 (uint16)49U
#define EXI_DIN_EI_AC_EVSECHARGE_PARAMETER                            (uint16)50U
#define EXI_DIN_EI_AC_EVSECHARGE_PARAMETER_SE                         (uint16)51U
#define EXI_DIN_EI_AC_EVSECHARGE_PARAMETER_CT                         (uint16)52U
#define EXI_DIN_EI_AC_EVSECHARGE_PARAMETER_EE                         (uint16)53U
#define EXI_DIN_EI_AC_EVSECHARGE_PARAMETER_AT                         (uint16)54U
#define EXI_DIN_EI_POWER_SWITCH_CLOSED                                (uint16)55U
#define EXI_DIN_EI_POWER_SWITCH_CLOSED_SE                             (uint16)56U
#define EXI_DIN_EI_POWER_SWITCH_CLOSED_CT                             (uint16)57U
#define EXI_DIN_EI_POWER_SWITCH_CLOSED_EE                             (uint16)58U
#define EXI_DIN_EI_POWER_SWITCH_CLOSED_AT                             (uint16)59U
#define EXI_DIN_EI_RCD                                                (uint16)60U
#define EXI_DIN_EI_RCD_SE                                             (uint16)61U
#define EXI_DIN_EI_RCD_CT                                             (uint16)62U
#define EXI_DIN_EI_RCD_EE                                             (uint16)63U
#define EXI_DIN_EI_RCD_AT                                             (uint16)64U
#define EXI_DIN_EI_NOTIFICATION_MAX_DELAY                             (uint16)65U
#define EXI_DIN_EI_NOTIFICATION_MAX_DELAY_SE                          (uint16)66U
#define EXI_DIN_EI_NOTIFICATION_MAX_DELAY_CT                          (uint16)67U
#define EXI_DIN_EI_NOTIFICATION_MAX_DELAY_EE                          (uint16)68U
#define EXI_DIN_EI_NOTIFICATION_MAX_DELAY_AT                          (uint16)69U
#define EXI_DIN_EI_EVSENOTIFICATION                                   (uint16)70U
#define EXI_DIN_EI_EVSENOTIFICATION_SE                                (uint16)71U
#define EXI_DIN_EI_EVSENOTIFICATION_CT                                (uint16)72U
#define EXI_DIN_EI_EVSENOTIFICATION_EE                                (uint16)73U
#define EXI_DIN_EI_EVSENOTIFICATION_AT                                (uint16)74U
#define EXI_DIN_EI_ATTRIBUTE_ID                                       (uint16)75U
#define EXI_DIN_EI_ATTRIBUTE_ID_SE                                    (uint16)76U
#define EXI_DIN_EI_ATTRIBUTE_ID_CT                                    (uint16)77U
#define EXI_DIN_EI_ATTRIBUTE_ID_EE                                    (uint16)78U
#define EXI_DIN_EI_ATTRIBUTE_ID_AT                                    (uint16)79U
#define EXI_DIN_EI_ATTRIBUTE_NAME                                     (uint16)80U
#define EXI_DIN_EI_ATTRIBUTE_NAME_SE                                  (uint16)81U
#define EXI_DIN_EI_ATTRIBUTE_NAME_CT                                  (uint16)82U
#define EXI_DIN_EI_ATTRIBUTE_NAME_EE                                  (uint16)83U
#define EXI_DIN_EI_ATTRIBUTE_NAME_AT                                  (uint16)84U
#define EXI_DIN_EI_ATTRIBUTE_VALUE                                    (uint16)85U
#define EXI_DIN_EI_ATTRIBUTE_VALUE_SE                                 (uint16)86U
#define EXI_DIN_EI_ATTRIBUTE_VALUE_CT                                 (uint16)87U
#define EXI_DIN_EI_ATTRIBUTE_VALUE_EE                                 (uint16)88U
#define EXI_DIN_EI_ATTRIBUTE_VALUE_AT                                 (uint16)89U
#define EXI_DIN_EI_BODY_ELEMENT                                       (uint16)90U
#define EXI_DIN_EI_BODY_ELEMENT_SE                                    (uint16)91U
#define EXI_DIN_EI_BODY_ELEMENT_CT                                    (uint16)92U
#define EXI_DIN_EI_BODY_ELEMENT_EE                                    (uint16)93U
#define EXI_DIN_EI_BODY_ELEMENT_AT                                    (uint16)94U
#define EXI_DIN_EI_DC_EVSTATUS                                        (uint16)95U
#define EXI_DIN_EI_DC_EVSTATUS_SE                                     (uint16)96U
#define EXI_DIN_EI_DC_EVSTATUS_CT                                     (uint16)97U
#define EXI_DIN_EI_DC_EVSTATUS_EE                                     (uint16)98U
#define EXI_DIN_EI_DC_EVSTATUS_AT                                     (uint16)99U
#define EXI_DIN_EI_CABLE_CHECK_REQ                                    (uint16)100U
#define EXI_DIN_EI_CABLE_CHECK_REQ_SE                                 (uint16)101U
#define EXI_DIN_EI_CABLE_CHECK_REQ_CT                                 (uint16)102U
#define EXI_DIN_EI_CABLE_CHECK_REQ_EE                                 (uint16)103U
#define EXI_DIN_EI_CABLE_CHECK_REQ_AT                                 (uint16)104U
#define EXI_DIN_EI_RESPONSE_CODE                                      (uint16)105U
#define EXI_DIN_EI_RESPONSE_CODE_SE                                   (uint16)106U
#define EXI_DIN_EI_RESPONSE_CODE_CT                                   (uint16)107U
#define EXI_DIN_EI_RESPONSE_CODE_EE                                   (uint16)108U
#define EXI_DIN_EI_RESPONSE_CODE_AT                                   (uint16)109U
#define EXI_DIN_EI_DC_EVSESTATUS                                      (uint16)110U
#define EXI_DIN_EI_DC_EVSESTATUS_SE                                   (uint16)111U
#define EXI_DIN_EI_DC_EVSESTATUS_CT                                   (uint16)112U
#define EXI_DIN_EI_DC_EVSESTATUS_EE                                   (uint16)113U
#define EXI_DIN_EI_DC_EVSESTATUS_AT                                   (uint16)114U
#define EXI_DIN_EI_EVSEPROCESSING                                     (uint16)115U
#define EXI_DIN_EI_EVSEPROCESSING_SE                                  (uint16)116U
#define EXI_DIN_EI_EVSEPROCESSING_CT                                  (uint16)117U
#define EXI_DIN_EI_EVSEPROCESSING_EE                                  (uint16)118U
#define EXI_DIN_EI_EVSEPROCESSING_AT                                  (uint16)119U
#define EXI_DIN_EI_CABLE_CHECK_RES                                    (uint16)120U
#define EXI_DIN_EI_CABLE_CHECK_RES_SE                                 (uint16)121U
#define EXI_DIN_EI_CABLE_CHECK_RES_CT                                 (uint16)122U
#define EXI_DIN_EI_CABLE_CHECK_RES_EE                                 (uint16)123U
#define EXI_DIN_EI_CABLE_CHECK_RES_AT                                 (uint16)124U
#define EXI_DIN_EI_CERTIFICATE                                        (uint16)125U
#define EXI_DIN_EI_CERTIFICATE_SE                                     (uint16)126U
#define EXI_DIN_EI_CERTIFICATE_CT                                     (uint16)127U
#define EXI_DIN_EI_CERTIFICATE_EE                                     (uint16)128U
#define EXI_DIN_EI_CERTIFICATE_AT                                     (uint16)129U
#define EXI_DIN_EI_SUB_CERTIFICATES                                   (uint16)130U
#define EXI_DIN_EI_SUB_CERTIFICATES_SE                                (uint16)131U
#define EXI_DIN_EI_SUB_CERTIFICATES_CT                                (uint16)132U
#define EXI_DIN_EI_SUB_CERTIFICATES_EE                                (uint16)133U
#define EXI_DIN_EI_SUB_CERTIFICATES_AT                                (uint16)134U
#define EXI_DIN_EI_ID                                                 (uint16)135U
#define EXI_DIN_EI_ID_SE                                              (uint16)136U
#define EXI_DIN_EI_ID_CT                                              (uint16)137U
#define EXI_DIN_EI_ID_EE                                              (uint16)138U
#define EXI_DIN_EI_ID_AT                                              (uint16)139U
#define EXI_DIN_EI_OEMPROVISIONING_CERT                               (uint16)140U
#define EXI_DIN_EI_OEMPROVISIONING_CERT_SE                            (uint16)141U
#define EXI_DIN_EI_OEMPROVISIONING_CERT_CT                            (uint16)142U
#define EXI_DIN_EI_OEMPROVISIONING_CERT_EE                            (uint16)143U
#define EXI_DIN_EI_OEMPROVISIONING_CERT_AT                            (uint16)144U
#define EXI_DIN_EI_LIST_OF_ROOT_CERTIFICATE_IDS                       (uint16)145U
#define EXI_DIN_EI_LIST_OF_ROOT_CERTIFICATE_IDS_SE                    (uint16)146U
#define EXI_DIN_EI_LIST_OF_ROOT_CERTIFICATE_IDS_CT                    (uint16)147U
#define EXI_DIN_EI_LIST_OF_ROOT_CERTIFICATE_IDS_EE                    (uint16)148U
#define EXI_DIN_EI_LIST_OF_ROOT_CERTIFICATE_IDS_AT                    (uint16)149U
#define EXI_DIN_EI_DHPARAMS                                           (uint16)150U
#define EXI_DIN_EI_DHPARAMS_SE                                        (uint16)151U
#define EXI_DIN_EI_DHPARAMS_CT                                        (uint16)152U
#define EXI_DIN_EI_DHPARAMS_EE                                        (uint16)153U
#define EXI_DIN_EI_DHPARAMS_AT                                        (uint16)154U
#define EXI_DIN_EI_CERTIFICATE_INSTALLATION_REQ                       (uint16)155U
#define EXI_DIN_EI_CERTIFICATE_INSTALLATION_REQ_SE                    (uint16)156U
#define EXI_DIN_EI_CERTIFICATE_INSTALLATION_REQ_CT                    (uint16)157U
#define EXI_DIN_EI_CERTIFICATE_INSTALLATION_REQ_EE                    (uint16)158U
#define EXI_DIN_EI_CERTIFICATE_INSTALLATION_REQ_AT                    (uint16)159U
#define EXI_DIN_EI_CONTRACT_SIGNATURE_CERT_CHAIN                      (uint16)160U
#define EXI_DIN_EI_CONTRACT_SIGNATURE_CERT_CHAIN_SE                   (uint16)161U
#define EXI_DIN_EI_CONTRACT_SIGNATURE_CERT_CHAIN_CT                   (uint16)162U
#define EXI_DIN_EI_CONTRACT_SIGNATURE_CERT_CHAIN_EE                   (uint16)163U
#define EXI_DIN_EI_CONTRACT_SIGNATURE_CERT_CHAIN_AT                   (uint16)164U
#define EXI_DIN_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY           (uint16)165U
#define EXI_DIN_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_SE        (uint16)166U
#define EXI_DIN_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_CT        (uint16)167U
#define EXI_DIN_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_EE        (uint16)168U
#define EXI_DIN_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_AT        (uint16)169U
#define EXI_DIN_EI_CONTRACT_ID                                        (uint16)170U
#define EXI_DIN_EI_CONTRACT_ID_SE                                     (uint16)171U
#define EXI_DIN_EI_CONTRACT_ID_CT                                     (uint16)172U
#define EXI_DIN_EI_CONTRACT_ID_EE                                     (uint16)173U
#define EXI_DIN_EI_CONTRACT_ID_AT                                     (uint16)174U
#define EXI_DIN_EI_CERTIFICATE_INSTALLATION_RES                       (uint16)175U
#define EXI_DIN_EI_CERTIFICATE_INSTALLATION_RES_SE                    (uint16)176U
#define EXI_DIN_EI_CERTIFICATE_INSTALLATION_RES_CT                    (uint16)177U
#define EXI_DIN_EI_CERTIFICATE_INSTALLATION_RES_EE                    (uint16)178U
#define EXI_DIN_EI_CERTIFICATE_INSTALLATION_RES_AT                    (uint16)179U
#define EXI_DIN_EI_CERTIFICATE_UPDATE_REQ                             (uint16)180U
#define EXI_DIN_EI_CERTIFICATE_UPDATE_REQ_SE                          (uint16)181U
#define EXI_DIN_EI_CERTIFICATE_UPDATE_REQ_CT                          (uint16)182U
#define EXI_DIN_EI_CERTIFICATE_UPDATE_REQ_EE                          (uint16)183U
#define EXI_DIN_EI_CERTIFICATE_UPDATE_REQ_AT                          (uint16)184U
#define EXI_DIN_EI_RETRY_COUNTER                                      (uint16)185U
#define EXI_DIN_EI_RETRY_COUNTER_SE                                   (uint16)186U
#define EXI_DIN_EI_RETRY_COUNTER_CT                                   (uint16)187U
#define EXI_DIN_EI_RETRY_COUNTER_EE                                   (uint16)188U
#define EXI_DIN_EI_RETRY_COUNTER_AT                                   (uint16)189U
#define EXI_DIN_EI_CERTIFICATE_UPDATE_RES                             (uint16)190U
#define EXI_DIN_EI_CERTIFICATE_UPDATE_RES_SE                          (uint16)191U
#define EXI_DIN_EI_CERTIFICATE_UPDATE_RES_CT                          (uint16)192U
#define EXI_DIN_EI_CERTIFICATE_UPDATE_RES_EE                          (uint16)193U
#define EXI_DIN_EI_CERTIFICATE_UPDATE_RES_AT                          (uint16)194U
#define EXI_DIN_EI_EVREQUESTED_ENERGY_TRANSFER_TYPE                   (uint16)195U
#define EXI_DIN_EI_EVREQUESTED_ENERGY_TRANSFER_TYPE_SE                (uint16)196U
#define EXI_DIN_EI_EVREQUESTED_ENERGY_TRANSFER_TYPE_CT                (uint16)197U
#define EXI_DIN_EI_EVREQUESTED_ENERGY_TRANSFER_TYPE_EE                (uint16)198U
#define EXI_DIN_EI_EVREQUESTED_ENERGY_TRANSFER_TYPE_AT                (uint16)199U
#define EXI_DIN_EI_EVCHARGE_PARAMETER                                 (uint16)200U
#define EXI_DIN_EI_EVCHARGE_PARAMETER_SE                              (uint16)201U
#define EXI_DIN_EI_EVCHARGE_PARAMETER_CT                              (uint16)202U
#define EXI_DIN_EI_EVCHARGE_PARAMETER_EE                              (uint16)203U
#define EXI_DIN_EI_EVCHARGE_PARAMETER_AT                              (uint16)204U
#define EXI_DIN_EI_CHARGE_PARAMETER_DISCOVERY_REQ                     (uint16)205U
#define EXI_DIN_EI_CHARGE_PARAMETER_DISCOVERY_REQ_SE                  (uint16)206U
#define EXI_DIN_EI_CHARGE_PARAMETER_DISCOVERY_REQ_CT                  (uint16)207U
#define EXI_DIN_EI_CHARGE_PARAMETER_DISCOVERY_REQ_EE                  (uint16)208U
#define EXI_DIN_EI_CHARGE_PARAMETER_DISCOVERY_REQ_AT                  (uint16)209U
#define EXI_DIN_EI_SASCHEDULES                                        (uint16)210U
#define EXI_DIN_EI_SASCHEDULES_SE                                     (uint16)211U
#define EXI_DIN_EI_SASCHEDULES_CT                                     (uint16)212U
#define EXI_DIN_EI_SASCHEDULES_EE                                     (uint16)213U
#define EXI_DIN_EI_SASCHEDULES_AT                                     (uint16)214U
#define EXI_DIN_EI_EVSECHARGE_PARAMETER                               (uint16)215U
#define EXI_DIN_EI_EVSECHARGE_PARAMETER_SE                            (uint16)216U
#define EXI_DIN_EI_EVSECHARGE_PARAMETER_CT                            (uint16)217U
#define EXI_DIN_EI_EVSECHARGE_PARAMETER_EE                            (uint16)218U
#define EXI_DIN_EI_EVSECHARGE_PARAMETER_AT                            (uint16)219U
#define EXI_DIN_EI_CHARGE_PARAMETER_DISCOVERY_RES                     (uint16)220U
#define EXI_DIN_EI_CHARGE_PARAMETER_DISCOVERY_RES_SE                  (uint16)221U
#define EXI_DIN_EI_CHARGE_PARAMETER_DISCOVERY_RES_CT                  (uint16)222U
#define EXI_DIN_EI_CHARGE_PARAMETER_DISCOVERY_RES_EE                  (uint16)223U
#define EXI_DIN_EI_CHARGE_PARAMETER_DISCOVERY_RES_AT                  (uint16)224U
#define EXI_DIN_EI_SASCHEDULE_TUPLE_ID                                (uint16)225U
#define EXI_DIN_EI_SASCHEDULE_TUPLE_ID_SE                             (uint16)226U
#define EXI_DIN_EI_SASCHEDULE_TUPLE_ID_CT                             (uint16)227U
#define EXI_DIN_EI_SASCHEDULE_TUPLE_ID_EE                             (uint16)228U
#define EXI_DIN_EI_SASCHEDULE_TUPLE_ID_AT                             (uint16)229U
#define EXI_DIN_EI_PROFILE_ENTRY                                      (uint16)230U
#define EXI_DIN_EI_PROFILE_ENTRY_SE                                   (uint16)231U
#define EXI_DIN_EI_PROFILE_ENTRY_CT                                   (uint16)232U
#define EXI_DIN_EI_PROFILE_ENTRY_EE                                   (uint16)233U
#define EXI_DIN_EI_PROFILE_ENTRY_AT                                   (uint16)234U
#define EXI_DIN_EI_EVSEID                                             (uint16)235U
#define EXI_DIN_EI_EVSEID_SE                                          (uint16)236U
#define EXI_DIN_EI_EVSEID_CT                                          (uint16)237U
#define EXI_DIN_EI_EVSEID_EE                                          (uint16)238U
#define EXI_DIN_EI_EVSEID_AT                                          (uint16)239U
#define EXI_DIN_EI_METER_INFO                                         (uint16)240U
#define EXI_DIN_EI_METER_INFO_SE                                      (uint16)241U
#define EXI_DIN_EI_METER_INFO_CT                                      (uint16)242U
#define EXI_DIN_EI_METER_INFO_EE                                      (uint16)243U
#define EXI_DIN_EI_METER_INFO_AT                                      (uint16)244U
#define EXI_DIN_EI_RECEIPT_REQUIRED                                   (uint16)245U
#define EXI_DIN_EI_RECEIPT_REQUIRED_SE                                (uint16)246U
#define EXI_DIN_EI_RECEIPT_REQUIRED_CT                                (uint16)247U
#define EXI_DIN_EI_RECEIPT_REQUIRED_EE                                (uint16)248U
#define EXI_DIN_EI_RECEIPT_REQUIRED_AT                                (uint16)249U
#define EXI_DIN_EI_CHARGING_STATUS_RES                                (uint16)250U
#define EXI_DIN_EI_CHARGING_STATUS_RES_SE                             (uint16)251U
#define EXI_DIN_EI_CHARGING_STATUS_RES_CT                             (uint16)252U
#define EXI_DIN_EI_CHARGING_STATUS_RES_EE                             (uint16)253U
#define EXI_DIN_EI_CHARGING_STATUS_RES_AT                             (uint16)254U
#define EXI_DIN_EI_START_VALUE                                        (uint16)255U
#define EXI_DIN_EI_START_VALUE_SE                                     (uint16)256U
#define EXI_DIN_EI_START_VALUE_CT                                     (uint16)257U
#define EXI_DIN_EI_START_VALUE_EE                                     (uint16)258U
#define EXI_DIN_EI_START_VALUE_AT                                     (uint16)259U
#define EXI_DIN_EI_COST                                               (uint16)260U
#define EXI_DIN_EI_COST_SE                                            (uint16)261U
#define EXI_DIN_EI_COST_CT                                            (uint16)262U
#define EXI_DIN_EI_COST_EE                                            (uint16)263U
#define EXI_DIN_EI_COST_AT                                            (uint16)264U
#define EXI_DIN_EI_GEN_CHALLENGE                                      (uint16)265U
#define EXI_DIN_EI_GEN_CHALLENGE_SE                                   (uint16)266U
#define EXI_DIN_EI_GEN_CHALLENGE_CT                                   (uint16)267U
#define EXI_DIN_EI_GEN_CHALLENGE_EE                                   (uint16)268U
#define EXI_DIN_EI_GEN_CHALLENGE_AT                                   (uint16)269U
#define EXI_DIN_EI_CONTRACT_AUTHENTICATION_REQ                        (uint16)270U
#define EXI_DIN_EI_CONTRACT_AUTHENTICATION_REQ_SE                     (uint16)271U
#define EXI_DIN_EI_CONTRACT_AUTHENTICATION_REQ_CT                     (uint16)272U
#define EXI_DIN_EI_CONTRACT_AUTHENTICATION_REQ_EE                     (uint16)273U
#define EXI_DIN_EI_CONTRACT_AUTHENTICATION_REQ_AT                     (uint16)274U
#define EXI_DIN_EI_CONTRACT_AUTHENTICATION_RES                        (uint16)275U
#define EXI_DIN_EI_CONTRACT_AUTHENTICATION_RES_SE                     (uint16)276U
#define EXI_DIN_EI_CONTRACT_AUTHENTICATION_RES_CT                     (uint16)277U
#define EXI_DIN_EI_CONTRACT_AUTHENTICATION_RES_EE                     (uint16)278U
#define EXI_DIN_EI_CONTRACT_AUTHENTICATION_RES_AT                     (uint16)279U
#define EXI_DIN_EI_COST_KIND                                          (uint16)280U
#define EXI_DIN_EI_COST_KIND_SE                                       (uint16)281U
#define EXI_DIN_EI_COST_KIND_CT                                       (uint16)282U
#define EXI_DIN_EI_COST_KIND_EE                                       (uint16)283U
#define EXI_DIN_EI_COST_KIND_AT                                       (uint16)284U
#define EXI_DIN_EI_AMOUNT                                             (uint16)285U
#define EXI_DIN_EI_AMOUNT_SE                                          (uint16)286U
#define EXI_DIN_EI_AMOUNT_CT                                          (uint16)287U
#define EXI_DIN_EI_AMOUNT_EE                                          (uint16)288U
#define EXI_DIN_EI_AMOUNT_AT                                          (uint16)289U
#define EXI_DIN_EI_AMOUNT_MULTIPLIER                                  (uint16)290U
#define EXI_DIN_EI_AMOUNT_MULTIPLIER_SE                               (uint16)291U
#define EXI_DIN_EI_AMOUNT_MULTIPLIER_CT                               (uint16)292U
#define EXI_DIN_EI_AMOUNT_MULTIPLIER_EE                               (uint16)293U
#define EXI_DIN_EI_AMOUNT_MULTIPLIER_AT                               (uint16)294U
#define EXI_DIN_EI_EVTARGET_CURRENT                                   (uint16)295U
#define EXI_DIN_EI_EVTARGET_CURRENT_SE                                (uint16)296U
#define EXI_DIN_EI_EVTARGET_CURRENT_CT                                (uint16)297U
#define EXI_DIN_EI_EVTARGET_CURRENT_EE                                (uint16)298U
#define EXI_DIN_EI_EVTARGET_CURRENT_AT                                (uint16)299U
#define EXI_DIN_EI_EVMAXIMUM_VOLTAGE_LIMIT                            (uint16)300U
#define EXI_DIN_EI_EVMAXIMUM_VOLTAGE_LIMIT_SE                         (uint16)301U
#define EXI_DIN_EI_EVMAXIMUM_VOLTAGE_LIMIT_CT                         (uint16)302U
#define EXI_DIN_EI_EVMAXIMUM_VOLTAGE_LIMIT_EE                         (uint16)303U
#define EXI_DIN_EI_EVMAXIMUM_VOLTAGE_LIMIT_AT                         (uint16)304U
#define EXI_DIN_EI_EVMAXIMUM_CURRENT_LIMIT                            (uint16)305U
#define EXI_DIN_EI_EVMAXIMUM_CURRENT_LIMIT_SE                         (uint16)306U
#define EXI_DIN_EI_EVMAXIMUM_CURRENT_LIMIT_CT                         (uint16)307U
#define EXI_DIN_EI_EVMAXIMUM_CURRENT_LIMIT_EE                         (uint16)308U
#define EXI_DIN_EI_EVMAXIMUM_CURRENT_LIMIT_AT                         (uint16)309U
#define EXI_DIN_EI_EVMAXIMUM_POWER_LIMIT                              (uint16)310U
#define EXI_DIN_EI_EVMAXIMUM_POWER_LIMIT_SE                           (uint16)311U
#define EXI_DIN_EI_EVMAXIMUM_POWER_LIMIT_CT                           (uint16)312U
#define EXI_DIN_EI_EVMAXIMUM_POWER_LIMIT_EE                           (uint16)313U
#define EXI_DIN_EI_EVMAXIMUM_POWER_LIMIT_AT                           (uint16)314U
#define EXI_DIN_EI_BULK_CHARGING_COMPLETE                             (uint16)315U
#define EXI_DIN_EI_BULK_CHARGING_COMPLETE_SE                          (uint16)316U
#define EXI_DIN_EI_BULK_CHARGING_COMPLETE_CT                          (uint16)317U
#define EXI_DIN_EI_BULK_CHARGING_COMPLETE_EE                          (uint16)318U
#define EXI_DIN_EI_BULK_CHARGING_COMPLETE_AT                          (uint16)319U
#define EXI_DIN_EI_CHARGING_COMPLETE                                  (uint16)320U
#define EXI_DIN_EI_CHARGING_COMPLETE_SE                               (uint16)321U
#define EXI_DIN_EI_CHARGING_COMPLETE_CT                               (uint16)322U
#define EXI_DIN_EI_CHARGING_COMPLETE_EE                               (uint16)323U
#define EXI_DIN_EI_CHARGING_COMPLETE_AT                               (uint16)324U
#define EXI_DIN_EI_REMAINING_TIME_TO_FULL_SO_C                        (uint16)325U
#define EXI_DIN_EI_REMAINING_TIME_TO_FULL_SO_C_SE                     (uint16)326U
#define EXI_DIN_EI_REMAINING_TIME_TO_FULL_SO_C_CT                     (uint16)327U
#define EXI_DIN_EI_REMAINING_TIME_TO_FULL_SO_C_EE                     (uint16)328U
#define EXI_DIN_EI_REMAINING_TIME_TO_FULL_SO_C_AT                     (uint16)329U
#define EXI_DIN_EI_REMAINING_TIME_TO_BULK_SO_C                        (uint16)330U
#define EXI_DIN_EI_REMAINING_TIME_TO_BULK_SO_C_SE                     (uint16)331U
#define EXI_DIN_EI_REMAINING_TIME_TO_BULK_SO_C_CT                     (uint16)332U
#define EXI_DIN_EI_REMAINING_TIME_TO_BULK_SO_C_EE                     (uint16)333U
#define EXI_DIN_EI_REMAINING_TIME_TO_BULK_SO_C_AT                     (uint16)334U
#define EXI_DIN_EI_EVTARGET_VOLTAGE                                   (uint16)335U
#define EXI_DIN_EI_EVTARGET_VOLTAGE_SE                                (uint16)336U
#define EXI_DIN_EI_EVTARGET_VOLTAGE_CT                                (uint16)337U
#define EXI_DIN_EI_EVTARGET_VOLTAGE_EE                                (uint16)338U
#define EXI_DIN_EI_EVTARGET_VOLTAGE_AT                                (uint16)339U
#define EXI_DIN_EI_CURRENT_DEMAND_REQ                                 (uint16)340U
#define EXI_DIN_EI_CURRENT_DEMAND_REQ_SE                              (uint16)341U
#define EXI_DIN_EI_CURRENT_DEMAND_REQ_CT                              (uint16)342U
#define EXI_DIN_EI_CURRENT_DEMAND_REQ_EE                              (uint16)343U
#define EXI_DIN_EI_CURRENT_DEMAND_REQ_AT                              (uint16)344U
#define EXI_DIN_EI_EVSEPRESENT_VOLTAGE                                (uint16)345U
#define EXI_DIN_EI_EVSEPRESENT_VOLTAGE_SE                             (uint16)346U
#define EXI_DIN_EI_EVSEPRESENT_VOLTAGE_CT                             (uint16)347U
#define EXI_DIN_EI_EVSEPRESENT_VOLTAGE_EE                             (uint16)348U
#define EXI_DIN_EI_EVSEPRESENT_VOLTAGE_AT                             (uint16)349U
#define EXI_DIN_EI_EVSEPRESENT_CURRENT                                (uint16)350U
#define EXI_DIN_EI_EVSEPRESENT_CURRENT_SE                             (uint16)351U
#define EXI_DIN_EI_EVSEPRESENT_CURRENT_CT                             (uint16)352U
#define EXI_DIN_EI_EVSEPRESENT_CURRENT_EE                             (uint16)353U
#define EXI_DIN_EI_EVSEPRESENT_CURRENT_AT                             (uint16)354U
#define EXI_DIN_EI_EVSECURRENT_LIMIT_ACHIEVED                         (uint16)355U
#define EXI_DIN_EI_EVSECURRENT_LIMIT_ACHIEVED_SE                      (uint16)356U
#define EXI_DIN_EI_EVSECURRENT_LIMIT_ACHIEVED_CT                      (uint16)357U
#define EXI_DIN_EI_EVSECURRENT_LIMIT_ACHIEVED_EE                      (uint16)358U
#define EXI_DIN_EI_EVSECURRENT_LIMIT_ACHIEVED_AT                      (uint16)359U
#define EXI_DIN_EI_EVSEVOLTAGE_LIMIT_ACHIEVED                         (uint16)360U
#define EXI_DIN_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_SE                      (uint16)361U
#define EXI_DIN_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_CT                      (uint16)362U
#define EXI_DIN_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_EE                      (uint16)363U
#define EXI_DIN_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_AT                      (uint16)364U
#define EXI_DIN_EI_EVSEPOWER_LIMIT_ACHIEVED                           (uint16)365U
#define EXI_DIN_EI_EVSEPOWER_LIMIT_ACHIEVED_SE                        (uint16)366U
#define EXI_DIN_EI_EVSEPOWER_LIMIT_ACHIEVED_CT                        (uint16)367U
#define EXI_DIN_EI_EVSEPOWER_LIMIT_ACHIEVED_EE                        (uint16)368U
#define EXI_DIN_EI_EVSEPOWER_LIMIT_ACHIEVED_AT                        (uint16)369U
#define EXI_DIN_EI_EVSEMAXIMUM_VOLTAGE_LIMIT                          (uint16)370U
#define EXI_DIN_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_SE                       (uint16)371U
#define EXI_DIN_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_CT                       (uint16)372U
#define EXI_DIN_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_EE                       (uint16)373U
#define EXI_DIN_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_AT                       (uint16)374U
#define EXI_DIN_EI_EVSEMAXIMUM_CURRENT_LIMIT                          (uint16)375U
#define EXI_DIN_EI_EVSEMAXIMUM_CURRENT_LIMIT_SE                       (uint16)376U
#define EXI_DIN_EI_EVSEMAXIMUM_CURRENT_LIMIT_CT                       (uint16)377U
#define EXI_DIN_EI_EVSEMAXIMUM_CURRENT_LIMIT_EE                       (uint16)378U
#define EXI_DIN_EI_EVSEMAXIMUM_CURRENT_LIMIT_AT                       (uint16)379U
#define EXI_DIN_EI_EVSEMAXIMUM_POWER_LIMIT                            (uint16)380U
#define EXI_DIN_EI_EVSEMAXIMUM_POWER_LIMIT_SE                         (uint16)381U
#define EXI_DIN_EI_EVSEMAXIMUM_POWER_LIMIT_CT                         (uint16)382U
#define EXI_DIN_EI_EVSEMAXIMUM_POWER_LIMIT_EE                         (uint16)383U
#define EXI_DIN_EI_EVSEMAXIMUM_POWER_LIMIT_AT                         (uint16)384U
#define EXI_DIN_EI_CURRENT_DEMAND_RES                                 (uint16)385U
#define EXI_DIN_EI_CURRENT_DEMAND_RES_SE                              (uint16)386U
#define EXI_DIN_EI_CURRENT_DEMAND_RES_CT                              (uint16)387U
#define EXI_DIN_EI_CURRENT_DEMAND_RES_EE                              (uint16)388U
#define EXI_DIN_EI_CURRENT_DEMAND_RES_AT                              (uint16)389U
#define EXI_DIN_EI_EVENERGY_CAPACITY                                  (uint16)390U
#define EXI_DIN_EI_EVENERGY_CAPACITY_SE                               (uint16)391U
#define EXI_DIN_EI_EVENERGY_CAPACITY_CT                               (uint16)392U
#define EXI_DIN_EI_EVENERGY_CAPACITY_EE                               (uint16)393U
#define EXI_DIN_EI_EVENERGY_CAPACITY_AT                               (uint16)394U
#define EXI_DIN_EI_EVENERGY_REQUEST                                   (uint16)395U
#define EXI_DIN_EI_EVENERGY_REQUEST_SE                                (uint16)396U
#define EXI_DIN_EI_EVENERGY_REQUEST_CT                                (uint16)397U
#define EXI_DIN_EI_EVENERGY_REQUEST_EE                                (uint16)398U
#define EXI_DIN_EI_EVENERGY_REQUEST_AT                                (uint16)399U
#define EXI_DIN_EI_FULL_SOC                                           (uint16)400U
#define EXI_DIN_EI_FULL_SOC_SE                                        (uint16)401U
#define EXI_DIN_EI_FULL_SOC_CT                                        (uint16)402U
#define EXI_DIN_EI_FULL_SOC_EE                                        (uint16)403U
#define EXI_DIN_EI_FULL_SOC_AT                                        (uint16)404U
#define EXI_DIN_EI_BULK_SOC                                           (uint16)405U
#define EXI_DIN_EI_BULK_SOC_SE                                        (uint16)406U
#define EXI_DIN_EI_BULK_SOC_CT                                        (uint16)407U
#define EXI_DIN_EI_BULK_SOC_EE                                        (uint16)408U
#define EXI_DIN_EI_BULK_SOC_AT                                        (uint16)409U
#define EXI_DIN_EI_DC_EVCHARGE_PARAMETER                              (uint16)410U
#define EXI_DIN_EI_DC_EVCHARGE_PARAMETER_SE                           (uint16)411U
#define EXI_DIN_EI_DC_EVCHARGE_PARAMETER_CT                           (uint16)412U
#define EXI_DIN_EI_DC_EVCHARGE_PARAMETER_EE                           (uint16)413U
#define EXI_DIN_EI_DC_EVCHARGE_PARAMETER_AT                           (uint16)414U
#define EXI_DIN_EI_DC_EVERROR_CODE                                    (uint16)415U
#define EXI_DIN_EI_DC_EVERROR_CODE_SE                                 (uint16)416U
#define EXI_DIN_EI_DC_EVERROR_CODE_CT                                 (uint16)417U
#define EXI_DIN_EI_DC_EVERROR_CODE_EE                                 (uint16)418U
#define EXI_DIN_EI_DC_EVERROR_CODE_AT                                 (uint16)419U
#define EXI_DIN_EI_DC_EVPOWER_DELIVERY_PARAMETER                      (uint16)420U
#define EXI_DIN_EI_DC_EVPOWER_DELIVERY_PARAMETER_SE                   (uint16)421U
#define EXI_DIN_EI_DC_EVPOWER_DELIVERY_PARAMETER_CT                   (uint16)422U
#define EXI_DIN_EI_DC_EVPOWER_DELIVERY_PARAMETER_EE                   (uint16)423U
#define EXI_DIN_EI_DC_EVPOWER_DELIVERY_PARAMETER_AT                   (uint16)424U
#define EXI_DIN_EI_EVSEMINIMUM_CURRENT_LIMIT                          (uint16)425U
#define EXI_DIN_EI_EVSEMINIMUM_CURRENT_LIMIT_SE                       (uint16)426U
#define EXI_DIN_EI_EVSEMINIMUM_CURRENT_LIMIT_CT                       (uint16)427U
#define EXI_DIN_EI_EVSEMINIMUM_CURRENT_LIMIT_EE                       (uint16)428U
#define EXI_DIN_EI_EVSEMINIMUM_CURRENT_LIMIT_AT                       (uint16)429U
#define EXI_DIN_EI_EVSEMINIMUM_VOLTAGE_LIMIT                          (uint16)430U
#define EXI_DIN_EI_EVSEMINIMUM_VOLTAGE_LIMIT_SE                       (uint16)431U
#define EXI_DIN_EI_EVSEMINIMUM_VOLTAGE_LIMIT_CT                       (uint16)432U
#define EXI_DIN_EI_EVSEMINIMUM_VOLTAGE_LIMIT_EE                       (uint16)433U
#define EXI_DIN_EI_EVSEMINIMUM_VOLTAGE_LIMIT_AT                       (uint16)434U
#define EXI_DIN_EI_EVSECURRENT_REGULATION_TOLERANCE                   (uint16)435U
#define EXI_DIN_EI_EVSECURRENT_REGULATION_TOLERANCE_SE                (uint16)436U
#define EXI_DIN_EI_EVSECURRENT_REGULATION_TOLERANCE_CT                (uint16)437U
#define EXI_DIN_EI_EVSECURRENT_REGULATION_TOLERANCE_EE                (uint16)438U
#define EXI_DIN_EI_EVSECURRENT_REGULATION_TOLERANCE_AT                (uint16)439U
#define EXI_DIN_EI_EVSEPEAK_CURRENT_RIPPLE                            (uint16)440U
#define EXI_DIN_EI_EVSEPEAK_CURRENT_RIPPLE_SE                         (uint16)441U
#define EXI_DIN_EI_EVSEPEAK_CURRENT_RIPPLE_CT                         (uint16)442U
#define EXI_DIN_EI_EVSEPEAK_CURRENT_RIPPLE_EE                         (uint16)443U
#define EXI_DIN_EI_EVSEPEAK_CURRENT_RIPPLE_AT                         (uint16)444U
#define EXI_DIN_EI_EVSEENERGY_TO_BE_DELIVERED                         (uint16)445U
#define EXI_DIN_EI_EVSEENERGY_TO_BE_DELIVERED_SE                      (uint16)446U
#define EXI_DIN_EI_EVSEENERGY_TO_BE_DELIVERED_CT                      (uint16)447U
#define EXI_DIN_EI_EVSEENERGY_TO_BE_DELIVERED_EE                      (uint16)448U
#define EXI_DIN_EI_EVSEENERGY_TO_BE_DELIVERED_AT                      (uint16)449U
#define EXI_DIN_EI_DC_EVSECHARGE_PARAMETER                            (uint16)450U
#define EXI_DIN_EI_DC_EVSECHARGE_PARAMETER_SE                         (uint16)451U
#define EXI_DIN_EI_DC_EVSECHARGE_PARAMETER_CT                         (uint16)452U
#define EXI_DIN_EI_DC_EVSECHARGE_PARAMETER_EE                         (uint16)453U
#define EXI_DIN_EI_DC_EVSECHARGE_PARAMETER_AT                         (uint16)454U
#define EXI_DIN_EI_DC_EVSESTATUS_CODE                                 (uint16)455U
#define EXI_DIN_EI_DC_EVSESTATUS_CODE_SE                              (uint16)456U
#define EXI_DIN_EI_DC_EVSESTATUS_CODE_CT                              (uint16)457U
#define EXI_DIN_EI_DC_EVSESTATUS_CODE_EE                              (uint16)458U
#define EXI_DIN_EI_DC_EVSESTATUS_CODE_AT                              (uint16)459U
#define EXI_DIN_EI_EVSEISOLATION_STATUS                               (uint16)460U
#define EXI_DIN_EI_EVSEISOLATION_STATUS_SE                            (uint16)461U
#define EXI_DIN_EI_EVSEISOLATION_STATUS_CT                            (uint16)462U
#define EXI_DIN_EI_EVSEISOLATION_STATUS_EE                            (uint16)463U
#define EXI_DIN_EI_EVSEISOLATION_STATUS_AT                            (uint16)464U
#define EXI_DIN_EI_EVSESTATUS_CODE                                    (uint16)465U
#define EXI_DIN_EI_EVSESTATUS_CODE_SE                                 (uint16)466U
#define EXI_DIN_EI_EVSESTATUS_CODE_CT                                 (uint16)467U
#define EXI_DIN_EI_EVSESTATUS_CODE_EE                                 (uint16)468U
#define EXI_DIN_EI_EVSESTATUS_CODE_AT                                 (uint16)469U
#define EXI_DIN_EI_EVREADY                                            (uint16)470U
#define EXI_DIN_EI_EVREADY_SE                                         (uint16)471U
#define EXI_DIN_EI_EVREADY_CT                                         (uint16)472U
#define EXI_DIN_EI_EVREADY_EE                                         (uint16)473U
#define EXI_DIN_EI_EVREADY_AT                                         (uint16)474U
#define EXI_DIN_EI_EVCABIN_CONDITIONING                               (uint16)475U
#define EXI_DIN_EI_EVCABIN_CONDITIONING_SE                            (uint16)476U
#define EXI_DIN_EI_EVCABIN_CONDITIONING_CT                            (uint16)477U
#define EXI_DIN_EI_EVCABIN_CONDITIONING_EE                            (uint16)478U
#define EXI_DIN_EI_EVCABIN_CONDITIONING_AT                            (uint16)479U
#define EXI_DIN_EI_EVRESSCONDITIONING                                 (uint16)480U
#define EXI_DIN_EI_EVRESSCONDITIONING_SE                              (uint16)481U
#define EXI_DIN_EI_EVRESSCONDITIONING_CT                              (uint16)482U
#define EXI_DIN_EI_EVRESSCONDITIONING_EE                              (uint16)483U
#define EXI_DIN_EI_EVRESSCONDITIONING_AT                              (uint16)484U
#define EXI_DIN_EI_EVERROR_CODE                                       (uint16)485U
#define EXI_DIN_EI_EVERROR_CODE_SE                                    (uint16)486U
#define EXI_DIN_EI_EVERROR_CODE_CT                                    (uint16)487U
#define EXI_DIN_EI_EVERROR_CODE_EE                                    (uint16)488U
#define EXI_DIN_EI_EVERROR_CODE_AT                                    (uint16)489U
#define EXI_DIN_EI_EVRESSSOC                                          (uint16)490U
#define EXI_DIN_EI_EVRESSSOC_SE                                       (uint16)491U
#define EXI_DIN_EI_EVRESSSOC_CT                                       (uint16)492U
#define EXI_DIN_EI_EVRESSSOC_EE                                       (uint16)493U
#define EXI_DIN_EI_EVRESSSOC_AT                                       (uint16)494U
#define EXI_DIN_EI_EVREQUESTED_ENERGY_TRANSFER                        (uint16)495U
#define EXI_DIN_EI_EVREQUESTED_ENERGY_TRANSFER_SE                     (uint16)496U
#define EXI_DIN_EI_EVREQUESTED_ENERGY_TRANSFER_CT                     (uint16)497U
#define EXI_DIN_EI_EVREQUESTED_ENERGY_TRANSFER_EE                     (uint16)498U
#define EXI_DIN_EI_EVREQUESTED_ENERGY_TRANSFER_AT                     (uint16)499U
#define EXI_DIN_EI_EVSESUPPORTED_ENERGY_TRANSFER                      (uint16)500U
#define EXI_DIN_EI_EVSESUPPORTED_ENERGY_TRANSFER_SE                   (uint16)501U
#define EXI_DIN_EI_EVSESUPPORTED_ENERGY_TRANSFER_CT                   (uint16)502U
#define EXI_DIN_EI_EVSESUPPORTED_ENERGY_TRANSFER_EE                   (uint16)503U
#define EXI_DIN_EI_EVSESUPPORTED_ENERGY_TRANSFER_AT                   (uint16)504U
#define EXI_DIN_EI_ROOT_CERTIFICATE_ID                                (uint16)505U
#define EXI_DIN_EI_ROOT_CERTIFICATE_ID_SE                             (uint16)506U
#define EXI_DIN_EI_ROOT_CERTIFICATE_ID_CT                             (uint16)507U
#define EXI_DIN_EI_ROOT_CERTIFICATE_ID_EE                             (uint16)508U
#define EXI_DIN_EI_ROOT_CERTIFICATE_ID_AT                             (uint16)509U
#define EXI_DIN_EI_SESSION_ID                                         (uint16)510U
#define EXI_DIN_EI_SESSION_ID_SE                                      (uint16)511U
#define EXI_DIN_EI_SESSION_ID_CT                                      (uint16)512U
#define EXI_DIN_EI_SESSION_ID_EE                                      (uint16)513U
#define EXI_DIN_EI_SESSION_ID_AT                                      (uint16)514U
#define EXI_DIN_EI_NOTIFICATION                                       (uint16)515U
#define EXI_DIN_EI_NOTIFICATION_SE                                    (uint16)516U
#define EXI_DIN_EI_NOTIFICATION_CT                                    (uint16)517U
#define EXI_DIN_EI_NOTIFICATION_EE                                    (uint16)518U
#define EXI_DIN_EI_NOTIFICATION_AT                                    (uint16)519U
#define EXI_DIN_EI_SIGNATURE                                          (uint16)520U
#define EXI_DIN_EI_SIGNATURE_SE                                       (uint16)521U
#define EXI_DIN_EI_SIGNATURE_CT                                       (uint16)522U
#define EXI_DIN_EI_SIGNATURE_EE                                       (uint16)523U
#define EXI_DIN_EI_SIGNATURE_AT                                       (uint16)524U
#define EXI_DIN_EI_METER_ID                                           (uint16)525U
#define EXI_DIN_EI_METER_ID_SE                                        (uint16)526U
#define EXI_DIN_EI_METER_ID_CT                                        (uint16)527U
#define EXI_DIN_EI_METER_ID_EE                                        (uint16)528U
#define EXI_DIN_EI_METER_ID_AT                                        (uint16)529U
#define EXI_DIN_EI_METER_READING                                      (uint16)530U
#define EXI_DIN_EI_METER_READING_SE                                   (uint16)531U
#define EXI_DIN_EI_METER_READING_CT                                   (uint16)532U
#define EXI_DIN_EI_METER_READING_EE                                   (uint16)533U
#define EXI_DIN_EI_METER_READING_AT                                   (uint16)534U
#define EXI_DIN_EI_SIG_METER_READING                                  (uint16)535U
#define EXI_DIN_EI_SIG_METER_READING_SE                               (uint16)536U
#define EXI_DIN_EI_SIG_METER_READING_CT                               (uint16)537U
#define EXI_DIN_EI_SIG_METER_READING_EE                               (uint16)538U
#define EXI_DIN_EI_SIG_METER_READING_AT                               (uint16)539U
#define EXI_DIN_EI_METER_STATUS                                       (uint16)540U
#define EXI_DIN_EI_METER_STATUS_SE                                    (uint16)541U
#define EXI_DIN_EI_METER_STATUS_CT                                    (uint16)542U
#define EXI_DIN_EI_METER_STATUS_EE                                    (uint16)543U
#define EXI_DIN_EI_METER_STATUS_AT                                    (uint16)544U
#define EXI_DIN_EI_TMETER                                             (uint16)545U
#define EXI_DIN_EI_TMETER_SE                                          (uint16)546U
#define EXI_DIN_EI_TMETER_CT                                          (uint16)547U
#define EXI_DIN_EI_TMETER_EE                                          (uint16)548U
#define EXI_DIN_EI_TMETER_AT                                          (uint16)549U
#define EXI_DIN_EI_METERING_RECEIPT_REQ                               (uint16)550U
#define EXI_DIN_EI_METERING_RECEIPT_REQ_SE                            (uint16)551U
#define EXI_DIN_EI_METERING_RECEIPT_REQ_CT                            (uint16)552U
#define EXI_DIN_EI_METERING_RECEIPT_REQ_EE                            (uint16)553U
#define EXI_DIN_EI_METERING_RECEIPT_REQ_AT                            (uint16)554U
#define EXI_DIN_EI_METERING_RECEIPT_RES                               (uint16)555U
#define EXI_DIN_EI_METERING_RECEIPT_RES_SE                            (uint16)556U
#define EXI_DIN_EI_METERING_RECEIPT_RES_CT                            (uint16)557U
#define EXI_DIN_EI_METERING_RECEIPT_RES_EE                            (uint16)558U
#define EXI_DIN_EI_METERING_RECEIPT_RES_AT                            (uint16)559U
#define EXI_DIN_EI_FAULT_CODE                                         (uint16)560U
#define EXI_DIN_EI_FAULT_CODE_SE                                      (uint16)561U
#define EXI_DIN_EI_FAULT_CODE_CT                                      (uint16)562U
#define EXI_DIN_EI_FAULT_CODE_EE                                      (uint16)563U
#define EXI_DIN_EI_FAULT_CODE_AT                                      (uint16)564U
#define EXI_DIN_EI_FAULT_MSG                                          (uint16)565U
#define EXI_DIN_EI_FAULT_MSG_SE                                       (uint16)566U
#define EXI_DIN_EI_FAULT_MSG_CT                                       (uint16)567U
#define EXI_DIN_EI_FAULT_MSG_EE                                       (uint16)568U
#define EXI_DIN_EI_FAULT_MSG_AT                                       (uint16)569U
#define EXI_DIN_EI_TIME_INTERVAL                                      (uint16)570U
#define EXI_DIN_EI_TIME_INTERVAL_SE                                   (uint16)571U
#define EXI_DIN_EI_TIME_INTERVAL_CT                                   (uint16)572U
#define EXI_DIN_EI_TIME_INTERVAL_EE                                   (uint16)573U
#define EXI_DIN_EI_TIME_INTERVAL_AT                                   (uint16)574U
#define EXI_DIN_EI_PMAX                                               (uint16)575U
#define EXI_DIN_EI_PMAX_SE                                            (uint16)576U
#define EXI_DIN_EI_PMAX_CT                                            (uint16)577U
#define EXI_DIN_EI_PMAX_EE                                            (uint16)578U
#define EXI_DIN_EI_PMAX_AT                                            (uint16)579U
#define EXI_DIN_EI_PMAX_SCHEDULE_ENTRY                                (uint16)580U
#define EXI_DIN_EI_PMAX_SCHEDULE_ENTRY_SE                             (uint16)581U
#define EXI_DIN_EI_PMAX_SCHEDULE_ENTRY_CT                             (uint16)582U
#define EXI_DIN_EI_PMAX_SCHEDULE_ENTRY_EE                             (uint16)583U
#define EXI_DIN_EI_PMAX_SCHEDULE_ENTRY_AT                             (uint16)584U
#define EXI_DIN_EI_PMAX_SCHEDULE_ID                                   (uint16)585U
#define EXI_DIN_EI_PMAX_SCHEDULE_ID_SE                                (uint16)586U
#define EXI_DIN_EI_PMAX_SCHEDULE_ID_CT                                (uint16)587U
#define EXI_DIN_EI_PMAX_SCHEDULE_ID_EE                                (uint16)588U
#define EXI_DIN_EI_PMAX_SCHEDULE_ID_AT                                (uint16)589U
#define EXI_DIN_EI_PARAMETER_SET_ID                                   (uint16)590U
#define EXI_DIN_EI_PARAMETER_SET_ID_SE                                (uint16)591U
#define EXI_DIN_EI_PARAMETER_SET_ID_CT                                (uint16)592U
#define EXI_DIN_EI_PARAMETER_SET_ID_EE                                (uint16)593U
#define EXI_DIN_EI_PARAMETER_SET_ID_AT                                (uint16)594U
#define EXI_DIN_EI_PARAMETER                                          (uint16)595U
#define EXI_DIN_EI_PARAMETER_SE                                       (uint16)596U
#define EXI_DIN_EI_PARAMETER_CT                                       (uint16)597U
#define EXI_DIN_EI_PARAMETER_EE                                       (uint16)598U
#define EXI_DIN_EI_PARAMETER_AT                                       (uint16)599U
#define EXI_DIN_EI_NAME                                               (uint16)600U
#define EXI_DIN_EI_NAME_SE                                            (uint16)601U
#define EXI_DIN_EI_NAME_CT                                            (uint16)602U
#define EXI_DIN_EI_NAME_EE                                            (uint16)603U
#define EXI_DIN_EI_NAME_AT                                            (uint16)604U
#define EXI_DIN_EI_VALUE_TYPE                                         (uint16)605U
#define EXI_DIN_EI_VALUE_TYPE_SE                                      (uint16)606U
#define EXI_DIN_EI_VALUE_TYPE_CT                                      (uint16)607U
#define EXI_DIN_EI_VALUE_TYPE_EE                                      (uint16)608U
#define EXI_DIN_EI_VALUE_TYPE_AT                                      (uint16)609U
#define EXI_DIN_EI_CHOICE_ELEMENT                                     (uint16)610U
#define EXI_DIN_EI_CHOICE_ELEMENT_SE                                  (uint16)611U
#define EXI_DIN_EI_CHOICE_ELEMENT_CT                                  (uint16)612U
#define EXI_DIN_EI_CHOICE_ELEMENT_EE                                  (uint16)613U
#define EXI_DIN_EI_CHOICE_ELEMENT_AT                                  (uint16)614U
#define EXI_DIN_EI_BOOL_VALUE                                         (uint16)615U
#define EXI_DIN_EI_BOOL_VALUE_SE                                      (uint16)616U
#define EXI_DIN_EI_BOOL_VALUE_CT                                      (uint16)617U
#define EXI_DIN_EI_BOOL_VALUE_EE                                      (uint16)618U
#define EXI_DIN_EI_BOOL_VALUE_AT                                      (uint16)619U
#define EXI_DIN_EI_BYTE_VALUE                                         (uint16)620U
#define EXI_DIN_EI_BYTE_VALUE_SE                                      (uint16)621U
#define EXI_DIN_EI_BYTE_VALUE_CT                                      (uint16)622U
#define EXI_DIN_EI_BYTE_VALUE_EE                                      (uint16)623U
#define EXI_DIN_EI_BYTE_VALUE_AT                                      (uint16)624U
#define EXI_DIN_EI_SHORT_VALUE                                        (uint16)625U
#define EXI_DIN_EI_SHORT_VALUE_SE                                     (uint16)626U
#define EXI_DIN_EI_SHORT_VALUE_CT                                     (uint16)627U
#define EXI_DIN_EI_SHORT_VALUE_EE                                     (uint16)628U
#define EXI_DIN_EI_SHORT_VALUE_AT                                     (uint16)629U
#define EXI_DIN_EI_INT_VALUE                                          (uint16)630U
#define EXI_DIN_EI_INT_VALUE_SE                                       (uint16)631U
#define EXI_DIN_EI_INT_VALUE_CT                                       (uint16)632U
#define EXI_DIN_EI_INT_VALUE_EE                                       (uint16)633U
#define EXI_DIN_EI_INT_VALUE_AT                                       (uint16)634U
#define EXI_DIN_EI_PAYMENT_DETAILS_REQ                                (uint16)635U
#define EXI_DIN_EI_PAYMENT_DETAILS_REQ_SE                             (uint16)636U
#define EXI_DIN_EI_PAYMENT_DETAILS_REQ_CT                             (uint16)637U
#define EXI_DIN_EI_PAYMENT_DETAILS_REQ_EE                             (uint16)638U
#define EXI_DIN_EI_PAYMENT_DETAILS_REQ_AT                             (uint16)639U
#define EXI_DIN_EI_DATE_TIME_NOW                                      (uint16)640U
#define EXI_DIN_EI_DATE_TIME_NOW_SE                                   (uint16)641U
#define EXI_DIN_EI_DATE_TIME_NOW_CT                                   (uint16)642U
#define EXI_DIN_EI_DATE_TIME_NOW_EE                                   (uint16)643U
#define EXI_DIN_EI_DATE_TIME_NOW_AT                                   (uint16)644U
#define EXI_DIN_EI_PAYMENT_DETAILS_RES                                (uint16)645U
#define EXI_DIN_EI_PAYMENT_DETAILS_RES_SE                             (uint16)646U
#define EXI_DIN_EI_PAYMENT_DETAILS_RES_CT                             (uint16)647U
#define EXI_DIN_EI_PAYMENT_DETAILS_RES_EE                             (uint16)648U
#define EXI_DIN_EI_PAYMENT_DETAILS_RES_AT                             (uint16)649U
#define EXI_DIN_EI_PAYMENT_OPTION                                     (uint16)650U
#define EXI_DIN_EI_PAYMENT_OPTION_SE                                  (uint16)651U
#define EXI_DIN_EI_PAYMENT_OPTION_CT                                  (uint16)652U
#define EXI_DIN_EI_PAYMENT_OPTION_EE                                  (uint16)653U
#define EXI_DIN_EI_PAYMENT_OPTION_AT                                  (uint16)654U
#define EXI_DIN_EI_MULTIPLIER                                         (uint16)655U
#define EXI_DIN_EI_MULTIPLIER_SE                                      (uint16)656U
#define EXI_DIN_EI_MULTIPLIER_CT                                      (uint16)657U
#define EXI_DIN_EI_MULTIPLIER_EE                                      (uint16)658U
#define EXI_DIN_EI_MULTIPLIER_AT                                      (uint16)659U
#define EXI_DIN_EI_UNIT                                               (uint16)660U
#define EXI_DIN_EI_UNIT_SE                                            (uint16)661U
#define EXI_DIN_EI_UNIT_CT                                            (uint16)662U
#define EXI_DIN_EI_UNIT_EE                                            (uint16)663U
#define EXI_DIN_EI_UNIT_AT                                            (uint16)664U
#define EXI_DIN_EI_VALUE                                              (uint16)665U
#define EXI_DIN_EI_VALUE_SE                                           (uint16)666U
#define EXI_DIN_EI_VALUE_CT                                           (uint16)667U
#define EXI_DIN_EI_VALUE_EE                                           (uint16)668U
#define EXI_DIN_EI_VALUE_AT                                           (uint16)669U
#define EXI_DIN_EI_READY_TO_CHARGE_STATE                              (uint16)670U
#define EXI_DIN_EI_READY_TO_CHARGE_STATE_SE                           (uint16)671U
#define EXI_DIN_EI_READY_TO_CHARGE_STATE_CT                           (uint16)672U
#define EXI_DIN_EI_READY_TO_CHARGE_STATE_EE                           (uint16)673U
#define EXI_DIN_EI_READY_TO_CHARGE_STATE_AT                           (uint16)674U
#define EXI_DIN_EI_CHARGING_PROFILE                                   (uint16)675U
#define EXI_DIN_EI_CHARGING_PROFILE_SE                                (uint16)676U
#define EXI_DIN_EI_CHARGING_PROFILE_CT                                (uint16)677U
#define EXI_DIN_EI_CHARGING_PROFILE_EE                                (uint16)678U
#define EXI_DIN_EI_CHARGING_PROFILE_AT                                (uint16)679U
#define EXI_DIN_EI_EVPOWER_DELIVERY_PARAMETER                         (uint16)680U
#define EXI_DIN_EI_EVPOWER_DELIVERY_PARAMETER_SE                      (uint16)681U
#define EXI_DIN_EI_EVPOWER_DELIVERY_PARAMETER_CT                      (uint16)682U
#define EXI_DIN_EI_EVPOWER_DELIVERY_PARAMETER_EE                      (uint16)683U
#define EXI_DIN_EI_EVPOWER_DELIVERY_PARAMETER_AT                      (uint16)684U
#define EXI_DIN_EI_POWER_DELIVERY_REQ                                 (uint16)685U
#define EXI_DIN_EI_POWER_DELIVERY_REQ_SE                              (uint16)686U
#define EXI_DIN_EI_POWER_DELIVERY_REQ_CT                              (uint16)687U
#define EXI_DIN_EI_POWER_DELIVERY_REQ_EE                              (uint16)688U
#define EXI_DIN_EI_POWER_DELIVERY_REQ_AT                              (uint16)689U
#define EXI_DIN_EI_EVSESTATUS                                         (uint16)690U
#define EXI_DIN_EI_EVSESTATUS_SE                                      (uint16)691U
#define EXI_DIN_EI_EVSESTATUS_CT                                      (uint16)692U
#define EXI_DIN_EI_EVSESTATUS_EE                                      (uint16)693U
#define EXI_DIN_EI_EVSESTATUS_AT                                      (uint16)694U
#define EXI_DIN_EI_POWER_DELIVERY_RES                                 (uint16)695U
#define EXI_DIN_EI_POWER_DELIVERY_RES_SE                              (uint16)696U
#define EXI_DIN_EI_POWER_DELIVERY_RES_CT                              (uint16)697U
#define EXI_DIN_EI_POWER_DELIVERY_RES_EE                              (uint16)698U
#define EXI_DIN_EI_POWER_DELIVERY_RES_AT                              (uint16)699U
#define EXI_DIN_EI_PRE_CHARGE_REQ                                     (uint16)700U
#define EXI_DIN_EI_PRE_CHARGE_REQ_SE                                  (uint16)701U
#define EXI_DIN_EI_PRE_CHARGE_REQ_CT                                  (uint16)702U
#define EXI_DIN_EI_PRE_CHARGE_REQ_EE                                  (uint16)703U
#define EXI_DIN_EI_PRE_CHARGE_REQ_AT                                  (uint16)704U
#define EXI_DIN_EI_PRE_CHARGE_RES                                     (uint16)705U
#define EXI_DIN_EI_PRE_CHARGE_RES_SE                                  (uint16)706U
#define EXI_DIN_EI_PRE_CHARGE_RES_CT                                  (uint16)707U
#define EXI_DIN_EI_PRE_CHARGE_RES_EE                                  (uint16)708U
#define EXI_DIN_EI_PRE_CHARGE_RES_AT                                  (uint16)709U
#define EXI_DIN_EI_CHARGING_PROFILE_ENTRY_START                       (uint16)710U
#define EXI_DIN_EI_CHARGING_PROFILE_ENTRY_START_SE                    (uint16)711U
#define EXI_DIN_EI_CHARGING_PROFILE_ENTRY_START_CT                    (uint16)712U
#define EXI_DIN_EI_CHARGING_PROFILE_ENTRY_START_EE                    (uint16)713U
#define EXI_DIN_EI_CHARGING_PROFILE_ENTRY_START_AT                    (uint16)714U
#define EXI_DIN_EI_CHARGING_PROFILE_ENTRY_MAX_POWER                   (uint16)715U
#define EXI_DIN_EI_CHARGING_PROFILE_ENTRY_MAX_POWER_SE                (uint16)716U
#define EXI_DIN_EI_CHARGING_PROFILE_ENTRY_MAX_POWER_CT                (uint16)717U
#define EXI_DIN_EI_CHARGING_PROFILE_ENTRY_MAX_POWER_EE                (uint16)718U
#define EXI_DIN_EI_CHARGING_PROFILE_ENTRY_MAX_POWER_AT                (uint16)719U
#define EXI_DIN_EI_START                                              (uint16)720U
#define EXI_DIN_EI_START_SE                                           (uint16)721U
#define EXI_DIN_EI_START_CT                                           (uint16)722U
#define EXI_DIN_EI_START_EE                                           (uint16)723U
#define EXI_DIN_EI_START_AT                                           (uint16)724U
#define EXI_DIN_EI_DURATION                                           (uint16)725U
#define EXI_DIN_EI_DURATION_SE                                        (uint16)726U
#define EXI_DIN_EI_DURATION_CT                                        (uint16)727U
#define EXI_DIN_EI_DURATION_EE                                        (uint16)728U
#define EXI_DIN_EI_DURATION_AT                                        (uint16)729U
#define EXI_DIN_EI_RELATIVE_TIME_INTERVAL                             (uint16)730U
#define EXI_DIN_EI_RELATIVE_TIME_INTERVAL_SE                          (uint16)731U
#define EXI_DIN_EI_RELATIVE_TIME_INTERVAL_CT                          (uint16)732U
#define EXI_DIN_EI_RELATIVE_TIME_INTERVAL_EE                          (uint16)733U
#define EXI_DIN_EI_RELATIVE_TIME_INTERVAL_AT                          (uint16)734U
#define EXI_DIN_EI_SASCHEDULE_TUPLE                                   (uint16)735U
#define EXI_DIN_EI_SASCHEDULE_TUPLE_SE                                (uint16)736U
#define EXI_DIN_EI_SASCHEDULE_TUPLE_CT                                (uint16)737U
#define EXI_DIN_EI_SASCHEDULE_TUPLE_EE                                (uint16)738U
#define EXI_DIN_EI_SASCHEDULE_TUPLE_AT                                (uint16)739U
#define EXI_DIN_EI_PMAX_SCHEDULE                                      (uint16)740U
#define EXI_DIN_EI_PMAX_SCHEDULE_SE                                   (uint16)741U
#define EXI_DIN_EI_PMAX_SCHEDULE_CT                                   (uint16)742U
#define EXI_DIN_EI_PMAX_SCHEDULE_EE                                   (uint16)743U
#define EXI_DIN_EI_PMAX_SCHEDULE_AT                                   (uint16)744U
#define EXI_DIN_EI_SALES_TARIFF                                       (uint16)745U
#define EXI_DIN_EI_SALES_TARIFF_SE                                    (uint16)746U
#define EXI_DIN_EI_SALES_TARIFF_CT                                    (uint16)747U
#define EXI_DIN_EI_SALES_TARIFF_EE                                    (uint16)748U
#define EXI_DIN_EI_SALES_TARIFF_AT                                    (uint16)749U
#define EXI_DIN_EI_EPRICE_LEVEL                                       (uint16)750U
#define EXI_DIN_EI_EPRICE_LEVEL_SE                                    (uint16)751U
#define EXI_DIN_EI_EPRICE_LEVEL_CT                                    (uint16)752U
#define EXI_DIN_EI_EPRICE_LEVEL_EE                                    (uint16)753U
#define EXI_DIN_EI_EPRICE_LEVEL_AT                                    (uint16)754U
#define EXI_DIN_EI_CONSUMPTION_COST                                   (uint16)755U
#define EXI_DIN_EI_CONSUMPTION_COST_SE                                (uint16)756U
#define EXI_DIN_EI_CONSUMPTION_COST_CT                                (uint16)757U
#define EXI_DIN_EI_CONSUMPTION_COST_EE                                (uint16)758U
#define EXI_DIN_EI_CONSUMPTION_COST_AT                                (uint16)759U
#define EXI_DIN_EI_SALES_TARIFF_ID                                    (uint16)760U
#define EXI_DIN_EI_SALES_TARIFF_ID_SE                                 (uint16)761U
#define EXI_DIN_EI_SALES_TARIFF_ID_CT                                 (uint16)762U
#define EXI_DIN_EI_SALES_TARIFF_ID_EE                                 (uint16)763U
#define EXI_DIN_EI_SALES_TARIFF_ID_AT                                 (uint16)764U
#define EXI_DIN_EI_SALES_TARIFF_DESCRIPTION                           (uint16)765U
#define EXI_DIN_EI_SALES_TARIFF_DESCRIPTION_SE                        (uint16)766U
#define EXI_DIN_EI_SALES_TARIFF_DESCRIPTION_CT                        (uint16)767U
#define EXI_DIN_EI_SALES_TARIFF_DESCRIPTION_EE                        (uint16)768U
#define EXI_DIN_EI_SALES_TARIFF_DESCRIPTION_AT                        (uint16)769U
#define EXI_DIN_EI_NUM_EPRICE_LEVELS                                  (uint16)770U
#define EXI_DIN_EI_NUM_EPRICE_LEVELS_SE                               (uint16)771U
#define EXI_DIN_EI_NUM_EPRICE_LEVELS_CT                               (uint16)772U
#define EXI_DIN_EI_NUM_EPRICE_LEVELS_EE                               (uint16)773U
#define EXI_DIN_EI_NUM_EPRICE_LEVELS_AT                               (uint16)774U
#define EXI_DIN_EI_SALES_TARIFF_ENTRY                                 (uint16)775U
#define EXI_DIN_EI_SALES_TARIFF_ENTRY_SE                              (uint16)776U
#define EXI_DIN_EI_SALES_TARIFF_ENTRY_CT                              (uint16)777U
#define EXI_DIN_EI_SALES_TARIFF_ENTRY_EE                              (uint16)778U
#define EXI_DIN_EI_SALES_TARIFF_ENTRY_AT                              (uint16)779U
#define EXI_DIN_EI_SELECTED_SERVICE                                   (uint16)780U
#define EXI_DIN_EI_SELECTED_SERVICE_SE                                (uint16)781U
#define EXI_DIN_EI_SELECTED_SERVICE_CT                                (uint16)782U
#define EXI_DIN_EI_SELECTED_SERVICE_EE                                (uint16)783U
#define EXI_DIN_EI_SELECTED_SERVICE_AT                                (uint16)784U
#define EXI_DIN_EI_SERVICE_ID                                         (uint16)785U
#define EXI_DIN_EI_SERVICE_ID_SE                                      (uint16)786U
#define EXI_DIN_EI_SERVICE_ID_CT                                      (uint16)787U
#define EXI_DIN_EI_SERVICE_ID_EE                                      (uint16)788U
#define EXI_DIN_EI_SERVICE_ID_AT                                      (uint16)789U
#define EXI_DIN_EI_SERVICE_TAG                                        (uint16)790U
#define EXI_DIN_EI_SERVICE_TAG_SE                                     (uint16)791U
#define EXI_DIN_EI_SERVICE_TAG_CT                                     (uint16)792U
#define EXI_DIN_EI_SERVICE_TAG_EE                                     (uint16)793U
#define EXI_DIN_EI_SERVICE_TAG_AT                                     (uint16)794U
#define EXI_DIN_EI_FREE_SERVICE                                       (uint16)795U
#define EXI_DIN_EI_FREE_SERVICE_SE                                    (uint16)796U
#define EXI_DIN_EI_FREE_SERVICE_CT                                    (uint16)797U
#define EXI_DIN_EI_FREE_SERVICE_EE                                    (uint16)798U
#define EXI_DIN_EI_FREE_SERVICE_AT                                    (uint16)799U
#define EXI_DIN_EI_ENERGY_TRANSFER_TYPE                               (uint16)800U
#define EXI_DIN_EI_ENERGY_TRANSFER_TYPE_SE                            (uint16)801U
#define EXI_DIN_EI_ENERGY_TRANSFER_TYPE_CT                            (uint16)802U
#define EXI_DIN_EI_ENERGY_TRANSFER_TYPE_EE                            (uint16)803U
#define EXI_DIN_EI_ENERGY_TRANSFER_TYPE_AT                            (uint16)804U
#define EXI_DIN_EI_SERVICE_CHARGE                                     (uint16)805U
#define EXI_DIN_EI_SERVICE_CHARGE_SE                                  (uint16)806U
#define EXI_DIN_EI_SERVICE_CHARGE_CT                                  (uint16)807U
#define EXI_DIN_EI_SERVICE_CHARGE_EE                                  (uint16)808U
#define EXI_DIN_EI_SERVICE_CHARGE_AT                                  (uint16)809U
#define EXI_DIN_EI_SERVICE_DETAIL_REQ                                 (uint16)810U
#define EXI_DIN_EI_SERVICE_DETAIL_REQ_SE                              (uint16)811U
#define EXI_DIN_EI_SERVICE_DETAIL_REQ_CT                              (uint16)812U
#define EXI_DIN_EI_SERVICE_DETAIL_REQ_EE                              (uint16)813U
#define EXI_DIN_EI_SERVICE_DETAIL_REQ_AT                              (uint16)814U
#define EXI_DIN_EI_SERVICE_PARAMETER_LIST                             (uint16)815U
#define EXI_DIN_EI_SERVICE_PARAMETER_LIST_SE                          (uint16)816U
#define EXI_DIN_EI_SERVICE_PARAMETER_LIST_CT                          (uint16)817U
#define EXI_DIN_EI_SERVICE_PARAMETER_LIST_EE                          (uint16)818U
#define EXI_DIN_EI_SERVICE_PARAMETER_LIST_AT                          (uint16)819U
#define EXI_DIN_EI_SERVICE_DETAIL_RES                                 (uint16)820U
#define EXI_DIN_EI_SERVICE_DETAIL_RES_SE                              (uint16)821U
#define EXI_DIN_EI_SERVICE_DETAIL_RES_CT                              (uint16)822U
#define EXI_DIN_EI_SERVICE_DETAIL_RES_EE                              (uint16)823U
#define EXI_DIN_EI_SERVICE_DETAIL_RES_AT                              (uint16)824U
#define EXI_DIN_EI_SERVICE_SCOPE                                      (uint16)825U
#define EXI_DIN_EI_SERVICE_SCOPE_SE                                   (uint16)826U
#define EXI_DIN_EI_SERVICE_SCOPE_CT                                   (uint16)827U
#define EXI_DIN_EI_SERVICE_SCOPE_EE                                   (uint16)828U
#define EXI_DIN_EI_SERVICE_SCOPE_AT                                   (uint16)829U
#define EXI_DIN_EI_SERVICE_CATEGORY                                   (uint16)830U
#define EXI_DIN_EI_SERVICE_CATEGORY_SE                                (uint16)831U
#define EXI_DIN_EI_SERVICE_CATEGORY_CT                                (uint16)832U
#define EXI_DIN_EI_SERVICE_CATEGORY_EE                                (uint16)833U
#define EXI_DIN_EI_SERVICE_CATEGORY_AT                                (uint16)834U
#define EXI_DIN_EI_SERVICE_DISCOVERY_REQ                              (uint16)835U
#define EXI_DIN_EI_SERVICE_DISCOVERY_REQ_SE                           (uint16)836U
#define EXI_DIN_EI_SERVICE_DISCOVERY_REQ_CT                           (uint16)837U
#define EXI_DIN_EI_SERVICE_DISCOVERY_REQ_EE                           (uint16)838U
#define EXI_DIN_EI_SERVICE_DISCOVERY_REQ_AT                           (uint16)839U
#define EXI_DIN_EI_PAYMENT_OPTIONS                                    (uint16)840U
#define EXI_DIN_EI_PAYMENT_OPTIONS_SE                                 (uint16)841U
#define EXI_DIN_EI_PAYMENT_OPTIONS_CT                                 (uint16)842U
#define EXI_DIN_EI_PAYMENT_OPTIONS_EE                                 (uint16)843U
#define EXI_DIN_EI_PAYMENT_OPTIONS_AT                                 (uint16)844U
#define EXI_DIN_EI_CHARGE_SERVICE                                     (uint16)845U
#define EXI_DIN_EI_CHARGE_SERVICE_SE                                  (uint16)846U
#define EXI_DIN_EI_CHARGE_SERVICE_CT                                  (uint16)847U
#define EXI_DIN_EI_CHARGE_SERVICE_EE                                  (uint16)848U
#define EXI_DIN_EI_CHARGE_SERVICE_AT                                  (uint16)849U
#define EXI_DIN_EI_SERVICE_LIST                                       (uint16)850U
#define EXI_DIN_EI_SERVICE_LIST_SE                                    (uint16)851U
#define EXI_DIN_EI_SERVICE_LIST_CT                                    (uint16)852U
#define EXI_DIN_EI_SERVICE_LIST_EE                                    (uint16)853U
#define EXI_DIN_EI_SERVICE_LIST_AT                                    (uint16)854U
#define EXI_DIN_EI_SERVICE_DISCOVERY_RES                              (uint16)855U
#define EXI_DIN_EI_SERVICE_DISCOVERY_RES_SE                           (uint16)856U
#define EXI_DIN_EI_SERVICE_DISCOVERY_RES_CT                           (uint16)857U
#define EXI_DIN_EI_SERVICE_DISCOVERY_RES_EE                           (uint16)858U
#define EXI_DIN_EI_SERVICE_DISCOVERY_RES_AT                           (uint16)859U
#define EXI_DIN_EI_PARAMETER_SET                                      (uint16)860U
#define EXI_DIN_EI_PARAMETER_SET_SE                                   (uint16)861U
#define EXI_DIN_EI_PARAMETER_SET_CT                                   (uint16)862U
#define EXI_DIN_EI_PARAMETER_SET_EE                                   (uint16)863U
#define EXI_DIN_EI_PARAMETER_SET_AT                                   (uint16)864U
#define EXI_DIN_EI_SELECTED_PAYMENT_OPTION                            (uint16)865U
#define EXI_DIN_EI_SELECTED_PAYMENT_OPTION_SE                         (uint16)866U
#define EXI_DIN_EI_SELECTED_PAYMENT_OPTION_CT                         (uint16)867U
#define EXI_DIN_EI_SELECTED_PAYMENT_OPTION_EE                         (uint16)868U
#define EXI_DIN_EI_SELECTED_PAYMENT_OPTION_AT                         (uint16)869U
#define EXI_DIN_EI_SELECTED_SERVICE_LIST                              (uint16)870U
#define EXI_DIN_EI_SELECTED_SERVICE_LIST_SE                           (uint16)871U
#define EXI_DIN_EI_SELECTED_SERVICE_LIST_CT                           (uint16)872U
#define EXI_DIN_EI_SELECTED_SERVICE_LIST_EE                           (uint16)873U
#define EXI_DIN_EI_SELECTED_SERVICE_LIST_AT                           (uint16)874U
#define EXI_DIN_EI_SERVICE_PAYMENT_SELECTION_REQ                      (uint16)875U
#define EXI_DIN_EI_SERVICE_PAYMENT_SELECTION_REQ_SE                   (uint16)876U
#define EXI_DIN_EI_SERVICE_PAYMENT_SELECTION_REQ_CT                   (uint16)877U
#define EXI_DIN_EI_SERVICE_PAYMENT_SELECTION_REQ_EE                   (uint16)878U
#define EXI_DIN_EI_SERVICE_PAYMENT_SELECTION_REQ_AT                   (uint16)879U
#define EXI_DIN_EI_SERVICE_PAYMENT_SELECTION_RES                      (uint16)880U
#define EXI_DIN_EI_SERVICE_PAYMENT_SELECTION_RES_SE                   (uint16)881U
#define EXI_DIN_EI_SERVICE_PAYMENT_SELECTION_RES_CT                   (uint16)882U
#define EXI_DIN_EI_SERVICE_PAYMENT_SELECTION_RES_EE                   (uint16)883U
#define EXI_DIN_EI_SERVICE_PAYMENT_SELECTION_RES_AT                   (uint16)884U
#define EXI_DIN_EI_SERVICE                                            (uint16)885U
#define EXI_DIN_EI_SERVICE_SE                                         (uint16)886U
#define EXI_DIN_EI_SERVICE_CT                                         (uint16)887U
#define EXI_DIN_EI_SERVICE_EE                                         (uint16)888U
#define EXI_DIN_EI_SERVICE_AT                                         (uint16)889U
#define EXI_DIN_EI_SERVICE_NAME                                       (uint16)890U
#define EXI_DIN_EI_SERVICE_NAME_SE                                    (uint16)891U
#define EXI_DIN_EI_SERVICE_NAME_CT                                    (uint16)892U
#define EXI_DIN_EI_SERVICE_NAME_EE                                    (uint16)893U
#define EXI_DIN_EI_SERVICE_NAME_AT                                    (uint16)894U
#define EXI_DIN_EI_EVCCID                                             (uint16)895U
#define EXI_DIN_EI_EVCCID_SE                                          (uint16)896U
#define EXI_DIN_EI_EVCCID_CT                                          (uint16)897U
#define EXI_DIN_EI_EVCCID_EE                                          (uint16)898U
#define EXI_DIN_EI_EVCCID_AT                                          (uint16)899U
#define EXI_DIN_EI_SESSION_SETUP_REQ                                  (uint16)900U
#define EXI_DIN_EI_SESSION_SETUP_REQ_SE                               (uint16)901U
#define EXI_DIN_EI_SESSION_SETUP_REQ_CT                               (uint16)902U
#define EXI_DIN_EI_SESSION_SETUP_REQ_EE                               (uint16)903U
#define EXI_DIN_EI_SESSION_SETUP_REQ_AT                               (uint16)904U
#define EXI_DIN_EI_SESSION_SETUP_RES                                  (uint16)905U
#define EXI_DIN_EI_SESSION_SETUP_RES_SE                               (uint16)906U
#define EXI_DIN_EI_SESSION_SETUP_RES_CT                               (uint16)907U
#define EXI_DIN_EI_SESSION_SETUP_RES_EE                               (uint16)908U
#define EXI_DIN_EI_SESSION_SETUP_RES_AT                               (uint16)909U
#define EXI_DIN_EI_SESSION_STOP_RES                                   (uint16)910U
#define EXI_DIN_EI_SESSION_STOP_RES_SE                                (uint16)911U
#define EXI_DIN_EI_SESSION_STOP_RES_CT                                (uint16)912U
#define EXI_DIN_EI_SESSION_STOP_RES_EE                                (uint16)913U
#define EXI_DIN_EI_SESSION_STOP_RES_AT                                (uint16)914U
#define EXI_DIN_EI_HEADER                                             (uint16)915U
#define EXI_DIN_EI_HEADER_SE                                          (uint16)916U
#define EXI_DIN_EI_HEADER_CT                                          (uint16)917U
#define EXI_DIN_EI_HEADER_EE                                          (uint16)918U
#define EXI_DIN_EI_HEADER_AT                                          (uint16)919U
#define EXI_DIN_EI_BODY                                               (uint16)920U
#define EXI_DIN_EI_BODY_SE                                            (uint16)921U
#define EXI_DIN_EI_BODY_CT                                            (uint16)922U
#define EXI_DIN_EI_BODY_EE                                            (uint16)923U
#define EXI_DIN_EI_BODY_AT                                            (uint16)924U
#define EXI_DIN_EI_V2G_MESSAGE                                        (uint16)925U
#define EXI_DIN_EI_V2G_MESSAGE_SE                                     (uint16)926U
#define EXI_DIN_EI_V2G_MESSAGE_CT                                     (uint16)927U
#define EXI_DIN_EI_V2G_MESSAGE_EE                                     (uint16)928U
#define EXI_DIN_EI_V2G_MESSAGE_AT                                     (uint16)929U
#define EXI_DIN_EI_WELDING_DETECTION_REQ                              (uint16)930U
#define EXI_DIN_EI_WELDING_DETECTION_REQ_SE                           (uint16)931U
#define EXI_DIN_EI_WELDING_DETECTION_REQ_CT                           (uint16)932U
#define EXI_DIN_EI_WELDING_DETECTION_REQ_EE                           (uint16)933U
#define EXI_DIN_EI_WELDING_DETECTION_REQ_AT                           (uint16)934U
#define EXI_DIN_EI_WELDING_DETECTION_RES                              (uint16)935U
#define EXI_DIN_EI_WELDING_DETECTION_RES_SE                           (uint16)936U
#define EXI_DIN_EI_WELDING_DETECTION_RES_CT                           (uint16)937U
#define EXI_DIN_EI_WELDING_DETECTION_RES_EE                           (uint16)938U
#define EXI_DIN_EI_WELDING_DETECTION_RES_AT                           (uint16)939U
#define EXI_DIN_EI_D_HPARAMS                                          (uint16)940U
#define EXI_DIN_EI_D_HPARAMS_SE                                       (uint16)941U
#define EXI_DIN_EI_D_HPARAMS_CT                                       (uint16)942U
#define EXI_DIN_EI_D_HPARAMS_EE                                       (uint16)943U
#define EXI_DIN_EI_D_HPARAMS_AT                                       (uint16)944U
#define EXI_DIN_EI_EVCC_ID                                            (uint16)945U
#define EXI_DIN_EI_EVCC_ID_SE                                         (uint16)946U
#define EXI_DIN_EI_EVCC_ID_CT                                         (uint16)947U
#define EXI_DIN_EI_EVCC_ID_EE                                         (uint16)948U
#define EXI_DIN_EI_EVCC_ID_AT                                         (uint16)949U
#define EXI_DIN_EI_EVSE_ID                                            (uint16)950U
#define EXI_DIN_EI_EVSE_ID_SE                                         (uint16)951U
#define EXI_DIN_EI_EVSE_ID_CT                                         (uint16)952U
#define EXI_DIN_EI_EVSE_ID_EE                                         (uint16)953U
#define EXI_DIN_EI_EVSE_ID_AT                                         (uint16)954U
#define EXI_DIN_EI_ISOLATION_LEVEL                                    (uint16)955U
#define EXI_DIN_EI_ISOLATION_LEVEL_SE                                 (uint16)956U
#define EXI_DIN_EI_ISOLATION_LEVEL_CT                                 (uint16)957U
#define EXI_DIN_EI_ISOLATION_LEVEL_EE                                 (uint16)958U
#define EXI_DIN_EI_ISOLATION_LEVEL_AT                                 (uint16)959U
#define EXI_DIN_EI_PRIVATE_KEY                                        (uint16)960U
#define EXI_DIN_EI_PRIVATE_KEY_SE                                     (uint16)961U
#define EXI_DIN_EI_PRIVATE_KEY_CT                                     (uint16)962U
#define EXI_DIN_EI_PRIVATE_KEY_EE                                     (uint16)963U
#define EXI_DIN_EI_PRIVATE_KEY_AT                                     (uint16)964U
#define EXI_DIN_EI_TARIFF_DESCRIPTION                                 (uint16)965U
#define EXI_DIN_EI_TARIFF_DESCRIPTION_SE                              (uint16)966U
#define EXI_DIN_EI_TARIFF_DESCRIPTION_CT                              (uint16)967U
#define EXI_DIN_EI_TARIFF_DESCRIPTION_EE                              (uint16)968U
#define EXI_DIN_EI_TARIFF_DESCRIPTION_AT                              (uint16)969U
#define EXI_DIN_EI_UNIT_SYMBOL                                        (uint16)970U
#define EXI_DIN_EI_UNIT_SYMBOL_SE                                     (uint16)971U
#define EXI_DIN_EI_UNIT_SYMBOL_CT                                     (uint16)972U
#define EXI_DIN_EI_UNIT_SYMBOL_EE                                     (uint16)973U
#define EXI_DIN_EI_UNIT_SYMBOL_AT                                     (uint16)974U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  EXI_DIN_EVSEPROCESSING_TYPE_FINISHED = 0u,
  EXI_DIN_EVSEPROCESSING_TYPE_ONGOING = 1u
} Exi_DIN_EVSEProcessingType;

typedef enum
{
  EXI_DIN_EVSENOTIFICATION_TYPE_NONE = 0u,
  EXI_DIN_EVSENOTIFICATION_TYPE_STOP_CHARGING = 1u,
  EXI_DIN_EVSENOTIFICATION_TYPE_RE_NEGOTIATION = 2u
} Exi_DIN_EVSENotificationType;

typedef enum
{
  EXI_DIN_SERVICE_CATEGORY_TYPE_EVCHARGING = 0u,
  EXI_DIN_SERVICE_CATEGORY_TYPE_INTERNET = 1u,
  EXI_DIN_SERVICE_CATEGORY_TYPE_CONTRACT_CERTIFICATE = 2u,
  EXI_DIN_SERVICE_CATEGORY_TYPE_OTHER_CUSTOM = 3u
} Exi_DIN_serviceCategoryType;

typedef enum
{
  EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_AC_SINGLE_PHASE_CORE = 0u,
  EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_AC_THREE_PHASE_CORE = 1u,
  EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_DC_CORE = 2u,
  EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_DC_EXTENDED = 3u,
  EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_DC_COMBO_CORE = 4u,
  EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_DC_DUAL = 5u,
  EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_AC_CORE1P_DC_EXTENDED = 6u,
  EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_AC_SINGLE_DC_CORE = 7u,
  EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_AC_SINGLE_PHASE_THREE_PHASE_CORE_DC_EXTENDED = 8u,
  EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_AC_CORE3P_DC_EXTENDED = 9u
} Exi_DIN_EVSESupportedEnergyTransferType;

typedef enum
{
  EXI_DIN_EVREQUESTED_ENERGY_TRANSFER_TYPE_AC_SINGLE_PHASE_CORE = 0u,
  EXI_DIN_EVREQUESTED_ENERGY_TRANSFER_TYPE_AC_THREE_PHASE_CORE = 1u,
  EXI_DIN_EVREQUESTED_ENERGY_TRANSFER_TYPE_DC_CORE = 2u,
  EXI_DIN_EVREQUESTED_ENERGY_TRANSFER_TYPE_DC_EXTENDED = 3u,
  EXI_DIN_EVREQUESTED_ENERGY_TRANSFER_TYPE_DC_COMBO_CORE = 4u,
  EXI_DIN_EVREQUESTED_ENERGY_TRANSFER_TYPE_DC_UNIQUE = 5u
} Exi_DIN_EVRequestedEnergyTransferType;

typedef enum
{
  EXI_DIN_COST_KIND_TYPE_RELATIVE_PRICE_PERCENTAGE = 0u,
  EXI_DIN_COST_KIND_TYPE_RENEWABLE_GENERATION_PERCENTAGE = 1u,
  EXI_DIN_COST_KIND_TYPE_CARBON_DIOXIDE_EMISSION = 2u
} Exi_DIN_costKindType;

typedef enum
{
  EXI_DIN_PAYMENT_OPTION_TYPE_CONTRACT = 0u,
  EXI_DIN_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT = 1u
} Exi_DIN_paymentOptionType;

typedef enum
{
  EXI_DIN_FAULT_CODE_TYPE_PARSING_ERROR = 0u,
  EXI_DIN_FAULT_CODE_TYPE_NO_TLSROOT_CERTIFICAT_AVAILABLE = 1u,
  EXI_DIN_FAULT_CODE_TYPE_UNKNOWN_ERROR = 2u
} Exi_DIN_faultCodeType;

typedef enum
{
  EXI_DIN_RESPONSE_CODE_TYPE_OK = 0u,
  EXI_DIN_RESPONSE_CODE_TYPE_OK_NEW_SESSION_ESTABLISHED = 1u,
  EXI_DIN_RESPONSE_CODE_TYPE_OK_OLD_SESSION_JOINED = 2u,
  EXI_DIN_RESPONSE_CODE_TYPE_OK_CERTIFICATE_EXPIRES_SOON = 3u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED = 4u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_SEQUENCE_ERROR = 5u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_SERVICE_IDINVALID = 6u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_UNKNOWN_SESSION = 7u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_SERVICE_SELECTION_INVALID = 8u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_PAYMENT_SELECTION_INVALID = 9u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_CERTIFICATE_EXPIRED = 10u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_SIGNATURE_ERROR = 11u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_NO_CERTIFICATE_AVAILABLE = 12u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_CERT_CHAIN_ERROR = 13u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_CHALLENGE_INVALID = 14u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_CONTRACT_CANCELED = 15u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_WRONG_CHARGE_PARAMETER = 16u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_POWER_DELIVERY_NOT_APPLIED = 17u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_TARIFF_SELECTION_INVALID = 18u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_CHARGING_PROFILE_INVALID = 19u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_EVSEPRESENT_VOLTAGE_TO_LOW = 20u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_METERING_SIGNATURE_NOT_VALID = 21u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_WRONG_ENERGY_TRANSFER_TYPE = 22u,
  EXI_DIN_RESPONSE_CODE_TYPE_FAILED_RFIDPAIRING = 23u
} Exi_DIN_responseCodeType;

typedef enum
{
  EXI_DIN_UNIT_SYMBOL_TYPE_H = 0u,
  EXI_DIN_UNIT_SYMBOL_TYPE_M = 1u,
  EXI_DIN_UNIT_SYMBOL_TYPE_S = 2u,
  EXI_DIN_UNIT_SYMBOL_TYPE_A = 3u,
  EXI_DIN_UNIT_SYMBOL_TYPE_AH = 4u,
  EXI_DIN_UNIT_SYMBOL_TYPE_V = 5u,
  EXI_DIN_UNIT_SYMBOL_TYPE_VA = 6u,
  EXI_DIN_UNIT_SYMBOL_TYPE_W = 7u,
  EXI_DIN_UNIT_SYMBOL_TYPE_W_S = 8u,
  EXI_DIN_UNIT_SYMBOL_TYPE_WH = 9u
} Exi_DIN_unitSymbolType;

typedef enum
{
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_EVSE_NOT_READY = 0u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_EVSE_READY = 1u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_EVSE_SHUTDOWN = 2u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_EVSE_UTILITY_INTERRUPT_EVENT = 3u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_EVSE_ISOLATION_MONITORING_ACTIVE = 4u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_EVSE_EMERGENCY_SHUTDOWN = 5u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_EVSE_MALFUNCTION = 6u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_RESERVED_8 = 7u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_RESERVED_9 = 8u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_RESERVED_A = 9u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_RESERVED_B = 10u,
  EXI_DIN_DC_EVSESTATUS_CODE_TYPE_RESERVED_C = 11u
} Exi_DIN_DC_EVSEStatusCodeType;

typedef enum
{
  EXI_DIN_ISOLATION_LEVEL_TYPE_INVALID = 0u,
  EXI_DIN_ISOLATION_LEVEL_TYPE_VALID = 1u,
  EXI_DIN_ISOLATION_LEVEL_TYPE_WARNING = 2u,
  EXI_DIN_ISOLATION_LEVEL_TYPE_FAULT = 3u
} Exi_DIN_isolationLevelType;

typedef enum
{
  EXI_DIN_DC_EVERROR_CODE_TYPE_NO_ERROR = 0u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_FAILED_RESSTEMPERATURE_INHIBIT = 1u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_FAILED_EVSHIFT_POSITION = 2u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_FAILED_CHARGER_CONNECTOR_LOCK_FAULT = 3u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_FAILED_EVRESSMALFUNCTION = 4u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_FAILED_CHARGING_CURRENTDIFFERENTIAL = 5u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_FAILED_CHARGING_VOLTAGE_OUT_OF_RANGE = 6u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_RESERVED_A = 7u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_RESERVED_B = 8u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_RESERVED_C = 9u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_FAILED_CHARGING_SYSTEM_INCOMPATIBILITY = 10u,
  EXI_DIN_DC_EVERROR_CODE_TYPE_NO_DATA = 11u
} Exi_DIN_DC_EVErrorCodeType;

typedef enum
{
  EXI_DIN_ATTRIBUTE_VALUE_TYPE_BOOL = 0u,
  EXI_DIN_ATTRIBUTE_VALUE_TYPE_BYTE = 1u,
  EXI_DIN_ATTRIBUTE_VALUE_TYPE_SHORT = 2u,
  EXI_DIN_ATTRIBUTE_VALUE_TYPE_INT = 3u,
  EXI_DIN_ATTRIBUTE_VALUE_TYPE_PHYSICAL_VALUE = 4u,
  EXI_DIN_ATTRIBUTE_VALUE_TYPE_STRING = 5u
} Exi_DIN_AttributeValueType;

typedef struct Exi_DIN_faultMsgType Exi_DIN_faultMsgType;
struct Exi_DIN_faultMsgType
{
  uint16 Length;
  uint8 Buffer[64];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_serviceNameType Exi_DIN_serviceNameType;
struct Exi_DIN_serviceNameType
{
  uint16 Length;
  uint8 Buffer[32];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_serviceScopeType Exi_DIN_serviceScopeType;
struct Exi_DIN_serviceScopeType
{
  uint16 Length;
  uint8 Buffer[32];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_genChallengeType Exi_DIN_genChallengeType;
struct Exi_DIN_genChallengeType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_DIN_GENCHALLENGE];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_DIN_GENCHALLENGE ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_DIN_GENCHALLENGE ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_DIN_GENCHALLENGE ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_certificateType Exi_DIN_certificateType;
struct Exi_DIN_certificateType
{
  struct Exi_DIN_certificateType* NextCertificatePtr;
  uint16 Length;
  uint8 Buffer[1200];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_rootCertificateIDType Exi_DIN_rootCertificateIDType;
struct Exi_DIN_rootCertificateIDType
{
  struct Exi_DIN_rootCertificateIDType* NextRootCertificateIDPtr;
  uint16 Length;
  uint8 Buffer[40];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_dHParamsType Exi_DIN_dHParamsType;
struct Exi_DIN_dHParamsType
{
  uint16 Length;
  uint8 Buffer[256];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_privateKeyType Exi_DIN_privateKeyType;
struct Exi_DIN_privateKeyType
{
  uint16 Length;
  uint8 Buffer[128];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_sigMeterReadingType Exi_DIN_sigMeterReadingType;
struct Exi_DIN_sigMeterReadingType
{
  uint16 Length;
  uint8 Buffer[32];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_sessionIDType Exi_DIN_sessionIDType;
struct Exi_DIN_sessionIDType
{
  uint16 Length;
  uint8 Buffer[8];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_evccIDType Exi_DIN_evccIDType;
struct Exi_DIN_evccIDType
{
  uint16 Length;
  uint8 Buffer[8];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_evseIDType Exi_DIN_evseIDType;
struct Exi_DIN_evseIDType
{
  uint16 Length;
  uint8 Buffer[32];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_contractIDType Exi_DIN_contractIDType;
struct Exi_DIN_contractIDType
{
  uint16 Length;
  uint8 Buffer[24];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_meterIDType Exi_DIN_meterIDType;
struct Exi_DIN_meterIDType
{
  uint16 Length;
  uint8 Buffer[32];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_tariffDescriptionType Exi_DIN_tariffDescriptionType;
struct Exi_DIN_tariffDescriptionType
{
  uint16 Length;
  uint8 Buffer[32];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_AttributeNameType Exi_DIN_AttributeNameType;
struct Exi_DIN_AttributeNameType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTENAME];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTENAME ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTENAME ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTENAME ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_AttributeIdType Exi_DIN_AttributeIdType;
struct Exi_DIN_AttributeIdType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTEID];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTEID ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTEID ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTEID ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_DIN_ParameterChoiceType Exi_DIN_ParameterChoiceType;

typedef struct Exi_DIN_NotificationType Exi_DIN_NotificationType;

typedef struct Exi_DIN_MessageHeaderType Exi_DIN_MessageHeaderType;

typedef void Exi_DIN_BodyBaseType;

typedef struct Exi_DIN_BodyType Exi_DIN_BodyType;

typedef struct Exi_DIN_V2G_MessageType Exi_DIN_V2G_MessageType;

typedef struct Exi_DIN_SessionSetupReqType Exi_DIN_SessionSetupReqType;

typedef struct Exi_DIN_SessionSetupResType Exi_DIN_SessionSetupResType;

typedef struct Exi_DIN_ServiceDiscoveryReqType Exi_DIN_ServiceDiscoveryReqType;

typedef struct Exi_DIN_PaymentOptionsType Exi_DIN_PaymentOptionsType;

typedef struct Exi_DIN_ServiceTagType Exi_DIN_ServiceTagType;

typedef struct Exi_DIN_ServiceChargeType Exi_DIN_ServiceChargeType;

typedef struct Exi_DIN_ServiceType Exi_DIN_ServiceType;

typedef struct Exi_DIN_ServiceTagListType Exi_DIN_ServiceTagListType;

typedef struct Exi_DIN_ServiceDiscoveryResType Exi_DIN_ServiceDiscoveryResType;

typedef struct Exi_DIN_ServiceDetailReqType Exi_DIN_ServiceDetailReqType;

typedef struct Exi_DIN_PhysicalValueType Exi_DIN_PhysicalValueType;

typedef struct Exi_DIN_ParameterType Exi_DIN_ParameterType;

typedef struct Exi_DIN_ParameterSetType Exi_DIN_ParameterSetType;

typedef struct Exi_DIN_ServiceParameterListType Exi_DIN_ServiceParameterListType;

typedef struct Exi_DIN_ServiceDetailResType Exi_DIN_ServiceDetailResType;

typedef struct Exi_DIN_SelectedServiceType Exi_DIN_SelectedServiceType;

typedef struct Exi_DIN_SelectedServiceListType Exi_DIN_SelectedServiceListType;

typedef struct Exi_DIN_ServicePaymentSelectionReqType Exi_DIN_ServicePaymentSelectionReqType;

typedef struct Exi_DIN_ServicePaymentSelectionResType Exi_DIN_ServicePaymentSelectionResType;

typedef struct Exi_DIN_SubCertificatesType Exi_DIN_SubCertificatesType;

typedef struct Exi_DIN_CertificateChainType Exi_DIN_CertificateChainType;

typedef struct Exi_DIN_PaymentDetailsReqType Exi_DIN_PaymentDetailsReqType;

typedef struct Exi_DIN_PaymentDetailsResType Exi_DIN_PaymentDetailsResType;

typedef struct Exi_DIN_ContractAuthenticationReqType Exi_DIN_ContractAuthenticationReqType;

typedef struct Exi_DIN_ContractAuthenticationResType Exi_DIN_ContractAuthenticationResType;

typedef void Exi_DIN_EVChargeParameterType;

typedef struct Exi_DIN_ChargeParameterDiscoveryReqType Exi_DIN_ChargeParameterDiscoveryReqType;

typedef void Exi_DIN_SASchedulesType;

typedef void Exi_DIN_EVSEChargeParameterType;

typedef struct Exi_DIN_ChargeParameterDiscoveryResType Exi_DIN_ChargeParameterDiscoveryResType;

typedef struct Exi_DIN_ProfileEntryType Exi_DIN_ProfileEntryType;

typedef struct Exi_DIN_ChargingProfileType Exi_DIN_ChargingProfileType;

typedef void Exi_DIN_EVPowerDeliveryParameterType;

typedef struct Exi_DIN_PowerDeliveryReqType Exi_DIN_PowerDeliveryReqType;

typedef void Exi_DIN_EVSEStatusType;

typedef struct Exi_DIN_PowerDeliveryResType Exi_DIN_PowerDeliveryResType;

typedef void Exi_DIN_ChargingStatusReqType;

typedef struct Exi_DIN_MeterInfoType Exi_DIN_MeterInfoType;

typedef struct Exi_DIN_AC_EVSEStatusType Exi_DIN_AC_EVSEStatusType;

typedef struct Exi_DIN_ChargingStatusResType Exi_DIN_ChargingStatusResType;

typedef struct Exi_DIN_MeteringReceiptReqType Exi_DIN_MeteringReceiptReqType;

typedef struct Exi_DIN_MeteringReceiptResType Exi_DIN_MeteringReceiptResType;

typedef void Exi_DIN_SessionStopReqType;

typedef struct Exi_DIN_SessionStopResType Exi_DIN_SessionStopResType;

typedef struct Exi_DIN_ListOfRootCertificateIDsType Exi_DIN_ListOfRootCertificateIDsType;

typedef struct Exi_DIN_CertificateUpdateReqType Exi_DIN_CertificateUpdateReqType;

typedef struct Exi_DIN_CertificateUpdateResType Exi_DIN_CertificateUpdateResType;

typedef struct Exi_DIN_CertificateInstallationReqType Exi_DIN_CertificateInstallationReqType;

typedef struct Exi_DIN_CertificateInstallationResType Exi_DIN_CertificateInstallationResType;

typedef struct Exi_DIN_DC_EVStatusType Exi_DIN_DC_EVStatusType;

typedef struct Exi_DIN_CableCheckReqType Exi_DIN_CableCheckReqType;

typedef struct Exi_DIN_DC_EVSEStatusType Exi_DIN_DC_EVSEStatusType;

typedef struct Exi_DIN_CableCheckResType Exi_DIN_CableCheckResType;

typedef struct Exi_DIN_PreChargeReqType Exi_DIN_PreChargeReqType;

typedef struct Exi_DIN_PreChargeResType Exi_DIN_PreChargeResType;

typedef struct Exi_DIN_CurrentDemandReqType Exi_DIN_CurrentDemandReqType;

typedef struct Exi_DIN_CurrentDemandResType Exi_DIN_CurrentDemandResType;

typedef struct Exi_DIN_WeldingDetectionReqType Exi_DIN_WeldingDetectionReqType;

typedef struct Exi_DIN_WeldingDetectionResType Exi_DIN_WeldingDetectionResType;

typedef void Exi_DIN_IntervalType;

typedef struct Exi_DIN_PMaxScheduleEntryType Exi_DIN_PMaxScheduleEntryType;

typedef struct Exi_DIN_PMaxScheduleType Exi_DIN_PMaxScheduleType;

typedef struct Exi_DIN_CostType Exi_DIN_CostType;

typedef struct Exi_DIN_ConsumptionCostType Exi_DIN_ConsumptionCostType;

typedef struct Exi_DIN_SalesTariffEntryType Exi_DIN_SalesTariffEntryType;

typedef struct Exi_DIN_SalesTariffType Exi_DIN_SalesTariffType;

typedef struct Exi_DIN_SAScheduleTupleType Exi_DIN_SAScheduleTupleType;

typedef struct Exi_DIN_SAScheduleListType Exi_DIN_SAScheduleListType;

typedef struct Exi_DIN_EntryType Exi_DIN_EntryType;

typedef struct Exi_DIN_RelativeTimeIntervalType Exi_DIN_RelativeTimeIntervalType;

typedef void Exi_DIN_EVStatusType;

typedef struct Exi_DIN_AC_EVChargeParameterType Exi_DIN_AC_EVChargeParameterType;

typedef struct Exi_DIN_DC_EVChargeParameterType Exi_DIN_DC_EVChargeParameterType;

typedef struct Exi_DIN_AC_EVSEChargeParameterType Exi_DIN_AC_EVSEChargeParameterType;

typedef struct Exi_DIN_DC_EVSEChargeParameterType Exi_DIN_DC_EVSEChargeParameterType;

typedef struct Exi_DIN_DC_EVPowerDeliveryParameterType Exi_DIN_DC_EVPowerDeliveryParameterType;

/* Exi_DIN_valueType has been disabled */

struct Exi_DIN_NotificationType
{
  Exi_DIN_faultMsgType* FaultMsg;
  Exi_DIN_faultCodeType FaultCode; /* Value range: 0 to 2; See type for exact values. */
  Exi_BitType FaultMsgFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_MessageHeaderType
{
  Exi_DIN_NotificationType* Notification;
  Exi_DIN_sessionIDType* SessionID;
#if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_XMLSIG_SignatureType* Signature;
#endif
  Exi_BitType NotificationFlag : 1;
  Exi_BitType SignatureFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_BodyType
{
  Exi_DIN_BodyBaseType* BodyElement; /* Following types are allowed:
          Exi_DIN_SessionSetupReqType
          Exi_DIN_SessionSetupResType
          Exi_DIN_ServiceDiscoveryReqType
          Exi_DIN_ServiceDiscoveryResType
          Exi_DIN_ServiceDetailReqType
          Exi_DIN_ServiceDetailResType
          Exi_DIN_ServicePaymentSelectionReqType
          Exi_DIN_ServicePaymentSelectionResType
          Exi_DIN_PaymentDetailsReqType
          Exi_DIN_PaymentDetailsResType
          Exi_DIN_ContractAuthenticationReqType
          Exi_DIN_ContractAuthenticationResType
          Exi_DIN_ChargeParameterDiscoveryReqType
          Exi_DIN_ChargeParameterDiscoveryResType
          Exi_DIN_PowerDeliveryReqType
          Exi_DIN_PowerDeliveryResType
          Exi_DIN_ChargingStatusReqType
          Exi_DIN_ChargingStatusResType
          Exi_DIN_MeteringReceiptReqType
          Exi_DIN_MeteringReceiptResType
          Exi_DIN_SessionStopReqType
          Exi_DIN_SessionStopResType
          Exi_DIN_CertificateUpdateReqType
          Exi_DIN_CertificateUpdateResType
          Exi_DIN_CertificateInstallationReqType
          Exi_DIN_CertificateInstallationResType
          Exi_DIN_CableCheckReqType
          Exi_DIN_CableCheckResType
          Exi_DIN_PreChargeReqType
          Exi_DIN_PreChargeResType
          Exi_DIN_CurrentDemandReqType
          Exi_DIN_CurrentDemandResType
          Exi_DIN_WeldingDetectionReqType
          Exi_DIN_WeldingDetectionResType */
  Exi_RootElementIdType BodyElementElementId; /* Following element IDs are allowed:
          EXI_DIN_SESSION_SETUP_REQ_TYPE
          EXI_DIN_SESSION_SETUP_RES_TYPE
          EXI_DIN_SERVICE_DISCOVERY_REQ_TYPE
          EXI_DIN_SERVICE_DISCOVERY_RES_TYPE
          EXI_DIN_SERVICE_DETAIL_REQ_TYPE
          EXI_DIN_SERVICE_DETAIL_RES_TYPE
          EXI_DIN_SERVICE_PAYMENT_SELECTION_REQ_TYPE
          EXI_DIN_SERVICE_PAYMENT_SELECTION_RES_TYPE
          EXI_DIN_PAYMENT_DETAILS_REQ_TYPE
          EXI_DIN_PAYMENT_DETAILS_RES_TYPE
          EXI_DIN_CONTRACT_AUTHENTICATION_REQ_TYPE
          EXI_DIN_CONTRACT_AUTHENTICATION_RES_TYPE
          EXI_DIN_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE
          EXI_DIN_CHARGE_PARAMETER_DISCOVERY_RES_TYPE
          EXI_DIN_POWER_DELIVERY_REQ_TYPE
          EXI_DIN_POWER_DELIVERY_RES_TYPE
          EXI_DIN_CHARGING_STATUS_REQ_TYPE
          EXI_DIN_CHARGING_STATUS_RES_TYPE
          EXI_DIN_METERING_RECEIPT_REQ_TYPE
          EXI_DIN_METERING_RECEIPT_RES_TYPE
          EXI_DIN_SESSION_STOP_REQ_TYPE
          EXI_DIN_SESSION_STOP_RES_TYPE
          EXI_DIN_CERTIFICATE_UPDATE_REQ_TYPE
          EXI_DIN_CERTIFICATE_UPDATE_RES_TYPE
          EXI_DIN_CERTIFICATE_INSTALLATION_REQ_TYPE
          EXI_DIN_CERTIFICATE_INSTALLATION_RES_TYPE
          EXI_DIN_CABLE_CHECK_REQ_TYPE
          EXI_DIN_CABLE_CHECK_RES_TYPE
          EXI_DIN_PRE_CHARGE_REQ_TYPE
          EXI_DIN_PRE_CHARGE_RES_TYPE
          EXI_DIN_CURRENT_DEMAND_REQ_TYPE
          EXI_DIN_CURRENT_DEMAND_RES_TYPE
          EXI_DIN_WELDING_DETECTION_REQ_TYPE
          EXI_DIN_WELDING_DETECTION_RES_TYPE */
  Exi_BitType BodyElementFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_V2G_MessageType
{
  Exi_DIN_BodyType* Body;
  Exi_DIN_MessageHeaderType* Header;
};

struct Exi_DIN_SessionSetupReqType
{
  Exi_DIN_evccIDType* EVCCID;
};

struct Exi_DIN_SessionSetupResType
{
  Exi_DIN_evseIDType* EVSEID;
  Exi_SInt64 DateTimeNow;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
  Exi_BitType DateTimeNowFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ServiceDiscoveryReqType
{
  Exi_DIN_serviceScopeType* ServiceScope;
  Exi_DIN_serviceCategoryType ServiceCategory; /* Value range: 0 to 3; See type for exact values. */
  Exi_BitType ServiceCategoryFlag : 1;
  Exi_BitType ServiceScopeFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_PaymentOptionsType
{
  uint16 PaymentOptionCount;
  Exi_DIN_paymentOptionType PaymentOption[EXI_MAXOCCURS_DIN_PAYMENTOPTION];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE * ( EXI_MAXOCCURS_DIN_PAYMENTOPTION )) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE * ( EXI_MAXOCCURS_DIN_PAYMENTOPTION )) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE * ( EXI_MAXOCCURS_DIN_PAYMENTOPTION )) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ServiceTagType
{
  Exi_DIN_serviceNameType* ServiceName;
  Exi_DIN_serviceScopeType* ServiceScope;
  uint16 ServiceID;
  Exi_DIN_serviceCategoryType ServiceCategory; /* Value range: 0 to 3; See type for exact values. */
  Exi_BitType ServiceNameFlag : 1;
  Exi_BitType ServiceScopeFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ServiceChargeType
{
  Exi_DIN_ServiceTagType* ServiceTag;
  Exi_DIN_EVSESupportedEnergyTransferType EnergyTransferType; /* Value range: 0 to 9; See type for exact values. */
  boolean FreeService;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ServiceType
{
  struct Exi_DIN_ServiceType* NextServicePtr;
  Exi_DIN_ServiceTagType* ServiceTag;
  boolean FreeService;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 1u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ServiceTagListType
{
  Exi_DIN_ServiceType* Service;
};

struct Exi_DIN_ServiceDiscoveryResType
{
  Exi_DIN_ServiceChargeType* ChargeService;
  Exi_DIN_PaymentOptionsType* PaymentOptions;
  Exi_DIN_ServiceTagListType* ServiceList;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
  Exi_BitType ServiceListFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ServiceDetailReqType
{
  uint16 ServiceID;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_PhysicalValueType
{
  sint16 Value;
  sint8 Multiplier; /* Value range: min: -3 max: 3 */
  Exi_DIN_unitSymbolType Unit; /* Value range: 0 to 9; See type for exact values. */
  Exi_BitType UnitFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ParameterChoiceType
{
  union
  {
    Exi_DIN_PhysicalValueType* physicalValue;
    Exi_stringType* stringValue;
    sint32 intValue;
    sint16 shortValue;
    boolean boolValue;
    sint8 byteValue;
  } ChoiceValue;
  Exi_BitType physicalValueFlag : 1;
  Exi_BitType stringValueFlag : 1;
  Exi_BitType intValueFlag : 1;
  Exi_BitType shortValueFlag : 1;
  Exi_BitType boolValueFlag : 1;
  Exi_BitType byteValueFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ParameterType
{
  Exi_DIN_ParameterChoiceType* ChoiceElement;
  Exi_DIN_AttributeNameType* Name;
  struct Exi_DIN_ParameterType* NextParameterPtr;
  Exi_DIN_AttributeValueType ValueType; /* Value range: 0 to 5; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ParameterSetType
{
  struct Exi_DIN_ParameterSetType* NextParameterSetPtr;
  Exi_DIN_ParameterType* Parameter;
  sint16 ParameterSetID;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ServiceParameterListType
{
  Exi_DIN_ParameterSetType* ParameterSet;
};

struct Exi_DIN_ServiceDetailResType
{
  Exi_DIN_ServiceParameterListType* ServiceParameterList;
  uint16 ServiceID;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
  Exi_BitType ServiceParameterListFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_SelectedServiceType
{
  struct Exi_DIN_SelectedServiceType* NextSelectedServicePtr;
  sint16 ParameterSetID;
  uint16 ServiceID;
  Exi_BitType ParameterSetIDFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_SelectedServiceListType
{
  Exi_DIN_SelectedServiceType* SelectedService;
};

struct Exi_DIN_ServicePaymentSelectionReqType
{
  Exi_DIN_SelectedServiceListType* SelectedServiceList;
  Exi_DIN_paymentOptionType SelectedPaymentOption; /* Value range: 0 to 1; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ServicePaymentSelectionResType
{
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_SubCertificatesType
{
  Exi_DIN_certificateType* Certificate;
};

struct Exi_DIN_CertificateChainType
{
  Exi_DIN_certificateType* Certificate;
  Exi_DIN_SubCertificatesType* SubCertificates;
  Exi_BitType SubCertificatesFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_PaymentDetailsReqType
{
  Exi_DIN_contractIDType* ContractID;
  Exi_DIN_CertificateChainType* ContractSignatureCertChain;
};

struct Exi_DIN_PaymentDetailsResType
{
  Exi_DIN_genChallengeType* GenChallenge;
  Exi_SInt64 DateTimeNow;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ContractAuthenticationReqType
{
  Exi_DIN_genChallengeType* GenChallenge;
  Exi_DIN_AttributeIdType* Id;
  Exi_BitType GenChallengeFlag : 1;
  Exi_BitType IdFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ContractAuthenticationResType
{
  Exi_DIN_EVSEProcessingType EVSEProcessing; /* Value range: 0 to 1; See type for exact values. */
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ChargeParameterDiscoveryReqType
{
  Exi_DIN_EVChargeParameterType* EVChargeParameter; /* Following types are allowed:
          Exi_DIN_AC_EVChargeParameterType
          Exi_DIN_DC_EVChargeParameterType */
  Exi_RootElementIdType EVChargeParameterElementId; /* Following element IDs are allowed:
          EXI_DIN_AC_EVCHARGE_PARAMETER_TYPE
          EXI_DIN_DC_EVCHARGE_PARAMETER_TYPE */
  Exi_DIN_EVRequestedEnergyTransferType EVRequestedEnergyTransferType; /* Value range: 0 to 5; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ChargeParameterDiscoveryResType
{
  Exi_DIN_EVSEChargeParameterType* EVSEChargeParameter; /* Following types are allowed:
          Exi_DIN_AC_EVSEChargeParameterType
          Exi_DIN_DC_EVSEChargeParameterType */
  Exi_DIN_SASchedulesType* SASchedules; /* Following types are allowed:
          Exi_DIN_SAScheduleListType */
  Exi_RootElementIdType EVSEChargeParameterElementId; /* Following element IDs are allowed:
          EXI_DIN_AC_EVSECHARGE_PARAMETER_TYPE
          EXI_DIN_DC_EVSECHARGE_PARAMETER_TYPE */
  Exi_RootElementIdType SASchedulesElementId; /* Following element IDs are allowed:
          EXI_DIN_SASCHEDULE_LIST_TYPE */
  Exi_DIN_EVSEProcessingType EVSEProcessing; /* Value range: 0 to 1; See type for exact values. */
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ProfileEntryType
{
  struct Exi_DIN_ProfileEntryType* NextProfileEntryPtr;
  uint32 ChargingProfileEntryStart;
  sint16 ChargingProfileEntryMaxPower;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ChargingProfileType
{
  Exi_DIN_ProfileEntryType* ProfileEntry;
  sint16 SAScheduleTupleID;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_PowerDeliveryReqType
{
  Exi_DIN_ChargingProfileType* ChargingProfile;
  Exi_DIN_EVPowerDeliveryParameterType* EVPowerDeliveryParameter; /* Following types are allowed:
          Exi_DIN_DC_EVPowerDeliveryParameterType */
  Exi_RootElementIdType EVPowerDeliveryParameterElementId; /* Following element IDs are allowed:
          EXI_DIN_DC_EVPOWER_DELIVERY_PARAMETER_TYPE */
  boolean ReadyToChargeState;
  Exi_BitType ChargingProfileFlag : 1;
  Exi_BitType EVPowerDeliveryParameterFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_PowerDeliveryResType
{
  Exi_DIN_EVSEStatusType* EVSEStatus; /* Following types are allowed:
          Exi_DIN_AC_EVSEStatusType
          Exi_DIN_DC_EVSEStatusType */
  Exi_RootElementIdType EVSEStatusElementId; /* Following element IDs are allowed:
          EXI_DIN_AC_EVSESTATUS_TYPE
          EXI_DIN_DC_EVSESTATUS_TYPE */
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_MeterInfoType
{
  Exi_DIN_meterIDType* MeterID;
  Exi_DIN_PhysicalValueType* MeterReading;
  Exi_DIN_sigMeterReadingType* SigMeterReading;
  Exi_SInt64 TMeter;
  sint16 MeterStatus;
  Exi_BitType MeterReadingFlag : 1;
  Exi_BitType MeterStatusFlag : 1;
  Exi_BitType SigMeterReadingFlag : 1;
  Exi_BitType TMeterFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_AC_EVSEStatusType
{
  uint32 NotificationMaxDelay;
  Exi_DIN_EVSENotificationType EVSENotification; /* Value range: 0 to 2; See type for exact values. */
  boolean PowerSwitchClosed;
  boolean RCD;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ChargingStatusResType
{
  Exi_DIN_AC_EVSEStatusType* AC_EVSEStatus;
  Exi_DIN_evseIDType* EVSEID;
  Exi_DIN_PhysicalValueType* EVSEMaxCurrent;
  Exi_DIN_MeterInfoType* MeterInfo;
  sint16 SAScheduleTupleID;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
  boolean ReceiptRequired;
  Exi_BitType EVSEMaxCurrentFlag : 1;
  Exi_BitType MeterInfoFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_MeteringReceiptReqType
{
  Exi_DIN_AttributeIdType* Id;
  Exi_DIN_MeterInfoType* MeterInfo;
  Exi_DIN_sessionIDType* SessionID;
  sint16 SAScheduleTupleID;
  Exi_BitType IdFlag : 1;
  Exi_BitType SAScheduleTupleIDFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_MeteringReceiptResType
{
  Exi_DIN_AC_EVSEStatusType* AC_EVSEStatus;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_SessionStopResType
{
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ListOfRootCertificateIDsType
{
  Exi_DIN_rootCertificateIDType* RootCertificateID;
};

struct Exi_DIN_CertificateUpdateReqType
{
  Exi_DIN_contractIDType* ContractID;
  Exi_DIN_CertificateChainType* ContractSignatureCertChain;
  Exi_DIN_dHParamsType* DHParams;
  Exi_DIN_AttributeIdType* Id;
  Exi_DIN_ListOfRootCertificateIDsType* ListOfRootCertificateIDs;
  Exi_BitType IdFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_CertificateUpdateResType
{
  Exi_DIN_contractIDType* ContractID;
  Exi_DIN_CertificateChainType* ContractSignatureCertChain;
  Exi_DIN_privateKeyType* ContractSignatureEncryptedPrivateKey;
  Exi_DIN_dHParamsType* DHParams;
  Exi_DIN_AttributeIdType* Id;
  sint16 RetryCounter;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_CertificateInstallationReqType
{
  Exi_DIN_dHParamsType* DHParams;
  Exi_DIN_AttributeIdType* Id;
  Exi_DIN_ListOfRootCertificateIDsType* ListOfRootCertificateIDs;
  Exi_DIN_certificateType* OEMProvisioningCert;
  Exi_BitType IdFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_CertificateInstallationResType
{
  Exi_DIN_contractIDType* ContractID;
  Exi_DIN_CertificateChainType* ContractSignatureCertChain;
  Exi_DIN_privateKeyType* ContractSignatureEncryptedPrivateKey;
  Exi_DIN_dHParamsType* DHParams;
  Exi_DIN_AttributeIdType* Id;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_DC_EVStatusType
{
  Exi_DIN_DC_EVErrorCodeType EVErrorCode; /* Value range: 0 to 11; See type for exact values. */
  boolean EVCabinConditioning;
  boolean EVRESSConditioning;
  boolean EVReady;
  sint8 EVRESSSOC; /* Value range: max: 100 */
  Exi_BitType EVCabinConditioningFlag : 1;
  Exi_BitType EVRESSConditioningFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_CableCheckReqType
{
  Exi_DIN_DC_EVStatusType* DC_EVStatus;
};

struct Exi_DIN_DC_EVSEStatusType
{
  uint32 NotificationMaxDelay;
  Exi_DIN_DC_EVSEStatusCodeType EVSEStatusCode; /* Value range: 0 to 11; See type for exact values. */
  Exi_DIN_EVSENotificationType EVSENotification; /* Value range: 0 to 2; See type for exact values. */
  Exi_DIN_isolationLevelType EVSEIsolationStatus; /* Value range: 0 to 3; See type for exact values. */
  Exi_BitType EVSEIsolationStatusFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_CableCheckResType
{
  Exi_DIN_DC_EVSEStatusType* DC_EVSEStatus;
  Exi_DIN_EVSEProcessingType EVSEProcessing; /* Value range: 0 to 1; See type for exact values. */
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_PreChargeReqType
{
  Exi_DIN_DC_EVStatusType* DC_EVStatus;
  Exi_DIN_PhysicalValueType* EVTargetCurrent;
  Exi_DIN_PhysicalValueType* EVTargetVoltage;
};

struct Exi_DIN_PreChargeResType
{
  Exi_DIN_DC_EVSEStatusType* DC_EVSEStatus;
  Exi_DIN_PhysicalValueType* EVSEPresentVoltage;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_CurrentDemandReqType
{
  Exi_DIN_DC_EVStatusType* DC_EVStatus;
  Exi_DIN_PhysicalValueType* EVMaximumCurrentLimit;
  Exi_DIN_PhysicalValueType* EVMaximumPowerLimit;
  Exi_DIN_PhysicalValueType* EVMaximumVoltageLimit;
  Exi_DIN_PhysicalValueType* EVTargetCurrent;
  Exi_DIN_PhysicalValueType* EVTargetVoltage;
  Exi_DIN_PhysicalValueType* RemainingTimeToBulkSoC;
  Exi_DIN_PhysicalValueType* RemainingTimeToFullSoC;
  boolean BulkChargingComplete;
  boolean ChargingComplete;
  Exi_BitType BulkChargingCompleteFlag : 1;
  Exi_BitType EVMaximumCurrentLimitFlag : 1;
  Exi_BitType EVMaximumPowerLimitFlag : 1;
  Exi_BitType EVMaximumVoltageLimitFlag : 1;
  Exi_BitType RemainingTimeToBulkSoCFlag : 1;
  Exi_BitType RemainingTimeToFullSoCFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_CurrentDemandResType
{
  Exi_DIN_DC_EVSEStatusType* DC_EVSEStatus;
  Exi_DIN_PhysicalValueType* EVSEMaximumCurrentLimit;
  Exi_DIN_PhysicalValueType* EVSEMaximumPowerLimit;
  Exi_DIN_PhysicalValueType* EVSEMaximumVoltageLimit;
  Exi_DIN_PhysicalValueType* EVSEPresentCurrent;
  Exi_DIN_PhysicalValueType* EVSEPresentVoltage;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
  boolean EVSECurrentLimitAchieved;
  boolean EVSEPowerLimitAchieved;
  boolean EVSEVoltageLimitAchieved;
  Exi_BitType EVSEMaximumCurrentLimitFlag : 1;
  Exi_BitType EVSEMaximumPowerLimitFlag : 1;
  Exi_BitType EVSEMaximumVoltageLimitFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_WeldingDetectionReqType
{
  Exi_DIN_DC_EVStatusType* DC_EVStatus;
};

struct Exi_DIN_WeldingDetectionResType
{
  Exi_DIN_DC_EVSEStatusType* DC_EVSEStatus;
  Exi_DIN_PhysicalValueType* EVSEPresentVoltage;
  Exi_DIN_responseCodeType ResponseCode; /* Value range: 0 to 23; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_PMaxScheduleEntryType
{
  struct Exi_DIN_PMaxScheduleEntryType* NextPMaxScheduleEntryPtr;
  Exi_DIN_IntervalType* TimeInterval; /* Following types are allowed:
          Exi_DIN_RelativeTimeIntervalType */
  Exi_RootElementIdType TimeIntervalElementId; /* Following element IDs are allowed:
          EXI_DIN_RELATIVE_TIME_INTERVAL_TYPE */
  sint16 PMax;
};

struct Exi_DIN_PMaxScheduleType
{
  Exi_DIN_PMaxScheduleEntryType* PMaxScheduleEntry;
  sint16 PMaxScheduleID;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_CostType
{
  struct Exi_DIN_CostType* NextCostPtr;
  uint32 amount;
  Exi_DIN_costKindType costKind; /* Value range: 0 to 2; See type for exact values. */
  sint8 amountMultiplier; /* Value range: min: -3 max: 3 */
  Exi_BitType amountMultiplierFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_ConsumptionCostType
{
  Exi_DIN_CostType* Cost;
  struct Exi_DIN_ConsumptionCostType* NextConsumptionCostPtr;
  uint32 startValue;
  Exi_BitType CostFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_SalesTariffEntryType
{
  Exi_DIN_ConsumptionCostType* ConsumptionCost;
  struct Exi_DIN_SalesTariffEntryType* NextSalesTariffEntryPtr;
  Exi_DIN_IntervalType* TimeInterval; /* Following types are allowed:
          Exi_DIN_RelativeTimeIntervalType */
  Exi_RootElementIdType TimeIntervalElementId; /* Following element IDs are allowed:
          EXI_DIN_RELATIVE_TIME_INTERVAL_TYPE */
  uint8 EPriceLevel;
  Exi_BitType ConsumptionCostFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_SalesTariffType
{
  Exi_DIN_AttributeIdType* Id;
  Exi_DIN_tariffDescriptionType* SalesTariffDescription;
  Exi_DIN_SalesTariffEntryType* SalesTariffEntry;
  sint16 SalesTariffID;
  uint8 NumEPriceLevels;
  Exi_BitType SalesTariffDescriptionFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 3u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_SAScheduleTupleType
{
  struct Exi_DIN_SAScheduleTupleType* NextSAScheduleTuplePtr;
  Exi_DIN_PMaxScheduleType* PMaxSchedule;
  Exi_DIN_SalesTariffType* SalesTariff;
  sint16 SAScheduleTupleID;
  Exi_BitType SalesTariffFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_SAScheduleListType
{
  Exi_DIN_SAScheduleTupleType* SAScheduleTuple;
};

struct Exi_DIN_EntryType
{
  Exi_DIN_IntervalType* TimeInterval; /* Following types are allowed:
          Exi_DIN_RelativeTimeIntervalType */
  Exi_RootElementIdType TimeIntervalElementId; /* Following element IDs are allowed:
          EXI_DIN_RELATIVE_TIME_INTERVAL_TYPE */
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_RelativeTimeIntervalType
{
  uint32 duration;
  uint32 start;
  Exi_BitType durationFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_AC_EVChargeParameterType
{
  Exi_DIN_PhysicalValueType* EAmount;
  Exi_DIN_PhysicalValueType* EVMaxCurrent;
  Exi_DIN_PhysicalValueType* EVMaxVoltage;
  Exi_DIN_PhysicalValueType* EVMinCurrent;
  uint32 DepartureTime;
};

struct Exi_DIN_DC_EVChargeParameterType
{
  Exi_DIN_DC_EVStatusType* DC_EVStatus;
  Exi_DIN_PhysicalValueType* EVEnergyCapacity;
  Exi_DIN_PhysicalValueType* EVEnergyRequest;
  Exi_DIN_PhysicalValueType* EVMaximumCurrentLimit;
  Exi_DIN_PhysicalValueType* EVMaximumPowerLimit;
  Exi_DIN_PhysicalValueType* EVMaximumVoltageLimit;
  sint8 BulkSOC; /* Value range: max: 100 */
  sint8 FullSOC; /* Value range: max: 100 */
  Exi_BitType BulkSOCFlag : 1;
  Exi_BitType EVEnergyCapacityFlag : 1;
  Exi_BitType EVEnergyRequestFlag : 1;
  Exi_BitType EVMaximumPowerLimitFlag : 1;
  Exi_BitType FullSOCFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_AC_EVSEChargeParameterType
{
  Exi_DIN_AC_EVSEStatusType* AC_EVSEStatus;
  Exi_DIN_PhysicalValueType* EVSEMaxCurrent;
  Exi_DIN_PhysicalValueType* EVSEMaxVoltage;
  Exi_DIN_PhysicalValueType* EVSEMinCurrent;
};

struct Exi_DIN_DC_EVSEChargeParameterType
{
  Exi_DIN_DC_EVSEStatusType* DC_EVSEStatus;
  Exi_DIN_PhysicalValueType* EVSECurrentRegulationTolerance;
  Exi_DIN_PhysicalValueType* EVSEEnergyToBeDelivered;
  Exi_DIN_PhysicalValueType* EVSEMaximumCurrentLimit;
  Exi_DIN_PhysicalValueType* EVSEMaximumPowerLimit;
  Exi_DIN_PhysicalValueType* EVSEMaximumVoltageLimit;
  Exi_DIN_PhysicalValueType* EVSEMinimumCurrentLimit;
  Exi_DIN_PhysicalValueType* EVSEMinimumVoltageLimit;
  Exi_DIN_PhysicalValueType* EVSEPeakCurrentRipple;
  Exi_BitType EVSECurrentRegulationToleranceFlag : 1;
  Exi_BitType EVSEEnergyToBeDeliveredFlag : 1;
  Exi_BitType EVSEMaximumPowerLimitFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_DIN_DC_EVPowerDeliveryParameterType
{
  Exi_DIN_DC_EVStatusType* DC_EVStatus;
  boolean BulkChargingComplete;
  boolean ChargingComplete;
  Exi_BitType BulkChargingCompleteFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};
#endif  /* EXI_ENABLE_DIN_MESSAGE_SET */

/* PRQA L:IDENTIFIER_NAMES */
/* PRQA L:NAMESPACE */
/* PRQA L:UNION */


#endif /* EXI_DIN_SCHEMA_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_DIN_SchemaTypes.h
 **********************************************************************************************************************/
