#ifndef __COMMON_H__
#define __COMMON_H__


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define MAXSTAGE 10



enum Sokoban
{
	SPACE, PLAYER, TARGET, DELIVERY, WALL, //공백, 플레이어, 목표지점, 배달물, 벽
	PLAYER_ON_TARGET, DELIVERY_ON_TARGET,  //타겟위에 플레이어, 타겟위에 배달물
};

typedef struct Player
{
	int x, y;
};

extern char map[20][20]; //원형은 MAP 파일에 있음.
extern Player Play; //플레이어의 좌표
extern int MAXTARGET; //원형은 Update에...

//MapTool
void LoadingFile(int stage, char ** InitMap);

//Map
void MapLoding(int stage); 

//Update
int IsitClear();
void Move(char ch);
void input();

//Gotoxy
void gotoxy(int x, int y, char * str);

#endif