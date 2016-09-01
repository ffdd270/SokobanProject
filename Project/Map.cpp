#include "Common.h"

char map[20][20];
int e_NOWSTAGE;

void MapLoding(int stage)
{
	char ** Maptemp;
	LoadingFile(stage, Maptemp);

	memcpy(map, Maptemp, sizeof(map));
}

