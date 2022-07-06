/*
 * TIMER1_interface.h
 *
 *  Created on: ١٠‏/٠٣‏/٢٠٢٢
 *      Author: abdalla
 */

#ifndef TIMER1_TIMER1_INTERFACE_H_
#define TIMER1_TIMER1_INTERFACE_H_

// enum for modes

typedef enum {

	TIMER1_NORMAL_MODE = 0,
	TIMER1_PHASE_CORRECT_8BIT_MODE,
	TIMER1_PHASE_CORRECT_9BIT_MODE,
	TIMER1_PHASE_CORRECT_10BIT_MODE,
	TIMER1_CTC_OCR1A_MODE,
	TIMER1_FAST_PWM_8BIT_MODE,
	TIMER1_FAST_PWM_9BIT_MODE,
	TIMER1_FAST_PWM_10BIT_MODE,
	TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_MODE,
	TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_MODE,
	TIMER1_PWM_PHASE_CORRECT_ICR1_MODE,
	TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE,
	TIMER1_CTC_ICR1_MODE,
	TIMER1_FAST_PWM_ICR1_MODE,
	TIMER1_FAST_PWM_OCR1A_MODE
} TIMER1_Mode_Type;

typedef enum {
	TIMER1_STOP = 0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	TIMER1_EXTERNAL_FALLING,
	TIMER1_EXTERNAL_RISING

} TIMER1_Scaler_Type;

typedef enum {

	OC1A_DISCONNECTED = 0,
	OC1A_TOGGLE,
	OC1A_NON_INVERTING,
	OC1A_INVERTING

} OC1A_Mode_Type;

typedef enum {

	OC1B_DISCONNECTED = 0,
	OC1B_TOGGLE,
	OC1B_NON_INVERTING,
	OC1B_INVERTING

} OC1B_Mode_Type;

typedef enum{
	RISING=0,
	FALLING
}ICU_Edge_Type;


void TIMER1_Init(TIMER1_Mode_Type Mode, TIMER1_Scaler_Type Prescaler,
		OC1A_Mode_Type Oc1a, OC1B_Mode_Type Oc1b);

void TIMER1_ICU_Edge(ICU_Edge_Type edge);

void TIMER1_OVF_SetCallBack(void (*LocalFptr)(void)) ;

void TIMER1_OCA_SetCallBack(void (*LocalFptr)(void)) ;

void TIMER1_OCB_SetCallBack(void (*LocalFptr)(void));

void TIMER1_ICU_SetCallBack(void (*LocalFptr)(void)) ;


void  TIMER1_Overflow_Interrupt_Enable();
void  TIMER1_Overflow_Interrupt_Disable();
void  TIMER1_ICU_Interrupt_Enable();
void  TIMER1_ICU_Interrupt_Disable();
void  TIMER1_OCA_Interrupt_Enable();
void  TIMER1_OCA_Interrupt_Disable();
void  TIMER1_OCB_Interrupt_Enable();
void  TIMER1_OCB_Interrupt_Disable();

void PWM_Init();
void PWM_Freq_HZ(u32 Freq);
void PWM_Freq_KZ(u32 KZ_Freq);
void PWM_Duty(u8 duty);
void PWM_Measure(u32* pFreq,u8* pDuty);






/****************	Interrupt Vectors Table For Timer 1		*******************/

#define TIMER1_CAPT_vect       __vector_6
#define TIMER1_COMPA_vect      __vector_7
#define TIMER1_COMPB_vect      __vector_8
#define TIMER1_OVF_vect        __vector_9


/****************   Interrupt Function  ISR  **********************************/
#define ISR(vector,...)  \
void vector (void) __attribute__ ((signal)) __VA_ARGS__ ; \
void vector (void)


#endif /* TIMER1_TIMER1_INTERFACE_H_ */
