/*
 * UART.c
 *
 * Created: 6/13/2021 10:36:42 AM
 *  Author: Rateb
 */ 

#include "UART.h"

void UART_Init(void)
{
	uint32 UBRR_Val = 0;
	/* TX Pin as output*/
	SET_BIT(DDRD , 1);
	/* Rx Pin as input*/
	CLR_BIT(DDRD , 0);
	/*enable UART transmitter*/
	SET_BIT(UCSRB , 3);
	
	/*enable UART reciever*/
	SET_BIT(UCSRB , 4);
	
	/* no parity, 8bit data, 1Stop bit*/
	UCSRC =0x86 ;
	
	
	UBRR_Val =((160000) / (16*96)) -1;
	
	UBRRL = UBRR_Val;
	
	
	
	
}

void UART_Tx(uint8 data)
{
    UDR = data;
	while(GET_BIT(UCSRA,5) ==0);
	
	
}

void UART_TxString(uint8* str)
{
	uint8 i=0;
	while(str[i] != '\0')
	{
		UART_Tx(str[i]);
		i++;
	}
	
}

uint8 UART_Rx(void)
{
	while(GET_BIT(UCSRA,7) == 0);
	
	return UDR;
}