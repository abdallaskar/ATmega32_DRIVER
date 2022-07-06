/*
 * config.h
 *
 *  Created on: Aug 26, 2021
 *      Author: abdalla
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

#include "LCD_Private.h"

/*  PORT DATA      PORT A
 *  PORT CONTROL   PORT B
 *
 *   EN : PIN 0
 *   RW : PIN 1
 *   RS : PIN 2
 *
 *   MODE CAN BE 4 OR 8
 */

#define  DDR_DATA       DDRA
#define  PORT_DATA      PORTA
#define  PORT_CONTROL   PORTB
#define  DDR_CONTROL    DDRB


#define EN_PIN  0
#define RW_PIN  1
#define RS_PIN  2



#define MODE   8

#endif /* LCD_LCD_CONFIG_H_ */
