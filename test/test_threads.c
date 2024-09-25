#include <stdio.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <pico/stdlib.h>
#include <pico/multicore.h>
#include <pico/cyw43_arch.h>
#include <unity.h>
#include "unity_config.h"

#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

#define SIDE_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define SIDE_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

SemaphoreHandle_t semaphore;
int counter = 0;

void setUp(void) {}

void tearDown(void) {}

void test_semaphore_work()
{
  vTaskDelay(1000);
  if( semaphore != NULL )
    {
        /* See if we can obtain the semaphore. If the semaphore is not
           available wait 10 ticks to see if it becomes free. */
        if( xSemaphoreTake(semaphore, portMAX_DELAY) == pdTRUE )
        {
	  counter += counter + 1; // should be = counter + 1 and not += counter + 1
	  printf("hello world from %s! Count %d\n", "thread", counter);
	}
	xSemaphoreGive(semaphore);
    }
}

int main (void)
{
    stdio_init_all();
    semaphore = xSemaphoreCreateCounting(1, 1);
    sleep_ms(5000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(test_semaphore_work);
    sleep_ms(5000);
    return UNITY_END();
}
