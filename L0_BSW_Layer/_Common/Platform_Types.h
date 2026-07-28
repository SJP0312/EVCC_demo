/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Platform_Types.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Provision of Platform Types for Infineon Tricore
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-11-06  Om                    Adaptation of template for Infineon Tricore
 *  01.01.01  2007-11-20  Jk                    Defines for CFG management added
 *  01.01.02  2007-11-27  Jk                    Defines for CFG management adapted
 *  02.00.00  2008-04-11  Jk                    Addapted to AUTOSAR 3.0
 *  02.00.01  2008-12-01  Ht                    Version number corrected
 *  02.01.00  2011-09-20  Bir                   Update to new template include AUTOSAR VERSION 4
 *  02.02.00  2014-09-17  visseu/visRna         AR4-667: Support sint64 and uint64
 *  02.03.00  2017-02-07  visRna  ESCAN00083285 Compiler error: not supported data type long long
 *  02.03.01  2018-09-10  Bns     ESCAN00100064 Compiler complains about undefined symbol "uint64" or "sint64"
 *  02.04.00  2020-11-18  visbwa                Removed AUTHOR IDENTITY, changed filter mechanism (Product instead of
 *                                              AutosarVersion)
 *  02.05.00  2023-07-17  virrlu  HALBE-10052   Update to AUTOSAR Release 21-11
 *  02.05.01  2023-08-29  virrlu  ESCAN00115508 Compiler warning: __STDC_VERSION__ not defined
 *  02.05.02  2023-09-20  virjas  ESCAN00115708 PostBuild generator fails when the AUTOSAR boolean type (_Bool) is used
 *  02.05.03  2024-02-01  xchen   OSHAL-287     Encapsulate definitions of UINT8_MAX, UINT16_MAX, UINT32_MAX and UINT64_MAX
*********************************************************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : CommonAsr_Tricore CQComponent : Impl_PlatformTypes */
#define COMMONASR_TRICORE_IMPL_PLATFORMTYPES_VERSION 0x0205
#define COMMONASR_TRICORE_IMPL_PLATFORMTYPES_RELEASE_VERSION 0x02

#define PLATFORM_VENDOR_ID    30u              /* Vendor ID of Vector */
#define PLATFORM_MODULE_ID    199u             /* 199 is the ID of Platform types */

/* AUTOSAR Software Specification Document Version Information */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION      (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION      (8u)
#define PLATFORM_AR_RELEASE_REVISION_VERSION   (0u)

/* Component Version Information */
#define PLATFORM_SW_MAJOR_VERSION       (2u)
#define PLATFORM_SW_MINOR_VERSION       (5u)
#define PLATFORM_SW_PATCH_VERSION       (3u)

#define CPU_TYPE_8       8u
#define CPU_TYPE_16      16u
#define CPU_TYPE_32      32u
#define CPU_TYPE_64      64u

#define MSB_FIRST        0u  /* big endian bit ordering */
#define LSB_FIRST        1u  /* little endian bit ordering */

#define HIGH_BYTE_FIRST  0u  /* big endian byte ordering */
#define LOW_BYTE_FIRST   1u  /* little endian byte ordering */

#ifndef TRUE
# define TRUE            1u
#endif

#ifndef FALSE
# define FALSE           0u
#endif

#define CPU_TYPE         CPU_TYPE_64

#define CPU_BIT_ORDER    LSB_FIRST       /*little endian bit ordering*/

#define CPU_BYTE_ORDER   LOW_BYTE_FIRST  /*little endian byte ordering*/

/* data type limitation defines */
#define UINT8_MIN        0u
#if !defined UINT8_MAX
#define UINT8_MAX        255u
#endif /* !defined UINT8_MAX */
#define UINT16_MIN       0u
#if !defined UINT16_MAX
#define UINT16_MAX       65535u
#endif /* !defined UINT16_MAX */
#define UINT32_MIN       0ul
#if !defined UINT32_MAX
#define UINT32_MAX       4294967295ul
#endif /* !defined UINT32_MAX */
#define UINT64_MIN       0ull
#if !defined UINT64_MAX
#define UINT64_MAX       18446744073709551615ull
#endif /* !defined UINT64_MAX */

#define SINT8_MIN        -128
#define SINT8_MAX        127
#define SINT16_MIN       -32768
#define SINT16_MAX       32767
#define SINT32_MIN       -2147483648
#define SINT32_MAX       2147483647
#define SINT64_MIN       -9223372036854775808
#define SINT64_MAX       9223372036854775807

#define FLOAT32_MIN      1.17549435e-38f
#define FLOAT32_MAX      3.40282347e+38f
#define FLOAT32_EPSILON  1.19209290e-07f

#define FLOAT64_MIN       2.2250738585072014e-308l
#define FLOAT64_MAX       1.7976931348623157e+308l
#define FLOAT64_EPSILON   2.2204460492503131e-16l

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef unsigned char       boolean;        /* for use with TRUE/FALSE        */

typedef signed char           sint8;         /*        -128 .. +127            */
typedef unsigned char         uint8;         /*           0 .. 255             */
typedef signed short          sint16;        /*      -32768 .. +32767          */
typedef unsigned short        uint16;        /*           0 .. 65535           */
typedef signed long           sint32;        /* -2147483648 .. +2147483647     */
typedef unsigned long         uint32;        /*           0 .. 4294967295      */

typedef signed char           sint8_least;   /* At least 7 bit + 1 bit sign    */
typedef unsigned char         uint8_least;   /* At least 8 bit                 */
typedef signed short          sint16_least;  /* At least 15 bit + 1 bit sign   */
typedef unsigned short        uint16_least;  /* At least 16 bit                */
typedef signed long           sint32_least;  /* At least 31 bit + 1 bit sign   */
typedef unsigned long         uint32_least;  /* At least 32 bit                */

#if defined(__TASKING__)  /* valid for Tasking */
# if (__STDC_VERSION__ >= 199901L) /* ISO-C version is C99 or higher*/
#define PLATFORM_SUPPORT_SINT64_UINT64
typedef signed    long long  sint64;   /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long  uint64;   /*                    0 .. 18446744073709551615     */
# endif
#else /* valid for GNU and Diab*/
#define PLATFORM_SUPPORT_SINT64_UINT64
typedef signed    long long  sint64;   /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long  uint64;   /*                    0 .. 18446744073709551615     */
#endif

typedef float                 float32;
typedef double                float64;

typedef void* VoidPtr;
typedef const void* ConstVoidPtr;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* PLATFORM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Platform_Types.h
 *********************************************************************************************************************/
