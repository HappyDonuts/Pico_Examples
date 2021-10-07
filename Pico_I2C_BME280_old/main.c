#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "bme280_old/bme280_handler.h"

int8_t user_i2c_read(uint8_t reg_addr, uint8_t *data, uint32_t len, void *intf_ptr);
void user_delay_us(uint32_t period, void *intf_ptr);
int8_t user_i2c_write(uint8_t reg_addr, const uint8_t *data, uint32_t len, void *intf_ptr);
static void print_sensor_data(struct bme280_data *comp_data);
static int8_t stream_sensor_data_forced_mode(struct bme280_dev *dev);



int main() {

    const uint led_pin = 25;

    // Initialize LED pin
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    // Initialize chosen serial port
    stdio_init_all();

    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    bme280_handle_t* bme280_handle = bme280_handle_new();

    float temp_f, hum_f, pre_f;
    uint16_t temp_u, hum_u, pre_u;

    while(1) {
        bme280h_get_data(bme280_handle);
        temp_f = bme280_handle->temperature;
		pre_f = bme280_handle->pressure;
		hum_f = bme280_handle->humidity;

        printf("%0.2lf deg C, %0.2lf hPa, %0.2lf%%\n", temp_f, pre_f, hum_f);

        sleep_ms(5000);
        
    }
    
}