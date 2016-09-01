#include "Common.h"


void Init();
void Print(); //출력
void Update(); //입력
void Release(); //해제




int main()
{
	Init();
	while (1)
	{
		Print();
		Update();
	}
	Release();
	return 0;
}

void Init()
{
	e_NOWSTAGE = 0;
}

void Print()
{
	Printing_Map();
}

void Update()
{
	input();
}

void Release()
{

}