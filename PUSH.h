// Copyright © 2020 魏懿航
// All rights reserved.

// filename:PUSH.h
// description:Just a simple pushing box game:)

// created by 魏懿航 at 05/19/2020
// QQ:770593981

#ifndef _PUSH__H
#define _PUSH__H

#define RF_FAULT -1
#define EM_FAULT -2
#define PUSH_NULL 0

#define CP "resource\\CP_INFO.json"
#define BUFSIZE 256

int epx[10], epy[10], spx, spy;
int mapsize, EPsize;
char Map[100][100];
char cp_number[13] = {0};

extern int get_info(int checkpoint);
extern int cp_transform(int _checkpoint);
extern void control(void);


#endif