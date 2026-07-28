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
/**        \file  Exi_ISO_20_WPT_10_SchemaEncoder.h
 *        \brief  Efficient XML Interchange ISO_20_WPT_10 encoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_WPT_10 encoder.
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

#if !defined (EXI_ISO_20_WPT_10_SCHEMA_ENCODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_WPT_10_SCHEMA_ENCODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaEncoder.h"

#if (!defined (EXI_ENABLE_ENCODE_ISO_20_WPT_10_MESSAGE_SET))
# define EXI_ENABLE_ENCODE_ISO_20_WPT_10_MESSAGE_SET   EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_ENCODE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_WPT_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_ALTERNATIVE_SECCLIST 0x01U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_ALTERNATIVE_SECC 0x02U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD_LIST 0x03U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD 0x04U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_REQ 0x05U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_RES 0x06U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_CHARGE_LOOP_REQ 0x07U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_CHARGE_LOOP_RES 0x08U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_REQ 0x09U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_RES 0x0AU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_COORDINATE_XYZ 0x0BU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_DATA_CONTAINER 0x0CU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_EVPCCHARGE_DIAGNOSTICS 0x0DU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_EVPCPOWER_CONTROL_PARAMETER 0x0EU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_EVRESULT 0x0FU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_LIST 0x10U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD 0x11U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_REQ 0x12U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_RES 0x13U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_REQ 0x14U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_RES 0x15U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE_LIST 0x16U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE 0x17U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_RECEIVER_DATA 0x18U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_RX_DATA_LIST 0x19U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_RX_DATA 0x1AU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_RX_RSSILIST 0x1BU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_RX_RSSI 0x1CU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_SYSTEM_SETUP_DATA 0x1DU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_TRANSMITTER_DATA 0x1EU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_TX_DATA_LIST 0x1FU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_TX_DATA 0x20U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_PAIRING_METHOD_LIST 0x21U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_PAIRING_METHOD 0x22U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_PAIRING_REQ 0x23U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_PAIRING_RES 0x24U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_POWER_CLASS 0x25U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS 0x26U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_SPCPOWER_CONTROL_PARAMETER 0x27U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_TX_RX_PACKAGE_SPEC_DATA 0x28U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_TX_RX_PULSE_ORDER 0x29U
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_TX_RX_SPEC_DATA 0x2AU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_BSSID 0x2BU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_IPADDRESS 0x2CU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_SCHEMA_FRAGMENT 0x2DU
#define EXI_API_ID_ENCODE_ISO_20_WPT_10_SCHEMA_ROOT 0x2EU


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_AlternativeSECCList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_AlternativeSECCListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AlternativeSECCListPtr      pointer to Exi_ISO_20_WPT_10_AlternativeSECCListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_AlternativeSECCList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_AlternativeSECCListType, AUTOMATIC, EXI_APPL_DATA) AlternativeSECCListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_AlternativeSECC
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_AlternativeSECCType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AlternativeSECCPtr          pointer to Exi_ISO_20_WPT_10_AlternativeSECCType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_AlternativeSECC( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_AlternativeSECCType, AUTOMATIC, EXI_APPL_DATA) AlternativeSECCPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType object
 *  \param[in,out] EncWsPtr                        pointer to EXI encoding workspace
 *  \param[in]     WPT_AlignmentCheckMethodListPtr pointer to Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType, AUTOMATIC, EXI_APPL_DATA) WPT_AlignmentCheckMethodListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethod
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_AlignmentCheckMethodPtr pointer to Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodType, AUTOMATIC, EXI_APPL_DATA) WPT_AlignmentCheckMethodPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_AlignmentCheckReqPtr    pointer to Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType, AUTOMATIC, EXI_APPL_DATA) WPT_AlignmentCheckReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_AlignmentCheckResPtr    pointer to Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType, AUTOMATIC, EXI_APPL_DATA) WPT_AlignmentCheckResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_ChargeLoopReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_ChargeLoopReqPtr        pointer to Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_ChargeLoopReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeLoopReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_ChargeLoopRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_ChargeLoopResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_ChargeLoopResPtr        pointer to Exi_ISO_20_WPT_10_WPT_ChargeLoopResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_ChargeLoopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeLoopResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType object
 *  \param[in,out] EncWsPtr                           pointer to EXI encoding workspace
 *  \param[in]     WPT_ChargeParameterDiscoveryReqPtr pointer to Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeParameterDiscoveryReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType object
 *  \param[in,out] EncWsPtr                           pointer to EXI encoding workspace
 *  \param[in]     WPT_ChargeParameterDiscoveryResPtr pointer to Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeParameterDiscoveryResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_CoordinateXYZ
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_CoordinateXYZType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_CoordinateXYZPtr        pointer to Exi_ISO_20_WPT_10_WPT_CoordinateXYZType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_CoordinateXYZ( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_CoordinateXYZType, AUTOMATIC, EXI_APPL_DATA) WPT_CoordinateXYZPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_DataContainer
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_DataContainerType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_DataContainerPtr        pointer to Exi_ISO_20_WPT_10_WPT_DataContainerType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_DataContainer( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, EXI_APPL_DATA) WPT_DataContainerPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_EVPCChargeDiagnostics
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType object
 *  \param[in,out] EncWsPtr                     pointer to EXI encoding workspace
 *  \param[in]     WPT_EVPCChargeDiagnosticsPtr pointer to Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_EVPCChargeDiagnostics( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType, AUTOMATIC, EXI_APPL_DATA) WPT_EVPCChargeDiagnosticsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType object
 *  \param[in,out] EncWsPtr                         pointer to EXI encoding workspace
 *  \param[in]     WPT_EVPCPowerControlParameterPtr pointer to Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType, AUTOMATIC, EXI_APPL_DATA) WPT_EVPCPowerControlParameterPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_EVResult
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_EVResultType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_EVResultPtr             pointer to Exi_ISO_20_WPT_10_WPT_EVResultType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_EVResult( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_EVResultType, AUTOMATIC, EXI_APPL_DATA) WPT_EVResultPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethodList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType object
 *  \param[in,out] EncWsPtr                         pointer to EXI encoding workspace
 *  \param[in]     WPT_FinePositioningMethodListPtr pointer to Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethodList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningMethodListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethod
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningMethodType object
 *  \param[in,out] EncWsPtr                     pointer to EXI encoding workspace
 *  \param[in]     WPT_FinePositioningMethodPtr pointer to Exi_ISO_20_WPT_10_WPT_FinePositioningMethodType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningMethodPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_FinePositioningReqPtr   pointer to Exi_ISO_20_WPT_10_WPT_FinePositioningReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_FinePositioningResPtr   pointer to Exi_ISO_20_WPT_10_WPT_FinePositioningResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningResType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningSetupReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     WPT_FinePositioningSetupReqPtr pointer to Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningSetupReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningSetupReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningSetupRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     WPT_FinePositioningSetupResPtr pointer to Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningSetupRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningSetupResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackageList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_DataPackageListPtr   pointer to Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackageList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_DataPackageListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackage
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_DataPackageType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_DataPackagePtr       pointer to Exi_ISO_20_WPT_10_WPT_LF_DataPackageType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackage( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_DataPackageType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_DataPackagePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_ReceiverData
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_ReceiverDataPtr      pointer to Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_ReceiverData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_ReceiverDataPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_RxDataList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_RxDataListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_RxDataListPtr        pointer to Exi_ISO_20_WPT_10_WPT_LF_RxDataListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_RxDataList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_RxDataListType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_RxDataListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_RxData
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_RxDataType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_RxDataPtr            pointer to Exi_ISO_20_WPT_10_WPT_LF_RxDataType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_RxData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_RxDataType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_RxDataPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_RxRSSIList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_RxRSSIListPtr        pointer to Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_RxRSSIList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_RxRSSIListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_RxRSSI
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_RxRSSIPtr            pointer to Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_RxRSSI( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_RxRSSIPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_SystemSetupData
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_SystemSetupDataPtr   pointer to Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_SystemSetupData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_SystemSetupDataPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_TransmitterData
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_TransmitterDataPtr   pointer to Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_TransmitterData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_TransmitterDataPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_TxDataList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_TxDataListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_TxDataListPtr        pointer to Exi_ISO_20_WPT_10_WPT_LF_TxDataListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_TxDataList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_TxDataListType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_TxDataListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_TxData
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_TxDataType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_LF_TxDataPtr            pointer to Exi_ISO_20_WPT_10_WPT_LF_TxDataType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_TxData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_TxDataType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_TxDataPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_PairingMethodList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_PairingMethodListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_PairingMethodListPtr    pointer to Exi_ISO_20_WPT_10_WPT_PairingMethodListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_PairingMethodList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_PairingMethodListType, AUTOMATIC, EXI_APPL_DATA) WPT_PairingMethodListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_PairingMethod
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_PairingMethodType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_PairingMethodPtr        pointer to Exi_ISO_20_WPT_10_WPT_PairingMethodType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_PairingMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_PairingMethodType, AUTOMATIC, EXI_APPL_DATA) WPT_PairingMethodPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_PairingReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_PairingReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_PairingReqPtr           pointer to Exi_ISO_20_WPT_10_WPT_PairingReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_PairingReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_PairingReqType, AUTOMATIC, EXI_APPL_DATA) WPT_PairingReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_PairingRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_PairingResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_PairingResPtr           pointer to Exi_ISO_20_WPT_10_WPT_PairingResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_PairingRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_PairingResType, AUTOMATIC, EXI_APPL_DATA) WPT_PairingResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_PowerClass
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_PowerClassType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_PowerClassPtr           pointer to Exi_ISO_20_WPT_10_WPT_PowerClassType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_PowerClass( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_PowerClassType, AUTOMATIC, EXI_APPL_DATA) WPT_PowerClassPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_SPCChargeDiagnostics
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_SPCChargeDiagnosticsPtr pointer to Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_SPCChargeDiagnostics( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType, AUTOMATIC, EXI_APPL_DATA) WPT_SPCChargeDiagnosticsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_SPCPowerControlParameter
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType object
 *  \param[in,out] EncWsPtr                        pointer to EXI encoding workspace
 *  \param[in]     WPT_SPCPowerControlParameterPtr pointer to Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_SPCPowerControlParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType, AUTOMATIC, EXI_APPL_DATA) WPT_SPCPowerControlParameterPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_TxRxPackageSpecData
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_TxRxPackageSpecDataPtr  pointer to Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_TxRxPackageSpecData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType, AUTOMATIC, EXI_APPL_DATA) WPT_TxRxPackageSpecDataPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_TxRxPulseOrder
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_TxRxPulseOrderPtr       pointer to Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_TxRxPulseOrder( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType, AUTOMATIC, EXI_APPL_DATA) WPT_TxRxPulseOrderPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_TxRxSpecData
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WPT_TxRxSpecDataPtr         pointer to Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_TxRxSpecData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType, AUTOMATIC, EXI_APPL_DATA) WPT_TxRxSpecDataPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_bssid
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_bssidType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     bssidPtr                    pointer to Exi_ISO_20_WPT_10_bssidType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_bssid( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_bssidType, AUTOMATIC, EXI_APPL_DATA) bssidPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_ipaddress
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_ipaddressType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ipaddressPtr                pointer to Exi_ISO_20_WPT_10_ipaddressType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_ipaddress( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_ipaddressType, AUTOMATIC, EXI_APPL_DATA) ipaddressPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_SchemaFragment
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_SchemaFragment object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_SchemaRoot
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_WPT_10_SchemaRoot object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22902
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_SchemaRoot( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_WPT_10_MESSAGE_SET == STD_ON)) */

#endif /* EXI_ISO_20_WPT_10_SCHEMA_ENCODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_WPT_10_SchemaEncoder.h
 **********************************************************************************************************************/
