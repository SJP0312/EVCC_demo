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
/**        \file  XmlSecurity_Lcfg.h
 *        \brief  Link-time header of the Xml Security.
 *
 *      \details  Link-time header of the Xml Security for ISO 15118 Smart Charge Communication.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the XmlSecurity module. >> XmlSecurity.h
 *********************************************************************************************************************/
#if !defined (XMLSECURITY_LCFG_H)
# define XMLSECURITY_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "XmlSecurity_Types.h"

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# if ( defined XMLSECURITY_CONFIG_VARIANT ) && ( 3u != XMLSECURITY_CONFIG_VARIANT )

#  define XMLSECURITY_START_SEC_CONST_UNSPECIFIED
#  include "XmlSecurity_MemMap.h"                                                                                       /* PRQA S 5087 */ /*  MD_MSR_MemMap */

extern CONST(XmlSecurity_ConfigType, XMLSECURITY_CONST) XmlSecurity_Config;

#  define XMLSECURITY_STOP_SEC_CONST_UNSPECIFIED
#  include "XmlSecurity_MemMap.h"                                                                                       /* PRQA S 5087 */ /*  MD_MSR_MemMap */

# endif /* (XMLSECURITY_CONFIG_VARIANT) && (3u == XMLSECURITY_CONFIG_VARIANT) */

#endif /* XMLSECURITY_LCFG_H */
/**********************************************************************************************************************
 *  END OF FILE: XmlSecurity_Lcfg.h
 *********************************************************************************************************************/
