#include "Rte_App_3.h"

#include "Lib_3.h"

void Rte_App3_Init(void)
{
    Lib3_Init();
}

void Rte_App3_MainFunction(void)
{
    Lib3_MainFunction();
}

const char *Rte_App3_GetLibInfo(void)
{
    return Lib3_GetInfo();
}
