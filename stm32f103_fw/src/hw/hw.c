/*
 * hw.c
 *
 *  Created on: Aug 22, 2024
 *      Author: cho00
 */


#include "hw.h"




void hwInit(void)
{
  bspInit();
  rtcInit();

  resetInit();
  ledInit();
  usbInit();
  uartInit();
}
