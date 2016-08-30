#include "Common.h"


void LoadingFile(int stage, char ** InitMap)
{
	char str[40];
	char tempMap[24][20];

	sprintf(str, "stage%d.txt", stage);
	FILE * fpmap = fopen(str, "rt");

	if (fpmap == NULL)
	{
		printf("모든 맵을 다 사용했습니다. \n");
		printf("프로그램을 종료합니다. \n");
		_getch();
		exit(0);
	}

	MAXTARGET = fgetc(fpmap) - 48;
	fgetc(fpmap);
	Play.Player_X = fgetc(fpmap) - 48;
	fgetc(fpmap); //스페이스 처리
	Play.Player_Y = fgetc(fpmap) - 48;
	fgetc(fpmap); //개행 처리

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			tempMap[i][j] = fgetc(fpmap) - 48;
		}
		fgetc(fpmap); //개행문자 처리.
	}

	memcpy(InitMap, tempMap, sizeof(tempMap));

}