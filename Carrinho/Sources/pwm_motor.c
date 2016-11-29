/* ***************************************************************** */
/* File name:         pwm_mtotor.c                                  */
/* File description: Contain functions for activation and changing  */
/*                   velocity of motors  		           */
/* Author name:      Lucas_C e Matheus_Z                            */
/* Creation date:    11/10/2016                                     */
/* ***************************************************************** */
#include "es670_peripheral_board.h"
#include "pwm_motor.h"

#include "fsl_tpm_hal.h"


/* ************************************************** */
/* Method name: 	   motor_initTPM1AsPWM        */
/* Method description:  configure Timer1 to act as PWM */
/*			and initialize motor with     */
/*			desired velocity              */
/* Input params:	   int iMotorPercent          */
/* Outpu params:	   n/a 			      */
/* ************************************************** */
void motor_initTPMx_AsPWM_Motor(int iMotorPercent) {
	/* un-gate port clock*/
		SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);
		SIM_SCGC5 |= SIM_SCGC5_PORTE(CGC_CLOCK_ENABLED);
		/* set pin as gpio */
		PORTA_PCR4 = PORT_PCR_MUX(M1_ALT);
		PORTE_PCR29 = PORT_PCR_MUX(M2_ALT);


	/* un-gate port clock*/
		SIM_SCGC6 |= SIM_SCGC6_TPM0(1); //Enable clock for TPM0

		SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);

		TPM0_SC |= TPM_SC_CPWMS(0);   //up counting mode
		TPM0_SC |= TPM_SC_PS(0);   //Prescale 1:1

		//TPM0 Channel 1
		TPM0_C1SC |= (TPM_CnSC_MSB(0b1) | TPM_CnSC_MSA(0b0) | TPM_CnSC_ELSB(0b1) | TPM_CnSC_ELSA(0b0));
		while(!(TPM0_C1SC&(TPM_CnSC_MSB(0b1) | TPM_CnSC_ELSB(0b1) )));

		//TPM0 Channel 2
		TPM0_C2SC |= (TPM_CnSC_MSB(0b1) | TPM_CnSC_MSA(0b0) | TPM_CnSC_ELSB(0b1) | TPM_CnSC_ELSA(0b0));
		while(!(TPM0_C2SC&(TPM_CnSC_MSB(0b1) | TPM_CnSC_ELSB(0b1) )));


		TPM0_C1V = iMotorPercent*50; //PWM %

		TPM0_C2V = iMotorPercent*50; //PWM %

		TPM0_SC |= TPM_SC_CMOD(1);   //LPTPM Counter increments on every LPTPM counter clock
		TPM0_MOD = 5000; //chosen module

}

/* ************************************************** */
/* Method name: 	  motor_change_percentage     */
/* Method description:   change PWM % sent to specific*/
/*			motor			      */
/* Input params:	  int iPercent, int iMotorNum */
/* Outpu params:	   n/a 			      */
/* ************************************************** */
void motor_change_percentage(int iPercent, int iMotorNum) {
	
	if (iMotorNum == 1) {//motor right
		TPM0_C1V = iPercent*50; //PWM %
	}
	else if (iMotorNum == 2) {//motor left
		TPM0_C2V = iPercent*50; //PWM %
	}
}






