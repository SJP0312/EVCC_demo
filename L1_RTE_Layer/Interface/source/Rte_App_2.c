#include "Rte_App_2.h"

#include "Lib_2.h"

void Rte_App2_Init(void)
{
    Lib2_Init();
}

void Rte_App2_MainFunction(void)
{
    Lib2_MainFunction();
}

const char *Rte_App2_GetLibInfo(void)
{
    return Lib2_GetInfo();
}
