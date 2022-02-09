/*
 * program.c
 *
 *  Created on: Sep 5, 2021
 *      Author: abdalla
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"

#include "GIE_private.h"


void GIE_EnableGlobleInterrupt(void){
	SET_BIT(SREG,7);


}
void GIE_DisableGlobleInterrupt(void){
	CLR_BIT(SREG,7);
}
