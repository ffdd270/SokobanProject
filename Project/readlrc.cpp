#include "Common.h"
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


//This Program ONLY READ ASCI FORMAT!!

FILE ** g_arr_rfp;
char ** g_arr_filename;
int g_filenum;

int InitLRC()
{
	_finddata_t fd;
	long handle;
	int result = 1;

	handle = _findfirst(".\\Music\\*.lrc",&fd);

	if (handle == 1)
	{
		printf("파일이 없어요! \n");
		_getch();
		exit(0);
	} 

	while (result != -1)
	{
		result = _findnext(handle, &fd);
		g_filenum++;
	}

	g_arr_rfp = (FILE **)malloc(sizeof(FILE*) * g_filenum);
	g_arr_filename = (char **)malloc(sizeof(char *) * g_filenum);

	int i = 0; //배열 조정용.

	result = 0;
	handle = _findfirst(".\\Music\\*.lrc", &fd);

	while (result != -1)
	{
		g_arr_filename[i] = strdup(fd.name);
		result = _findnext(handle, &fd);
		i++;
	}
}

int LoadLRC(int FileNum)
{
	static int MyFnum = 0;
	static int OldFnum = -1;

	char str[100];
	char filename[100];
	if (MyFnum != OldFnum && OldFnum != -1)
	{
		fclose(g_arr_rfp[OldFnum]);
	}


	sprintf(filename, ".\\Music\\%s", g_arr_filename[FileNum]);

	g_arr_rfp[FileNum] = (FILE *)malloc(sizeof(FILE *));
	g_arr_rfp[FileNum] = fopen(filename, "rt+");
	fgets(str, 100, g_arr_rfp[FileNum]);	//printf("%s", str);
	fgets(str, 100, g_arr_rfp[FileNum]);	//printf("%s", str);
	fgets(str, 100, g_arr_rfp[FileNum]);	//printf("%s\n", str);
	return 1;
}

int ReadLRC(int filenum, int Playtime)
{
	static char str[3][50];
	static int i = 0;
	static int min, sec, milsec;
	int Omin, Osec, Omilsec;
	int nowtime = 0;
	int newnowtime = 0; //새로 구하는 값.

	fscanf(g_arr_rfp[filenum], "[%d:%d.%d]", &min, &sec, &milsec);
	nowtime = milsec + (sec * 1000) + (min * 1000 * 60);

	if (nowtime > Playtime)
	{
		for (int j = 0; j < i; j++)
		{
			gotoxy(30, 20 + j, str[j]);
		}
		return 0;
	}

	else
	{
		system("cls");
		Printing_Map();
		i = 0;
	}

	while (1)
	{
		fscanf(g_arr_rfp[filenum], "[%d:%d.%d]", &min, &sec, &milsec);
		newnowtime = milsec + (sec * 1000) + (min * 1000 * 60);
		if (feof(g_arr_rfp[filenum]))
		{
			return 1;
		}
		if (nowtime != newnowtime)
		{
			break;
		}

		fgets(str[i], 50, g_arr_rfp[filenum]);
		gotoxy(30, 20 + i, str[i]);
		i++;
	}

	printf("\n\n");

	return 0;
}

int ContorlLRC(int filenum, int PlayTime)
{
	static int OldFileNum = -1;
	if (OldFileNum != filenum)
	{
		LoadLRC(filenum);
	}
	if (ReadLRC(filenum, PlayTime))
	{
		printf("\n\nEOF!\n");
		return 0;
	}
	OldFileNum = filenum;
	return 1;
}

//int main()
//{
//	int i = 0;
//	InitLRC();
//	LoadLRC(i);
//	while (1)
//	{
//		if (ContorlLRC(i) == 0)
//		{
//			i++;
//			if (i >= g_filenum)
//			{
//				printf("모든 파일 로드 완료");
//				_getch();
//				return 0;
//			}
//			LoadLRC(i);
//		}
//	}
//
//	_getch();
//}