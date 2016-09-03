#include "Common.h"

Player e_Play;
char e_map[20][20];
int e_NOWSTAGE;
int e_MAXTARGET; // 맵에 있는 타겟의 수를 저장함.
bool e_IsPlaying = false;
bool e_IsPaused = false;
int e_NowSong;