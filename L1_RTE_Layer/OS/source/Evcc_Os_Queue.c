#include "Evcc_Os.h"

#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define EVCC_OS_MAX_QUEUES 8U
#define EVCC_OS_QUEUE_MAX_ITEM_SIZE 64U
#define EVCC_OS_QUEUE_MAX_LENGTH 16U

struct EvccOs_QueueControlBlock
{
    int inUse;
    size_t itemSize;
    size_t length;
    size_t head;
    size_t tail;
    size_t count;
    unsigned char storage[EVCC_OS_QUEUE_MAX_ITEM_SIZE * EVCC_OS_QUEUE_MAX_LENGTH];
    pthread_mutex_t mutex;
    pthread_cond_t notEmpty;
    pthread_cond_t notFull;
};

static struct EvccOs_QueueControlBlock evcc_os_queues[EVCC_OS_MAX_QUEUES];

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

void EvccOs_QueueInit(void)
{
    size_t index;

    for (index = 0U; index < EVCC_OS_MAX_QUEUES; index++) {
        if (evcc_os_queues[index].inUse) {
            pthread_mutex_destroy(&evcc_os_queues[index].mutex);
            pthread_cond_destroy(&evcc_os_queues[index].notEmpty);
            pthread_cond_destroy(&evcc_os_queues[index].notFull);
        }
    }
    memset(evcc_os_queues, 0, sizeof(evcc_os_queues));
}

EvccOs_QueueHandle EvccOs_QueueCreate(size_t itemSize, size_t length)
{
    size_t index;

    if ((itemSize == 0U) || (itemSize > EVCC_OS_QUEUE_MAX_ITEM_SIZE) ||
        (length == 0U) || (length > EVCC_OS_QUEUE_MAX_LENGTH)) {
        return NULL;
    }

    for (index = 0U; index < EVCC_OS_MAX_QUEUES; index++) {
        if (!evcc_os_queues[index].inUse) {
            evcc_os_queues[index].inUse = 1;
            evcc_os_queues[index].itemSize = itemSize;
            evcc_os_queues[index].length = length;
            evcc_os_queues[index].head = 0U;
            evcc_os_queues[index].tail = 0U;
            evcc_os_queues[index].count = 0U;
            pthread_mutex_init(&evcc_os_queues[index].mutex, NULL);
            pthread_cond_init(&evcc_os_queues[index].notEmpty, NULL);
            pthread_cond_init(&evcc_os_queues[index].notFull, NULL);
            return &evcc_os_queues[index];
        }
    }

    return NULL;
}

int EvccOs_QueueSend(EvccOs_QueueHandle queue, const void *item, unsigned int timeoutMs)
{
    struct timespec timeout;
    int waitResult = 0;

    if ((queue == NULL) || (item == NULL)) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&queue->mutex);
    if (timeoutMs != EVCC_OS_WAIT_FOREVER) {
        EvccOs_GetTimeoutTime(timeoutMs, &timeout);
    }

    while (queue->count >= queue->length) {
        if (timeoutMs == EVCC_OS_NO_WAIT) {
            pthread_mutex_unlock(&queue->mutex);
            return EVCC_OS_TIMEOUT;
        }
        if (timeoutMs == EVCC_OS_WAIT_FOREVER) {
            waitResult = pthread_cond_wait(&queue->notFull, &queue->mutex);
        } else {
            waitResult = pthread_cond_timedwait(&queue->notFull, &queue->mutex, &timeout);
        }
        if (waitResult == ETIMEDOUT) {
            pthread_mutex_unlock(&queue->mutex);
            return EVCC_OS_TIMEOUT;
        }
        if (waitResult != 0) {
            pthread_mutex_unlock(&queue->mutex);
            return EVCC_OS_ERROR;
        }
    }

    memcpy(&queue->storage[queue->tail * queue->itemSize], item, queue->itemSize);
    queue->tail = (queue->tail + 1U) % queue->length;
    queue->count++;
    pthread_cond_signal(&queue->notEmpty);
    pthread_mutex_unlock(&queue->mutex);
    return EVCC_OS_OK;
}

int EvccOs_QueueReceive(EvccOs_QueueHandle queue, void *item, unsigned int timeoutMs)
{
    struct timespec timeout;
    int waitResult = 0;

    if ((queue == NULL) || (item == NULL)) {
        return EVCC_OS_ERROR;
    }

    pthread_mutex_lock(&queue->mutex);
    if (timeoutMs != EVCC_OS_WAIT_FOREVER) {
        EvccOs_GetTimeoutTime(timeoutMs, &timeout);
    }

    while (queue->count == 0U) {
        if (timeoutMs == EVCC_OS_NO_WAIT) {
            pthread_mutex_unlock(&queue->mutex);
            return EVCC_OS_TIMEOUT;
        }
        if (timeoutMs == EVCC_OS_WAIT_FOREVER) {
            waitResult = pthread_cond_wait(&queue->notEmpty, &queue->mutex);
        } else {
            waitResult = pthread_cond_timedwait(&queue->notEmpty, &queue->mutex, &timeout);
        }
        if (waitResult == ETIMEDOUT) {
            pthread_mutex_unlock(&queue->mutex);
            return EVCC_OS_TIMEOUT;
        }
        if (waitResult != 0) {
            pthread_mutex_unlock(&queue->mutex);
            return EVCC_OS_ERROR;
        }
    }

    memcpy(item, &queue->storage[queue->head * queue->itemSize], queue->itemSize);
    queue->head = (queue->head + 1U) % queue->length;
    queue->count--;
    pthread_cond_signal(&queue->notFull);
    pthread_mutex_unlock(&queue->mutex);
    return EVCC_OS_OK;
}

int EvccOs_QueueSendFromIsr(EvccOs_QueueHandle queue, const void *item)
{
    return EvccOs_QueueSend(queue, item, EVCC_OS_NO_WAIT);
}
