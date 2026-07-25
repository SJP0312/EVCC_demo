#ifndef EVCC_OS_H
#define EVCC_OS_H

#include <stddef.h>

#define EVCC_OS_OK 0
#define EVCC_OS_ERROR (-1)
#define EVCC_OS_TIMEOUT 1
#define EVCC_OS_NO_WAIT 0U
#define EVCC_OS_WAIT_FOREVER 0xFFFFFFFFU

typedef void (*EvccOs_TaskMainFunc)(void);
typedef unsigned int EvccOs_TickType;
typedef unsigned int EvccOs_EventBitsType;

typedef struct EvccOs_QueueControlBlock *EvccOs_QueueHandle;
typedef struct EvccOs_SemaphoreControlBlock *EvccOs_SemaphoreHandle;
typedef struct EvccOs_EventGroupControlBlock *EvccOs_EventGroupHandle;
typedef void (*EvccOs_InterruptHandler)(void *context);

typedef enum
{
    EVCC_OS_STATE_STOP = 0,
    EVCC_OS_STATE_RUN = 1
} EvccOs_StateType;

typedef struct
{
    const char *taskName;
    EvccOs_TaskMainFunc taskFunc;
    EvccOs_TickType periodTicks;
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
EvccOs_TickType EvccOs_GetTickCount(void);
void EvccOs_SetState(EvccOs_StateType state);
EvccOs_StateType EvccOs_GetState(void);
int EvccOs_IsRunning(void);
void EvccOs_Printf(const char *format, ...);

EvccOs_QueueHandle EvccOs_QueueCreate(size_t itemSize, size_t length);
int EvccOs_QueueSend(EvccOs_QueueHandle queue, const void *item, unsigned int timeoutMs);
int EvccOs_QueueReceive(EvccOs_QueueHandle queue, void *item, unsigned int timeoutMs);
int EvccOs_QueueSendFromIsr(EvccOs_QueueHandle queue, const void *item);

EvccOs_SemaphoreHandle EvccOs_SemaphoreCreateBinary(unsigned int initialCount);
EvccOs_SemaphoreHandle EvccOs_SemaphoreCreateCounting(unsigned int maxCount, unsigned int initialCount);
int EvccOs_SemaphoreTake(EvccOs_SemaphoreHandle semaphore, unsigned int timeoutMs);
int EvccOs_SemaphoreGive(EvccOs_SemaphoreHandle semaphore);
int EvccOs_SemaphoreGiveFromIsr(EvccOs_SemaphoreHandle semaphore);

EvccOs_EventGroupHandle EvccOs_EventGroupCreate(void);
int EvccOs_EventGroupSetBits(EvccOs_EventGroupHandle eventGroup, EvccOs_EventBitsType bits);
int EvccOs_EventGroupClearBits(EvccOs_EventGroupHandle eventGroup, EvccOs_EventBitsType bits);
int EvccOs_EventGroupWaitBits(EvccOs_EventGroupHandle eventGroup,
                              EvccOs_EventBitsType bitsToWaitFor,
                              int clearOnExit,
                              int waitForAllBits,
                              unsigned int timeoutMs,
                              EvccOs_EventBitsType *matchedBits);

int EvccOs_RegisterInterrupt(unsigned int interruptId, EvccOs_InterruptHandler handler, void *context);
int EvccOs_EnableInterrupt(unsigned int interruptId);
int EvccOs_DisableInterrupt(unsigned int interruptId);
int EvccOs_TriggerInterrupt(unsigned int interruptId);

#endif
