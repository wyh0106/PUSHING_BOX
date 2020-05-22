// Copyright © 2020 魏懿航
// All rights reserved.

// filename:cp_direction.c
// description:Just a simple pushing box game:)

// created by 魏懿航 at 05/19/2020
// QQ:770593981

#include <stdio.h>
#include <string.h>

#include "PUSH.h"

#define cp_ "checkpoint_"

int cp_transform(int _checkpoint)
{
    switch(_checkpoint)
    {
        case 1: strcat(cp_number, cp_);
                strcat(cp_number, "1");
                break;
        case 2: strcat(cp_number, cp_);
                strcat(cp_number, "2");
                break;
        case 3: strcat(cp_number, cp_);
                strcat(cp_number, "3");
                break;
        case 4: strcat(cp_number, cp_);
                strcat(cp_number, "4");
                break;
        case 5: strcat(cp_number, cp_);
                strcat(cp_number, "5");
                break;
        case 6: strcat(cp_number, cp_);
                strcat(cp_number, "6");
                break;
        case 7: strcat(cp_number, cp_);
                strcat(cp_number, "7");
                break;
        case 8: strcat(cp_number, cp_);
                strcat(cp_number, "8");
                break;
        default: return EM_FAULT;
    }
    
}