#include <stdio.h>
#include "pico/stdlib.h"

int main() {

    const uint led_pin = 25;

    // Initialize LED pin
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    // Initialize chosen serial port
    stdio_init_all();

    // Loop forever
    while (true) {

        printf("Hello World!\r\n");
        sleep_ms(1000);
    }
}