/*
 * bma2x2_my.c
 *
 *  Created on: 5 Apr 2022
 *      Author: marcel
 */
#include "i2c.h"
#include"bma2x2.h"
#include "bma2x2_my.h"
#include <stdio.h>

struct bma2x2_t bma2x2;

int8_t BMA220_init(void){
	int8_t result;
	//I2C_routine();
	//bma2x2.power_mode_u8=
	bma2x2.chip_id=BMA2x2;
	//bma2x2.ctrl_mode_reg=
	//bma2x2.low_mode_reg=
	bma2x2.dev_addr=0x00;
	//bma2x2.fifo_config=
	bma2x2.bus_read=BMA2x2_I2C_bus_read;
	bma2x2.bus_write=BMA2x2_I2C_bus_write;
	bma2x2.delay_msec=BMA2x2_delay_msek;

	result=bma2x2_init(&bma2x2);
	result += bma2x2_set_power_mode(BMA2x2_MODE_NORMAL);
	result+=bma2x2_set_range(BMA2x2_RANGE_8G);



	return result;
}


uint32_t BM220_read_data(void){
	s16	accel_x_s16, accel_y_s16, accel_z_s16 = BMA2x2_INIT_VALUE;

	struct bma2x2_accel_data sample_xyz;
	bma2x2_read_accel_xyz(&sample_xyz);
	printf("X = %d Y = %d z= %d",sample_xyz.x,sample_xyz.y,sample_xyz.z);
	HAL_Delay(1000);

}

void BMA2x2_delay_msek(uint32_t msek){
	HAL_Delay(msek);
}


int8_t BMA2x2_I2C_bus_read(uint8_t dev_addr,uint8_t reg_addr,uint8_t *reg_data,uint8_t len){
	HAL_I2C_Mem_Read(&hi2c1, dev_addr, reg_addr, 1, reg_data, len, 100);
	return 0;
}

int8_t BMA2x2_I2C_bus_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t len){
	HAL_I2C_Mem_Write(&hi2c1, dev_addr, reg_addr, 1, *reg_data, len, 100);
	return 0;
}
