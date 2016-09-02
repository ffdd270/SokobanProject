#include "Common.h"
#include <fmod.h>
#include <io.h>
#include <fmod_errors.h>
FMOD_SYSTEM *g_System;  // Note: FMOD system 포인터 변수 선언
FMOD_SOUND  **g_arr_Sound;   // Note: FMOD Sound 포인터 변수 선언
FMOD_CHANNEL * g_channel = NULL;

char ** g_arr_songname;

int h_Fsys = 0;
int h_Fsnd = 0;
int g_SongNumber = 0;

void FMOD_Init()
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

	handle = _findfirst(".\\*.mp3", &fd);
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

void Sound_Release()
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

void ERRORCALL(FMOD_RESULT errchk)
{
	if (errchk != FMOD_OK)
	{
		printf("FMOD ERROR : (%d) %s \n", errchk, FMOD_ErrorString(errchk));
		_getch();
		exit(0);
	}
}

FMOD_RESULT Play(int SongNum)
{
	static int OldMusic = -1; //전음악, -1이면 아직 전음악이 없었던 상황
	FMOD_RESULT errchk;
	int MyMusic = SongNum;

	if ((OldMusic != -1) && (OldMusic != MyMusic))
	{
		errchk = FMOD_Sound_Release(g_arr_Sound[OldMusic]);
	}
	if (OldMusic != MyMusic)
	{
		g_arr_Sound[MyMusic] = (FMOD_SOUND *)malloc(sizeof(FMOD_SOUND *));
		errchk = FMOD_System_CreateSound(g_System, g_arr_songname[SongNum], FMOD_LOOP_NORMAL, NULL, &g_arr_Sound[SongNum]);
	}
	ERRORCALL(errchk);
	OldMusic = MyMusic;
	return errchk;
}


void Sound_Init()
{
	FMOD_Init();
}

void PlayingMusic() //다른 함수에서 접근할 함수,
{
	FMOD_RESULT errchk; //에러 체킹
	errchk = Play(e_NowSong);
	ERRORCALL(errchk);
	errchk = FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_arr_Sound[e_NowSong], 0, &g_channel);
	ERRORCALL(errchk);
}

void UpdatingMusic()
{
	FMOD_RESULT errchk; //에러 체킹
	FMOD_BOOL IsPlaying; //플레이 하고 있나요?

	FMOD_Channel_IsPlaying(g_channel, &IsPlaying);
	if (IsPlaying == 1)
	{
		errchk = FMOD_System_Update(g_System);
		ERRORCALL(errchk);
	}
}

void StopingMusic()
{
	FMOD_Channel_Stop(g_channel);
}

void NowPlaying(char * str)
{
	unsigned int nowtime = 0;
	unsigned int totaltime = 0;
	int n_arr[3] = { 0 }; //0부터 - 분 / 초 / 밀리
	int t_arr[3] = { 0 }; // ""
	FMOD_BOOL    paused = 0;



	if (e_IsPlaying == true)
	{
		FMOD_Sound_GetLength(g_arr_Sound[e_NowSong], &totaltime, FMOD_TIMEUNIT_MS); //음악 전채길이
		FMOD_Channel_GetPaused(g_channel, &paused); //멈췄나요 ? 
		FMOD_Channel_GetPosition(g_channel, &nowtime, FMOD_TIMEUNIT_MS); //현재 길이.

		n_arr[0] = nowtime / 1000 / 60;
		n_arr[1] = nowtime / 1000 % 60;
		n_arr[2] = nowtime / 10 % 100;

		t_arr[0] = totaltime / 1000 / 60;
		t_arr[1] = totaltime / 1000 % 60;
		t_arr[2] = totaltime / 10 % 100;
	}

	sprintf(str, "%s %d : %s Time : %02d:%02d:%02d / %02d:%02d:%02d", e_IsPaused ? "NOW PLAYING" : "Paused", e_NowSong, g_arr_songname[e_NowSong], n_arr[0], n_arr[1], n_arr[2], t_arr[0], t_arr[1], t_arr[2]);
}

void PrintMusicList()
{
	char print[100];
	for (int i = 0; i < g_SongNumber; i++)
	{
		sprintf(print, "%d : %s", i, g_arr_songname[i]);
		gotoxy(40, 10 + i * 2, print);
	}

}

void PauseMusic()
{
	FMOD_BOOL paused;

	FMOD_Channel_GetPaused(g_channel, &paused);
	FMOD_Channel_SetPaused(g_channel, !paused);
}


//
//int main()
//{
//	int nKey;
//	FMOD_CHANNEL * channel = NULL;
//	FMOD_RESULT errchk; //에러 체킹
//	float volume = 0.5f;
//	FMOD_BOOL IsPlaying;
//	int SongNum = 0;
//	Init();
//
//	while (1)
//	{
//
//		if (_kbhit())
//		{
//			nKey = getch();
//			if (nKey == 'q')
//				break;
//
//			switch (nKey)
//			{
//			case 'e':
//				errchk = FMOD_Channel_Stop(channel);
//				SongNum++;
//				break;
//			case 'd':
//				errchk = FMOD_Channel_Stop(channel);
//				SongNum--;
//				break;
//			case 'p':
//				errchk = Play(SongNum);
//				ERRORCALL(errchk);
//				errchk = FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_arr_Sound[SongNum], 0, &channel);
//				ERRORCALL(errchk);
//				break;
//			case 's':
//				errchk = FMOD_Channel_Stop(channel);
//				break;
//			case 'x':
//				if (volume > -0.01f)
//					volume = 0.0f;
//				volume -= 0.1f;
//				errchk = FMOD_Channel_SetVolume(channel, volume);
//				break;
//			case 'u':
//				volume += 0.1f;
//				if (volume > 1.0f)
//					volume = 1.0f;
//				errchk = FMOD_Channel_SetVolume(channel, volume);
//				break;
//			}
//			printf("Number : %d ", SongNum);
//		}
//		
//		FMOD_Channel_IsPlaying(channel, &IsPlaying);
//		if (IsPlaying == 1)
//		{
//			errchk = FMOD_System_Update(g_System);
//			ERRORCALL(errchk);
//		}
//	}
//	Release();
//	return 0;
//}
