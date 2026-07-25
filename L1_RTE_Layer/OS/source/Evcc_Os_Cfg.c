#include "Evcc_Os_Cfg.h"

/*ASW HEADER CONFIG*/
#include "App_1.h"
#include "App_2.h"
#include "App_3.h"
#include "App_4.h"
#include "App_5.h"

const EvccOs_TaskConfigType EvccOs_TaskConfigTable[] = {
    {
        "App_1_Task",
        App1_MainFunction,
        EVCC_OS_MS_TO_TICKS(EVCC_OS_APP1_TASK_PERIOD_MS),
        EVCC_OS_DEFAULT_STACK_SIZE,
        2U,
    },
    {
        "App_2_Task",
        App2_MainFunction,
        EVCC_OS_MS_TO_TICKS(EVCC_OS_APP2_TASK_PERIOD_MS),
        EVCC_OS_DEFAULT_STACK_SIZE,
        2U,
    },
    {
        "App_3_Task",
        App3_MainFunction,
        EVCC_OS_MS_TO_TICKS(EVCC_OS_APP3_TASK_PERIOD_MS),
        EVCC_OS_DEFAULT_STACK_SIZE,
        2U,
    },
    {
        "App_4_Task",
        App4_MainFunction,
        EVCC_OS_MS_TO_TICKS(EVCC_OS_APP4_TASK_PERIOD_MS),
        EVCC_OS_DEFAULT_STACK_SIZE,
        2U,
    },
    {
        "App_5_Task",
        App5_MainFunction,
        EVCC_OS_MS_TO_TICKS(EVCC_OS_APP5_TASK_PERIOD_MS),
        EVCC_OS_DEFAULT_STACK_SIZE,
        2U,
    },
};

const size_t EvccOs_TaskConfigCount = sizeof(EvccOs_TaskConfigTable) / sizeof(EvccOs_TaskConfigTable[0]);

const EvccOs_InterruptConfigType EvccOs_InterruptConfigTable[] = {
    {
        "Console_Command_Input",
        1U,
        1U,
    },
};

const size_t EvccOs_InterruptConfigCount = sizeof(EvccOs_InterruptConfigTable) / sizeof(EvccOs_InterruptConfigTable[0]);
