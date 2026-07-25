#include "App_2.h"

#include "Evcc_Os.h"
#include "Rte_App_2.h"

#define APP2_HEARTBEAT_CALL_INTERVAL 500U

static unsigned int app2_call_count;

static void App2_PrivateFunction(void);

void App2_Init(void)
{
    app2_call_count = 0U;
    EvccOs_Printf("[App_2] Init\n");
}

void App2_MainFunction(void)
{
    app2_call_count++;
    Rte_App2_MainFunction();
    App2_StateMachine();
    App2_PrivateFunction();

    if ((app2_call_count % APP2_HEARTBEAT_CALL_INTERVAL) == 0U) {
        EvccOs_Printf("[App_2][Heartbeat=%u] %s\n", app2_call_count, Rte_App2_GetLibInfo());
    }
}

void App2_StateMachine(void)
{
}

void App2_PublicFunction(void)
{
}

static void App2_PrivateFunction(void)
{
}
