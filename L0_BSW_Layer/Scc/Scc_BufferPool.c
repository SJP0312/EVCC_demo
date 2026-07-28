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
/*!        \file  Scc_BufferPool.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Buffer Pool handling to share buffers between different parallel channels.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#define SCC_BUFFERPOOL_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_BufferPool.h"
#include "Scc_Core_Channel.h"
#include "Scc_Priv.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL_INLINE)
# define SCC_LOCAL_INLINE LOCAL_INLINE
#endif

#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/

 /* 8bit variables - no init */
#define SCC_START_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(boolean, SCC_VAR_NOINIT) Scc_BufferPool_Busy[SCC_NUM_OF_POOL_BUFF];

#define SCC_STOP_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_BufferPool_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_BufferPool_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for number of channels */
  for (; index < (uint8_least)SCC_NUM_OF_POOL_BUFF; index++)
  {
    /* #20 Set Scc_BufferPool_Busy to false */
    Scc_BufferPool_Busy[index] = FALSE;
  }
}

/**********************************************************************************************************************
 *  Scc_BufferPoolRequest
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_BufferPoolRequest(
  Scc_PoolBuffType PoolBuffType,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) PoolIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8_least index = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for number of pool buffers */
  for (; index < SCC_NUM_OF_POOL_BUFF; index++)
  {
    /* #20 Check if PoolBuffType matches and if buffer is not busy */
    if ((Scc_PoolBufferArray[index].PoolBuffType == PoolBuffType) && (Scc_BufferPool_Busy[index] == FALSE))
    {
      /* #30 Return Index and Set flag that buffer is busy */
      *PoolIdPtr = (uint8)index;
      Scc_BufferPool_Busy[index] = TRUE;
      retVal = E_OK;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_BufferPoolRelease
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_BufferPoolRelease(uint8 PoolId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if PoolId is valid */
  if (PoolId < SCC_NUM_OF_POOL_BUFF)
  {
    if (Scc_BufferPool_Busy[PoolId] == TRUE)
    {
      /* #20 Set that the buffer is not busy */
      Scc_BufferPool_Busy[PoolId] = FALSE;
    }
    else
    {
      /* #30 Report error */
      Scc_ReportError(Scc_StackError_BufferPool, SccDetailedError_BuffPool_ReleaseError);
    }
  }
#if (SCC_DEV_ERROR_REPORT == STD_ON)
  else
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_RELEASE_BUFFER, SCC_DET_INV_PARAM);
  }
#endif /* SCC_DEV_ERROR_REPORT */
}

/**********************************************************************************************************************
 *  Scc_BufferPoolGetBuffer
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_BufferPoolGetBuffer(
  uint8 PoolId,
  P2VAR(uint8 *, AUTOMATIC, SCC_APPL_DATA) BufferPtrPtr,
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) BufferSizePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 sizePoolBuff = SCC_NUM_OF_POOL_BUFF;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if PoolId is valid */
  if (PoolId < sizePoolBuff)
  {
    /* #20 Return pointers for given PoolId */
    *BufferPtrPtr = Scc_PoolBufferArray[PoolId].BufferPtr;
    *BufferSizePtr = Scc_PoolBufferArray[PoolId].BufferLen;
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_BufferPoolRequestGetBuffer
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_BufferPoolRequestGetBuffer(
  Scc_PoolBuffType PoolBuffType,
  P2VAR(uint8*, AUTOMATIC, SCC_APPL_DATA) BufferPtrPtr,
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) BufferSizePtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) PoolIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if BufferPool could not be requested */
  if (Scc_BufferPoolRequest(PoolBuffType, PoolIdPtr) != E_OK)
  {
    /* #20 Report error */
    Scc_ReportError(Scc_StackError_BufferPool, SccDetailedError_BuffPool_RequestError);
  }
  /* #30 Otherwise */
  else
  {
    /* #40 Fetch buffer */
    (void)Scc_BufferPoolGetBuffer(*PoolIdPtr, BufferPtrPtr, BufferSizePtr);
    /* Return Ok */
    retVal = E_OK;
  }

  return retVal;
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_BufferPool.c
 *********************************************************************************************************************/
