
#pragma once

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <pico/stdlib.h>
#include <pico/multicore.h>


void unorphaned_lock(SemaphoreHandle_t semaphore, TickType_t timeout, int *counter);
void orphaned_lock(SemaphoreHandle_t semaphore, TickType_t timeout, int *counter);
