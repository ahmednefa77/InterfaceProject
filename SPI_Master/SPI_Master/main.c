/*
 * SPI_Master.c
 *
 * Created: 5/2/2020 2:33:16 PM
 * Author : Mohamed
 
 *LAB01-SPI
 *Requirements:
 *Configure SPI in MODE 0 and with 1Mhz Speed
 *MSB as a data order
 *Polling Mode
 */ 


#define F_CPU	16000000
#include <util/delay.h>
#include <avr/io.h>

#define SS_ENABLE()		PORTC&=~(1<<0)
#define SS_DISABLE()	PORTC|=(1<<0)

//we used these functions
void SPI_Init();
unsigned char SPI_Transfer(unsigned char sendByte);
void uartInit();
void uartSend(char data);


int main(void)
{
    SPI_Init();
	uartInit();
    while (1) 
    {
		 SS_ENABLE();
		unsigned char data=uartReceive();
		 _delay_ms(30);
		 
		unsigned char recvByte=SPI_Transfer(data);
		SS_DISABLE();
		_delay_ms(100);
		
    }
}
