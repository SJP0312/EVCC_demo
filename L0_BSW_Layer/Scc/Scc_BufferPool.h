/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Scc_BufferPool.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Buffer Pool handling to share buffers between different parallel channels.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_BUFFERPOOL_H)
#define SCC_BUFFERPOOL_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_BufferPool_Init()
 *********************************************************************************************************************/
/*! \brief          Initialize all the Scc_BufferPool variables.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_BufferPool_Init(void);

/**********************************************************************************************************************
 *  Scc_BufferPoolRequest
 *********************************************************************************************************************/
/*! \brief          Returns PoolId in case buffer is available.
 *  \details        -
 *  \param[in]      PoolBuffType     Type of buffer to be requested
 *  \param[out]     PoolIdPtr        PoolId of the available buffer
 *  \return         E_OK             Buffer available.
 *  \return         E_NOT_OK         Buffer not available.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_BufferPoolRequest(
  Scc_PoolBuffType PoolBuffType,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) PoolIdPtr);

/**********************************************************************************************************************
 *  Scc_BufferPoolRelease
 *********************************************************************************************************************/
/*! \brief          Releases the buffer used so that it can be used later on.
 *  \details        -
 *  \param[in]      PoolId     PoolId of the buffer
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_BufferPoolRelease(uint8 PoolId);

/**********************************************************************************************************************
 *  Scc_BufferPoolGetBuffer
 *********************************************************************************************************************/
/*! \brief          Returns buffer pointer and size of buffer.
 *  \details        -
 *  \param[out]     BufferPtrPtr  Pointer to the available buffer
 *  \param[out]     BufferSizePtr Size of returned buffer
 *  \return         E_OK          No errors.
 *  \return         E_NOT_OK      Invalid PoolId.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_BufferPoolGetBuffer(
  uint8 PoolId,
  P2VAR(uint8*, AUTOMATIC, SCC_APPL_DATA) BufferPtrPtr,
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) BufferSizePtr);

/**********************************************************************************************************************
 *  Scc_BufferPoolRequestGetBuffer
 *********************************************************************************************************************/
/*! \brief          Returns PoolId, buffer pointer and size of buffer in case available.
 *  \details        -
 *  \param[in]      PoolBuffType     Type of buffer to be requested
 *  \param[out]     BufferPtrPtr     Pointer to the available buffer
 *  \param[out]     BufferSizePtr    Size of returned buffer
 *  \param[out]     PoolIdPtr        PoolId of the available buffer
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_BufferPoolRequestGetBuffer(
  Scc_PoolBuffType PoolBuffType,
  P2VAR(uint8*, AUTOMATIC, SCC_APPL_DATA) BufferPtrPtr,
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) BufferSizePtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) PoolIdPtr);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_BUFFERPOOL_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_BufferPool.h
 *********************************************************************************************************************/
