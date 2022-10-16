/*
 * adc_prj.c
 *
 * Created: 8/16/2022 3:04:43 PM
 *  Author: DDOzzy
 */ 

#include "adc_prj.h"

volatile static uint8_t adc_convert_done = 1; //for inerrupt

ISR(ADC_vect){
	adc_convert_done = 1;
}


void adc_init(void){
	
	ADMUX |= (0b01 << REFS0);// select Vref= Avcc
	
	ADCSRA |= (1 << ADEN) | (1 << ADIE) | (0b111 << ADPS0); // set prescaler to 128 and enable ADC
}

void adc_pin_enable(uint8_t pin){//enable any pin analog input
	DIDR0 |= 1 << pin;
}

void adc_pin_disable(uint8_t pin){//disables to set back to digital
	DIDR0 &= ~(1 << pin);
}

void adc_pin_select(uint8_t souce){
	ADMUX &= 0xF0;// clear lower four bits
	ADMUX |= souce;
}


uint16_t adc_convert(void){
	
	uint8_t adcl = 0;//temp storage
	uint8_t adch = 0;
	
	adc_convert_done = 0; // global variable for interrupts
	
	ADCSRA |= 1 << ADSC;//start conversion
	while(adc_convert_done == 0);
	
	adcl = ADCL;
	adch = ADCH;
	
	return (adch << 8 | adcl);
	
	
}