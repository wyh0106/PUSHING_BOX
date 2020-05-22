// Copyright © 2020 魏懿航
// All rights reserved.

// filename:PUSH.h
// description:Just a simple pushing box game:)

// created by 魏懿航 at 05/19/2020
// QQ:770593981

#ifndef _PUSH__H
#define _PUSH__H

// 声明返回信息含义
#define RF_FAULT -1
#define EM_FAULT -2
#define PUSH_NULL 0
#define WIN 1
#define QUIT 2

// 关卡资源文件地址
#define CP "resource\\CP_INFO.json"
#define BUFSIZE 256

// 用于缓存关卡资源信息的变量
int epx[10], epy[10], spx, spy;// 终点坐标，自机坐标
int mapsize, EPsize;// 地图列数，终点个数
char Map[100][100];// 用于缓存地图的二维数组
char cp_number[13];// 转译关卡名的字符串数组

// 声明功能函数
extern int get_info(int checkpoint);// 获取关卡信息函数
extern int cp_transform(int _checkpoint);// 关卡名转译函数
extern int control(void);// 自机控制函数

#endif