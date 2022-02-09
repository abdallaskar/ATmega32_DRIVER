/*
 * config.h
 *
 *  Created on: Aug 26, 2021
 *      Author: abdalla
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_
/* LCD PORT C PIN FROM 4 : 7
 * LCD PORT COMMEND PORT D
 *   RS : PIN 0
 *   EN : PIN 1
 *   RW : GROUND
 *
 *   MODE CAN BE 4 OR 8
 */


#define LCD_PORT  2
#define LCD_PORT_COMMEND  3

#define RS_PIN  1
#define EN_PIN  0
#define mode 4

#endif /* LCD_LCD_CONFIG_H_ */
