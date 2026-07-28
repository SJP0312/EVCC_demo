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
/**        \file  Exi.h
 *        \brief  Efficient XML Interchange main header file
 *
 *      \details  Vector static code main header file for the Efficient XML Interchange module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author      Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2012-02-01  visdd       -             created
 *  01.00.01  2012-04-19  visdd       -             Encoder bugfix: multiple optional elements with substitution group
 *                                    -             bugfix MemMap and CompilerCfg
 *  01.01.00  2012-07-04  visdd       ESCAN00058666 Support final DIN 70121 schema
 *                                    ESCAN00058667 Offset calculation for range limited values
 *                                    ESCAN00059066 Bugfix negative integer decoding
 *                        visfdn      ESCAN00058734 Enhance Encoding / Decoding by Offset
 *                                    ESCAN00059073 Change return values of failed internal Det checks
 *                                    ESCAN00059077 Decoding of string and byte-arrays fails under certain circumstances
 *                                    ESCAN00059078 DET check missing is some internal functions
 *                                    ESCAN00059119 Int decoding functions return incorrect result if value is too large
 *                                    ESCAN00059111 Exi_VBSEncodeBytes() returns E_OK even if buffer is too small
 *                        visdd       ESCAN00059287 Using new Exi_ReturnType instead of Std_ReturnType
 *                                    ESCAN00059448 Bugfix De-/Encoding UInt8 > 127 and negative Int8 values
 *                                    ESCAN00059587 Basic schema deviation support
 *                        visfdn      ESCAN00059318 Bugfix decoding UInt > 32bit
 *                        visdd       ESCAN00059715 Encoding error for CurrentDemandReq depending on optional parameters
 *                                    ESCAN00059905 Added support for XSD choice elements
 *  01.01.01  2012-09-27  visdd       ESCAN00060205 Bugfix buffer elements (strings, binary data) with MaxOccurs > 1
 *                                    ESCAN00060304 Bugfix encoding PowerDeliveryReq with ChargingProfile
 *                                    ESCAN00061353 Bugfix CurrentDemandRes encoding
 *                                    ESCAN00061356 Added EXI_E_DISABLED_FEATURE return code
 *                                    ESCAN00061379 Bugfix: ChargingProfile enabled for basic message set
 *                        visfdn      ESCAN00061516 Exi_VBSDecodeSkipBits() sets bit position after EOS
 *  01.02.00  2012-09-28  visdd       ESCAN00061406 Removed return values and conditional checks to reduce code size and
 *                                                    improve readability
 *                                    -             Added StatusCode to encoding and decoding workspace
 *  01.03.00  2013-01-16  visdd       ESCAN00063173 Add configuration support for unbounded buffer elements
 *                                    ESCAN00062410 XML Security support: Added possiblity to encode all root elements
 *                                    ESCAN00061243 Map xsd:long and xsd:unsignedLong to 64 bit integer values
 *                                    ESCAN00064184 Compiler error in Exi_InitDecodeWorkspace if PBuf support disabled and
 *                                                    det enabled
 *                                    ESCAN00064179 Support schema-informed fragment grammar encoding for XML Signatures
 *  01.03.01  2013-07-05  visdd       ESCAN00066902 EXI fails to decode document streams that do not start with V2G_Message
 *                                    ESCAN00066944 Generated fragment stream is invalid for some messages
 *                                    ESCAN00068523 EXI fails to decode/encode integers of arbitrary length
 *                                    ESCAN00068674 Encoding/Decoding of Base64 encoded binary data not possible for length
 *                                                    limited elements
 *                                    ESCAN00068813 Decoding of supportedAppProtocolReq message with exactly 20 AppProtocol elements fails
 *  01.03.02  2013-07-23  visdd       ESCAN00069290 Encoding and Decoding of multiple choice elements fails
 *  01.03.03  2013-10-01  visdd       ESCAN00069263 AR4-450: Usage of section PBCFG in PB files
 *  02.00.00  2013-11-05  visdd       ESCAN00071678 Support ISO 15118 FDIS schema version
 *  02.00.01  2014-02-20  visdd       ESCAN00073827 Compiler error: identifier "Exi_XMLSIG_SignatureType" is undefined
 *                                                  Wrong encoding of eMAID (CertificateInstallation/UpdateRes)
 *  02.01.00  2014-03-03  visdd       ESCAN00074027 Customer specific extensions
 *                                    ESCAN00073480 Wrong fragment encoding for eMAID XML Fragment
 *  02.01.01  2014-05-27  vissop      ESCAN00074805 Fix: Enable string encoding for ISO and DIN
 *  02.02.00  2014-06-10  vissop      ESCAN00076165 Add: Customer specific extensions
 *  03.00.00  2014-07-18  vissop      ESCAN00077211 Adapt package attributes
 *            2014-08-08  vissop      ESCAN00077713 Fix: Decoder PBuf handling to support more than two segments
 *            2014-08-08  vissop      ESCAN00077725 Remove single source S from Vector internal filenames
 *            2014-08-08  vissop      ESCAN00077726 Remove version checks from various files
 *  03.00.01  2014-08-22  vissop      ESCAN00078008 Fix: Encoder PBuf handling to support more than two segments
 *            2014-08-25  vissop      ESCAN00078016 Customer specific: Fixed bug in customer specific schema
 *  03.00.02  2014-08-28  vissop      ESCAN00078123 Fix: Decode error in case last sub element is optional and not present
 *  03.00.03  2014-09-29  vissop      ESCAN00078623 Fix: EXI decode may read from invalid memory after truncated string
 *  03.00.04  2014-10-29  vissop      ESCAN00079205 Fix: 64 bit data type usage on 16 bit platforms
 *  03.01.00  2014-10-27  vissop      ESCAN00079157 Add: EXI simple TX streaming support
 *            2014-12-15  vissop      ESCAN00079971 Fix EVSE only: Wrong encoding in case an optional element is missing in
 *                                                  front of a list element
 *  03.02.00  2015-04-16  vissop      ESCAN00081584 Add: Configurable manual structure padding for 16 and 32 bit
 *  03.02.01  2015-06-12  vissop      ESCAN00083369 Fix EVSE only: Wrong encoding of the ISO CurrentDemandRes with missing optional elements
 *            2015-06-12  vissop      ESCAN00083250 Fix: Compiler error in case PBuf support is disabled
 *  03.02.02  2015-07-07  vissop      ESCAN00083840 Fix: Compiler warning with EXI struct padding default configuration
 *  03.02.03  2015-09-02  vissop      ESCAN00083713 Fix: Remove extended version for MICROSAR 4
 *  03.02.04  2016-02-26  vissop      ESCAN00088287 Fix: ISO15118: Optional PnC elements cannot be decoded in case PnC charging is disabled
 *            2016-03-01  vissop      ESCAN00088649 Fix: ISO15118: MeterReading value cannot be bigger than uint32 maximum while encoding
 *  03.02.05  2016-12-07  vissop      ESCAN00092055 Fix: MainFunction shall not throw DET's in UNINIT case
 *  04.00.00  2017-06-07  vissop      ESCAN00095446 Add: ISO15118-2 edition 2 CD2 schema support
 *            2017-06-07  vissop      ESCAN00095284 Fix: Internal functions: 'se64Binary' -> 'base64Binary'; 'ring' -> 'string'
 *            2017-08-21  vissop      ESCAN00096374 Add: Code Generator: Add support for concatenated substitution groups
 *            2017-08-21  vissop      ESCAN00088786 Fix: ChargingStatusRes with missing MeterInfo and ReceiptRequired cannot be encoded (EVSE issue only)
 *            2017-08-21  vissop      ESCAN00080266 Fix: Code Generator: Wrong encoding in case an optional element is missing in front of a list element
 *            2017-08-21  vissop      ESCAN00082828 Fix: Code Generator: Wrong encoding of the CurrentDemandRes with missing optional elements
 *            2017-09-06  vissop      ESCAN00096545 Fix: Wrong decoding in case optional elements are in front of mandatory substitution groups
 *            2017-09-11  vissop      ESCAN00097197 Fix: Messages with only an optional substitution group (ISO ED2 CD2 schema only)
 *            2017-11-28  vissop      ESCAN00097578 Fix: MISRA, PCLint and multiple compiler compliance
 *            2017-11-30  vissop      ESCAN00097608 Add: Remove obsolete customer specific schema support
 *  04.00.01  2018-01-31  vissop      ESCAN00098218 Fix: Integrate review findings from review of version 4.00.00
 *            2018-01-31  vissop      ESCAN00098138 Fix: Memory may be overwritten while element lists are decoded
 *            2018-01-31  vissop      ESCAN00097998 Fix: Exi_EncodeFragment for EXI_SCHEMA_SET_ISO_ED2_CD2_TYPE may encode invalid fragments
 *            2018-02-20  vissop      ESCAN00098429 Fix: Compiler error: Exi_IDType is unknown
 *  04.00.02  2018-03-19  vissop      ESCAN00098808 Fix: Compiler warning: Unreferenced parameter in Exi_SchemaDecoder.c
 *            2018-03-20  vissop      STORYC-4738   Fix: MISRA findings in GeneratorMsr
 *  05.00.00  2018-05-08  vissop      STORYC-3888   Add: Proc3.0 for Exi (CDD and DET refactoring)
 *            2018-04-09  vissop      ESCAN00099043 Fix: ISO_ED2_CD2: Wrong encoding of FinePositioningSetupRes if all optional elements are present
 *            2018-05-07  vissop      ESCAN00099355 Fix: ISO ED2 CD2: ChargeParameterDiscoveryRes invaild encoding if optional SAScheduleList is missing
 *            2018-06-13  vissop      ESCAN00096780 Fix: Compiler warning: Function Exi_EncodeFragment parameter 'Namespace' not used
 *            2018-06-13  vissop      ESCAN00098838 Fix: Compiler warning: DET API ID: cast truncates constant value
 *            2018-06-13  vissop      -             Fix: 1st Review integration for this version
 *            2018-06-22  vissop      ESCAN00098840 Fix: Compiler warning: SchemaSetId : unreferenced formal parameter
 *  06.00.00  2018-08-29  vissop      STORYC-5808   Add: Introduce ISO15118-2 Edition 2 DIS schema for AC and DC charging (remove CD2 schema)
 *            2018-08-29  vissop      STORYC-6593   Add: ISO15118-2 Edition 2 DIS WPT charging
 *            2018-08-29  vissop      STORYC-6373   Add: Optimization: Remove obsolete code paths
 *  06.00.01  2018-12-11  vissop      -             Fix: Review integration of previous version (Typos in API descriptions)
 *            2019-01-31  vissop      ESCAN00101943 Fix: PBuf check of Init*Workspace call does fail for PBufs using multiple segments
 *  08.00.00  2020-02-19  visiay      ESCAN00060182 Fix: Error decoding schema deviations before and after optional elements
 *            2020-01-15  visiay      V2G-269       Fix: Add attribute support in schema deviation start element
 *            2020-01-15  visiay      V2G-269       Fix: Add support for deviations after and before (bounded/unbounded)lists/choice elements/substitution elements
 *            2020-01-18  visiay      V2G-333       Add: Reduced code variants and removed unnecessary code paths
 *            2020-01-18  visiay      ESCAN00076782 Fix: Compiler error: Exi_DecoderFcts too many initializers
 *            2020-01-18  visiay      ESCAN00106970 Fix: BigInt handling is not correct (encoder and decoder)(e.g. SerialNumber)
 *  08.00.01  2020-06-26  visiay      ESCAN00106583 Fix: XML Signature schema cannot be disabled completely
 *            2020-06-26  visiay      ESCAN00106617 Fix: Compiler error XMLSIG types and schemata are undefined
 *            2020-07-07  visiay      ESCAN00106725 Fix: Compiler error Undeclared Exi Types in SCC
 *  09.00.00  2020-07-20  visiay      V2G-491       MISRA-C:2012
 *  09.00.01  2020-08-07  visiay      ESCAN00107068 XML Signature schema fragments cannot be created anymore
 *  10.00.00  2021-01-18  vissop      V2G-901       Add: ISO/FDIS 15118-20 support: First draft schema
 *  10.01.00  2021-05-03  vissop      V2G-1659      Add: ISO/FDIS 15118-20 support: Update to second draft schema
 *  10.02.00  2021-07-21  vissop      V2G-1802      Add: ISO/FDIS 15118-20 support: Update to first FDIS candidate
 *            2021-07-23  visiay      V2G-1567      Update MISRA analysis tool to QAC2021.1
 *  10.03.00  2021-09-02  visiay      V2G-2174      Fix: Remove usage own 64 bit types
 *            2021-09-02  visiay      V2G-2176      Fix: Changed DET macros as function like macros
 *            2021-09-21  visiay      V2G-1222      Updated to latest schema
 *  11.00.00  2022-01-13  visiay      V2G-2138      Add: ISO/FDIS 15118-20 support: WPT
 *            2022-01-13  visiay      V2G-1235      Add: ISO/FDIS 15118-20 support: ACDP
 *            2022-01-14  visiay      V2G-1991      Usage of <Mip>_MemMap
 *  11.00.01  2022-10-25  vissop      ESCAN00113014 Fix: Decoding of BigIntegers with one additional zero byte in the value buffer
 *            2022-10-25  vissop      ESCAN00110286 Fix: Decoder: Negative BigInt values with maximum length are not handled correctly
 *            2022-10-25  vissop      ESCAN00113031 Fix: Compiler warning: Variable value not used (ISO15118-20 WPT)
 *  12.00.00  2023-04-05  vissop      V2G-3814      Remove code filters and obsolete configuration switches
 *  13.00.00  2023-11-27  leisenbeis  ESCAN00110234 Fix: NULL_PTR access in Exi_VBSDecodeGenericElement() on variable QNamePtr
 *            2023-11-28  leisenbeis  V2G-4541      Support SAE J3105 schema as enhancement of DIN70121 schema
 *            2023-11-30  leisenbeis  V2G-3872      Add an external buffer allocation API
 *            2023-12-05  leisenbeis  ESCAN00111895 Fix: Decoding is successful even if string values are longer than allowed by the schema
 *            2023-12-14  leisenbeis  ESCAN00116330 Fix: Array content skipping is wrong in case the end of the array is beyond Byte-Position 65535 in the EXI stream
 *  13.01.00  2024-02-16  leisenbeis  V2G-4786      Add additional APIs
 *  13.02.00  2024-04-09  visese      V2G-4942      Fix CPC warnings
 *            2024-06-06  leisenbeis  V2G-5129      Fix Vector Coding Rules findings for if-conditions with E_NOT_OK
 *            2024-06-13  leisenbeis  ESCAN00117522 Fix: Exi_FinalizeExiStream: Invalid DET report API ID and missing DET checks
 *  13.02.01  2024-07-04  leisenbeis  ESCAN00117722 Fix: Invalid DET error thrown in case of Exi Tx streaming when output buffer size smaller than stream size
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_Exi_1.1_0857 */ /* [L] Number of macro definitions exceeds 1024 - program is non-conforming. */
#if !defined (EXI_H)                                                                                                    /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_Types.h"
#include "Exi_Lcfg.h"
#include "SchM_Exi.h"

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
#define EXI_VENDOR_ID                                 30u   /* Vector ID */
#define EXI_MODULE_ID                                255u   /* CDD module ID used for EXI */
#define EXI_INSTANCE_ID                              107u   /* EXI is identified via instance ID */
#define EXI_ENCODER_INSTANCE_ID                      108u   /* EXI Encoder is identified via instance ID */
#define EXI_DECODER_INSTANCE_ID                      109u   /* EXI Decoder is identified via instance ID */


/* ----- Component version information (decimal version of ALM implementation package) ----- */
#define EXI_SW_MAJOR_VERSION                      13u
#define EXI_SW_MINOR_VERSION                      2u
#define EXI_SW_PATCH_VERSION                      1u

/* ----- API service IDs ----- */
#define EXI_API_ID_INIT                             0x01u
#define EXI_API_ID_MAIN_FUNCTION                    0x02u
#define EXI_API_ID_INIT_DECODE_WORKSPACE            0x03u
#define EXI_API_ID_INIT_ENCODE_WORKSPACE            0x04u
#define EXI_API_ID_DECODE                           0x05u
#define EXI_API_ID_ENCODE                           0x06u
#define EXI_API_ID_FINALIZE_EXI_STREAM              0x07u
#define EXI_API_ID_GET_VERSION_INFO                 0x08u
#define EXI_API_ID_V_INTERNAL_FUNCTION              0x09u
#define EXI_API_ID_ENCODE_FRAGMENT                  0x0Au
#define EXI_API_ID_INIT_MEM_ALLOC_WORKSPACE         0x0Bu
#define EXI_API_ID_MEM_ALLOC                        0x0Cu

/* ----- Error codes ----- */
typedef uint8 Exi_DetErrorType;
#define EXI_E_NO_ERROR                              0x00u
#define EXI_E_NOT_INITIALIZED                       0x01u
#define EXI_E_INV_POINTER                           0x02u
#define EXI_E_INV_PARAM                             0x03u
#define EXI_E_INVALID_PBBUF_POS                     0x04u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Exi_InitMemory
 *********************************************************************************************************************/
/*! \brief         Initialize global variables
 *  \details       This function is used to initialize the global variables of the Exi at startup.
 *  \param[in]     void
 *  \pre           The provided workspace must be initialized
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          Use this function in case these variables are not initialized by the
 *                 startup code. In case this API is called it has to called before Exi_Init is called.
 *  \trace         CREQ-154402
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_InitMemory(void);

/**********************************************************************************************************************
 *  Exi_Init
 *********************************************************************************************************************/
/*! \brief         Initialize the Exi component
 *  \details       This function is used to initialize the Exi component. The configuration data that shall be used by
 *                 the Exi is passed as parameter.
 *  \param[in]     Exi_ConfigPtr      Pointer to the post-build configuration data structure of the Exi. If the
 *                 configuration variant pre-compile is used, the pointer given is ignored.
 *  \pre           The provided workspace must be initialized
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          This function has to be called before usage of the module
 *  \trace         CREQ-154402
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Init(P2CONST(Exi_ConfigType, AUTOMATIC, EXI_CONST) Exi_ConfigPtr);

#if EXI_VERSION_INFO_API == STD_ON
/**********************************************************************************************************************
 *  Exi_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief         Returns the version information
 *  \details       Returns the decimal encoded version information, vendor ID and AUTOSAR module ID of the EXI component.
 *  \param[in]     VersionInfoPtr        Pointer to a memory location where the Exi version information shall be stored.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        EXI_VERSION_INFO_API
 *  \trace         CREQ-154403
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, EXI_APPL_DATA) VersionInfoPtr);
#endif
  /* EXI_VERSION_INFO_API == STD_ON */

/**********************************************************************************************************************
 *  Exi_MainFunction
 *********************************************************************************************************************/
/*! \brief         Main function of the EXI module
 *  \details       This function is empty, but can be optionally called.
 *  \param[in]     void
 *  \pre           The Exi has to be initialized with a call of Exi_Init.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
/* extern FUNC(void, EXI_CODE) Exi_MainFunction(void); */

/**********************************************************************************************************************
 *  Exi_InitEncodeWorkspace()
 **********************************************************************************************************************/
/*! \brief         Initialze a EXI encode workspace.
 *  \details       This function is called to initialize an EXI encoding workspace. The encoding workspace is used to
 *                 handle all data that is required to transform a schema conform data structures into a valid EXI
 *                 stream.
 *  \param[in,out] EncWsPtr                    Pointer to EXI workspace containing the input and output data buffer
 *  \param[in,out] InBufPtr                    Pointer to EXI input data buffer (EXI struct)
 *  \param[in,out] OutPBufPtr                  Pointer to EXI output data buffer (EXI stream).\n
 *                                             Give at least 1 byte of buffer for EXI stream length calculation \n
 *                                             (TX streaming)\n
 *                                             Parameter is available if PBUF support is enabled.
 *  \param[in,out] OutBufPtr                   Pointer to EXI output data buffer (EXI stream).\n
 *                                             Give at least 1 byte of buffer for EXI stream length calculation \n
 *                                             (TX streaming)\n
 *                                             Parameter is available if PBUF support is disabled.
 *  \param[in]     OutBufLen                   Maximum EXI output data buffer length\n
 *                                             Parameter is available if PBUF support is disabled.
 *  \param[in]     OutBufOfs                   Byte offset in output buffer at which encoding starts
 *  \param[in]     StartWriteAtStreamPos       Start writing at stream byte position, skip writing bytes until this \n
 *                                             position. Set to value 0xFFFFFFFF to calculate EXI stream length \n
 *                                             without writing.\n
 *                                             Parameter is available if simple TX streaming is enabled.
 *  \param[in]     CalculateStreamLength       If TRUE the complete stream length will be calculated\n
 *                                             If FALSE encoding will be skipped after buffer is full\n
 *                                             Parameter is available if simple TX streaming is enabled.
 *  \return        EXI_E_OK:                      Finished successfully\n
 *                 EXI_E_NOT_OK:                  undefined error\n
 *                 EXI_E_INV_HEADER:              invalid exi header\n
 *                 EXI_E_EOS:                     end of exi stream buffer\n
 *                 EXI_E_INT_OVERFLOW:            decoded integer too big for target buffer\n
 *                 EXI_E_ARR_OVERFLOW:            decoded array too big for target array\n
 *                 EXI_E_STRING_TABLE_LOCAL_HIT:  string empty, must be in local table\n
 *                 EXI_E_STRING_TABLE_GLOBAL_HIT: string empty, must be in global table\n
 *                 EXI_E_INV_EVENT_CODE:          invalid/unknown event code\n
 *                 EXI_E_BUFFER_SIZE:             target buffer to small\n
 *                 EXI_E_DISABLED_FEATURE:        feature disabled\n
 *                 EXI_E_LIST_TO_LONG:            To many elements in a list or last NextPtr not NULL\n
 *                 EXI_E_ENUM_OUT_OF_RANGE:       Enumaration value is out of range\n
 *                 EXI_E_INV_STRUCT_POINTER:      Invalid pointer, this may happen if a flag is 1 but the element is NULL_PTR\n
 *                 EXI_E_INV_CHOICE_SELECTION:    Choice element selection is invalid, multiple flags are set\n
 *                 EXI_E_INCONSISTEN_PBUF:        The provided PBuf is not consistent regarding its length information
 *  \pre           The Exi has to be initialized with a call of Exi_Init.
 *  \context       TASK|ISR2
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(Exi_ReturnType, EXI_CODE) Exi_InitEncodeWorkspace(
  P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(uint8, AUTOMATIC, EXI_APPL_DATA) InBufPtr,
#if EXI_ENABLE_PBUF_SUPPORT == STD_ON
  P2VAR(IpBase_PbufType, AUTOMATIC, EXI_APPL_VAR) OutPBufPtr,
#else
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) OutBufPtr,
  uint32 OutBufLen,
#endif
  uint32 OutBufOfs
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
  , uint32 StartWriteAtStreamPos
  , boolean CalculateStreamLength
#endif
);

/**********************************************************************************************************************
 *  Exi_InitDecodeWorkspace()
 **********************************************************************************************************************/
/*! \brief         Initialze a EXI decode workspace.
 *  \details       This function is called to initialize an EXI decoding workspace. The decoding workspace is used to
 *                 handle all data that is required to transform an EXI stream into a schema conform data structures.
 *  \param[in,out] DecWsPtr           Pointer to EXI workspace containing the input and output data buffer
 *  \param[in,out] InPBufPtr          Pointer to EXI input data buffer (EXI stream)\n
 *                                    Parameter is available if PBUF support is enabled.
 *  \param[in,out] InBufPtr           Pointer to EXI input data buffer (EXI stream)\n
 *                                    Parameter is available if PBUF support is disabled.
 *  \param[in,out] OutBufPtr          Pointer to EXI output data buffer (EXI struct)
 *  \param[in]     InBufLen           EXI input data length\n
 *                                    Parameter is available if PBUF support is disabled.
 *  \param[in]     OutBufLen          Maximum EXI output data buffer length
 *  \param[in]     InBufOfs           byte offset in input buffer at which decoding begins
 *  \return        EXI_E_OK:                      Finished successfully\n
 *                 EXI_E_NOT_OK:                  undefined error\n
 *                 EXI_E_INV_HEADER:              invalid exi header\n
 *                 EXI_E_EOS:                     end of exi stream buffer\n
 *                 EXI_E_INT_OVERFLOW:            decoded integer too big for target buffer\n
 *                 EXI_E_ARR_OVERFLOW:            decoded array too big for target array\n
 *                 EXI_E_STRING_TABLE_LOCAL_HIT:  string empty, must be in local table\n
 *                 EXI_E_STRING_TABLE_GLOBAL_HIT: string empty, must be in global table\n
 *                 EXI_E_INV_EVENT_CODE:          invalid/unknown event code\n
 *                 EXI_E_BUFFER_SIZE:             target buffer to small\n
 *                 EXI_E_DISABLED_FEATURE:        feature disabled\n
 *                 EXI_E_LIST_TO_LONG:            To many elements in a list or last NextPtr not NULL\n
 *                 EXI_E_ENUM_OUT_OF_RANGE:       Enumaration value is out of range\n
 *                 EXI_E_INV_STRUCT_POINTER:      Invalid pointer, this may happen if a flag is 1 but the element is NULL_PTR\n
 *                 EXI_E_INV_CHOICE_SELECTION:    Choice element selection is invalid, multiple flags are set\n
 *                 EXI_E_INCONSISTEN_PBUF:        The provided PBuf is not consistent regarding its length information
 *  \pre           The Exi has to be initialized with a call of Exi_Init.
 *  \context       TASK|ISR2
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(Exi_ReturnType, EXI_CODE) Exi_InitDecodeWorkspace(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
#if EXI_ENABLE_PBUF_SUPPORT == STD_ON
  P2CONST(IpBase_PbufType, AUTOMATIC, EXI_APPL_DATA) InPBufPtr,
#else
  P2CONST(uint8, AUTOMATIC, EXI_APPL_DATA) InBufPtr,
#endif
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) OutBufPtr,
#if EXI_ENABLE_PBUF_SUPPORT == STD_OFF
  uint32 InBufLen,
#endif
  uint32 OutBufLen,
  uint32 InBufOfs);

/**********************************************************************************************************************
 *  Exi_Encode
 *********************************************************************************************************************/
/*! \brief         Encode an EXI stream.
 *  \details       This function is used to generate a schema conform EXI stream based on the schema-informed document
 *                 grammar that represents the data structure included in the encoding workspace.
 *  \param[in,out] EncWsPtr           Pointer to EXI workspace containing the input and output data buffer
 *  \return        EXI_E_OK:                      Finished successfully\n
 *                 EXI_E_NOT_OK:                  undefined error\n
 *                 EXI_E_INV_HEADER:              invalid exi header\n
 *                 EXI_E_EOS:                     end of exi stream buffer\n
 *                 EXI_E_INT_OVERFLOW:            decoded integer too big for target buffer\n
 *                 EXI_E_ARR_OVERFLOW:            decoded array too big for target array\n
 *                 EXI_E_STRING_TABLE_LOCAL_HIT:  string empty, must be in local table\n
 *                 EXI_E_STRING_TABLE_GLOBAL_HIT: string empty, must be in global table\n
 *                 EXI_E_INV_EVENT_CODE:          invalid/unknown event code\n
 *                 EXI_E_BUFFER_SIZE:             target buffer to small\n
 *                 EXI_E_DISABLED_FEATURE:        feature disabled\n
 *                 EXI_E_LIST_TO_LONG:            To many elements in a list or last NextPtr not NULL\n
 *                 EXI_E_ENUM_OUT_OF_RANGE:       Enumaration value is out of range\n
 *                 EXI_E_INV_STRUCT_POINTER:      Invalid pointer, this may happen if a flag is 1 but the element is NULL_PTR\n
 *                 EXI_E_INV_CHOICE_SELECTION:    Choice element selection is invalid, multiple flags are set\n
 *                 EXI_E_INCONSISTEN_PBUF:        The provided PBuf is not consistent regarding its length information
 *  \pre           The Exi has to be initialized with a call of Exi_Init and the provided Exi_EncodeWorkspaceType
 *                 has to be initializes with call to Exi_InitEncodeWorkspace first.
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \note          Encoding of large EXI streams may take several milliseconds, depending on the system performance.
 *********************************************************************************************************************/
extern FUNC(Exi_ReturnType, EXI_CODE) Exi_Encode( P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );

/**********************************************************************************************************************
 *  Exi_EncodeFragment
 *********************************************************************************************************************/
/*! \brief         Encode an EXI schema fragment.
 *  \details       This function is used to generate a schema conform EXI stream based on the schema-informed fragment
 *                 grammar that represents the data structure included in the encoding workspace.
 *  \param[in,out] EncWsPtr           Pointer to EXI workspace containing the input and output data buffer
 *  \param[in]     Namespace          Namespace identifier
 *  \return        EXI_E_OK:                      Finished successfully\n
 *                 EXI_E_NOT_OK:                  undefined error\n
 *                 EXI_E_INV_HEADER:              invalid exi header\n
 *                 EXI_E_EOS:                     end of exi stream buffer\n
 *                 EXI_E_INT_OVERFLOW:            decoded integer too big for target buffer\n
 *                 EXI_E_ARR_OVERFLOW:            decoded array too big for target array\n
 *                 EXI_E_STRING_TABLE_LOCAL_HIT:  string empty, must be in local table\n
 *                 EXI_E_STRING_TABLE_GLOBAL_HIT: string empty, must be in global table\n
 *                 EXI_E_INV_EVENT_CODE:          invalid/unknown event code\n
 *                 EXI_E_BUFFER_SIZE:             target buffer to small\n
 *                 EXI_E_DISABLED_FEATURE:        feature disabled\n
 *                 EXI_E_LIST_TO_LONG:            To many elements in a list or last NextPtr not NULL\n
 *                 EXI_E_ENUM_OUT_OF_RANGE:       Enumaration value is out of range\n
 *                 EXI_E_INV_STRUCT_POINTER:      Invalid pointer, this may happen if a flag is 1 but the element is NULL_PTR\n
 *                 EXI_E_INV_CHOICE_SELECTION:    Choice element selection is invalid, multiple flags are set\n
 *                 EXI_E_INCONSISTEN_PBUF:        The provided PBuf is not consistent regarding its length information
 *  \pre           The Exi has to be initialized with a call of Exi_Init and the provided Exi_EncodeWorkspaceType
 *                 has to be initializes with call to Exi_InitEncodeWorkspace first.
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \note          Encoding of large EXI streams may take several milliseconds, depending on the system performance.
 *********************************************************************************************************************/
extern FUNC(Exi_ReturnType, EXI_CODE) Exi_EncodeFragment( P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
                                       Exi_NamespaceIdType Namespace );

/**********************************************************************************************************************
 *  Exi_FinalizeExiStream
 *********************************************************************************************************************/
/*! \brief         Finalize an EXI stream after conding.
 *  \details       Finalize an EXI stream. Padding will be added and EncWsPtr->EncWs.BytePos will indicate EXI stream
 *                 length.
 *  \param[in,out] EncWsPtr           Pointer to EXI workspace containing the input and output data buffer\n
 *                                    See Exi_BSEncodeWorkspaceType declaration for out parameters (external)
 *  \return        EXI_E_OK:                      Finished successfully\n
 *                 EXI_E_NOT_OK:                  undefined error\n
 *                 EXI_E_INV_HEADER:              invalid exi header\n
 *                 EXI_E_EOS:                     end of exi stream buffer\n
 *                 EXI_E_INT_OVERFLOW:            decoded integer too big for target buffer\n
 *                 EXI_E_ARR_OVERFLOW:            decoded array too big for target array\n
 *                 EXI_E_STRING_TABLE_LOCAL_HIT:  string empty, must be in local table\n
 *                 EXI_E_STRING_TABLE_GLOBAL_HIT: string empty, must be in global table\n
 *                 EXI_E_INV_EVENT_CODE:          invalid/unknown event code\n
 *                 EXI_E_BUFFER_SIZE:             target buffer to small\n
 *                 EXI_E_DISABLED_FEATURE:        feature disabled\n
 *                 EXI_E_LIST_TO_LONG:            To many elements in a list or last NextPtr not NULL\n
 *                 EXI_E_ENUM_OUT_OF_RANGE:       Enumaration value is out of range\n
 *                 EXI_E_INV_STRUCT_POINTER:      Invalid pointer, this may happen if a flag is 1 but the element is NULL_PTR\n
 *                 EXI_E_INV_CHOICE_SELECTION:    Choice element selection is invalid, multiple flags are set\n
 *                 EXI_E_INCONSISTEN_PBUF:        The provided PBuf is not consistent regarding its length information
 *  \pre           The Exi has to be initialized with a call of Exi_Init and the provided Exi_EncodeWorkspaceType
 *                 has to be initializes with call to Exi_InitEncodeWorkspace first.
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \note          Encoding of large EXI streams may take several milliseconds, depending on the system performance.
 *********************************************************************************************************************/
extern FUNC(Exi_ReturnType, EXI_CODE) Exi_FinalizeExiStream( P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );

/**********************************************************************************************************************
 *  Exi_Decode
 *********************************************************************************************************************/
/*! \brief         Decode an EXI stream.
 *  \details       This function is used to decode an EXI stream and store the data structures in the decoding workspace
 *                 output storage.
 *  \param[in,out] DecWsPtr                    Pointer to EXI workspace containing the input and output data buffer
 *  \return        EXI_E_OK:                      Finished successfully\n
 *                 EXI_E_NOT_OK:                  undefined error\n
 *                 EXI_E_INV_HEADER:              invalid exi header\n
 *                 EXI_E_EOS:                     end of exi stream buffer\n
 *                 EXI_E_INT_OVERFLOW:            decoded integer too big for target buffer\n
 *                 EXI_E_ARR_OVERFLOW:            decoded array too big for target array\n
 *                 EXI_E_STRING_TABLE_LOCAL_HIT:  string empty, must be in local table\n
 *                 EXI_E_STRING_TABLE_GLOBAL_HIT: string empty, must be in global table\n
 *                 EXI_E_INV_EVENT_CODE:          invalid/unknown event code\n
 *                 EXI_E_BUFFER_SIZE:             target buffer to small\n
 *                 EXI_E_DISABLED_FEATURE:        feature disabled\n
 *                 EXI_E_LIST_TO_LONG:            To many elements in a list or last NextPtr not NULL\n
 *                 EXI_E_ENUM_OUT_OF_RANGE:       Enumaration value is out of range\n
 *                 EXI_E_INV_STRUCT_POINTER:      Invalid pointer, this may happen if a flag is 1 but the element is NULL_PTR\n
 *                 EXI_E_INV_CHOICE_SELECTION:    Choice element selection is invalid, multiple flags are set\n
 *                 EXI_E_INCONSISTEN_PBUF:        The provided PBuf is not consistent regarding its length information
 *  \pre           The Exi has to be initialized with a call of Exi_Init and the provided Exi_DecodeWorkspaceType
 *                 has to be initializes with call to Exi_InitDecodeWorkspace first.
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \note          Decoding of large EXI streams may take several milliseconds, depending on the system performance.
 *********************************************************************************************************************/
extern FUNC(Exi_ReturnType, EXI_CODE) Exi_Decode( P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr );

/**********************************************************************************************************************
 *  Exi_InitMemAllocWorkspace
 *********************************************************************************************************************/
/*! \brief         Initialize Exi_MemAllocWorkspaceType element.
 *  \details       This function is used to assign an existing buffer to an Exi_MemAllocWorkspaceType element.
 *  \param[in,out] MemAllocWorkspace           Pointer to workspace containing the buffer parameters
 *  \param[in]     BufferPtr                   Pointer to buffer which shall be referenced in workspace, must be 
 *                                             aligned at least to the pointer size of the platform
 *  \param[in]     BufferOffset                Current write offset of referenced buffer
 *  \param[in]     BufferSize                  Size of referenced buffer
 *  \return        EXI_E_OK                    Finished successfully
 *                 EXI_E_NOT_OK                Invalid input parameters given
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(Exi_ReturnType, EXI_CODE) Exi_InitMemAllocWorkspace(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, EXI_APPL_VAR) MemAllocWorkspace,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) BufferPtr,
  uint32 BufferOffset,
  uint32 BufferSize);

/**********************************************************************************************************************
 *  Exi_AllocateElementFromBufferWs
 *********************************************************************************************************************/
/*! \brief         Allocate buffer.
 *  \details       This function is used to allocate buffer within a buffer workspace for a given element size.
 *  \param[in,out] BufferWs                    Pointer to workspace containing the input and output data buffer
 *  \param[in]     ElementSize                 Size of the element to allocate buffer for
 *  \param[in]     IncrementStorageBuffer      True: Increment fill level. False: Do not increment.
 *  \return        NULL_PTR:                   Error storage buffer is too small
 *                 != NULL_PTR:                pointer to the allocated buffer
 *  \pre           The provided workspace must be initialized
 *  \context       TASK
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void*, EXI_CODE) Exi_AllocateElementFromBufferWs(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, EXI_APPL_VAR) BufferWs,
  uint32 ElementSize,
  Exi_BooleanType IncrementStorageBuffer);

/**********************************************************************************************************************
 *  Exi_GetRemainingBufferSizeFromBufferWs
 *********************************************************************************************************************/
/*! \brief         Get remaining buffer size.
 *  \details       This function is used to determine the remaining buffer size from a given buffer workspace.
 *  \param[in]     BufferWs                    Pointer to workspace containing the input and output data buffer
 *  \return        0:                          Invalid input parameters given or buffer is already full
 *                 >0:                         Remaining buffer size
 *  \pre           The provided workspace must be initialized
 *  \context       TASK
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(uint32, EXI_CODE) Exi_GetRemainingBufferSizeFromBufferWs(
  P2CONST(Exi_MemAllocWorkspaceType, AUTOMATIC, EXI_APPL_VAR) BufferWs);

/**********************************************************************************************************************
 *  Exi_IncrementBufferOffsetInBufferWs
 *********************************************************************************************************************/
/*! \brief         Increment buffer offset.
 *  \details       This function is used to increment the buffer offset of a given buffer workspace.
 *  \param[in,out] BufferWs                    Pointer to workspace containing the input and output data buffer
 *  \param[in]     BufferOffsetIncrement       Increment that is added up to current buffer offset
 *  \return        EXI_E_NOT_OK:               Invalid input parameters given
 *                 EXI_E_BUFFER_SIZE:          Current offset plus BufferOffsetIncrement would exceed buffer size
 *                 EXI_E_OK:                   Buffer offset has been incremented successfully
 *  \pre           The provided workspace must be initialized
 *  \context       TASK
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(Exi_ReturnType, EXI_CODE) Exi_IncrementBufferOffsetInBufferWs(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, EXI_APPL_VAR) BufferWs,
  uint32 BufferOffsetIncrement);

#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

#endif /* EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi.h
 *********************************************************************************************************************/
