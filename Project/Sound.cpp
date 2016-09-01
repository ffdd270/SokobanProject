#include "Common.h"
#include <fmod.h>
#include <io.h>

FMOD_SYSTEM *g_System;  // Note: FMOD system 포인터 변수 선언
FMOD_SOUND  **g_arr_Sound;   // Note: FMOD Sound 포인터 변수 선언


char ** g_arr_songname;

int h_Fsys = 0;
int h_Fsnd = 0;
int g_SongNumber = 0;

void Init()
{
	// Note: FMOD 사운드 초기화 및 사운드 로딩
	_finddata_t fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.mp3", &fd);

	if (handle == 1)
	{
		system("cls");
		printf("system Failed : No Mp3 File in Here. ");
		_getch();
		exit(1);
	}

	//곡의 갯수 확인.
	while (result != -1)
	{
		result = _findnext(handle, &fd);
		g_SongNumber++;
	}

	g_arr_songname = (char **)malloc(sizeof(char *) * g_SongNumber);
	g_arr_Sound = (FMOD_SOUND **)malloc(sizeof(FMOD_SOUND *)* g_SongNumber);

	handle = _findfirst(".\\*,mp3", &fd);
	int i = 0;
	result = 0;

	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);

	while (result != -1)
	{
		g_arr_songname[i] = (char *)malloc(strlen(fd.name));
		strcpy(g_arr_songname[i], fd.name);
		result = _findnext(handle, &fd);
		i++;
	}
}

void Release()
{
	// Note: FMOD 해제
	for (int i = 0; i < g_SongNumber; i++)
	{
		FMOD_Sound_Release(g_arr_Sound[i]);
		free(g_arr_Sound[i]);
	}

	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

int main(void)
{
	int nKey;
	FMOD_CHANNEL *channel = NULL;
	float volume = 0.5f;
	FMOD_BOOL IsPlaying;

	Init();

	while (1)
	{
		if (_kbhit())  // 키 입력 감지   
		{
			nKey = _getch();   // 입력된 키 값을 키보드 버퍼로부터 가져옴
			if (nKey == 'q')  // q 키가 눌리면 프로그램 종료, 키 입력중 가장 최우선 순위가 된다. 
				break;

			switch (nKey)
			{
			case 'p':
				FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound, 0, &channel);
				break;
			case 's':
				FMOD_Channel_Stop(channel);
				break;
			case 'u': // 볼륨 업
				volume += 0.1f;
				if (volume > 1.0f)
					volume = 1.0f;
				FMOD_Channel_SetVolume(channel, volume);
				break;
			case 'd': // 볼륨 다운
				volume -= 0.1f;
				if (volume < 0.0f)
					volume = 0.0f;
				FMOD_Channel_SetVolume(channel, volume);
				break;
			}
		}

		FMOD_Channel_IsPlaying(channel, &IsPlaying); // 사운드 출력중인지 체크
		if (IsPlaying == 1)
			FMOD_System_Update(g_System);		 	   // FMOD 업데이트	 
	}

	Release();
	return 0;
}

