#include "Common.h"

#define TRUE 1
#define FALSE 0
#define ISITCHANGE 2

int NOWONTARGET; //���� Ÿ�� ���� �ö� ��޹��� ���ڸ� ������.


void input()
{
	char ch;					// Ű����� �Է¹��� ����
	int x, y;					// ���� ��ġ

	ch = getch();

	switch (ch)
	{
	case 'w':
	case 'a':
	case 's':
	case 'd':
		Move(ch);							// Move�Լ��� ch���� �ѱ��
		break;
	}

	ch = tolower(ch);						// ch�� ���ڸ� �ҹ��ڷ� ��ȯ!

	if (ch == 'r')							// ���� ch�� 'r'�� ��
	{
		LoadingFile(e_NOWSTAGE);			// ���� Ż��
	}

	if (ch == 'q')							// ���� ch�� 'q'�� ��
		exit(0);							// ���� ����

	if (ch == 'n')// ���� ch�� 'n'�� ��
	{
		e_NOWSTAGE++;
		LoadingFile(e_NOWSTAGE);
	}
	// ���� ������ �̵�

	if (ch == 'p')							// ���� ch�� 'p'�� ��
	{
		e_NOWSTAGE++;
		LoadingFile(e_NOWSTAGE);
	}

	if (IsitClear() == TRUE)
	{
		e_NOWSTAGE++;

		if (e_NOWSTAGE == MAXSTAGE)
		{
			system("cls");
			printf("��� ���������� �������ϴ� ^_^");
			printf("�ɸ� �ð� : ");
		}

		LoadingFile(e_NOWSTAGE);
	}

}

int IsitClear() //Ŭ���� �߳���?
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

	//switch (ch)
	//{
	//case LEFT:
	//	dx -= 1;
	//	break;
	//case RIGHT:
	//	dx += 1;
	//	break;
	//case UP:
	//	dy -= 1;
	//	break;
	//case DOWN:
	//	dy += 1;
	//	break;
	//default:
	//	break;
	//}

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


	if (e_map[e_Play.y + dy][e_Play.x + dx] != 4)					// (�迭)��[����y��ǥ + �̵�y��ǥ][����x��ǥ + �̵�x��ǥ]
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

	else //���� �΋Hħ.
	{
		return;
	}

	e_map[e_Play.y][e_Play.x] = SPACE;

	e_Play.x += dx;
	e_Play.y += dy;

	e_map[e_Play.y][e_Play.x] = PLAYER;
}