#include "Common.h"

char map[25][20];


void MapLoding(int stage)
{
	char ** Maptemp;
	LoadingFile(stage, Maptemp);

	memcpy(map, Maptemp, sizeof(map));
}

