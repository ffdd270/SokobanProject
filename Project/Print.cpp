#include "Common.h"

void Printing_Map()
{
	char str[100];
	int x , y;

	system("cls");

	for (y = 0; y < 20; y++)
	{
		for (x = 0; x < 20; x++)
		{
			switch (e_map[y][x])
			{
			case SPACE:
				printf(" ");
				break;
			case PLAYER:
				printf("p");
				break;
			case TARGET:
				printf(".");
				break;
			case DELIVERY:
				printf("o");
				break;
			case WALL:
				printf("#");
				break;
			case PLAYER_ON_TARGET:
				printf("P");
				break;
			case DELIVERY_ON_TARGET:
				printf("O");
				break;

			}
		}
		printf("\n");
	}

	gotoxy(20, 2, "���ڹ�!!! \n");
	gotoxy(20, 4, "���� : r \n");
	gotoxy(30, 4, "���� ���� : q \n");
	gotoxy(20, 6, "���� �������� : n \n");
	gotoxy(40, 6, "���� �������� : p \n");

	PrintMusicList();
}
