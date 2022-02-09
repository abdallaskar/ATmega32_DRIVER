/*
 * LED_program.c
 *
 *  Created on: Oct 31, 2021
 *      Author: Abdalla
 */
#include "../LIB/STD_TYPE.h"
#include "../DIO/DIO_interface.h"
#include <util/delay.h>

void LED_init(){
	DIO_SetPortDirection(DIO_PORTA,0xff);
}

void LED_display(s8 Pin_number){
	DIO_SetPinValue(DIO_PORTA,Pin_number,HIGH);
}
void LED_off(s8 Pin_number){
	DIO_SetPinValue(DIO_PORTA,Pin_number,LOW);
}

