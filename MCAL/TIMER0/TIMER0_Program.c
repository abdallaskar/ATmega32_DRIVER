/*
 * Title      : TIMER0
 * File Name  : TIMER0_Program.c
 * Author     : abdalla
 * Created on : Mar 27, 2022
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"

void (*TIMER0_pvCOMP)(void) = NULLPTR;
void (*TIMER0_pvOVF)(void) = NULLPTR;

/* Timer Init set timer mode and scaler
 */

void TIMER0_Init(TIMER0_Mode_Type mode, TIMER0_Scaler_Type scaler,
		OC0_Mode_Type oc0_mode) {

	// Select mode
	switch (mode) {

	case TIMER0_NORMAL_MODE: {
		CLEAR_BIT(TCCR0, WGM00);
		CLEAR_BIT(TCCR0, WGM01);
	}
		break;
	case TIMER0_PHASECORRECT_MODE: {
		SET_BIT(TCCR0, WGM00);
		CLEAR_BIT(TCCR0, WGM01);
	}
		break;
	case TIMER0_CTC_MODE: {
		CLEAR_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	}
		break;
	case TIMER0_FASTPWM_MODE: {
		SET_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	}
		break;

	}

	// chose scaler to frequency

	TCCR0 = TCCR0 & 0b11111000; // clear three bits for scaler
	TCCR0 = TCCR0 | scaler;

	switch (oc0_mode) {

	case OC0_DISCONNECTED: {
		CLEAR_BIT(TCCR0, COM00);
		CLEAR_BIT(TCCR0, COM01);
	}
		break;
	case OC0_TOGGLE: {
		SET_BIT(TCCR0, COM00);
		CLEAR_BIT(TCCR0, COM01);
	}
		break;
	case OC0_NON_INVERTING: {
		CLEAR_BIT(TCCR0, COM00);
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

/*** Timer overflow interrupt enable ***/

void TIMER0_Overflow_Interrupt_Eable() {
	SET_BIT(TIMSK, TOIE0);
}
/*** Timer overflow interrupt disable ***/

void TIMER0_Overflow_Interrupt_Disable() {
	CLEAR_BIT(TIMSK, TOIE0);
}

/*** Timer output compare interrupt enable ***/

void TIMER0_Output_Compare_Interrupt_Eable() {
	SET_BIT(TIMSK, OCIE0);
}
/*** Timer output compare interrupt disable ***/

void TIMER0_Output_Compare_Interrupt_Disable() {
	CLEAR_BIT(TIMSK, OCIE0);
}

/***** Timer 0 overflow set call pack function *******/

void TIMER0_OVF_SetCallBack(void(*Copy_pvOVFFunc)(void)) {
	TIMER0_pvOVF = Copy_pvOVFFunc;
}

/***** Timer 0 output compare set call pack function *******/

void TIMER0_OCMP_SetCallBack(void(*Copy_pvOCMPFunc)(void))
{
	TIMER0_pvCOMP = Copy_pvOCMPFunc;
}



/************* Interrupt service routine to overflow *************/

ISR(TIMER0_OVF_vect) {
	if (TIMER0_pvOVF != NULLPTR) {
		TIMER0_pvOVF();
	}
}

/************* Interrupt service routine to output compare match *************/

ISR(TIMER0_COMP_vect) {

	if (TIMER0_pvCOMP != NULLPTR) {
		TIMER0_pvCOMP();
	}
}

