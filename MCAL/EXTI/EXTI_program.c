/*
 * EXTI_program.c
 *
 *  Created on: Sep 2, 2021
 *      Author: abdalla
 */

#include "../LIB/STD_TYPE.h"
#include "../LIB/BIT_MATH.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

/************** Pointer to function to assign to ISR***/

static void (*INT0_Fptr)(void) = NULLPTR;
static void (*INT1_Fptr)(void) = NULLPTR;
static void (*INT2_Fptr)(void) = NULLPTR;

/************* Call back function ************/

void EXTI_Set_Call_Back(EXTI_Source_Type interrput, void (*LocalPtr)(void)) {

	switch (interrput) {
	case EXTI_INT0:
		INT0_Fptr = LocalPtr;
		break;
	case EXTI_INT1:
		INT1_Fptr = LocalPtr;
		break;
	case EXTI_INT2:
		INT2_Fptr = LocalPtr;
		break;

	}

}

/***** Enable external interrupt ****/

void EXTI_Enable(EXTI_Source_Type interrupt) {

	switch (interrupt) {
	case EXTI_INT0:
		SET_BIT(GICR, INT0);
		break;
	case EXTI_INT1:
		SET_BIT(GICR, INT1);
		break;
	case EXTI_INT2:
		SET_BIT(GICR, INT2);
		break;

	}

}

/***** Disable external interrupt ****/

void EXTI_Disable(EXTI_Source_Type interrupt) {

	switch (interrupt) {
	case EXTI_INT0:
		CLR_BIT(GICR, INT0);
		break;
	case EXTI_INT1:
		CLR_BIT(GICR, INT1);
		break;
	case EXTI_INT2:
		CLR_BIT(GICR, INT2);
		break;

	}

}

/******* Chose trigger edge for each external interrupt ******/

void EXTI_Trigger_Edge(EXTI_Source_Type interrupt, Trigger_Edge_Type edge) {
	switch (interrupt) {
	case EXTI_INT0: {
		switch (edge) {
		case LOW_LEVEL: {
			CLR_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
		}
			break;
		case ANY_LOGIC_CHANGE: {
			SET_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
		}
			break;
		case FALLING_EDGE: {
			CLR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
		}
			break;
		case RISING_EDGE: {
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
		}
			break;
		}
	}
		break;
	case EXTI_INT1: {
		switch (edge) {
		case LOW_LEVEL: {
			CLR_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
		}
			break;
		case ANY_LOGIC_CHANGE: {
			SET_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
		}
			break;
		case FALLING_EDGE: {
			CLR_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
		}
			break;
		case RISING_EDGE: {
			SET_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
		}
			break;
		}

	}
		break;
	case EXTI_INT2: {
		switch (edge) {
		case FALLING_EDGE:
			CLR_BIT(MCUCSR, ISC2);

			break;
		case RISING_EDGE:
			CLR_BIT(MCUCSR, ISC2);

			break;
		default:
			CLR_BIT(MCUCSR, ISC2);
			break;
		}
	}
		break;

	}
}

/****************** ISR functions ********************/
ISR(INT0_vect) {

	if (INT0_Fptr != NULLPTR) {
		INT0_Fptr();
	}
}
ISR(INT1_vect) {
	if (INT1_Fptr != NULLPTR) {
		INT1_Fptr();
	}
}
ISR(INT2_vect) {
	if (INT1_Fptr != NULLPTR) {
		INT1_Fptr();
	}
}

