#ifndef USART_H
#define	USART_H

#include "main.h"

void USART_Init(long);
char USART_ReceiveChar(void);
char USART_ReceiveChar_RCREG(void);

#define F_CPU 8000000/64
//#define Baud_value(baud_rate) (((float)(F_CPU)/(float)baud_rate)-1)
#define Baud_value (((float)(F_CPU)/(float)baud_rate)-1)

#endif	/* USART_HEADER_FILE_H */
