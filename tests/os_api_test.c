#include "Evcc_Os.h"

#include <stdio.h>
#include <string.h>

static EvccOs_SemaphoreHandle interrupt_semaphore;
static int interrupt_counter;

static int AssertTrue(int condition, const char *message)
{
    if (!condition) {
        printf("FAIL: %s\n", message);
        return -1;
    }
    return 0;
}

static void TestInterruptHandler(void *context)
{
    int *counter = (int *)context;

    (*counter)++;
    (void)EvccOs_SemaphoreGiveFromIsr(interrupt_semaphore);
}

int main(void)
{
    EvccOs_QueueHandle queue;
    EvccOs_SemaphoreHandle binary_semaphore;
    EvccOs_SemaphoreHandle counting_semaphore;
    EvccOs_EventGroupHandle event_group;
    EvccOs_EventBitsType matched_bits;
    int sent_value;
    int received_value;

    EvccOs_Init();

    queue = EvccOs_QueueCreate(sizeof(int), 2U);
    if (AssertTrue(queue != NULL, "queue create") != 0) {
        return 1;
    }

    sent_value = 42;
    received_value = 0;
    if (AssertTrue(EvccOs_QueueSend(queue, &sent_value, EVCC_OS_NO_WAIT) == EVCC_OS_OK, "queue send") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_QueueReceive(queue, &received_value, EVCC_OS_NO_WAIT) == EVCC_OS_OK, "queue receive") != 0) {
        return 1;
    }
    if (AssertTrue(received_value == 42, "queue payload") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_QueueReceive(queue, &received_value, EVCC_OS_NO_WAIT) == EVCC_OS_TIMEOUT, "queue empty timeout") != 0) {
        return 1;
    }

    binary_semaphore = EvccOs_SemaphoreCreateBinary(0U);
    if (AssertTrue(binary_semaphore != NULL, "binary semaphore create") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_SemaphoreTake(binary_semaphore, EVCC_OS_NO_WAIT) == EVCC_OS_TIMEOUT, "binary semaphore empty") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_SemaphoreGive(binary_semaphore) == EVCC_OS_OK, "binary semaphore give") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_SemaphoreTake(binary_semaphore, EVCC_OS_NO_WAIT) == EVCC_OS_OK, "binary semaphore take") != 0) {
        return 1;
    }

    counting_semaphore = EvccOs_SemaphoreCreateCounting(2U, 1U);
    if (AssertTrue(counting_semaphore != NULL, "counting semaphore create") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_SemaphoreGive(counting_semaphore) == EVCC_OS_OK, "counting semaphore give to max") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_SemaphoreGive(counting_semaphore) == EVCC_OS_ERROR, "counting semaphore overflow") != 0) {
        return 1;
    }

    event_group = EvccOs_EventGroupCreate();
    if (AssertTrue(event_group != NULL, "event group create") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_EventGroupSetBits(event_group, 0x03U) == EVCC_OS_OK, "event set bits") != 0) {
        return 1;
    }
    matched_bits = 0U;
    if (AssertTrue(EvccOs_EventGroupWaitBits(event_group, 0x03U, 1, 1, EVCC_OS_NO_WAIT, &matched_bits) == EVCC_OS_OK, "event wait all") != 0) {
        return 1;
    }
    if (AssertTrue((matched_bits & 0x03U) == 0x03U, "event matched bits") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_EventGroupWaitBits(event_group, 0x03U, 0, 1, EVCC_OS_NO_WAIT, &matched_bits) == EVCC_OS_TIMEOUT, "event clear on exit") != 0) {
        return 1;
    }

    interrupt_semaphore = EvccOs_SemaphoreCreateBinary(0U);
    interrupt_counter = 0;
    if (AssertTrue(EvccOs_RegisterInterrupt(0U, TestInterruptHandler, &interrupt_counter) == EVCC_OS_OK, "interrupt register") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_EnableInterrupt(0U) == EVCC_OS_OK, "interrupt enable") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_TriggerInterrupt(0U) == EVCC_OS_OK, "interrupt trigger") != 0) {
        return 1;
    }
    if (AssertTrue(interrupt_counter == 1, "interrupt handler called") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_SemaphoreTake(interrupt_semaphore, EVCC_OS_NO_WAIT) == EVCC_OS_OK, "interrupt semaphore") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_DisableInterrupt(0U) == EVCC_OS_OK, "interrupt disable") != 0) {
        return 1;
    }
    if (AssertTrue(EvccOs_TriggerInterrupt(0U) == EVCC_OS_ERROR, "disabled interrupt blocked") != 0) {
        return 1;
    }
    if (AssertTrue(interrupt_counter == 1, "disabled interrupt not called") != 0) {
        return 1;
    }

    printf("OS API test passed.\n");
    return 0;
}
