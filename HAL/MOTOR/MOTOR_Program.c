/*
 * program.c
 *
 *  Created on: Dec 4, 2021
 *      Author: Abdalla
 */
#include "../DIO/DIO_interface.h"
#include "MOTOR_Interface.h"



void MOTOR_Inti(void){
	DIO_SetPinDirection(MOTOR_PORT,MOTOR_PIN0,1);
	DIO_SetPinDirection(MOTOR_PORT,MOTOR_PIN1,1);
}
void MOTOR_Stop(void){
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN0,0);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN1,0);
}
void MOTOR_TurnRight(void){
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN0,1);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN1,0);
}
void MOTOR_TurnLeft(void){
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN0,0);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN1,1);
}
