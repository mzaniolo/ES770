
//* ***************************************************************** */
/* File name:        pid.H                                    		*/
/* File description: Contain functions used for PID control of      */
/*                   system parts								     */
/* Author name:      Lucas_C e Matheus_Z                            */
/* Creation date:    19/11/2016                                     */
/* ***************************************************************** */
#ifndef SOURCES_PID_H_
#define SOURCES_PID_H_
/* ************************************************ */
/* Method name:        pid_setRef                  */
/* Method description: Set Reference for the PID   */
/*						controller                 */
/* Input params:       float ref                   */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_setRef(float ref);
/* ************************************************ */
/* Method name:        pid_setGanho                 */
/* Method description: Set gains of the PID controller*/
/* Input params:       float kp, float ki, float kd,*/
/*					   int iMotor					*/
/* Output params:      n/a                          */
/* ************************************************ */
void pid_setGanho (float kp, float ki, float kd, int iMotor);

/* ************************************************ */
/* Method name:        pid_rodarPID                 */
/* Method description: Initialize the PID controller*/
/*						and execute it for chosen   */
/*						motor						*/
/* Input params:       int iMotor                   */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_rodarPID(int iMotor);

/* ************************************************ */
/* Method name:        pid_setDt                   */
/* Method description: Set Derivative Time for the */
/*						PID controller             */
/* Input params:       float ref                   */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_setDt(float Dt);


#endif /* SOURCES_PID_H_ */
