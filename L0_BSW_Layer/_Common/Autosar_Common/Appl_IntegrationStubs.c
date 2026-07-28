#include "Std_Types.h"
#include "_Appl_Rand.h"
#include "_Appl_Time.h"
#include "Crypto_GeneralTypes.h"
#include "KeyM_Cfg.h"

extern void Scc_Cbk_Csm_ApplNotification(uint32 jobId, Crypto_ResultType result);

static uint16 ApplRand_Value = 0xACE1u;
static const uint8 Appl_PlcChipMacAddress[6] = { 0x02u, 0x00u, 0x00u, 0x00u, 0x00u, 0x01u };

void ApplRand_Init(void)
{
  ApplRand_Value = 0xACE1u;
}

uint16 ApplRand_GetRandNo(void)
{
  ApplRand_Value = (uint16)((ApplRand_Value * 1103u) + 12345u);
  return ApplRand_Value;
}

uint16 Appl_Crypto_GetRandNo(void)
{
  return ApplRand_GetRandNo();
}

void ApplRand_GetRandArray(uint8* TgtDataPtr, uint16 TgtLen)
{
  uint16 index;

  for (index = 0u; index < TgtLen; index++)
  {
    if ((index & 1u) == 0u)
    {
      ApplRand_Value = ApplRand_GetRandNo();
    }
    TgtDataPtr[index] = (uint8)(ApplRand_Value >> ((index & 1u) * 8u));
  }
}

void Appl_Crypto_GetRandArray(uint8* TgtDataPtr, uint16 TgtLen)
{
  ApplRand_GetRandArray(TgtDataPtr, TgtLen);
}

void ApplRand_Deinit(void)
{
}

void Appl_TlsGetTime32(uint32* TgtDataPtr)
{
  ApplTime_GetTime32(TgtDataPtr);
}

void ApplTime_GetTime32(uint32* TgtDataPtr)
{
  if (TgtDataPtr != NULL_PTR)
  {
    *TgtDataPtr = 1644192000u;
  }
}

const uint8* Appl_GetPlcChipMacAddress(void)
{
  return Appl_PlcChipMacAddress;
}

const uint8* Appl_Callout_GetMacAddress(void)
{
  return Appl_PlcChipMacAddress;
}

Std_ReturnType Appl_Cbk_SpiBuffError(uint8 CtrlIdx, uint8 ErrorType)
{
  (void)CtrlIdx;
  (void)ErrorType;
  return E_OK;
}

Std_ReturnType Appl_Cbk_SpiOutOfSyncDetect(uint8 CtrlIdx, uint8 ResetType)
{
  (void)CtrlIdx;
  (void)ResetType;
  return E_OK;
}

uint16 Appl_SccDynCP_DIN70121_TimerCfg_CurrentDemandMessageTimeout(void)
{
  return 400u;
}

uint16 Appl_SccDynCP_ISO15118_2_TimerCfg_CurrentDemandMessageTimeout(void)
{
  return 400u;
}

void Scc_Cbk_Csm_ApplNotification_Csm43(Crypto_JobType* job, Std_ReturnType result)
{
  uint32 jobId = 0u;

  if (job != NULL_PTR)
  {
    jobId = job->jobId;
  }

  Scc_Cbk_Csm_ApplNotification(jobId, (Crypto_ResultType)result);
}

Std_ReturnType Appl_KeyMCertificateGetCurrentTimeCalloutFunc(KeyM_CertificateIdType CertId, uint64* timeStamp)
{
  (void)CertId;

  if (timeStamp != NULL_PTR)
  {
    *timeStamp = 1644192000ull;
  }

  return E_OK;
}

static void Appl_KeyM_SetEmptyCertificate(KeyM_CertificateIdType CertId, KeyM_ConstCertDataType* CertificateDataPtr)
{
  (void)CertId;

  if (CertificateDataPtr != NULL_PTR)
  {
    CertificateDataPtr->certDataLength = 0u;
    CertificateDataPtr->certData = NULL_PTR;
  }
}

#define DEFINE_KEYM_CERT_INIT_CALLOUT(name) \
  void name(KeyM_CertificateIdType CertId, KeyM_ConstCertDataType* CertificateDataPtr) \
  { \
    Appl_KeyM_SetEmptyCertificate(CertId, CertificateDataPtr); \
  }

DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_ISO20_EMSPContract_0_InitCalloutFunc)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_ISO20_EMSPSubCA1_0_InitCalloutFunc)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_ISO20_EMSPSubCA2_0_InitCalloutFunc)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_ISO2_ContractCertificate_0)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_ISO2_MOSubCA1_0)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_ISO2_MOSubCA2_0)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_ISO2_OEMProvCertificate_0)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_0)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_1)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_2)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_3)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_4)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_5)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_6)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_7)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_8)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_9)
DEFINE_KEYM_CERT_INIT_CALLOUT(Appl_KeyMCertificateCertInit_V2G_Root_10)
