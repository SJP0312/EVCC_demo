#include "Rte_App_1.h"

#include "Lib_1.h"

void Rte_App1_Init(void)
{
    Lib1_Init();
}

void Rte_App1_MainFunction(void)
{
    Lib1_MainFunction();
}

const char *Rte_App1_GetLibInfo(void)
{
    return Lib1_GetInfo();
}
