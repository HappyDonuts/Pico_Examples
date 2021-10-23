#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"

const uint8_t LED_ON = 1;
const uint8_t LED_OFF = 0;

const uint8_t LED_PIN = 25;

void core_0_led(void);
void core_1_timing(void);

int main() {

    // Initialize LED pin
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Initialize chosen serial port
    stdio_init_all();

    // Launch second core loop
    multicore_launch_core1(core_1_timing);

    // Main core loop
    core_0_led();
}

// Main core loop
void core_0_led(void)
{
    while (1)
    {
        // Core 0 gets blocked waiting for fifo data to be popped
        uint32_t led_status = multicore_fifo_pop_blocking();
        gpio_put(LED_PIN, led_status);
    }
}

// Second core loop
void core_1_timing(void)
{
    while (1)
    {
        // Push data every 500 ms
        multicore_fifo_push_blocking(LED_ON);
        sleep_ms(500);
        multicore_fifo_push_blocking(LED_OFF);
        sleep_ms(500);
    }  
}