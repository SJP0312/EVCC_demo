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
/*!        \file  Slac_Priv.h
 *        \brief  Slac header file
 *      \details  Private (internal) header file of the Slac module.
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 **********************************************************************************************************************/

#if !defined (SLAC_PRIV_H)
# define SLAC_PRIV_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Slac_Types.h"
# include "Slac_Lcfg.h"
# if (SLAC_DEV_ERROR_REPORT == STD_ON)
#  include "Det.h"
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* PRQA S 3453 5 */ /* MD_MSR_FctLikeMacro */
# if (SLAC_DEV_ERROR_REPORT == STD_ON)
#  define Slac_DetReportError(ApiID, ErrorID) (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, (ApiID), (ErrorID))
# else
#  define Slac_DetReportError(ApiID, ErrorID)
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined(SLAC_ETHIF_PROVIDE_TX_BUFFER_API)
# define SLAC_ETHIF_PROVIDE_TX_BUFFER_API EthIf_ProvideTxBuffer
#endif
#if !defined(SLAC_ETHIF_TRANSMIT_API)
# define SLAC_ETHIF_TRANSMIT_API EthIf_Transmit
#endif
#if !defined(SLAC_ETHIF_GET_PHYS_ADDR_API)
# define SLAC_ETHIF_GET_PHYS_ADDR_API EthIf_GetPhysAddr
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define SLAC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

extern VAR(Slac_StateType, SLAC_VAR_NOINIT) Slac_State;

#define SLAC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define SLAC_START_SEC_CODE
# include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  Slac_AssociationStatus()
 *********************************************************************************************************************/
/*! \brief       Indicates the association status event to the application
 *  \details     If there is a DLink down change, it is indicated to the applciation too
 *  \param[in]   AssocStep            Current association step
 *  \param[in]   AssocEvent           Association status event
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_AssociationStatus(
  CONST(Slac_AssocStatusStepType, SLAC_CONST) AssocStep,
  CONST(Slac_AssocStatusEventType, SLAC_CONST) AssocEvent);

/**********************************************************************************************************************
 *  Slac_EvseProfilesGetIfKnownOrCreate()
 *********************************************************************************************************************/
/*! \brief       Gets a known EVSE profile or creates new one
 *  \details     -
 *  \param[in]   EvseMacPtr           Pointer to the MAC address of the EVSE
 *  \param[out]  RetEvseProfilePtrPtr Poitner to the EVSE profile
 *  \param[in]   AllowCreation        True: Creating new EVSE profile entries is allowed
 *                                    False: Only search for known EVSEs in the known list
 *  \return      Slac_RT_Ok    - Known or new EVSE profile is provided
 *  \return      Slac_RT_NotOk - Failed: EVSE not found or creation not possible
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Slac_ReturnType, SLAC_CODE) Slac_EvseProfilesGetIfKnownOrCreate(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) EvseMacPtr,
  P2VAR(Slac_EvseProfilesType*, AUTOMATIC, SLAC_APPL_DATA) RetEvseProfilePtrPtr,
  CONST(Slac_BooleanType, SLAC_CONST) AllowCreation);

# define SLAC_STOP_SEC_CODE
# include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#endif /* SLAC_PRIV_H */

/**********************************************************************************************************************
 *  END OF FILE: Slac.h
 *********************************************************************************************************************/
