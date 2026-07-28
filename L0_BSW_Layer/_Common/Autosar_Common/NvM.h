#ifndef AUTOSAR_COMMON_NVM_H
#define AUTOSAR_COMMON_NVM_H

#include "Std_Types.h"

typedef uint16 NvM_BlockIdType;
typedef uint8 NvM_RequestResultType;
typedef uint8 NvM_ServiceIdType;

#define NVM_REQ_OK                ((NvM_RequestResultType)0u)
#define NVM_REQ_NOT_OK            ((NvM_RequestResultType)1u)
#define NVM_REQ_PENDING           ((NvM_RequestResultType)2u)
#define NVM_REQ_INTEGRITY_FAILED  ((NvM_RequestResultType)3u)
#define NVM_REQ_BLOCK_SKIPPED     ((NvM_RequestResultType)4u)
#define NVM_REQ_NV_INVALIDATED    ((NvM_RequestResultType)5u)
#define NVM_REQ_CANCELED          ((NvM_RequestResultType)6u)
#define NVM_REQ_REDUNDANCY_FAILED ((NvM_RequestResultType)7u)
#define NVM_REQ_RESTORED_FROM_ROM ((NvM_RequestResultType)8u)

#define NVM_READ_BLOCK            0x06u
#define NVM_WRITE_BLOCK           0x07u
#define NVM_WRITE_ALL             0x0Du

#define NvMConf_NvMBlockDescriptor_SccSessionIdNvmBlock         ((NvM_BlockIdType)1u)
#define NvMConf_NvMBlockDescriptor_SccDynConfigParamsNvmBlock   ((NvM_BlockIdType)2u)
#define NvMConf_NvMBlockDescriptor_NvMMOContract_0              ((NvM_BlockIdType)3u)
#define NvMConf_NvMBlockDescriptor_NvMMOSubCA1                  ((NvM_BlockIdType)4u)
#define NvMConf_NvMBlockDescriptor_NvMMOSubCA2                  ((NvM_BlockIdType)5u)
#define NvMConf_NvMBlockDescriptor_Scc_ISO20_EMSPLeaf_0         ((NvM_BlockIdType)6u)
#define NvMConf_NvMBlockDescriptor_Scc_ISO20_EMSPSubCa1_1       ((NvM_BlockIdType)7u)
#define NvMConf_NvMBlockDescriptor_Scc_ISO20_EMSPSubCa2_0       ((NvM_BlockIdType)8u)
#define NvMConf_NvMBlockDescriptor_CryptoKeyStorage             ((NvM_BlockIdType)9u)

static inline Std_ReturnType NvM_GetErrorStatus(NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr)
{
  (void)BlockId;
  if (RequestResultPtr != NULL_PTR)
  {
    *RequestResultPtr = NVM_REQ_OK;
  }
  return E_OK;
}

static inline Std_ReturnType NvM_SetRamBlockStatus(NvM_BlockIdType BlockId, boolean BlockChanged)
{
  (void)BlockId;
  (void)BlockChanged;
  return E_OK;
}

static inline Std_ReturnType NvM_ReadBlock(NvM_BlockIdType BlockId, void* NvM_DstPtr)
{
  (void)BlockId;
  (void)NvM_DstPtr;
  return E_OK;
}

static inline Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void* NvM_SrcPtr)
{
  (void)BlockId;
  (void)NvM_SrcPtr;
  return E_OK;
}

#endif /* AUTOSAR_COMMON_NVM_H */
