/*
 * program.c
 *
 *  Created on: Aug 26, 2021
 *      Author: abdalla
 */
#include<util/delay.h>
#include "../LIB/STD_TYPE.h"
#include "../DIO/DIO_interface.h"
#include "LCD_Config.h"
/*  LCD_SendCommond : send commend to LCD
 *  arguments       : commend
 *  return          : null
 */

void LCD_SendCommond(u8 u8Cpy_commond) {

	DIO_SetPortDirection(LCD_PORT, 0xf0);
	DIO_SetPinDirection(LCD_PORT_COMMEND,EN_PIN,1);
	DIO_SetPinDirection(LCD_PORT_COMMEND,RS_PIN,1);

	DIO_SetPinValue(LCD_PORT_COMMEND, RS_PIN, 0);  // RS=0

	if (mode == 8) {
		DIO_SetPortValue(LCD_PORT, u8Cpy_commond);
	} else if (mode == 4) {

		DIO_SetPortValue(LCD_PORT, (u8Cpy_commond & 0xf0));  // send high nibble

		DIO_SetPinValue(LCD_PORT_COMMEND, EN_PIN, 1); // EN=1
		_delay_ms(1);
		DIO_SetPinValue(LCD_PORT_COMMEND, EN_PIN, 0); // EN=0
		_delay_ms(1);
		DIO_SetPortValue(LCD_PORT, (u8Cpy_commond << 4));   // send low nibble
	}

	DIO_SetPinValue(LCD_PORT_COMMEND, EN_PIN, 1); // set enable
	_delay_ms(1);
	DIO_SetPinValue(LCD_PORT_COMMEND, EN_PIN, 0); // reset enable
	_delay_ms(1);

}

/*  LCD_SendChracter : send charter to LCD
 *  arguments        : unsigned Charter
 *  return           : null
 */
void LCD_SendChar(u8 u8Cpy_data) {


	DIO_SetPortDirection(LCD_PORT, 0xf0);
	DIO_SetPinDirection(LCD_PORT_COMMEND,EN_PIN,1);
	DIO_SetPinDirection(LCD_PORT_COMMEND,RS_PIN,1);

	DIO_SetPinValue(LCD_PORT_COMMEND, RS_PIN, 1);  //RS=1

	if (mode == 8) {
		DIO_SetPortValue(LCD_PORT, u8Cpy_data);

	} else if (mode == 4) {

		DIO_SetPortValue(LCD_PORT, (u8Cpy_data & 0xf0));

		DIO_SetPinValue(DIO_PORTD, EN_PIN, 1); // EN
		_delay_ms(1);
		DIO_SetPinValue(DIO_PORTD, EN_PIN, 0); // EN
		_delay_ms(1);
		DIO_SetPortValue(LCD_PORT, (u8Cpy_data << 4));
	}

	DIO_SetPinValue(LCD_PORT_COMMEND, EN_PIN, 1); // EN
	_delay_ms(1);
	DIO_SetPinValue(LCD_PORT_COMMEND, EN_PIN, 0); // EN
	_delay_ms(1);
}

void LCD_Init(void) {

	DIO_SetPortDirection(LCD_PORT, 0xf0);
	DIO_SetPinDirection(LCD_PORT_COMMEND,EN_PIN,1);
	DIO_SetPinDirection(LCD_PORT_COMMEND,RS_PIN,1);


	DIO_SetPinValue(LCD_PORT_COMMEND, EN_PIN, 0);   //EN=0
	//_delay_ms(2000);
	if (mode == 8) {

		LCD_SendCommond(0x38);
		LCD_SendCommond(0x0E);
		LCD_SendCommond(0x01);

	} else if (mode == 4) {
		LCD_SendCommond(0x33);
		LCD_SendCommond(0x32);
		LCD_SendCommond(0x28);
		LCD_SendCommond(0x0E);
		LCD_SendCommond(0x01);
	}

	_delay_ms(2);
	LCD_SendCommond(0x06);

}

void LCD_PrintString(char *str) {
	u16 i = 0;
	while (str[i] != 0) {
		LCD_SendChar(str[i]);
		i++;
	}

}

void LCD_SetCursorPostion(u8 x, u8 y) {
	u8 posit = 0x80;
	x %= 16;
	if (x >= 0 && x < 16) {
		if (y == 0) {
			posit += x;
		}
		if (y == 1) {

			posit += (x + 0x40);
		}

	}
	LCD_SendCommond(posit);
}

void LCD_PrintNum(s32 s32_CPY_Num) {
	s32 arr[11] = { -1 };
	s32 digit = 0;
	int i = 0;
	s32 nu = 0;

	if (s32_CPY_Num < 0) {
		arr[i++] = '-';         // keep negative
		s32_CPY_Num *= -1;      // convert number to positive
		nu++;
	};

	while (s32_CPY_Num != 0) {
		digit = s32_CPY_Num % 10;
		arr[i++] = ('0' + digit);

		s32_CPY_Num = s32_CPY_Num / 10;
		nu++;
	}

	if (arr[0] == '-') {

		LCD_SendChar(arr[0]);
		for (int i = nu; i >= 1; --i) {

			if (arr[i] != -1) {

				LCD_SendChar(arr[i]);
			}
		}
	} else if(nu>=1){
		for (int i = nu - 1; i >= 0; --i) {

			if (arr[i] != -1) {

				LCD_SendChar(arr[i]);
			}
		}
	}else{
		LCD_SendChar('0');
	}

}

void LCD_SaveCustomCharater(u8 arr[], u8 ind) {

	if (ind >= 0 && ind < 8) {
		LCD_SendCommond((0x40 + (ind * 8)));
		for (int i = 0; i < 8; ++i) {
			LCD_SendChar(arr[i]);
		}
		LCD_SendCommond(0x80);
	}

}

