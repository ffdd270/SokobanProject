#include "Common.h"
#include <Windows.h>


void Init();
void Release(); //����


int main()
{
	char str[100];
	Init();
	Printing_Map();
	while (1)
	{
		if (e_IsPlaying == true)
		{
			UpdatingMusic();
			NowPlaying(str);
			gotoxy(0, 24, str); //���������� �����ؾ��ؼ� ���λ�
			Sleep(20);
		}
		if (_kbhit() && e_IsPlaying == true && e_IsPaused == false)
		{
			input();
			Printing_Map();
		}
		if (_kbhit())
		{
			MusicInput();
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