/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Exi
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Exi_Cfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#if !defined(EXI_CFG_H)
#define EXI_CFG_H

/* PRQA S 0857 EOF */ /* MD_Exi_1.1_0857 */ /* [L] Number of macro definitions exceeds 1024 - program is non-conforming. */

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "vstdlib.h"

/**********************************************************************************************************************
 *  LINKTIME / PRECOMPILE CRC
 *********************************************************************************************************************/
#define EXI_CRC_CHECK                       STD_OFF
#define EXI_PRECOMPILE_CRC                  0x00000000u

/**********************************************************************************************************************
 *  EXI ECUC GLOBAL CONFIGURATION CONTAINER NAME
 *********************************************************************************************************************/
#define ExiConfigSet                        Exi_Config

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#ifndef EXI_USE_DUMMY_STATEMENT
#define EXI_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef EXI_DUMMY_STATEMENT
#define EXI_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef EXI_DUMMY_STATEMENT_CONST
#define EXI_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef EXI_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define EXI_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef EXI_ATOMIC_VARIABLE_ACCESS
#define EXI_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef EXI_PROCESSOR_TC377T
#define EXI_PROCESSOR_TC377T
#endif
#ifndef EXI_COMP_DIAB
#define EXI_COMP_DIAB
#endif
#ifndef EXI_GEN_GENERATOR_MSR
#define EXI_GEN_GENERATOR_MSR
#endif
#ifndef EXI_CPUTYPE_BITORDER_LSB2MSB
#define EXI_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef EXI_CONFIGURATION_VARIANT_PRECOMPILE
#define EXI_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef EXI_CONFIGURATION_VARIANT_LINKTIME
#define EXI_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef EXI_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define EXI_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef EXI_CONFIGURATION_VARIANT
#define EXI_CONFIGURATION_VARIANT EXI_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef EXI_POSTBUILD_VARIANT_SUPPORT
#define EXI_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/
#define EXI_CONFIG_VARIANT                  EXI_CONFIGURATION_VARIANT

/**********************************************************************************************************************
 *  General configuration
 *********************************************************************************************************************/
#define EXI_VERSION_INFO_API                   STD_OFF
#define EXI_DEV_ERROR_DETECT                   STD_ON
#define EXI_INTERNAL_DEV_ERROR_DETECT          STD_ON
#define EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT STD_ON
#define EXI_ENABLE_PBUF_SUPPORT                STD_ON

/**********************************************************************************************************************
 *  General Max Occurs
 *********************************************************************************************************************/
#define EXI_MAXOCCURS_GENERICELEMENT           1u
#define EXI_MAXOCCURS_UNBOUNDED                32u

/**********************************************************************************************************************
 *  General Max Buffer Size
 *********************************************************************************************************************/
#define EXI_MAX_NUM_BYTES_BIGINT               20u
#define EXI_MAX_BUFFER_SIZE_BASE64BINARY       900u
#define EXI_MAX_BUFFER_SIZE_ID                 10u
#define EXI_MAX_BUFFER_SIZE_STRING             64u
#define EXI_MAX_BUFFER_SIZE_UNBOUNDED          64u

/**********************************************************************************************************************
 *  Supported App Protocol specific configuration
 *********************************************************************************************************************/
#define EXI_ENABLE_SAP_MESSAGE_SET                 STD_ON

/**********************************************************************************************************************
 *  DIN 70121 specific configuration
 *********************************************************************************************************************/
#define EXI_ENABLE_DIN_MESSAGE_SET            STD_ON

/**********************************************************************************************************************
 *  DIN Max Occurs
 *********************************************************************************************************************/
#define EXI_MAXOCCURS_DIN_CERTIFICATE          8u
#define EXI_MAXOCCURS_DIN_CONSUMPTIONCOST      3u
#define EXI_MAXOCCURS_DIN_COST                 3u
#define EXI_MAXOCCURS_DIN_PARAMETER            2u
#define EXI_MAXOCCURS_DIN_PARAMETERSET         4u
#define EXI_MAXOCCURS_DIN_PAYMENTOPTION        2u
#define EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY    12u
#define EXI_MAXOCCURS_DIN_PROFILEENTRY         24u
#define EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID    20u
#define EXI_MAXOCCURS_DIN_SALESTARIFFENTRY     12u
#define EXI_MAXOCCURS_DIN_SASCHEDULETUPLE      3u
#define EXI_MAXOCCURS_DIN_SELECTEDSERVICE      3u
#define EXI_MAXOCCURS_DIN_SERVICE              3u

/**********************************************************************************************************************
 *  DIN Max Buffer Size
 *********************************************************************************************************************/
#define EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTEID    10u
#define EXI_MAX_BUFFER_SIZE_DIN_ATTRIBUTENAME  8u
#define EXI_MAX_BUFFER_SIZE_DIN_GENCHALLENGE   32u



/**********************************************************************************************************************
 *  ISO 15118 specific configuration
 *********************************************************************************************************************/
#define EXI_ENABLE_ISO_MESSAGE_SET             STD_ON

/**********************************************************************************************************************
 *  ISO Max Buffer Size
 *********************************************************************************************************************/
#define EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTEID    10u
#define EXI_MAX_BUFFER_SIZE_ISO_ATTRIBUTENAME  8u



/**********************************************************************************************************************
 *  ISO 15118-20 specific configuration
 *********************************************************************************************************************/
#define EXI_ENABLE_ISO_20_CT_10_MESSAGE_SET    STD_ON
#define EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET    STD_ON
#define EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET    STD_OFF
#define EXI_ENABLE_ISO_20_DC_10_MESSAGE_SET    STD_ON
#define EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET   STD_OFF
#define EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET  STD_OFF

/**********************************************************************************************************************
 *  ISO 15118-20 Max Buffer Size
 *********************************************************************************************************************/
#define EXI_MAX_BUFFER_SIZE_ISO_20_CM_10_ATTRIBUTEID 64u



/**********************************************************************************************************************
 *  XML Signature specific configuration
 *********************************************************************************************************************/
#define EXI_ENABLE_XMLSIG_MESSAGE_SET                  STD_ON

/**********************************************************************************************************************
 *  XMLSIG Max Occurs
 *********************************************************************************************************************/
#define EXI_MAXOCCURS_XMLSIG_REFERENCE                 16u
#define EXI_MAXOCCURS_XMLSIG_SIGNATUREPROPERTY         1u
#define EXI_MAXOCCURS_XMLSIG_TRANSFORM                 2u
#define EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE           1u
#define EXI_MAXOCCURS_XMLSIG_SIGNATUREPROPERTYCHOICE   1u

/**********************************************************************************************************************
 *  XMLSIG Max Buffer Size
 *********************************************************************************************************************/
#define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM  51u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEID         10u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEURI        11u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_DIGESTVALUE         64u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_SIGNATUREVALUE      141u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTETYPE       1u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEENCODING   1u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEMIMETYPE   1u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTETARGET     1u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_CRYPTOBINARY        1u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_KEYNAME             1u
#define EXI_MAX_BUFFER_SIZE_XMLSIG_MGMTDATA            1u



/**********************************************************************************************************************
 *  Struct Padding configuration
 *********************************************************************************************************************/
#define EXI_STRUCTURE_PADDING_16BIT_ENABLE        STD_OFF
#define EXI_STRUCTURE_PADDING_32BIT_ENABLE        STD_ON
#define EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE 1u
#define EXI_STRUCTURE_PADDING_ENUM_SIZE_BYTE      1u
 
 /**********************************************************************************************************************
 *  FUNCTION DEFINES
 *********************************************************************************************************************/
#define Exi_ClearMemory(MEMPTR, LENGTH) VStdMemClr((MEMPTR), (LENGTH))                      /* PRQA S 3453 */ /* MD_MSR_19.7 */


#endif /* EXI_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Exi_Cfg.h
 *********************************************************************************************************************/
 
