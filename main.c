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
#include "get_cp_info.c"
#include "cp_direction.c"
#include "self_con.c"

int main(void)
{
    int Key, li, error_massage, CP_NUMBER;

    //输入对应关卡
	while(li != QUIT)
	{
		printf("\nPlease enter what level you want to play:");
		scanf("%d", &CP_NUMBER);

		//错误代码处理，为0则正常运行
		error_massage = get_info(CP_NUMBER);
		switch(error_massage)
		{
			case -2:printf("Unknown mistake!\nCheck the function: get_info.\n");
					return -1;
			case -1:printf("Ensure the resource file are legal.");
					return -1;
			case  0:printf("Loading resource file succeessful.\n");
					li = QUIT;//只有正常运行才不会重复请求输入关卡号码
					break;
		}
	}

	//自机控制
	Key = control();
	//胜利条件检测及胜利界面打印
	if(Key == WIN)
	{
		system("cls");
		puts("==========");
		puts(" YOU WIN!");
		puts("==========");
	}

	system("pause");

    return 0;
}