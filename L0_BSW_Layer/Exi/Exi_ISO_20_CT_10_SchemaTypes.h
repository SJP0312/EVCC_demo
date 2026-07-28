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
/**        \file  Exi_ISO_20_CT_10_SchemaTypes.h
 *        \brief  Efficient XML Interchange ISO_20_CT_10 types header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_CT_10 types.
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

#if !defined (EXI_ISO_20_CT_10_SCHEMA_TYPES_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_CT_10_SCHEMA_TYPES_H

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
#define EXI_ISO_20_CT_10_CLREQ_CONTROL_MODE_TYPE                                         (Exi_RootElementIdType)113U
#define EXI_ISO_20_CT_10_CLRES_CONTROL_MODE_TYPE                                         (Exi_RootElementIdType)114U

#if (defined(EXI_ENABLE_ISO_20_CT_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_CT_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* Elements */
#define EXI_ISO_20_CT_10_ACK_MAX_DELAY_TYPE                                              (Exi_RootElementIdType)513U
#define EXI_ISO_20_CT_10_ADDITIONAL_SERVICES_COSTS_TYPE                                  (Exi_RootElementIdType)514U
#define EXI_ISO_20_CT_10_AMOUNT_TYPE                                                     (Exi_RootElementIdType)515U
#define EXI_ISO_20_CT_10_BPT_DISCHARGED_ENERGY_READING_WH_TYPE                           (Exi_RootElementIdType)516U
#define EXI_ISO_20_CT_10_BPT_INDUCTIVE_ENERGY_READING_VARH_TYPE                          (Exi_RootElementIdType)517U
#define EXI_ISO_20_CT_10_BATTERY_ENERGY_CAPACITY_TYPE                                    (Exi_RootElementIdType)518U
#define EXI_ISO_20_CT_10_CAPACITIVE_ENERGY_READING_VARH_TYPE                             (Exi_RootElementIdType)519U
#define EXI_ISO_20_CT_10_CHARGED_ENERGY_READING_WH_TYPE                                  (Exi_RootElementIdType)520U
#define EXI_ISO_20_CT_10_CHARGING_COMPLETE_TYPE                                          (Exi_RootElementIdType)521U
#define EXI_ISO_20_CT_10_COST_PER_UNIT_TYPE                                              (Exi_RootElementIdType)522U
#define EXI_ISO_20_CT_10_DEPARTURE_TIME_TYPE                                             (Exi_RootElementIdType)523U
#define EXI_ISO_20_CT_10_DISPLAY_PARAMETERS_TYPE                                         (Exi_RootElementIdType)524U
#define EXI_ISO_20_CT_10_EVMAXIMUM_ENERGY_REQUEST_TYPE                                   (Exi_RootElementIdType)525U
#define EXI_ISO_20_CT_10_EVMINIMUM_ENERGY_REQUEST_TYPE                                   (Exi_RootElementIdType)526U
#define EXI_ISO_20_CT_10_EVSENOTIFICATION_TYPE                                           (Exi_RootElementIdType)527U
#define EXI_ISO_20_CT_10_EVSESTATUS_TYPE                                                 (Exi_RootElementIdType)528U
#define EXI_ISO_20_CT_10_EVTARGET_ENERGY_REQUEST_TYPE                                    (Exi_RootElementIdType)529U
#define EXI_ISO_20_CT_10_ENERGY_COSTS_TYPE                                               (Exi_RootElementIdType)530U
#define EXI_ISO_20_CT_10_EXPONENT_TYPE                                                   (Exi_RootElementIdType)531U
#define EXI_ISO_20_CT_10_HEADER_TYPE                                                     (Exi_RootElementIdType)532U
#define EXI_ISO_20_CT_10_INLET_HOT_TYPE                                                  (Exi_RootElementIdType)533U
#define EXI_ISO_20_CT_10_MAXIMUM_SOC_TYPE                                                (Exi_RootElementIdType)534U
#define EXI_ISO_20_CT_10_METER_ID_TYPE                                                   (Exi_RootElementIdType)535U
#define EXI_ISO_20_CT_10_METER_INFO_TYPE                                                 (Exi_RootElementIdType)536U
#define EXI_ISO_20_CT_10_METER_INFO_REQUESTED_TYPE                                       (Exi_RootElementIdType)537U
#define EXI_ISO_20_CT_10_METER_SIGNATURE_TYPE                                            (Exi_RootElementIdType)538U
#define EXI_ISO_20_CT_10_METER_STATUS_TYPE                                               (Exi_RootElementIdType)539U
#define EXI_ISO_20_CT_10_METER_TIMESTAMP_TYPE                                            (Exi_RootElementIdType)540U
#define EXI_ISO_20_CT_10_MINIMUM_SOC_TYPE                                                (Exi_RootElementIdType)541U
#define EXI_ISO_20_CT_10_NOTIFICATION_MAX_DELAY_TYPE                                     (Exi_RootElementIdType)542U
#define EXI_ISO_20_CT_10_OCCUPANCY_COSTS_TYPE                                            (Exi_RootElementIdType)543U
#define EXI_ISO_20_CT_10_OVERSTAY_COSTS_TYPE                                             (Exi_RootElementIdType)544U
#define EXI_ISO_20_CT_10_PRESENT_SOC_TYPE                                                (Exi_RootElementIdType)545U
#define EXI_ISO_20_CT_10_RECEIPT_TYPE                                                    (Exi_RootElementIdType)546U
#define EXI_ISO_20_CT_10_REMAINING_TIME_TO_MAXIMUM_SOC_TYPE                              (Exi_RootElementIdType)547U
#define EXI_ISO_20_CT_10_REMAINING_TIME_TO_MINIMUM_SOC_TYPE                              (Exi_RootElementIdType)548U
#define EXI_ISO_20_CT_10_REMAINING_TIME_TO_TARGET_SOC_TYPE                               (Exi_RootElementIdType)549U
#define EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE                                              (Exi_RootElementIdType)550U
#define EXI_ISO_20_CT_10_ROOT_CERTIFICATE_ID_TYPE                                        (Exi_RootElementIdType)551U
#define EXI_ISO_20_CT_10_SESSION_ID_TYPE                                                 (Exi_RootElementIdType)552U
#define EXI_ISO_20_CT_10_SIGNATURE_TYPE                                                  (Exi_RootElementIdType)553U
#define EXI_ISO_20_CT_10_TARGET_SOC_TYPE                                                 (Exi_RootElementIdType)554U
#define EXI_ISO_20_CT_10_TAX_COSTS_TYPE                                                  (Exi_RootElementIdType)555U
#define EXI_ISO_20_CT_10_TAX_RULE_ID_TYPE                                                (Exi_RootElementIdType)556U
#define EXI_ISO_20_CT_10_TIME_ANCHOR_TYPE                                                (Exi_RootElementIdType)557U
#define EXI_ISO_20_CT_10_TIME_STAMP_TYPE                                                 (Exi_RootElementIdType)558U
#define EXI_ISO_20_CT_10_VALUE_TYPE                                                      (Exi_RootElementIdType)559U
#define EXI_SCHEMA_SET_ISO_20_CT_10_TYPE                                                 (Exi_RootElementIdType)4U

/**********************************************************************************************************************
 *  ELEMENT IDENTIFIER DEFINES
**********************************************************************************************************************/
#define EXI_ISO_20_CT_10_EI_ATTRIBUTENAME                                      (uint16)0U
#define EXI_ISO_20_CT_10_EI_ATTRIBUTENAME_SE                                   (uint16)1U
#define EXI_ISO_20_CT_10_EI_ATTRIBUTENAME_CT                                   (uint16)2U
#define EXI_ISO_20_CT_10_EI_ATTRIBUTENAME_EE                                   (uint16)3U
#define EXI_ISO_20_CT_10_EI_ATTRIBUTENAME_AT                                   (uint16)4U
#define EXI_ISO_20_CT_10_EI_AMOUNT                                             (uint16)5U
#define EXI_ISO_20_CT_10_EI_AMOUNT_SE                                          (uint16)6U
#define EXI_ISO_20_CT_10_EI_AMOUNT_CT                                          (uint16)7U
#define EXI_ISO_20_CT_10_EI_AMOUNT_EE                                          (uint16)8U
#define EXI_ISO_20_CT_10_EI_AMOUNT_AT                                          (uint16)9U
#define EXI_ISO_20_CT_10_EI_COST_PER_UNIT                                      (uint16)10U
#define EXI_ISO_20_CT_10_EI_COST_PER_UNIT_SE                                   (uint16)11U
#define EXI_ISO_20_CT_10_EI_COST_PER_UNIT_CT                                   (uint16)12U
#define EXI_ISO_20_CT_10_EI_COST_PER_UNIT_EE                                   (uint16)13U
#define EXI_ISO_20_CT_10_EI_COST_PER_UNIT_AT                                   (uint16)14U
#define EXI_ISO_20_CT_10_EI_TAX_RULE_ID                                        (uint16)15U
#define EXI_ISO_20_CT_10_EI_TAX_RULE_ID_SE                                     (uint16)16U
#define EXI_ISO_20_CT_10_EI_TAX_RULE_ID_CT                                     (uint16)17U
#define EXI_ISO_20_CT_10_EI_TAX_RULE_ID_EE                                     (uint16)18U
#define EXI_ISO_20_CT_10_EI_TAX_RULE_ID_AT                                     (uint16)19U
#define EXI_ISO_20_CT_10_EI_PRESENT_SOC                                        (uint16)20U
#define EXI_ISO_20_CT_10_EI_PRESENT_SOC_SE                                     (uint16)21U
#define EXI_ISO_20_CT_10_EI_PRESENT_SOC_CT                                     (uint16)22U
#define EXI_ISO_20_CT_10_EI_PRESENT_SOC_EE                                     (uint16)23U
#define EXI_ISO_20_CT_10_EI_PRESENT_SOC_AT                                     (uint16)24U
#define EXI_ISO_20_CT_10_EI_MINIMUM_SOC                                        (uint16)25U
#define EXI_ISO_20_CT_10_EI_MINIMUM_SOC_SE                                     (uint16)26U
#define EXI_ISO_20_CT_10_EI_MINIMUM_SOC_CT                                     (uint16)27U
#define EXI_ISO_20_CT_10_EI_MINIMUM_SOC_EE                                     (uint16)28U
#define EXI_ISO_20_CT_10_EI_MINIMUM_SOC_AT                                     (uint16)29U
#define EXI_ISO_20_CT_10_EI_TARGET_SOC                                         (uint16)30U
#define EXI_ISO_20_CT_10_EI_TARGET_SOC_SE                                      (uint16)31U
#define EXI_ISO_20_CT_10_EI_TARGET_SOC_CT                                      (uint16)32U
#define EXI_ISO_20_CT_10_EI_TARGET_SOC_EE                                      (uint16)33U
#define EXI_ISO_20_CT_10_EI_TARGET_SOC_AT                                      (uint16)34U
#define EXI_ISO_20_CT_10_EI_MAXIMUM_SOC                                        (uint16)35U
#define EXI_ISO_20_CT_10_EI_MAXIMUM_SOC_SE                                     (uint16)36U
#define EXI_ISO_20_CT_10_EI_MAXIMUM_SOC_CT                                     (uint16)37U
#define EXI_ISO_20_CT_10_EI_MAXIMUM_SOC_EE                                     (uint16)38U
#define EXI_ISO_20_CT_10_EI_MAXIMUM_SOC_AT                                     (uint16)39U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MINIMUM_SOC                      (uint16)40U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MINIMUM_SOC_SE                   (uint16)41U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MINIMUM_SOC_CT                   (uint16)42U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MINIMUM_SOC_EE                   (uint16)43U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MINIMUM_SOC_AT                   (uint16)44U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_TARGET_SOC                       (uint16)45U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_TARGET_SOC_SE                    (uint16)46U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_TARGET_SOC_CT                    (uint16)47U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_TARGET_SOC_EE                    (uint16)48U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_TARGET_SOC_AT                    (uint16)49U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MAXIMUM_SOC                      (uint16)50U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MAXIMUM_SOC_SE                   (uint16)51U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MAXIMUM_SOC_CT                   (uint16)52U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MAXIMUM_SOC_EE                   (uint16)53U
#define EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MAXIMUM_SOC_AT                   (uint16)54U
#define EXI_ISO_20_CT_10_EI_CHARGING_COMPLETE                                  (uint16)55U
#define EXI_ISO_20_CT_10_EI_CHARGING_COMPLETE_SE                               (uint16)56U
#define EXI_ISO_20_CT_10_EI_CHARGING_COMPLETE_CT                               (uint16)57U
#define EXI_ISO_20_CT_10_EI_CHARGING_COMPLETE_EE                               (uint16)58U
#define EXI_ISO_20_CT_10_EI_CHARGING_COMPLETE_AT                               (uint16)59U
#define EXI_ISO_20_CT_10_EI_BATTERY_ENERGY_CAPACITY                            (uint16)60U
#define EXI_ISO_20_CT_10_EI_BATTERY_ENERGY_CAPACITY_SE                         (uint16)61U
#define EXI_ISO_20_CT_10_EI_BATTERY_ENERGY_CAPACITY_CT                         (uint16)62U
#define EXI_ISO_20_CT_10_EI_BATTERY_ENERGY_CAPACITY_EE                         (uint16)63U
#define EXI_ISO_20_CT_10_EI_BATTERY_ENERGY_CAPACITY_AT                         (uint16)64U
#define EXI_ISO_20_CT_10_EI_INLET_HOT                                          (uint16)65U
#define EXI_ISO_20_CT_10_EI_INLET_HOT_SE                                       (uint16)66U
#define EXI_ISO_20_CT_10_EI_INLET_HOT_CT                                       (uint16)67U
#define EXI_ISO_20_CT_10_EI_INLET_HOT_EE                                       (uint16)68U
#define EXI_ISO_20_CT_10_EI_INLET_HOT_AT                                       (uint16)69U
#define EXI_ISO_20_CT_10_EI_NOTIFICATION_MAX_DELAY                             (uint16)70U
#define EXI_ISO_20_CT_10_EI_NOTIFICATION_MAX_DELAY_SE                          (uint16)71U
#define EXI_ISO_20_CT_10_EI_NOTIFICATION_MAX_DELAY_CT                          (uint16)72U
#define EXI_ISO_20_CT_10_EI_NOTIFICATION_MAX_DELAY_EE                          (uint16)73U
#define EXI_ISO_20_CT_10_EI_NOTIFICATION_MAX_DELAY_AT                          (uint16)74U
#define EXI_ISO_20_CT_10_EI_EVSENOTIFICATION                                   (uint16)75U
#define EXI_ISO_20_CT_10_EI_EVSENOTIFICATION_SE                                (uint16)76U
#define EXI_ISO_20_CT_10_EI_EVSENOTIFICATION_CT                                (uint16)77U
#define EXI_ISO_20_CT_10_EI_EVSENOTIFICATION_EE                                (uint16)78U
#define EXI_ISO_20_CT_10_EI_EVSENOTIFICATION_AT                                (uint16)79U
#define EXI_ISO_20_CT_10_EI_ROOT_CERTIFICATE_ID                                (uint16)80U
#define EXI_ISO_20_CT_10_EI_ROOT_CERTIFICATE_ID_SE                             (uint16)81U
#define EXI_ISO_20_CT_10_EI_ROOT_CERTIFICATE_ID_CT                             (uint16)82U
#define EXI_ISO_20_CT_10_EI_ROOT_CERTIFICATE_ID_EE                             (uint16)83U
#define EXI_ISO_20_CT_10_EI_ROOT_CERTIFICATE_ID_AT                             (uint16)84U
#define EXI_ISO_20_CT_10_EI_SESSION_ID                                         (uint16)85U
#define EXI_ISO_20_CT_10_EI_SESSION_ID_SE                                      (uint16)86U
#define EXI_ISO_20_CT_10_EI_SESSION_ID_CT                                      (uint16)87U
#define EXI_ISO_20_CT_10_EI_SESSION_ID_EE                                      (uint16)88U
#define EXI_ISO_20_CT_10_EI_SESSION_ID_AT                                      (uint16)89U
#define EXI_ISO_20_CT_10_EI_TIME_STAMP                                         (uint16)90U
#define EXI_ISO_20_CT_10_EI_TIME_STAMP_SE                                      (uint16)91U
#define EXI_ISO_20_CT_10_EI_TIME_STAMP_CT                                      (uint16)92U
#define EXI_ISO_20_CT_10_EI_TIME_STAMP_EE                                      (uint16)93U
#define EXI_ISO_20_CT_10_EI_TIME_STAMP_AT                                      (uint16)94U
#define EXI_ISO_20_CT_10_EI_SIGNATURE                                          (uint16)95U
#define EXI_ISO_20_CT_10_EI_SIGNATURE_SE                                       (uint16)96U
#define EXI_ISO_20_CT_10_EI_SIGNATURE_CT                                       (uint16)97U
#define EXI_ISO_20_CT_10_EI_SIGNATURE_EE                                       (uint16)98U
#define EXI_ISO_20_CT_10_EI_SIGNATURE_AT                                       (uint16)99U
#define EXI_ISO_20_CT_10_EI_METER_ID                                           (uint16)100U
#define EXI_ISO_20_CT_10_EI_METER_ID_SE                                        (uint16)101U
#define EXI_ISO_20_CT_10_EI_METER_ID_CT                                        (uint16)102U
#define EXI_ISO_20_CT_10_EI_METER_ID_EE                                        (uint16)103U
#define EXI_ISO_20_CT_10_EI_METER_ID_AT                                        (uint16)104U
#define EXI_ISO_20_CT_10_EI_CHARGED_ENERGY_READING_WH                          (uint16)105U
#define EXI_ISO_20_CT_10_EI_CHARGED_ENERGY_READING_WH_SE                       (uint16)106U
#define EXI_ISO_20_CT_10_EI_CHARGED_ENERGY_READING_WH_CT                       (uint16)107U
#define EXI_ISO_20_CT_10_EI_CHARGED_ENERGY_READING_WH_EE                       (uint16)108U
#define EXI_ISO_20_CT_10_EI_CHARGED_ENERGY_READING_WH_AT                       (uint16)109U
#define EXI_ISO_20_CT_10_EI_BPT_DISCHARGED_ENERGY_READING_WH                   (uint16)110U
#define EXI_ISO_20_CT_10_EI_BPT_DISCHARGED_ENERGY_READING_WH_SE                (uint16)111U
#define EXI_ISO_20_CT_10_EI_BPT_DISCHARGED_ENERGY_READING_WH_CT                (uint16)112U
#define EXI_ISO_20_CT_10_EI_BPT_DISCHARGED_ENERGY_READING_WH_EE                (uint16)113U
#define EXI_ISO_20_CT_10_EI_BPT_DISCHARGED_ENERGY_READING_WH_AT                (uint16)114U
#define EXI_ISO_20_CT_10_EI_CAPACITIVE_ENERGY_READING_VARH                     (uint16)115U
#define EXI_ISO_20_CT_10_EI_CAPACITIVE_ENERGY_READING_VARH_SE                  (uint16)116U
#define EXI_ISO_20_CT_10_EI_CAPACITIVE_ENERGY_READING_VARH_CT                  (uint16)117U
#define EXI_ISO_20_CT_10_EI_CAPACITIVE_ENERGY_READING_VARH_EE                  (uint16)118U
#define EXI_ISO_20_CT_10_EI_CAPACITIVE_ENERGY_READING_VARH_AT                  (uint16)119U
#define EXI_ISO_20_CT_10_EI_BPT_INDUCTIVE_ENERGY_READING_VARH                  (uint16)120U
#define EXI_ISO_20_CT_10_EI_BPT_INDUCTIVE_ENERGY_READING_VARH_SE               (uint16)121U
#define EXI_ISO_20_CT_10_EI_BPT_INDUCTIVE_ENERGY_READING_VARH_CT               (uint16)122U
#define EXI_ISO_20_CT_10_EI_BPT_INDUCTIVE_ENERGY_READING_VARH_EE               (uint16)123U
#define EXI_ISO_20_CT_10_EI_BPT_INDUCTIVE_ENERGY_READING_VARH_AT               (uint16)124U
#define EXI_ISO_20_CT_10_EI_METER_SIGNATURE                                    (uint16)125U
#define EXI_ISO_20_CT_10_EI_METER_SIGNATURE_SE                                 (uint16)126U
#define EXI_ISO_20_CT_10_EI_METER_SIGNATURE_CT                                 (uint16)127U
#define EXI_ISO_20_CT_10_EI_METER_SIGNATURE_EE                                 (uint16)128U
#define EXI_ISO_20_CT_10_EI_METER_SIGNATURE_AT                                 (uint16)129U
#define EXI_ISO_20_CT_10_EI_METER_STATUS                                       (uint16)130U
#define EXI_ISO_20_CT_10_EI_METER_STATUS_SE                                    (uint16)131U
#define EXI_ISO_20_CT_10_EI_METER_STATUS_CT                                    (uint16)132U
#define EXI_ISO_20_CT_10_EI_METER_STATUS_EE                                    (uint16)133U
#define EXI_ISO_20_CT_10_EI_METER_STATUS_AT                                    (uint16)134U
#define EXI_ISO_20_CT_10_EI_METER_TIMESTAMP                                    (uint16)135U
#define EXI_ISO_20_CT_10_EI_METER_TIMESTAMP_SE                                 (uint16)136U
#define EXI_ISO_20_CT_10_EI_METER_TIMESTAMP_CT                                 (uint16)137U
#define EXI_ISO_20_CT_10_EI_METER_TIMESTAMP_EE                                 (uint16)138U
#define EXI_ISO_20_CT_10_EI_METER_TIMESTAMP_AT                                 (uint16)139U
#define EXI_ISO_20_CT_10_EI_EXPONENT                                           (uint16)140U
#define EXI_ISO_20_CT_10_EI_EXPONENT_SE                                        (uint16)141U
#define EXI_ISO_20_CT_10_EI_EXPONENT_CT                                        (uint16)142U
#define EXI_ISO_20_CT_10_EI_EXPONENT_EE                                        (uint16)143U
#define EXI_ISO_20_CT_10_EI_EXPONENT_AT                                        (uint16)144U
#define EXI_ISO_20_CT_10_EI_VALUE                                              (uint16)145U
#define EXI_ISO_20_CT_10_EI_VALUE_SE                                           (uint16)146U
#define EXI_ISO_20_CT_10_EI_VALUE_CT                                           (uint16)147U
#define EXI_ISO_20_CT_10_EI_VALUE_EE                                           (uint16)148U
#define EXI_ISO_20_CT_10_EI_VALUE_AT                                           (uint16)149U
#define EXI_ISO_20_CT_10_EI_TIME_ANCHOR                                        (uint16)150U
#define EXI_ISO_20_CT_10_EI_TIME_ANCHOR_SE                                     (uint16)151U
#define EXI_ISO_20_CT_10_EI_TIME_ANCHOR_CT                                     (uint16)152U
#define EXI_ISO_20_CT_10_EI_TIME_ANCHOR_EE                                     (uint16)153U
#define EXI_ISO_20_CT_10_EI_TIME_ANCHOR_AT                                     (uint16)154U
#define EXI_ISO_20_CT_10_EI_ENERGY_COSTS                                       (uint16)155U
#define EXI_ISO_20_CT_10_EI_ENERGY_COSTS_SE                                    (uint16)156U
#define EXI_ISO_20_CT_10_EI_ENERGY_COSTS_CT                                    (uint16)157U
#define EXI_ISO_20_CT_10_EI_ENERGY_COSTS_EE                                    (uint16)158U
#define EXI_ISO_20_CT_10_EI_ENERGY_COSTS_AT                                    (uint16)159U
#define EXI_ISO_20_CT_10_EI_OCCUPANCY_COSTS                                    (uint16)160U
#define EXI_ISO_20_CT_10_EI_OCCUPANCY_COSTS_SE                                 (uint16)161U
#define EXI_ISO_20_CT_10_EI_OCCUPANCY_COSTS_CT                                 (uint16)162U
#define EXI_ISO_20_CT_10_EI_OCCUPANCY_COSTS_EE                                 (uint16)163U
#define EXI_ISO_20_CT_10_EI_OCCUPANCY_COSTS_AT                                 (uint16)164U
#define EXI_ISO_20_CT_10_EI_ADDITIONAL_SERVICES_COSTS                          (uint16)165U
#define EXI_ISO_20_CT_10_EI_ADDITIONAL_SERVICES_COSTS_SE                       (uint16)166U
#define EXI_ISO_20_CT_10_EI_ADDITIONAL_SERVICES_COSTS_CT                       (uint16)167U
#define EXI_ISO_20_CT_10_EI_ADDITIONAL_SERVICES_COSTS_EE                       (uint16)168U
#define EXI_ISO_20_CT_10_EI_ADDITIONAL_SERVICES_COSTS_AT                       (uint16)169U
#define EXI_ISO_20_CT_10_EI_OVERSTAY_COSTS                                     (uint16)170U
#define EXI_ISO_20_CT_10_EI_OVERSTAY_COSTS_SE                                  (uint16)171U
#define EXI_ISO_20_CT_10_EI_OVERSTAY_COSTS_CT                                  (uint16)172U
#define EXI_ISO_20_CT_10_EI_OVERSTAY_COSTS_EE                                  (uint16)173U
#define EXI_ISO_20_CT_10_EI_OVERSTAY_COSTS_AT                                  (uint16)174U
#define EXI_ISO_20_CT_10_EI_TAX_COSTS                                          (uint16)175U
#define EXI_ISO_20_CT_10_EI_TAX_COSTS_SE                                       (uint16)176U
#define EXI_ISO_20_CT_10_EI_TAX_COSTS_CT                                       (uint16)177U
#define EXI_ISO_20_CT_10_EI_TAX_COSTS_EE                                       (uint16)178U
#define EXI_ISO_20_CT_10_EI_TAX_COSTS_AT                                       (uint16)179U
#define EXI_ISO_20_CT_10_EI_DESCRIPTION                                        (uint16)180U
#define EXI_ISO_20_CT_10_EI_DESCRIPTION_SE                                     (uint16)181U
#define EXI_ISO_20_CT_10_EI_DESCRIPTION_CT                                     (uint16)182U
#define EXI_ISO_20_CT_10_EI_DESCRIPTION_EE                                     (uint16)183U
#define EXI_ISO_20_CT_10_EI_DESCRIPTION_AT                                     (uint16)184U
#define EXI_ISO_20_CT_10_EI_EVSE_NOTIFICATION                                  (uint16)185U
#define EXI_ISO_20_CT_10_EI_EVSE_NOTIFICATION_SE                               (uint16)186U
#define EXI_ISO_20_CT_10_EI_EVSE_NOTIFICATION_CT                               (uint16)187U
#define EXI_ISO_20_CT_10_EI_EVSE_NOTIFICATION_EE                               (uint16)188U
#define EXI_ISO_20_CT_10_EI_EVSE_NOTIFICATION_AT                               (uint16)189U
#define EXI_ISO_20_CT_10_EI_IDENTIFIER                                         (uint16)190U
#define EXI_ISO_20_CT_10_EI_IDENTIFIER_SE                                      (uint16)191U
#define EXI_ISO_20_CT_10_EI_IDENTIFIER_CT                                      (uint16)192U
#define EXI_ISO_20_CT_10_EI_IDENTIFIER_EE                                      (uint16)193U
#define EXI_ISO_20_CT_10_EI_IDENTIFIER_AT                                      (uint16)194U
#define EXI_ISO_20_CT_10_EI_NAME                                               (uint16)195U
#define EXI_ISO_20_CT_10_EI_NAME_SE                                            (uint16)196U
#define EXI_ISO_20_CT_10_EI_NAME_CT                                            (uint16)197U
#define EXI_ISO_20_CT_10_EI_NAME_EE                                            (uint16)198U
#define EXI_ISO_20_CT_10_EI_NAME_AT                                            (uint16)199U
#define EXI_ISO_20_CT_10_EI_PROCESSING                                         (uint16)200U
#define EXI_ISO_20_CT_10_EI_PROCESSING_SE                                      (uint16)201U
#define EXI_ISO_20_CT_10_EI_PROCESSING_CT                                      (uint16)202U
#define EXI_ISO_20_CT_10_EI_PROCESSING_EE                                      (uint16)203U
#define EXI_ISO_20_CT_10_EI_PROCESSING_AT                                      (uint16)204U
#define EXI_ISO_20_CT_10_EI_RESPONSE_CODE                                      (uint16)205U
#define EXI_ISO_20_CT_10_EI_RESPONSE_CODE_SE                                   (uint16)206U
#define EXI_ISO_20_CT_10_EI_RESPONSE_CODE_CT                                   (uint16)207U
#define EXI_ISO_20_CT_10_EI_RESPONSE_CODE_EE                                   (uint16)208U
#define EXI_ISO_20_CT_10_EI_RESPONSE_CODE_AT                                   (uint16)209U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_PAUSE = 0u,
  EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_EXIT_STANDBY = 1u,
  EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_TERMINATE = 2u,
  EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_SCHEDULE_RENEGOTIATION = 3u,
  EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_SERVICE_RENEGOTIATION = 4u,
  EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_METERING_CONFIRMATION = 5u
} Exi_ISO_20_CT_10_evseNotificationType;

typedef enum
{
  EXI_ISO_20_CT_10_PROCESSING_TYPE_FINISHED = 0u,
  EXI_ISO_20_CT_10_PROCESSING_TYPE_ONGOING = 1u,
  EXI_ISO_20_CT_10_PROCESSING_TYPE_ONGOING_WAITING_FOR_CUSTOMER_INTERACTION = 2u
} Exi_ISO_20_CT_10_processingType;

typedef enum
{
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK = 0u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK_CERTIFICATE_EXPIRES_SOON = 1u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK_NEW_SESSION_ESTABLISHED = 2u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK_OLD_SESSION_JOINED = 3u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK_POWER_TOLERANCE_CONFIRMED = 4u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_AUTHORIZATION_SELECTION_INVALID = 5u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_EXPIRED = 6u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_NOT_YET_VALID = 7u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_REVOKED = 8u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_VALIDATION_ERROR = 9u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CHALLENGE_INVALID = 10u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_EIMAUTHORIZATION_FAILURE = 11u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_E_MSPUNKNOWN = 12u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_EVPOWER_PROFILE_VIOLATION = 13u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_GENERAL_PN_CAUTHORIZATION_ERROR = 14u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_NO_CERTIFICATE_AVAILABLE = 15u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_NO_CONTRACT_MATCHING_PCIDFOUND = 16u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_POWER_TOLERANCE_NOT_CONFIRMED = 17u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_SCHEDULE_RENEGOTIATION_FAILED = 18u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_STANDBY_NOT_ALLOWED = 19u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_WPT = 20u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED = 21u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_ASSOCIATION_ERROR = 22u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_CONTACTOR_ERROR = 23u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_EVPOWER_PROFILE_INVALID = 24u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_EVPOWER_PROFILE_VIOLATION = 25u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_METERING_SIGNATURE_NOT_VALID = 26u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_NO_ENERGY_TRANSFER_SERVICE_SELECTED = 27u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_NO_SERVICE_RENEGOTIATION_SUPPORTED = 28u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_PAUSE_NOT_ALLOWED = 29u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_POWER_DELIVERY_NOT_APPLIED = 30u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_POWER_TOLERANCE_NOT_CONFIRMED = 31u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_SCHEDULE_RENEGOTIATION = 32u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_SCHEDULE_SELECTION_INVALID = 33u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_SEQUENCE_ERROR = 34u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_SERVICE_IDINVALID = 35u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_SERVICE_SELECTION_INVALID = 36u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_SIGNATURE_ERROR = 37u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_UNKNOWN_SESSION = 38u,
  EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_WRONG_CHARGE_PARAMETER = 39u
} Exi_ISO_20_CT_10_responseCodeType;

typedef struct Exi_ISO_20_CT_10_sessionIDType Exi_ISO_20_CT_10_sessionIDType;
struct Exi_ISO_20_CT_10_sessionIDType
{
  uint16 Length;
  uint8 Buffer[8];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_20_CT_10_identifierType Exi_ISO_20_CT_10_identifierType;
struct Exi_ISO_20_CT_10_identifierType
{
  struct Exi_ISO_20_CT_10_identifierType* NextEMAIDPtr;
  uint16 Length;
  uint8 Buffer[255];
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

typedef struct Exi_ISO_20_CT_10_nameType Exi_ISO_20_CT_10_nameType;
struct Exi_ISO_20_CT_10_nameType
{
  struct Exi_ISO_20_CT_10_nameType* NextProviderIDPtr;
  uint16 Length;
  uint8 Buffer[80];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_20_CT_10_descriptionType Exi_ISO_20_CT_10_descriptionType;
struct Exi_ISO_20_CT_10_descriptionType
{
  uint16 Length;
  uint8 Buffer[160];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_20_CT_10_meterIDType Exi_ISO_20_CT_10_meterIDType;
struct Exi_ISO_20_CT_10_meterIDType
{
  uint16 Length;
  uint8 Buffer[32];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_20_CT_10_meterSignatureType Exi_ISO_20_CT_10_meterSignatureType;
struct Exi_ISO_20_CT_10_meterSignatureType
{
  uint16 Length;
  uint8 Buffer[64];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_20_CT_10_AttributenameType Exi_ISO_20_CT_10_AttributenameType;
struct Exi_ISO_20_CT_10_AttributenameType
{
  struct Exi_ISO_20_CT_10_nameType* NextProviderIDPtr;
  uint16 Length;
  uint8 Buffer[80];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef void Exi_ISO_20_CT_10_CLReqControlModeType;

typedef void Exi_ISO_20_CT_10_CLResControlModeType;

typedef struct Exi_ISO_20_CT_10_MessageHeaderType Exi_ISO_20_CT_10_MessageHeaderType;

typedef struct Exi_ISO_20_CT_10_V2GMessageType Exi_ISO_20_CT_10_V2GMessageType;

typedef struct Exi_ISO_20_CT_10_V2GRequestType Exi_ISO_20_CT_10_V2GRequestType;

typedef struct Exi_ISO_20_CT_10_V2GResponseType Exi_ISO_20_CT_10_V2GResponseType;

typedef struct Exi_ISO_20_CT_10_ChargeParameterDiscoveryReqType Exi_ISO_20_CT_10_ChargeParameterDiscoveryReqType;

typedef struct Exi_ISO_20_CT_10_ChargeParameterDiscoveryResType Exi_ISO_20_CT_10_ChargeParameterDiscoveryResType;

typedef struct Exi_ISO_20_CT_10_RationalNumberType Exi_ISO_20_CT_10_RationalNumberType;

typedef struct Exi_ISO_20_CT_10_DisplayParametersType Exi_ISO_20_CT_10_DisplayParametersType;

typedef struct Exi_ISO_20_CT_10_ChargeLoopReqType Exi_ISO_20_CT_10_ChargeLoopReqType;

typedef struct Exi_ISO_20_CT_10_EVSEStatusType Exi_ISO_20_CT_10_EVSEStatusType;

typedef struct Exi_ISO_20_CT_10_MeterInfoType Exi_ISO_20_CT_10_MeterInfoType;

typedef struct Exi_ISO_20_CT_10_DetailedCostType Exi_ISO_20_CT_10_DetailedCostType;

typedef struct Exi_ISO_20_CT_10_DetailedTaxType Exi_ISO_20_CT_10_DetailedTaxType;

typedef struct Exi_ISO_20_CT_10_ReceiptType Exi_ISO_20_CT_10_ReceiptType;

typedef struct Exi_ISO_20_CT_10_ChargeLoopResType Exi_ISO_20_CT_10_ChargeLoopResType;

typedef struct Exi_ISO_20_CT_10_Scheduled_CLReqControlModeType Exi_ISO_20_CT_10_Scheduled_CLReqControlModeType;

typedef void Exi_ISO_20_CT_10_Scheduled_CLResControlModeType;

typedef struct Exi_ISO_20_CT_10_Dynamic_CLReqControlModeType Exi_ISO_20_CT_10_Dynamic_CLReqControlModeType;

typedef struct Exi_ISO_20_CT_10_Dynamic_CLResControlModeType Exi_ISO_20_CT_10_Dynamic_CLResControlModeType;

typedef struct Exi_ISO_20_CT_10_ListOfRootCertificateIDsType Exi_ISO_20_CT_10_ListOfRootCertificateIDsType;

struct Exi_ISO_20_CT_10_MessageHeaderType
{
  Exi_ISO_20_CT_10_sessionIDType* SessionID;
#if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_XMLSIG_SignatureType* Signature;
#endif
  Exi_UInt64 TimeStamp;
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

struct Exi_ISO_20_CT_10_V2GMessageType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
};

struct Exi_ISO_20_CT_10_V2GRequestType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
};

struct Exi_ISO_20_CT_10_V2GResponseType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
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

struct Exi_ISO_20_CT_10_ChargeParameterDiscoveryReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
};

struct Exi_ISO_20_CT_10_ChargeParameterDiscoveryResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
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

struct Exi_ISO_20_CT_10_RationalNumberType
{
  sint16 Value;
  sint8 Exponent;
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

struct Exi_ISO_20_CT_10_DisplayParametersType
{
  Exi_ISO_20_CT_10_RationalNumberType* BatteryEnergyCapacity;
  uint32 RemainingTimeToMaximumSOC;
  uint32 RemainingTimeToMinimumSOC;
  uint32 RemainingTimeToTargetSOC;
  boolean ChargingComplete;
  boolean InletHot;
  sint8 MaximumSOC; /* Value range: max: 100 */
  sint8 MinimumSOC; /* Value range: max: 100 */
  sint8 PresentSOC; /* Value range: max: 100 */
  sint8 TargetSOC; /* Value range: max: 100 */
  Exi_BitType BatteryEnergyCapacityFlag : 1;
  Exi_BitType ChargingCompleteFlag : 1;
  Exi_BitType InletHotFlag : 1;
  Exi_BitType MaximumSOCFlag : 1;
  Exi_BitType MinimumSOCFlag : 1;
  Exi_BitType PresentSOCFlag : 1;
  Exi_BitType RemainingTimeToMaximumSOCFlag : 1;
  Exi_BitType RemainingTimeToMinimumSOCFlag : 1;
  Exi_BitType RemainingTimeToTargetSOCFlag : 1;
  Exi_BitType TargetSOCFlag : 1;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_CT_10_ChargeLoopReqType
{
  Exi_ISO_20_CT_10_DisplayParametersType* DisplayParameters;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  boolean MeterInfoRequested;
  Exi_BitType DisplayParametersFlag : 1;
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

struct Exi_ISO_20_CT_10_EVSEStatusType
{
  uint16 NotificationMaxDelay;
  Exi_ISO_20_CT_10_evseNotificationType EVSENotification; /* Value range: 0 to 5; See type for exact values. */
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

struct Exi_ISO_20_CT_10_MeterInfoType
{
  Exi_ISO_20_CT_10_meterIDType* MeterID;
  Exi_ISO_20_CT_10_meterSignatureType* MeterSignature;
  Exi_UInt64 BPT_DischargedEnergyReadingWh;
  Exi_UInt64 BPT_InductiveEnergyReadingVARh;
  Exi_UInt64 CapacitiveEnergyReadingVARh;
  Exi_UInt64 ChargedEnergyReadingWh;
  Exi_UInt64 MeterTimestamp;
  sint16 MeterStatus;
  Exi_BitType BPT_DischargedEnergyReadingWhFlag : 1;
  Exi_BitType BPT_InductiveEnergyReadingVARhFlag : 1;
  Exi_BitType CapacitiveEnergyReadingVARhFlag : 1;
  Exi_BitType MeterSignatureFlag : 1;
  Exi_BitType MeterStatusFlag : 1;
  Exi_BitType MeterTimestampFlag : 1;
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

struct Exi_ISO_20_CT_10_DetailedCostType
{
  Exi_ISO_20_CT_10_RationalNumberType* Amount;
  Exi_ISO_20_CT_10_RationalNumberType* CostPerUnit;
};

struct Exi_ISO_20_CT_10_DetailedTaxType
{
  Exi_ISO_20_CT_10_RationalNumberType* Amount;
  struct Exi_ISO_20_CT_10_DetailedTaxType* NextTaxCostsPtr;
  uint32 TaxRuleID; /* Value range: min: 1 max: 4294967295 */
};

struct Exi_ISO_20_CT_10_ReceiptType
{
  Exi_ISO_20_CT_10_DetailedCostType* AdditionalServicesCosts;
  Exi_ISO_20_CT_10_DetailedCostType* EnergyCosts;
  Exi_ISO_20_CT_10_DetailedCostType* OccupancyCosts;
  Exi_ISO_20_CT_10_DetailedCostType* OverstayCosts;
  Exi_ISO_20_CT_10_DetailedTaxType* TaxCosts;
  Exi_UInt64 TimeAnchor;
  Exi_BitType AdditionalServicesCostsFlag : 1;
  Exi_BitType EnergyCostsFlag : 1;
  Exi_BitType OccupancyCostsFlag : 1;
  Exi_BitType OverstayCostsFlag : 1;
  Exi_BitType TaxCostsFlag : 1;
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

struct Exi_ISO_20_CT_10_ChargeLoopResType
{
  Exi_ISO_20_CT_10_EVSEStatusType* EVSEStatus;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_MeterInfoType* MeterInfo;
  Exi_ISO_20_CT_10_ReceiptType* Receipt;
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  Exi_BitType EVSEStatusFlag : 1;
  Exi_BitType MeterInfoFlag : 1;
  Exi_BitType ReceiptFlag : 1;
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

struct Exi_ISO_20_CT_10_Scheduled_CLReqControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVTargetEnergyRequest;
  Exi_BitType EVMaximumEnergyRequestFlag : 1;
  Exi_BitType EVMinimumEnergyRequestFlag : 1;
  Exi_BitType EVTargetEnergyRequestFlag : 1;
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

struct Exi_ISO_20_CT_10_Dynamic_CLReqControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVTargetEnergyRequest;
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

struct Exi_ISO_20_CT_10_Dynamic_CLResControlModeType
{
  uint32 DepartureTime;
  uint16 AckMaxDelay;
  sint8 MinimumSOC; /* Value range: max: 100 */
  sint8 TargetSOC; /* Value range: max: 100 */
  Exi_BitType AckMaxDelayFlag : 1;
  Exi_BitType DepartureTimeFlag : 1;
  Exi_BitType MinimumSOCFlag : 1;
  Exi_BitType TargetSOCFlag : 1;
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

struct Exi_ISO_20_CT_10_ListOfRootCertificateIDsType
{
#if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_XMLSIG_X509IssuerSerialType* RootCertificateID;
#else
  uint32 dummy;
#endif
};
#endif  /* EXI_ENABLE_ISO_20_CT_10_MESSAGE_SET */

/* PRQA L:IDENTIFIER_NAMES */
/* PRQA L:NAMESPACE */
/* PRQA L:UNION */


#endif /* EXI_ISO_20_CT_10_SCHEMA_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_CT_10_SchemaTypes.h
 **********************************************************************************************************************/
