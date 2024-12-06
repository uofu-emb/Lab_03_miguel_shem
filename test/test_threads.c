#include <stdio.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <pico/stdlib.h>
#include <pico/multicore.h>
#include <pico/cyw43_arch.h>

#ifndef UNITY
#include <unity.h>
#include "unity_config.h"
#endif

#include "deadlock.h"

#ifndef PRIORITIES

#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 2UL )
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

#define SIDE_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define SIDE_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

#endif


SemaphoreHandle_t semaphore, semaphoreB, semaphoreA;
TaskHandle_t task_1, task_2;
int* counter = 0;


void task1(void *pvParameters);
void task2(void *pvParameters);

void setUp(void) {}

void tearDown(void) {}


void test_semaphore_work()
{
  vTaskDelay(100);
  if( semaphore != NULL )
    {
        /* See if we can obtain the semaphore. If the semaphore is not
           available wait 10 ticks to see if it becomes free. */
      int res = xSemaphoreTake( semaphore, ( TickType_t ) 10 );
      if(res  == pdTRUE)
        {
	  *counter += 1; // should be = counter + 1 and not += counter + 1
	  printf("hello world from %s! Count %d\n", "thread", *counter);
	}
	xSemaphoreGive(semaphore);
    }
  TEST_ASSERT_EQUAL_INT(1, counter);
}


void test_deadlocked_work()
{
    // Create tasks that use orphaned_lock to create a deadlock scenario
    TaskHandle_t task_1Handle, task_2Handle;

    // Initialize counter
    int count = 0;
    counter = &count;

    // Create Task 1 that locks semaphoreA, then semaphoreB
    xTaskCreate(task1, "Task_1", SIDE_TASK_STACK_SIZE, NULL, SIDE_TASK_PRIORITY, &task_1Handle);

    // Create Task 2 that locks semaphoreB, then semaphoreA
    xTaskCreate(task2, "Task_2", SIDE_TASK_STACK_SIZE, NULL, SIDE_TASK_PRIORITY, &task_2Handle);

    // Allow time for the tasks to execute and potentially deadlock
    vTaskDelay(100);

    // Check if counter was incremented, indicating no deadlock occurred
    // If deadlock happens, neither task will increment the counter
    TEST_ASSERT_EQUAL_INT(0, *counter);

    // Cleanup tasks after test
    vTaskDelete(task_1Handle);
    vTaskDelete(task_2Handle);
}



// Task 1: Acquire semaphoreA first, then semaphoreB
void task1(void *pvParameters)
{
    orphaned_lock(semaphoreA, portMAX_DELAY, counter);
    vTaskDelete(NULL); // Cleanup task after execution
}

// Task 2: Acquire semaphoreB first, then semaphoreA
void task2(void *pvParameters)
{
    orphaned_lock(semaphoreB, portMAX_DELAY, counter);
    vTaskDelete(NULL); // Cleanup task after execution
}


void run_test(){
  sleep_ms(10000); // Give time for TTY to attach.
  printf("Start tests\n");
  UNITY_BEGIN();
  RUN_TEST(test_semaphore_work);
  sleep_ms(10000);
  RUN_TEST(test_deadlocked_work);
  sleep_ms(10000);
  UNITY_END();
}

int main (void)
{
    stdio_init_all();
    TaskHandle_t main;
    semaphore = xSemaphoreCreateCounting(1, 1);
    semaphoreB = xSemaphoreCreateCounting(1, 1);
    semaphoreA = xSemaphoreCreateCounting(1, 1);
    if(semaphore)
      {
	printf("Semaphore is good.");
      }
    if(semaphoreA)
      {
	printf("SemaphoreA is good.");
      }
    if(semaphoreB)
      {
	printf("SemaphoreB is good.");
      }
    xTaskCreate(run_test, "run_test",
                MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &main);
}
