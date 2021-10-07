/*
 * bme280_api.h
 *
 *  Created on: Oct 01, 2021
 *      Author: Javier Morales
 */

#ifndef BME280_API_H_
#define BME280_API_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bme280.h"

/* Modify depending on the MCU used */
#include "pico/stdlib.h"
#include "hardware/i2c.h"


typedef struct bme280_handle_t
{
    struct bme280_dev dev;
    struct identifier* id;
    struct bme280_data comp_data;
    uint8_t settings_sel;
} bme280_handle_t;

bme280_handle_t* bme280_handle_new(uint8_t address);
int8_t bme280_handle_init(bme280_handle_t* bme280_handle, uint8_t address);

int8_t user_i2c_read(uint8_t reg_addr, uint8_t *data, uint32_t len, uint8_t addr);
int8_t user_i2c_write(uint8_t reg_addr, const uint8_t *data, uint32_t len, uint8_t addr);
void user_delay_us(uint32_t period);

void bme280_api_print_data(bme280_handle_t* bme280_handle);
int8_t bme280_api_get_data(bme280_handle_t* bme280_handle);

#endif /* BME280_API_H_ */