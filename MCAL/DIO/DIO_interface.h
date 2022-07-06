/*
 * DIO_interface.h
 *
 *  Created on: Oct 30, 2021
 *      Author: Abdalla
 */

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_


/* Define number of port */

	#define  DIO_PORTA   0
	#define  DIO_PORTB   1
	#define  DIO_PORTC   2
	#define  DIO_PORTD   3

/* define number of pins */

	#define   PIN0  0
	#define   PIN1  1
	#define   PIN2  2
	#define   PIN3  3
	#define   PIN4  4
	#define   PIN5  5
	#define   PIN6  6
	#define   PIN7  7

/* Define direction value */
	#define  OUTPUT  1
	#define  INPUT   0

/* Define pin value */
	#define  HIGH  1
	#define  LOW   0

/* Prototype of function */

	void DIO_SetPinDirection(u8 port, u8 pin, u8 direction);
	void DIO_SetPortDirection(u8 port, u8 direction);
	void DIO_SetPinValue(u8 port, u8 pin, u8 value);
	void DIO_SetPortValue(u8 port, u8 value);
	void DIO_TogglePin(u8 port, u8 pin);
	u8 DIO_GetPinValue(u8 port, u8 pin);
	u8 DIO_GitPortValue(u8 port);


#endif /* DIO_DIO_INTERFACE_H_ */
