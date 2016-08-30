#include "Common.h"

void main()
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


}