// bit_math.h
#ifndef BIT_MATH_H
#define BIT_MATH_H


#define  SET_BIT(VAR,BIT)     ((VAR) |=(1<<(BIT)))
#define  CLR_BIT(VAR,BIT)     ((VAR) &= ~(1<<(BIT)))
#define  TOGGLE_BIT(VAR,BIT)    ((VAR) ^= (1<<(BIT)))
#define  GIT_BIT(VAR,BIT)      (((VAR)>>(BIT)) &1)


#endif