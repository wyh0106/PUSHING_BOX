/* 
这个部分被用来定义控制部分中的条件判断。
包括推箱子中和普通行动两种判断。
*/
#ifndef _CONTROL__H
#define _CONTROL__H

#define GO_DOWN map_cache[Spx+1][Spy]!='#' && map_cache[Spx+1][Spy]!='O' && map_cache[Spx+1][Spy]!='@'
#define GO_UP map_cache[Spx-1][Spy]!='#' && map_cache[Spx-1][Spy]!='O' && map_cache[Spx-1][Spy]!='@'
#define GO_RIGHT map_cache[Spx][Spy+1]!='#' && map_cache[Spx][Spy+1]!='O' && map_cache[Spx][Spy+1]!='@'
#define GO_LEFT map_cache[Spx][Spy-1]!='#' && map_cache[Spx][Spy-1]!='O' && map_cache[Spx][Spy-1]!='@'
#define PUSH_DOWN map_cache[Spx+2][Spy]!='#' && map_cache[Spx+1][Spy]=='O' && map_cache[Spx+2][Spy]!='O' && map_cache[Spx+2][Spy]!='@' || map_cache[Spx+1][Spy]=='@' && map_cache[Spx+2][Spy]!='#' && map_cache[Spx+2][Spy]!='@'
#define PUSH_UP map_cache[Spx-2][Spy]!='#' && map_cache[Spx-1][Spy]=='O' && map_cache[Spx-2][Spy]!='O' && map_cache[Spx-2][Spy]!='@' || map_cache[Spx-1][Spy]=='@' && map_cache[Spx-2][Spy]!='#' && map_cache[Spx-2][Spy]!='@'
#define PUSH_RIGHT map_cache[Spx][Spy+2]!='#' && map_cache[Spx][Spy+1]=='O' && map_cache[Spx][Spy+2]!='O' && map_cache[Spx][Spy+2]!='@' || map_cache[Spx][Spy+1]=='@' && map_cache[Spx][Spy+2]!='#' && map_cache[Spx][Spy+2]!='@'
#define PUSH_LEFT map_cache[Spx][Spy-2]!='#' && map_cache[Spx][Spy-1]=='O' && map_cache[Spx][Spy-2]!='O' && map_cache[Spx][Spy-2]!='@' || map_cache[Spx][Spy-1]=='@' && map_cache[Spx][Spy-2]!='#' && map_cache[Spx][Spy-2]!='@'

#endif