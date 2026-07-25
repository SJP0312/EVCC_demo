#include "Evcc_Os.h"

#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define EVCC_OS_MAX_EVENT_GROUPS 8U

struct EvccOs_EventGroupControlBlock
{
    int inUse;
    EvccOs_EventBitsType bits;
    pthread_mutex_t mutex;
    pthread_cond_t changed;
};

static struct EvccOs_EventGroupControlBlock evcc_os_event_groups[EVCC_OS_MAX_EVENT_GROUPS];

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

static int EvccOs_EventBitsMatch(EvccOs_EventBitsType currentBits,
                                 EvccOs_EventBitsType bitsToWaitFor,
                                 int waitForAllBits)
{
    if (waitForAllBits) {
        return (currentBits & bitsToWaitFor) == bitsToWaitFor;
    }

    return (currentBits & bitsToWaitFor) != 0U;
}

void EvccOs_EventGroupInit(void)
{
    size_t index;

    for (index = 0U; index < EVCC_OS_MAX_EVENT_GROUPS; index++) {
        if (evcc_os_event_groups[index].inUse) {
            pthread_mutex_destroy(&evcc_os_event_groups[index].mutex);
            pthread_cond_destroy(&evcc_os_event_groups[index].changed);
        }
    }
    memset(evcc_os_event_groups, 0, sizeof(evcc_os_event_groups));
}

EvccOs_EventGroupHandle EvccOs_EventGroupCreate(void)
{
    size_t index;

    for (index = 0U; index < EVCC_OS_MAX_EVENT_GROUPS; index++) {
        if (!evcc_os_event_groups[index].inUse) {
            evcc_os_event_groups[index].inUse = 1;
            evcc_os_event_groups[index].bits = 0U;
            pthread_mutex_init(&evcc_os_event_groups[index].mutex, NULL);
            pthread_cond_init(&evcc_os_event_groups[index].changed, NULL);
            return &evcc_os_event_groups[index];
        }
    }

    return NULL;
}

int EvccOs_EventGroupSetBits(EvccOs_EventGroupHandle eventGroup, EvccOs_EventBitsType bits)
{
    if (eventGroup == NULL) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&eventGroup->mutex);
    eventGroup->bits |= bits;
    pthread_cond_broadcast(&eventGroup->changed);
    pthread_mutex_unlock(&eventGroup->mutex);
    return EVCC_OS_OK;
}

int EvccOs_EventGroupClearBits(EvccOs_EventGroupHandle eventGroup, EvccOs_EventBitsType bits)
{
    if (eventGroup == NULL) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&eventGroup->mutex);
    eventGroup->bits &= ~bits;
    pthread_mutex_unlock(&eventGroup->mutex);
    return EVCC_OS_OK;
}

int EvccOs_EventGroupWaitBits(EvccOs_EventGroupHandle eventGroup,
                              EvccOs_EventBitsType bitsToWaitFor,
                              int clearOnExit,
                              int waitForAllBits,
                              unsigned int timeoutMs,
                              EvccOs_EventBitsType *matchedBits)
{
    struct timespec timeout;
    int waitResult = 0;

    if ((eventGroup == NULL) || (bitsToWaitFor == 0U)) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&eventGroup->mutex);
    if (timeoutMs != EVCC_OS_WAIT_FOREVER) {
        EvccOs_GetTimeoutTime(timeoutMs, &timeout);
    }

    while (!EvccOs_EventBitsMatch(eventGroup->bits, bitsToWaitFor, waitForAllBits)) {
        if (timeoutMs == EVCC_OS_NO_WAIT) {
            pthread_mutex_unlock(&eventGroup->mutex);
            return EVCC_OS_TIMEOUT;
        }
        if (timeoutMs == EVCC_OS_WAIT_FOREVER) {
            waitResult = pthread_cond_wait(&eventGroup->changed, &eventGroup->mutex);
        } else {
            waitResult = pthread_cond_timedwait(&eventGroup->changed, &eventGroup->mutex, &timeout);
        }
        if (waitResult == ETIMEDOUT) {
            pthread_mutex_unlock(&eventGroup->mutex);
            return EVCC_OS_TIMEOUT;
        }
        if (waitResult != 0) {
            pthread_mutex_unlock(&eventGroup->mutex);
            return EVCC_OS_ERROR;
        }
    }

    if (matchedBits != NULL) {
        *matchedBits = eventGroup->bits;
    }
    if (clearOnExit) {
        eventGroup->bits &= ~bitsToWaitFor;
    }

    pthread_mutex_unlock(&eventGroup->mutex);
    return EVCC_OS_OK;
}
