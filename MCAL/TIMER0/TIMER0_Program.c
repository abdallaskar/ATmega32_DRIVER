/*
 * TIMER0_Program.c
 *
 *  Created on: Dec 18, 2021
 *      Author: Abdalla
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"
#include "TIMER0_Private.h"
#include "TIMER0_Interface.h"


/* Timer Init set timer mode and scaler
 */

void TIMER0_Init(TIMER0_Mode_Type mode, TIMER0_Scaler_Type scaler,
		OC0_Mode_Type oc0_mode) {

	// Select mode
	switch (mode) {

	case TIMER0_NORMAL_MODE: {
		CLR_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
	}
		break;
	case TIMER0_PHASECORRECT_MODE: {
		SET_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
	}
		break;
	case TIMER0_CTC_MODE: {
		CLR_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	}
		break;
	case TIMER0_FASTPWM_MODE: {
		SET_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	}
		break;

	}
	// chose scaler
	TCCR0 = TCCR0 & 0b11111000; // clear three bits for scaler
	TCCR0 = TCCR0 | scaler;

	switch (oc0_mode) {

	case OC0_DISCONNECTED: {
		CLR_BIT(TCCR0, COM00);
		CLR_BIT(TCCR0, COM01);
	}
		break;
	case OC0_TOGGLE: {
		SET_BIT(TCCR0, COM00);
		CLR_BIT(TCCR0, COM01);
	}
		break;
	case OC0_NON_INVERTING: {
		CLR_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
	}
		break;
	case OC0_INVERTING: {
		SET_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
	}
		break;

	}

}

/* Timer overflow interrupt enable
 */

void TIMER0_Overflow_Interrupt_Eable() {
	SET_BIT(TIMSK, TOIE0);
}
void TIMER0_Overflow_Interrupt_Disable() {
	CLR_BIT(TIMSK, TOIE0);
}
void  TIMER0_Output_Compare_Interrupt_Eable(){
	SET_BIT(TIMSK, OCIE0);
}
void  TIMER0_Output_Compare_Interrupt_Disable(){
	CLR_BIT(TIMSK, OCIE0);
}


//void TIMER0_Delay() {
//	static u8 count = 0;
//	TCNT0 = 0x00;
//	//normal mode prescaler 1024
//	TCCR0 = 0x05;
//	while (count < 31) {
//		while ((GIT_BIT(TIFR0,0) & 0x01) == 0) {
//		}
//		count++;
//		SET_BIT(TIFR0, 0);
//		//TCNT0 = 0x00;
//	}
//
//	TCCR0 = 0x00;
//	count = 0;
//}
//void TIMER0_NormalMode() {
//
//}
//
////void TIMER0_CTCMode() {
////	// Enable General interrupt enable
////	GIE_EnableGlobleInterrupt();
////
////	// enable PIE
////	// OCIE     ::  Timer/Counter0 Output Compare Match Interrupt Enable
////	SET_BIT(TIMSK,OCIE0);
////	//  compare match mode
////	CLR_BIT(TCCR0, WGM00);
////	SET_BIT(TCCR0, WGM01);
////
////	// match hard ware action toggle
////	SET_BIT(TCCR0, COM00);
////	CLR_BIT(TCCR0, COM01);
////
////	// value of compare match
////	OSR0 = 254;
////
////	// pre scaler /1024   CS0:2 :: Clock Select   1 0 1
////	SET_BIT(TCCR0, CS00);
////	CLR_BIT(TCCR0, CS01);
////	SET_BIT(TCCR0, CS02);
////
////	// TCNT Start count form 0x00
////	TCNT0 = 0x00;
////
////}
////void __vector_10(void) __attribute__((signal));
////void __vector_10(void){
//
////}
//
