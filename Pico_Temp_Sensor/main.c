#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {

    const uint8_t led_pin = 25;
    const float conversion_factor = 3.3f / (1 << 12);

    // Initialize LED pin
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    // Initialize chosen serial port
    stdio_init_all();

    // ADC init
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);

    // Loop forever
    while (true) {
 
        uint16_t adc_raw = adc_read();
        float adc_voltage = adc_raw * conversion_factor;

        // Default calibration is terrible... 
        float temp = 27 - (adc_voltage - 0.706)/0.001721;

        printf("%.2f \r\n", temp);
        sleep_ms(500);
    }
}