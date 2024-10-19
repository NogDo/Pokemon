#pragma once
#include "Map.h"

#define GYM_MAP_SIZE_X			24
#define GYM_MAP_SIZE_Y			24
#define GYM_MAP_SIZE_MAX_X		TILE_SIZE_X * GYM_MAP_SIZE_X
#define GYM_MAP_SIZE_MAX_Y		TILE_SIZE_Y * GYM_MAP_SIZE_Y

#define POINT_STRING_WIDTH		26
#define POINT_STRING_HEIGHT		2

class GymMap : public Map
{
private:
	char** m_chArrBlank;
	char** m_chArrGymRoad;
	char** m_chArrGymFallRoadUp;
	char** m_chArrGymFallRoadDown;
	char** m_chArrGymWall;
	char** m_chArrGymWall2;
	char** m_chArrGymStatueUp;
	char** m_chArrGymStatueMiddle1;
	char** m_chArrGymStatueMiddle2;
	char** m_chArrGymStatueDown;
	char** m_chArrGymCarpet;

	char* m_chArrPointString;

public:
	void Init() override;

	char* GetPointString() { return m_chArrPointString; }

	GymMap();
	~GymMap();
};

