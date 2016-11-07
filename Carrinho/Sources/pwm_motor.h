/*
 * pwm_motor.h
 *
 *  Created on: 11/10/2016
 *      Author: ES670A
 */

#ifndef SOURCES_PWM_MOTOR_H_
#define SOURCES_PWM_MOTOR_H_

void timer_initTPMx_AsPWM_Motor(int iMotorPercent);

void motor_change_percentage(int iPercent, int iMotorNum);



#endif /* SOURCES_PWM_MOTOR_H_ */
