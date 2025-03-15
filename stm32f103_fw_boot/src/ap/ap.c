/*
 * ap.c
 *
 *  Created on: Aug 22, 2024
 *      Author: cho00
 */


#include "ap.h"



void apInit(void)
{
}

void apMain(void)
{
  uint32_t pre_time;

  pre_time= millis();
  while(1)
  {
    // led 깜빡 거리기
    if(millis() - pre_time >= 100)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }


  }
}
