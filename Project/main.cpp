#include "Common.h"



void Init();
void Release(); //«ÿ¡¶


int main()
{
	Init();
	Printing_Map();
	while (1)
	{
		if (e_IsPlaying == true)
		{
			UpdatingMusic();
		}
		if (_kbhit())
		{
			input();
			Printing_Map();
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