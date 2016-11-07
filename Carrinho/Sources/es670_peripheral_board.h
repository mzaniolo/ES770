/* ***************************************************************** */
/* File name:        es670_peripheral_board.h                        */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_ES670_PERIPHERAL_BOARD_H_
#define SOURCES_ES670_PERIPHERAL_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/* GPIO input / output */
#define GPIO_INPUT                  0x00U
#define GPIO_OUTPUT                 0x01U


/*                 END OF General uC definitions         */



/*                 Emissor Definitions                    */
#define E_PORT_BASE_PNT1            PORTA                                   /* peripheral port base pointer */
#define E_GPIO_BASE_PNT1            PTA                                     /* peripheral gpio base pointer */
#define E_PORT_BASE_PNT2            PORTD                                   /* peripheral port base pointer */
#define E_GPIO_BASE_PNT2            PTD                                     /* peripheral gpio base pointer */

/*                            Sensor na porta A                    */
#define E1_PIN                     13U                                      /* led/switch #1 pin */
#define E1_OUTPUT              (GPIO_OUTPUT << E1_PIN)
#define E1_ALT                     0x01u                                   /* GPIO alternative */

/*                          Sensores na porta D                           */
#define E2_PIN                     5U                                      /* led/switch #2 pin */
#define E2_OUTPUT              (GPIO_OUTPUT << E2_PIN)
#define E2_ALT                     E1_ALT

#define E3_PIN                     0U                                      /* led/switch #3 pin */
#define E3_OUTPUT              (GPIO_OUTPUT << E3_PIN)
#define E3_ALT                     E1_ALT

#define E4_PIN                     2U                                      /* led/switch #4 pin */
#define E4_OUTPUT              (GPIO_OUTPUT << E4_PIN)
#define E4_ALT                     E1_ALT

#define E5_PIN                     3U                                      /* led/switch #4 pin */
#define E5_OUTPUT              (GPIO_OUTPUT << E5_PIN)
#define E5_ALT                     E1_ALT

#define E6_PIN                     1U                                      /* led/switch #4 pin */
#define E6_OUTPUT              (GPIO_OUTPUT << E6_PIN)
#define E6_ALT                     E1_ALT

/*                 END OF Emissor definitions             */

/*                 	Receptor Definitions                    */
#define R_PORT_BASE_PNT1            PORTC                                   /* peripheral port base pointer */
#define R_GPIO_BASE_PNT1            PTC                                     /* peripheral gpio base pointer */
#define R_PORT_BASE_PNT2            PORTB                                   /* peripheral port base pointer */
#define R_GPIO_BASE_PNT2            PTB                                     /* peripheral gpio base pointer */

/*                            Sensor na porta A                    */
#define R1_PIN                     13U                                      /* led/switch #1 pin */
#define R1_OUTPUT              (GPIO_OUTPUT << R1_PIN)
#define R1_ALT                     0x01u                                   /* GPIO alternative */
#define R1_CH						0b01000

/*                          Sensores na porta D                           */
#define R2_PIN                     5U                                      /* led/switch #2 pin */
#define R2_OUTPUT              (GPIO_OUTPUT << R2_PIN)
#define R2_ALT                     R1_ALT
#define R2_CH						0b01001

#define R3_PIN                     0U                                      /* led/switch #3 pin */
#define R3_OUTPUT              (GPIO_OUTPUT << R3_PIN)
#define R3_ALT                     R1_ALT
#define R3_CH						0b01100

#define R4_PIN                     2U                                      /* led/switch #4 pin */
#define R4_OUTPUT              (GPIO_OUTPUT << R4_PIN)
#define R4_ALT                     R1_ALT
#define R4_CH						0b01101

#define R5_PIN                     3U                                      /* led/switch #4 pin */
#define R5_OUTPUT              (GPIO_OUTPUT << R5_PIN)
#define R5_ALT                     R1_ALT
#define R5_CH						0b01111

#define R6_PIN                     1U                                      /* led/switch #4 pin */
#define R6_OUTPUT              (GPIO_OUTPUT << R6_PIN)
#define R6_ALT                     R1_ALT
#define R6_CH						0b01011

/*                 END OF Receptor definitions             */

/*                    ADC Definitions              */
#define ADC_ADICLK 			1U
#define ADC_ADCMODE 		3U
#define ADC_ADLSMP			0U
#define ADC_ADIV  			0U
#define ADC_ADLPC			0U
#define ADC_REFSEL			0U
#define ADC_DMAEN			0U
#define ADC_ACFE			0U
#define ADC_ADTRG			0U
#define ADC_ADLSTS			0U
#define ADC_ADHSC           0U
#define ADC_ADACKEN			0U
#define ADC_MUXSEL			0U

/*                 END OF ADC definitions             */

/*                Motors Definitions                    */
#define M_PORT_BASE_PNT1         PORTA                                   /* peripheral port base pointer */
#define M_GPIO_BASE_PNT1         PTA                                     /* peripheral gpio base pointer */
#define M_PORT_BASE_PNT2         PORTE                                   /* peripheral port base pointer */
#define M_GPIO_BASE_PNT2         PTE                                     /* peripheral gpio base pointer */

#define M1_PIN                  4U                                      /* motor1 pin */
#define M1_DIR              	kGpioDigitalOutput
#define M1_DIR_OUTPUT       	(GPIO_OUTPUT << M1_PIN)
#define M1_ALT              	3U

#define M2_PIN                  29U                                      /* motor2 pin */
#define M2_DIR              	kGpioDigitalOutput
#define M2_DIR_OUTPUT       	(GPIO_OUTPUT << M2_PIN)
#define M2_ALT              	3U
/*                 END OF Motors definitions             */




/*               Encoders Definitions                    */

#define ENC_PORT_BASE_PNT1        PORTC                                   /* peripheral port base pointer */
#define ENC_GPIO_BASE_PNT1        PTC                                     /* peripheral gpio base pointer */

#define ENC1_PIN                12U                                      /* Encoder 1 pin */
#define ENC1_DIR              	kGpioDigitalOutput
#define ENC1_DIR_OUTPUT       	(GPIO_OUTPUT << ENC1_PIN)
#define	ENC1_ALT              	4U

#define ENC2_PIN                13U                                      /* Encoder 2 pin */
#define ENC2_DIR              	kGpioDigitalOutput
#define ENC2_DIR_OUTPUT       	(GPIO_OUTPUT << ENC2_PIN)
#define ENC2_ALT              	4U
/*                 END OF Encoders definitions             */



#endif /* SOURCES_ES670_PERIPHERAL_BOARD_H_*/

