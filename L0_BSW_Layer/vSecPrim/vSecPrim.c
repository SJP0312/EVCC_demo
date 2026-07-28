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
/*!        \file  vSecPrim.c
 *        \brief  Provides static informations. No functionality provided.
 *
 *      \details  Main file of vSecPrim providing Misra and SBSW justifications.
 *                This file is part of the embedded systems library cvActLib/ES
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
#define VSECPRIM_SOURCE
#include "vSecPrim.h"
#include "vSecPrim_Cfg.h"
#include "actConfig.h"
#include "actPlatformTypes.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of vSecPrim header file */
#if ((VSECPRIM_SW_MAJOR_VERSION != (10u)) \
    || (VSECPRIM_SW_MINOR_VERSION != (1u)) \
    || (VSECPRIM_SW_PATCH_VERSION != (0u)))
# error "Vendor specific version numbers of vSecPrim.c and vSecPrim.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  vSecPrim_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) vSecPrim_getVersionInfo(
  VSECPRIM_P2VAR_PARA(vSecPrim_VersionInfoType) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  /* Check parameters */
  if (versioninfo == NULL_PTR)
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else
  {
    /* Write versionInfo pointer with modules versions. */
    versioninfo->vendorID = (uint16)VSECPRIM_VENDOR_ID; /* SBSW_VSECPRIM_WRITE_POINTER */
    versioninfo->moduleID = (uint8)VSECPRIM_MODULE_ID; /* SBSW_VSECPRIM_WRITE_POINTER */
    versioninfo->sw_major_version = (uint8)VSECPRIM_SW_MAJOR_VERSION; /* SBSW_VSECPRIM_WRITE_POINTER */
    versioninfo->sw_minor_version = (uint8)VSECPRIM_SW_MINOR_VERSION; /* SBSW_VSECPRIM_WRITE_POINTER */
    versioninfo->sw_patch_version = (uint8)VSECPRIM_SW_PATCH_VERSION; /* SBSW_VSECPRIM_WRITE_POINTER */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* Module specific MISRA deviations:

  MD_VSECPRIM_8.7:
    Reason:     Following this MISRA rule would lead to unreadable code, as the constant fields are huge.
                Vector style guide prevents usage of static variables/constant objects in function scope.
    Risk:       None
    Prevention: Not necessary

  MD_VSECPRIM_5.6:
    Reason:     Naming of the buffer and struct members are similar to provided parameters to make the code more
                readable.
    Risk:       One could read wrong and adapt the code falsely.
    Prevention: Covered by code review and tests.

  MD_VSECPRIM_11.4:
    Reason:     Casting between different pointer is necessary due to the nature of this library.
    Risk:       None - the basic types remain the same.
    Prevention: Covered by code review and tests.

  MD_VSECPRIM_13.1:
    Reason:     An assignment operator is being used in a boolean expression this decreases the
                readability of the code.
    Risk:       Code could be mistaken.
    Prevention: Additional comment is stated.

  MD_VSECPRIM_21.1:
    Reason:     There could be no wraparound because of the previous check.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_16.7:
    Reason:     Pointer can only be const when method is empty and only Dummy statements are used.
    Risk:       None
    Prevention: Covered by code review.

  MD_VSECPRIM_14.6:
    Reason:     Two break statements are implemented to provide simple yet efficient code.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_19.1:
    Reason:     The included file contains wrapper functions that can be used in different contexts. Before including
                it, it is necessary to define the data type the wrappers shall be defined for.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_WATCHDOG:
    Reason:     Calling the watchdog trigger function depends basically on two factors:
                  - If the watchdog trigger function is a valid pointer
                  - Watchdog trigger level
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_P2VOID_CAST: MISRA Dir 1.1
    Reason:     The implicit conversion from a pointer to object type to a pointer to void is used calling functions
                that allow pointers to different object types as parameter.
    Risk:       There is an invalid conversion within the function from a pointer to void to a pointer to object type
                and thus invalid data are read.
    Prevention: Code inspection.

  MD_VSECPRIM_11.4_P2UINT8_CAST: MISRA Rule 11.4
    Reason:     The conversion from a pointer to void to a pointer to object type is used to access the object's memory byte-wisely.
                The size of the object's memory is known.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_REDUNDANT_OP:
    Reason:     The redundant operation is a side effect of a better readability of the code.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_CONFIGURATION_DEPENDENT_REDUNDANT_OP:
    Reason:     The redundant operation is a side effect of the configurability of the code and required to avoid
                compile errors in certain configurations.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_ASSIGNMENT_RESULT_IN_OP: Misra Rule 13.4
    Reason:     The result of an assignment is being used in an arithmetic operation or another assigning operation in
                order to keep the processing flow of the algorithm's complex arithmetic operations as they are
                described in the algorithm's specification.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_USE_OF_BASIC_TYPES: Misra Dir 4.6
    Reason:     Only non safe files are affected.
    Risk:       None
    Prevention: Review.

  MD_VSECPRIM_CONST_BOOL_OPERAND: Misra Rule 14.3
    Reason:     Boolean operand might be constant in definition depend on configuration.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_REDUNDANT_ASSIGNMENT: Misra Rule 2.2
    Reason:     Redundant assignment in last cycle of for loop.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_ALGORITHM_REQUIRED_ASSIGNMENT
    Reason:     Redundant assignment due to algorithm specification
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_2.2
    Reason:     Redundant assignment to avoid compiler warning of use of potentially uninitialized variable.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_CONST_POINTER: Misra Rule 8.13
    Reason:     The function parameter is a pointer to a pointer. The object referenced by the inner pointer
                (and therefore also by the pointer to the pointer) is modified or the outer pointer is passed to another function,
                but this is not detected by QAC. Thus, the parameter can not be passed as pointer-to-const.
    Risk:       The use of a pointer referencing another pointer makes the code more complicated to understand.
    Prevention: Code review.

  MD_VSECPRIM_8.9
    Reason:     An array lies in static ROM, but is only accessed in one function.
    Risk:       Additional Rom usage.
    Prevention: N/A

  MD_VSECPRIM_QM_ONLY_METRIC
    Reason:     A function in the QM part of the component violates a metric threshold. The function is
                proven in use.
    Risk:       Code is difficult to comprehend
    Prevention: Code review.

  MD_VSECPRIM_QM_ONLY_UNUSED_FUNCTION
    Reason:     A function in the QM part of the component is not used in some configurations. This affects
                placeholder functions that are used when a certain algorithm is turned off. The function is
                proven in use.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_QM_ONLY_RETURN_PATHS
    Reason:     A function in the QM part of the component has more than one return path. The function is
                proven in use.
    Risk:       Code is difficult to comprehend
    Prevention: Code review.

  MD_VSECPRIM_QM_ONLY_REDUNDANT_ASSIGNMENT_OR_OPERATION
    Reason:     A redundant assignment or operation is made in the QM part of the component. The function is
                proven in use.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_QM_ONLY_CASTING_POINTER_TYPE
    Reason:     A pointer is cast to a pointer referencing an object of different type in the QM part
                of the component. The function is proven in use.
    Risk:       None
    Prevention: N/A

  MD_VSECPRIM_QM_ONLY_POINTER_ARITHMETIC
    Reason:     There is an arithmetic operation on a pointer in the QM part of the component. The function is
                proven in use.
    Risk:       Code is difficult to comprehend.
    Prevention: N/A

  MD_VSECPRIM_QM_ONLY_VARIABLE_IN_LOOP
    Reason:     In a for-loop, two variables instead of one are compared to a stopping criterion and are incremented
                in the QM part of the component. The function is proven in use.
    Risk:       Code is difficult to comprehend.
    Prevention: N/A

  MD_VSECPRIM_QM_ONLY_SHORT_DECREMENT_INCREMENT_OPERATION
    Reason:     A decrement or increment operation is used in combination with another operation in the QM part of the component.
                The function is proven in use.
    Risk:       Code is difficult to comprehend.
    Prevention: N/A

  MD_VSECPRIM_QM_ONLY_POINTER_CAST_TO_LARGER_TYPE
    Reason:     A pointer is cast to a type with a stricter alignment requirement in the QM part of the component.
                The function is proven in use.
    Risk:       None.
    Prevention: N/A

  MD_VSECPRIM_WRAPAROUND
    Reason:     There is a wraparound in an unsigned arithmetic operation. This is intended due to the specification of the algorithm.
    Risk:       None
    Prevention: Code review.

  MD_VSECPRIM_INVALID_PTR_AES
    Reason:     Dereference of an invalid pointer value within rco_tab[(i % 10u)]. (i % 10u) ensures that the access to rco_tab is always in range.
    Risk:       None
    Prevention: Code review.

  MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHD
    Reason:     Dereference of an invalid pointer value within a[d]. The for-loops go up to BNDIGITS_912 where d is used for accessing a,
                however a is of size BNDIGITS_912_MULTIPLICATION (BNDIGITS_912_MULTIPLICATION > BNDIGITS_912).
    Risk:       None
    Prevention: Code review.

  MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHOFFSET1
    Reason:     Dereference of an invalid pointer value within a[offset1]. The for-loops go up to BNDIGITS_912 where offset1 is used for accessing a,
                however a is of size BNDIGITS_912_MULTIPLICATION (BNDIGITS_912_MULTIPLICATION > BNDIGITS_912).
    Risk:       None
    Prevention: Code review.

  MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHOFFSET2
    Reason:     Dereference of an invalid pointer value within a[offset2]. The for-loops go up to BNDIGITS_912 where offset2 is used for accessing a,
                however a is of size BNDIGITS_912_MULTIPLICATION (BNDIGITS_912_MULTIPLICATION > BNDIGITS_912).
    Risk:       None
    Prevention: Code review.

  MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHQ
    Reason:     Dereference of an invalid pointer value within q[offsetq]. The for-loops go up to BNDIGITS_456 where offsetq is used for accessing q,
                however q is of size BNDIGIT_456. The last loop where q is accessed goes up to BNDIGITS_456, but the incrementation of offsetq
                happens after the write-operation. Hence, the last index of q is q[BNDIGIT_456-1].
    Risk:       None
    Prevention: Code review.

  MD_VSECPRIM_PTR_REDEFINITION_SM4
    Reason:     Pointer parameter is redefined to handle the next block of the buffer. There is no overflow since the
                for-loop goes over the number of blocks in the buffer.
    Risk:       None
    Prevention: Code review.
 */

/**********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 *********************************************************************************************************************/
/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_VSECPRIM_WRITE_ARRAY_NO_CHECK
    \DESCRIPTION This function has writing operation on an array without any boundary checks.
    \COUNTERMEASURE \N The specific function must not be called by the user but only by the vSecPrim module itself.
                       The calling operations where a possible boundary violation could occur have been validated during the code review.

  \ID SBSW_VSECPRIM_WRITE_ARRAY
    \DESCRIPTION This function has writing operation on an array with boundary check.
    \COUNTERMEASURE \N The specific function must not be called by the user but only by the vSecPrim module itself.
                       Possible boundary violations are evaluated during the code review.

  \ID SBSW_VSECPRIM_WRITE_POINTER
    \DESCRIPTION    The function does a write access on an pointer.
    \COUNTERMEASURE \R The validity of the pointer was checked before.

  \ID SBSW_VSECPRIM_CALL_FUNCTION
    \DESCRIPTION    The function passes a pointer to another function.
    \COUNTERMEASURE \R The validity of the pointer was checked before either by the calling function or a function in the upper layer.

  \ID SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG
    \DESCRIPTION    The function passes a function pointer referencing a watchdog trigger function to another function.
                    That passed function pointer in turn has been passed by the caller. The API requires that the referenced function is
                    a watchdog trigger function.
    \COUNTERMEASURE \N The caller ensures that the function pointer passed as parameter is valid and references a watchdog trigger function.

  \ID SBSW_VSECPRIM_FUNCTION_POINTER_CALL_WATCHDOG
    \DESCRIPTION    A function pointer to a watchdog trigger function to be called inside the called function is
                    provided by the caller. The API requires that watchdog is a pointer to a watchdog trigger
                    function.
    \COUNTERMEASURE \N The specific function must not be called by the user but only by the vSecPrim module itself.
                       The validity of the function pointer is guaranteed by the caller of this function.

  \ID SBSW_VSECPRIM_FUNCTION_POINTER_CALL_TRANSFORM
    \DESCRIPTION    A function pointer to a transformation function to be called inside the called function is
                    provided by the caller. The API requires that transform is a pointer to a  transformation
                    function.
    \COUNTERMEASURE \N The specific function must not be called by the user but only by the vSecPrim module itself.
                       The validity of the function pointer is guaranteed by the caller of this function.

  \ID SBSW_VSECPRIM_FUNCTION_CALL_POINTER_CHECKED_WITHIN
    \DESCRIPTION    Pointer(s) are passed to the function without previous validity checks.
    \COUNTERMEASURE \N The function pointer is checked for validity within this function.

  \ID SBSW_VSECPRIM_PTR_WRITE_ACCESS_PASSED_BUFFER
    \DESCRIPTION    The function uses the pointer to write to the referenced object. The pointer is passed as
                    parameter. The API requires that the referenced object is of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE]

  \ID SBSW_VSECPRIM_ARRAY_WRITE_ACCESS_LOCAL_BUFFER_FIXED_INDEX
    \DESCRIPTION    The function writes array elements using fixed indices. The array is defined locally and of known
                    size.
    \COUNTERMEASURE \N [CM_VSECPRIM_EXCLUDE_BOUNDARY_VIOLATION_BY_REVIEW]

  \ID SBSW_VSECPRIM_ARRAY_WRITE_ACCESS_LOCAL_BUFFER_MASKED_INDEX
    \DESCRIPTION    The function writes array elements using indices that are masked resp. size-restricted by a modulo
                    operation before being applied. The array is defined locally and of known size.
    \COUNTERMEASURE \R [CM_VSECPRIM_EXCLUDE_BOUNDARY_VIOLATION_BY_RUNTIME_MEASURE]

  \ID SBSW_VSECPRIM_ARRAY_WRITE_ACCESS_LOCAL_BUFFER_VARIABLE_INDEX_CHECK
    \DESCRIPTION    The function writes array elements using indices that are checked against the array size before
                    being applied. The array is defined locally and of known size.
    \COUNTERMEASURE \N [CM_VSECPRIM_EXCLUDE_BOUNDARY_VIOLATION_BY_REVIEW]

  \ID SBSW_VSECPRIM_ARRAY_WRITE_ACCESS_PASSED_BUFFER_FIXED_INDEX
    \DESCRIPTION    The function writes array elements using fixed indices. A pointer to the array is passed as
                    parameter. The API requires that the referenced array is of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_EXCLUDE_BOUNDARY_VIOLATION_BY_REVIEW]

  \ID SBSW_VSECPRIM_ARRAY_WRITE_ACCESS_PASSED_BUFFER_VARIABLE_INDEX_CHECK
    \DESCRIPTION    The function writes array elements using variable indices that are checked against the array size
                    before being applied. A pointer to the array is passed as parameter. The API requires that the
                    referenced array is of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_EXCLUDE_BOUNDARY_VIOLATION_BY_REVIEW]

  \ID SBSW_VSECPRIM_FCT_CALL_LOCAL_BUFFER
    \DESCRIPTION    The function passes a pointer referencing a locally defined buffer of known size to another function.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLEE_ENSURES_BUFFER_SIZE]

  \ID SBSW_VSECPRIM_FCT_CALL_LOCAL_BUFFER_FIXED_SIZE
    \DESCRIPTION    The function passes a pointer referencing a locally defined buffer of known size and its size to
                    another function. The passed buffer size is fixed.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLEE_ENSURES_PASSED_BUFFER_SIZE]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER
    \DESCRIPTION    The function passes a pointer referencing a buffer to another function. That passed pointer in
                    turn has been passed by the caller. The API requires that the referenced object is of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_AND_LOCAL_BUFFER
    \DESCRIPTION    The function passes a pointer referencing a buffer to another function. That passed pointer in
                    turn has been passed by the caller. The API requires that the referenced object is of valid size.
                    The function passes a pointer referencing a locally defined buffer of known size and its size to
                    another function.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_BUFFER_SIZE]

  \ID SBSW_VSECPRIM_FCT_CALL_P2CONSTPARAM_AND_LOCAL_BUFFER
    \DESCRIPTION    The function passes a pointer referencing a buffer to another function, where this parameter is
                    qualified as const. The passed pointer in turn has been passed by the caller. The API requires
                    that the referenced object is of valid size. The function passes a pointer referencing a locally
                    defined buffer of known size to the same function.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_BUFFER_SIZE]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_AND_P2CONSTPARAM
    \DESCRIPTION    The function passes a pointer referencing a buffer to another function. That passed pointer in
                    turn has been passed by the caller. The API requires that the referenced object is of valid size.
                    The function passes another pointer referencing a buffer to the same function.
                    The parameter for passing the pointer is qualified as "pointer to const".
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_BUFFER_SIZE]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SIZE
    \DESCRIPTION    The function passes a pointer referencing a buffer and its size to another function. The passed
                    buffer size is fixed. That passed pointer in turn has been passed by the caller. The API requires
                    that the referenced object is of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_PASSED_BUFFER_SIZE]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_VARIABLE_SIZE
    \DESCRIPTION    The function passes a pointer referencing a buffer and its size to another function. The passed
                    buffer size is variable. That passed pointer in turn has been passed by the caller. The API requires
                    that the referenced object is of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_PASSED_BUFFER_SIZE]
                       and:
                       The buffer to be written is at least of the size of one block,
                       The size of the written bytes is always equal or smaller than the block size, see [CM_VSECPRIM_BUFFER_USED_SMALLER_BLOCK_SIZE]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_VARIABLE_SIZE_CHECK
    \DESCRIPTION    The function passes a pointer referencing a buffer and its size to another function. The passed
                    buffer size is variable and it is checked that the size does not exceed the size of the passed buffer.
                    That passed pointer in  turn has been passed by the caller. The API requires
                    that the referenced object is of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_PASSED_BUFFER_SIZE]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SUBADDRESS
    \DESCRIPTION    The function passes a pointer referencing a buffer to another function. That passed pointer is a
                    fixed sub-address within the buffer passed by the caller. The API requires that the referenced object is
                    of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_VALID_SUBADDRESS]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SUBADDRESS_FIXED_SIZE
    \DESCRIPTION    The function passes a pointer referencing a buffer to another function. That passed pointer is a
                    fixed sub-address within the buffer passed by the caller. The passed buffer size is fixed. The API
                    requires that the referenced object is of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_PASSED_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_VALID_SUBADDRESS]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_VARIABLE_SUBADDRESS
    \DESCRIPTION    The function passes a pointer referencing a buffer to another function. That passed pointer is a
                    variable sub-address within the buffer passed by the caller. The API requires that the referenced object is
                    of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_VALID_SUBADDRESS]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_VARIABLE_SUBADDRESS_VARIABLE_SIZE
    \DESCRIPTION    The function passes a pointer referencing a buffer to another function. That passed pointer is a
                    variable sub-address within the buffer passed by the caller. The passed buffer size is variable.
                    The API requires that the referenced object is of valid size.
    \COUNTERMEASURE \N [CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_PASSED_BUFFER_SIZE] and [CM_VSECPRIM_CALLEE_ENSURES_VALID_SUBADDRESS]
                    and:
                    info->buffer is the size of one block  (e.g. actSIPHASH_BLOCK_SIZE, actGHASH_BLOCK_SIZE, actGCM_BLOCK_SIZE)
                    &info->buffer[info->buffer_used] is within info->buffer since info->buffer_used is always equal or smaller than the block size, see [CM_VSECPRIM_BUFFER_USED_SMALLER_BLOCK_SIZE]
                    the size of the buffer passed by &info->buffer[info->buffer_used] is (block size - info->buffer_used),
                    the size to be written (e.g. diff) is equal or smaller than (block size - info->buffer_used), see [CM_VSECPRIM_BUFFER_USED_SMALLER_BLOCK_SIZE]

  \ID SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM
    \DESCRIPTION    A pointer referencing a buffer is passed to another function. The corresponding parameter of the called function is qualified as "pointer to const".
    \COUNTERMEASURE \N Pointers qualified as "pointer to const" cannot be used for write access.

  \ID SBSW_VSECPRIM_FUNCTION_CALL_WITH_FUNCTION_POINTER
    \DESCRIPTION    An array of function pointers is accessed via a fixed index.
    \COUNTERMEASURE \N Code review verifies that only valid indices are used.

  \ID SBSW_VSECPRIM_ARRAY_WRITE_ACCESS_PASSED_BUFFER_FIXED_INDEX_SIPHASH_FINALIZE
    \DESCRIPTION    The function esl_finalizeSipHash writes to the object referenced by parameter 'messageMAC'.
                    It writes array elements using fixed indices.
    \COUNTERMEASURE \S The caller of function esl_finalizeSipHash must ensure that the pointer passed to the parameter 'messageMAC'
                       references a valid memory location and that the size of the array referenced by the parameter 'messageMAC'
                       is greater or equal to 8 bytes. [SMI-160485]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_GCM_ENCRYPT_DECRYPT_UPDATE
    \DESCRIPTION    The functions esl_updatePlaintextEncryptGCM and esl_updateCiphertextDecryptGCM write to the object referenced by parameter 'output'.
                    They pass the pointer given by 'output' to another function.
    \COUNTERMEASURE \S The caller of functions esl_updatePlaintextEncryptGCM and esl_updateCiphertextDecryptGCM must ensure that the pointer passed to
                       the parameter 'output' references a valid memory location and that the size of the array referenced by the
                       parameter 'output' is a multiple of the GCM block size (16 bytes) and greater than or equal to the size given by parameter 'inputLength'. [SMI-160486]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_GCM_ENCRYPT_DECRYPT_FINALIZE
    \DESCRIPTION    The functions esl_finalizeEncryptGCM and esl_finalizeDecryptGCM write to the object referenced by parameter 'output'.
                    They pass the pointer given by 'output' to another function.
    \COUNTERMEASURE \S The caller of functions esl_finalizeEncryptGCM and esl_finalizeDecryptGCM must ensure that the pointer passed to
                       the parameter 'output' references a valid memory location and that the size of the array referenced by the
                       parameter 'output' is greater or equal than the GCM block size (16 bytes). [SMI-160487]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_CMACAES128_FINALIZE
    \DESCRIPTION    The function esl_finalizeCMACAES128 writes to the object referenced by parameter 'messageCMAC'.
                    It passes the pointer given by 'messageCMAC' to another function.
    \COUNTERMEASURE \S The caller of functions esl_finalizeCMACAES128 must ensure that the pointer passed to
                       the parameter 'messageCMAC' references a valid memory location and that the size of the array referenced by the
                       parameter 'messageCMAC' is greater than or equal to the AES block size (16 bytes). [SMI-163627]

    \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_HMACSHA256_FINALIZE
    \DESCRIPTION    The function esl_finalizeHashMACSHA256 writes to the object referenced by parameter 'messageHashMAC'.
                    It passes the pointer given by 'messageHashMAC' to another function.
    \COUNTERMEASURE \S The caller of functions esl_finalizeHashMACSHA256 must ensure that the pointer passed to
                       the parameter 'messageHashMAC' references a valid memory location and that the size of the array referenced by the
                       parameter 'messageHashMAC' is greater than or equal to the SHA2-256 digest size (32 bytes). [SMI-552783]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_SHA_FINALIZE
    \DESCRIPTION    The functions
                      esl_finalizeSHA1
                      esl_finalizeSHA224
                      esl_finalizeSHA256
                      esl_finalizeSHA384
                      esl_finalizeSHA512
                      esl_finalizeSHA512_224
                      esl_finalizeSHA512_256
                    write to the object referenced by parameter 'messageDigest'.
                    They pass the pointer given by 'messageDigest' to another function.
    \COUNTERMEASURE \S The caller of functions
                        esl_finalizeSHA1
                        esl_finalizeSHA224
                        esl_finalizeSHA256
                        esl_finalizeSHA384
                        esl_finalizeSHA512
                        esl_finalizeSHA512_224
                        esl_finalizeSHA512_256
                       must ensure that the pointer passed to the parameter 'messageDigest' references a valid memory
                       location and that the size of the array referenced by the parameter 'messageDigest' is greater
                       than or equal to 20 (28/32/48/28/32/64) bytes for esl_finaleSHA1 (esl_finalizeSHA224/esl_finalizeSHA256/
                       esl_finalizeSHA384/esl_finalizeSHA512/esl_finalizeSHA512_224/esl_finalizeSHA512_256). [SMI-163628]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_RSAPSSSHA256_FINALIZE_HASH
    \DESCRIPTION    The functions
                     esl_finalizeHashSignRSASHA256_PSS
                     esl_finalizeHashVerifyRSASHA256_PSS
                       write to the object referenced by parameter 'messageDigest'.
                       They pass the pointer given by 'messageDigest' to another function.
    \COUNTERMEASURE \S The caller of functions
                        esl_finalizeHashSignRSASHA256_PSS
                        esl_finalizeHashVerifyRSASHA256_PSS
                       must ensure that the pointer passed to the parameter 'messageDigest' references a valid memory
                       location and that the size of the array referenced by the parameter 'messageDigest' is greater
                       than or equal to 32 bytes. [SMI-423463]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_RSAPSSSHA256_SALTEDHASH
    \DESCRIPTION    The function
                     esl_calcSaltedHashRSASHA256_PSS
                    writes to the object referenced by parameter 'saltedHash'.
                    It passes the pointer given by 'saltedHash' to another function.
    \COUNTERMEASURE \S The caller of function
                        esl_calcSaltedHashRSASHA256_PSS
                       must ensure that the pointer passed to the parameter 'saltedHash' references a valid memory
                       location and that the size of the array referenced by the parameter 'saltedHash' is greater
                       than or equal to 32 bytes. [SMI-423463]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_RSAPSSSHA256_MASK
    \DESCRIPTION    The function
                     esl_generateMaskMGF1RSASHA256_PSS
                    writes to the object referenced by parameter 'tempHash'.
                    It passes the pointer given by 'tempHash' to another function.
    \COUNTERMEASURE \S The caller of function
                        esl_generateMaskMGF1RSASHA256_PSS
                       must ensure that the pointer passed to the parameter 'tempHash' references a valid memory
                       location and that the size of the array referenced by the parameter 'tempHash' is greater
                       than or equal to 32 bytes. [SMI-423463]

  \ID SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_GENERATEKEY_ECP
    \DESCRIPTION    The function
                     esl_generateKeyEcP_prim
                    writes to the objects referenced by the parameters 'privateKey', 'publicKey_x' and 'publicKey_y'.
                    It passes the pointers given by 'privateKey', 'publicKey_x' and 'publicKey_y' to another function.
    \COUNTERMEASURE \S The user of MICROSAR Safe shall verify that the pointers privateKey, publicKey_x and publicKey_y
                       passed to the function
                        esl_generateKeyEcP_prim
                       reference valid memory locations and that the sizes of the arrays referenced by the parameters
                       privateKey, publicKey_x and publicKey_y are greater than or equal to the return values of
                        esl_getLengthOfEcPprivateKey(domain) for privateKey and
                        esl_getLengthOfEcPpublicKey_comp(domain) for publicKey_x and publicKey_y
                       in bytes, where domain is the ASN1 structure describing the  domain parameters of the underlying curve.
                       The maximally required buffer size is 32 byte, if ECP_MAX_KEY_SIZE = ECP_MAX_KEY_SIZE_256, and 48 byte,
                       if ECP_MAX_KEY_SIZE = ECP_MAX_KEY_SIZE_384. [SMI-455434]

SBSW_JUSTIFICATION_END */

/*

  \CM CM_VSECPRIM_EXCLUDE_BOUNDARY_VIOLATION_BY_REVIEW The write operations where a possible boundary violation could occur have been validated during the code review.

  \CM CM_VSECPRIM_EXCLUDE_BOUNDARY_VIOLATION_BY_RUNTIME_MEASURE Write operations where a possible boundary violation could occur are prevented by run-time measure.

  \CM CM_VSECPRIM_CALLER_ENSURES_BUFFER_SIZE The caller ensures that the pointer passed as parameter is valid and references an object of valid size.

  \CM CM_VSECPRIM_CALLEE_ENSURES_BUFFER_SIZE The callee ensures that the passed buffer is of valid size, i.e. that the size is as required by the called function.

  \CM CM_VSECPRIM_CALLEE_ENSURES_PASSED_BUFFER_SIZE The callee ensures that the passed buffer size does not exceed the size of the passed buffer.

  \CM CM_VSECPRIM_CALLEE_ENSURES_VALID_SUBADDRESS The callee ensures that the passed buffer referenced by the sub-address is of valid size, i.e. that it is fully within the buffer passed by the caller.

  \CM CM_VSECPRIM_BUFFER_USED_SMALLER_BLOCK_SIZE  Evaluation of all write accesses to info->buffer_used, proofing that info->buffer_used < BLOCK_SIZE
                                                  1.) In init and finalize functions:
                                                      info->buffer_used = 0u;
                                                  2.) In update functions:
                                                      I) diff = minimum(length, BLOCK_SIZE - info->buffer_used)
                                                          info->buffer_used += diff
                                                          --> info->buffer_used <= BLOCK_SIZE
                                                          A) If info->buffer_used < BLOCK_SIZE:
                                                            Update is finished
                                                            --> info->buffer_used < BLOCK_SIZE
                                                          B) If info->buffer_used == BLOCK_SIZE:
                                                            blocks = (length - diff) / BLOCK_SIZE
                                                            diff is as calculated previously
                                                            info->buffer_used = (length - (diff + (BLOCK_SIZE * blocks)))
                                                            info->buffer_used = length - (diff + (BLOCK_SIZE * blocks))
                                                                              = (length - diff) - ((length - diff) / BLOCK_SIZE ) * BLOCK_SIZE
                                                                              = (length - diff) % BLOCK_SIZE
                                                            --> info->buffer_used < BLOCK_SIZE

 */

/**********************************************************************************************************************
 *  COVERAGE JUSTIFICATIONS
 *********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

  \ID COV_VSECPRIM_GHASH_SPEED_UP
    \REASON This check always has the same result since the switch actGHASH_SPEED_UP is constantly defined to the value 1.
    \PREVENTION Covered by code review.

  \ID COV_VSECPRIM_CPLUSPLUS
    \REASON This check always results in FALSE since the switch __cplusplus is always undefined.
    \PREVENTION Covered by code review.

  \ID COV_VSECPRIM_NO_SAFE_CONFIG
    \REASON This algorithm or option must not be configured for building a safe library.
    \PREVENTION ELISA plug-in

  \ID COV_VSECPRIM_STD_VALUES
    \ACCEPT TX
    \ACCEPT XF
    \REASON This check can only be true if the parameter is not defined externally.
            This check can only be false if the parameter is defined externally.

  \ID COV_VSECPRIM_NOT_CONFIGURABLE
    \REASON This check always results in the same boolean value since the considered parameter is constantly defined internally.
    \PREVENTION Covered by code review.

  \ID COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT
    \ACCEPT X
    \REASON This else/default statements are required by misra but cannot be reached in code. The statement is captured by upper Api.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  FETA JUSTIFICATIONS
 *********************************************************************************************************************/
/* FETA_JUSTIFICATION_BEGIN

  \ID FETA_VSECPRIM_BOUNDARY_CHECK_BY_CALLER
    \DESCRIPTION Upper boundary is checked by caller.
    \COUNTERMEASURE \R [CM_VSECPRIM_UPPER_BOUNDARY_CALLER], [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND]

  \ID FETA_VSECPRIM_BOUNDARY_CHECK_BY_CALLER_PARAMETER
    \DESCRIPTION Upper boundary is checked by caller.
    \COUNTERMEASURE \R [CM_VSECPRIM_UPPER_BOUNDARY_CALLER], [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND_PARAMETER]

  \ID FETA_VSECPRIM_BOUNDARY_CHECK_BY_CALLER_PARAMETER_DECREASE
    \DESCRIPTION Upper boundary is checked by caller.
    \COUNTERMEASURE \R The loop's type of the counter variable is appropriate for the loop's type of upper bound value
                       and is decreased once within each single loop (strictly monotonically decreasing) until it
                       reaches a value that makes the loop stop without any occurrences of underflows. This is done by
                       a comparison used as loop termination condition. The loop's upper bound is passed to the
                       function as a parameter. Also, [CM_VSECPRIM_UPPER_BOUNDARY_CALLER] applies.

  \ID FETA_VSECPRIM_BOUNDARY_CHECK_BY_ESLIB_PARAMETER
    \DESCRIPTION Upper boundary is checked by esLib.
    \COUNTERMEASURE \R [CM_VSECPRIM_UPPER_BOUNDARY_ESLIB], [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND_PARAMETER]

  \ID FETA_VSECPRIM_UPPER_BOUNDARY_CHECKED_BY_CALLEE
    \DESCRIPTION Upper boundary is checked by callee.
    \COUNTERMEASURE \R [CM_VSECPRIM_UPPER_BOUNDARY_CALLEE], [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND]

  \ID FETA_VSECPRIM_UPPER_BOUNDARY_CHECKED_BY_CALLEE_DECREASE
    \DESCRIPTION Upper boundary is checked by callee.
    \COUNTERMEASURE \R [CM_VSECPRIM_UPPER_BOUNDARY_CALLEE], [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND_DECREASE]

  \ID FETA_VSECPRIM_UPPER_BOUNDARY_CHECKED_BY_CALLEE_PARAMETER
    \DESCRIPTION Upper boundary is checked by callee.
    \COUNTERMEASURE \R [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND_PARAMETER]

  \ID FETA_VSECPRIM_UPPER_BOUNDARY_LARGER_UINT32_MAX
    \DESCRIPTION Upper boundary in algorithm is specified to be larger than uint32_max.
    \COUNTERMEASURE \N An upper boundary cannot be checked. No action necessary.

  \ID FETA_VSECPRIM_ACTUTILITIES_COPY_CALL_WITH_FIXED_SIZE
    \DESCRIPTION According to FETA a loop may not terminate in functions
                 - actCpyBEtoU32(),
                 - actCpyLEtoU32(),
                 - actCpyU32toBE() and
                 - actCpyU32toLE().
                 In these functions, a for loop is used to copy data from a source to a target buffer.
                 The length of the data to be copied determines the number of iterations of the for loop and
                 is passed to the function as a parameter.
    \COUNTERMEASURE \N [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND] Furthermore, whenever the function is
                    called, the passed value is of fixed size and known at compile time. This is ensured by review.

  \ID FETA_VSECPRIM_ACTUTILITIES_MEM_COMPARE
    \DESCRIPTION According to FETA a loop may not terminate in function
                 - actMemcmp.
                 In this function, a for loop is used to compare data from a source and a target buffer.
                 The length of the data to be compared determines the number of iterations of the for loop and
                 is passed to the function as a parameter.
    \COUNTERMEASURE \N [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND] Furthermore, whenever the function is
                    called, the passed value is of fixed size and known at compile time. This is ensured by review.

  \ID FETA_VSECPRIM_ACTUTILITIES_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND
    \DESCRIPTION  According to FETA a loop may not terminate in functions
                  - actMemSet(),
                  - actMemcpy() and
                  - actXOR().
    \COUNTERMEASURE \N [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND]

  \ID FETA_VSECPRIM_BIGNUM_BOUND_LIMITED_BY_PREVIOUSLY_CHECKED_PARAMETER
    \DESCRIPTION According to FETA, a loop may not terminate in functions
                 - actBNCopy(),
                 - actBNSet(),
                 - actBNIsZero(),
                 - actBNCompare(),
                 - actBNSetOctetString(),
                 - actBNSetOctetStringROM(),
                 - actBNOctetString(),
                 - actBNAdd(),
                 - actBNDiv2(),
                 - actBNMontMul(),
                 - actBNMult(),
                 - actBNMulDigit(),
                 - actBNReduce() and
                 - actBNSub().
                The loop's bound is either passed to the function as a constant parameter or
                a static variable.
    \COUNTERMEASURE \N [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND] Furthermore, the value of
                    the bound is either given by curve parameters (curve prime, group order) of
                    elliptic curves or by the RSA modulus or derived from one of these values.
                    All of these values are compared to configured sizes before the above listed
                    functions are called (e.g. in actECInit). This is ensured by review.
                    Exception: Calltrees starting in actSPAKE2PPreambleCalc() use different values,
                    but the used values are fixed and known at compile time, too.

  \ID FETA_VSECPRIM_EC_REDUCTION_OF_POINT_COORDINATE_BY_GROUP_ORDER
    \DESCRIPTION According to FETA, a loop may not terminate in functions
                - actECReduceXModN()
                - actBNReduceSimple().
                In this function, the x-coordinate of a point, x, on the elliptic curve is to be
                reduced by n, the fixed group order. It holds that n < x < p, where p is the fixed curve prime.
                The function subtracts n from x as long as the result is still larger than or equal to n.
    \COUNTERMEASURE \N In each iteration of the while loop, x is reduced by the positive value n, thus
                    eventually, x will be less than n.
                    At most (p-n)/n subtractions and thus iterations of the while loop are necessary,
                    since x < p and it holds that p - ((p-n)/n)*n = n. p and n are compared to configured
                    sizes before actECReduceXModN() is called (e.g. in actECInit).

  \ID FETA_VSECPRIM_ECDSA_SIGNATURE_GENERATION
    \DESCRIPTION According to FETA, a loop may not terminate in function
                - actECDSAsp().
                This function computes a signature according to the ECDSA specification. The signature
                consists of two components, r and s. If one of the two components is 0, the
                computation shall start over. This is realized in a while-loop.
    \COUNTERMEASURE \N The while-loop is endless by intention, in order to comply with the ECDSA specification.
                    This is documented in the CDD and in the TechRef. There, the ECDSA specification is
                    referenced, too.

  \ID FETA_VSECPRIM_ADD_UNTIL_REMAINDER_ZERO
    \DESCRIPTION According to FETA, a loop may not terminate in function
                - actECPMultG().
                This loop increments a variable i until the termination condition i mod x = 0 is reached.
    \COUNTERMEASURE \N i and x are of the same type. Thus, at most x iterations of the loop are required
                    before i mod x = 0 is reached.
                    Note: The loop could be replaced by a for-loop with x as upper bound, which would not
                    require a FETA justification. However, this would result in a condition 'iterator < x',
                    which is not testable with standard curves. If vSecPrim is used in combination with LibCv,
                    x = 2 or x = 3.

  \ID FETA_VSECPRIM_BARRETT_REDUCTION
    \DESCRIPTION According to FETA, a loop may not terminate in function
                - act25519_reduce().
                - act448_reduce().
                In this function, n is to be subtracted from an estimate of c = a mod n repeatedly,
                where a is a runtime parameter and n is a fixed curve parameter (prime p or order q).
                This is a step of the so-called Barrett reduction method.
    \COUNTERMEASURE \N In each iteration of the while loop, a is reduced by the positive value n, thus
                    eventually, a will be less than n.
                    Since all input values a for this function fulfil a < n^2, which is ensured by review,
                    one subtraction is sufficient to reach a < n. However, in order to account for input
                    values up to n, more subtractions are provided.

  \ID FETA_VSECPRIM_MODULAR_REDUCTION
    \DESCRIPTION According to FETA, a loop may not terminate in function
                 actBNReduceRefineQuotientEstimate() which belongs to actBNReduce(), which is adapted from
                 the Handbook of Cryptography '97 -  Algorithm 14.20.
                 In this function, 1 is to be subtracted from an estimate of a digit of the quotient (qDig),
                 as long as the estimation for qDig is too big (See Step 3.2 in Algorithm 14.20):
                 qDig*(b_t*b + b_(t-1)) > (a_i*base^2+a_(i-1)*base+a_(i-2)).
    \COUNTERMEASURE \N All digits of a and b are constant, the only factor that changes is qDig, which gets smaller
                    with each iteration. At latest when qDig is zero, the while loop terminates.
                    According to the Handbook of Cryptography, this step is never repeated more than twice, since
                    we do a normalisation before (See Note 14.23).

  \ID FETA_VSECPRIM_DEFAULT_FOR_LOOP
    \DESCRIPTION According to FETA, an increasing loop may not terminate.
    \COUNTERMEASURE \N [CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND]

  \ID FETA_VSECPRIM_WHILE_LOOP
    \DESCRIPTION According to FETA, a while loop may not terminate.
    \COUNTERMEASURE \N The while loop's termination condition can be reached without the occurrence of over-
                    or underflows. In each iteration, the iterator is strictly monotonically increased or decreased,
                    respectively. Thus, the maximal number of iterations of the loop is determined by the size
                    of the type of the iterator.
                    Potentially in addition to that, break statement are used to terminate the loop sooner.

  \ID FETA_VSECPRIM_ACTCMACAES_WHILE_LOOP
    \DESCRIPTION According to FETA, a while loop may not terminate in function
                - actCMACAESProcess().
    \COUNTERMEASURE \N This loop has two termination conditions which have to be met both:
                       (rest > 0u) || (processLastBlock == TRUE). This function is called in two use cases:
                       1) During an CMAC update: In this use case, processLastBlock is always set to FALSE. rest is
                          reduced until it reaches the value 0.
                       2) During the finish step: In this use case, processLastBlock is set to TRUE and will be set
                          to FALSE during the last iteration. This step uses the subkey as input which is specified
                          to have a size of 16 bytes. Therefore, the value of rest is set to 16 before the loop and
                          is decreased to 0 during the iterations.
                       In both cases, rest can never underflow as the value of rest itself is the maximum value which
                       is subtracted.

  \ID FETA_VSECPRIM_ACTKECCACKF_PERMUTATION_WHILE_LOOP
    \DESCRIPTION According to FETA, a while loop may not terminate in function
                - KECCACKf().
    \COUNTERMEASURE \N The while loop traverses over the array pi_lane[] in 24 iterations. By passing through the array,
                       it is ensured that the termination condition of the loop is met and that the variable src has the
                       value 1 after the last pass. For the order of the iterations, see the definition of pi_lane[] in
                       the file actKECCACKf-64.h.

  \ID FETA_VSECPRIM_ACTKECCACKF_ABSORB_SQUEEZE_WHILE_LOOP
    \DESCRIPTION According to FETA, a while loop may not terminate in functions
                - actKECCAKcAbsorb() and
                - actKECCAKcSqueeze().
    \COUNTERMEASURE \N The loop contains three branches. In each branch, the value of the counting variable len/size is
                       decreased until the terminating condition of the loop is reached. The counting variable can never
                       underflow as each branch implements an underflow check and the maximum value which is subtracted
                       from len/size is the value of len/size itself.

FETA_JUSTIFICATION_END */

/*

  \CM CM_VSECPRIM_UPPER_BOUNDARY_CALLER Upper boundary is ensured by caller. No check necessary by callee.

  \CM CM_VSECPRIM_UPPER_BOUNDARY_CALLEE Upper boundary is ensured by callee. Callee compares or sets boundary to fixed value which is known at compile time.

  \CM CM_VSECPRIM_UPPER_BOUNDARY_ESLIB Upper boundary is ensured by esLib in a previous check. No check necessary by callee.

  \CM CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND The here applied loop uses as upper bound a variable that remains unchanged during loop execution.
                                            The loop's type of the counter variable is appropriate for the loop's type of upper bound value and is increased once within each single loop
                                            (strictly monotonically increasing) until it reaches a value that makes the loop stop without any occurrences of overflows. This is done by a
                                            comparison used as loop termination condition. The loop's bound is of fixed size. This is ensured by review.

  \CM CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND_DECREASE The here applied loop uses as lower bound a fixed value.
                                                     The loop's type of the counter variable is appropriate for the loop's type of lower bound value and is decreased once within each single loop
                                                     (strictly monotonically decreasing) until it reaches a value that makes the loop stop without any occurrences of underflows. This is done by a
                                                     comparison used as loop termination condition. The loop's bound is of fixed size. This is ensured by review.

  \CM CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND_PARAMETER The here applied loop uses as upper bound a variable that remains unchanged during loop execution.
                                                      The loop's type of the counter variable is appropriate for the loop's type of upper bound value and is increased once within each single loop
                                                      (strictly monotonically increasing) until it reaches a value that makes the loop stop without any occurrences of overflows. This is done by a
                                                      comparison used as loop termination condition. The loop's upper bound is passed to the function as a parameter.

  \CM CM_VSECPRIM_FOR_LOOP_WITH_FIXED_BOUND_PARAMETER_DECREASE The loop's type of the counter variable is appropriate for the loop's type of upper bound value and is decreased once within each single loop
                                                               (strictly monotonically decreasing) until it reaches a value that makes the loop stop without any occurrences of underflows. This is done by a
                                                               comparison used as loop termination condition. The loop's upper bound is passed to the function as a parameter.

 */

/**********************************************************************************************************************
 *  END OF FILE: vSecPrim.c
 *********************************************************************************************************************/
