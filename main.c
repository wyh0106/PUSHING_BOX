// Copyright © 2020 魏懿航
// All rights reserved.

// filename:main.c
// description:Just a simple pushing box game:)

// created by 魏懿航 at 05/19/2020
// QQ:770593981

#include <stdio.h>
#include <windows.h>

#include "PUSH.h"
#include "get_cp_info.c"
#include "cp_direction.c"
#include "self_con.c"

int main(void)
{
    int temp = 0, error_massage, CP_NUMBER;

    //输入对应关卡
    record_level:
    printf("Please enter what level you want to play:");
    scanf("%d", &CP_NUMBER);

    //错误代码处理，如为0则正常运行
    error_massage = get_info(CP_NUMBER);
    switch(error_massage)
    {
        case -2:printf("Unknown mistake!\nCheck the function: get_info.\n");
                goto record_level;// 回到关卡选择

        case -1:printf("Ensure the resource file are legal.");
                return -1;

        case 0: printf("Loading resource file succeessful.\n");
                break;
    }

    control();

    //调试用信息输出
    //---------------------------
    // for(; temp < mapsize; temp++)
    // {
    //     puts(Map[temp]);
    // }

    // printf("%d,%d\n\n", spx, spy);
    // for(temp = 0; temp < EPsize; temp++)
    // {
    //     printf("%d %d\n", epx[temp], epy[temp]);
    // }
    //---------------------------

    return 0;
}