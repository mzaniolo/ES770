/* ***************************************************************** */
/* File name:        main.c                                         */
/* File description: File dedicated to the ES670 prototype projects  */
/*                   involving the FRDM-KL25Z board together with is */
/*                   daughter board containing more peripherals      */
/*                                                                   */
/*                   Processor MKL25Z128VLK4 characteristics         */
/*                   48 MHz ARM Cortex-M0+ core                      */
/*                   128 KB program flash memory                     */
/*                   16 KB SRAM                                      */
/*                   Voltage range: 1.71 to 3.6 V                    */
/*                                                                   */
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    01jul2016                                       */
/* ***************************************************************** */

/* our includes */
#include "es670_peripheral_board.h"
#include "sensor_hal.h"
#include "mcg_hal.h"
#include "pwm_motor.h"
#include "encoder_hal.h"
#include "autoteste.h"
#include "pid.h"
#include "Serial.h"
/* system includes */
#include "fsl_debug_console.h"

/* defines */
#define CYCLIC_EXECUTIVE_PERIOD         100 * 1000 /* 1 000 000 micro seconds */

volatile unsigned int uiFlagNextPeriod = 0;         /* cyclic executive flag */


void main_cyclicExecuteIsr(void)
{
    /* set the cyclic executive flag */\
    uiFlagNextPeriod = 1;
}

/************************************************** */
/* Method name:        main_boardInit		        */
/* Method description: peripherals initialization   */
/*                     service routine              */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void main_boardInit(){
	mcg_clockInit();
	timer_initTPMx_AsPWM_Motor(0);
	encoder_init();
	setConfig();
	sensor_initSensor();
	autoteste_motor();
}


/* ************************************************ */
/* Method name:        main                         */
/* Method description: system entry point           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int main(void)
{
    /* board initializations */
	main_boardInit();

//	pid_setRef(5);
//	pid_setDt(CYCLIC_EXECUTIVE_PERIOD/1000000);
//
//	pid_setGanho (80, 20, 0.5, 1);
//	pid_setGanho (80, 20, 0.5, 2);


    motor_change_percentage(0, 1);
    motor_change_percentage(0, 2);
    /* cooperative cyclic executive main loop */
    while(1U)
    {

//    	pid_rodarPID(1);
//    	pid_rodarPID(2);

    	/* WAIT FOR CYCLIC EXECUTIVE PERIOD */
		while(!uiFlagNextPeriod){}
		uiFlagNextPeriod = 0;
    }
    /* Never leave main */
    return 0;
}
///////////
