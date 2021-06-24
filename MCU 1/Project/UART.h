/*
 * UART.h
 *
 * Created: 6/13/2021 10:37:00 AM
 *  Author: Rateb
 */ 


#ifndef UART_H_
#define UART_H_

#include "MCU.h"
#include "STD.h"
#include "BIT_Math.h"


void UART_Init(void);

void UART_Tx(uint8 data);

void UART_TxString(uint8* str);

uint8 UART_Rx(void);






#endif /* UART_H_ */