/*
 * hw.c
 *
 *  Created on: Aug 22, 2024
 *      Author: cho00
 */


#include "hw.h"



// 모듈을 만든후 쓰기 위해 추가
void hwInit(void)
{
  bspInit();
  rtcInit();

  resetInit();
  ledInit();
  usbInit();
  uartInit();
  flashInit();


}
