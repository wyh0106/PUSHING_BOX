// Copyright © 2020 魏懿航
// All rights reserved.

// filename:get_cp_info.c
// description:从关卡资源文件中获取关卡信息

// created by 魏懿航 at 05/19/2020
// QQ:770593981

#include "cJSON\cJSON.h"
#include "cJSON\cJSON.c"

#include "PUSH.h"

int get_info(int checkpoint_ID)
{
    FILE *level_INFO;

    char buf[256], cp[2048]={0};//初始化可能用到的变量

    if(EM_FAULT == cp_transform(checkpoint_ID))//将关卡id转换成对应关卡的键
    {//非法关卡号码处理
        printf("Please entered currect level number.");
        return EM_FAULT;
    }

    level_INFO = fopen(CP, "r");//打开关卡信息文件
    if(NULL == level_INFO)//文件打开失败反馈
    {
        printf("FILE OPEN FAULT!");
        return RF_FAULT;
    }

    while(fgets(buf, BUFSIZE, level_INFO))//把关卡信息文件字符串化，以便后续解析
        strcat(cp,buf);

    cJSON *root = NULL, *checkpoint = NULL, *map = NULL,
          *self_position = NULL, *end_position = NULL,
          *mapline = NULL, *ep = NULL, *ep_v = NULL;//初始化cJSON变量
    root = cJSON_Parse(cp);//解析json文本
    if(!root)//异常处理，返回错误代码
        printf("Error before: [%s]\n", cJSON_GetErrorPtr());

    else
    {
        checkpoint = cJSON_GetObjectItem(root, cp_number);
        map = cJSON_GetObjectItem(checkpoint, "map");
        self_position = cJSON_GetObjectItem(checkpoint, "self_position");
        end_position = cJSON_GetObjectItem(checkpoint, "end_position");
        //逐级解析关卡信息

        //从关卡信息中获取地图信息，并保存到Map二维数组中
        int temp = 0;
        mapsize = cJSON_GetArraySize(map);
        for(; temp < mapsize; temp++)
        {
            mapline = cJSON_GetArrayItem(map, temp);
            strcpy(Map[temp], mapline->valuestring);
        }

        //从关卡信息中获取自机位置并保存到spx和spy中
        spx = (cJSON_GetArrayItem(self_position, 0))->valueint;
        spy = (cJSON_GetArrayItem(self_position, 1))->valueint;

        //从关卡信息中获取终点位置并保存到epx和epy数组中
        EPsize = cJSON_GetArraySize(end_position);
        for(temp = 0; temp < EPsize; temp++)
        {
            ep = cJSON_GetArrayItem(end_position, temp);
            ep_v = cJSON_GetArrayItem(ep, 0);
            epx[temp] = ep_v->valueint;
            ep_v = cJSON_GetArrayItem(ep, 1);
            epy[temp] = ep_v->valueint;
        }

    }

    return 0;
}