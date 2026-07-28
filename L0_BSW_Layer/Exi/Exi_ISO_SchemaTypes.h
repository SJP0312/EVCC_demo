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
/**        \file  Exi_ISO_SchemaTypes.h
 *        \brief  Efficient XML Interchange ISO types header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO types.
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

#if !defined (EXI_ISO_SCHEMA_TYPES_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_SCHEMA_TYPES_H

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
#define EXI_ISO_AC_EVCHARGE_PARAMETER_TYPE                                               (Exi_RootElementIdType)57U
#define EXI_ISO_AC_EVSECHARGE_PARAMETER_TYPE                                             (Exi_RootElementIdType)58U
#define EXI_ISO_AC_EVSESTATUS_TYPE                                                       (Exi_RootElementIdType)59U
#define EXI_ISO_AUTHORIZATION_REQ_TYPE                                                   (Exi_RootElementIdType)60U
#define EXI_ISO_AUTHORIZATION_RES_TYPE                                                   (Exi_RootElementIdType)61U
#define EXI_ISO_BODY_BASE_TYPE                                                           (Exi_RootElementIdType)62U
#define EXI_ISO_CABLE_CHECK_REQ_TYPE                                                     (Exi_RootElementIdType)63U
#define EXI_ISO_CABLE_CHECK_RES_TYPE                                                     (Exi_RootElementIdType)64U
#define EXI_ISO_CERTIFICATE_INSTALLATION_REQ_TYPE                                        (Exi_RootElementIdType)65U
#define EXI_ISO_CERTIFICATE_INSTALLATION_RES_TYPE                                        (Exi_RootElementIdType)66U
#define EXI_ISO_CERTIFICATE_UPDATE_REQ_TYPE                                              (Exi_RootElementIdType)67U
#define EXI_ISO_CERTIFICATE_UPDATE_RES_TYPE                                              (Exi_RootElementIdType)68U
#define EXI_ISO_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE                                      (Exi_RootElementIdType)69U
#define EXI_ISO_CHARGE_PARAMETER_DISCOVERY_RES_TYPE                                      (Exi_RootElementIdType)70U
#define EXI_ISO_CHARGING_STATUS_REQ_TYPE                                                 (Exi_RootElementIdType)71U
#define EXI_ISO_CHARGING_STATUS_RES_TYPE                                                 (Exi_RootElementIdType)72U
#define EXI_ISO_CURRENT_DEMAND_REQ_TYPE                                                  (Exi_RootElementIdType)73U
#define EXI_ISO_CURRENT_DEMAND_RES_TYPE                                                  (Exi_RootElementIdType)74U
#define EXI_ISO_DC_EVCHARGE_PARAMETER_TYPE                                               (Exi_RootElementIdType)75U
#define EXI_ISO_DC_EVPOWER_DELIVERY_PARAMETER_TYPE                                       (Exi_RootElementIdType)76U
#define EXI_ISO_DC_EVSECHARGE_PARAMETER_TYPE                                             (Exi_RootElementIdType)77U
#define EXI_ISO_DC_EVSESTATUS_TYPE                                                       (Exi_RootElementIdType)78U
#define EXI_ISO_DC_EVSTATUS_TYPE                                                         (Exi_RootElementIdType)79U
#define EXI_ISO_EVCHARGE_PARAMETER_TYPE                                                  (Exi_RootElementIdType)80U
#define EXI_ISO_EVPOWER_DELIVERY_PARAMETER_TYPE                                          (Exi_RootElementIdType)81U
#define EXI_ISO_EVSECHARGE_PARAMETER_TYPE                                                (Exi_RootElementIdType)82U
#define EXI_ISO_EVSESTATUS_TYPE                                                          (Exi_RootElementIdType)83U
#define EXI_ISO_EVSTATUS_TYPE                                                            (Exi_RootElementIdType)84U
#define EXI_ISO_ENTRY_TYPE                                                               (Exi_RootElementIdType)85U
#define EXI_ISO_INTERVAL_TYPE                                                            (Exi_RootElementIdType)86U
#define EXI_ISO_METERING_RECEIPT_REQ_TYPE                                                (Exi_RootElementIdType)87U
#define EXI_ISO_METERING_RECEIPT_RES_TYPE                                                (Exi_RootElementIdType)88U
#define EXI_ISO_PMAX_SCHEDULE_ENTRY_TYPE                                                 (Exi_RootElementIdType)89U
#define EXI_ISO_PAYMENT_DETAILS_REQ_TYPE                                                 (Exi_RootElementIdType)90U
#define EXI_ISO_PAYMENT_DETAILS_RES_TYPE                                                 (Exi_RootElementIdType)91U
#define EXI_ISO_PAYMENT_SERVICE_SELECTION_REQ_TYPE                                       (Exi_RootElementIdType)92U
#define EXI_ISO_PAYMENT_SERVICE_SELECTION_RES_TYPE                                       (Exi_RootElementIdType)93U
#define EXI_ISO_POWER_DELIVERY_REQ_TYPE                                                  (Exi_RootElementIdType)94U
#define EXI_ISO_POWER_DELIVERY_RES_TYPE                                                  (Exi_RootElementIdType)95U
#define EXI_ISO_PRE_CHARGE_REQ_TYPE                                                      (Exi_RootElementIdType)96U
#define EXI_ISO_PRE_CHARGE_RES_TYPE                                                      (Exi_RootElementIdType)97U
#define EXI_ISO_RELATIVE_TIME_INTERVAL_TYPE                                              (Exi_RootElementIdType)98U
#define EXI_ISO_SASCHEDULE_LIST_TYPE                                                     (Exi_RootElementIdType)99U
#define EXI_ISO_SASCHEDULES_TYPE                                                         (Exi_RootElementIdType)100U
#define EXI_ISO_SALES_TARIFF_ENTRY_TYPE                                                  (Exi_RootElementIdType)101U
#define EXI_ISO_SERVICE_DETAIL_REQ_TYPE                                                  (Exi_RootElementIdType)102U
#define EXI_ISO_SERVICE_DETAIL_RES_TYPE                                                  (Exi_RootElementIdType)103U
#define EXI_ISO_SERVICE_DISCOVERY_REQ_TYPE                                               (Exi_RootElementIdType)104U
#define EXI_ISO_SERVICE_DISCOVERY_RES_TYPE                                               (Exi_RootElementIdType)105U
#define EXI_ISO_SESSION_SETUP_REQ_TYPE                                                   (Exi_RootElementIdType)106U
#define EXI_ISO_SESSION_SETUP_RES_TYPE                                                   (Exi_RootElementIdType)107U
#define EXI_ISO_SESSION_STOP_REQ_TYPE                                                    (Exi_RootElementIdType)108U
#define EXI_ISO_SESSION_STOP_RES_TYPE                                                    (Exi_RootElementIdType)109U
#define EXI_ISO_V2G_MESSAGE_TYPE                                                         (Exi_RootElementIdType)110U
#define EXI_ISO_WELDING_DETECTION_REQ_TYPE                                               (Exi_RootElementIdType)111U
#define EXI_ISO_WELDING_DETECTION_RES_TYPE                                               (Exi_RootElementIdType)112U

#if (defined(EXI_ENABLE_ISO_MESSAGE_SET) && (EXI_ENABLE_ISO_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* Elements */
#define EXI_ISO_BODY_TYPE                                                                (Exi_RootElementIdType)384U
#define EXI_ISO_BODY_ELEMENT_TYPE                                                        (Exi_RootElementIdType)385U
#define EXI_ISO_BULK_CHARGING_COMPLETE_TYPE                                              (Exi_RootElementIdType)386U
#define EXI_ISO_BULK_SOC_TYPE                                                            (Exi_RootElementIdType)387U
#define EXI_ISO_CERTIFICATE_TYPE                                                         (Exi_RootElementIdType)388U
#define EXI_ISO_CHARGE_PROGRESS_TYPE                                                     (Exi_RootElementIdType)389U
#define EXI_ISO_CHARGE_SERVICE_TYPE                                                      (Exi_RootElementIdType)390U
#define EXI_ISO_CHARGING_COMPLETE_TYPE                                                   (Exi_RootElementIdType)391U
#define EXI_ISO_CHARGING_PROFILE_TYPE                                                    (Exi_RootElementIdType)392U
#define EXI_ISO_CHARGING_PROFILE_ENTRY_MAX_NUMBER_OF_PHASES_IN_USE_TYPE                  (Exi_RootElementIdType)393U
#define EXI_ISO_CHARGING_PROFILE_ENTRY_MAX_POWER_TYPE                                    (Exi_RootElementIdType)394U
#define EXI_ISO_CHARGING_PROFILE_ENTRY_START_TYPE                                        (Exi_RootElementIdType)395U
#define EXI_ISO_CHARGING_SESSION_TYPE                                                    (Exi_RootElementIdType)396U
#define EXI_ISO_CONSUMPTION_COST_TYPE                                                    (Exi_RootElementIdType)397U
#define EXI_ISO_CONTRACT_SIGNATURE_CERT_CHAIN_TYPE                                       (Exi_RootElementIdType)398U
#define EXI_ISO_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_TYPE                            (Exi_RootElementIdType)399U
#define EXI_ISO_COST_TYPE                                                                (Exi_RootElementIdType)400U
#define EXI_ISO_DHPUBLICKEY_TYPE                                                         (Exi_RootElementIdType)401U
#define EXI_ISO_DEPARTURE_TIME_TYPE                                                      (Exi_RootElementIdType)402U
#define EXI_ISO_EAMOUNT_TYPE                                                             (Exi_RootElementIdType)403U
#define EXI_ISO_EPRICE_LEVEL_TYPE                                                        (Exi_RootElementIdType)404U
#define EXI_ISO_EVCCID_TYPE                                                              (Exi_RootElementIdType)405U
#define EXI_ISO_EVENERGY_CAPACITY_TYPE                                                   (Exi_RootElementIdType)406U
#define EXI_ISO_EVENERGY_REQUEST_TYPE                                                    (Exi_RootElementIdType)407U
#define EXI_ISO_EVERROR_CODE_TYPE                                                        (Exi_RootElementIdType)408U
#define EXI_ISO_EVMAX_CURRENT_TYPE                                                       (Exi_RootElementIdType)409U
#define EXI_ISO_EVMAX_VOLTAGE_TYPE                                                       (Exi_RootElementIdType)410U
#define EXI_ISO_EVMAXIMUM_CURRENT_LIMIT_TYPE                                             (Exi_RootElementIdType)411U
#define EXI_ISO_EVMAXIMUM_POWER_LIMIT_TYPE                                               (Exi_RootElementIdType)412U
#define EXI_ISO_EVMAXIMUM_VOLTAGE_LIMIT_TYPE                                             (Exi_RootElementIdType)413U
#define EXI_ISO_EVMIN_CURRENT_TYPE                                                       (Exi_RootElementIdType)414U
#define EXI_ISO_EVRESSSOC_TYPE                                                           (Exi_RootElementIdType)415U
#define EXI_ISO_EVREADY_TYPE                                                             (Exi_RootElementIdType)416U
#define EXI_ISO_EVSECURRENT_LIMIT_ACHIEVED_TYPE                                          (Exi_RootElementIdType)417U
#define EXI_ISO_EVSECURRENT_REGULATION_TOLERANCE_TYPE                                    (Exi_RootElementIdType)418U
#define EXI_ISO_EVSEENERGY_TO_BE_DELIVERED_TYPE                                          (Exi_RootElementIdType)419U
#define EXI_ISO_EVSEID_TYPE                                                              (Exi_RootElementIdType)420U
#define EXI_ISO_EVSEISOLATION_STATUS_TYPE                                                (Exi_RootElementIdType)421U
#define EXI_ISO_EVSEMAX_CURRENT_TYPE                                                     (Exi_RootElementIdType)422U
#define EXI_ISO_EVSEMAXIMUM_CURRENT_LIMIT_TYPE                                           (Exi_RootElementIdType)423U
#define EXI_ISO_EVSEMAXIMUM_POWER_LIMIT_TYPE                                             (Exi_RootElementIdType)424U
#define EXI_ISO_EVSEMAXIMUM_VOLTAGE_LIMIT_TYPE                                           (Exi_RootElementIdType)425U
#define EXI_ISO_EVSEMINIMUM_CURRENT_LIMIT_TYPE                                           (Exi_RootElementIdType)426U
#define EXI_ISO_EVSEMINIMUM_VOLTAGE_LIMIT_TYPE                                           (Exi_RootElementIdType)427U
#define EXI_ISO_EVSENOMINAL_VOLTAGE_TYPE                                                 (Exi_RootElementIdType)428U
#define EXI_ISO_EVSENOTIFICATION_TYPE                                                    (Exi_RootElementIdType)429U
#define EXI_ISO_EVSEPEAK_CURRENT_RIPPLE_TYPE                                             (Exi_RootElementIdType)430U
#define EXI_ISO_EVSEPOWER_LIMIT_ACHIEVED_TYPE                                            (Exi_RootElementIdType)431U
#define EXI_ISO_EVSEPRESENT_CURRENT_TYPE                                                 (Exi_RootElementIdType)432U
#define EXI_ISO_EVSEPRESENT_VOLTAGE_TYPE                                                 (Exi_RootElementIdType)433U
#define EXI_ISO_EVSEPROCESSING_TYPE                                                      (Exi_RootElementIdType)434U
#define EXI_ISO_EVSESTATUS_CODE_TYPE                                                     (Exi_RootElementIdType)435U
#define EXI_ISO_EVSETIME_STAMP_TYPE                                                      (Exi_RootElementIdType)436U
#define EXI_ISO_EVSEVOLTAGE_LIMIT_ACHIEVED_TYPE                                          (Exi_RootElementIdType)437U
#define EXI_ISO_EVTARGET_CURRENT_TYPE                                                    (Exi_RootElementIdType)438U
#define EXI_ISO_EVTARGET_VOLTAGE_TYPE                                                    (Exi_RootElementIdType)439U
#define EXI_ISO_ENERGY_TRANSFER_MODE_TYPE                                                (Exi_RootElementIdType)440U
#define EXI_ISO_FAULT_CODE_TYPE                                                          (Exi_RootElementIdType)441U
#define EXI_ISO_FAULT_MSG_TYPE                                                           (Exi_RootElementIdType)442U
#define EXI_ISO_FREE_SERVICE_TYPE                                                        (Exi_RootElementIdType)443U
#define EXI_ISO_FULL_SOC_TYPE                                                            (Exi_RootElementIdType)444U
#define EXI_ISO_GEN_CHALLENGE_TYPE                                                       (Exi_RootElementIdType)445U
#define EXI_ISO_HEADER_TYPE                                                              (Exi_RootElementIdType)446U
#define EXI_ISO_LIST_OF_ROOT_CERTIFICATE_IDS_TYPE                                        (Exi_RootElementIdType)447U
#define EXI_ISO_MAX_ENTRIES_SASCHEDULE_TUPLE_TYPE                                        (Exi_RootElementIdType)448U
#define EXI_ISO_METER_ID_TYPE                                                            (Exi_RootElementIdType)449U
#define EXI_ISO_METER_INFO_TYPE                                                          (Exi_RootElementIdType)450U
#define EXI_ISO_METER_READING_TYPE                                                       (Exi_RootElementIdType)451U
#define EXI_ISO_METER_STATUS_TYPE                                                        (Exi_RootElementIdType)452U
#define EXI_ISO_MULTIPLIER_TYPE                                                          (Exi_RootElementIdType)453U
#define EXI_ISO_NOTIFICATION_TYPE                                                        (Exi_RootElementIdType)454U
#define EXI_ISO_NOTIFICATION_MAX_DELAY_TYPE                                              (Exi_RootElementIdType)455U
#define EXI_ISO_NUM_EPRICE_LEVELS_TYPE                                                   (Exi_RootElementIdType)456U
#define EXI_ISO_OEMPROVISIONING_CERT_TYPE                                                (Exi_RootElementIdType)457U
#define EXI_ISO_PMAX_TYPE                                                                (Exi_RootElementIdType)458U
#define EXI_ISO_PMAX_SCHEDULE_TYPE                                                       (Exi_RootElementIdType)459U
#define EXI_ISO_PARAMETER_TYPE                                                           (Exi_RootElementIdType)460U
#define EXI_ISO_PARAMETER_SET_TYPE                                                       (Exi_RootElementIdType)461U
#define EXI_ISO_PARAMETER_SET_ID_TYPE                                                    (Exi_RootElementIdType)462U
#define EXI_ISO_PAYMENT_OPTION_TYPE                                                      (Exi_RootElementIdType)463U
#define EXI_ISO_PAYMENT_OPTION_LIST_TYPE                                                 (Exi_RootElementIdType)464U
#define EXI_ISO_PROFILE_ENTRY_TYPE                                                       (Exi_RootElementIdType)465U
#define EXI_ISO_RCD_TYPE                                                                 (Exi_RootElementIdType)466U
#define EXI_ISO_RECEIPT_REQUIRED_TYPE                                                    (Exi_RootElementIdType)467U
#define EXI_ISO_REMAINING_TIME_TO_BULK_SO_C_TYPE                                         (Exi_RootElementIdType)468U
#define EXI_ISO_REMAINING_TIME_TO_FULL_SO_C_TYPE                                         (Exi_RootElementIdType)469U
#define EXI_ISO_REQUESTED_ENERGY_TRANSFER_MODE_TYPE                                      (Exi_RootElementIdType)470U
#define EXI_ISO_RESPONSE_CODE_TYPE                                                       (Exi_RootElementIdType)471U
#define EXI_ISO_RETRY_COUNTER_TYPE                                                       (Exi_RootElementIdType)472U
#define EXI_ISO_ROOT_CERTIFICATE_ID_TYPE                                                 (Exi_RootElementIdType)473U
#define EXI_ISO_SAPROVISIONING_CERTIFICATE_CHAIN_TYPE                                    (Exi_RootElementIdType)474U
#define EXI_ISO_SASCHEDULE_TUPLE_TYPE                                                    (Exi_RootElementIdType)475U
#define EXI_ISO_SASCHEDULE_TUPLE_ID_TYPE                                                 (Exi_RootElementIdType)476U
#define EXI_ISO_SALES_TARIFF_TYPE                                                        (Exi_RootElementIdType)477U
#define EXI_ISO_SALES_TARIFF_DESCRIPTION_TYPE                                            (Exi_RootElementIdType)478U
#define EXI_ISO_SALES_TARIFF_ID_TYPE                                                     (Exi_RootElementIdType)479U
#define EXI_ISO_SELECTED_PAYMENT_OPTION_TYPE                                             (Exi_RootElementIdType)480U
#define EXI_ISO_SELECTED_SERVICE_TYPE                                                    (Exi_RootElementIdType)481U
#define EXI_ISO_SELECTED_SERVICE_LIST_TYPE                                               (Exi_RootElementIdType)482U
#define EXI_ISO_SERVICE_TYPE                                                             (Exi_RootElementIdType)483U
#define EXI_ISO_SERVICE_CATEGORY_TYPE                                                    (Exi_RootElementIdType)484U
#define EXI_ISO_SERVICE_ID_TYPE                                                          (Exi_RootElementIdType)485U
#define EXI_ISO_SERVICE_LIST_TYPE                                                        (Exi_RootElementIdType)486U
#define EXI_ISO_SERVICE_NAME_TYPE                                                        (Exi_RootElementIdType)487U
#define EXI_ISO_SERVICE_PARAMETER_LIST_TYPE                                              (Exi_RootElementIdType)488U
#define EXI_ISO_SERVICE_SCOPE_TYPE                                                       (Exi_RootElementIdType)489U
#define EXI_ISO_SESSION_ID_TYPE                                                          (Exi_RootElementIdType)490U
#define EXI_ISO_SIG_METER_READING_TYPE                                                   (Exi_RootElementIdType)491U
#define EXI_ISO_SIGNATURE_TYPE                                                           (Exi_RootElementIdType)492U
#define EXI_ISO_SUB_CERTIFICATES_TYPE                                                    (Exi_RootElementIdType)493U
#define EXI_ISO_SUPPORTED_ENERGY_TRANSFER_MODE_TYPE                                      (Exi_RootElementIdType)494U
#define EXI_ISO_TMETER_TYPE                                                              (Exi_RootElementIdType)495U
#define EXI_ISO_TIME_INTERVAL_TYPE                                                       (Exi_RootElementIdType)496U
#define EXI_ISO_UNIT_TYPE                                                                (Exi_RootElementIdType)497U
#define EXI_ISO_VALUE_TYPE                                                               (Exi_RootElementIdType)498U
#define EXI_ISO_AMOUNT_TYPE                                                              (Exi_RootElementIdType)499U
#define EXI_ISO_AMOUNT_MULTIPLIER_TYPE                                                   (Exi_RootElementIdType)500U
#define EXI_ISO_BOOL_VALUE_TYPE                                                          (Exi_RootElementIdType)501U
#define EXI_ISO_BYTE_VALUE_TYPE                                                          (Exi_RootElementIdType)502U
#define EXI_ISO_COST_KIND_TYPE                                                           (Exi_RootElementIdType)503U
#define EXI_ISO_DURATION_TYPE                                                            (Exi_RootElementIdType)504U
#define EXI_ISO_E_MAID_TYPE                                                              (Exi_RootElementIdType)505U
#define EXI_ISO_EMAID_TYPE                                                               (Exi_RootElementIdType)506U
#define EXI_ISO_INT_VALUE_TYPE                                                           (Exi_RootElementIdType)507U
#define EXI_ISO_PHYSICAL_VALUE_TYPE                                                      (Exi_RootElementIdType)508U
#define EXI_ISO_SHORT_VALUE_TYPE                                                         (Exi_RootElementIdType)509U
#define EXI_ISO_START_TYPE                                                               (Exi_RootElementIdType)510U
#define EXI_ISO_START_VALUE_TYPE                                                         (Exi_RootElementIdType)511U
#define EXI_ISO_STRING_VALUE_TYPE                                                        (Exi_RootElementIdType)512U
#define EXI_SCHEMA_SET_ISO_TYPE                                                          (Exi_RootElementIdType)3U
#ifndef EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTEID
  #define EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTEID EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTENAME
  #define EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTENAME EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_ISO_CONTRACTSIGNATUREENCRYPTEDPRIVATEKEY
  #define EXI_MAX_BUFFER_SIZE_ISO_CONTRACTSIGNATUREENCRYPTEDPRIVATEKEY EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_ISO_DIFFIEHELLMANPUBLICKEY
  #define EXI_MAX_BUFFER_SIZE_ISO_DIFFIEHELLMANPUBLICKEY EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_ISO_EMAID
  #define EXI_MAX_BUFFER_SIZE_ISO_EMAID EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif

/**********************************************************************************************************************
 *  ELEMENT IDENTIFIER DEFINES
**********************************************************************************************************************/
#define EXI_ISO_EI_DEPARTURE_TIME                                     (uint16)0U
#define EXI_ISO_EI_DEPARTURE_TIME_SE                                  (uint16)1U
#define EXI_ISO_EI_DEPARTURE_TIME_CT                                  (uint16)2U
#define EXI_ISO_EI_DEPARTURE_TIME_EE                                  (uint16)3U
#define EXI_ISO_EI_DEPARTURE_TIME_AT                                  (uint16)4U
#define EXI_ISO_EI_EAMOUNT                                            (uint16)5U
#define EXI_ISO_EI_EAMOUNT_SE                                         (uint16)6U
#define EXI_ISO_EI_EAMOUNT_CT                                         (uint16)7U
#define EXI_ISO_EI_EAMOUNT_EE                                         (uint16)8U
#define EXI_ISO_EI_EAMOUNT_AT                                         (uint16)9U
#define EXI_ISO_EI_EVMAX_VOLTAGE                                      (uint16)10U
#define EXI_ISO_EI_EVMAX_VOLTAGE_SE                                   (uint16)11U
#define EXI_ISO_EI_EVMAX_VOLTAGE_CT                                   (uint16)12U
#define EXI_ISO_EI_EVMAX_VOLTAGE_EE                                   (uint16)13U
#define EXI_ISO_EI_EVMAX_VOLTAGE_AT                                   (uint16)14U
#define EXI_ISO_EI_EVMAX_CURRENT                                      (uint16)15U
#define EXI_ISO_EI_EVMAX_CURRENT_SE                                   (uint16)16U
#define EXI_ISO_EI_EVMAX_CURRENT_CT                                   (uint16)17U
#define EXI_ISO_EI_EVMAX_CURRENT_EE                                   (uint16)18U
#define EXI_ISO_EI_EVMAX_CURRENT_AT                                   (uint16)19U
#define EXI_ISO_EI_EVMIN_CURRENT                                      (uint16)20U
#define EXI_ISO_EI_EVMIN_CURRENT_SE                                   (uint16)21U
#define EXI_ISO_EI_EVMIN_CURRENT_CT                                   (uint16)22U
#define EXI_ISO_EI_EVMIN_CURRENT_EE                                   (uint16)23U
#define EXI_ISO_EI_EVMIN_CURRENT_AT                                   (uint16)24U
#define EXI_ISO_EI_AC_EVCHARGE_PARAMETER                              (uint16)25U
#define EXI_ISO_EI_AC_EVCHARGE_PARAMETER_SE                           (uint16)26U
#define EXI_ISO_EI_AC_EVCHARGE_PARAMETER_CT                           (uint16)27U
#define EXI_ISO_EI_AC_EVCHARGE_PARAMETER_EE                           (uint16)28U
#define EXI_ISO_EI_AC_EVCHARGE_PARAMETER_AT                           (uint16)29U
#define EXI_ISO_EI_AC_EVSESTATUS                                      (uint16)30U
#define EXI_ISO_EI_AC_EVSESTATUS_SE                                   (uint16)31U
#define EXI_ISO_EI_AC_EVSESTATUS_CT                                   (uint16)32U
#define EXI_ISO_EI_AC_EVSESTATUS_EE                                   (uint16)33U
#define EXI_ISO_EI_AC_EVSESTATUS_AT                                   (uint16)34U
#define EXI_ISO_EI_EVSENOMINAL_VOLTAGE                                (uint16)35U
#define EXI_ISO_EI_EVSENOMINAL_VOLTAGE_SE                             (uint16)36U
#define EXI_ISO_EI_EVSENOMINAL_VOLTAGE_CT                             (uint16)37U
#define EXI_ISO_EI_EVSENOMINAL_VOLTAGE_EE                             (uint16)38U
#define EXI_ISO_EI_EVSENOMINAL_VOLTAGE_AT                             (uint16)39U
#define EXI_ISO_EI_EVSEMAX_CURRENT                                    (uint16)40U
#define EXI_ISO_EI_EVSEMAX_CURRENT_SE                                 (uint16)41U
#define EXI_ISO_EI_EVSEMAX_CURRENT_CT                                 (uint16)42U
#define EXI_ISO_EI_EVSEMAX_CURRENT_EE                                 (uint16)43U
#define EXI_ISO_EI_EVSEMAX_CURRENT_AT                                 (uint16)44U
#define EXI_ISO_EI_AC_EVSECHARGE_PARAMETER                            (uint16)45U
#define EXI_ISO_EI_AC_EVSECHARGE_PARAMETER_SE                         (uint16)46U
#define EXI_ISO_EI_AC_EVSECHARGE_PARAMETER_CT                         (uint16)47U
#define EXI_ISO_EI_AC_EVSECHARGE_PARAMETER_EE                         (uint16)48U
#define EXI_ISO_EI_AC_EVSECHARGE_PARAMETER_AT                         (uint16)49U
#define EXI_ISO_EI_NOTIFICATION_MAX_DELAY                             (uint16)50U
#define EXI_ISO_EI_NOTIFICATION_MAX_DELAY_SE                          (uint16)51U
#define EXI_ISO_EI_NOTIFICATION_MAX_DELAY_CT                          (uint16)52U
#define EXI_ISO_EI_NOTIFICATION_MAX_DELAY_EE                          (uint16)53U
#define EXI_ISO_EI_NOTIFICATION_MAX_DELAY_AT                          (uint16)54U
#define EXI_ISO_EI_EVSENOTIFICATION                                   (uint16)55U
#define EXI_ISO_EI_EVSENOTIFICATION_SE                                (uint16)56U
#define EXI_ISO_EI_EVSENOTIFICATION_CT                                (uint16)57U
#define EXI_ISO_EI_EVSENOTIFICATION_EE                                (uint16)58U
#define EXI_ISO_EI_EVSENOTIFICATION_AT                                (uint16)59U
#define EXI_ISO_EI_RCD                                                (uint16)60U
#define EXI_ISO_EI_RCD_SE                                             (uint16)61U
#define EXI_ISO_EI_RCD_CT                                             (uint16)62U
#define EXI_ISO_EI_RCD_EE                                             (uint16)63U
#define EXI_ISO_EI_RCD_AT                                             (uint16)64U
#define EXI_ISO_EI_ATTRIBUTE_ID                                       (uint16)65U
#define EXI_ISO_EI_ATTRIBUTE_ID_SE                                    (uint16)66U
#define EXI_ISO_EI_ATTRIBUTE_ID_CT                                    (uint16)67U
#define EXI_ISO_EI_ATTRIBUTE_ID_EE                                    (uint16)68U
#define EXI_ISO_EI_ATTRIBUTE_ID_AT                                    (uint16)69U
#define EXI_ISO_EI_ATTRIBUTE_NAME                                     (uint16)70U
#define EXI_ISO_EI_ATTRIBUTE_NAME_SE                                  (uint16)71U
#define EXI_ISO_EI_ATTRIBUTE_NAME_CT                                  (uint16)72U
#define EXI_ISO_EI_ATTRIBUTE_NAME_EE                                  (uint16)73U
#define EXI_ISO_EI_ATTRIBUTE_NAME_AT                                  (uint16)74U
#define EXI_ISO_EI_ID                                                 (uint16)75U
#define EXI_ISO_EI_ID_SE                                              (uint16)76U
#define EXI_ISO_EI_ID_CT                                              (uint16)77U
#define EXI_ISO_EI_ID_EE                                              (uint16)78U
#define EXI_ISO_EI_ID_AT                                              (uint16)79U
#define EXI_ISO_EI_GEN_CHALLENGE                                      (uint16)80U
#define EXI_ISO_EI_GEN_CHALLENGE_SE                                   (uint16)81U
#define EXI_ISO_EI_GEN_CHALLENGE_CT                                   (uint16)82U
#define EXI_ISO_EI_GEN_CHALLENGE_EE                                   (uint16)83U
#define EXI_ISO_EI_GEN_CHALLENGE_AT                                   (uint16)84U
#define EXI_ISO_EI_AUTHORIZATION_REQ                                  (uint16)85U
#define EXI_ISO_EI_AUTHORIZATION_REQ_SE                               (uint16)86U
#define EXI_ISO_EI_AUTHORIZATION_REQ_CT                               (uint16)87U
#define EXI_ISO_EI_AUTHORIZATION_REQ_EE                               (uint16)88U
#define EXI_ISO_EI_AUTHORIZATION_REQ_AT                               (uint16)89U
#define EXI_ISO_EI_RESPONSE_CODE                                      (uint16)90U
#define EXI_ISO_EI_RESPONSE_CODE_SE                                   (uint16)91U
#define EXI_ISO_EI_RESPONSE_CODE_CT                                   (uint16)92U
#define EXI_ISO_EI_RESPONSE_CODE_EE                                   (uint16)93U
#define EXI_ISO_EI_RESPONSE_CODE_AT                                   (uint16)94U
#define EXI_ISO_EI_EVSEPROCESSING                                     (uint16)95U
#define EXI_ISO_EI_EVSEPROCESSING_SE                                  (uint16)96U
#define EXI_ISO_EI_EVSEPROCESSING_CT                                  (uint16)97U
#define EXI_ISO_EI_EVSEPROCESSING_EE                                  (uint16)98U
#define EXI_ISO_EI_EVSEPROCESSING_AT                                  (uint16)99U
#define EXI_ISO_EI_AUTHORIZATION_RES                                  (uint16)100U
#define EXI_ISO_EI_AUTHORIZATION_RES_SE                               (uint16)101U
#define EXI_ISO_EI_AUTHORIZATION_RES_CT                               (uint16)102U
#define EXI_ISO_EI_AUTHORIZATION_RES_EE                               (uint16)103U
#define EXI_ISO_EI_AUTHORIZATION_RES_AT                               (uint16)104U
#define EXI_ISO_EI_BODY_ELEMENT                                       (uint16)105U
#define EXI_ISO_EI_BODY_ELEMENT_SE                                    (uint16)106U
#define EXI_ISO_EI_BODY_ELEMENT_CT                                    (uint16)107U
#define EXI_ISO_EI_BODY_ELEMENT_EE                                    (uint16)108U
#define EXI_ISO_EI_BODY_ELEMENT_AT                                    (uint16)109U
#define EXI_ISO_EI_DC_EVSTATUS                                        (uint16)110U
#define EXI_ISO_EI_DC_EVSTATUS_SE                                     (uint16)111U
#define EXI_ISO_EI_DC_EVSTATUS_CT                                     (uint16)112U
#define EXI_ISO_EI_DC_EVSTATUS_EE                                     (uint16)113U
#define EXI_ISO_EI_DC_EVSTATUS_AT                                     (uint16)114U
#define EXI_ISO_EI_CABLE_CHECK_REQ                                    (uint16)115U
#define EXI_ISO_EI_CABLE_CHECK_REQ_SE                                 (uint16)116U
#define EXI_ISO_EI_CABLE_CHECK_REQ_CT                                 (uint16)117U
#define EXI_ISO_EI_CABLE_CHECK_REQ_EE                                 (uint16)118U
#define EXI_ISO_EI_CABLE_CHECK_REQ_AT                                 (uint16)119U
#define EXI_ISO_EI_DC_EVSESTATUS                                      (uint16)120U
#define EXI_ISO_EI_DC_EVSESTATUS_SE                                   (uint16)121U
#define EXI_ISO_EI_DC_EVSESTATUS_CT                                   (uint16)122U
#define EXI_ISO_EI_DC_EVSESTATUS_EE                                   (uint16)123U
#define EXI_ISO_EI_DC_EVSESTATUS_AT                                   (uint16)124U
#define EXI_ISO_EI_CABLE_CHECK_RES                                    (uint16)125U
#define EXI_ISO_EI_CABLE_CHECK_RES_SE                                 (uint16)126U
#define EXI_ISO_EI_CABLE_CHECK_RES_CT                                 (uint16)127U
#define EXI_ISO_EI_CABLE_CHECK_RES_EE                                 (uint16)128U
#define EXI_ISO_EI_CABLE_CHECK_RES_AT                                 (uint16)129U
#define EXI_ISO_EI_CERTIFICATE                                        (uint16)130U
#define EXI_ISO_EI_CERTIFICATE_SE                                     (uint16)131U
#define EXI_ISO_EI_CERTIFICATE_CT                                     (uint16)132U
#define EXI_ISO_EI_CERTIFICATE_EE                                     (uint16)133U
#define EXI_ISO_EI_CERTIFICATE_AT                                     (uint16)134U
#define EXI_ISO_EI_SUB_CERTIFICATES                                   (uint16)135U
#define EXI_ISO_EI_SUB_CERTIFICATES_SE                                (uint16)136U
#define EXI_ISO_EI_SUB_CERTIFICATES_CT                                (uint16)137U
#define EXI_ISO_EI_SUB_CERTIFICATES_EE                                (uint16)138U
#define EXI_ISO_EI_SUB_CERTIFICATES_AT                                (uint16)139U
#define EXI_ISO_EI_OEMPROVISIONING_CERT                               (uint16)140U
#define EXI_ISO_EI_OEMPROVISIONING_CERT_SE                            (uint16)141U
#define EXI_ISO_EI_OEMPROVISIONING_CERT_CT                            (uint16)142U
#define EXI_ISO_EI_OEMPROVISIONING_CERT_EE                            (uint16)143U
#define EXI_ISO_EI_OEMPROVISIONING_CERT_AT                            (uint16)144U
#define EXI_ISO_EI_LIST_OF_ROOT_CERTIFICATE_IDS                       (uint16)145U
#define EXI_ISO_EI_LIST_OF_ROOT_CERTIFICATE_IDS_SE                    (uint16)146U
#define EXI_ISO_EI_LIST_OF_ROOT_CERTIFICATE_IDS_CT                    (uint16)147U
#define EXI_ISO_EI_LIST_OF_ROOT_CERTIFICATE_IDS_EE                    (uint16)148U
#define EXI_ISO_EI_LIST_OF_ROOT_CERTIFICATE_IDS_AT                    (uint16)149U
#define EXI_ISO_EI_CERTIFICATE_INSTALLATION_REQ                       (uint16)150U
#define EXI_ISO_EI_CERTIFICATE_INSTALLATION_REQ_SE                    (uint16)151U
#define EXI_ISO_EI_CERTIFICATE_INSTALLATION_REQ_CT                    (uint16)152U
#define EXI_ISO_EI_CERTIFICATE_INSTALLATION_REQ_EE                    (uint16)153U
#define EXI_ISO_EI_CERTIFICATE_INSTALLATION_REQ_AT                    (uint16)154U
#define EXI_ISO_EI_SAPROVISIONING_CERTIFICATE_CHAIN                   (uint16)155U
#define EXI_ISO_EI_SAPROVISIONING_CERTIFICATE_CHAIN_SE                (uint16)156U
#define EXI_ISO_EI_SAPROVISIONING_CERTIFICATE_CHAIN_CT                (uint16)157U
#define EXI_ISO_EI_SAPROVISIONING_CERTIFICATE_CHAIN_EE                (uint16)158U
#define EXI_ISO_EI_SAPROVISIONING_CERTIFICATE_CHAIN_AT                (uint16)159U
#define EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN                      (uint16)160U
#define EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_SE                   (uint16)161U
#define EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_CT                   (uint16)162U
#define EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_EE                   (uint16)163U
#define EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_AT                   (uint16)164U
#define EXI_ISO_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY           (uint16)165U
#define EXI_ISO_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_SE        (uint16)166U
#define EXI_ISO_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_CT        (uint16)167U
#define EXI_ISO_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_EE        (uint16)168U
#define EXI_ISO_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_AT        (uint16)169U
#define EXI_ISO_EI_DHPUBLICKEY                                        (uint16)170U
#define EXI_ISO_EI_DHPUBLICKEY_SE                                     (uint16)171U
#define EXI_ISO_EI_DHPUBLICKEY_CT                                     (uint16)172U
#define EXI_ISO_EI_DHPUBLICKEY_EE                                     (uint16)173U
#define EXI_ISO_EI_DHPUBLICKEY_AT                                     (uint16)174U
#define EXI_ISO_EI_E_MAID                                             (uint16)175U
#define EXI_ISO_EI_E_MAID_SE                                          (uint16)176U
#define EXI_ISO_EI_E_MAID_CT                                          (uint16)177U
#define EXI_ISO_EI_E_MAID_EE                                          (uint16)178U
#define EXI_ISO_EI_E_MAID_AT                                          (uint16)179U
#define EXI_ISO_EI_CERTIFICATE_INSTALLATION_RES                       (uint16)180U
#define EXI_ISO_EI_CERTIFICATE_INSTALLATION_RES_SE                    (uint16)181U
#define EXI_ISO_EI_CERTIFICATE_INSTALLATION_RES_CT                    (uint16)182U
#define EXI_ISO_EI_CERTIFICATE_INSTALLATION_RES_EE                    (uint16)183U
#define EXI_ISO_EI_CERTIFICATE_INSTALLATION_RES_AT                    (uint16)184U
#define EXI_ISO_EI_CERTIFICATE_UPDATE_REQ                             (uint16)185U
#define EXI_ISO_EI_CERTIFICATE_UPDATE_REQ_SE                          (uint16)186U
#define EXI_ISO_EI_CERTIFICATE_UPDATE_REQ_CT                          (uint16)187U
#define EXI_ISO_EI_CERTIFICATE_UPDATE_REQ_EE                          (uint16)188U
#define EXI_ISO_EI_CERTIFICATE_UPDATE_REQ_AT                          (uint16)189U
#define EXI_ISO_EI_RETRY_COUNTER                                      (uint16)190U
#define EXI_ISO_EI_RETRY_COUNTER_SE                                   (uint16)191U
#define EXI_ISO_EI_RETRY_COUNTER_CT                                   (uint16)192U
#define EXI_ISO_EI_RETRY_COUNTER_EE                                   (uint16)193U
#define EXI_ISO_EI_RETRY_COUNTER_AT                                   (uint16)194U
#define EXI_ISO_EI_CERTIFICATE_UPDATE_RES                             (uint16)195U
#define EXI_ISO_EI_CERTIFICATE_UPDATE_RES_SE                          (uint16)196U
#define EXI_ISO_EI_CERTIFICATE_UPDATE_RES_CT                          (uint16)197U
#define EXI_ISO_EI_CERTIFICATE_UPDATE_RES_EE                          (uint16)198U
#define EXI_ISO_EI_CERTIFICATE_UPDATE_RES_AT                          (uint16)199U
#define EXI_ISO_EI_MAX_ENTRIES_SASCHEDULE_TUPLE                       (uint16)200U
#define EXI_ISO_EI_MAX_ENTRIES_SASCHEDULE_TUPLE_SE                    (uint16)201U
#define EXI_ISO_EI_MAX_ENTRIES_SASCHEDULE_TUPLE_CT                    (uint16)202U
#define EXI_ISO_EI_MAX_ENTRIES_SASCHEDULE_TUPLE_EE                    (uint16)203U
#define EXI_ISO_EI_MAX_ENTRIES_SASCHEDULE_TUPLE_AT                    (uint16)204U
#define EXI_ISO_EI_REQUESTED_ENERGY_TRANSFER_MODE                     (uint16)205U
#define EXI_ISO_EI_REQUESTED_ENERGY_TRANSFER_MODE_SE                  (uint16)206U
#define EXI_ISO_EI_REQUESTED_ENERGY_TRANSFER_MODE_CT                  (uint16)207U
#define EXI_ISO_EI_REQUESTED_ENERGY_TRANSFER_MODE_EE                  (uint16)208U
#define EXI_ISO_EI_REQUESTED_ENERGY_TRANSFER_MODE_AT                  (uint16)209U
#define EXI_ISO_EI_EVCHARGE_PARAMETER                                 (uint16)210U
#define EXI_ISO_EI_EVCHARGE_PARAMETER_SE                              (uint16)211U
#define EXI_ISO_EI_EVCHARGE_PARAMETER_CT                              (uint16)212U
#define EXI_ISO_EI_EVCHARGE_PARAMETER_EE                              (uint16)213U
#define EXI_ISO_EI_EVCHARGE_PARAMETER_AT                              (uint16)214U
#define EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_REQ                     (uint16)215U
#define EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_REQ_SE                  (uint16)216U
#define EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_REQ_CT                  (uint16)217U
#define EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_REQ_EE                  (uint16)218U
#define EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_REQ_AT                  (uint16)219U
#define EXI_ISO_EI_SASCHEDULES                                        (uint16)220U
#define EXI_ISO_EI_SASCHEDULES_SE                                     (uint16)221U
#define EXI_ISO_EI_SASCHEDULES_CT                                     (uint16)222U
#define EXI_ISO_EI_SASCHEDULES_EE                                     (uint16)223U
#define EXI_ISO_EI_SASCHEDULES_AT                                     (uint16)224U
#define EXI_ISO_EI_EVSECHARGE_PARAMETER                               (uint16)225U
#define EXI_ISO_EI_EVSECHARGE_PARAMETER_SE                            (uint16)226U
#define EXI_ISO_EI_EVSECHARGE_PARAMETER_CT                            (uint16)227U
#define EXI_ISO_EI_EVSECHARGE_PARAMETER_EE                            (uint16)228U
#define EXI_ISO_EI_EVSECHARGE_PARAMETER_AT                            (uint16)229U
#define EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_RES                     (uint16)230U
#define EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_RES_SE                  (uint16)231U
#define EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_RES_CT                  (uint16)232U
#define EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_RES_EE                  (uint16)233U
#define EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_RES_AT                  (uint16)234U
#define EXI_ISO_EI_SERVICE_ID                                         (uint16)235U
#define EXI_ISO_EI_SERVICE_ID_SE                                      (uint16)236U
#define EXI_ISO_EI_SERVICE_ID_CT                                      (uint16)237U
#define EXI_ISO_EI_SERVICE_ID_EE                                      (uint16)238U
#define EXI_ISO_EI_SERVICE_ID_AT                                      (uint16)239U
#define EXI_ISO_EI_SERVICE_NAME                                       (uint16)240U
#define EXI_ISO_EI_SERVICE_NAME_SE                                    (uint16)241U
#define EXI_ISO_EI_SERVICE_NAME_CT                                    (uint16)242U
#define EXI_ISO_EI_SERVICE_NAME_EE                                    (uint16)243U
#define EXI_ISO_EI_SERVICE_NAME_AT                                    (uint16)244U
#define EXI_ISO_EI_SERVICE_CATEGORY                                   (uint16)245U
#define EXI_ISO_EI_SERVICE_CATEGORY_SE                                (uint16)246U
#define EXI_ISO_EI_SERVICE_CATEGORY_CT                                (uint16)247U
#define EXI_ISO_EI_SERVICE_CATEGORY_EE                                (uint16)248U
#define EXI_ISO_EI_SERVICE_CATEGORY_AT                                (uint16)249U
#define EXI_ISO_EI_SERVICE_SCOPE                                      (uint16)250U
#define EXI_ISO_EI_SERVICE_SCOPE_SE                                   (uint16)251U
#define EXI_ISO_EI_SERVICE_SCOPE_CT                                   (uint16)252U
#define EXI_ISO_EI_SERVICE_SCOPE_EE                                   (uint16)253U
#define EXI_ISO_EI_SERVICE_SCOPE_AT                                   (uint16)254U
#define EXI_ISO_EI_FREE_SERVICE                                       (uint16)255U
#define EXI_ISO_EI_FREE_SERVICE_SE                                    (uint16)256U
#define EXI_ISO_EI_FREE_SERVICE_CT                                    (uint16)257U
#define EXI_ISO_EI_FREE_SERVICE_EE                                    (uint16)258U
#define EXI_ISO_EI_FREE_SERVICE_AT                                    (uint16)259U
#define EXI_ISO_EI_SUPPORTED_ENERGY_TRANSFER_MODE                     (uint16)260U
#define EXI_ISO_EI_SUPPORTED_ENERGY_TRANSFER_MODE_SE                  (uint16)261U
#define EXI_ISO_EI_SUPPORTED_ENERGY_TRANSFER_MODE_CT                  (uint16)262U
#define EXI_ISO_EI_SUPPORTED_ENERGY_TRANSFER_MODE_EE                  (uint16)263U
#define EXI_ISO_EI_SUPPORTED_ENERGY_TRANSFER_MODE_AT                  (uint16)264U
#define EXI_ISO_EI_PROFILE_ENTRY                                      (uint16)265U
#define EXI_ISO_EI_PROFILE_ENTRY_SE                                   (uint16)266U
#define EXI_ISO_EI_PROFILE_ENTRY_CT                                   (uint16)267U
#define EXI_ISO_EI_PROFILE_ENTRY_EE                                   (uint16)268U
#define EXI_ISO_EI_PROFILE_ENTRY_AT                                   (uint16)269U
#define EXI_ISO_EI_EVSEID                                             (uint16)270U
#define EXI_ISO_EI_EVSEID_SE                                          (uint16)271U
#define EXI_ISO_EI_EVSEID_CT                                          (uint16)272U
#define EXI_ISO_EI_EVSEID_EE                                          (uint16)273U
#define EXI_ISO_EI_EVSEID_AT                                          (uint16)274U
#define EXI_ISO_EI_SASCHEDULE_TUPLE_ID                                (uint16)275U
#define EXI_ISO_EI_SASCHEDULE_TUPLE_ID_SE                             (uint16)276U
#define EXI_ISO_EI_SASCHEDULE_TUPLE_ID_CT                             (uint16)277U
#define EXI_ISO_EI_SASCHEDULE_TUPLE_ID_EE                             (uint16)278U
#define EXI_ISO_EI_SASCHEDULE_TUPLE_ID_AT                             (uint16)279U
#define EXI_ISO_EI_METER_INFO                                         (uint16)280U
#define EXI_ISO_EI_METER_INFO_SE                                      (uint16)281U
#define EXI_ISO_EI_METER_INFO_CT                                      (uint16)282U
#define EXI_ISO_EI_METER_INFO_EE                                      (uint16)283U
#define EXI_ISO_EI_METER_INFO_AT                                      (uint16)284U
#define EXI_ISO_EI_RECEIPT_REQUIRED                                   (uint16)285U
#define EXI_ISO_EI_RECEIPT_REQUIRED_SE                                (uint16)286U
#define EXI_ISO_EI_RECEIPT_REQUIRED_CT                                (uint16)287U
#define EXI_ISO_EI_RECEIPT_REQUIRED_EE                                (uint16)288U
#define EXI_ISO_EI_RECEIPT_REQUIRED_AT                                (uint16)289U
#define EXI_ISO_EI_CHARGING_STATUS_RES                                (uint16)290U
#define EXI_ISO_EI_CHARGING_STATUS_RES_SE                             (uint16)291U
#define EXI_ISO_EI_CHARGING_STATUS_RES_CT                             (uint16)292U
#define EXI_ISO_EI_CHARGING_STATUS_RES_EE                             (uint16)293U
#define EXI_ISO_EI_CHARGING_STATUS_RES_AT                             (uint16)294U
#define EXI_ISO_EI_START_VALUE                                        (uint16)295U
#define EXI_ISO_EI_START_VALUE_SE                                     (uint16)296U
#define EXI_ISO_EI_START_VALUE_CT                                     (uint16)297U
#define EXI_ISO_EI_START_VALUE_EE                                     (uint16)298U
#define EXI_ISO_EI_START_VALUE_AT                                     (uint16)299U
#define EXI_ISO_EI_COST                                               (uint16)300U
#define EXI_ISO_EI_COST_SE                                            (uint16)301U
#define EXI_ISO_EI_COST_CT                                            (uint16)302U
#define EXI_ISO_EI_COST_EE                                            (uint16)303U
#define EXI_ISO_EI_COST_AT                                            (uint16)304U
#define EXI_ISO_EI_COST_KIND                                          (uint16)305U
#define EXI_ISO_EI_COST_KIND_SE                                       (uint16)306U
#define EXI_ISO_EI_COST_KIND_CT                                       (uint16)307U
#define EXI_ISO_EI_COST_KIND_EE                                       (uint16)308U
#define EXI_ISO_EI_COST_KIND_AT                                       (uint16)309U
#define EXI_ISO_EI_AMOUNT                                             (uint16)310U
#define EXI_ISO_EI_AMOUNT_SE                                          (uint16)311U
#define EXI_ISO_EI_AMOUNT_CT                                          (uint16)312U
#define EXI_ISO_EI_AMOUNT_EE                                          (uint16)313U
#define EXI_ISO_EI_AMOUNT_AT                                          (uint16)314U
#define EXI_ISO_EI_AMOUNT_MULTIPLIER                                  (uint16)315U
#define EXI_ISO_EI_AMOUNT_MULTIPLIER_SE                               (uint16)316U
#define EXI_ISO_EI_AMOUNT_MULTIPLIER_CT                               (uint16)317U
#define EXI_ISO_EI_AMOUNT_MULTIPLIER_EE                               (uint16)318U
#define EXI_ISO_EI_AMOUNT_MULTIPLIER_AT                               (uint16)319U
#define EXI_ISO_EI_EVTARGET_CURRENT                                   (uint16)320U
#define EXI_ISO_EI_EVTARGET_CURRENT_SE                                (uint16)321U
#define EXI_ISO_EI_EVTARGET_CURRENT_CT                                (uint16)322U
#define EXI_ISO_EI_EVTARGET_CURRENT_EE                                (uint16)323U
#define EXI_ISO_EI_EVTARGET_CURRENT_AT                                (uint16)324U
#define EXI_ISO_EI_EVMAXIMUM_VOLTAGE_LIMIT                            (uint16)325U
#define EXI_ISO_EI_EVMAXIMUM_VOLTAGE_LIMIT_SE                         (uint16)326U
#define EXI_ISO_EI_EVMAXIMUM_VOLTAGE_LIMIT_CT                         (uint16)327U
#define EXI_ISO_EI_EVMAXIMUM_VOLTAGE_LIMIT_EE                         (uint16)328U
#define EXI_ISO_EI_EVMAXIMUM_VOLTAGE_LIMIT_AT                         (uint16)329U
#define EXI_ISO_EI_EVMAXIMUM_CURRENT_LIMIT                            (uint16)330U
#define EXI_ISO_EI_EVMAXIMUM_CURRENT_LIMIT_SE                         (uint16)331U
#define EXI_ISO_EI_EVMAXIMUM_CURRENT_LIMIT_CT                         (uint16)332U
#define EXI_ISO_EI_EVMAXIMUM_CURRENT_LIMIT_EE                         (uint16)333U
#define EXI_ISO_EI_EVMAXIMUM_CURRENT_LIMIT_AT                         (uint16)334U
#define EXI_ISO_EI_EVMAXIMUM_POWER_LIMIT                              (uint16)335U
#define EXI_ISO_EI_EVMAXIMUM_POWER_LIMIT_SE                           (uint16)336U
#define EXI_ISO_EI_EVMAXIMUM_POWER_LIMIT_CT                           (uint16)337U
#define EXI_ISO_EI_EVMAXIMUM_POWER_LIMIT_EE                           (uint16)338U
#define EXI_ISO_EI_EVMAXIMUM_POWER_LIMIT_AT                           (uint16)339U
#define EXI_ISO_EI_BULK_CHARGING_COMPLETE                             (uint16)340U
#define EXI_ISO_EI_BULK_CHARGING_COMPLETE_SE                          (uint16)341U
#define EXI_ISO_EI_BULK_CHARGING_COMPLETE_CT                          (uint16)342U
#define EXI_ISO_EI_BULK_CHARGING_COMPLETE_EE                          (uint16)343U
#define EXI_ISO_EI_BULK_CHARGING_COMPLETE_AT                          (uint16)344U
#define EXI_ISO_EI_CHARGING_COMPLETE                                  (uint16)345U
#define EXI_ISO_EI_CHARGING_COMPLETE_SE                               (uint16)346U
#define EXI_ISO_EI_CHARGING_COMPLETE_CT                               (uint16)347U
#define EXI_ISO_EI_CHARGING_COMPLETE_EE                               (uint16)348U
#define EXI_ISO_EI_CHARGING_COMPLETE_AT                               (uint16)349U
#define EXI_ISO_EI_REMAINING_TIME_TO_FULL_SO_C                        (uint16)350U
#define EXI_ISO_EI_REMAINING_TIME_TO_FULL_SO_C_SE                     (uint16)351U
#define EXI_ISO_EI_REMAINING_TIME_TO_FULL_SO_C_CT                     (uint16)352U
#define EXI_ISO_EI_REMAINING_TIME_TO_FULL_SO_C_EE                     (uint16)353U
#define EXI_ISO_EI_REMAINING_TIME_TO_FULL_SO_C_AT                     (uint16)354U
#define EXI_ISO_EI_REMAINING_TIME_TO_BULK_SO_C                        (uint16)355U
#define EXI_ISO_EI_REMAINING_TIME_TO_BULK_SO_C_SE                     (uint16)356U
#define EXI_ISO_EI_REMAINING_TIME_TO_BULK_SO_C_CT                     (uint16)357U
#define EXI_ISO_EI_REMAINING_TIME_TO_BULK_SO_C_EE                     (uint16)358U
#define EXI_ISO_EI_REMAINING_TIME_TO_BULK_SO_C_AT                     (uint16)359U
#define EXI_ISO_EI_EVTARGET_VOLTAGE                                   (uint16)360U
#define EXI_ISO_EI_EVTARGET_VOLTAGE_SE                                (uint16)361U
#define EXI_ISO_EI_EVTARGET_VOLTAGE_CT                                (uint16)362U
#define EXI_ISO_EI_EVTARGET_VOLTAGE_EE                                (uint16)363U
#define EXI_ISO_EI_EVTARGET_VOLTAGE_AT                                (uint16)364U
#define EXI_ISO_EI_CURRENT_DEMAND_REQ                                 (uint16)365U
#define EXI_ISO_EI_CURRENT_DEMAND_REQ_SE                              (uint16)366U
#define EXI_ISO_EI_CURRENT_DEMAND_REQ_CT                              (uint16)367U
#define EXI_ISO_EI_CURRENT_DEMAND_REQ_EE                              (uint16)368U
#define EXI_ISO_EI_CURRENT_DEMAND_REQ_AT                              (uint16)369U
#define EXI_ISO_EI_EVSEPRESENT_VOLTAGE                                (uint16)370U
#define EXI_ISO_EI_EVSEPRESENT_VOLTAGE_SE                             (uint16)371U
#define EXI_ISO_EI_EVSEPRESENT_VOLTAGE_CT                             (uint16)372U
#define EXI_ISO_EI_EVSEPRESENT_VOLTAGE_EE                             (uint16)373U
#define EXI_ISO_EI_EVSEPRESENT_VOLTAGE_AT                             (uint16)374U
#define EXI_ISO_EI_EVSEPRESENT_CURRENT                                (uint16)375U
#define EXI_ISO_EI_EVSEPRESENT_CURRENT_SE                             (uint16)376U
#define EXI_ISO_EI_EVSEPRESENT_CURRENT_CT                             (uint16)377U
#define EXI_ISO_EI_EVSEPRESENT_CURRENT_EE                             (uint16)378U
#define EXI_ISO_EI_EVSEPRESENT_CURRENT_AT                             (uint16)379U
#define EXI_ISO_EI_EVSECURRENT_LIMIT_ACHIEVED                         (uint16)380U
#define EXI_ISO_EI_EVSECURRENT_LIMIT_ACHIEVED_SE                      (uint16)381U
#define EXI_ISO_EI_EVSECURRENT_LIMIT_ACHIEVED_CT                      (uint16)382U
#define EXI_ISO_EI_EVSECURRENT_LIMIT_ACHIEVED_EE                      (uint16)383U
#define EXI_ISO_EI_EVSECURRENT_LIMIT_ACHIEVED_AT                      (uint16)384U
#define EXI_ISO_EI_EVSEVOLTAGE_LIMIT_ACHIEVED                         (uint16)385U
#define EXI_ISO_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_SE                      (uint16)386U
#define EXI_ISO_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_CT                      (uint16)387U
#define EXI_ISO_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_EE                      (uint16)388U
#define EXI_ISO_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_AT                      (uint16)389U
#define EXI_ISO_EI_EVSEPOWER_LIMIT_ACHIEVED                           (uint16)390U
#define EXI_ISO_EI_EVSEPOWER_LIMIT_ACHIEVED_SE                        (uint16)391U
#define EXI_ISO_EI_EVSEPOWER_LIMIT_ACHIEVED_CT                        (uint16)392U
#define EXI_ISO_EI_EVSEPOWER_LIMIT_ACHIEVED_EE                        (uint16)393U
#define EXI_ISO_EI_EVSEPOWER_LIMIT_ACHIEVED_AT                        (uint16)394U
#define EXI_ISO_EI_EVSEMAXIMUM_VOLTAGE_LIMIT                          (uint16)395U
#define EXI_ISO_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_SE                       (uint16)396U
#define EXI_ISO_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_CT                       (uint16)397U
#define EXI_ISO_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_EE                       (uint16)398U
#define EXI_ISO_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_AT                       (uint16)399U
#define EXI_ISO_EI_EVSEMAXIMUM_CURRENT_LIMIT                          (uint16)400U
#define EXI_ISO_EI_EVSEMAXIMUM_CURRENT_LIMIT_SE                       (uint16)401U
#define EXI_ISO_EI_EVSEMAXIMUM_CURRENT_LIMIT_CT                       (uint16)402U
#define EXI_ISO_EI_EVSEMAXIMUM_CURRENT_LIMIT_EE                       (uint16)403U
#define EXI_ISO_EI_EVSEMAXIMUM_CURRENT_LIMIT_AT                       (uint16)404U
#define EXI_ISO_EI_EVSEMAXIMUM_POWER_LIMIT                            (uint16)405U
#define EXI_ISO_EI_EVSEMAXIMUM_POWER_LIMIT_SE                         (uint16)406U
#define EXI_ISO_EI_EVSEMAXIMUM_POWER_LIMIT_CT                         (uint16)407U
#define EXI_ISO_EI_EVSEMAXIMUM_POWER_LIMIT_EE                         (uint16)408U
#define EXI_ISO_EI_EVSEMAXIMUM_POWER_LIMIT_AT                         (uint16)409U
#define EXI_ISO_EI_CURRENT_DEMAND_RES                                 (uint16)410U
#define EXI_ISO_EI_CURRENT_DEMAND_RES_SE                              (uint16)411U
#define EXI_ISO_EI_CURRENT_DEMAND_RES_CT                              (uint16)412U
#define EXI_ISO_EI_CURRENT_DEMAND_RES_EE                              (uint16)413U
#define EXI_ISO_EI_CURRENT_DEMAND_RES_AT                              (uint16)414U
#define EXI_ISO_EI_EVENERGY_CAPACITY                                  (uint16)415U
#define EXI_ISO_EI_EVENERGY_CAPACITY_SE                               (uint16)416U
#define EXI_ISO_EI_EVENERGY_CAPACITY_CT                               (uint16)417U
#define EXI_ISO_EI_EVENERGY_CAPACITY_EE                               (uint16)418U
#define EXI_ISO_EI_EVENERGY_CAPACITY_AT                               (uint16)419U
#define EXI_ISO_EI_EVENERGY_REQUEST                                   (uint16)420U
#define EXI_ISO_EI_EVENERGY_REQUEST_SE                                (uint16)421U
#define EXI_ISO_EI_EVENERGY_REQUEST_CT                                (uint16)422U
#define EXI_ISO_EI_EVENERGY_REQUEST_EE                                (uint16)423U
#define EXI_ISO_EI_EVENERGY_REQUEST_AT                                (uint16)424U
#define EXI_ISO_EI_FULL_SOC                                           (uint16)425U
#define EXI_ISO_EI_FULL_SOC_SE                                        (uint16)426U
#define EXI_ISO_EI_FULL_SOC_CT                                        (uint16)427U
#define EXI_ISO_EI_FULL_SOC_EE                                        (uint16)428U
#define EXI_ISO_EI_FULL_SOC_AT                                        (uint16)429U
#define EXI_ISO_EI_BULK_SOC                                           (uint16)430U
#define EXI_ISO_EI_BULK_SOC_SE                                        (uint16)431U
#define EXI_ISO_EI_BULK_SOC_CT                                        (uint16)432U
#define EXI_ISO_EI_BULK_SOC_EE                                        (uint16)433U
#define EXI_ISO_EI_BULK_SOC_AT                                        (uint16)434U
#define EXI_ISO_EI_DC_EVCHARGE_PARAMETER                              (uint16)435U
#define EXI_ISO_EI_DC_EVCHARGE_PARAMETER_SE                           (uint16)436U
#define EXI_ISO_EI_DC_EVCHARGE_PARAMETER_CT                           (uint16)437U
#define EXI_ISO_EI_DC_EVCHARGE_PARAMETER_EE                           (uint16)438U
#define EXI_ISO_EI_DC_EVCHARGE_PARAMETER_AT                           (uint16)439U
#define EXI_ISO_EI_DC_EVERROR_CODE                                    (uint16)440U
#define EXI_ISO_EI_DC_EVERROR_CODE_SE                                 (uint16)441U
#define EXI_ISO_EI_DC_EVERROR_CODE_CT                                 (uint16)442U
#define EXI_ISO_EI_DC_EVERROR_CODE_EE                                 (uint16)443U
#define EXI_ISO_EI_DC_EVERROR_CODE_AT                                 (uint16)444U
#define EXI_ISO_EI_DC_EVPOWER_DELIVERY_PARAMETER                      (uint16)445U
#define EXI_ISO_EI_DC_EVPOWER_DELIVERY_PARAMETER_SE                   (uint16)446U
#define EXI_ISO_EI_DC_EVPOWER_DELIVERY_PARAMETER_CT                   (uint16)447U
#define EXI_ISO_EI_DC_EVPOWER_DELIVERY_PARAMETER_EE                   (uint16)448U
#define EXI_ISO_EI_DC_EVPOWER_DELIVERY_PARAMETER_AT                   (uint16)449U
#define EXI_ISO_EI_EVSEMINIMUM_CURRENT_LIMIT                          (uint16)450U
#define EXI_ISO_EI_EVSEMINIMUM_CURRENT_LIMIT_SE                       (uint16)451U
#define EXI_ISO_EI_EVSEMINIMUM_CURRENT_LIMIT_CT                       (uint16)452U
#define EXI_ISO_EI_EVSEMINIMUM_CURRENT_LIMIT_EE                       (uint16)453U
#define EXI_ISO_EI_EVSEMINIMUM_CURRENT_LIMIT_AT                       (uint16)454U
#define EXI_ISO_EI_EVSEMINIMUM_VOLTAGE_LIMIT                          (uint16)455U
#define EXI_ISO_EI_EVSEMINIMUM_VOLTAGE_LIMIT_SE                       (uint16)456U
#define EXI_ISO_EI_EVSEMINIMUM_VOLTAGE_LIMIT_CT                       (uint16)457U
#define EXI_ISO_EI_EVSEMINIMUM_VOLTAGE_LIMIT_EE                       (uint16)458U
#define EXI_ISO_EI_EVSEMINIMUM_VOLTAGE_LIMIT_AT                       (uint16)459U
#define EXI_ISO_EI_EVSECURRENT_REGULATION_TOLERANCE                   (uint16)460U
#define EXI_ISO_EI_EVSECURRENT_REGULATION_TOLERANCE_SE                (uint16)461U
#define EXI_ISO_EI_EVSECURRENT_REGULATION_TOLERANCE_CT                (uint16)462U
#define EXI_ISO_EI_EVSECURRENT_REGULATION_TOLERANCE_EE                (uint16)463U
#define EXI_ISO_EI_EVSECURRENT_REGULATION_TOLERANCE_AT                (uint16)464U
#define EXI_ISO_EI_EVSEPEAK_CURRENT_RIPPLE                            (uint16)465U
#define EXI_ISO_EI_EVSEPEAK_CURRENT_RIPPLE_SE                         (uint16)466U
#define EXI_ISO_EI_EVSEPEAK_CURRENT_RIPPLE_CT                         (uint16)467U
#define EXI_ISO_EI_EVSEPEAK_CURRENT_RIPPLE_EE                         (uint16)468U
#define EXI_ISO_EI_EVSEPEAK_CURRENT_RIPPLE_AT                         (uint16)469U
#define EXI_ISO_EI_EVSEENERGY_TO_BE_DELIVERED                         (uint16)470U
#define EXI_ISO_EI_EVSEENERGY_TO_BE_DELIVERED_SE                      (uint16)471U
#define EXI_ISO_EI_EVSEENERGY_TO_BE_DELIVERED_CT                      (uint16)472U
#define EXI_ISO_EI_EVSEENERGY_TO_BE_DELIVERED_EE                      (uint16)473U
#define EXI_ISO_EI_EVSEENERGY_TO_BE_DELIVERED_AT                      (uint16)474U
#define EXI_ISO_EI_DC_EVSECHARGE_PARAMETER                            (uint16)475U
#define EXI_ISO_EI_DC_EVSECHARGE_PARAMETER_SE                         (uint16)476U
#define EXI_ISO_EI_DC_EVSECHARGE_PARAMETER_CT                         (uint16)477U
#define EXI_ISO_EI_DC_EVSECHARGE_PARAMETER_EE                         (uint16)478U
#define EXI_ISO_EI_DC_EVSECHARGE_PARAMETER_AT                         (uint16)479U
#define EXI_ISO_EI_DC_EVSESTATUS_CODE                                 (uint16)480U
#define EXI_ISO_EI_DC_EVSESTATUS_CODE_SE                              (uint16)481U
#define EXI_ISO_EI_DC_EVSESTATUS_CODE_CT                              (uint16)482U
#define EXI_ISO_EI_DC_EVSESTATUS_CODE_EE                              (uint16)483U
#define EXI_ISO_EI_DC_EVSESTATUS_CODE_AT                              (uint16)484U
#define EXI_ISO_EI_EVSEISOLATION_STATUS                               (uint16)485U
#define EXI_ISO_EI_EVSEISOLATION_STATUS_SE                            (uint16)486U
#define EXI_ISO_EI_EVSEISOLATION_STATUS_CT                            (uint16)487U
#define EXI_ISO_EI_EVSEISOLATION_STATUS_EE                            (uint16)488U
#define EXI_ISO_EI_EVSEISOLATION_STATUS_AT                            (uint16)489U
#define EXI_ISO_EI_EVSESTATUS_CODE                                    (uint16)490U
#define EXI_ISO_EI_EVSESTATUS_CODE_SE                                 (uint16)491U
#define EXI_ISO_EI_EVSESTATUS_CODE_CT                                 (uint16)492U
#define EXI_ISO_EI_EVSESTATUS_CODE_EE                                 (uint16)493U
#define EXI_ISO_EI_EVSESTATUS_CODE_AT                                 (uint16)494U
#define EXI_ISO_EI_EVREADY                                            (uint16)495U
#define EXI_ISO_EI_EVREADY_SE                                         (uint16)496U
#define EXI_ISO_EI_EVREADY_CT                                         (uint16)497U
#define EXI_ISO_EI_EVREADY_EE                                         (uint16)498U
#define EXI_ISO_EI_EVREADY_AT                                         (uint16)499U
#define EXI_ISO_EI_EVERROR_CODE                                       (uint16)500U
#define EXI_ISO_EI_EVERROR_CODE_SE                                    (uint16)501U
#define EXI_ISO_EI_EVERROR_CODE_CT                                    (uint16)502U
#define EXI_ISO_EI_EVERROR_CODE_EE                                    (uint16)503U
#define EXI_ISO_EI_EVERROR_CODE_AT                                    (uint16)504U
#define EXI_ISO_EI_EVRESSSOC                                          (uint16)505U
#define EXI_ISO_EI_EVRESSSOC_SE                                       (uint16)506U
#define EXI_ISO_EI_EVRESSSOC_CT                                       (uint16)507U
#define EXI_ISO_EI_EVRESSSOC_EE                                       (uint16)508U
#define EXI_ISO_EI_EVRESSSOC_AT                                       (uint16)509U
#define EXI_ISO_EI_DIFFIE_HELLMAN_PUBLICKEY                           (uint16)510U
#define EXI_ISO_EI_DIFFIE_HELLMAN_PUBLICKEY_SE                        (uint16)511U
#define EXI_ISO_EI_DIFFIE_HELLMAN_PUBLICKEY_CT                        (uint16)512U
#define EXI_ISO_EI_DIFFIE_HELLMAN_PUBLICKEY_EE                        (uint16)513U
#define EXI_ISO_EI_DIFFIE_HELLMAN_PUBLICKEY_AT                        (uint16)514U
#define EXI_ISO_EI_EMAID                                              (uint16)515U
#define EXI_ISO_EI_EMAID_SE                                           (uint16)516U
#define EXI_ISO_EI_EMAID_CT                                           (uint16)517U
#define EXI_ISO_EI_EMAID_EE                                           (uint16)518U
#define EXI_ISO_EI_EMAID_AT                                           (uint16)519U
#define EXI_ISO_EI_ENERGY_TRANSFER_MODE                               (uint16)520U
#define EXI_ISO_EI_ENERGY_TRANSFER_MODE_SE                            (uint16)521U
#define EXI_ISO_EI_ENERGY_TRANSFER_MODE_CT                            (uint16)522U
#define EXI_ISO_EI_ENERGY_TRANSFER_MODE_EE                            (uint16)523U
#define EXI_ISO_EI_ENERGY_TRANSFER_MODE_AT                            (uint16)524U
#define EXI_ISO_EI_ROOT_CERTIFICATE_ID                                (uint16)525U
#define EXI_ISO_EI_ROOT_CERTIFICATE_ID_SE                             (uint16)526U
#define EXI_ISO_EI_ROOT_CERTIFICATE_ID_CT                             (uint16)527U
#define EXI_ISO_EI_ROOT_CERTIFICATE_ID_EE                             (uint16)528U
#define EXI_ISO_EI_ROOT_CERTIFICATE_ID_AT                             (uint16)529U
#define EXI_ISO_EI_SESSION_ID                                         (uint16)530U
#define EXI_ISO_EI_SESSION_ID_SE                                      (uint16)531U
#define EXI_ISO_EI_SESSION_ID_CT                                      (uint16)532U
#define EXI_ISO_EI_SESSION_ID_EE                                      (uint16)533U
#define EXI_ISO_EI_SESSION_ID_AT                                      (uint16)534U
#define EXI_ISO_EI_NOTIFICATION                                       (uint16)535U
#define EXI_ISO_EI_NOTIFICATION_SE                                    (uint16)536U
#define EXI_ISO_EI_NOTIFICATION_CT                                    (uint16)537U
#define EXI_ISO_EI_NOTIFICATION_EE                                    (uint16)538U
#define EXI_ISO_EI_NOTIFICATION_AT                                    (uint16)539U
#define EXI_ISO_EI_SIGNATURE                                          (uint16)540U
#define EXI_ISO_EI_SIGNATURE_SE                                       (uint16)541U
#define EXI_ISO_EI_SIGNATURE_CT                                       (uint16)542U
#define EXI_ISO_EI_SIGNATURE_EE                                       (uint16)543U
#define EXI_ISO_EI_SIGNATURE_AT                                       (uint16)544U
#define EXI_ISO_EI_METER_ID                                           (uint16)545U
#define EXI_ISO_EI_METER_ID_SE                                        (uint16)546U
#define EXI_ISO_EI_METER_ID_CT                                        (uint16)547U
#define EXI_ISO_EI_METER_ID_EE                                        (uint16)548U
#define EXI_ISO_EI_METER_ID_AT                                        (uint16)549U
#define EXI_ISO_EI_METER_READING                                      (uint16)550U
#define EXI_ISO_EI_METER_READING_SE                                   (uint16)551U
#define EXI_ISO_EI_METER_READING_CT                                   (uint16)552U
#define EXI_ISO_EI_METER_READING_EE                                   (uint16)553U
#define EXI_ISO_EI_METER_READING_AT                                   (uint16)554U
#define EXI_ISO_EI_SIG_METER_READING                                  (uint16)555U
#define EXI_ISO_EI_SIG_METER_READING_SE                               (uint16)556U
#define EXI_ISO_EI_SIG_METER_READING_CT                               (uint16)557U
#define EXI_ISO_EI_SIG_METER_READING_EE                               (uint16)558U
#define EXI_ISO_EI_SIG_METER_READING_AT                               (uint16)559U
#define EXI_ISO_EI_METER_STATUS                                       (uint16)560U
#define EXI_ISO_EI_METER_STATUS_SE                                    (uint16)561U
#define EXI_ISO_EI_METER_STATUS_CT                                    (uint16)562U
#define EXI_ISO_EI_METER_STATUS_EE                                    (uint16)563U
#define EXI_ISO_EI_METER_STATUS_AT                                    (uint16)564U
#define EXI_ISO_EI_TMETER                                             (uint16)565U
#define EXI_ISO_EI_TMETER_SE                                          (uint16)566U
#define EXI_ISO_EI_TMETER_CT                                          (uint16)567U
#define EXI_ISO_EI_TMETER_EE                                          (uint16)568U
#define EXI_ISO_EI_TMETER_AT                                          (uint16)569U
#define EXI_ISO_EI_METERING_RECEIPT_REQ                               (uint16)570U
#define EXI_ISO_EI_METERING_RECEIPT_REQ_SE                            (uint16)571U
#define EXI_ISO_EI_METERING_RECEIPT_REQ_CT                            (uint16)572U
#define EXI_ISO_EI_METERING_RECEIPT_REQ_EE                            (uint16)573U
#define EXI_ISO_EI_METERING_RECEIPT_REQ_AT                            (uint16)574U
#define EXI_ISO_EI_EVSESTATUS                                         (uint16)575U
#define EXI_ISO_EI_EVSESTATUS_SE                                      (uint16)576U
#define EXI_ISO_EI_EVSESTATUS_CT                                      (uint16)577U
#define EXI_ISO_EI_EVSESTATUS_EE                                      (uint16)578U
#define EXI_ISO_EI_EVSESTATUS_AT                                      (uint16)579U
#define EXI_ISO_EI_METERING_RECEIPT_RES                               (uint16)580U
#define EXI_ISO_EI_METERING_RECEIPT_RES_SE                            (uint16)581U
#define EXI_ISO_EI_METERING_RECEIPT_RES_CT                            (uint16)582U
#define EXI_ISO_EI_METERING_RECEIPT_RES_EE                            (uint16)583U
#define EXI_ISO_EI_METERING_RECEIPT_RES_AT                            (uint16)584U
#define EXI_ISO_EI_FAULT_CODE                                         (uint16)585U
#define EXI_ISO_EI_FAULT_CODE_SE                                      (uint16)586U
#define EXI_ISO_EI_FAULT_CODE_CT                                      (uint16)587U
#define EXI_ISO_EI_FAULT_CODE_EE                                      (uint16)588U
#define EXI_ISO_EI_FAULT_CODE_AT                                      (uint16)589U
#define EXI_ISO_EI_FAULT_MSG                                          (uint16)590U
#define EXI_ISO_EI_FAULT_MSG_SE                                       (uint16)591U
#define EXI_ISO_EI_FAULT_MSG_CT                                       (uint16)592U
#define EXI_ISO_EI_FAULT_MSG_EE                                       (uint16)593U
#define EXI_ISO_EI_FAULT_MSG_AT                                       (uint16)594U
#define EXI_ISO_EI_TIME_INTERVAL                                      (uint16)595U
#define EXI_ISO_EI_TIME_INTERVAL_SE                                   (uint16)596U
#define EXI_ISO_EI_TIME_INTERVAL_CT                                   (uint16)597U
#define EXI_ISO_EI_TIME_INTERVAL_EE                                   (uint16)598U
#define EXI_ISO_EI_TIME_INTERVAL_AT                                   (uint16)599U
#define EXI_ISO_EI_PMAX                                               (uint16)600U
#define EXI_ISO_EI_PMAX_SE                                            (uint16)601U
#define EXI_ISO_EI_PMAX_CT                                            (uint16)602U
#define EXI_ISO_EI_PMAX_EE                                            (uint16)603U
#define EXI_ISO_EI_PMAX_AT                                            (uint16)604U
#define EXI_ISO_EI_PMAX_SCHEDULE_ENTRY                                (uint16)605U
#define EXI_ISO_EI_PMAX_SCHEDULE_ENTRY_SE                             (uint16)606U
#define EXI_ISO_EI_PMAX_SCHEDULE_ENTRY_CT                             (uint16)607U
#define EXI_ISO_EI_PMAX_SCHEDULE_ENTRY_EE                             (uint16)608U
#define EXI_ISO_EI_PMAX_SCHEDULE_ENTRY_AT                             (uint16)609U
#define EXI_ISO_EI_PARAMETER_SET_ID                                   (uint16)610U
#define EXI_ISO_EI_PARAMETER_SET_ID_SE                                (uint16)611U
#define EXI_ISO_EI_PARAMETER_SET_ID_CT                                (uint16)612U
#define EXI_ISO_EI_PARAMETER_SET_ID_EE                                (uint16)613U
#define EXI_ISO_EI_PARAMETER_SET_ID_AT                                (uint16)614U
#define EXI_ISO_EI_PARAMETER                                          (uint16)615U
#define EXI_ISO_EI_PARAMETER_SE                                       (uint16)616U
#define EXI_ISO_EI_PARAMETER_CT                                       (uint16)617U
#define EXI_ISO_EI_PARAMETER_EE                                       (uint16)618U
#define EXI_ISO_EI_PARAMETER_AT                                       (uint16)619U
#define EXI_ISO_EI_NAME                                               (uint16)620U
#define EXI_ISO_EI_NAME_SE                                            (uint16)621U
#define EXI_ISO_EI_NAME_CT                                            (uint16)622U
#define EXI_ISO_EI_NAME_EE                                            (uint16)623U
#define EXI_ISO_EI_NAME_AT                                            (uint16)624U
#define EXI_ISO_EI_CHOICE_ELEMENT                                     (uint16)625U
#define EXI_ISO_EI_CHOICE_ELEMENT_SE                                  (uint16)626U
#define EXI_ISO_EI_CHOICE_ELEMENT_CT                                  (uint16)627U
#define EXI_ISO_EI_CHOICE_ELEMENT_EE                                  (uint16)628U
#define EXI_ISO_EI_CHOICE_ELEMENT_AT                                  (uint16)629U
#define EXI_ISO_EI_BOOL_VALUE                                         (uint16)630U
#define EXI_ISO_EI_BOOL_VALUE_SE                                      (uint16)631U
#define EXI_ISO_EI_BOOL_VALUE_CT                                      (uint16)632U
#define EXI_ISO_EI_BOOL_VALUE_EE                                      (uint16)633U
#define EXI_ISO_EI_BOOL_VALUE_AT                                      (uint16)634U
#define EXI_ISO_EI_BYTE_VALUE                                         (uint16)635U
#define EXI_ISO_EI_BYTE_VALUE_SE                                      (uint16)636U
#define EXI_ISO_EI_BYTE_VALUE_CT                                      (uint16)637U
#define EXI_ISO_EI_BYTE_VALUE_EE                                      (uint16)638U
#define EXI_ISO_EI_BYTE_VALUE_AT                                      (uint16)639U
#define EXI_ISO_EI_SHORT_VALUE                                        (uint16)640U
#define EXI_ISO_EI_SHORT_VALUE_SE                                     (uint16)641U
#define EXI_ISO_EI_SHORT_VALUE_CT                                     (uint16)642U
#define EXI_ISO_EI_SHORT_VALUE_EE                                     (uint16)643U
#define EXI_ISO_EI_SHORT_VALUE_AT                                     (uint16)644U
#define EXI_ISO_EI_INT_VALUE                                          (uint16)645U
#define EXI_ISO_EI_INT_VALUE_SE                                       (uint16)646U
#define EXI_ISO_EI_INT_VALUE_CT                                       (uint16)647U
#define EXI_ISO_EI_INT_VALUE_EE                                       (uint16)648U
#define EXI_ISO_EI_INT_VALUE_AT                                       (uint16)649U
#define EXI_ISO_EI_PAYMENT_DETAILS_REQ                                (uint16)650U
#define EXI_ISO_EI_PAYMENT_DETAILS_REQ_SE                             (uint16)651U
#define EXI_ISO_EI_PAYMENT_DETAILS_REQ_CT                             (uint16)652U
#define EXI_ISO_EI_PAYMENT_DETAILS_REQ_EE                             (uint16)653U
#define EXI_ISO_EI_PAYMENT_DETAILS_REQ_AT                             (uint16)654U
#define EXI_ISO_EI_EVSETIME_STAMP                                     (uint16)655U
#define EXI_ISO_EI_EVSETIME_STAMP_SE                                  (uint16)656U
#define EXI_ISO_EI_EVSETIME_STAMP_CT                                  (uint16)657U
#define EXI_ISO_EI_EVSETIME_STAMP_EE                                  (uint16)658U
#define EXI_ISO_EI_EVSETIME_STAMP_AT                                  (uint16)659U
#define EXI_ISO_EI_PAYMENT_DETAILS_RES                                (uint16)660U
#define EXI_ISO_EI_PAYMENT_DETAILS_RES_SE                             (uint16)661U
#define EXI_ISO_EI_PAYMENT_DETAILS_RES_CT                             (uint16)662U
#define EXI_ISO_EI_PAYMENT_DETAILS_RES_EE                             (uint16)663U
#define EXI_ISO_EI_PAYMENT_DETAILS_RES_AT                             (uint16)664U
#define EXI_ISO_EI_PAYMENT_OPTION                                     (uint16)665U
#define EXI_ISO_EI_PAYMENT_OPTION_SE                                  (uint16)666U
#define EXI_ISO_EI_PAYMENT_OPTION_CT                                  (uint16)667U
#define EXI_ISO_EI_PAYMENT_OPTION_EE                                  (uint16)668U
#define EXI_ISO_EI_PAYMENT_OPTION_AT                                  (uint16)669U
#define EXI_ISO_EI_SELECTED_PAYMENT_OPTION                            (uint16)670U
#define EXI_ISO_EI_SELECTED_PAYMENT_OPTION_SE                         (uint16)671U
#define EXI_ISO_EI_SELECTED_PAYMENT_OPTION_CT                         (uint16)672U
#define EXI_ISO_EI_SELECTED_PAYMENT_OPTION_EE                         (uint16)673U
#define EXI_ISO_EI_SELECTED_PAYMENT_OPTION_AT                         (uint16)674U
#define EXI_ISO_EI_SELECTED_SERVICE_LIST                              (uint16)675U
#define EXI_ISO_EI_SELECTED_SERVICE_LIST_SE                           (uint16)676U
#define EXI_ISO_EI_SELECTED_SERVICE_LIST_CT                           (uint16)677U
#define EXI_ISO_EI_SELECTED_SERVICE_LIST_EE                           (uint16)678U
#define EXI_ISO_EI_SELECTED_SERVICE_LIST_AT                           (uint16)679U
#define EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_REQ                      (uint16)680U
#define EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_REQ_SE                   (uint16)681U
#define EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_REQ_CT                   (uint16)682U
#define EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_REQ_EE                   (uint16)683U
#define EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_REQ_AT                   (uint16)684U
#define EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_RES                      (uint16)685U
#define EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_RES_SE                   (uint16)686U
#define EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_RES_CT                   (uint16)687U
#define EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_RES_EE                   (uint16)688U
#define EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_RES_AT                   (uint16)689U
#define EXI_ISO_EI_MULTIPLIER                                         (uint16)690U
#define EXI_ISO_EI_MULTIPLIER_SE                                      (uint16)691U
#define EXI_ISO_EI_MULTIPLIER_CT                                      (uint16)692U
#define EXI_ISO_EI_MULTIPLIER_EE                                      (uint16)693U
#define EXI_ISO_EI_MULTIPLIER_AT                                      (uint16)694U
#define EXI_ISO_EI_UNIT                                               (uint16)695U
#define EXI_ISO_EI_UNIT_SE                                            (uint16)696U
#define EXI_ISO_EI_UNIT_CT                                            (uint16)697U
#define EXI_ISO_EI_UNIT_EE                                            (uint16)698U
#define EXI_ISO_EI_UNIT_AT                                            (uint16)699U
#define EXI_ISO_EI_VALUE                                              (uint16)700U
#define EXI_ISO_EI_VALUE_SE                                           (uint16)701U
#define EXI_ISO_EI_VALUE_CT                                           (uint16)702U
#define EXI_ISO_EI_VALUE_EE                                           (uint16)703U
#define EXI_ISO_EI_VALUE_AT                                           (uint16)704U
#define EXI_ISO_EI_CHARGE_PROGRESS                                    (uint16)705U
#define EXI_ISO_EI_CHARGE_PROGRESS_SE                                 (uint16)706U
#define EXI_ISO_EI_CHARGE_PROGRESS_CT                                 (uint16)707U
#define EXI_ISO_EI_CHARGE_PROGRESS_EE                                 (uint16)708U
#define EXI_ISO_EI_CHARGE_PROGRESS_AT                                 (uint16)709U
#define EXI_ISO_EI_CHARGING_PROFILE                                   (uint16)710U
#define EXI_ISO_EI_CHARGING_PROFILE_SE                                (uint16)711U
#define EXI_ISO_EI_CHARGING_PROFILE_CT                                (uint16)712U
#define EXI_ISO_EI_CHARGING_PROFILE_EE                                (uint16)713U
#define EXI_ISO_EI_CHARGING_PROFILE_AT                                (uint16)714U
#define EXI_ISO_EI_EVPOWER_DELIVERY_PARAMETER                         (uint16)715U
#define EXI_ISO_EI_EVPOWER_DELIVERY_PARAMETER_SE                      (uint16)716U
#define EXI_ISO_EI_EVPOWER_DELIVERY_PARAMETER_CT                      (uint16)717U
#define EXI_ISO_EI_EVPOWER_DELIVERY_PARAMETER_EE                      (uint16)718U
#define EXI_ISO_EI_EVPOWER_DELIVERY_PARAMETER_AT                      (uint16)719U
#define EXI_ISO_EI_POWER_DELIVERY_REQ                                 (uint16)720U
#define EXI_ISO_EI_POWER_DELIVERY_REQ_SE                              (uint16)721U
#define EXI_ISO_EI_POWER_DELIVERY_REQ_CT                              (uint16)722U
#define EXI_ISO_EI_POWER_DELIVERY_REQ_EE                              (uint16)723U
#define EXI_ISO_EI_POWER_DELIVERY_REQ_AT                              (uint16)724U
#define EXI_ISO_EI_POWER_DELIVERY_RES                                 (uint16)725U
#define EXI_ISO_EI_POWER_DELIVERY_RES_SE                              (uint16)726U
#define EXI_ISO_EI_POWER_DELIVERY_RES_CT                              (uint16)727U
#define EXI_ISO_EI_POWER_DELIVERY_RES_EE                              (uint16)728U
#define EXI_ISO_EI_POWER_DELIVERY_RES_AT                              (uint16)729U
#define EXI_ISO_EI_PRE_CHARGE_REQ                                     (uint16)730U
#define EXI_ISO_EI_PRE_CHARGE_REQ_SE                                  (uint16)731U
#define EXI_ISO_EI_PRE_CHARGE_REQ_CT                                  (uint16)732U
#define EXI_ISO_EI_PRE_CHARGE_REQ_EE                                  (uint16)733U
#define EXI_ISO_EI_PRE_CHARGE_REQ_AT                                  (uint16)734U
#define EXI_ISO_EI_PRE_CHARGE_RES                                     (uint16)735U
#define EXI_ISO_EI_PRE_CHARGE_RES_SE                                  (uint16)736U
#define EXI_ISO_EI_PRE_CHARGE_RES_CT                                  (uint16)737U
#define EXI_ISO_EI_PRE_CHARGE_RES_EE                                  (uint16)738U
#define EXI_ISO_EI_PRE_CHARGE_RES_AT                                  (uint16)739U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_START                       (uint16)740U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_START_SE                    (uint16)741U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_START_CT                    (uint16)742U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_START_EE                    (uint16)743U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_START_AT                    (uint16)744U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_POWER                   (uint16)745U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_POWER_SE                (uint16)746U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_POWER_CT                (uint16)747U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_POWER_EE                (uint16)748U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_POWER_AT                (uint16)749U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_NUMBER_OF_PHASES_IN_USE (uint16)750U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_NUMBER_OF_PHASES_IN_USE_SE (uint16)751U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_NUMBER_OF_PHASES_IN_USE_CT (uint16)752U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_NUMBER_OF_PHASES_IN_USE_EE (uint16)753U
#define EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_NUMBER_OF_PHASES_IN_USE_AT (uint16)754U
#define EXI_ISO_EI_START                                              (uint16)755U
#define EXI_ISO_EI_START_SE                                           (uint16)756U
#define EXI_ISO_EI_START_CT                                           (uint16)757U
#define EXI_ISO_EI_START_EE                                           (uint16)758U
#define EXI_ISO_EI_START_AT                                           (uint16)759U
#define EXI_ISO_EI_DURATION                                           (uint16)760U
#define EXI_ISO_EI_DURATION_SE                                        (uint16)761U
#define EXI_ISO_EI_DURATION_CT                                        (uint16)762U
#define EXI_ISO_EI_DURATION_EE                                        (uint16)763U
#define EXI_ISO_EI_DURATION_AT                                        (uint16)764U
#define EXI_ISO_EI_RELATIVE_TIME_INTERVAL                             (uint16)765U
#define EXI_ISO_EI_RELATIVE_TIME_INTERVAL_SE                          (uint16)766U
#define EXI_ISO_EI_RELATIVE_TIME_INTERVAL_CT                          (uint16)767U
#define EXI_ISO_EI_RELATIVE_TIME_INTERVAL_EE                          (uint16)768U
#define EXI_ISO_EI_RELATIVE_TIME_INTERVAL_AT                          (uint16)769U
#define EXI_ISO_EI_SASCHEDULE_TUPLE                                   (uint16)770U
#define EXI_ISO_EI_SASCHEDULE_TUPLE_SE                                (uint16)771U
#define EXI_ISO_EI_SASCHEDULE_TUPLE_CT                                (uint16)772U
#define EXI_ISO_EI_SASCHEDULE_TUPLE_EE                                (uint16)773U
#define EXI_ISO_EI_SASCHEDULE_TUPLE_AT                                (uint16)774U
#define EXI_ISO_EI_SASCHEDULE_LIST                                    (uint16)775U
#define EXI_ISO_EI_SASCHEDULE_LIST_SE                                 (uint16)776U
#define EXI_ISO_EI_SASCHEDULE_LIST_CT                                 (uint16)777U
#define EXI_ISO_EI_SASCHEDULE_LIST_EE                                 (uint16)778U
#define EXI_ISO_EI_SASCHEDULE_LIST_AT                                 (uint16)779U
#define EXI_ISO_EI_PMAX_SCHEDULE                                      (uint16)780U
#define EXI_ISO_EI_PMAX_SCHEDULE_SE                                   (uint16)781U
#define EXI_ISO_EI_PMAX_SCHEDULE_CT                                   (uint16)782U
#define EXI_ISO_EI_PMAX_SCHEDULE_EE                                   (uint16)783U
#define EXI_ISO_EI_PMAX_SCHEDULE_AT                                   (uint16)784U
#define EXI_ISO_EI_SALES_TARIFF                                       (uint16)785U
#define EXI_ISO_EI_SALES_TARIFF_SE                                    (uint16)786U
#define EXI_ISO_EI_SALES_TARIFF_CT                                    (uint16)787U
#define EXI_ISO_EI_SALES_TARIFF_EE                                    (uint16)788U
#define EXI_ISO_EI_SALES_TARIFF_AT                                    (uint16)789U
#define EXI_ISO_EI_EPRICE_LEVEL                                       (uint16)790U
#define EXI_ISO_EI_EPRICE_LEVEL_SE                                    (uint16)791U
#define EXI_ISO_EI_EPRICE_LEVEL_CT                                    (uint16)792U
#define EXI_ISO_EI_EPRICE_LEVEL_EE                                    (uint16)793U
#define EXI_ISO_EI_EPRICE_LEVEL_AT                                    (uint16)794U
#define EXI_ISO_EI_CONSUMPTION_COST                                   (uint16)795U
#define EXI_ISO_EI_CONSUMPTION_COST_SE                                (uint16)796U
#define EXI_ISO_EI_CONSUMPTION_COST_CT                                (uint16)797U
#define EXI_ISO_EI_CONSUMPTION_COST_EE                                (uint16)798U
#define EXI_ISO_EI_CONSUMPTION_COST_AT                                (uint16)799U
#define EXI_ISO_EI_SALES_TARIFF_ENTRY                                 (uint16)800U
#define EXI_ISO_EI_SALES_TARIFF_ENTRY_SE                              (uint16)801U
#define EXI_ISO_EI_SALES_TARIFF_ENTRY_CT                              (uint16)802U
#define EXI_ISO_EI_SALES_TARIFF_ENTRY_EE                              (uint16)803U
#define EXI_ISO_EI_SALES_TARIFF_ENTRY_AT                              (uint16)804U
#define EXI_ISO_EI_SALES_TARIFF_ID                                    (uint16)805U
#define EXI_ISO_EI_SALES_TARIFF_ID_SE                                 (uint16)806U
#define EXI_ISO_EI_SALES_TARIFF_ID_CT                                 (uint16)807U
#define EXI_ISO_EI_SALES_TARIFF_ID_EE                                 (uint16)808U
#define EXI_ISO_EI_SALES_TARIFF_ID_AT                                 (uint16)809U
#define EXI_ISO_EI_SALES_TARIFF_DESCRIPTION                           (uint16)810U
#define EXI_ISO_EI_SALES_TARIFF_DESCRIPTION_SE                        (uint16)811U
#define EXI_ISO_EI_SALES_TARIFF_DESCRIPTION_CT                        (uint16)812U
#define EXI_ISO_EI_SALES_TARIFF_DESCRIPTION_EE                        (uint16)813U
#define EXI_ISO_EI_SALES_TARIFF_DESCRIPTION_AT                        (uint16)814U
#define EXI_ISO_EI_NUM_EPRICE_LEVELS                                  (uint16)815U
#define EXI_ISO_EI_NUM_EPRICE_LEVELS_SE                               (uint16)816U
#define EXI_ISO_EI_NUM_EPRICE_LEVELS_CT                               (uint16)817U
#define EXI_ISO_EI_NUM_EPRICE_LEVELS_EE                               (uint16)818U
#define EXI_ISO_EI_NUM_EPRICE_LEVELS_AT                               (uint16)819U
#define EXI_ISO_EI_SELECTED_SERVICE                                   (uint16)820U
#define EXI_ISO_EI_SELECTED_SERVICE_SE                                (uint16)821U
#define EXI_ISO_EI_SELECTED_SERVICE_CT                                (uint16)822U
#define EXI_ISO_EI_SELECTED_SERVICE_EE                                (uint16)823U
#define EXI_ISO_EI_SELECTED_SERVICE_AT                                (uint16)824U
#define EXI_ISO_EI_SERVICE_DETAIL_REQ                                 (uint16)825U
#define EXI_ISO_EI_SERVICE_DETAIL_REQ_SE                              (uint16)826U
#define EXI_ISO_EI_SERVICE_DETAIL_REQ_CT                              (uint16)827U
#define EXI_ISO_EI_SERVICE_DETAIL_REQ_EE                              (uint16)828U
#define EXI_ISO_EI_SERVICE_DETAIL_REQ_AT                              (uint16)829U
#define EXI_ISO_EI_SERVICE_PARAMETER_LIST                             (uint16)830U
#define EXI_ISO_EI_SERVICE_PARAMETER_LIST_SE                          (uint16)831U
#define EXI_ISO_EI_SERVICE_PARAMETER_LIST_CT                          (uint16)832U
#define EXI_ISO_EI_SERVICE_PARAMETER_LIST_EE                          (uint16)833U
#define EXI_ISO_EI_SERVICE_PARAMETER_LIST_AT                          (uint16)834U
#define EXI_ISO_EI_SERVICE_DETAIL_RES                                 (uint16)835U
#define EXI_ISO_EI_SERVICE_DETAIL_RES_SE                              (uint16)836U
#define EXI_ISO_EI_SERVICE_DETAIL_RES_CT                              (uint16)837U
#define EXI_ISO_EI_SERVICE_DETAIL_RES_EE                              (uint16)838U
#define EXI_ISO_EI_SERVICE_DETAIL_RES_AT                              (uint16)839U
#define EXI_ISO_EI_SERVICE_DISCOVERY_REQ                              (uint16)840U
#define EXI_ISO_EI_SERVICE_DISCOVERY_REQ_SE                           (uint16)841U
#define EXI_ISO_EI_SERVICE_DISCOVERY_REQ_CT                           (uint16)842U
#define EXI_ISO_EI_SERVICE_DISCOVERY_REQ_EE                           (uint16)843U
#define EXI_ISO_EI_SERVICE_DISCOVERY_REQ_AT                           (uint16)844U
#define EXI_ISO_EI_PAYMENT_OPTION_LIST                                (uint16)845U
#define EXI_ISO_EI_PAYMENT_OPTION_LIST_SE                             (uint16)846U
#define EXI_ISO_EI_PAYMENT_OPTION_LIST_CT                             (uint16)847U
#define EXI_ISO_EI_PAYMENT_OPTION_LIST_EE                             (uint16)848U
#define EXI_ISO_EI_PAYMENT_OPTION_LIST_AT                             (uint16)849U
#define EXI_ISO_EI_CHARGE_SERVICE                                     (uint16)850U
#define EXI_ISO_EI_CHARGE_SERVICE_SE                                  (uint16)851U
#define EXI_ISO_EI_CHARGE_SERVICE_CT                                  (uint16)852U
#define EXI_ISO_EI_CHARGE_SERVICE_EE                                  (uint16)853U
#define EXI_ISO_EI_CHARGE_SERVICE_AT                                  (uint16)854U
#define EXI_ISO_EI_SERVICE_LIST                                       (uint16)855U
#define EXI_ISO_EI_SERVICE_LIST_SE                                    (uint16)856U
#define EXI_ISO_EI_SERVICE_LIST_CT                                    (uint16)857U
#define EXI_ISO_EI_SERVICE_LIST_EE                                    (uint16)858U
#define EXI_ISO_EI_SERVICE_LIST_AT                                    (uint16)859U
#define EXI_ISO_EI_SERVICE_DISCOVERY_RES                              (uint16)860U
#define EXI_ISO_EI_SERVICE_DISCOVERY_RES_SE                           (uint16)861U
#define EXI_ISO_EI_SERVICE_DISCOVERY_RES_CT                           (uint16)862U
#define EXI_ISO_EI_SERVICE_DISCOVERY_RES_EE                           (uint16)863U
#define EXI_ISO_EI_SERVICE_DISCOVERY_RES_AT                           (uint16)864U
#define EXI_ISO_EI_SERVICE                                            (uint16)865U
#define EXI_ISO_EI_SERVICE_SE                                         (uint16)866U
#define EXI_ISO_EI_SERVICE_CT                                         (uint16)867U
#define EXI_ISO_EI_SERVICE_EE                                         (uint16)868U
#define EXI_ISO_EI_SERVICE_AT                                         (uint16)869U
#define EXI_ISO_EI_PARAMETER_SET                                      (uint16)870U
#define EXI_ISO_EI_PARAMETER_SET_SE                                   (uint16)871U
#define EXI_ISO_EI_PARAMETER_SET_CT                                   (uint16)872U
#define EXI_ISO_EI_PARAMETER_SET_EE                                   (uint16)873U
#define EXI_ISO_EI_PARAMETER_SET_AT                                   (uint16)874U
#define EXI_ISO_EI_EVCCID                                             (uint16)875U
#define EXI_ISO_EI_EVCCID_SE                                          (uint16)876U
#define EXI_ISO_EI_EVCCID_CT                                          (uint16)877U
#define EXI_ISO_EI_EVCCID_EE                                          (uint16)878U
#define EXI_ISO_EI_EVCCID_AT                                          (uint16)879U
#define EXI_ISO_EI_SESSION_SETUP_REQ                                  (uint16)880U
#define EXI_ISO_EI_SESSION_SETUP_REQ_SE                               (uint16)881U
#define EXI_ISO_EI_SESSION_SETUP_REQ_CT                               (uint16)882U
#define EXI_ISO_EI_SESSION_SETUP_REQ_EE                               (uint16)883U
#define EXI_ISO_EI_SESSION_SETUP_REQ_AT                               (uint16)884U
#define EXI_ISO_EI_SESSION_SETUP_RES                                  (uint16)885U
#define EXI_ISO_EI_SESSION_SETUP_RES_SE                               (uint16)886U
#define EXI_ISO_EI_SESSION_SETUP_RES_CT                               (uint16)887U
#define EXI_ISO_EI_SESSION_SETUP_RES_EE                               (uint16)888U
#define EXI_ISO_EI_SESSION_SETUP_RES_AT                               (uint16)889U
#define EXI_ISO_EI_CHARGING_SESSION                                   (uint16)890U
#define EXI_ISO_EI_CHARGING_SESSION_SE                                (uint16)891U
#define EXI_ISO_EI_CHARGING_SESSION_CT                                (uint16)892U
#define EXI_ISO_EI_CHARGING_SESSION_EE                                (uint16)893U
#define EXI_ISO_EI_CHARGING_SESSION_AT                                (uint16)894U
#define EXI_ISO_EI_SESSION_STOP_REQ                                   (uint16)895U
#define EXI_ISO_EI_SESSION_STOP_REQ_SE                                (uint16)896U
#define EXI_ISO_EI_SESSION_STOP_REQ_CT                                (uint16)897U
#define EXI_ISO_EI_SESSION_STOP_REQ_EE                                (uint16)898U
#define EXI_ISO_EI_SESSION_STOP_REQ_AT                                (uint16)899U
#define EXI_ISO_EI_SESSION_STOP_RES                                   (uint16)900U
#define EXI_ISO_EI_SESSION_STOP_RES_SE                                (uint16)901U
#define EXI_ISO_EI_SESSION_STOP_RES_CT                                (uint16)902U
#define EXI_ISO_EI_SESSION_STOP_RES_EE                                (uint16)903U
#define EXI_ISO_EI_SESSION_STOP_RES_AT                                (uint16)904U
#define EXI_ISO_EI_HEADER                                             (uint16)905U
#define EXI_ISO_EI_HEADER_SE                                          (uint16)906U
#define EXI_ISO_EI_HEADER_CT                                          (uint16)907U
#define EXI_ISO_EI_HEADER_EE                                          (uint16)908U
#define EXI_ISO_EI_HEADER_AT                                          (uint16)909U
#define EXI_ISO_EI_BODY                                               (uint16)910U
#define EXI_ISO_EI_BODY_SE                                            (uint16)911U
#define EXI_ISO_EI_BODY_CT                                            (uint16)912U
#define EXI_ISO_EI_BODY_EE                                            (uint16)913U
#define EXI_ISO_EI_BODY_AT                                            (uint16)914U
#define EXI_ISO_EI_V2G_MESSAGE                                        (uint16)915U
#define EXI_ISO_EI_V2G_MESSAGE_SE                                     (uint16)916U
#define EXI_ISO_EI_V2G_MESSAGE_CT                                     (uint16)917U
#define EXI_ISO_EI_V2G_MESSAGE_EE                                     (uint16)918U
#define EXI_ISO_EI_V2G_MESSAGE_AT                                     (uint16)919U
#define EXI_ISO_EI_WELDING_DETECTION_REQ                              (uint16)920U
#define EXI_ISO_EI_WELDING_DETECTION_REQ_SE                           (uint16)921U
#define EXI_ISO_EI_WELDING_DETECTION_REQ_CT                           (uint16)922U
#define EXI_ISO_EI_WELDING_DETECTION_REQ_EE                           (uint16)923U
#define EXI_ISO_EI_WELDING_DETECTION_REQ_AT                           (uint16)924U
#define EXI_ISO_EI_WELDING_DETECTION_RES                              (uint16)925U
#define EXI_ISO_EI_WELDING_DETECTION_RES_SE                           (uint16)926U
#define EXI_ISO_EI_WELDING_DETECTION_RES_CT                           (uint16)927U
#define EXI_ISO_EI_WELDING_DETECTION_RES_EE                           (uint16)928U
#define EXI_ISO_EI_WELDING_DETECTION_RES_AT                           (uint16)929U
#define EXI_ISO_EI_EVCC_ID                                            (uint16)930U
#define EXI_ISO_EI_EVCC_ID_SE                                         (uint16)931U
#define EXI_ISO_EI_EVCC_ID_CT                                         (uint16)932U
#define EXI_ISO_EI_EVCC_ID_EE                                         (uint16)933U
#define EXI_ISO_EI_EVCC_ID_AT                                         (uint16)934U
#define EXI_ISO_EI_EVSE_ID                                            (uint16)935U
#define EXI_ISO_EI_EVSE_ID_SE                                         (uint16)936U
#define EXI_ISO_EI_EVSE_ID_CT                                         (uint16)937U
#define EXI_ISO_EI_EVSE_ID_EE                                         (uint16)938U
#define EXI_ISO_EI_EVSE_ID_AT                                         (uint16)939U
#define EXI_ISO_EI_ISOLATION_LEVEL                                    (uint16)940U
#define EXI_ISO_EI_ISOLATION_LEVEL_SE                                 (uint16)941U
#define EXI_ISO_EI_ISOLATION_LEVEL_CT                                 (uint16)942U
#define EXI_ISO_EI_ISOLATION_LEVEL_EE                                 (uint16)943U
#define EXI_ISO_EI_ISOLATION_LEVEL_AT                                 (uint16)944U
#define EXI_ISO_EI_TARIFF_DESCRIPTION                                 (uint16)945U
#define EXI_ISO_EI_TARIFF_DESCRIPTION_SE                              (uint16)946U
#define EXI_ISO_EI_TARIFF_DESCRIPTION_CT                              (uint16)947U
#define EXI_ISO_EI_TARIFF_DESCRIPTION_EE                              (uint16)948U
#define EXI_ISO_EI_TARIFF_DESCRIPTION_AT                              (uint16)949U
#define EXI_ISO_EI_UNIT_SYMBOL                                        (uint16)950U
#define EXI_ISO_EI_UNIT_SYMBOL_SE                                     (uint16)951U
#define EXI_ISO_EI_UNIT_SYMBOL_CT                                     (uint16)952U
#define EXI_ISO_EI_UNIT_SYMBOL_EE                                     (uint16)953U
#define EXI_ISO_EI_UNIT_SYMBOL_AT                                     (uint16)954U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  EXI_ISO_EVSEPROCESSING_TYPE_FINISHED = 0u,
  EXI_ISO_EVSEPROCESSING_TYPE_ONGOING = 1u,
  EXI_ISO_EVSEPROCESSING_TYPE_ONGOING_WAITING_FOR_CUSTOMER_INTERACTION = 2u
} Exi_ISO_EVSEProcessingType;

typedef enum
{
  EXI_ISO_EVSENOTIFICATION_TYPE_NONE = 0u,
  EXI_ISO_EVSENOTIFICATION_TYPE_STOP_CHARGING = 1u,
  EXI_ISO_EVSENOTIFICATION_TYPE_RE_NEGOTIATION = 2u
} Exi_ISO_EVSENotificationType;

typedef enum
{
  EXI_ISO_CHARGE_PROGRESS_TYPE_START = 0u,
  EXI_ISO_CHARGE_PROGRESS_TYPE_STOP = 1u,
  EXI_ISO_CHARGE_PROGRESS_TYPE_RENEGOTIATE = 2u
} Exi_ISO_chargeProgressType;

typedef enum
{
  EXI_ISO_CHARGING_SESSION_TYPE_TERMINATE = 0u,
  EXI_ISO_CHARGING_SESSION_TYPE_PAUSE = 1u
} Exi_ISO_chargingSessionType;

typedef enum
{
  EXI_ISO_SERVICE_CATEGORY_TYPE_EVCHARGING = 0u,
  EXI_ISO_SERVICE_CATEGORY_TYPE_INTERNET = 1u,
  EXI_ISO_SERVICE_CATEGORY_TYPE_CONTRACT_CERTIFICATE = 2u,
  EXI_ISO_SERVICE_CATEGORY_TYPE_OTHER_CUSTOM = 3u
} Exi_ISO_serviceCategoryType;

typedef enum
{
  EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_SINGLE_PHASE_CORE = 0u,
  EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_THREE_PHASE_CORE = 1u,
  EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_CORE = 2u,
  EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_EXTENDED = 3u,
  EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_COMBO_CORE = 4u,
  EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_UNIQUE = 5u
} Exi_ISO_EnergyTransferModeType;

typedef enum
{
  EXI_ISO_COST_KIND_TYPE_RELATIVE_PRICE_PERCENTAGE = 0u,
  EXI_ISO_COST_KIND_TYPE_RENEWABLE_GENERATION_PERCENTAGE = 1u,
  EXI_ISO_COST_KIND_TYPE_CARBON_DIOXIDE_EMISSION = 2u
} Exi_ISO_costKindType;

typedef enum
{
  EXI_ISO_PAYMENT_OPTION_TYPE_CONTRACT = 0u,
  EXI_ISO_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT = 1u
} Exi_ISO_paymentOptionType;

typedef enum
{
  EXI_ISO_FAULT_CODE_TYPE_PARSING_ERROR = 0u,
  EXI_ISO_FAULT_CODE_TYPE_NO_TLSROOT_CERTIFICAT_AVAILABLE = 1u,
  EXI_ISO_FAULT_CODE_TYPE_UNKNOWN_ERROR = 2u
} Exi_ISO_faultCodeType;

typedef enum
{
  EXI_ISO_RESPONSE_CODE_TYPE_OK = 0u,
  EXI_ISO_RESPONSE_CODE_TYPE_OK_NEW_SESSION_ESTABLISHED = 1u,
  EXI_ISO_RESPONSE_CODE_TYPE_OK_OLD_SESSION_JOINED = 2u,
  EXI_ISO_RESPONSE_CODE_TYPE_OK_CERTIFICATE_EXPIRES_SOON = 3u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED = 4u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_SEQUENCE_ERROR = 5u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_SERVICE_IDINVALID = 6u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_UNKNOWN_SESSION = 7u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_SERVICE_SELECTION_INVALID = 8u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_PAYMENT_SELECTION_INVALID = 9u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_CERTIFICATE_EXPIRED = 10u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_SIGNATURE_ERROR = 11u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_NO_CERTIFICATE_AVAILABLE = 12u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_CERT_CHAIN_ERROR = 13u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_CHALLENGE_INVALID = 14u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_CONTRACT_CANCELED = 15u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_WRONG_CHARGE_PARAMETER = 16u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_POWER_DELIVERY_NOT_APPLIED = 17u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_TARIFF_SELECTION_INVALID = 18u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_CHARGING_PROFILE_INVALID = 19u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_METERING_SIGNATURE_NOT_VALID = 20u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_NO_CHARGE_SERVICE_SELECTED = 21u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_WRONG_ENERGY_TRANSFER_MODE = 22u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_CONTACTOR_ERROR = 23u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_CERTIFICATE_NOT_ALLOWED_AT_THIS_EVSE = 24u,
  EXI_ISO_RESPONSE_CODE_TYPE_FAILED_CERTIFICATE_REVOKED = 25u
} Exi_ISO_responseCodeType;

typedef enum
{
  EXI_ISO_UNIT_SYMBOL_TYPE_H = 0u,
  EXI_ISO_UNIT_SYMBOL_TYPE_M = 1u,
  EXI_ISO_UNIT_SYMBOL_TYPE_S = 2u,
  EXI_ISO_UNIT_SYMBOL_TYPE_A = 3u,
  EXI_ISO_UNIT_SYMBOL_TYPE_V = 4u,
  EXI_ISO_UNIT_SYMBOL_TYPE_W = 5u,
  EXI_ISO_UNIT_SYMBOL_TYPE_WH = 6u
} Exi_ISO_unitSymbolType;

typedef enum
{
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_EVSE_NOT_READY = 0u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_EVSE_READY = 1u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_EVSE_SHUTDOWN = 2u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_EVSE_UTILITY_INTERRUPT_EVENT = 3u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_EVSE_ISOLATION_MONITORING_ACTIVE = 4u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_EVSE_EMERGENCY_SHUTDOWN = 5u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_EVSE_MALFUNCTION = 6u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_RESERVED_8 = 7u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_RESERVED_9 = 8u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_RESERVED_A = 9u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_RESERVED_B = 10u,
  EXI_ISO_DC_EVSESTATUS_CODE_TYPE_RESERVED_C = 11u
} Exi_ISO_DC_EVSEStatusCodeType;

typedef enum
{
  EXI_ISO_ISOLATION_LEVEL_TYPE_INVALID = 0u,
  EXI_ISO_ISOLATION_LEVEL_TYPE_VALID = 1u,
  EXI_ISO_ISOLATION_LEVEL_TYPE_WARNING = 2u,
  EXI_ISO_ISOLATION_LEVEL_TYPE_FAULT = 3u,
  EXI_ISO_ISOLATION_LEVEL_TYPE_NO_IMD = 4u
} Exi_ISO_isolationLevelType;

typedef enum
{
  EXI_ISO_DC_EVERROR_CODE_TYPE_NO_ERROR = 0u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_FAILED_RESSTEMPERATURE_INHIBIT = 1u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_FAILED_EVSHIFT_POSITION = 2u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_FAILED_CHARGER_CONNECTOR_LOCK_FAULT = 3u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_FAILED_EVRESSMALFUNCTION = 4u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_FAILED_CHARGING_CURRENTDIFFERENTIAL = 5u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_FAILED_CHARGING_VOLTAGE_OUT_OF_RANGE = 6u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_RESERVED_A = 7u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_RESERVED_B = 8u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_RESERVED_C = 9u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_FAILED_CHARGING_SYSTEM_INCOMPATIBILITY = 10u,
  EXI_ISO_DC_EVERROR_CODE_TYPE_NO_DATA = 11u
} Exi_ISO_DC_EVErrorCodeType;

typedef struct Exi_ISO_faultMsgType Exi_ISO_faultMsgType;
struct Exi_ISO_faultMsgType
{
  uint16 Length;
  uint8 Buffer[64];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_serviceNameType Exi_ISO_serviceNameType;
struct Exi_ISO_serviceNameType
{
  uint16 Length;
  uint8 Buffer[32];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_serviceScopeType Exi_ISO_serviceScopeType;
struct Exi_ISO_serviceScopeType
{
  uint16 Length;
  uint8 Buffer[64];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_genChallengeType Exi_ISO_genChallengeType;
struct Exi_ISO_genChallengeType
{
  uint16 Length;
  uint8 Buffer[16];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_certificateType Exi_ISO_certificateType;
struct Exi_ISO_certificateType
{
  struct Exi_ISO_certificateType* NextCertificatePtr;
  uint16 Length;
  uint8 Buffer[800];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_sigMeterReadingType Exi_ISO_sigMeterReadingType;
struct Exi_ISO_sigMeterReadingType
{
  uint16 Length;
  uint8 Buffer[64];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_sessionIDType Exi_ISO_sessionIDType;
struct Exi_ISO_sessionIDType
{
  uint16 Length;
  uint8 Buffer[8];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_evccIDType Exi_ISO_evccIDType;
struct Exi_ISO_evccIDType
{
  uint16 Length;
  uint8 Buffer[6];
};

typedef struct Exi_ISO_evseIDType Exi_ISO_evseIDType;
struct Exi_ISO_evseIDType
{
  uint16 Length;
  uint8 Buffer[37];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 3u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_eMAIDType Exi_ISO_eMAIDType;
struct Exi_ISO_eMAIDType
{
  uint16 Length;
  uint8 Buffer[15];
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

typedef struct Exi_ISO_meterIDType Exi_ISO_meterIDType;
struct Exi_ISO_meterIDType
{
  uint16 Length;
  uint8 Buffer[32];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_tariffDescriptionType Exi_ISO_tariffDescriptionType;
struct Exi_ISO_tariffDescriptionType
{
  uint16 Length;
  uint8 Buffer[32];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_AttributeNameType Exi_ISO_AttributeNameType;
struct Exi_ISO_AttributeNameType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTENAME];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTENAME ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTENAME ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTENAME ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_AttributeIdType Exi_ISO_AttributeIdType;
struct Exi_ISO_AttributeIdType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTEID];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTEID ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTEID ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTEID ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_ContractSignatureEncryptedPrivateKeyType Exi_ISO_ContractSignatureEncryptedPrivateKeyType;
struct Exi_ISO_ContractSignatureEncryptedPrivateKeyType
{
  Exi_ISO_AttributeIdType* Id;
  uint16 Length;
  uint8 Buffer[48];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_DiffieHellmanPublickeyType Exi_ISO_DiffieHellmanPublickeyType;
struct Exi_ISO_DiffieHellmanPublickeyType
{
  Exi_ISO_AttributeIdType* Id;
  uint16 Length;
  uint8 Buffer[65];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 3u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_EMAIDType Exi_ISO_EMAIDType;
struct Exi_ISO_EMAIDType
{
  Exi_ISO_AttributeIdType* Id;
  uint16 Length;
  uint8 Buffer[15];
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

typedef struct Exi_ISO_ParameterChoiceType Exi_ISO_ParameterChoiceType;

typedef struct Exi_ISO_NotificationType Exi_ISO_NotificationType;

typedef struct Exi_ISO_MessageHeaderType Exi_ISO_MessageHeaderType;

typedef void Exi_ISO_BodyBaseType;

typedef struct Exi_ISO_BodyType Exi_ISO_BodyType;

typedef struct Exi_ISO_V2G_MessageType Exi_ISO_V2G_MessageType;

typedef struct Exi_ISO_SessionSetupReqType Exi_ISO_SessionSetupReqType;

typedef struct Exi_ISO_SessionSetupResType Exi_ISO_SessionSetupResType;

typedef struct Exi_ISO_ServiceDiscoveryReqType Exi_ISO_ServiceDiscoveryReqType;

typedef struct Exi_ISO_PaymentOptionListType Exi_ISO_PaymentOptionListType;

typedef struct Exi_ISO_SupportedEnergyTransferModeType Exi_ISO_SupportedEnergyTransferModeType;

typedef struct Exi_ISO_ChargeServiceType Exi_ISO_ChargeServiceType;

typedef struct Exi_ISO_ServiceType Exi_ISO_ServiceType;

typedef struct Exi_ISO_ServiceListType Exi_ISO_ServiceListType;

typedef struct Exi_ISO_ServiceDiscoveryResType Exi_ISO_ServiceDiscoveryResType;

typedef struct Exi_ISO_ServiceDetailReqType Exi_ISO_ServiceDetailReqType;

typedef struct Exi_ISO_PhysicalValueType Exi_ISO_PhysicalValueType;

typedef struct Exi_ISO_ParameterType Exi_ISO_ParameterType;

typedef struct Exi_ISO_ParameterSetType Exi_ISO_ParameterSetType;

typedef struct Exi_ISO_ServiceParameterListType Exi_ISO_ServiceParameterListType;

typedef struct Exi_ISO_ServiceDetailResType Exi_ISO_ServiceDetailResType;

typedef struct Exi_ISO_SelectedServiceType Exi_ISO_SelectedServiceType;

typedef struct Exi_ISO_SelectedServiceListType Exi_ISO_SelectedServiceListType;

typedef struct Exi_ISO_PaymentServiceSelectionReqType Exi_ISO_PaymentServiceSelectionReqType;

typedef struct Exi_ISO_PaymentServiceSelectionResType Exi_ISO_PaymentServiceSelectionResType;

typedef struct Exi_ISO_SubCertificatesType Exi_ISO_SubCertificatesType;

typedef struct Exi_ISO_CertificateChainType Exi_ISO_CertificateChainType;

typedef struct Exi_ISO_PaymentDetailsReqType Exi_ISO_PaymentDetailsReqType;

typedef struct Exi_ISO_PaymentDetailsResType Exi_ISO_PaymentDetailsResType;

typedef struct Exi_ISO_AuthorizationReqType Exi_ISO_AuthorizationReqType;

typedef struct Exi_ISO_AuthorizationResType Exi_ISO_AuthorizationResType;

typedef struct Exi_ISO_EVChargeParameterType Exi_ISO_EVChargeParameterType;

typedef struct Exi_ISO_ChargeParameterDiscoveryReqType Exi_ISO_ChargeParameterDiscoveryReqType;

typedef void Exi_ISO_SASchedulesType;

typedef void Exi_ISO_EVSEChargeParameterType;

typedef struct Exi_ISO_ChargeParameterDiscoveryResType Exi_ISO_ChargeParameterDiscoveryResType;

typedef struct Exi_ISO_ProfileEntryType Exi_ISO_ProfileEntryType;

typedef struct Exi_ISO_ChargingProfileType Exi_ISO_ChargingProfileType;

typedef void Exi_ISO_EVPowerDeliveryParameterType;

typedef struct Exi_ISO_PowerDeliveryReqType Exi_ISO_PowerDeliveryReqType;

typedef struct Exi_ISO_EVSEStatusType Exi_ISO_EVSEStatusType;

typedef struct Exi_ISO_PowerDeliveryResType Exi_ISO_PowerDeliveryResType;

typedef struct Exi_ISO_MeterInfoType Exi_ISO_MeterInfoType;

typedef struct Exi_ISO_MeteringReceiptReqType Exi_ISO_MeteringReceiptReqType;

typedef struct Exi_ISO_MeteringReceiptResType Exi_ISO_MeteringReceiptResType;

typedef struct Exi_ISO_SessionStopReqType Exi_ISO_SessionStopReqType;

typedef struct Exi_ISO_SessionStopResType Exi_ISO_SessionStopResType;

typedef struct Exi_ISO_ListOfRootCertificateIDsType Exi_ISO_ListOfRootCertificateIDsType;

typedef struct Exi_ISO_CertificateUpdateReqType Exi_ISO_CertificateUpdateReqType;

typedef struct Exi_ISO_CertificateUpdateResType Exi_ISO_CertificateUpdateResType;

typedef struct Exi_ISO_CertificateInstallationReqType Exi_ISO_CertificateInstallationReqType;

typedef struct Exi_ISO_CertificateInstallationResType Exi_ISO_CertificateInstallationResType;

typedef void Exi_ISO_ChargingStatusReqType;

typedef struct Exi_ISO_AC_EVSEStatusType Exi_ISO_AC_EVSEStatusType;

typedef struct Exi_ISO_ChargingStatusResType Exi_ISO_ChargingStatusResType;

typedef struct Exi_ISO_DC_EVStatusType Exi_ISO_DC_EVStatusType;

typedef struct Exi_ISO_CableCheckReqType Exi_ISO_CableCheckReqType;

typedef struct Exi_ISO_DC_EVSEStatusType Exi_ISO_DC_EVSEStatusType;

typedef struct Exi_ISO_CableCheckResType Exi_ISO_CableCheckResType;

typedef struct Exi_ISO_PreChargeReqType Exi_ISO_PreChargeReqType;

typedef struct Exi_ISO_PreChargeResType Exi_ISO_PreChargeResType;

typedef struct Exi_ISO_CurrentDemandReqType Exi_ISO_CurrentDemandReqType;

typedef struct Exi_ISO_CurrentDemandResType Exi_ISO_CurrentDemandResType;

typedef struct Exi_ISO_WeldingDetectionReqType Exi_ISO_WeldingDetectionReqType;

typedef struct Exi_ISO_WeldingDetectionResType Exi_ISO_WeldingDetectionResType;

typedef void Exi_ISO_IntervalType;

typedef struct Exi_ISO_PMaxScheduleEntryType Exi_ISO_PMaxScheduleEntryType;

typedef struct Exi_ISO_PMaxScheduleType Exi_ISO_PMaxScheduleType;

typedef struct Exi_ISO_CostType Exi_ISO_CostType;

typedef struct Exi_ISO_ConsumptionCostType Exi_ISO_ConsumptionCostType;

typedef struct Exi_ISO_SalesTariffEntryType Exi_ISO_SalesTariffEntryType;

typedef struct Exi_ISO_SalesTariffType Exi_ISO_SalesTariffType;

typedef struct Exi_ISO_SAScheduleTupleType Exi_ISO_SAScheduleTupleType;

typedef struct Exi_ISO_SAScheduleListType Exi_ISO_SAScheduleListType;

typedef struct Exi_ISO_EntryType Exi_ISO_EntryType;

typedef struct Exi_ISO_RelativeTimeIntervalType Exi_ISO_RelativeTimeIntervalType;

typedef void Exi_ISO_EVStatusType;

typedef struct Exi_ISO_AC_EVChargeParameterType Exi_ISO_AC_EVChargeParameterType;

typedef struct Exi_ISO_DC_EVChargeParameterType Exi_ISO_DC_EVChargeParameterType;

typedef struct Exi_ISO_AC_EVSEChargeParameterType Exi_ISO_AC_EVSEChargeParameterType;

typedef struct Exi_ISO_DC_EVSEChargeParameterType Exi_ISO_DC_EVSEChargeParameterType;

typedef struct Exi_ISO_DC_EVPowerDeliveryParameterType Exi_ISO_DC_EVPowerDeliveryParameterType;

/* Exi_ISO_valueType has been disabled */

/* Exi_ISO_dHpublickeyType has been disabled */

/* Exi_ISO_privateKeyType has been disabled */

struct Exi_ISO_NotificationType
{
  Exi_ISO_faultMsgType* FaultMsg;
  Exi_ISO_faultCodeType FaultCode; /* Value range: 0 to 2; See type for exact values. */
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

struct Exi_ISO_MessageHeaderType
{
  Exi_ISO_NotificationType* Notification;
  Exi_ISO_sessionIDType* SessionID;
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

struct Exi_ISO_BodyType
{
  Exi_ISO_BodyBaseType* BodyElement; /* Following types are allowed:
          Exi_ISO_SessionSetupReqType
          Exi_ISO_SessionSetupResType
          Exi_ISO_ServiceDiscoveryReqType
          Exi_ISO_ServiceDiscoveryResType
          Exi_ISO_ServiceDetailReqType
          Exi_ISO_ServiceDetailResType
          Exi_ISO_PaymentServiceSelectionReqType
          Exi_ISO_PaymentServiceSelectionResType
          Exi_ISO_PaymentDetailsReqType
          Exi_ISO_PaymentDetailsResType
          Exi_ISO_AuthorizationReqType
          Exi_ISO_AuthorizationResType
          Exi_ISO_ChargeParameterDiscoveryReqType
          Exi_ISO_ChargeParameterDiscoveryResType
          Exi_ISO_PowerDeliveryReqType
          Exi_ISO_PowerDeliveryResType
          Exi_ISO_MeteringReceiptReqType
          Exi_ISO_MeteringReceiptResType
          Exi_ISO_SessionStopReqType
          Exi_ISO_SessionStopResType
          Exi_ISO_CertificateUpdateReqType
          Exi_ISO_CertificateUpdateResType
          Exi_ISO_CertificateInstallationReqType
          Exi_ISO_CertificateInstallationResType
          Exi_ISO_ChargingStatusReqType
          Exi_ISO_ChargingStatusResType
          Exi_ISO_CableCheckReqType
          Exi_ISO_CableCheckResType
          Exi_ISO_PreChargeReqType
          Exi_ISO_PreChargeResType
          Exi_ISO_CurrentDemandReqType
          Exi_ISO_CurrentDemandResType
          Exi_ISO_WeldingDetectionReqType
          Exi_ISO_WeldingDetectionResType */
  Exi_RootElementIdType BodyElementElementId; /* Following element IDs are allowed:
          EXI_ISO_SESSION_SETUP_REQ_TYPE
          EXI_ISO_SESSION_SETUP_RES_TYPE
          EXI_ISO_SERVICE_DISCOVERY_REQ_TYPE
          EXI_ISO_SERVICE_DISCOVERY_RES_TYPE
          EXI_ISO_SERVICE_DETAIL_REQ_TYPE
          EXI_ISO_SERVICE_DETAIL_RES_TYPE
          EXI_ISO_PAYMENT_SERVICE_SELECTION_REQ_TYPE
          EXI_ISO_PAYMENT_SERVICE_SELECTION_RES_TYPE
          EXI_ISO_PAYMENT_DETAILS_REQ_TYPE
          EXI_ISO_PAYMENT_DETAILS_RES_TYPE
          EXI_ISO_AUTHORIZATION_REQ_TYPE
          EXI_ISO_AUTHORIZATION_RES_TYPE
          EXI_ISO_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE
          EXI_ISO_CHARGE_PARAMETER_DISCOVERY_RES_TYPE
          EXI_ISO_POWER_DELIVERY_REQ_TYPE
          EXI_ISO_POWER_DELIVERY_RES_TYPE
          EXI_ISO_METERING_RECEIPT_REQ_TYPE
          EXI_ISO_METERING_RECEIPT_RES_TYPE
          EXI_ISO_SESSION_STOP_REQ_TYPE
          EXI_ISO_SESSION_STOP_RES_TYPE
          EXI_ISO_CERTIFICATE_UPDATE_REQ_TYPE
          EXI_ISO_CERTIFICATE_UPDATE_RES_TYPE
          EXI_ISO_CERTIFICATE_INSTALLATION_REQ_TYPE
          EXI_ISO_CERTIFICATE_INSTALLATION_RES_TYPE
          EXI_ISO_CHARGING_STATUS_REQ_TYPE
          EXI_ISO_CHARGING_STATUS_RES_TYPE
          EXI_ISO_CABLE_CHECK_REQ_TYPE
          EXI_ISO_CABLE_CHECK_RES_TYPE
          EXI_ISO_PRE_CHARGE_REQ_TYPE
          EXI_ISO_PRE_CHARGE_RES_TYPE
          EXI_ISO_CURRENT_DEMAND_REQ_TYPE
          EXI_ISO_CURRENT_DEMAND_RES_TYPE
          EXI_ISO_WELDING_DETECTION_REQ_TYPE
          EXI_ISO_WELDING_DETECTION_RES_TYPE */
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

struct Exi_ISO_V2G_MessageType
{
  Exi_ISO_BodyType* Body;
  Exi_ISO_MessageHeaderType* Header;
};

struct Exi_ISO_SessionSetupReqType
{
  Exi_ISO_evccIDType* EVCCID;
};

struct Exi_ISO_SessionSetupResType
{
  Exi_ISO_evseIDType* EVSEID;
  Exi_SInt64 EVSETimeStamp;
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
  Exi_BitType EVSETimeStampFlag : 1;
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

struct Exi_ISO_ServiceDiscoveryReqType
{
  Exi_ISO_serviceScopeType* ServiceScope;
  Exi_ISO_serviceCategoryType ServiceCategory; /* Value range: 0 to 3; See type for exact values. */
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

struct Exi_ISO_PaymentOptionListType
{
  Exi_ISO_paymentOptionType PaymentOption[2];
  uint8 PaymentOptionCount;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_SupportedEnergyTransferModeType
{
  Exi_ISO_EnergyTransferModeType EnergyTransferMode[6];
  uint8 EnergyTransferModeCount;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (6u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (6u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (6u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_ChargeServiceType
{
  Exi_ISO_serviceNameType* ServiceName;
  Exi_ISO_serviceScopeType* ServiceScope;
  Exi_ISO_SupportedEnergyTransferModeType* SupportedEnergyTransferMode;
  uint16 ServiceID;
  Exi_ISO_serviceCategoryType ServiceCategory; /* Value range: 0 to 3; See type for exact values. */
  boolean FreeService;
  Exi_BitType ServiceNameFlag : 1;
  Exi_BitType ServiceScopeFlag : 1;
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

struct Exi_ISO_ServiceType
{
  struct Exi_ISO_ServiceType* NextServicePtr;
  Exi_ISO_serviceNameType* ServiceName;
  Exi_ISO_serviceScopeType* ServiceScope;
  uint16 ServiceID;
  Exi_ISO_serviceCategoryType ServiceCategory; /* Value range: 0 to 3; See type for exact values. */
  boolean FreeService;
  Exi_BitType ServiceNameFlag : 1;
  Exi_BitType ServiceScopeFlag : 1;
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

struct Exi_ISO_ServiceListType
{
  Exi_ISO_ServiceType* Service;
};

struct Exi_ISO_ServiceDiscoveryResType
{
  Exi_ISO_ChargeServiceType* ChargeService;
  Exi_ISO_PaymentOptionListType* PaymentOptionList;
  Exi_ISO_ServiceListType* ServiceList;
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_ServiceDetailReqType
{
  uint16 ServiceID;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_PhysicalValueType
{
  sint16 Value;
  sint8 Multiplier; /* Value range: min: -3 max: 3 */
  Exi_ISO_unitSymbolType Unit; /* Value range: 0 to 6; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 3u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_ParameterChoiceType
{
  union
  {
    Exi_ISO_PhysicalValueType* physicalValue;
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

struct Exi_ISO_ParameterType
{
  Exi_ISO_ParameterChoiceType* ChoiceElement;
  Exi_ISO_AttributeNameType* Name;
  struct Exi_ISO_ParameterType* NextParameterPtr;
};

struct Exi_ISO_ParameterSetType
{
  struct Exi_ISO_ParameterSetType* NextParameterSetPtr;
  Exi_ISO_ParameterType* Parameter;
  sint16 ParameterSetID;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_ServiceParameterListType
{
  Exi_ISO_ParameterSetType* ParameterSet;
};

struct Exi_ISO_ServiceDetailResType
{
  Exi_ISO_ServiceParameterListType* ServiceParameterList;
  uint16 ServiceID;
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_SelectedServiceType
{
  struct Exi_ISO_SelectedServiceType* NextSelectedServicePtr;
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

struct Exi_ISO_SelectedServiceListType
{
  Exi_ISO_SelectedServiceType* SelectedService;
};

struct Exi_ISO_PaymentServiceSelectionReqType
{
  Exi_ISO_SelectedServiceListType* SelectedServiceList;
  Exi_ISO_paymentOptionType SelectedPaymentOption; /* Value range: 0 to 1; See type for exact values. */
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

struct Exi_ISO_PaymentServiceSelectionResType
{
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_SubCertificatesType
{
  Exi_ISO_certificateType* Certificate;
};

struct Exi_ISO_CertificateChainType
{
  Exi_ISO_certificateType* Certificate;
  Exi_ISO_AttributeIdType* Id;
  Exi_ISO_SubCertificatesType* SubCertificates;
  Exi_BitType IdFlag : 1;
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

struct Exi_ISO_PaymentDetailsReqType
{
  Exi_ISO_CertificateChainType* ContractSignatureCertChain;
  Exi_ISO_eMAIDType* eMAID;
};

struct Exi_ISO_PaymentDetailsResType
{
  Exi_ISO_genChallengeType* GenChallenge;
  Exi_SInt64 EVSETimeStamp;
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_AuthorizationReqType
{
  Exi_ISO_genChallengeType* GenChallenge;
  Exi_ISO_AttributeIdType* Id;
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

struct Exi_ISO_AuthorizationResType
{
  Exi_ISO_EVSEProcessingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_EVChargeParameterType
{
  uint32 DepartureTime;
  Exi_BitType DepartureTimeFlag : 1;
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

struct Exi_ISO_ChargeParameterDiscoveryReqType
{
  Exi_ISO_EVChargeParameterType* EVChargeParameter; /* Following types are allowed:
          Exi_ISO_AC_EVChargeParameterType
          Exi_ISO_DC_EVChargeParameterType */
  Exi_RootElementIdType EVChargeParameterElementId; /* Following element IDs are allowed:
          EXI_ISO_AC_EVCHARGE_PARAMETER_TYPE
          EXI_ISO_DC_EVCHARGE_PARAMETER_TYPE */
  uint16 MaxEntriesSAScheduleTuple;
  Exi_ISO_EnergyTransferModeType RequestedEnergyTransferMode; /* Value range: 0 to 5; See type for exact values. */
  Exi_BitType MaxEntriesSAScheduleTupleFlag : 1;
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

struct Exi_ISO_ChargeParameterDiscoveryResType
{
  Exi_ISO_EVSEChargeParameterType* EVSEChargeParameter; /* Following types are allowed:
          Exi_ISO_AC_EVSEChargeParameterType
          Exi_ISO_DC_EVSEChargeParameterType */
  Exi_ISO_SASchedulesType* SASchedules; /* Following types are allowed:
          Exi_ISO_SAScheduleListType */
  Exi_RootElementIdType EVSEChargeParameterElementId; /* Following element IDs are allowed:
          EXI_ISO_AC_EVSECHARGE_PARAMETER_TYPE
          EXI_ISO_DC_EVSECHARGE_PARAMETER_TYPE */
  Exi_RootElementIdType SASchedulesElementId; /* Following element IDs are allowed:
          EXI_ISO_SASCHEDULE_LIST_TYPE */
  Exi_ISO_EVSEProcessingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
  Exi_BitType SASchedulesFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_ProfileEntryType
{
  Exi_ISO_PhysicalValueType* ChargingProfileEntryMaxPower;
  struct Exi_ISO_ProfileEntryType* NextProfileEntryPtr;
  uint32 ChargingProfileEntryStart;
  sint8 ChargingProfileEntryMaxNumberOfPhasesInUse; /* Value range: min: 1 max: 3 */
  Exi_BitType ChargingProfileEntryMaxNumberOfPhasesInUseFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_ChargingProfileType
{
  Exi_ISO_ProfileEntryType* ProfileEntry;
};

struct Exi_ISO_PowerDeliveryReqType
{
  Exi_ISO_ChargingProfileType* ChargingProfile;
  Exi_ISO_EVPowerDeliveryParameterType* EVPowerDeliveryParameter; /* Following types are allowed:
          Exi_ISO_DC_EVPowerDeliveryParameterType */
  Exi_RootElementIdType EVPowerDeliveryParameterElementId; /* Following element IDs are allowed:
          EXI_ISO_DC_EVPOWER_DELIVERY_PARAMETER_TYPE */
  Exi_ISO_chargeProgressType ChargeProgress; /* Value range: 0 to 2; See type for exact values. */
  uint8 SAScheduleTupleID; /* Value range: min: 1 max: 255 */
  Exi_BitType ChargingProfileFlag : 1;
  Exi_BitType EVPowerDeliveryParameterFlag : 1;
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

struct Exi_ISO_EVSEStatusType
{
  uint16 NotificationMaxDelay;
  Exi_ISO_EVSENotificationType EVSENotification; /* Value range: 0 to 2; See type for exact values. */
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

struct Exi_ISO_PowerDeliveryResType
{
  Exi_ISO_EVSEStatusType* EVSEStatus; /* Following types are allowed:
          Exi_ISO_AC_EVSEStatusType
          Exi_ISO_DC_EVSEStatusType */
  Exi_RootElementIdType EVSEStatusElementId; /* Following element IDs are allowed:
          EXI_ISO_AC_EVSESTATUS_TYPE
          EXI_ISO_DC_EVSESTATUS_TYPE */
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_MeterInfoType
{
  Exi_ISO_meterIDType* MeterID;
  Exi_ISO_sigMeterReadingType* SigMeterReading;
  Exi_SInt64 TMeter;
  Exi_UInt64 MeterReading;
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

struct Exi_ISO_MeteringReceiptReqType
{
  Exi_ISO_AttributeIdType* Id;
  Exi_ISO_MeterInfoType* MeterInfo;
  Exi_ISO_sessionIDType* SessionID;
  uint8 SAScheduleTupleID; /* Value range: min: 1 max: 255 */
  Exi_BitType IdFlag : 1;
  Exi_BitType SAScheduleTupleIDFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_MeteringReceiptResType
{
  Exi_ISO_EVSEStatusType* EVSEStatus; /* Following types are allowed:
          Exi_ISO_AC_EVSEStatusType
          Exi_ISO_DC_EVSEStatusType */
  Exi_RootElementIdType EVSEStatusElementId; /* Following element IDs are allowed:
          EXI_ISO_AC_EVSESTATUS_TYPE
          EXI_ISO_DC_EVSESTATUS_TYPE */
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_SessionStopReqType
{
  Exi_ISO_chargingSessionType ChargingSession; /* Value range: 0 to 1; See type for exact values. */
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

struct Exi_ISO_SessionStopResType
{
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_ListOfRootCertificateIDsType
{
#if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_XMLSIG_X509IssuerSerialType* RootCertificateID;
#else
  uint32 dummy;
#endif
};

struct Exi_ISO_CertificateUpdateReqType
{
  Exi_ISO_CertificateChainType* ContractSignatureCertChain;
  Exi_ISO_AttributeIdType* Id;
  Exi_ISO_ListOfRootCertificateIDsType* ListOfRootCertificateIDs;
  Exi_ISO_eMAIDType* eMAID;
};

struct Exi_ISO_CertificateUpdateResType
{
  Exi_ISO_CertificateChainType* ContractSignatureCertChain;
  Exi_ISO_ContractSignatureEncryptedPrivateKeyType* ContractSignatureEncryptedPrivateKey;
  Exi_ISO_DiffieHellmanPublickeyType* DHpublickey;
  Exi_ISO_CertificateChainType* SAProvisioningCertificateChain;
  Exi_ISO_EMAIDType* eMAID;
  sint16 RetryCounter;
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
  Exi_BitType RetryCounterFlag : 1;
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

struct Exi_ISO_CertificateInstallationReqType
{
  Exi_ISO_AttributeIdType* Id;
  Exi_ISO_ListOfRootCertificateIDsType* ListOfRootCertificateIDs;
  Exi_ISO_certificateType* OEMProvisioningCert;
};

struct Exi_ISO_CertificateInstallationResType
{
  Exi_ISO_CertificateChainType* ContractSignatureCertChain;
  Exi_ISO_ContractSignatureEncryptedPrivateKeyType* ContractSignatureEncryptedPrivateKey;
  Exi_ISO_DiffieHellmanPublickeyType* DHpublickey;
  Exi_ISO_CertificateChainType* SAProvisioningCertificateChain;
  Exi_ISO_EMAIDType* eMAID;
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_AC_EVSEStatusType
{
  uint16 NotificationMaxDelay;
  Exi_ISO_EVSENotificationType EVSENotification; /* Value range: 0 to 2; See type for exact values. */
  boolean RCD;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 3u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_ChargingStatusResType
{
  Exi_ISO_AC_EVSEStatusType* AC_EVSEStatus;
  Exi_ISO_evseIDType* EVSEID;
  Exi_ISO_PhysicalValueType* EVSEMaxCurrent;
  Exi_ISO_MeterInfoType* MeterInfo;
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
  boolean ReceiptRequired;
  uint8 SAScheduleTupleID; /* Value range: min: 1 max: 255 */
  Exi_BitType EVSEMaxCurrentFlag : 1;
  Exi_BitType MeterInfoFlag : 1;
  Exi_BitType ReceiptRequiredFlag : 1;
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

struct Exi_ISO_DC_EVStatusType
{
  Exi_ISO_DC_EVErrorCodeType EVErrorCode; /* Value range: 0 to 11; See type for exact values. */
  boolean EVReady;
  sint8 EVRESSSOC; /* Value range: max: 100 */
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

struct Exi_ISO_CableCheckReqType
{
  Exi_ISO_DC_EVStatusType* DC_EVStatus;
};

struct Exi_ISO_DC_EVSEStatusType
{
  uint16 NotificationMaxDelay;
  Exi_ISO_DC_EVSEStatusCodeType EVSEStatusCode; /* Value range: 0 to 11; See type for exact values. */
  Exi_ISO_EVSENotificationType EVSENotification; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_isolationLevelType EVSEIsolationStatus; /* Value range: 0 to 4; See type for exact values. */
  Exi_BitType EVSEIsolationStatusFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_CableCheckResType
{
  Exi_ISO_DC_EVSEStatusType* DC_EVSEStatus;
  Exi_ISO_EVSEProcessingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_PreChargeReqType
{
  Exi_ISO_DC_EVStatusType* DC_EVStatus;
  Exi_ISO_PhysicalValueType* EVTargetCurrent;
  Exi_ISO_PhysicalValueType* EVTargetVoltage;
};

struct Exi_ISO_PreChargeResType
{
  Exi_ISO_DC_EVSEStatusType* DC_EVSEStatus;
  Exi_ISO_PhysicalValueType* EVSEPresentVoltage;
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_CurrentDemandReqType
{
  Exi_ISO_DC_EVStatusType* DC_EVStatus;
  Exi_ISO_PhysicalValueType* EVMaximumCurrentLimit;
  Exi_ISO_PhysicalValueType* EVMaximumPowerLimit;
  Exi_ISO_PhysicalValueType* EVMaximumVoltageLimit;
  Exi_ISO_PhysicalValueType* EVTargetCurrent;
  Exi_ISO_PhysicalValueType* EVTargetVoltage;
  Exi_ISO_PhysicalValueType* RemainingTimeToBulkSoC;
  Exi_ISO_PhysicalValueType* RemainingTimeToFullSoC;
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

struct Exi_ISO_CurrentDemandResType
{
  Exi_ISO_DC_EVSEStatusType* DC_EVSEStatus;
  Exi_ISO_evseIDType* EVSEID;
  Exi_ISO_PhysicalValueType* EVSEMaximumCurrentLimit;
  Exi_ISO_PhysicalValueType* EVSEMaximumPowerLimit;
  Exi_ISO_PhysicalValueType* EVSEMaximumVoltageLimit;
  Exi_ISO_PhysicalValueType* EVSEPresentCurrent;
  Exi_ISO_PhysicalValueType* EVSEPresentVoltage;
  Exi_ISO_MeterInfoType* MeterInfo;
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
  boolean EVSECurrentLimitAchieved;
  boolean EVSEPowerLimitAchieved;
  boolean EVSEVoltageLimitAchieved;
  boolean ReceiptRequired;
  uint8 SAScheduleTupleID; /* Value range: min: 1 max: 255 */
  Exi_BitType EVSEMaximumCurrentLimitFlag : 1;
  Exi_BitType EVSEMaximumPowerLimitFlag : 1;
  Exi_BitType EVSEMaximumVoltageLimitFlag : 1;
  Exi_BitType MeterInfoFlag : 1;
  Exi_BitType ReceiptRequiredFlag : 1;
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

struct Exi_ISO_WeldingDetectionReqType
{
  Exi_ISO_DC_EVStatusType* DC_EVStatus;
};

struct Exi_ISO_WeldingDetectionResType
{
  Exi_ISO_DC_EVSEStatusType* DC_EVSEStatus;
  Exi_ISO_PhysicalValueType* EVSEPresentVoltage;
  Exi_ISO_responseCodeType ResponseCode; /* Value range: 0 to 25; See type for exact values. */
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

struct Exi_ISO_PMaxScheduleEntryType
{
  struct Exi_ISO_PMaxScheduleEntryType* NextPMaxScheduleEntryPtr;
  Exi_ISO_PhysicalValueType* PMax;
  Exi_ISO_IntervalType* TimeInterval; /* Following types are allowed:
          Exi_ISO_RelativeTimeIntervalType */
  Exi_RootElementIdType TimeIntervalElementId; /* Following element IDs are allowed:
          EXI_ISO_RELATIVE_TIME_INTERVAL_TYPE */
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_PMaxScheduleType
{
  Exi_ISO_PMaxScheduleEntryType* PMaxScheduleEntry;
};

struct Exi_ISO_CostType
{
  struct Exi_ISO_CostType* NextCostPtr;
  uint32 amount;
  Exi_ISO_costKindType costKind; /* Value range: 0 to 2; See type for exact values. */
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

struct Exi_ISO_ConsumptionCostType
{
  Exi_ISO_CostType* Cost;
  struct Exi_ISO_ConsumptionCostType* NextConsumptionCostPtr;
  Exi_ISO_PhysicalValueType* startValue;
};

struct Exi_ISO_SalesTariffEntryType
{
  Exi_ISO_ConsumptionCostType* ConsumptionCost;
  struct Exi_ISO_SalesTariffEntryType* NextSalesTariffEntryPtr;
  Exi_ISO_IntervalType* TimeInterval; /* Following types are allowed:
          Exi_ISO_RelativeTimeIntervalType */
  Exi_RootElementIdType TimeIntervalElementId; /* Following element IDs are allowed:
          EXI_ISO_RELATIVE_TIME_INTERVAL_TYPE */
  uint8 EPriceLevel;
  Exi_BitType ConsumptionCostFlag : 1;
  Exi_BitType EPriceLevelFlag : 1;
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

struct Exi_ISO_SalesTariffType
{
  Exi_ISO_AttributeIdType* Id;
  Exi_ISO_tariffDescriptionType* SalesTariffDescription;
  Exi_ISO_SalesTariffEntryType* SalesTariffEntry;
  uint8 NumEPriceLevels;
  uint8 SalesTariffID; /* Value range: min: 1 max: 255 */
  Exi_BitType IdFlag : 1;
  Exi_BitType NumEPriceLevelsFlag : 1;
  Exi_BitType SalesTariffDescriptionFlag : 1;
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

struct Exi_ISO_SAScheduleTupleType
{
  struct Exi_ISO_SAScheduleTupleType* NextSAScheduleTuplePtr;
  Exi_ISO_PMaxScheduleType* PMaxSchedule;
  Exi_ISO_SalesTariffType* SalesTariff;
  uint8 SAScheduleTupleID; /* Value range: min: 1 max: 255 */
  Exi_BitType SalesTariffFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_SAScheduleListType
{
  Exi_ISO_SAScheduleTupleType* SAScheduleTuple;
};

struct Exi_ISO_EntryType
{
  Exi_ISO_IntervalType* TimeInterval; /* Following types are allowed:
          Exi_ISO_RelativeTimeIntervalType */
  Exi_RootElementIdType TimeIntervalElementId; /* Following element IDs are allowed:
          EXI_ISO_RELATIVE_TIME_INTERVAL_TYPE */
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_RelativeTimeIntervalType
{
  uint32 duration; /* Value range: max: 86400 */
  uint32 start; /* Value range: max: 16777214 */
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

struct Exi_ISO_AC_EVChargeParameterType
{
  Exi_ISO_PhysicalValueType* EAmount;
  Exi_ISO_PhysicalValueType* EVMaxCurrent;
  Exi_ISO_PhysicalValueType* EVMaxVoltage;
  Exi_ISO_PhysicalValueType* EVMinCurrent;
  uint32 DepartureTime;
  Exi_BitType DepartureTimeFlag : 1;
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

struct Exi_ISO_DC_EVChargeParameterType
{
  Exi_ISO_DC_EVStatusType* DC_EVStatus;
  Exi_ISO_PhysicalValueType* EVEnergyCapacity;
  Exi_ISO_PhysicalValueType* EVEnergyRequest;
  Exi_ISO_PhysicalValueType* EVMaximumCurrentLimit;
  Exi_ISO_PhysicalValueType* EVMaximumPowerLimit;
  Exi_ISO_PhysicalValueType* EVMaximumVoltageLimit;
  uint32 DepartureTime;
  sint8 BulkSOC; /* Value range: max: 100 */
  sint8 FullSOC; /* Value range: max: 100 */
  Exi_BitType BulkSOCFlag : 1;
  Exi_BitType DepartureTimeFlag : 1;
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

struct Exi_ISO_AC_EVSEChargeParameterType
{
  Exi_ISO_AC_EVSEStatusType* AC_EVSEStatus;
  Exi_ISO_PhysicalValueType* EVSEMaxCurrent;
  Exi_ISO_PhysicalValueType* EVSENominalVoltage;
};

struct Exi_ISO_DC_EVSEChargeParameterType
{
  Exi_ISO_DC_EVSEStatusType* DC_EVSEStatus;
  Exi_ISO_PhysicalValueType* EVSECurrentRegulationTolerance;
  Exi_ISO_PhysicalValueType* EVSEEnergyToBeDelivered;
  Exi_ISO_PhysicalValueType* EVSEMaximumCurrentLimit;
  Exi_ISO_PhysicalValueType* EVSEMaximumPowerLimit;
  Exi_ISO_PhysicalValueType* EVSEMaximumVoltageLimit;
  Exi_ISO_PhysicalValueType* EVSEMinimumCurrentLimit;
  Exi_ISO_PhysicalValueType* EVSEMinimumVoltageLimit;
  Exi_ISO_PhysicalValueType* EVSEPeakCurrentRipple;
  Exi_BitType EVSECurrentRegulationToleranceFlag : 1;
  Exi_BitType EVSEEnergyToBeDeliveredFlag : 1;
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

struct Exi_ISO_DC_EVPowerDeliveryParameterType
{
  Exi_ISO_DC_EVStatusType* DC_EVStatus;
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
#endif  /* EXI_ENABLE_ISO_MESSAGE_SET */

/* PRQA L:IDENTIFIER_NAMES */
/* PRQA L:NAMESPACE */
/* PRQA L:UNION */


#endif /* EXI_ISO_SCHEMA_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_SchemaTypes.h
 **********************************************************************************************************************/
