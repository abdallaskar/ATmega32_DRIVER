
#ifndef BIT_MATH_H
#define BIT_MATH_H


#define  CLEAR_REG(VAR)           ((VAR) = (0b00000000))
#define  SET_REG(VAR)             ((VAR) = (0b11111111))
#define  ASSIGN_REG(VAR,VALUE)    ((VAR) = (VALUE))
#define  SET_BIT(VAR,BIT)         ((VAR) |=(1<<(BIT)))
#define  CLEAR_BIT(VAR,BIT)       ((VAR) &= ~(1<<(BIT)))
#define  TOGGLE_BIT(VAR,BIT)      ((VAR) ^= (1<<(BIT)))
#define  GET_BIT(VAR,BIT)         (((VAR)>>(BIT)) &1)


#endif
