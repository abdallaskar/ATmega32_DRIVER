/*
 * File Name  :TIMER1_program.c
 * Created on : 10‏/02‏/2022
 * Author     : abdalla
 */

#include  "../LIB/BIT_MATH.h"
#include  "../LIB/STD_TYPE.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"


/************************ Pointer to function to assigned to ISR **************/

static void (*TIMER1_OVF_Fptr)(void) = NULLPTR;
static void (*TIMER1_OCA_Fptr)(void) = NULLPTR;
static void (*TIMER1_OCB_Fptr)(void) = NULLPTR;
static void (*TIMER1_ICU_Fptr)(void) = NULLPTR;

void TIMER1_Init(TIMER1_Mode_Type Mode, TIMER1_Scaler_Type Prescaler,
		OC1A_Mode_Type OC1A, OC1B_Mode_Type OC1B) {

	switch (Mode) {
	case TIMER1_NORMAL_MODE:
		/* Timer1 Mode Normal or Overflow */
		CLEAR_BIT(TCCR1A, WGM10);
		CLEAR_BIT(TCCR1A, WGM11);
		CLEAR_BIT(TCCR1B, WGM12);
		CLEAR_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_PHASE_CORRECT_8BIT_MODE:
		/* Timer1 Mode PWM, Phase Correct, 8-bit */
		SET_BIT(TCCR1A, WGM10);
		CLEAR_BIT(TCCR1A, WGM11);
		CLEAR_BIT(TCCR1B, WGM12);
		CLEAR_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_PHASE_CORRECT_9BIT_MODE:
		/* Timer1 Mode PWM, Phase Correct, 9-bit */
		CLEAR_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		CLEAR_BIT(TCCR1B, WGM12);
		CLEAR_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_PHASE_CORRECT_10BIT_MODE:
		/* Timer1 Mode PWM, Phase Correct, 10-bit */
		SET_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		CLEAR_BIT(TCCR1B, WGM12);
		CLEAR_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_CTC_OCR1A_MODE:
		/* Timer1 Mode CTC Top OCR1A */
		CLEAR_BIT(TCCR1A, WGM10);
		CLEAR_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		CLEAR_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_FAST_PWM_8BIT_MODE:
		/* Timer1 Mode Fast PWM, 8-bit */
		SET_BIT(TCCR1A, WGM10);
		CLEAR_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		CLEAR_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_FAST_PWM_9BIT_MODE:
		/* Timer1 Mode Fast PWM, 9-bit */
		CLEAR_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		CLEAR_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_FAST_PWM_10BIT_MODE:
		/* Timer1 Mode Fast PWM, 10-bit */
		SET_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		CLEAR_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_MODE:
		/* Timer1 Mode PWM, Phase and Frequency Correct Top ICR1 */
		CLEAR_BIT(TCCR1A, WGM10);
		CLEAR_BIT(TCCR1A, WGM11);
		CLEAR_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_MODE:
		/* Timer1 Mode PWM, Phase and Frequency Correct Top OCR1A */
		SET_BIT(TCCR1A, WGM10);
		CLEAR_BIT(TCCR1A, WGM11);
		CLEAR_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_PWM_PHASE_CORRECT_ICR1_MODE:
		/* Timer1 Mode PWM, Phase Correct Top ICR1 */
		CLEAR_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		CLEAR_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE:
		/* Timer1 Mode PWM, Phase Correct Top OCR1A */
		SET_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		CLEAR_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_CTC_ICR1_MODE:
		/* Timer1 Mode CTC Top ICR1 */
		CLEAR_BIT(TCCR1A, WGM10);
		CLEAR_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_FAST_PWM_ICR1_MODE:
		/* Timer1 Mode Fast PWM Top ICR1 */
		CLEAR_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);
		break;

	case TIMER1_FAST_PWM_OCR1A_MODE:
		/* Timer1 Mode Fast PWM Top OCR1A */
		SET_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);
		break;
	default:
		break;
	}

	/**** Prescaler mask *****/

	TCCR1B &= 0xF8;
	/***** Set prescaler value *****/

	TCCR1B |= Prescaler;

	switch (OC1A) {

	case OC1A_DISCONNECTED:

		/* Select channel A normal */
		CLEAR_BIT(TCCR1A, COM1A0);
		CLEAR_BIT(TCCR1A, COM1A1);
		break;

	case OC1A_TOGGLE:

		/* Select Channel A Toggle */
		SET_BIT(TCCR1A, COM1A0);
		CLEAR_BIT(TCCR1A, COM1A1);
		break;

	case OC1A_NON_INVERTING:

		/* Select Channel A Non-inverting */
		CLEAR_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1A1);
		break;

	case OC1A_INVERTING:

		/* Select Channel A Inverting */
		SET_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1A1);
		break;

	default:
		break;
	}
	switch (OC1B) {

	case OC1B_DISCONNECTED:

		/* Select channel B normal */
		CLEAR_BIT(TCCR1A, COM1B0);
		CLEAR_BIT(TCCR1A, COM1B1);
		break;

	case OC1B_TOGGLE:

		/* Select Channel B Toggle */
		SET_BIT(TCCR1A, COM1B0);
		CLEAR_BIT(TCCR1A, COM1B1);
		break;

	case OC1B_NON_INVERTING:

		/* Select Channel B Non-inverting */
		CLEAR_BIT(TCCR1A, COM1B0);
		SET_BIT(TCCR1A, COM1B1);
		break;

	case OC1B_INVERTING:

		/* Select Channel B Inverting */
		SET_BIT(TCCR1A, COM1B0);
		SET_BIT(TCCR1A, COM1B1);
		break;

	default:
		break;
	}

}
void TIMER1_ICU_Edge(ICU_Edge_Type edge) {

	switch (edge) {
	case RISING:
		SET_BIT(TCCR1B, ICES1);
		break;
	case FALLING:
		CLEAR_BIT(TCCR1B, ICES1);
		break;
	default:
		break;
	}
}

/****************  Interrupt Enable and Disable For Timer 1  ******************/

void TIMER1_Overflow_Interrupt_Enable() {

	SET_BIT(TIMSK, TOIE1);
}
void TIMER1_Overflow_Interrupt_Disable() {
	CLEAR_BIT(TIMSK, TOIE1);
}
void TIMER1_ICU_Interrupt_Enable() {
	SET_BIT(TIMSK, TICIE1);
}
void TIMER1_ICU_Interrupt_Disable() {
	CLEAR_BIT(TIMSK, TICIE1);
}
void TIMER1_OCA_Interrupt_Enable() {
	SET_BIT(TIMSK, OCIE1A);
}
void TIMER1_OCA_Interrupt_Disable() {
	CLEAR_BIT(TIMSK, OCIE1A);
}
void TIMER1_OCB_Interrupt_Enable() {
	SET_BIT(TIMSK, OCIE1B);
}
void TIMER1_OCB_Interrupt_Disable() {
	CLEAR_BIT(TIMSK, OCIE1B);
}

/**********************  TIMER 1  Call Back Functions ************************/

void TIMER1_OVF_SetCallBack(void (*LocalFptr)(void)) {

	TIMER1_OVF_Fptr = LocalFptr;
}

void TIMER1_OCA_SetCallBack(void (*LocalFptr)(void)) {
	TIMER1_OCA_Fptr = LocalFptr;
}

void TIMER1_OCB_SetCallBack(void (*LocalFptr)(void)) {
	TIMER1_OCB_Fptr = LocalFptr;
}

void TIMER1_ICU_SetCallBack(void (*LocalFptr)(void)) {
	TIMER1_ICU_Fptr = LocalFptr;
}

/**********************   TIMER1 ISR Functions ********************************/

ISR( TIMER1_OVF_vect) {
	if (TIMER1_OVF_Fptr != NULLPTR) {
		TIMER1_OVF_Fptr();
	}
}

ISR( TIMER1_COMPA_vect ) {
	if (TIMER1_OCA_Fptr != NULLPTR) {
		TIMER1_OCA_Fptr();
	}
}
ISR( TIMER1_COMPB_vect) {
	if (TIMER1_OCB_Fptr != NULLPTR) {
		TIMER1_OCB_Fptr();
	}
}
ISR(TIMER1_CAPT_vect ) {
	if (TIMER1_ICU_Fptr != NULLPTR) {
		TIMER1_ICU_Fptr();
	}
}

/******************************* PWM APIS *************************************/

void PWM_Init() {

	TIMER1_Init(TIMER1_FAST_PWM_ICR1_MODE, TIMER1_SCALER_8, OC1A_NON_INVERTING,
			OC1B_DISCONNECTED);
}

void PWM_Freq_HZ(u32 Freq) {

	if (Freq == 0) {

	} else {
		u32 T_total = 1000000 / Freq;
		if (T_total > 1) {
			ICR1 = T_total - 1;
		} else {
			ICR1 = 0;
		}

	}

}
void PWM_Freq_KZ(u32 KZ_Freq) {

	if (KZ_Freq == 0) {

	} else {
		u32 T_total = 1000 / KZ_Freq;

		if (T_total > 1) {
			ICR1 = T_total - 1;
		} else {
			ICR1 = 0;
		}

	}

}
void PWM_Duty(u8 duty) {
	if (duty <= 100) {
		u32 T_on = ((u32) duty * (ICR1 + 1)) / 100;

		if (T_on > 1) {
			OCR1A = T_on - 1;
		} else {
			OCR1A = 0;
		}

	}
}

/********  Interrupt function to Input capture unite and varibles *********/
volatile u16 t1 = 0, t2 = 0, t3 = 0, flag = 0;

static void func_ICU() {

	if (flag == 0) {
		t1 = ICR1;
		TIMER1_ICU_Edge(FALLING);
		flag = 1;
	} else if (flag == 1) {
		t2 = ICR1;
		TIMER1_ICU_Edge(RISING);
		flag = 2;
	} else if (flag == 2) {
		t3 = ICR1;
		TIMER1_ICU_Interrupt_Disable();
		flag = 3;
	}

}

/********** Measure frequency and duty for pwm******/

void PWM_Measure(u32 *pfreq, u8 *pduty) {

	u16 Time_on = 0, Time_of = 0, total_t = 0;

	TCNT1 = 0;
	TIMER1_ICU_SetCallBack(func_ICU);
	TIMER1_ICU_Edge(RISING);
	TIMER1_ICU_Interrupt_Enable();
	flag = 0;

	while (flag <= 2) {
	}

	Time_on = t2 - t1;
	Time_of = t3 - t2;
	total_t = t3 - t1;

	*pduty = ((u32) Time_on * (u32) 100 / ((u32) total_t));
	*pfreq = (u32) 1000000 / ((u32) total_t);
}

