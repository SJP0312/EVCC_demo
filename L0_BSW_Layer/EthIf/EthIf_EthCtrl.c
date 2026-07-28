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
/*!        \file  EthIf_EthCtrl.c
 *        \brief  EthIf EthCtrl public API source file
 *
 *      \details  Implementation of the public API of the sub-module EthCtrl of EthIf.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define ETHIF_ETHCTRL_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/*********************************************************************************************************
 * Predefined file includes based on \trace DSGN-EthIfDiag1975
 *********************************************************************************************************/
#include "EthIf_EthCtrl.h"
#include "EthIf_EthCtrl_Cbk.h"
#include "EthIf_EthCtrl_Int.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of Msn header file */
#if (  (ETHIF_SW_MAJOR_VERSION != (18u)) \
    || (ETHIF_SW_MINOR_VERSION != (0u)) \
    || (ETHIF_SW_PATCH_VERSION != (8u)) )
# error "Vendor specific version numbers of EthIf_EthCtrl.c and EthIf.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (ETHIF_ETHCTRL_LOCAL)                                                                                      /* COV_ETHIF_LOCAL_INLINE */
# define ETHIF_ETHCTRL_LOCAL                                          static
#endif

#if !defined (ETHIF_ETHCTRL_LOCAL_INLINE)                                                                               /* COV_ETHIF_LOCAL_INLINE */
# define ETHIF_ETHCTRL_LOCAL_INLINE                                   LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define ETHIF_START_SEC_CODE
#include "EthIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#if ( ETHIF_PHC_SUPPORT == STD_ON )
/***********************************************************************************************************************
 *  EthIf_Internal_GetCurrentTimeTuple
 **********************************************************************************************************************/
/*! \brief          Internal function to retrieve the current time from the driver using Eth_GetCurrentTimeTuple API.
 *  \details        -
 *  \param[in]      ethIfPhysCtrlCfgIdx  Index of configuration element of the physical controller generated by the
 *                                       comstacklib that owns the clock unit
 *  \param[in]      clkUnitIdx           Index of the Clock Unit within the context of the Ethernet Interface to provide
 *                                       the time tuple
 *  \param[out]     currentTimeTuplePtr  Current time tuple with the
                                          - value of the free-running clock used for timestamping
                                          - value of the adjustable PHC
 *  \return         E_OK - Current time successfully retrieved
 *  \return         E_NOT_OK - Current time could not be retrieved
 *  \pre            -
 *  \context        ANY
 *  \reentrant      FALSE
 *********************************************************************************************************************/
ETHIF_ETHCTRL_LOCAL_INLINE FUNC(Std_ReturnType, ETHIF_CODE) EthIf_Internal_GetCurrentTimeTuple(
        EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType  ethIfPhysCtrlCfgIdx,
        uint8                                     clkUnitIdx,
  P2VAR(TimeTupleType, AUTOMATIC, ETHIF_APPL_VAR) currentTimeTuplePtr);

/***********************************************************************************************************************
 *  EthIf_Internal_GetCurrentTime
 **********************************************************************************************************************/
/*! \brief          Internal function to retrieve the current time tuple from the driver that is older that AR23-11.
 *  \details        This function retrieves the current time from the controller by calling Eth_GetCurrentTime and
 *                  copies the retrievd time to passed param currentTimeTuplePtr.
 *  \param[in]      ethIfPhysCtrlCfgIdx  Index of configuration element of the physical controller generated by the
 *                                       comstacklib that owns the clock unit
 *  \param[out]     currentTimeTuplePtr  Current time tuple with the
                                          - value of the free-running clock used for timestamping
                                          - value of the adjustable PHC
 *  \return         E_OK - Current time successfully retrieved
 *  \return         E_NOT_OK - Current time could not be retrieved
 *  \pre            -
 *  \context        ANY
 *  \reentrant      FALSE
 *  \note           This function is called from EthIf_GetCurrentTimeTuple API to provide compatibility for the Ethernet
 *                  drivers older than AR23-11
 *********************************************************************************************************************/
ETHIF_ETHCTRL_LOCAL_INLINE FUNC(Std_ReturnType, ETHIF_CODE) EthIf_Internal_GetCurrentTime(
        EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType  ethIfPhysCtrlCfgIdx,
  P2VAR(TimeTupleType, AUTOMATIC, ETHIF_APPL_VAR) currentTimeTuplePtr);
#endif /* ETHIF_PHC_SUPPORT */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if ( ETHIF_PHC_SUPPORT == STD_ON )
/**********************************************************************************************************************
 *  EthIf_Internal_GetCurrentTimeTuple
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
ETHIF_ETHCTRL_LOCAL_INLINE FUNC(Std_ReturnType, ETHIF_CODE) EthIf_Internal_GetCurrentTimeTuple(
        EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType  ethIfPhysCtrlCfgIdx,
        uint8                                     clkUnitIdx,
  P2VAR(TimeTupleType, AUTOMATIC, ETHIF_APPL_VAR) currentTimeTuplePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHIF_E_NO_ERROR;

  EthIf_EthDrvApiIdxOfEthIfPhysCtrlCfgType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx);

  /* #10 Check if driver provides the API */
  if( EthIf_GetGetCurrentTimeTupleOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
  {
    EthIf_EthIfClkUnitIterType ethIfClkUnitIdx = (EthIf_EthIfClkUnitIterType)EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx) + clkUnitIdx;

    /* #110 Redirect call to the driver */
    retVal = EthIf_GetGetCurrentTimeTupleOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetEthCtrlIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx),
                                                                    (uint8)EthIf_GetEthClkUnitIdxOfEthIfClkUnit(ethIfClkUnitIdx),
                                                                    currentTimeTuplePtr);                               /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */
  }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
  else
  {
    errorId = ETHIF_E_INV_DRIVER_API_CALL;
  }
# endif /* ETHIF_DEV_ERROR_DETECT */

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #20 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_CURRENT_TIME_TUPLE, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_Internal_GetCurrentTimeTuple() */

/**********************************************************************************************************************
 *  EthIf_Internal_GetCurrentTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
ETHIF_ETHCTRL_LOCAL_INLINE FUNC(Std_ReturnType, ETHIF_CODE) EthIf_Internal_GetCurrentTime(
        EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType  ethIfPhysCtrlCfgIdx,
  P2VAR(TimeTupleType, AUTOMATIC, ETHIF_APPL_VAR) currentTimeTuplePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHIF_E_NO_ERROR;

  EthIf_EthDrvApiIdxOfEthIfPhysCtrlCfgType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx);

  /* #10 Check if driver provides the API */
  if( EthIf_GetGetCurrentTimeOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
  {
    Eth_TimeStampType timeStamp;
    Eth_TimeStampQualType timeQual;

    /* #110 Redirect call to the driver */
    retVal = EthIf_GetGetCurrentTimeOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetEthCtrlIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx),
                                                              &timeStamp,
                                                              &timeQual);                                               /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */

    /* #120 If the retrievd time is valid */
    if (retVal == E_OK)
    {
      /* #1210 Copy the retrieved time info into the passed parameter structure currentTimeTuplePtr */
      currentTimeTuplePtr->disciplinedClockValue.nanoseconds = timeStamp.nanoseconds;                                   /* SBSW_ETHIF_INT_FCT_PARAM_PTR_WRITE */
      currentTimeTuplePtr->disciplinedClockValue.seconds = timeStamp.seconds;                                           /* SBSW_ETHIF_INT_FCT_PARAM_PTR_WRITE */
      currentTimeTuplePtr->disciplinedClockValue.secondsHi = timeStamp.secondsHi;                                       /* SBSW_ETHIF_INT_FCT_PARAM_PTR_WRITE */
      currentTimeTuplePtr->timestampClockValue = currentTimeTuplePtr->disciplinedClockValue;                            /* SBSW_ETHIF_INT_FCT_PARAM_PTR_WRITE */

      switch (timeQual)
      {
        case ETH_TIMESTAMP_VALID:
          currentTimeTuplePtr->timeQuality = VALID;                                                                     /* SBSW_ETHIF_INT_FCT_PARAM_PTR_WRITE */
          break;
        case ETH_TIMESTAMP_INVALID:
          currentTimeTuplePtr->timeQuality = INVALID;                                                                    /* SBSW_ETHIF_INT_FCT_PARAM_PTR_WRITE */
          break;
        case ETH_TIMESTAMP_UNCERTAIN:
          currentTimeTuplePtr->timeQuality = UNCERTAIN;                                                                 /* SBSW_ETHIF_INT_FCT_PARAM_PTR_WRITE */
          break;
        default:
          /* Invalid time quality value */
          retVal = E_NOT_OK;
          break;
      }
    }
  }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
  else
  {
    errorId = ETHIF_E_INV_DRIVER_API_CALL;
  }
# endif /* ETHIF_DEV_ERROR_DETECT */

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #20 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_CURRENT_TIME_TUPLE, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_Internal_GetCurrentTime() */
#endif /* ETHIF_PHC_SUPPORT */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  EthIf_GetPhysAddr
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, ETHIF_CODE) EthIf_GetPhysAddr(
        uint8                              CtrlIdx,
  P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR)  PhysAddrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
    uint8 errorId = ETHIF_E_NO_ERROR;

    /* ----- Development Error Checks ------------------------------------- */
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                  /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( PhysAddrPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
#endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Redirect the call to the addressed Ethernet driver */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    EthIf_GetGetPhysAddrOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                  PhysAddrPtr);                                                         /* SBSW_ETHIF_DRVAPI_FCT_PTR_MAN_WITH_PUB_PARAM_PTR_CSL03 */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_PHYS_ADDR, errorId);
  }
#else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif

} /* EthIf_GetPhysAddr() */

/**********************************************************************************************************************
 *  EthIf_SetPhysAddr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, ETHIF_CODE) EthIf_SetPhysAddr(
          uint8                               CtrlIdx,
  P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA)  PhysAddrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                  /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( PhysAddrPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
#endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Redirect the call to the addressed Ethernet driver */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    EthIf_SetValidOfSrcMacAddrBuffer(ethCtrlIdx, FALSE);                                                                /* SBSW_ETHIF_COMMON_CSL03 */

    EthIf_GetSetPhysAddrOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                  PhysAddrPtr);                                                         /* SBSW_ETHIF_DRVAPI_FCT_PTR_MAN_WITH_PUB_PARAM_PTR_CSL03 */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_SET_PHYS_ADDR, errorId);
  }
#else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif

} /* EthIf_SetPhysAddr() */

#if ( ETHIF_ENABLE_UPDATE_PHYS_ADDR_FILTER == STD_ON )
/**********************************************************************************************************************
 *  EthIf_UpdatePhysAddrFilter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_UpdatePhysAddrFilter( /* PRQA S 6080 */ /* MD_MSR_STMIF */
          uint8                                             CtrlIdx,
  P2CONST(uint8,               AUTOMATIC, ETHIF_APPL_DATA)  PhysAddrPtr,
          Eth_FilterActionType                              Action)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType  retVal  = E_NOT_OK;
  uint8           errorId = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( PhysAddrPtr == NULL_PTR)
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else if( (Action != ETH_ADD_TO_FILTER)      &&
           (Action != ETH_REMOVE_FROM_FILTER)    )
  {
    errorId = ETHIF_E_INV_PARAM;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetUpdatePhysAddrFilterOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
    {
      /* #300 Redirect call to the driver */
      retVal = EthIf_GetUpdatePhysAddrFilterOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                                      PhysAddrPtr,
                                                                      Action);                                          /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId = ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_UPDATE_PHYS_ADDR_FILTER, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_UpdatePhysAddrFilter() */
#endif/* ETHIF_ENABLE_UPDATE_PHYS_ADDR_FILTER */

#if ( ETHIF_GLOBAL_TIME_SUPPORT == STD_ON )
/***********************************************************************************************************************
 *  EthIf_GetCurrentTime
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetCurrentTime( /* PRQA S 6080 */ /* MD_MSR_STMIF */
        uint8                                              CtrlIdx,
  P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETHIF_APPL_VAR)  timeQualPtr,
  P2VAR(Eth_TimeStampType,     AUTOMATIC, ETHIF_APPL_VAR)  timeStampPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( timeStampPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else if( timeQualPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetGetCurrentTimeOfEthDrvApi(ethDrvIdx) != NULL_PTR )
    {
      /* #300 Redirect call to the driver */
      retVal = EthIf_GetGetCurrentTimeOfEthDrvApi(ethDrvIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                              timeStampPtr,
                                                              timeQualPtr);                                             /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId = ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_CURRENT_TIME, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_GetCurrentTime() */

/***********************************************************************************************************************
 *  EthIf_EnableEgressTimestamp
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_EnableEgressTimestamp(
  uint8  CtrlIdx,
  uint8  BufIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( BufIdx > EthIf_GetMaxTxBufIdxForEthIfCtrl(CtrlIdx) )
  {
    errorId = ETHIF_E_INV_PARAM;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetEnableEgressTimeStampOfEthDrvApi(ethDrvIdx) != NULL_PTR )
    {
      /* #300 Redirect call to the driver */
      retVal = EthIf_GetEnableEgressTimeStampOfEthDrvApi(ethDrvIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                                    BufIdx);                                            /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId = ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_ENABLE_EGRESS_TIMESTAMP, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_EnableEgressTimestamp() */

/***********************************************************************************************************************
 *  EthIf_GetEgressTimestamp
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetEgressTimestamp( /* PRQA S 6080 */ /* MD_MSR_STMIF */
        uint8                                                 CtrlIdx,
        uint8                                                 BufIdx,
  P2VAR(Eth_TimeStampType,        AUTOMATIC, ETHIF_APPL_VAR)  TimestampPtr,
  P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETHIF_APPL_VAR)  TimestampQualityPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( BufIdx > EthIf_GetMaxTxBufIdxForEthIfCtrl(CtrlIdx) )
  {
    errorId = ETHIF_E_INV_PARAM;
  }
  else if( TimestampPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else if( TimestampQualityPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetGetEgressTimeStampOfEthDrvApi(ethDrvIdx) != NULL_PTR )
    {
      /* #300 Redirect call to the driver */
      retVal = EthIf_GetGetEgressTimeStampOfEthDrvApi(ethDrvIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                                  BufIdx,
                                                                  TimestampPtr,
                                                                  TimestampQualityPtr);                                 /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId = ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_EGRESS_TIMESTAMP, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_GetEgressTimestamp() */

/***********************************************************************************************************************
 *  EthIf_GetIngressTimestamp
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetIngressTimestamp( /* PRQA S 6080 */ /* MD_MSR_STMIF */
        uint8                                                 CtrlIdx,
  P2VAR(Eth_DataType,             AUTOMATIC, ETHIF_APPL_VAR)  DataPtr,
  P2VAR(Eth_TimeStampType,        AUTOMATIC, ETHIF_APPL_VAR)  TimestampPtr,
  P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETHIF_APPL_VAR)  TimestampQualityPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( DataPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else if( TimestampPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else if( TimestampQualityPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetGetIngressTimeStampOfEthDrvApi(ethDrvIdx) != NULL_PTR )
    {
      P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR)  u8DataPtr;

      u8DataPtr = (P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR))DataPtr; /* PRQA S 0310 */ /* MD_EthIf_310_Buffer */

      /* #300 Adapt buffer pointer passed to driver depending on type of EthIf controller (un-tagged, tagged) */
      if( EthIf_GetTypeOfEthIfCtrl(CtrlIdx) != ETHIF_ETHIFCTRL_TYPE_PHYSICAL_TYPEOFETHIFCTRL )
      {
        u8DataPtr = &u8DataPtr[-((sint8)ETHIF_VLAN_TAG_LEN_BYTE)]; /* PRQA S 3382 */ /* MD_EthIf_3382 */
      }

      /* #310 Redirect call to the driver */
      /* PRQA S 0310, 3305 4 */ /* MD_EthIf_310_Buffer, MD_EthIf_3305_Buffer */
      retVal = EthIf_GetGetIngressTimeStampOfEthDrvApi(ethDrvIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                                  (P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_VAR))u8DataPtr,
                                                                  TimestampPtr,
                                                                  TimestampQualityPtr);                                 /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId = ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_INGRESS_TIMESTAMP, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_GetIngressTimestamp() */
#endif /* ETHIF_GLOBAL_TIME_SUPPORT */

#if ( ETHIF_PHC_SUPPORT == STD_ON )
/***********************************************************************************************************************
 *  EthIf_GetCurrentTimeTuple
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetCurrentTimeTuple( /* PRQA S 6080 */ /* MD_MSR_STMIF */
        uint8                                     CtrlIdx,
        uint8                                     ClkUnitIdx,
  P2VAR(TimeTupleType, AUTOMATIC, ETHIF_APPL_VAR) CurrentTimeTuplePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                                /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( EthIf_IsEthIfClkUnitUsedOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx)) != TRUE )
  {
    errorId = ETHIF_E_INV_CLKUNIT_IDX;
  }
  else if( ClkUnitIdx >= (EthIf_GetEthIfClkUnitEndIdxOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx)) -
                          EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx))) )
  {
    errorId = ETHIF_E_INV_CLKUNIT_IDX;
  }
  else if( CurrentTimeTuplePtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType ethIfPhysCtrlCfgIdx = EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx);

    /* #30 If the driver supports Eth_GetCurrentTimeTuple API */
    if( EthIf_IsEthPhcSupportAvailableOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx) == TRUE )
    {
      /* #310 Trigger the retrial of current time using Eth_GetCurrentTimeTuple API */
      retVal = EthIf_Internal_GetCurrentTimeTuple(ethIfPhysCtrlCfgIdx, ClkUnitIdx, CurrentTimeTuplePtr);                /* SBSW_ETHIF_INT_FCT_PUB_PARAM_PTR_PASS */
    }
    /* #40 If the driver doesn't supports Eth_GetCurrentTimeTuple API */
    else
    {
      /* #410 Trigger the retrial of current time using Eth_GetCurrentTime API */
      retVal = EthIf_Internal_GetCurrentTime(ethIfPhysCtrlCfgIdx, CurrentTimeTuplePtr);                                 /* SBSW_ETHIF_INT_FCT_PUB_PARAM_PTR_PASS */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #50 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_CURRENT_TIME_TUPLE, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_GetCurrentTimeTuple() */

/***********************************************************************************************************************
 *  EthIf_SetPhcTime
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE)  EthIf_SetPhcTime( /* PRQA S 6080 */ /* MD_MSR_STMIF */
          uint8                                     CtrlIdx,
          uint8                                     ClkUnitIdx,
  P2CONST(TimeStampType, AUTOMATIC, ETHIF_APPL_VAR) TimeStampPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType  retVal   = E_NOT_OK;
  uint8           errorId  = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if(EthIf_IsEthIfClkUnitUsedOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx)) != TRUE)
  {
    errorId = ETHIF_E_INV_CLKUNIT_IDX;
  }
  else if( ClkUnitIdx >= (EthIf_GetEthIfClkUnitEndIdxOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx)) -
                          EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx))))
  {
    errorId = ETHIF_E_INV_CLKUNIT_IDX;
  }
  else if( TimeStampPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType ethIfPhysCtrlCfgIdx = EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthIfPhysCtrlCfgType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetSetPhcTimeOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
    {
      EthIf_EthIfClkUnitIterType ethIfClkUnitIdx = (EthIf_EthIfClkUnitIterType)EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx) + ClkUnitIdx;

      /* #300 Redirect call to the driver */
      retVal = EthIf_GetSetPhcTimeOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetEthCtrlIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx),
                                                            (uint8)EthIf_GetEthClkUnitIdxOfEthIfClkUnit(ethIfClkUnitIdx),
                                                                TimeStampPtr);                                          /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId =  ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_SET_PHC_TIME, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_SetPhcTime() */

/***********************************************************************************************************************
 *  EthIf_SetPhcCorrection
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE)  EthIf_SetPhcCorrection( /* PRQA S 6080 */ /* MD_MSR_STMIF */
  uint8  CtrlIdx,
  uint8  ClkUnitIdx,
  sint32 RateDeviation,
  sint32 Offset)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType  retVal   = E_NOT_OK;
  uint8           errorId  = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if(EthIf_IsEthIfClkUnitUsedOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx)) != TRUE)
  {
    errorId = ETHIF_E_INV_CLKUNIT_IDX;
  }
  else if(ClkUnitIdx >= (EthIf_GetEthIfClkUnitEndIdxOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx)) -
                          EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx))))
  {
    errorId = ETHIF_E_INV_CLKUNIT_IDX;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType ethIfPhysCtrlCfgIdx = EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthIfPhysCtrlCfgType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetSetPhcCorrectionOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
    {
      EthIf_EthIfClkUnitIterType ethIfClkUnitIdx = (EthIf_EthIfClkUnitIterType)EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx) + ClkUnitIdx;

      /* #300 Redirect call to the driver */
      retVal = EthIf_GetSetPhcCorrectionOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetEthCtrlIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx),
                                                                  (uint8)EthIf_GetEthClkUnitIdxOfEthIfClkUnit(ethIfClkUnitIdx),
                                                                  RateDeviation,
                                                                  Offset);                                              /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId =  ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_SET_PHC_CORRECTION, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_SetPhcCorrection() */

/***********************************************************************************************************************
 *  EthIf_GetPhcTime
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE)  EthIf_GetPhcTime( /* PRQA S 6080 */ /* MD_MSR_STMIF */
        uint8                                         CtrlIdx,
        uint8                                         ClkUnitIdx,
  P2VAR(TimeStampQualType, AUTOMATIC, ETHIF_APPL_VAR) TimeQualPtr,
  P2VAR(TimeStampType, AUTOMATIC, ETHIF_APPL_VAR)     TimeStampPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType  retVal   = E_NOT_OK;
  uint8           errorId  = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if(EthIf_IsEthIfClkUnitUsedOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx)) != TRUE)
  {
    errorId = ETHIF_E_INV_CLKUNIT_IDX;
  }
  else if(ClkUnitIdx >= (EthIf_GetEthIfClkUnitEndIdxOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx)) -
                          EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx))))
  {
    errorId = ETHIF_E_INV_CLKUNIT_IDX;
  }
  else if( TimeQualPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else if( TimeStampPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType ethIfPhysCtrlCfgIdx = EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthIfPhysCtrlCfgType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetGetPhcTimeOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
    {
      EthIf_EthIfClkUnitIterType ethIfClkUnitIdx = (EthIf_EthIfClkUnitIterType)EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx) + ClkUnitIdx;

      /* #300 Redirect call to the driver */
      retVal = EthIf_GetGetPhcTimeOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetEthCtrlIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx),
                                                            (uint8)EthIf_GetEthClkUnitIdxOfEthIfClkUnit(ethIfClkUnitIdx),
                                                                TimeQualPtr,
                                                                TimeStampPtr);                                          /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId =  ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_PHC_TIME, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_GetPhcTime() */

/***********************************************************************************************************************
 *  EthIf_SetPpsSignalMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE)  EthIf_SetPpsSignalMode( /* PRQA S 6080 */ /* MD_MSR_STMIF */
  uint8   CtrlIdx,
  uint8   ClkUnitIdx,
  boolean SignalMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType  retVal   = E_NOT_OK;
  uint8           errorId  = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if(EthIf_IsEthIfClkUnitUsedOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx)) != TRUE)
  {
    errorId = ETHIF_E_INV_CLKUNIT_IDX;
  }
  else if(ClkUnitIdx >= (EthIf_GetEthIfClkUnitEndIdxOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx)) -
                          EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx))))
  {
    errorId = ETHIF_E_INV_CLKUNIT_IDX;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType ethIfPhysCtrlCfgIdx = EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthIfPhysCtrlCfgType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetSetPpsSignalModeOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
    {
      EthIf_EthIfClkUnitIterType ethIfClkUnitIdx = (EthIf_EthIfClkUnitIterType)EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx) + ClkUnitIdx;

      /* #300 Redirect call to the driver */
      retVal = EthIf_GetSetPpsSignalModeOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetEthCtrlIdxOfEthIfPhysCtrlCfg(ethIfPhysCtrlCfgIdx),
                                                                  (uint8)EthIf_GetEthClkUnitIdxOfEthIfClkUnit(ethIfClkUnitIdx),
                                                                  SignalMode);                                          /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId =  ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_SET_PPS_SIGNAL_MODE, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_SetPpsSignalMode() */
#endif /* ETHIF_PHC_SUPPORT */

#if ( ETHIF_ENABLE_HEADER_ACCESS_API == STD_ON )
/***********************************************************************************************************************
 *  EthIf_GetTxHeaderPtr
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetTxHeaderPtr( /* PRQA S 6080 */ /* MD_MSR_STMIF */
        uint8                                                                       CtrlIdx,
        uint8                                                                       BufIdx,
  P2VAR(P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_VAR), AUTOMATIC, ETHIF_APPL_VAR)  BufPtr,
  P2VAR(uint16,                                         AUTOMATIC, ETHIF_APPL_VAR)  LenBytePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType  retVal   = E_NOT_OK;
  uint8           errorId  = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( BufIdx > EthIf_GetMaxTxBufIdxForEthIfCtrl(CtrlIdx) )
  {
    errorId = ETHIF_E_INV_PARAM;
  }
  else if( BufPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else if( LenBytePtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetGetTxHeaderPtrOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
    {
      /* #300 Redirect call to the driver */
      retVal = EthIf_GetGetTxHeaderPtrOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                                BufIdx,
                                                                BufPtr,
                                                                LenBytePtr);                                            /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */

      if( retVal == E_OK )
      {
        /* #310 Check the EthIf controller type (non-tagged or tagged) and consider the
         *      tag length in the resulting buffer length if necessary */
        if( EthIf_GetTypeOfEthIfCtrl(CtrlIdx) != ETHIF_ETHIFCTRL_TYPE_PHYSICAL_TYPEOFETHIFCTRL )
        {
          (*LenBytePtr) += ETHIF_VLAN_TAG_LEN_BYTE;                                                                       /* SBSW_ETHIF_PUB_FCT_PARAM_PTR_WRITE */
        }
      }
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId =  ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_TX_HEADER_PTR, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_GetTxHeaderPtr() */

/***********************************************************************************************************************
 *  EthIf_GetRxHeaderPtr
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetRxHeaderPtr( /* PRQA S 6080 */ /* MD_MSR_STMIF */
        uint8                                                                       CtrlIdx,
  P2VAR(P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_VAR), AUTOMATIC, ETHIF_APPL_VAR)  BufPtr,
  P2VAR(uint16,                                         AUTOMATIC, ETHIF_APPL_VAR)  LenBytePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType  retVal   = E_NOT_OK;
  uint8           errorId  = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( BufPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else if( LenBytePtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetGetRxHeaderPtrOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
    {
      P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR) tagAwareBufPtr;

      tagAwareBufPtr = (P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR))*BufPtr; /* PRQA S 0310 */ /* MD_EthIf_310_Buffer */

      /* #300 Check the EthIf controller type (non-tagged or tagged) and adapt the buffer pointer
       *      to the location the driver expects */
      if( EthIf_GetTypeOfEthIfCtrl(CtrlIdx) != ETHIF_ETHIFCTRL_TYPE_PHYSICAL_TYPEOFETHIFCTRL )
      {
        tagAwareBufPtr = &tagAwareBufPtr[-((sint8)ETHIF_VLAN_TAG_LEN_BYTE)]; /* PRQA S 3382 */ /* MD_EthIf_3382 */
      }

      /* #310 Redirect call to the driver */
      /* PRQA S 0310, 3305 3 */ /* MD_EthIf_310_Buffer, MD_EthIf_3305_Buffer */
      retVal = EthIf_GetGetRxHeaderPtrOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                                (P2VAR(P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_VAR), AUTOMATIC, ETHIF_APPL_VAR))&tagAwareBufPtr,
                                                                LenBytePtr);                                            /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */

      /* #320 Prepare data that shall be passed to the caller so access to Ethernet header is possible */
      /* PRQA S 0310, 3305, 2916 1 */ /* MD_EthIf_310_Buffer, MD_EthIf_3305_Buffer, MD_EthIf_2916 */
      (*BufPtr) = (P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_VAR))tagAwareBufPtr;                                       /* SBSW_ETHIF_PUB_FCT_PARAM_PTR_WRITE */

      if( EthIf_GetTypeOfEthIfCtrl(CtrlIdx) != ETHIF_ETHIFCTRL_TYPE_PHYSICAL_TYPEOFETHIFCTRL )
      {
        (*LenBytePtr) += ETHIF_VLAN_TAG_LEN_BYTE;                                                                       /* SBSW_ETHIF_PUB_FCT_PARAM_PTR_WRITE */
      }
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId = ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_RX_HEADER_PTR, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_GetRxHeaderPtr() */
#endif /* ETHIF_ENABLE_HEADER_ACCESS_API */

#if ( ETHIF_DYNAMIC_TRAFFIC_SHAPING_SUPPORT == STD_ON )
/**********************************************************************************************************************
 * EthIf_SetBandwidthLimit
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetBandwidthLimit(
  uint8   CtrlIdx,
  uint8   QueuePrio,
  uint32  BandwidthLimit)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( QueuePrio > ETHIF_VLAN_PCP_MAX_VAL )
  {
    errorId = ETHIF_E_INV_PARAM;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetSetBandwidthLimitOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
    {
      /* #3000 Redirect call to the driver */
      retVal = EthIf_GetSetBandwidthLimitOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                                    QueuePrio,
                                                                    BandwidthLimit);                                    /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId = ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_SET_BANDWIDTH_LIMIT, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_SetBandwidthLimit() */

/**********************************************************************************************************************
 * EthIf_GetBandwidthLimit
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetBandwidthLimit( /* PRQA S 6080 */ /* MD_MSR_STMIF */
        uint8                               CtrlIdx,
        uint8                               QueuePrio,
  P2VAR(uint32, AUTOMATIC, ETHIF_APPL_VAR)  BandwidthLimitPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHIF_DEV_ERROR_DETECT == STD_ON)                                                                                 /* COV_ETHIF_SAFE_FEAT */
  /* #10 Check module states */
  if( EthIf_ModuleInitialized == ETHIF_STATE_UNINIT )
  {
    errorId = ETHIF_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if( CtrlIdx >= EthIf_GetSizeOfEthIfCtrl() )
  {
    errorId = ETHIF_E_INV_CTRL_IDX;
  }
  else if( QueuePrio > ETHIF_VLAN_PCP_MAX_VAL )
  {
    errorId = ETHIF_E_INV_PARAM;
  }
  else if( BandwidthLimitPtr == NULL_PTR )
  {
    errorId = ETHIF_E_PARAM_POINTER;
  }
  else
# endif /* ETHIF_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    EthIf_EthCtrlIdxOfEthIfCtrlType ethCtrlIdx = EthIf_GetEthCtrlIdxOfEthIfCtrl(CtrlIdx);
    EthIf_EthDrvApiIdxOfEthCtrlType ethDrvApiIdx = EthIf_GetEthDrvApiIdxOfEthCtrl(ethCtrlIdx);

    /* #30 Check if driver provides the API */
    if( EthIf_GetGetBandwidthLimitOfEthDrvApi(ethDrvApiIdx) != NULL_PTR )
    {
      /* #3000 Redirect call to the driver */
      retVal = EthIf_GetGetBandwidthLimitOfEthDrvApi(ethDrvApiIdx)((uint8)EthIf_GetSnvOfEthCtrl(ethCtrlIdx),
                                                                    QueuePrio,
                                                                    BandwidthLimitPtr);                                 /* SBSW_ETHIF_DRVAPI_FCT_PTR_OPT_WITH_PUB_PARAM_PTR_CSL03 */
    }
# if ( ETHIF_DEV_ERROR_DETECT == STD_ON )                                                                               /* COV_ETHIF_SAFE_FEAT */
    else
    {
      errorId = ETHIF_E_INV_DRIVER_API_CALL;
    }
# endif /* ETHIF_DEV_ERROR_DETECT */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ETHIF_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report default errors if any occurred */
  if (errorId != ETHIF_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID_DET, ETHIF_SID_GET_BANDWIDTH_LIMIT, errorId);
  }
# else
  ETHIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* EthIf_GetBandwidthLimit() */

#endif /* ETHIF_DYNAMIC_TRAFFIC_SHAPING_SUPPORT */

#define ETHIF_STOP_SEC_CODE
#include "EthIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: EthIf_EthCtrl.c
 *********************************************************************************************************************/

