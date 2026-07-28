/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Scc_ISO15118_20_Exi.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO15118-20.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_ISO15118_20_EXI_H)
# define SCC_ISO15118_20_EXI_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if (defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u))

#include "Scc_Types.h"
#include "Scc_Exi.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/
#if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )
# ifndef SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_URI
#  define SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_URI       "http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha512"              /* [V2G20-2473] */
# endif
# define SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_URI_LEN   (sizeof(SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_URI) - 1u)
# ifndef SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_SIGSIZE
#  define SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_SIGSIZE   132u
# endif
# ifndef SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_URI
#  define SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_URI      "http://www.w3.org/2001/04/xmlenc#sha512"                                  /* [V2G20-2475] */
# endif
# define SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_URI_LEN  (sizeof(SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_URI) - 1u)
# ifndef SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_DIGSIZE
#  define SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_DIGSIZE  64u                                                                        /* [V2G20-2475] */
# endif
#endif /* SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES */

#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
# ifndef SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_URI
#  define SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_URI       "urn:iso:std:iso:15118:-20:Security:xmldsig#Ed448"                       /* [V2G20-2474] */
# endif
# define SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_URI_LEN   (sizeof(SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_URI) - 1u)
# ifndef SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_SIGSIZE
#  define SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_SIGSIZE   114u
# endif
# ifndef SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_URI
#  define SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_URI      "urn:iso:std:iso:15118:-20:Security:xmlenc#SHAKE256"                     /* [V2G20-2476] */
# endif
# define SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_URI_LEN  (sizeof(SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_URI) - 1u)
# ifndef SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_DIGSIZE
#  define SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_DIGSIZE  64u
# endif
#endif /* SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES */

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiTx_SetupTxConfig
 *********************************************************************************************************************/
/*! \brief          Sets up the passed function pointer
 *  \details        -
 *  \param[out]     TxPrepMessagePtr      Function pointer to setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_ExiTx_SetupTxConfig(
  P2VAR(Scc_ExiTx_Xyz_PrepareMessageFctType, AUTOMATIC, SCC_APPL_DATA) TxPrepMessagePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiRx_SetupRxConfig
 *********************************************************************************************************************/
/*! \brief          Sets up the passed RxConfigPtr
 *  \details        Main entry point at start of ISO15118-20 based communication
 *  \param[out]     RxConfigPtr             Pointer to the configuration structure to setup
 *  \param[out]     SapSchemaID             SchemaID chosen by the EVSE
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_ExiRx_SetupRxConfig(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr,
  Scc_SAPSchemaIDType SapSchemaID);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiRx_CheckSessionId
 *********************************************************************************************************************/
/*! \brief          Checks the session id of the passed message
 *  \details        -
 *  \param[in]      SessionIdPtr               Pointer to the session Id
 *  \return         E_OK                       Session Id as expected
 *  \return         E_NOT_OK                   Session Id not as expected
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_ISO15118_20_ExiRx_CheckSessionId(
  P2CONST(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, SCC_APPL_DATA) SessionIdPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiTx_WriteSessionId
 *********************************************************************************************************************/
/*! \brief          Write the sessionId from Nvm to SessionIdPtr
 *  \details        -
 *  \param[in]      SessionIdPtr               Pointer to the session Id
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20_ExiTx_WriteSessionId(
  P2VAR(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, SCC_APPL_DATA) SessionIdPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiTx_WriteHeader
 *********************************************************************************************************************/
/*! \brief          Creates and writes the ISO15118-20 header to the buffer
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[out]     MessageHeaderPtrPtr     Pointer to the Tx message header.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_ExiTx_WriteHeader(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_20_CT_10_MessageHeaderType*, AUTOMATIC, SCC_APPL_DATA) MessageHeaderPtrPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiTx_CreateRationaleNumberType
 *********************************************************************************************************************/
/*! \brief          Creates a ISO-20 RationaleNumber type based on a Scc physical value type.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in]      ValuePtr                Pointer to the value that should be assigned.
 *  \param[out]     RationaleNumberTypePtr  Pointer to the RationaleNumberType that should be created.
 *  \return         Scc_ReturnType_OK       Data type was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_ExiTx_CreateRationaleNumberType(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) ValuePtr,
  P2VAR(Exi_ISO_20_CT_10_RationalNumberType*, AUTOMATIC, SCC_VAR_NOINIT) RationaleNumberTypePtr);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20 */

#endif /* SCC_ISO15118_20_EXI_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_Exi.h
 *********************************************************************************************************************/
