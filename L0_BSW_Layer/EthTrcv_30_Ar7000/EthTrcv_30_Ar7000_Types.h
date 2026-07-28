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
/**        \file  EthTrcv_30_Ar7000_Types.h
 *        \brief  Ethernet transceiver driver QCA 7005 types header file
 *
 *      \details  Vector static code types header header file for the Ethernet transceiver driver QCA 7005 module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file EthTrcv_30_Ar7000.h.
 *********************************************************************************************************************/

#if !defined (ETHTRCV_30_AR7000_TYPES_H)
# define ETHTRCV_30_AR7000_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EthTrcv_GeneralTypes.h"
#include "Eth_GeneralTypes.h"
#include "EthTrcv_30_Ar7000_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  ETHTRCV_30_AR7000_RT_OK      = E_OK,
  ETHTRCV_30_AR7000_RT_NOT_OK  = E_NOT_OK,
  ETHTRCV_30_AR7000_RT_PENDING = 2u
} EthTrcv_30_Ar7000_ReturnType;

/* PRQA S 0750 7 */ /* MD_EthTrcv_30_Ar7000_BufferAccessUnion */
typedef union
{
  P2VAR(Eth_DataType, ETHTRCV_30_AR7000_VAR_NOINIT, ETHTRCV_30_AR7000_VAR_NOINIT) Native;
  P2VAR(uint32,       ETHTRCV_30_AR7000_VAR_NOINIT, ETHTRCV_30_AR7000_VAR_NOINIT) U32;
  P2VAR(uint16,       ETHTRCV_30_AR7000_VAR_NOINIT, ETHTRCV_30_AR7000_VAR_NOINIT) U16;
  P2VAR(uint8,        ETHTRCV_30_AR7000_VAR_NOINIT, ETHTRCV_30_AR7000_VAR_NOINIT) U8;
} EthTrcv_30_Ar7000_EthernetBufferUnionType;

/* PRQA S 0750 7 */ /* MD_EthTrcv_30_Ar7000_BufferAccessUnion */
typedef union
{
  P2CONST(Eth_DataType, ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST) Native;
  P2CONST(uint32,       ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST) U32;
  P2CONST(uint16,       ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST) U16;
  P2CONST(uint8,        ETHTRCV_30_AR7000_CONST, ETHTRCV_30_AR7000_CONST) U8;
} EthTrcv_30_Ar7000_EthernetBufferUnionConstType;


typedef struct EthTrcv_30_Ar7000_EthernetBuffer
{
  EthTrcv_30_Ar7000_EthernetBufferUnionType Buffer; /* PRQA S 0759 */ /* MD_EthTrcv_30_Ar7000_BufferAccessUnion */
  uint16 BufLen;
} EthTrcv_30_Ar7000_EthernetBufferType;

#if ( ETHTRCV_30_AR7000_ENABLE_WRITE_DAK == STD_ON )
typedef uint8 EthTrcv_30_Ar7000_DakType[ETHTRCV_30_AR7000_DAK_SIZE_BYTE];
#endif /* ( ETHTRCV_30_AR7000_ENABLE_WRITE_DAK == STD_ON ) */

typedef uint8 EthTrcv_30_Ar7000_ConfigType;

#if ( ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON )
typedef uint8 EthTrcv_30_Ar7000_PBActionType;
#define ETHTRCV_30_AR7000_PBACTION_JOIN                     1U
#define ETHTRCV_30_AR7000_PBACTION_LEAVE                    2U
#define ETHTRCV_30_AR7000_PBACTION_STATUS                   3U
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if ((defined ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API ))
typedef struct EthTrcv_30_Ar7000_SetPropertyParamter
{
  uint8  Option;
  uint32 PropVersion;
  uint32 PropId;
  uint32 PropDataLength;
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_DATA) PropData;
} EthTrcv_30_Ar7000_SetPropertyParamterType;

typedef uint8 EthTrcv_30_Ar7000_SetPropType;
/* Set Property MStatus return values */
#define ETHTRCV_30_AR7000_SETPROP_SUCCESS                        0x00U
#define ETHTRCV_30_AR7000_SETPROP_FAILURE                        0x01U
#define ETHTRCV_30_AR7000_SETPROP_PROP_NOT_SUPPORTED             0x02U
#define ETHTRCV_30_AR7000_SETPROP_VER_NOT_SUPPORTED              0x03U
#define ETHTRCV_30_AR7000_SETPROP_PROP_NOT_PERSISTENT            0x04U
#define ETHTRCV_30_AR7000_SETPROP_FLASH_FAILURE                  0x05U
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */


#if ( (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) || \
      ((defined ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) && (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK)) )
typedef struct EthTrcv_30_Ar7000_NVMHeader
{
  uint16 MajorVersion; 
  uint16 MinorVersion;
  uint32 AppletExecutionmask;
  uint32 ImageNvmAddress;
  uint32 ImageMemoryAddress;
  uint32 ImageLength;
  uint32 ImageChecksum;
  uint32 AppletEntryPtr;
  uint32 NextNvmHeaderPtr;
  uint32 PreviousNvmHeaderPtr;
  uint32 EntryType;
  uint16 ModuleId;
  uint16 ModuleSubId;
  uint16 AppletEntryVersion;
  uint16 Reserved0;
  uint32 Reserved1;
  uint32 Reserved2;
  uint32 Reserved3;
  uint32 Reserved4;
  uint32 Reserved5;
  uint32 Reserved6;
  uint32 Reserved7;
  uint32 Reserved8;
  uint32 Reserved9;
  uint32 Reserved10;
  uint32 Reserved11;
  uint32 HeaderChecksum;
} EthTrcv_30_Ar7000_NVMHeaderType;
#endif /* (ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE != ETHTRCV_30_AR7000_CFG_PAS_PIB) ||
          (STD_ON == ETHTRCV_30_AR7000_ENABLE_WRITE_DAK) */

#endif /* ETHTRCV_30_AR7000_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ar7000_Types.h
 *********************************************************************************************************************/

