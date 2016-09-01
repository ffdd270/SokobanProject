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

void Play(int SongNum)
{
	static int OldMusic = -1; //전음악, -1이면 아직 전음악이 없었던 상황
	int MyMusic = SongNum;

	if ((OldMusic != -1) && (OldMusic != MyMusic))
	{
		FMOD_Sound_Release(g_arr_Sound[OldMusic]);
	}
	if (OldMusic != MyMusic)
	{
		FMOD_System_CreateSound(g_System, g_arr_songname[SongNum], FMOD_LOOP_NORMAL, NULL, &g_arr_Sound[SongNum]);
	}
	OldMusic = MyMusic;
}

int main()
{
	int nKey;
	FMOD_CHANNEL * channel = NULL;
	float volume = 0.5f;
	FMOD_BOOL IsPlaying;
	int SongNum = 0;
	Init();

	while (1)
	{

		if (_kbhit())
		{
			nKey = getch();
			if (nKey == 'q')
				break;

			switch (nKey)
			{
			case 'e':
				FMOD_Channel_Stop(channel);
				SongNum++;
				break;
			case 'd':
				FMOD_Channel_Stop(channel);
				SongNum--;
				break;
			case 'p':
				Play(SongNum);
				FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_arr_Sound[SongNum], 0, &channel);
				break;
			case 's':
				FMOD_Channel_Stop(channel);
				break;
			case 'x':
				if (volume > -0.01f)
					volume = 0.0f;
				volume -= 0.1f;
				FMOD_Channel_SetVolume(channel, volume);
				break;
			case 'u':
				volume += 0.1f;
				if (volume > 1.0f)
					volume = 1.0f;
				FMOD_Channel_SetVolume(channel, volume);
				break;
			}
			printf("Number : %d ", SongNum);
		}
		FMOD_Channel_IsPlaying(channel, &IsPlaying);
		if (IsPlaying == 1)
			FMOD_System_Update(g_System);
	}
	Release();
	return 0;
}