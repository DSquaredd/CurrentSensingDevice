/*
 * ADCAtmega.c
 *
 * Created: 8/16/2022 3:03:16 PM
 * Author : DDOzzy
 */ 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "uart_Prj.h"
#include "adc_prj.h"



 uint8_t print_buffer[64] = {0};
		
//char i;
//int row=1,col=1;


int main(void)
{
	const uint8_t start[] = "\n\rProgram start\n\r";
	//uint8_t run = 0;
	uint16_t convert = 0;//store conversion value

    DDRC |= (1 << PC5);// led register
	

		
		uart_init(9600,0);// boud rate 9600 with no high speed
		adc_init();
		adc_pin_enable(ADC0_PIN);
		adc_pin_select(ADC0_PIN);
		


	sei(); // uart interrupt will not loop if on  
	uart_send_string((uint8_t*)start);
    while (1) 
    {
		PORTC |= (1 << PC5);//led on
		convert = adc_convert();
		float volts =  ADC_VOLT(convert);
		float current = ADC_CURR(convert);
		

		
		memset(print_buffer,0,sizeof(print_buffer));
		sprintf((char*)print_buffer,"LED probe: V:%0.2f A:%0.4f\r",volts,current);
		uart_send_string(print_buffer);
		
		//run = convert >> 2;// chops last two bits to display in a 8 bit port
    }
}
