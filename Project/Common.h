#ifndef __COMMON_H__
#define __COMMON_H__


#include <stdio.h>
#include <conio.h>

enum Sokoban
{
	SPACE, PLAYER, TARGET, DELIVERY, //공백, 플레이어, 목표지점, 배달물
	PLAYER_ON_TARGET, DELIVERY_ON_TARGET,  //타겟위에 플레이어, 타겟위에 배달물
};

#endif