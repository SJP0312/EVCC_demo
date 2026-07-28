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
/**        \file  Exi_Priv.h
 *        \brief  Efficient XML Interchange private header file
 *
 *      \details  Vector static private header file for the Efficient XML Interchange module. This header file contains
 *                module internal declarations.
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

#if (!defined EXI_PRIV_H)                                                                                               /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_PRIV_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_Types.h"
#if (EXI_DEV_ERROR_DETECT == STD_ON) || (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/* EXI_DEV_ERROR_DETECT */
#include "Exi_Lcfg.h"

/**********************************************************************************************************************
 *  CONSISTENCY CHECK
 *********************************************************************************************************************/
#if (EXI_CONFIGURATION_VARIANT_PRECOMPILE != EXI_CONFIG_VARIANT)
# error "Component Exi: Configuration variant other than pre compile is not supported."
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define EXI_HEADER_BYTE                      0x80u
#define EXI_BITS_IN_BYTE                     8u

#define EXI_SINT8_MAX_POS_NUM                0x7FU                /*                     127 */
#define EXI_SINT8_MAX_NEG_NUM                0x80U                /* (-)                 128 */
#define EXI_SINT16_MAX_POS_NUM               0x7FFFU              /*                   32767 */
#define EXI_SINT16_MAX_NEG_NUM               0x8000U              /* (-)               32768 */
#define EXI_SINT32_MAX_POS_NUM               0x7FFFFFFFU          /*              2147483647 */
#define EXI_SINT32_MAX_NEG_NUM               0x80000000U          /* (-)          2147483648 */
#if defined(Exi_SInt64_Available)
#define EXI_SINT64_MAX_POS_NUM               0x7FFFFFFFFFFFFFFFULL /*     9223372036854775807 */
#define EXI_SINT64_MAX_NEG_NUM               0x8000000000000000ULL /* (-) 9223372036854775808 */
#endif

#define EXI_UINT8_MAX_NUM                    0xFFU
#define EXI_UINT16_MAX_NUM                   0xFFFFU
#define EXI_UINT32_MAX_NUM                   0xFFFFFFFFU
#if defined(Exi_UInt64_Available)
#define EXI_UINT64_MAX_NUM                   0xFFFFFFFFFFFFFFFFULL
#endif

#define EXI_P2VAR_IN_FUNCTION(Type)          P2VAR(Type, AUTOMATIC, EXI_APPL_VAR)                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define EXI_P2CONST_IN_FUNCTION(Type)        P2CONST(Type, AUTOMATIC, EXI_CONST)                                        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
*  GLOBAL FUNCTION MACROS
*********************************************************************************************************************/
/* PRQA S 3453 FUNCTIONLIKEMACRO */ /* MD_MSR_FctLikeMacro */

/* Development Error Tracer */
#if !defined(EXI_DEV_ERROR_REPORT)
#define EXI_DEV_ERROR_REPORT  EXI_DEV_ERROR_DETECT
#endif

#if !defined(EXI_INTERNAL_DEV_ERROR_REPORT)
#define EXI_INTERNAL_DEV_ERROR_REPORT  EXI_INTERNAL_DEV_ERROR_DETECT
#endif

  /* EXI_INTERNAL_DEV_ERROR_REPORT */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* PRQA L:FUNCTIONLIKEMACRO */
#endif /* EXI_PRIV_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_Priv.h
 *********************************************************************************************************************/
