#include "Evcc_Os.h"

#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define EVCC_OS_MAX_TASKS 16U

typedef struct
{
    const EvccOs_TaskConfigType *config;
    pthread_t thread;
    int created;
} EvccOs_TaskControlBlock;

static EvccOs_TaskControlBlock evcc_os_tasks[EVCC_OS_MAX_TASKS];
static size_t evcc_os_task_count;
static pthread_mutex_t evcc_os_state_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t evcc_os_print_mutex = PTHREAD_MUTEX_INITIALIZER;
static EvccOs_StateType evcc_os_state = EVCC_OS_STATE_STOP;
static pthread_t evcc_os_console_thread;
static int evcc_os_console_created;

static void *EvccOs_TaskThread(void *argument);
static void *EvccOs_ConsoleCommandThread(void *argument);

void EvccOs_Init(void)
{
    evcc_os_task_count = 0U;
    evcc_os_console_created = 0;
    EvccOs_SetState(EVCC_OS_STATE_STOP);
}

int EvccOs_CreateTask(const EvccOs_TaskConfigType *taskConfig)
{
    pthread_attr_t attr;
    int result;

    if ((taskConfig == NULL) || (taskConfig->taskFunc == NULL) || (taskConfig->periodMs == 0U)) {
        return -1;
    }

    if (evcc_os_task_count >= EVCC_OS_MAX_TASKS) {
        return -1;
    }

    result = pthread_attr_init(&attr);
    if (result != 0) {
        return result;
    }

    if (taskConfig->stackSize > 0U) {
        (void)pthread_attr_setstacksize(&attr, (size_t)taskConfig->stackSize);
    }

    evcc_os_tasks[evcc_os_task_count].config = taskConfig;
    result = pthread_create(&evcc_os_tasks[evcc_os_task_count].thread,
                            &attr,
                            EvccOs_TaskThread,
                            &evcc_os_tasks[evcc_os_task_count]);
    (void)pthread_attr_destroy(&attr);

    if (result != 0) {
        evcc_os_tasks[evcc_os_task_count].config = NULL;
        return result;
    }

    evcc_os_tasks[evcc_os_task_count].created = 1;
    evcc_os_task_count++;
    EvccOs_Printf("[OS] Task created: %s\n", taskConfig->taskName);
    return 0;
}

void EvccOs_StartScheduler(void)
{
    int result;

    EvccOs_Printf("[OS] Scheduler start. Input command: 1=start/resume, 0=stop/pause\n");
    result = pthread_create(&evcc_os_console_thread, NULL, EvccOs_ConsoleCommandThread, NULL);
    if (result == 0) {
        evcc_os_console_created = 1;
    } else {
        EvccOs_Printf("[OS] Console command task create failed: %d\n", result);
    }

    while (1) {
        EvccOs_DelayMs(1000U);
    }
}

void EvccOs_DelayMs(unsigned int delayMs)
{
    struct timespec request;

    request.tv_sec = (time_t)(delayMs / 1000U);
    request.tv_nsec = (long)((delayMs % 1000U) * 1000000UL);
    while (nanosleep(&request, &request) != 0) {
    }
}

void EvccOs_SetState(EvccOs_StateType state)
{
    pthread_mutex_lock(&evcc_os_state_mutex);
    evcc_os_state = state;
    pthread_mutex_unlock(&evcc_os_state_mutex);
}

EvccOs_StateType EvccOs_GetState(void)
{
    EvccOs_StateType state;

    pthread_mutex_lock(&evcc_os_state_mutex);
    state = evcc_os_state;
    pthread_mutex_unlock(&evcc_os_state_mutex);
    return state;
}

int EvccOs_IsRunning(void)
{
    return EvccOs_GetState() == EVCC_OS_STATE_RUN;
}

void EvccOs_Printf(const char *format, ...)
{
    va_list args;

    pthread_mutex_lock(&evcc_os_print_mutex);
    va_start(args, format);
    (void)vprintf(format, args);
    va_end(args);
    fflush(stdout);
    pthread_mutex_unlock(&evcc_os_print_mutex);
}

static void *EvccOs_TaskThread(void *argument)
{
    EvccOs_TaskControlBlock *task = (EvccOs_TaskControlBlock *)argument;

    while (1) {
        if (EvccOs_IsRunning()) {
            task->config->taskFunc();
        }
        EvccOs_DelayMs(task->config->periodMs);
    }

    return NULL;
}

static void *EvccOs_ConsoleCommandThread(void *argument)
{
    char line[32];

    (void)argument;
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[0] == '1') {
            EvccOs_SetState(EVCC_OS_STATE_RUN);
            EvccOs_Printf("[OS] System state changed: RUN\n");
        } else if (line[0] == '0') {
            EvccOs_SetState(EVCC_OS_STATE_STOP);
            EvccOs_Printf("[OS] System state changed: STOP\n");
        } else {
            line[strcspn(line, "\r\n")] = '\0';
            EvccOs_Printf("[OS] Unknown command: %s. Use 1=start/resume, 0=stop/pause\n", line);
        }
    }

    return NULL;
}

