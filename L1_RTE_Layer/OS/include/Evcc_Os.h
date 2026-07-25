#ifndef EVCC_OS_H
#define EVCC_OS_H

#include <stddef.h>

typedef void (*EvccOs_TaskMainFunc)(void);

typedef enum
{
    EVCC_OS_STATE_STOP = 0,
    EVCC_OS_STATE_RUN = 1
} EvccOs_StateType;

typedef struct
{
    const char *taskName;
    EvccOs_TaskMainFunc taskFunc;
    unsigned int periodMs;
    unsigned int stackSize;
    unsigned int priority;
} EvccOs_TaskConfigType;

typedef struct
{
    const char *interruptName;
    unsigned int priority;
    unsigned char enabled;
} EvccOs_InterruptConfigType;

void EvccOs_Init(void);
int EvccOs_CreateTask(const EvccOs_TaskConfigType *taskConfig);
void EvccOs_StartScheduler(void);
void EvccOs_DelayMs(unsigned int delayMs);
void EvccOs_SetState(EvccOs_StateType state);
EvccOs_StateType EvccOs_GetState(void);
int EvccOs_IsRunning(void);
void EvccOs_Printf(const char *format, ...);

#endif

