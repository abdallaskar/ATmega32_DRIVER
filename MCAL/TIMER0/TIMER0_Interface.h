/*
 * TIMER0_Interface.h
 *
 *  Created on: Dec 18, 2021
 *      Author: Abdalla
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"
#include "TIMER0_Private.h"


// enum for modes

typedef enum {

	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE


}TIMER0_Mode_Type;

typedef enum {
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL_FALLING,
	EXTERNAL_RISING

}TIMER0_Scaler_Type;

typedef enum {

	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING

}OC0_Mode_Type;


void  TIMER0_Init(TIMER0_Mode_Type mode,TIMER0_Scaler_Type scaler,OC0_Mode_Type  oc0_mode);
void  TIMER0_Overflow_Interrupt_Eable();
void  TIMER0_Overflow_Interrupt_Disable();
void  TIMER0_Output_Compare_Interrupt_Eable();
void  TIMER0_Output_Compare_Interrupt_Disable();

/*  TCCRO  */

#define   FOC0     7
#define   WGM00    6
#define   COM01    5
#define	  COM00    4
#define	  WGM01    3
#define   CS02     2
#define	  CS01     1
#define	  CS00     0

/*  TIMSK  */

#define   OCIE0    1
#define   TOIE0    0

//void TIMER0_Delay();
//void TIMER0_NormalMode();
//void TIMER0_CTCMode();

#endif /* TIMER0_INTERFACE_H_ */
