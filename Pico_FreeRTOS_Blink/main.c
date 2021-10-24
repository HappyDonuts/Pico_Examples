#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

void BlinkTask(void *param);
void HelloTask(void *param);

const uint8_t led_pin = 25;
const uint16_t period_blink_ms = 500;
const uint16_t period_hello_ms = 1000;

int main() {

    // Initialize LED pin
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    // Initialize chosen serial port
    stdio_init_all();

    // Task handles
    TaskHandle_t blinkHandle = NULL;
    TaskHandle_t helloHandle = NULL;

    // Tasks creation
    xTaskCreate(BlinkTask, "Blink LED", 1024, NULL, tskIDLE_PRIORITY, &blinkHandle);
    xTaskCreate(HelloTask, "Hello world printf", 1024, NULL, 1, &helloHandle);

    // FreeRTOS scheduler starts
    vTaskStartScheduler();

}

void BlinkTask(void *param)
{
    uint32_t ticks = xTaskGetTickCount();
    for(;;)
    {
        uint8_t led_status = gpio_get_out_level(led_pin);
        gpio_put(led_pin, !(led_status));
        vTaskDelayUntil(&ticks, period_blink_ms);
    }
}

void HelloTask(void *param)
{
    uint32_t ticks = xTaskGetTickCount();
    for(;;)
    {
        printf("Hello World using FreeRTOS!\r\n");
        vTaskDelayUntil(&ticks, period_hello_ms);
    }
}