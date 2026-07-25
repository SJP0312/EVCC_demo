#include "App_3.h"

#include "Evcc_Os.h"
#include "Rte_App_3.h"

#define APP3_HEARTBEAT_CALL_INTERVAL 300U

static unsigned int app3_call_count;

static void App3_PrivateFunction(void);

void App3_Init(void)
{
    app3_call_count = 0U;
    EvccOs_Printf("[App_3] Init\n");
}

void App3_MainFunction(void)
{
    app3_call_count++;
    Rte_App3_MainFunction();
    App3_StateMachine();
    App3_PrivateFunction();

    if ((app3_call_count % APP3_HEARTBEAT_CALL_INTERVAL) == 0U) {
        EvccOs_Printf("[App_3][Heartbeat=%u] %s\n", app3_call_count, Rte_App3_GetLibInfo());
    }
}

void App3_StateMachine(void)
{
}

void App3_PublicFunction(void)
{
}

static void App3_PrivateFunction(void)
{
}
