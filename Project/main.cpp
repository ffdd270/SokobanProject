#include "Common.h"
#include <Windows.h>
#include <time.h>

void Init();
void Release(); //해제


int main()
{
	char str[100];
	char ch;
	Init();
	Printing_Map();
	static int OldTime = 0;
	static int NowTime = 0;
	while (1)
	{

		if (e_IsPlaying == true)
		{
			if (OldTime == 0)
			{
				OldTime = GetTickCount();
			}
			UpdatingMusic();
			NowPlaying(str);
			ContorlLRC(e_NowSong, nowtime);
			gotoxy(0, 24, str); //지속적으로 갱신해야해서 따로뺌
			NowTime = GetTickCount();
		}

		if (_kbhit())
		{
			ch = getch();
			if (e_IsPlaying == true && e_IsPaused == false)
			{
				input(ch);
			}
			MusicInput(ch);
			Printing_Map();
		}


		if (NowTime - OldTime > totaltime)
		{
			system("cls");
			printf("게임 오버!");
			_getch();
			return 0;
		}
	}
	Release();
	return 0;
}

void Init()
{
	e_NOWSTAGE = 1;
	CursurDisable();
	LoadingFile(e_NOWSTAGE);
	InitLRC();
	Sound_Init();
}

void Release()
{
	Sound_Release();
}