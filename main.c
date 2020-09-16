// Copyright © 2020 魏懿航
// All rights reserved.

// filename:main.c
// description:Just a simple pushing box game:)

// created by 魏懿航 at 05/19/2020
// QQ:770593981

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "cJSON\cJSON.h"

#include "PUSH.h"
#include "CONTROL.h"
#include "get_cp_info.c"
#include "cp_direction.c"
#include "self_con.c"
#include "UI.c"

#define SELECT 0

int main(void)
{
    int count = 0, error_massage;
	char level = 2;

	// system("pause");

	while(level)
	{
		// if(count>=1)
		// {
		// 	printf("");
		// }
		UI(SELECT);
		//输入对应关卡
		reset:
		level = getch();
		if('Q'==level || 'q'==level)
			return 0;

		if(level!='1' && level!='2' && level!='3')
			goto reset;

		//错误代码处理，为0则正常运行
		error_massage = get_info(level);
		switch(error_massage)
		{
			case -2:printf("\nUnknown mistake!\nCheck the function: get_info.\n");
					return -1;
			case -1:printf("\nEnsure the resource file are legal.");
					return -1;
			case  0:level = QUIT;//只有正常运行才不会重复请求输入关卡号码
					break;
		}
		//自机控制
		level = control();
		//胜利条件检测及胜利界面打印
		if(level == WIN)
		{
			UI(WIN);
			cJSON_Delete(root);
			cJSON_Delete(checkpoint);
			cJSON_Delete(map);
			cJSON_Delete(mapline);
			cJSON_Delete(self_position);
			cJSON_Delete(end_position);
			system("pause");
		}
		// count++;
	}

	system("pause");
	return 0;
}