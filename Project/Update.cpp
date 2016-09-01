#include "Common.h"

int e_MAXTARGET; // 맵에 있는 타겟의 수를 저장함.
int NOWONTARGET; //현재 타겟 위에 올라간 배달물의 숫자를 저장함.
int NOWSTAGE;

void input()
{
	char ch;					// 키보드로 입력받을 문자
	int x, y;					// 유저 위치

	while (2)
	{
		ch = getch();

		if (ch == 0xE0 || ch == 0)					// ch가 최대범위 이거나 최소범위 일 때
		{
			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				Move(ch);							// Move함수에 ch값을 넘긴다
				break;
			}
		}
		else
		{
			ch = tolower(ch);						// ch의 문자를 소문자로 변환!

			if (ch == 'r')							// 만약 ch가 'r'일 때
				MapLoding(NOWSTAGE);
				break;								// 루프 탈출

			if (ch == 'q')							// 만약 ch가 'q'일 때
				exit(0);							// 게임 종료

			if (ch == 'n')
				NOWSTAGE++;                             // 만약 ch가 'n'일 때
													   // 다음 맵으로 이동

			if (ch == 'p')							// 만약 ch가 'p'일 때
				NOWSTAGE--;   						// 이전 맵으로 이동


		}
	}
}

int IsitClear()
{
	if (NOWONTARGET == e_MAXTARGET)
	{
		
	}
}

void Move(char ch)
{
	int dx = 0, dy = 0;

	switch (ch)
	{
	case LEFT:
		dx -= 1;
		break;
	case RIGHT:
		dx += 1;
		break;
	case UP:
		dy -= 1;
		break;
	case DOWN:
		dy += 1;
		break;
	default:
		break;
	}


	if (e_map[e_Play.y + dy][e_Play.x + dx] != 4)
	{
		if (e_map[e_Play.y + dy][e_Play.x + dx] == DELIVERY)
		{
			if (e_map[e_Play.y + (dy * 2)][e_Play.x + (dx * 2)] == TARGET)
			{
				e_map[e_Play.y + (dy * 2)][e_Play.x + (dx * 2)] = DELIVERY_ON_TARGET;
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
				NOWONTARGET++;
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
	}
}