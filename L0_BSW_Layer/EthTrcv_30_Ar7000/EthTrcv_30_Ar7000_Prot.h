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
/**        \file  EthTrcv_30_Ar7000_Prot.h
 *        \brief  Ethernet transceiver driver QCA 7005 protected header file
 *
 *      \details  Vector static code protected header file for the Ethernet transceiver driver QCA 7005. This
 *                header file contains module declarations that are module internal.
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

#if !defined (ETHTRCV_30_AR7000_PROT_H)
# define ETHTRCV_30_AR7000_PROT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EthIf.h"
#include "EthTrcv_30_Ar7000_Types.h"

/**********************************************************************************************************************
 *  PROTECTED DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK )

/* Module operation base parameters */
typedef struct
{
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) ModOpBufPtr;
  uint16 ModOpFrameLen;
  uint16 ModOpTotLen;
  uint8 ModOpState;
  uint8 ModOpLockCnt;
} EthTrcv_30_Ar7000_ModOp_Params;

/* Module operation read parameters */
typedef struct
{
  EthTrcv_30_Ar7000_ModOp_Params BaseParams;
  uint32 ModOpStartOffset;
  uint32 ModOpCurOffset; /* current offset into module (at initialization same value than StartOffset) */
  uint16 ModOpModuleId;
  uint16 ModOpModuleSubId;
  uint16 ModOpDataLenTx; /* total size of requested data */
} EthTrcv_30_Ar7000_ModOp_Rd_Params;

#endif /* ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) ||
          ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API )  ||
          ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK ) */

/**********************************************************************************************************************
 *  PROTECTED FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_VFrameHeader
 **********************************************************************************************************************/
/*!
 * \brief       Writes the Qualcomm specific MME header into the buffer
 * \details     The assembled header portion consists of the MMV, the MMType and OUI fields (5 Bytes)
 * \param[in]   TrcvIdx           Zero based index of the transceiver
 * \param[in]   MMType            16 Bit MMType identifier according to Qualcomm specification. The endianess
 *                                complies with the platform specific endianess
 * \param[in]   EthBufPtr         Pointer to the buffer the header shall be written to.
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 */
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_VFrameHeader(
        uint8                                                                                               TrcvIdx,
        uint16                                                                                              MMType,
  P2CONST(EthTrcv_30_Ar7000_EthernetBufferType, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_CONST) EthBufPtr);

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API ) || \
    ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_ModuleOperation
 **********************************************************************************************************************/
/*!
 * \brief       Starts a new module operation session.
 * \details     See Qualcomm documentation for detailed information about the module operation use cases.
 *              Please pay special attention to the integration chapter for correct usage of this API.
 * \param[in]   TrcvIdx        Zero based index of the transceiver
 * \param[in]   ModOp          One of the module operations types stated below.\n
 *                             See Qualcomm documentation for detailed information:\n
 *                               - ETHTRCV_30_AR7000_MODOP_RD_MEM (supported)\n
 *                               - ETHTRCV_30_AR7000_MODOP_RD_NVM (currently not supported!)\n
 *                               - ETHTRCV_30_AR7000_MODOP_STRT_WR (currently not supported!)\n
 *                               - ETHTRCV_30_AR7000_MODOP_WR (currently not supported!)\n
 *                               - ETHTRCV_30_AR7000_MODOP_COMMIT (currently not supported!)\n
 *                               - ETHTRCV_30_AR7000_MODOP_READ (currently not supported!)
 * \param[in]   Params         Parameters of type EthTrcv_30_Ar7000_ModOp_Params.\n
 *                             See integration chapter in Technical Reference for detailed information.
 *                             The EthTrcv_30_Ar7000_ModOp_Params is a base type that is usually derived by module
 *                             operation specific subtypes.\n
 *                             Type EthTrcv_30_Ar7000_ModOp_Rd_Params derives from EthTrcv_30_Ar7000_ModOp_Params
 *                             and is used for ETHTRCV_30_AR7000_MODOP_RD_MEM. Instantiate an object of type
 *                             ETHTRCV_30_AR7000_MODOP_RD_MEM and cast to base type EthTrcv_30_Ar7000_ModOp_Params.
 * \return      E_OK           Session successfully start. E_OK does not indicate that the session is already done
 * \return      E_NOT_OK       Could not start the session.
 * \pre         -
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP || ETHTRCV_30_AR7000_ENABLE_MODOP_API ||
                ETHTRCV_30_AR7000_ENABLE_READ_NMK
 * \note        This is an expert API. Please pay special attention to the technical reference for a correct usage of
 *              the API. You may also have a detailed look into Qualcomm documentation for the module operation usage.\n
 *              Currently, only ETHTRCV_30_AR7000_MODOP_RD_MEM is supported!
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_ModuleOperation(
        uint8                                                                                   TrcvIdx,
        uint16                                                                                  ModOp,
  P2VAR(EthTrcv_30_Ar7000_ModOp_Params, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) Params );
#endif /* ( STD_ON == ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP ) ||
          ( STD_ON == ETHTRCV_30_AR7000_ENABLE_MODOP_API )  ||
          ( STD_ON == ETHTRCV_30_AR7000_ENABLE_READ_NMK ) */

#endif /* ETHTRCV_30_AR7000_PROT_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ar7000_Prot.h
 *********************************************************************************************************************/

