#include "Common.h"

int MAXTARGET; // 맵에 있는 타겟의 수를 저장함.
#include "Common.h"

void input()
{
	char ch;
	int x, y;

	for (; 2;)
	{
		ch = getch();

		if (ch == 0xE0 || ch == 0)
		{
			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				Move(ch);
				break;
			}
		}
		else
		{
			ch = tolower(ch);

			if (ch == 'r')
				break;
			if (ch == 'q')
				exit(0);

		}
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


	if (map[Play.])
}