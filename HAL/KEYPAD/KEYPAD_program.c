/*
 * KEY_PAD_program.c
 *
 *  Created on: Aug 30, 2021
 *      Author: abdalla
 */
#include "../DIO/DIO_interface.h"
#include <util/delay.h>


void KEYPPAD_Init(void){

	DIO_SetPortDirection(DIO_PORTC,0xf0);
	DIO_SetPortValue(DIO_PORTC,0xff);

}
u8 KEYPAD_GetPresedKey(void){
	u8 PresedKey=0;

	for (int c = 0; c < 4; ++c) {
		DIO_SetPinValue(DIO_PORTC,(c+4),0);
		for (int r = 0; r < 4; ++r) {
			if(DIO_GetPinValue(DIO_PORTC,(r))==0){
				PresedKey=((r*4)+(c+1));
			}
			while(DIO_GetPinValue(DIO_PORTC,(r))==0){}
			_delay_ms(5);

		}
		DIO_SetPinValue(DIO_PORTC,(c+4),1);
	}
	return PresedKey;

}
