#ifndef __COMMON_H__
#define __COMMON_H__


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define MAXSTAGE 10



enum Sokoban
{
	SPACE, PLAYER, TARGET, DELIVERY, //����, �÷��̾�, ��ǥ����, ��޹�
	PLAYER_ON_TARGET, DELIVERY_ON_TARGET,  //Ÿ������ �÷��̾�, Ÿ������ ��޹�
};

typedef struct Player
{
	int x, y;
};

extern char map[25][20]; //������ MAP ���Ͽ� ����.
extern Player Play;
extern int MAXTARGET; //������ Update��...

//MapTool
void LoadingFile(int stage, char ** InitMap);

//Map
void MapLoding(int stage); 

//Update
int IsitClear();



#endif