/*
 * Serial.h
 *
 *  Created on: 18/10/2016
 *      Author: root
 */

#ifndef SOURCES_INTERFACE_SERIAL_H_
#define SOURCES_INTERFACE_SERIAL_H_


#define BUFF_SIZE	256U

/* ***************************************************/
/* Method name:        setConfig                     */
/* Method description:  This method initialize the   */
/* 						communication           	 */
/* Input params:       n/a                           */
/* Output params:       n/a                          */
/* ***************************************************/
void setConfig(void);

/* ********************************************************/
/* Method name:        sendBuffer                         */
/* Method description:  This method sends a string through*/
/* 						the serial port	                  */
/* Input params:       *cmd = vector to be written        */
/* Output params:       n/a                               */
/* ********************************************************/
void sendBuffer(char *str);


char readBuffer(char *cmd);



#endif /* SOURCES_INTERFACE_SERIAL_H_ */