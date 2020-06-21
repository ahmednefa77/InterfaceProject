/*
 * SPI.c
 *
 * Created: 6/21/2020 2:14:49 PM
 *  Author: Ahmed
 */
#define MOSI	5
#define MISO	6
#define SCK		7
#define CS		0
#define LED0	2

 
#include <avr/io.h>
#include <avr/interrupt.h>

void SPI_Init(){
	//data direction for SPI bus Pins
	DDRB|=(1<<MOSI)|(1<<SCK);
	DDRC|=(1<<CS)|(1<<LED0);
	//MODE0-CPOL=0 CPHA=0 , SPE=1 , MSTR=1 DORD=MSB(0) , SPEED=FOSC/16=1Mhz
	SPCR|=(1<<MSTR)|(1<<SPE)|(1<<SPR0);
	//global interrupt
	//sei();
}

unsigned char SPI_Transfer(unsigned char sendByte){
	//
	SPDR=sendByte;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}
