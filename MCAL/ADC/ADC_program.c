/*
 * ADC_program.c
 *
 *  Created on: Sep 5, 2021
 *      Author: abdalla
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"
#include "ADC_private.h"
#include "../DIO/DIO_interface.h"

void ADC_Init(void) {

   DIO_SetPortDirection(DIO_PORTA,0x00); // set port A as input

   ADCSRA= 0x87;  //make ADC enable and select ck/128
   ADMUX= 0xC0;  //2.56V Vref, ADC0 single ended input

   //ADMUX= 0x40;  //5V Vref, ADC0 single ended input

  /*
   *  Enable ADC
	SET_BIT(ADCSRA, 7);
	// Start Conversion
	SET_BIT(ADCSRA, 6);
	// Single conversion
	CLR_BIT(ADCSRA, 5);
	// Clear ADC Flag
	SET_BIT(ADCSRA, 4);
	// Polling
	CLR_BIT(ADCSRA, 3);
	// Prescaler Configuration
	SET_BIT(ADCSRA, 2);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 0);

	// Refer to channel zero
	CLR_BIT(ADMUX, 0);
	CLR_BIT(ADMUX, 1);
	CLR_BIT(ADMUX, 2);
	CLR_BIT(ADMUX, 3);
	CLR_BIT(ADMUX, 4);
	// select adjustment
	CLR_BIT(ADMUX, 5);

	// Reference voltage at VCC
	SET_BIT(ADMUX, 6);
	CLR_BIT(ADMUX, 7);

	*/


}

u16 ADC_u16ReadValue(void) {
	u16 u16Value = 0;
	// Start Conversion
	 SET_BIT(ADCSRA, 6);

	 //wait for conversion to finish*/
	while (GIT_BIT(ADCSRA,4) == 0) ;

	// Reading for right adjustment
	 u16Value=ADCL;
	 // u16 tempt=ADCH;
      u16Value |=(ADCH<<8);



    // Clear flag
	 SET_BIT(ADCSRA, 4);

	return u16Value;


	/*ADCSRA|=(1<<ADSC);      //start conversion
	while((ADCSRA&(1<<ADIF))==0);  //wait for conversion to finish*/
}


