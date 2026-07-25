#include "Evcc_Os.h"

#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define EVCC_OS_MAX_SEMAPHORES 8U

struct EvccOs_SemaphoreControlBlock
{
    int inUse;
    unsigned int count;
    unsigned int maxCount;
    pthread_mutex_t mutex;
    pthread_cond_t available;
};

static struct EvccOs_SemaphoreControlBlock evcc_os_semaphores[EVCC_OS_MAX_SEMAPHORES];

static void EvccOs_GetTimeoutTime(unsigned int timeoutMs, struct timespec *timeValue)
{
    clock_gettime(CLOCK_REALTIME, timeValue);
    timeValue->tv_sec += (time_t)(timeoutMs / 1000U);
    timeValue->tv_nsec += (long)((timeoutMs % 1000U) * 1000000UL);
    if (timeValue->tv_nsec >= 1000000000L) {
        timeValue->tv_sec++;
        timeValue->tv_nsec -= 1000000000L;
    }
}

void EvccOs_SemaphoreInit(void)
{
    size_t index;

    for (index = 0U; index < EVCC_OS_MAX_SEMAPHORES; index++) {
        if (evcc_os_semaphores[index].inUse) {
            pthread_mutex_destroy(&evcc_os_semaphores[index].mutex);
            pthread_cond_destroy(&evcc_os_semaphores[index].available);
        }
    }
    memset(evcc_os_semaphores, 0, sizeof(evcc_os_semaphores));
}

EvccOs_SemaphoreHandle EvccOs_SemaphoreCreateCounting(unsigned int maxCount, unsigned int initialCount)
{
    size_t index;

    if ((maxCount == 0U) || (initialCount > maxCount)) {
        return NULL;
    }

    for (index = 0U; index < EVCC_OS_MAX_SEMAPHORES; index++) {
        if (!evcc_os_semaphores[index].inUse) {
            evcc_os_semaphores[index].inUse = 1;
            evcc_os_semaphores[index].count = initialCount;
            evcc_os_semaphores[index].maxCount = maxCount;
            pthread_mutex_init(&evcc_os_semaphores[index].mutex, NULL);
            pthread_cond_init(&evcc_os_semaphores[index].available, NULL);
            return &evcc_os_semaphores[index];
        }
    }

    return NULL;
}

EvccOs_SemaphoreHandle EvccOs_SemaphoreCreateBinary(unsigned int initialCount)
{
    if (initialCount > 1U) {
        return NULL;
    }

    return EvccOs_SemaphoreCreateCounting(1U, initialCount);
}

int EvccOs_SemaphoreTake(EvccOs_SemaphoreHandle semaphore, unsigned int timeoutMs)
{
    struct timespec timeout;
    int waitResult = 0;

    if (semaphore == NULL) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&semaphore->mutex);
    if (timeoutMs != EVCC_OS_WAIT_FOREVER) {
        EvccOs_GetTimeoutTime(timeoutMs, &timeout);
    }

    while (semaphore->count == 0U) {
        if (timeoutMs == EVCC_OS_NO_WAIT) {
            pthread_mutex_unlock(&semaphore->mutex);
            return EVCC_OS_TIMEOUT;
        }
        if (timeoutMs == EVCC_OS_WAIT_FOREVER) {
            waitResult = pthread_cond_wait(&semaphore->available, &semaphore->mutex);
        } else {
            waitResult = pthread_cond_timedwait(&semaphore->available, &semaphore->mutex, &timeout);
        }
        if (waitResult == ETIMEDOUT) {
            pthread_mutex_unlock(&semaphore->mutex);
            return EVCC_OS_TIMEOUT;
        }
        if (waitResult != 0) {
            pthread_mutex_unlock(&semaphore->mutex);
            return EVCC_OS_ERROR;
        }
    }

    semaphore->count--;
    pthread_mutex_unlock(&semaphore->mutex);
    return EVCC_OS_OK;
}

int EvccOs_SemaphoreGive(EvccOs_SemaphoreHandle semaphore)
{
    if (semaphore == NULL) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&semaphore->mutex);
    if (semaphore->count >= semaphore->maxCount) {
        pthread_mutex_unlock(&semaphore->mutex);
        return EVCC_OS_ERROR;
    }

    semaphore->count++;
    pthread_cond_signal(&semaphore->available);
    pthread_mutex_unlock(&semaphore->mutex);
    return EVCC_OS_OK;
}

int EvccOs_SemaphoreGiveFromIsr(EvccOs_SemaphoreHandle semaphore)
{
    return EvccOs_SemaphoreGive(semaphore);
}
