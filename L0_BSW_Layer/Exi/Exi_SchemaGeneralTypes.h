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
/**        \file  Exi_SchemaGeneralTypes.h
 *        \brief  Efficient XML Interchange general types header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component general types.
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

#if !defined (EXI_SCHEMA_GENERAL_TYPES_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_SCHEMA_GENERAL_TYPES_H

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
/* Generic */
#define EXI_SCHEMA_GENERIC_ELEMENT_TYPE (Exi_RootElementIdType)919U
#define EXI_SCHEMA_GENERIC_STRING_TYPE (Exi_RootElementIdType)920U
#define EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE (Exi_RootElementIdType)921U
#define EXI_UNKNOWN_SCHEMA_SET_TYPE (Exi_RootElementIdType)10U
#ifndef EXI_MAX_BUFFER_SIZE_BASE64BINARY
  #define EXI_MAX_BUFFER_SIZE_BASE64BINARY EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_STRING
  #define EXI_MAX_BUFFER_SIZE_STRING EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif

/**********************************************************************************************************************
 *  ELEMENT IDENTIFIER DEFINES
**********************************************************************************************************************/
#define EXI_GENERAL_TYPES_EI_BASE64BINARY                                       (uint16)0U
#define EXI_GENERAL_TYPES_EI_BASE64BINARY_SE                                    (uint16)1U
#define EXI_GENERAL_TYPES_EI_BASE64BINARY_CT                                    (uint16)2U
#define EXI_GENERAL_TYPES_EI_BASE64BINARY_EE                                    (uint16)3U
#define EXI_GENERAL_TYPES_EI_BASE64BINARY_AT                                    (uint16)4U
#define EXI_GENERAL_TYPES_EI_STRING                                             (uint16)5U
#define EXI_GENERAL_TYPES_EI_STRING_SE                                          (uint16)6U
#define EXI_GENERAL_TYPES_EI_STRING_CT                                          (uint16)7U
#define EXI_GENERAL_TYPES_EI_STRING_EE                                          (uint16)8U
#define EXI_GENERAL_TYPES_EI_STRING_AT                                          (uint16)9U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct Exi_GenericElementType Exi_GenericElementType;

struct Exi_GenericElementType
{
  Exi_RootElementIdType QNameType;
  void* GenericQName;
  Exi_RootElementIdType ContentType;
  void* GenericContent;
  Exi_GenericElementType* NextGenericElement;
};

typedef struct Exi_GenericStringType Exi_GenericStringType;

struct Exi_GenericStringType
{
  uint16 Length;
  uint8 Buffer[128];
};

typedef struct Exi_stringType Exi_stringType;
struct Exi_stringType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_STRING];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_STRING ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_STRING ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_STRING ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_base64BinaryType Exi_base64BinaryType;
struct Exi_base64BinaryType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_BASE64BINARY];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_BASE64BINARY ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_BASE64BINARY ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_BASE64BINARY ) + 2u ) % 4u)];
# endif
#endif 
};
/* PRQA L:IDENTIFIER_NAMES */
/* PRQA L:NAMESPACE */
/* PRQA L:UNION */


#endif /* EXI_SCHEMA_GENERAL_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_SchemaGeneralTypes.h
 **********************************************************************************************************************/
