/*
 * bma2x2_my.c
 *
 *  Created on: 5 Apr 2022
 *      Author: marcel
 */
#ifndef BMA2X2_MY_H_
#define BMA2X2_MY_H_
//struct bma2x2_t bma2x2;


int8_t BMA220_init(void);
uint32_t BM220_read_data(void);
void BMA2x2_delay_msek(uint32_t msek);
int8_t BMA2x2_I2C_bus_read(uint8_t dev_addr,uint8_t reg_addr,uint8_t *reg_data,uint8_t len);
int8_t BMA2x2_I2C_bus_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t len);

#endif
