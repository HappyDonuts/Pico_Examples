#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

int main() {

    const uint8_t led_pin = 25;
    const uint8_t sensor_addr = 0x18;

    const uint8_t MCP9808_REG_AMBIENT_TEMP = 0x05;

    const uint8_t MCP9808_REG_RESOLUTION = 0x08;
    const uint8_t MCP9808_RESOLUTION_05 = 0x00;

    // Initialize LED pin
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    // Initialize chosen serial port
    stdio_init_all();

    // Config I2C interface
    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    volatile uint8_t ret_1, ret_2;
    uint8_t rxdata[2];
    volatile float temp;

    // Loop forever
    while (true) {       

        ret_1 = i2c_write_timeout_us(i2c_default,sensor_addr, &MCP9808_REG_AMBIENT_TEMP, 1, false, 10*1000);
        ret_2 = i2c_read_blocking(i2c_default, sensor_addr, rxdata, 2, false);
       
        rxdata[0] = (rxdata[0] & 0x0F) << 4; // MSB
        temp = rxdata[0] + ((float)rxdata[1])/16; // LSB
        printf("%.6f\n", temp);

         sleep_ms(1000);
    }
}