/* ***************************************************************** */
/* File name:       encoder.h                                       */
/* File description: Contain functions for activation and reading  */
/*                   of the system encoders		           */
/* Author name:      Lucas_C e Matheus_Z                            */
/* Creation date:    25/10/2016                                     */
/* ***************************************************************** */

#ifndef SOURCES_ENCODER_HAL_H_
#define SOURCES_ENCODER_HAL_H_
/* ************************************************ */
/* Method name:        encoder_init                 */
/* Method description: Initialize the encoder        */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void encoder_init(void);

/* ************************************************ */
/* Method name:        encoder_read                 */
/* Method description: Reads the encoder value  of  */
/*			           chosen motor		            */
/* Input params:       int iMotor                   */
/* Output params:      n/a                          */
/* ************************************************ */
int encoder_read(int iMotor);

#endif /* SOURCES_ENCODER_HAL_H_ */