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
 *            Module: XmlSecurity
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: XmlSecurity_Cfg.h
 *   Generation Time: 2025-09-11 13:39:30
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined(XMLSECURITY_CFG_H)
#define XMLSECURITY_CFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  XMLSECURITY ECUC GLOBAL CONFIGURATION CONTAINER NAME
 *********************************************************************************************************************/
#define XmlSecurityConfigSet                         XmlSecurity_Config

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#ifndef XMLSECURITY_USE_DUMMY_STATEMENT
#define XMLSECURITY_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XMLSECURITY_DUMMY_STATEMENT
#define XMLSECURITY_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XMLSECURITY_DUMMY_STATEMENT_CONST
#define XMLSECURITY_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XMLSECURITY_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define XMLSECURITY_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef XMLSECURITY_ATOMIC_VARIABLE_ACCESS
#define XMLSECURITY_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef XMLSECURITY_PROCESSOR_TC377T
#define XMLSECURITY_PROCESSOR_TC377T
#endif
#ifndef XMLSECURITY_COMP_DIAB
#define XMLSECURITY_COMP_DIAB
#endif
#ifndef XMLSECURITY_GEN_GENERATOR_MSR
#define XMLSECURITY_GEN_GENERATOR_MSR
#endif
#ifndef XMLSECURITY_CPUTYPE_BITORDER_LSB2MSB
#define XMLSECURITY_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef XMLSECURITY_CONFIGURATION_VARIANT_PRECOMPILE
#define XMLSECURITY_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef XMLSECURITY_CONFIGURATION_VARIANT_LINKTIME
#define XMLSECURITY_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef XMLSECURITY_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define XMLSECURITY_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef XMLSECURITY_CONFIGURATION_VARIANT
#define XMLSECURITY_CONFIGURATION_VARIANT XMLSECURITY_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef XMLSECURITY_POSTBUILD_VARIANT_SUPPORT
#define XMLSECURITY_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/**********************************************************************************************************************
 *  INTEGER DEFINES
 *********************************************************************************************************************/
#define XMLSECURITY_CFG_MAJOR_VERSION        11u
#define XMLSECURITY_CFG_MINOR_VERSION        1u

/**********************************************************************************************************************
 *  XMLSECURITY CONFIG VARIANT
 *********************************************************************************************************************/
#define XMLSECURITY_CONFIG_VARIANT                  XMLSECURITY_CONFIGURATION_VARIANT

/**********************************************************************************************************************
 *  PRECOMPILE CONFIG
 *********************************************************************************************************************/
#define XMLSECURITY_VERSION_INFO_API         STD_OFF
#define XMLSECURITY_DEV_ERROR_DETECT         STD_ON
#define XMLSECURITY_DEV_ERROR_REPORT         STD_ON


#define XMLSECURITY_EXI_TRANSFORM_URI        "http://www.w3.org/TR/canonical-exi/"
#define XMLSECURITY_EXI_TRANSFORM_URI_LEN    36u


/**********************************************************************************************************************
 *  CSM Abstraction Layer
 *********************************************************************************************************************/
 #define XMLSECURITY_CSM_SIGNATUREGENERATE  Csm_SignatureGenerate /* DefinitionRef: /MICROSAR/XmlSecurity/XmlSecurityCsmAbstraction/XmlSecurityCsmSignatureGenerate */
 #define XMLSECURITY_CSM_SIGNATUREVERIFY    Csm_SignatureVerify /* DefinitionRef: /MICROSAR/XmlSecurity/XmlSecurityCsmAbstraction/XmlSecurityCsmSignatureVerify */
 #define XMLSECURITY_CSM_HASH               Csm_Hash /* DefinitionRef: /MICROSAR/XmlSecurity/XmlSecurityCsmAbstraction/XmlSecurityCsmHash */

#endif /* XMLSECURITY_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: XmlSecurity_Cfg.h
 *********************************************************************************************************************/
 
