/*
 * SSD_program.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: ALIAA
 */

//#include<avr\io.h>
#include "../DIO/DIO_interface.h"
#include "../DIO/DIO_private.h"
#include "../LIB/STD_TYPE.h"
#include "SSD_Config.h"
#include "SSD_private.h"

const u8 arr_num[10] = { 0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6D, 0x07, 0x7f, 0x67 };
void SSD_Init(void) {

	DIO_SetPortDirection(SSD_PORT, OUTPUT);

	//SSD_DIRECTION =0xff;
	// data port direction will be output
}

void SSD_DisplayNum(u8 num) {
	if (num < 10) // to control if num greater than 9 segment not work
			{
#if SSD_TYPES == COMMON_CATHOD

		/// SSD_PORT = arr_num[num];
		DIO_SetPortValue(SSD_PORT, arr_num[num]);

#elif SSD_TYPES == COMMON_ANODE // when i use seg common cathod this part will neglect

		DIO_SetPortValue(SSD_PORT,~arr_num[num]);

#endif
	}
}

