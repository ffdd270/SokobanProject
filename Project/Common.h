#ifndef __COMMON_H__
#define __COMMON_H__
#define GIT_PLZ_PULLING 1


//Made : HSH
//START : 8월 셋째주
//END : 160902

//나이스 팀플레이.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80


#define MAXSTAGE 10

enum Sokoban
{
	SPACE, PLAYER, DELIVERY, TARGET, WALL, //공백, 플레이어, 목표지점, 배달물, 벽
	PLAYER_ON_TARGET, DELIVERY_ON_TARGET,  //타겟위에 플레이어, 타겟위에 배달물
};

typedef struct Player
{
	int x, y;
};

//Extern Vaule

//Common_Value
extern char e_map[20][20]; 
extern Player e_Play;  
extern int e_MAXTARGET; 
extern int e_NOWSTAGE; 
extern bool e_IsPlaying;
extern int e_NowSong;
extern bool e_IsPaused;

//Fuction

//MapTool
void LoadingFile(int stage);

//Map
void MapLoding(int stage); 

//Update
int IsitClear();
void Move(char ch);
void input();

//Gotoxy
void gotoxy(int x, int y, char * str);
void CursurDisable();

//Print
void Printing_Map();

//Sound
void Sound_Init(); //반드시 이함수 먼저 쓸것.
void PlayingMusic();
void UpdatingMusic();
void StopingMusic();
void PrintMusicList(); 
void NowPlaying(char * str);
void Sound_Release();
void PauseMusic();

#endif