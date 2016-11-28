/*
 * encoder_hal.c
 *
 *  Created on: 25/10/2016
 *      Author: ES670A
 */

#include "es670_peripheral_board.h"
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"
#include "encoder_hal.h"


/* ************************************************ */
/* Method name:        tachometer_init              */
/* Method description: Initialize the tachometer    */
/* 					   device						*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void encoder_init(void)
{
	/* Init Encoder pin */
		SIM_SCGC5 |= SIM_SCGC5_PORTC(1);
		PORTC_PCR12 = PORT_PCR_MUX(ENC1_ALT);
		PORTC_PCR13 = PORT_PCR_MUX(ENC2_ALT);

		/* INIT TPM */

		//Init TPM Clock source as OSCERCLOCK
		SIM_SOPT2 |= SIM_SOPT2_TPMSRC(2);

		//TPM1 ClockIn0
		SIM_WR_SOPT4_TPM1CLKSEL(SIM,0);
		//Enable clock to TPM1
		SIM_SCGC6 |= SIM_SCGC6_TPM1(1);
		//Select External Clock Source for TPM module
		TPM1_SC |= TPM_SC_CMOD(2);
		//Prescale 1:1
		TPM_WR_SC_PS(TPM1,0);

		//TPM2 ClockIn1
		SIM_WR_SOPT4_TPM2CLKSEL(SIM,1);
		//Enable clock to TPM2
		SIM_SCGC6 |= SIM_SCGC6_TPM2(1);
		//Select External Clock Source for TPM module
		TPM2_SC |= TPM_SC_CMOD(2);
		//Prescale 1:1
		TPM_WR_SC_PS(TPM2,0);

		TPM1_MOD = 0b1111111111111111;
		TPM2_MOD = 0b1111111111111111;

}


int encoder_read(int iMotor){
	int temp;
	if (iMotor == 1){
		temp = TPM1_CNT;
		TPM1_CNT = 0;
	}else if (iMotor == 2){
		temp = TPM2_CNT;
		TPM2_CNT = 0;

	}
	return temp;
}



