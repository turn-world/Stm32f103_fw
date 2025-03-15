/*
 * flash.h
 *
 *  Created on: Feb 24, 2025
 *      Author: cho00
 */

#ifndef SRC_COMMON_HW_FLASH_H_
#define SRC_COMMON_HW_FLASH_H_

#include "hw_def.h"

#ifdef  _USE_HW_FLASH

bool flashInit(void);
bool flashErase(uint32_t addr, uint32_t length);
bool flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length);
bool flashRead(uint32_t addr, uint8_t *p_data, uint32_t length);





#endif

#endif /* SRC_COMMON_HW_FLASH_H_ */
