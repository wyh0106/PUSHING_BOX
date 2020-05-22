// Copyright © 2020 魏懿航
// All rights reserved.

// filename:cp_direction.c
// description:Just a simple pushing bospx game:)

// created by 魏懿航 at 05/19/2020
// QQ:770593981

#include "PUSH.h"
#include "CONTROL.h"

int control(void)
{
    char map_cache [100][100], key;
    int i, row = 0, Spx = spx, Spy = spy;

	memcpy(map_cache, Map, sizeof(map_cache));

	while(TRUE)
	{
		system("cls");//显示部分
		for (; row <= mapsize; row++) 
        {
            puts(map_cache[row]);
        }
		row = 0;

        key = getch();//从用户处读入一个指令

        if (key == 's')//小人向下
        {
            //不推箱子时实现向下
            if (GO_DOWN)
            {
                map_cache[Spx][Spy] = ' ';
                map_cache[++Spx][Spy] = 'S';
            }
            //推箱子时执行实现向下
            else if (PUSH_DOWN)
            {
                map_cache[Spx][Spy] = ' ';
                Spx += 2;
                map_cache[Spx][Spy] = 'O';
                Spx--;
                map_cache[Spx][Spy] = 'S';
            }
        }

        else if (key == 'w')//小人向上 
        {
            //不推箱子的时候实现向上 
            if (GO_UP)
            {
                map_cache[Spx][Spy] = ' ';
                Spx--;
                map_cache[Spx][Spy] = 'S';

            }
            //推箱子的时候实现向上
            else if (PUSH_UP)
            {
                map_cache[Spx][Spy] = ' ';
                Spx -= 2;
                map_cache[Spx][Spy] = 'O';
                Spx++;
                map_cache[Spx][Spy] = 'S';
            }
        }

        else if (key == 'd')
        {
            //不推箱子实现向右
            if (GO_RIGHT)
            {
                map_cache[Spx][Spy] = ' ';
                Spy++;
                map_cache[Spx][Spy] = 'S';
            }
            //推箱子时实现向右
            else if (PUSH_RIGHT)
            {
                map_cache[Spx][Spy] = ' ';
                Spy += 2;
                map_cache[Spx][Spy] = 'O';
                Spy--;
                map_cache[Spx][Spy] = 'S';
            }
        }

        else if (key == 'a')
        {
            if(GO_LEFT)//下一位置无箱子
            {
                map_cache[Spx][Spy] = ' ';
                Spy--;
                map_cache[Spx][Spy] = 'S';
            }
            else if(PUSH_LEFT)//下一位置存在箱子
            {
                map_cache[Spx][Spy] = ' ';
                Spy -= 2;
                map_cache[Spx][Spy] = 'O';
                Spy++;
                map_cache[Spx][Spy] = 'S';
            }
        }

		for(i=0;i<EPsize;i++)
		{//自机和箱子到达*点的时候的控制
			if(map_cache[epx[i]][epy[i]]=='O')
				map_cache[epx[i]][epy[i]] = '@';
			if(map_cache[epx[i]][epy[i]]!='@' && map_cache[epx[i]][epy[i]]!='S')
				map_cache[epx[i]][epy[i]] = '*';
		}

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


		if(key=='B' || key=='b')
			{//退出
				return QUIT;
			}
			else if(key=='R' || key=='r')
			{//重新开始
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
