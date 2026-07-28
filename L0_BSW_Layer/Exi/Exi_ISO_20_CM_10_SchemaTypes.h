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
/**        \file  Exi_ISO_20_CM_10_SchemaTypes.h
 *        \brief  Efficient XML Interchange ISO_20_CM_10 types header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_CM_10 types.
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

#if !defined (EXI_ISO_20_CM_10_SCHEMA_TYPES_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_CM_10_SCHEMA_TYPES_H

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
#define EXI_ISO_20_CM_10_AUTHORIZATION_REQ_TYPE                                          (Exi_RootElementIdType)115U
#define EXI_ISO_20_CM_10_AUTHORIZATION_RES_TYPE                                          (Exi_RootElementIdType)116U
#define EXI_ISO_20_CM_10_AUTHORIZATION_SETUP_REQ_TYPE                                    (Exi_RootElementIdType)117U
#define EXI_ISO_20_CM_10_AUTHORIZATION_SETUP_RES_TYPE                                    (Exi_RootElementIdType)118U
#define EXI_ISO_20_CM_10_CERTIFICATE_INSTALLATION_REQ_TYPE                               (Exi_RootElementIdType)119U
#define EXI_ISO_20_CM_10_CERTIFICATE_INSTALLATION_RES_TYPE                               (Exi_RootElementIdType)120U
#define EXI_ISO_20_CM_10_METERING_CONFIRMATION_REQ_TYPE                                  (Exi_RootElementIdType)121U
#define EXI_ISO_20_CM_10_METERING_CONFIRMATION_RES_TYPE                                  (Exi_RootElementIdType)122U
#define EXI_ISO_20_CM_10_POWER_DELIVERY_REQ_TYPE                                         (Exi_RootElementIdType)123U
#define EXI_ISO_20_CM_10_POWER_DELIVERY_RES_TYPE                                         (Exi_RootElementIdType)124U
#define EXI_ISO_20_CM_10_SCHEDULE_EXCHANGE_REQ_TYPE                                      (Exi_RootElementIdType)125U
#define EXI_ISO_20_CM_10_SCHEDULE_EXCHANGE_RES_TYPE                                      (Exi_RootElementIdType)126U
#define EXI_ISO_20_CM_10_SERVICE_DETAIL_REQ_TYPE                                         (Exi_RootElementIdType)127U
#define EXI_ISO_20_CM_10_SERVICE_DETAIL_RES_TYPE                                         (Exi_RootElementIdType)128U
#define EXI_ISO_20_CM_10_SERVICE_DISCOVERY_REQ_TYPE                                      (Exi_RootElementIdType)129U
#define EXI_ISO_20_CM_10_SERVICE_DISCOVERY_RES_TYPE                                      (Exi_RootElementIdType)130U
#define EXI_ISO_20_CM_10_SERVICE_SELECTION_REQ_TYPE                                      (Exi_RootElementIdType)131U
#define EXI_ISO_20_CM_10_SERVICE_SELECTION_RES_TYPE                                      (Exi_RootElementIdType)132U
#define EXI_ISO_20_CM_10_SESSION_SETUP_REQ_TYPE                                          (Exi_RootElementIdType)133U
#define EXI_ISO_20_CM_10_SESSION_SETUP_RES_TYPE                                          (Exi_RootElementIdType)134U
#define EXI_ISO_20_CM_10_SESSION_STOP_REQ_TYPE                                           (Exi_RootElementIdType)135U
#define EXI_ISO_20_CM_10_SESSION_STOP_RES_TYPE                                           (Exi_RootElementIdType)136U
#define EXI_ISO_20_CM_10_SIGNED_INSTALLATION_DATA_TYPE                                   (Exi_RootElementIdType)137U
#define EXI_ISO_20_CM_10_SIGNED_METERING_DATA_TYPE                                       (Exi_RootElementIdType)138U
#define EXI_ISO_20_CM_10_VEHICLE_CHECK_IN_REQ_TYPE                                       (Exi_RootElementIdType)139U
#define EXI_ISO_20_CM_10_VEHICLE_CHECK_IN_RES_TYPE                                       (Exi_RootElementIdType)140U
#define EXI_ISO_20_CM_10_VEHICLE_CHECK_OUT_REQ_TYPE                                      (Exi_RootElementIdType)141U
#define EXI_ISO_20_CM_10_VEHICLE_CHECK_OUT_RES_TYPE                                      (Exi_RootElementIdType)142U

#if (defined(EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* Elements */
#define EXI_ISO_20_CM_10_ABSOLUTE_PRICE_SCHEDULE_TYPE                                    (Exi_RootElementIdType)560U
#define EXI_ISO_20_CM_10_ADDITIONAL_SELECTED_SERVICES_TYPE                               (Exi_RootElementIdType)561U
#define EXI_ISO_20_CM_10_ADDITIONAL_SERVICE_TYPE                                         (Exi_RootElementIdType)562U
#define EXI_ISO_20_CM_10_APPLIES_MINIMUM_MAXIMUM_COST_TYPE                               (Exi_RootElementIdType)563U
#define EXI_ISO_20_CM_10_APPLIES_TO_ENERGY_FEE_TYPE                                      (Exi_RootElementIdType)564U
#define EXI_ISO_20_CM_10_APPLIES_TO_OVERSTAY_FEE_TYPE                                    (Exi_RootElementIdType)565U
#define EXI_ISO_20_CM_10_APPLIES_TO_PARKING_FEE_TYPE                                     (Exi_RootElementIdType)566U
#define EXI_ISO_20_CM_10_AUTHORIZATION_SERVICES_TYPE                                     (Exi_RootElementIdType)567U
#define EXI_ISO_20_CM_10_AVAILABLE_ENERGY_TYPE                                           (Exi_RootElementIdType)568U
#define EXI_ISO_20_CM_10_BPT_CHANNEL_SELECTION_TYPE                                      (Exi_RootElementIdType)569U
#define EXI_ISO_20_CM_10_CPSCERTIFICATE_CHAIN_TYPE                                       (Exi_RootElementIdType)570U
#define EXI_ISO_20_CM_10_CARBON_DIOXIDE_EMISSION_TYPE                                    (Exi_RootElementIdType)571U
#define EXI_ISO_20_CM_10_CERTIFICATE_TYPE                                                (Exi_RootElementIdType)572U
#define EXI_ISO_20_CM_10_CERTIFICATE_INSTALLATION_SERVICE_TYPE                           (Exi_RootElementIdType)573U
#define EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE                                            (Exi_RootElementIdType)574U
#define EXI_ISO_20_CM_10_CHARGING_SCHEDULE_TYPE                                          (Exi_RootElementIdType)575U
#define EXI_ISO_20_CM_10_CHARGING_SESSION_TYPE                                           (Exi_RootElementIdType)576U
#define EXI_ISO_20_CM_10_CHECK_OUT_TIME_TYPE                                             (Exi_RootElementIdType)577U
#define EXI_ISO_20_CM_10_CONTRACT_CERTIFICATE_CHAIN_TYPE                                 (Exi_RootElementIdType)578U
#define EXI_ISO_20_CM_10_CURRENCY_TYPE                                                   (Exi_RootElementIdType)579U
#define EXI_ISO_20_CM_10_DHPUBLIC_KEY_TYPE                                               (Exi_RootElementIdType)580U
#define EXI_ISO_20_CM_10_DEPARTURE_TIME_TYPE                                             (Exi_RootElementIdType)581U
#define EXI_ISO_20_CM_10_DEVICE_LOCATION_TYPE                                            (Exi_RootElementIdType)582U
#define EXI_ISO_20_CM_10_DEVICE_OFFSET_TYPE                                              (Exi_RootElementIdType)583U
#define EXI_ISO_20_CM_10_DISCHARGING_SCHEDULE_TYPE                                       (Exi_RootElementIdType)584U
#define EXI_ISO_20_CM_10_DURATION_TYPE                                                   (Exi_RootElementIdType)585U
#define EXI_ISO_20_CM_10_DYNAMIC_EVPPTCONTROL_MODE_TYPE                                  (Exi_RootElementIdType)586U
#define EXI_ISO_20_CM_10_DYNAMIC_SEREQ_CONTROL_MODE_TYPE                                 (Exi_RootElementIdType)587U
#define EXI_ISO_20_CM_10_DYNAMIC_SERES_CONTROL_MODE_TYPE                                 (Exi_RootElementIdType)588U
#define EXI_ISO_20_CM_10_DYNAMIC_SMDTCONTROL_MODE_TYPE                                   (Exi_RootElementIdType)589U
#define EXI_ISO_20_CM_10_ECDHCURVE_TYPE                                                  (Exi_RootElementIdType)590U
#define EXI_ISO_20_CM_10_EIM_AREQ_AUTHORIZATION_MODE_TYPE                                (Exi_RootElementIdType)591U
#define EXI_ISO_20_CM_10_EIM_ASRES_AUTHORIZATION_MODE_TYPE                               (Exi_RootElementIdType)592U
#define EXI_ISO_20_CM_10_EMAID_TYPE                                                      (Exi_RootElementIdType)593U
#define EXI_ISO_20_CM_10_EVABSOLUTE_PRICE_SCHEDULE_TYPE                                  (Exi_RootElementIdType)594U
#define EXI_ISO_20_CM_10_EVCCID_TYPE                                                     (Exi_RootElementIdType)595U
#define EXI_ISO_20_CM_10_EVCHECK_IN_STATUS_TYPE                                          (Exi_RootElementIdType)596U
#define EXI_ISO_20_CM_10_EVCHECK_OUT_STATUS_TYPE                                         (Exi_RootElementIdType)597U
#define EXI_ISO_20_CM_10_EVENERGY_OFFER_TYPE                                             (Exi_RootElementIdType)598U
#define EXI_ISO_20_CM_10_EVMAXIMUM_ENERGY_REQUEST_TYPE                                   (Exi_RootElementIdType)599U
#define EXI_ISO_20_CM_10_EVMAXIMUM_V2XENERGY_REQUEST_TYPE                                (Exi_RootElementIdType)600U
#define EXI_ISO_20_CM_10_EVMINIMUM_ENERGY_REQUEST_TYPE                                   (Exi_RootElementIdType)601U
#define EXI_ISO_20_CM_10_EVMINIMUM_V2XENERGY_REQUEST_TYPE                                (Exi_RootElementIdType)602U
#define EXI_ISO_20_CM_10_EVPOWER_PROFILE_TYPE                                            (Exi_RootElementIdType)603U
#define EXI_ISO_20_CM_10_EVPOWER_PROFILE_ENTRIES_TYPE                                    (Exi_RootElementIdType)604U
#define EXI_ISO_20_CM_10_EVPOWER_PROFILE_ENTRY_TYPE                                      (Exi_RootElementIdType)605U
#define EXI_ISO_20_CM_10_EVPOWER_SCHEDULE_TYPE                                           (Exi_RootElementIdType)606U
#define EXI_ISO_20_CM_10_EVPOWER_SCHEDULE_ENTRIES_TYPE                                   (Exi_RootElementIdType)607U
#define EXI_ISO_20_CM_10_EVPOWER_SCHEDULE_ENTRY_TYPE                                     (Exi_RootElementIdType)608U
#define EXI_ISO_20_CM_10_EVPRICE_RULE_TYPE                                               (Exi_RootElementIdType)609U
#define EXI_ISO_20_CM_10_EVPRICE_RULE_STACK_TYPE                                         (Exi_RootElementIdType)610U
#define EXI_ISO_20_CM_10_EVPRICE_RULE_STACKS_TYPE                                        (Exi_RootElementIdType)611U
#define EXI_ISO_20_CM_10_EVPROCESSING_TYPE                                               (Exi_RootElementIdType)612U
#define EXI_ISO_20_CM_10_EVSECHECK_OUT_STATUS_TYPE                                       (Exi_RootElementIdType)613U
#define EXI_ISO_20_CM_10_EVSEID_TYPE                                                     (Exi_RootElementIdType)614U
#define EXI_ISO_20_CM_10_EVSEPROCESSING_TYPE                                             (Exi_RootElementIdType)615U
#define EXI_ISO_20_CM_10_EVSESTATUS_TYPE                                                 (Exi_RootElementIdType)616U
#define EXI_ISO_20_CM_10_EVTARGET_ENERGY_REQUEST_TYPE                                    (Exi_RootElementIdType)617U
#define EXI_ISO_20_CM_10_EVTERMINATION_CODE_TYPE                                         (Exi_RootElementIdType)618U
#define EXI_ISO_20_CM_10_EVTERMINATION_EXPLANATION_TYPE                                  (Exi_RootElementIdType)619U
#define EXI_ISO_20_CM_10_ENERGY_FEE_TYPE                                                 (Exi_RootElementIdType)620U
#define EXI_ISO_20_CM_10_ENERGY_TRANSFER_SERVICE_LIST_TYPE                               (Exi_RootElementIdType)621U
#define EXI_ISO_20_CM_10_FREE_SERVICE_TYPE                                               (Exi_RootElementIdType)622U
#define EXI_ISO_20_CM_10_GEN_CHALLENGE_TYPE                                              (Exi_RootElementIdType)623U
#define EXI_ISO_20_CM_10_GO_TO_PAUSE_TYPE                                                (Exi_RootElementIdType)624U
#define EXI_ISO_20_CM_10_LANGUAGE_TYPE                                                   (Exi_RootElementIdType)625U
#define EXI_ISO_20_CM_10_LIST_OF_ROOT_CERTIFICATE_IDS_TYPE                               (Exi_RootElementIdType)626U
#define EXI_ISO_20_CM_10_MAXIMUM_CONTRACT_CERTIFICATE_CHAINS_TYPE                        (Exi_RootElementIdType)627U
#define EXI_ISO_20_CM_10_MAXIMUM_COST_TYPE                                               (Exi_RootElementIdType)628U
#define EXI_ISO_20_CM_10_MAXIMUM_SUPPORTING_POINTS_TYPE                                  (Exi_RootElementIdType)629U
#define EXI_ISO_20_CM_10_METER_INFO_TYPE                                                 (Exi_RootElementIdType)630U
#define EXI_ISO_20_CM_10_MINIMUM_COST_TYPE                                               (Exi_RootElementIdType)631U
#define EXI_ISO_20_CM_10_MINIMUM_SOC_TYPE                                                (Exi_RootElementIdType)632U
#define EXI_ISO_20_CM_10_NUMBER_OF_PRICE_LEVELS_TYPE                                     (Exi_RootElementIdType)633U
#define EXI_ISO_20_CM_10_OEMPROVISIONING_CERTIFICATE_CHAIN_TYPE                          (Exi_RootElementIdType)634U
#define EXI_ISO_20_CM_10_OVERSTAY_FEE_TYPE                                               (Exi_RootElementIdType)635U
#define EXI_ISO_20_CM_10_OVERSTAY_FEE_PERIOD_TYPE                                        (Exi_RootElementIdType)636U
#define EXI_ISO_20_CM_10_OVERSTAY_POWER_THRESHOLD_TYPE                                   (Exi_RootElementIdType)637U
#define EXI_ISO_20_CM_10_OVERSTAY_RULE_TYPE                                              (Exi_RootElementIdType)638U
#define EXI_ISO_20_CM_10_OVERSTAY_RULE_DESCRIPTION_TYPE                                  (Exi_RootElementIdType)639U
#define EXI_ISO_20_CM_10_OVERSTAY_RULES_TYPE                                             (Exi_RootElementIdType)640U
#define EXI_ISO_20_CM_10_OVERSTAY_TIME_THRESHOLD_TYPE                                    (Exi_RootElementIdType)641U
#define EXI_ISO_20_CM_10_PARAMETER_TYPE                                                  (Exi_RootElementIdType)642U
#define EXI_ISO_20_CM_10_PARAMETER_SET_TYPE                                              (Exi_RootElementIdType)643U
#define EXI_ISO_20_CM_10_PARAMETER_SET_ID_TYPE                                           (Exi_RootElementIdType)644U
#define EXI_ISO_20_CM_10_PARKING_FEE_TYPE                                                (Exi_RootElementIdType)645U
#define EXI_ISO_20_CM_10_PARKING_FEE_PERIOD_TYPE                                         (Exi_RootElementIdType)646U
#define EXI_ISO_20_CM_10_PARKING_METHOD_TYPE                                             (Exi_RootElementIdType)647U
#define EXI_ISO_20_CM_10_PARKING_SPACE_TYPE                                              (Exi_RootElementIdType)648U
#define EXI_ISO_20_CM_10_PN_C_AREQ_AUTHORIZATION_MODE_TYPE                               (Exi_RootElementIdType)649U
#define EXI_ISO_20_CM_10_PN_C_ASRES_AUTHORIZATION_MODE_TYPE                              (Exi_RootElementIdType)650U
#define EXI_ISO_20_CM_10_POWER_TYPE                                                      (Exi_RootElementIdType)651U
#define EXI_ISO_20_CM_10_POWER_RANGE_START_TYPE                                          (Exi_RootElementIdType)652U
#define EXI_ISO_20_CM_10_POWER_SCHEDULE_TYPE                                             (Exi_RootElementIdType)653U
#define EXI_ISO_20_CM_10_POWER_SCHEDULE_ENTRIES_TYPE                                     (Exi_RootElementIdType)654U
#define EXI_ISO_20_CM_10_POWER_SCHEDULE_ENTRY_TYPE                                       (Exi_RootElementIdType)655U
#define EXI_ISO_20_CM_10_POWER_TOLERANCE_TYPE                                            (Exi_RootElementIdType)656U
#define EXI_ISO_20_CM_10_POWER_TOLERANCE_ACCEPTANCE_TYPE                                 (Exi_RootElementIdType)657U
#define EXI_ISO_20_CM_10_POWER_L2_TYPE                                                   (Exi_RootElementIdType)658U
#define EXI_ISO_20_CM_10_POWER_L3_TYPE                                                   (Exi_RootElementIdType)659U
#define EXI_ISO_20_CM_10_PRICE_ALGORITHM_TYPE                                            (Exi_RootElementIdType)660U
#define EXI_ISO_20_CM_10_PRICE_LEVEL_TYPE                                                (Exi_RootElementIdType)661U
#define EXI_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_TYPE                                       (Exi_RootElementIdType)662U
#define EXI_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_ENTRIES_TYPE                               (Exi_RootElementIdType)663U
#define EXI_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_ENTRY_TYPE                                 (Exi_RootElementIdType)664U
#define EXI_ISO_20_CM_10_PRICE_RULE_TYPE                                                 (Exi_RootElementIdType)665U
#define EXI_ISO_20_CM_10_PRICE_RULE_STACK_TYPE                                           (Exi_RootElementIdType)666U
#define EXI_ISO_20_CM_10_PRICE_RULE_STACKS_TYPE                                          (Exi_RootElementIdType)667U
#define EXI_ISO_20_CM_10_PRICE_SCHEDULE_DESCRIPTION_TYPE                                 (Exi_RootElementIdType)668U
#define EXI_ISO_20_CM_10_PRICE_SCHEDULE_ID_TYPE                                          (Exi_RootElementIdType)669U
#define EXI_ISO_20_CM_10_PRIORITIZED_EMAIDS_TYPE                                         (Exi_RootElementIdType)670U
#define EXI_ISO_20_CM_10_PROVIDER_ID_TYPE                                                (Exi_RootElementIdType)671U
#define EXI_ISO_20_CM_10_RECEIPT_TYPE                                                    (Exi_RootElementIdType)672U
#define EXI_ISO_20_CM_10_REMAINING_CONTRACT_CERTIFICATE_CHAINS_TYPE                      (Exi_RootElementIdType)673U
#define EXI_ISO_20_CM_10_RENEWABLE_GENERATION_PERCENTAGE_TYPE                            (Exi_RootElementIdType)674U
#define EXI_ISO_20_CM_10_SECP521_ENCRYPTED_PRIVATE_KEY_TYPE                              (Exi_RootElementIdType)675U
#define EXI_ISO_20_CM_10_SCHEDULE_TUPLE_TYPE                                             (Exi_RootElementIdType)676U
#define EXI_ISO_20_CM_10_SCHEDULE_TUPLE_ID_TYPE                                          (Exi_RootElementIdType)677U
#define EXI_ISO_20_CM_10_SCHEDULED_EVPPTCONTROL_MODE_TYPE                                (Exi_RootElementIdType)678U
#define EXI_ISO_20_CM_10_SCHEDULED_SEREQ_CONTROL_MODE_TYPE                               (Exi_RootElementIdType)679U
#define EXI_ISO_20_CM_10_SCHEDULED_SERES_CONTROL_MODE_TYPE                               (Exi_RootElementIdType)680U
#define EXI_ISO_20_CM_10_SCHEDULED_SMDTCONTROL_MODE_TYPE                                 (Exi_RootElementIdType)681U
#define EXI_ISO_20_CM_10_SELECTED_AUTHORIZATION_SERVICE_TYPE                             (Exi_RootElementIdType)682U
#define EXI_ISO_20_CM_10_SELECTED_ENERGY_TRANSFER_SERVICE_TYPE                           (Exi_RootElementIdType)683U
#define EXI_ISO_20_CM_10_SELECTED_SCHEDULE_TUPLE_ID_TYPE                                 (Exi_RootElementIdType)684U
#define EXI_ISO_20_CM_10_SELECTED_SERVICE_TYPE                                           (Exi_RootElementIdType)685U
#define EXI_ISO_20_CM_10_SELECTED_VASLIST_TYPE                                           (Exi_RootElementIdType)686U
#define EXI_ISO_20_CM_10_SERVICE_TYPE                                                    (Exi_RootElementIdType)687U
#define EXI_ISO_20_CM_10_SERVICE_FEE_TYPE                                                (Exi_RootElementIdType)688U
#define EXI_ISO_20_CM_10_SERVICE_ID_TYPE                                                 (Exi_RootElementIdType)689U
#define EXI_ISO_20_CM_10_SERVICE_NAME_TYPE                                               (Exi_RootElementIdType)690U
#define EXI_ISO_20_CM_10_SERVICE_PARAMETER_LIST_TYPE                                     (Exi_RootElementIdType)691U
#define EXI_ISO_20_CM_10_SERVICE_RENEGOTIATION_SUPPORTED_TYPE                            (Exi_RootElementIdType)692U
#define EXI_ISO_20_CM_10_SESSION_ID_TYPE                                                 (Exi_RootElementIdType)693U
#define EXI_ISO_20_CM_10_START_TIME_TYPE                                                 (Exi_RootElementIdType)694U
#define EXI_ISO_20_CM_10_SUB_CERTIFICATES_TYPE                                           (Exi_RootElementIdType)695U
#define EXI_ISO_20_CM_10_SUPPORTED_PROVIDERS_TYPE                                        (Exi_RootElementIdType)696U
#define EXI_ISO_20_CM_10_SUPPORTED_SERVICE_IDS_TYPE                                      (Exi_RootElementIdType)697U
#define EXI_ISO_20_CM_10_TPM_ENCRYPTED_PRIVATE_KEY_TYPE                                  (Exi_RootElementIdType)698U
#define EXI_ISO_20_CM_10_TARGET_DISTANCE_TYPE                                            (Exi_RootElementIdType)699U
#define EXI_ISO_20_CM_10_TARGET_OFFSET_X_TYPE                                            (Exi_RootElementIdType)700U
#define EXI_ISO_20_CM_10_TARGET_OFFSET_Y_TYPE                                            (Exi_RootElementIdType)701U
#define EXI_ISO_20_CM_10_TARGET_SOC_TYPE                                                 (Exi_RootElementIdType)702U
#define EXI_ISO_20_CM_10_TAX_INCLUDED_IN_PRICE_TYPE                                      (Exi_RootElementIdType)703U
#define EXI_ISO_20_CM_10_TAX_RATE_TYPE                                                   (Exi_RootElementIdType)704U
#define EXI_ISO_20_CM_10_TAX_RULE_TYPE                                                   (Exi_RootElementIdType)705U
#define EXI_ISO_20_CM_10_TAX_RULE_ID_TYPE                                                (Exi_RootElementIdType)706U
#define EXI_ISO_20_CM_10_TAX_RULE_NAME_TYPE                                              (Exi_RootElementIdType)707U
#define EXI_ISO_20_CM_10_TAX_RULES_TYPE                                                  (Exi_RootElementIdType)708U
#define EXI_ISO_20_CM_10_TIME_ANCHOR_TYPE                                                (Exi_RootElementIdType)709U
#define EXI_ISO_20_CM_10_VASLIST_TYPE                                                    (Exi_RootElementIdType)710U
#define EXI_ISO_20_CM_10_VEHICLE_FRAME_TYPE                                              (Exi_RootElementIdType)711U
#define EXI_ISO_20_CM_10_VEHICLE_TRAVEL_TYPE                                             (Exi_RootElementIdType)712U
#define EXI_ISO_20_CM_10_X448_ENCRYPTED_PRIVATE_KEY_TYPE                                 (Exi_RootElementIdType)713U
#define EXI_ISO_20_CM_10_BOOL_VALUE_TYPE                                                 (Exi_RootElementIdType)714U
#define EXI_ISO_20_CM_10_BYTE_VALUE_TYPE                                                 (Exi_RootElementIdType)715U
#define EXI_ISO_20_CM_10_FINITE_STRING_TYPE                                              (Exi_RootElementIdType)716U
#define EXI_ISO_20_CM_10_INT_VALUE_TYPE                                                  (Exi_RootElementIdType)717U
#define EXI_ISO_20_CM_10_RATIONAL_NUMBER_TYPE                                            (Exi_RootElementIdType)718U
#define EXI_ISO_20_CM_10_SHORT_VALUE_TYPE                                                (Exi_RootElementIdType)719U
#define EXI_SCHEMA_SET_ISO_20_CM_10_TYPE                                                 (Exi_RootElementIdType)5U
#ifndef EXI_MAX_BUFFER_SIZE_ISO_20_CM_10_ATTRIBUTEID
  #define EXI_MAX_BUFFER_SIZE_ISO_20_CM_10_ATTRIBUTEID EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif

/**********************************************************************************************************************
 *  ELEMENT IDENTIFIER DEFINES
**********************************************************************************************************************/
#define EXI_ISO_20_CM_10_EI_ID                                                 (uint16)0U
#define EXI_ISO_20_CM_10_EI_ID_SE                                              (uint16)1U
#define EXI_ISO_20_CM_10_EI_ID_CT                                              (uint16)2U
#define EXI_ISO_20_CM_10_EI_ID_EE                                              (uint16)3U
#define EXI_ISO_20_CM_10_EI_ID_AT                                              (uint16)4U
#define EXI_ISO_20_CM_10_EI_TIME_ANCHOR                                        (uint16)5U
#define EXI_ISO_20_CM_10_EI_TIME_ANCHOR_SE                                     (uint16)6U
#define EXI_ISO_20_CM_10_EI_TIME_ANCHOR_CT                                     (uint16)7U
#define EXI_ISO_20_CM_10_EI_TIME_ANCHOR_EE                                     (uint16)8U
#define EXI_ISO_20_CM_10_EI_TIME_ANCHOR_AT                                     (uint16)9U
#define EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID                                  (uint16)10U
#define EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID_SE                               (uint16)11U
#define EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID_CT                               (uint16)12U
#define EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID_EE                               (uint16)13U
#define EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID_AT                               (uint16)14U
#define EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_DESCRIPTION                         (uint16)15U
#define EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_DESCRIPTION_SE                      (uint16)16U
#define EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_DESCRIPTION_CT                      (uint16)17U
#define EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_DESCRIPTION_EE                      (uint16)18U
#define EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_DESCRIPTION_AT                      (uint16)19U
#define EXI_ISO_20_CM_10_EI_CURRENCY                                           (uint16)20U
#define EXI_ISO_20_CM_10_EI_CURRENCY_SE                                        (uint16)21U
#define EXI_ISO_20_CM_10_EI_CURRENCY_CT                                        (uint16)22U
#define EXI_ISO_20_CM_10_EI_CURRENCY_EE                                        (uint16)23U
#define EXI_ISO_20_CM_10_EI_CURRENCY_AT                                        (uint16)24U
#define EXI_ISO_20_CM_10_EI_LANGUAGE                                           (uint16)25U
#define EXI_ISO_20_CM_10_EI_LANGUAGE_SE                                        (uint16)26U
#define EXI_ISO_20_CM_10_EI_LANGUAGE_CT                                        (uint16)27U
#define EXI_ISO_20_CM_10_EI_LANGUAGE_EE                                        (uint16)28U
#define EXI_ISO_20_CM_10_EI_LANGUAGE_AT                                        (uint16)29U
#define EXI_ISO_20_CM_10_EI_PRICE_ALGORITHM                                    (uint16)30U
#define EXI_ISO_20_CM_10_EI_PRICE_ALGORITHM_SE                                 (uint16)31U
#define EXI_ISO_20_CM_10_EI_PRICE_ALGORITHM_CT                                 (uint16)32U
#define EXI_ISO_20_CM_10_EI_PRICE_ALGORITHM_EE                                 (uint16)33U
#define EXI_ISO_20_CM_10_EI_PRICE_ALGORITHM_AT                                 (uint16)34U
#define EXI_ISO_20_CM_10_EI_MINIMUM_COST                                       (uint16)35U
#define EXI_ISO_20_CM_10_EI_MINIMUM_COST_SE                                    (uint16)36U
#define EXI_ISO_20_CM_10_EI_MINIMUM_COST_CT                                    (uint16)37U
#define EXI_ISO_20_CM_10_EI_MINIMUM_COST_EE                                    (uint16)38U
#define EXI_ISO_20_CM_10_EI_MINIMUM_COST_AT                                    (uint16)39U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_COST                                       (uint16)40U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_COST_SE                                    (uint16)41U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_COST_CT                                    (uint16)42U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_COST_EE                                    (uint16)43U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_COST_AT                                    (uint16)44U
#define EXI_ISO_20_CM_10_EI_TAX_RULES                                          (uint16)45U
#define EXI_ISO_20_CM_10_EI_TAX_RULES_SE                                       (uint16)46U
#define EXI_ISO_20_CM_10_EI_TAX_RULES_CT                                       (uint16)47U
#define EXI_ISO_20_CM_10_EI_TAX_RULES_EE                                       (uint16)48U
#define EXI_ISO_20_CM_10_EI_TAX_RULES_AT                                       (uint16)49U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_STACKS                                  (uint16)50U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_STACKS_SE                               (uint16)51U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_STACKS_CT                               (uint16)52U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_STACKS_EE                               (uint16)53U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_STACKS_AT                               (uint16)54U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULES                                     (uint16)55U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULES_SE                                  (uint16)56U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULES_CT                                  (uint16)57U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULES_EE                                  (uint16)58U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULES_AT                                  (uint16)59U
#define EXI_ISO_20_CM_10_EI_ADDITIONAL_SELECTED_SERVICES                       (uint16)60U
#define EXI_ISO_20_CM_10_EI_ADDITIONAL_SELECTED_SERVICES_SE                    (uint16)61U
#define EXI_ISO_20_CM_10_EI_ADDITIONAL_SELECTED_SERVICES_CT                    (uint16)62U
#define EXI_ISO_20_CM_10_EI_ADDITIONAL_SELECTED_SERVICES_EE                    (uint16)63U
#define EXI_ISO_20_CM_10_EI_ADDITIONAL_SELECTED_SERVICES_AT                    (uint16)64U
#define EXI_ISO_20_CM_10_EI_ADDITIONAL_SERVICE                                 (uint16)65U
#define EXI_ISO_20_CM_10_EI_ADDITIONAL_SERVICE_SE                              (uint16)66U
#define EXI_ISO_20_CM_10_EI_ADDITIONAL_SERVICE_CT                              (uint16)67U
#define EXI_ISO_20_CM_10_EI_ADDITIONAL_SERVICE_EE                              (uint16)68U
#define EXI_ISO_20_CM_10_EI_ADDITIONAL_SERVICE_AT                              (uint16)69U
#define EXI_ISO_20_CM_10_EI_SERVICE_NAME                                       (uint16)70U
#define EXI_ISO_20_CM_10_EI_SERVICE_NAME_SE                                    (uint16)71U
#define EXI_ISO_20_CM_10_EI_SERVICE_NAME_CT                                    (uint16)72U
#define EXI_ISO_20_CM_10_EI_SERVICE_NAME_EE                                    (uint16)73U
#define EXI_ISO_20_CM_10_EI_SERVICE_NAME_AT                                    (uint16)74U
#define EXI_ISO_20_CM_10_EI_SERVICE_FEE                                        (uint16)75U
#define EXI_ISO_20_CM_10_EI_SERVICE_FEE_SE                                     (uint16)76U
#define EXI_ISO_20_CM_10_EI_SERVICE_FEE_CT                                     (uint16)77U
#define EXI_ISO_20_CM_10_EI_SERVICE_FEE_EE                                     (uint16)78U
#define EXI_ISO_20_CM_10_EI_SERVICE_FEE_AT                                     (uint16)79U
#define EXI_ISO_20_CM_10_EI_ATTRIBUTE_ID                                       (uint16)80U
#define EXI_ISO_20_CM_10_EI_ATTRIBUTE_ID_SE                                    (uint16)81U
#define EXI_ISO_20_CM_10_EI_ATTRIBUTE_ID_CT                                    (uint16)82U
#define EXI_ISO_20_CM_10_EI_ATTRIBUTE_ID_EE                                    (uint16)83U
#define EXI_ISO_20_CM_10_EI_ATTRIBUTE_ID_AT                                    (uint16)84U
#define EXI_ISO_20_CM_10_EI_HEADER                                             (uint16)85U
#define EXI_ISO_20_CM_10_EI_HEADER_SE                                          (uint16)86U
#define EXI_ISO_20_CM_10_EI_HEADER_CT                                          (uint16)87U
#define EXI_ISO_20_CM_10_EI_HEADER_EE                                          (uint16)88U
#define EXI_ISO_20_CM_10_EI_HEADER_AT                                          (uint16)89U
#define EXI_ISO_20_CM_10_EI_SELECTED_AUTHORIZATION_SERVICE                     (uint16)90U
#define EXI_ISO_20_CM_10_EI_SELECTED_AUTHORIZATION_SERVICE_SE                  (uint16)91U
#define EXI_ISO_20_CM_10_EI_SELECTED_AUTHORIZATION_SERVICE_CT                  (uint16)92U
#define EXI_ISO_20_CM_10_EI_SELECTED_AUTHORIZATION_SERVICE_EE                  (uint16)93U
#define EXI_ISO_20_CM_10_EI_SELECTED_AUTHORIZATION_SERVICE_AT                  (uint16)94U
#define EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT                                     (uint16)95U
#define EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE                                  (uint16)96U
#define EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_CT                                  (uint16)97U
#define EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE                                  (uint16)98U
#define EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_AT                                  (uint16)99U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_REQ                                  (uint16)100U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_REQ_SE                               (uint16)101U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_REQ_CT                               (uint16)102U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_REQ_EE                               (uint16)103U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_REQ_AT                               (uint16)104U
#define EXI_ISO_20_CM_10_EI_RESPONSE_CODE                                      (uint16)105U
#define EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE                                   (uint16)106U
#define EXI_ISO_20_CM_10_EI_RESPONSE_CODE_CT                                   (uint16)107U
#define EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE                                   (uint16)108U
#define EXI_ISO_20_CM_10_EI_RESPONSE_CODE_AT                                   (uint16)109U
#define EXI_ISO_20_CM_10_EI_EVSEPROCESSING                                     (uint16)110U
#define EXI_ISO_20_CM_10_EI_EVSEPROCESSING_SE                                  (uint16)111U
#define EXI_ISO_20_CM_10_EI_EVSEPROCESSING_CT                                  (uint16)112U
#define EXI_ISO_20_CM_10_EI_EVSEPROCESSING_EE                                  (uint16)113U
#define EXI_ISO_20_CM_10_EI_EVSEPROCESSING_AT                                  (uint16)114U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_RES                                  (uint16)115U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_RES_SE                               (uint16)116U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_RES_CT                               (uint16)117U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_RES_EE                               (uint16)118U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_RES_AT                               (uint16)119U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_REQ                            (uint16)120U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_REQ_SE                         (uint16)121U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_REQ_CT                         (uint16)122U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_REQ_EE                         (uint16)123U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_REQ_AT                         (uint16)124U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SERVICES                             (uint16)125U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SERVICES_SE                          (uint16)126U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SERVICES_CT                          (uint16)127U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SERVICES_EE                          (uint16)128U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SERVICES_AT                          (uint16)129U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_SERVICE                   (uint16)130U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_SERVICE_SE                (uint16)131U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_SERVICE_CT                (uint16)132U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_SERVICE_EE                (uint16)133U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_SERVICE_AT                (uint16)134U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_RES                            (uint16)135U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_RES_SE                         (uint16)136U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_RES_CT                         (uint16)137U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_RES_EE                         (uint16)138U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_RES_AT                         (uint16)139U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE                                        (uint16)140U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_SE                                     (uint16)141U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_CT                                     (uint16)142U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_EE                                     (uint16)143U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_AT                                     (uint16)144U
#define EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES                                   (uint16)145U
#define EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES_SE                                (uint16)146U
#define EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES_CT                                (uint16)147U
#define EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES_EE                                (uint16)148U
#define EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES_AT                                (uint16)149U
#define EXI_ISO_20_CM_10_EI_OEMPROVISIONING_CERTIFICATE_CHAIN                  (uint16)150U
#define EXI_ISO_20_CM_10_EI_OEMPROVISIONING_CERTIFICATE_CHAIN_SE               (uint16)151U
#define EXI_ISO_20_CM_10_EI_OEMPROVISIONING_CERTIFICATE_CHAIN_CT               (uint16)152U
#define EXI_ISO_20_CM_10_EI_OEMPROVISIONING_CERTIFICATE_CHAIN_EE               (uint16)153U
#define EXI_ISO_20_CM_10_EI_OEMPROVISIONING_CERTIFICATE_CHAIN_AT               (uint16)154U
#define EXI_ISO_20_CM_10_EI_LIST_OF_ROOT_CERTIFICATE_IDS                       (uint16)155U
#define EXI_ISO_20_CM_10_EI_LIST_OF_ROOT_CERTIFICATE_IDS_SE                    (uint16)156U
#define EXI_ISO_20_CM_10_EI_LIST_OF_ROOT_CERTIFICATE_IDS_CT                    (uint16)157U
#define EXI_ISO_20_CM_10_EI_LIST_OF_ROOT_CERTIFICATE_IDS_EE                    (uint16)158U
#define EXI_ISO_20_CM_10_EI_LIST_OF_ROOT_CERTIFICATE_IDS_AT                    (uint16)159U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_CONTRACT_CERTIFICATE_CHAINS                (uint16)160U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_CONTRACT_CERTIFICATE_CHAINS_SE             (uint16)161U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_CONTRACT_CERTIFICATE_CHAINS_CT             (uint16)162U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_CONTRACT_CERTIFICATE_CHAINS_EE             (uint16)163U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_CONTRACT_CERTIFICATE_CHAINS_AT             (uint16)164U
#define EXI_ISO_20_CM_10_EI_PRIORITIZED_EMAIDS                                 (uint16)165U
#define EXI_ISO_20_CM_10_EI_PRIORITIZED_EMAIDS_SE                              (uint16)166U
#define EXI_ISO_20_CM_10_EI_PRIORITIZED_EMAIDS_CT                              (uint16)167U
#define EXI_ISO_20_CM_10_EI_PRIORITIZED_EMAIDS_EE                              (uint16)168U
#define EXI_ISO_20_CM_10_EI_PRIORITIZED_EMAIDS_AT                              (uint16)169U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_REQ                       (uint16)170U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_REQ_SE                    (uint16)171U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_REQ_CT                    (uint16)172U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_REQ_EE                    (uint16)173U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_REQ_AT                    (uint16)174U
#define EXI_ISO_20_CM_10_EI_CPSCERTIFICATE_CHAIN                               (uint16)175U
#define EXI_ISO_20_CM_10_EI_CPSCERTIFICATE_CHAIN_SE                            (uint16)176U
#define EXI_ISO_20_CM_10_EI_CPSCERTIFICATE_CHAIN_CT                            (uint16)177U
#define EXI_ISO_20_CM_10_EI_CPSCERTIFICATE_CHAIN_EE                            (uint16)178U
#define EXI_ISO_20_CM_10_EI_CPSCERTIFICATE_CHAIN_AT                            (uint16)179U
#define EXI_ISO_20_CM_10_EI_SIGNED_INSTALLATION_DATA                           (uint16)180U
#define EXI_ISO_20_CM_10_EI_SIGNED_INSTALLATION_DATA_SE                        (uint16)181U
#define EXI_ISO_20_CM_10_EI_SIGNED_INSTALLATION_DATA_CT                        (uint16)182U
#define EXI_ISO_20_CM_10_EI_SIGNED_INSTALLATION_DATA_EE                        (uint16)183U
#define EXI_ISO_20_CM_10_EI_SIGNED_INSTALLATION_DATA_AT                        (uint16)184U
#define EXI_ISO_20_CM_10_EI_REMAINING_CONTRACT_CERTIFICATE_CHAINS              (uint16)185U
#define EXI_ISO_20_CM_10_EI_REMAINING_CONTRACT_CERTIFICATE_CHAINS_SE           (uint16)186U
#define EXI_ISO_20_CM_10_EI_REMAINING_CONTRACT_CERTIFICATE_CHAINS_CT           (uint16)187U
#define EXI_ISO_20_CM_10_EI_REMAINING_CONTRACT_CERTIFICATE_CHAINS_EE           (uint16)188U
#define EXI_ISO_20_CM_10_EI_REMAINING_CONTRACT_CERTIFICATE_CHAINS_AT           (uint16)189U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_RES                       (uint16)190U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_RES_SE                    (uint16)191U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_RES_CT                    (uint16)192U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_RES_EE                    (uint16)193U
#define EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_RES_AT                    (uint16)194U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE                                     (uint16)195U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_SE                                  (uint16)196U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_CT                                  (uint16)197U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_EE                                  (uint16)198U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_AT                                  (uint16)199U
#define EXI_ISO_20_CM_10_EI_DEPARTURE_TIME                                     (uint16)200U
#define EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_SE                                  (uint16)201U
#define EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_CT                                  (uint16)202U
#define EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_EE                                  (uint16)203U
#define EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_AT                                  (uint16)204U
#define EXI_ISO_20_CM_10_EI_MINIMUM_SOC                                        (uint16)205U
#define EXI_ISO_20_CM_10_EI_MINIMUM_SOC_SE                                     (uint16)206U
#define EXI_ISO_20_CM_10_EI_MINIMUM_SOC_CT                                     (uint16)207U
#define EXI_ISO_20_CM_10_EI_MINIMUM_SOC_EE                                     (uint16)208U
#define EXI_ISO_20_CM_10_EI_MINIMUM_SOC_AT                                     (uint16)209U
#define EXI_ISO_20_CM_10_EI_TARGET_SOC                                         (uint16)210U
#define EXI_ISO_20_CM_10_EI_TARGET_SOC_SE                                      (uint16)211U
#define EXI_ISO_20_CM_10_EI_TARGET_SOC_CT                                      (uint16)212U
#define EXI_ISO_20_CM_10_EI_TARGET_SOC_EE                                      (uint16)213U
#define EXI_ISO_20_CM_10_EI_TARGET_SOC_AT                                      (uint16)214U
#define EXI_ISO_20_CM_10_EI_EVTARGET_ENERGY_REQUEST                            (uint16)215U
#define EXI_ISO_20_CM_10_EI_EVTARGET_ENERGY_REQUEST_SE                         (uint16)216U
#define EXI_ISO_20_CM_10_EI_EVTARGET_ENERGY_REQUEST_CT                         (uint16)217U
#define EXI_ISO_20_CM_10_EI_EVTARGET_ENERGY_REQUEST_EE                         (uint16)218U
#define EXI_ISO_20_CM_10_EI_EVTARGET_ENERGY_REQUEST_AT                         (uint16)219U
#define EXI_ISO_20_CM_10_EI_EVMAXIMUM_ENERGY_REQUEST                           (uint16)220U
#define EXI_ISO_20_CM_10_EI_EVMAXIMUM_ENERGY_REQUEST_SE                        (uint16)221U
#define EXI_ISO_20_CM_10_EI_EVMAXIMUM_ENERGY_REQUEST_CT                        (uint16)222U
#define EXI_ISO_20_CM_10_EI_EVMAXIMUM_ENERGY_REQUEST_EE                        (uint16)223U
#define EXI_ISO_20_CM_10_EI_EVMAXIMUM_ENERGY_REQUEST_AT                        (uint16)224U
#define EXI_ISO_20_CM_10_EI_EVMINIMUM_ENERGY_REQUEST                           (uint16)225U
#define EXI_ISO_20_CM_10_EI_EVMINIMUM_ENERGY_REQUEST_SE                        (uint16)226U
#define EXI_ISO_20_CM_10_EI_EVMINIMUM_ENERGY_REQUEST_CT                        (uint16)227U
#define EXI_ISO_20_CM_10_EI_EVMINIMUM_ENERGY_REQUEST_EE                        (uint16)228U
#define EXI_ISO_20_CM_10_EI_EVMINIMUM_ENERGY_REQUEST_AT                        (uint16)229U
#define EXI_ISO_20_CM_10_EI_EVMAXIMUM_V2XENERGY_REQUEST                        (uint16)230U
#define EXI_ISO_20_CM_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_SE                     (uint16)231U
#define EXI_ISO_20_CM_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_CT                     (uint16)232U
#define EXI_ISO_20_CM_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_EE                     (uint16)233U
#define EXI_ISO_20_CM_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_AT                     (uint16)234U
#define EXI_ISO_20_CM_10_EI_EVMINIMUM_V2XENERGY_REQUEST                        (uint16)235U
#define EXI_ISO_20_CM_10_EI_EVMINIMUM_V2XENERGY_REQUEST_SE                     (uint16)236U
#define EXI_ISO_20_CM_10_EI_EVMINIMUM_V2XENERGY_REQUEST_CT                     (uint16)237U
#define EXI_ISO_20_CM_10_EI_EVMINIMUM_V2XENERGY_REQUEST_EE                     (uint16)238U
#define EXI_ISO_20_CM_10_EI_EVMINIMUM_V2XENERGY_REQUEST_AT                     (uint16)239U
#define EXI_ISO_20_CM_10_EI_EMAID                                              (uint16)240U
#define EXI_ISO_20_CM_10_EI_EMAID_SE                                           (uint16)241U
#define EXI_ISO_20_CM_10_EI_EMAID_CT                                           (uint16)242U
#define EXI_ISO_20_CM_10_EI_EMAID_EE                                           (uint16)243U
#define EXI_ISO_20_CM_10_EI_EMAID_AT                                           (uint16)244U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACKS                                (uint16)245U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACKS_SE                             (uint16)246U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACKS_CT                             (uint16)247U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACKS_EE                             (uint16)248U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACKS_AT                             (uint16)249U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE                                   (uint16)250U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_SE                                (uint16)251U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_CT                                (uint16)252U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_EE                                (uint16)253U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_AT                                (uint16)254U
#define EXI_ISO_20_CM_10_EI_EVABSOLUTE_PRICE_SCHEDULE                          (uint16)255U
#define EXI_ISO_20_CM_10_EI_EVABSOLUTE_PRICE_SCHEDULE_SE                       (uint16)256U
#define EXI_ISO_20_CM_10_EI_EVABSOLUTE_PRICE_SCHEDULE_CT                       (uint16)257U
#define EXI_ISO_20_CM_10_EI_EVABSOLUTE_PRICE_SCHEDULE_EE                       (uint16)258U
#define EXI_ISO_20_CM_10_EI_EVABSOLUTE_PRICE_SCHEDULE_AT                       (uint16)259U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRY                              (uint16)260U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRY_SE                           (uint16)261U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRY_CT                           (uint16)262U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRY_EE                           (uint16)263U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRY_AT                           (uint16)264U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRIES                            (uint16)265U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRIES_SE                         (uint16)266U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRIES_CT                         (uint16)267U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRIES_EE                         (uint16)268U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRIES_AT                         (uint16)269U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRY                             (uint16)270U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRY_SE                          (uint16)271U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRY_CT                          (uint16)272U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRY_EE                          (uint16)273U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRY_AT                          (uint16)274U
#define EXI_ISO_20_CM_10_EI_DURATION                                           (uint16)275U
#define EXI_ISO_20_CM_10_EI_DURATION_SE                                        (uint16)276U
#define EXI_ISO_20_CM_10_EI_DURATION_CT                                        (uint16)277U
#define EXI_ISO_20_CM_10_EI_DURATION_EE                                        (uint16)278U
#define EXI_ISO_20_CM_10_EI_DURATION_AT                                        (uint16)279U
#define EXI_ISO_20_CM_10_EI_POWER                                              (uint16)280U
#define EXI_ISO_20_CM_10_EI_POWER_SE                                           (uint16)281U
#define EXI_ISO_20_CM_10_EI_POWER_CT                                           (uint16)282U
#define EXI_ISO_20_CM_10_EI_POWER_EE                                           (uint16)283U
#define EXI_ISO_20_CM_10_EI_POWER_AT                                           (uint16)284U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRIES                           (uint16)285U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRIES_SE                        (uint16)286U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRIES_CT                        (uint16)287U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRIES_EE                        (uint16)288U
#define EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRIES_AT                        (uint16)289U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACK                                 (uint16)290U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACK_SE                              (uint16)291U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACK_CT                              (uint16)292U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACK_EE                              (uint16)293U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACK_AT                              (uint16)294U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE                                       (uint16)295U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_SE                                    (uint16)296U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_CT                                    (uint16)297U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_EE                                    (uint16)298U
#define EXI_ISO_20_CM_10_EI_EVPRICE_RULE_AT                                    (uint16)299U
#define EXI_ISO_20_CM_10_EI_ENERGY_FEE                                         (uint16)300U
#define EXI_ISO_20_CM_10_EI_ENERGY_FEE_SE                                      (uint16)301U
#define EXI_ISO_20_CM_10_EI_ENERGY_FEE_CT                                      (uint16)302U
#define EXI_ISO_20_CM_10_EI_ENERGY_FEE_EE                                      (uint16)303U
#define EXI_ISO_20_CM_10_EI_ENERGY_FEE_AT                                      (uint16)304U
#define EXI_ISO_20_CM_10_EI_POWER_RANGE_START                                  (uint16)305U
#define EXI_ISO_20_CM_10_EI_POWER_RANGE_START_SE                               (uint16)306U
#define EXI_ISO_20_CM_10_EI_POWER_RANGE_START_CT                               (uint16)307U
#define EXI_ISO_20_CM_10_EI_POWER_RANGE_START_EE                               (uint16)308U
#define EXI_ISO_20_CM_10_EI_POWER_RANGE_START_AT                               (uint16)309U
#define EXI_ISO_20_CM_10_EI_SIGNED_METERING_DATA                               (uint16)310U
#define EXI_ISO_20_CM_10_EI_SIGNED_METERING_DATA_SE                            (uint16)311U
#define EXI_ISO_20_CM_10_EI_SIGNED_METERING_DATA_CT                            (uint16)312U
#define EXI_ISO_20_CM_10_EI_SIGNED_METERING_DATA_EE                            (uint16)313U
#define EXI_ISO_20_CM_10_EI_SIGNED_METERING_DATA_AT                            (uint16)314U
#define EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_REQ                          (uint16)315U
#define EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_REQ_SE                       (uint16)316U
#define EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_REQ_CT                       (uint16)317U
#define EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_REQ_EE                       (uint16)318U
#define EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_REQ_AT                       (uint16)319U
#define EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_RES                          (uint16)320U
#define EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_RES_SE                       (uint16)321U
#define EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_RES_CT                       (uint16)322U
#define EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_RES_EE                       (uint16)323U
#define EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_RES_AT                       (uint16)324U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_TIME_THRESHOLD                            (uint16)325U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_TIME_THRESHOLD_SE                         (uint16)326U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_TIME_THRESHOLD_CT                         (uint16)327U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_TIME_THRESHOLD_EE                         (uint16)328U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_TIME_THRESHOLD_AT                         (uint16)329U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_POWER_THRESHOLD                           (uint16)330U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_POWER_THRESHOLD_SE                        (uint16)331U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_POWER_THRESHOLD_CT                        (uint16)332U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_POWER_THRESHOLD_EE                        (uint16)333U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_POWER_THRESHOLD_AT                        (uint16)334U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULE                                      (uint16)335U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_SE                                   (uint16)336U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_CT                                   (uint16)337U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_EE                                   (uint16)338U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_AT                                   (uint16)339U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_DESCRIPTION                          (uint16)340U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_DESCRIPTION_SE                       (uint16)341U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_DESCRIPTION_CT                       (uint16)342U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_DESCRIPTION_EE                       (uint16)343U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_DESCRIPTION_AT                       (uint16)344U
#define EXI_ISO_20_CM_10_EI_START_TIME                                         (uint16)345U
#define EXI_ISO_20_CM_10_EI_START_TIME_SE                                      (uint16)346U
#define EXI_ISO_20_CM_10_EI_START_TIME_CT                                      (uint16)347U
#define EXI_ISO_20_CM_10_EI_START_TIME_EE                                      (uint16)348U
#define EXI_ISO_20_CM_10_EI_START_TIME_AT                                      (uint16)349U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_FEE                                       (uint16)350U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_SE                                    (uint16)351U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_CT                                    (uint16)352U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_EE                                    (uint16)353U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_AT                                    (uint16)354U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_PERIOD                                (uint16)355U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_PERIOD_SE                             (uint16)356U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_PERIOD_CT                             (uint16)357U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_PERIOD_EE                             (uint16)358U
#define EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_PERIOD_AT                             (uint16)359U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID                                   (uint16)360U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID_SE                                (uint16)361U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID_CT                                (uint16)362U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID_EE                                (uint16)363U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID_AT                                (uint16)364U
#define EXI_ISO_20_CM_10_EI_PARAMETER                                          (uint16)365U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SE                                       (uint16)366U
#define EXI_ISO_20_CM_10_EI_PARAMETER_CT                                       (uint16)367U
#define EXI_ISO_20_CM_10_EI_PARAMETER_EE                                       (uint16)368U
#define EXI_ISO_20_CM_10_EI_PARAMETER_AT                                       (uint16)369U
#define EXI_ISO_20_CM_10_EI_NAME                                               (uint16)370U
#define EXI_ISO_20_CM_10_EI_NAME_SE                                            (uint16)371U
#define EXI_ISO_20_CM_10_EI_NAME_CT                                            (uint16)372U
#define EXI_ISO_20_CM_10_EI_NAME_EE                                            (uint16)373U
#define EXI_ISO_20_CM_10_EI_NAME_AT                                            (uint16)374U
#define EXI_ISO_20_CM_10_EI_BOOL_VALUE                                         (uint16)375U
#define EXI_ISO_20_CM_10_EI_BOOL_VALUE_SE                                      (uint16)376U
#define EXI_ISO_20_CM_10_EI_BOOL_VALUE_CT                                      (uint16)377U
#define EXI_ISO_20_CM_10_EI_BOOL_VALUE_EE                                      (uint16)378U
#define EXI_ISO_20_CM_10_EI_BOOL_VALUE_AT                                      (uint16)379U
#define EXI_ISO_20_CM_10_EI_BYTE_VALUE                                         (uint16)380U
#define EXI_ISO_20_CM_10_EI_BYTE_VALUE_SE                                      (uint16)381U
#define EXI_ISO_20_CM_10_EI_BYTE_VALUE_CT                                      (uint16)382U
#define EXI_ISO_20_CM_10_EI_BYTE_VALUE_EE                                      (uint16)383U
#define EXI_ISO_20_CM_10_EI_BYTE_VALUE_AT                                      (uint16)384U
#define EXI_ISO_20_CM_10_EI_SHORT_VALUE                                        (uint16)385U
#define EXI_ISO_20_CM_10_EI_SHORT_VALUE_SE                                     (uint16)386U
#define EXI_ISO_20_CM_10_EI_SHORT_VALUE_CT                                     (uint16)387U
#define EXI_ISO_20_CM_10_EI_SHORT_VALUE_EE                                     (uint16)388U
#define EXI_ISO_20_CM_10_EI_SHORT_VALUE_AT                                     (uint16)389U
#define EXI_ISO_20_CM_10_EI_INT_VALUE                                          (uint16)390U
#define EXI_ISO_20_CM_10_EI_INT_VALUE_SE                                       (uint16)391U
#define EXI_ISO_20_CM_10_EI_INT_VALUE_CT                                       (uint16)392U
#define EXI_ISO_20_CM_10_EI_INT_VALUE_EE                                       (uint16)393U
#define EXI_ISO_20_CM_10_EI_INT_VALUE_AT                                       (uint16)394U
#define EXI_ISO_20_CM_10_EI_GEN_CHALLENGE                                      (uint16)395U
#define EXI_ISO_20_CM_10_EI_GEN_CHALLENGE_SE                                   (uint16)396U
#define EXI_ISO_20_CM_10_EI_GEN_CHALLENGE_CT                                   (uint16)397U
#define EXI_ISO_20_CM_10_EI_GEN_CHALLENGE_EE                                   (uint16)398U
#define EXI_ISO_20_CM_10_EI_GEN_CHALLENGE_AT                                   (uint16)399U
#define EXI_ISO_20_CM_10_EI_CONTRACT_CERTIFICATE_CHAIN                         (uint16)400U
#define EXI_ISO_20_CM_10_EI_CONTRACT_CERTIFICATE_CHAIN_SE                      (uint16)401U
#define EXI_ISO_20_CM_10_EI_CONTRACT_CERTIFICATE_CHAIN_CT                      (uint16)402U
#define EXI_ISO_20_CM_10_EI_CONTRACT_CERTIFICATE_CHAIN_EE                      (uint16)403U
#define EXI_ISO_20_CM_10_EI_CONTRACT_CERTIFICATE_CHAIN_AT                      (uint16)404U
#define EXI_ISO_20_CM_10_EI_SUPPORTED_PROVIDERS                                (uint16)405U
#define EXI_ISO_20_CM_10_EI_SUPPORTED_PROVIDERS_SE                             (uint16)406U
#define EXI_ISO_20_CM_10_EI_SUPPORTED_PROVIDERS_CT                             (uint16)407U
#define EXI_ISO_20_CM_10_EI_SUPPORTED_PROVIDERS_EE                             (uint16)408U
#define EXI_ISO_20_CM_10_EI_SUPPORTED_PROVIDERS_AT                             (uint16)409U
#define EXI_ISO_20_CM_10_EI_EVPROCESSING                                       (uint16)410U
#define EXI_ISO_20_CM_10_EI_EVPROCESSING_SE                                    (uint16)411U
#define EXI_ISO_20_CM_10_EI_EVPROCESSING_CT                                    (uint16)412U
#define EXI_ISO_20_CM_10_EI_EVPROCESSING_EE                                    (uint16)413U
#define EXI_ISO_20_CM_10_EI_EVPROCESSING_AT                                    (uint16)414U
#define EXI_ISO_20_CM_10_EI_CHARGE_PROGRESS                                    (uint16)415U
#define EXI_ISO_20_CM_10_EI_CHARGE_PROGRESS_SE                                 (uint16)416U
#define EXI_ISO_20_CM_10_EI_CHARGE_PROGRESS_CT                                 (uint16)417U
#define EXI_ISO_20_CM_10_EI_CHARGE_PROGRESS_EE                                 (uint16)418U
#define EXI_ISO_20_CM_10_EI_CHARGE_PROGRESS_AT                                 (uint16)419U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE                                    (uint16)420U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_SE                                 (uint16)421U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_CT                                 (uint16)422U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_EE                                 (uint16)423U
#define EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_AT                                 (uint16)424U
#define EXI_ISO_20_CM_10_EI_BPT_CHANNEL_SELECTION                              (uint16)425U
#define EXI_ISO_20_CM_10_EI_BPT_CHANNEL_SELECTION_SE                           (uint16)426U
#define EXI_ISO_20_CM_10_EI_BPT_CHANNEL_SELECTION_CT                           (uint16)427U
#define EXI_ISO_20_CM_10_EI_BPT_CHANNEL_SELECTION_EE                           (uint16)428U
#define EXI_ISO_20_CM_10_EI_BPT_CHANNEL_SELECTION_AT                           (uint16)429U
#define EXI_ISO_20_CM_10_EI_POWER_DELIVERY_REQ                                 (uint16)430U
#define EXI_ISO_20_CM_10_EI_POWER_DELIVERY_REQ_SE                              (uint16)431U
#define EXI_ISO_20_CM_10_EI_POWER_DELIVERY_REQ_CT                              (uint16)432U
#define EXI_ISO_20_CM_10_EI_POWER_DELIVERY_REQ_EE                              (uint16)433U
#define EXI_ISO_20_CM_10_EI_POWER_DELIVERY_REQ_AT                              (uint16)434U
#define EXI_ISO_20_CM_10_EI_EVSESTATUS                                         (uint16)435U
#define EXI_ISO_20_CM_10_EI_EVSESTATUS_SE                                      (uint16)436U
#define EXI_ISO_20_CM_10_EI_EVSESTATUS_CT                                      (uint16)437U
#define EXI_ISO_20_CM_10_EI_EVSESTATUS_EE                                      (uint16)438U
#define EXI_ISO_20_CM_10_EI_EVSESTATUS_AT                                      (uint16)439U
#define EXI_ISO_20_CM_10_EI_POWER_DELIVERY_RES                                 (uint16)440U
#define EXI_ISO_20_CM_10_EI_POWER_DELIVERY_RES_SE                              (uint16)441U
#define EXI_ISO_20_CM_10_EI_POWER_DELIVERY_RES_CT                              (uint16)442U
#define EXI_ISO_20_CM_10_EI_POWER_DELIVERY_RES_EE                              (uint16)443U
#define EXI_ISO_20_CM_10_EI_POWER_DELIVERY_RES_AT                              (uint16)444U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRY                               (uint16)445U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRY_SE                            (uint16)446U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRY_CT                            (uint16)447U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRY_EE                            (uint16)448U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRY_AT                            (uint16)449U
#define EXI_ISO_20_CM_10_EI_POWER_L2                                           (uint16)450U
#define EXI_ISO_20_CM_10_EI_POWER_L2_SE                                        (uint16)451U
#define EXI_ISO_20_CM_10_EI_POWER_L2_CT                                        (uint16)452U
#define EXI_ISO_20_CM_10_EI_POWER_L2_EE                                        (uint16)453U
#define EXI_ISO_20_CM_10_EI_POWER_L2_AT                                        (uint16)454U
#define EXI_ISO_20_CM_10_EI_POWER_L3                                           (uint16)455U
#define EXI_ISO_20_CM_10_EI_POWER_L3_SE                                        (uint16)456U
#define EXI_ISO_20_CM_10_EI_POWER_L3_CT                                        (uint16)457U
#define EXI_ISO_20_CM_10_EI_POWER_L3_EE                                        (uint16)458U
#define EXI_ISO_20_CM_10_EI_POWER_L3_AT                                        (uint16)459U
#define EXI_ISO_20_CM_10_EI_AVAILABLE_ENERGY                                   (uint16)460U
#define EXI_ISO_20_CM_10_EI_AVAILABLE_ENERGY_SE                                (uint16)461U
#define EXI_ISO_20_CM_10_EI_AVAILABLE_ENERGY_CT                                (uint16)462U
#define EXI_ISO_20_CM_10_EI_AVAILABLE_ENERGY_EE                                (uint16)463U
#define EXI_ISO_20_CM_10_EI_AVAILABLE_ENERGY_AT                                (uint16)464U
#define EXI_ISO_20_CM_10_EI_POWER_TOLERANCE                                    (uint16)465U
#define EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_SE                                 (uint16)466U
#define EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_CT                                 (uint16)467U
#define EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_EE                                 (uint16)468U
#define EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_AT                                 (uint16)469U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRIES                             (uint16)470U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRIES_SE                          (uint16)471U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRIES_CT                          (uint16)472U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRIES_EE                          (uint16)473U
#define EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRIES_AT                          (uint16)474U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRY                         (uint16)475U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRY_SE                      (uint16)476U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRY_CT                      (uint16)477U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRY_EE                      (uint16)478U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRY_AT                      (uint16)479U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL                                        (uint16)480U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SE                                     (uint16)481U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_CT                                     (uint16)482U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_EE                                     (uint16)483U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_AT                                     (uint16)484U
#define EXI_ISO_20_CM_10_EI_NUMBER_OF_PRICE_LEVELS                             (uint16)485U
#define EXI_ISO_20_CM_10_EI_NUMBER_OF_PRICE_LEVELS_SE                          (uint16)486U
#define EXI_ISO_20_CM_10_EI_NUMBER_OF_PRICE_LEVELS_CT                          (uint16)487U
#define EXI_ISO_20_CM_10_EI_NUMBER_OF_PRICE_LEVELS_EE                          (uint16)488U
#define EXI_ISO_20_CM_10_EI_NUMBER_OF_PRICE_LEVELS_AT                          (uint16)489U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRIES                       (uint16)490U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRIES_SE                    (uint16)491U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRIES_CT                    (uint16)492U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRIES_EE                    (uint16)493U
#define EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRIES_AT                    (uint16)494U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_STACK                                   (uint16)495U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_STACK_SE                                (uint16)496U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_STACK_CT                                (uint16)497U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_STACK_EE                                (uint16)498U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_STACK_AT                                (uint16)499U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE                                         (uint16)500U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_SE                                      (uint16)501U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_CT                                      (uint16)502U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_EE                                      (uint16)503U
#define EXI_ISO_20_CM_10_EI_PRICE_RULE_AT                                      (uint16)504U
#define EXI_ISO_20_CM_10_EI_PARKING_FEE                                        (uint16)505U
#define EXI_ISO_20_CM_10_EI_PARKING_FEE_SE                                     (uint16)506U
#define EXI_ISO_20_CM_10_EI_PARKING_FEE_CT                                     (uint16)507U
#define EXI_ISO_20_CM_10_EI_PARKING_FEE_EE                                     (uint16)508U
#define EXI_ISO_20_CM_10_EI_PARKING_FEE_AT                                     (uint16)509U
#define EXI_ISO_20_CM_10_EI_PARKING_FEE_PERIOD                                 (uint16)510U
#define EXI_ISO_20_CM_10_EI_PARKING_FEE_PERIOD_SE                              (uint16)511U
#define EXI_ISO_20_CM_10_EI_PARKING_FEE_PERIOD_CT                              (uint16)512U
#define EXI_ISO_20_CM_10_EI_PARKING_FEE_PERIOD_EE                              (uint16)513U
#define EXI_ISO_20_CM_10_EI_PARKING_FEE_PERIOD_AT                              (uint16)514U
#define EXI_ISO_20_CM_10_EI_CARBON_DIOXIDE_EMISSION                            (uint16)515U
#define EXI_ISO_20_CM_10_EI_CARBON_DIOXIDE_EMISSION_SE                         (uint16)516U
#define EXI_ISO_20_CM_10_EI_CARBON_DIOXIDE_EMISSION_CT                         (uint16)517U
#define EXI_ISO_20_CM_10_EI_CARBON_DIOXIDE_EMISSION_EE                         (uint16)518U
#define EXI_ISO_20_CM_10_EI_CARBON_DIOXIDE_EMISSION_AT                         (uint16)519U
#define EXI_ISO_20_CM_10_EI_RENEWABLE_GENERATION_PERCENTAGE                    (uint16)520U
#define EXI_ISO_20_CM_10_EI_RENEWABLE_GENERATION_PERCENTAGE_SE                 (uint16)521U
#define EXI_ISO_20_CM_10_EI_RENEWABLE_GENERATION_PERCENTAGE_CT                 (uint16)522U
#define EXI_ISO_20_CM_10_EI_RENEWABLE_GENERATION_PERCENTAGE_EE                 (uint16)523U
#define EXI_ISO_20_CM_10_EI_RENEWABLE_GENERATION_PERCENTAGE_AT                 (uint16)524U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_SUPPORTING_POINTS                          (uint16)525U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_SUPPORTING_POINTS_SE                       (uint16)526U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_SUPPORTING_POINTS_CT                       (uint16)527U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_SUPPORTING_POINTS_EE                       (uint16)528U
#define EXI_ISO_20_CM_10_EI_MAXIMUM_SUPPORTING_POINTS_AT                       (uint16)529U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_REQ                              (uint16)530U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_REQ_SE                           (uint16)531U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_REQ_CT                           (uint16)532U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_REQ_EE                           (uint16)533U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_REQ_AT                           (uint16)534U
#define EXI_ISO_20_CM_10_EI_GO_TO_PAUSE                                        (uint16)535U
#define EXI_ISO_20_CM_10_EI_GO_TO_PAUSE_SE                                     (uint16)536U
#define EXI_ISO_20_CM_10_EI_GO_TO_PAUSE_CT                                     (uint16)537U
#define EXI_ISO_20_CM_10_EI_GO_TO_PAUSE_EE                                     (uint16)538U
#define EXI_ISO_20_CM_10_EI_GO_TO_PAUSE_AT                                     (uint16)539U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_RES                              (uint16)540U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_RES_SE                           (uint16)541U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_RES_CT                           (uint16)542U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_RES_EE                           (uint16)543U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_RES_AT                           (uint16)544U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_ID                                  (uint16)545U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_ID_SE                               (uint16)546U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_ID_CT                               (uint16)547U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_ID_EE                               (uint16)548U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_ID_AT                               (uint16)549U
#define EXI_ISO_20_CM_10_EI_CHARGING_SCHEDULE                                  (uint16)550U
#define EXI_ISO_20_CM_10_EI_CHARGING_SCHEDULE_SE                               (uint16)551U
#define EXI_ISO_20_CM_10_EI_CHARGING_SCHEDULE_CT                               (uint16)552U
#define EXI_ISO_20_CM_10_EI_CHARGING_SCHEDULE_EE                               (uint16)553U
#define EXI_ISO_20_CM_10_EI_CHARGING_SCHEDULE_AT                               (uint16)554U
#define EXI_ISO_20_CM_10_EI_DISCHARGING_SCHEDULE                               (uint16)555U
#define EXI_ISO_20_CM_10_EI_DISCHARGING_SCHEDULE_SE                            (uint16)556U
#define EXI_ISO_20_CM_10_EI_DISCHARGING_SCHEDULE_CT                            (uint16)557U
#define EXI_ISO_20_CM_10_EI_DISCHARGING_SCHEDULE_EE                            (uint16)558U
#define EXI_ISO_20_CM_10_EI_DISCHARGING_SCHEDULE_AT                            (uint16)559U
#define EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID                         (uint16)560U
#define EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID_SE                      (uint16)561U
#define EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID_CT                      (uint16)562U
#define EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID_EE                      (uint16)563U
#define EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID_AT                      (uint16)564U
#define EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_ACCEPTANCE                         (uint16)565U
#define EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_ACCEPTANCE_SE                      (uint16)566U
#define EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_ACCEPTANCE_CT                      (uint16)567U
#define EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_ACCEPTANCE_EE                      (uint16)568U
#define EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_ACCEPTANCE_AT                      (uint16)569U
#define EXI_ISO_20_CM_10_EI_EVENERGY_OFFER                                     (uint16)570U
#define EXI_ISO_20_CM_10_EI_EVENERGY_OFFER_SE                                  (uint16)571U
#define EXI_ISO_20_CM_10_EI_EVENERGY_OFFER_CT                                  (uint16)572U
#define EXI_ISO_20_CM_10_EI_EVENERGY_OFFER_EE                                  (uint16)573U
#define EXI_ISO_20_CM_10_EI_EVENERGY_OFFER_AT                                  (uint16)574U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE                                     (uint16)575U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_SE                                  (uint16)576U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_CT                                  (uint16)577U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_EE                                  (uint16)578U
#define EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_AT                                  (uint16)579U
#define EXI_ISO_20_CM_10_EI_SELECTED_SERVICE                                   (uint16)580U
#define EXI_ISO_20_CM_10_EI_SELECTED_SERVICE_SE                                (uint16)581U
#define EXI_ISO_20_CM_10_EI_SELECTED_SERVICE_CT                                (uint16)582U
#define EXI_ISO_20_CM_10_EI_SELECTED_SERVICE_EE                                (uint16)583U
#define EXI_ISO_20_CM_10_EI_SELECTED_SERVICE_AT                                (uint16)584U
#define EXI_ISO_20_CM_10_EI_SERVICE_ID                                         (uint16)585U
#define EXI_ISO_20_CM_10_EI_SERVICE_ID_SE                                      (uint16)586U
#define EXI_ISO_20_CM_10_EI_SERVICE_ID_CT                                      (uint16)587U
#define EXI_ISO_20_CM_10_EI_SERVICE_ID_EE                                      (uint16)588U
#define EXI_ISO_20_CM_10_EI_SERVICE_ID_AT                                      (uint16)589U
#define EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_REQ                                 (uint16)590U
#define EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_REQ_SE                              (uint16)591U
#define EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_REQ_CT                              (uint16)592U
#define EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_REQ_EE                              (uint16)593U
#define EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_REQ_AT                              (uint16)594U
#define EXI_ISO_20_CM_10_EI_SERVICE_PARAMETER_LIST                             (uint16)595U
#define EXI_ISO_20_CM_10_EI_SERVICE_PARAMETER_LIST_SE                          (uint16)596U
#define EXI_ISO_20_CM_10_EI_SERVICE_PARAMETER_LIST_CT                          (uint16)597U
#define EXI_ISO_20_CM_10_EI_SERVICE_PARAMETER_LIST_EE                          (uint16)598U
#define EXI_ISO_20_CM_10_EI_SERVICE_PARAMETER_LIST_AT                          (uint16)599U
#define EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_RES                                 (uint16)600U
#define EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_RES_SE                              (uint16)601U
#define EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_RES_CT                              (uint16)602U
#define EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_RES_EE                              (uint16)603U
#define EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_RES_AT                              (uint16)604U
#define EXI_ISO_20_CM_10_EI_SUPPORTED_SERVICE_IDS                              (uint16)605U
#define EXI_ISO_20_CM_10_EI_SUPPORTED_SERVICE_IDS_SE                           (uint16)606U
#define EXI_ISO_20_CM_10_EI_SUPPORTED_SERVICE_IDS_CT                           (uint16)607U
#define EXI_ISO_20_CM_10_EI_SUPPORTED_SERVICE_IDS_EE                           (uint16)608U
#define EXI_ISO_20_CM_10_EI_SUPPORTED_SERVICE_IDS_AT                           (uint16)609U
#define EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_REQ                              (uint16)610U
#define EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_REQ_SE                           (uint16)611U
#define EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_REQ_CT                           (uint16)612U
#define EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_REQ_EE                           (uint16)613U
#define EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_REQ_AT                           (uint16)614U
#define EXI_ISO_20_CM_10_EI_SERVICE_RENEGOTIATION_SUPPORTED                    (uint16)615U
#define EXI_ISO_20_CM_10_EI_SERVICE_RENEGOTIATION_SUPPORTED_SE                 (uint16)616U
#define EXI_ISO_20_CM_10_EI_SERVICE_RENEGOTIATION_SUPPORTED_CT                 (uint16)617U
#define EXI_ISO_20_CM_10_EI_SERVICE_RENEGOTIATION_SUPPORTED_EE                 (uint16)618U
#define EXI_ISO_20_CM_10_EI_SERVICE_RENEGOTIATION_SUPPORTED_AT                 (uint16)619U
#define EXI_ISO_20_CM_10_EI_ENERGY_TRANSFER_SERVICE_LIST                       (uint16)620U
#define EXI_ISO_20_CM_10_EI_ENERGY_TRANSFER_SERVICE_LIST_SE                    (uint16)621U
#define EXI_ISO_20_CM_10_EI_ENERGY_TRANSFER_SERVICE_LIST_CT                    (uint16)622U
#define EXI_ISO_20_CM_10_EI_ENERGY_TRANSFER_SERVICE_LIST_EE                    (uint16)623U
#define EXI_ISO_20_CM_10_EI_ENERGY_TRANSFER_SERVICE_LIST_AT                    (uint16)624U
#define EXI_ISO_20_CM_10_EI_VASLIST                                            (uint16)625U
#define EXI_ISO_20_CM_10_EI_VASLIST_SE                                         (uint16)626U
#define EXI_ISO_20_CM_10_EI_VASLIST_CT                                         (uint16)627U
#define EXI_ISO_20_CM_10_EI_VASLIST_EE                                         (uint16)628U
#define EXI_ISO_20_CM_10_EI_VASLIST_AT                                         (uint16)629U
#define EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_RES                              (uint16)630U
#define EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_RES_SE                           (uint16)631U
#define EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_RES_CT                           (uint16)632U
#define EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_RES_EE                           (uint16)633U
#define EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_RES_AT                           (uint16)634U
#define EXI_ISO_20_CM_10_EI_SERVICE                                            (uint16)635U
#define EXI_ISO_20_CM_10_EI_SERVICE_SE                                         (uint16)636U
#define EXI_ISO_20_CM_10_EI_SERVICE_CT                                         (uint16)637U
#define EXI_ISO_20_CM_10_EI_SERVICE_EE                                         (uint16)638U
#define EXI_ISO_20_CM_10_EI_SERVICE_AT                                         (uint16)639U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SET                                      (uint16)640U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SET_SE                                   (uint16)641U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SET_CT                                   (uint16)642U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SET_EE                                   (uint16)643U
#define EXI_ISO_20_CM_10_EI_PARAMETER_SET_AT                                   (uint16)644U
#define EXI_ISO_20_CM_10_EI_SELECTED_ENERGY_TRANSFER_SERVICE                   (uint16)645U
#define EXI_ISO_20_CM_10_EI_SELECTED_ENERGY_TRANSFER_SERVICE_SE                (uint16)646U
#define EXI_ISO_20_CM_10_EI_SELECTED_ENERGY_TRANSFER_SERVICE_CT                (uint16)647U
#define EXI_ISO_20_CM_10_EI_SELECTED_ENERGY_TRANSFER_SERVICE_EE                (uint16)648U
#define EXI_ISO_20_CM_10_EI_SELECTED_ENERGY_TRANSFER_SERVICE_AT                (uint16)649U
#define EXI_ISO_20_CM_10_EI_SELECTED_VASLIST                                   (uint16)650U
#define EXI_ISO_20_CM_10_EI_SELECTED_VASLIST_SE                                (uint16)651U
#define EXI_ISO_20_CM_10_EI_SELECTED_VASLIST_CT                                (uint16)652U
#define EXI_ISO_20_CM_10_EI_SELECTED_VASLIST_EE                                (uint16)653U
#define EXI_ISO_20_CM_10_EI_SELECTED_VASLIST_AT                                (uint16)654U
#define EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_REQ                              (uint16)655U
#define EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_REQ_SE                           (uint16)656U
#define EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_REQ_CT                           (uint16)657U
#define EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_REQ_EE                           (uint16)658U
#define EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_REQ_AT                           (uint16)659U
#define EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_RES                              (uint16)660U
#define EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_RES_SE                           (uint16)661U
#define EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_RES_CT                           (uint16)662U
#define EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_RES_EE                           (uint16)663U
#define EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_RES_AT                           (uint16)664U
#define EXI_ISO_20_CM_10_EI_FREE_SERVICE                                       (uint16)665U
#define EXI_ISO_20_CM_10_EI_FREE_SERVICE_SE                                    (uint16)666U
#define EXI_ISO_20_CM_10_EI_FREE_SERVICE_CT                                    (uint16)667U
#define EXI_ISO_20_CM_10_EI_FREE_SERVICE_EE                                    (uint16)668U
#define EXI_ISO_20_CM_10_EI_FREE_SERVICE_AT                                    (uint16)669U
#define EXI_ISO_20_CM_10_EI_EVCCID                                             (uint16)670U
#define EXI_ISO_20_CM_10_EI_EVCCID_SE                                          (uint16)671U
#define EXI_ISO_20_CM_10_EI_EVCCID_CT                                          (uint16)672U
#define EXI_ISO_20_CM_10_EI_EVCCID_EE                                          (uint16)673U
#define EXI_ISO_20_CM_10_EI_EVCCID_AT                                          (uint16)674U
#define EXI_ISO_20_CM_10_EI_SESSION_SETUP_REQ                                  (uint16)675U
#define EXI_ISO_20_CM_10_EI_SESSION_SETUP_REQ_SE                               (uint16)676U
#define EXI_ISO_20_CM_10_EI_SESSION_SETUP_REQ_CT                               (uint16)677U
#define EXI_ISO_20_CM_10_EI_SESSION_SETUP_REQ_EE                               (uint16)678U
#define EXI_ISO_20_CM_10_EI_SESSION_SETUP_REQ_AT                               (uint16)679U
#define EXI_ISO_20_CM_10_EI_EVSEID                                             (uint16)680U
#define EXI_ISO_20_CM_10_EI_EVSEID_SE                                          (uint16)681U
#define EXI_ISO_20_CM_10_EI_EVSEID_CT                                          (uint16)682U
#define EXI_ISO_20_CM_10_EI_EVSEID_EE                                          (uint16)683U
#define EXI_ISO_20_CM_10_EI_EVSEID_AT                                          (uint16)684U
#define EXI_ISO_20_CM_10_EI_SESSION_SETUP_RES                                  (uint16)685U
#define EXI_ISO_20_CM_10_EI_SESSION_SETUP_RES_SE                               (uint16)686U
#define EXI_ISO_20_CM_10_EI_SESSION_SETUP_RES_CT                               (uint16)687U
#define EXI_ISO_20_CM_10_EI_SESSION_SETUP_RES_EE                               (uint16)688U
#define EXI_ISO_20_CM_10_EI_SESSION_SETUP_RES_AT                               (uint16)689U
#define EXI_ISO_20_CM_10_EI_CHARGING_SESSION                                   (uint16)690U
#define EXI_ISO_20_CM_10_EI_CHARGING_SESSION_SE                                (uint16)691U
#define EXI_ISO_20_CM_10_EI_CHARGING_SESSION_CT                                (uint16)692U
#define EXI_ISO_20_CM_10_EI_CHARGING_SESSION_EE                                (uint16)693U
#define EXI_ISO_20_CM_10_EI_CHARGING_SESSION_AT                                (uint16)694U
#define EXI_ISO_20_CM_10_EI_EVTERMINATION_CODE                                 (uint16)695U
#define EXI_ISO_20_CM_10_EI_EVTERMINATION_CODE_SE                              (uint16)696U
#define EXI_ISO_20_CM_10_EI_EVTERMINATION_CODE_CT                              (uint16)697U
#define EXI_ISO_20_CM_10_EI_EVTERMINATION_CODE_EE                              (uint16)698U
#define EXI_ISO_20_CM_10_EI_EVTERMINATION_CODE_AT                              (uint16)699U
#define EXI_ISO_20_CM_10_EI_EVTERMINATION_EXPLANATION                          (uint16)700U
#define EXI_ISO_20_CM_10_EI_EVTERMINATION_EXPLANATION_SE                       (uint16)701U
#define EXI_ISO_20_CM_10_EI_EVTERMINATION_EXPLANATION_CT                       (uint16)702U
#define EXI_ISO_20_CM_10_EI_EVTERMINATION_EXPLANATION_EE                       (uint16)703U
#define EXI_ISO_20_CM_10_EI_EVTERMINATION_EXPLANATION_AT                       (uint16)704U
#define EXI_ISO_20_CM_10_EI_SESSION_STOP_REQ                                   (uint16)705U
#define EXI_ISO_20_CM_10_EI_SESSION_STOP_REQ_SE                                (uint16)706U
#define EXI_ISO_20_CM_10_EI_SESSION_STOP_REQ_CT                                (uint16)707U
#define EXI_ISO_20_CM_10_EI_SESSION_STOP_REQ_EE                                (uint16)708U
#define EXI_ISO_20_CM_10_EI_SESSION_STOP_REQ_AT                                (uint16)709U
#define EXI_ISO_20_CM_10_EI_SESSION_STOP_RES                                   (uint16)710U
#define EXI_ISO_20_CM_10_EI_SESSION_STOP_RES_SE                                (uint16)711U
#define EXI_ISO_20_CM_10_EI_SESSION_STOP_RES_CT                                (uint16)712U
#define EXI_ISO_20_CM_10_EI_SESSION_STOP_RES_EE                                (uint16)713U
#define EXI_ISO_20_CM_10_EI_SESSION_STOP_RES_AT                                (uint16)714U
#define EXI_ISO_20_CM_10_EI_ECDHCURVE                                          (uint16)715U
#define EXI_ISO_20_CM_10_EI_ECDHCURVE_SE                                       (uint16)716U
#define EXI_ISO_20_CM_10_EI_ECDHCURVE_CT                                       (uint16)717U
#define EXI_ISO_20_CM_10_EI_ECDHCURVE_EE                                       (uint16)718U
#define EXI_ISO_20_CM_10_EI_ECDHCURVE_AT                                       (uint16)719U
#define EXI_ISO_20_CM_10_EI_DHPUBLIC_KEY                                       (uint16)720U
#define EXI_ISO_20_CM_10_EI_DHPUBLIC_KEY_SE                                    (uint16)721U
#define EXI_ISO_20_CM_10_EI_DHPUBLIC_KEY_CT                                    (uint16)722U
#define EXI_ISO_20_CM_10_EI_DHPUBLIC_KEY_EE                                    (uint16)723U
#define EXI_ISO_20_CM_10_EI_DHPUBLIC_KEY_AT                                    (uint16)724U
#define EXI_ISO_20_CM_10_EI_SESSION_ID                                         (uint16)725U
#define EXI_ISO_20_CM_10_EI_SESSION_ID_SE                                      (uint16)726U
#define EXI_ISO_20_CM_10_EI_SESSION_ID_CT                                      (uint16)727U
#define EXI_ISO_20_CM_10_EI_SESSION_ID_EE                                      (uint16)728U
#define EXI_ISO_20_CM_10_EI_SESSION_ID_AT                                      (uint16)729U
#define EXI_ISO_20_CM_10_EI_METER_INFO                                         (uint16)730U
#define EXI_ISO_20_CM_10_EI_METER_INFO_SE                                      (uint16)731U
#define EXI_ISO_20_CM_10_EI_METER_INFO_CT                                      (uint16)732U
#define EXI_ISO_20_CM_10_EI_METER_INFO_EE                                      (uint16)733U
#define EXI_ISO_20_CM_10_EI_METER_INFO_AT                                      (uint16)734U
#define EXI_ISO_20_CM_10_EI_RECEIPT                                            (uint16)735U
#define EXI_ISO_20_CM_10_EI_RECEIPT_SE                                         (uint16)736U
#define EXI_ISO_20_CM_10_EI_RECEIPT_CT                                         (uint16)737U
#define EXI_ISO_20_CM_10_EI_RECEIPT_EE                                         (uint16)738U
#define EXI_ISO_20_CM_10_EI_RECEIPT_AT                                         (uint16)739U
#define EXI_ISO_20_CM_10_EI_PROVIDER_ID                                        (uint16)740U
#define EXI_ISO_20_CM_10_EI_PROVIDER_ID_SE                                     (uint16)741U
#define EXI_ISO_20_CM_10_EI_PROVIDER_ID_CT                                     (uint16)742U
#define EXI_ISO_20_CM_10_EI_PROVIDER_ID_EE                                     (uint16)743U
#define EXI_ISO_20_CM_10_EI_PROVIDER_ID_AT                                     (uint16)744U
#define EXI_ISO_20_CM_10_EI_TARGET_OFFSET_X                                    (uint16)745U
#define EXI_ISO_20_CM_10_EI_TARGET_OFFSET_X_SE                                 (uint16)746U
#define EXI_ISO_20_CM_10_EI_TARGET_OFFSET_X_CT                                 (uint16)747U
#define EXI_ISO_20_CM_10_EI_TARGET_OFFSET_X_EE                                 (uint16)748U
#define EXI_ISO_20_CM_10_EI_TARGET_OFFSET_X_AT                                 (uint16)749U
#define EXI_ISO_20_CM_10_EI_TARGET_OFFSET_Y                                    (uint16)750U
#define EXI_ISO_20_CM_10_EI_TARGET_OFFSET_Y_SE                                 (uint16)751U
#define EXI_ISO_20_CM_10_EI_TARGET_OFFSET_Y_CT                                 (uint16)752U
#define EXI_ISO_20_CM_10_EI_TARGET_OFFSET_Y_EE                                 (uint16)753U
#define EXI_ISO_20_CM_10_EI_TARGET_OFFSET_Y_AT                                 (uint16)754U
#define EXI_ISO_20_CM_10_EI_TAX_RULE                                           (uint16)755U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_SE                                        (uint16)756U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_CT                                        (uint16)757U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_EE                                        (uint16)758U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_AT                                        (uint16)759U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_ID                                        (uint16)760U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_ID_SE                                     (uint16)761U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_ID_CT                                     (uint16)762U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_ID_EE                                     (uint16)763U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_ID_AT                                     (uint16)764U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_NAME                                      (uint16)765U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_NAME_SE                                   (uint16)766U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_NAME_CT                                   (uint16)767U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_NAME_EE                                   (uint16)768U
#define EXI_ISO_20_CM_10_EI_TAX_RULE_NAME_AT                                   (uint16)769U
#define EXI_ISO_20_CM_10_EI_TAX_RATE                                           (uint16)770U
#define EXI_ISO_20_CM_10_EI_TAX_RATE_SE                                        (uint16)771U
#define EXI_ISO_20_CM_10_EI_TAX_RATE_CT                                        (uint16)772U
#define EXI_ISO_20_CM_10_EI_TAX_RATE_EE                                        (uint16)773U
#define EXI_ISO_20_CM_10_EI_TAX_RATE_AT                                        (uint16)774U
#define EXI_ISO_20_CM_10_EI_TAX_INCLUDED_IN_PRICE                              (uint16)775U
#define EXI_ISO_20_CM_10_EI_TAX_INCLUDED_IN_PRICE_SE                           (uint16)776U
#define EXI_ISO_20_CM_10_EI_TAX_INCLUDED_IN_PRICE_CT                           (uint16)777U
#define EXI_ISO_20_CM_10_EI_TAX_INCLUDED_IN_PRICE_EE                           (uint16)778U
#define EXI_ISO_20_CM_10_EI_TAX_INCLUDED_IN_PRICE_AT                           (uint16)779U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_ENERGY_FEE                              (uint16)780U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_ENERGY_FEE_SE                           (uint16)781U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_ENERGY_FEE_CT                           (uint16)782U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_ENERGY_FEE_EE                           (uint16)783U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_ENERGY_FEE_AT                           (uint16)784U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_PARKING_FEE                             (uint16)785U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_PARKING_FEE_SE                          (uint16)786U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_PARKING_FEE_CT                          (uint16)787U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_PARKING_FEE_EE                          (uint16)788U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_PARKING_FEE_AT                          (uint16)789U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_OVERSTAY_FEE                            (uint16)790U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_OVERSTAY_FEE_SE                         (uint16)791U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_OVERSTAY_FEE_CT                         (uint16)792U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_OVERSTAY_FEE_EE                         (uint16)793U
#define EXI_ISO_20_CM_10_EI_APPLIES_TO_OVERSTAY_FEE_AT                         (uint16)794U
#define EXI_ISO_20_CM_10_EI_APPLIES_MINIMUM_MAXIMUM_COST                       (uint16)795U
#define EXI_ISO_20_CM_10_EI_APPLIES_MINIMUM_MAXIMUM_COST_SE                    (uint16)796U
#define EXI_ISO_20_CM_10_EI_APPLIES_MINIMUM_MAXIMUM_COST_CT                    (uint16)797U
#define EXI_ISO_20_CM_10_EI_APPLIES_MINIMUM_MAXIMUM_COST_EE                    (uint16)798U
#define EXI_ISO_20_CM_10_EI_APPLIES_MINIMUM_MAXIMUM_COST_AT                    (uint16)799U
#define EXI_ISO_20_CM_10_EI_EVCHECK_IN_STATUS                                  (uint16)800U
#define EXI_ISO_20_CM_10_EI_EVCHECK_IN_STATUS_SE                               (uint16)801U
#define EXI_ISO_20_CM_10_EI_EVCHECK_IN_STATUS_CT                               (uint16)802U
#define EXI_ISO_20_CM_10_EI_EVCHECK_IN_STATUS_EE                               (uint16)803U
#define EXI_ISO_20_CM_10_EI_EVCHECK_IN_STATUS_AT                               (uint16)804U
#define EXI_ISO_20_CM_10_EI_PARKING_METHOD                                     (uint16)805U
#define EXI_ISO_20_CM_10_EI_PARKING_METHOD_SE                                  (uint16)806U
#define EXI_ISO_20_CM_10_EI_PARKING_METHOD_CT                                  (uint16)807U
#define EXI_ISO_20_CM_10_EI_PARKING_METHOD_EE                                  (uint16)808U
#define EXI_ISO_20_CM_10_EI_PARKING_METHOD_AT                                  (uint16)809U
#define EXI_ISO_20_CM_10_EI_VEHICLE_FRAME                                      (uint16)810U
#define EXI_ISO_20_CM_10_EI_VEHICLE_FRAME_SE                                   (uint16)811U
#define EXI_ISO_20_CM_10_EI_VEHICLE_FRAME_CT                                   (uint16)812U
#define EXI_ISO_20_CM_10_EI_VEHICLE_FRAME_EE                                   (uint16)813U
#define EXI_ISO_20_CM_10_EI_VEHICLE_FRAME_AT                                   (uint16)814U
#define EXI_ISO_20_CM_10_EI_DEVICE_OFFSET                                      (uint16)815U
#define EXI_ISO_20_CM_10_EI_DEVICE_OFFSET_SE                                   (uint16)816U
#define EXI_ISO_20_CM_10_EI_DEVICE_OFFSET_CT                                   (uint16)817U
#define EXI_ISO_20_CM_10_EI_DEVICE_OFFSET_EE                                   (uint16)818U
#define EXI_ISO_20_CM_10_EI_DEVICE_OFFSET_AT                                   (uint16)819U
#define EXI_ISO_20_CM_10_EI_VEHICLE_TRAVEL                                     (uint16)820U
#define EXI_ISO_20_CM_10_EI_VEHICLE_TRAVEL_SE                                  (uint16)821U
#define EXI_ISO_20_CM_10_EI_VEHICLE_TRAVEL_CT                                  (uint16)822U
#define EXI_ISO_20_CM_10_EI_VEHICLE_TRAVEL_EE                                  (uint16)823U
#define EXI_ISO_20_CM_10_EI_VEHICLE_TRAVEL_AT                                  (uint16)824U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_REQ                               (uint16)825U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_REQ_SE                            (uint16)826U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_REQ_CT                            (uint16)827U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_REQ_EE                            (uint16)828U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_REQ_AT                            (uint16)829U
#define EXI_ISO_20_CM_10_EI_PARKING_SPACE                                      (uint16)830U
#define EXI_ISO_20_CM_10_EI_PARKING_SPACE_SE                                   (uint16)831U
#define EXI_ISO_20_CM_10_EI_PARKING_SPACE_CT                                   (uint16)832U
#define EXI_ISO_20_CM_10_EI_PARKING_SPACE_EE                                   (uint16)833U
#define EXI_ISO_20_CM_10_EI_PARKING_SPACE_AT                                   (uint16)834U
#define EXI_ISO_20_CM_10_EI_DEVICE_LOCATION                                    (uint16)835U
#define EXI_ISO_20_CM_10_EI_DEVICE_LOCATION_SE                                 (uint16)836U
#define EXI_ISO_20_CM_10_EI_DEVICE_LOCATION_CT                                 (uint16)837U
#define EXI_ISO_20_CM_10_EI_DEVICE_LOCATION_EE                                 (uint16)838U
#define EXI_ISO_20_CM_10_EI_DEVICE_LOCATION_AT                                 (uint16)839U
#define EXI_ISO_20_CM_10_EI_TARGET_DISTANCE                                    (uint16)840U
#define EXI_ISO_20_CM_10_EI_TARGET_DISTANCE_SE                                 (uint16)841U
#define EXI_ISO_20_CM_10_EI_TARGET_DISTANCE_CT                                 (uint16)842U
#define EXI_ISO_20_CM_10_EI_TARGET_DISTANCE_EE                                 (uint16)843U
#define EXI_ISO_20_CM_10_EI_TARGET_DISTANCE_AT                                 (uint16)844U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_RES                               (uint16)845U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_RES_SE                            (uint16)846U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_RES_CT                            (uint16)847U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_RES_EE                            (uint16)848U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_RES_AT                            (uint16)849U
#define EXI_ISO_20_CM_10_EI_EVCHECK_OUT_STATUS                                 (uint16)850U
#define EXI_ISO_20_CM_10_EI_EVCHECK_OUT_STATUS_SE                              (uint16)851U
#define EXI_ISO_20_CM_10_EI_EVCHECK_OUT_STATUS_CT                              (uint16)852U
#define EXI_ISO_20_CM_10_EI_EVCHECK_OUT_STATUS_EE                              (uint16)853U
#define EXI_ISO_20_CM_10_EI_EVCHECK_OUT_STATUS_AT                              (uint16)854U
#define EXI_ISO_20_CM_10_EI_CHECK_OUT_TIME                                     (uint16)855U
#define EXI_ISO_20_CM_10_EI_CHECK_OUT_TIME_SE                                  (uint16)856U
#define EXI_ISO_20_CM_10_EI_CHECK_OUT_TIME_CT                                  (uint16)857U
#define EXI_ISO_20_CM_10_EI_CHECK_OUT_TIME_EE                                  (uint16)858U
#define EXI_ISO_20_CM_10_EI_CHECK_OUT_TIME_AT                                  (uint16)859U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_REQ                              (uint16)860U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_REQ_SE                           (uint16)861U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_REQ_CT                           (uint16)862U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_REQ_EE                           (uint16)863U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_REQ_AT                           (uint16)864U
#define EXI_ISO_20_CM_10_EI_EVSECHECK_OUT_STATUS                               (uint16)865U
#define EXI_ISO_20_CM_10_EI_EVSECHECK_OUT_STATUS_SE                            (uint16)866U
#define EXI_ISO_20_CM_10_EI_EVSECHECK_OUT_STATUS_CT                            (uint16)867U
#define EXI_ISO_20_CM_10_EI_EVSECHECK_OUT_STATUS_EE                            (uint16)868U
#define EXI_ISO_20_CM_10_EI_EVSECHECK_OUT_STATUS_AT                            (uint16)869U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_RES                              (uint16)870U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_RES_SE                           (uint16)871U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_RES_CT                           (uint16)872U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_RES_EE                           (uint16)873U
#define EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_RES_AT                           (uint16)874U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION                                      (uint16)875U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_SE                                   (uint16)876U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_CT                                   (uint16)877U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_EE                                   (uint16)878U
#define EXI_ISO_20_CM_10_EI_AUTHORIZATION_AT                                   (uint16)879U
#define EXI_ISO_20_CM_10_EI_CHANNEL_SELECTION                                  (uint16)880U
#define EXI_ISO_20_CM_10_EI_CHANNEL_SELECTION_SE                               (uint16)881U
#define EXI_ISO_20_CM_10_EI_CHANNEL_SELECTION_CT                               (uint16)882U
#define EXI_ISO_20_CM_10_EI_CHANNEL_SELECTION_EE                               (uint16)883U
#define EXI_ISO_20_CM_10_EI_CHANNEL_SELECTION_AT                               (uint16)884U
#define EXI_ISO_20_CM_10_EI_DH_PUBLIC_KEY                                      (uint16)885U
#define EXI_ISO_20_CM_10_EI_DH_PUBLIC_KEY_SE                                   (uint16)886U
#define EXI_ISO_20_CM_10_EI_DH_PUBLIC_KEY_CT                                   (uint16)887U
#define EXI_ISO_20_CM_10_EI_DH_PUBLIC_KEY_EE                                   (uint16)888U
#define EXI_ISO_20_CM_10_EI_DH_PUBLIC_KEY_AT                                   (uint16)889U
#define EXI_ISO_20_CM_10_EI_ECDH_CURVE                                         (uint16)890U
#define EXI_ISO_20_CM_10_EI_ECDH_CURVE_SE                                      (uint16)891U
#define EXI_ISO_20_CM_10_EI_ECDH_CURVE_CT                                      (uint16)892U
#define EXI_ISO_20_CM_10_EI_ECDH_CURVE_EE                                      (uint16)893U
#define EXI_ISO_20_CM_10_EI_ECDH_CURVE_AT                                      (uint16)894U
#define EXI_ISO_20_CM_10_EI_EV_CHECK_IN_STATUS                                 (uint16)895U
#define EXI_ISO_20_CM_10_EI_EV_CHECK_IN_STATUS_SE                              (uint16)896U
#define EXI_ISO_20_CM_10_EI_EV_CHECK_IN_STATUS_CT                              (uint16)897U
#define EXI_ISO_20_CM_10_EI_EV_CHECK_IN_STATUS_EE                              (uint16)898U
#define EXI_ISO_20_CM_10_EI_EV_CHECK_IN_STATUS_AT                              (uint16)899U
#define EXI_ISO_20_CM_10_EI_EV_CHECK_OUT_STATUS                                (uint16)900U
#define EXI_ISO_20_CM_10_EI_EV_CHECK_OUT_STATUS_SE                             (uint16)901U
#define EXI_ISO_20_CM_10_EI_EV_CHECK_OUT_STATUS_CT                             (uint16)902U
#define EXI_ISO_20_CM_10_EI_EV_CHECK_OUT_STATUS_EE                             (uint16)903U
#define EXI_ISO_20_CM_10_EI_EV_CHECK_OUT_STATUS_AT                             (uint16)904U
#define EXI_ISO_20_CM_10_EI_EVSE_CHECK_OUT_STATUS                              (uint16)905U
#define EXI_ISO_20_CM_10_EI_EVSE_CHECK_OUT_STATUS_SE                           (uint16)906U
#define EXI_ISO_20_CM_10_EI_EVSE_CHECK_OUT_STATUS_CT                           (uint16)907U
#define EXI_ISO_20_CM_10_EI_EVSE_CHECK_OUT_STATUS_EE                           (uint16)908U
#define EXI_ISO_20_CM_10_EI_EVSE_CHECK_OUT_STATUS_AT                           (uint16)909U
#define EXI_ISO_20_CM_10_EI_SECP521_ENCRYPTED_PRIVATE_KEY                      (uint16)910U
#define EXI_ISO_20_CM_10_EI_SECP521_ENCRYPTED_PRIVATE_KEY_SE                   (uint16)911U
#define EXI_ISO_20_CM_10_EI_SECP521_ENCRYPTED_PRIVATE_KEY_CT                   (uint16)912U
#define EXI_ISO_20_CM_10_EI_SECP521_ENCRYPTED_PRIVATE_KEY_EE                   (uint16)913U
#define EXI_ISO_20_CM_10_EI_SECP521_ENCRYPTED_PRIVATE_KEY_AT                   (uint16)914U
#define EXI_ISO_20_CM_10_EI_TPM_ENCRYPTED_PRIVATE_KEY                          (uint16)915U
#define EXI_ISO_20_CM_10_EI_TPM_ENCRYPTED_PRIVATE_KEY_SE                       (uint16)916U
#define EXI_ISO_20_CM_10_EI_TPM_ENCRYPTED_PRIVATE_KEY_CT                       (uint16)917U
#define EXI_ISO_20_CM_10_EI_TPM_ENCRYPTED_PRIVATE_KEY_EE                       (uint16)918U
#define EXI_ISO_20_CM_10_EI_TPM_ENCRYPTED_PRIVATE_KEY_AT                       (uint16)919U
#define EXI_ISO_20_CM_10_EI_X448_ENCRYPTED_PRIVATE_KEY                         (uint16)920U
#define EXI_ISO_20_CM_10_EI_X448_ENCRYPTED_PRIVATE_KEY_SE                      (uint16)921U
#define EXI_ISO_20_CM_10_EI_X448_ENCRYPTED_PRIVATE_KEY_CT                      (uint16)922U
#define EXI_ISO_20_CM_10_EI_X448_ENCRYPTED_PRIVATE_KEY_EE                      (uint16)923U
#define EXI_ISO_20_CM_10_EI_X448_ENCRYPTED_PRIVATE_KEY_AT                      (uint16)924U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  EXI_ISO_20_CM_10_AUTHORIZATION_TYPE_EIM = 0u,
  EXI_ISO_20_CM_10_AUTHORIZATION_TYPE_PN_C = 1u
} Exi_ISO_20_CM_10_authorizationType;

typedef enum
{
  EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE_START = 0u,
  EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE_STOP = 1u,
  EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE_STANDBY = 2u,
  EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE_SCHEDULE_RENEGOTIATION = 3u
} Exi_ISO_20_CM_10_chargeProgressType;

typedef enum
{
  EXI_ISO_20_CM_10_CHANNEL_SELECTION_TYPE_CHARGE = 0u,
  EXI_ISO_20_CM_10_CHANNEL_SELECTION_TYPE_DISCHARGE = 1u
} Exi_ISO_20_CM_10_channelSelectionType;

typedef enum
{
  EXI_ISO_20_CM_10_ECDH_CURVE_TYPE_SECP521 = 0u,
  EXI_ISO_20_CM_10_ECDH_CURVE_TYPE_X448 = 1u
} Exi_ISO_20_CM_10_ecdhCurveType;

typedef enum
{
  EXI_ISO_20_CM_10_CHARGING_SESSION_TYPE_PAUSE = 0u,
  EXI_ISO_20_CM_10_CHARGING_SESSION_TYPE_TERMINATE = 1u,
  EXI_ISO_20_CM_10_CHARGING_SESSION_TYPE_SERVICE_RENEGOTIATION = 2u
} Exi_ISO_20_CM_10_chargingSessionType;

typedef enum
{
  EXI_ISO_20_CM_10_EV_CHECK_IN_STATUS_TYPE_CHECK_IN = 0u,
  EXI_ISO_20_CM_10_EV_CHECK_IN_STATUS_TYPE_PROCESSING = 1u,
  EXI_ISO_20_CM_10_EV_CHECK_IN_STATUS_TYPE_COMPLETED = 2u
} Exi_ISO_20_CM_10_evCheckInStatusType;

typedef enum
{
  EXI_ISO_20_CM_10_EV_CHECK_OUT_STATUS_TYPE_CHECK_OUT = 0u,
  EXI_ISO_20_CM_10_EV_CHECK_OUT_STATUS_TYPE_PROCESSING = 1u,
  EXI_ISO_20_CM_10_EV_CHECK_OUT_STATUS_TYPE_COMPLETED = 2u
} Exi_ISO_20_CM_10_evCheckOutStatusType;

typedef enum
{
  EXI_ISO_20_CM_10_EVSE_CHECK_OUT_STATUS_TYPE_SCHEDULED = 0u,
  EXI_ISO_20_CM_10_EVSE_CHECK_OUT_STATUS_TYPE_COMPLETED = 1u
} Exi_ISO_20_CM_10_evseCheckOutStatusType;

typedef enum
{
  EXI_ISO_20_CM_10_PARKING_METHOD_TYPE_AUTO_PARKING = 0u,
  EXI_ISO_20_CM_10_PARKING_METHOD_TYPE_MVGUIDE_MANUAL = 1u,
  EXI_ISO_20_CM_10_PARKING_METHOD_TYPE_MANUAL = 2u
} Exi_ISO_20_CM_10_parkingMethodType;

typedef enum
{
  EXI_ISO_20_CM_10_POWER_TOLERANCE_ACCEPTANCE_TYPE_POWER_TOLERANCE_NOT_CONFIRMED = 0u,
  EXI_ISO_20_CM_10_POWER_TOLERANCE_ACCEPTANCE_TYPE_POWER_TOLERANCE_CONFIRMED = 1u
} Exi_ISO_20_CM_10_powerToleranceAcceptanceType;

typedef struct Exi_ISO_20_CM_10_genChallengeType Exi_ISO_20_CM_10_genChallengeType;
struct Exi_ISO_20_CM_10_genChallengeType
{
  uint16 Length;
  uint8 Buffer[16];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_20_CM_10_dhPublicKeyType Exi_ISO_20_CM_10_dhPublicKeyType;
struct Exi_ISO_20_CM_10_dhPublicKeyType
{
  uint16 Length;
  uint8 Buffer[133];
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

typedef struct Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType;
struct Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType
{
  uint16 Length;
  uint8 Buffer[94];
};

typedef struct Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType;
struct Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType
{
  uint16 Length;
  uint8 Buffer[84];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType;
struct Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType
{
  uint16 Length;
  uint8 Buffer[206];
};

typedef struct Exi_ISO_20_CM_10_currencyType Exi_ISO_20_CM_10_currencyType;
struct Exi_ISO_20_CM_10_currencyType
{
  uint16 Length;
  uint8 Buffer[3];
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

typedef struct Exi_ISO_20_CM_10_languageType Exi_ISO_20_CM_10_languageType;
struct Exi_ISO_20_CM_10_languageType
{
  uint16 Length;
  uint8 Buffer[3];
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

typedef struct Exi_ISO_20_CM_10_certificateType Exi_ISO_20_CM_10_certificateType;
struct Exi_ISO_20_CM_10_certificateType
{
  struct Exi_ISO_20_CM_10_certificateType* NextCertificatePtr;
  uint16 Length;
  uint8 Buffer[1600];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_20_CM_10_AttributeIdType Exi_ISO_20_CM_10_AttributeIdType;
struct Exi_ISO_20_CM_10_AttributeIdType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_ISO_20_CM_10_ATTRIBUTEID];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_ISO_20_CM_10_ATTRIBUTEID ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_ISO_20_CM_10_ATTRIBUTEID ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_ISO_20_CM_10_ATTRIBUTEID ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType;

typedef struct Exi_ISO_20_CM_10_AuthorizationReqChoiceType Exi_ISO_20_CM_10_AuthorizationReqChoiceType;

typedef struct Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType;

typedef struct Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType;

typedef struct Exi_ISO_20_CM_10_SignedInstallationDataChoiceType Exi_ISO_20_CM_10_SignedInstallationDataChoiceType;

typedef struct Exi_ISO_20_CM_10_SignedMeteringDataChoiceType Exi_ISO_20_CM_10_SignedMeteringDataChoiceType;

typedef struct Exi_ISO_20_CM_10_ParameterChoiceType Exi_ISO_20_CM_10_ParameterChoiceType;

typedef struct Exi_ISO_20_CM_10_ChargingScheduleChoiceType Exi_ISO_20_CM_10_ChargingScheduleChoiceType;

typedef struct Exi_ISO_20_CM_10_Dynamic_SEResControlModeChoiceType Exi_ISO_20_CM_10_Dynamic_SEResControlModeChoiceType;

typedef struct Exi_ISO_20_CM_10_EVPowerProfileChoiceType Exi_ISO_20_CM_10_EVPowerProfileChoiceType;

typedef struct Exi_ISO_20_CM_10_SessionSetupReqType Exi_ISO_20_CM_10_SessionSetupReqType;

typedef struct Exi_ISO_20_CM_10_SessionSetupResType Exi_ISO_20_CM_10_SessionSetupResType;

typedef struct Exi_ISO_20_CM_10_AuthorizationSetupReqType Exi_ISO_20_CM_10_AuthorizationSetupReqType;

typedef struct Exi_ISO_20_CM_10_AuthorizationSetupResType Exi_ISO_20_CM_10_AuthorizationSetupResType;

typedef struct Exi_ISO_20_CM_10_AuthorizationReqType Exi_ISO_20_CM_10_AuthorizationReqType;

typedef struct Exi_ISO_20_CM_10_AuthorizationResType Exi_ISO_20_CM_10_AuthorizationResType;

typedef struct Exi_ISO_20_CM_10_ServiceDiscoveryReqType Exi_ISO_20_CM_10_ServiceDiscoveryReqType;

typedef struct Exi_ISO_20_CM_10_ServiceDiscoveryResType Exi_ISO_20_CM_10_ServiceDiscoveryResType;

typedef struct Exi_ISO_20_CM_10_ServiceDetailReqType Exi_ISO_20_CM_10_ServiceDetailReqType;

typedef struct Exi_ISO_20_CM_10_ServiceDetailResType Exi_ISO_20_CM_10_ServiceDetailResType;

typedef struct Exi_ISO_20_CM_10_ServiceSelectionReqType Exi_ISO_20_CM_10_ServiceSelectionReqType;

typedef struct Exi_ISO_20_CM_10_ServiceSelectionResType Exi_ISO_20_CM_10_ServiceSelectionResType;

typedef struct Exi_ISO_20_CM_10_ScheduleExchangeReqType Exi_ISO_20_CM_10_ScheduleExchangeReqType;

typedef struct Exi_ISO_20_CM_10_ScheduleExchangeResType Exi_ISO_20_CM_10_ScheduleExchangeResType;

typedef struct Exi_ISO_20_CM_10_PowerDeliveryReqType Exi_ISO_20_CM_10_PowerDeliveryReqType;

typedef struct Exi_ISO_20_CM_10_PowerDeliveryResType Exi_ISO_20_CM_10_PowerDeliveryResType;

typedef struct Exi_ISO_20_CM_10_MeteringConfirmationReqType Exi_ISO_20_CM_10_MeteringConfirmationReqType;

typedef struct Exi_ISO_20_CM_10_MeteringConfirmationResType Exi_ISO_20_CM_10_MeteringConfirmationResType;

typedef struct Exi_ISO_20_CM_10_SessionStopReqType Exi_ISO_20_CM_10_SessionStopReqType;

typedef struct Exi_ISO_20_CM_10_SessionStopResType Exi_ISO_20_CM_10_SessionStopResType;

typedef struct Exi_ISO_20_CM_10_CertificateInstallationReqType Exi_ISO_20_CM_10_CertificateInstallationReqType;

typedef struct Exi_ISO_20_CM_10_CertificateInstallationResType Exi_ISO_20_CM_10_CertificateInstallationResType;

typedef struct Exi_ISO_20_CM_10_VehicleCheckInReqType Exi_ISO_20_CM_10_VehicleCheckInReqType;

typedef struct Exi_ISO_20_CM_10_VehicleCheckInResType Exi_ISO_20_CM_10_VehicleCheckInResType;

typedef struct Exi_ISO_20_CM_10_VehicleCheckOutReqType Exi_ISO_20_CM_10_VehicleCheckOutReqType;

typedef struct Exi_ISO_20_CM_10_VehicleCheckOutResType Exi_ISO_20_CM_10_VehicleCheckOutResType;

typedef struct Exi_ISO_20_CM_10_SubCertificatesType Exi_ISO_20_CM_10_SubCertificatesType;

typedef struct Exi_ISO_20_CM_10_ContractCertificateChainType Exi_ISO_20_CM_10_ContractCertificateChainType;

typedef struct Exi_ISO_20_CM_10_SignedInstallationDataType Exi_ISO_20_CM_10_SignedInstallationDataType;

typedef void Exi_ISO_20_CM_10_Dynamic_SMDTControlModeType;

typedef struct Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType;

typedef struct Exi_ISO_20_CM_10_SignedMeteringDataType Exi_ISO_20_CM_10_SignedMeteringDataType;

typedef struct Exi_ISO_20_CM_10_SupportedProvidersListType Exi_ISO_20_CM_10_SupportedProvidersListType;

typedef struct Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType;

typedef void Exi_ISO_20_CM_10_EIM_ASResAuthorizationModeType;

typedef struct Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType;

typedef void Exi_ISO_20_CM_10_EIM_AReqAuthorizationModeType;

typedef struct Exi_ISO_20_CM_10_ServiceIDListType Exi_ISO_20_CM_10_ServiceIDListType;

typedef struct Exi_ISO_20_CM_10_ServiceType Exi_ISO_20_CM_10_ServiceType;

typedef struct Exi_ISO_20_CM_10_ServiceListType Exi_ISO_20_CM_10_ServiceListType;

typedef struct Exi_ISO_20_CM_10_SelectedServiceType Exi_ISO_20_CM_10_SelectedServiceType;

typedef struct Exi_ISO_20_CM_10_SelectedServiceListType Exi_ISO_20_CM_10_SelectedServiceListType;

typedef struct Exi_ISO_20_CM_10_ParameterType Exi_ISO_20_CM_10_ParameterType;

typedef struct Exi_ISO_20_CM_10_ParameterSetType Exi_ISO_20_CM_10_ParameterSetType;

typedef struct Exi_ISO_20_CM_10_ServiceParameterListType Exi_ISO_20_CM_10_ServiceParameterListType;

typedef struct Exi_ISO_20_CM_10_PowerScheduleEntryType Exi_ISO_20_CM_10_PowerScheduleEntryType;

typedef struct Exi_ISO_20_CM_10_PowerScheduleEntryListType Exi_ISO_20_CM_10_PowerScheduleEntryListType;

typedef struct Exi_ISO_20_CM_10_PowerScheduleType Exi_ISO_20_CM_10_PowerScheduleType;

typedef struct Exi_ISO_20_CM_10_TaxRuleType Exi_ISO_20_CM_10_TaxRuleType;

typedef struct Exi_ISO_20_CM_10_TaxRuleListType Exi_ISO_20_CM_10_TaxRuleListType;

typedef struct Exi_ISO_20_CM_10_PriceRuleType Exi_ISO_20_CM_10_PriceRuleType;

typedef struct Exi_ISO_20_CM_10_PriceRuleStackType Exi_ISO_20_CM_10_PriceRuleStackType;

typedef struct Exi_ISO_20_CM_10_PriceRuleStackListType Exi_ISO_20_CM_10_PriceRuleStackListType;

typedef struct Exi_ISO_20_CM_10_OverstayRuleType Exi_ISO_20_CM_10_OverstayRuleType;

typedef struct Exi_ISO_20_CM_10_OverstayRuleListType Exi_ISO_20_CM_10_OverstayRuleListType;

typedef struct Exi_ISO_20_CM_10_AdditionalServiceType Exi_ISO_20_CM_10_AdditionalServiceType;

typedef struct Exi_ISO_20_CM_10_AdditionalServiceListType Exi_ISO_20_CM_10_AdditionalServiceListType;

typedef struct Exi_ISO_20_CM_10_AbsolutePriceScheduleType Exi_ISO_20_CM_10_AbsolutePriceScheduleType;

typedef struct Exi_ISO_20_CM_10_PriceLevelScheduleEntryType Exi_ISO_20_CM_10_PriceLevelScheduleEntryType;

typedef struct Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType;

typedef struct Exi_ISO_20_CM_10_PriceLevelScheduleType Exi_ISO_20_CM_10_PriceLevelScheduleType;

typedef struct Exi_ISO_20_CM_10_ChargingScheduleType Exi_ISO_20_CM_10_ChargingScheduleType;

typedef struct Exi_ISO_20_CM_10_ScheduleTupleType Exi_ISO_20_CM_10_ScheduleTupleType;

typedef struct Exi_ISO_20_CM_10_EVPowerScheduleEntryType Exi_ISO_20_CM_10_EVPowerScheduleEntryType;

typedef struct Exi_ISO_20_CM_10_EVPowerScheduleEntryListType Exi_ISO_20_CM_10_EVPowerScheduleEntryListType;

typedef struct Exi_ISO_20_CM_10_EVPowerScheduleType Exi_ISO_20_CM_10_EVPowerScheduleType;

typedef struct Exi_ISO_20_CM_10_EVPriceRuleType Exi_ISO_20_CM_10_EVPriceRuleType;

typedef struct Exi_ISO_20_CM_10_EVPriceRuleStackType Exi_ISO_20_CM_10_EVPriceRuleStackType;

typedef struct Exi_ISO_20_CM_10_EVPriceRuleStackListType Exi_ISO_20_CM_10_EVPriceRuleStackListType;

typedef struct Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType;

typedef struct Exi_ISO_20_CM_10_EVEnergyOfferType Exi_ISO_20_CM_10_EVEnergyOfferType;

typedef struct Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType;

typedef struct Exi_ISO_20_CM_10_Scheduled_SEResControlModeType Exi_ISO_20_CM_10_Scheduled_SEResControlModeType;

typedef struct Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType;

typedef struct Exi_ISO_20_CM_10_Dynamic_SEResControlModeType Exi_ISO_20_CM_10_Dynamic_SEResControlModeType;

typedef struct Exi_ISO_20_CM_10_TargetPositionType Exi_ISO_20_CM_10_TargetPositionType;

typedef struct Exi_ISO_20_CM_10_PriceScheduleType Exi_ISO_20_CM_10_PriceScheduleType;

typedef struct Exi_ISO_20_CM_10_EVPowerProfileEntryListType Exi_ISO_20_CM_10_EVPowerProfileEntryListType;

typedef void Exi_ISO_20_CM_10_Dynamic_EVPPTControlModeType;

typedef struct Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType;

typedef struct Exi_ISO_20_CM_10_EVPowerProfileType Exi_ISO_20_CM_10_EVPowerProfileType;

typedef struct Exi_ISO_20_CM_10_EMAIDListType Exi_ISO_20_CM_10_EMAIDListType;

typedef struct Exi_ISO_20_CM_10_CertificateChainType Exi_ISO_20_CM_10_CertificateChainType;

typedef struct Exi_ISO_20_CM_10_SignedCertificateChainType Exi_ISO_20_CM_10_SignedCertificateChainType;

struct Exi_ISO_20_CM_10_SessionSetupReqType
{
  Exi_ISO_20_CT_10_identifierType* EVCCID;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
};

struct Exi_ISO_20_CM_10_SessionSetupResType
{
  Exi_ISO_20_CT_10_identifierType* EVSEID;
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

struct Exi_ISO_20_CM_10_AuthorizationSetupReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
};

struct Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType
{
  union
  {
    Exi_ISO_20_CM_10_EIM_ASResAuthorizationModeType* EIM_ASResAuthorizationMode;
    Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType* PnC_ASResAuthorizationMode;
  } ChoiceValue;
  Exi_BitType EIM_ASResAuthorizationModeFlag : 1;
  Exi_BitType PnC_ASResAuthorizationModeFlag : 1;
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

struct Exi_ISO_20_CM_10_AuthorizationSetupResType
{
  Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType* ChoiceElement;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_authorizationType AuthorizationServices[2];
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  boolean CertificateInstallationService;
  uint8 AuthorizationServicesCount;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_CM_10_AuthorizationReqChoiceType
{
  union
  {
    Exi_ISO_20_CM_10_EIM_AReqAuthorizationModeType* EIM_AReqAuthorizationMode;
    Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType* PnC_AReqAuthorizationMode;
  } ChoiceValue;
  Exi_BitType EIM_AReqAuthorizationModeFlag : 1;
  Exi_BitType PnC_AReqAuthorizationModeFlag : 1;
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

struct Exi_ISO_20_CM_10_AuthorizationReqType
{
  Exi_ISO_20_CM_10_AuthorizationReqChoiceType* ChoiceElement;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_authorizationType SelectedAuthorizationService; /* Value range: 0 to 1; See type for exact values. */
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

struct Exi_ISO_20_CM_10_AuthorizationResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_processingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
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

struct Exi_ISO_20_CM_10_ServiceDiscoveryReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_ServiceIDListType* SupportedServiceIDs;
  Exi_BitType SupportedServiceIDsFlag : 1;
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

struct Exi_ISO_20_CM_10_ServiceDiscoveryResType
{
  Exi_ISO_20_CM_10_ServiceListType* EnergyTransferServiceList;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_ServiceListType* VASList;
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  boolean ServiceRenegotiationSupported;
  Exi_BitType VASListFlag : 1;
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

struct Exi_ISO_20_CM_10_ServiceDetailReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  uint16 ServiceID;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_CM_10_ServiceDetailResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_ServiceParameterListType* ServiceParameterList;
  uint16 ServiceID;
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
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

struct Exi_ISO_20_CM_10_ServiceSelectionReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_SelectedServiceType* SelectedEnergyTransferService;
  Exi_ISO_20_CM_10_SelectedServiceListType* SelectedVASList;
  Exi_BitType SelectedVASListFlag : 1;
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

struct Exi_ISO_20_CM_10_ServiceSelectionResType
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

struct Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType
{
  union
  {
    Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType* Dynamic_SEReqControlMode;
    Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType* Scheduled_SEReqControlMode;
  } ChoiceValue;
  Exi_BitType Dynamic_SEReqControlModeFlag : 1;
  Exi_BitType Scheduled_SEReqControlModeFlag : 1;
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

struct Exi_ISO_20_CM_10_ScheduleExchangeReqType
{
  Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType* ChoiceElement;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  uint16 MaximumSupportingPoints; /* Value range: min: 12 max: 1024 */
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType
{
  union
  {
    Exi_ISO_20_CM_10_Dynamic_SEResControlModeType* Dynamic_SEResControlMode;
    Exi_ISO_20_CM_10_Scheduled_SEResControlModeType* Scheduled_SEResControlMode;
  } ChoiceValue;
  Exi_BitType Dynamic_SEResControlModeFlag : 1;
  Exi_BitType Scheduled_SEResControlModeFlag : 1;
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

struct Exi_ISO_20_CM_10_ScheduleExchangeResType
{
  Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType* ChoiceElement;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_processingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  boolean GoToPause;
  Exi_BitType GoToPauseFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_CM_10_PowerDeliveryReqType
{
  Exi_ISO_20_CM_10_EVPowerProfileType* EVPowerProfile;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_channelSelectionType BPT_ChannelSelection; /* Value range: 0 to 1; See type for exact values. */
  Exi_ISO_20_CM_10_chargeProgressType ChargeProgress; /* Value range: 0 to 3; See type for exact values. */
  Exi_ISO_20_CT_10_processingType EVProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_BitType BPT_ChannelSelectionFlag : 1;
  Exi_BitType EVPowerProfileFlag : 1;
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

struct Exi_ISO_20_CM_10_PowerDeliveryResType
{
  Exi_ISO_20_CT_10_EVSEStatusType* EVSEStatus;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  Exi_BitType EVSEStatusFlag : 1;
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

struct Exi_ISO_20_CM_10_MeteringConfirmationReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_SignedMeteringDataType* SignedMeteringData;
};

struct Exi_ISO_20_CM_10_MeteringConfirmationResType
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

struct Exi_ISO_20_CM_10_SessionStopReqType
{
  Exi_ISO_20_CT_10_nameType* EVTerminationCode;
  Exi_ISO_20_CT_10_descriptionType* EVTerminationExplanation;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_chargingSessionType ChargingSession; /* Value range: 0 to 2; See type for exact values. */
  Exi_BitType EVTerminationCodeFlag : 1;
  Exi_BitType EVTerminationExplanationFlag : 1;
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

struct Exi_ISO_20_CM_10_SessionStopResType
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

struct Exi_ISO_20_CM_10_CertificateInstallationReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_ListOfRootCertificateIDsType* ListOfRootCertificateIDs;
  Exi_ISO_20_CM_10_SignedCertificateChainType* OEMProvisioningCertificateChain;
  Exi_ISO_20_CM_10_EMAIDListType* PrioritizedEMAIDs;
  uint8 MaximumContractCertificateChains;
  Exi_BitType PrioritizedEMAIDsFlag : 1;
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

struct Exi_ISO_20_CM_10_CertificateInstallationResType
{
  Exi_ISO_20_CM_10_CertificateChainType* CPSCertificateChain;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_SignedInstallationDataType* SignedInstallationData;
  Exi_ISO_20_CT_10_processingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  uint8 RemainingContractCertificateChains;
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

struct Exi_ISO_20_CM_10_VehicleCheckInReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  sint16 DeviceOffset;
  sint16 VehicleFrame;
  sint16 VehicleTravel;
  Exi_ISO_20_CM_10_evCheckInStatusType EVCheckInStatus; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CM_10_parkingMethodType ParkingMethod; /* Value range: 0 to 2; See type for exact values. */
  Exi_BitType DeviceOffsetFlag : 1;
  Exi_BitType VehicleFrameFlag : 1;
  Exi_BitType VehicleTravelFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_CM_10_VehicleCheckInResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  sint16 DeviceLocation;
  sint16 ParkingSpace;
  sint16 TargetDistance;
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  Exi_BitType DeviceLocationFlag : 1;
  Exi_BitType ParkingSpaceFlag : 1;
  Exi_BitType TargetDistanceFlag : 1;
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

struct Exi_ISO_20_CM_10_VehicleCheckOutReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_UInt64 CheckOutTime;
  Exi_ISO_20_CM_10_evCheckOutStatusType EVCheckOutStatus; /* Value range: 0 to 2; See type for exact values. */
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

struct Exi_ISO_20_CM_10_VehicleCheckOutResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CM_10_evseCheckOutStatusType EVSECheckOutStatus; /* Value range: 0 to 1; See type for exact values. */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
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

struct Exi_ISO_20_CM_10_SubCertificatesType
{
  Exi_ISO_20_CM_10_certificateType* Certificate;
};

struct Exi_ISO_20_CM_10_ContractCertificateChainType
{
  Exi_ISO_20_CM_10_certificateType* Certificate;
  Exi_ISO_20_CM_10_SubCertificatesType* SubCertificates;
};

struct Exi_ISO_20_CM_10_SignedInstallationDataChoiceType
{
  union
  {
    Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType* SECP521_EncryptedPrivateKey;
    Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType* TPM_EncryptedPrivateKey;
    Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType* X448_EncryptedPrivateKey;
  } ChoiceValue;
  Exi_BitType SECP521_EncryptedPrivateKeyFlag : 1;
  Exi_BitType TPM_EncryptedPrivateKeyFlag : 1;
  Exi_BitType X448_EncryptedPrivateKeyFlag : 1;
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

struct Exi_ISO_20_CM_10_SignedInstallationDataType
{
  Exi_ISO_20_CM_10_SignedInstallationDataChoiceType* ChoiceElement;
  Exi_ISO_20_CM_10_ContractCertificateChainType* ContractCertificateChain;
  Exi_ISO_20_CM_10_dhPublicKeyType* DHPublicKey;
  Exi_ISO_20_CM_10_AttributeIdType* Id;
  Exi_ISO_20_CM_10_ecdhCurveType ECDHCurve; /* Value range: 0 to 1; See type for exact values. */
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

struct Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType
{
  uint32 SelectedScheduleTupleID; /* Value range: min: 1 max: 4294967295 */
};

struct Exi_ISO_20_CM_10_SignedMeteringDataChoiceType
{
  union
  {
    Exi_ISO_20_CM_10_Dynamic_SMDTControlModeType* Dynamic_SMDTControlMode;
    Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType* Scheduled_SMDTControlMode;
  } ChoiceValue;
  Exi_BitType Dynamic_SMDTControlModeFlag : 1;
  Exi_BitType Scheduled_SMDTControlModeFlag : 1;
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

struct Exi_ISO_20_CM_10_SignedMeteringDataType
{
  Exi_ISO_20_CM_10_SignedMeteringDataChoiceType* ChoiceElement;
  Exi_ISO_20_CM_10_AttributeIdType* Id;
  Exi_ISO_20_CT_10_MeterInfoType* MeterInfo;
  Exi_ISO_20_CT_10_ReceiptType* Receipt;
  Exi_ISO_20_CT_10_sessionIDType* SessionID;
  Exi_BitType ReceiptFlag : 1;
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

struct Exi_ISO_20_CM_10_SupportedProvidersListType
{
  Exi_ISO_20_CT_10_nameType* ProviderID;
};

struct Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType
{
  Exi_ISO_20_CM_10_genChallengeType* GenChallenge;
  Exi_ISO_20_CM_10_SupportedProvidersListType* SupportedProviders;
  Exi_BitType SupportedProvidersFlag : 1;
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

struct Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType
{
  Exi_ISO_20_CM_10_ContractCertificateChainType* ContractCertificateChain;
  Exi_ISO_20_CM_10_genChallengeType* GenChallenge;
  Exi_ISO_20_CM_10_AttributeIdType* Id;
};

struct Exi_ISO_20_CM_10_ServiceIDListType
{
  uint16 ServiceID[16];
  uint8 ServiceIDCount;
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

struct Exi_ISO_20_CM_10_ServiceType
{
  struct Exi_ISO_20_CM_10_ServiceType* NextServicePtr;
  uint16 ServiceID;
  boolean FreeService;
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

struct Exi_ISO_20_CM_10_ServiceListType
{
  Exi_ISO_20_CM_10_ServiceType* Service;
};

struct Exi_ISO_20_CM_10_SelectedServiceType
{
  struct Exi_ISO_20_CM_10_SelectedServiceType* NextSelectedServicePtr;
  uint16 ParameterSetID;
  uint16 ServiceID;
};

struct Exi_ISO_20_CM_10_SelectedServiceListType
{
  Exi_ISO_20_CM_10_SelectedServiceType* SelectedService;
};

struct Exi_ISO_20_CM_10_ParameterChoiceType
{
  union
  {
    Exi_ISO_20_CT_10_nameType* finiteString;
    Exi_ISO_20_CT_10_RationalNumberType* rationalNumber;
    sint32 intValue;
    sint16 shortValue;
    boolean boolValue;
    sint8 byteValue;
  } ChoiceValue;
  Exi_BitType finiteStringFlag : 1;
  Exi_BitType rationalNumberFlag : 1;
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

struct Exi_ISO_20_CM_10_ParameterType
{
  Exi_ISO_20_CM_10_ParameterChoiceType* ChoiceElement;
  Exi_ISO_20_CT_10_AttributenameType* Name;
  struct Exi_ISO_20_CM_10_ParameterType* NextParameterPtr;
};

struct Exi_ISO_20_CM_10_ParameterSetType
{
  struct Exi_ISO_20_CM_10_ParameterSetType* NextParameterSetPtr;
  Exi_ISO_20_CM_10_ParameterType* Parameter;
  uint16 ParameterSetID;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_CM_10_ServiceParameterListType
{
  Exi_ISO_20_CM_10_ParameterSetType* ParameterSet;
};

struct Exi_ISO_20_CM_10_PowerScheduleEntryType
{
  struct Exi_ISO_20_CM_10_PowerScheduleEntryType* NextEVPowerProfileEntryPtr;
  struct Exi_ISO_20_CM_10_PowerScheduleEntryType* NextPowerScheduleEntryPtr;
  Exi_ISO_20_CT_10_RationalNumberType* Power;
  Exi_ISO_20_CT_10_RationalNumberType* Power_L2;
  Exi_ISO_20_CT_10_RationalNumberType* Power_L3;
  uint32 Duration;
  Exi_BitType Power_L2Flag : 1;
  Exi_BitType Power_L3Flag : 1;
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

struct Exi_ISO_20_CM_10_PowerScheduleEntryListType
{
  Exi_ISO_20_CM_10_PowerScheduleEntryType* PowerScheduleEntry;
};

struct Exi_ISO_20_CM_10_PowerScheduleType
{
  Exi_ISO_20_CT_10_RationalNumberType* AvailableEnergy;
  Exi_ISO_20_CM_10_PowerScheduleEntryListType* PowerScheduleEntries;
  Exi_ISO_20_CT_10_RationalNumberType* PowerTolerance;
  Exi_UInt64 TimeAnchor;
  Exi_BitType AvailableEnergyFlag : 1;
  Exi_BitType PowerToleranceFlag : 1;
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

struct Exi_ISO_20_CM_10_TaxRuleType
{
  struct Exi_ISO_20_CM_10_TaxRuleType* NextTaxRulePtr;
  Exi_ISO_20_CT_10_RationalNumberType* TaxRate;
  Exi_ISO_20_CT_10_nameType* TaxRuleName;
  uint32 TaxRuleID; /* Value range: min: 1 max: 4294967295 */
  boolean AppliesMinimumMaximumCost;
  boolean AppliesToEnergyFee;
  boolean AppliesToOverstayFee;
  boolean AppliesToParkingFee;
  boolean TaxIncludedInPrice;
  Exi_BitType TaxIncludedInPriceFlag : 1;
  Exi_BitType TaxRuleNameFlag : 1;
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

struct Exi_ISO_20_CM_10_TaxRuleListType
{
  Exi_ISO_20_CM_10_TaxRuleType* TaxRule;
};

struct Exi_ISO_20_CM_10_PriceRuleType
{
  Exi_ISO_20_CT_10_RationalNumberType* EnergyFee;
  struct Exi_ISO_20_CM_10_PriceRuleType* NextPriceRulePtr;
  Exi_ISO_20_CT_10_RationalNumberType* ParkingFee;
  Exi_ISO_20_CT_10_RationalNumberType* PowerRangeStart;
  uint32 ParkingFeePeriod;
  uint16 CarbonDioxideEmission;
  uint8 RenewableGenerationPercentage;
  Exi_BitType CarbonDioxideEmissionFlag : 1;
  Exi_BitType ParkingFeeFlag : 1;
  Exi_BitType ParkingFeePeriodFlag : 1;
  Exi_BitType RenewableGenerationPercentageFlag : 1;
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

struct Exi_ISO_20_CM_10_PriceRuleStackType
{
  struct Exi_ISO_20_CM_10_PriceRuleStackType* NextPriceRuleStackPtr;
  Exi_ISO_20_CM_10_PriceRuleType* PriceRule;
  uint32 Duration;
};

struct Exi_ISO_20_CM_10_PriceRuleStackListType
{
  Exi_ISO_20_CM_10_PriceRuleStackType* PriceRuleStack;
};

struct Exi_ISO_20_CM_10_OverstayRuleType
{
  struct Exi_ISO_20_CM_10_OverstayRuleType* NextOverstayRulePtr;
  Exi_ISO_20_CT_10_RationalNumberType* OverstayFee;
  Exi_ISO_20_CT_10_descriptionType* OverstayRuleDescription;
  uint32 OverstayFeePeriod;
  uint32 StartTime;
  Exi_BitType OverstayRuleDescriptionFlag : 1;
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

struct Exi_ISO_20_CM_10_OverstayRuleListType
{
  Exi_ISO_20_CT_10_RationalNumberType* OverstayPowerThreshold;
  Exi_ISO_20_CM_10_OverstayRuleType* OverstayRule;
  uint32 OverstayTimeThreshold;
  Exi_BitType OverstayPowerThresholdFlag : 1;
  Exi_BitType OverstayTimeThresholdFlag : 1;
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

struct Exi_ISO_20_CM_10_AdditionalServiceType
{
  struct Exi_ISO_20_CM_10_AdditionalServiceType* NextAdditionalServicePtr;
  Exi_ISO_20_CT_10_RationalNumberType* ServiceFee;
  Exi_ISO_20_CT_10_nameType* ServiceName;
};

struct Exi_ISO_20_CM_10_AdditionalServiceListType
{
  Exi_ISO_20_CM_10_AdditionalServiceType* AdditionalService;
};

struct Exi_ISO_20_CM_10_AbsolutePriceScheduleType
{
  Exi_ISO_20_CM_10_AdditionalServiceListType* AdditionalSelectedServices;
  Exi_ISO_20_CM_10_currencyType* Currency;
  Exi_ISO_20_CM_10_AttributeIdType* Id;
  Exi_ISO_20_CM_10_languageType* Language;
  Exi_ISO_20_CT_10_RationalNumberType* MaximumCost;
  Exi_ISO_20_CT_10_RationalNumberType* MinimumCost;
  Exi_ISO_20_CM_10_OverstayRuleListType* OverstayRules;
  Exi_ISO_20_CT_10_identifierType* PriceAlgorithm;
  Exi_ISO_20_CM_10_PriceRuleStackListType* PriceRuleStacks;
  Exi_ISO_20_CT_10_descriptionType* PriceScheduleDescription;
  Exi_ISO_20_CM_10_TaxRuleListType* TaxRules;
  Exi_UInt64 TimeAnchor;
  uint32 PriceScheduleID; /* Value range: min: 1 max: 4294967295 */
  Exi_BitType AdditionalSelectedServicesFlag : 1;
  Exi_BitType IdFlag : 1;
  Exi_BitType MaximumCostFlag : 1;
  Exi_BitType MinimumCostFlag : 1;
  Exi_BitType OverstayRulesFlag : 1;
  Exi_BitType PriceScheduleDescriptionFlag : 1;
  Exi_BitType TaxRulesFlag : 1;
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

struct Exi_ISO_20_CM_10_PriceLevelScheduleEntryType
{
  struct Exi_ISO_20_CM_10_PriceLevelScheduleEntryType* NextPriceLevelScheduleEntryPtr;
  uint32 Duration;
  uint8 PriceLevel;
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

struct Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType
{
  Exi_ISO_20_CM_10_PriceLevelScheduleEntryType* PriceLevelScheduleEntry;
};

struct Exi_ISO_20_CM_10_PriceLevelScheduleType
{
  Exi_ISO_20_CM_10_AttributeIdType* Id;
  Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType* PriceLevelScheduleEntries;
  Exi_ISO_20_CT_10_descriptionType* PriceScheduleDescription;
  Exi_UInt64 TimeAnchor;
  uint32 PriceScheduleID; /* Value range: min: 1 max: 4294967295 */
  uint8 NumberOfPriceLevels;
  Exi_BitType IdFlag : 1;
  Exi_BitType PriceScheduleDescriptionFlag : 1;
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

struct Exi_ISO_20_CM_10_ChargingScheduleChoiceType
{
  union
  {
    Exi_ISO_20_CM_10_AbsolutePriceScheduleType* AbsolutePriceSchedule;
    Exi_ISO_20_CM_10_PriceLevelScheduleType* PriceLevelSchedule;
  } ChoiceValue;
  Exi_BitType AbsolutePriceScheduleFlag : 1;
  Exi_BitType PriceLevelScheduleFlag : 1;
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

struct Exi_ISO_20_CM_10_ChargingScheduleType
{
  Exi_ISO_20_CM_10_ChargingScheduleChoiceType* ChoiceElement;
  Exi_ISO_20_CM_10_PowerScheduleType* PowerSchedule;
  Exi_BitType ChoiceElementFlag : 1;
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

struct Exi_ISO_20_CM_10_ScheduleTupleType
{
  Exi_ISO_20_CM_10_ChargingScheduleType* ChargingSchedule;
  Exi_ISO_20_CM_10_ChargingScheduleType* DischargingSchedule;
  struct Exi_ISO_20_CM_10_ScheduleTupleType* NextScheduleTuplePtr;
  uint32 ScheduleTupleID; /* Value range: min: 1 max: 4294967295 */
  Exi_BitType DischargingScheduleFlag : 1;
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

struct Exi_ISO_20_CM_10_EVPowerScheduleEntryType
{
  struct Exi_ISO_20_CM_10_EVPowerScheduleEntryType* NextEVPowerScheduleEntryPtr;
  Exi_ISO_20_CT_10_RationalNumberType* Power;
  uint32 Duration;
};

struct Exi_ISO_20_CM_10_EVPowerScheduleEntryListType
{
  Exi_ISO_20_CM_10_EVPowerScheduleEntryType* EVPowerScheduleEntry;
};

struct Exi_ISO_20_CM_10_EVPowerScheduleType
{
  Exi_ISO_20_CM_10_EVPowerScheduleEntryListType* EVPowerScheduleEntries;
  Exi_UInt64 TimeAnchor;
};

struct Exi_ISO_20_CM_10_EVPriceRuleType
{
  Exi_ISO_20_CT_10_RationalNumberType* EnergyFee;
  struct Exi_ISO_20_CM_10_EVPriceRuleType* NextEVPriceRulePtr;
  Exi_ISO_20_CT_10_RationalNumberType* PowerRangeStart;
};

struct Exi_ISO_20_CM_10_EVPriceRuleStackType
{
  Exi_ISO_20_CM_10_EVPriceRuleType* EVPriceRule;
  struct Exi_ISO_20_CM_10_EVPriceRuleStackType* NextEVPriceRuleStackPtr;
  uint32 Duration;
};

struct Exi_ISO_20_CM_10_EVPriceRuleStackListType
{
  Exi_ISO_20_CM_10_EVPriceRuleStackType* EVPriceRuleStack;
};

struct Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType
{
  Exi_ISO_20_CM_10_currencyType* Currency;
  Exi_ISO_20_CM_10_EVPriceRuleStackListType* EVPriceRuleStacks;
  Exi_ISO_20_CT_10_identifierType* PriceAlgorithm;
  Exi_UInt64 TimeAnchor;
};

struct Exi_ISO_20_CM_10_EVEnergyOfferType
{
  Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType* EVAbsolutePriceSchedule;
  Exi_ISO_20_CM_10_EVPowerScheduleType* EVPowerSchedule;
};

struct Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType
{
  Exi_ISO_20_CM_10_EVEnergyOfferType* EVEnergyOffer;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVTargetEnergyRequest;
  uint32 DepartureTime;
  Exi_BitType DepartureTimeFlag : 1;
  Exi_BitType EVEnergyOfferFlag : 1;
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

struct Exi_ISO_20_CM_10_Scheduled_SEResControlModeType
{
  Exi_ISO_20_CM_10_ScheduleTupleType* ScheduleTuple;
};

struct Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumV2XEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumV2XEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVTargetEnergyRequest;
  uint32 DepartureTime;
  sint8 MinimumSOC; /* Value range: max: 100 */
  sint8 TargetSOC; /* Value range: max: 100 */
  Exi_BitType EVMaximumV2XEnergyRequestFlag : 1;
  Exi_BitType EVMinimumV2XEnergyRequestFlag : 1;
  Exi_BitType MinimumSOCFlag : 1;
  Exi_BitType TargetSOCFlag : 1;
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

struct Exi_ISO_20_CM_10_Dynamic_SEResControlModeChoiceType
{
  union
  {
    Exi_ISO_20_CM_10_AbsolutePriceScheduleType* AbsolutePriceSchedule;
    Exi_ISO_20_CM_10_PriceLevelScheduleType* PriceLevelSchedule;
  } ChoiceValue;
  Exi_BitType AbsolutePriceScheduleFlag : 1;
  Exi_BitType PriceLevelScheduleFlag : 1;
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

struct Exi_ISO_20_CM_10_Dynamic_SEResControlModeType
{
  Exi_ISO_20_CM_10_Dynamic_SEResControlModeChoiceType* ChoiceElement;
  uint32 DepartureTime;
  sint8 MinimumSOC; /* Value range: max: 100 */
  sint8 TargetSOC; /* Value range: max: 100 */
  Exi_BitType ChoiceElementFlag : 1;
  Exi_BitType DepartureTimeFlag : 1;
  Exi_BitType MinimumSOCFlag : 1;
  Exi_BitType TargetSOCFlag : 1;
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

struct Exi_ISO_20_CM_10_TargetPositionType
{
  uint16 TargetOffsetX;
  uint16 TargetOffsetY;
};

struct Exi_ISO_20_CM_10_PriceScheduleType
{
  Exi_ISO_20_CT_10_descriptionType* PriceScheduleDescription;
  Exi_UInt64 TimeAnchor;
  uint32 PriceScheduleID; /* Value range: min: 1 max: 4294967295 */
  Exi_BitType PriceScheduleDescriptionFlag : 1;
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

struct Exi_ISO_20_CM_10_EVPowerProfileEntryListType
{
  Exi_ISO_20_CM_10_PowerScheduleEntryType* EVPowerProfileEntry;
};

struct Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType
{
  uint32 SelectedScheduleTupleID; /* Value range: min: 1 max: 4294967295 */
  Exi_ISO_20_CM_10_powerToleranceAcceptanceType PowerToleranceAcceptance; /* Value range: 0 to 1; See type for exact values. */
  Exi_BitType PowerToleranceAcceptanceFlag : 1;
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

struct Exi_ISO_20_CM_10_EVPowerProfileChoiceType
{
  union
  {
    Exi_ISO_20_CM_10_Dynamic_EVPPTControlModeType* Dynamic_EVPPTControlMode;
    Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType* Scheduled_EVPPTControlMode;
  } ChoiceValue;
  Exi_BitType Dynamic_EVPPTControlModeFlag : 1;
  Exi_BitType Scheduled_EVPPTControlModeFlag : 1;
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

struct Exi_ISO_20_CM_10_EVPowerProfileType
{
  Exi_ISO_20_CM_10_EVPowerProfileChoiceType* ChoiceElement;
  Exi_ISO_20_CM_10_EVPowerProfileEntryListType* EVPowerProfileEntries;
  Exi_UInt64 TimeAnchor;
};

struct Exi_ISO_20_CM_10_EMAIDListType
{
  Exi_ISO_20_CT_10_identifierType* EMAID;
};

struct Exi_ISO_20_CM_10_CertificateChainType
{
  Exi_ISO_20_CM_10_certificateType* Certificate;
  Exi_ISO_20_CM_10_SubCertificatesType* SubCertificates;
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

struct Exi_ISO_20_CM_10_SignedCertificateChainType
{
  Exi_ISO_20_CM_10_certificateType* Certificate;
  Exi_ISO_20_CM_10_AttributeIdType* Id;
  Exi_ISO_20_CM_10_SubCertificatesType* SubCertificates;
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
#endif  /* EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET */

/* PRQA L:IDENTIFIER_NAMES */
/* PRQA L:NAMESPACE */
/* PRQA L:UNION */


#endif /* EXI_ISO_20_CM_10_SCHEMA_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_CM_10_SchemaTypes.h
 **********************************************************************************************************************/
