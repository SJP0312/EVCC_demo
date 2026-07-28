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
/**        \file  Exi_SAP_SchemaTypes.h
 *        \brief  Efficient XML Interchange SAP types header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component SAP types.
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

#if !defined (EXI_SAP_SCHEMA_TYPES_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_SAP_SCHEMA_TYPES_H

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
#define EXI_SAP_SUPPORTED_APP_PROTOCOL_REQ_TYPE                                          (Exi_RootElementIdType)201U
#define EXI_SAP_SUPPORTED_APP_PROTOCOL_RES_TYPE                                          (Exi_RootElementIdType)202U

#if (defined(EXI_ENABLE_SAP_MESSAGE_SET) && (EXI_ENABLE_SAP_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* Elements */
#define EXI_SAP_APP_PROTOCOL_TYPE                                                        (Exi_RootElementIdType)227U
#define EXI_SAP_PRIORITY_TYPE                                                            (Exi_RootElementIdType)228U
#define EXI_SAP_PROTOCOL_NAMESPACE_TYPE                                                  (Exi_RootElementIdType)229U
#define EXI_SAP_RESPONSE_CODE_TYPE                                                       (Exi_RootElementIdType)230U
#define EXI_SAP_SCHEMA_ID_TYPE                                                           (Exi_RootElementIdType)231U
#define EXI_SAP_VERSION_NUMBER_MAJOR_TYPE                                                (Exi_RootElementIdType)232U
#define EXI_SAP_VERSION_NUMBER_MINOR_TYPE                                                (Exi_RootElementIdType)233U
#define EXI_SCHEMA_SET_SAP_TYPE                                                          (Exi_RootElementIdType)0U

/**********************************************************************************************************************
 *  ELEMENT IDENTIFIER DEFINES
**********************************************************************************************************************/
#define EXI_SAP_EI_PROTOCOL_NAMESPACE                                 (uint16)0U
#define EXI_SAP_EI_PROTOCOL_NAMESPACE_SE                              (uint16)1U
#define EXI_SAP_EI_PROTOCOL_NAMESPACE_CT                              (uint16)2U
#define EXI_SAP_EI_PROTOCOL_NAMESPACE_EE                              (uint16)3U
#define EXI_SAP_EI_PROTOCOL_NAMESPACE_AT                              (uint16)4U
#define EXI_SAP_EI_VERSION_NUMBER_MAJOR                               (uint16)5U
#define EXI_SAP_EI_VERSION_NUMBER_MAJOR_SE                            (uint16)6U
#define EXI_SAP_EI_VERSION_NUMBER_MAJOR_CT                            (uint16)7U
#define EXI_SAP_EI_VERSION_NUMBER_MAJOR_EE                            (uint16)8U
#define EXI_SAP_EI_VERSION_NUMBER_MAJOR_AT                            (uint16)9U
#define EXI_SAP_EI_VERSION_NUMBER_MINOR                               (uint16)10U
#define EXI_SAP_EI_VERSION_NUMBER_MINOR_SE                            (uint16)11U
#define EXI_SAP_EI_VERSION_NUMBER_MINOR_CT                            (uint16)12U
#define EXI_SAP_EI_VERSION_NUMBER_MINOR_EE                            (uint16)13U
#define EXI_SAP_EI_VERSION_NUMBER_MINOR_AT                            (uint16)14U
#define EXI_SAP_EI_SCHEMA_ID                                          (uint16)15U
#define EXI_SAP_EI_SCHEMA_ID_SE                                       (uint16)16U
#define EXI_SAP_EI_SCHEMA_ID_CT                                       (uint16)17U
#define EXI_SAP_EI_SCHEMA_ID_EE                                       (uint16)18U
#define EXI_SAP_EI_SCHEMA_ID_AT                                       (uint16)19U
#define EXI_SAP_EI_PRIORITY                                           (uint16)20U
#define EXI_SAP_EI_PRIORITY_SE                                        (uint16)21U
#define EXI_SAP_EI_PRIORITY_CT                                        (uint16)22U
#define EXI_SAP_EI_PRIORITY_EE                                        (uint16)23U
#define EXI_SAP_EI_PRIORITY_AT                                        (uint16)24U
#define EXI_SAP_EI_RESPONSE_CODE                                      (uint16)25U
#define EXI_SAP_EI_RESPONSE_CODE_SE                                   (uint16)26U
#define EXI_SAP_EI_RESPONSE_CODE_CT                                   (uint16)27U
#define EXI_SAP_EI_RESPONSE_CODE_EE                                   (uint16)28U
#define EXI_SAP_EI_RESPONSE_CODE_AT                                   (uint16)29U
#define EXI_SAP_EI_APP_PROTOCOL                                       (uint16)30U
#define EXI_SAP_EI_APP_PROTOCOL_SE                                    (uint16)31U
#define EXI_SAP_EI_APP_PROTOCOL_CT                                    (uint16)32U
#define EXI_SAP_EI_APP_PROTOCOL_EE                                    (uint16)33U
#define EXI_SAP_EI_APP_PROTOCOL_AT                                    (uint16)34U
#define EXI_SAP_EI_SUPPORTED_APP_PROTOCOL_REQ                         (uint16)35U
#define EXI_SAP_EI_SUPPORTED_APP_PROTOCOL_REQ_SE                      (uint16)36U
#define EXI_SAP_EI_SUPPORTED_APP_PROTOCOL_REQ_CT                      (uint16)37U
#define EXI_SAP_EI_SUPPORTED_APP_PROTOCOL_REQ_EE                      (uint16)38U
#define EXI_SAP_EI_SUPPORTED_APP_PROTOCOL_REQ_AT                      (uint16)39U
#define EXI_SAP_EI_SUPPORTED_APP_PROTOCOL_RES                         (uint16)40U
#define EXI_SAP_EI_SUPPORTED_APP_PROTOCOL_RES_SE                      (uint16)41U
#define EXI_SAP_EI_SUPPORTED_APP_PROTOCOL_RES_CT                      (uint16)42U
#define EXI_SAP_EI_SUPPORTED_APP_PROTOCOL_RES_EE                      (uint16)43U
#define EXI_SAP_EI_SUPPORTED_APP_PROTOCOL_RES_AT                      (uint16)44U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  EXI_SAP_RESPONSE_CODE_TYPE_OK_SUCCESSFUL_NEGOTIATION = 0u,
  EXI_SAP_RESPONSE_CODE_TYPE_OK_SUCCESSFUL_NEGOTIATION_WITH_MINOR_DEVIATION = 1u,
  EXI_SAP_RESPONSE_CODE_TYPE_FAILED_NO_NEGOTIATION = 2u
} Exi_SAP_responseCodeType;

typedef struct Exi_SAP_protocolNamespaceType Exi_SAP_protocolNamespaceType;
struct Exi_SAP_protocolNamespaceType
{
  uint16 Length;
  uint8 Buffer[100];
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_SAP_AppProtocolType Exi_SAP_AppProtocolType;

typedef struct Exi_SAP_supportedAppProtocolReqType Exi_SAP_supportedAppProtocolReqType;

typedef struct Exi_SAP_supportedAppProtocolResType Exi_SAP_supportedAppProtocolResType;

/* Exi_SAP_protocolNameType has been disabled */

struct Exi_SAP_AppProtocolType
{
  struct Exi_SAP_AppProtocolType* NextAppProtocolPtr;
  Exi_SAP_protocolNamespaceType* ProtocolNamespace;
  uint32 VersionNumberMajor;
  uint32 VersionNumberMinor;
  uint8 Priority; /* Value range: min: 1 max: 20 */
  uint8 SchemaID;
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( 2u ) % 4u)];
# endif
#endif 
};

struct Exi_SAP_supportedAppProtocolReqType
{
  Exi_SAP_AppProtocolType* AppProtocol;
};

struct Exi_SAP_supportedAppProtocolResType
{
  Exi_SAP_responseCodeType ResponseCode; /* Value range: 0 to 2; See type for exact values. */
  uint8 SchemaID;
  Exi_BitType SchemaIDFlag : 1;
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
#endif  /* EXI_ENABLE_SAP_MESSAGE_SET */

/* PRQA L:IDENTIFIER_NAMES */
/* PRQA L:NAMESPACE */
/* PRQA L:UNION */


#endif /* EXI_SAP_SCHEMA_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_SAP_SchemaTypes.h
 **********************************************************************************************************************/
