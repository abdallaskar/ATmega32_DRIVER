/*
 * interface.h
 *
 *  Created on: Aug 26, 2021
 *      Author: abdalla
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

#include "../LIB/STD_TYPE.h"

void LCD_Init(void);
void LCD_SendCommond(u8 u8Cpy_commond);
void LCD_SendChar(u8 u8Cpy_data);
void LCD_PrintString(char *str);
void LCD_PrintNum(s32 s32_CPY_Num) ;
void LCD_SaveCustomCharater(u8 arr[], u8 ind);
void LCD_SetCursorPostion(u8 x, u8 y) ;


#endif /* LCD_LCD_INTERFACE_H_ */
