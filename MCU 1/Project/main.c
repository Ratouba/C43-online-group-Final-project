/*
 * Project.c
 *
 * Created: 6/13/2021 10:34:06 AM
 * Author : Rateb
 */ 

#include "UART.h"
#include "DIO.h"
#include "SPI.h"

#define F_CPU  16000000
#include <util/delay.h>


int main(void)
{
   
	uint8 tx_data={'a','b','c','d'};
	
	uint8 rx_data=0;
	
	
	/*initialise USART with 9600 baud rate*/
	UART_Init();
	SPI_Master_Init();
	SPI_Master_InitTrans();
	_delay_ms(1000);
	
	 while (1) 
    {
		
		tx_data =UART_Rx(); /*receive data from Bluetooth*/
		rx_data=SPI_Tranceiver(tx_data);
		if(rx_data==0)
		{
			
		}
		_delay_ms(1000);
		
		
    }
}

