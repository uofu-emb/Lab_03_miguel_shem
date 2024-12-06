#include <stdio.h>

#include "deadlock.h"


void orphaned_lock(SemaphoreHandle_t semaphore, TickType_t timeout, int *counter)
{
    while (1) {
        xSemaphoreTake(semaphore, portMAX_DELAY);
        *counter++;
        if (*counter % 2) {
            continue;
        }
        printf("Count %d\n", *counter);
        xSemaphoreGive(&semaphore);
    }
}

void unorphaned_lock(SemaphoreHandle_t semaphore, TickType_t timeout, int *counter)
{
  xSemaphoreTake(semaphore, portMAX_DELAY);
  *counter++;
  if (*counter % 2) {
    vTaskDelay(100);
  }
  printf("Count %d\n", *counter);
  xSemaphoreGive(&semaphore);
}
