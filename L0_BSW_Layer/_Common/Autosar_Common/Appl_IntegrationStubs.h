#ifndef AUTOSAR_COMMON_APPL_INTEGRATIONSTUBS_H
#define AUTOSAR_COMMON_APPL_INTEGRATIONSTUBS_H

#include "Std_Types.h"

const uint8* Appl_GetPlcChipMacAddress(void);
const uint8* Appl_Callout_GetMacAddress(void);
Std_ReturnType Appl_Cbk_SpiBuffError(uint8 CtrlIdx, uint8 ErrorType);
Std_ReturnType Appl_Cbk_SpiOutOfSyncDetect(uint8 CtrlIdx, uint8 ResetType);
uint16 Appl_SccDynCP_DIN70121_TimerCfg_CurrentDemandMessageTimeout(void);
uint16 Appl_SccDynCP_ISO15118_2_TimerCfg_CurrentDemandMessageTimeout(void);

#endif /* AUTOSAR_COMMON_APPL_INTEGRATIONSTUBS_H */
