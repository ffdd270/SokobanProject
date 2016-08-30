#include "Common.h"

int MAXTARGET; // 맵에 있는 타겟의 수를 저장함.
#include "Common.h"

void input()
{
	char ch;					// 키보드로 입력받을 문자
	int x, y;					// 유저 위치

	for (; 2;)
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
				break;								// 루프 탈출

			if (ch == 'q')							// 만약 ch가 'q'일 때
				exit(0);							// 게임 종료

			if (ch == 'n')							// 만약 ch가 'p'일 때
													// 다음 맵으로 이동

			if (ch == 'p')							// 만약 ch가 'p'일 때
													// 이전 맵으로 이동


		}
	}
}

void Move(char ch)
{
	int dx = 0, dy = 0;


}