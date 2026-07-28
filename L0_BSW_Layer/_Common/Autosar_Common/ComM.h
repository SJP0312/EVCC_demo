#ifndef AUTOSAR_COMMON_COMM_H
#define AUTOSAR_COMMON_COMM_H

#include "ComStack_Types.h"

typedef uint8 ComM_ModeType;

#define COMM_NO_COMMUNICATION     ((ComM_ModeType)0u)
#define COMM_SILENT_COMMUNICATION ((ComM_ModeType)1u)
#define COMM_FULL_COMMUNICATION   ((ComM_ModeType)2u)

#define ComMConf_ComMChannel_ComMChlEth ((NetworkHandleType)0u)

#endif /* AUTOSAR_COMMON_COMM_H */
