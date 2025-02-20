/*
 * ap.c
 *
 *  Created on: Aug 22, 2024
 *      Author: cho00
 */


#include "ap.h"



void apInit(void)
{
  uartOpen(_DEF_UART1, 57600); // USB
  uartOpen(_DEF_UART2, 57600); // UART USB속도가 바뀌면 UART도 바뀌어야함
}

void apMain(void)
{
  uint32_t pre_time;
  uint8_t rx_buf[128];
  uint32_t rx_len;

  pre_time= millis();
  while(1)
  {
    if(millis() - pre_time >= 500)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }
    if(uartGetBaud(_DEF_UART1) != uartGetBaud(_DEF_UART2))
    {
      uartOpen(_DEF_UART2, uartGetBaud(_DEF_UART2)); // 물리적인 uart를 재 오픈 usb통신 속도로
    }
    //USB -> UART로 보내는 것
    rx_len = uartAvailable(_DEF_UART1);
    if(rx_len > 128)
    {
      rx_len = 128;
    }
    if(rx_len > 0)
    {
      for (int i=0; i<rx_len ; i++)
      {
        rx_buf[i] = uartRead(_DEF_UART1);
      }
      uartWrite(_DEF_UART2,rx_buf, rx_len);
    }
    //UART -> USB
    rx_len = uartAvailable(_DEF_UART1);
        if(rx_len > 128)
        {
          rx_len = 128;
        }
        if(rx_len > 0)
        {
          for (int i=0; i<rx_len ; i++)
          {
            rx_buf[i] = uartRead(_DEF_UART2);
          }
          uartWrite(_DEF_UART1,rx_buf, rx_len);
        }
  }
}
