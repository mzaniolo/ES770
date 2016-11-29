/* ***************************************************************** */
/* File name:         pwm_mtotor.h                                  */
/* File description: Contain functions for activation and changing  */
/*                   velocity of motors  		           */
/* Author name:      Lucas_C e Matheus_Z                            */
/* Creation date:    25/10/2016                                     */
/* ***************************************************************** */

#ifndef SOURCES_PWM_MOTOR_H_
#define SOURCES_PWM_MOTOR_H_

/* **************************************************  */
/* Method name: 	   motor_initTPM1AsPWM             */
/* Method description:  configure Timer1 to act as PWM */
/*			                and initialize motor with  */
/*			                desired velocity           */
/* Input params:	      int iMotorPercent            */
/* Outpu params:	        n/a 			           */
/* **************************************************  */
void motor_initTPMx_AsPWM_Motor(int iMotorPercent);

/* ************************************************** */
/* Method name: 	  motor_change_percentage         */
/* Method description:   change PWM % sent to specific*/
/*			                  motor			          */
/* Input params:	  int iPercent, int iMotorNum     */
/* Outpu params:	   n/a 			                  */
/* ************************************************** */
void motor_change_percentage(int iPercent, int iMotorNum);




#endif /* SOURCES_PWM_MOTOR_H_ */
