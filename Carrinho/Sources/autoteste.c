/*
 * autoteste.c
 *
 *  Created on: 05/11/2016
 *      Author: ES670A
 */

#include "es670_peripheral_board.h"
#include "sensor_hal.h"
#include "mcg_hal.h"
#include "pwm_motor.h"
#include "encoder_hal.h"
#include "autoteste.h"
#include "util.h"

/* system includes */
#include "fsl_debug_console.h"

void autoteste_leds(void){
	SIM_SCGC5 |= SIM_SCGC5_PORTC(CGC_CLOCK_ENABLED);
	SIM_SCGC5 |= SIM_SCGC5_PORTD(CGC_CLOCK_ENABLED);

	PORTC_PCR9 = PORT_PCR_MUX(1);
	PORTD_PCR7 = PORT_PCR_MUX(1);
}

void autoteste_motor(void){
	autoteste_leds();

	motor_change_percentage(100, 1);
	motor_change_percentage(0,2);
	util_genDelay1s();
	util_genDelay1s();
	if (TPM1_CNT != 0 && TPM2_CNT == 0){ //motor1 works?
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << 9));
	}

	motor_change_percentage(100, 2);
	motor_change_percentage(0,1);
	util_genDelay1s();
	util_genDelay1s();
	if (TPM2_CNT!=0 && TPM1_CNT==0){ //motor2 works?
		GPIOD_PCOR = GPIO_PCOR_PTCO( (0x01U << 7));
	}
	motor_change_percentage(0,2);
}
