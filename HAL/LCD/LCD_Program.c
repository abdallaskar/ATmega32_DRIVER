/*
 * program.c
 *
 *  Created on: Aug 26, 2021
 *      Author: abdalla
 */

#include  <util/delay.h>
#include "../LIB/STD_TYPE.h"
#include "../LIB/BIT_MATH.h"
#include "LCD_Config.h"

/*  LCD_SendCommond : send commend to LCD
 *  arguments       : commend
 *  return          : null
 */

void LCD_SendCommond(u8 u8Cpy_commond) {

	CLEAR_BIT(PORT_CONTROL, RS_PIN);  // RS -> 0
	CLEAR_BIT(PORT_CONTROL, RW_PIN);  // RW -> 0

	if (MODE == 8) {
		ASSIGN_REG(PORT_DATA, u8Cpy_commond);   // assign data to port data
	} else if (MODE == 4) {

		ASSIGN_REG(PORT_DATA, (u8Cpy_commond & 0xf0));  // send high nibble

		SET_BIT(PORT_CONTROL, EN_PIN);   //EN ->  1
		_delay_ms(1);
		CLEAR_BIT(PORT_CONTROL, EN_PIN); //EN ->  0
		_delay_ms(1);

		ASSIGN_REG(PORT_DATA, (u8Cpy_commond << 4));   // send low nibble
	}

	SET_BIT(PORT_CONTROL, EN_PIN);   //EN ->  1
	_delay_ms(1);
	CLEAR_BIT(PORT_CONTROL, EN_PIN);      //EN ->  0
	_delay_ms(1);

}

/*  LCD_SendChracter : send charter to LCD
 *  arguments        : unsigned Charter
 *  return           : null
 */
void LCD_SendChar(u8 u8Cpy_data) {

	SET_BIT(PORT_CONTROL, RS_PIN);    // RS -> 1
	CLEAR_BIT(PORT_CONTROL, RW_PIN);  // RW -> 0

	if (MODE == 8) {
		ASSIGN_REG(PORT_DATA, u8Cpy_data);    // Assigned charter to port data

	} else if (MODE == 4) {

		ASSIGN_REG(PORT_DATA, (u8Cpy_data & 0xf0));    // send high nibble

		SET_BIT(PORT_CONTROL, EN_PIN);        //EN ->  1
		_delay_ms(1);
		CLEAR_BIT(PORT_CONTROL, EN_PIN);      //EN ->  0
		_delay_ms(EN_PIN);

		ASSIGN_REG(PORT_DATA, (u8Cpy_data << 4));   // send low nibble
	}

	SET_BIT(PORTB, EN_PIN);               //EN ->  1
	_delay_ms(1);
	CLEAR_BIT(PORT_CONTROL, EN_PIN);      //EN ->  0
	_delay_ms(1);

}

void LCD_Init(void) {

	if (MODE == 8) {
		SET_REG(DDR_DATA);                       // port data as output
		ASSIGN_REG(DDR_CONTROL, 0b00000111);     // pins control as output
		_delay_ms(40);

		LCD_SendCommond(0x38);
		_delay_ms(1);
		LCD_SendCommond(0x0E);
		_delay_ms(1);
		LCD_SendCommond(0x01);

	} else if (MODE == 4) {
		ASSIGN_REG(DDR_DATA,0b11110000);                // pins data as output
		ASSIGN_REG(DDR_CONTROL, 0b00000111);            // pins control as output
		_delay_ms(40);

		LCD_SendCommond(0x33);
		_delay_ms(1);
		LCD_SendCommond(0x32);
		_delay_ms(1);
		LCD_SendCommond(0x28);
		_delay_ms(1);
		LCD_SendCommond(0x0E);
		_delay_ms(1);
		LCD_SendCommond(0x01);
	}

	_delay_ms(2);
	LCD_SendCommond(0x06);

}

/* LCD_PrintString : print string to LCD
 * arguments       : pointer to charter
 * return          : void
 */

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
	} else if (nu >= 1) {
		for (int i = nu - 1; i >= 0; --i) {

			if (arr[i] != -1) {

				LCD_SendChar(arr[i]);
			}
		}
	} else {
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
void LCD_Clear() {
	LCD_SendCommond(0x01);
	_delay_ms(2);
}
