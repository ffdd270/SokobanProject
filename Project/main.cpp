#include "Common.h"
#include <Windows.h>


void Init();
void Release(); //����


int main()
{
	char str[100];
	char ch;
	Init();
	Printing_Map();
	while (1)
	{
		if (_kbhit())
		{
			ch = getch();
			if (e_IsPlaying == true && e_IsPaused == false)
			{
				input(ch);
			}
			Printing_Map();
			MusicInput(ch);
			
		}

		if (e_IsPlaying == true)
		{
			UpdatingMusic();
			NowPlaying(str);
			gotoxy(0, 24, str); //���������� �����ؾ��ؼ� ���λ�
			Sleep(20);
		}

		if (_kbhit() && e_IsPlaying == true && e_IsPaused == false)
		{
			
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
	Sound_Init();
}

void Release()
{
	Sound_Release();
}