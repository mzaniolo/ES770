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

/* system includes */
#include "fsl_debug_console.h"

/* defines */
#define CYCLIC_EXECUTIVE_PERIOD         100 * 10000 /* 1 000 000 micro seconds */

volatile unsigned int uiFlagNextPeriod = 0;         /* cyclic executive flag */
int enc_motor1=0, enc_motor2=0;

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
	sensor_initSensor();
	mcg_clockInit();
	timer_initTPMx_AsPWM_Motor(100);
	encoder_init();
	//autoteste_motor();
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
//    int* ok;
    motor_change_percentage(0, 1);
   	motor_change_percentage(50, 1);
   	motor_change_percentage(0, 2);
   	motor_change_percentage(50, 2);

   // int v;
   // int sensores[6] = {R1_CH,R2_CH,R3_CH,R4_CH,R5_CH,R6_CH}, ref[6]={0,0,0,0,0,0};
    /* cooperative cyclic executive main loop */
    while(1U)
    {
    	//ok= sensor_Test();
    	motor_change_percentage(0, 1);
    	motor_change_percentage(100, 2);

    	enc_motor1= TPM1_CNT;
    	enc_motor2= TPM2_CNT;

//    	for(int i = 0;i<6;i++){
//    		ref[i] = sensor_getValue(sensores[i]);
//    	}
//    	for(int i = 0;i<6;i++){
//    		sensor_setEmissor(i+1);
//    		v = sensor_getValue(sensores[i]);
//    		sensor_clearEmissor(i+1);
//    	}

    	/* WAIT FOR CYCLIC EXECUTIVE PERIOD */
//		while(!uiFlagNextPeriod){}
		uiFlagNextPeriod = 0;
    }
    /* Never leave main */
    return 0;
}
///////////
