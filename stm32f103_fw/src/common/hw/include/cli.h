/*
 * cli.h
 *
 *  Created on: 2020. 12. 19.
 *      Author: baram
 */

#ifndef SRC_COMMON_HW_INCLUDE_CLI_H_
#define SRC_COMMON_HW_INCLUDE_CLI_H_


#include "hw_def.h"


#ifdef _USE_HW_CLI

#define CLI_CMD_LIST_MAX      HW_CLI_CMD_LIST_MAX			// 추가하고자 하는 명령의 갯수			16개
#define CLI_CMD_NAME_MAX      HW_CLI_CMD_NAME_MAX			// 명령어 하나당 몇자까지 허용할 것 이냐	15글자

#define CLI_LINE_HIS_MAX      HW_CLI_LINE_HIS_MAX
#define CLI_LINE_BUF_MAX      HW_CLI_LINE_BUF_MAX



//명령어 하나당 함수 하나
typedef struct
{
  uint16_t   argc;			// argument의 갯수
  char     **argv;			// argument의 문자열 첫번째 문자열 두번째 문자열

  int32_t  (*getData)(uint8_t index);		// 정수
  float    (*getFloat)(uint8_t index);		// 실수
  char    *(*getStr)(uint8_t index);		// string
  bool     (*isStr)(uint8_t index, char *p_str);	// 입력된 파라미터의 문자열이 존재하느냐
} cli_args_t;
//argument를 넣게 되면 폴더에 접근해서 바로 볼 수가 있어서 좀 더 편함
// 16byte를 먹음 추가로

bool cliInit(void);
bool cliOpen(uint8_t ch, uint32_t baud);
bool cliOpenLog(uint8_t ch, uint32_t baud);
bool cliMain(void);
void cliPrintf(const char *fmt, ...);							//CLI명령어 창에 출력
bool cliAdd(const char *cmd_str, void (*p_func)(cli_args_t *));	// 명령어를 추가하는 문자열 함수 추가기능
bool cliKeepLoop(void);											// while loop


#endif

#endif /* SRC_COMMON_HW_INCLUDE_CLI_H_ */
