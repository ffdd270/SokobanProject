#include "Common.h"



void Init();
void Print(); //���
void Update(); //�Է�
void Release(); //����


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
	e_NOWSTAGE = 1;
	CursurDisable();
	LoadingFile(e_NOWSTAGE);
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