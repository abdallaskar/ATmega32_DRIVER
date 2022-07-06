
/*
 * Title      : TIMER0
 * File Name  : TIMER0_Private.h
 * Author     : abdalla
 * Created on : Mar 27, 2022
 */

#ifndef TIMER0_TIMER0_PRIVATE_H_
#define TIMER0_TIMER0_PRIVATE_H_



#define TCNT0          *((volatile u8*)(0x52))
#define TCCR0          *((volatile u8*)(0x53))
#define TIFR           *((volatile u8*)(0x58))
#define TIMSK          *((volatile u8*)(0x59))
#define SREG           *((volatile u8*)(0x5f))
#define OCR0           *((volatile u8*)(0x5c))


/*  TCCRO  */

#define   FOC0     7
#define   WGM00    6
#define   COM01    5
#define	  COM00    4
#define	  WGM01    3
#define   CS02     2
#define	  CS01     1
#define	  CS00     0

/*  TIMSK  */

#define   OCIE0    1
#define   TOIE0    0




#endif /* TIMER0_TIMER0_PRIVATE_H_ */
