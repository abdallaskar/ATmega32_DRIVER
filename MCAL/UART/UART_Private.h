/*
 * Title      : UART_DRIVER
 * File Name  : UART_Private.h
 * Author     : abdalla
 * Created on : Mar 17, 2022
 */

#ifndef UART_UART_PRIVATE_H_
#define UART_UART_PRIVATE_H_


#define UBRRL       *(( volatile u8*)(0x29))
#define UCSRB       *(( volatile u8*)(0x2a))
#define UCSRA       *(( volatile u8*)(0x2b))
#define UDR         *(( volatile u8*)(0x2c))
#define UBRRH       *(( volatile u8*)(0x40))
#define UCSRC       *(( volatile u8*)(0x40))

/* USART Register C */

#define    UMSEL        6
#define    UPM1         5
#define    UPM0         4
#define    USBS         3
#define    UCSZ1        2
#define    UCSZ0        1
#define    UCPOL        0

/* USART Status Register A  */
#define    RXC          7
#define    TXC          6
#define    UDRE         5
#define    FE           4
#define    DOR          3
#define    UPE          2
#define    U2X          1
#define    MPCM         0

/* USART Control Register B  */

#define    RXCIE        7
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    UCSZ         2
#define    UCSZ2        2
#define    RXB8         1
#define    TXB8         0


#endif /* UART_UART_PRIVATE_H_ */
