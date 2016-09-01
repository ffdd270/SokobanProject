#include "Common.h"


void LoadingFile(int stage)
{
	char str[40];
	char tempMap[20][20];

	sprintf(str, "stage%d.txt", stage);
	FILE * fpmap = fopen(str, "rt");

	if (fpmap == NULL)
	{
		printf("��� ���� �� ����߽��ϴ�. \n");
		printf("���α׷��� �����մϴ�. \n");
		_getch();
		exit(0);
	}

	e_MAXTARGET = fgetc(fpmap) - 48;
	fgetc(fpmap);
	e_Play.y = fgetc(fpmap) - 48;
	fgetc(fpmap); //�����̽� ó��
	e_Play.x = fgetc(fpmap) - 48;
	fgetc(fpmap); //���� ó��

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			tempMap[i][j] = fgetc(fpmap) - 48;
		}
		fgetc(fpmap); //���๮�� ó��.
	}

	memcpy(e_map, tempMap, sizeof(tempMap));

}