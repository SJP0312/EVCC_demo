#include "Evcc_Os.h"

#include <pthread.h>
#include <string.h>

#define EVCC_OS_MAX_INTERRUPTS 16U

typedef struct
{
    int registered;
    int enabled;
    EvccOs_InterruptHandler handler;
    void *context;
} EvccOs_InterruptControlBlock;

static EvccOs_InterruptControlBlock evcc_os_interrupts[EVCC_OS_MAX_INTERRUPTS];
static pthread_mutex_t evcc_os_interrupt_mutex = PTHREAD_MUTEX_INITIALIZER;

void EvccOs_InterruptInit(void)
{
    pthread_mutex_lock(&evcc_os_interrupt_mutex);
    memset(evcc_os_interrupts, 0, sizeof(evcc_os_interrupts));
    pthread_mutex_unlock(&evcc_os_interrupt_mutex);
}

int EvccOs_RegisterInterrupt(unsigned int interruptId, EvccOs_InterruptHandler handler, void *context)
{
    if ((interruptId >= EVCC_OS_MAX_INTERRUPTS) || (handler == NULL)) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&evcc_os_interrupt_mutex);
    evcc_os_interrupts[interruptId].registered = 1;
    evcc_os_interrupts[interruptId].enabled = 0;
    evcc_os_interrupts[interruptId].handler = handler;
    evcc_os_interrupts[interruptId].context = context;
    pthread_mutex_unlock(&evcc_os_interrupt_mutex);
    return EVCC_OS_OK;
}

int EvccOs_EnableInterrupt(unsigned int interruptId)
{
    if (interruptId >= EVCC_OS_MAX_INTERRUPTS) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&evcc_os_interrupt_mutex);
    if (!evcc_os_interrupts[interruptId].registered) {
        pthread_mutex_unlock(&evcc_os_interrupt_mutex);
        return EVCC_OS_ERROR;
    }
    evcc_os_interrupts[interruptId].enabled = 1;
    pthread_mutex_unlock(&evcc_os_interrupt_mutex);
    return EVCC_OS_OK;
}

int EvccOs_DisableInterrupt(unsigned int interruptId)
{
    if (interruptId >= EVCC_OS_MAX_INTERRUPTS) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&evcc_os_interrupt_mutex);
    if (!evcc_os_interrupts[interruptId].registered) {
        pthread_mutex_unlock(&evcc_os_interrupt_mutex);
        return EVCC_OS_ERROR;
    }
    evcc_os_interrupts[interruptId].enabled = 0;
    pthread_mutex_unlock(&evcc_os_interrupt_mutex);
    return EVCC_OS_OK;
}

int EvccOs_TriggerInterrupt(unsigned int interruptId)
{
    EvccOs_InterruptHandler handler;
    void *context;

    if (interruptId >= EVCC_OS_MAX_INTERRUPTS) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&evcc_os_interrupt_mutex);
    if ((!evcc_os_interrupts[interruptId].registered) || (!evcc_os_interrupts[interruptId].enabled)) {
        pthread_mutex_unlock(&evcc_os_interrupt_mutex);
        return EVCC_OS_ERROR;
    }
    handler = evcc_os_interrupts[interruptId].handler;
    context = evcc_os_interrupts[interruptId].context;
    pthread_mutex_unlock(&evcc_os_interrupt_mutex);

    handler(context);
    return EVCC_OS_OK;
}
