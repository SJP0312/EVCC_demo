#include "main.h"

#include "App_1.h"
#include "App_2.h"
#include "App_3.h"
#include "App_4.h"
#include "App_5.h"
#include "Evcc_Os.h"
#include "Evcc_Os_Cfg.h"
#include "Rte_App_1.h"
#include "Rte_App_2.h"
#include "Rte_App_3.h"
#include "Rte_App_4.h"
#include "Rte_App_5.h"

void EVCC_Init(void)
{
    EvccOs_Printf("EVCC demo start\n");
    EvccOs_Init();
    Rte_App1_Init();
    Rte_App2_Init();
    Rte_App3_Init();
    Rte_App4_Init();
    Rte_App5_Init();
    App1_Init();
    App2_Init();
    App3_Init();
    App4_Init();
    App5_Init();
}

void EVCC_CreateTasks(void)
{
    size_t index;

    for (index = 0U; index < EvccOs_TaskConfigCount; index++) {
        if (EvccOs_CreateTask(&EvccOs_TaskConfigTable[index]) != 0) {
            EvccOs_Printf("[EVCC] Failed to create task: %s\n", EvccOs_TaskConfigTable[index].taskName);
        }
    }
}

void EVCC_MainStateMachine(void)
{
}

int main(void)
{
    EVCC_Init();
    EVCC_CreateTasks();
    EVCC_MainStateMachine();
    EvccOs_StartScheduler();
    return 0;
}
