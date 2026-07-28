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
/**        \file  Exi_XMLSIG_SchemaTypes.h
 *        \brief  Efficient XML Interchange XMLSIG types header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component XMLSIG types.
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

#if !defined (EXI_XMLSIG_SCHEMA_TYPES_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_XMLSIG_SCHEMA_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_Types.h"

/* PRQA S 0779 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* PRQA S 0780 NAMESPACE */ /* MD_Exi_5.6 */
/* PRQA S 0750 UNION */ /* MD_Exi_18.4 */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Root elements */
#define EXI_XMLSIG_CANONICALIZATION_METHOD_TYPE                                          (Exi_RootElementIdType)203U
#define EXI_XMLSIG_DSAKEY_VALUE_TYPE                                                     (Exi_RootElementIdType)204U
#define EXI_XMLSIG_DIGEST_METHOD_TYPE                                                    (Exi_RootElementIdType)205U
#define EXI_XMLSIG_DIGEST_VALUE_TYPE                                                     (Exi_RootElementIdType)206U
#define EXI_XMLSIG_KEY_INFO_TYPE                                                         (Exi_RootElementIdType)207U
#define EXI_XMLSIG_KEY_NAME_TYPE                                                         (Exi_RootElementIdType)208U
#define EXI_XMLSIG_KEY_VALUE_TYPE                                                        (Exi_RootElementIdType)209U
#define EXI_XMLSIG_MANIFEST_TYPE                                                         (Exi_RootElementIdType)210U
#define EXI_XMLSIG_MGMT_DATA_TYPE                                                        (Exi_RootElementIdType)211U
#define EXI_XMLSIG_OBJECT_TYPE                                                           (Exi_RootElementIdType)212U
#define EXI_XMLSIG_PGPDATA_TYPE                                                          (Exi_RootElementIdType)213U
#define EXI_XMLSIG_RSAKEY_VALUE_TYPE                                                     (Exi_RootElementIdType)214U
#define EXI_XMLSIG_REFERENCE_TYPE                                                        (Exi_RootElementIdType)215U
#define EXI_XMLSIG_RETRIEVAL_METHOD_TYPE                                                 (Exi_RootElementIdType)216U
#define EXI_XMLSIG_SPKIDATA_TYPE                                                         (Exi_RootElementIdType)217U
#define EXI_XMLSIG_SIGNATURE_METHOD_TYPE                                                 (Exi_RootElementIdType)218U
#define EXI_XMLSIG_SIGNATURE_PROPERTIES_TYPE                                             (Exi_RootElementIdType)219U
#define EXI_XMLSIG_SIGNATURE_PROPERTY_TYPE                                               (Exi_RootElementIdType)220U
#define EXI_XMLSIG_SIGNATURE_TYPE                                                        (Exi_RootElementIdType)221U
#define EXI_XMLSIG_SIGNATURE_VALUE_TYPE                                                  (Exi_RootElementIdType)222U
#define EXI_XMLSIG_SIGNED_INFO_TYPE                                                      (Exi_RootElementIdType)223U
#define EXI_XMLSIG_TRANSFORM_TYPE                                                        (Exi_RootElementIdType)224U
#define EXI_XMLSIG_TRANSFORMS_TYPE                                                       (Exi_RootElementIdType)225U
#define EXI_XMLSIG_X509DATA_TYPE                                                         (Exi_RootElementIdType)226U

#if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* Elements */
#define EXI_XMLSIG_EXPONENT_TYPE                                                         (Exi_RootElementIdType)234U
#define EXI_XMLSIG_G_TYPE                                                                (Exi_RootElementIdType)235U
#define EXI_XMLSIG_HMACOUTPUT_LENGTH_TYPE                                                (Exi_RootElementIdType)236U
#define EXI_XMLSIG_J_TYPE                                                                (Exi_RootElementIdType)237U
#define EXI_XMLSIG_MODULUS_TYPE                                                          (Exi_RootElementIdType)238U
#define EXI_XMLSIG_P_TYPE                                                                (Exi_RootElementIdType)239U
#define EXI_XMLSIG_PGPKEY_ID_TYPE                                                        (Exi_RootElementIdType)240U
#define EXI_XMLSIG_PGPKEY_PACKET_TYPE                                                    (Exi_RootElementIdType)241U
#define EXI_XMLSIG_PGEN_COUNTER_TYPE                                                     (Exi_RootElementIdType)242U
#define EXI_XMLSIG_Q_TYPE                                                                (Exi_RootElementIdType)243U
#define EXI_XMLSIG_SPKISEXP_TYPE                                                         (Exi_RootElementIdType)244U
#define EXI_XMLSIG_SEED_TYPE                                                             (Exi_RootElementIdType)245U
#define EXI_XMLSIG_X509CRL_TYPE                                                          (Exi_RootElementIdType)246U
#define EXI_XMLSIG_X509CERTIFICATE_TYPE                                                  (Exi_RootElementIdType)247U
#define EXI_XMLSIG_X509ISSUER_NAME_TYPE                                                  (Exi_RootElementIdType)248U
#define EXI_XMLSIG_X509ISSUER_SERIAL_TYPE                                                (Exi_RootElementIdType)249U
#define EXI_XMLSIG_X509SKI_TYPE                                                          (Exi_RootElementIdType)250U
#define EXI_XMLSIG_X509SERIAL_NUMBER_TYPE                                                (Exi_RootElementIdType)251U
#define EXI_XMLSIG_X509SUBJECT_NAME_TYPE                                                 (Exi_RootElementIdType)252U
#define EXI_XMLSIG_XPATH_TYPE                                                            (Exi_RootElementIdType)253U
#define EXI_XMLSIG_Y_TYPE                                                                (Exi_RootElementIdType)254U
#define EXI_SCHEMA_SET_XMLSIG_TYPE                                                       (Exi_RootElementIdType)1U
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEENCODING
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEENCODING EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEID
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEID EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEMIMETYPE
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEMIMETYPE EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTETARGET
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTETARGET EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTETYPE
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTETYPE EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEURI
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEURI EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_CRYPTOBINARY
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_CRYPTOBINARY EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_DIGESTVALUE
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_DIGESTVALUE EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_KEYNAME
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_KEYNAME EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_MGMTDATA
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_MGMTDATA EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif
#ifndef EXI_MAX_BUFFER_SIZE_XMLSIG_SIGNATUREVALUE
  #define EXI_MAX_BUFFER_SIZE_XMLSIG_SIGNATUREVALUE EXI_MAX_BUFFER_SIZE_UNBOUNDED
#endif

/**********************************************************************************************************************
 *  ELEMENT IDENTIFIER DEFINES
**********************************************************************************************************************/
#define EXI_XMLSIG_EI_ATTRIBUTE_ALGORITHM                                (uint16)0U
#define EXI_XMLSIG_EI_ATTRIBUTE_ALGORITHM_SE                             (uint16)1U
#define EXI_XMLSIG_EI_ATTRIBUTE_ALGORITHM_CT                             (uint16)2U
#define EXI_XMLSIG_EI_ATTRIBUTE_ALGORITHM_EE                             (uint16)3U
#define EXI_XMLSIG_EI_ATTRIBUTE_ALGORITHM_AT                             (uint16)4U
#define EXI_XMLSIG_EI_ATTRIBUTE_ID                                       (uint16)5U
#define EXI_XMLSIG_EI_ATTRIBUTE_ID_SE                                    (uint16)6U
#define EXI_XMLSIG_EI_ATTRIBUTE_ID_CT                                    (uint16)7U
#define EXI_XMLSIG_EI_ATTRIBUTE_ID_EE                                    (uint16)8U
#define EXI_XMLSIG_EI_ATTRIBUTE_ID_AT                                    (uint16)9U
#define EXI_XMLSIG_EI_ATTRIBUTE                                          (uint16)10U
#define EXI_XMLSIG_EI_ATTRIBUTE_SE                                       (uint16)11U
#define EXI_XMLSIG_EI_ATTRIBUTE_CT                                       (uint16)12U
#define EXI_XMLSIG_EI_ATTRIBUTE_EE                                       (uint16)13U
#define EXI_XMLSIG_EI_ATTRIBUTE_AT                                       (uint16)14U
#define EXI_XMLSIG_EI_ATTRIBUTE_URI                                      (uint16)15U
#define EXI_XMLSIG_EI_ATTRIBUTE_URI_SE                                   (uint16)16U
#define EXI_XMLSIG_EI_ATTRIBUTE_URI_CT                                   (uint16)17U
#define EXI_XMLSIG_EI_ATTRIBUTE_URI_EE                                   (uint16)18U
#define EXI_XMLSIG_EI_ATTRIBUTE_URI_AT                                   (uint16)19U
#define EXI_XMLSIG_EI_ALGORITHM                                          (uint16)20U
#define EXI_XMLSIG_EI_ALGORITHM_SE                                       (uint16)21U
#define EXI_XMLSIG_EI_ALGORITHM_CT                                       (uint16)22U
#define EXI_XMLSIG_EI_ALGORITHM_EE                                       (uint16)23U
#define EXI_XMLSIG_EI_ALGORITHM_AT                                       (uint16)24U
#define EXI_XMLSIG_EI_GENERIC_ELEMENT                                    (uint16)25U
#define EXI_XMLSIG_EI_GENERIC_ELEMENT_SE                                 (uint16)26U
#define EXI_XMLSIG_EI_GENERIC_ELEMENT_CT                                 (uint16)27U
#define EXI_XMLSIG_EI_GENERIC_ELEMENT_EE                                 (uint16)28U
#define EXI_XMLSIG_EI_GENERIC_ELEMENT_AT                                 (uint16)29U
#define EXI_XMLSIG_EI_DIGEST_VALUE                                       (uint16)30U
#define EXI_XMLSIG_EI_DIGEST_VALUE_SE                                    (uint16)31U
#define EXI_XMLSIG_EI_DIGEST_VALUE_CT                                    (uint16)32U
#define EXI_XMLSIG_EI_DIGEST_VALUE_EE                                    (uint16)33U
#define EXI_XMLSIG_EI_DIGEST_VALUE_AT                                    (uint16)34U
#define EXI_XMLSIG_EI_ID                                                 (uint16)35U
#define EXI_XMLSIG_EI_ID_SE                                              (uint16)36U
#define EXI_XMLSIG_EI_ID_CT                                              (uint16)37U
#define EXI_XMLSIG_EI_ID_EE                                              (uint16)38U
#define EXI_XMLSIG_EI_ID_AT                                              (uint16)39U
#define EXI_XMLSIG_EI_TYPE                                               (uint16)40U
#define EXI_XMLSIG_EI_TYPE_SE                                            (uint16)41U
#define EXI_XMLSIG_EI_TYPE_CT                                            (uint16)42U
#define EXI_XMLSIG_EI_TYPE_EE                                            (uint16)43U
#define EXI_XMLSIG_EI_TYPE_AT                                            (uint16)44U
#define EXI_XMLSIG_EI_URI                                                (uint16)45U
#define EXI_XMLSIG_EI_URI_SE                                             (uint16)46U
#define EXI_XMLSIG_EI_URI_CT                                             (uint16)47U
#define EXI_XMLSIG_EI_URI_EE                                             (uint16)48U
#define EXI_XMLSIG_EI_URI_AT                                             (uint16)49U
#define EXI_XMLSIG_EI_TRANSFORMS                                         (uint16)50U
#define EXI_XMLSIG_EI_TRANSFORMS_SE                                      (uint16)51U
#define EXI_XMLSIG_EI_TRANSFORMS_CT                                      (uint16)52U
#define EXI_XMLSIG_EI_TRANSFORMS_EE                                      (uint16)53U
#define EXI_XMLSIG_EI_TRANSFORMS_AT                                      (uint16)54U
#define EXI_XMLSIG_EI_DIGEST_METHOD                                      (uint16)55U
#define EXI_XMLSIG_EI_DIGEST_METHOD_SE                                   (uint16)56U
#define EXI_XMLSIG_EI_DIGEST_METHOD_CT                                   (uint16)57U
#define EXI_XMLSIG_EI_DIGEST_METHOD_EE                                   (uint16)58U
#define EXI_XMLSIG_EI_DIGEST_METHOD_AT                                   (uint16)59U
#define EXI_XMLSIG_EI_REFERENCE                                          (uint16)60U
#define EXI_XMLSIG_EI_REFERENCE_SE                                       (uint16)61U
#define EXI_XMLSIG_EI_REFERENCE_CT                                       (uint16)62U
#define EXI_XMLSIG_EI_REFERENCE_EE                                       (uint16)63U
#define EXI_XMLSIG_EI_REFERENCE_AT                                       (uint16)64U
#define EXI_XMLSIG_EI_HMACOUTPUT_LENGTH                                  (uint16)65U
#define EXI_XMLSIG_EI_HMACOUTPUT_LENGTH_SE                               (uint16)66U
#define EXI_XMLSIG_EI_HMACOUTPUT_LENGTH_CT                               (uint16)67U
#define EXI_XMLSIG_EI_HMACOUTPUT_LENGTH_EE                               (uint16)68U
#define EXI_XMLSIG_EI_HMACOUTPUT_LENGTH_AT                               (uint16)69U
#define EXI_XMLSIG_EI_SIGNED_INFO                                        (uint16)70U
#define EXI_XMLSIG_EI_SIGNED_INFO_SE                                     (uint16)71U
#define EXI_XMLSIG_EI_SIGNED_INFO_CT                                     (uint16)72U
#define EXI_XMLSIG_EI_SIGNED_INFO_EE                                     (uint16)73U
#define EXI_XMLSIG_EI_SIGNED_INFO_AT                                     (uint16)74U
#define EXI_XMLSIG_EI_SIGNATURE_VALUE                                    (uint16)75U
#define EXI_XMLSIG_EI_SIGNATURE_VALUE_SE                                 (uint16)76U
#define EXI_XMLSIG_EI_SIGNATURE_VALUE_CT                                 (uint16)77U
#define EXI_XMLSIG_EI_SIGNATURE_VALUE_EE                                 (uint16)78U
#define EXI_XMLSIG_EI_SIGNATURE_VALUE_AT                                 (uint16)79U
#define EXI_XMLSIG_EI_KEY_INFO                                           (uint16)80U
#define EXI_XMLSIG_EI_KEY_INFO_SE                                        (uint16)81U
#define EXI_XMLSIG_EI_KEY_INFO_CT                                        (uint16)82U
#define EXI_XMLSIG_EI_KEY_INFO_EE                                        (uint16)83U
#define EXI_XMLSIG_EI_KEY_INFO_AT                                        (uint16)84U
#define EXI_XMLSIG_EI_OBJECT                                             (uint16)85U
#define EXI_XMLSIG_EI_OBJECT_SE                                          (uint16)86U
#define EXI_XMLSIG_EI_OBJECT_CT                                          (uint16)87U
#define EXI_XMLSIG_EI_OBJECT_EE                                          (uint16)88U
#define EXI_XMLSIG_EI_OBJECT_AT                                          (uint16)89U
#define EXI_XMLSIG_EI_CANONICALIZATION_METHOD                            (uint16)90U
#define EXI_XMLSIG_EI_CANONICALIZATION_METHOD_SE                         (uint16)91U
#define EXI_XMLSIG_EI_CANONICALIZATION_METHOD_CT                         (uint16)92U
#define EXI_XMLSIG_EI_CANONICALIZATION_METHOD_EE                         (uint16)93U
#define EXI_XMLSIG_EI_CANONICALIZATION_METHOD_AT                         (uint16)94U
#define EXI_XMLSIG_EI_SIGNATURE_METHOD                                   (uint16)95U
#define EXI_XMLSIG_EI_SIGNATURE_METHOD_SE                                (uint16)96U
#define EXI_XMLSIG_EI_SIGNATURE_METHOD_CT                                (uint16)97U
#define EXI_XMLSIG_EI_SIGNATURE_METHOD_EE                                (uint16)98U
#define EXI_XMLSIG_EI_SIGNATURE_METHOD_AT                                (uint16)99U
#define EXI_XMLSIG_EI_CHOICE_ELEMENT                                     (uint16)100U
#define EXI_XMLSIG_EI_CHOICE_ELEMENT_SE                                  (uint16)101U
#define EXI_XMLSIG_EI_CHOICE_ELEMENT_CT                                  (uint16)102U
#define EXI_XMLSIG_EI_CHOICE_ELEMENT_EE                                  (uint16)103U
#define EXI_XMLSIG_EI_CHOICE_ELEMENT_AT                                  (uint16)104U
#define EXI_XMLSIG_EI_TRANSFORM                                          (uint16)105U
#define EXI_XMLSIG_EI_TRANSFORM_SE                                       (uint16)106U
#define EXI_XMLSIG_EI_TRANSFORM_CT                                       (uint16)107U
#define EXI_XMLSIG_EI_TRANSFORM_EE                                       (uint16)108U
#define EXI_XMLSIG_EI_TRANSFORM_AT                                       (uint16)109U
#define EXI_XMLSIG_EI_X509ISSUER_NAME                                    (uint16)110U
#define EXI_XMLSIG_EI_X509ISSUER_NAME_SE                                 (uint16)111U
#define EXI_XMLSIG_EI_X509ISSUER_NAME_CT                                 (uint16)112U
#define EXI_XMLSIG_EI_X509ISSUER_NAME_EE                                 (uint16)113U
#define EXI_XMLSIG_EI_X509ISSUER_NAME_AT                                 (uint16)114U
#define EXI_XMLSIG_EI_X509SERIAL_NUMBER                                  (uint16)115U
#define EXI_XMLSIG_EI_X509SERIAL_NUMBER_SE                               (uint16)116U
#define EXI_XMLSIG_EI_X509SERIAL_NUMBER_CT                               (uint16)117U
#define EXI_XMLSIG_EI_X509SERIAL_NUMBER_EE                               (uint16)118U
#define EXI_XMLSIG_EI_X509SERIAL_NUMBER_AT                               (uint16)119U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct Exi_XMLSIG_DigestValueType Exi_XMLSIG_DigestValueType;
struct Exi_XMLSIG_DigestValueType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_XMLSIG_DIGESTVALUE];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_DIGESTVALUE ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_DIGESTVALUE ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_XMLSIG_DIGESTVALUE ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_XMLSIG_AttributeIdType Exi_XMLSIG_AttributeIdType;
struct Exi_XMLSIG_AttributeIdType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEID];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEID ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEID ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEID ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_XMLSIG_AttributeAlgorithmType Exi_XMLSIG_AttributeAlgorithmType;
struct Exi_XMLSIG_AttributeAlgorithmType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_XMLSIG_AttributeURIType Exi_XMLSIG_AttributeURIType;
struct Exi_XMLSIG_AttributeURIType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEURI];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEURI ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEURI ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEURI ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_XMLSIG_AttributeType Exi_XMLSIG_AttributeType;
struct Exi_XMLSIG_AttributeType
{
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTETYPE];
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTETYPE ) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTETYPE ) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTETYPE ) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_XMLSIG_SignatureValueType Exi_XMLSIG_SignatureValueType;
struct Exi_XMLSIG_SignatureValueType
{
  Exi_XMLSIG_AttributeIdType* Id;
  uint16 Length;
  uint8 Buffer[EXI_MAX_BUFFER_SIZE_XMLSIG_SIGNATUREVALUE];
  Exi_BitType IdFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_SIGNATUREVALUE ) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( ( EXI_MAX_BUFFER_SIZE_XMLSIG_SIGNATUREVALUE ) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( ( EXI_MAX_BUFFER_SIZE_XMLSIG_SIGNATUREVALUE ) + (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) + 2u ) % 4u)];
# endif
#endif 
};

typedef struct Exi_XMLSIG_TransformChoiceType Exi_XMLSIG_TransformChoiceType;

typedef struct Exi_XMLSIG_X509DataChoiceType Exi_XMLSIG_X509DataChoiceType;

typedef struct Exi_XMLSIG_CanonicalizationMethodType Exi_XMLSIG_CanonicalizationMethodType;

typedef struct Exi_XMLSIG_SignatureMethodType Exi_XMLSIG_SignatureMethodType;

typedef struct Exi_XMLSIG_TransformType Exi_XMLSIG_TransformType;

typedef struct Exi_XMLSIG_TransformsType Exi_XMLSIG_TransformsType;

typedef struct Exi_XMLSIG_DigestMethodType Exi_XMLSIG_DigestMethodType;

typedef struct Exi_XMLSIG_ReferenceType Exi_XMLSIG_ReferenceType;

typedef struct Exi_XMLSIG_SignedInfoType Exi_XMLSIG_SignedInfoType;

typedef struct Exi_XMLSIG_X509IssuerSerialType Exi_XMLSIG_X509IssuerSerialType;

typedef struct Exi_XMLSIG_SignatureType Exi_XMLSIG_SignatureType;

/* Exi_XMLSIG_CryptoBinaryType has been disabled */

/* Exi_XMLSIG_GenericElementType has been disabled */

struct Exi_XMLSIG_CanonicalizationMethodType
{
  Exi_XMLSIG_AttributeAlgorithmType* Algorithm;
  Exi_BitType GenericElementFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_XMLSIG_SignatureMethodType
{
  Exi_XMLSIG_AttributeAlgorithmType* Algorithm;
  Exi_BigIntType* HMACOutputLength;
  Exi_BitType GenericElementFlag : 1;
  Exi_BitType HMACOutputLengthFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_XMLSIG_TransformChoiceType
{
  union
  {
    Exi_stringType* XPath;
  } ChoiceValue;
  struct Exi_XMLSIG_TransformChoiceType* NextChoiceElementPtr;
  Exi_BitType XPathFlag : 1;
  Exi_BitType GenericElementFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_XMLSIG_TransformType
{
  Exi_XMLSIG_AttributeAlgorithmType* Algorithm;
  Exi_XMLSIG_TransformChoiceType* ChoiceElement;
  struct Exi_XMLSIG_TransformType* NextTransformPtr;
  Exi_BitType ChoiceElementFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_XMLSIG_TransformsType
{
  Exi_XMLSIG_TransformType* Transform;
};

struct Exi_XMLSIG_DigestMethodType
{
  Exi_XMLSIG_AttributeAlgorithmType* Algorithm;
  Exi_BitType GenericElementFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_XMLSIG_ReferenceType
{
  Exi_XMLSIG_DigestMethodType* DigestMethod;
  Exi_XMLSIG_DigestValueType* DigestValue;
  Exi_XMLSIG_AttributeIdType* Id;
  struct Exi_XMLSIG_ReferenceType* NextReferencePtr;
  Exi_XMLSIG_TransformsType* Transforms;
  Exi_XMLSIG_AttributeType* Type;
  Exi_XMLSIG_AttributeURIType* URI;
  Exi_BitType IdFlag : 1;
  Exi_BitType TransformsFlag : 1;
  Exi_BitType TypeFlag : 1;
  Exi_BitType URIFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

struct Exi_XMLSIG_SignedInfoType
{
  Exi_XMLSIG_CanonicalizationMethodType* CanonicalizationMethod;
  Exi_XMLSIG_AttributeIdType* Id;
  Exi_XMLSIG_ReferenceType* Reference;
  Exi_XMLSIG_SignatureMethodType* SignatureMethod;
  Exi_BitType IdFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

/* Exi_XMLSIG_KeyNameType has been disabled */

/* Exi_XMLSIG_DSAKeyValueType has been disabled */

/* Exi_XMLSIG_RSAKeyValueType has been disabled */

/* Exi_XMLSIG_KeyValueChoiceType has been disabled */

/* Exi_XMLSIG_KeyValueType has been disabled */

/* Exi_XMLSIG_RetrievalMethodType has been disabled */

struct Exi_XMLSIG_X509IssuerSerialType
{
  struct Exi_XMLSIG_X509IssuerSerialType* NextRootCertificateIDPtr;
  Exi_stringType* X509IssuerName;
  Exi_BigIntType* X509SerialNumber;
};

struct Exi_XMLSIG_X509DataChoiceType
{
  union
  {
    Exi_base64BinaryType* X509CRL;
    Exi_base64BinaryType* X509Certificate;
    Exi_XMLSIG_X509IssuerSerialType* X509IssuerSerial;
    Exi_base64BinaryType* X509SKI;
    Exi_stringType* X509SubjectName;
  } ChoiceValue;
  struct Exi_XMLSIG_X509DataChoiceType* NextChoiceElementPtr;
  Exi_BitType X509CRLFlag : 1;
  Exi_BitType X509CertificateFlag : 1;
  Exi_BitType X509IssuerSerialFlag : 1;
  Exi_BitType X509SKIFlag : 1;
  Exi_BitType X509SubjectNameFlag : 1;
  Exi_BitType GenericElementFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

/* Exi_XMLSIG_X509DataType has been disabled */

/* Exi_XMLSIG_PGPDataChoiceSeq0Type has been disabled */

/* Exi_XMLSIG_PGPDataChoiceSeq1Type has been disabled */

/* Exi_XMLSIG_PGPDataChoiceType has been disabled */

/* Exi_XMLSIG_PGPDataType has been disabled */

/* Exi_XMLSIG_SPKIDataType has been disabled */

/* Exi_XMLSIG_MgmtDataType has been disabled */

/* Exi_XMLSIG_KeyInfoChoiceType has been disabled */

/* Exi_XMLSIG_KeyInfoType has been disabled */

/* Exi_XMLSIG_AttributeMimeType has been disabled */

/* Exi_XMLSIG_AttributeEncodingType has been disabled */

/* Exi_XMLSIG_ObjectType has been disabled */

struct Exi_XMLSIG_SignatureType
{
  Exi_XMLSIG_AttributeIdType* Id;
  Exi_XMLSIG_SignatureValueType* SignatureValue;
  Exi_XMLSIG_SignedInfoType* SignedInfo;
  Exi_BitType IdFlag : 1;
  Exi_BitType KeyInfoFlag : 1;
  Exi_BitType ObjectFlag : 1;
#if (EXI_STRUCTURE_PADDING_16BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 2u ) != 0u )
  uint8 Exi_Padding16Bit[1];
# endif
#endif 
#if (EXI_STRUCTURE_PADDING_32BIT_ENABLE == STD_ON)
# if ( ( ( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u ) != 0u )
  uint8 Exi_Padding32Bit[4u - (( (1u * EXI_STRUCTURE_PADDING_BIT_FIELD_SIZE_BYTE) ) % 4u)];
# endif
#endif 
};

/* Exi_XMLSIG_ManifestType has been disabled */

/* Exi_XMLSIG_AttributeTargetType has been disabled */

/* Exi_XMLSIG_SignaturePropertyChoiceType has been disabled */

/* Exi_XMLSIG_SignaturePropertyType has been disabled */

/* Exi_XMLSIG_SignaturePropertiesType has been disabled */
#endif  /* EXI_ENABLE_XMLSIG_MESSAGE_SET */

/* PRQA L:IDENTIFIER_NAMES */
/* PRQA L:NAMESPACE */
/* PRQA L:UNION */


#endif /* EXI_XMLSIG_SCHEMA_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Exi_XMLSIG_SchemaTypes.h
 **********************************************************************************************************************/
