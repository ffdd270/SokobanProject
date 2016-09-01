#include "Common.h"

void Printing_Map()
{
	int x , y;

	while (1)
	{
		for (y = 0; y < 20; y++)
		{
			for (x = 0; x < 20; x++)
			{
				switch (e_map[y][x])
				{
				case SPACE :
					printf(" ");
					break;
				case PLAYER :
					printf("p");
					break;
				case TARGET :
					printf(".");
					break;
				case DELIVERY :
					printf("o");
					break;
				case WALL :
					printf("#");
					break;
				case PLAYER_ON_TARGET :
					printf("P");
					break;
				case DELIVERY_ON_TARGET :
					printf("O");
					break;
		
				}
			}
		}

		gotoxy(20, 6, "소코반!!! \n");
		gotoxy(20, 8, "리겜 : r \n");
		gotoxy(30, 8, "게임 종료 : q \n");
		gotoxy(20, 10, "다음 스테이지 : n \n");
		gotoxy(20, 12, "이전 스테이지 : p \n");
	}
}
