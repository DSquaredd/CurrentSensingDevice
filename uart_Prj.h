/*
 * uart_Prj.h
 *
 * Created: 8/15/2022 1:06:33 PM
 *  Author: DDOzzy
 */ 


#ifndef UART_PRJ_H_
#define UART_PRJ_H_



#include <stdint.h>
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define RX_BUFFER_SIZE 128 // 128 byte buffer 

void uart_init(uint32_t baud, uint8_t high_speed);
void uart_send_byte(uint8_t c);
void uart_send_array(uint8_t *c, uint16_t len);
void uart_send_string(uint8_t *c);
uint16_t uart_read_count(void);
uint8_t uart_read(void);


#endif /* UART_PRJ_H_ */