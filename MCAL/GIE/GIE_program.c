/*
 * program.c
 *
 *  Created on: Sep 5, 2021
 *      Author: abdalla
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "GIE_private.h"


void GIE_voidEnableGlobleInterrupt(void){
	SET_BIT(SREG,7);


}
void GIE_voidDisableGlobleInterrupt(void){
	CLEAR_BIT(SREG,7);
}
