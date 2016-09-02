#include "Common.h"

#define TRUE 1
#define FALSE 0
#define ISITCHANGE 2

int NOWONTARGET; //현재 타겟 위에 올라간 배달물의 숫자를 저장함.


void input()
{
	char ch;					// 키보드로 입력받을 문자
	int x, y;					// 유저 위치

	ch = getch();

	ch = tolower(ch);						// ch의 문자를 소문자로 변환!

	switch (ch)
	{
	case 'w':
	case 'a':
	case 's':
	case 'd':
		Move(ch);							// Move함수에 ch값을 넘긴다
		break;
	case 'r':
		LoadingFile(e_NOWSTAGE);			// 루프 탈출
		break;
	case 'q':
		exit(0);							// 게임 종료
		break;
	case 'n':
		e_NOWSTAGE++;
		LoadingFile(e_NOWSTAGE);
		break;
	case 'p':
		e_NOWSTAGE++;
		LoadingFile(e_NOWSTAGE);
		break;
	case 'm':
		gotoxy(0, 23, "P : 재생 N : 다음곡 B : 전곡 S : 정지");
		ch = getch();
		ch = tolower(ch);
		switch (ch)
		{
		case 'p':
			e_IsPlaying = true;
			PlayingMusic();
			break;
		case 'n':
			StopingMusic();
			e_NowSong++;
			break;
		case 'b':
			StopingMusic();
			e_NowSong--;
			break;
		case 's':
			e_IsPlaying = false;
			StopingMusic();
			break;
		default:
			break;
		}
	}

	if (IsitClear() == TRUE)
	{
		e_NOWSTAGE++;

		if (e_NOWSTAGE == MAXSTAGE)
		{
			system("cls");
			printf("모든 스테이지가 끝났습니다 ^_^");
			printf("걸린 시간 : ");
		}

		LoadingFile(e_NOWSTAGE);
	}

}

int IsitClear() //클리어 했나요?
{
	if (NOWONTARGET == e_MAXTARGET)
	{
		return TRUE;
	}
	return FALSE;
}

void Move(char ch)
{
	int dx = 0, dy = 0;

	switch (ch)
	{
	case 'a':
		dx -= 1;
		break;
	case 'd':
		dx += 1;
		break;
	case 'w':
		dy -= 1;
		break;
	case 's':
		dy += 1;
		break;
	default:
		break;
	}


	if (e_map[e_Play.y + dy][e_Play.x + dx] != 4)					// (배열)맵[현재y좌표 + 이동y좌표][현재x좌표 + 이동x좌표]
	{
		if (e_map[e_Play.y + dy][e_Play.x + dx] == DELIVERY)
		{
			if (e_map[e_Play.y + (dy * 2)][e_Play.x + (dx * 2)] == TARGET)
			{
				e_map[e_Play.y + (dy * 2)][e_Play.x + (dx * 2)] = DELIVERY_ON_TARGET;
				e_map[e_Play.y][e_Play.x] = SPACE;
				e_Play.x += dx;
				e_Play.y += dy;
				e_map[e_Play.y][e_Play.x] = PLAYER;
				NOWONTARGET++;
			}
			if (e_map[e_Play.y + (dy * 2)][e_Play.x + (dx * 2)] == SPACE)
			{
				e_map[e_Play.y + (dy * 2)][e_Play.x + (dx * 2)] = DELIVERY;
			}
			else
			{
				return;
			}
		}

		if (e_map[e_Play.y + dy][e_Play.x + dx] == DELIVERY_ON_TARGET)
		{
			if (e_map[e_Play.y + (dy * 2)][e_Play.x + (dx * 2)] == SPACE)
			{
				e_map[e_Play.y + dy][e_Play.x + dx] == TARGET;
				NOWONTARGET--;
			}
			if (e_map[e_Play.y + (dy * 2)][e_Play.x + (dx * 2)] == TARGET)
			{
				e_map[e_Play.y + dy][e_Play.x + dx] == PLAYER_ON_TARGET;
				NOWONTARGET++;
			}
			else
			{
				return;
			}
		}

		if (e_map[e_Play.y + dy][e_Play.x + dx] == TARGET)
		{
			e_map[e_Play.y][e_Play.x] = SPACE;
			e_Play.y += dy; e_Play.x += dx;
			e_map[e_Play.y][e_Play.x] = PLAYER_ON_TARGET;
			return;
		}

		if (e_map[e_Play.y][e_Play.x] == PLAYER_ON_TARGET)
		{
			e_map[e_Play.y][e_Play.x] = TARGET;
			e_Play.x += dx;
			e_Play.y += dy;
			e_map[e_Play.y][e_Play.x] = PLAYER;
			return;
		}
	}

	else //벽에 부딫침.
	{
		return;
	}

	e_map[e_Play.y][e_Play.x] = SPACE;

	e_Play.x += dx;
	e_Play.y += dy;

	e_map[e_Play.y][e_Play.x] = PLAYER;
}