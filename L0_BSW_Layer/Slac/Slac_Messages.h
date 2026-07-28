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
/*!        \file  Slac_Messages.h
 *        \brief  Slac header file
 *      \details  Message specific header file of the Slac module.
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

#if !defined (SLAC_MESSAGES_H)
# define SLAC_MESSAGES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Slac_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define SLAC_START_SEC_CODE
# include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  Slac_InitMessageParameters()
 *********************************************************************************************************************/
/*! \brief       Initialize parameters for messages
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_InitMessageParameters(void);

/**********************************************************************************************************************
 *  Slac_HandleGeneralMessageExchange()
 *********************************************************************************************************************/
/*! \brief       Transmits request messages and optionally receives confirmation message if required
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_HandleGeneralMessageExchange(void);

/**********************************************************************************************************************
 *  Slac_ReceiveCmSlacParmCnf()
 *********************************************************************************************************************/
/*! \brief       Receives a CM_SLAC_PARM.CNF message
 *  \details     -
 *  \param[in]   SrcMacPtr            Pointer to the source byte array
 *  \param[in]   PayloadPtr           Pointer to the payload that shall be received
 *  \param[in]   PayloadLen           Length of the payload
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_ReceiveCmSlacParmCnf(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen);

/**********************************************************************************************************************
 *  Slac_HandleCmAttenCharExchange()
 *********************************************************************************************************************/
/*! \brief       Handles the reception of CM_ATTEN_CHAR messages
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_HandleCmAttenCharExchange(void);

/**********************************************************************************************************************
 *  Slac_ReceiveCmAttenCharInd()
 *********************************************************************************************************************/
/*! \brief       Receives a CM_ATTEN_CHAR.IND message
 *  \details     -
 *  \param[in]   SrcMacPtr            Pointer to the source byte array
 *  \param[in]   PayloadPtr           Pointer to the payload that shall be received
 *  \param[in]   PayloadLen           Length of the payload
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_ReceiveCmAttenCharInd(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen);

/**********************************************************************************************************************
 *  Slac_ReceiveCmValidateCnf()
 *********************************************************************************************************************/
/*! \brief       Receives a CM_VALIDATE.CNF message
 *  \details     -
 *  \param[in]   SrcMacPtr            Pointer to the source byte array
 *  \param[in]   PayloadPtr           Pointer to the payload that shall be received
 *  \param[in]   PayloadLen           Length of the payload
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_ReceiveCmValidateCnf(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen);

/**********************************************************************************************************************
 *  Slac_ReceiveCmSlacMatchCnf()
 *********************************************************************************************************************/
/*! \brief       Receives a CM_SLAC_MATCH.CNF message
 *  \details     -
 *  \param[in]   SrcMacPtr            Pointer to the source byte array
 *  \param[in]   PayloadPtr           Pointer to the payload that shall be received
 *  \param[in]   PayloadLen           Length of the payload
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_ReceiveCmSlacMatchCnf(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen);

/**********************************************************************************************************************
 *  Slac_ReceiveCmSetKeyCnf()
 *********************************************************************************************************************/
/*! \brief       Receives a CM_SET_KEY.CNF message
 *  \details     -
 *  \param[in]   SrcMacPtr            Pointer to the source byte array
 *  \param[in]   PayloadPtr           Pointer to the payload that shall be received
 *  \param[in]   PayloadLen           Length of the payload
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_ReceiveCmSetKeyCnf(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen);

/**********************************************************************************************************************
 *  Slac_HandleCmAmpMapExchange()
 *********************************************************************************************************************/
/*! \brief       Handles the optional transmission and reception of the CM_AMP_MAP message
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_HandleCmAmpMapExchange(void);

/**********************************************************************************************************************
 *  Slac_ReceiveCmAmpMapReq()
 *********************************************************************************************************************/
/*! \brief       Receives a CM_AMP_MAP.REQ message
 *  \details     -
 *  \param[in]   SrcMacPtr            Pointer to the source byte array
 *  \param[in]   PayloadPtr           Pointer to the payload that shall be received
 *  \param[in]   PayloadLen           Length of the payload
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_ReceiveCmAmpMapReq(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen);

/**********************************************************************************************************************
 *  Slac_ReceiveCmAmpMapCnf()
 *********************************************************************************************************************/
/*! \brief       Receives a CM_AMP_MAP.CNF message
 *  \details     -
 *  \param[in]   SrcMacPtr            Pointer to the source byte array
 *  \param[in]   PayloadPtr           Pointer to the payload that shall be received
 *  \param[in]   PayloadLen           Length of the payload
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_ReceiveCmAmpMapCnf(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen);

/**********************************************************************************************************************
 *  Slac_CopyArray()
 *********************************************************************************************************************/
/*! \brief       Copy one array to another array
 *  \details     -
 *  \param[in]   SourcePtr            Pointer to the source byte array
 *  \param[in]   TargetPtr            Pointer to the destination byte array
 *  \param[in]   TargetLen            Length of both byte array
 *  \pre         This API does not lock any interrupts, in case data consistency is relevant, call it within an ISR lock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_CopyArray(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SourcePtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) TargetPtr,
  CONST(uint16, SLAC_CONST) CopyLen);

/**********************************************************************************************************************
 *  Slac_SetConstValueToArray()
 *********************************************************************************************************************/
/*! \brief       Sets a constant value to a byte array
 *  \details     -
 *  \param[in]   Value                Value to set
 *  \param[in]   TargetPtr            Pointer to the destination byte array
 *  \param[in]   TargetLen            Length of the destination byte array
 *  \pre         This API does not lock any interrupts, in case data consistency is relevant, call it within an ISR lock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_SetConstValueToArray(
  CONST(uint8, SLAC_CONST) Value,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) TargetPtr,
  CONST(uint16, SLAC_CONST) TargetLen);

/**********************************************************************************************************************
 *  Slac_CopyPhysAddress()
 *********************************************************************************************************************/
/*! \brief       Copies a MAC address from the 6 bytes source buffer to the target buffer
 *  \details     -
 *  \param[in]   SourcePtr            Pointer to the MAC address that shall be copied
 *  \param[in]   TargetPtr            Pointer to the MAC address destination buffer
 *  \pre         This API does not lock any interrupts, in case data consistency is relevant, call it within an ISR lock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_CopyPhysAddress(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SourcePtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA)  TargetPtr);

/**********************************************************************************************************************
 *  Slac_CheckPhysAddress()
 *********************************************************************************************************************/
/*! \brief       Checks if the two provided 6 bytes MAC addresses do match each other
 *  \details     -
 *  \param[in]   MacToCheckPtr        Pointer to the MAC address that shall be checked
 *  \param[in]   MacExpectedPtr       Pointer to the MAC address that is expected
 *  \return      Slac_RT_Ok    - Provided address is correct
 *  \return      Slac_RT_NotOk - Provided address is not correct
 *  \pre         This API does not lock any interrupts, in case data consistency is relevant, call it within an ISR lock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckPhysAddress(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) MacToCheckPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) MacExpectedPtr);

# define SLAC_STOP_SEC_CODE
# include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#endif /* SLAC_MESSAGES_H */

/**********************************************************************************************************************
 *  END OF FILE: Slac_Messages.h
 *********************************************************************************************************************/
