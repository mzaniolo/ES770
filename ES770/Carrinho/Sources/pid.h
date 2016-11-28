/*
 * pid.h
 *
 *  Created on: 19/11/2016
 *      Author: ES670A
 */

#ifndef SOURCES_PID_H_
#define SOURCES_PID_H_

void pid_setRef(float ref);

void pid_setGanho (float kp, float ki, float kd, int iMotor);

void pid_rodarPID(int iMotor);

void pid_setDt(float Dt);


#endif /* SOURCES_PID_H_ */
