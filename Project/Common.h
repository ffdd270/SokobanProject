#ifndef __COMMON_H__
#define __COMMON_H__


#include <stdio.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80


enum Sokoban
{
	SPACE, PLAYER, TARGET, DELIVERY, //����, �÷��̾�, ��ǥ����, ��޹�
	PLAYER_ON_TARGET, DELIVERY_ON_TARGET,  //Ÿ������ �÷��̾�, Ÿ������ ��޹�
};

typedef struct Player
{

};

#endif