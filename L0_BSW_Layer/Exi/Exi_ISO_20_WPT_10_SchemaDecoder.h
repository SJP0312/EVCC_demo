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
/**        \file  Exi_ISO_20_WPT_10_SchemaDecoder.h
 *        \brief  Efficient XML Interchange ISO_20_WPT_10 decoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_WPT_10 decoder.
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

#if !defined (EXI_ISO_20_WPT_10_SCHEMA_DECODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_WPT_10_SCHEMA_DECODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaDecoder.h"

#if (!defined (EXI_ENABLE_DECODE_ISO_20_WPT_10_MESSAGE_SET))
# define EXI_ENABLE_DECODE_ISO_20_WPT_10_MESSAGE_SET   EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_DECODE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_WPT_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_DECODE_ISO_20_WPT_10_ALTERNATIVE_SECCLIST 0x01U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_ALTERNATIVE_SECC 0x02U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD_LIST 0x03U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD 0x04U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_REQ 0x05U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_RES 0x06U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_CHARGE_LOOP_REQ 0x07U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_CHARGE_LOOP_RES 0x08U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_REQ 0x09U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_RES 0x0AU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_COORDINATE_XYZ 0x0BU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_DATA_CONTAINER 0x0CU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_EVPCCHARGE_DIAGNOSTICS 0x0DU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_EVPCPOWER_CONTROL_PARAMETER 0x0EU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_EVRESULT 0x0FU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_LIST 0x10U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD 0x11U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_REQ 0x12U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_RES 0x13U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_REQ 0x14U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_RES 0x15U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE_LIST 0x16U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE 0x17U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_RECEIVER_DATA 0x18U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_RX_DATA_LIST 0x19U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_RX_DATA 0x1AU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_RX_RSSILIST 0x1BU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_RX_RSSI 0x1CU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_SYSTEM_SETUP_DATA 0x1DU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_TRANSMITTER_DATA 0x1EU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_TX_DATA_LIST 0x1FU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_TX_DATA 0x20U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_PAIRING_METHOD_LIST 0x21U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_PAIRING_METHOD 0x22U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_PAIRING_REQ 0x23U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_PAIRING_RES 0x24U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_POWER_CLASS 0x25U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS 0x26U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_SPCPOWER_CONTROL_PARAMETER 0x27U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_TX_RX_PACKAGE_SPEC_DATA 0x28U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_TX_RX_PULSE_ORDER 0x29U
#define EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_TX_RX_SPEC_DATA 0x2AU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_BSSID 0x2BU
#define EXI_API_ID_DECODE_ISO_20_WPT_10_IPADDRESS 0x2CU
#define EXI_API_ID_DECODE_SCHEMA_SET_ISO_20_WPT_10 0x2DU


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_AlternativeSECCList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_AlternativeSECCListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_AlternativeSECCList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_AlternativeSECCListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_AlternativeSECC
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_AlternativeSECCType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_AlternativeSECC( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_AlternativeSECCType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethod
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] WPT_AlignmentCheckMethodPtr in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodType, AUTOMATIC, EXI_APPL_VAR) WPT_AlignmentCheckMethodPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_ChargeLoopReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_ChargeLoopReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_ChargeLoopRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_ChargeLoopResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_ChargeLoopRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeLoopResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_CoordinateXYZ
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_CoordinateXYZType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_CoordinateXYZ( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_CoordinateXYZType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_DataContainer
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_DataContainerType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_DataContainer( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_EVPCChargeDiagnostics
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] WPT_EVPCChargeDiagnosticsPtr in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_EVPCChargeDiagnostics( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType, AUTOMATIC, EXI_APPL_VAR) WPT_EVPCChargeDiagnosticsPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_EVResult
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_EVResultType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] WPT_EVResultPtr             in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_EVResult( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_EVResultType, AUTOMATIC, EXI_APPL_VAR) WPT_EVResultPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethodList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethodList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethod
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningMethodType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] WPT_FinePositioningMethodPtr in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodType, AUTOMATIC, EXI_APPL_VAR) WPT_FinePositioningMethodPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningSetupReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningSetupReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningSetupRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningSetupRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackageList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackageList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackage
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_DataPackageType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackage( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_DataPackageType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_ReceiverData
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_ReceiverData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_RxDataList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_RxDataListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_RxDataList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxDataListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_RxData
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_RxDataType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_RxData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_RxRSSIList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_RxRSSIList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_RxRSSI
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_RxRSSI( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_SystemSetupData
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_SystemSetupData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_TransmitterData
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_TransmitterData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_TxDataList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_TxDataListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_TxDataList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_TxDataListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_TxData
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_LF_TxDataType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_TxData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_TxDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_PairingMethodList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_PairingMethodListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_PairingMethodList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_PairingMethodListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_PairingMethod
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_PairingMethodType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] WPT_PairingMethodPtr        in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_PairingMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_PairingMethodType, AUTOMATIC, EXI_APPL_VAR) WPT_PairingMethodPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_PairingReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_PairingReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_PairingReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_PairingReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_PairingRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_PairingResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_PairingRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_PairingResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_PowerClass
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_PowerClassType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] WPT_PowerClassPtr           in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_PowerClass( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_PowerClassType, AUTOMATIC, EXI_APPL_VAR) WPT_PowerClassPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_SPCChargeDiagnostics
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] WPT_SPCChargeDiagnosticsPtr in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_SPCChargeDiagnostics( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType, AUTOMATIC, EXI_APPL_VAR) WPT_SPCChargeDiagnosticsPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_SPCPowerControlParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_SPCPowerControlParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_TxRxPackageSpecData
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_TxRxPackageSpecData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_TxRxPulseOrder
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_TxRxPulseOrder( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_TxRxSpecData
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_TxRxSpecData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_bssid
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_bssidType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_bssid( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_bssidType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_ipaddress
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_WPT_10_ipaddressType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_ipaddress( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_ipaddressType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_SchemaSet_ISO_20_WPT_10
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_SchemaSet_ISO_20_WPT_10 object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22902
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_SchemaSet_ISO_20_WPT_10( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined (EXI_ENABLE_DECODE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_WPT_10_MESSAGE_SET == STD_ON)) */

#endif /* EXI_ISO_20_WPT_10_SCHEMA_DECODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_WPT_10_SchemaDecoder.h
 **********************************************************************************************************************/
