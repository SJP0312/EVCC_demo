/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*      \file  Crypto_30_LibCv_Mac.c
 *      \brief  MICROSAR Crypto Driver (Crypto)
 *
 *      \details  Implementation for MAC Services
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_LIBCV_MAC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_LibCv.h"
#include "Crypto_30_LibCv_Services.h"
#include "Crypto_30_LibCv_MacGenerate.h"
#include "Crypto_30_LibCv_MacVerify.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL_CONSTANT MACROS
 *********************************************************************************************************************/
#define CRYPTO_30_LIBCV_MODULO_8(x)                                   ((x) & (8u - 1u))
#define CRYPTO_30_LIBCV_SIP_HASH_KEY_LENGTH                           (16u)
#define CRYPTO_30_LIBCV_SIPHASH_MAC_SIZE                              (8u)
#define CRYPTO_30_LIBCV_SHA2_256_KEY_LENGTH                           (32u)
#define CRYPTO_30_LIBCV_GMAC_MAX_OUT_TAG_SIZE                         (16u)

#define CRYPTO_30_LIBCV_CMAC_AES_MODE_128                             (0u)
#define CRYPTO_30_LIBCV_CMAC_AES_MODE_256                             (1u)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_LIBCV_START_SEC_CODE
#include "Crypto_30_LibCv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_LIBCV_SERVICE_MAC_VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_CompareMac()
 *********************************************************************************************************************/
/*! \brief          Compares two MACs
 *  \details        This function compares two MAC values from MSB to LSB.
 *  \param[in]      mac1                  Holds a pointer to the first mac
 *  \param[in]      mac2                  Holds a pointer to the second mac
 *  \param[in]      lengthInBit           Number of bits which shall be compared from MSB to LSB.
 *  \return         CRYPTO_E_VER_NOT_OK   Macs are not similar
 *                  CRYPTO_E_VER_OK       Macs are similar
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Crypto_VerifyResultType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_CompareMac(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) mac1,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) mac2,
  uint32 lengthInBit);
#endif /* (CRYPTO_30_LIBCV_SERVICE_MAC_VERIFY == STD_ON) */

#if ((CRYPTO_30_LIBCV_CMACAESVERIFY == STD_ON) || (CRYPTO_30_LIBCV_CMACAESGENERATE == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAes_Init_CalculateKey()
 *********************************************************************************************************************/
/*! \brief          Initializes the CMAC AES algorithm including calculate the round keys.
 *  \details        Depending on the AES key size, 128bit or 256bit AES CMAC is initialized.
 *  \param[in]      job                Pointer to the job which shall be dispatched.
 *  \param[in,out]  workspace          Pointer to the esl workspace.
 *  \param[in]      sheService         Holds the service for SHE key usage.
 *  \return         E_OK               Init was successful.
 *                  E_NOT_OK           Init failed.
 *                  CRYPTO_E_KEY_NOT_VALID      Request failed, the key is not valid.
 *                  CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the provided key has no proper size.
 *  \pre            workspace has to be valid.
 *                  job has to be a valid job object handle.
 *                  sheService hast be be a valid SHE service.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAes_Init_CalculateKey(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace,
  Crypto_30_LibCv_ServiceType sheService);

# if (CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAes_Init_ReuseKey()
 *********************************************************************************************************************/
/*! \brief          Initializes the CMAC AES algorithm by reusing the round keys.
 *  \details        Call esl_initExpandedCMACAES128/256 with NULL_PTR and length=0 as expanded key and key length so
 *                  that vSecPrim reuses the previously generated expanded key.
 *  \param[in,out]  workspace          Pointer to the esl workspace.
 *  \return         E_OK               Init was successful.
 *                  E_NOT_OK           Init failed.
 *  \pre            workspace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAes_Init_ReuseKey(
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace);
# endif /* (CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE == STD_ON) */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAes_Start()
 *********************************************************************************************************************/
/*! \brief          Handles operation mode START.
 *  \details        If round key reuse is activated, the function checks if the round keys need to be recalculated or
 *                  or can be reused and initializes the CMAC AES. If not, it just initializes the AES CMAC algorithm.
 *  \param[in]      objectId           Holds the identifier of the Crypto Driver Object.
 *  \param[in,out]  workspace          Pointer to the esl workspace.
 *  \param[in]      job                Pointer to the job which shall be dispatched.
 *  \param[in]      sheService         Holds the service for SHE key usage.
 *  \return         E_OK               Init was successful.
 *                  E_NOT_OK           Init failed.
 *                  CRYPTO_E_KEY_NOT_VALID      Request failed, the key is not valid.
 *                  CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the provided key has no proper size.
 *  \pre            workspace has to be valid.
 *                  objectId has to be a valid driver object handle.
 *                  job has to be a valid job object handle.
 *                  sheService hast be be a valid SHE service.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAes_Start(
  uint32 objectId,
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_30_LibCv_ServiceType sheService);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAes_Update()
 *********************************************************************************************************************/
/*! \brief          Handles operation mode UPDATE.
 *  \details        Forwards the plain text data to the underlying crypto library.
 *  \param[in,out]  workspace          Pointer to the esl workspace.
 *  \param[in]      job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Request was successful.
 *                  E_NOT_OK           Request failed.
 *  \pre            workspace has to be valid.
 *                  job has to be a valid job object handle.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAes_Update(
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAes_CalcFullMac()
 *********************************************************************************************************************/
/*! \brief          Calculates the full-sized AES CMAC.
 *  \details        Calls the suitable function of the underlaying crypto library based on round key reuse and AES mode.
 *                  Checks if the calculated MAC has a proper size of CRYPTO_30_LIBCV_CMACAES_MAC_SIZE (16 bytes).
 *  \param[in,out]  workspace          Pointer to the esl workspace.
 *  \param[in,out]  macBuffer          Pointer to a buffer where the AES CMAC shall be stored.
 *  \param[in,out]  macLength          Pointer to a length variable providing the length of the macBuffer.
 *  \return         E_OK               Request was successful.
 *                  E_NOT_OK           Request failed.
 *  \pre            workspace has to be valid.
 *                  macBuffer has to be a valid buffer with a length of CRYPTO_30_LIBCV_CMACAES_MAC_SIZE (16 bytes).
 *                  macLength hat to be a valid pointer providing the length of macBuffer.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAes_CalcFullMac(
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) macBuffer,
  P2VAR(eslt_Length, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) macLength);
#endif /* ((CRYPTO_30_LIBCV_CMACAESVERIFY == STD_ON) || (CRYPTO_30_LIBCV_CMACAESGENERATE == STD_ON)) */

#if (CRYPTO_30_LIBCV_HMACSHA1GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA1VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA1ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in]      job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *                  job has to be a job object handle.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA1ModeStart(
  P2VAR(eslt_WorkSpaceHMACSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA1ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA1ModeUpdate(
  P2VAR(eslt_WorkSpaceHMACSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA1GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA1VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA1GENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA1GenerateModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the tag value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA1GenerateModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA1GENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA256GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA256VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA256ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in]      job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *                  job has to be a job object handle.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA256ModeStart(
  P2VAR(eslt_WorkSpaceHMACSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA256ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA256ModeUpdate(
  P2VAR(eslt_WorkSpaceHMACSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA256GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA256VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA256GENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA256GenerateModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the tag value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA256GenerateModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA256GENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA384GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA384VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA384ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in]      job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *                  job has to be a job object handle.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA384ModeStart(
  P2VAR(eslt_WorkSpaceHMACSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA384ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA384ModeUpdate(
  P2VAR(eslt_WorkSpaceHMACSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA384GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA384VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA384GENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA384GenerateModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the tag value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA384GenerateModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA384GENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA512GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA512VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA512ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in]      job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *                  job has to be a job object handle.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA512ModeStart(
  P2VAR(eslt_WorkSpaceHMACSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA512ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA512ModeUpdate(
  P2VAR(eslt_WorkSpaceHMACSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA512GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA512VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA512GENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA512GenerateModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the tag value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA512GenerateModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA512GENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA1VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA1VerifyModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers and checks if verification was successful.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA1VerifyModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA1VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA256VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA256VerifyModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers and checks if verification was successful.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA256VerifyModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA256VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA384VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA384VerifyModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers and checks if verification was successful.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA384VerifyModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA384VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA512VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA512VerifyModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers and checks if verification was successful.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA512VerifyModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACSHA512VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_GMACAESGENERATE == STD_ON) || (CRYPTO_30_LIBCV_GMACAESVERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchGmacAesModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in]      job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *                  job has to be a job object handle.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchGmacAesModeStart(
  P2VAR(eslt_WorkSpaceGMAC, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchGmacAesModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchGmacAesModeUpdate(
  P2VAR(eslt_WorkSpaceGMAC, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_GMACAESGENERATE == STD_ON) || (CRYPTO_30_LIBCV_GMACAESVERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_GMACAESGENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchGmacAesGenerateModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the tag value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchGmacAesGenerateModeFinish(
  P2VAR(eslt_WorkSpaceGMAC, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_GMACAESGENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_GMACAESVERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchGmacAesVerifyModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers and checks if verification was successful.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchGmacAesVerifyModeFinish(
  P2VAR(eslt_WorkSpaceGMAC, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_GMACAESVERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACRIPEMD160GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACRIPEMD160VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacRipeMd160ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in]      job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *                  job has to be a job object handle.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacRipeMd160ModeStart(
  P2VAR(eslt_WorkSpaceHMACRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacRipeMd160ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacRipeMd160ModeUpdate(
  P2VAR(eslt_WorkSpaceHMACRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACRIPEMD160GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACRIPEMD160VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACRIPEMD160GENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacRipeMd160GenerateModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the tag value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacRipeMd160GenerateModeFinish(
  P2VAR(eslt_WorkSpaceHMACRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACRIPEMD160GENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACRIPEMD160VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacRipeMd160VerifyModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers and checks if verification was successful.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacRipeMd160VerifyModeFinish(
  P2VAR(eslt_WorkSpaceHMACRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_HMACRIPEMD160VERIFY == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (CRYPTO_30_LIBCV_SERVICE_MAC_VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_CompareMac()
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
CRYPTO_30_LIBCV_LOCAL FUNC(Crypto_VerifyResultType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_CompareMac(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) mac1,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) mac2,
  uint32 lengthInBit)
{
  Crypto_VerifyResultType result = CRYPTO_E_VER_OK;
  const uint32 numberOfFullBytesInMac = Crypto_30_LibCv_Bit2Byte(lengthInBit);
  uint32 numberBitsInLastByte;
  uint8 verifyBitMask;

  uint32 i = 0u;

  /* # Compare full bytes of both MACs. */
  /* # No use of VStdLib_MemCmp, so that the for-loop steps through all bytes in order to achieve a constant function runtime (security measure). */
  for (i = 0u; i < (numberOfFullBytesInMac); i++) /* FETA_CRYPTO_30_LIBCV_MONOTONIC_LOOP_UP_WITH_PARAMETER_DEPENDENT_UPPER_BOUND */
  {
    if (mac1[i] != mac2[i])
    {
      /* Verification does not match */
      result = CRYPTO_E_VER_NOT_OK;
    }
  }

  /* # Compare remaining bits. */
  /* Compute number of bits to verify in the last byte */
  numberBitsInLastByte = CRYPTO_30_LIBCV_MODULO_8(lengthInBit);  /* Calculate modulo */
  if (numberBitsInLastByte != 0u)
  {
    /* Generate bitmask which contains all bits to be verified */
    verifyBitMask = (uint8)~((1u << (8u - numberBitsInLastByte)) - 1u);

    /* Verify the last masked byte */
    if ((mac1[numberOfFullBytesInMac] & verifyBitMask)
        != (mac2[numberOfFullBytesInMac] & verifyBitMask))
    {
      result = CRYPTO_E_VER_NOT_OK;
    }
  }

  return result;
} /* Crypto_30_LibCv_CompareMac() */
#endif /* (CRYPTO_30_LIBCV_SERVICE_MAC_VERIFY == STD_ON) */

#if ((CRYPTO_30_LIBCV_CMACAESVERIFY == STD_ON) || (CRYPTO_30_LIBCV_CMACAESGENERATE == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAes_Init_CalculateKey()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAes_Init_CalculateKey(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace,
  Crypto_30_LibCv_ServiceType sheService)
{
  uint32 cmacAesKeyLength;
  Crypto_30_LibCv_SizeOfKeyStorageType cmacAesKeyIndex;

  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* Get MAC key */
  Std_ReturnType localRetVal = Crypto_30_LibCv_Local_KeyElementGetStorageIndexExtended(job->cryptoKeyId, CRYPTO_KE_MAC_KEY,
                                                                                       &cmacAesKeyIndex, &cmacAesKeyLength,
                                                                                       CRYPTO_30_LIBCV_LENGTH_CHECK_NONE, sheService); /* SBSW_CRYPTO_30_LIBCV_STACK_VARIABLE_AS_PTR */

  if (localRetVal == E_OK)
  {
    /* Initialize workspace header. */
    retValCv = esl_initWorkSpaceHeader(&(workspace->wsCMACAES.header), ESL_MAXSIZEOF_WS_CMACAES, CRYPTO_30_LIBCV_WATCHDOG_PTR); /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */

    if (retValCv == ESL_ERC_NO_ERROR)
    {
      /* Distinguish AES CMAC mode based on AES key size. */
      switch (cmacAesKeyLength)
      {
        case CRYPTO_30_LIBCV_CMACAES128_KEY_SIZE:
        {
          /* Init CMAC AES128 */
          workspace->mode = CRYPTO_30_LIBCV_CMAC_AES_MODE_128; /* SBSW_CRYPTO_30_LIBCV_WORKSPACE_MEMBER_ACCESS */
          retValCv = esl_initCMACAES128(
            &workspace->wsCMACAES, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER */
            (eslt_Length)cmacAesKeyLength,
            (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(cmacAesKeyIndex));
          break;
        }
        case CRYPTO_30_LIBCV_CMACAES256_KEY_SIZE:
        {
          /* Init CMAC AES256 */
          workspace->mode = CRYPTO_30_LIBCV_CMAC_AES_MODE_256; /* SBSW_CRYPTO_30_LIBCV_WORKSPACE_MEMBER_ACCESS */
          retValCv = esl_initCMACAES256(
            &workspace->wsCMACAES, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER */
            (eslt_Length)cmacAesKeyLength,
            (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(cmacAesKeyIndex));
          break;
        }
        default:
        {
          /* MAC key has no proper size. */
          retVal = CRYPTO_E_KEY_SIZE_MISMATCH;
          retValCv = ESL_ERC_ERROR;
          break;
        }
      }

      if (retValCv == ESL_ERC_NO_ERROR)
      {
        retVal = E_OK;
      }
    }
  }
  else if (localRetVal == CRYPTO_E_KEY_NOT_VALID)
  {
    retVal = CRYPTO_E_KEY_NOT_VALID;
  }
  else
  {
    /* retVal remains on E_NOT_OK */
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_CmacAes_Init_CalculateKey() */

# if (CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAes_Init_ReuseKey()
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
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAes_Init_ReuseKey(
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace)
{
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* Get the AES CMAC mode from the workspace mode which was written in the previous AES CMAC round. */
  switch (workspace->mode)
  {
    case CRYPTO_30_LIBCV_CMAC_AES_MODE_128:
    {
      retValCv = esl_initExpandedCMACAES128(&workspace->wsCMACAES, NULL_PTR, (eslt_Length) 0u); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_NULL_PTR */
      break;
    }
    case CRYPTO_30_LIBCV_CMAC_AES_MODE_256:
    {
      retValCv = esl_initExpandedCMACAES256(&workspace->wsCMACAES, NULL_PTR, (eslt_Length) 0u); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_NULL_PTR */
      break;
    }
    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported mode. */
      /* retValCv remains error. */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_CmacAes_Init_ReuseKey() */
# endif /* (CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE == STD_ON) */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAes_Start()
 *********************************************************************************************************************/
/*!
 *
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
/* PRQA S 6080, 6030 5 */ /* MD_MSR_STMIF, MD_MSR_STCYC */
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAes_Start(
  uint32 objectId,
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_30_LibCv_ServiceType sheService)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Load key element from storage and initialize algorithm with keys. Dependent on roundkey feature, either the roundkey is loaded as key or the original key. */
# if (CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE== STD_ON)
  Crypto_30_LibCv_SizeOfKeyElementsType macElementId = 0u;
  boolean reCalculate = FALSE;

  Std_ReturnType localRetVal = Crypto_30_LibCv_Local_KeyElementSearch(job->cryptoKeyId, CRYPTO_KE_MAC_KEY, &macElementId); /* SBSW_CRYPTO_30_LIBCV_STACK_VARIABLE_AS_PTR */

  /* Check if MAC key has changed */
  if ((localRetVal != E_OK) || (!Crypto_30_LibCv_IsKeyElementStateByMask(macElementId, CRYPTO_30_LIBCV_KEYELEMENTSTATE_VALUE_USED_MASK)))
  {
    reCalculate = TRUE;
  }
  /* Check if job is last job / workspace has changed */
  if (Crypto_30_LibCv_ObjectWorkspaceHasChanged(objectId, job) == TRUE) /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_JOB_PTR */
  {
    reCalculate = TRUE;
  }

  if (reCalculate == TRUE)
# endif
  {
    retVal = Crypto_30_LibCv_Dispatch_CmacAes_Init_CalculateKey(job, workspace, sheService); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */

# if (CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE == STD_ON)
    /* Set flag that roundkeys are calculated */
    if (retVal == E_OK)
    {
      Crypto_30_LibCv_SetKeyElementStateByMask(macElementId, CRYPTO_30_LIBCV_KEYELEMENTSTATE_VALUE_USED_MASK); /* SBSW_CRYPTO_30_LIBCV_CSL02_KEY_STORAGE_VIA_KEY_ELEMENT */
    }
  }
  else
  {
    retVal = Crypto_30_LibCv_Dispatch_CmacAes_Init_ReuseKey(workspace); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_PTR_OF_WORKSPACE */

# else /* !(CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE== STD_ON) */
    CRYPTO_30_LIBCV_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
# endif
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_CmacAes_Start() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAes_Update()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAes_Update(
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* Distinguish between 128bit or 256bit based on workspace mode. */
  switch(workspace->mode)
  {
    case CRYPTO_30_LIBCV_CMAC_AES_MODE_128:
    {
      retValCv = esl_updateCMACAES128(&workspace->wsCMACAES, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
        (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
        (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);
      break;
    }

    case CRYPTO_30_LIBCV_CMAC_AES_MODE_256:
    {
      retValCv = esl_updateCMACAES256(&workspace->wsCMACAES, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
        (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
        (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);
      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported mode. */
      /* retValCv remains error. */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_CmacAes_Update() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAes_CalcFullMac()
 **********************************************************************************************************************/
/*!
 *
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
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAes_CalcFullMac(
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) macBuffer,
  P2VAR(eslt_Length, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) macLength)
{
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  switch (workspace->mode)
  {
# if (CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE == STD_ON)
    case CRYPTO_30_LIBCV_CMAC_AES_MODE_128:
    {
      retValCv = esl_finalizeKeepStateCMACAES128(&workspace->wsCMACAES,
                                                 (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))macBuffer,
                                                 macLength); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_PARAMETER_BUFFER */
      break;
    }
    case CRYPTO_30_LIBCV_CMAC_AES_MODE_256:
    {
      retValCv = esl_finalizeKeepStateCMACAES256(&workspace->wsCMACAES,
                                                 (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))macBuffer,
                                                 macLength); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_PARAMETER_BUFFER */
      break;
    }
# else /* !(CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE == STD_ON) */
    case CRYPTO_30_LIBCV_CMAC_AES_MODE_128:
    {
      retValCv = esl_finalizeCMACAES128(&workspace->wsCMACAES,
                                        (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))macBuffer); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
      break;
    }
    case CRYPTO_30_LIBCV_CMAC_AES_MODE_256:
    {
      retValCv = esl_finalizeCMACAES256(&workspace->wsCMACAES,
                                        (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))macBuffer,
                                        macLength); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_PARAMETER_BUFFER */

      break;
    }
# endif /* !(CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE == STD_ON) */

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported mode. */
      /* retValCv remains error. */
      break;
    }
  }

  /* Check if MAC was fully generated */
  if ((retValCv == ESL_ERC_NO_ERROR) && (*macLength == CRYPTO_30_LIBCV_CMACAES_MAC_SIZE))
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_CmacAes_CalcFullMac() */
#endif /* ((CRYPTO_30_LIBCV_CMACAESVERIFY == STD_ON) || (CRYPTO_30_LIBCV_CMACAESGENERATE == STD_ON)) */

#if (CRYPTO_30_LIBCV_CMACAESGENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAesGenerate()
 **********************************************************************************************************************/
/*!
 *
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
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAesGenerate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job, /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_1 */
  Crypto_OperationModeType mode)
{
  Std_ReturnType retVal = E_NOT_OK;

  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfCmacAesGenerate(Crypto_30_LibCv_GetCmacAesGenerateIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(Crypto_30_LibCv_WorkSpaceCMACAES)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* Distinguish modes. */
  switch (mode)
  {
    /* Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      /* Init CMAC AES. */
      retVal = Crypto_30_LibCv_Dispatch_CmacAes_Start(objectId, workspace, job, CRYPTO_30_LIBCV_SHE_SERVICE_MAC_GENERATE); /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */ /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_JOB_PTR */
      break;
    }

    /* Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
      {
      /* Process plaintext data. */
      retVal = Crypto_30_LibCv_Dispatch_CmacAes_Update(workspace, job); /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */ /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_JOB_PTR */
      break;
    }

    /* Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      /* Create local buffer to store the full MAC */
      uint8 macBuffer[CRYPTO_30_LIBCV_CMACAES_MAC_SIZE];
      eslt_Length macLength = CRYPTO_30_LIBCV_CMACAES_MAC_SIZE;

      /* Calculate full MAC (16 bytes) */
      if(Crypto_30_LibCv_Dispatch_CmacAes_CalcFullMac(workspace, macBuffer, &macLength) == E_OK) /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */ /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_ACCESS_WITH_SIZE */
      {
        /* Get local job output ptrs to shorten the variable names */
        P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) outputPtr = job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr;
        P2VAR(uint32, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) outputLengthPtr = job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr;

        /* Limit job output length to default AES CMAC size (16 bytes). */
        if (*outputLengthPtr > CRYPTO_30_LIBCV_CMACAES_MAC_SIZE)
        {
          *outputLengthPtr = CRYPTO_30_LIBCV_CMACAES_MAC_SIZE; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
        }

        /* Copy calculated MAC into output buffer with given outputLengthPtr (truncation possible). */
        Crypto_30_LibCv_CopyData(outputPtr, macBuffer, *outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

        retVal = E_OK;
      }
      break;
    }

    default: /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_CmacAesGenerate() */
#endif /* (CRYPTO_30_LIBCV_CMACAESGENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_CMACAESVERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_CmacAesVerify()
 **********************************************************************************************************************/
/*!
 *
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
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_CmacAesVerify(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job, /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_1 */
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfCmacAesVerify(Crypto_30_LibCv_GetCmacAesVerifyIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(Crypto_30_LibCv_WorkSpaceCMACAES)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      /* Init CMAC AES. */
      retVal = Crypto_30_LibCv_Dispatch_CmacAes_Start(objectId, workspace, job, CRYPTO_30_LIBCV_SHE_SERVICE_MAC_VERIFY); /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */ /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_JOB_PTR */
      break;
    }

    /* Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      /* Process plaintext data. */
      retVal = Crypto_30_LibCv_Dispatch_CmacAes_Update(workspace, job); /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */ /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      /* Create local buffer to store the full MAC */
      uint8 macBuffer[CRYPTO_30_LIBCV_CMACAES_MAC_SIZE];
      eslt_Length macLength = CRYPTO_30_LIBCV_CMACAES_MAC_SIZE;

      /* Check if input length is not to large. */
      /* Size is given in bits. */
      if (job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength <= (Crypto_30_LibCv_Byte2Bit(CRYPTO_30_LIBCV_CMACAES_MAC_SIZE)))
      {
        /* Calculate full MAC (16 bytes) */
        if (Crypto_30_LibCv_Dispatch_CmacAes_CalcFullMac(workspace, macBuffer, &macLength) == E_OK) /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */ /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_ACCESS_WITH_SIZE */
        {
          macLength = (eslt_Length) job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength;

          /* Verify the input MAC by comparing it with the calculated MAC. */
          /* Only the given length is compared to enable truncation. */
          *(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.verifyPtr) = /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
            Crypto_30_LibCv_CompareMac(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputPtr, macBuffer, (uint32) macLength); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_STACK_BUFFER_AND_PARAMETER_BUFFER */

          retVal = E_OK;
        }
      }
      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_CmacAesVerify() */
#endif /* (CRYPTO_30_LIBCV_CMACAESVERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_SIPHASHGENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_SipHashGenerate()
 **********************************************************************************************************************/
/*!
 *
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
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_SipHashGenerate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job, /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_1 */
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceSipHash, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfSipHashGenerate(Crypto_30_LibCv_GetSipHashGenerateIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceSipHash)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      Crypto_30_LibCv_KeyElementGetType keyElements[1];

      Crypto_30_LibCv_Local_ElementGetterSetId(keyElements, 0u, CRYPTO_KE_MAC_KEY); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */

      /* # Initialize workspace header. */
      if (esl_initWorkSpaceHeader(&(workspace->header), ESL_MAXSIZEOF_WS_SIPHASH, CRYPTO_30_LIBCV_WATCHDOG_PTR) == ESL_ERC_NO_ERROR) /* PRQA S 3395 */ /* MD_CRYPTO_30_LIBCV_3395 */ /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */
      {
        /* Check if key element is accessible */
        /* # Read key elements. */
        retVal = Crypto_30_LibCv_Local_GetElementsIndexJob(job->cryptoKeyId, keyElements, 1u, CRYPTO_30_LIBCV_LENGTH_CHECK_NONE); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */

        if (retVal == E_OK)
        {
          /* # Initialize algorithm. */
          retVal = E_NOT_OK;
          retValCv = esl_initSipHash(workspace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER */
                                     (eslt_Length)keyElements[0u].keyElementLength,
                                     (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(keyElements[0u].keyElementIndex));
        }
      }
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {

      /* # Process plaintext data */
      retValCv = esl_updateSipHash(workspace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
                                   (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
                                   (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

      break;
    }
    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      eslt_Byte macBuffer[CRYPTO_30_LIBCV_SIPHASH_MAC_SIZE];

      retValCv = esl_finalizeSipHash(workspace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))macBuffer); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
      if (retValCv == ESL_ERC_NO_ERROR)
      {
        /* # Adapt output size. */
        if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > CRYPTO_30_LIBCV_SIPHASH_MAC_SIZE)
        {
          *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = CRYPTO_30_LIBCV_SIPHASH_MAC_SIZE; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
        }

        /* # Write results in output buffers. */
        Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, macBuffer, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
      }

      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_SipHashGenerate() */
#endif /* (CRYPTO_30_LIBCV_SIPHASHGENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_SIPHASHVERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_SipHashVerify()
 **********************************************************************************************************************/
/*!
 *
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
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_SipHashVerify(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job, /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_1 */
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceSipHash, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfSipHashVerify(Crypto_30_LibCv_GetSipHashVerifyIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceSipHash)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      Crypto_30_LibCv_KeyElementGetType keyElements[1];

      Crypto_30_LibCv_Local_ElementGetterSetId(keyElements, 0u, CRYPTO_KE_MAC_KEY); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */

      /* # Initialize workspace header. */
      if (esl_initWorkSpaceHeader(&(workspace->header), ESL_MAXSIZEOF_WS_SIPHASH, CRYPTO_30_LIBCV_WATCHDOG_PTR) == ESL_ERC_NO_ERROR) /* PRQA S 3395 */ /* MD_CRYPTO_30_LIBCV_3395 */ /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */
      {
        /* Check if key element is accessible */
        /* # Read key elements. */
        retVal = Crypto_30_LibCv_Local_GetElementsIndexJob(job->cryptoKeyId, keyElements, 1u, CRYPTO_30_LIBCV_LENGTH_CHECK_NONE); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */

        if (retVal == E_OK)
        {
          /* # Initialize algorithm. */
          retVal = E_NOT_OK;
          retValCv = esl_initSipHash(workspace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER */
                                     (eslt_Length)keyElements[0u].keyElementLength,
                                     (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(keyElements[0u].keyElementIndex));
        }
      }
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      /* # Process plaintext data */
      retValCv = esl_updateSipHash(workspace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
                                   (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
                                   (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      eslt_Byte macBuffer[CRYPTO_30_LIBCV_SIPHASH_MAC_SIZE];
      uint32 macLength;
      retValCv = esl_finalizeSipHash(workspace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))macBuffer); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */

      if (retValCv == ESL_ERC_NO_ERROR)
      {
        /* # Check if input length is not to large. */
        macLength = job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength;
        if (macLength <= (CRYPTO_30_LIBCV_SIPHASH_MAC_SIZE << 3u))
        {

          /* # Check if verification was successful. */
          *(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.verifyPtr) = /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
            Crypto_30_LibCv_CompareMac(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputPtr, macBuffer, macLength); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_STACK_BUFFER_AND_PARAMETER_BUFFER */
        }
        else
        {
          retValCv = ESL_ERC_ERROR;
        }
      }
      break;
    }

    default:   /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_SipHashVerify() */
#endif /* (CRYPTO_30_LIBCV_SIPHASHVERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA1GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA1VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA1ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA1ModeStart(
  P2VAR(eslt_WorkSpaceHMACSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  /* # Initialize workspace header. */
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  Crypto_30_LibCv_KeyElementGetType keyElements[1];

  Crypto_30_LibCv_Local_ElementGetterSetId(keyElements, 0u, CRYPTO_KE_MAC_KEY); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */

  if (esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_HMACSHA1, CRYPTO_30_LIBCV_WATCHDOG_PTR) == ESL_ERC_NO_ERROR) /* PRQA S 3395 */ /* MD_CRYPTO_30_LIBCV_3395 */ /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */
  {
    /* Check if key element is accessible */
    /* # Read key elements. */
    retVal = Crypto_30_LibCv_Local_GetElementsIndexJob(job->cryptoKeyId, keyElements, 1u, CRYPTO_30_LIBCV_LENGTH_CHECK_NONE); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */
    if (retVal == E_OK)
    {
      /* # Initialize algorithm. */
      retVal = E_NOT_OK;
      retValCv = esl_initHashMACSHA1(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER */
                                     (eslt_Length)keyElements[0u].keyElementLength,
                                     (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(keyElements[0u].keyElementIndex));
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_DispatchHmacSHA1ModeStart() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA1ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA1ModeUpdate(
  P2VAR(eslt_WorkSpaceHMACSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;

  /* Update HMAC Calculation */
  /* # Process input data. */
  retValCv = esl_updateHashMACSHA1(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
                                   (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
                                   (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA1ModeUpdate() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA1GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA1VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA1GENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA1GenerateModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA1GenerateModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  uint8 macBuffer[ESL_SIZEOF_SHA1_DIGEST];

  if (esl_finalizeHashMACSHA1(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR)) macBuffer) == ESL_ERC_NO_ERROR) /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
  {
    /* # Adapt output size. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_SHA1_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_SHA1_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }

    /* # Write results in output buffers. */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, macBuffer, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    /* Set return value */
    retValCv = ESL_ERC_NO_ERROR;
  }
  else
  {
    *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = 0u; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA1GenerateModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_HmacSha1Generate()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_HmacSha1Generate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceHMACSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfHmacSha1Generate(Crypto_30_LibCv_GetHmacSha1GenerateIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceHMACSHA1)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHmacSHA1ModeStart(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA1ModeUpdate(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA1GenerateModeFinish(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_HmacSha1Generate() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA1GENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA256GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA256VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA256ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA256ModeStart(
  P2VAR(eslt_WorkSpaceHMACSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  /* # Initialize workspace header. */
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  Crypto_30_LibCv_KeyElementGetType keyElements[1];

  Crypto_30_LibCv_Local_ElementGetterSetId(keyElements, 0u, CRYPTO_KE_MAC_KEY); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */

  if (esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_HMACSHA256, CRYPTO_30_LIBCV_WATCHDOG_PTR) == ESL_ERC_NO_ERROR) /* PRQA S 3395 */ /* MD_CRYPTO_30_LIBCV_3395 */ /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */
  {
    /* Check if key element is accessible */
    /* # Read key elements. */
    retVal = Crypto_30_LibCv_Local_GetElementsIndexJob(job->cryptoKeyId, keyElements, 1u, CRYPTO_30_LIBCV_LENGTH_CHECK_NONE); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */
    if (retVal == E_OK)
    {
      /* # Initialize algorithm. */
      retVal = E_NOT_OK;
      retValCv = esl_initHashMACSHA256(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER */
                                       (eslt_Length)keyElements[0u].keyElementLength,
                                       (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(keyElements[0u].keyElementIndex));
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_DispatchHmacSHA256ModeStart() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA256ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA256ModeUpdate(
  P2VAR(eslt_WorkSpaceHMACSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;

  /* Update HMAC Calculation */
  /* # Process input data. */
  retValCv = esl_updateHashMACSHA256(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
                                     (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
                                     (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA256ModeUpdate() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA256GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA256VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA256GENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA256GenerateModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA256GenerateModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  uint8 macBuffer[ESL_SIZEOF_SHA256_DIGEST];

  if (esl_finalizeHashMACSHA256(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR)) macBuffer) == ESL_ERC_NO_ERROR) /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
  {
    /* # Adapt output size. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_SHA256_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_SHA256_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }

    /* # Write results in output buffers. */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, macBuffer, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    /* Set return value */
    retValCv = ESL_ERC_NO_ERROR;
  }
  else
  {
    *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = 0u; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA256GenerateModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_HmacSha256Generate()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_HmacSha256Generate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceHMACSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfHmacSha256Generate(Crypto_30_LibCv_GetHmacSha256GenerateIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceHMACSHA256)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHmacSHA256ModeStart(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA256ModeUpdate(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA256GenerateModeFinish(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_HmacSha256Generate() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA256GENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA384GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA384VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA384ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA384ModeStart(
  P2VAR(eslt_WorkSpaceHMACSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  /* # Initialize workspace header. */
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  Crypto_30_LibCv_KeyElementGetType keyElements[1];

  Crypto_30_LibCv_Local_ElementGetterSetId(keyElements, 0u, CRYPTO_KE_MAC_KEY); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */

  if (esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_HMACSHA384, CRYPTO_30_LIBCV_WATCHDOG_PTR) == ESL_ERC_NO_ERROR) /* PRQA S 3395 */ /* MD_CRYPTO_30_LIBCV_3395 */ /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */
  {
    /* Check if key element is accessible */
    /* # Read key elements. */
    retVal = Crypto_30_LibCv_Local_GetElementsIndexJob(job->cryptoKeyId, keyElements, 1u, CRYPTO_30_LIBCV_LENGTH_CHECK_NONE); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */
    if (retVal == E_OK)
    {
      /* # Initialize algorithm. */
      retVal = E_NOT_OK;
      retValCv = esl_initHashMACSHA384(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER */
                                       (eslt_Length)keyElements[0u].keyElementLength,
                                       (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(keyElements[0u].keyElementIndex));
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_DispatchHmacSHA384ModeStart() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA384ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA384ModeUpdate(
  P2VAR(eslt_WorkSpaceHMACSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;

  /* Update HMAC Calculation */
  /* # Process input data. */
  retValCv = esl_updateHashMACSHA384(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
                                     (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
                                     (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA384ModeUpdate() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA384GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA384VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA384GENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA384GenerateModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA384GenerateModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  uint8 macBuffer[ESL_SIZEOF_SHA384_DIGEST];

  if (esl_finalizeHashMACSHA384(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR)) macBuffer) == ESL_ERC_NO_ERROR) /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
  {
    /* # Adapt output size. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_SHA384_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_SHA384_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }

    /* # Write results in output buffers. */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, macBuffer, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    /* Set return value */
    retValCv = ESL_ERC_NO_ERROR;
  }
  else
  {
    *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = 0u; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA384GenerateModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_HmacSha384Generate()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_HmacSha384Generate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceHMACSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfHmacSha384Generate(Crypto_30_LibCv_GetHmacSha384GenerateIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceHMACSHA384)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHmacSHA384ModeStart(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA384ModeUpdate(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA384GenerateModeFinish(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_HmacSha384Generate() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA384GENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA512GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA512VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA512ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA512ModeStart(
  P2VAR(eslt_WorkSpaceHMACSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  /* # Initialize workspace header. */
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  Crypto_30_LibCv_KeyElementGetType keyElements[1];

  Crypto_30_LibCv_Local_ElementGetterSetId(keyElements, 0u, CRYPTO_KE_MAC_KEY); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */

  if (esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_HMACSHA512, CRYPTO_30_LIBCV_WATCHDOG_PTR) == ESL_ERC_NO_ERROR) /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */
  {
    /* Check if key element is accessible */
    /* # Read key elements. */
    retVal = Crypto_30_LibCv_Local_GetElementsIndexJob(job->cryptoKeyId, keyElements, 1u, CRYPTO_30_LIBCV_LENGTH_CHECK_NONE); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */
    if (retVal == E_OK)
    {
      /* # Initialize algorithm. */
      retVal = E_NOT_OK;
      retValCv = esl_initHashMACSHA512(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER  */
                                       (eslt_Length)keyElements[0u].keyElementLength,
                                       (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(keyElements[0u].keyElementIndex));
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_DispatchHmacSHA512ModeStart() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA512ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA512ModeUpdate(
  P2VAR(eslt_WorkSpaceHMACSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;

  /* Update HMAC Calculation */
  /* # Process input data. */
  retValCv = esl_updateHashMACSHA512(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
    (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
    (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA512ModeUpdate() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA512GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACSHA512VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA512GENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA512GenerateModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA512GenerateModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  uint8 macBuffer[ESL_SIZEOF_SHA512_DIGEST];
  eslt_Length macLength = sizeof(macBuffer);

  if (esl_finalizeHashMACSHA512(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR)) macBuffer, (P2VAR(eslt_Length, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))&macLength) == ESL_ERC_NO_ERROR) /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_PARAMETER_BUFFER */
  {
    /* # Adapt output size. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_SHA512_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_SHA512_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }

    /* # Write results in output buffers. */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, macBuffer, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    /* Set return value */
    retValCv = ESL_ERC_NO_ERROR;
  }
  else
  {
    *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = 0u; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA512GenerateModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_HmacSha512Generate()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_HmacSha512Generate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceHMACSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfHmacSha512Generate(Crypto_30_LibCv_GetHmacSha512GenerateIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceHMACSHA512)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHmacSHA512ModeStart(workspace, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA512ModeUpdate(workspace, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA512GenerateModeFinish(workspace, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default: /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_HmacSha512Generate() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA512GENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA1VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA1VerifyModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA1VerifyModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_1 */
{
  eslt_ErrorCode retValCv;
  uint8 macBuffer[ESL_SIZEOF_SHA1_DIGEST];

  retValCv = esl_finalizeHashMACSHA1(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR)) macBuffer); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Check if input length is not to large. */
    /* size is given in bits */
    if (job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength <= Crypto_30_LibCv_Byte2Bit(ESL_SIZEOF_SHA1_DIGEST))
    {
      /* # Check if verification was successful. */
      *(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.verifyPtr) = /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
        Crypto_30_LibCv_CompareMac(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputPtr, macBuffer, job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_STACK_BUFFER_AND_PARAMETER_BUFFER */
    }
    else
    {
      retValCv = ESL_ERC_ERROR;
    }
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA1VerifyModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_HmacSha1Verify()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_HmacSha1Verify(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceHMACSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfHmacSha1Verify(Crypto_30_LibCv_GetHmacSha1VerifyIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceHMACSHA1)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHmacSHA1ModeStart(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA1ModeUpdate(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA1VerifyModeFinish(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default: /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_HmacSha1Verify() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA1VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA256VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA256VerifyModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA256VerifyModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_1 */
{
  eslt_ErrorCode retValCv;
  uint8 macBuffer[ESL_SIZEOF_SHA256_DIGEST];

  retValCv = esl_finalizeHashMACSHA256(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR)) macBuffer); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Check if input length is not to large. */
    /* size is given in bits */
    if (job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength <= Crypto_30_LibCv_Byte2Bit(ESL_SIZEOF_SHA256_DIGEST))
    {
      /* # Check if verification was successful. */
      *(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.verifyPtr) = /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
        Crypto_30_LibCv_CompareMac(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputPtr, macBuffer, job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_STACK_BUFFER_AND_PARAMETER_BUFFER */
    }
    else
    {
      retValCv = ESL_ERC_ERROR;
    }
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA256VerifyModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_HmacSha256Verify()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_HmacSha256Verify(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceHMACSHA256, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT) workspace = Crypto_30_LibCv_GetWorkspaceOfHmacSha256Verify(Crypto_30_LibCv_GetHmacSha256VerifyIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceHMACSHA256)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHmacSHA256ModeStart(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA256ModeUpdate(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA256VerifyModeFinish(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_HmacSha256Verify() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA256VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA384VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA384VerifyModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA384VerifyModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_1 */
{
  eslt_ErrorCode retValCv;
  uint8 macBuffer[ESL_SIZEOF_SHA384_DIGEST];

  retValCv = esl_finalizeHashMACSHA384(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR)) macBuffer); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Check if input length is not to large. */
    /* size is given in bits */
    if (job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength <= Crypto_30_LibCv_Byte2Bit(ESL_SIZEOF_SHA384_DIGEST))
    {
      /* # Check if verification was successful. */
      *(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.verifyPtr) = /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
        Crypto_30_LibCv_CompareMac(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputPtr, macBuffer, job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_STACK_BUFFER_AND_PARAMETER_BUFFER */
    }
    else
    {
      retValCv = ESL_ERC_ERROR;
    }
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA384VerifyModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_HmacSha384Verify()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_HmacSha384Verify(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceHMACSHA384, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT) workspace = Crypto_30_LibCv_GetWorkspaceOfHmacSha384Verify(Crypto_30_LibCv_GetHmacSha384VerifyIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceHMACSHA384)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHmacSHA384ModeStart(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA384ModeUpdate(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA384VerifyModeFinish(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_HmacSha384Verify() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA384VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACSHA512VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacSHA512VerifyModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacSHA512VerifyModeFinish(
  P2VAR(eslt_WorkSpaceHMACSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_1 */
{
  eslt_ErrorCode retValCv;
  uint8 macBuffer[ESL_SIZEOF_SHA512_DIGEST];
  eslt_Length macLength = sizeof(macBuffer);

  retValCv = esl_finalizeHashMACSHA512(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))macBuffer, (P2VAR(eslt_Length, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))&macLength); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_PARAMETER_BUFFER */
  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Check if input length is not to large. */
    /* size is given in bits */
    if (job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength <= Crypto_30_LibCv_Byte2Bit(ESL_SIZEOF_SHA512_DIGEST))
    {
      /* # Check if verification was successful. */
      *(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.verifyPtr) = /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
        Crypto_30_LibCv_CompareMac(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputPtr, macBuffer, job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_STACK_BUFFER_AND_PARAMETER_BUFFER */
    }
    else
    {
      retValCv = ESL_ERC_ERROR;
    }
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacSHA512VerifyModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_HmacSha512Verify()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_HmacSha512Verify(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceHMACSHA512, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT) workspace = Crypto_30_LibCv_GetWorkspaceOfHmacSha512Verify(Crypto_30_LibCv_GetHmacSha512VerifyIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceHMACSHA512)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHmacSHA512ModeStart(workspace, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA512ModeUpdate(workspace, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacSHA512VerifyModeFinish(workspace, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default: /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_HmacSha512Verify() */
#endif /* (CRYPTO_30_LIBCV_HMACSHA512VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_GMACAESGENERATE == STD_ON) || (CRYPTO_30_LIBCV_GMACAESVERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchGmacAesModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchGmacAesModeStart(
  P2VAR(eslt_WorkSpaceGMAC, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  /* # Initialize workspace header. */
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  Crypto_30_LibCv_KeyElementGetType keyElements[2];

  Crypto_30_LibCv_Local_ElementGetterSetId(keyElements, 0u, CRYPTO_KE_CIPHER_KEY); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */
  Crypto_30_LibCv_Local_ElementGetterSetId(keyElements, 1u, CRYPTO_KE_CIPHER_IV); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */

  if (esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_GMAC, CRYPTO_30_LIBCV_WATCHDOG_PTR) == ESL_ERC_NO_ERROR) /* PRQA S 3395 */ /* MD_CRYPTO_30_LIBCV_3395 */ /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */
  {
    /* Check if key element is accessible */
    /* # Read key elements. */
    retVal = Crypto_30_LibCv_Local_GetElementsIndexJob(job->cryptoKeyId, keyElements, 2u, CRYPTO_30_LIBCV_LENGTH_CHECK_NONE); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */
    if (retVal == E_OK)
    {
      /* # Initialize algorithm. */
      retVal = E_NOT_OK;
      retValCv = esl_initGMAC(workSpace,
                              (eslt_Length)keyElements[0u].keyElementLength,
                              (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(keyElements[0u].keyElementIndex),
                              (eslt_Length)keyElements[1u].keyElementLength, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER */
                              (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(keyElements[1u].keyElementIndex));
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_DispatchGmacAesModeStart() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchGmacAesModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchGmacAesModeUpdate(
  P2VAR(eslt_WorkSpaceGMAC, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;

  /* Update GMAC Calculation */
  /* # Process input data. */
  retValCv = esl_updateGMAC(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
                            (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
                            (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  return retValCv;
} /* Crypto_30_LibCv_DispatchGmacAesModeUpdate() */
#endif /* (CRYPTO_30_LIBCV_GMACAESGENERATE == STD_ON) || (CRYPTO_30_LIBCV_GMACAESVERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_GMACAESGENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchGmacAesGenerateModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchGmacAesGenerateModeFinish(
  P2VAR(eslt_WorkSpaceGMAC, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* buffer holding Auth Tag */
  eslt_Byte authTagTempBuffer[CRYPTO_30_LIBCV_GMAC_MAX_OUT_TAG_SIZE] = { 0u };

  /* # Write results in output buffer. */
  if (esl_finalizeGMAC(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))&authTagTempBuffer[0]) /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
      == ESL_ERC_NO_ERROR)
  {
    /* # Adapt output size of auth tag. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > CRYPTO_30_LIBCV_GMAC_MAX_OUT_TAG_SIZE)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = CRYPTO_30_LIBCV_GMAC_MAX_OUT_TAG_SIZE; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }
    /* # Copy auth tag to output buffer. */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, authTagTempBuffer, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    retValCv = ESL_ERC_NO_ERROR;
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchGmacAesGenerateModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_GmacAesGenerate()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030 4 */ /* MD_MSR_STCYC */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_GmacAesGenerate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceGMAC, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfGmacAesGenerate(Crypto_30_LibCv_GetGmacAesGenerateIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceGMAC)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchGmacAesModeStart(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchGmacAesModeUpdate(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchGmacAesGenerateModeFinish(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }
  return retVal;
} /* Crypto_30_LibCv_Dispatch_GmacAesGenerate() */
#endif /* (CRYPTO_30_LIBCV_GMACAESGENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_GMACAESVERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchGmacAesVerifyModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchGmacAesVerifyModeFinish(
  P2VAR(eslt_WorkSpaceGMAC, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_1 */
{
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* buffer holding Auth Tag */
  eslt_Byte authTagTempBuffer[CRYPTO_30_LIBCV_GMAC_MAX_OUT_TAG_SIZE] = { 0u };
  uint32 authTagTempBufferLength;

  /* # Write results in output buffer. */
  if (esl_finalizeGMAC(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))&authTagTempBuffer[0]) /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
      == ESL_ERC_NO_ERROR)
  {
    /* # Check if input length is not to large. */
    authTagTempBufferLength = job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength;
    /* size is given in bits */
    if (authTagTempBufferLength <= (CRYPTO_30_LIBCV_GMAC_MAX_OUT_TAG_SIZE << 3u))
    {

      /* # Check if verification was successful. */
      *(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.verifyPtr) = /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
        Crypto_30_LibCv_CompareMac(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputPtr, authTagTempBuffer, authTagTempBufferLength); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_STACK_BUFFER_AND_PARAMETER_BUFFER */
      retValCv = ESL_ERC_NO_ERROR;
    }
    else
    {
      retValCv = ESL_ERC_ERROR;
    }
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchGmacAesVerifyModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_GmacAesVerify()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030 4 */ /* MD_MSR_STCYC */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_GmacAesVerify(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceGMAC, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfGmacAesVerify(Crypto_30_LibCv_GetGmacAesVerifyIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceGMAC)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchGmacAesModeStart(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchGmacAesModeUpdate(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchGmacAesVerifyModeFinish(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }
  return retVal;
} /* Crypto_30_LibCv_Dispatch_GmacAesVerify() */
#endif /* (CRYPTO_30_LIBCV_GMACAESVERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACRIPEMD160GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACRIPEMD160VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacRipeMd160ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacRipeMd160ModeStart(
  P2VAR(eslt_WorkSpaceHMACRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  /* # Initialize workspace header. */
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  Crypto_30_LibCv_KeyElementGetType keyElements[1];

  Crypto_30_LibCv_Local_ElementGetterSetId(keyElements, 0u, CRYPTO_KE_MAC_KEY); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */

  if (esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_HMACRIPEMD160, CRYPTO_30_LIBCV_WATCHDOG_PTR) == ESL_ERC_NO_ERROR) /* PRQA S 3395 */ /* MD_CRYPTO_30_LIBCV_3395 */ /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */
  {
    /* Check if key element is accessible */
    /* # Read key elements. */
    retVal = Crypto_30_LibCv_Local_GetElementsIndexJob(job->cryptoKeyId, keyElements, 1u, CRYPTO_30_LIBCV_LENGTH_CHECK_NONE); /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_VARIABLE_AS_PTR */
    if (retVal == E_OK)
    {
      /* # Initialize algorithm. */
      retVal = E_NOT_OK;
      retValCv = esl_initHashMACRIPEMD160(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER */
                                         (eslt_Length)keyElements[0u].keyElementLength,
                                         (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))Crypto_30_LibCv_GetAddrKeyStorage(keyElements[0u].keyElementIndex));
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_DispatchHmacRipeMd160ModeStart() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacRipeMd160ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacRipeMd160ModeUpdate(
  P2VAR(eslt_WorkSpaceHMACRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;

  /* Update HMAC Calculation */
  /* # Process input data. */
  retValCv = esl_updateHashMACRIPEMD160(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
                                       (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
                                       (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacRipeMd160ModeUpdate() */
#endif /* (CRYPTO_30_LIBCV_HMACRIPEMD160GENERATE == STD_ON) || (CRYPTO_30_LIBCV_HMACRIPEMD160VERIFY == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACRIPEMD160GENERATE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacRipeMd160GenerateModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacRipeMd160GenerateModeFinish(
  P2VAR(eslt_WorkSpaceHMACRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;
  uint8 macBuffer[ESL_SIZEOF_SHA1_DIGEST];

  if (esl_finalizeHashMACRIPEMD160(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR)) macBuffer) == ESL_ERC_NO_ERROR) /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
  {
    /* # Adapt output size. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_RIPEMD160_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_RIPEMD160_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }

    /* # Write results in output buffers. */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, macBuffer, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    /* Set return value */
    retValCv = ESL_ERC_NO_ERROR;
  }
  else
  {
    *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = 0u; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacRipeMd160GenerateModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_HmacRipeMd160Generate()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_HmacRipeMd160Generate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceHMACRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfHmacRipeMd160Generate(Crypto_30_LibCv_GetHmacRipeMd160GenerateIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceHMACRIPEMD160)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHmacRipeMd160ModeStart(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacRipeMd160ModeUpdate(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacRipeMd160GenerateModeFinish(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default:  /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_HmacRipeMd160Generate() */
#endif /* (CRYPTO_30_LIBCV_HMACRIPEMD160GENERATE == STD_ON) */

#if (CRYPTO_30_LIBCV_HMACRIPEMD160VERIFY == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHmacRipeMd160VerifyModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHmacRipeMd160VerifyModeFinish(
  P2VAR(eslt_WorkSpaceHMACRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_1 */
{
  eslt_ErrorCode retValCv;
  uint8 macBuffer[ESL_SIZEOF_RIPEMD160_DIGEST];

  retValCv = esl_finalizeHashMACRIPEMD160(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR)) macBuffer); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */
  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Check if input length is not to large. */
    /* size is given in bits */
    if (job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength <= Crypto_30_LibCv_Byte2Bit(ESL_SIZEOF_RIPEMD160_DIGEST))
    {
      /* # Check if verification was successful. */
      *(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.verifyPtr) = /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
        Crypto_30_LibCv_CompareMac(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputPtr, macBuffer, job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_STACK_BUFFER_AND_PARAMETER_BUFFER */
    }
    else
    {
      retValCv = ESL_ERC_ERROR;
    }
  }

  return retValCv;
} /* Crypto_30_LibCv_DispatchHmacRipeMd160VerifyModeFinish() */

/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_HmacRipeMd160Verify()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_HmacRipeMd160Verify(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  eslt_ErrorCode retValCv = ESL_ERC_ERROR;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceHMACRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workspace = Crypto_30_LibCv_GetWorkspaceOfHmacRipeMd160Verify(Crypto_30_LibCv_GetHmacRipeMd160VerifyIdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceHMACRIPEMD160)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHmacRipeMd160ModeStart(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacRipeMd160ModeUpdate(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retValCv = Crypto_30_LibCv_DispatchHmacRipeMd160VerifyModeFinish(workspace, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }

    default: /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      /* Not supported State */
      break;
    }
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_LibCv_Dispatch_HmacRipeMd160Verify() */
#endif /* (CRYPTO_30_LIBCV_HMACRIPEMD160VERIFY == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define CRYPTO_30_LIBCV_STOP_SEC_CODE
#include "Crypto_30_LibCv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_LibCv_Mac.c
 *********************************************************************************************************************/
