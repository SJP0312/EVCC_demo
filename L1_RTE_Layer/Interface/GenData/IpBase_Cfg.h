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
 *            Module: IpBase
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IpBase_Cfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#if !defined (IPBASE_CFG_H)
# define IPBASE_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define IPBASE_DEV_ERROR_REPORT                          STD_ON
# define IPBASE_ENABLE_INLINE_FUNCTIONS                   STD_ON
# define IPBASE_ENABLE_ONE_STEP_CHECKSUM_COPY             STD_OFF
# define IPBASE_CHECKSUM_DATA_POINTER_TYPE                uint32


# if !defined (IPBASE_LOCAL)
#  define IPBASE_LOCAL                                    static
# endif
# if !defined (IPBASE_LOCAL_INLINE)
#  if IPBASE_ENABLE_INLINE_FUNCTIONS == STD_ON
#   define IPBASE_LOCAL_INLINE                            LOCAL_INLINE
#  else
#   define IPBASE_LOCAL_INLINE
#  endif
# endif

#endif
  /* IPBASE_CFG_H */
/**********************************************************************************************************************
 *  END OF FILE: IpBase_Cfg.h
 *********************************************************************************************************************/
