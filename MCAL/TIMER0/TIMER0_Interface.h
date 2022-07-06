
/*
 * Title      : TIMER0
 * File Name  : TIMER0_Interface.h
 * Author     : abdalla
 * Created on : Mar 27, 2022
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_




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

void TIMER0_OCMP_SetCallBack(void(*Copy_pvOCMPFunc)(void)) ;
void TIMER0_OVF_SetCallBack(void(*Copy_pvOVFFunc)(void)) ;




/****************	Interrupt Vectors Table For Timer 0 	*******************/

#define TIMER0_COMP_vect       __vector_10
#define TIMER0_OVF_vect        __vector_11

/****************   Interrupt Function  ISR  **********************************/
#define ISR(vector,...)  \
void vector (void) __attribute__ ((signal)) __VA_ARGS__ ; \
void vector (void)


#endif /* TIMER0_INTERFACE_H_ */
