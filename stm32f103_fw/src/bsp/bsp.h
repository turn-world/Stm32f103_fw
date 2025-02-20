/*
 * bsp.h
 *
 *  Created on: Aug 22, 2024
 *      Author: cho00
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_

#include "def.h"


#include "stm32f1xx_hal.h"


void bspInit(void);

void delay(uint32_t ms);
uint32_t millis(void);

void Error_Handler(void);
#endif /* SRC_BSP_BSP_H_ */
