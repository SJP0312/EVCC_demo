#include "Evcc_Os.h"

#include <stdio.h>

#define TEST_EXPECTED_QUEUE_POOL_SIZE 8U
#define TEST_EXPECTED_SEMAPHORE_POOL_SIZE 8U
#define TEST_EXPECTED_EVENT_GROUP_POOL_SIZE 8U
#define TEST_EXPECTED_INTERRUPT_POOL_SIZE 16U

static int interrupt_counter;

static int AssertTrue(int condition, const char *message)
{
    if (!condition) {
        printf("FAIL: %s\n", message);
        return -1;
    }
    return 0;
}

static void BoundaryInterruptHandler(void *context)
{
    int *counter = (int *)context;

    (*counter)++;
}

static int TestQueueBoundaries(void)
{
    EvccOs_QueueHandle queues[TEST_EXPECTED_QUEUE_POOL_SIZE];
    EvccOs_QueueHandle queue;
    int value;
    int output;
    size_t index;

    EvccOs_Init();

    if (AssertTrue(EvccOs_QueueCreate(0U, 1U) == NULL, "queue rejects zero item size") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_QueueCreate(65U, 1U) == NULL, "queue rejects item size above static max") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_QueueCreate(sizeof(int), 0U) == NULL, "queue rejects zero length") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_QueueCreate(sizeof(int), 17U) == NULL, "queue rejects length above static max") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_QueueSend(NULL, &value, EVCC_OS_NO_WAIT) == EVCC_OS_ERROR, "queue send rejects null queue") != 0) {
        return -1;
    }

    queue = EvccOs_QueueCreate(sizeof(int), 2U);
    if (AssertTrue(queue != NULL, "queue create for full/empty boundary") != 0) {
        return -1;
    }

    value = 1;
    if (AssertTrue(EvccOs_QueueSend(queue, &value, EVCC_OS_NO_WAIT) == EVCC_OS_OK, "queue send first item") != 0) {
        return -1;
    }
    value = 2;
    if (AssertTrue(EvccOs_QueueSend(queue, &value, EVCC_OS_NO_WAIT) == EVCC_OS_OK, "queue send second item") != 0) {
        return -1;
    }
    value = 3;
    if (AssertTrue(EvccOs_QueueSend(queue, &value, EVCC_OS_NO_WAIT) == EVCC_OS_TIMEOUT, "queue full returns timeout") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_QueueReceive(queue, &output, EVCC_OS_NO_WAIT) == EVCC_OS_OK, "queue receive first item") != 0) {
        return -1;
    }
    if (AssertTrue(output == 1, "queue preserves first payload") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_QueueReceive(queue, &output, EVCC_OS_NO_WAIT) == EVCC_OS_OK, "queue receive second item") != 0) {
        return -1;
    }
    if (AssertTrue(output == 2, "queue preserves second payload") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_QueueReceive(queue, &output, EVCC_OS_NO_WAIT) == EVCC_OS_TIMEOUT, "queue empty returns timeout") != 0) {
        return -1;
    }

    EvccOs_Init();
    for (index = 0U; index < TEST_EXPECTED_QUEUE_POOL_SIZE; index++) {
        queues[index] = EvccOs_QueueCreate(sizeof(int), 1U);
        if (AssertTrue(queues[index] != NULL, "queue pool slot allocation") != 0) {
            return -1;
        }
    }
    if (AssertTrue(EvccOs_QueueCreate(sizeof(int), 1U) == NULL, "queue pool exhaustion returns null") != 0) {
        return -1;
    }

    EvccOs_Init();
    if (AssertTrue(EvccOs_QueueCreate(sizeof(int), 1U) != NULL, "queue pool reset after init") != 0) {
        return -1;
    }

    return 0;
}

static int TestSemaphoreBoundaries(void)
{
    EvccOs_SemaphoreHandle semaphores[TEST_EXPECTED_SEMAPHORE_POOL_SIZE];
    EvccOs_SemaphoreHandle semaphore;
    size_t index;

    EvccOs_Init();

    if (AssertTrue(EvccOs_SemaphoreCreateBinary(2U) == NULL, "binary semaphore rejects initial count above one") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_SemaphoreCreateCounting(0U, 0U) == NULL, "counting semaphore rejects zero max") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_SemaphoreCreateCounting(2U, 3U) == NULL, "counting semaphore rejects initial above max") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_SemaphoreTake(NULL, EVCC_OS_NO_WAIT) == EVCC_OS_ERROR, "semaphore take rejects null") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_SemaphoreGive(NULL) == EVCC_OS_ERROR, "semaphore give rejects null") != 0) {
        return -1;
    }

    semaphore = EvccOs_SemaphoreCreateCounting(2U, 2U);
    if (AssertTrue(semaphore != NULL, "counting semaphore create at max") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_SemaphoreGive(semaphore) == EVCC_OS_ERROR, "counting semaphore overflow rejected") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_SemaphoreTake(semaphore, EVCC_OS_NO_WAIT) == EVCC_OS_OK, "counting semaphore take from max") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_SemaphoreTake(semaphore, EVCC_OS_NO_WAIT) == EVCC_OS_OK, "counting semaphore take second token") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_SemaphoreTake(semaphore, EVCC_OS_NO_WAIT) == EVCC_OS_TIMEOUT, "empty semaphore returns timeout") != 0) {
        return -1;
    }

    EvccOs_Init();
    for (index = 0U; index < TEST_EXPECTED_SEMAPHORE_POOL_SIZE; index++) {
        semaphores[index] = EvccOs_SemaphoreCreateBinary(0U);
        if (AssertTrue(semaphores[index] != NULL, "semaphore pool slot allocation") != 0) {
            return -1;
        }
    }
    if (AssertTrue(EvccOs_SemaphoreCreateBinary(0U) == NULL, "semaphore pool exhaustion returns null") != 0) {
        return -1;
    }

    EvccOs_Init();
    if (AssertTrue(EvccOs_SemaphoreCreateBinary(0U) != NULL, "semaphore pool reset after init") != 0) {
        return -1;
    }

    return 0;
}

static int TestEventGroupBoundaries(void)
{
    EvccOs_EventGroupHandle eventGroups[TEST_EXPECTED_EVENT_GROUP_POOL_SIZE];
    EvccOs_EventGroupHandle eventGroup;
    EvccOs_EventBitsType matchedBits;
    size_t index;

    EvccOs_Init();

    if (AssertTrue(EvccOs_EventGroupSetBits(NULL, 0x01U) == EVCC_OS_ERROR, "event set rejects null") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_EventGroupClearBits(NULL, 0x01U) == EVCC_OS_ERROR, "event clear rejects null") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_EventGroupWaitBits(NULL, 0x01U, 0, 0, EVCC_OS_NO_WAIT, &matchedBits) == EVCC_OS_ERROR, "event wait rejects null") != 0) {
        return -1;
    }

    eventGroup = EvccOs_EventGroupCreate();
    if (AssertTrue(eventGroup != NULL, "event group create") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_EventGroupWaitBits(eventGroup, 0U, 0, 0, EVCC_OS_NO_WAIT, &matchedBits) == EVCC_OS_ERROR, "event wait rejects zero bits") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_EventGroupWaitBits(eventGroup, 0x01U, 0, 1, EVCC_OS_NO_WAIT, &matchedBits) == EVCC_OS_TIMEOUT, "event wait missing bit timeout") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_EventGroupSetBits(eventGroup, 0x01U) == EVCC_OS_OK, "event set single bit") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_EventGroupWaitBits(eventGroup, 0x03U, 0, 1, EVCC_OS_NO_WAIT, &matchedBits) == EVCC_OS_TIMEOUT, "event wait all missing bit timeout") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_EventGroupWaitBits(eventGroup, 0x03U, 0, 0, EVCC_OS_NO_WAIT, &matchedBits) == EVCC_OS_OK, "event wait any succeeds") != 0) {
        return -1;
    }
    if (AssertTrue((matchedBits & 0x01U) != 0U, "event wait any matched bit") != 0) {
        return -1;
    }

    EvccOs_Init();
    for (index = 0U; index < TEST_EXPECTED_EVENT_GROUP_POOL_SIZE; index++) {
        eventGroups[index] = EvccOs_EventGroupCreate();
        if (AssertTrue(eventGroups[index] != NULL, "event group pool slot allocation") != 0) {
            return -1;
        }
    }
    if (AssertTrue(EvccOs_EventGroupCreate() == NULL, "event group pool exhaustion returns null") != 0) {
        return -1;
    }

    EvccOs_Init();
    if (AssertTrue(EvccOs_EventGroupCreate() != NULL, "event group pool reset after init") != 0) {
        return -1;
    }

    return 0;
}

static int TestInterruptBoundaries(void)
{
    unsigned int index;

    EvccOs_Init();
    interrupt_counter = 0;

    if (AssertTrue(EvccOs_RegisterInterrupt(TEST_EXPECTED_INTERRUPT_POOL_SIZE, BoundaryInterruptHandler, &interrupt_counter) == EVCC_OS_ERROR, "interrupt rejects invalid register id") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_RegisterInterrupt(0U, NULL, &interrupt_counter) == EVCC_OS_ERROR, "interrupt rejects null handler") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_EnableInterrupt(0U) == EVCC_OS_ERROR, "interrupt enable rejects unregistered id") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_TriggerInterrupt(0U) == EVCC_OS_ERROR, "interrupt trigger rejects unregistered id") != 0) {
        return -1;
    }

    for (index = 0U; index < TEST_EXPECTED_INTERRUPT_POOL_SIZE; index++) {
        if (AssertTrue(EvccOs_RegisterInterrupt(index, BoundaryInterruptHandler, &interrupt_counter) == EVCC_OS_OK, "interrupt register slot") != 0) {
            return -1;
        }
    }
    if (AssertTrue(EvccOs_TriggerInterrupt(0U) == EVCC_OS_ERROR, "interrupt disabled trigger rejected") != 0) {
        return -1;
    }
    if (AssertTrue(interrupt_counter == 0, "disabled interrupt did not run handler") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_EnableInterrupt(0U) == EVCC_OS_OK, "interrupt enable registered id") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_TriggerInterrupt(0U) == EVCC_OS_OK, "interrupt trigger enabled id") != 0) {
        return -1;
    }
    if (AssertTrue(interrupt_counter == 1, "enabled interrupt ran handler") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_DisableInterrupt(0U) == EVCC_OS_OK, "interrupt disable registered id") != 0) {
        return -1;
    }
    if (AssertTrue(EvccOs_TriggerInterrupt(0U) == EVCC_OS_ERROR, "disabled interrupt trigger rejected again") != 0) {
        return -1;
    }
    if (AssertTrue(interrupt_counter == 1, "disabled interrupt did not run handler again") != 0) {
        return -1;
    }

    EvccOs_Init();
    if (AssertTrue(EvccOs_TriggerInterrupt(0U) == EVCC_OS_ERROR, "interrupt table reset after init") != 0) {
        return -1;
    }

    return 0;
}

int main(void)
{
    if (TestQueueBoundaries() != 0) {
        return 1;
    }
    if (TestSemaphoreBoundaries() != 0) {
        return 1;
    }
    if (TestEventGroupBoundaries() != 0) {
        return 1;
    }
    if (TestInterruptBoundaries() != 0) {
        return 1;
    }

    printf("OS API boundary test passed.\n");
    return 0;
}
