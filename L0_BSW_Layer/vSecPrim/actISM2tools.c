/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 1999 - 2016 cv cryptovision GmbH.                                                All rights reserved.
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
/*!        \file  actISM2tools.c
 *         \unit  act_SM2
 *        \brief  Implementation of shared functions for SM2 signature, key generation and key exchange.
 *      \details Currently the actClib version is used.
 *               This file is part of the embedded systems library actCLib
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

#define ACTISM2TOOLS_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "actISM2.h"
#include "actECTools.h"

#if (VSECPRIM_ACTISM2TOOLS_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

# if (VSECPRIM_SM2_SIGNATURE_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */
/***********************************************************************************************************************
 *  actISM2CalculateZA()
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
 *
 *
 *
 *
 *
 *
 *
 */
 /* PRQA S 6010, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STMIF */
VSECPRIM_FUNC(void) actISM2CalculateZA(VSECPRIM_P2VAR_PARA(actSM2STRUCT) sm2,
  VSECPRIM_P2CONST_PARA(actU8) id,
  const actLengthType idLength,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyX,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyY,
  VSECPRIM_P2VAR_PARA(actU8) za,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_P2VAR_PARA(actSM3STRUCT) sm3 = &sm2->sm3;
  /* the cast to actU16 is valid, as the maximum value for length is uint16max, which has been checked before */
  actU16 length = (actU16) idLength;
  actLengthType p_bytes = 0u;
  VSECPRIM_P2CONST_PARA(actU8) a_addr;
  VSECPRIM_P2CONST_PARA(actU8) b_addr;
  VSECPRIM_P2CONST_PARA(actU8) g_addr;

  actSM2ParseDomain(sm2->domain, &p_bytes, &a_addr, &b_addr, &g_addr);

  /* hash user information ZA */
  actSM3Init(sm3);
  actU16toBE(za, length);  /* encode id length */

  (void)actSM3Update(sm3, za, 2u, watchdog);
  if (id != NULL_PTR)
  {
    (void)actSM3Update(sm3, id, (actU16) actBitsToBytes((actU16) (length + (actU16) 7u)), watchdog);
  }
  (void)actSM3Update(sm3, a_addr, p_bytes, watchdog); /* a */
  (void)actSM3Update(sm3, b_addr, p_bytes, watchdog); /* b */
  (void)actSM3Update(sm3, g_addr, 2u * p_bytes, watchdog); /* xG, yG */
  (void)actSM3Update(sm3, publicKeyX, p_bytes, watchdog); /* xA */
  (void)actSM3Update(sm3, publicKeyY, p_bytes, watchdog); /* yA */

  actSM3Finalize(sm3, za, watchdog);
}
# endif /* (VSECPRIM_SM2_SIGNATURE_ENABLED == STD_ON) */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTISM2TOOLS_ENABLED == STD_ON) */
/***********************************************************************************************************************
 *  END OF FILE: actISM2tools.c
 **********************************************************************************************************************/
