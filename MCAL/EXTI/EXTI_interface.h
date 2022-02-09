/*
 * EXTI_interface.h
 *
 *  Created on: Sep 2, 2021
 *      Author: abdalla
 */

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_



typedef enum {
	LOW_LEVEL =0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE

} Trigger_Edge_Type ;

typedef enum {
 EXTI_INT0 = 0,
 EXTI_INT1,
 EXTI_INT2

} EXTI_Source_Type;


/************ prototype function ******/

void EXTI_Enable(EXTI_Source_Type interrupt);
void EXTI_Disable(EXTI_Source_Type interrupt);
void EXTI_Trigger_Edge(EXTI_Source_Type  interrupt , Trigger_Edge_Type  edge);
void EXTI_Set_Call_Back(EXTI_Source_Type interrput, void (*LocalPtr)(void));


/******* Interrupt vectors table ********/

#define INT0_vect              __vector_1
#define INT1_vect              __vector_2
#define INT2_vect              __vector_3
#define TIMER2_COMP_vect       __vector_4
#define TIMER2_OVF_vect        __vector_5
#define TIMER1_CAPT_vect       __vector_6
#define TIMER1_COMPA_vect      __vector_7
#define TIMER1_COMPB_vect      __vector_8
#define TIMER1_OVF_vect        __vector_9
#define TIMER0_COMP_vect       __vector_10
#define TIMER0_OVF_vect        __vector_11
#define SPI_STC_vect           __vector_12
#define USART_RXC_vect         __vector_13
#define USART_UDRE_vect        __vector_14
#define USART_TXC_vect         __vector_15
#define ADC_vect               __vector_16
#define EE_RDY_vect            __vector_17
#define ANA_COMP_vect          __vector_18
#define TWI_vect               __vector_19
#define SPM_RDY_vect           __vector_20

/***************  interrupt function  ISR  ************/
#define ISR(vector,...)  \
void vector (void) __attribute__ ((signal)) __VA_ARGS__ ; \
void vector (void)

/******************/

#define ISR_NOBLOCK   __attribute__ ((interrupt))
#define ISR_NAKED     __attribute__ ((naked))

/******************/

/******** set global interrupt *******/
#define sei()     __asm__ __volatile__ ("sei" ::)
/******** clear global interrupt *******/
#define cli()     __asm__ __volatile__ ("cli" ::)
/******** return from interrupt *******/
#define reti()    __asm__ __volatile__ ("reti" ::)

#endif /* EXTI_EXTI_INTERFACE_H_ */
