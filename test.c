#include <stdio.h>

#include "cJSON\\cJSON.h"
#include "cJSON\\cJSON.h"

#include "resource\\CP_INFO.json"

#define BUFSIZE 1024

void main(void)
{
    FILE *level_INFO;
	char buf[256], cp[2048]={0};

    cJSON *root = NULL, *checkpoint = NULL, *map = NULL,
        *self_position = NULL, *end_position = NULL,
		*mapline = NULL, *ep = NULL, *ep_v = NULL;//初始化cJSON变量

	level_INFO = fopen("resource\\CP_INFO.json", "r");//打开关卡信息文件
    if(NULL == level_INFO)//文件打开失败反馈
    {
        printf("FILE OPEN FAULT!");
        return -1;
    }

    while(fgets(buf, BUFSIZE, level_INFO))//把关卡信息文件字符串化，以便后续解析
        strcat(cp,buf);
    root = cJSON_Parse(cp);//解析json文本
    if(!root)//异常处理，返回错误代码
        printf("Error before: [%s]\n", cJSON_GetErrorPtr());

        checkpoint = cJSON_GetObjectItem(root, "chekpoint_1");
        map = cJSON_GetObjectItem(checkpoint, "map");
        self_position = cJSON_GetObjectItem(checkpoint, "self_position");
        end_position = cJSON_GetObjectItem(checkpoint, "end_position");
        //逐级解析关卡信息
		checkpoint = cJSON_GetObjectItem(root, "checkpoint_2");
        map = cJSON_GetObjectItem(checkpoint, "map");
        self_position = cJSON_GetObjectItem(checkpoint, "self_position");
        end_position = cJSON_GetObjectItem(checkpoint, "end_position");
}