#pragma once
#include "Map.h"

#define VILLAGE_MAP_SIZE_X			44
#define VILLAGE_MAP_SIZE_Y			26
#define VILLAGE_MAP_SIZE_MAX_X		TILE_SIZE_X * VILLAGE_MAP_SIZE_X
#define VILLAGE_MAP_SIZE_MAX_Y		TILE_SIZE_Y * VILLAGE_MAP_SIZE_Y


class VillageMap : public Map
{
private:
	char** m_chArrStoneRoad;
	char** m_chArrGrassRoad;
	char** m_chArrTreeLeftUp;
	char** m_chArrTreeRightUp;
	char** m_chArrTreeLeftDown;
	char** m_chArrTreeRightDown;
	char** m_chArrBuildingOutsideWall;
	char** m_chArrBuildingMiddleWall;
	char** m_chArrBuildingOutsideDown;
	char** m_chArrBuildingMiddleDown;
	char** m_chArrPoketSignLeft;
	char** m_chArrPoketSignRight;
	char** m_chArrShopSignLeft;
	char** m_chArrShopSignRight;
	char** m_chArrSignDown;
	char** m_chArrDoorUp;
	char** m_chArrDoorDown;
	char** m_chArrRoofLeftUp;
	char** m_chArrRoofMiddleUp;
	char** m_chArrRoofRightUp;
	char** m_chArrRoofLeftMiddle;
	char** m_chArrRoofMiddleMiddle;
	char** m_chArrRoofRightMiddle;
	char** m_chArrRoofLeftDown;
	char** m_chArrRoofMiddleDown;
	char** m_chArrRoofRightDown;
	char** m_chArrPoketmonGrass;
	char** m_chArrGymSignLeft;
	char** m_chArrGymSignMiddle;
	char** m_chArrGymSignRight;

public:
	void Init() override;

	VillageMap();
	~VillageMap();
};