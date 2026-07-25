#include "App_1.h"

#include "Evcc_Os.h"
#include "Rte_App_1.h"

static unsigned int app1_heartbeat_seconds;

static void App1_PrivateFunction(void);

void App1_Init(void)
{
    app1_heartbeat_seconds = 0U;
    EvccOs_Printf("[App_1] Init\n");
}

void App1_MainFunction(void)
{
    app1_heartbeat_seconds++;
    Rte_App1_MainFunction();
    App1_StateMachine();
    App1_PrivateFunction();

    if ((app1_heartbeat_seconds % 5U) == 0U) {
        EvccOs_Printf("[App_1][Heartbeat=%us] %s\n", app1_heartbeat_seconds, Rte_App1_GetLibInfo());
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
