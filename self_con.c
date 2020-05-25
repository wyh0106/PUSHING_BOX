// Copyright © 2020 魏懿航
// All rights reserved.

// filename:cp_direction.c
// description:实现针对自机控制的函数

// created by 魏懿航 at 05/19/2020
// QQ:770593981
#include <string.h>

#include "PUSH.h"
#include "CONTROL.h"
#include "wasd.c"

int row, temp;
char key;

void wasd(void);
void print_map(void);
void reset_winpoint(void);
int conditions_of_victory(void);
void reset_checkpoint(void);

int control(void)
{
	reset_checkpoint();

	while(1)
	{
		print_map();//打印地图

		wasd();//检测用户的指令

		if(WIN == conditions_of_victory())//胜利条件判定，所有胜利点必须均为@则返回胜利
			return WIN;

		//对用户提交的特殊需求进行处理
		if(key=='B' || key=='b')//退出
			return QUIT;
		else if(key=='R' || key=='r')
			reset_checkpoint();
    }
}


//输出地图信息
void print_map()
{
	system("cls");//刷新屏幕
	for (row = 0; row <= checkpoint_info.mapsize; row++) 
    {//逐行打印缓存的地图
        puts(map_cache[row]);
    }
	row = 0;
}

//读取并对用户指令做出响应
void wasd()
{
	key = getch();//读取指令

	//判断用户输入的是上下左右中的哪一个
	if(key=='w' || key=='W')
		_w();

	else if(key=='a' || key=='A')
		_a();

	else if(key=='s' || key=='S')
		_s();

	else if(key=='d' || key=='D')
		_d();
	
	reset_winpoint();//移动完之后进行一次胜利点检查来恢复*
}

//重置胜利点*
void reset_winpoint()
{//在自机和箱子离开胜利点后，将胜利点恢复成*
	for(temp = 0;temp<checkpoint_info.EPsize;temp++)
	{
		if( map_cache[checkpoint_info.epx[temp]][checkpoint_info.epy[temp]]=='O')
			map_cache[checkpoint_info.epx[temp]][checkpoint_info.epy[temp]]= '@';
		if( map_cache[checkpoint_info.epx[temp]][checkpoint_info.epy[temp]]!='@' && map_cache[checkpoint_info.epx[temp]][checkpoint_info.epy[temp]]!='S')
			map_cache[checkpoint_info.epx[temp]][checkpoint_info.epy[temp]]= '*';
	}
}

//胜利条件判断
int conditions_of_victory()
{
	int win_count = 0;
	for(temp=0;temp<checkpoint_info.EPsize;temp++)
	{
		if(map_cache[checkpoint_info.epx[temp]][checkpoint_info.epy[temp]] == '@')
			win_count++;
	}
	if(win_count == checkpoint_info.EPsize)
		return WIN;
}

//重置关卡信息
void reset_checkpoint()
{
	Spx = checkpoint_info.spx, Spy = checkpoint_info.spy;
	memcpy(map_cache, checkpoint_info.Map, sizeof(map_cache));
	print_map();
}