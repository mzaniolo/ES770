/*
 * sensor_hal.c
 *
 *  Created on: 04/10/2016
 *      Author: ES670A
 */

#include "sensor_hal.h"
#include "es670_peripheral_board.h"
#include "pwm_motor.h"
#include "util.h"

static float fMax[6], fMin[6], fBackground[6];



void sensor_clearEmissor(int E)
{

	switch (E){
		case 1:
			GPIOA_PSOR |= GPIO_PSOR_PTSO( (0x01U << E1_PIN) );
			break;
		case 2:
			GPIOD_PSOR |= GPIO_PSOR_PTSO( (0x01U << E2_PIN) );
			break;
		case 3:
			GPIOD_PSOR |= GPIO_PSOR_PTSO( (0x01U << E3_PIN) );
			break;
		case 4:
			GPIOD_PSOR |= GPIO_PSOR_PTSO( (0x01U << E4_PIN) );
			break;
		case 5:
			GPIOD_PSOR |= GPIO_PSOR_PTSO( (0x01U << E5_PIN) );
			break;
		case 6:
			GPIOD_PSOR |= GPIO_PSOR_PTSO( (0x01U << E6_PIN) );
			break;
		default:
			GPIOA_PSOR |= GPIO_PSOR_PTSO( (0x01U << E1_PIN) );
			GPIOD_PSOR |= GPIO_PSOR_PTSO( (0x01U << E2_PIN) );
			GPIOD_PSOR |= GPIO_PSOR_PTSO( (0x01U << E3_PIN) );
			GPIOD_PSOR |= GPIO_PSOR_PTSO( (0x01U << E4_PIN) );
			GPIOD_PSOR |= GPIO_PSOR_PTSO( (0x01U << E5_PIN) );
			GPIOD_PSOR |= GPIO_PSOR_PTSO( (0x01U << E6_PIN) );
	}


}


void sensor_setEmissor(int E)
{
	switch (E){
	case 1:
		GPIOA_PCOR |= GPIO_PCOR_PTCO( (0x01U << E1_PIN) );
		break;
	case 2:
		GPIOD_PCOR |= GPIO_PCOR_PTCO( (0x01U << E2_PIN) );
		break;
	case 3:
		GPIOD_PCOR |= GPIO_PCOR_PTCO( (0x01U << E3_PIN) );
		break;
	case 4:
		GPIOD_PCOR |= GPIO_PCOR_PTCO( (0x01U << E4_PIN) );
		break;
	case 5:
		GPIOD_PCOR |= GPIO_PCOR_PTCO( (0x01U << E5_PIN) );
		break;
	case 6:
		GPIOD_PCOR |= GPIO_PCOR_PTCO( (0x01U << E6_PIN) );
		break;
	default:
		GPIOA_PCOR |= GPIO_PCOR_PTCO( (0x01U << E1_PIN) );
		GPIOD_PCOR |= GPIO_PCOR_PTCO( (0x01U << E2_PIN) );
		GPIOD_PCOR |= GPIO_PCOR_PTCO( (0x01U << E3_PIN) );
		GPIOD_PCOR |= GPIO_PCOR_PTCO( (0x01U << E4_PIN) );
		GPIOD_PCOR |= GPIO_PCOR_PTCO( (0x01U << E5_PIN) );
		GPIOD_PCOR |= GPIO_PCOR_PTCO( (0x01U << E6_PIN) );
	}

}


void sensor_initConvertion(int Channel){
	ADC0_SC1A &= (ADC_SC1_ADCH(Channel) | ADC_SC1_DIFF(0) | ADC_SC1_AIEN(0));

    /*
    ADC_SC1_COCO(x) // conversion complete flag HW-set
    ADC_SC1_AIEN(x) // conversion complete interrupt disables
	ADC_SC1_DIFF(x) // selects single-ended convertion
	ADC_SC1_ADCH(x) // selects channel
	*/
}

int sensor_isAdcDone(void){
	if(ADC0_SC1A >> 7) // watch complete convertion flag
	{
		return 0; // if the conversion is complete, return 1
	}
	else
		return 1; // if the conversion is still taking place, return 0

}

int sensor_getRawData(int Channel){
	sensor_initConvertion(Channel);
	while(sensor_isAdcDone()){}
    return ADC0_RA; // return the register value that keeps the result of convertion
}



float sensor_getValue(int Channel){
	float valor;
		valor = sensor_getRawData(Channel) - fBackground[Channel-1];
		return (valor - fMin[Channel-1])/(fMax[Channel-1] - fMin[Channel-1])*100;
}



void sensor_calibracao (){

	sensor_clearEmissor(-1);
	for(int i = 0;i<6;i++){
		fBackground[i] = sensor_getRawData(i+1);
	}


	float valor[6], valor2[6];

	motor_change_percentage(40, 1);
	motor_change_percentage(0, 2);

	for (int k = 0; k<300; k++){
		util_genDelay10ms();
		for (int i = 0; i < 6; i++){
			sensor_setEmissor(i+1);
			valor[i] = sensor_getRawData(i+1) - fBackground[i];
			sensor_clearEmissor(i+1);
			if(k == 0){
				fMax[i] = valor[i];
				fMin[i] = valor[i];
			}
			if(valor[i]>fMax[i]){
				fMax[i] = valor[i];
			} else if (valor[i] < fMin[i]){
				fMin[i] = valor[i];
			}
		}

	}

	motor_change_percentage(0, 2);
	motor_change_percentage(40, 1);

	for (int k = 0; k<300; k++){
		util_genDelay10ms();
//		for (int i = 0; i < 6; i++){
//			sensor_setEmissor(i+1);
//			valor[i] = sensor_getRawData(i+1) - fBackground[i];
//			sensor_clearEmissor(i+1);
//			if(k == 0){
//				fMax[i] = valor[i];
//				fMin[i] = valor[i];
//			}
//			if(valor[i]>fMax[i]){
//				fMax[i] = valor[i];
//			} else if (valor[i] < fMin[i]){
//				fMin[i] = valor[i];
//			}
//		}

	}


	motor_change_percentage(0, 1);
	motor_change_percentage(40, 2);

	for (int k = 0; k<300; k++){
		util_genDelay10ms();
		for (int i = 0; i < 6; i++){
			sensor_setEmissor(i+1);
			valor2[i] = sensor_getRawData(i+1) - fBackground[i];
			sensor_clearEmissor(i+1);
//			if(valor2[i]>fMax[i]){
//				fMax[i] = valor2[i];
//			} else if (valor[i] < fMin[i]){
//				fMin[i] = valor2[i];
//			}
		}
	}
	for (int i = 0; i < 6; i++){
		if(valor2[i]>fMax[i]){
			fMax[i] = valor2[i];
		} else if (valor[i] < fMin[i]){
			fMin[i] = valor2[i];
		}
	}

	motor_change_percentage(0, 1);
	motor_change_percentage(0, 2);

}

void sensor_initSensor()
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);
    SIM_SCGC5 |= SIM_SCGC5_PORTD(CGC_CLOCK_ENABLED);
    SIM_SCGC5 |= SIM_SCGC5_PORTC(CGC_CLOCK_ENABLED);
    SIM_SCGC5 |= SIM_SCGC5_PORTB(CGC_CLOCK_ENABLED);
    SIM_SCGC6 |= SIM_SCGC6_ADC0(CGC_CLOCK_ENABLED);	//Enable clock for ADC


    PORTA_PCR13 = PORT_PCR_MUX(E1_ALT);
    PORTD_PCR5 = PORT_PCR_MUX(E2_ALT);
    PORTD_PCR0 = PORT_PCR_MUX(E3_ALT);
    PORTD_PCR2 = PORT_PCR_MUX(E4_ALT);
    PORTD_PCR3 = PORT_PCR_MUX(E5_ALT);
    PORTD_PCR1 = PORT_PCR_MUX(E6_ALT);

    PORTC_PCR1 = PORT_PCR_MUX(R1_ALT);
	PORTC_PCR2 = PORT_PCR_MUX(R2_ALT);
	PORTB_PCR0 = PORT_PCR_MUX(R3_ALT);
	PORTB_PCR1 = PORT_PCR_MUX(R4_ALT);
	PORTB_PCR2 = PORT_PCR_MUX(R5_ALT);
	PORTB_PCR3 = PORT_PCR_MUX(R6_ALT);


    GPIOA_PDDR |= GPIO_PDDR_PDD(E1_OUTPUT);
    GPIOD_PDDR |= GPIO_PDDR_PDD(E2_OUTPUT | E3_OUTPUT | E4_OUTPUT | E5_OUTPUT | E6_OUTPUT);

    ADC0_CFG1 |= (ADC_CFG1_ADICLK(ADC_ADICLK) | ADC_CFG1_MODE(ADC_ADCMODE) | ADC_CFG1_ADLSMP(ADC_ADLSMP) | ADC_CFG1_ADIV(ADC_ADIV) | ADC_CFG1_ADLPC(ADC_ADLPC));
	ADC0_SC2 |= (ADC_SC2_REFSEL(ADC_REFSEL) | ADC_SC2_DMAEN(ADC_DMAEN) | ADC_SC2_ACFE(ADC_ACFE) | ADC_SC2_ADTRG(ADC_ADTRG));
	ADC0_CFG2 |= (ADC_CFG2_ADLSTS(ADC_ADLSTS) | ADC_CFG2_ADHSC(ADC_ADHSC) | ADC_CFG2_ADACKEN(ADC_ADACKEN) | ADC_CFG2_MUXSEL(ADC_MUXSEL));

	for(int i = 1;i<7;i++){
		sensor_clearEmissor(i);
	}

	sensor_calibracao();

}

/*int *sensor_Test(){
	int ref[6]={0,0,0,0,0,0},sensores[6] = {R1_CH,R2_CH,R3_CH,R4_CH,R5_CH,R6_CH}, ok[6] = {0,0,0,0,0,0};
	int v = 0;
	float fator=2;

	for(int i = 0;i<6;i++){
		ref[i] = sensor_getValue(sensores[i]);
	}
	for(int i = 0;i<6;i++){
		sensor_setEmissor(i+1);
		v = sensor_getValue(sensores[i]);
		sensor_clearEmissor(i+1);
		if(v>fator*ref[i]){
			ok[i] = 1;
		}
	}
return &ok;
}*/
