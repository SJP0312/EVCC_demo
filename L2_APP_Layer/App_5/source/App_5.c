#include "App_5.h"

#include "Rte_App_5.h"

static void App5_PrivateFunction(void);

void App5_Init(void)
{
}

void App5_MainFunction(void)
{
    Rte_App5_MainFunction();
    App5_StateMachine();
    App5_PrivateFunction();
}

void App5_StateMachine(void)
{
}

void App5_PublicFunction(void)
{
}

static void App5_PrivateFunction(void)
{
}
