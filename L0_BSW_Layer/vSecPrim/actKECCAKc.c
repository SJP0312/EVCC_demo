/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 1999 - 2020 cv cryptovision GmbH.                                                All rights reserved.
 *
 *  For modifications by Vector Informatik GmbH:
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is protected under intellectual property laws and proprietary to cv cryptovision GmbH
 *                and/or Vector Informatik GmbH.
 *                No right or license is granted save as expressly set out in the applicable license conditions.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  actKECCAKc.c
 *        \brief  SHA-3 implementation.
 *
 *      \details Currently the actClib version is used.
 *               This file is part of the embedded systems library cvActLib/ES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to module's header file.
 *********************************************************************************************************************/

#define ACTKECCAKC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "actKECCAKc.h"
#include "actITypes.h"
#include "actUtilities.h"
#include "actWatchdog.h"

#if (VSECPRIM_ACTKECCAK_ENABLED == STD_ON)

# ifdef ACT_PLATFORM_UINT64_AVAILABLE
#  include "actKECCAKf-64.h"
# else
#  include "actKECCAKf-32.h"
# endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  actKECCAKcInit()
 *********************************************************************************************************************/
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
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actKECCAKcInit(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  const actU32 strength,
  const actU8  pad1)
{
  actRETURNCODE retVal;

  /*  ensure capacity is a multiple of actHASH_SHA3_LANE size  */
  if (((2u * strength) % actHASH_SHA3_LANE) == 0u)
  {
    /* defines whether to use SHA3-224, SHA3-256, SHA3-384 or SHA3-512 */
    info->strength = strength;  /* SBSW_VSECPRIM_WRITE_POINTER */
    info->rate     = (actHASH_SHA3_WIDTH - (2u * strength)) /actHASH_SHA3_LANE; /* SBSW_VSECPRIM_WRITE_POINTER */
    info->pad1     = pad1; /* SBSW_VSECPRIM_WRITE_POINTER */

    /* set last 4 bit of phase to zero */
    info->phase = (actU8)(info->phase & (~KECCAKc_PHASE)); /* SBSW_VSECPRIM_WRITE_POINTER */
    /* set last bit of phase to one */
    info->phase   |=  KECCAKc_PHASE_INITIAL; /* SBSW_VSECPRIM_WRITE_POINTER */
    info->rUsed    = 0u; /* SBSW_VSECPRIM_WRITE_POINTER */
    info->dUsed    = 0u; /* SBSW_VSECPRIM_WRITE_POINTER */
    actMemClear(info->state, actBitsToBytes(actHASH_SHA3_WIDTH)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SIZE */
    actMemClear(info->data, actBitsToBytes(actHASH_SHA3_LANE)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SIZE */

    retVal = actOK;
  }
  else
  {
    retVal = actEXCEPTION_LENGTH;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  actKECCAKcAbsorb()
 *********************************************************************************************************************/
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
VSECPRIM_FUNC(actRETURNCODE) actKECCAKcAbsorb(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) data,
  const actLengthType dataLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal;
  actLengthType size_remaining, size_used;
  actLengthType n;

  if ((info->phase & KECCAKc_PHASE) != KECCAKc_PHASE_SQUEEZE)
  {
    size_remaining = dataLength;
    size_used = 0u;

    while(size_remaining > 0u) /* FETA_VSECPRIM_ACTKECCACKF_ABSORB_SQUEEZE_WHILE_LOOP */
    {
      /* Used in a multi-update usecase */
      if (info->dUsed != 0u)
      {
        /*  fill buffer  */

        n = actMin ((actHASH_SHA3_LANE /8u) - info->dUsed, size_remaining);
        actMemCpyByteArray (&(info->data [info->dUsed]), &data[size_used], n); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
        info->dUsed += n; /* SBSW_VSECPRIM_WRITE_POINTER */
        size_used += n;
        size_remaining -= n;

        if (info->dUsed >= (actHASH_SHA3_LANE /8u))
        {
          /*  absorb actHASH_SHA3_LANE from filled buffer  */
          actKECCAKcAbsorbData(info, info->data); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_AND_P2CONSTPARAM */
          info->rUsed++; /* SBSW_VSECPRIM_WRITE_POINTER */
          info->dUsed = 0u; /* SBSW_VSECPRIM_WRITE_POINTER */
        }
      }
      else if (size_remaining >= (actHASH_SHA3_LANE /8u))
      {
        /*  absorb entire actHASH_SHA3_LANE from data  into state */
        actKECCAKcAbsorbData(info, &data[size_used]); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_AND_P2CONSTPARAM */
        info->rUsed++; /* SBSW_VSECPRIM_WRITE_POINTER */
        size_used += (actHASH_SHA3_LANE / 8u);
        size_remaining -= (actHASH_SHA3_LANE /8u);
      }
      else
      {
        /*  save remaining data in buffer  */
        actMemCpyByteArray (info->data, &data[size_used], size_remaining); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
        info->dUsed = size_remaining; /* SBSW_VSECPRIM_WRITE_POINTER */
        size_used += size_remaining;
        size_remaining -= size_remaining;
      }

      if (info->rUsed >= info->rate)
      {
        /*  "rate" bits absorbed - update state */
        actKECCAKf (info, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
        info->rUsed = 0u; /* SBSW_VSECPRIM_WRITE_POINTER */
      }
    }

    info->phase = (actU8)(info->phase & (~KECCAKc_PHASE)); /* SBSW_VSECPRIM_WRITE_POINTER */
    info->phase |=  KECCAKc_PHASE_ABSORB; /* SBSW_VSECPRIM_WRITE_POINTER */

    retVal = actOK;
  }
  else
  {
    retVal = actEXCEPTION_MODE;
  }

  actL1trigger (watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  return retVal;
}

/**********************************************************************************************************************
 *  actKECCAKcSqueeze()
 *********************************************************************************************************************/
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
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actKECCAKcSqueeze(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) digest,
  const actLengthType digestSize,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal;
  actLengthType size_remaining, size_used, n;

  /*  ensure digestSize is a multiple of 8 (bytes)  */
  if ((digestSize % 8u) == 0u)
  {

    /*  PAD data and finalize actKECCAKf  */
    if ((info->phase & KECCAKc_PHASE) == KECCAKc_PHASE_ABSORB)
    {
      /*  PAD1  */
      actMemClear(&(info->data[info->dUsed]), ((actHASH_SHA3_LANE / 8u) - info->dUsed));  /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
      info->data[info->dUsed] ^= info->pad1; /* SBSW_VSECPRIM_PTR_WRITE_ACCESS_PASSED_BUFFER */
      actKECCAKcAbsorbData(info, info->data); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_AND_P2CONSTPARAM */

      /*  PAD2  */
      actMemClear(info->data, actBitsToBytes(actHASH_SHA3_LANE)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SIZE */
      /* The ABSORB macro assumes little endian data arrays, thus the last entry of info->data is set to PAD_2. */
      info->data[actBitsToBytes(actHASH_SHA3_LANE) - 1u] = actHASH_SHA3_PAD_2; /* SBSW_VSECPRIM_ARRAY_WRITE_ACCESS_PASSED_BUFFER_FIXED_INDEX */
      info->rUsed = info->rate - 1u; /* SBSW_VSECPRIM_WRITE_POINTER */
      actKECCAKcAbsorbData(info, info->data); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_AND_P2CONSTPARAM */

      actKECCAKf (info, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */

      /* set last 4 bit of phase to zero */
      info->phase = (actU8)(info->phase & (~KECCAKc_PHASE)); /* SBSW_VSECPRIM_WRITE_POINTER */
      /* set last bit of phase to three */
      info->phase |=  KECCAKc_PHASE_SQUEEZE; /* SBSW_VSECPRIM_WRITE_POINTER */
      info->rUsed = 0u;                /*  NOTHING exported yet  */ /* SBSW_VSECPRIM_WRITE_POINTER */
      info->dUsed = 0u;                /*  NOTHING exported yet  */ /* SBSW_VSECPRIM_WRITE_POINTER */
    }

    /*  export digest  */
    size_remaining = (digestSize / 8u);
    size_used = 0u;

    while (size_remaining > 0u) /* FETA_VSECPRIM_ACTKECCACKF_ABSORB_SQUEEZE_WHILE_LOOP */
    {
      /* apply actKECCAKf() another time to info->state to squeeze more data out of it */
      if (info->rUsed >= info->rate)
      {
        actKECCAKf (info, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
        info->rUsed = 0u;            /*  NOTHING exported yet  */ /* SBSW_VSECPRIM_WRITE_POINTER */
      }

      if (info->dUsed != 0u)
      {
        /*  return digest from buffer  */
        n = actMin ((actHASH_SHA3_LANE /8u) - info->dUsed, size_remaining);
        actMemCpyByteArray (&digest[size_used], &(info->data [info->dUsed]), n); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
        info->dUsed += n; /* SBSW_VSECPRIM_WRITE_POINTER */
        info->dUsed %= 8u; /* SBSW_VSECPRIM_WRITE_POINTER */
        size_used += n;
        size_remaining -= n;
      }
      else if (size_remaining >= (actHASH_SHA3_LANE /8u))
      {
        /*  return entire actHASH_SHA3_LANE from state  */
        actKECCAKcSqueezeData(info, &digest[size_used]); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_AND_P2CONSTPARAM */
        info->rUsed++; /* SBSW_VSECPRIM_WRITE_POINTER */
        size_used += (actHASH_SHA3_LANE / 8u);
        size_remaining -= (actHASH_SHA3_LANE/8u);
      }
      else /* used for SHAKE */
      {
        /*  return partial actHASH_SHA3_LANE via buffer  */
        actKECCAKcSqueezeData(info, info->data); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
        info->rUsed++; /* SBSW_VSECPRIM_WRITE_POINTER */

        actMemCpyByteArray  (&digest[size_used], info->data, size_remaining); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
        info->dUsed = size_remaining; /* SBSW_VSECPRIM_WRITE_POINTER */
        size_used += size_remaining;
        size_remaining -= size_remaining;
      }
    }

    retVal = actOK;
  }
  else
  {
    retVal = actEXCEPTION_LENGTH;
  }

  actL1trigger (watchdog);  /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VSECPRIM_ACTKECCAK_ENABLED == STD_ON */
/**********************************************************************************************************************
 *  END OF FILE: actKECCAKc.c
 *********************************************************************************************************************/
