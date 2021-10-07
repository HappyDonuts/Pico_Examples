/*
 * bme280_api.c
 *
 *  Created on: Oct 01, 2021
 *      Author: Javier Morales
 */

#include "bme280_api.h"

/**
 * @brief  Initializes kim handler struct
 * @param  *kim_handler: pointer to kim_handler structure
 * @param  *hrtc: RTC peripheral
 * @param  *huart: UART peripheral used for logging (can be NULL)
 * @retval none
 */
bme280_handle_t* bme280_handle_new(uint8_t address)
{
	bme280_handle_t* bme280_handle = malloc(sizeof(*bme280_handle));
	bme280_handle_init(bme280_handle, address);
	return bme280_handle;
}

/**
 * @brief  Initializes kim handler struct
 * @param  *kim_handler: pointer to kim_handler structure
 * @param  *hrtc: RTC peripheral
 * @param  *huart: UART peripheral used for logging (can be NULL)
 * @retval none
 */
int8_t bme280_handle_init(bme280_handle_t* bme280_handle, uint8_t address)
{
    int8_t rslt = BME280_OK;

    bme280_handle->dev.intf = BME280_I2C_INTF;
    bme280_handle->dev.read = user_i2c_read;
    bme280_handle->dev.write = user_i2c_write;
    bme280_handle->dev.delay_us = user_delay_us;
    bme280_handle->dev.addr = address;

    rslt = bme280_init(&(bme280_handle->dev));
    if (rslt != BME280_OK)
    {
        return rslt;
    }

    /* Recommended mode of operation: Indoor navigation */
    bme280_handle->dev.settings.osr_h = BME280_OVERSAMPLING_1X;
    bme280_handle->dev.settings.osr_p = BME280_OVERSAMPLING_16X;
    bme280_handle->dev.settings.osr_t = BME280_OVERSAMPLING_2X;
    bme280_handle->dev.settings.filter = BME280_FILTER_COEFF_16;

    bme280_handle->settings_sel = BME280_OSR_PRESS_SEL | BME280_OSR_TEMP_SEL | BME280_OSR_HUM_SEL | BME280_FILTER_SEL;

    rslt = bme280_set_sensor_settings(bme280_handle->settings_sel, &(bme280_handle->dev));
    if (rslt != BME280_OK)
    {
        return rslt;
    }
}

void user_delay_us(uint32_t period)
{
    sleep_us(period);
}

int8_t user_i2c_read(uint8_t reg_addr, uint8_t *data, uint32_t len, uint8_t addr)
{
    if(i2c_write_blocking(i2c_default, addr, &reg_addr, 1, false) < 0) return -1;
    if(i2c_read_blocking(i2c_default, addr , data, len, false) < 0) return -1;

    return 0;
}

int8_t user_i2c_write(uint8_t reg_addr, const uint8_t *data, uint32_t len, uint8_t addr)
{
    int8_t *buf;
    buf = malloc(len +1);
    buf[0] = reg_addr;
    memcpy(buf +1, data, len);

    if(i2c_write_blocking(i2c_default, addr, (uint8_t*)buf, len + 1, false) < 0) return -1;

    free(buf);
    return 0;
}

int8_t bme280_api_get_data(bme280_handle_t* bme280_handle)
{
    int8_t rslt;
    uint8_t settings_sel;
    struct bme280_data comp_data;

    rslt = bme280_set_sensor_mode(BME280_FORCED_MODE, &(bme280_handle->dev));
    if (rslt != BME280_OK)
    {
        fprintf(stderr, "Failed to set sensor mode (code %+d).", rslt);
        return -1;
    }

    /* Wait for the measurement to complete and print data @25Hz */
    bme280_handle->dev.delay_us(40000);
    rslt = bme280_get_sensor_data(BME280_ALL, &(bme280_handle->comp_data), &(bme280_handle->dev));
    if (rslt != BME280_OK)
    {
        return -1;
    }

    return rslt;
}

void bme280_api_print_data(bme280_handle_t* bme280_handle)
{
    float temp, press, hum;

#ifdef BME280_FLOAT_ENABLE
    temp = bme280_handle->comp_data.temperature;
    press = 0.01 * bme280_handle->comp_data.pressure;
    hum = bme280_handle->comp_data.humidity;
#endif
    printf("%0.2lf deg C, %0.2lf hPa, %0.2lf%%\n", temp, press, hum);
}