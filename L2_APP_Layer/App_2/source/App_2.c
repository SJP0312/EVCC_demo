#include "App_2.h"

#include "Evcc_Os.h"
#include "Rte_App_2.h"

static unsigned int app2_heartbeat_seconds;

static void App2_PrivateFunction(void);

void App2_Init(void)
{
    app2_heartbeat_seconds = 0U;
    EvccOs_Printf("[App_2] Init\n");
}

void App2_MainFunction(void)
{
    app2_heartbeat_seconds++;
    Rte_App2_MainFunction();
    App2_StateMachine();
    App2_PrivateFunction();

    if ((app2_heartbeat_seconds % 10U) == 0U) {
        EvccOs_Printf("[App_2][Heartbeat=%us] %s\n", app2_heartbeat_seconds, Rte_App2_GetLibInfo());
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
