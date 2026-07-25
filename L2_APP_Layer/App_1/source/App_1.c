#include "App_1.h"

#include "Evcc_Os.h"
#include "Rte_App_1.h"

#define APP1_HEARTBEAT_CALL_INTERVAL 500U

static unsigned int app1_call_count;

static void App1_PrivateFunction(void);

void App1_Init(void)
{
    app1_call_count = 0U;
    EvccOs_Printf("[App_1] Init\n");
}

void App1_MainFunction(void)
{
    app1_call_count++;
    Rte_App1_MainFunction();
    App1_StateMachine();
    App1_PrivateFunction();

    if ((app1_call_count % APP1_HEARTBEAT_CALL_INTERVAL) == 0U) {
        EvccOs_Printf("[App_1][Heartbeat=%u] %s\n", app1_call_count, Rte_App1_GetLibInfo());
    }
}

void App1_StateMachine(void)
{
}

void App1_PublicFunction(void)
{
}

static void App1_PrivateFunction(void)
{
}
