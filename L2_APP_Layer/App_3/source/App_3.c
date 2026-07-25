#include "App_3.h"

#include "Evcc_Os.h"
#include "Rte_App_3.h"

static unsigned int app3_heartbeat_seconds;

static void App3_PrivateFunction(void);

void App3_Init(void)
{
    app3_heartbeat_seconds = 0U;
    EvccOs_Printf("[App_3] Init\n");
}

void App3_MainFunction(void)
{
    app3_heartbeat_seconds++;
    Rte_App3_MainFunction();
    App3_StateMachine();
    App3_PrivateFunction();

    if ((app3_heartbeat_seconds % 15U) == 0U) {
        EvccOs_Printf("[App_3][Heartbeat=%us] %s\n", app3_heartbeat_seconds, Rte_App3_GetLibInfo());
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
