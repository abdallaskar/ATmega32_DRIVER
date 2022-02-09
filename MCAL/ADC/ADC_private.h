/*
 * ADC_private.h
 *
 *  Created on: Sep 5, 2021
 *      Author: abdalla
 */

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_





#define ADMUX    *((volatile u8*)(0x27))
#define ADCSRA   *((volatile u8*)(0x26))
#define SFIOR    *((volatile u8*)(0x50))
#define ADCH     *((volatile u8*)(0x25))
#define ADCL     *((volatile u8*)(0x24))




#endif /* ADC_ADC_PRIVATE_H_ */
