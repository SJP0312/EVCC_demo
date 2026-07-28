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
/**        \file  Exi_ISO_20_DC_10_SchemaEncoder.h
 *        \brief  Efficient XML Interchange ISO_20_DC_10 encoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_DC_10 encoder.
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

#if !defined (EXI_ISO_20_DC_10_SCHEMA_ENCODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_DC_10_SCHEMA_ENCODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaEncoder.h"

#if (!defined (EXI_ENABLE_ENCODE_ISO_20_DC_10_MESSAGE_SET))
# define EXI_ENABLE_ENCODE_ISO_20_DC_10_MESSAGE_SET   EXI_ENABLE_ISO_20_DC_10_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_ENCODE_ISO_20_DC_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_DC_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_DC_CPDREQ_ENERGY_TRANSFER_MODE 0x01U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_DC_CPDRES_ENERGY_TRANSFER_MODE 0x02U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_DYNAMIC_DC_CLREQ_CONTROL_MODE 0x03U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_DYNAMIC_DC_CLRES_CONTROL_MODE 0x04U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_SCHEDULED_DC_CLREQ_CONTROL_MODE 0x05U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_SCHEDULED_DC_CLRES_CONTROL_MODE 0x06U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CPDREQ_ENERGY_TRANSFER_MODE 0x07U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CPDRES_ENERGY_TRANSFER_MODE 0x08U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CABLE_CHECK_REQ 0x09U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CABLE_CHECK_RES 0x0AU
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CHARGE_LOOP_REQ 0x0BU
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CHARGE_LOOP_RES 0x0CU
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CHARGE_PARAMETER_DISCOVERY_REQ 0x0DU
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CHARGE_PARAMETER_DISCOVERY_RES 0x0EU
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_PRE_CHARGE_REQ 0x0FU
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_PRE_CHARGE_RES 0x10U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_WELDING_DETECTION_REQ 0x11U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DC_WELDING_DETECTION_RES 0x12U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DYNAMIC_DC_CLREQ_CONTROL_MODE 0x13U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_DYNAMIC_DC_CLRES_CONTROL_MODE 0x14U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_SCHEDULED_DC_CLREQ_CONTROL_MODE 0x15U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_SCHEDULED_DC_CLRES_CONTROL_MODE 0x16U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_SCHEMA_FRAGMENT 0x17U
#define EXI_API_ID_ENCODE_ISO_20_DC_10_SCHEMA_ROOT 0x18U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType object
 *  \param[in,out] EncWsPtr                           pointer to EXI encoding workspace
 *  \param[in]     BPT_DC_CPDReqEnergyTransferModePtr pointer to Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_DC_CPDReqEnergyTransferModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType object
 *  \param[in,out] EncWsPtr                           pointer to EXI encoding workspace
 *  \param[in]     BPT_DC_CPDResEnergyTransferModePtr pointer to Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_DC_CPDResEnergyTransferModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType object
 *  \param[in,out] EncWsPtr                           pointer to EXI encoding workspace
 *  \param[in]     BPT_Dynamic_DC_CLReqControlModePtr pointer to Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_DC_CLReqControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType object
 *  \param[in,out] EncWsPtr                           pointer to EXI encoding workspace
 *  \param[in]     BPT_Dynamic_DC_CLResControlModePtr pointer to Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_DC_CLResControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType object
 *  \param[in,out] EncWsPtr                             pointer to EXI encoding workspace
 *  \param[in]     BPT_Scheduled_DC_CLReqControlModePtr pointer to Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_DC_CLReqControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType object
 *  \param[in,out] EncWsPtr                             pointer to EXI encoding workspace
 *  \param[in]     BPT_Scheduled_DC_CLResControlModePtr pointer to Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_DC_CLResControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_CPDReqEnergyTransferMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     DC_CPDReqEnergyTransferModePtr pointer to Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_CPDReqEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) DC_CPDReqEnergyTransferModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_CPDResEnergyTransferMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_CPDResEnergyTransferModeType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     DC_CPDResEnergyTransferModePtr pointer to Exi_ISO_20_DC_10_DC_CPDResEnergyTransferModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_CPDResEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) DC_CPDResEnergyTransferModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_CableCheckReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_CableCheckReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_CableCheckReqPtr         pointer to Exi_ISO_20_DC_10_DC_CableCheckReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_CableCheckReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_CableCheckReqType, AUTOMATIC, EXI_APPL_DATA) DC_CableCheckReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_CableCheckRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_CableCheckResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_CableCheckResPtr         pointer to Exi_ISO_20_DC_10_DC_CableCheckResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_CableCheckRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_CableCheckResType, AUTOMATIC, EXI_APPL_DATA) DC_CableCheckResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_ChargeLoopReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_ChargeLoopReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_ChargeLoopReqPtr         pointer to Exi_ISO_20_DC_10_DC_ChargeLoopReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_ChargeLoopReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeLoopReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_ChargeLoopRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_ChargeLoopResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_ChargeLoopResPtr         pointer to Exi_ISO_20_DC_10_DC_ChargeLoopResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_ChargeLoopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeLoopResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryReqType object
 *  \param[in,out] EncWsPtr                          pointer to EXI encoding workspace
 *  \param[in]     DC_ChargeParameterDiscoveryReqPtr pointer to Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeParameterDiscoveryReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryResType object
 *  \param[in,out] EncWsPtr                          pointer to EXI encoding workspace
 *  \param[in]     DC_ChargeParameterDiscoveryResPtr pointer to Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeParameterDiscoveryResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_PreChargeReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_PreChargeReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_PreChargeReqPtr          pointer to Exi_ISO_20_DC_10_DC_PreChargeReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_PreChargeReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_PreChargeReqType, AUTOMATIC, EXI_APPL_DATA) DC_PreChargeReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_PreChargeRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_PreChargeResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_PreChargeResPtr          pointer to Exi_ISO_20_DC_10_DC_PreChargeResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_PreChargeRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_PreChargeResType, AUTOMATIC, EXI_APPL_DATA) DC_PreChargeResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_WeldingDetectionReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_WeldingDetectionReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_WeldingDetectionReqPtr   pointer to Exi_ISO_20_DC_10_DC_WeldingDetectionReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_WeldingDetectionReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_WeldingDetectionReqType, AUTOMATIC, EXI_APPL_DATA) DC_WeldingDetectionReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_WeldingDetectionRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_DC_WeldingDetectionResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_WeldingDetectionResPtr   pointer to Exi_ISO_20_DC_10_DC_WeldingDetectionResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_WeldingDetectionRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_WeldingDetectionResType, AUTOMATIC, EXI_APPL_DATA) DC_WeldingDetectionResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLReqControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     Dynamic_DC_CLReqControlModePtr pointer to Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_DC_CLReqControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLResControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     Dynamic_DC_CLResControlModePtr pointer to Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_DC_CLResControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLReqControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType object
 *  \param[in,out] EncWsPtr                         pointer to EXI encoding workspace
 *  \param[in]     Scheduled_DC_CLReqControlModePtr pointer to Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_DC_CLReqControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLResControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType object
 *  \param[in,out] EncWsPtr                         pointer to EXI encoding workspace
 *  \param[in]     Scheduled_DC_CLResControlModePtr pointer to Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_DC_CLResControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_SchemaFragment
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_SchemaFragment object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_SchemaRoot
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_DC_10_SchemaRoot object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22902
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_SchemaRoot( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_DC_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_DC_10_MESSAGE_SET == STD_ON)) */

#endif /* EXI_ISO_20_DC_10_SCHEMA_ENCODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_DC_10_SchemaEncoder.h
 **********************************************************************************************************************/
