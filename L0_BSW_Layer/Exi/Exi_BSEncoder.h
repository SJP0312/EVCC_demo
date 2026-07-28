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
/**        \file  Exi_BSEncoder.h
 *        \brief  Efficient XML Interchange basic Encoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component basic encoder.
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

#if !defined (EXI_BS_ENCODER_H)                                                                                         /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_BS_ENCODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_Types.h"
#include "Exi_SchemaEncoder.h"
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
 *  Exi_VBSEncodeInitWorkspace()
 **********************************************************************************************************************/
/*! \brief         Initialize an EXI bitstream encoding workspace.
 *  \details       Initialize an EXI bitstream encoding workspace.
 *  \param[in,out] EncWsPtr               pointer to EXI encoding workspace
 *  \param[in]     PBufPtr                buffer where the EXI stream shall be encoded to
 *  \param[in]     BufPtr                 buffer where the EXI stream shall be encoded to
 *  \param[in]     BufLen                 length of the data in BufPtr in bytes
 *  \param[in]     ByteOffset             offset in the output buffer
 *  \param[in]     StartWriteAtStreamPos  position in the EXI stream where writing shall be started (TxStremaing)
 *  \param[in]     CalculateStreamLength  TRUE: after end of output buffer has been reached, encoding will continue
 *                                        without writing furhter bits, so that the final stream length can be read out
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, EXI_CODE) Exi_VBSEncodeInitWorkspace(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  P2VAR(IpBase_PbufType, AUTOMATIC, EXI_APPL_VAR) PBufPtr,
#else
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) BufPtr,
  uint32 BufLen,
#endif
  uint32 ByteOffset
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
 ,uint32 StartWriteAtStreamPos
 ,Exi_BooleanType CalculateStreamLength
#endif
);

/**********************************************************************************************************************
 *  Exi_VBSEncodeGetWorkspaceBitPos()
 **********************************************************************************************************************/
/*! \brief         Get the bit position in the EXI stream of the workspace
 *  \details       Get the bit position in the EXI stream of the workspace
 *  \param[in]     EncWsPtr         EXI bitstream encoding workspace
 *  \retrun        Current bit position in the EXI stream
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(uint32, EXI_CODE) Exi_VBSEncodeGetWorkspaceBitPos(
  P2CONST(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr);

/**********************************************************************************************************************
 *  Exi_VBSWriteHeader()
 **********************************************************************************************************************/
/*! \brief         Write one-byte exi header
 *  \details       Write one-byte exi header
 *  \param[in]     EncWsPtr         EXI bitstream encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSWriteHeader(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr);

/**********************************************************************************************************************
 *  Exi_VBSWriteBits()
 **********************************************************************************************************************/
/*! \brief         Write bits into an EXI output buffer
 *  \details       Write bits into an EXI output buffer
 *  \param[in,out] EncWsPtr   Binary EXI stream object. (context)
 *  \param[in]     BitBuf     buffer containing the bits that should be written into the EXI stream.
 *                            The bits will be shiftet to the right into the EXi stream.
 *                            This means the BitCount lsbs will be written.
 *  \param[in]     BitCount   number of bits that should be sent.
 *  \return                   number ob written bits. This valus may be smaller that BitCount if the end of the EXI stream has
 *                            been reached. In this case this function must be called again with a buffer conatning only the
 *                            remaining bits. and BitCount set to the number of ramaining bits.
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(uint8, EXI_CODE) Exi_VBSWriteBits(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_BitBufType BitBuf,
  uint8 BitCount);

/**********************************************************************************************************************
 *  Exi_VBSEncodeBytes()
 **********************************************************************************************************************/
/*! \brief         encode length prefixed byte array to exi stream
 *  \details       encode length prefixed byte array to exi stream
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[in]     DataPtr            pointer to the byte array to write
 *  \param[in]     DataLen            length of the byte array
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeBytes(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(uint8, AUTOMATIC, EXI_APPL_DATA) DataPtr,
  uint16 DataLen);

/**********************************************************************************************************************
 *  Exi_VBSEncodeBool()
 **********************************************************************************************************************/
/*! \brief         encode boolean value
 *  \details       encode boolean value
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[in]     Value              value to encode
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeBool(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  boolean Value);

/**********************************************************************************************************************
 *  Exi_VBSEncodeInt()
 **********************************************************************************************************************/
/*! \brief         Encode a signed integer
 *  \details       Encode a signed integer
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[in]     Value              value to encode
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeInt(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  sint32 Value);

/**********************************************************************************************************************
 *  Exi_VBSEncodeInt64()
 **********************************************************************************************************************/
/*! \brief         Encode a 64 bit signed integer
 *  \details       Encode a 64 bit signed integer
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[in]     Value              value to encode
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeInt64(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_SInt64 Value);

/**********************************************************************************************************************
 *  Exi_VBSEncodeBigInt()
 **********************************************************************************************************************/
/*! \brief         Encode a big integer
 *  \details       Encode a big integer
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[in]     ValuePtr           pointer to the Exi_BigIntType structure to encode
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeBigInt(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(Exi_BigIntType, AUTOMATIC, EXI_APPL_DATA) ValuePtr);

/**********************************************************************************************************************
 *  Exi_VBSEncodeUInt()
 **********************************************************************************************************************/
/*! \brief         Encode an variable-length unsigned integer
 *  \details       Encode an variable-length unsigned integer
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[in]     Value              value to encode
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeUInt(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_BitBufType Value);

/**********************************************************************************************************************
 *  Exi_VBSEncodeUInt64()
 **********************************************************************************************************************/
/*! \brief         Encode a 64 bit unsigned integer
 *  \details       Encode a 64 bit unsigned integer
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[in]     Value              value to encode
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeUInt64(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_UInt64 Value);

/**********************************************************************************************************************
 *  Exi_VBSEncodeUIntN()
 **********************************************************************************************************************/
/*! \brief         Encode n bit unsigned integer value
 *  \details       Encode n bit unsigned integer value
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[in]     BitBuf             Bits shall be encoded
 *  \param[in]     BitCount           Number of bits that shall be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeUIntN(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_BitBufType BitBuf,
  uint8 BitCount);

/**********************************************************************************************************************
 *  Exi_VBSEncodeStringOnly()
 **********************************************************************************************************************/
/*! \brief         Encode string without preceding length information
 *  \details       Encode string without preceding length information
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[out]    StrBufPtr          buffer of the characters that shall be encoded
 *  \param[in,out] StrBufLen          number of characters to encode
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeStringOnly(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  uint16 StrBufLen);

/**********************************************************************************************************************
 *  Exi_VBSEncodeString()
 **********************************************************************************************************************/
/*! \brief         Encode string with preceding length information
 *  \details       Encode string with preceding length information
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[out]    StrBufPtr          buffer of the characters that shall be encoded
 *  \param[in,out] StrBufLen          number of characters to encode
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeString(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  uint16 StrBufLen);

/**********************************************************************************************************************
 *  Exi_VBSEncodeStringValue()
 **********************************************************************************************************************/
/*! \brief         Encode string without preceding length information
 *  \details       Encode string without preceding length information
 *  \param[in]     EncWsPtr           EXI bitstream encoding workspace
 *  \param[out]    StrBufPtr          buffer of the characters that shall be encoded
 *  \param[in,out] StrBufLen          number of characters to encode
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeStringValue(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  uint16 StrBufLen);

/**********************************************************************************************************************
 *  Exi_VBSEncodeSetStatusCode
 *********************************************************************************************************************/
/*! \brief         This function is used while encoding to update the StatusCode in case of error detections.
 *  \details       This function is used while encoding to update the StatusCode in case of error detections.
 *  \param[in,out] EncWsPtr                    Pointer to basic encoder workspace
 *  \param[in]     NewStatusCode               Status code to set
 *  \param[in]     CallInternal           Specify if DET shall be called always or only on change of the status code
 *  \param[in]     ApiId                       DET API ID
 *  \param[in]     ErrorId                     DET error code
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeSetStatusCode(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_ReturnType NewStatusCode,
  Exi_BSSetStatusCodeDetType CallInternal,
  uint16 ApiId,
  uint8 ErrorId);

/**********************************************************************************************************************
 *  Exi_VBSEncodeCheckAndEncodeEE
 *********************************************************************************************************************/
/*! \brief         This function is used while encoding to check and encode the end element tag
 *  \details       This function is used while encoding to check and encode the end element tag
 *  \param[in,out] EncWsPtr                    Pointer to basic encoder workspace
 *  \param[in]     BitBuf                      Value of the end element tag
 *  \param[in]     BitCount                    Size of the EE tag in bits
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_VBSEncodeCheckAndEncodeEE(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_BitBufType BitBuf,
  uint8 BitCount);

#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

#endif /* EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi.h
 **********************************************************************************************************************/
