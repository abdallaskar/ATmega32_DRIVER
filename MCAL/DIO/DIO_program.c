/*
 * DIO_Program.c
 *
 *  Created on: Oct 30, 2021
 *      Author: Abdalla
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "../DIO/DIO_private.h"


void DIO_SetPinDirection(u8 port, u8 pin, u8 direction) {
	if (direction == 1) {
		switch (port) {
		case 0:
			SET_BIT(DDRA, pin);
			break;
		case 1:
			SET_BIT(DDRB, pin);
			break;
		case 2:
			SET_BIT(DDRC, pin);
			break;
		case 3:
			SET_BIT(DDRD, pin);
			break;
		}
	} else {
		switch (port) {
		case 0:
			CLEAR_BIT(DDRA, pin);
			break;
		case 1:
			CLEAR_BIT(DDRB, pin);
			break;
		case 2:
			CLEAR_BIT(DDRC, pin);
			break;
		case 3:
			CLEAR_BIT(DDRD, pin);
			break;
		}
	}
}

void DIO_SetPortDirection(u8 port, u8 direction) {

	switch (port) {
	case 0:
		DDRA = direction;
		break;
	case 1:
		DDRB = direction;
		break;
	case 2:
		DDRC = direction;
		break;
	case 3:
		DDRD = direction;
		break;
	}
}

void DIO_SetPinValue(u8 port, u8 pin, u8 value) {
	if (value == 1) {
		switch (port) {
		case 0:
			SET_BIT(PORTA, pin);
			break;
		case 1:
			SET_BIT(PORTB, pin);
			break;
		case 2:
			SET_BIT(PORTC, pin);
			break;
		case 3:
			SET_BIT(PORTD, pin);
			break;
		}
	} else {
		switch (port) {
		case 0:
			CLEAR_BIT(PORTA, pin);
			break;
		case 1:
			CLEAR_BIT(PORTB, pin);
			break;
		case 2:
			CLEAR_BIT(PORTC, pin);
			break;
		case 3:
			CLEAR_BIT(PORTD, pin);
			break;
		}
	}
}

void DIO_SetPortValue(u8 port, u8 value) {
	switch (port) {
	case 0:
		PORTA = value;
		break;
	case 1:
		PORTB = value;
		break;
	case 2:
		PORTC = value;
		break;
	case 3:
		PORTD = value;
		break;
	}
}
void DIO_TogglePin(u8 port, u8 pin) {
	switch (port) {
	case 0:{
		TOGGLE_BIT(PORTA, pin);
	}
		break;
	case 1:
		TOGGLE_BIT(PORTB, pin);
		break;
	case 2:
		TOGGLE_BIT(PORTC, pin);
		break;
	case 3:
		TOGGLE_BIT(PORTD, pin);
		break;
	}

}
u8 DIO_GetPinValue(u8 port, u8 pin) {
	u8 return_value1 = 0;
	switch (port) {
	case 0:
		return_value1 = GET_BIT(PINA, pin);
		break;
	case 1:
		return_value1 = GET_BIT(PINB, pin);
		break;
	case 2:
		return_value1 = GET_BIT(PINC, pin);
		break;
	case 3:
		return_value1 = GET_BIT(PIND, pin);
		break;
	}
	return return_value1;
}

u8 DIO_GitPortValue(u8 port) {
	u8 return_value = 0;
	switch (port) {
	case 0:
		return_value = PINA;
		break;
	case 1:
		return_value = PINB;
		break;
	case 2:
		return_value = PINC;
		break;
	case 3:
		return_value = PIND;
		break;
	}
	return return_value;
}
