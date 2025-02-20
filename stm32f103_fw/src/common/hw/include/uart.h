/*
 * uart.h
 *
 *  Created on: Jan 8, 2025
 *      Author: cho00
 */

#ifndef SRC_COMMON_HW_INCLUDE_UART_H_
#define SRC_COMMON_HW_INCLUDE_UART_H_

#include "hw_def.h"

#ifdef _USE_HW_UART

#define UART_MAX_CH           HW_UART_MAX_CH


bool uartInit(void);
bool uartOpen(uint8_t ch,uint32_t baud);
uint32_t uartAvailable(uint8_t ch);
uint8_t uartRead(uint8_t ch);
uint32_t uartWrite(uint8_t ch, uint8_t *p,uint32_t length);
uint32_t uartPrintf(uint8_t ch, char *fmt, ...);
uint32_t uartGetBaud(uint8_t ch);
#endif

#endif /* SRC_COMMON_HW_INCLUDE_UART_H_ */
