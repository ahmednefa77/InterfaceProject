/*
 * SPI_Mstr.c
 *
 * Created: 5/2/2020 10:36:27 AM
 * Author : infin
 */ 

#define MISO	6
#define SCK		7
#define LED0	2
#define F_CPU		16000000


#include <util/delay.h>
#include <avr/io.h>

void SPI_Init(){
	SPCR=(1<<SPE);
	// Set MOSI, SCK as Output
	DDRB|=(1<<MISO);
	
	 
}
unsigned char SPI_Transfer(unsigned char sendByte){
	
	 SPDR=sendByte;
	while(!(SPSR&(1<<SPIF)));//if interrupt flag is not set loop(read
 
	return SPDR;
}

int main(void)
{ 
	SPI_Init();
	
	DDRC|=0b10000111;
    while (1) 
    {
	unsigned char recvByte=SPI_Transfer('2');	
		
		switch (recvByte)
		{
			case '1':PORTC^=(1<<0);break;
			case '2':PORTC^=(1<<1);break;
			case '3':PORTC^=(1<<2);break;
			case '7':PORTC^=(1<<7);break;
		};
		_delay_ms(100);
    }//while
}//main

