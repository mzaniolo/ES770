
 //* ***************************************************************** */
/* File name:        sensor_hal.h                                  */
/* File description: Contain functions for activation and reading    */
/*                   of the system line sensors	          			 */
/* Author name:      Lucas_C e Matheus_Z                             */
/* Creation date:    4/10/2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_SENSOR_HAL_H_
#define SOURCES_SENSOR_HAL_H_
/* ************************************************ */
/* Method name:        sensor_initSensor	        */
/* Method description: Initialize Sensors on the    */
/*						board						*/
/* Input params:       n/a			                */
/* Output params:      n/a						    */
/* ************************************************ */
void sensor_initSensor(void);

/* ************************************************ */
/* Method name:        sensor_setEmissor            */
/* Method description: Sets the desired emitter     */
/* Input params:       int iE                       */
/* Output params:      n/a                          */
/* ************************************************ */
void sensor_setEmissor(int iE);

/* ************************************************ */
/* Method name:        sensor_clearEmissor          */
/* Method description: Clears the desired emitter  */
/* Input params:       int iE                       */
/* Output params:      n/a                          */
/* ************************************************ */
void sensor_clearEmissor(int iE);

/* ************************************************ */
/* Method name:        sensor_getValue		        */
/* Method description: Gets the data normalized in  */
/*						ADC	specific Channel for 	*/
/*						calibration					*/
/* Input params:       iChannel		                */
/* Output params:      int value for the sensor     */
/* ************************************************ */
float sensor_getValue(int iChannel);

/* ************************************************ */
/* Method name:        sensor_calibracao	        */
/* Method description: Gets the data for sensor     */
/*						calibration					*/
/* Input params:       n/a			                */
/* Output params:      n/a						    */
/* ************************************************ */
void sensor_calibracao (void);

/* ************************************************ */
/* Method name:        sensor_getRawData	        */
/* Method description: Gets the data converted in   */
/*						ADC	specific Channel		*/
/* Input params:       iChannel		                */
/* Output params:      int value of ADC0_RA         */
/* ************************************************ */
int sensor_getRawData(int iChannel);


#endif /* SOURCES_SENSOR_HAL_H_ */
