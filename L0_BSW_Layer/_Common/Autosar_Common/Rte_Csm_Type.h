/*
********************************************************************************
*
*  File name:    Rte_Csm_Type.h
*
*  Copyright    Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 1.0
*  Author/Date : jia_feng/2020.03.02
*  Change: New
*  Cause: New
********************************************************************************
*  Version: 1.0
*  Author/Date : jia_feng/2020.03.02
*  Change: New
*  Cause: New
********************************************************************************
*  Version: 3.0
*  Author/Date: NiXM/2023.03.08
*  Change: Add new structure due to interaction with RTE.
*  Cause: Optimization
********************************************************************************
*/

#ifndef RTE_CSM_TYPE_H_
#define RTE_CSM_TYPE_H_

/*
********************************************************************************
* Includes
********************************************************************************
*/
#include "Std_Types.h"

/*
*******************************************************************************
*    Global Macros
*******************************************************************************
*/
/* Csm module specific return values for use in Std_ReturnType that could occur on async. */
#define E_SMALL_BUFFER                  0x02U
#define E_ENTROPY_EXHAUSTION            0x03U
#define E_KEY_READ_FAIL                 0x04U
#define E_KEY_NOT_AVAILABLE             0x05U
#define E_KEY_NOT_VALID                 0x06U
#define E_JOB_CANCELED                  0x07U
#define E_KEY_EMPTY                     0x08U

/*
*******************************************************************************
*    Global Types
*******************************************************************************
*/
#ifndef Rte_TypeDef_Csm_ResultType
#define Rte_TypeDef_Csm_ResultType
typedef uint8 Csm_ResultType;
#endif

#ifndef Rte_TypeDef_Crypto_ResultType
#define Rte_TypeDef_Crypto_ResultType
typedef enum
{
    RES_E_OK = 0x00U,
    RES_E_NOT_OK,
    RES_CRYPTO_E_BUSY,
    RES_CRYPTO_E_ENTROPY_EXHAUSTED = 0x04U,
    RES_CRYPTO_E_KEY_READ_FAIL = 0x06U,
    RES_CRYPTO_E_KEY_WRITE_FAIL,
    RES_CRYPTO_E_KEY_NOT_AVAILABLE,
    RES_CRYPTO_E_KEY_NOT_VALID,
    RES_CRYPTO_E_KEY_SIZE_MISMATCH,
    RES_CRYPTO_E_JOB_CANCELED = 0x0CU,
    RES_CRYPTO_E_KEY_EMPTY
}Crypto_ResultType;
#endif

#ifndef Rte_TypeDef_Crypto_OperationModeType
#define Rte_TypeDef_Crypto_OperationModeType
typedef enum Crypto_OperationModeTypeS
{
    CRYPTO_OPERATIONMODE_IDLE = 0x00U,              /* Operation Mode is "Idle". */
    CRYPTO_OPERATIONMODE_START = 0x01U,             /* Operation Mode is "Start".
                                                       The job's state shall be reset,
                                                       i.e. previous input data and intermediate results shall be deleted. */
    CRYPTO_OPERATIONMODE_UPDATE,                    /* Operation Mode is "Update". Used to calculate intermediate results. */
    CRYPTO_OPERATIONMODE_STREAMSTART,               /* Operation Mode is "Stream Start". Mixture of "Start" and "Update". Used for streaming.*/
    CRYPTO_OPERATIONMODE_FINISH,                    /* Operation Mode is "Finish". The calculations shall be finalized. */
    CRYPTO_OPERATIONMODE_ERROR = 0x05U,             /* If Operation Mode is "Start" and "Finish" only,Return E_NOT_OK */
    CRYPTO_OPERATIONMODE_SINGLECALL = 0x07U,        /* Operation Mode is "Single Call". Mixture of "Start", "Update" and "Finish". */
    CRYPTO_OPERATIONMODE_SAVE_CONTEXT = 0x08U,      /* Operation mode is "Save workspace context". Context data shall be provided by the
                                                       crypto driver to the application.*/
    CRYPTO_OPERATIONMODE_RESTORE_CONTEXT = 0x10U    /* Operation mode is "Restore workspace context". Application provides the context data
                                                       that was previously stored and the crypto driver shall restore the internal workspace.*/
}Crypto_OperationModeType;
#endif

#ifndef Rte_TypeDef_Crypto_VerifyResultType
#define Rte_TypeDef_Crypto_VerifyResultType
typedef enum Crypto_VerifyResultTypeS
{
    CRYPTO_E_VER_OK = 0x00U,                        /* The result of the verification is "true",
                                                       i.e. the two compared elements are identical.
                                                       This return code shall be given as value "0" */
    CRYPTO_E_VER_NOT_OK                             /* The result of the verification is "false",
                                                       i.e. the two compared elements are not identical.
                                                       This return code shall be given as value "1". */
}Crypto_VerifyResultType;
#endif

#ifndef Rte_TypeDef_Csm_CbkServiceOutputType
#define Rte_TypeDef_Csm_CbkServiceOutputType
typedef struct
{
    uint8* outputPtr;                               /* Pointer to the output data. */
    uint32* outputLengthPtr;                        /* Holds a pointer to a memory location containing the output length in bytes. */
    uint8* secondaryOutputPtr;                      /* Pointer to the secondary output data. */
    uint32* secondaryOutputLengthPtr;               /* Holds a pointer to a memory location containing the secondary output length in bytes. */
    Crypto_VerifyResultType* verifyPtr;             /* Output pointer to a memory location holding a Crypto_VerifyResultType */
}Csm_CbkServiceOutputType;
#endif

#ifndef Rte_TypeDef_Crypto_KeyStatusType
#define Rte_TypeDef_Crypto_KeyStatusType
typedef enum
{
    CRYPTO_KEYSTATUS_INVALID = 0x00U,               /* The status of the key is invalid. */
    CRYPTO_KEYSTATUS_VALID   = 0x01U                /* The status of the key is valid. */
}Crypto_KeyStatusType;

#endif

/*
*******************************************************************************
*    Global variable
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Constants
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Functions
*******************************************************************************
*/

#endif
