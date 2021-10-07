#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "mcp9808/mcp9808.h"

const uint8_t sensor_addr =                 0x18;

const uint8_t MCP9808_REG_CONFIG =          0x01;
const uint8_t MCP9808_REG_TUPPER =          0x02;
const uint8_t MCP9808_REG_TLOWER =          0x03;
const uint8_t MCP9808_REG_TCRIT =           0x04;
const uint8_t MCP9808_REG_TA =              0x05;
const uint8_t MCP9808_REG_MANUFACTURER_ID = 0x06;
const uint8_t MCP9808_REG_DEVICE_ID =       0x07;
const uint8_t MCP9808_REG_RESOLUTION =      0x08;

const uint8_t MCP9808_RESOLUTION_0P5 =      0b00;
const uint8_t MCP9808_RESOLUTION_0P25 =     0b01;
const uint8_t MCP9808_RESOLUTION_0P125 =    0b10;
const uint8_t MCP9808_RESOLUTION_0P0625 =   0b11;

int main() {

    const uint8_t led_pin = 25;

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
    uint8_t rxdata[3];
    volatile float temp;

    uint8_t tx_data[2];
    // tx_data[0] = MCP9808_REG_CONFIG;
    // tx_data[1] = 0x01;
    // tx_data[2] = 0x00;
    // ret_1 = i2c_write_timeout_us(i2c_default, sensor_addr, tx_data, 3, false, 10*1000);
    // sleep_ms(100);
    
    tx_data[0] = MCP9808_REG_RESOLUTION;
    tx_data[1] = MCP9808_RESOLUTION_0P0625;
    ret_1 = i2c_write_timeout_us(i2c_default, sensor_addr, tx_data, 2, false, 10*1000);
    sleep_ms(100);
    
    // Loop forever
    while (true) {       

        ret_1 = i2c_write_timeout_us(i2c_default, sensor_addr, &MCP9808_REG_TA, 1, false, 10*1000);
        ret_2 = i2c_read_blocking(i2c_default, sensor_addr, rxdata, 2, false);

        if (ret_2 == 2) {
            rxdata[0] = (rxdata[0] & 0x0F) << 4; // MSB
            temp = rxdata[0] + ((float)rxdata[1])/16; // LSB
            printf("%.6f\n", temp);
        } else {
            printf("Sensor not detected \n");
        }

        sleep_ms(1000);
    }
}