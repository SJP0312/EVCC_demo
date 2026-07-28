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
/**        \file  Exi_Types.h
 *        \brief  Efficient XML Interchange types header file
 *
 *      \details  Vector static code types header file for the Efficient XML Interchange module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file Exi.h.
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_Exi_1.1_0857 */ /* [L] Number of macro definitions exceeds 1024 - program is non-conforming. */

#if !defined (EXI_TYPES_H)                                                                                              /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_Cfg.h"

#if EXI_ENABLE_PBUF_SUPPORT == STD_ON
#include "IpBase_Types.h"
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  Exi_BT_False = FALSE, /* Value is FALSE. */
  Exi_BT_True = TRUE    /* Value is TRUE. */
} Exi_BooleanType;

#if defined(PLATFORM_SUPPORT_SINT64_UINT64)
#define Exi_UInt64_Available /* unsigned 64 bit type */
typedef uint64 Exi_UInt64;
#define Exi_SInt64_Available /* signed 64 bit type */
typedef sint64 Exi_SInt64;
#else
  /* CPU: no 64 bit support available */
typedef struct
{
  uint32 HiWord;
  uint32 LoWord;
} Exi_UInt64Type;
typedef struct
{
  sint32 HiWord;
  uint32 LoWord;
} Exi_SInt64Type;
typedef Exi_UInt64Type Exi_UInt64;
typedef Exi_SInt64Type Exi_SInt64;
#endif

#if defined (EXI_MAX_NUM_BYTES_BIGINT)
typedef struct
{
  uint16 Length;
  boolean IsNegative; /* In case this is TRUE, Value[] will be a negative number,
                               * this flag is the only indication that the value is negative.
                               * E.g. Value: {0x01, 0x01} -> 257
                               * IsNegative: FALSE -> Real value:  257
                               * IsNegative:  TRUE -> Real value: -257
                               */
  uint8 Value[EXI_MAX_NUM_BYTES_BIGINT];
} Exi_BigIntType;
#endif

typedef uint8 Exi_ConfigType;



/* this type defines the maximum number of bits that can be read or written with a single call to Exi_VBSReadBits or Exi_VBSWriteBits. */
typedef uint32 Exi_BitBufType;

/* Exi_ReturnType */
typedef uint8  Exi_ReturnType;
#define EXI_E_OK                         0U /* Finished successfully */
#define EXI_E_NOT_OK                     1U /* undefined error */
#define EXI_E_INV_HEADER              0x10U /* invalid exi header */
#define EXI_E_EOS                     0x11U /* end of exi stream buffer */
#define EXI_E_INT_OVERFLOW            0x12U /* decoded integer too big for target buffer */
#define EXI_E_ARR_OVERFLOW            0x13U /* decoded array too big for target array */
#define EXI_E_STRING_TABLE_LOCAL_HIT  0x14U /* string empty, must be in local table */
#define EXI_E_STRING_TABLE_GLOBAL_HIT 0x15U /* string empty, must be in global table */
#define EXI_E_INV_EVENT_CODE          0x16U /* invalid/unknown event code */
#define EXI_E_BUFFER_SIZE             0x17U /* target buffer to small */
#define EXI_E_DISABLED_FEATURE        0x18U /* feature disabled */
#define EXI_E_LIST_TO_LONG            0x19U /* To many elements in a list or last NextPtr not NULL */
#define EXI_E_ENUM_OUT_OF_RANGE       0x1AU /* Enumaration value is out of range */
#define EXI_E_INV_STRUCT_POINTER      0x1BU /* Invalid pointer, this may happen if a flag is 1 but the element is NULL_PTR */
#define EXI_E_INV_CHOICE_SELECTION    0x1CU /* Choice element selection is invalid, multiple flags are set */
#define EXI_E_INCONSISTEN_PBUF        0x1DU /* The provided PBuf is not consistent regarding its length information */
#define EXI_E_ELEMENT_NOT_AVAILABLE   0x1EU /* Element to process is not availalbe because it is not relevant */
#define EXI_E_PARAMETER_CHECK_FAILED  0x1FU /* Element to process is not availalbe because it is not relevant */

typedef uint8 Exi_NamespaceIdType; /* namespace identifier */
typedef uint16 Exi_RootElementIdType; /* message type identifier */


typedef struct
{
  /* position in buffer (encoding process) */
  uint8                                           BitPos;  /* bit position in current byte (0-7, 0 = msb) */
  uint32                                          BytePos; /* byte position in exi stream buffer segment */

  /* EXI internal data */
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON) /* Data elements are duplicated in different sort order, to be more memory efficient. */
  P2VAR(IpBase_PbufType, AUTOMATIC, EXI_APPL_VAR) PBufPtr; /* buffer segments of underlying ring-buffer */
  uint32                                          PBufProcessedElementBytes; /* Processed bytes of all PBuf segments (including start offset) */
  uint8                                           PBufIdx; /* current buffer segment */
  uint32                                          StartOffset;  /* Buffer start offset, required to calculate stream length */
#else
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR)           BufPtr;  /* exi stream buffer */
  uint32                                          BufLen;  /* exi stream buffer length */
  uint32                                          StartOffset;  /* Buffer start offset, required to calculate stream length */
#endif

#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
  /* Simple TX streaming relevant data */
  Exi_BooleanType                                 WritingToBufferIsActive;
  uint32                                          StartWriteAtBytePos; /* Start writing at stream byte position, skip writing bytes until this position */
  uint32                                          OverallStreamBytePos; /* Position in the current EXI stream */
  Exi_BooleanType                                 CalculateStreamLength; /* Is enabled in case the user wants to encode the first segment and calculate the stream length at once */
#endif

  Exi_ReturnType                                  StatusCode; /* this status will be set in case an error was detected */

  Exi_BooleanType                                 EERequired; /* TRUE when calling function needs to encode the next EE tag */

  /* External data, may be used by the application */
  uint32                                          TotalStreamLength; /* EXI stream length of the encoded stream, valid after finalize */
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
  /* Simple TX streaming relevant data */
  uint32                                          CurrentStreamSegmentLen; /* Length of the written segment */
  Exi_BooleanType                                 StreamComplete; /* TRUE in case this was the last segment of the stream */
#endif

} Exi_BSEncodeWorkspaceType;

typedef struct
{
  P2CONST(uint8, AUTOMATIC, EXI_APPL_DATA) StoragePtr;    /* pointer to the message that will be encoded */
  Exi_RootElementIdType                    RootElementId; /* message type identifier */
} Exi_EncoderInputDataType;

typedef struct
{
  Exi_BSEncodeWorkspaceType EncWs;
  Exi_EncoderInputDataType  InputData;
} Exi_EncodeWorkspaceType; /* public type used by exi users */

typedef struct
{
  uint8 ComplexDeviationLevel; /* count deviations levels for multi-complex deviations */
  uint32 ComplexGenericElementsCount; /* count the number of elements inside complex deviation */
  Exi_BooleanType ElementIndexRequired;/* TRUE when calling function needs to decode the index of previous element in complex type */
  Exi_BooleanType ElementContentEERequired;/*  TRUE when calling function needs to decode the next EE tag in deviation content */
  Exi_BooleanType IsAttribute;/*  TRUE when calling function needs to decode an attribute in deviation content */
  Exi_BooleanType DeviationOccur; /*  TRUE when at least one deviation is found in the stream */
} Exi_DecodeDeviationWorkspaceType; /* public type used by exi users */

typedef struct
{
  Exi_DecodeDeviationWorkspaceType                   DeviationWs;

  /* buffer */
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  P2CONST(IpBase_PbufType, AUTOMATIC, EXI_APPL_DATA) PBufPtr; /* buffer segments of underlying ring-buffer */
  uint8                                              PBufIdx; /* current buffer segment */
  uint32                                             PBufProcessedElementBytes; /* Processed bytes of all PBuf segments (including start offset) */
#else
  P2CONST(uint8, AUTOMATIC, EXI_APPL_DATA)           BufPtr;  /* exi stream buffer */
  uint32                                             BufLen;  /* exi stream buffer length */
#endif

  /* position in buffer (decoding process) */
  uint32                                             BytePos; /* byte position in exi stream buffer segment */
  uint8                                              BitPos;  /* bit position in current byte (0-7, 0 = msb)  */

  uint32                                             TotalStreamLength; /* EXI stream length of the decoded stream, valid after encode is complete */
  uint32                                             StartOffset;  /* Buffer start offset, required to calculate stream length */

  Exi_ReturnType                                     StatusCode;  /* this status will be set in case an error was detected */

  Exi_BooleanType                                    EERequired; /* TRUE when calling function needs to encode the next EE tag */

} Exi_BSDecodeWorkspaceType;

typedef struct
{
  P2VAR(uint8, AUTOMATIC, EXI_APPL_DATA)    BufferPtr;    /* Location of the buffer where memory shall be allocated. */
  uint32                                    BufferSize;   /* Size of the buffer where memory shall be allocated. */
  uint32                                    BufferOffset; /* Buffer index where no data has been written yet. */

} Exi_MemAllocWorkspaceType;

typedef struct
{
  Exi_MemAllocWorkspaceType                MemAllocWs;    /* workspace that contains buffer parameters for the decoded message */
  Exi_RootElementIdType                    SchemaSetId;   /* schema set identifier */
  Exi_RootElementIdType                    RootElementId; /* message type identifier */

} Exi_DecoderOutputDataType;

typedef struct
{

  Exi_BSDecodeWorkspaceType DecWs;
  Exi_DecoderOutputDataType OutputData;

} Exi_DecodeWorkspaceType; /* public type used by exi users */

typedef unsigned int Exi_BitType;
typedef void (*Exi_EncoderFctType)(Exi_EncodeWorkspaceType* EncWsPtr);
typedef void (*Exi_DecoderFctType)(Exi_DecodeWorkspaceType* DecWsPtr);


typedef enum
{
  EXI_BS_SSC_NO_DET_CALL = 0U,
  EXI_BS_SSC_CALL_DET_ALLWAYS = 1U,
  EXI_BS_SSC_CALL_DET_ON_CHANGE = 2U
} Exi_BSSetStatusCodeDetType;



#endif /* EXI_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_Types.h
 *********************************************************************************************************************/
