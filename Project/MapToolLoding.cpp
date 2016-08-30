#include "Common.h"


void LoadingFile(int stage, char ** InitMap)
{
	char str[40];
	char tempMap[24][20];

	sprintf(str, "stage%d.txt", stage);
	FILE * fpmap = fopen(str, "rt");

	if (fpmap == NULL)
	{
		printf("��� ���� �� ����߽��ϴ�. \n");
		printf("���α׷��� �����մϴ�. \n");
		_getch();
		exit(0);
	}

	MAXTARGET = fgetc(fpmap) - 48;
	fgetc(fpmap);
	Play.Player_X = fgetc(fpmap) - 48;
	fgetc(fpmap); //�����̽� ó��
	Play.Player_Y = fgetc(fpmap) - 48;
	fgetc(fpmap); //���� ó��

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			tempMap[i][j] = fgetc(fpmap) - 48;
		}
		fgetc(fpmap); //���๮�� ó��.
	}

	memcpy(InitMap, tempMap, sizeof(tempMap));

}