#include <stdio.h>

#include "main.h"

const char *evcc_demo_message(void)
{
    return PROJECT_GREETING;
}

int main(void)
{
    printf("%s\n", evcc_demo_message());
    return 0;
}