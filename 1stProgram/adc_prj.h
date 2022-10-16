/*
 * adc_prj.h
 *
 * Created: 8/16/2022 3:04:15 PM
 *  Author: DDOzzy
 */ 


#ifndef ADC_PRJ_H_
#define ADC_PRJ_H_


#include <stdint.h>
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define ADC_VOLT(x) (x + 4.00)
#define ADC_CURR(x) (x * (5.000/1074.000))

enum{
	ADC0_PIN,
	ADC1_PIN,
	ADC2_PIN,
	ADC3_PIN,
	ADC4_PIN,
	ADC5_PIN,
	ADC6_PIN,
	ADC7_PIN,
	ADC8_TEMPERATURE,
	ADC_1V1 = 0b1110,
	ADC_GND,
};


void adc_init(void);
void adc_pin_enable(uint8_t pin);
void adc_pin_disable(uint8_t pin);
void adc_pin_select(uint8_t souce);
uint16_t adc_convert(void);


#endif /* ADC_PRJ_H_ */