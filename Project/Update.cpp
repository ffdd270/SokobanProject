#include "Common.h"

int MAXTARGET; // �ʿ� �ִ� Ÿ���� ���� ������.

void input()
{
	char ch;					// Ű����� �Է¹��� ����
	int x, y;					// ���� ��ġ

	for (; 2;)
	{
		ch = getch();

		if (ch == 0xE0 || ch == 0)					// ch�� �ִ���� �̰ų� �ּҹ��� �� ��
		{
			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				Move(ch);							// Move�Լ��� ch���� �ѱ��
				break;
			}
		}
		else
		{
			ch = tolower(ch);						// ch�� ���ڸ� �ҹ��ڷ� ��ȯ!

			if (ch == 'r')							// ���� ch�� 'r'�� ��
				break;								// ���� Ż��

			if (ch == 'q')							// ���� ch�� 'q'�� ��
				exit(0);							// ���� ����

			if (ch == 'n')							// ���� ch�� 'p'�� ��
													// ���� ������ �̵�

			if (ch == 'p')							// ���� ch�� 'p'�� ��
													// ���� ������ �̵�


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


	if (map[Play.y + dy][Play.x + dx] != 4)
	{
		if (map[Play.y + dy][Play.x + dx] == DELIVERY)
		{
			if (map[Play.y + (dy * 2)][Play.x + (dx * 2)] == TARGET)
			{
				map[Play.y + (dy * 2)][Play.x + (dx * 2)] = DELIVERY_ON_TARGET;
			}
			if (map[Play.y + (dy * 2)][Play.x + (dx * 2)])
		}
	}
}