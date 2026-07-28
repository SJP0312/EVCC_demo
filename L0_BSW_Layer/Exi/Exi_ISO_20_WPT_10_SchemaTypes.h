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
/**        \file  Exi_ISO_20_WPT_10_SchemaTypes.h
 *        \brief  Efficient XML Interchange ISO_20_WPT_10 types header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_WPT_10 types.
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

#if !defined (EXI_ISO_20_WPT_10_SCHEMA_TYPES_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_WPT_10_SCHEMA_TYPES_H

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
#define EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_REQ_TYPE                                   (Exi_RootElementIdType)181U
#define EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_RES_TYPE                                   (Exi_RootElementIdType)182U
#define EXI_ISO_20_WPT_10_WPT_CHARGE_LOOP_REQ_TYPE                                       (Exi_RootElementIdType)183U
#define EXI_ISO_20_WPT_10_WPT_CHARGE_LOOP_RES_TYPE                                       (Exi_RootElementIdType)184U
#define EXI_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE                        (Exi_RootElementIdType)185U
#define EXI_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_RES_TYPE                        (Exi_RootElementIdType)186U
#define EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_REQ_TYPE                                  (Exi_RootElementIdType)187U
#define EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_RES_TYPE                                  (Exi_RootElementIdType)188U
#define EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_REQ_TYPE                            (Exi_RootElementIdType)189U
#define EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_RES_TYPE                            (Exi_RootElementIdType)190U
#define EXI_ISO_20_WPT_10_WPT_PAIRING_REQ_TYPE                                           (Exi_RootElementIdType)191U
#define EXI_ISO_20_WPT_10_WPT_PAIRING_RES_TYPE                                           (Exi_RootElementIdType)192U

#if (defined(EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* Elements */
#define EXI_ISO_20_WPT_10_ALTERNATIVE_SECC_TYPE                                          (Exi_RootElementIdType)803U
#define EXI_ISO_20_WPT_10_ALTERNATIVE_SECCLIST_TYPE                                      (Exi_RootElementIdType)804U
#define EXI_ISO_20_WPT_10_BSSID_TYPE                                                     (Exi_RootElementIdType)805U
#define EXI_ISO_20_WPT_10_COORD_X_TYPE                                                   (Exi_RootElementIdType)806U
#define EXI_ISO_20_WPT_10_COORD_Y_TYPE                                                   (Exi_RootElementIdType)807U
#define EXI_ISO_20_WPT_10_COORD_Z_TYPE                                                   (Exi_RootElementIdType)808U
#define EXI_ISO_20_WPT_10_EIRP_TYPE                                                      (Exi_RootElementIdType)809U
#define EXI_ISO_20_WPT_10_EVDEVICE_ALIGNMENT_CHECK_METHOD_LIST_TYPE                      (Exi_RootElementIdType)810U
#define EXI_ISO_20_WPT_10_EVDEVICE_FINE_POSITIONING_METHOD_LIST_TYPE                     (Exi_RootElementIdType)811U
#define EXI_ISO_20_WPT_10_EVDEVICE_PAIRING_METHOD_LIST_TYPE                              (Exi_RootElementIdType)812U
#define EXI_ISO_20_WPT_10_EVPCCHARGE_DIAGNOSTICS_TYPE                                    (Exi_RootElementIdType)813U
#define EXI_ISO_20_WPT_10_EVPCCOIL_CURRENT_INFORMATION_TYPE                              (Exi_RootElementIdType)814U
#define EXI_ISO_20_WPT_10_EVPCCOIL_CURRENT_REQUEST_TYPE                                  (Exi_RootElementIdType)815U
#define EXI_ISO_20_WPT_10_EVPCCURRENT_OUTPUT_INFORMATION_TYPE                            (Exi_RootElementIdType)816U
#define EXI_ISO_20_WPT_10_EVPCDEVICE_LOCAL_CONTROL_TYPE                                  (Exi_RootElementIdType)817U
#define EXI_ISO_20_WPT_10_EVPCMAX_RECEIVABLE_POWER_TYPE                                  (Exi_RootElementIdType)818U
#define EXI_ISO_20_WPT_10_EVPCNATURAL_FREQUENCY_TYPE                                     (Exi_RootElementIdType)819U
#define EXI_ISO_20_WPT_10_EVPCOPERATING_FREQUENCY_TYPE                                   (Exi_RootElementIdType)820U
#define EXI_ISO_20_WPT_10_EVPCPOWER_CONTROL_PARAMETER_TYPE                               (Exi_RootElementIdType)821U
#define EXI_ISO_20_WPT_10_EVPCPOWER_OUTPUT_TYPE                                          (Exi_RootElementIdType)822U
#define EXI_ISO_20_WPT_10_EVPCPOWER_REQUEST_TYPE                                         (Exi_RootElementIdType)823U
#define EXI_ISO_20_WPT_10_EVPCVOLTAGE_OUTPUT_INFORMATION_TYPE                            (Exi_RootElementIdType)824U
#define EXI_ISO_20_WPT_10_EVPROCESSING_TYPE                                              (Exi_RootElementIdType)825U
#define EXI_ISO_20_WPT_10_EVRESULT_CODE_TYPE                                             (Exi_RootElementIdType)826U
#define EXI_ISO_20_WPT_10_EVSEPROCESSING_TYPE                                            (Exi_RootElementIdType)827U
#define EXI_ISO_20_WPT_10_IPADDRESS_TYPE                                                 (Exi_RootElementIdType)828U
#define EXI_ISO_20_WPT_10_INDEX_NUMBER_TYPE                                              (Exi_RootElementIdType)829U
#define EXI_ISO_20_WPT_10_LF_RECEIVER_SETUP_DATA_TYPE                                    (Exi_RootElementIdType)830U
#define EXI_ISO_20_WPT_10_LF_RX_DATA_TYPE                                                (Exi_RootElementIdType)831U
#define EXI_ISO_20_WPT_10_LF_SYSTEM_SETUP_DATA_TYPE                                      (Exi_RootElementIdType)832U
#define EXI_ISO_20_WPT_10_LF_TRANSMITTER_SETUP_DATA_TYPE                                 (Exi_RootElementIdType)833U
#define EXI_ISO_20_WPT_10_LF_TX_DATA_TYPE                                                (Exi_RootElementIdType)834U
#define EXI_ISO_20_WPT_10_MANUFACTURER_SPECIFIC_DATA_CONTAINER_TYPE                      (Exi_RootElementIdType)835U
#define EXI_ISO_20_WPT_10_NATURAL_OFFSET_TYPE                                            (Exi_RootElementIdType)836U
#define EXI_ISO_20_WPT_10_NUM_PACKAGES_TYPE                                              (Exi_RootElementIdType)837U
#define EXI_ISO_20_WPT_10_NUMBER_OF_RECEIVERS_TYPE                                       (Exi_RootElementIdType)838U
#define EXI_ISO_20_WPT_10_NUMBER_OF_TRANSMITTERS_TYPE                                    (Exi_RootElementIdType)839U
#define EXI_ISO_20_WPT_10_OBSERVED_IDCODE_TYPE                                           (Exi_RootElementIdType)840U
#define EXI_ISO_20_WPT_10_PDINPUT_POWER_CLASS_TYPE                                       (Exi_RootElementIdType)841U
#define EXI_ISO_20_WPT_10_PDMAX_COIL_CURRENT_TYPE                                        (Exi_RootElementIdType)842U
#define EXI_ISO_20_WPT_10_PDMIN_COIL_CURRENT_TYPE                                        (Exi_RootElementIdType)843U
#define EXI_ISO_20_WPT_10_PACKAGE_INDEX_TYPE                                             (Exi_RootElementIdType)844U
#define EXI_ISO_20_WPT_10_PACKAGE_SEPARATION_TIME_TYPE                                   (Exi_RootElementIdType)845U
#define EXI_ISO_20_WPT_10_PORT_TYPE                                                      (Exi_RootElementIdType)846U
#define EXI_ISO_20_WPT_10_POWER_TRANSMITTED_TYPE                                         (Exi_RootElementIdType)847U
#define EXI_ISO_20_WPT_10_PRIMARY_DEVICE_ALIGNMENT_CHECK_METHOD_LIST_TYPE                (Exi_RootElementIdType)848U
#define EXI_ISO_20_WPT_10_PRIMARY_DEVICE_FINE_POSITIONING_METHOD_LIST_TYPE               (Exi_RootElementIdType)849U
#define EXI_ISO_20_WPT_10_PRIMARY_DEVICE_PAIRING_METHOD_LIST_TYPE                        (Exi_RootElementIdType)850U
#define EXI_ISO_20_WPT_10_PULSE_DURATION_TYPE                                            (Exi_RootElementIdType)851U
#define EXI_ISO_20_WPT_10_PULSE_SEPARATION_TIME_TYPE                                     (Exi_RootElementIdType)852U
#define EXI_ISO_20_WPT_10_PULSE_SEQUENCE_ORDER_TYPE                                      (Exi_RootElementIdType)853U
#define EXI_ISO_20_WPT_10_RSSI_TYPE                                                      (Exi_RootElementIdType)854U
#define EXI_ISO_20_WPT_10_RSSIDATA_TYPE                                                  (Exi_RootElementIdType)855U
#define EXI_ISO_20_WPT_10_RSSIDATA_LIST_TYPE                                             (Exi_RootElementIdType)856U
#define EXI_ISO_20_WPT_10_RX_IDENTIFIER_TYPE                                             (Exi_RootElementIdType)857U
#define EXI_ISO_20_WPT_10_RX_SPEC_DATA_TYPE                                              (Exi_RootElementIdType)858U
#define EXI_ISO_20_WPT_10_SDMANUFACTURER_SPECIFIC_DATA_CONTAINER_TYPE                    (Exi_RootElementIdType)859U
#define EXI_ISO_20_WPT_10_SDMAX_GROUND_CLEARANCE_SUPPORT_TYPE                            (Exi_RootElementIdType)860U
#define EXI_ISO_20_WPT_10_SDMAX_GROUND_CLEARENCE_TYPE                                    (Exi_RootElementIdType)861U
#define EXI_ISO_20_WPT_10_SDMAX_OUTPUT_POWER_TYPE                                        (Exi_RootElementIdType)862U
#define EXI_ISO_20_WPT_10_SDMIN_GROUND_CLEARANCE_SUPPORT_TYPE                            (Exi_RootElementIdType)863U
#define EXI_ISO_20_WPT_10_SDMIN_GROUND_CLEARENCE_TYPE                                    (Exi_RootElementIdType)864U
#define EXI_ISO_20_WPT_10_SDMIN_OUTPUT_POWER_TYPE                                        (Exi_RootElementIdType)865U
#define EXI_ISO_20_WPT_10_SDPOWER_INPUT_TYPE                                             (Exi_RootElementIdType)866U
#define EXI_ISO_20_WPT_10_SPCCHARGE_DIAGNOSTICS_TYPE                                     (Exi_RootElementIdType)867U
#define EXI_ISO_20_WPT_10_SPCMAX_OUTPUT_POWER_LIMIT_TYPE                                 (Exi_RootElementIdType)868U
#define EXI_ISO_20_WPT_10_SPCMIN_OUTPUT_POWER_LIMIT_TYPE                                 (Exi_RootElementIdType)869U
#define EXI_ISO_20_WPT_10_SPCOPERATING_FREQUENCY_TYPE                                    (Exi_RootElementIdType)870U
#define EXI_ISO_20_WPT_10_SPCPOWER_CONTROL_PARAMETER_TYPE                                (Exi_RootElementIdType)871U
#define EXI_ISO_20_WPT_10_SPCPRIMARY_DEVICE_COIL_CURRENT_INFORMATION_TYPE                (Exi_RootElementIdType)872U
#define EXI_ISO_20_WPT_10_SSID_TYPE                                                      (Exi_RootElementIdType)873U
#define EXI_ISO_20_WPT_10_SIGNAL_FREQUENCY_TYPE                                          (Exi_RootElementIdType)874U
#define EXI_ISO_20_WPT_10_SUPPLY_DEVICE_CURRENT_TYPE                                     (Exi_RootElementIdType)875U
#define EXI_ISO_20_WPT_10_TARGET_COIL_CURRENT_TYPE                                       (Exi_RootElementIdType)876U
#define EXI_ISO_20_WPT_10_TX_IDENTIFIER_TYPE                                             (Exi_RootElementIdType)877U
#define EXI_ISO_20_WPT_10_TX_PACKAGE_SPEC_DATA_TYPE                                      (Exi_RootElementIdType)878U
#define EXI_ISO_20_WPT_10_TX_RX_IDENTIFIER_TYPE                                          (Exi_RootElementIdType)879U
#define EXI_ISO_20_WPT_10_TX_RX_ORIENTATION_TYPE                                         (Exi_RootElementIdType)880U
#define EXI_ISO_20_WPT_10_TX_RX_POSITION_TYPE                                            (Exi_RootElementIdType)881U
#define EXI_ISO_20_WPT_10_TX_SPEC_DATA_TYPE                                              (Exi_RootElementIdType)882U
#define EXI_ISO_20_WPT_10_VENDOR_SPECIFIC_DATA_CONTAINER_TYPE                            (Exi_RootElementIdType)883U
#define EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD_TYPE                                (Exi_RootElementIdType)884U
#define EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_TYPE                               (Exi_RootElementIdType)885U
#define EXI_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE_TYPE                                       (Exi_RootElementIdType)886U
#define EXI_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE_LIST_TYPE                                  (Exi_RootElementIdType)887U
#define EXI_ISO_20_WPT_10_WPT_LF_RX_DATA_LIST_TYPE                                       (Exi_RootElementIdType)888U
#define EXI_ISO_20_WPT_10_WPT_LF_TX_DATA_LIST_TYPE                                       (Exi_RootElementIdType)889U
#define EXI_ISO_20_WPT_10_WPT_PAIRING_METHOD_TYPE                                        (Exi_RootElementIdType)890U
#define EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE                                                (Exi_RootElementIdType)8U

/**********************************************************************************************************************
 *  ELEMENT IDENTIFIER DEFINES
**********************************************************************************************************************/
#define EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECC                                   (uint16)0U
#define EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECC_SE                                (uint16)1U
#define EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECC_CT                                (uint16)2U
#define EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECC_EE                                (uint16)3U
#define EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECC_AT                                (uint16)4U
#define EXI_ISO_20_WPT_10_EI_SSID                                               (uint16)5U
#define EXI_ISO_20_WPT_10_EI_SSID_SE                                            (uint16)6U
#define EXI_ISO_20_WPT_10_EI_SSID_CT                                            (uint16)7U
#define EXI_ISO_20_WPT_10_EI_SSID_EE                                            (uint16)8U
#define EXI_ISO_20_WPT_10_EI_SSID_AT                                            (uint16)9U
#define EXI_ISO_20_WPT_10_EI_BSSID                                              (uint16)10U
#define EXI_ISO_20_WPT_10_EI_BSSID_SE                                           (uint16)11U
#define EXI_ISO_20_WPT_10_EI_BSSID_CT                                           (uint16)12U
#define EXI_ISO_20_WPT_10_EI_BSSID_EE                                           (uint16)13U
#define EXI_ISO_20_WPT_10_EI_BSSID_AT                                           (uint16)14U
#define EXI_ISO_20_WPT_10_EI_IPADDRESS                                          (uint16)15U
#define EXI_ISO_20_WPT_10_EI_IPADDRESS_SE                                       (uint16)16U
#define EXI_ISO_20_WPT_10_EI_IPADDRESS_CT                                       (uint16)17U
#define EXI_ISO_20_WPT_10_EI_IPADDRESS_EE                                       (uint16)18U
#define EXI_ISO_20_WPT_10_EI_IPADDRESS_AT                                       (uint16)19U
#define EXI_ISO_20_WPT_10_EI_PORT                                               (uint16)20U
#define EXI_ISO_20_WPT_10_EI_PORT_SE                                            (uint16)21U
#define EXI_ISO_20_WPT_10_EI_PORT_CT                                            (uint16)22U
#define EXI_ISO_20_WPT_10_EI_PORT_EE                                            (uint16)23U
#define EXI_ISO_20_WPT_10_EI_PORT_AT                                            (uint16)24U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_METHOD                         (uint16)25U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_METHOD_SE                      (uint16)26U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_METHOD_CT                      (uint16)27U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_METHOD_EE                      (uint16)28U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_METHOD_AT                      (uint16)29U
#define EXI_ISO_20_WPT_10_EI_HEADER                                             (uint16)30U
#define EXI_ISO_20_WPT_10_EI_HEADER_SE                                          (uint16)31U
#define EXI_ISO_20_WPT_10_EI_HEADER_CT                                          (uint16)32U
#define EXI_ISO_20_WPT_10_EI_HEADER_EE                                          (uint16)33U
#define EXI_ISO_20_WPT_10_EI_HEADER_AT                                          (uint16)34U
#define EXI_ISO_20_WPT_10_EI_EVPROCESSING                                       (uint16)35U
#define EXI_ISO_20_WPT_10_EI_EVPROCESSING_SE                                    (uint16)36U
#define EXI_ISO_20_WPT_10_EI_EVPROCESSING_CT                                    (uint16)37U
#define EXI_ISO_20_WPT_10_EI_EVPROCESSING_EE                                    (uint16)38U
#define EXI_ISO_20_WPT_10_EI_EVPROCESSING_AT                                    (uint16)39U
#define EXI_ISO_20_WPT_10_EI_TARGET_COIL_CURRENT                                (uint16)40U
#define EXI_ISO_20_WPT_10_EI_TARGET_COIL_CURRENT_SE                             (uint16)41U
#define EXI_ISO_20_WPT_10_EI_TARGET_COIL_CURRENT_CT                             (uint16)42U
#define EXI_ISO_20_WPT_10_EI_TARGET_COIL_CURRENT_EE                             (uint16)43U
#define EXI_ISO_20_WPT_10_EI_TARGET_COIL_CURRENT_AT                             (uint16)44U
#define EXI_ISO_20_WPT_10_EI_EVRESULT_CODE                                      (uint16)45U
#define EXI_ISO_20_WPT_10_EI_EVRESULT_CODE_SE                                   (uint16)46U
#define EXI_ISO_20_WPT_10_EI_EVRESULT_CODE_CT                                   (uint16)47U
#define EXI_ISO_20_WPT_10_EI_EVRESULT_CODE_EE                                   (uint16)48U
#define EXI_ISO_20_WPT_10_EI_EVRESULT_CODE_AT                                   (uint16)49U
#define EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER                     (uint16)50U
#define EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_SE                  (uint16)51U
#define EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_CT                  (uint16)52U
#define EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_EE                  (uint16)53U
#define EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_AT                  (uint16)54U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_REQ                            (uint16)55U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_REQ_SE                         (uint16)56U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_REQ_CT                         (uint16)57U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_REQ_EE                         (uint16)58U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_REQ_AT                         (uint16)59U
#define EXI_ISO_20_WPT_10_EI_RESPONSE_CODE                                      (uint16)60U
#define EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_SE                                   (uint16)61U
#define EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_CT                                   (uint16)62U
#define EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_EE                                   (uint16)63U
#define EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_AT                                   (uint16)64U
#define EXI_ISO_20_WPT_10_EI_EVSEPROCESSING                                     (uint16)65U
#define EXI_ISO_20_WPT_10_EI_EVSEPROCESSING_SE                                  (uint16)66U
#define EXI_ISO_20_WPT_10_EI_EVSEPROCESSING_CT                                  (uint16)67U
#define EXI_ISO_20_WPT_10_EI_EVSEPROCESSING_EE                                  (uint16)68U
#define EXI_ISO_20_WPT_10_EI_EVSEPROCESSING_AT                                  (uint16)69U
#define EXI_ISO_20_WPT_10_EI_POWER_TRANSMITTED                                  (uint16)70U
#define EXI_ISO_20_WPT_10_EI_POWER_TRANSMITTED_SE                               (uint16)71U
#define EXI_ISO_20_WPT_10_EI_POWER_TRANSMITTED_CT                               (uint16)72U
#define EXI_ISO_20_WPT_10_EI_POWER_TRANSMITTED_EE                               (uint16)73U
#define EXI_ISO_20_WPT_10_EI_POWER_TRANSMITTED_AT                               (uint16)74U
#define EXI_ISO_20_WPT_10_EI_SUPPLY_DEVICE_CURRENT                              (uint16)75U
#define EXI_ISO_20_WPT_10_EI_SUPPLY_DEVICE_CURRENT_SE                           (uint16)76U
#define EXI_ISO_20_WPT_10_EI_SUPPLY_DEVICE_CURRENT_CT                           (uint16)77U
#define EXI_ISO_20_WPT_10_EI_SUPPLY_DEVICE_CURRENT_EE                           (uint16)78U
#define EXI_ISO_20_WPT_10_EI_SUPPLY_DEVICE_CURRENT_AT                           (uint16)79U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_RES                            (uint16)80U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_RES_SE                         (uint16)81U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_RES_CT                         (uint16)82U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_RES_EE                         (uint16)83U
#define EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_RES_AT                         (uint16)84U
#define EXI_ISO_20_WPT_10_EI_DISPLAY_PARAMETERS                                 (uint16)85U
#define EXI_ISO_20_WPT_10_EI_DISPLAY_PARAMETERS_SE                              (uint16)86U
#define EXI_ISO_20_WPT_10_EI_DISPLAY_PARAMETERS_CT                              (uint16)87U
#define EXI_ISO_20_WPT_10_EI_DISPLAY_PARAMETERS_EE                              (uint16)88U
#define EXI_ISO_20_WPT_10_EI_DISPLAY_PARAMETERS_AT                              (uint16)89U
#define EXI_ISO_20_WPT_10_EI_METER_INFO_REQUESTED                               (uint16)90U
#define EXI_ISO_20_WPT_10_EI_METER_INFO_REQUESTED_SE                            (uint16)91U
#define EXI_ISO_20_WPT_10_EI_METER_INFO_REQUESTED_CT                            (uint16)92U
#define EXI_ISO_20_WPT_10_EI_METER_INFO_REQUESTED_EE                            (uint16)93U
#define EXI_ISO_20_WPT_10_EI_METER_INFO_REQUESTED_AT                            (uint16)94U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_REQUEST                                  (uint16)95U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_REQUEST_SE                               (uint16)96U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_REQUEST_CT                               (uint16)97U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_REQUEST_EE                               (uint16)98U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_REQUEST_AT                               (uint16)99U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_OUTPUT                                   (uint16)100U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_OUTPUT_SE                                (uint16)101U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_OUTPUT_CT                                (uint16)102U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_OUTPUT_EE                                (uint16)103U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_OUTPUT_AT                                (uint16)104U
#define EXI_ISO_20_WPT_10_EI_EVPCCHARGE_DIAGNOSTICS                             (uint16)105U
#define EXI_ISO_20_WPT_10_EI_EVPCCHARGE_DIAGNOSTICS_SE                          (uint16)106U
#define EXI_ISO_20_WPT_10_EI_EVPCCHARGE_DIAGNOSTICS_CT                          (uint16)107U
#define EXI_ISO_20_WPT_10_EI_EVPCCHARGE_DIAGNOSTICS_EE                          (uint16)108U
#define EXI_ISO_20_WPT_10_EI_EVPCCHARGE_DIAGNOSTICS_AT                          (uint16)109U
#define EXI_ISO_20_WPT_10_EI_EVPCOPERATING_FREQUENCY                            (uint16)110U
#define EXI_ISO_20_WPT_10_EI_EVPCOPERATING_FREQUENCY_SE                         (uint16)111U
#define EXI_ISO_20_WPT_10_EI_EVPCOPERATING_FREQUENCY_CT                         (uint16)112U
#define EXI_ISO_20_WPT_10_EI_EVPCOPERATING_FREQUENCY_EE                         (uint16)113U
#define EXI_ISO_20_WPT_10_EI_EVPCOPERATING_FREQUENCY_AT                         (uint16)114U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_CONTROL_PARAMETER                        (uint16)115U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_CONTROL_PARAMETER_SE                     (uint16)116U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_CONTROL_PARAMETER_CT                     (uint16)117U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_CONTROL_PARAMETER_EE                     (uint16)118U
#define EXI_ISO_20_WPT_10_EI_EVPCPOWER_CONTROL_PARAMETER_AT                     (uint16)119U
#define EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER               (uint16)120U
#define EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER_SE            (uint16)121U
#define EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER_CT            (uint16)122U
#define EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER_EE            (uint16)123U
#define EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER_AT            (uint16)124U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_REQ                                (uint16)125U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_REQ_SE                             (uint16)126U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_REQ_CT                             (uint16)127U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_REQ_EE                             (uint16)128U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_REQ_AT                             (uint16)129U
#define EXI_ISO_20_WPT_10_EI_EVSESTATUS                                         (uint16)130U
#define EXI_ISO_20_WPT_10_EI_EVSESTATUS_SE                                      (uint16)131U
#define EXI_ISO_20_WPT_10_EI_EVSESTATUS_CT                                      (uint16)132U
#define EXI_ISO_20_WPT_10_EI_EVSESTATUS_EE                                      (uint16)133U
#define EXI_ISO_20_WPT_10_EI_EVSESTATUS_AT                                      (uint16)134U
#define EXI_ISO_20_WPT_10_EI_METER_INFO                                         (uint16)135U
#define EXI_ISO_20_WPT_10_EI_METER_INFO_SE                                      (uint16)136U
#define EXI_ISO_20_WPT_10_EI_METER_INFO_CT                                      (uint16)137U
#define EXI_ISO_20_WPT_10_EI_METER_INFO_EE                                      (uint16)138U
#define EXI_ISO_20_WPT_10_EI_METER_INFO_AT                                      (uint16)139U
#define EXI_ISO_20_WPT_10_EI_RECEIPT                                            (uint16)140U
#define EXI_ISO_20_WPT_10_EI_RECEIPT_SE                                         (uint16)141U
#define EXI_ISO_20_WPT_10_EI_RECEIPT_CT                                         (uint16)142U
#define EXI_ISO_20_WPT_10_EI_RECEIPT_EE                                         (uint16)143U
#define EXI_ISO_20_WPT_10_EI_RECEIPT_AT                                         (uint16)144U
#define EXI_ISO_20_WPT_10_EI_SDPOWER_INPUT                                      (uint16)145U
#define EXI_ISO_20_WPT_10_EI_SDPOWER_INPUT_SE                                   (uint16)146U
#define EXI_ISO_20_WPT_10_EI_SDPOWER_INPUT_CT                                   (uint16)147U
#define EXI_ISO_20_WPT_10_EI_SDPOWER_INPUT_EE                                   (uint16)148U
#define EXI_ISO_20_WPT_10_EI_SDPOWER_INPUT_AT                                   (uint16)149U
#define EXI_ISO_20_WPT_10_EI_SPCMAX_OUTPUT_POWER_LIMIT                          (uint16)150U
#define EXI_ISO_20_WPT_10_EI_SPCMAX_OUTPUT_POWER_LIMIT_SE                       (uint16)151U
#define EXI_ISO_20_WPT_10_EI_SPCMAX_OUTPUT_POWER_LIMIT_CT                       (uint16)152U
#define EXI_ISO_20_WPT_10_EI_SPCMAX_OUTPUT_POWER_LIMIT_EE                       (uint16)153U
#define EXI_ISO_20_WPT_10_EI_SPCMAX_OUTPUT_POWER_LIMIT_AT                       (uint16)154U
#define EXI_ISO_20_WPT_10_EI_SPCMIN_OUTPUT_POWER_LIMIT                          (uint16)155U
#define EXI_ISO_20_WPT_10_EI_SPCMIN_OUTPUT_POWER_LIMIT_SE                       (uint16)156U
#define EXI_ISO_20_WPT_10_EI_SPCMIN_OUTPUT_POWER_LIMIT_CT                       (uint16)157U
#define EXI_ISO_20_WPT_10_EI_SPCMIN_OUTPUT_POWER_LIMIT_EE                       (uint16)158U
#define EXI_ISO_20_WPT_10_EI_SPCMIN_OUTPUT_POWER_LIMIT_AT                       (uint16)159U
#define EXI_ISO_20_WPT_10_EI_SPCCHARGE_DIAGNOSTICS                              (uint16)160U
#define EXI_ISO_20_WPT_10_EI_SPCCHARGE_DIAGNOSTICS_SE                           (uint16)161U
#define EXI_ISO_20_WPT_10_EI_SPCCHARGE_DIAGNOSTICS_CT                           (uint16)162U
#define EXI_ISO_20_WPT_10_EI_SPCCHARGE_DIAGNOSTICS_EE                           (uint16)163U
#define EXI_ISO_20_WPT_10_EI_SPCCHARGE_DIAGNOSTICS_AT                           (uint16)164U
#define EXI_ISO_20_WPT_10_EI_SPCOPERATING_FREQUENCY                             (uint16)165U
#define EXI_ISO_20_WPT_10_EI_SPCOPERATING_FREQUENCY_SE                          (uint16)166U
#define EXI_ISO_20_WPT_10_EI_SPCOPERATING_FREQUENCY_CT                          (uint16)167U
#define EXI_ISO_20_WPT_10_EI_SPCOPERATING_FREQUENCY_EE                          (uint16)168U
#define EXI_ISO_20_WPT_10_EI_SPCOPERATING_FREQUENCY_AT                          (uint16)169U
#define EXI_ISO_20_WPT_10_EI_SPCPOWER_CONTROL_PARAMETER                         (uint16)170U
#define EXI_ISO_20_WPT_10_EI_SPCPOWER_CONTROL_PARAMETER_SE                      (uint16)171U
#define EXI_ISO_20_WPT_10_EI_SPCPOWER_CONTROL_PARAMETER_CT                      (uint16)172U
#define EXI_ISO_20_WPT_10_EI_SPCPOWER_CONTROL_PARAMETER_EE                      (uint16)173U
#define EXI_ISO_20_WPT_10_EI_SPCPOWER_CONTROL_PARAMETER_AT                      (uint16)174U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_RES                                (uint16)175U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_RES_SE                             (uint16)176U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_RES_CT                             (uint16)177U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_RES_EE                             (uint16)178U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_RES_AT                             (uint16)179U
#define EXI_ISO_20_WPT_10_EI_EVPCMAX_RECEIVABLE_POWER                           (uint16)180U
#define EXI_ISO_20_WPT_10_EI_EVPCMAX_RECEIVABLE_POWER_SE                        (uint16)181U
#define EXI_ISO_20_WPT_10_EI_EVPCMAX_RECEIVABLE_POWER_CT                        (uint16)182U
#define EXI_ISO_20_WPT_10_EI_EVPCMAX_RECEIVABLE_POWER_EE                        (uint16)183U
#define EXI_ISO_20_WPT_10_EI_EVPCMAX_RECEIVABLE_POWER_AT                        (uint16)184U
#define EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARENCE                             (uint16)185U
#define EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARENCE_SE                          (uint16)186U
#define EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARENCE_CT                          (uint16)187U
#define EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARENCE_EE                          (uint16)188U
#define EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARENCE_AT                          (uint16)189U
#define EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARENCE                             (uint16)190U
#define EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARENCE_SE                          (uint16)191U
#define EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARENCE_CT                          (uint16)192U
#define EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARENCE_EE                          (uint16)193U
#define EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARENCE_AT                          (uint16)194U
#define EXI_ISO_20_WPT_10_EI_EVPCNATURAL_FREQUENCY                              (uint16)195U
#define EXI_ISO_20_WPT_10_EI_EVPCNATURAL_FREQUENCY_SE                           (uint16)196U
#define EXI_ISO_20_WPT_10_EI_EVPCNATURAL_FREQUENCY_CT                           (uint16)197U
#define EXI_ISO_20_WPT_10_EI_EVPCNATURAL_FREQUENCY_EE                           (uint16)198U
#define EXI_ISO_20_WPT_10_EI_EVPCNATURAL_FREQUENCY_AT                           (uint16)199U
#define EXI_ISO_20_WPT_10_EI_EVPCDEVICE_LOCAL_CONTROL                           (uint16)200U
#define EXI_ISO_20_WPT_10_EI_EVPCDEVICE_LOCAL_CONTROL_SE                        (uint16)201U
#define EXI_ISO_20_WPT_10_EI_EVPCDEVICE_LOCAL_CONTROL_CT                        (uint16)202U
#define EXI_ISO_20_WPT_10_EI_EVPCDEVICE_LOCAL_CONTROL_EE                        (uint16)203U
#define EXI_ISO_20_WPT_10_EI_EVPCDEVICE_LOCAL_CONTROL_AT                        (uint16)204U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_REQ                 (uint16)205U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_REQ_SE              (uint16)206U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_REQ_CT              (uint16)207U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_REQ_EE              (uint16)208U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_REQ_AT              (uint16)209U
#define EXI_ISO_20_WPT_10_EI_PDINPUT_POWER_CLASS                                (uint16)210U
#define EXI_ISO_20_WPT_10_EI_PDINPUT_POWER_CLASS_SE                             (uint16)211U
#define EXI_ISO_20_WPT_10_EI_PDINPUT_POWER_CLASS_CT                             (uint16)212U
#define EXI_ISO_20_WPT_10_EI_PDINPUT_POWER_CLASS_EE                             (uint16)213U
#define EXI_ISO_20_WPT_10_EI_PDINPUT_POWER_CLASS_AT                             (uint16)214U
#define EXI_ISO_20_WPT_10_EI_SDMIN_OUTPUT_POWER                                 (uint16)215U
#define EXI_ISO_20_WPT_10_EI_SDMIN_OUTPUT_POWER_SE                              (uint16)216U
#define EXI_ISO_20_WPT_10_EI_SDMIN_OUTPUT_POWER_CT                              (uint16)217U
#define EXI_ISO_20_WPT_10_EI_SDMIN_OUTPUT_POWER_EE                              (uint16)218U
#define EXI_ISO_20_WPT_10_EI_SDMIN_OUTPUT_POWER_AT                              (uint16)219U
#define EXI_ISO_20_WPT_10_EI_SDMAX_OUTPUT_POWER                                 (uint16)220U
#define EXI_ISO_20_WPT_10_EI_SDMAX_OUTPUT_POWER_SE                              (uint16)221U
#define EXI_ISO_20_WPT_10_EI_SDMAX_OUTPUT_POWER_CT                              (uint16)222U
#define EXI_ISO_20_WPT_10_EI_SDMAX_OUTPUT_POWER_EE                              (uint16)223U
#define EXI_ISO_20_WPT_10_EI_SDMAX_OUTPUT_POWER_AT                              (uint16)224U
#define EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARANCE_SUPPORT                     (uint16)225U
#define EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARANCE_SUPPORT_SE                  (uint16)226U
#define EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARANCE_SUPPORT_CT                  (uint16)227U
#define EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARANCE_SUPPORT_EE                  (uint16)228U
#define EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARANCE_SUPPORT_AT                  (uint16)229U
#define EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARANCE_SUPPORT                     (uint16)230U
#define EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARANCE_SUPPORT_SE                  (uint16)231U
#define EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARANCE_SUPPORT_CT                  (uint16)232U
#define EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARANCE_SUPPORT_EE                  (uint16)233U
#define EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARANCE_SUPPORT_AT                  (uint16)234U
#define EXI_ISO_20_WPT_10_EI_PDMIN_COIL_CURRENT                                 (uint16)235U
#define EXI_ISO_20_WPT_10_EI_PDMIN_COIL_CURRENT_SE                              (uint16)236U
#define EXI_ISO_20_WPT_10_EI_PDMIN_COIL_CURRENT_CT                              (uint16)237U
#define EXI_ISO_20_WPT_10_EI_PDMIN_COIL_CURRENT_EE                              (uint16)238U
#define EXI_ISO_20_WPT_10_EI_PDMIN_COIL_CURRENT_AT                              (uint16)239U
#define EXI_ISO_20_WPT_10_EI_PDMAX_COIL_CURRENT                                 (uint16)240U
#define EXI_ISO_20_WPT_10_EI_PDMAX_COIL_CURRENT_SE                              (uint16)241U
#define EXI_ISO_20_WPT_10_EI_PDMAX_COIL_CURRENT_CT                              (uint16)242U
#define EXI_ISO_20_WPT_10_EI_PDMAX_COIL_CURRENT_EE                              (uint16)243U
#define EXI_ISO_20_WPT_10_EI_PDMAX_COIL_CURRENT_AT                              (uint16)244U
#define EXI_ISO_20_WPT_10_EI_SDMANUFACTURER_SPECIFIC_DATA_CONTAINER             (uint16)245U
#define EXI_ISO_20_WPT_10_EI_SDMANUFACTURER_SPECIFIC_DATA_CONTAINER_SE          (uint16)246U
#define EXI_ISO_20_WPT_10_EI_SDMANUFACTURER_SPECIFIC_DATA_CONTAINER_CT          (uint16)247U
#define EXI_ISO_20_WPT_10_EI_SDMANUFACTURER_SPECIFIC_DATA_CONTAINER_EE          (uint16)248U
#define EXI_ISO_20_WPT_10_EI_SDMANUFACTURER_SPECIFIC_DATA_CONTAINER_AT          (uint16)249U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_RES                 (uint16)250U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_RES_SE              (uint16)251U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_RES_CT              (uint16)252U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_RES_EE              (uint16)253U
#define EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_RES_AT              (uint16)254U
#define EXI_ISO_20_WPT_10_EI_COORD_X                                            (uint16)255U
#define EXI_ISO_20_WPT_10_EI_COORD_X_SE                                         (uint16)256U
#define EXI_ISO_20_WPT_10_EI_COORD_X_CT                                         (uint16)257U
#define EXI_ISO_20_WPT_10_EI_COORD_X_EE                                         (uint16)258U
#define EXI_ISO_20_WPT_10_EI_COORD_X_AT                                         (uint16)259U
#define EXI_ISO_20_WPT_10_EI_COORD_Y                                            (uint16)260U
#define EXI_ISO_20_WPT_10_EI_COORD_Y_SE                                         (uint16)261U
#define EXI_ISO_20_WPT_10_EI_COORD_Y_CT                                         (uint16)262U
#define EXI_ISO_20_WPT_10_EI_COORD_Y_EE                                         (uint16)263U
#define EXI_ISO_20_WPT_10_EI_COORD_Y_AT                                         (uint16)264U
#define EXI_ISO_20_WPT_10_EI_COORD_Z                                            (uint16)265U
#define EXI_ISO_20_WPT_10_EI_COORD_Z_SE                                         (uint16)266U
#define EXI_ISO_20_WPT_10_EI_COORD_Z_CT                                         (uint16)267U
#define EXI_ISO_20_WPT_10_EI_COORD_Z_EE                                         (uint16)268U
#define EXI_ISO_20_WPT_10_EI_COORD_Z_AT                                         (uint16)269U
#define EXI_ISO_20_WPT_10_EI_WPT_DATA_CONTAINER                                 (uint16)270U
#define EXI_ISO_20_WPT_10_EI_WPT_DATA_CONTAINER_SE                              (uint16)271U
#define EXI_ISO_20_WPT_10_EI_WPT_DATA_CONTAINER_CT                              (uint16)272U
#define EXI_ISO_20_WPT_10_EI_WPT_DATA_CONTAINER_EE                              (uint16)273U
#define EXI_ISO_20_WPT_10_EI_WPT_DATA_CONTAINER_AT                              (uint16)274U
#define EXI_ISO_20_WPT_10_EI_WPT_EVPCCHARGE_DIAGNOSTICS                         (uint16)275U
#define EXI_ISO_20_WPT_10_EI_WPT_EVPCCHARGE_DIAGNOSTICS_SE                      (uint16)276U
#define EXI_ISO_20_WPT_10_EI_WPT_EVPCCHARGE_DIAGNOSTICS_CT                      (uint16)277U
#define EXI_ISO_20_WPT_10_EI_WPT_EVPCCHARGE_DIAGNOSTICS_EE                      (uint16)278U
#define EXI_ISO_20_WPT_10_EI_WPT_EVPCCHARGE_DIAGNOSTICS_AT                      (uint16)279U
#define EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_REQUEST                           (uint16)280U
#define EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_REQUEST_SE                        (uint16)281U
#define EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_REQUEST_CT                        (uint16)282U
#define EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_REQUEST_EE                        (uint16)283U
#define EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_REQUEST_AT                        (uint16)284U
#define EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_INFORMATION                       (uint16)285U
#define EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_INFORMATION_SE                    (uint16)286U
#define EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_INFORMATION_CT                    (uint16)287U
#define EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_INFORMATION_EE                    (uint16)288U
#define EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_INFORMATION_AT                    (uint16)289U
#define EXI_ISO_20_WPT_10_EI_EVPCCURRENT_OUTPUT_INFORMATION                     (uint16)290U
#define EXI_ISO_20_WPT_10_EI_EVPCCURRENT_OUTPUT_INFORMATION_SE                  (uint16)291U
#define EXI_ISO_20_WPT_10_EI_EVPCCURRENT_OUTPUT_INFORMATION_CT                  (uint16)292U
#define EXI_ISO_20_WPT_10_EI_EVPCCURRENT_OUTPUT_INFORMATION_EE                  (uint16)293U
#define EXI_ISO_20_WPT_10_EI_EVPCCURRENT_OUTPUT_INFORMATION_AT                  (uint16)294U
#define EXI_ISO_20_WPT_10_EI_EVPCVOLTAGE_OUTPUT_INFORMATION                     (uint16)295U
#define EXI_ISO_20_WPT_10_EI_EVPCVOLTAGE_OUTPUT_INFORMATION_SE                  (uint16)296U
#define EXI_ISO_20_WPT_10_EI_EVPCVOLTAGE_OUTPUT_INFORMATION_CT                  (uint16)297U
#define EXI_ISO_20_WPT_10_EI_EVPCVOLTAGE_OUTPUT_INFORMATION_EE                  (uint16)298U
#define EXI_ISO_20_WPT_10_EI_EVPCVOLTAGE_OUTPUT_INFORMATION_AT                  (uint16)299U
#define EXI_ISO_20_WPT_10_EI_WPT_EVRESULT                                       (uint16)300U
#define EXI_ISO_20_WPT_10_EI_WPT_EVRESULT_SE                                    (uint16)301U
#define EXI_ISO_20_WPT_10_EI_WPT_EVRESULT_CT                                    (uint16)302U
#define EXI_ISO_20_WPT_10_EI_WPT_EVRESULT_EE                                    (uint16)303U
#define EXI_ISO_20_WPT_10_EI_WPT_EVRESULT_AT                                    (uint16)304U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_METHOD                        (uint16)305U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_METHOD_SE                     (uint16)306U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_METHOD_CT                     (uint16)307U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_METHOD_EE                     (uint16)308U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_METHOD_AT                     (uint16)309U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_LIST                           (uint16)310U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_LIST_SE                        (uint16)311U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_LIST_CT                        (uint16)312U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_LIST_EE                        (uint16)313U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_LIST_AT                        (uint16)314U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_REQ                           (uint16)315U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_REQ_SE                        (uint16)316U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_REQ_CT                        (uint16)317U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_REQ_EE                        (uint16)318U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_REQ_AT                        (uint16)319U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_RES                           (uint16)320U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_RES_SE                        (uint16)321U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_RES_CT                        (uint16)322U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_RES_EE                        (uint16)323U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_RES_AT                        (uint16)324U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_FINE_POSITIONING_METHOD_LIST              (uint16)325U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_FINE_POSITIONING_METHOD_LIST_SE           (uint16)326U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_FINE_POSITIONING_METHOD_LIST_CT           (uint16)327U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_FINE_POSITIONING_METHOD_LIST_EE           (uint16)328U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_FINE_POSITIONING_METHOD_LIST_AT           (uint16)329U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_PAIRING_METHOD_LIST                       (uint16)330U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_PAIRING_METHOD_LIST_SE                    (uint16)331U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_PAIRING_METHOD_LIST_CT                    (uint16)332U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_PAIRING_METHOD_LIST_EE                    (uint16)333U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_PAIRING_METHOD_LIST_AT                    (uint16)334U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_ALIGNMENT_CHECK_METHOD_LIST               (uint16)335U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_ALIGNMENT_CHECK_METHOD_LIST_SE            (uint16)336U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_ALIGNMENT_CHECK_METHOD_LIST_CT            (uint16)337U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_ALIGNMENT_CHECK_METHOD_LIST_EE            (uint16)338U
#define EXI_ISO_20_WPT_10_EI_EVDEVICE_ALIGNMENT_CHECK_METHOD_LIST_AT            (uint16)339U
#define EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET                                     (uint16)340U
#define EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET_SE                                  (uint16)341U
#define EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET_CT                                  (uint16)342U
#define EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET_EE                                  (uint16)343U
#define EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET_AT                                  (uint16)344U
#define EXI_ISO_20_WPT_10_EI_LF_SYSTEM_SETUP_DATA                               (uint16)345U
#define EXI_ISO_20_WPT_10_EI_LF_SYSTEM_SETUP_DATA_SE                            (uint16)346U
#define EXI_ISO_20_WPT_10_EI_LF_SYSTEM_SETUP_DATA_CT                            (uint16)347U
#define EXI_ISO_20_WPT_10_EI_LF_SYSTEM_SETUP_DATA_EE                            (uint16)348U
#define EXI_ISO_20_WPT_10_EI_LF_SYSTEM_SETUP_DATA_AT                            (uint16)349U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_REQ                     (uint16)350U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_REQ_SE                  (uint16)351U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_REQ_CT                  (uint16)352U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_REQ_EE                  (uint16)353U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_REQ_AT                  (uint16)354U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_FINE_POSITIONING_METHOD_LIST        (uint16)355U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_FINE_POSITIONING_METHOD_LIST_SE     (uint16)356U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_FINE_POSITIONING_METHOD_LIST_CT     (uint16)357U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_FINE_POSITIONING_METHOD_LIST_EE     (uint16)358U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_FINE_POSITIONING_METHOD_LIST_AT     (uint16)359U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_PAIRING_METHOD_LIST                 (uint16)360U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_PAIRING_METHOD_LIST_SE              (uint16)361U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_PAIRING_METHOD_LIST_CT              (uint16)362U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_PAIRING_METHOD_LIST_EE              (uint16)363U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_PAIRING_METHOD_LIST_AT              (uint16)364U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_ALIGNMENT_CHECK_METHOD_LIST         (uint16)365U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_ALIGNMENT_CHECK_METHOD_LIST_SE      (uint16)366U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_ALIGNMENT_CHECK_METHOD_LIST_CT      (uint16)367U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_ALIGNMENT_CHECK_METHOD_LIST_EE      (uint16)368U
#define EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_ALIGNMENT_CHECK_METHOD_LIST_AT      (uint16)369U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_RES                     (uint16)370U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_RES_SE                  (uint16)371U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_RES_CT                  (uint16)372U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_RES_EE                  (uint16)373U
#define EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_RES_AT                  (uint16)374U
#define EXI_ISO_20_WPT_10_EI_NUM_PACKAGES                                       (uint16)375U
#define EXI_ISO_20_WPT_10_EI_NUM_PACKAGES_SE                                    (uint16)376U
#define EXI_ISO_20_WPT_10_EI_NUM_PACKAGES_CT                                    (uint16)377U
#define EXI_ISO_20_WPT_10_EI_NUM_PACKAGES_EE                                    (uint16)378U
#define EXI_ISO_20_WPT_10_EI_NUM_PACKAGES_AT                                    (uint16)379U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE                                (uint16)380U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_SE                             (uint16)381U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_CT                             (uint16)382U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_EE                             (uint16)383U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_AT                             (uint16)384U
#define EXI_ISO_20_WPT_10_EI_PACKAGE_INDEX                                      (uint16)385U
#define EXI_ISO_20_WPT_10_EI_PACKAGE_INDEX_SE                                   (uint16)386U
#define EXI_ISO_20_WPT_10_EI_PACKAGE_INDEX_CT                                   (uint16)387U
#define EXI_ISO_20_WPT_10_EI_PACKAGE_INDEX_EE                                   (uint16)388U
#define EXI_ISO_20_WPT_10_EI_PACKAGE_INDEX_AT                                   (uint16)389U
#define EXI_ISO_20_WPT_10_EI_CHOICE_ELEMENT                                     (uint16)390U
#define EXI_ISO_20_WPT_10_EI_CHOICE_ELEMENT_SE                                  (uint16)391U
#define EXI_ISO_20_WPT_10_EI_CHOICE_ELEMENT_CT                                  (uint16)392U
#define EXI_ISO_20_WPT_10_EI_CHOICE_ELEMENT_EE                                  (uint16)393U
#define EXI_ISO_20_WPT_10_EI_CHOICE_ELEMENT_AT                                  (uint16)394U
#define EXI_ISO_20_WPT_10_EI_NUMBER_OF_RECEIVERS                                (uint16)395U
#define EXI_ISO_20_WPT_10_EI_NUMBER_OF_RECEIVERS_SE                             (uint16)396U
#define EXI_ISO_20_WPT_10_EI_NUMBER_OF_RECEIVERS_CT                             (uint16)397U
#define EXI_ISO_20_WPT_10_EI_NUMBER_OF_RECEIVERS_EE                             (uint16)398U
#define EXI_ISO_20_WPT_10_EI_NUMBER_OF_RECEIVERS_AT                             (uint16)399U
#define EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA                                       (uint16)400U
#define EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA_SE                                    (uint16)401U
#define EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA_CT                                    (uint16)402U
#define EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA_EE                                    (uint16)403U
#define EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA_AT                                    (uint16)404U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_RX_DATA_LIST                                (uint16)405U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_RX_DATA_LIST_SE                             (uint16)406U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_RX_DATA_LIST_CT                             (uint16)407U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_RX_DATA_LIST_EE                             (uint16)408U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_RX_DATA_LIST_AT                             (uint16)409U
#define EXI_ISO_20_WPT_10_EI_RX_IDENTIFIER                                      (uint16)410U
#define EXI_ISO_20_WPT_10_EI_RX_IDENTIFIER_SE                                   (uint16)411U
#define EXI_ISO_20_WPT_10_EI_RX_IDENTIFIER_CT                                   (uint16)412U
#define EXI_ISO_20_WPT_10_EI_RX_IDENTIFIER_EE                                   (uint16)413U
#define EXI_ISO_20_WPT_10_EI_RX_IDENTIFIER_AT                                   (uint16)414U
#define EXI_ISO_20_WPT_10_EI_RSSIDATA                                           (uint16)415U
#define EXI_ISO_20_WPT_10_EI_RSSIDATA_SE                                        (uint16)416U
#define EXI_ISO_20_WPT_10_EI_RSSIDATA_CT                                        (uint16)417U
#define EXI_ISO_20_WPT_10_EI_RSSIDATA_EE                                        (uint16)418U
#define EXI_ISO_20_WPT_10_EI_RSSIDATA_AT                                        (uint16)419U
#define EXI_ISO_20_WPT_10_EI_RSSIDATA_LIST                                      (uint16)420U
#define EXI_ISO_20_WPT_10_EI_RSSIDATA_LIST_SE                                   (uint16)421U
#define EXI_ISO_20_WPT_10_EI_RSSIDATA_LIST_CT                                   (uint16)422U
#define EXI_ISO_20_WPT_10_EI_RSSIDATA_LIST_EE                                   (uint16)423U
#define EXI_ISO_20_WPT_10_EI_RSSIDATA_LIST_AT                                   (uint16)424U
#define EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER                                      (uint16)425U
#define EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER_SE                                   (uint16)426U
#define EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER_CT                                   (uint16)427U
#define EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER_EE                                   (uint16)428U
#define EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER_AT                                   (uint16)429U
#define EXI_ISO_20_WPT_10_EI_RSSI                                               (uint16)430U
#define EXI_ISO_20_WPT_10_EI_RSSI_SE                                            (uint16)431U
#define EXI_ISO_20_WPT_10_EI_RSSI_CT                                            (uint16)432U
#define EXI_ISO_20_WPT_10_EI_RSSI_EE                                            (uint16)433U
#define EXI_ISO_20_WPT_10_EI_RSSI_AT                                            (uint16)434U
#define EXI_ISO_20_WPT_10_EI_NUMBER_OF_TRANSMITTERS                             (uint16)435U
#define EXI_ISO_20_WPT_10_EI_NUMBER_OF_TRANSMITTERS_SE                          (uint16)436U
#define EXI_ISO_20_WPT_10_EI_NUMBER_OF_TRANSMITTERS_CT                          (uint16)437U
#define EXI_ISO_20_WPT_10_EI_NUMBER_OF_TRANSMITTERS_EE                          (uint16)438U
#define EXI_ISO_20_WPT_10_EI_NUMBER_OF_TRANSMITTERS_AT                          (uint16)439U
#define EXI_ISO_20_WPT_10_EI_SIGNAL_FREQUENCY                                   (uint16)440U
#define EXI_ISO_20_WPT_10_EI_SIGNAL_FREQUENCY_SE                                (uint16)441U
#define EXI_ISO_20_WPT_10_EI_SIGNAL_FREQUENCY_CT                                (uint16)442U
#define EXI_ISO_20_WPT_10_EI_SIGNAL_FREQUENCY_EE                                (uint16)443U
#define EXI_ISO_20_WPT_10_EI_SIGNAL_FREQUENCY_AT                                (uint16)444U
#define EXI_ISO_20_WPT_10_EI_TX_SPEC_DATA                                       (uint16)445U
#define EXI_ISO_20_WPT_10_EI_TX_SPEC_DATA_SE                                    (uint16)446U
#define EXI_ISO_20_WPT_10_EI_TX_SPEC_DATA_CT                                    (uint16)447U
#define EXI_ISO_20_WPT_10_EI_TX_SPEC_DATA_EE                                    (uint16)448U
#define EXI_ISO_20_WPT_10_EI_TX_SPEC_DATA_AT                                    (uint16)449U
#define EXI_ISO_20_WPT_10_EI_TX_PACKAGE_SPEC_DATA                               (uint16)450U
#define EXI_ISO_20_WPT_10_EI_TX_PACKAGE_SPEC_DATA_SE                            (uint16)451U
#define EXI_ISO_20_WPT_10_EI_TX_PACKAGE_SPEC_DATA_CT                            (uint16)452U
#define EXI_ISO_20_WPT_10_EI_TX_PACKAGE_SPEC_DATA_EE                            (uint16)453U
#define EXI_ISO_20_WPT_10_EI_TX_PACKAGE_SPEC_DATA_AT                            (uint16)454U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_TX_DATA_LIST                                (uint16)455U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_TX_DATA_LIST_SE                             (uint16)456U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_TX_DATA_LIST_CT                             (uint16)457U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_TX_DATA_LIST_EE                             (uint16)458U
#define EXI_ISO_20_WPT_10_EI_WPT_LF_TX_DATA_LIST_AT                             (uint16)459U
#define EXI_ISO_20_WPT_10_EI_EIRP                                               (uint16)460U
#define EXI_ISO_20_WPT_10_EI_EIRP_SE                                            (uint16)461U
#define EXI_ISO_20_WPT_10_EI_EIRP_CT                                            (uint16)462U
#define EXI_ISO_20_WPT_10_EI_EIRP_EE                                            (uint16)463U
#define EXI_ISO_20_WPT_10_EI_EIRP_AT                                            (uint16)464U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_METHOD                                 (uint16)465U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_METHOD_SE                              (uint16)466U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_METHOD_CT                              (uint16)467U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_METHOD_EE                              (uint16)468U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_METHOD_AT                              (uint16)469U
#define EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE                                    (uint16)470U
#define EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE_SE                                 (uint16)471U
#define EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE_CT                                 (uint16)472U
#define EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE_EE                                 (uint16)473U
#define EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE_AT                                 (uint16)474U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_REQ                                    (uint16)475U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_REQ_SE                                 (uint16)476U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_REQ_CT                                 (uint16)477U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_REQ_EE                                 (uint16)478U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_REQ_AT                                 (uint16)479U
#define EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECCLIST                               (uint16)480U
#define EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECCLIST_SE                            (uint16)481U
#define EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECCLIST_CT                            (uint16)482U
#define EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECCLIST_EE                            (uint16)483U
#define EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECCLIST_AT                            (uint16)484U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_RES                                    (uint16)485U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_RES_SE                                 (uint16)486U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_RES_CT                                 (uint16)487U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_RES_EE                                 (uint16)488U
#define EXI_ISO_20_WPT_10_EI_WPT_PAIRING_RES_AT                                 (uint16)489U
#define EXI_ISO_20_WPT_10_EI_WPT_POWER_CLASS                                    (uint16)490U
#define EXI_ISO_20_WPT_10_EI_WPT_POWER_CLASS_SE                                 (uint16)491U
#define EXI_ISO_20_WPT_10_EI_WPT_POWER_CLASS_CT                                 (uint16)492U
#define EXI_ISO_20_WPT_10_EI_WPT_POWER_CLASS_EE                                 (uint16)493U
#define EXI_ISO_20_WPT_10_EI_WPT_POWER_CLASS_AT                                 (uint16)494U
#define EXI_ISO_20_WPT_10_EI_WPT_SPCCHARGE_DIAGNOSTICS                          (uint16)495U
#define EXI_ISO_20_WPT_10_EI_WPT_SPCCHARGE_DIAGNOSTICS_SE                       (uint16)496U
#define EXI_ISO_20_WPT_10_EI_WPT_SPCCHARGE_DIAGNOSTICS_CT                       (uint16)497U
#define EXI_ISO_20_WPT_10_EI_WPT_SPCCHARGE_DIAGNOSTICS_EE                       (uint16)498U
#define EXI_ISO_20_WPT_10_EI_WPT_SPCCHARGE_DIAGNOSTICS_AT                       (uint16)499U
#define EXI_ISO_20_WPT_10_EI_SPCPRIMARY_DEVICE_COIL_CURRENT_INFORMATION         (uint16)500U
#define EXI_ISO_20_WPT_10_EI_SPCPRIMARY_DEVICE_COIL_CURRENT_INFORMATION_SE      (uint16)501U
#define EXI_ISO_20_WPT_10_EI_SPCPRIMARY_DEVICE_COIL_CURRENT_INFORMATION_CT      (uint16)502U
#define EXI_ISO_20_WPT_10_EI_SPCPRIMARY_DEVICE_COIL_CURRENT_INFORMATION_EE      (uint16)503U
#define EXI_ISO_20_WPT_10_EI_SPCPRIMARY_DEVICE_COIL_CURRENT_INFORMATION_AT      (uint16)504U
#define EXI_ISO_20_WPT_10_EI_PULSE_SEQUENCE_ORDER                               (uint16)505U
#define EXI_ISO_20_WPT_10_EI_PULSE_SEQUENCE_ORDER_SE                            (uint16)506U
#define EXI_ISO_20_WPT_10_EI_PULSE_SEQUENCE_ORDER_CT                            (uint16)507U
#define EXI_ISO_20_WPT_10_EI_PULSE_SEQUENCE_ORDER_EE                            (uint16)508U
#define EXI_ISO_20_WPT_10_EI_PULSE_SEQUENCE_ORDER_AT                            (uint16)509U
#define EXI_ISO_20_WPT_10_EI_PULSE_SEPARATION_TIME                              (uint16)510U
#define EXI_ISO_20_WPT_10_EI_PULSE_SEPARATION_TIME_SE                           (uint16)511U
#define EXI_ISO_20_WPT_10_EI_PULSE_SEPARATION_TIME_CT                           (uint16)512U
#define EXI_ISO_20_WPT_10_EI_PULSE_SEPARATION_TIME_EE                           (uint16)513U
#define EXI_ISO_20_WPT_10_EI_PULSE_SEPARATION_TIME_AT                           (uint16)514U
#define EXI_ISO_20_WPT_10_EI_PULSE_DURATION                                     (uint16)515U
#define EXI_ISO_20_WPT_10_EI_PULSE_DURATION_SE                                  (uint16)516U
#define EXI_ISO_20_WPT_10_EI_PULSE_DURATION_CT                                  (uint16)517U
#define EXI_ISO_20_WPT_10_EI_PULSE_DURATION_EE                                  (uint16)518U
#define EXI_ISO_20_WPT_10_EI_PULSE_DURATION_AT                                  (uint16)519U
#define EXI_ISO_20_WPT_10_EI_PACKAGE_SEPARATION_TIME                            (uint16)520U
#define EXI_ISO_20_WPT_10_EI_PACKAGE_SEPARATION_TIME_SE                         (uint16)521U
#define EXI_ISO_20_WPT_10_EI_PACKAGE_SEPARATION_TIME_CT                         (uint16)522U
#define EXI_ISO_20_WPT_10_EI_PACKAGE_SEPARATION_TIME_EE                         (uint16)523U
#define EXI_ISO_20_WPT_10_EI_PACKAGE_SEPARATION_TIME_AT                         (uint16)524U
#define EXI_ISO_20_WPT_10_EI_INDEX_NUMBER                                       (uint16)525U
#define EXI_ISO_20_WPT_10_EI_INDEX_NUMBER_SE                                    (uint16)526U
#define EXI_ISO_20_WPT_10_EI_INDEX_NUMBER_CT                                    (uint16)527U
#define EXI_ISO_20_WPT_10_EI_INDEX_NUMBER_EE                                    (uint16)528U
#define EXI_ISO_20_WPT_10_EI_INDEX_NUMBER_AT                                    (uint16)529U
#define EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER                                   (uint16)530U
#define EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER_SE                                (uint16)531U
#define EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER_CT                                (uint16)532U
#define EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER_EE                                (uint16)533U
#define EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER_AT                                (uint16)534U
#define EXI_ISO_20_WPT_10_EI_TX_RX_POSITION                                     (uint16)535U
#define EXI_ISO_20_WPT_10_EI_TX_RX_POSITION_SE                                  (uint16)536U
#define EXI_ISO_20_WPT_10_EI_TX_RX_POSITION_CT                                  (uint16)537U
#define EXI_ISO_20_WPT_10_EI_TX_RX_POSITION_EE                                  (uint16)538U
#define EXI_ISO_20_WPT_10_EI_TX_RX_POSITION_AT                                  (uint16)539U
#define EXI_ISO_20_WPT_10_EI_TX_RX_ORIENTATION                                  (uint16)540U
#define EXI_ISO_20_WPT_10_EI_TX_RX_ORIENTATION_SE                               (uint16)541U
#define EXI_ISO_20_WPT_10_EI_TX_RX_ORIENTATION_CT                               (uint16)542U
#define EXI_ISO_20_WPT_10_EI_TX_RX_ORIENTATION_EE                               (uint16)543U
#define EXI_ISO_20_WPT_10_EI_TX_RX_ORIENTATION_AT                               (uint16)544U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_TYPE_MANUAL = 0u,
  EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_TYPE_LF_TX_EV = 1u,
  EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_TYPE_LF_TX_PRIMARY_DEVICE = 2u,
  EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_TYPE_LPE = 3u,
  EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_TYPE_PROPRIETARY = 4u
} Exi_ISO_20_WPT_10_WPT_FinePositioningMethodType;

typedef enum
{
  EXI_ISO_20_WPT_10_WPT_PAIRING_METHOD_TYPE_EXTERNALCONFIRMATION = 0u,
  EXI_ISO_20_WPT_10_WPT_PAIRING_METHOD_TYPE_LPE = 1u,
  EXI_ISO_20_WPT_10_WPT_PAIRING_METHOD_TYPE_LF_TX_EV = 2u,
  EXI_ISO_20_WPT_10_WPT_PAIRING_METHOD_TYPE_LF_TX_PRIMARY_DEVICE = 3u,
  EXI_ISO_20_WPT_10_WPT_PAIRING_METHOD_TYPE_OPTICAL = 4u,
  EXI_ISO_20_WPT_10_WPT_PAIRING_METHOD_TYPE_PROPRIETARY = 5u
} Exi_ISO_20_WPT_10_WPT_PairingMethodType;

typedef enum
{
  EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD_TYPE_POWER_CHECK = 0u,
  EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD_TYPE_LPE = 1u,
  EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD_TYPE_PROPRIETARY = 2u
} Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodType;

typedef enum
{
  EXI_ISO_20_WPT_10_WPT_EVPCCHARGE_DIAGNOSTICS_TYPE_EVPCNO_ISSUE = 0u,
  EXI_ISO_20_WPT_10_WPT_EVPCCHARGE_DIAGNOSTICS_TYPE_EVPCTEMP_OVERHEAT_DETECTED = 1u,
  EXI_ISO_20_WPT_10_WPT_EVPCCHARGE_DIAGNOSTICS_TYPE_EVPCPOWER_TRANSFER_ANOMALY_DETECTED = 2u,
  EXI_ISO_20_WPT_10_WPT_EVPCCHARGE_DIAGNOSTICS_TYPE_EVPCANOMALY_DETECTED = 3u
} Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType;

typedef enum
{
  EXI_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS_TYPE_SPCNO_ISSUE = 0u,
  EXI_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS_TYPE_SPCFODDETECTED = 1u,
  EXI_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS_TYPE_SPCLOPDETECTED = 2u,
  EXI_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS_TYPE_SPCTEMP_OVERHEAT_DETECTED = 3u,
  EXI_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS_TYPE_SPCPOWER_TRANSFER_ANOMALY_DETECTED = 4u,
  EXI_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS_TYPE_SPCANOMALY_DETECTED = 5u
} Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType;

typedef enum
{
  EXI_ISO_20_WPT_10_WPT_POWER_CLASS_TYPE_MF_WPT1 = 0u,
  EXI_ISO_20_WPT_10_WPT_POWER_CLASS_TYPE_MF_WPT2 = 1u,
  EXI_ISO_20_WPT_10_WPT_POWER_CLASS_TYPE_MF_WPT3 = 2u,
  EXI_ISO_20_WPT_10_WPT_POWER_CLASS_TYPE_MF_WPT4 = 3u
} Exi_ISO_20_WPT_10_WPT_PowerClassType;

typedef enum
{
  EXI_ISO_20_WPT_10_WPT_EVRESULT_TYPE_EVRESULT_UNKNOWN = 0u,
  EXI_ISO_20_WPT_10_WPT_EVRESULT_TYPE_EVRESULT_SUCCESS = 1u,
  EXI_ISO_20_WPT_10_WPT_EVRESULT_TYPE_EVRESULT_FAILED = 2u
} Exi_ISO_20_WPT_10_WPT_EVResultType;

typedef struct Exi_ISO_20_WPT_10_bssidType Exi_ISO_20_WPT_10_bssidType;
struct Exi_ISO_20_WPT_10_bssidType
{
  uint16 Length;
  uint8 Buffer[12];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_ISO_20_WPT_10_ipaddressType Exi_ISO_20_WPT_10_ipaddressType;
struct Exi_ISO_20_WPT_10_ipaddressType
{
  uint16 Length;
  uint8 Buffer[39];
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

typedef struct Exi_ISO_20_WPT_10_WPT_DataContainerType Exi_ISO_20_WPT_10_WPT_DataContainerType;
struct Exi_ISO_20_WPT_10_WPT_DataContainerType
{
  uint16 Length;
  struct Exi_ISO_20_WPT_10_WPT_DataContainerType* NextWPT_DataContainerPtr;
  uint8 Buffer[256];
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

typedef struct Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataChoiceType Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataChoiceType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_DataPackageChoiceType Exi_ISO_20_WPT_10_WPT_LF_DataPackageChoiceType;

typedef struct Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType;

typedef struct Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType;

typedef struct Exi_ISO_20_WPT_10_WPT_FinePositioningReqType Exi_ISO_20_WPT_10_WPT_FinePositioningReqType;

typedef struct Exi_ISO_20_WPT_10_WPT_FinePositioningResType Exi_ISO_20_WPT_10_WPT_FinePositioningResType;

typedef struct Exi_ISO_20_WPT_10_WPT_PairingReqType Exi_ISO_20_WPT_10_WPT_PairingReqType;

typedef struct Exi_ISO_20_WPT_10_WPT_PairingResType Exi_ISO_20_WPT_10_WPT_PairingResType;

typedef struct Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType;

typedef struct Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType;

typedef struct Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType;

typedef struct Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType;

typedef struct Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType;

typedef struct Exi_ISO_20_WPT_10_WPT_ChargeLoopResType Exi_ISO_20_WPT_10_WPT_ChargeLoopResType;

typedef struct Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType;

typedef struct Exi_ISO_20_WPT_10_WPT_PairingMethodListType Exi_ISO_20_WPT_10_WPT_PairingMethodListType;

typedef struct Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType;

typedef struct Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType;

typedef struct Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType;

typedef struct Exi_ISO_20_WPT_10_WPT_CoordinateXYZType Exi_ISO_20_WPT_10_WPT_CoordinateXYZType;

typedef struct Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType;

typedef struct Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType;

typedef struct Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_TxDataType Exi_ISO_20_WPT_10_WPT_LF_TxDataType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_TxDataListType Exi_ISO_20_WPT_10_WPT_LF_TxDataListType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_RxDataType Exi_ISO_20_WPT_10_WPT_LF_RxDataType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_RxDataListType Exi_ISO_20_WPT_10_WPT_LF_RxDataListType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_DataPackageType Exi_ISO_20_WPT_10_WPT_LF_DataPackageType;

typedef struct Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType;

typedef struct Exi_ISO_20_WPT_10_AlternativeSECCType Exi_ISO_20_WPT_10_AlternativeSECCType;

typedef struct Exi_ISO_20_WPT_10_AlternativeSECCListType Exi_ISO_20_WPT_10_AlternativeSECCListType;

struct Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType
{
  Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType* EVDeviceAlignmentCheckMethodList;
  Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType* EVDeviceFinePositioningMethodList;
  Exi_ISO_20_WPT_10_WPT_PairingMethodListType* EVDevicePairingMethodList;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType* LF_SystemSetupData;
  uint16 NaturalOffset;
  Exi_ISO_20_CT_10_processingType EVProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_WPT_10_WPT_DataContainerType* VendorSpecificDataContainer;
  Exi_BitType LF_SystemSetupDataFlag : 1;
  Exi_BitType VendorSpecificDataContainerFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (17u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (17u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (17u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType* LF_SystemSetupData;
  Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType* PrimaryDeviceAlignmentCheckMethodList;
  Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType* PrimaryDeviceFinePositioningMethodList;
  Exi_ISO_20_WPT_10_WPT_PairingMethodListType* PrimaryDevicePairingMethodList;
  uint16 NaturalOffset;
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  Exi_ISO_20_WPT_10_WPT_DataContainerType* VendorSpecificDataContainer;
  Exi_BitType LF_SystemSetupDataFlag : 1;
  Exi_BitType VendorSpecificDataContainerFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (17u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (17u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (17u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_FinePositioningReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType* WPT_LF_DataPackageList;
  Exi_ISO_20_CT_10_processingType EVProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_WPT_10_WPT_DataContainerType* VendorSpecificDataContainer;
  Exi_ISO_20_WPT_10_WPT_EVResultType EVResultCode; /* Value range: 0 to 2; See type for exact values. */
  Exi_BitType VendorSpecificDataContainerFlag : 1;
  Exi_BitType WPT_LF_DataPackageListFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_FinePositioningResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType* WPT_LF_DataPackageList;
  Exi_ISO_20_CT_10_processingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  Exi_ISO_20_WPT_10_WPT_DataContainerType* VendorSpecificDataContainer;
  Exi_BitType VendorSpecificDataContainerFlag : 1;
  Exi_BitType WPT_LF_DataPackageListFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_PairingReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  uint32 ObservedIDCode; /* Value range: min: 1 max: 4294967295 */
  Exi_ISO_20_CT_10_processingType EVProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_WPT_10_WPT_DataContainerType* VendorSpecificDataContainer;
  Exi_ISO_20_WPT_10_WPT_EVResultType EVResultCode; /* Value range: 0 to 2; See type for exact values. */
  Exi_BitType ObservedIDCodeFlag : 1;
  Exi_BitType VendorSpecificDataContainerFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_PairingResType
{
  Exi_ISO_20_WPT_10_AlternativeSECCListType* AlternativeSECCList;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  uint32 ObservedIDCode; /* Value range: min: 1 max: 4294967295 */
  Exi_ISO_20_CT_10_processingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  Exi_ISO_20_WPT_10_WPT_DataContainerType* VendorSpecificDataContainer;
  Exi_BitType AlternativeSECCListFlag : 1;
  Exi_BitType ObservedIDCodeFlag : 1;
  Exi_BitType VendorSpecificDataContainerFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVPCMaxReceivablePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVPCNaturalFrequency;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  uint16 SDMaxGroundClearence;
  uint16 SDMinGroundClearence;
  Exi_ISO_20_WPT_10_WPT_DataContainerType* VendorSpecificDataContainer;
  boolean EVPCDeviceLocalControl;
  Exi_BitType VendorSpecificDataContainerFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (16u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (16u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (16u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_RationalNumberType* PDMaxCoilCurrent;
  Exi_ISO_20_CT_10_RationalNumberType* PDMinCoilCurrent;
  Exi_ISO_20_CT_10_RationalNumberType* SDMaxOutputPower;
  Exi_ISO_20_CT_10_RationalNumberType* SDMinOutputPower;
  uint16 SDMaxGroundClearanceSupport;
  uint16 SDMinGroundClearanceSupport;
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  Exi_ISO_20_WPT_10_WPT_DataContainerType* SDManufacturerSpecificDataContainer;
  Exi_ISO_20_WPT_10_WPT_PowerClassType PDInputPowerClass; /* Value range: 0 to 3; See type for exact values. */
  Exi_BitType SDManufacturerSpecificDataContainerFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_RationalNumberType* TargetCoilCurrent;
  Exi_ISO_20_CT_10_processingType EVProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_WPT_10_WPT_DataContainerType* VendorSpecificDataContainer;
  Exi_ISO_20_WPT_10_WPT_EVResultType EVResultCode; /* Value range: 0 to 2; See type for exact values. */
  Exi_BitType TargetCoilCurrentFlag : 1;
  Exi_BitType VendorSpecificDataContainerFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_RationalNumberType* PowerTransmitted;
  Exi_ISO_20_CT_10_RationalNumberType* SupplyDeviceCurrent;
  Exi_ISO_20_CT_10_processingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  Exi_ISO_20_WPT_10_WPT_DataContainerType* VendorSpecificDataContainer;
  Exi_BitType PowerTransmittedFlag : 1;
  Exi_BitType SupplyDeviceCurrentFlag : 1;
  Exi_BitType VendorSpecificDataContainerFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType
{
  Exi_ISO_20_CT_10_DisplayParametersType* DisplayParameters;
  Exi_ISO_20_CT_10_RationalNumberType* EVPCOperatingFrequency;
  Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType* EVPCPowerControlParameter;
  Exi_ISO_20_CT_10_RationalNumberType* EVPCPowerOutput;
  Exi_ISO_20_CT_10_RationalNumberType* EVPCPowerRequest;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_WPT_10_WPT_DataContainerType* ManufacturerSpecificDataContainer;
  Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType EVPCChargeDiagnostics; /* Value range: 0 to 3; See type for exact values. */
  boolean MeterInfoRequested;
  Exi_BitType DisplayParametersFlag : 1;
  Exi_BitType EVPCOperatingFrequencyFlag : 1;
  Exi_BitType EVPCPowerControlParameterFlag : 1;
  Exi_BitType ManufacturerSpecificDataContainerFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (17u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (17u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (17u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_ChargeLoopResType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVPCPowerRequest;
  Exi_ISO_20_CT_10_EVSEStatusType* EVSEStatus;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_MeterInfoType* MeterInfo;
  Exi_ISO_20_CT_10_ReceiptType* Receipt;
  Exi_ISO_20_CT_10_RationalNumberType* SDPowerInput;
  Exi_ISO_20_CT_10_RationalNumberType* SPCMaxOutputPowerLimit;
  Exi_ISO_20_CT_10_RationalNumberType* SPCMinOutputPowerLimit;
  Exi_ISO_20_CT_10_RationalNumberType* SPCOperatingFrequency;
  Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType* SPCPowerControlParameter;
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  Exi_ISO_20_WPT_10_WPT_DataContainerType* ManufacturerSpecificDataContainer;
  Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType SPCChargeDiagnostics; /* Value range: 0 to 5; See type for exact values. */
  Exi_BitType EVSEStatusFlag : 1;
  Exi_BitType ManufacturerSpecificDataContainerFlag : 1;
  Exi_BitType MeterInfoFlag : 1;
  Exi_BitType ReceiptFlag : 1;
  Exi_BitType SDPowerInputFlag : 1;
  Exi_BitType SPCOperatingFrequencyFlag : 1;
  Exi_BitType SPCPowerControlParameterFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (18u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType
{
  Exi_ISO_20_WPT_10_WPT_FinePositioningMethodType WPT_FinePositioningMethod[8];
  uint8 WPT_FinePositioningMethodCount;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (8u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (8u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (8u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_PairingMethodListType
{
  Exi_ISO_20_WPT_10_WPT_PairingMethodType WPT_PairingMethod[8];
  uint8 WPT_PairingMethodCount;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (8u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (8u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (8u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType
{
  Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodType WPT_AlignmentCheckMethod[8];
  uint8 WPT_AlignmentCheckMethodCount;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (8u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (8u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (8u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVPCCoilCurrentInformation;
  Exi_ISO_20_CT_10_RationalNumberType* EVPCCoilCurrentRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVPCCurrentOutputInformation;
  Exi_ISO_20_CT_10_RationalNumberType* EVPCVoltageOutputInformation;
};

struct Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType
{
  Exi_ISO_20_CT_10_RationalNumberType* SPCPrimaryDeviceCoilCurrentInformation;
};

struct Exi_ISO_20_WPT_10_WPT_CoordinateXYZType
{
  sint16 Coord_X;
  sint16 Coord_Y;
  sint16 Coord_Z;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType
{
  struct Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType* NextRxSpecDataPtr;
  struct Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType* NextTxSpecDataPtr;
  Exi_ISO_20_WPT_10_WPT_CoordinateXYZType* TxRxOrientation;
  Exi_ISO_20_WPT_10_WPT_CoordinateXYZType* TxRxPosition;
  uint32 TxRxIdentifier; /* Value range: min: 1 max: 4294967295 */
};

struct Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType
{
  struct Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType* NextPulseSequenceOrderPtr;
  uint32 TxRxIdentifier; /* Value range: min: 1 max: 4294967295 */
  uint16 IndexNumber;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType
{
  Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType* PulseSequenceOrder;
  uint16 PackageSeparationTime;
  uint16 PulseDuration;
  uint16 PulseSeparationTime;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType
{
  Exi_ISO_20_CT_10_RationalNumberType* SignalFrequency;
  Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType* TxPackageSpecData;
  Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType* TxSpecData;
  uint8 NumberOfTransmitters;
  Exi_BitType TxPackageSpecDataFlag : 1;
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

struct Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType
{
  Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType* RxSpecData;
  uint8 NumberOfReceivers;
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

struct Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataChoiceType
{
  union
  {
    Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType* LF_ReceiverSetupData;
    Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType* LF_TransmitterSetupData;
  } ChoiceValue;
  Exi_BitType LF_ReceiverSetupDataFlag : 1;
  Exi_BitType LF_TransmitterSetupDataFlag : 1;
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

struct Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType
{
  Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataChoiceType* ChoiceElement;
};

struct Exi_ISO_20_WPT_10_WPT_LF_TxDataType
{
  Exi_ISO_20_CT_10_RationalNumberType* EIRP;
  uint32 TxIdentifier; /* Value range: min: 1 max: 4294967295 */
};

struct Exi_ISO_20_WPT_10_WPT_LF_TxDataListType
{
  Exi_ISO_20_WPT_10_WPT_LF_TxDataType* WPT_LF_TxDataList;
};

struct Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType
{
  Exi_ISO_20_CT_10_RationalNumberType* RSSI;
  uint32 TxIdentifier; /* Value range: min: 1 max: 4294967295 */
};

struct Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType
{
  Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType* RSSIDataList;
};

struct Exi_ISO_20_WPT_10_WPT_LF_RxDataType
{
  Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType* RSSIData;
  uint32 RxIdentifier; /* Value range: min: 1 max: 4294967295 */
};

struct Exi_ISO_20_WPT_10_WPT_LF_RxDataListType
{
  Exi_ISO_20_WPT_10_WPT_LF_RxDataType* WPT_LF_RxDataList;
};

struct Exi_ISO_20_WPT_10_WPT_LF_DataPackageChoiceType
{
  union
  {
    Exi_ISO_20_WPT_10_WPT_LF_RxDataListType* LF_RxData;
    Exi_ISO_20_WPT_10_WPT_LF_TxDataListType* LF_TxData;
  } ChoiceValue;
  Exi_BitType LF_RxDataFlag : 1;
  Exi_BitType LF_TxDataFlag : 1;
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

struct Exi_ISO_20_WPT_10_WPT_LF_DataPackageType
{
  Exi_ISO_20_WPT_10_WPT_LF_DataPackageChoiceType* ChoiceElement;
  uint8 PackageIndex;
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

struct Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType
{
  Exi_ISO_20_WPT_10_WPT_LF_DataPackageType* WPT_LF_DataPackage;
  uint8 NumPackages;
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

struct Exi_ISO_20_WPT_10_AlternativeSECCType
{
  Exi_ISO_20_WPT_10_bssidType* BSSID;
  Exi_ISO_20_WPT_10_ipaddressType* IPAddress;
  struct Exi_ISO_20_WPT_10_AlternativeSECCType* NextAlternativeSECCPtr;
  Exi_ISO_20_CT_10_identifierType* SSID;
  uint16 Port;
  Exi_BitType BSSIDFlag : 1;
  Exi_BitType IPAddressFlag : 1;
  Exi_BitType PortFlag : 1;
  Exi_BitType SSIDFlag : 1;
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

struct Exi_ISO_20_WPT_10_AlternativeSECCListType
{
  Exi_ISO_20_WPT_10_AlternativeSECCType* AlternativeSECC;
};
#endif  /* EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET */

/* PRQA L:IDENTIFIER_NAMES */
/* PRQA L:NAMESPACE */
/* PRQA L:UNION */


#endif /* EXI_ISO_20_WPT_10_SCHEMA_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_WPT_10_SchemaTypes.h
 **********************************************************************************************************************/
