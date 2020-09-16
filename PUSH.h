// Copyright © 2020 魏懿航
// All rights reserved.

// filename:PUSH.h
// description:Just a simple pushing box game:)

// created by 魏懿航 at 05/19/2020
// QQ:770593981

#ifndef _PUSH__H
#define _PUSH__H

#include "cJSON\cJSON.h"

// 声明返回信息含义
#define RF_FAULT -1
#define EM_FAULT -2
#define PUSH_NULL 0
#define QUIT 2

// 关卡资源文件地址
#define CP "resource\\CP_INFO.json"
#define BUFSIZE 256

cJSON *root, *checkpoint, *map,
*self_position, *end_position,
*mapline;

// 用于缓存关卡资源信息的变量
struct checkpoint
{
	int epx[10], epy[10], spx, spy;// 终点坐标，自机坐标
	int mapsize, EPsize;// 地图列数，终点个数
	char Map[100][100];// 用于缓存地图的二维数组
	char cp_number[13];// 转译关卡名的字符串数组
}checkpoint_info;

// 声明功能函数
extern int get_info(char checkpoint);// 获取关卡信息函数
extern int cp_transform(char _checkpoint);// 关卡名转译函数
extern int control(void);// 自机控制函数
extern void UI(int UI_type);//UI界面

#endif