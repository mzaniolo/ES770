#include "Serial.h"
#include "debugUart.h"
#include "fsl_debug_console.h"
#include "MKL25Z4_extension.h"
#include "es670_peripheral_board.h"

/* ***************************************************/
/* Method name:        setConfig                     */
/* Method description:  This method initialize the   */
/* 						communication           	 */
/* Input params:       n/a                           */
/* Output params:       n/a                          */
/* ***************************************************/
void setConfig(){
	SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);
	debugUart_init();
}

/* ********************************************************/
/* Method name:        sendBuffer                         */
/* Method description:  This method sends a string through*/
/* 						the serial port	                  */
/* Input params:       *cmd = vector to be written        */
/* Output params:       n/a                               */
/* ********************************************************/
void sendBuffer(char *str){

	for (int i = 0; i< BUFF_SIZE; i++)
	{

		if (0x0A != str[i] )
		{
			PUTCHAR(str[i]);
		} else
		{
			PUTCHAR(str[i]);
			break;
		}

	}

}

/* *****************************************************************/
/* Method name:        sendBuffer                                  */
/* Method description:  This method reads a byte through           */
/* 						the serial port	                           */
/* Input params:       *cmd = char to be written                   */
/* Output params:       1 if it reads something and 0 if otherwise */
/* *****************************************************************/
char readBuffer(char *cmd){

    if(UART0_BRD_S1_RDRF(UART0)){
    	*cmd = GETCHAR();
        return 1;
    }
    return 0;

}
