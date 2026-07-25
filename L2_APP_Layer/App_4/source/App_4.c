#include "App_4.h"

#include "Rte_App_4.h"

static void App4_PrivateFunction(void);

void App4_Init(void)
{
}

void App4_MainFunction(void)
{
    Rte_App4_MainFunction();
    App4_StateMachine();
    App4_PrivateFunction();
}

void App4_StateMachine(void)
{
}

void App4_PublicFunction(void)
{
}

static void App4_PrivateFunction(void)
{
}
