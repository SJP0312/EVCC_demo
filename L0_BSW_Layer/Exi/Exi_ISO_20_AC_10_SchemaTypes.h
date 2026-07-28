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
/**        \file  Exi_ISO_20_AC_10_SchemaTypes.h
 *        \brief  Efficient XML Interchange ISO_20_AC_10 types header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_AC_10 types.
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

#if !defined (EXI_ISO_20_AC_10_SCHEMA_TYPES_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_AC_10_SCHEMA_TYPES_H

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
#define EXI_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE                             (Exi_RootElementIdType)143U
#define EXI_ISO_20_AC_10_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE                             (Exi_RootElementIdType)144U
#define EXI_ISO_20_AC_10_AC_CHARGE_LOOP_REQ_TYPE                                         (Exi_RootElementIdType)145U
#define EXI_ISO_20_AC_10_AC_CHARGE_LOOP_RES_TYPE                                         (Exi_RootElementIdType)146U
#define EXI_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE                          (Exi_RootElementIdType)147U
#define EXI_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_RES_TYPE                          (Exi_RootElementIdType)148U
#define EXI_ISO_20_AC_10_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE                         (Exi_RootElementIdType)149U
#define EXI_ISO_20_AC_10_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE                         (Exi_RootElementIdType)150U
#define EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE                          (Exi_RootElementIdType)151U
#define EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE                          (Exi_RootElementIdType)152U
#define EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE                        (Exi_RootElementIdType)153U
#define EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE                        (Exi_RootElementIdType)154U
#define EXI_ISO_20_AC_10_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE                              (Exi_RootElementIdType)155U
#define EXI_ISO_20_AC_10_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE                              (Exi_RootElementIdType)156U
#define EXI_ISO_20_AC_10_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE                            (Exi_RootElementIdType)157U
#define EXI_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE                            (Exi_RootElementIdType)158U

#if (defined(EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* Elements */
#define EXI_ISO_20_AC_10_CLREQ_CONTROL_MODE_TYPE                                         (Exi_RootElementIdType)720U
#define EXI_ISO_20_AC_10_CLRES_CONTROL_MODE_TYPE                                         (Exi_RootElementIdType)721U
#define EXI_ISO_20_AC_10_EVMAXIMUM_CHARGE_POWER_TYPE                                     (Exi_RootElementIdType)722U
#define EXI_ISO_20_AC_10_EVMAXIMUM_CHARGE_POWER_L2_TYPE                                  (Exi_RootElementIdType)723U
#define EXI_ISO_20_AC_10_EVMAXIMUM_CHARGE_POWER_L3_TYPE                                  (Exi_RootElementIdType)724U
#define EXI_ISO_20_AC_10_EVMAXIMUM_DISCHARGE_POWER_TYPE                                  (Exi_RootElementIdType)725U
#define EXI_ISO_20_AC_10_EVMAXIMUM_DISCHARGE_POWER_L2_TYPE                               (Exi_RootElementIdType)726U
#define EXI_ISO_20_AC_10_EVMAXIMUM_DISCHARGE_POWER_L3_TYPE                               (Exi_RootElementIdType)727U
#define EXI_ISO_20_AC_10_EVMAXIMUM_V2XENERGY_REQUEST_TYPE                                (Exi_RootElementIdType)728U
#define EXI_ISO_20_AC_10_EVMINIMUM_CHARGE_POWER_TYPE                                     (Exi_RootElementIdType)729U
#define EXI_ISO_20_AC_10_EVMINIMUM_CHARGE_POWER_L2_TYPE                                  (Exi_RootElementIdType)730U
#define EXI_ISO_20_AC_10_EVMINIMUM_CHARGE_POWER_L3_TYPE                                  (Exi_RootElementIdType)731U
#define EXI_ISO_20_AC_10_EVMINIMUM_DISCHARGE_POWER_TYPE                                  (Exi_RootElementIdType)732U
#define EXI_ISO_20_AC_10_EVMINIMUM_DISCHARGE_POWER_L2_TYPE                               (Exi_RootElementIdType)733U
#define EXI_ISO_20_AC_10_EVMINIMUM_DISCHARGE_POWER_L3_TYPE                               (Exi_RootElementIdType)734U
#define EXI_ISO_20_AC_10_EVMINIMUM_V2XENERGY_REQUEST_TYPE                                (Exi_RootElementIdType)735U
#define EXI_ISO_20_AC_10_EVPRESENT_ACTIVE_POWER_TYPE                                     (Exi_RootElementIdType)736U
#define EXI_ISO_20_AC_10_EVPRESENT_ACTIVE_POWER_L2_TYPE                                  (Exi_RootElementIdType)737U
#define EXI_ISO_20_AC_10_EVPRESENT_ACTIVE_POWER_L3_TYPE                                  (Exi_RootElementIdType)738U
#define EXI_ISO_20_AC_10_EVPRESENT_REACTIVE_POWER_TYPE                                   (Exi_RootElementIdType)739U
#define EXI_ISO_20_AC_10_EVPRESENT_REACTIVE_POWER_L2_TYPE                                (Exi_RootElementIdType)740U
#define EXI_ISO_20_AC_10_EVPRESENT_REACTIVE_POWER_L3_TYPE                                (Exi_RootElementIdType)741U
#define EXI_ISO_20_AC_10_EVSEMAXIMUM_CHARGE_POWER_TYPE                                   (Exi_RootElementIdType)742U
#define EXI_ISO_20_AC_10_EVSEMAXIMUM_CHARGE_POWER_L2_TYPE                                (Exi_RootElementIdType)743U
#define EXI_ISO_20_AC_10_EVSEMAXIMUM_CHARGE_POWER_L3_TYPE                                (Exi_RootElementIdType)744U
#define EXI_ISO_20_AC_10_EVSEMAXIMUM_DISCHARGE_POWER_TYPE                                (Exi_RootElementIdType)745U
#define EXI_ISO_20_AC_10_EVSEMAXIMUM_DISCHARGE_POWER_L2_TYPE                             (Exi_RootElementIdType)746U
#define EXI_ISO_20_AC_10_EVSEMAXIMUM_DISCHARGE_POWER_L3_TYPE                             (Exi_RootElementIdType)747U
#define EXI_ISO_20_AC_10_EVSEMINIMUM_CHARGE_POWER_TYPE                                   (Exi_RootElementIdType)748U
#define EXI_ISO_20_AC_10_EVSEMINIMUM_CHARGE_POWER_L2_TYPE                                (Exi_RootElementIdType)749U
#define EXI_ISO_20_AC_10_EVSEMINIMUM_CHARGE_POWER_L3_TYPE                                (Exi_RootElementIdType)750U
#define EXI_ISO_20_AC_10_EVSEMINIMUM_DISCHARGE_POWER_TYPE                                (Exi_RootElementIdType)751U
#define EXI_ISO_20_AC_10_EVSEMINIMUM_DISCHARGE_POWER_L2_TYPE                             (Exi_RootElementIdType)752U
#define EXI_ISO_20_AC_10_EVSEMINIMUM_DISCHARGE_POWER_L3_TYPE                             (Exi_RootElementIdType)753U
#define EXI_ISO_20_AC_10_EVSENOMINAL_FREQUENCY_TYPE                                      (Exi_RootElementIdType)754U
#define EXI_ISO_20_AC_10_EVSEPOWER_RAMP_LIMITATION_TYPE                                  (Exi_RootElementIdType)755U
#define EXI_ISO_20_AC_10_EVSEPRESENT_ACTIVE_POWER_TYPE                                   (Exi_RootElementIdType)756U
#define EXI_ISO_20_AC_10_EVSEPRESENT_ACTIVE_POWER_L2_TYPE                                (Exi_RootElementIdType)757U
#define EXI_ISO_20_AC_10_EVSEPRESENT_ACTIVE_POWER_L3_TYPE                                (Exi_RootElementIdType)758U
#define EXI_ISO_20_AC_10_EVSETARGET_ACTIVE_POWER_TYPE                                    (Exi_RootElementIdType)759U
#define EXI_ISO_20_AC_10_EVSETARGET_ACTIVE_POWER_L2_TYPE                                 (Exi_RootElementIdType)760U
#define EXI_ISO_20_AC_10_EVSETARGET_ACTIVE_POWER_L3_TYPE                                 (Exi_RootElementIdType)761U
#define EXI_ISO_20_AC_10_EVSETARGET_FREQUENCY_TYPE                                       (Exi_RootElementIdType)762U
#define EXI_ISO_20_AC_10_EVSETARGET_REACTIVE_POWER_TYPE                                  (Exi_RootElementIdType)763U
#define EXI_ISO_20_AC_10_EVSETARGET_REACTIVE_POWER_L2_TYPE                               (Exi_RootElementIdType)764U
#define EXI_ISO_20_AC_10_EVSETARGET_REACTIVE_POWER_L3_TYPE                               (Exi_RootElementIdType)765U
#define EXI_ISO_20_AC_10_MAXIMUM_POWER_ASYMMETRY_TYPE                                    (Exi_RootElementIdType)766U
#define EXI_SCHEMA_SET_ISO_20_AC_10_TYPE                                                 (Exi_RootElementIdType)6U

/**********************************************************************************************************************
 *  ELEMENT IDENTIFIER DEFINES
**********************************************************************************************************************/
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER                             (uint16)0U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_SE                          (uint16)1U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_CT                          (uint16)2U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_EE                          (uint16)3U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_AT                          (uint16)4U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2                          (uint16)5U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_SE                       (uint16)6U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_CT                       (uint16)7U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_EE                       (uint16)8U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_AT                       (uint16)9U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3                          (uint16)10U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_SE                       (uint16)11U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_CT                       (uint16)12U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_EE                       (uint16)13U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_AT                       (uint16)14U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER                             (uint16)15U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_SE                          (uint16)16U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_CT                          (uint16)17U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_EE                          (uint16)18U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_AT                          (uint16)19U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2                          (uint16)20U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_SE                       (uint16)21U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_CT                       (uint16)22U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_EE                       (uint16)23U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_AT                       (uint16)24U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3                          (uint16)25U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_SE                       (uint16)26U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_CT                       (uint16)27U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_EE                       (uint16)28U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_AT                       (uint16)29U
#define EXI_ISO_20_AC_10_EI_AC_CPDREQ_ENERGY_TRANSFER_MODE                     (uint16)30U
#define EXI_ISO_20_AC_10_EI_AC_CPDREQ_ENERGY_TRANSFER_MODE_SE                  (uint16)31U
#define EXI_ISO_20_AC_10_EI_AC_CPDREQ_ENERGY_TRANSFER_MODE_CT                  (uint16)32U
#define EXI_ISO_20_AC_10_EI_AC_CPDREQ_ENERGY_TRANSFER_MODE_EE                  (uint16)33U
#define EXI_ISO_20_AC_10_EI_AC_CPDREQ_ENERGY_TRANSFER_MODE_AT                  (uint16)34U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER                           (uint16)35U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_SE                        (uint16)36U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_CT                        (uint16)37U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_EE                        (uint16)38U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_AT                        (uint16)39U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L2                        (uint16)40U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L2_SE                     (uint16)41U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L2_CT                     (uint16)42U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L2_EE                     (uint16)43U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L2_AT                     (uint16)44U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L3                        (uint16)45U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L3_SE                     (uint16)46U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L3_CT                     (uint16)47U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L3_EE                     (uint16)48U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L3_AT                     (uint16)49U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER                           (uint16)50U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_SE                        (uint16)51U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_CT                        (uint16)52U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_EE                        (uint16)53U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_AT                        (uint16)54U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L2                        (uint16)55U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L2_SE                     (uint16)56U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L2_CT                     (uint16)57U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L2_EE                     (uint16)58U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L2_AT                     (uint16)59U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L3                        (uint16)60U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L3_SE                     (uint16)61U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L3_CT                     (uint16)62U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L3_EE                     (uint16)63U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L3_AT                     (uint16)64U
#define EXI_ISO_20_AC_10_EI_EVSENOMINAL_FREQUENCY                              (uint16)65U
#define EXI_ISO_20_AC_10_EI_EVSENOMINAL_FREQUENCY_SE                           (uint16)66U
#define EXI_ISO_20_AC_10_EI_EVSENOMINAL_FREQUENCY_CT                           (uint16)67U
#define EXI_ISO_20_AC_10_EI_EVSENOMINAL_FREQUENCY_EE                           (uint16)68U
#define EXI_ISO_20_AC_10_EI_EVSENOMINAL_FREQUENCY_AT                           (uint16)69U
#define EXI_ISO_20_AC_10_EI_MAXIMUM_POWER_ASYMMETRY                            (uint16)70U
#define EXI_ISO_20_AC_10_EI_MAXIMUM_POWER_ASYMMETRY_SE                         (uint16)71U
#define EXI_ISO_20_AC_10_EI_MAXIMUM_POWER_ASYMMETRY_CT                         (uint16)72U
#define EXI_ISO_20_AC_10_EI_MAXIMUM_POWER_ASYMMETRY_EE                         (uint16)73U
#define EXI_ISO_20_AC_10_EI_MAXIMUM_POWER_ASYMMETRY_AT                         (uint16)74U
#define EXI_ISO_20_AC_10_EI_EVSEPOWER_RAMP_LIMITATION                          (uint16)75U
#define EXI_ISO_20_AC_10_EI_EVSEPOWER_RAMP_LIMITATION_SE                       (uint16)76U
#define EXI_ISO_20_AC_10_EI_EVSEPOWER_RAMP_LIMITATION_CT                       (uint16)77U
#define EXI_ISO_20_AC_10_EI_EVSEPOWER_RAMP_LIMITATION_EE                       (uint16)78U
#define EXI_ISO_20_AC_10_EI_EVSEPOWER_RAMP_LIMITATION_AT                       (uint16)79U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER                           (uint16)80U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_SE                        (uint16)81U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_CT                        (uint16)82U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_EE                        (uint16)83U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_AT                        (uint16)84U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2                        (uint16)85U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_SE                     (uint16)86U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_CT                     (uint16)87U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_EE                     (uint16)88U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_AT                     (uint16)89U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3                        (uint16)90U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_SE                     (uint16)91U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_CT                     (uint16)92U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_EE                     (uint16)93U
#define EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_AT                     (uint16)94U
#define EXI_ISO_20_AC_10_EI_AC_CPDRES_ENERGY_TRANSFER_MODE                     (uint16)95U
#define EXI_ISO_20_AC_10_EI_AC_CPDRES_ENERGY_TRANSFER_MODE_SE                  (uint16)96U
#define EXI_ISO_20_AC_10_EI_AC_CPDRES_ENERGY_TRANSFER_MODE_CT                  (uint16)97U
#define EXI_ISO_20_AC_10_EI_AC_CPDRES_ENERGY_TRANSFER_MODE_EE                  (uint16)98U
#define EXI_ISO_20_AC_10_EI_AC_CPDRES_ENERGY_TRANSFER_MODE_AT                  (uint16)99U
#define EXI_ISO_20_AC_10_EI_HEADER                                             (uint16)100U
#define EXI_ISO_20_AC_10_EI_HEADER_SE                                          (uint16)101U
#define EXI_ISO_20_AC_10_EI_HEADER_CT                                          (uint16)102U
#define EXI_ISO_20_AC_10_EI_HEADER_EE                                          (uint16)103U
#define EXI_ISO_20_AC_10_EI_HEADER_AT                                          (uint16)104U
#define EXI_ISO_20_AC_10_EI_DISPLAY_PARAMETERS                                 (uint16)105U
#define EXI_ISO_20_AC_10_EI_DISPLAY_PARAMETERS_SE                              (uint16)106U
#define EXI_ISO_20_AC_10_EI_DISPLAY_PARAMETERS_CT                              (uint16)107U
#define EXI_ISO_20_AC_10_EI_DISPLAY_PARAMETERS_EE                              (uint16)108U
#define EXI_ISO_20_AC_10_EI_DISPLAY_PARAMETERS_AT                              (uint16)109U
#define EXI_ISO_20_AC_10_EI_METER_INFO_REQUESTED                               (uint16)110U
#define EXI_ISO_20_AC_10_EI_METER_INFO_REQUESTED_SE                            (uint16)111U
#define EXI_ISO_20_AC_10_EI_METER_INFO_REQUESTED_CT                            (uint16)112U
#define EXI_ISO_20_AC_10_EI_METER_INFO_REQUESTED_EE                            (uint16)113U
#define EXI_ISO_20_AC_10_EI_METER_INFO_REQUESTED_AT                            (uint16)114U
#define EXI_ISO_20_AC_10_EI_CLREQ_CONTROL_MODE                                 (uint16)115U
#define EXI_ISO_20_AC_10_EI_CLREQ_CONTROL_MODE_SE                              (uint16)116U
#define EXI_ISO_20_AC_10_EI_CLREQ_CONTROL_MODE_CT                              (uint16)117U
#define EXI_ISO_20_AC_10_EI_CLREQ_CONTROL_MODE_EE                              (uint16)118U
#define EXI_ISO_20_AC_10_EI_CLREQ_CONTROL_MODE_AT                              (uint16)119U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_REQ                                 (uint16)120U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_REQ_SE                              (uint16)121U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_REQ_CT                              (uint16)122U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_REQ_EE                              (uint16)123U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_REQ_AT                              (uint16)124U
#define EXI_ISO_20_AC_10_EI_RESPONSE_CODE                                      (uint16)125U
#define EXI_ISO_20_AC_10_EI_RESPONSE_CODE_SE                                   (uint16)126U
#define EXI_ISO_20_AC_10_EI_RESPONSE_CODE_CT                                   (uint16)127U
#define EXI_ISO_20_AC_10_EI_RESPONSE_CODE_EE                                   (uint16)128U
#define EXI_ISO_20_AC_10_EI_RESPONSE_CODE_AT                                   (uint16)129U
#define EXI_ISO_20_AC_10_EI_EVSESTATUS                                         (uint16)130U
#define EXI_ISO_20_AC_10_EI_EVSESTATUS_SE                                      (uint16)131U
#define EXI_ISO_20_AC_10_EI_EVSESTATUS_CT                                      (uint16)132U
#define EXI_ISO_20_AC_10_EI_EVSESTATUS_EE                                      (uint16)133U
#define EXI_ISO_20_AC_10_EI_EVSESTATUS_AT                                      (uint16)134U
#define EXI_ISO_20_AC_10_EI_METER_INFO                                         (uint16)135U
#define EXI_ISO_20_AC_10_EI_METER_INFO_SE                                      (uint16)136U
#define EXI_ISO_20_AC_10_EI_METER_INFO_CT                                      (uint16)137U
#define EXI_ISO_20_AC_10_EI_METER_INFO_EE                                      (uint16)138U
#define EXI_ISO_20_AC_10_EI_METER_INFO_AT                                      (uint16)139U
#define EXI_ISO_20_AC_10_EI_RECEIPT                                            (uint16)140U
#define EXI_ISO_20_AC_10_EI_RECEIPT_SE                                         (uint16)141U
#define EXI_ISO_20_AC_10_EI_RECEIPT_CT                                         (uint16)142U
#define EXI_ISO_20_AC_10_EI_RECEIPT_EE                                         (uint16)143U
#define EXI_ISO_20_AC_10_EI_RECEIPT_AT                                         (uint16)144U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_FREQUENCY                               (uint16)145U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_FREQUENCY_SE                            (uint16)146U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_FREQUENCY_CT                            (uint16)147U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_FREQUENCY_EE                            (uint16)148U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_FREQUENCY_AT                            (uint16)149U
#define EXI_ISO_20_AC_10_EI_CLRES_CONTROL_MODE                                 (uint16)150U
#define EXI_ISO_20_AC_10_EI_CLRES_CONTROL_MODE_SE                              (uint16)151U
#define EXI_ISO_20_AC_10_EI_CLRES_CONTROL_MODE_CT                              (uint16)152U
#define EXI_ISO_20_AC_10_EI_CLRES_CONTROL_MODE_EE                              (uint16)153U
#define EXI_ISO_20_AC_10_EI_CLRES_CONTROL_MODE_AT                              (uint16)154U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_RES                                 (uint16)155U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_RES_SE                              (uint16)156U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_RES_CT                              (uint16)157U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_RES_EE                              (uint16)158U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_RES_AT                              (uint16)159U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_REQ                  (uint16)160U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_REQ_SE               (uint16)161U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_REQ_CT               (uint16)162U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_REQ_EE               (uint16)163U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_REQ_AT               (uint16)164U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_RES                  (uint16)165U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_RES_SE               (uint16)166U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_RES_CT               (uint16)167U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_RES_EE               (uint16)168U
#define EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_RES_AT               (uint16)169U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER                          (uint16)170U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_SE                       (uint16)171U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_CT                       (uint16)172U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_EE                       (uint16)173U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_AT                       (uint16)174U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2                       (uint16)175U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2_SE                    (uint16)176U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2_CT                    (uint16)177U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2_EE                    (uint16)178U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2_AT                    (uint16)179U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3                       (uint16)180U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3_SE                    (uint16)181U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3_CT                    (uint16)182U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3_EE                    (uint16)183U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3_AT                    (uint16)184U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER                          (uint16)185U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_SE                       (uint16)186U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_CT                       (uint16)187U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_EE                       (uint16)188U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_AT                       (uint16)189U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2                       (uint16)190U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2_SE                    (uint16)191U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2_CT                    (uint16)192U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2_EE                    (uint16)193U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2_AT                    (uint16)194U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3                       (uint16)195U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3_SE                    (uint16)196U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3_CT                    (uint16)197U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3_EE                    (uint16)198U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3_AT                    (uint16)199U
#define EXI_ISO_20_AC_10_EI_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE                 (uint16)200U
#define EXI_ISO_20_AC_10_EI_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_SE              (uint16)201U
#define EXI_ISO_20_AC_10_EI_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_CT              (uint16)202U
#define EXI_ISO_20_AC_10_EI_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_EE              (uint16)203U
#define EXI_ISO_20_AC_10_EI_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_AT              (uint16)204U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER                        (uint16)205U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_SE                     (uint16)206U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_CT                     (uint16)207U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_EE                     (uint16)208U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_AT                     (uint16)209U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L2                     (uint16)210U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L2_SE                  (uint16)211U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L2_CT                  (uint16)212U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L2_EE                  (uint16)213U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L2_AT                  (uint16)214U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L3                     (uint16)215U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L3_SE                  (uint16)216U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L3_CT                  (uint16)217U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L3_EE                  (uint16)218U
#define EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L3_AT                  (uint16)219U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER                        (uint16)220U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_SE                     (uint16)221U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_CT                     (uint16)222U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_EE                     (uint16)223U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_AT                     (uint16)224U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L2                     (uint16)225U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L2_SE                  (uint16)226U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L2_CT                  (uint16)227U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L2_EE                  (uint16)228U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L2_AT                  (uint16)229U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L3                     (uint16)230U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L3_SE                  (uint16)231U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L3_CT                  (uint16)232U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L3_EE                  (uint16)233U
#define EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L3_AT                  (uint16)234U
#define EXI_ISO_20_AC_10_EI_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE                 (uint16)235U
#define EXI_ISO_20_AC_10_EI_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_SE              (uint16)236U
#define EXI_ISO_20_AC_10_EI_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_CT              (uint16)237U
#define EXI_ISO_20_AC_10_EI_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_EE              (uint16)238U
#define EXI_ISO_20_AC_10_EI_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_AT              (uint16)239U
#define EXI_ISO_20_AC_10_EI_DEPARTURE_TIME                                     (uint16)240U
#define EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_SE                                  (uint16)241U
#define EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_CT                                  (uint16)242U
#define EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_EE                                  (uint16)243U
#define EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_AT                                  (uint16)244U
#define EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST                            (uint16)245U
#define EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_SE                         (uint16)246U
#define EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_CT                         (uint16)247U
#define EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_EE                         (uint16)248U
#define EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_AT                         (uint16)249U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST                           (uint16)250U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_SE                        (uint16)251U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_CT                        (uint16)252U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_EE                        (uint16)253U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_AT                        (uint16)254U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST                           (uint16)255U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_SE                        (uint16)256U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_CT                        (uint16)257U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_EE                        (uint16)258U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_AT                        (uint16)259U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER                             (uint16)260U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_SE                          (uint16)261U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_CT                          (uint16)262U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_EE                          (uint16)263U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_AT                          (uint16)264U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2                          (uint16)265U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_SE                       (uint16)266U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_CT                       (uint16)267U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_EE                       (uint16)268U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_AT                       (uint16)269U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3                          (uint16)270U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_SE                       (uint16)271U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_CT                       (uint16)272U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_EE                       (uint16)273U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_AT                       (uint16)274U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER                           (uint16)275U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_SE                        (uint16)276U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_CT                        (uint16)277U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_EE                        (uint16)278U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_AT                        (uint16)279U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2                        (uint16)280U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_SE                     (uint16)281U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_CT                     (uint16)282U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_EE                     (uint16)283U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_AT                     (uint16)284U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3                        (uint16)285U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_SE                     (uint16)286U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_CT                     (uint16)287U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_EE                     (uint16)288U
#define EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_AT                     (uint16)289U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_V2XENERGY_REQUEST                        (uint16)290U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_SE                     (uint16)291U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_CT                     (uint16)292U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_EE                     (uint16)293U
#define EXI_ISO_20_AC_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_AT                     (uint16)294U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_V2XENERGY_REQUEST                        (uint16)295U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_V2XENERGY_REQUEST_SE                     (uint16)296U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_V2XENERGY_REQUEST_CT                     (uint16)297U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_V2XENERGY_REQUEST_EE                     (uint16)298U
#define EXI_ISO_20_AC_10_EI_EVMINIMUM_V2XENERGY_REQUEST_AT                     (uint16)299U
#define EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE                  (uint16)300U
#define EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_SE               (uint16)301U
#define EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_CT               (uint16)302U
#define EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_EE               (uint16)303U
#define EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_AT               (uint16)304U
#define EXI_ISO_20_AC_10_EI_MINIMUM_SOC                                        (uint16)305U
#define EXI_ISO_20_AC_10_EI_MINIMUM_SOC_SE                                     (uint16)306U
#define EXI_ISO_20_AC_10_EI_MINIMUM_SOC_CT                                     (uint16)307U
#define EXI_ISO_20_AC_10_EI_MINIMUM_SOC_EE                                     (uint16)308U
#define EXI_ISO_20_AC_10_EI_MINIMUM_SOC_AT                                     (uint16)309U
#define EXI_ISO_20_AC_10_EI_TARGET_SOC                                         (uint16)310U
#define EXI_ISO_20_AC_10_EI_TARGET_SOC_SE                                      (uint16)311U
#define EXI_ISO_20_AC_10_EI_TARGET_SOC_CT                                      (uint16)312U
#define EXI_ISO_20_AC_10_EI_TARGET_SOC_EE                                      (uint16)313U
#define EXI_ISO_20_AC_10_EI_TARGET_SOC_AT                                      (uint16)314U
#define EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY                                      (uint16)315U
#define EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_SE                                   (uint16)316U
#define EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_CT                                   (uint16)317U
#define EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_EE                                   (uint16)318U
#define EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_AT                                   (uint16)319U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER                            (uint16)320U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_SE                         (uint16)321U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_CT                         (uint16)322U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_EE                         (uint16)323U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_AT                         (uint16)324U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2                         (uint16)325U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_SE                      (uint16)326U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_CT                      (uint16)327U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_EE                      (uint16)328U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_AT                      (uint16)329U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3                         (uint16)330U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_SE                      (uint16)331U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_CT                      (uint16)332U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_EE                      (uint16)333U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_AT                      (uint16)334U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER                          (uint16)335U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_SE                       (uint16)336U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_CT                       (uint16)337U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_EE                       (uint16)338U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_AT                       (uint16)339U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2                       (uint16)340U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_SE                    (uint16)341U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_CT                    (uint16)342U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_EE                    (uint16)343U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_AT                    (uint16)344U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3                       (uint16)345U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_SE                    (uint16)346U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_CT                    (uint16)347U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_EE                    (uint16)348U
#define EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_AT                    (uint16)349U
#define EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE                  (uint16)350U
#define EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_SE               (uint16)351U
#define EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_CT               (uint16)352U
#define EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_EE               (uint16)353U
#define EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_AT               (uint16)354U
#define EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE                (uint16)355U
#define EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_SE             (uint16)356U
#define EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_CT             (uint16)357U
#define EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_EE             (uint16)358U
#define EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_AT             (uint16)359U
#define EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE                (uint16)360U
#define EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_SE             (uint16)361U
#define EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_CT             (uint16)362U
#define EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_EE             (uint16)363U
#define EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_AT             (uint16)364U
#define EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLREQ_CONTROL_MODE                      (uint16)365U
#define EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLREQ_CONTROL_MODE_SE                   (uint16)366U
#define EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLREQ_CONTROL_MODE_CT                   (uint16)367U
#define EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLREQ_CONTROL_MODE_EE                   (uint16)368U
#define EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLREQ_CONTROL_MODE_AT                   (uint16)369U
#define EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLRES_CONTROL_MODE                      (uint16)370U
#define EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLRES_CONTROL_MODE_SE                   (uint16)371U
#define EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLRES_CONTROL_MODE_CT                   (uint16)372U
#define EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLRES_CONTROL_MODE_EE                   (uint16)373U
#define EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLRES_CONTROL_MODE_AT                   (uint16)374U
#define EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLREQ_CONTROL_MODE                    (uint16)375U
#define EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLREQ_CONTROL_MODE_SE                 (uint16)376U
#define EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLREQ_CONTROL_MODE_CT                 (uint16)377U
#define EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLREQ_CONTROL_MODE_EE                 (uint16)378U
#define EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLREQ_CONTROL_MODE_AT                 (uint16)379U
#define EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLRES_CONTROL_MODE                    (uint16)380U
#define EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLRES_CONTROL_MODE_SE                 (uint16)381U
#define EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLRES_CONTROL_MODE_CT                 (uint16)382U
#define EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLRES_CONTROL_MODE_EE                 (uint16)383U
#define EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLRES_CONTROL_MODE_AT                 (uint16)384U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType;

typedef struct Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType;

typedef struct Exi_ISO_20_AC_10_AC_ChargeLoopReqType Exi_ISO_20_AC_10_AC_ChargeLoopReqType;

typedef struct Exi_ISO_20_AC_10_AC_ChargeLoopResType Exi_ISO_20_AC_10_AC_ChargeLoopResType;

typedef struct Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType;

typedef struct Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType;

typedef struct Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType;

typedef struct Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType;

typedef struct Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType;

typedef struct Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType;

typedef struct Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType;

typedef struct Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType;

typedef struct Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType;

typedef struct Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType;

typedef struct Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType;

typedef struct Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType;

struct Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType
{
  Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType* AC_CPDReqEnergyTransferMode; /* Following types are allowed:
          Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType
          Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType */
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_RootElementIdType AC_CPDReqEnergyTransferModeElementId; /* Following element IDs are allowed:
          EXI_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE
          EXI_ISO_20_AC_10_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE */
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType
{
  Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType* AC_CPDResEnergyTransferMode; /* Following types are allowed:
          Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType
          Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType */
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_RootElementIdType AC_CPDResEnergyTransferModeElementId; /* Following element IDs are allowed:
          EXI_ISO_20_AC_10_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE
          EXI_ISO_20_AC_10_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE */
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

struct Exi_ISO_20_AC_10_AC_ChargeLoopReqType
{
  Exi_ISO_20_CT_10_CLReqControlModeType* CLReqControlMode; /* Following types are allowed:
          Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType
          Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType
          Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType
          Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType */
  Exi_ISO_20_CT_10_DisplayParametersType* DisplayParameters;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_RootElementIdType CLReqControlModeElementId; /* Following element IDs are allowed:
          EXI_ISO_20_AC_10_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE
          EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE
          EXI_ISO_20_AC_10_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE
          EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE */
  boolean MeterInfoRequested;
  Exi_BitType DisplayParametersFlag : 1;
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

struct Exi_ISO_20_AC_10_AC_ChargeLoopResType
{
  Exi_ISO_20_CT_10_CLResControlModeType* CLResControlMode; /* Following types are allowed:
          Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType
          Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType
          Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType
          Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType */
  Exi_ISO_20_CT_10_EVSEStatusType* EVSEStatus;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetFrequency;
  Exi_ISO_20_CT_10_MessageHeaderType* Header;
  Exi_ISO_20_CT_10_MeterInfoType* MeterInfo;
  Exi_ISO_20_CT_10_ReceiptType* Receipt;
  Exi_RootElementIdType CLResControlModeElementId; /* Following element IDs are allowed:
          EXI_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE
          EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE
          EXI_ISO_20_AC_10_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE
          EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE */
  Exi_ISO_20_CT_10_responseCodeType ResponseCode; /* Value range: 0 to 39; See type for exact values. */
  Exi_BitType EVSEStatusFlag : 1;
  Exi_BitType EVSETargetFrequencyFlag : 1;
  Exi_BitType MeterInfoFlag : 1;
  Exi_BitType ReceiptFlag : 1;
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

struct Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L3;
  Exi_BitType EVMaximumChargePower_L2Flag : 1;
  Exi_BitType EVMaximumChargePower_L3Flag : 1;
  Exi_BitType EVMinimumChargePower_L2Flag : 1;
  Exi_BitType EVMinimumChargePower_L3Flag : 1;
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

struct Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMaximumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMaximumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMaximumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMinimumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMinimumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMinimumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSENominalFrequency;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPowerRampLimitation;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* MaximumPowerAsymmetry;
  Exi_BitType EVSEMaximumChargePower_L2Flag : 1;
  Exi_BitType EVSEMaximumChargePower_L3Flag : 1;
  Exi_BitType EVSEMinimumChargePower_L2Flag : 1;
  Exi_BitType EVSEMinimumChargePower_L3Flag : 1;
  Exi_BitType EVSEPowerRampLimitationFlag : 1;
  Exi_BitType EVSEPresentActivePowerFlag : 1;
  Exi_BitType EVSEPresentActivePower_L2Flag : 1;
  Exi_BitType EVSEPresentActivePower_L3Flag : 1;
  Exi_BitType MaximumPowerAsymmetryFlag : 1;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumDischargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumDischargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumDischargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumDischargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumDischargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumDischargePower_L3;
  Exi_BitType EVMaximumChargePower_L2Flag : 1;
  Exi_BitType EVMaximumChargePower_L3Flag : 1;
  Exi_BitType EVMaximumDischargePower_L2Flag : 1;
  Exi_BitType EVMaximumDischargePower_L3Flag : 1;
  Exi_BitType EVMinimumChargePower_L2Flag : 1;
  Exi_BitType EVMinimumChargePower_L3Flag : 1;
  Exi_BitType EVMinimumDischargePower_L2Flag : 1;
  Exi_BitType EVMinimumDischargePower_L3Flag : 1;
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

struct Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMaximumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMaximumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMaximumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMaximumDischargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMaximumDischargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMaximumDischargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMinimumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMinimumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMinimumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMinimumDischargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMinimumDischargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEMinimumDischargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSENominalFrequency;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPowerRampLimitation;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* MaximumPowerAsymmetry;
  Exi_BitType EVSEMaximumChargePower_L2Flag : 1;
  Exi_BitType EVSEMaximumChargePower_L3Flag : 1;
  Exi_BitType EVSEMaximumDischargePower_L2Flag : 1;
  Exi_BitType EVSEMaximumDischargePower_L3Flag : 1;
  Exi_BitType EVSEMinimumChargePower_L2Flag : 1;
  Exi_BitType EVSEMinimumChargePower_L3Flag : 1;
  Exi_BitType EVSEMinimumDischargePower_L2Flag : 1;
  Exi_BitType EVSEMinimumDischargePower_L3Flag : 1;
  Exi_BitType EVSEPowerRampLimitationFlag : 1;
  Exi_BitType EVSEPresentActivePowerFlag : 1;
  Exi_BitType EVSEPresentActivePower_L2Flag : 1;
  Exi_BitType EVSEPresentActivePower_L3Flag : 1;
  Exi_BitType MaximumPowerAsymmetryFlag : 1;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVTargetEnergyRequest;
  Exi_BitType EVMaximumChargePowerFlag : 1;
  Exi_BitType EVMaximumChargePower_L2Flag : 1;
  Exi_BitType EVMaximumChargePower_L3Flag : 1;
  Exi_BitType EVMaximumEnergyRequestFlag : 1;
  Exi_BitType EVMinimumChargePowerFlag : 1;
  Exi_BitType EVMinimumChargePower_L2Flag : 1;
  Exi_BitType EVMinimumChargePower_L3Flag : 1;
  Exi_BitType EVMinimumEnergyRequestFlag : 1;
  Exi_BitType EVPresentActivePower_L2Flag : 1;
  Exi_BitType EVPresentActivePower_L3Flag : 1;
  Exi_BitType EVPresentReactivePowerFlag : 1;
  Exi_BitType EVPresentReactivePower_L2Flag : 1;
  Exi_BitType EVPresentReactivePower_L3Flag : 1;
  Exi_BitType EVTargetEnergyRequestFlag : 1;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower_L3;
  Exi_BitType EVSEPresentActivePowerFlag : 1;
  Exi_BitType EVSEPresentActivePower_L2Flag : 1;
  Exi_BitType EVSEPresentActivePower_L3Flag : 1;
  Exi_BitType EVSETargetActivePowerFlag : 1;
  Exi_BitType EVSETargetActivePower_L2Flag : 1;
  Exi_BitType EVSETargetActivePower_L3Flag : 1;
  Exi_BitType EVSETargetReactivePowerFlag : 1;
  Exi_BitType EVSETargetReactivePower_L2Flag : 1;
  Exi_BitType EVSETargetReactivePower_L3Flag : 1;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumDischargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumDischargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumDischargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumDischargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumDischargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumDischargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVTargetEnergyRequest;
  Exi_BitType EVMaximumChargePowerFlag : 1;
  Exi_BitType EVMaximumChargePower_L2Flag : 1;
  Exi_BitType EVMaximumChargePower_L3Flag : 1;
  Exi_BitType EVMaximumDischargePowerFlag : 1;
  Exi_BitType EVMaximumDischargePower_L2Flag : 1;
  Exi_BitType EVMaximumDischargePower_L3Flag : 1;
  Exi_BitType EVMaximumEnergyRequestFlag : 1;
  Exi_BitType EVMinimumChargePowerFlag : 1;
  Exi_BitType EVMinimumChargePower_L2Flag : 1;
  Exi_BitType EVMinimumChargePower_L3Flag : 1;
  Exi_BitType EVMinimumDischargePowerFlag : 1;
  Exi_BitType EVMinimumDischargePower_L2Flag : 1;
  Exi_BitType EVMinimumDischargePower_L3Flag : 1;
  Exi_BitType EVMinimumEnergyRequestFlag : 1;
  Exi_BitType EVPresentActivePower_L2Flag : 1;
  Exi_BitType EVPresentActivePower_L3Flag : 1;
  Exi_BitType EVPresentReactivePowerFlag : 1;
  Exi_BitType EVPresentReactivePower_L2Flag : 1;
  Exi_BitType EVPresentReactivePower_L3Flag : 1;
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

struct Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower_L3;
  Exi_BitType EVSEPresentActivePowerFlag : 1;
  Exi_BitType EVSEPresentActivePower_L2Flag : 1;
  Exi_BitType EVSEPresentActivePower_L3Flag : 1;
  Exi_BitType EVSETargetActivePowerFlag : 1;
  Exi_BitType EVSETargetActivePower_L2Flag : 1;
  Exi_BitType EVSETargetActivePower_L3Flag : 1;
  Exi_BitType EVSETargetReactivePowerFlag : 1;
  Exi_BitType EVSETargetReactivePower_L2Flag : 1;
  Exi_BitType EVSETargetReactivePower_L3Flag : 1;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVTargetEnergyRequest;
  uint32 DepartureTime;
  Exi_BitType DepartureTimeFlag : 1;
  Exi_BitType EVMaximumChargePower_L2Flag : 1;
  Exi_BitType EVMaximumChargePower_L3Flag : 1;
  Exi_BitType EVMinimumChargePower_L2Flag : 1;
  Exi_BitType EVMinimumChargePower_L3Flag : 1;
  Exi_BitType EVPresentActivePower_L2Flag : 1;
  Exi_BitType EVPresentActivePower_L3Flag : 1;
  Exi_BitType EVPresentReactivePower_L2Flag : 1;
  Exi_BitType EVPresentReactivePower_L3Flag : 1;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower_L3;
  uint32 DepartureTime;
  uint16 AckMaxDelay;
  sint8 MinimumSOC; /* Value range: max: 100 */
  sint8 TargetSOC; /* Value range: max: 100 */
  Exi_BitType AckMaxDelayFlag : 1;
  Exi_BitType DepartureTimeFlag : 1;
  Exi_BitType EVSEPresentActivePowerFlag : 1;
  Exi_BitType EVSEPresentActivePower_L2Flag : 1;
  Exi_BitType EVSEPresentActivePower_L3Flag : 1;
  Exi_BitType EVSETargetActivePower_L2Flag : 1;
  Exi_BitType EVSETargetActivePower_L3Flag : 1;
  Exi_BitType EVSETargetReactivePowerFlag : 1;
  Exi_BitType EVSETargetReactivePower_L2Flag : 1;
  Exi_BitType EVSETargetReactivePower_L3Flag : 1;
  Exi_BitType MinimumSOCFlag : 1;
  Exi_BitType TargetSOCFlag : 1;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumDischargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumDischargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumDischargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMaximumV2XEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumChargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumDischargePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumDischargePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumDischargePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVMinimumV2XEnergyRequest;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVPresentReactivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVTargetEnergyRequest;
  uint32 DepartureTime;
  Exi_BitType DepartureTimeFlag : 1;
  Exi_BitType EVMaximumChargePower_L2Flag : 1;
  Exi_BitType EVMaximumChargePower_L3Flag : 1;
  Exi_BitType EVMaximumDischargePower_L2Flag : 1;
  Exi_BitType EVMaximumDischargePower_L3Flag : 1;
  Exi_BitType EVMaximumV2XEnergyRequestFlag : 1;
  Exi_BitType EVMinimumChargePower_L2Flag : 1;
  Exi_BitType EVMinimumChargePower_L3Flag : 1;
  Exi_BitType EVMinimumDischargePower_L2Flag : 1;
  Exi_BitType EVMinimumDischargePower_L3Flag : 1;
  Exi_BitType EVMinimumV2XEnergyRequestFlag : 1;
  Exi_BitType EVPresentActivePower_L2Flag : 1;
  Exi_BitType EVPresentActivePower_L3Flag : 1;
  Exi_BitType EVPresentReactivePower_L2Flag : 1;
  Exi_BitType EVPresentReactivePower_L3Flag : 1;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType
{
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSEPresentActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetActivePower_L3;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower_L2;
  Exi_ISO_20_CT_10_RationalNumberType* EVSETargetReactivePower_L3;
  uint32 DepartureTime;
  uint16 AckMaxDelay;
  sint8 MinimumSOC; /* Value range: max: 100 */
  sint8 TargetSOC; /* Value range: max: 100 */
  Exi_BitType AckMaxDelayFlag : 1;
  Exi_BitType DepartureTimeFlag : 1;
  Exi_BitType EVSEPresentActivePowerFlag : 1;
  Exi_BitType EVSEPresentActivePower_L2Flag : 1;
  Exi_BitType EVSEPresentActivePower_L3Flag : 1;
  Exi_BitType EVSETargetActivePower_L2Flag : 1;
  Exi_BitType EVSETargetActivePower_L3Flag : 1;
  Exi_BitType EVSETargetReactivePowerFlag : 1;
  Exi_BitType EVSETargetReactivePower_L2Flag : 1;
  Exi_BitType EVSETargetReactivePower_L3Flag : 1;
  Exi_BitType MinimumSOCFlag : 1;
  Exi_BitType TargetSOCFlag : 1;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};
#endif  /* EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET */

/* PRQA L:IDENTIFIER_NAMES */
/* PRQA L:NAMESPACE */
/* PRQA L:UNION */


#endif /* EXI_ISO_20_AC_10_SCHEMA_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_AC_10_SchemaTypes.h
 **********************************************************************************************************************/
