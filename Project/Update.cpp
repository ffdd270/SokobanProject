#include "Common.h"

int e_MAXTARGET; // �ʿ� �ִ� Ÿ���� ���� ������.
int NOWONTARGET; //���� Ÿ�� ���� �ö� ��޹��� ���ڸ� ������.
int NOWSTAGE;

void input()
{
	char ch;					// Ű����� �Է¹��� ����
	int x, y;					// ���� ��ġ

	while (2)
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
				MapLoding(NOWSTAGE);
				break;								// ���� Ż��

			if (ch == 'q')							// ���� ch�� 'q'�� ��
				exit(0);							// ���� ����

			if (ch == 'n')
				NOWSTAGE++;                             // ���� ch�� 'n'�� ��
													   // ���� ������ �̵�

			if (ch == 'p')							// ���� ch�� 'p'�� ��
				NOWSTAGE--;   						// ���� ������ �̵�


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