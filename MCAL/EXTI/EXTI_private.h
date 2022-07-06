/*
 * EXTI_private.h
 *
 *  Created on: Sep 2, 2021
 *      Author: abdalla
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

#include "../LIB/STD_TYPE.h"




/******* External Interrupt Register and bits  *************/

// register enable and disable
#define GICR     *((volatile  u8*)(0x5B))

#define INT1  7
#define INT0  6
#define INT2  5

// register flag
#define GIFR     *((volatile  u8*)(0x5A))

#define  INTF1  7
#define  INTF0  6
#define  INTF2  5


#define MCUCR    *((volatile  u8*)(0x55))

#define ISC11  3
#define ISC10  2
#define ISC01  1
#define ISC00  0


#define MCUCSR   *((volatile  u8*)(0x54))

#define ISC2   6

#endif /* EXTI_EXTI_PRIVATE_H_ */
