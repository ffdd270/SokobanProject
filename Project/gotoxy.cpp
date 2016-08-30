#include <Windows.h>
#include "Common.h"

void gotoxy(int x, int y, char * str)
{
	COORD cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	printf("%s", str);
}