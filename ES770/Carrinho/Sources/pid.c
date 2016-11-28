/*
 * PID.c
 *
 *  Created on: 19/11/2016
 *      Author: ES670A
 */

#include "pid.h"
#include "pwm_motor.h"
#include "encoder_hal.h"
#include "Serial.h"
#include <stdio.h>

#define ENC_RES 20

float fDt = 0.1;
float Saturacao = 1000;

typedef struct pids{
	float fInt, fDev, fProp, fErro, fErroAntigo;
	float Ki, Kd, Kp;
}PID;

static float fRef = 10; //Rotações por s
static PID pid1;
static PID pid2;

void pid_rodarPID(int iMotor){

	float saida;

	if (iMotor == 1){
		/* Erro */
		pid1.fErro = (fRef*ENC_RES - encoder_read(iMotor))/fDt;

		/* Termo Integral */
		pid1.fInt += pid1.Ki*pid1.fErro;
		if (pid1.fInt > Saturacao) pid1.fInt = Saturacao;

		/* Termo Derivativo */
		pid1.fDev = pid1.Kd*(pid1.fErro - pid1.fErroAntigo)/fDt;
		pid1.fErroAntigo = pid1.fErro;

		/* Termo Proporcional */
		pid1.fProp = pid1.Kp*pid1.fErro;

		/* Saida do PID */
		saida = pid1.fInt + pid1.fDev + pid1.fProp;
		if (saida > 100) saida = 100;
		else if (saida < 0) saida = 0;

		/* PID motor 2 */
	} else if (iMotor == 2){
		/* Erro */
		pid2.fErro = (fRef*ENC_RES - encoder_read(iMotor))/fDt;

		/* Termo Integral */
		pid2.fInt += pid2.Ki*pid2.fErro;
		if (pid2.fInt > Saturacao) pid2.fInt = Saturacao;

		/* Termo Derivativo */
		pid2.fDev = pid2.Kd*(pid2.fErro - pid2.fErroAntigo)/fDt;
		pid2.fErroAntigo = pid2.fErro;

		/* Termo Proporcional */
		pid2.fProp = pid2.Kp*pid2.fErro;

		/* Saida do PID */
		saida = pid2.fInt + pid2.fDev + pid2.fProp;
		if (saida > 100) saida = 100;
		else if (saida < 0) saida = 0;
	}

	/* Motor */
	motor_change_percentage(saida, iMotor);

	char str[20];
	sprintf(str,"%f\n\r", saida);
	sendBuffer(str);
}


void pid_setGanho (float kp, float ki, float kd, int iMotor){
	if (iMotor == 1){
		pid1.Ki = ki;
		pid1.Kd = kd;
		pid1.Kp = kp;
	} else if (iMotor == 2){
		pid2.Ki = ki;
		pid2.Kd = kd;
		pid2.Kp = kp;
	}
}

void pid_setRef(float ref){
	fRef = ref;
}

void pid_setDt(float Dt){
	fDt = Dt;
}
