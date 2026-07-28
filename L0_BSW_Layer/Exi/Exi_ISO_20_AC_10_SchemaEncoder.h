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
/**        \file  Exi_ISO_20_AC_10_SchemaEncoder.h
 *        \brief  Efficient XML Interchange ISO_20_AC_10 encoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_AC_10 encoder.
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

#if !defined (EXI_ISO_20_AC_10_SCHEMA_ENCODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_AC_10_SCHEMA_ENCODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaEncoder.h"

#if (!defined (EXI_ENABLE_ENCODE_ISO_20_AC_10_MESSAGE_SET))
# define EXI_ENABLE_ENCODE_ISO_20_AC_10_MESSAGE_SET   EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_ENCODE_ISO_20_AC_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_AC_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE 0x01U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CPDRES_ENERGY_TRANSFER_MODE 0x02U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CHARGE_LOOP_REQ 0x03U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CHARGE_LOOP_RES 0x04U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_REQ 0x05U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_RES 0x06U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE 0x07U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE 0x08U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE 0x09U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE 0x0AU
#define EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE 0x0BU
#define EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE 0x0CU
#define EXI_API_ID_ENCODE_ISO_20_AC_10_DYNAMIC_AC_CLREQ_CONTROL_MODE 0x0DU
#define EXI_API_ID_ENCODE_ISO_20_AC_10_DYNAMIC_AC_CLRES_CONTROL_MODE 0x0EU
#define EXI_API_ID_ENCODE_ISO_20_AC_10_SCHEDULED_AC_CLREQ_CONTROL_MODE 0x0FU
#define EXI_API_ID_ENCODE_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE 0x10U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_SCHEMA_FRAGMENT 0x11U
#define EXI_API_ID_ENCODE_ISO_20_AC_10_SCHEMA_ROOT 0x12U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_CPDReqEnergyTransferMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     AC_CPDReqEnergyTransferModePtr pointer to Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_CPDReqEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) AC_CPDReqEnergyTransferModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_CPDResEnergyTransferMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     AC_CPDResEnergyTransferModePtr pointer to Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_CPDResEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) AC_CPDResEnergyTransferModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_ChargeLoopReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_AC_ChargeLoopReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AC_ChargeLoopReqPtr         pointer to Exi_ISO_20_AC_10_AC_ChargeLoopReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_ChargeLoopReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeLoopReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_ChargeLoopRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_AC_ChargeLoopResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AC_ChargeLoopResPtr         pointer to Exi_ISO_20_AC_10_AC_ChargeLoopResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_ChargeLoopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeLoopResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType object
 *  \param[in,out] EncWsPtr                          pointer to EXI encoding workspace
 *  \param[in]     AC_ChargeParameterDiscoveryReqPtr pointer to Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeParameterDiscoveryReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType object
 *  \param[in,out] EncWsPtr                          pointer to EXI encoding workspace
 *  \param[in]     AC_ChargeParameterDiscoveryResPtr pointer to Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeParameterDiscoveryResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType object
 *  \param[in,out] EncWsPtr                           pointer to EXI encoding workspace
 *  \param[in]     BPT_AC_CPDReqEnergyTransferModePtr pointer to Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_AC_CPDReqEnergyTransferModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType object
 *  \param[in,out] EncWsPtr                           pointer to EXI encoding workspace
 *  \param[in]     BPT_AC_CPDResEnergyTransferModePtr pointer to Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_AC_CPDResEnergyTransferModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType object
 *  \param[in,out] EncWsPtr                           pointer to EXI encoding workspace
 *  \param[in]     BPT_Dynamic_AC_CLReqControlModePtr pointer to Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_AC_CLReqControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType object
 *  \param[in,out] EncWsPtr                           pointer to EXI encoding workspace
 *  \param[in]     BPT_Dynamic_AC_CLResControlModePtr pointer to Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_AC_CLResControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType object
 *  \param[in,out] EncWsPtr                             pointer to EXI encoding workspace
 *  \param[in]     BPT_Scheduled_AC_CLReqControlModePtr pointer to Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_AC_CLReqControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType object
 *  \param[in,out] EncWsPtr                             pointer to EXI encoding workspace
 *  \param[in]     BPT_Scheduled_AC_CLResControlModePtr pointer to Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_AC_CLResControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLReqControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     Dynamic_AC_CLReqControlModePtr pointer to Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_AC_CLReqControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLResControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     Dynamic_AC_CLResControlModePtr pointer to Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_AC_CLResControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLReqControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType object
 *  \param[in,out] EncWsPtr                         pointer to EXI encoding workspace
 *  \param[in]     Scheduled_AC_CLReqControlModePtr pointer to Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_AC_CLReqControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLResControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType object
 *  \param[in,out] EncWsPtr                         pointer to EXI encoding workspace
 *  \param[in]     Scheduled_AC_CLResControlModePtr pointer to Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_AC_CLResControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_SchemaFragment
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_SchemaFragment object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_SchemaRoot
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_AC_10_SchemaRoot object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22902
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_SchemaRoot( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_AC_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_AC_10_MESSAGE_SET == STD_ON)) */

#endif /* EXI_ISO_20_AC_10_SCHEMA_ENCODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_AC_10_SchemaEncoder.h
 **********************************************************************************************************************/
