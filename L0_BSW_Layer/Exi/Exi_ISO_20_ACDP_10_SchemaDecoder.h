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
/**        \file  Exi_ISO_20_ACDP_10_SchemaDecoder.h
 *        \brief  Efficient XML Interchange ISO_20_ACDP_10 decoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_ACDP_10 decoder.
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

#if !defined (EXI_ISO_20_ACDP_10_SCHEMA_DECODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_ACDP_10_SCHEMA_DECODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaDecoder.h"

#if (!defined (EXI_ENABLE_DECODE_ISO_20_ACDP_10_MESSAGE_SET))
# define EXI_ENABLE_DECODE_ISO_20_ACDP_10_MESSAGE_SET   EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_DECODE_ISO_20_ACDP_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_ACDP_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_ACDP_CONNECT_REQ 0x01U
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_ACDP_CONNECT_RES 0x02U
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_ACDP_SYSTEM_STATUS_REQ 0x03U
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_ACDP_SYSTEM_STATUS_RES 0x04U
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_REQ 0x05U
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_RES 0x06U
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_EVTECHNICAL_STATUS 0x07U
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_CP_STATUS 0x08U
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_ELECTRICAL_CHARGING_DEVICE_STATUS 0x09U
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_ERROR_CODE 0x0AU
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_ISOLATION_STATUS 0x0BU
#define EXI_API_ID_DECODE_ISO_20_ACDP_10_MECHANICAL_CHARGING_DEVICE_STATUS 0x0CU
#define EXI_API_ID_DECODE_SCHEMA_SET_ISO_20_ACDP_10 0x0DU


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_ACDP_ConnectReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_ACDP_ConnectReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_ACDP_ConnectReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_ACDP_ConnectRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_ACDP_ConnectResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_ACDP_ConnectRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_ACDP_ConnectResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_ACDP_SystemStatusReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_ACDP_SystemStatusReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_ACDP_SystemStatusRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_ACDP_SystemStatusResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_ACDP_SystemStatusRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_ACDP_SystemStatusResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_ACDP_VehiclePositioningReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_ACDP_VehiclePositioningReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_ACDP_VehiclePositioningRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_ACDP_VehiclePositioningRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_EVTechnicalStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_EVTechnicalStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_EVTechnicalStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_EVTechnicalStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_cpStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_cpStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] cpStatusPtr                 in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_cpStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_cpStatusType, AUTOMATIC, EXI_APPL_VAR) cpStatusPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_electricalChargingDeviceStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_electricalChargingDeviceStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] electricalChargingDeviceStatusPtr in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_electricalChargingDeviceStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_electricalChargingDeviceStatusType, AUTOMATIC, EXI_APPL_VAR) electricalChargingDeviceStatusPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_errorCode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_errorCodeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] errorCodePtr                in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_errorCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_errorCodeType, AUTOMATIC, EXI_APPL_VAR) errorCodePtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_isolationStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_isolationStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] isolationStatusPtr          in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_isolationStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_isolationStatusType, AUTOMATIC, EXI_APPL_VAR) isolationStatusPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_ACDP_10_mechanicalChargingDeviceStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_20_ACDP_10_mechanicalChargingDeviceStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] mechanicalChargingDeviceStatusPtr in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_20_ACDP_10_mechanicalChargingDeviceStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_ACDP_10_mechanicalChargingDeviceStatusType, AUTOMATIC, EXI_APPL_VAR) mechanicalChargingDeviceStatusPtr );


/**********************************************************************************************************************
 *  Exi_Decode_SchemaSet_ISO_20_ACDP_10
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_SchemaSet_ISO_20_ACDP_10 object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22902
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_SchemaSet_ISO_20_ACDP_10( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined (EXI_ENABLE_DECODE_ISO_20_ACDP_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_ACDP_10_MESSAGE_SET == STD_ON)) */

#endif /* EXI_ISO_20_ACDP_10_SCHEMA_DECODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_ACDP_10_SchemaDecoder.h
 **********************************************************************************************************************/
