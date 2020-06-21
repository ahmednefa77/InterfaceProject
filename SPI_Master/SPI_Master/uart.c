/*
 * uart.c
 *
 * Created: 6/21/2020 11:10:57 AM
 *  Author: Ahmed
 */
#define F_CPU	16000000
#include <avr/io.h>
 
#define BAUD   9600
#define BAUD_EQ		((F_CPU/(BAUD*16UL))-1)

void uartInit(){
	//Select Baud Rate
	UBRRL=BAUD_EQ;
	//Enable RX and TX
	UCSRB =(1<<RXEN)|(1<<TXEN);
	//select frame size and number of stop bits
	UCSRC=(1<<7)|(1<<1) | (1<<2);
}

void uartSend(char data){
	
	while( !(UCSRA & (1<<UDRE)));
	UDR=data;
}

unsigned char uartReceive(){
	while( !(UCSRA & (1<<RXC)));
	return UDR;
}
void uart_sendString(char *str){
	char i=0;
	while(str[i]!='\0'){
		uartSend(str[i]);
		i++;
	}
}
