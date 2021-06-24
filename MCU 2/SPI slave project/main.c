#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>


int main(void)
{
	uint8 tx_data=0;
	uint8 rx_data=0;
	
	DIO_SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	SPI_Slave_Init();
	
	while (1)
	{
		rx_data=SPI_Tranceiver(tx_data);
		if(rx_data=='a')
		{
			
			/* Turn On LED 0*/
			
			DIO_SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_PIN_HIGH);
			
		}
		else if(rx_data=='b')
		{
			/*turn Off LED 0*/
			DIO_SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_PIN_LOW);
		}
		else if (rx_data =='c')
		{
			/*Turn On LED 1*/
			DIO_SetPinValue(DIO_PORTC , DIO_PIN7 , DIO_PIN_HIGH);
		}
		else if (rx_data=='d')
		{
			/*Turn off LED 1*/
			DIO_SetPinValue(DIO_PORTC , DIO_PIN7 , DIO_PIN_LOW);
		}
		
	
		_delay_ms(1000);
	}

}



