/*
 * Title      : UART_DRIVER
 * File Name  : UART_Interface.h
 * Author     : abdalla
 * Created on : Mar 17, 2022
 */

#ifndef UART_UART_INTERFACE_H_
#define UART_UART_INTERFACE_H_




void UART_Init(void);

void UART_SendByte(u8 data);
u8 UART_ReceiveByte(void);
u8 UART_Receive_NoBlock(u8* pdata);





void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);

void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);

void UART_RX_SetCallBack(void (*LocalFptr)(void));
void UART_TX_SetCallBack(void (*LocalFptr)(void));





void UART_SendByteNoBlock(u8 data);
u8 UART_ReceiveByteNoBlock(void);

/****************	Interrupt Vectors Table For Timer 1		*******************/

#define USART_RXC_vect         __vector_13
#define USART_UDRE_vect        __vector_14
#define USART_TXC_vect         __vector_15


/****************   Interrupt Function  ISR  **********************************/
#define ISR(vector,...)  \
void vector (void) __attribute__ ((signal)) __VA_ARGS__ ; \
void vector (void)





#endif /* UART_UART_INTERFACE_H_ */
