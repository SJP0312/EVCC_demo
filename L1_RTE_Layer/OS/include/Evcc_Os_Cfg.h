#ifndef EVCC_OS_CFG_H
#define EVCC_OS_CFG_H

#include <stddef.h>

#include "Evcc_Os.h"

#define EVCC_OS_APP_TASK_PERIOD_MS 1000U
#define EVCC_OS_LIB_TASK_PERIOD_MS 1000U
#define EVCC_OS_DEFAULT_STACK_SIZE 1024U

extern const EvccOs_TaskConfigType EvccOs_TaskConfigTable[];
extern const size_t EvccOs_TaskConfigCount;
extern const EvccOs_InterruptConfigType EvccOs_InterruptConfigTable[];
extern const size_t EvccOs_InterruptConfigCount;

#endif

