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
/**        \file  Exi_BSDecoder.h
 *        \brief  Efficient XML Interchange basic decoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component basic decoder.
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

#if !defined (EXI_BS_DECODER_H)                                                                                         /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_BS_DECODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_Types.h"
#include "Exi_SchemaDecoder.h"
#include "Exi_Lcfg.h"
#include "Exi_Priv.h"

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Exi_VBSDecodeInitWorkspace()
 **********************************************************************************************************************/
/*! \brief         Initialize an EXI bitstream decoding workspace.
 *  \details       Initialize an EXI bitstream decoding workspace.
 *  \param[in]     DecWsPtr   EXI bitstream decoding workspace
 *  \param[in]     PBufPtr    buffer contining the binary data to decode
 *  \param[in]     BufPtr     buffer contining the binary data to decode
 *  \param[in]     BufLen     length of the data in BufPtr in bytes
 *  \param[in]     ByteOffset offset in the input buffer
 *  \pre           -
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, EXI_CODE) Exi_VBSDecodeInitWorkspace(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  P2CONST(IpBase_PbufType, AUTOMATIC, EXI_APPL_VAR) PBufPtr,
#else
  P2CONST(uint8, AUTOMATIC, EXI_APPL_VAR) BufPtr,
  uint32 BufLen,
#endif
  uint32 ByteOffset
);

/**********************************************************************************************************************
 *  Exi_VBSDecodeSkipBits()
 **********************************************************************************************************************/
/*! \brief         Skip N bits of the exi stream
 *  \details       Skip N bits of the exi stream
 *  \param[in]     DecWsPtr   EXI bitstream decoding workspace
 *  \param[in]     BitCount   number of bits to skip
 *  \retrun        number of bits skipped. This value may be less than BitCount if the end of the stream buffer has been
 *                 reached. In this case the function must be called again with the remaining bit count.
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(uint32, EXI_CODE) Exi_VBSDecodeSkipBits(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint32 BitCount);

/**********************************************************************************************************************
 *  Exi_VBSDecodeGetWorkspaceBitPos()
 **********************************************************************************************************************/
/*! \brief         Get the bit position in the EXI stream of the workspace
 *  \details       Get the bit position in the EXI stream of the workspace
 *  \param[in]     DecWsPtr         EXI bitstream decoding workspace
 *  \retrun        Current bit position in the EXI stream
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(uint32, EXI_CODE) Exi_VBSDecodeGetWorkspaceBitPos(
  P2CONST(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_DATA) DecWsPtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeSetWorkspaceBitPos()
 **********************************************************************************************************************/
/*! \brief         Set a new bit position in the EXI stream to the workspace
 *  \details       Set a new bit position in the EXI stream to the workspace
 *  \param[in]     DecWsPtr         EXI bitstream decoding workspace
 *  \param[in]     BitPos           New bit position in the stream
 *  \retrun        New bit position for checks
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(uint32, EXI_CODE) Exi_VBSDecodeSetWorkspaceBitPos(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint32 BitPos);

/**********************************************************************************************************************
 *  Exi_VBSReadHeader()
 **********************************************************************************************************************/
/*! \brief         Read one-byte exi header
 *  \details       Read one-byte exi header
 *  \param[in]     DecWsPtr         EXI bitstream decoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSReadHeader(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr);

/**********************************************************************************************************************
 *  Exi_VBSReadBits()
 **********************************************************************************************************************/
/*! \brief         Read an arbitrary number of bits form an EXI bitstream
 *  \details       Read an arbitrary number of bits form an EXI bitstream
 *  \param[in]     DecWsPtr   EXI bitstream decoding workspace
 *  \param[in,out] BitBufPtr  pointer to an integer buffer. The bits read from the EXI stream will be left shifted
 *                 into the buffer. If the buffer contains already data this data will be shifted to the left by
 *                 up to BitCount bits.
 *  \param[in]     BitCount   number of bits to read from the EXI stream
 *  \return        number of bits read. This value may be less than BitCount if the end of the stream buffer has been
 *                 reached. In this case the StatusCode EXI_E_EOS was set and decoding is considered to be failed.
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(uint8, EXI_CODE) Exi_VBSReadBits(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BitBufType, AUTOMATIC, EXI_APPL_VAR) BitBufPtr,
  uint8 BitCount);

/**********************************************************************************************************************
 *  Exi_VBSDecodeBytes()
 **********************************************************************************************************************/
/*! \brief         decode length prefixed byte array from exi stream
 *  \details       decode length prefixed byte array from exi stream
 *  \param[in]     DecWsPtr             EXI bitstream decoding workspace
 *  \param[out]    BufPtr               target buffer for the byte array
 *  \param[in,out] BufLenPtr            in: target buffer length
 *                                      out: used target buffer length
 *  \param[in]     MaxLengthRestricted  True: Indicate error if byte length exceeds buffer length
 *                                      False: Truncate bytes that exceed buffer length
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeBytes(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) BufPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) BufLenPtr,
  Exi_BooleanType MaxLengthRestricted);

/**********************************************************************************************************************
 *  Exi_VBSDecodeBool()
 **********************************************************************************************************************/
/*! \brief         decode boolean value
 *  \details       decode boolean value
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded boolean value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeBool(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(boolean, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeInt8()
 **********************************************************************************************************************/
/*! \brief         decode integer value into sint8
 *  \details       decode integer value into sint8
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded integer value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeInt8(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(sint8, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeInt16()
 **********************************************************************************************************************/
/*! \brief         decode integer value into sint16
 *  \details       decode integer value into sint16
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded integer value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeInt16(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(sint16, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeInt32()
 **********************************************************************************************************************/
/*! \brief         decode integer value into sint32
 *  \details       decode integer value into sint32
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded integer value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeInt32(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(sint32, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeInt64()
 **********************************************************************************************************************/
/*! \brief         decode integer value into sint64
 *  \details       decode integer value into sint64
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded integer value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeInt64(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_SInt64, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeBigInt()
 **********************************************************************************************************************/
/*! \brief         decode big integer value into Exi_BigIntType structure
 *  \details       decode big integer value into Exi_BigIntType structure
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded integer value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeBigInt(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BigIntType, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeUInt()
 **********************************************************************************************************************/
/*! \brief         decode unsigned integer value into uint32
 *  \details       decode unsigned integer value into uint32
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeUInt(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BitBufType, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeUInt8()
 **********************************************************************************************************************/
/*! \brief         decode unsigned integer value into uint8
 *  \details       decode unsigned integer value into uint8
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeUInt8(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeUInt16()
 **********************************************************************************************************************/
/*! \brief         decode unsigned integer value into uint16
 *  \details       decode unsigned integer value into uint16
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeUInt16(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeUInt32()
 **********************************************************************************************************************/
/*! \brief         decode unsigned integer value into uint32
 *  \details       decode unsigned integer value into uint32
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeUInt32(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint32, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeUInt64()
 **********************************************************************************************************************/
/*! \brief         decode unsigned integer value into uint64
 *  \details       decode unsigned integer value into uint64
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    ValuePtr           decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeUInt64(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_UInt64, AUTOMATIC, EXI_APPL_VAR) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeUIntN()
 **********************************************************************************************************************/
/*! \brief         decode n bit unsigned integer value
 *  \details       decode n bit unsigned integer value
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    BitBufPtr          Pointer the buffer where the bits shall be copied to
 *  \param[out]    BitCount           Number of bits that shall be decoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeUIntN(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BitBufType, AUTOMATIC, EXI_APPL_VAR) BitBufPtr,
  uint8 BitCount);

/**********************************************************************************************************************
 *  Exi_VBSDecodeStringOnly()
 **********************************************************************************************************************/
/*! \brief         Decode a string with exactly StrLen characters
 *  \details       Decode a string with exactly StrLen characters
 *  \param[in]     DecWsPtr             EXI bitstream decoding workspace
 *  \param[out]    StrBufPtr            buffer to which the characters are copied
 *  \param[in,out] StrBufLenPtr         maximum number of characters that fit into the buffer.
 *                                      when the function returns the number of actually written characters will be stored
 *                                      here.
 *  \param[in]     StrLen               number of characters to read
 *  \param[in]     MaxLengthRestricted  True: Indicate error if byte length exceeds buffer length
 *                                      False: Truncate bytes that exceed buffer length
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeStringOnly(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) StrBufLenPtr,
  uint16 StrLen,
  Exi_BooleanType MaxLengthRestricted);

/**********************************************************************************************************************
 *  Exi_VBSDecodeString()
 **********************************************************************************************************************/
/*! \brief         Decode string with preceding length information
 *  \details       Decode string with preceding length information
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    StrBufPtr          buffer to which the characters are copied
 *  \param[in,out] StrBufLenPtr       maximum number of characters that fit into the buffer.
 *                                    when the function returns the number of actually written charaters will be stored
 *                                    here.
 *  \param[in]     StrLen             number of characters to read
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeString(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) StrBufLenPtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeStringValue()
 **********************************************************************************************************************/
/*! \brief         Decode string with preceding length information (length - 2)
 *  \details       Decode string with preceding length information (length - 2)
 *  \param[in]     DecWsPtr             EXI bitstream decoding workspace
 *  \param[out]    StrBufPtr            buffer to which the characters are copied
 *  \param[in,out] StrBufLenPtr         maximum number of characters that fit into the buffer.
 *                                      when the function returns the number of actually written charaters will be stored
 *                                      here.
 *  \param[in]     StrLen               number of characters to read
 *  \param[in]     MaxLengthRestricted  True: Indicate error if byte length exceeds buffer length
 *                                      False: Truncate bytes that exceed buffer length
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeStringValue(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) StrBufLenPtr,
  Exi_BooleanType MaxLengthRestricted);

/**********************************************************************************************************************
 *  Exi_VBSDecodeQName()
 **********************************************************************************************************************/
/*! \brief         Decode QName with preceding length information (length - 1)
 *  \details       Decode QName with preceding length information (length - 1)
 *  \param[in]     DecWsPtr           EXI bitstream decoding workspace
 *  \param[out]    StrBufPtr          buffer to which the characters are copied
 *  \param[in,out] StrBufLenPtr       maximum number of characters that fit into the buffer.
 *                                    when the function returns the number of actually written charaters will be stored
 *                                    here.
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeQName(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) StrBufLenPtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeCheckSchemaDeviation()
 **********************************************************************************************************************/
/*! \brief         Check if a schema deviation did occur.
 *  \details       If a schema deviation did occur call the decoding function.
 *  \param[in]     DecWsPtr                 EXI decoding workspace
 *  \param[in,out] ExiEventCodePtr          in: event code of this element; out: event code of the next element
 *  \param[in]     SchemaDeviationEventCode Event code that is used as schema deviation at the current position
 *  \param[in]     EventCodeBitSize         Bit size of the current element event code
 *  \param[in]     StartElement             TRUE if SE(*) is accepted at this EXI stream position
 *  \param[in]     OptionalElement          TRUE if element is optional
 *  \param[in]     AttributesAllowed        TRUE if AT-Events are accepted at this EXI stream position, will be
 *                                          set to FALSE if there is no other AT excepted
 *  \param[in]     OptionalElementatEE      TRUE Optional exists just before the EE of a type
 *  \param[in]     KnownAttributesNum       Number of Attributes available in the schema at this EXI stream position
 *  \param[in]     SchemaSetId              EXI stream is based on this known schema set
 *  \param[in]     ElementIdentifier        Identifier of the element (only required for testing)
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeCheckSchemaDeviation(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BitBufType, AUTOMATIC, EXI_APPL_VAR) ExiEventCodePtr,
  Exi_BitBufType SchemaDeviationEventCode,
  uint8 EventCodeBitSize,
  Exi_BooleanType StartElement,
  Exi_BooleanType OptionalElement,
  Exi_BooleanType SubstitutionElement,
  Exi_BooleanType AttributesAllowed,
  Exi_BooleanType OptionalElementatEE,
  uint8 KnownAttributesNum,
  uint16 SchemaSetId,
  uint16 ElementIdentifier);

/**********************************************************************************************************************
 *  Exi_VBSDecodeSchemaDeviation()
 **********************************************************************************************************************/
/*! \brief         Decode a general schema deviation. All information found in the EXI stream will be skipped
 *  \details       Decode a general schema deviation. All information found in the EXI stream will be skipped
 *  \param[in]     DecWsPtr                                       EXI decoding workspace
 *  \param[in,out] ExiEventCodePtr                                in: event code of this element; out: event code of the next element
 *  \param[in]     SchemaDeviationEventCode                       Event code that is used as schema deviation at the current position
 *  \param[in]     EventCodeBitSize                               Bit size of the current element event code
 *  \param[in]     StartElement                                   TRUE if SE(*) is accepted at this EXI stream position
 *  \param[in]     OptionalElement                                TRUE if element is optional
 *  \param[in]     SubstitutionOrMultiOccurenceBufferElement      TRUE if element is substitution or multi occurence buffer type
 *  \param[in]     AttributesAllowed                              TRUE if AT-Events are accepted at this EXI stream position, will be
 *                                                                set to FALSE if there is no other AT excepted
 *  \param[in]     OptionalElementatEE                            TRUE if optional element is at EE of an element
 *  \param[in]     KnownAttributesNum                             Number of Attributes available in the schema at this EXI stream position
 *  \param[in]     SchemaSetId                                    EXI stream is based on this known schema set
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeSchemaDeviation(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BitBufType, AUTOMATIC, EXI_APPL_VAR) ExiEventCodePtr,
  Exi_BitBufType SchemaDeviationEventCode,
  uint8 EventCodeBitSize,
  Exi_BooleanType StartElement,
  Exi_BooleanType OptionalElement,
  Exi_BooleanType SubstitutionOrMultiOccurenceBufferElement,
  Exi_BooleanType AttributesAllowed,
  Exi_BooleanType OptionalElementatEE,
  uint8 KnownAttributesNum,
  uint16 SchemaSetId);

/**********************************************************************************************************************
 *  Exi_VBSDecodeGenericElement()
 **********************************************************************************************************************/
/*! \brief         Decode a generic element
 *  \details       Decode a generic element
 *  \param[in]     DecWsPtr           EXI decoding workspace
 *  \param[in]     SchemaSetId        EXI stream is based on this known schema set
 *  \param[in]     SkipElement        TRUE: data will be ignored, FALSE: Exi_GenericElementType struct will be stored
 *                                    in the decoding workspaces storage buffer
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \note          This function is indirectly recursive trough API Exi_VBSDecodeGenericElementContent().
 *                 This is required due to the generic decoding of unknown elements.
 **********************************************************************************************************************/
extern FUNC(void*, EXI_CODE) Exi_VBSDecodeGenericElement(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint16 SchemaSetId,
  Exi_BooleanType SkipElement);

/**********************************************************************************************************************
 *  Exi_VBSDecodeGenericElementContent()
 **********************************************************************************************************************/
/*! \brief         Decode a generic element content
 *  \details       Decode a generic element content
 *  \param[in]     DecWsPtr           EXI decoding workspace
 *  \param[in]     SchemaSetId        EXI stream is based on this known schema set
 *  \param[in]     SkipContent        TRUE: data will be ignored, FALSE: Exi_GenericElementType struct will be stored
 *                                    in the decoding workspaces storage buffer
 *  \param[in,out] GenericElementPtr  Content will be stored in this generic elements content if SkipContent is FALSE
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \note          This function is directly recursive and indirectly recursive trough API Exi_VBSDecodeGenericElement().
 *                 This is required due to the generic decoding of unknown elements.
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeGenericElementContent(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint16 SchemaSetId,
  Exi_BooleanType SkipContent,
  Exi_GenericElementType* GenericElementPtr);

/**********************************************************************************************************************
 *  Exi_VBSDecodeCalculateBitSize()
 **********************************************************************************************************************/
/*! \brief         Calculates the EXI events bit size required for the specified MaxValue
 *  \details       Calculates the EXI events bit size required for the specified MaxValue
 *  \param[in]     MaxValue           Number of possible EXI events
 *  \return                           Number of bits required to decode the value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(uint8, EXI_CODE) Exi_VBSDecodeCalculateBitSize(uint8 MaxValue);

/**********************************************************************************************************************
 *  Exi_VBSDecodeCheckAndAllocateBuffer
 *********************************************************************************************************************/
/*! \brief         This function is used while decoding for allocation of new EXI structure buffer.
 *  \details       This function is used while decoding for allocation of new EXI structure buffer.
 *  \param[in,out] DecWsPtr                    Pointer to EXI workspace containing the input and output data buffer
 *  \param[in]     ElementSize                 Size of the element to allocate buffer for
 *  \param[in]     IncrementStorageBuffer      Specify is the storage buffer fill level shall be incremented
 *  \return        NULL_PTR:                   Error storage buffer is to small\n
 *                 != NULL_PTR:                pointer to the allocated buffer
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void*, EXI_CODE) Exi_VBSDecodeCheckAndAllocateBuffer(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint32 ElementSize,
  Exi_BooleanType IncrementStorageBuffer);

/**********************************************************************************************************************
 *  Exi_VBSDecodeSetStatusCode
 *********************************************************************************************************************/
/*! \brief         This function is used while decoding to update the StatusCode in case of error detections.
 *  \details       This function is used while decoding to update the StatusCode in case of error detections.
 *  \param[in,out] DecWsPtr               Pointer to basic decoder workspace
 *  \param[in]     NewStatusCode          Status code to set
 *  \param[in]     CallInternal           Specify if DET shall be called always or only on change of the status code
 *  \param[in]     ApiId                  DET API ID
 *  \param[in]     ErrorId                DET error code
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeSetStatusCode(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  Exi_ReturnType NewStatusCode,
  Exi_BSSetStatusCodeDetType CallInternal,
  uint16 ApiId,
  uint8 ErrorId);

/**********************************************************************************************************************
 *  Exi_VBSDecodeCheckForFirstElement
 *********************************************************************************************************************/
/*! \brief         This function is used while decoding to check if this is first element and to set the root element ID
 *  \details       This function is used while decoding to check if this is first element and to set the root element ID
 *  \param[in,out] OutPutDataPtr               Pointer to the output data of the decode workspace
 *  \param[out]    isFirstElementPtr           Pointer to the isfirstElement variable of the caling function
 *  \param[in]     RootElementId               Root element ID to set
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSDecodeCheckForFirstElement(
  P2VAR(Exi_DecoderOutputDataType, AUTOMATIC, EXI_APPL_VAR) OutPutDataPtr,
  P2VAR(Exi_BooleanType, AUTOMATIC, EXI_APPL_VAR) isFirstElementPtr,
  Exi_RootElementIdType RootElementId);

/**********************************************************************************************************************
 *  Exi_VBSDecodeCheckAndDecodeEE
 *********************************************************************************************************************/
/*! \brief         This function is used while decoding to check and decode the end element tag
 *  \details       This function is used while decoding to check and decode the end element tag
 *  \param[in,out] DecWsPtr                    Pointer to basic decoder workspace
 *  \param[in]     BitCount                    Size of the EE tag in bits
 *  \param[in]     SchemaDeviationEventCode    Value of the schema deviation event code
 *  \param[in]     SchemaSetId                 ID of the schema were this call is made from
 *  \param[in]     ElementIdentifier           Identifier of the element (only required for testing)
 *  \return        E_OK:                       Successful\n
 *                 E_NOT_OK:                   Error EE event code was invalid
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, EXI_CODE) Exi_VBSDecodeCheckAndDecodeEE(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint8 BitCount,
  Exi_BitBufType SchemaDeviationEventCode,
  uint16 SchemaSetId,
  uint16 ElementIdentifier);

#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

#endif /* EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi.h
 **********************************************************************************************************************/
