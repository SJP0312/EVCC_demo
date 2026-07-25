#ifndef EVCC_OS_CFG_H
#define EVCC_OS_CFG_H

#include <stddef.h>

#include "Evcc_Os.h"

#define EVCC_OS_TICK_RATE_HZ 100U
#define EVCC_OS_TICK_PERIOD_MS (1000U / EVCC_OS_TICK_RATE_HZ)
#define EVCC_OS_MS_TO_TICKS(ms) ((EvccOs_TickType)((ms) / EVCC_OS_TICK_PERIOD_MS))

#define EVCC_OS_APP1_TASK_PERIOD_MS 10U
#define EVCC_OS_APP2_TASK_PERIOD_MS 20U
#define EVCC_OS_APP3_TASK_PERIOD_MS 50U
#define EVCC_OS_APP4_TASK_PERIOD_MS 100U
#define EVCC_OS_APP5_TASK_PERIOD_MS 200U
#define EVCC_OS_DEFAULT_STACK_SIZE 1024U

extern const EvccOs_TaskConfigType EvccOs_TaskConfigTable[];
extern const size_t EvccOs_TaskConfigCount;
extern const EvccOs_InterruptConfigType EvccOs_InterruptConfigTable[];
extern const size_t EvccOs_InterruptConfigCount;

#endif

