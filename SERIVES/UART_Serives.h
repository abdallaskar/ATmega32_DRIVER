/*
 * Title      : UART_SERIVES
 * File Name  : UART_Iinterface.h
 * Author     : abdalla
 * Created on : Mar 22, 2022
 */

#ifndef SERIVES_UART_IINTERFACE_H_
#define SERIVES_UART_IINTERFACE_H_


#include "../UART/UART_Interface.h"


void UART_SendString(u8* Str);
void UART_SendString_Asynch(u8 *Str);
void UART_SendString_Asynch_NocodeInInt(u8 *Str);


void UART_ReceiveString(u8 *Str);
void UART_ReceiveString_NoBlock(u8 *Str);   // Receive until #
void UART_ReceiveString_Asynch(u8 *Str);


void UART_SendString_MYProtocol(u8*str);
u8 UART_ReceiveString_MyProtocol(u8*str);





#endif /* SERIVES_UART_IINTERFACE_H_ */
