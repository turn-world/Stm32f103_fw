/*
 * flash.c
 *
 *  Created on: Feb 24, 2025
 *      Author: cho00
 */
#include "flash.h"
// lib/cubef103/drivers/stm321fxx_HAL_Driver 에서 flash.h에서 확인 가능함 ex파일에서도 확인 가능

#define FLASH_SECTOR_MAX          64

typedef struct
{
  uint32_t addr;
  uint16_t length;
}flash_tbl_t;

static flash_tbl_t flash_tbl[FLASH_SECTOR_MAX];


static bool flashInSector(uint16_t sector_num, uint32_t addr, uint32_t length);
// 다른 외부에서 못쓰게 static 선언
//한꺼번에 설정 가능
bool flashInit(void)
{
  for(int i = 0; i <FLASH_SECTOR_MAX; i++)
  {
    flash_tbl[i].addr = 0x8000000 + i *1024;
    flash_tbl[i].length = 1024;
  }
  return true;

}
// 주소를 주고 첫번째 섹터부터 돌면서 포함하고 있는지 돌려주는 함수
bool flashErase(uint32_t addr, uint32_t length)
{
  bool ret = false;

  HAL_StatusTypeDef status;
  FLASH_EraseInitTypeDef init;
  uint32_t page_error;

  int16_t start_sector_num = -1;
  uint32_t sector_count = 0;


  for(int i = 0; i < FLASH_SECTOR_MAX; i++)
  {
    if(flashInSector(i,addr,length) == true)
    {
      if(start_sector_num < 0)
      {
        start_sector_num = i;
      }
      sector_count++;
    }
  }

  if(sector_count > 0)
  {
    HAL_FLASH_Unlock();

    init.TypeErase  = FLASH_TYPEERASE_PAGES;
    init.Banks      = FLASH_BANK_1;
    init.PageAddress= flash_tbl[start_sector_num].addr;
      //섹터 번호를 넣는게 있고 주소를 넣는게 있음 확인 주의
    init.NbPages    = sector_count;
    status = HAL_FLASHEx_Erase(&init , &page_error);
    if(status == HAL_OK)
    {
      ret = true;
    }
    HAL_FLASH_Lock();
  }

  return ret;

}
bool flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length)
{
  bool ret = true;
  HAL_StatusTypeDef status;
  // 2바이트 단위로 align된 주소에만 가능하도록
  if (addr%2 != 0)
  {
    return false;
  }

  HAL_FLASH_Unlock();

  for (int i = 0; i < length; i+=2)
  {
    uint16_t data;
    data  = p_data[i+0] << 0;
    data |= p_data[i+1] << 8;

    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, addr + i,(uint64_t)data);
    if(status != HAL_OK)
    {
      ret = false;
      break;
    }
  }
  HAL_FLASH_Lock();


  return ret;

}


bool flashRead(uint32_t addr, uint8_t *p_data, uint32_t length)
{
  bool ret = true;

  uint8_t *p_byte = (uint8_t *)addr;
  for(int i = 0; i<length; i++)
  {
    p_data[i] = p_byte[i];
  }

  return ret;
}

//지우고자하는 플래시의 시작과 길이 주소
bool flashInSector(uint16_t sector_num, uint32_t addr, uint32_t length)
{
  bool ret = false;

  uint32_t sector_start;
  uint32_t sector_end;
  uint32_t flash_start;
  uint32_t flash_end;


  sector_start  = flash_tbl[sector_num].addr;
  sector_end     = flash_tbl[sector_num].addr+ flash_tbl[sector_num].length - 1;
//실제 섹터 공간의 다음 시작주소가 되서 -1을 해줘야 함
  flash_start   = addr;
  flash_end     =addr + length -1;

  if (sector_start >= flash_start && sector_start <= flash_end)
  {
    ret = true;
  }
  if (sector_end >= flash_start && sector_end <= flash_end)
  {
    ret = true;
  }
  if (flash_start >= sector_start && flash_start <= sector_end)
  {
    ret = true;
  }
  if (flash_end >= sector_start && flash_end <= sector_end)
  {
    ret = true;
  }
  return ret;
}
