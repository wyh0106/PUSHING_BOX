

#include "CONTROL.h"
#include "PUSH.h"

void _s()
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

void _w()//自机向上
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

void _d()//自机向右
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

void _a()//自机向左
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