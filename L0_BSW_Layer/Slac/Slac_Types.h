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
/*!        \file  Slac_Types.h
 *        \brief  Slac types header file
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 **********************************************************************************************************************/

#if !defined (SLAC_TYPES_H)
#define SLAC_TYPES_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
# include "Slac_Cfg.h"
# include "ComStack_Types.h"
# include "Eth_GeneralTypes.h"
# include "EthTrcv_GeneralTypes.h"
# include "EthIf_Types.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
# define SLAC_ETHIF_TX_CONF_REQUIRED FALSE
# define SLAC_FLAG_ENABLED  1u
# define SLAC_FLAG_DISABLED 1u

# define SLAC_HPGP_MME_TYPE 0x88E1u
# define SLAC_ETH_FRAME_PRIORITY 0u

# define SLAC_INVALID_AVERAGE_ATTENUATION_VALUE 0xFFu

/*** Message elements ***/
/** General **/
# define SLAC_MME_SUPPORT_VERSION        0x01u
# define SLAC_MME_SUPPORT_FRAGMENTATION  0x00u
# define SLAC_MME_GENERIC_HEADER_LEN        5u
# define SLAC_MME_RUN_ID_LEN                8u
# define SLAC_MME_NODE_ID_LEN              17u /* Used for SENDER_ID, SOURCE_ID, RESP_ID, PEV_ID and EVSE_ID */
# define SLAC_MME_RSVD_LEN                  8u
# define SLAC_MME_RND_LEN                  16u
# define SLAC_MME_NID_LEN         SLAC_NID_LEN
# define SLAC_MME_NMK_LEN         SLAC_NMK_LEN
# define SLAC_MME_NONCE_LEN                 4u
# define SLAC_MME_PRN_LEN                   2u
/* Message fixed values */
# define SLAC_MME_APPLICATION_TYPE_VALUE                0x00u
# define SLAC_MME_SECURITY_TYPE_VALUE                   0x00u
# define SLAC_MME_TIME_OUT_VALUE                        0x06u
# define SLAC_MME_RESP_TYPE_VALUE                       0x01u
# define SLAC_MME_NODE_ID_VALUE                         0x00u /* Used for SENDER_ID, SOURCE_ID, RESP_ID, PEV_ID and EVSE_ID */
# define SLAC_MME_RSVD_VALUE                            0x00u
# define SLAC_MME_ATTEN_PROFILE_NUM_GROUPS_VALUE        0x3Au /* 58 */
# define SLAC_MME_SIGNAL_TYPE_EV_S2_TOGGLES_ON_CP_VALUE 0x00u
# define SLAC_MME_MATCH_REQ_MVF_LENGTH_VALUE            0x3Eu /* 62 */
# define SLAC_MME_MATCH_CNF_MVF_LENGTH_VALUE            0x56u /* 86 */
# define SLAC_MME_NID_INVALID_VALUE                     0x00u
# define SLAC_MME_NMK_INVALID_VALUE                     0x00u
# define SLAC_MME_KEY_TYPE_VALUE                        0x01u
# define SLAC_MME_NONCE_VALUE                           0x00u
# define SLAC_MME_PID_VALUE                             0x04u
# define SLAC_MME_PRN_VALUE                             0x00u
# define SLAC_MME_PMN_VALUE                             0x00u
# define SLAC_MME_NEW_EKS_VALUE                         0x01u

/** Message specific **/
/* CM_SLAC_PARM.REQ */
# define SLAC_MME_CM_SLAC_PARM_REQ_LENGTH                        (SLAC_MME_GENERIC_HEADER_LEN + 10u)
# define SLAC_MME_CM_SLAC_PARM_REQ_LENGTH_PAD32                  (SLAC_MME_CM_SLAC_PARM_REQ_LENGTH + 1u)
# define SLAC_MME_CM_SLAC_PARM_REQ_APPLICATION_TYPE_POS          (SLAC_MME_GENERIC_HEADER_LEN + 0u) /* Length: 1; Value: SLAC_MME_APPLICATION_TYPE_VALUE */
# define SLAC_MME_CM_SLAC_PARM_REQ_SECURITY_TYPE_POS             (SLAC_MME_GENERIC_HEADER_LEN + 1u) /* Length: 1; Value: SLAC_MME_SECURITY_TYPE_VALUE */
# define SLAC_MME_CM_SLAC_PARM_REQ_RUN_ID_POS                    (SLAC_MME_GENERIC_HEADER_LEN + 2u) /* Length: 8; Value: Random */
/* CM_SLAC_PARM.CNF */
# define SLAC_MME_CM_SLAC_PARM_CNF_LENGTH                        (SLAC_MME_GENERIC_HEADER_LEN + 25u)
# define SLAC_MME_CM_SLAC_PARM_CNF_LENGTH_PAD32                  (SLAC_MME_CM_SLAC_PARM_CNF_LENGTH + 2u)
# define SLAC_MME_CM_SLAC_PARM_CNF_M_SOUND_TARGET_POS            (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length: 6; Value: Slac_BroadcastPhysAddress */
# define SLAC_MME_CM_SLAC_PARM_CNF_NUM_SOUNDS_POS                (SLAC_MME_GENERIC_HEADER_LEN +  6u) /* Length: 1; Value: SLAC_CFG_MSG_C_EV_MATCH_MNBC_MIN <= Value <= SLAC_CFG_MSG_C_EV_MATCH_MNBC_MAX */
# define SLAC_MME_CM_SLAC_PARM_CNF_TIME_OUT_POS                  (SLAC_MME_GENERIC_HEADER_LEN +  7u) /* Length: 1; Value: SLAC_MME_TIME_OUT_TYPE_VALUE */
# define SLAC_MME_CM_SLAC_PARM_CNF_RESP_TYPE_POS                 (SLAC_MME_GENERIC_HEADER_LEN +  8u) /* Length: 1; Value: SLAC_MME_RESP_TYPE_VALUE */
# define SLAC_MME_CM_SLAC_PARM_CNF_FORWARDING_STA_POS            (SLAC_MME_GENERIC_HEADER_LEN +  9u) /* Length: 6; Value: EV MAC */
# define SLAC_MME_CM_SLAC_PARM_CNF_APPLICATION_TYPE_POS          (SLAC_MME_GENERIC_HEADER_LEN + 15u) /* Length: 1; Value: SLAC_MME_APPLICATION_TYPE_VALUE */
# define SLAC_MME_CM_SLAC_PARM_CNF_SECURITY_TYPE_POS             (SLAC_MME_GENERIC_HEADER_LEN + 16u) /* Length: 1; Value: SLAC_MME_SECURITY_TYPE_VALUE */
# define SLAC_MME_CM_SLAC_PARM_CNF_RUN_ID_POS                    (SLAC_MME_GENERIC_HEADER_LEN + 17u) /* Length: 8; Value: Value of CM_SLAC_PARM.REQ */
/* CM_START_ATTEN_CHAR.IND */
# define SLAC_MME_CM_START_ATTEN_CHAR_IND_LENGTH                 (SLAC_MME_GENERIC_HEADER_LEN + 19u)
# define SLAC_MME_CM_START_ATTEN_CHAR_IND_LENGTH_PAD32           (SLAC_MME_CM_START_ATTEN_CHAR_IND_LENGTH + 0u)
# define SLAC_MME_CM_START_ATTEN_CHAR_IND_APPLICATION_TYPE_POS   (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length: 1; Value: SLAC_MME_APPLICATION_TYPE_VALUE */
# define SLAC_MME_CM_START_ATTEN_CHAR_IND_SECURITY_TYPE_POS      (SLAC_MME_GENERIC_HEADER_LEN +  1u) /* Length: 1; Value: SLAC_MME_SECURITY_TYPE_VALUE */
# define SLAC_MME_CM_START_ATTEN_CHAR_IND_NUM_SOUNDS_POS         (SLAC_MME_GENERIC_HEADER_LEN +  2u) /* Length: 1; Value: Biggest valid EVSE value */
# define SLAC_MME_CM_START_ATTEN_CHAR_IND_TIME_OUT_POS           (SLAC_MME_GENERIC_HEADER_LEN +  3u) /* Length: 1; Value: SLAC_MME_TIME_OUT_TYPE_VALUE */
# define SLAC_MME_CM_START_ATTEN_CHAR_IND_RESP_TYPE_POS          (SLAC_MME_GENERIC_HEADER_LEN +  4u) /* Length: 1; Value: SLAC_MME_RESP_TYPE_VALUE */
# define SLAC_MME_CM_START_ATTEN_CHAR_IND_FORWARDING_STA_POS     (SLAC_MME_GENERIC_HEADER_LEN +  5u) /* Length: 6; Value: EV MAC */
# define SLAC_MME_CM_START_ATTEN_CHAR_IND_RUN_ID_POS             (SLAC_MME_GENERIC_HEADER_LEN + 11u) /* Length: 8; Value: Value of CM_SLAC_PARM.REQ */
/* CM_MNBC_SOUND.IND */
# define SLAC_MME_CM_MNBC_SOUND_IND_LENGTH                       (SLAC_MME_GENERIC_HEADER_LEN + 52u)
# define SLAC_MME_CM_MNBC_SOUND_IND_LENGTH_PAD32                 (SLAC_MME_CM_MNBC_SOUND_IND_LENGTH + 3u)
# define SLAC_MME_CM_MNBC_SOUND_IND_APPLICATION_TYPE_POS         (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:  1; Value: SLAC_MME_APPLICATION_TYPE_VALUE */
# define SLAC_MME_CM_MNBC_SOUND_IND_SECURITY_TYPE_POS            (SLAC_MME_GENERIC_HEADER_LEN +  1u) /* Length:  1; Value: SLAC_MME_SECURITY_TYPE_VALUE */
# define SLAC_MME_CM_MNBC_SOUND_IND_SENDER_ID_POS                (SLAC_MME_GENERIC_HEADER_LEN +  2u) /* Length: 17; Value: Set to all SLAC_MME_NODE_ID_VALUE */
# define SLAC_MME_CM_MNBC_SOUND_IND_CNT_POS                      (SLAC_MME_GENERIC_HEADER_LEN + 19u) /* Length:  1; Value: Number of remaining SOUNDS */
# define SLAC_MME_CM_MNBC_SOUND_IND_RUN_ID_POS                   (SLAC_MME_GENERIC_HEADER_LEN + 20u) /* Length:  8; Value: Value of CM_SLAC_PARM.REQ */
# define SLAC_MME_CM_MNBC_SOUND_IND_RSVD_POS                     (SLAC_MME_GENERIC_HEADER_LEN + 28u) /* Length:  8; Value: Set to all SLAC_MME_RSVD_VALUE */
# define SLAC_MME_CM_MNBC_SOUND_IND_RND_POS                      (SLAC_MME_GENERIC_HEADER_LEN + 36u) /* Length: 16; Value: Random value per message */
/* CM_ATTEN_CHAR.IND */
# define SLAC_MME_CM_ATTEN_CHAR_IND_LENGTH                       (SLAC_MME_GENERIC_HEADER_LEN + 110u)
# define SLAC_MME_CM_ATTEN_CHAR_IND_LENGTH_PAD32                 (SLAC_MME_CM_ATTEN_CHAR_IND_LENGTH + 1u)
# define SLAC_MME_CM_ATTEN_CHAR_IND_APPLICATION_TYPE_POS         (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:  1; Value: SLAC_MME_APPLICATION_TYPE_VALUE */
# define SLAC_MME_CM_ATTEN_CHAR_IND_SECURITY_TYPE_POS            (SLAC_MME_GENERIC_HEADER_LEN +  1u) /* Length:  1; Value: SLAC_MME_SECURITY_TYPE_VALUE */
# define SLAC_MME_CM_ATTEN_CHAR_IND_SOURCE_ADDRESS_POS           (SLAC_MME_GENERIC_HEADER_LEN +  2u) /* Length:  6; Value: EV MAC */
# define SLAC_MME_CM_ATTEN_CHAR_IND_RUN_ID_POS                   (SLAC_MME_GENERIC_HEADER_LEN +  8u) /* Length:  8; Value: Value of CM_SLAC_PARM.REQ */
# define SLAC_MME_CM_ATTEN_CHAR_IND_SOURCE_ID_POS                (SLAC_MME_GENERIC_HEADER_LEN + 16u) /* Length: 17; Value: Set to all SLAC_MME_NODE_ID_VALUE */
# define SLAC_MME_CM_ATTEN_CHAR_IND_RESP_ID_POS                  (SLAC_MME_GENERIC_HEADER_LEN + 33u) /* Length: 17; Value: Set to all SLAC_MME_NODE_ID_VALUE */
# define SLAC_MME_CM_ATTEN_CHAR_IND_NUM_SOUNDS_POS               (SLAC_MME_GENERIC_HEADER_LEN + 50u) /* Length:  1; Value: Number of soundings used */
# define SLAC_MME_CM_ATTEN_CHAR_IND_ATTEN_PROFILE_NUM_GROUPS_POS (SLAC_MME_GENERIC_HEADER_LEN + 51u) /* Length:  1; Value: SLAC_MME_ATTEN_PROFILE_NUM_GROUPS_VALUE */
# define SLAC_MME_CM_ATTEN_CHAR_IND_ATTEN_PROFILE_AAGS_POS       (SLAC_MME_GENERIC_HEADER_LEN + 52u) /* Length: 58; Value: Measured attenuation values */
/* CM_ATTEN_CHAR.RSP */
# define SLAC_MME_CM_ATTEN_CHAR_RSP_LENGTH                       (SLAC_MME_GENERIC_HEADER_LEN + 51u)
# define SLAC_MME_CM_ATTEN_CHAR_RSP_LENGTH_PAD32                 (SLAC_MME_CM_ATTEN_CHAR_RSP_LENGTH + 0u)
# define SLAC_MME_CM_ATTEN_CHAR_RSP_APPLICATION_TYPE_POS         (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:  1; Value: SLAC_MME_APPLICATION_TYPE_VALUE */
# define SLAC_MME_CM_ATTEN_CHAR_RSP_SECURITY_TYPE_POS            (SLAC_MME_GENERIC_HEADER_LEN +  1u) /* Length:  1; Value: SLAC_MME_SECURITY_TYPE_VALUE */
# define SLAC_MME_CM_ATTEN_CHAR_RSP_SOURCE_ADDRESS_POS           (SLAC_MME_GENERIC_HEADER_LEN +  2u) /* Length:  6; Value: EV MAC */
# define SLAC_MME_CM_ATTEN_CHAR_RSP_RUN_ID_POS                   (SLAC_MME_GENERIC_HEADER_LEN +  8u) /* Length:  8; Value: Value of CM_SLAC_PARM.REQ */
# define SLAC_MME_CM_ATTEN_CHAR_RSP_SOURCE_ID_POS                (SLAC_MME_GENERIC_HEADER_LEN + 16u) /* Length: 17; Value: Set to all SLAC_MME_NODE_ID_VALUE */
# define SLAC_MME_CM_ATTEN_CHAR_RSP_RESP_ID_POS                  (SLAC_MME_GENERIC_HEADER_LEN + 33u) /* Length: 17; Value: Set to all SLAC_MME_NODE_ID_VALUE */
# define SLAC_MME_CM_ATTEN_CHAR_RSP_RESULT_POS                   (SLAC_MME_GENERIC_HEADER_LEN + 50u) /* Length:  1; Value: SLAC_MME_ATTEN_CHAR_SUCCESS_VALUE if EVSE is known/added */
/* CM_VALIDATE.REQ */
# define SLAC_MME_CM_VALIDATE_REQ_LENGTH                         (SLAC_MME_GENERIC_HEADER_LEN + 3u)
# define SLAC_MME_CM_VALIDATE_REQ_LENGTH_PAD32                   (SLAC_MME_CM_VALIDATE_REQ_LENGTH + 0u)
# define SLAC_MME_CM_VALIDATE_REQ_SIGNAL_TYPE_POS                (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:  1; Value: SLAC_MME_SIGNAL_TYPE_EV_S2_TOGGLES_ON_CP_VALUE */
# define SLAC_MME_CM_VALIDATE_REQ_TIMER_POS                      (SLAC_MME_GENERIC_HEADER_LEN +  1u) /* Length:  1; Value: Req1: 0; Req2: < 3500 ms (0x00 == 100 ms) */
# define SLAC_MME_CM_VALIDATE_REQ_RESULT_POS                     (SLAC_MME_GENERIC_HEADER_LEN +  2u) /* Length:  1; Value: 0x01 (Slac_ERVR_Ready) */
/* CM_VALIDATE.CNF */
# define SLAC_MME_CM_VALIDATE_CNF_LENGTH                         (SLAC_MME_GENERIC_HEADER_LEN + 3u)
# define SLAC_MME_CM_VALIDATE_CNF_LENGTH_PAD32                   (SLAC_MME_CM_VALIDATE_CNF_LENGTH + 0u)
# define SLAC_MME_CM_VALIDATE_CNF_SIGNAL_TYPE_POS                (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:  1; Value: SLAC_MME_SIGNAL_TYPE_EV_S2_TOGGLES_ON_CP_VALUE */
# define SLAC_MME_CM_VALIDATE_CNF_TOGGLE_NUM_POS                 (SLAC_MME_GENERIC_HEADER_LEN +  1u) /* Length:  1; Value: Cnf1: 0; Cnf2: 1-3 */
# define SLAC_MME_CM_VALIDATE_CNF_RESULT_POS                     (SLAC_MME_GENERIC_HEADER_LEN +  2u) /* Length:  1; Value: See Slac_EvseRxValidationResultType */
/* CM_SLAC_MATCH.REQ */
# define SLAC_MME_CM_SLAC_MATCH_REQ_LENGTH                       (SLAC_MME_GENERIC_HEADER_LEN + 66u)
# define SLAC_MME_CM_SLAC_MATCH_REQ_LENGTH_PAD32                 (SLAC_MME_CM_SLAC_MATCH_REQ_LENGTH + 1u)
# define SLAC_MME_CM_SLAC_MATCH_REQ_APPLICATION_TYPE_POS         (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:  1; Value: SLAC_MME_APPLICATION_TYPE_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_REQ_SECURITY_TYPE_POS            (SLAC_MME_GENERIC_HEADER_LEN +  1u) /* Length:  1; Value: SLAC_MME_SECURITY_TYPE_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_REQ_MVF_LENGTH_POS               (SLAC_MME_GENERIC_HEADER_LEN +  2u) /* Length:  2; Value: SLAC_MME_MATCH_REQ_MVF_LENGTH_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_REQ_PEV_ID_POS                   (SLAC_MME_GENERIC_HEADER_LEN +  4u) /* Length: 17; Value: Set to all SLAC_MME_NODE_ID_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_REQ_PEV_MAC_POS                  (SLAC_MME_GENERIC_HEADER_LEN + 21u) /* Length:  6; Value: EV MAC */
# define SLAC_MME_CM_SLAC_MATCH_REQ_EVSE_ID_POS                  (SLAC_MME_GENERIC_HEADER_LEN + 27u) /* Length: 17; Value: Set to all SLAC_MME_NODE_ID_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_REQ_EVSE_MAC_POS                 (SLAC_MME_GENERIC_HEADER_LEN + 44u) /* Length:  6; Value: EVSE MAC */
# define SLAC_MME_CM_SLAC_MATCH_REQ_RUN_ID_POS                   (SLAC_MME_GENERIC_HEADER_LEN + 50u) /* Length:  8; Value: Value of CM_SLAC_PARM.REQ */
# define SLAC_MME_CM_SLAC_MATCH_REQ_RSVD_POS                     (SLAC_MME_GENERIC_HEADER_LEN + 58u) /* Length:  8; Value: Set to all SLAC_MME_RSVD_VALUE */
/* CM_SLAC_MATCH.REQ */
# define SLAC_MME_CM_SLAC_MATCH_CNF_LENGTH                       (SLAC_MME_GENERIC_HEADER_LEN + 90u)
# define SLAC_MME_CM_SLAC_MATCH_CNF_LENGTH_PAD32                 (SLAC_MME_CM_SLAC_MATCH_CNF_LENGTH + 1u)
# define SLAC_MME_CM_SLAC_MATCH_CNF_APPLICATION_TYPE_POS         (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:  1; Value: SLAC_MME_APPLICATION_TYPE_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_CNF_SECURITY_TYPE_POS            (SLAC_MME_GENERIC_HEADER_LEN +  1u) /* Length:  1; Value: SLAC_MME_SECURITY_TYPE_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_CNF_MVF_LENGTH_POS               (SLAC_MME_GENERIC_HEADER_LEN +  2u) /* Length:  2; Value: SLAC_MME_MATCH_CNF_MVF_LENGTH_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_CNF_PEV_ID_POS                   (SLAC_MME_GENERIC_HEADER_LEN +  4u) /* Length: 17; Value: Set to all SLAC_MME_NODE_ID_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_CNF_PEV_MAC_POS                  (SLAC_MME_GENERIC_HEADER_LEN + 21u) /* Length:  6; Value: EV MAC */
# define SLAC_MME_CM_SLAC_MATCH_CNF_EVSE_ID_POS                  (SLAC_MME_GENERIC_HEADER_LEN + 27u) /* Length: 17; Value: Set to all SLAC_MME_NODE_ID_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_CNF_EVSE_MAC_POS                 (SLAC_MME_GENERIC_HEADER_LEN + 44u) /* Length:  6; Value: EVSE MAC */
# define SLAC_MME_CM_SLAC_MATCH_CNF_RUN_ID_POS                   (SLAC_MME_GENERIC_HEADER_LEN + 50u) /* Length:  8; Value: Value of CM_SLAC_PARM.REQ */
# define SLAC_MME_CM_SLAC_MATCH_CNF_RSVD1_POS                    (SLAC_MME_GENERIC_HEADER_LEN + 58u) /* Length:  8; Value: Set to all SLAC_MME_RSVD_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_CNF_NID_POS                      (SLAC_MME_GENERIC_HEADER_LEN + 66u) /* Length:  7; Value: NID of the AVLN to join */
# define SLAC_MME_CM_SLAC_MATCH_CNF_RSVD2_POS                    (SLAC_MME_GENERIC_HEADER_LEN + 73u) /* Length:  1; Value: SLAC_MME_RSVD_VALUE */
# define SLAC_MME_CM_SLAC_MATCH_CNF_NMK_POS                      (SLAC_MME_GENERIC_HEADER_LEN + 74u) /* Length: 16; Value: NMK of the AVLN to join */
/* CM_SET_KEY.REQ */
# define SLAC_MME_CM_SET_KEY_REQ_LENGTH                          (SLAC_MME_GENERIC_HEADER_LEN + 38u)
# define SLAC_MME_CM_SET_KEY_REQ_LENGTH_PAD32                    (SLAC_MME_CM_SET_KEY_REQ_LENGTH + 1u)
# define SLAC_MME_CM_SET_KEY_REQ_KEY_TYPE_POS                    (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:  1; Value: SLAC_MME_KEY_TYPE_VALUE */
# define SLAC_MME_CM_SET_KEY_REQ_MY_NONCE_POS                    (SLAC_MME_GENERIC_HEADER_LEN +  1u) /* Length:  4; Value: Set to all SLAC_MME_NONCE_VALUE */
# define SLAC_MME_CM_SET_KEY_REQ_YOUR_NONCE_POS                  (SLAC_MME_GENERIC_HEADER_LEN +  5u) /* Length:  4; Value: Set to all SLAC_MME_NONCE_VALUE */
# define SLAC_MME_CM_SET_KEY_REQ_PID_POS                         (SLAC_MME_GENERIC_HEADER_LEN +  9u) /* Length:  1; Value: Set to all SLAC_MME_PID_VALUE */
# define SLAC_MME_CM_SET_KEY_REQ_PRN_POS                         (SLAC_MME_GENERIC_HEADER_LEN + 10u) /* Length:  2; Value: EV SLAC_MME_PRN_VALUE */
# define SLAC_MME_CM_SET_KEY_REQ_PMN_POS                         (SLAC_MME_GENERIC_HEADER_LEN + 12u) /* Length:  1; Value: SLAC_MME_PMN_VALUE */
# define SLAC_MME_CM_SET_KEY_REQ_CCO_CAPABILITY_POS              (SLAC_MME_GENERIC_HEADER_LEN + 13u) /* Length:  1; Value: SLAC_CFG_MME_CCO_CAPABILITY_VALUE */
# define SLAC_MME_CM_SET_KEY_REQ_NID_POS                         (SLAC_MME_GENERIC_HEADER_LEN + 14u) /* Length:  7; Value: NID of the AVLN to join */
# define SLAC_MME_CM_SET_KEY_REQ_NEW_EKS_POS                     (SLAC_MME_GENERIC_HEADER_LEN + 21u) /* Length:  1; Value: SLAC_MME_NEW_EKS_VALUE */
# define SLAC_MME_CM_SET_KEY_REQ_NMK_POS                         (SLAC_MME_GENERIC_HEADER_LEN + 22u) /* Length: 16; Value: NMK of the AVLN to join */
/* CM_SET_KEY.CNF */
# define SLAC_MME_CM_SET_KEY_CNF_LENGTH                          (SLAC_MME_GENERIC_HEADER_LEN + 14u)
# define SLAC_MME_CM_SET_KEY_CNF_LENGTH_PAD32                    (SLAC_MME_CM_SET_KEY_CNF_LENGTH + 1u)
# define SLAC_MME_CM_SET_KEY_CNF_RESULT_POS                      (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:  1; Value: See Slac_SetKeyResultType */
# define SLAC_MME_CM_SET_KEY_CNF_MY_NONCE_POS                    (SLAC_MME_GENERIC_HEADER_LEN +  1u) /* Length:  4; Value: Set to all SLAC_MME_NONCE_VALUE */
# define SLAC_MME_CM_SET_KEY_CNF_YOUR_NONCE_POS                  (SLAC_MME_GENERIC_HEADER_LEN +  5u) /* Length:  4; Value: Set to all SLAC_MME_NONCE_VALUE */
# define SLAC_MME_CM_SET_KEY_CNF_PID_POS                         (SLAC_MME_GENERIC_HEADER_LEN +  9u) /* Length:  1; Value: Set to all SLAC_MME_PID_VALUE */
# define SLAC_MME_CM_SET_KEY_CNF_PRN_POS                         (SLAC_MME_GENERIC_HEADER_LEN + 10u) /* Length:  2; Value: EV SLAC_MME_PRN_VALUE */
# define SLAC_MME_CM_SET_KEY_CNF_PMN_POS                         (SLAC_MME_GENERIC_HEADER_LEN + 12u) /* Length:  1; Value: SLAC_MME_PMN_VALUE */
# define SLAC_MME_CM_SET_KEY_CNF_CCO_CAPABILITY_POS              (SLAC_MME_GENERIC_HEADER_LEN + 13u) /* Length:  1; Value: SLAC_CFG_MME_CCO_CAPABILITY_VALUE */
/* CM_AMP_MAP.REQ */
# define SLAC_MME_CM_AMP_MAP_REQ_LENGTH                          (SLAC_MME_GENERIC_HEADER_LEN + 461u)
# define SLAC_MME_CM_AMP_MAP_REQ_LENGTH_PAD32                    (SLAC_MME_CM_AMP_MAP_REQ_LENGTH + 2u)
# define SLAC_MME_CM_AMP_MAP_REQ_AMLEN_POS                       (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:   2; Value: SLAC_CFG_AMP_MAP_SIZE */
# define SLAC_MME_CM_AMP_MAP_REQ_AMDATA_POS                      (SLAC_MME_GENERIC_HEADER_LEN +  2u) /* Length: SLAC_CFG_AMP_MAP_NVM_SIZE; Value size: 4 bit; Value: Carrier attenuation reduction */
/* CM_AMP_MAP.CNF */
# define SLAC_MME_CM_AMP_MAP_CNF_LENGTH                          (SLAC_MME_GENERIC_HEADER_LEN + 1u)
# define SLAC_MME_CM_AMP_MAP_CNF_LENGTH_PAD32                    (SLAC_MME_CM_AMP_MAP_CNF_LENGTH + 2u)
# define SLAC_MME_CM_AMP_MAP_CNF_RES_TYPE_POS                    (SLAC_MME_GENERIC_HEADER_LEN +  0u) /* Length:   1; Value: See Slac_AmpMapResTypeType */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
typedef enum
{
  Slac_RT_Ok = E_OK,        /* Executed successful. */
  Slac_RT_NotOk = E_NOT_OK, /* Execution failed. */
  Slac_RT_Pending = 0x02u   /* Execution is still ongoing, call again later. */
} Slac_ReturnType;

#if (SLAC_DEV_ERROR_DETECT == STD_ON)
typedef enum
{
  Slac_IS_Uninitialized = 0u, /* The module has not been initialized. */
  Slac_IS_Initialized = 1u    /* The module has been initialized successfully. */
} Slac_InitStateType;
#endif

typedef enum
{
  Slac_TLS_Down = ETHTRCV_LINK_STATE_DOWN, /* Link has been reported as down. */
  Slac_TLS_Up = ETHTRCV_LINK_STATE_ACTIVE  /* Link has been reported as up.   */
} Slac_TrcvLinkStateType;


typedef enum
{
#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM)
  Slac_DDI_PsdValueMap,    /* Local PSD value map */
#endif
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
  Slac_DDI_RemoteAmpMap,   /* Remote amplitude map */
#endif
#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
  Slac_DDI_CalibrationMap, /* Calibration map */
#endif
#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM)
  Slac_DDI_PlcChipAddress, /* PLC chip physical address */
#endif
  Slac_DDI_InvalidDataId   /* Internal: This value must not be set, it only exists to perform internal checks. */
} Slac_DiagDataIdType;

typedef enum
{
  Slac_DDR_Pending         = 0u, /* Access is pending, call again later. */
  Slac_DDR_Done            = 1u, /* Access has been finished successfully. */
  Slac_DDR_NvmError        = 2u, /* NvM access error during the operation. */
  Slac_DDR_NotPossible     = 3u, /* Access currently not possible, due to module states or provided parameters. */
  Slac_DDR_InvalidRequest  = 4u  /* Provided data ID is unknown. */
} Slac_DiagDataResultType;

typedef enum
{
  Slac_MMT_CmSlacParmReq       = 0x6064u,
  Slac_MMT_CmSlacParmCnf       = 0x6065u,
  Slac_MMT_CmStartAttenCharInd = 0x606Au,
  Slac_MMT_CmMnbcSoundInd      = 0x6076u,
  Slac_MMT_CmAttenCharInd      = 0x606Eu,
  Slac_MMT_CmAttenCharRsp      = 0x606Fu,
  Slac_MMT_CmValidateReq       = 0x6078u,
  Slac_MMT_CmValidateCnf       = 0x6079u,
  Slac_MMT_CmSlacMatchReq      = 0x607Cu,
  Slac_MMT_CmSlacMatchCnf      = 0x607Du,
  Slac_MMT_CmSetKeyReq         = 0x6008u,
  Slac_MMT_CmSetKeyCnf         = 0x6009u,
  Slac_MMT_CmAmpMapReq         = 0x601Cu,
  Slac_MMT_CmAmpMapCnf         = 0x601Du,
  Slac_MMT_VendorSpecificStart = 0x8000u
} Slac_MessageMmeTypeType;


#define SLAC_ASE_INFO_MASK     0x1000u /* Informational event, SLAC is continued. */
#define SLAC_ASE_WARNING_MASK  0x2000u /* Warning event, SLAC is continued. */
#define SLAC_ASE_ERROR_MASK    0x4000u /* Error event, SLAC is abort. */


typedef enum
{
  Slac_AMM_PassiveAmpMapExchange = 0u, /* Passive mode: No CM_AMP_MAP.REQ is sent by the EV to the EVSE. The EV does just wait if the 
                                        * EVSE tries to transmit an CM_AMP_MAP.REQ to the EV. If it does, the EV confirms the request 
                                        * and applies the changes by sending a CM_AMP_MAP.REQ to the local PLC chip. */
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
  Slac_AMM_ActiveAmpMapExchange = 1u, /* Active mode: In this mode additionally to the passive mode the Slac module send a 
                                       * CM_AMP_MAP.REQ to the EVSE to request a change. In parallel the execution of the passive 
                                       * mode is optionally possible. */
#endif
  Slac_AMM_InvalidValue               /* Internal: This value must not be set, it only exists to perform internal checks. */
} Slac_AmpMapModeType;

/* PRQA S 0750 5 */ /* MD_Slac_0358_Union */
typedef union
{
  P2VAR(Eth_DataType, AUTOMATIC, SLAC_APPL_DATA) NativePtr;
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) U8Ptr;
} Slac_EthernetBufferUnionType;

typedef struct
{
  Slac_EthernetBufferUnionType Buffer;
  uint16 BufferLen;
} Slac_EthernetBufferType;


/* The types Slac_ValidationRecommendedType and Slac_ValidationExecutionType have compatible values. 
 * Therefore Slac_ValidationRecommendedType may just be cast to Slac_ValidationExecutionType on 
 * application level, in case the value 'pending' is not required.
 */
typedef enum
{
  Slac_VR_NotRequired           = 0u, /* There is only one EVSE classified as FOUND, therefore the validation is not required. Additionally, there may be POTENTIALLY_FOUND EVSEs. */
  Slac_VR_ValidationRecommended = 1u, /* There are multiple EVSEs available. More than one has been classified as FOUND or all available EVSEs are POTENTIALLY_FOUND, therefore a validation is recommended. */
  Slac_VR_ValidationRequired    = 2u  /* There are no EVSEs classified as FOUND, but one EVSE classified as POTENTIALLY_FOUND, therefore a validation should be executed for safety reasons. */
} Slac_ValidationRecommendedType;

typedef enum
{
  Slac_VE_DoNotValidate         = 0u, /* Validation is skipped, the EVSE with the lowest attenuation mean is chosen. EVSEs classified as FOUND and POTENTIALLY_FOUND are taken into account. */
  Slac_VE_OptionalValidation    = 1u, /* Validate all available EVSEs. EVSEs that do not support the validation are allowed to skip the validation process.
                                       * - In case one EVSE attending in the validation process returns the correct toggles, this EVSE is selected.
                                       * - In case no EVSE returns the correct toggles count and there is at least on EVSE not attending in the validation process, the 'not attending' EVSE 
                                       *   with the lowest mean attenuation value is selected. */
  Slac_VE_ForceValidation       = 2u, /* Validate all available EVSEs. The EVSE has to acceppt and execute the validation process. All EVSE returning Result==Failure will be ignored for further processing. */
  Slac_VE_DecisionPending       = 3u  /* Return this in case the result is calculated with some delay (e.g. on another ECU). */
} Slac_ValidationExecutionType;

typedef struct
{
  Slac_ValidationRecommendedType ValidationRecommended;
  uint8 EvseFoundCnt;
  uint8 EvsePotentiallyFoundCount;
} Slac_ValidationInfoType;

typedef enum
{
  Slac_SKR_Failure = 0u,
  Slac_SKR_Success = 1u
} Slac_SetKeyResultType;

typedef enum
{
  Slac_AMRT_Success = 0u,
  Slac_AMRT_Failure = 1u
} Slac_AmpMapResTypeType;

/* Type has been renamed due to a typo, the old type name is still present, to prevent a braking change because of this renaming. */
#define  Slac_DLinkStausType Slac_DLinkStatusType

typedef void (*Slac_MessageHandlingFctType)(void);
typedef Slac_ReturnType (*Slac_SendMessageToFixedAddressFctType)(void);


#if (SLAC_NVM_REQUIRED == STD_ON)
typedef enum
{
  Slac_NRWS_RetryRead,
  Slac_NRWS_ReadStart,
  Slac_NRWS_Reading,
  Slac_NRWS_RetryWrite,
  Slac_NRWS_WriteStart,
  Slac_NRWS_Writing,
  Slac_NRWS_Done,
  Slac_NRWS_Error
} Slac_NvmReadWriteStateType;
#endif

#if (   (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM) \
     || (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_CALLOUT) \
     || (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON) )
typedef struct
{
#if (   (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM) \
     || (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON) )
  Slac_NvmReadWriteStateType ReadWriteState;
#endif
  uint8 Map[SLAC_CFG_AMP_MAP_NVM_SIZE];
} Slac_AmpMapNvmBlockType;
#endif

#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
typedef struct
{
  Slac_NvmReadWriteStateType ReadWriteState;
  sint8 Map[SLAC_CFG_CALIBRATION_MAP_SIZE];
} Slac_CalibrationMapNvmBlockType;
#endif

#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM)
typedef struct
{
  Slac_NvmReadWriteStateType ReadWriteState;
} Slac_PlcChipAddressNvmBlockType;
#endif


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif  /* SLAC_TYPES_H */

/***********************************************************************************************************************
 *  END OF FILE: Slac_Types.h
 **********************************************************************************************************************/
