

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "bme280/bme280_api.h"

int main() {

    const uint led_pin = 25;

    // Initialize LED pin
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    // Initialize chosen serial port
    stdio_init_all();

    // Initialize I2C interface pins
    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    // BME280 handle declaration
    bme280_handle_t* bme280_1 = bme280_handle_new(BME280_I2C_ADDR_PRIM);

    // Loop forever
    while (true) {

        // Get BME280 data
        int8_t rslt = bme280_api_get_data(bme280_1);

        if (rslt != BME280_OK) {
            fprintf(stderr, "Failed to stream sensor data (code %+d).\n", rslt);
            exit(1);
        } else {
            bme280_api_print_data(bme280_1);
        }
        sleep_ms(2000);
    }
}





