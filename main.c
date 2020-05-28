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

#include "PUSH.h"
#include "CONTROL.h"
#include "get_cp_info.c"
#include "cp_direction.c"
#include "self_con.c"
#include "UI.c"

#define SELECT 0

int main(void)
{
    int li, error_massage;
	char Key;

	do
	{
		UI(SELECT);
		//输入对应关卡
		reset:
		Key = getch();
		if('Q'==Key || 'q'==Key)
			return 0;

		if(Key!='1' && Key!='2' && Key!='3')
			goto reset;

		//错误代码处理，为0则正常运行
		error_massage = get_info(Key);
		switch(error_massage)
		{
			case -2:printf("\nUnknown mistake!\nCheck the function: get_info.\n");
					return -1;
			case -1:printf("\nEnsure the resource file are legal.");
					return -1;
			case  0:li = QUIT;//只有正常运行才不会重复请求输入关卡号码
					break;
		}
		//自机控制
		Key = control();
		//胜利条件检测及胜利界面打印
		if(Key == WIN)
		{
			UI(WIN);
			system("pause");
		}
	}while(key);

	system("pause");
	return 0;
}