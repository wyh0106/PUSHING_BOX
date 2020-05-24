// Copyright © 2020 魏懿航
// All rights reserved.

// filename:cp_direction.c
// description:实现针对自机控制的函数

// created by 魏懿航 at 05/19/2020
// QQ:770593981


#include "PUSH.h"
#include "CONTROL.h"

int control(void)
{
    char map_cache [100][100], key;
    int i, row = 0, Spx = spx, Spy = spy;

	memcpy(map_cache, Map, sizeof(map_cache));

	while(1)
	{
		system("cls");//显示部分
		for (; row <= mapsize; row++) 
        {
            puts(map_cache[row]);
        }
		row = 0;

        key = getch();//读取指令

        if (key == 's')//自机向下
        {
            //没有接触箱子时的向下算法
            if (GO_DOWN)
            {
                map_cache[Spx][Spy] = ' ';
                map_cache[++Spx][Spy] = 'S';
            }
            //接触箱子时的向下算法
            else if (PUSH_DOWN)
            {
                map_cache[Spx][Spy] = ' ';
                Spx += 2;
                map_cache[Spx][Spy] = 'O';
                Spx--;
                map_cache[Spx][Spy] = 'S';
            }
        }

        else if (key == 'w')//自机向下
        {
            //没有接触箱子时的向上算法
            if (GO_UP)
            {
                map_cache[Spx][Spy] = ' ';
                Spx--;
                map_cache[Spx][Spy] = 'S';

            }
            //接触箱子时的向上算法
            else if (PUSH_UP)
            {
                map_cache[Spx][Spy] = ' ';
                Spx -= 2;
                map_cache[Spx][Spy] = 'O';
                Spx++;
                map_cache[Spx][Spy] = 'S';
            }
        }

        else if (key == 'd')//自机向右
        {
            //没有接触箱子时的向右算法
            if (GO_RIGHT)
            {
                map_cache[Spx][Spy] = ' ';
                Spy++;
                map_cache[Spx][Spy] = 'S';
            }
            //接触箱子时的向右算法
            else if (PUSH_RIGHT)
            {
                map_cache[Spx][Spy] = ' ';
                Spy += 2;
                map_cache[Spx][Spy] = 'O';
                Spy--;
                map_cache[Spx][Spy] = 'S';
            }
        }

        else if (key == 'a')//自机向左
        {
            if(GO_LEFT)
			//没有接触箱子时的向左算法
            {
                map_cache[Spx][Spy] = ' ';
                Spy--;
                map_cache[Spx][Spy] = 'S';
            }
			//接触箱子时的向左算法
            else if(PUSH_LEFT)
            {
                map_cache[Spx][Spy] = ' ';
                Spy -= 2;
                map_cache[Spx][Spy] = 'O';
                Spy++;
                map_cache[Spx][Spy] = 'S';
            }
        }

		for(i=0;i<EPsize;i++)
		{//自机和箱子到达和离开*位时的变化
			if(map_cache[epx[i]][epy[i]]=='O')
				map_cache[epx[i]][epy[i]] = '@';
			if(map_cache[epx[i]][epy[i]]!='@' && map_cache[epx[i]][epy[i]]!='S')
				map_cache[epx[i]][epy[i]] = '*';
		}
		//胜利条件判定，四个胜利点必须均为@才允许胜利
		{
			int win_count = 0;
			for(i=0;i<EPsize;i++)
			{
				if(map_cache[epx[i]][epy[i]] == '@')
					win_count++;
			}
			if(win_count == EPsize)
				return WIN;
		}

		//对用户提交的特殊需求进行处理
		if(key=='B' || key=='b')
			{//退出
				return QUIT;
			}
			else if(key=='R' || key=='r')
			{//重置关卡信息
				Spx = spx, Spy = spy;
				memcpy(map_cache, Map, sizeof(map_cache));
				system("cls");
				for (; row <= mapsize; row++)
				{
					puts(map_cache[row]);
				}
				row = 0;
			}

    }

}
