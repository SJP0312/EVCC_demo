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
/*!        \file  Slac_Cbk.h
 *        \brief  Slac callback header file
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 **********************************************************************************************************************/

#if !defined (SLAC_CBK_H)
# define SLAC_CBK_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "Slac_Cfg.h"
#include "EthIf_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define SLAC_START_SEC_CODE
# include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/***********************************************************************************************************************
 *  Slac_Cbk_FirmwareDownloadBegin
 **********************************************************************************************************************/
/*! \brief       Indicate that the PLC chip firmware download has been started
 *  \details     -
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-207363
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_Cbk_FirmwareDownloadBegin(void);

/***********************************************************************************************************************
 *  Slac_Cbk_FirmwareDownloadEnd
 **********************************************************************************************************************/
/*! \brief       Indicate that the PLC chip firmware download has been finished
 *  \details     -
 *  \param[in]   Success              True: Finished; False: Failed
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-207363
 *  \note        A failed call can be overwritten later e.g. firmware download times out, but PLC chip 
 *               still finishes in a retry later.
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_Cbk_FirmwareDownloadEnd(
  CONST(boolean, SLAC_CONST) Success);

/***********************************************************************************************************************
 *  Slac_Cbk_ReadyForSlac
 **********************************************************************************************************************/
/*! \brief       PLC chip is ready to start the SLAC process
 *  \details     -
 *  \param[in]   ReadyForSlac         True: Ready; False: Not ready/failed
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-207364
 *  \note        A failed call can be overwritten later e.g. SLAC ready first times out, but PLC chip 
 *               indicates 'ready' later.
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_Cbk_ReadyForSlac(
  CONST(boolean, SLAC_CONST) ReadyForSlac);

/***********************************************************************************************************************
 *  Slac_Cbk_TrcvLinkStateChanged
 **********************************************************************************************************************/
/*! \brief       Receives transceiver link state changes
 *  \details     -
 *  \param[in]   CtrlIdx              EthIf controller index on which the transceiver link state has been changed
 *  \param[in]   TrcvLinkState        New link state
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-207365
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_Cbk_TrcvLinkStateChanged(
  VAR(uint8, SLAC_APPL_VAR) CtrlIdx,
  VAR(EthTrcv_LinkStateType, SLAC_APPL_VAR) TrcvLinkState);

/***********************************************************************************************************************
 *  Slac_Cbk_RxIndication
 **********************************************************************************************************************/
/*! \brief       Receives MME messages
 *  \details     This API performs general checks on received MME message and forwards the message to specific 
 *               processing functions.
 *  \param[in]   CtrlIdx              EthIf controller index on which the frame was received
 *  \param[in]   EthernetType         Ethernet type of the received frame
 *  \param[in]   IsBroadcast          True: Frame was sent to a broadcast address; False: Was unicast
 *  \param[in]   SrcMacPtr            Pointer to the source MAC address of the frame
 *  \param[in]   PayloadPtr           Pointer to the payload of the frame
 *  \param[in]   PayloadLen           Length of the payload in byte
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-207366
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_Cbk_RxIndication(
  VAR(uint8, SLAC_APPL_VAR) CtrlIdx,
  VAR(uint16, SLAC_APPL_VAR) EthernetType,
  VAR(boolean, SLAC_APPL_VAR) IsBroadcast,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  VAR(uint16, SLAC_APPL_VAR) PayloadLen);

# define SLAC_STOP_SEC_CODE
# include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#endif  /* SLAC_CBK_H */

/***********************************************************************************************************************
 *  END OF FILE: Slac_Cbk.h
 **********************************************************************************************************************/
