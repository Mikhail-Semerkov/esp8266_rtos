#include "esp_common.h"
#include "freertos/task.h"
#include "gpio.h"
#include "uart.h"

#define UART0_BAUD 115200

void task_test1(void* ignore)
{
    while(true) 
    {
        printf("task_test1\r\n");
        vTaskDelay(500/portTICK_RATE_MS);
    }

    vTaskDelete(NULL);
}

void task_test2(void* ignore)
{
    while(true) 
    {
        printf("task_test2\r\n");
        vTaskDelay(200/portTICK_RATE_MS);
    }

    vTaskDelete(NULL);
}

void user_init(void)
{
    UART_SetBaudrate(UART0, UART0_BAUD);
    xTaskCreate(&task_test1, "task_test1", configMINIMAL_STACK_SIZE * 1, NULL, 1, NULL);
    xTaskCreate(&task_test2, "task_test2", configMINIMAL_STACK_SIZE * 1, NULL, 1, NULL);
}

