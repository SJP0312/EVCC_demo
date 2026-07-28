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
/**        \file  Exi_ISO_20_ACDP_10_SchemaTypes.h
 *        \brief  Efficient XML Interchange ISO_20_ACDP_10 types header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_ACDP_10 types.
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

#if !defined (EXI_ISO_20_ACDP_10_SCHEMA_TYPES_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_ACDP_10_SCHEMA_TYPES_H

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
#define EXI_ISO_20_ACDP_10_ACDP_CONNECT_REQ_TYPE                                         (Exi_RootElementIdType)193U
#define EXI_ISO_20_ACDP_10_ACDP_DISCONNECT_REQ_TYPE                                      (Exi_RootElementIdType)194U
#define EXI_ISO_20_ACDP_10_ACDP_CONNECT_RES_TYPE                                         (Exi_RootElementIdType)195U
#define EXI_ISO_20_ACDP_10_ACDP_DISCONNECT_RES_TYPE                                      (Exi_RootElementIdType)196U
#define EXI_ISO_20_ACDP_10_ACDP_SYSTEM_STATUS_REQ_TYPE                                   (Exi_RootElementIdType)197U
#define EXI_ISO_20_ACDP_10_ACDP_SYSTEM_STATUS_RES_TYPE                                   (Exi_RootElementIdType)198U
#define EXI_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_REQ_TYPE                             (Exi_RootElementIdType)199U
#define EXI_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_RES_TYPE                             (Exi_RootElementIdType)200U

#if (defined(EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* Elements */
#define EXI_ISO_20_ACDP_10_CONTACT_WINDOW_XC_TYPE                                        (Exi_RootElementIdType)891U
#define EXI_ISO_20_ACDP_10_CONTACT_WINDOW_YC_TYPE                                        (Exi_RootElementIdType)892U
#define EXI_ISO_20_ACDP_10_EVASSOCIATION_STATUS_TYPE                                     (Exi_RootElementIdType)893U
#define EXI_ISO_20_ACDP_10_EVCPSTATUS_TYPE                                               (Exi_RootElementIdType)894U
#define EXI_ISO_20_ACDP_10_EVELECTRICAL_CHARGING_DEVICE_STATUS_TYPE                      (Exi_RootElementIdType)895U
#define EXI_ISO_20_ACDP_10_EVERROR_CODE_TYPE                                             (Exi_RootElementIdType)896U
#define EXI_ISO_20_ACDP_10_EVIMMOBILIZATION_REQUEST_TYPE                                 (Exi_RootElementIdType)897U
#define EXI_ISO_20_ACDP_10_EVIMMOBILIZED_TYPE                                            (Exi_RootElementIdType)898U
#define EXI_ISO_20_ACDP_10_EVIN_CHARGE_POSITION_TYPE                                     (Exi_RootElementIdType)899U
#define EXI_ISO_20_ACDP_10_EVMOBILITY_STATUS_TYPE                                        (Exi_RootElementIdType)900U
#define EXI_ISO_20_ACDP_10_EVPOSITIONING_SUPPORT_TYPE                                    (Exi_RootElementIdType)901U
#define EXI_ISO_20_ACDP_10_EVREADY_TO_CHARGE_TYPE                                        (Exi_RootElementIdType)902U
#define EXI_ISO_20_ACDP_10_EVRELATIVE_XDEVIATION_TYPE                                    (Exi_RootElementIdType)903U
#define EXI_ISO_20_ACDP_10_EVRELATIVE_YDEVIATION_TYPE                                    (Exi_RootElementIdType)904U
#define EXI_ISO_20_ACDP_10_EVSEDISABLED_TYPE                                             (Exi_RootElementIdType)905U
#define EXI_ISO_20_ACDP_10_EVSEELECTRICAL_CHARGING_DEVICE_STATUS_TYPE                    (Exi_RootElementIdType)906U
#define EXI_ISO_20_ACDP_10_EVSEEMERGENCY_SHUTDOWN_TYPE                                   (Exi_RootElementIdType)907U
#define EXI_ISO_20_ACDP_10_EVSEISOLATION_STATUS_TYPE                                     (Exi_RootElementIdType)908U
#define EXI_ISO_20_ACDP_10_EVSEMALFUNCTION_TYPE                                          (Exi_RootElementIdType)909U
#define EXI_ISO_20_ACDP_10_EVSEMECHANICAL_CHARGING_DEVICE_STATUS_TYPE                    (Exi_RootElementIdType)910U
#define EXI_ISO_20_ACDP_10_EVSEPOSITIONING_SUPPORT_TYPE                                  (Exi_RootElementIdType)911U
#define EXI_ISO_20_ACDP_10_EVSEPROCESSING_TYPE                                           (Exi_RootElementIdType)912U
#define EXI_ISO_20_ACDP_10_EVSEREADY_TO_CHARGE_TYPE                                      (Exi_RootElementIdType)913U
#define EXI_ISO_20_ACDP_10_EVSEUTILITY_INTERRUPT_EVENT_TYPE                              (Exi_RootElementIdType)914U
#define EXI_ISO_20_ACDP_10_EVSOC_TYPE                                                    (Exi_RootElementIdType)915U
#define EXI_ISO_20_ACDP_10_EVTECHNICAL_STATUS_TYPE                                       (Exi_RootElementIdType)916U
#define EXI_ISO_20_ACDP_10_EVTIMEOUT_TYPE                                                (Exi_RootElementIdType)917U
#define EXI_ISO_20_ACDP_10_EVWLANSTRENGTH_TYPE                                           (Exi_RootElementIdType)918U
#define EXI_SCHEMA_SET_ISO_20_ACDP_10_TYPE                                               (Exi_RootElementIdType)9U

/**********************************************************************************************************************
 *  ELEMENT IDENTIFIER DEFINES
**********************************************************************************************************************/
#define EXI_ISO_20_ACDP_10_EI_HEADER                                             (uint16)0U
#define EXI_ISO_20_ACDP_10_EI_HEADER_SE                                          (uint16)1U
#define EXI_ISO_20_ACDP_10_EI_HEADER_CT                                          (uint16)2U
#define EXI_ISO_20_ACDP_10_EI_HEADER_EE                                          (uint16)3U
#define EXI_ISO_20_ACDP_10_EI_HEADER_AT                                          (uint16)4U
#define EXI_ISO_20_ACDP_10_EI_EVELECTRICAL_CHARGING_DEVICE_STATUS                (uint16)5U
#define EXI_ISO_20_ACDP_10_EI_EVELECTRICAL_CHARGING_DEVICE_STATUS_SE             (uint16)6U
#define EXI_ISO_20_ACDP_10_EI_EVELECTRICAL_CHARGING_DEVICE_STATUS_CT             (uint16)7U
#define EXI_ISO_20_ACDP_10_EI_EVELECTRICAL_CHARGING_DEVICE_STATUS_EE             (uint16)8U
#define EXI_ISO_20_ACDP_10_EI_EVELECTRICAL_CHARGING_DEVICE_STATUS_AT             (uint16)9U
#define EXI_ISO_20_ACDP_10_EI_ACDP_CONNECT_REQ                                   (uint16)10U
#define EXI_ISO_20_ACDP_10_EI_ACDP_CONNECT_REQ_SE                                (uint16)11U
#define EXI_ISO_20_ACDP_10_EI_ACDP_CONNECT_REQ_CT                                (uint16)12U
#define EXI_ISO_20_ACDP_10_EI_ACDP_CONNECT_REQ_EE                                (uint16)13U
#define EXI_ISO_20_ACDP_10_EI_ACDP_CONNECT_REQ_AT                                (uint16)14U
#define EXI_ISO_20_ACDP_10_EI_RESPONSE_CODE                                      (uint16)15U
#define EXI_ISO_20_ACDP_10_EI_RESPONSE_CODE_SE                                   (uint16)16U
#define EXI_ISO_20_ACDP_10_EI_RESPONSE_CODE_CT                                   (uint16)17U
#define EXI_ISO_20_ACDP_10_EI_RESPONSE_CODE_EE                                   (uint16)18U
#define EXI_ISO_20_ACDP_10_EI_RESPONSE_CODE_AT                                   (uint16)19U
#define EXI_ISO_20_ACDP_10_EI_EVSEPROCESSING                                     (uint16)20U
#define EXI_ISO_20_ACDP_10_EI_EVSEPROCESSING_SE                                  (uint16)21U
#define EXI_ISO_20_ACDP_10_EI_EVSEPROCESSING_CT                                  (uint16)22U
#define EXI_ISO_20_ACDP_10_EI_EVSEPROCESSING_EE                                  (uint16)23U
#define EXI_ISO_20_ACDP_10_EI_EVSEPROCESSING_AT                                  (uint16)24U
#define EXI_ISO_20_ACDP_10_EI_EVSEELECTRICAL_CHARGING_DEVICE_STATUS              (uint16)25U
#define EXI_ISO_20_ACDP_10_EI_EVSEELECTRICAL_CHARGING_DEVICE_STATUS_SE           (uint16)26U
#define EXI_ISO_20_ACDP_10_EI_EVSEELECTRICAL_CHARGING_DEVICE_STATUS_CT           (uint16)27U
#define EXI_ISO_20_ACDP_10_EI_EVSEELECTRICAL_CHARGING_DEVICE_STATUS_EE           (uint16)28U
#define EXI_ISO_20_ACDP_10_EI_EVSEELECTRICAL_CHARGING_DEVICE_STATUS_AT           (uint16)29U
#define EXI_ISO_20_ACDP_10_EI_EVSEMECHANICAL_CHARGING_DEVICE_STATUS              (uint16)30U
#define EXI_ISO_20_ACDP_10_EI_EVSEMECHANICAL_CHARGING_DEVICE_STATUS_SE           (uint16)31U
#define EXI_ISO_20_ACDP_10_EI_EVSEMECHANICAL_CHARGING_DEVICE_STATUS_CT           (uint16)32U
#define EXI_ISO_20_ACDP_10_EI_EVSEMECHANICAL_CHARGING_DEVICE_STATUS_EE           (uint16)33U
#define EXI_ISO_20_ACDP_10_EI_EVSEMECHANICAL_CHARGING_DEVICE_STATUS_AT           (uint16)34U
#define EXI_ISO_20_ACDP_10_EI_ACDP_CONNECT_RES                                   (uint16)35U
#define EXI_ISO_20_ACDP_10_EI_ACDP_CONNECT_RES_SE                                (uint16)36U
#define EXI_ISO_20_ACDP_10_EI_ACDP_CONNECT_RES_CT                                (uint16)37U
#define EXI_ISO_20_ACDP_10_EI_ACDP_CONNECT_RES_EE                                (uint16)38U
#define EXI_ISO_20_ACDP_10_EI_ACDP_CONNECT_RES_AT                                (uint16)39U
#define EXI_ISO_20_ACDP_10_EI_EVTECHNICAL_STATUS                                 (uint16)40U
#define EXI_ISO_20_ACDP_10_EI_EVTECHNICAL_STATUS_SE                              (uint16)41U
#define EXI_ISO_20_ACDP_10_EI_EVTECHNICAL_STATUS_CT                              (uint16)42U
#define EXI_ISO_20_ACDP_10_EI_EVTECHNICAL_STATUS_EE                              (uint16)43U
#define EXI_ISO_20_ACDP_10_EI_EVTECHNICAL_STATUS_AT                              (uint16)44U
#define EXI_ISO_20_ACDP_10_EI_ACDP_SYSTEM_STATUS_REQ                             (uint16)45U
#define EXI_ISO_20_ACDP_10_EI_ACDP_SYSTEM_STATUS_REQ_SE                          (uint16)46U
#define EXI_ISO_20_ACDP_10_EI_ACDP_SYSTEM_STATUS_REQ_CT                          (uint16)47U
#define EXI_ISO_20_ACDP_10_EI_ACDP_SYSTEM_STATUS_REQ_EE                          (uint16)48U
#define EXI_ISO_20_ACDP_10_EI_ACDP_SYSTEM_STATUS_REQ_AT                          (uint16)49U
#define EXI_ISO_20_ACDP_10_EI_EVSEREADY_TO_CHARGE                                (uint16)50U
#define EXI_ISO_20_ACDP_10_EI_EVSEREADY_TO_CHARGE_SE                             (uint16)51U
#define EXI_ISO_20_ACDP_10_EI_EVSEREADY_TO_CHARGE_CT                             (uint16)52U
#define EXI_ISO_20_ACDP_10_EI_EVSEREADY_TO_CHARGE_EE                             (uint16)53U
#define EXI_ISO_20_ACDP_10_EI_EVSEREADY_TO_CHARGE_AT                             (uint16)54U
#define EXI_ISO_20_ACDP_10_EI_EVSEISOLATION_STATUS                               (uint16)55U
#define EXI_ISO_20_ACDP_10_EI_EVSEISOLATION_STATUS_SE                            (uint16)56U
#define EXI_ISO_20_ACDP_10_EI_EVSEISOLATION_STATUS_CT                            (uint16)57U
#define EXI_ISO_20_ACDP_10_EI_EVSEISOLATION_STATUS_EE                            (uint16)58U
#define EXI_ISO_20_ACDP_10_EI_EVSEISOLATION_STATUS_AT                            (uint16)59U
#define EXI_ISO_20_ACDP_10_EI_EVSEDISABLED                                       (uint16)60U
#define EXI_ISO_20_ACDP_10_EI_EVSEDISABLED_SE                                    (uint16)61U
#define EXI_ISO_20_ACDP_10_EI_EVSEDISABLED_CT                                    (uint16)62U
#define EXI_ISO_20_ACDP_10_EI_EVSEDISABLED_EE                                    (uint16)63U
#define EXI_ISO_20_ACDP_10_EI_EVSEDISABLED_AT                                    (uint16)64U
#define EXI_ISO_20_ACDP_10_EI_EVSEUTILITY_INTERRUPT_EVENT                        (uint16)65U
#define EXI_ISO_20_ACDP_10_EI_EVSEUTILITY_INTERRUPT_EVENT_SE                     (uint16)66U
#define EXI_ISO_20_ACDP_10_EI_EVSEUTILITY_INTERRUPT_EVENT_CT                     (uint16)67U
#define EXI_ISO_20_ACDP_10_EI_EVSEUTILITY_INTERRUPT_EVENT_EE                     (uint16)68U
#define EXI_ISO_20_ACDP_10_EI_EVSEUTILITY_INTERRUPT_EVENT_AT                     (uint16)69U
#define EXI_ISO_20_ACDP_10_EI_EVSEEMERGENCY_SHUTDOWN                             (uint16)70U
#define EXI_ISO_20_ACDP_10_EI_EVSEEMERGENCY_SHUTDOWN_SE                          (uint16)71U
#define EXI_ISO_20_ACDP_10_EI_EVSEEMERGENCY_SHUTDOWN_CT                          (uint16)72U
#define EXI_ISO_20_ACDP_10_EI_EVSEEMERGENCY_SHUTDOWN_EE                          (uint16)73U
#define EXI_ISO_20_ACDP_10_EI_EVSEEMERGENCY_SHUTDOWN_AT                          (uint16)74U
#define EXI_ISO_20_ACDP_10_EI_EVSEMALFUNCTION                                    (uint16)75U
#define EXI_ISO_20_ACDP_10_EI_EVSEMALFUNCTION_SE                                 (uint16)76U
#define EXI_ISO_20_ACDP_10_EI_EVSEMALFUNCTION_CT                                 (uint16)77U
#define EXI_ISO_20_ACDP_10_EI_EVSEMALFUNCTION_EE                                 (uint16)78U
#define EXI_ISO_20_ACDP_10_EI_EVSEMALFUNCTION_AT                                 (uint16)79U
#define EXI_ISO_20_ACDP_10_EI_EVIN_CHARGE_POSITION                               (uint16)80U
#define EXI_ISO_20_ACDP_10_EI_EVIN_CHARGE_POSITION_SE                            (uint16)81U
#define EXI_ISO_20_ACDP_10_EI_EVIN_CHARGE_POSITION_CT                            (uint16)82U
#define EXI_ISO_20_ACDP_10_EI_EVIN_CHARGE_POSITION_EE                            (uint16)83U
#define EXI_ISO_20_ACDP_10_EI_EVIN_CHARGE_POSITION_AT                            (uint16)84U
#define EXI_ISO_20_ACDP_10_EI_EVASSOCIATION_STATUS                               (uint16)85U
#define EXI_ISO_20_ACDP_10_EI_EVASSOCIATION_STATUS_SE                            (uint16)86U
#define EXI_ISO_20_ACDP_10_EI_EVASSOCIATION_STATUS_CT                            (uint16)87U
#define EXI_ISO_20_ACDP_10_EI_EVASSOCIATION_STATUS_EE                            (uint16)88U
#define EXI_ISO_20_ACDP_10_EI_EVASSOCIATION_STATUS_AT                            (uint16)89U
#define EXI_ISO_20_ACDP_10_EI_ACDP_SYSTEM_STATUS_RES                             (uint16)90U
#define EXI_ISO_20_ACDP_10_EI_ACDP_SYSTEM_STATUS_RES_SE                          (uint16)91U
#define EXI_ISO_20_ACDP_10_EI_ACDP_SYSTEM_STATUS_RES_CT                          (uint16)92U
#define EXI_ISO_20_ACDP_10_EI_ACDP_SYSTEM_STATUS_RES_EE                          (uint16)93U
#define EXI_ISO_20_ACDP_10_EI_ACDP_SYSTEM_STATUS_RES_AT                          (uint16)94U
#define EXI_ISO_20_ACDP_10_EI_EVMOBILITY_STATUS                                  (uint16)95U
#define EXI_ISO_20_ACDP_10_EI_EVMOBILITY_STATUS_SE                               (uint16)96U
#define EXI_ISO_20_ACDP_10_EI_EVMOBILITY_STATUS_CT                               (uint16)97U
#define EXI_ISO_20_ACDP_10_EI_EVMOBILITY_STATUS_EE                               (uint16)98U
#define EXI_ISO_20_ACDP_10_EI_EVMOBILITY_STATUS_AT                               (uint16)99U
#define EXI_ISO_20_ACDP_10_EI_EVPOSITIONING_SUPPORT                              (uint16)100U
#define EXI_ISO_20_ACDP_10_EI_EVPOSITIONING_SUPPORT_SE                           (uint16)101U
#define EXI_ISO_20_ACDP_10_EI_EVPOSITIONING_SUPPORT_CT                           (uint16)102U
#define EXI_ISO_20_ACDP_10_EI_EVPOSITIONING_SUPPORT_EE                           (uint16)103U
#define EXI_ISO_20_ACDP_10_EI_EVPOSITIONING_SUPPORT_AT                           (uint16)104U
#define EXI_ISO_20_ACDP_10_EI_ACDP_VEHICLE_POSITIONING_REQ                       (uint16)105U
#define EXI_ISO_20_ACDP_10_EI_ACDP_VEHICLE_POSITIONING_REQ_SE                    (uint16)106U
#define EXI_ISO_20_ACDP_10_EI_ACDP_VEHICLE_POSITIONING_REQ_CT                    (uint16)107U
#define EXI_ISO_20_ACDP_10_EI_ACDP_VEHICLE_POSITIONING_REQ_EE                    (uint16)108U
#define EXI_ISO_20_ACDP_10_EI_ACDP_VEHICLE_POSITIONING_REQ_AT                    (uint16)109U
#define EXI_ISO_20_ACDP_10_EI_EVSEPOSITIONING_SUPPORT                            (uint16)110U
#define EXI_ISO_20_ACDP_10_EI_EVSEPOSITIONING_SUPPORT_SE                         (uint16)111U
#define EXI_ISO_20_ACDP_10_EI_EVSEPOSITIONING_SUPPORT_CT                         (uint16)112U
#define EXI_ISO_20_ACDP_10_EI_EVSEPOSITIONING_SUPPORT_EE                         (uint16)113U
#define EXI_ISO_20_ACDP_10_EI_EVSEPOSITIONING_SUPPORT_AT                         (uint16)114U
#define EXI_ISO_20_ACDP_10_EI_EVRELATIVE_XDEVIATION                              (uint16)115U
#define EXI_ISO_20_ACDP_10_EI_EVRELATIVE_XDEVIATION_SE                           (uint16)116U
#define EXI_ISO_20_ACDP_10_EI_EVRELATIVE_XDEVIATION_CT                           (uint16)117U
#define EXI_ISO_20_ACDP_10_EI_EVRELATIVE_XDEVIATION_EE                           (uint16)118U
#define EXI_ISO_20_ACDP_10_EI_EVRELATIVE_XDEVIATION_AT                           (uint16)119U
#define EXI_ISO_20_ACDP_10_EI_EVRELATIVE_YDEVIATION                              (uint16)120U
#define EXI_ISO_20_ACDP_10_EI_EVRELATIVE_YDEVIATION_SE                           (uint16)121U
#define EXI_ISO_20_ACDP_10_EI_EVRELATIVE_YDEVIATION_CT                           (uint16)122U
#define EXI_ISO_20_ACDP_10_EI_EVRELATIVE_YDEVIATION_EE                           (uint16)123U
#define EXI_ISO_20_ACDP_10_EI_EVRELATIVE_YDEVIATION_AT                           (uint16)124U
#define EXI_ISO_20_ACDP_10_EI_CONTACT_WINDOW_XC                                  (uint16)125U
#define EXI_ISO_20_ACDP_10_EI_CONTACT_WINDOW_XC_SE                               (uint16)126U
#define EXI_ISO_20_ACDP_10_EI_CONTACT_WINDOW_XC_CT                               (uint16)127U
#define EXI_ISO_20_ACDP_10_EI_CONTACT_WINDOW_XC_EE                               (uint16)128U
#define EXI_ISO_20_ACDP_10_EI_CONTACT_WINDOW_XC_AT                               (uint16)129U
#define EXI_ISO_20_ACDP_10_EI_CONTACT_WINDOW_YC                                  (uint16)130U
#define EXI_ISO_20_ACDP_10_EI_CONTACT_WINDOW_YC_SE                               (uint16)131U
#define EXI_ISO_20_ACDP_10_EI_CONTACT_WINDOW_YC_CT                               (uint16)132U
#define EXI_ISO_20_ACDP_10_EI_CONTACT_WINDOW_YC_EE                               (uint16)133U
#define EXI_ISO_20_ACDP_10_EI_CONTACT_WINDOW_YC_AT                               (uint16)134U
#define EXI_ISO_20_ACDP_10_EI_ACDP_VEHICLE_POSITIONING_RES                       (uint16)135U
#define EXI_ISO_20_ACDP_10_EI_ACDP_VEHICLE_POSITIONING_RES_SE                    (uint16)136U
#define EXI_ISO_20_ACDP_10_EI_ACDP_VEHICLE_POSITIONING_RES_CT                    (uint16)137U
#define EXI_ISO_20_ACDP_10_EI_ACDP_VEHICLE_POSITIONING_RES_EE                    (uint16)138U
#define EXI_ISO_20_ACDP_10_EI_ACDP_VEHICLE_POSITIONING_RES_AT                    (uint16)139U
#define EXI_ISO_20_ACDP_10_EI_EVREADY_TO_CHARGE                                  (uint16)140U
#define EXI_ISO_20_ACDP_10_EI_EVREADY_TO_CHARGE_SE                               (uint16)141U
#define EXI_ISO_20_ACDP_10_EI_EVREADY_TO_CHARGE_CT                               (uint16)142U
#define EXI_ISO_20_ACDP_10_EI_EVREADY_TO_CHARGE_EE                               (uint16)143U
#define EXI_ISO_20_ACDP_10_EI_EVREADY_TO_CHARGE_AT                               (uint16)144U
#define EXI_ISO_20_ACDP_10_EI_EVIMMOBILIZATION_REQUEST                           (uint16)145U
#define EXI_ISO_20_ACDP_10_EI_EVIMMOBILIZATION_REQUEST_SE                        (uint16)146U
#define EXI_ISO_20_ACDP_10_EI_EVIMMOBILIZATION_REQUEST_CT                        (uint16)147U
#define EXI_ISO_20_ACDP_10_EI_EVIMMOBILIZATION_REQUEST_EE                        (uint16)148U
#define EXI_ISO_20_ACDP_10_EI_EVIMMOBILIZATION_REQUEST_AT                        (uint16)149U
#define EXI_ISO_20_ACDP_10_EI_EVIMMOBILIZED                                      (uint16)150U
#define EXI_ISO_20_ACDP_10_EI_EVIMMOBILIZED_SE                                   (uint16)151U
#define EXI_ISO_20_ACDP_10_EI_EVIMMOBILIZED_CT                                   (uint16)152U
#define EXI_ISO_20_ACDP_10_EI_EVIMMOBILIZED_EE                                   (uint16)153U
#define EXI_ISO_20_ACDP_10_EI_EVIMMOBILIZED_AT                                   (uint16)154U
#define EXI_ISO_20_ACDP_10_EI_EVWLANSTRENGTH                                     (uint16)155U
#define EXI_ISO_20_ACDP_10_EI_EVWLANSTRENGTH_SE                                  (uint16)156U
#define EXI_ISO_20_ACDP_10_EI_EVWLANSTRENGTH_CT                                  (uint16)157U
#define EXI_ISO_20_ACDP_10_EI_EVWLANSTRENGTH_EE                                  (uint16)158U
#define EXI_ISO_20_ACDP_10_EI_EVWLANSTRENGTH_AT                                  (uint16)159U
#define EXI_ISO_20_ACDP_10_EI_EVCPSTATUS                                         (uint16)160U
#define EXI_ISO_20_ACDP_10_EI_EVCPSTATUS_SE                                      (uint16)161U
#define EXI_ISO_20_ACDP_10_EI_EVCPSTATUS_CT                                      (uint16)162U
#define EXI_ISO_20_ACDP_10_EI_EVCPSTATUS_EE                                      (uint16)163U
#define EXI_ISO_20_ACDP_10_EI_EVCPSTATUS_AT                                      (uint16)164U
#define EXI_ISO_20_ACDP_10_EI_EVSOC                                              (uint16)165U
#define EXI_ISO_20_ACDP_10_EI_EVSOC_SE                                           (uint16)166U
#define EXI_ISO_20_ACDP_10_EI_EVSOC_CT                                           (uint16)167U
#define EXI_ISO_20_ACDP_10_EI_EVSOC_EE                                           (uint16)168U
#define EXI_ISO_20_ACDP_10_EI_EVSOC_AT                                           (uint16)169U
#define EXI_ISO_20_ACDP_10_EI_EVERROR_CODE                                       (uint16)170U
#define EXI_ISO_20_ACDP_10_EI_EVERROR_CODE_SE                                    (uint16)171U
#define EXI_ISO_20_ACDP_10_EI_EVERROR_CODE_CT                                    (uint16)172U
#define EXI_ISO_20_ACDP_10_EI_EVERROR_CODE_EE                                    (uint16)173U
#define EXI_ISO_20_ACDP_10_EI_EVERROR_CODE_AT                                    (uint16)174U
#define EXI_ISO_20_ACDP_10_EI_EVTIMEOUT                                          (uint16)175U
#define EXI_ISO_20_ACDP_10_EI_EVTIMEOUT_SE                                       (uint16)176U
#define EXI_ISO_20_ACDP_10_EI_EVTIMEOUT_CT                                       (uint16)177U
#define EXI_ISO_20_ACDP_10_EI_EVTIMEOUT_EE                                       (uint16)178U
#define EXI_ISO_20_ACDP_10_EI_EVTIMEOUT_AT                                       (uint16)179U
#define EXI_ISO_20_ACDP_10_EI_CP_STATUS                                          (uint16)180U
#define EXI_ISO_20_ACDP_10_EI_CP_STATUS_SE                                       (uint16)181U
#define EXI_ISO_20_ACDP_10_EI_CP_STATUS_CT                                       (uint16)182U
#define EXI_ISO_20_ACDP_10_EI_CP_STATUS_EE                                       (uint16)183U
#define EXI_ISO_20_ACDP_10_EI_CP_STATUS_AT                                       (uint16)184U
#define EXI_ISO_20_ACDP_10_EI_ELECTRICAL_CHARGING_DEVICE_STATUS                  (uint16)185U
#define EXI_ISO_20_ACDP_10_EI_ELECTRICAL_CHARGING_DEVICE_STATUS_SE               (uint16)186U
#define EXI_ISO_20_ACDP_10_EI_ELECTRICAL_CHARGING_DEVICE_STATUS_CT               (uint16)187U
#define EXI_ISO_20_ACDP_10_EI_ELECTRICAL_CHARGING_DEVICE_STATUS_EE               (uint16)188U
#define EXI_ISO_20_ACDP_10_EI_ELECTRICAL_CHARGING_DEVICE_STATUS_AT               (uint16)189U
#define EXI_ISO_20_ACDP_10_EI_ERROR_CODE                                         (uint16)190U
#define EXI_ISO_20_ACDP_10_EI_ERROR_CODE_SE                                      (uint16)191U
#define EXI_ISO_20_ACDP_10_EI_ERROR_CODE_CT                                      (uint16)192U
#define EXI_ISO_20_ACDP_10_EI_ERROR_CODE_EE                                      (uint16)193U
#define EXI_ISO_20_ACDP_10_EI_ERROR_CODE_AT                                      (uint16)194U
#define EXI_ISO_20_ACDP_10_EI_ISOLATION_STATUS                                   (uint16)195U
#define EXI_ISO_20_ACDP_10_EI_ISOLATION_STATUS_SE                                (uint16)196U
#define EXI_ISO_20_ACDP_10_EI_ISOLATION_STATUS_CT                                (uint16)197U
#define EXI_ISO_20_ACDP_10_EI_ISOLATION_STATUS_EE                                (uint16)198U
#define EXI_ISO_20_ACDP_10_EI_ISOLATION_STATUS_AT                                (uint16)199U
#define EXI_ISO_20_ACDP_10_EI_MECHANICAL_CHARGING_DEVICE_STATUS                  (uint16)200U
#define EXI_ISO_20_ACDP_10_EI_MECHANICAL_CHARGING_DEVICE_STATUS_SE               (uint16)201U
#define EXI_ISO_20_ACDP_10_EI_MECHANICAL_CHARGING_DEVICE_STATUS_CT               (uint16)202U
#define EXI_ISO_20_ACDP_10_EI_MECHANICAL_CHARGING_DEVICE_STATUS_EE               (uint16)203U
#define EXI_ISO_20_ACDP_10_EI_MECHANICAL_CHARGING_DEVICE_STATUS_AT               (uint16)204U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  EXI_ISO_20_ACDP_10_CP_STATUS_TYPE_STATE_A = 0u,
  EXI_ISO_20_ACDP_10_CP_STATUS_TYPE_STATE_B = 1u,
  EXI_ISO_20_ACDP_10_CP_STATUS_TYPE_STATE_C = 2u,
  EXI_ISO_20_ACDP_10_CP_STATUS_TYPE_STATE_D = 3u,
  EXI_ISO_20_ACDP_10_CP_STATUS_TYPE_STATE_E = 4u
} Exi_ISO_20_ACDP_10_cpStatusType;

typedef enum
{
  EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_OK_NO_EVERROR = 0u,
  EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_FAILED = 1u,
  EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_FAILED_EMERGENCY_EVENT = 2u,
  EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_FAILED_BREAKER = 3u,
  EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_FAILED_RESSTEMPERATURE_INHIBIT = 4u,
  EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_FAILED_RESS = 5u,
  EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_FAILED_CHARGING_CURRENT_DIFFERENTIAL = 6u,
  EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_FAILED_CHARGING_VOLTAGE_OUT_OF_RANGE = 7u,
  EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_FAILED_RESERVED1 = 8u,
  EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_FAILED_RESERVED2 = 9u
} Exi_ISO_20_ACDP_10_errorCodeType;

typedef enum
{
  EXI_ISO_20_ACDP_10_ISOLATION_STATUS_TYPE_INVALID = 0u,
  EXI_ISO_20_ACDP_10_ISOLATION_STATUS_TYPE_SAFE = 1u,
  EXI_ISO_20_ACDP_10_ISOLATION_STATUS_TYPE_WARNING = 2u,
  EXI_ISO_20_ACDP_10_ISOLATION_STATUS_TYPE_FAULT = 3u
} Exi_ISO_20_ACDP_10_isolationStatusType;

typedef enum
{
  EXI_ISO_20_ACDP_10_ELECTRICAL_CHARGING_DEVICE_STATUS_TYPE_STATE_A = 0u,
  EXI_ISO_20_ACDP_10_ELECTRICAL_CHARGING_DEVICE_STATUS_TYPE_STATE_B = 1u,
  EXI_ISO_20_ACDP_10_ELECTRICAL_CHARGING_DEVICE_STATUS_TYPE_STATE_C = 2u,
  EXI_ISO_20_ACDP_10_ELECTRICAL_CHARGING_DEVICE_STATUS_TYPE_STATE_D = 3u
} Exi_ISO_20_ACDP_10_electricalChargingDeviceStatusType;

typedef enum
{
  EXI_ISO_20_ACDP_10_MECHANICAL_CHARGING_DEVICE_STATUS_TYPE_HOME = 0u,
  EXI_ISO_20_ACDP_10_MECHANICAL_CHARGING_DEVICE_STATUS_TYPE_MOVING = 1u,
  EXI_ISO_20_ACDP_10_MECHANICAL_CHARGING_DEVICE_STATUS_TYPE_END_POSITION = 2u
} Exi_ISO_20_ACDP_10_mechanicalChargingDeviceStatusType;

typedef struct Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType;

typedef struct Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningResType Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningResType;

typedef struct Exi_ISO_20_ACDP_10_ACDP_ConnectReqType Exi_ISO_20_ACDP_10_ACDP_ConnectReqType;

typedef struct Exi_ISO_20_ACDP_10_ACDP_ConnectResType Exi_ISO_20_ACDP_10_ACDP_ConnectResType;

typedef struct Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType;

typedef struct Exi_ISO_20_ACDP_10_ACDP_SystemStatusResType Exi_ISO_20_ACDP_10_ACDP_SystemStatusResType;

typedef struct Exi_ISO_20_ACDP_10_EVTechnicalStatusType Exi_ISO_20_ACDP_10_EVTechnicalStatusType;

struct Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  boolean EVMobilityStatus;
  boolean EVPositioningSupport;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  sint16 ContactWindowXc;
  sint16 ContactWindowYc;
  sint16 EVRelativeXDeviation;
  sint16 EVRelativeYDeviation;
  Exi_ISO_20_CT_10_processingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  boolean EVInChargePosition;
  boolean EVSEPositioningSupport;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (2u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_ACDP_10_ACDP_ConnectReqType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_ACDP_10_electricalChargingDeviceStatusType EVElectricalChargingDeviceStatus; /* Value range: 0 to 3; See type for exact values. */
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

struct Exi_ISO_20_ACDP_10_ACDP_ConnectResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_ACDP_10_electricalChargingDeviceStatusType EVSEElectricalChargingDeviceStatus; /* Value range: 0 to 3; See type for exact values. */
  Exi_ISO_20_ACDP_10_mechanicalChargingDeviceStatusType EVSEMechanicalChargingDeviceStatus; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CT_10_processingType EVSEProcessing; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (4u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (4u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (4u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType
{
  Exi_ISO_20_ACDP_10_EVTechnicalStatusType* EVTechnicalStatus;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
};

struct Exi_ISO_20_ACDP_10_ACDP_SystemStatusResType
{
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_ACDP_10_isolationStatusType EVSEIsolationStatus; /* Value range: 0 to 3; See type for exact values. */
  Exi_ISO_20_ACDP_10_mechanicalChargingDeviceStatusType EVSEMechanicalChargingDeviceStatus; /* Value range: 0 to 2; See type for exact values. */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  boolean EVAssociationStatus;
  boolean EVInChargePosition;
  boolean EVSEDisabled;
  boolean EVSEEmergencyShutdown;
  boolean EVSEMalfunction;
  boolean EVSEReadyToCharge;
  boolean EVSEUtilityInterruptEvent;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 1 ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 3u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (3u * EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE) + 3u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_ACDP_10_EVTechnicalStatusType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVWLANStrength;
  Exi_ISO_20_ACDP_10_cpStatusType EVCPStatus; /* Value range: 0 to 4; See type for exact values. */
  Exi_ISO_20_ACDP_10_errorCodeType EVErrorCode; /* Value range: 0 to 9; See type for exact values. */
  boolean EVImmobilizationRequest;
  boolean EVImmobilized;
  boolean EVReadyToCharge;
  boolean EVTimeout;
  sint8 EVSOC; /* Value range: max: 100 */
  Exi_BitType EVCPStatusFlag : 1;
  Exi_BitType EVErrorCodeFlag : 1;
  Exi_BitType EVImmobilizedFlag : 1;
  Exi_BitType EVSOCFlag : 1;
  Exi_BitType EVTimeoutFlag : 1;
  Exi_BitType EVWLANStrengthFlag : 1;
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
#endif  /* EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET */

/* PRQA L:IDENTIFIER_NAMES */
/* PRQA L:NAMESPACE */
/* PRQA L:UNION */


#endif /* EXI_ISO_20_ACDP_10_SCHEMA_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_ACDP_10_SchemaTypes.h
 **********************************************************************************************************************/
