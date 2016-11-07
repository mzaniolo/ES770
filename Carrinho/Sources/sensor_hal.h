/*
 * sensor_hal.h
 *
 *  Created on: 04/10/2016
 *      Author: ES670A
 */

#ifndef SOURCES_SENSOR_HAL_H_
#define SOURCES_SENSOR_HAL_H_

void sensor_initSensor();

void sensor_setEmissor(int E);

void sensor_clearEmissor(int E);

int sensor_getValue(int Channel);

void sensor_calibracao(void);

int sensor_getRawData(int Channel);

//int *sensor_Test();

#endif /* SOURCES_SENSOR_HAL_H_ */
