/*
 * TIMER0_Private.h
 *
 *  Created on: Dec 18, 2021
 *      Author: Abdalla
 */

#ifndef TIMER0_TIMER0_PRIVATE_H_
#define TIMER0_TIMER0_PRIVATE_H_



#define TCNT0          *((volatile u8*)(0x52))
#define TCCR0          *((volatile u8*)(0x53))
#define TIFR0          *((volatile u8*)(0x58))
#define TIMSK          *((volatile u8*)(0x59))
#define SREG           *((volatile u8*)(0x5f))
#define OSR0           *((volatile u8*)(0x5c))





#endif /* TIMER0_TIMER0_PRIVATE_H_ */
