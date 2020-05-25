// Copyright © 2020 魏懿航
// All rights reserved.

// filename:cp_direction.c
// description:用来实现对关卡名转换，
// 			   转换成关卡资源文件中的键。

// created by 魏懿航 at 05/19/2020
// QQ:770593981

#include "PUSH.h"

#define cp_ "checkpoint_"

int cp_transform(int _checkpoint)
{
    switch(_checkpoint)
    {
        case 1: strcat(checkpoint_info.cp_number, cp_);
                strcat(checkpoint_info.cp_number, "1");
                break;
        case 2: strcat(checkpoint_info.cp_number, cp_);
                strcat(checkpoint_info.cp_number, "2");
                break;
        case 3: strcat(checkpoint_info.cp_number, cp_);
                strcat(checkpoint_info.cp_number, "3");
                break;
        case 4: strcat(checkpoint_info.cp_number, cp_);
                strcat(checkpoint_info.cp_number, "4");
                break;
        case 5: strcat(checkpoint_info.cp_number, cp_);
                strcat(checkpoint_info.cp_number, "5");
                break;
        case 6: strcat(checkpoint_info.cp_number, cp_);
                strcat(checkpoint_info.cp_number, "6");
                break;
        case 7: strcat(checkpoint_info.cp_number, cp_);
                strcat(checkpoint_info.cp_number, "7");
                break;
        case 8: strcat(checkpoint_info.cp_number, cp_);
                strcat(checkpoint_info.cp_number, "8");
                break;
        default: return EM_FAULT;
    }
    
}