#include "VillageMap.h"

VillageMap::VillageMap()
{
	Init();
}

VillageMap::~VillageMap()
{
	for (int i = 0; i < TILE_SIZE_X; i++)
	{
		delete[] * (m_chArrStoneRoad + i);
		delete[] * (m_chArrGrassRoad + i);
		delete[] * (m_chArrTreeLeftUp + i);
		delete[] * (m_chArrTreeRightUp + i);
		delete[] * (m_chArrTreeLeftDown + i);
		delete[] * (m_chArrTreeRightDown + i);
		delete[] * (m_chArrBuildingOutsideWall + i);
		delete[] * (m_chArrBuildingMiddleWall + i);
		delete[] * (m_chArrBuildingOutsideDown + i);
		delete[] * (m_chArrBuildingMiddleDown + i);
		delete[] * (m_chArrPoketSignLeft + i);
		delete[] * (m_chArrPoketSignRight + i);
		delete[] * (m_chArrShopSignLeft + i);
		delete[] * (m_chArrShopSignRight + i);
		delete[] * (m_chArrSignDown + i);
		delete[] * (m_chArrDoorUp + i);
		delete[] * (m_chArrDoorDown + i);
		delete[] * (m_chArrRoofLeftUp + i);
		delete[] * (m_chArrRoofMiddleUp + i);
		delete[] * (m_chArrRoofRightUp + i);
		delete[] * (m_chArrRoofLeftMiddle + i);
		delete[] * (m_chArrRoofMiddleMiddle + i);
		delete[] * (m_chArrRoofRightMiddle + i);
		delete[] * (m_chArrRoofLeftDown + i);
		delete[] * (m_chArrRoofMiddleDown + i);
		delete[] * (m_chArrRoofRightDown + i);
		delete[] * (m_chArrPoketmonGrass + i);
		delete[] * (m_chArrGymSignLeft + i);
		delete[] * (m_chArrGymSignMiddle + i);
		delete[] * (m_chArrGymSignRight + i);
	}

	delete[] m_chArrStoneRoad;
	delete[] m_chArrGrassRoad;
	delete[] m_chArrTreeLeftUp;
	delete[] m_chArrTreeRightUp;
	delete[] m_chArrTreeLeftDown;
	delete[] m_chArrTreeRightDown;
	delete[] m_chArrBuildingOutsideWall;
	delete[] m_chArrBuildingMiddleWall;
	delete[] m_chArrBuildingOutsideDown;
	delete[] m_chArrBuildingMiddleDown;
	delete[] m_chArrPoketSignLeft;
	delete[] m_chArrPoketSignRight;
	delete[] m_chArrShopSignLeft;
	delete[] m_chArrShopSignRight;
	delete[] m_chArrSignDown;
	delete[] m_chArrDoorUp;
	delete[] m_chArrDoorDown;
	delete[] m_chArrRoofLeftUp;
	delete[] m_chArrRoofMiddleUp;
	delete[] m_chArrRoofRightUp;
	delete[] m_chArrRoofLeftMiddle;
	delete[] m_chArrRoofMiddleMiddle;
	delete[] m_chArrRoofRightMiddle;
	delete[] m_chArrRoofLeftDown;
	delete[] m_chArrRoofMiddleDown;
	delete[] m_chArrRoofRightDown;
	delete[] m_chArrPoketmonGrass;
	delete[] m_chArrGymSignLeft;
	delete[] m_chArrGymSignMiddle;
	delete[] m_chArrGymSignRight;
}

/// <summary>
/// 타일 및 맵 초기화
/// </summary>
void VillageMap::Init()
{
	m_MapType = EMap_Type::VILLAGE;

	m_chArrStoneRoad = new char* [TILE_SIZE_Y];
	*(m_chArrStoneRoad + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrStoneRoad + 1) = new char[TILE_SIZE_X] { 15, 7, 15, 15, 15, 15, 15, 7 };
	*(m_chArrStoneRoad + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 7, 15, 15, 15 };
	*(m_chArrStoneRoad + 3) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrStoneRoad + 4) = new char[TILE_SIZE_X] { 7, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrStoneRoad + 5) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 7 };
	*(m_chArrStoneRoad + 6) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrStoneRoad + 7) = new char[TILE_SIZE_X] { 15, 7, 15, 15, 15, 15, 15, 15 };

	m_chArrGrassRoad = new char* [TILE_SIZE_Y];
	*(m_chArrGrassRoad + 0) = new char[TILE_SIZE_X] { 2, 10, 2, 10, 2, 10, 10, 10 };
	*(m_chArrGrassRoad + 1) = new char[TILE_SIZE_X] { 10, 2, 7, 2, 10, 2, 10, 2 };
	*(m_chArrGrassRoad + 2) = new char[TILE_SIZE_X] { 2, 10, 2, 10, 7, 10, 2, 10 };
	*(m_chArrGrassRoad + 3) = new char[TILE_SIZE_X] { 10, 10, 10, 2, 10, 2, 10, 10 };
	*(m_chArrGrassRoad + 4) = new char[TILE_SIZE_X] { 2, 10, 2, 10, 2, 10, 2, 10 };
	*(m_chArrGrassRoad + 5) = new char[TILE_SIZE_X] { 10, 2, 10, 2, 10, 2, 7, 2 };
	*(m_chArrGrassRoad + 6) = new char[TILE_SIZE_X] { 10, 10, 10, 10, 2, 10, 2, 10 };
	*(m_chArrGrassRoad + 7) = new char[TILE_SIZE_X] { 10, 10, 10, 2, 10, 2, 10, 10 };

	m_chArrTreeLeftUp = new char* [TILE_SIZE_Y];
	*(m_chArrTreeLeftUp + 0) = new char[TILE_SIZE_X] { 2, 10, 2, 10, 2, 10, 10, 0 };
	*(m_chArrTreeLeftUp + 1) = new char[TILE_SIZE_X] { 10, 2, 7, 2, 10, 2, 0, 10 };
	*(m_chArrTreeLeftUp + 2) = new char[TILE_SIZE_X] { 2, 10, 2, 10, 7, 10, 0, 10 };
	*(m_chArrTreeLeftUp + 3) = new char[TILE_SIZE_X] { 10, 10, 10, 2, 10, 0, 2, 2 };
	*(m_chArrTreeLeftUp + 4) = new char[TILE_SIZE_X] { 2, 10, 2, 0, 0, 0, 2, 0 };
	*(m_chArrTreeLeftUp + 5) = new char[TILE_SIZE_X] { 10, 2, 0, 10, 0, 2, 2, 0 };
	*(m_chArrTreeLeftUp + 6) = new char[TILE_SIZE_X] { 10, 10, 0, 0, 0, 2, 0, 2 };
	*(m_chArrTreeLeftUp + 7) = new char[TILE_SIZE_X] { 10, 10, 0, 2, 2, 0, 0, 2 };

	m_chArrTreeRightUp = new char* [TILE_SIZE_Y];
	*(m_chArrTreeRightUp + 0) = new char[TILE_SIZE_X] { 0, 10, 2, 10, 2, 10, 10, 10 };
	*(m_chArrTreeRightUp + 1) = new char[TILE_SIZE_X] { 2, 0, 7, 2, 10, 2, 10, 2 };
	*(m_chArrTreeRightUp + 2) = new char[TILE_SIZE_X] { 2, 0, 2, 10, 7, 10, 2, 10 };
	*(m_chArrTreeRightUp + 3) = new char[TILE_SIZE_X] { 2, 2, 0, 2, 10, 2, 10, 10 };
	*(m_chArrTreeRightUp + 4) = new char[TILE_SIZE_X] { 2, 2, 0, 0, 0, 10, 2, 10 };
	*(m_chArrTreeRightUp + 5) = new char[TILE_SIZE_X] { 2, 2, 2, 0, 2, 0, 7, 2 };
	*(m_chArrTreeRightUp + 6) = new char[TILE_SIZE_X] { 2, 0, 2, 0, 0, 0, 2, 10 };
	*(m_chArrTreeRightUp + 7) = new char[TILE_SIZE_X] { 0, 0, 0, 2, 2, 0, 10, 10 };

	m_chArrTreeLeftDown = new char* [TILE_SIZE_Y];
	*(m_chArrTreeLeftDown + 0) = new char[TILE_SIZE_X] { 0, 0, 2, 2, 0, 2, 2, 2 };
	*(m_chArrTreeLeftDown + 1) = new char[TILE_SIZE_X] { 10, 0, 2, 0, 2, 2, 0, 2 };
	*(m_chArrTreeLeftDown + 2) = new char[TILE_SIZE_X] { 2, 10, 0, 0, 2, 0, 0, 2 };
	*(m_chArrTreeLeftDown + 3) = new char[TILE_SIZE_X] { 10, 10, 2, 0, 0, 0, 2, 0 };
	*(m_chArrTreeLeftDown + 4) = new char[TILE_SIZE_X] { 10, 2, 2, 2, 2, 0, 2, 2 };
	*(m_chArrTreeLeftDown + 5) = new char[TILE_SIZE_X] { 10, 2, 2, 2, 0, 2, 2, 10 };
	*(m_chArrTreeLeftDown + 6) = new char[TILE_SIZE_X] { 2, 10, 2, 2, 2, 2, 0, 2 };
	*(m_chArrTreeLeftDown + 7) = new char[TILE_SIZE_X] { 10, 2, 10, 10, 2, 2, 2, 0 };

	m_chArrTreeRightDown = new char* [TILE_SIZE_Y];
	*(m_chArrTreeRightDown + 0) = new char[TILE_SIZE_X] { 2, 2, 2, 2, 2, 2, 0, 0 };
	*(m_chArrTreeRightDown + 1) = new char[TILE_SIZE_X] { 2, 0, 2, 2, 0, 2, 0, 2  };
	*(m_chArrTreeRightDown + 2) = new char[TILE_SIZE_X] { 0, 0, 0, 2, 0, 0, 10, 10 };
	*(m_chArrTreeRightDown + 3) = new char[TILE_SIZE_X] { 2, 2, 0, 0, 0, 2, 10, 2 };
	*(m_chArrTreeRightDown + 4) = new char[TILE_SIZE_X] { 2, 2, 0, 2, 2, 2, 2, 10 };
	*(m_chArrTreeRightDown + 5) = new char[TILE_SIZE_X] { 2, 2, 2, 0, 2, 2, 2, 10 };
	*(m_chArrTreeRightDown + 6) = new char[TILE_SIZE_X] { 2, 0, 2, 2, 2, 2, 10, 10 };
	*(m_chArrTreeRightDown + 7) = new char[TILE_SIZE_X] { 2, 2, 2, 2, 10, 10, 10, 2 };

	m_chArrBuildingOutsideWall = new char* [TILE_SIZE_Y];
	*(m_chArrBuildingOutsideWall + 0) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 15, 15, 6, 15 };
	*(m_chArrBuildingOutsideWall + 1) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 15, 15, 6, 15 };
	*(m_chArrBuildingOutsideWall + 2) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 15, 15, 6, 15 };
	*(m_chArrBuildingOutsideWall + 3) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 15, 15, 6, 15 };
	*(m_chArrBuildingOutsideWall + 4) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 15, 15, 6, 15 };
	*(m_chArrBuildingOutsideWall + 5) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 15, 15, 6, 15 };
	*(m_chArrBuildingOutsideWall + 6) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 15, 15, 6, 15 };
	*(m_chArrBuildingOutsideWall + 7) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 15, 15, 6, 15 };

	m_chArrBuildingMiddleWall = new char* [TILE_SIZE_Y];
	*(m_chArrBuildingMiddleWall + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrBuildingMiddleWall + 1) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 15 };
	*(m_chArrBuildingMiddleWall + 2) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 15 };
	*(m_chArrBuildingMiddleWall + 3) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrBuildingMiddleWall + 4) = new char[TILE_SIZE_X] { 13, 13, 13, 15, 13, 13, 13, 13 };
	*(m_chArrBuildingMiddleWall + 5) = new char[TILE_SIZE_X] { 13, 13, 13, 15, 13, 13, 13, 13 };
	*(m_chArrBuildingMiddleWall + 6) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrBuildingMiddleWall + 7) = new char[TILE_SIZE_X] { 15, 13, 13, 13, 13, 13, 13, 15 };

	m_chArrBuildingOutsideDown = new char* [TILE_SIZE_Y];
	*(m_chArrBuildingOutsideDown + 0) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 15, 15, 6, 15 };
	*(m_chArrBuildingOutsideDown + 1) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 15, 15, 6, 15 };
	*(m_chArrBuildingOutsideDown + 2) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 14, 15, 6, 14 };
	*(m_chArrBuildingOutsideDown + 3) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 14, 14, 6, 6 };
	*(m_chArrBuildingOutsideDown + 4) = new char[TILE_SIZE_X] { 15, 6, 6, 0, 14, 14, 6, 6 };
	*(m_chArrBuildingOutsideDown + 5) = new char[TILE_SIZE_X] { 15, 6, 6, 6, 0, 14, 6, 6 };
	*(m_chArrBuildingOutsideDown + 6) = new char[TILE_SIZE_X] { 15, 6, 6, 6, 6, 0, 0, 0 };
	*(m_chArrBuildingOutsideDown + 7) = new char[TILE_SIZE_X] { 15, 6, 6, 6, 6, 6, 6, 6 };

	m_chArrBuildingMiddleDown = new char* [TILE_SIZE_Y];
	*(m_chArrBuildingMiddleDown + 0) = new char[TILE_SIZE_X] { 6, 15, 6, 15, 6, 15, 6, 15 };
	*(m_chArrBuildingMiddleDown + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrBuildingMiddleDown + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrBuildingMiddleDown + 3) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrBuildingMiddleDown + 4) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrBuildingMiddleDown + 5) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrBuildingMiddleDown + 6) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrBuildingMiddleDown + 7) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };

	m_chArrPoketSignLeft = new char* [TILE_SIZE_Y];
	*(m_chArrPoketSignLeft + 0) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 13 };
	*(m_chArrPoketSignLeft + 1) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrPoketSignLeft + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrPoketSignLeft + 3) = new char[TILE_SIZE_X] { 15, 0, 0, 15, 15, 0, 0, 15 };
	*(m_chArrPoketSignLeft + 4) = new char[TILE_SIZE_X] { 0, 15, 0, 15, 0, 15, 0, 15 };
	*(m_chArrPoketSignLeft + 5) = new char[TILE_SIZE_X] { 0, 0, 0, 15, 0, 15, 0, 15 };
	*(m_chArrPoketSignLeft + 6) = new char[TILE_SIZE_X] { 0, 15, 15, 15, 0, 15, 0, 15 };
	*(m_chArrPoketSignLeft + 7) = new char[TILE_SIZE_X] { 0, 15, 15, 15, 0, 0, 15, 15 };

	m_chArrPoketSignRight = new char* [TILE_SIZE_Y];
	*(m_chArrPoketSignRight + 0) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 13 };
	*(m_chArrPoketSignRight + 1) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrPoketSignRight + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 0, 15 };
	*(m_chArrPoketSignRight + 3) = new char[TILE_SIZE_X] { 0, 15, 0, 15, 15, 0, 15, 15 };
	*(m_chArrPoketSignRight + 4) = new char[TILE_SIZE_X] { 0, 15, 0, 15, 0, 0, 0, 15 };
	*(m_chArrPoketSignRight + 5) = new char[TILE_SIZE_X] { 0, 0, 15, 15, 0, 15, 0, 15 };
	*(m_chArrPoketSignRight + 6) = new char[TILE_SIZE_X] { 0, 15, 0, 15, 0, 0, 15, 15 };
	*(m_chArrPoketSignRight + 7) = new char[TILE_SIZE_X] { 0, 15, 0, 15, 15, 0, 0, 15 };

	m_chArrShopSignLeft = new char* [TILE_SIZE_Y];
	*(m_chArrShopSignLeft + 0) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 13 };
	*(m_chArrShopSignLeft + 1) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrShopSignLeft + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopSignLeft + 3) = new char[TILE_SIZE_X] { 0, 15, 15, 15, 0, 15, 15, 0 };
	*(m_chArrShopSignLeft + 4) = new char[TILE_SIZE_X] { 0, 0, 15, 0, 0, 15, 0, 15 };
	*(m_chArrShopSignLeft + 5) = new char[TILE_SIZE_X] { 0, 15, 0, 15, 0, 15, 0, 0 };
	*(m_chArrShopSignLeft + 6) = new char[TILE_SIZE_X] { 0, 15, 15, 15, 0, 15, 0, 15 };
	*(m_chArrShopSignLeft + 7) = new char[TILE_SIZE_X] { 0, 15, 15, 15, 0, 15, 0, 15 };

	m_chArrShopSignRight = new char* [TILE_SIZE_Y];
	*(m_chArrShopSignRight + 0) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 13 };
	*(m_chArrShopSignRight + 1) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrShopSignRight + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopSignRight + 3) = new char[TILE_SIZE_X] { 15, 15, 0, 0, 15, 0, 0, 0 };
	*(m_chArrShopSignRight + 4) = new char[TILE_SIZE_X] { 0, 15, 0, 15, 0, 15, 0, 15 };
	*(m_chArrShopSignRight + 5) = new char[TILE_SIZE_X] { 0, 15, 0, 0, 15, 15, 0, 15 };
	*(m_chArrShopSignRight + 6) = new char[TILE_SIZE_X] { 0, 15, 0, 15, 0, 15, 0, 15 };
	*(m_chArrShopSignRight + 7) = new char[TILE_SIZE_X] { 0, 15, 0, 15, 0, 15, 0, 15 };

	m_chArrSignDown = new char* [TILE_SIZE_Y];
	*(m_chArrSignDown + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrSignDown + 1) = new char[TILE_SIZE_X] { 15, 6, 6, 6, 6, 6, 6, 15 };
	*(m_chArrSignDown + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrSignDown + 3) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrSignDown + 4) = new char[TILE_SIZE_X] { 6, 6, 0, 15, 15, 0, 6, 6 };
	*(m_chArrSignDown + 5) = new char[TILE_SIZE_X] { 6, 6, 0, 15, 15, 0, 6, 6 };
	*(m_chArrSignDown + 6) = new char[TILE_SIZE_X] { 0, 0, 0, 15, 15, 0, 0, 0 };
	*(m_chArrSignDown + 7) = new char[TILE_SIZE_X] { 6, 6, 0, 0, 0, 0, 6, 6 };

	m_chArrDoorUp = new char* [TILE_SIZE_Y];
	*(m_chArrDoorUp + 0) = new char[TILE_SIZE_X] { 14, 6, 14, 14, 14, 14, 14, 14 };
	*(m_chArrDoorUp + 1) = new char[TILE_SIZE_X] { 14, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrDoorUp + 2) = new char[TILE_SIZE_X] { 14, 0, 6, 6, 6, 6, 6, 6 };
	*(m_chArrDoorUp + 3) = new char[TILE_SIZE_X] { 14, 0, 14, 0, 0, 0, 0, 0 };
	*(m_chArrDoorUp + 4) = new char[TILE_SIZE_X] { 14, 0, 14, 0, 15, 15, 15, 15 };
	*(m_chArrDoorUp + 5) = new char[TILE_SIZE_X] { 14, 0, 14, 0, 15, 15, 15, 15 };
	*(m_chArrDoorUp + 6) = new char[TILE_SIZE_X] { 14, 0, 14, 0, 15, 15, 15, 15 };
	*(m_chArrDoorUp + 7) = new char[TILE_SIZE_X] { 14, 0, 14, 0, 14, 14, 14, 14 };

	m_chArrDoorDown = new char* [TILE_SIZE_Y];
	*(m_chArrDoorDown + 0) = new char[TILE_SIZE_X] { 15, 0, 6, 0, 0, 0, 0, 0 };
	*(m_chArrDoorDown + 1) = new char[TILE_SIZE_X] { 15, 0, 6, 0, 0, 0, 0, 0 };
	*(m_chArrDoorDown + 2) = new char[TILE_SIZE_X] { 15, 0, 6, 6, 6, 6, 6, 6 };
	*(m_chArrDoorDown + 3) = new char[TILE_SIZE_X] { 15, 0, 6, 6, 6, 6, 6, 6 };
	*(m_chArrDoorDown + 4) = new char[TILE_SIZE_X] { 15, 0, 6, 6, 6, 6, 6, 6 };
	*(m_chArrDoorDown + 5) = new char[TILE_SIZE_X] { 15, 0, 6, 6, 6, 6, 6, 6 };
	*(m_chArrDoorDown + 6) = new char[TILE_SIZE_X] { 15, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrDoorDown + 7) = new char[TILE_SIZE_X] { 0, 0, 6, 6, 6, 6, 6, 6 };

	m_chArrRoofLeftUp = new char* [TILE_SIZE_Y];
	*(m_chArrRoofLeftUp + 0) = new char[TILE_SIZE_X] { 15, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrRoofLeftUp + 1) = new char[TILE_SIZE_X] { 0, 0, 15, 15, 15, 15, 15, 15 };
	*(m_chArrRoofLeftUp + 2) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftUp + 3) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftUp + 4) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftUp + 5) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftUp + 6) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftUp + 7) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };

	m_chArrRoofMiddleUp = new char* [TILE_SIZE_Y];
	*(m_chArrRoofMiddleUp + 0) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrRoofMiddleUp + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrRoofMiddleUp + 2) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleUp + 3) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleUp + 4) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleUp + 5) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleUp + 6) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleUp + 7) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };

	m_chArrRoofRightUp = new char* [TILE_SIZE_Y];
	*(m_chArrRoofRightUp + 0) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 15 };
	*(m_chArrRoofRightUp + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 5, 0, 0 };
	*(m_chArrRoofRightUp + 2) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightUp + 3) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightUp + 4) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightUp + 5) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightUp + 6) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightUp + 7) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };

	m_chArrRoofLeftMiddle = new char* [TILE_SIZE_Y];
	*(m_chArrRoofLeftMiddle + 0) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftMiddle + 1) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftMiddle + 2) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftMiddle + 3) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftMiddle + 4) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftMiddle + 5) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftMiddle + 6) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftMiddle + 7) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };

	m_chArrRoofMiddleMiddle = new char* [TILE_SIZE_Y];
	*(m_chArrRoofMiddleMiddle + 0) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleMiddle + 1) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleMiddle + 2) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleMiddle + 3) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleMiddle + 4) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleMiddle + 5) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleMiddle + 6) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleMiddle + 7) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };

	m_chArrRoofRightMiddle = new char* [TILE_SIZE_Y];
	*(m_chArrRoofRightMiddle + 0) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightMiddle + 1) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightMiddle + 2) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightMiddle + 3) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightMiddle + 4) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightMiddle + 5) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightMiddle + 6) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightMiddle + 7) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };

	m_chArrRoofLeftDown = new char* [TILE_SIZE_Y];
	*(m_chArrRoofLeftDown + 0) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftDown + 1) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftDown + 2) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftDown + 3) = new char[TILE_SIZE_X] { 0, 0, 15, 13, 13, 13, 5, 13 };
	*(m_chArrRoofLeftDown + 4) = new char[TILE_SIZE_X] { 0, 0, 5, 5, 5, 5, 5, 5 };
	*(m_chArrRoofLeftDown + 5) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrRoofLeftDown + 6) = new char[TILE_SIZE_X] { 0, 5, 5, 5, 5, 5, 5, 5 };
	*(m_chArrRoofLeftDown + 7) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };

	m_chArrRoofMiddleDown = new char* [TILE_SIZE_Y];
	*(m_chArrRoofMiddleDown + 0) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleDown + 1) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleDown + 2) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleDown + 3) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 13, 5, 13 };
	*(m_chArrRoofMiddleDown + 4) = new char[TILE_SIZE_X] { 5, 5, 5, 5, 5, 5, 5, 5 };
	*(m_chArrRoofMiddleDown + 5) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrRoofMiddleDown + 6) = new char[TILE_SIZE_X] { 5, 5, 5, 5, 5, 5, 5, 5 };
	*(m_chArrRoofMiddleDown + 7) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };

	m_chArrRoofRightDown = new char* [TILE_SIZE_Y];
	*(m_chArrRoofRightDown + 0) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightDown + 1) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightDown + 2) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightDown + 3) = new char[TILE_SIZE_X] { 13, 13, 5, 13, 13, 5, 0, 0 };
	*(m_chArrRoofRightDown + 4) = new char[TILE_SIZE_X] { 5, 5, 5, 5, 5, 5, 0, 0 };
	*(m_chArrRoofRightDown + 5) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };
	*(m_chArrRoofRightDown + 6) = new char[TILE_SIZE_X] { 5, 5, 5, 5, 5, 5, 5, 0 };
	*(m_chArrRoofRightDown + 7) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 0, 0, 0, 0 };

	m_chArrPoketmonGrass = new char* [TILE_SIZE_Y];
	*(m_chArrPoketmonGrass + 0) = new char[TILE_SIZE_X] { 10, 10, 10, 10, 10, 10, 10, 10 };
	*(m_chArrPoketmonGrass + 1) = new char[TILE_SIZE_X] { 10, 2, 10, 10, 10, 2, 10, 10 };
	*(m_chArrPoketmonGrass + 2) = new char[TILE_SIZE_X] { 2, 10, 2, 10, 2, 10, 2, 10 };
	*(m_chArrPoketmonGrass + 3) = new char[TILE_SIZE_X] { 2, 10, 10, 2, 10, 10, 2, 10 };
	*(m_chArrPoketmonGrass + 4) = new char[TILE_SIZE_X] { 10, 2, 10, 2, 10, 2, 10, 10 };
	*(m_chArrPoketmonGrass + 5) = new char[TILE_SIZE_X] { 10, 2, 2, 10, 2, 2, 10, 10 };
	*(m_chArrPoketmonGrass + 6) = new char[TILE_SIZE_X] { 10, 10, 2, 2, 2, 10, 10, 10 };
	*(m_chArrPoketmonGrass + 7) = new char[TILE_SIZE_X] { 10, 10, 10, 2, 10, 10, 10, 10 };

	m_chArrGymSignLeft = new char* [TILE_SIZE_Y];
	*(m_chArrGymSignLeft + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 13, 13, 13, 13 };
	*(m_chArrGymSignLeft + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrGymSignLeft + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 0, 0, 0 };
	*(m_chArrGymSignLeft + 3) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 0, 0, 15, 15 };
	*(m_chArrGymSignLeft + 4) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 0, 0, 15, 0 };
	*(m_chArrGymSignLeft + 5) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 0, 0, 15, 15 };
	*(m_chArrGymSignLeft + 6) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 0, 0, 0 };
	*(m_chArrGymSignLeft + 7) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };

	m_chArrGymSignMiddle = new char* [TILE_SIZE_Y];
	*(m_chArrGymSignMiddle + 0) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 13 };
	*(m_chArrGymSignMiddle + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrGymSignMiddle + 2) = new char[TILE_SIZE_X] { 0, 15, 0, 15, 15, 0, 15, 0 };
	*(m_chArrGymSignMiddle + 3) = new char[TILE_SIZE_X] { 15, 15, 0, 15, 15, 0, 15, 0 };
	*(m_chArrGymSignMiddle + 4) = new char[TILE_SIZE_X] { 0, 15, 0, 0, 0, 0, 15, 0 };
	*(m_chArrGymSignMiddle + 5) = new char[TILE_SIZE_X] { 0, 15, 15, 0, 0, 15, 15, 0 };
	*(m_chArrGymSignMiddle + 6) = new char[TILE_SIZE_X] { 0, 15, 15, 0, 0, 15, 15, 0 };
	*(m_chArrGymSignMiddle + 7) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };

	m_chArrGymSignRight = new char* [TILE_SIZE_Y];
	*(m_chArrGymSignRight + 0) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 15, 15, 15, 15 };
	*(m_chArrGymSignRight + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrGymSignRight + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 0, 15, 15, 15, 15 };
	*(m_chArrGymSignRight + 3) = new char[TILE_SIZE_X] { 0, 15, 0, 0, 15, 15, 15, 15 };
	*(m_chArrGymSignRight + 4) = new char[TILE_SIZE_X] { 0, 0, 0, 0, 15, 15, 15, 15 };
	*(m_chArrGymSignRight + 5) = new char[TILE_SIZE_X] { 15, 0, 15, 0, 15, 15, 15, 15 };
	*(m_chArrGymSignRight + 6) = new char[TILE_SIZE_X] { 15, 0, 15, 0, 15, 15, 15, 15 };
	*(m_chArrGymSignRight + 7) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };


	m_eMapTile_Type = new EMapTile_Type * [VILLAGE_MAP_SIZE_Y];
	*(m_eMapTile_Type + 0) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 체육관 지붕 맨위
		EMapTile_Type::ROOF_LEFTUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP,
		EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP,
		EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP,
		EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_RIGHTUP,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 상점 지붕 맨위
		EMapTile_Type::ROOF_LEFTUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP,
		EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_RIGHTUP,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 포켓몬 센터 지붕 맨위
		EMapTile_Type::ROOF_LEFTUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP,
		EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_MIDDLEUP, EMapTile_Type::ROOF_RIGHTUP
	};

	*(m_eMapTile_Type + 1) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 체육관 지붕 중간
		EMapTile_Type::ROOF_LEFTMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE,
		EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE,
		EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE,
		EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_RIGHTMIDDLE,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		// 상점 지붕 중간
		EMapTile_Type::ROOF_LEFTMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE,
		EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_RIGHTMIDDLE,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		// 포켓몬 센터 지붕 중간
		EMapTile_Type::ROOF_LEFTMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE,
		EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_RIGHTMIDDLE
	};

	*(m_eMapTile_Type + 2) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 체육관 지붕 중간
		EMapTile_Type::ROOF_LEFTMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE,
		EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE,
		EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE,
		EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_RIGHTMIDDLE,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 상점 지붕 중간
		EMapTile_Type::ROOF_LEFTMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE,
		EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_RIGHTMIDDLE,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 포켓몬 센터 지붕 중간
		EMapTile_Type::ROOF_LEFTMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE,
		EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_MIDDLEMIDDLE, EMapTile_Type::ROOF_RIGHTMIDDLE
	};

	*(m_eMapTile_Type + 3) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 체육관 지붕 밑
		EMapTile_Type::ROOF_LEFTDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN,
		EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN,
		EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN,
		EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_RIGHTDOWN,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		// 상점 지붕 밑
		EMapTile_Type::ROOF_LEFTDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN,
		EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_RIGHTDOWN,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		// 포켓몬 센터 지붕 밑
		EMapTile_Type::ROOF_LEFTDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN,
		EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_MIDDLEDOWN, EMapTile_Type::ROOF_RIGHTDOWN
	};

	*(m_eMapTile_Type + 4) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 체육관 벽, GYM 글자
		EMapTile_Type::BUILDING_LEFTWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::GYM_SIGN_LEFT, EMapTile_Type::GYM_SIGN_MIDDLE,
		EMapTile_Type::GYM_SIGN_RIGHT, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_RIGHTWALL,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 상점 벽
		EMapTile_Type::BUILDING_LEFTWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_RIGHTWALL,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 포켓몬 센터 벽
		EMapTile_Type::BUILDING_LEFTWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_RIGHTWALL
	};

	*(m_eMapTile_Type + 5) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 체육관 벽
		EMapTile_Type::BUILDING_LEFTWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_RIGHTWALL,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		// 상점 벽
		EMapTile_Type::BUILDING_LEFTWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_RIGHTWALL,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		// 포켓몬 센터 벽
		EMapTile_Type::BUILDING_LEFTWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_RIGHTWALL
	};

	*(m_eMapTile_Type + 6) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 체육관 벽, 문 위
		EMapTile_Type::BUILDING_LEFTWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::GYM_DOOR_LEFTUP, EMapTile_Type::GYM_DOOR_RIGHTUP,
		EMapTile_Type::GYM_DOOR_LEFTUP, EMapTile_Type::GYM_DOOR_RIGHTUP, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL,
		EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_RIGHTWALL,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 상점 벽, 문 위, 표지판 위
		EMapTile_Type::BUILDING_LEFTWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::SHOP_DOOR_LEFTUP, EMapTile_Type::SHOP_DOOR_RIGHTUP,
		EMapTile_Type::SHOP_SIGN_LEFT, EMapTile_Type::SHOP_SIGN_RIGHT, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_RIGHTWALL,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 포켓몬 센터 벽, 문 위, 표지판 위
		EMapTile_Type::BUILDING_LEFTWALL, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::POKETMONCENTER_DOOR_LEFTUP, EMapTile_Type::POKETMONCENTER_DOOR_RIGHTUP,
		EMapTile_Type::POKET_SIGN_LEFT, EMapTile_Type::POKET_SIGN_RIGHT, EMapTile_Type::BUILDING_MIDDLEWALL, EMapTile_Type::BUILDING_RIGHTWALL
	};

	*(m_eMapTile_Type + 7) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 체육관 벽 아래, 문 아래
		EMapTile_Type::BUILDING_LEFTDOWN, EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::BUILDING_MIDDLEDOWN,
		EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::GYM_DOOR_LEFTDOWN, EMapTile_Type::GYM_DOOR_RIGHTDOWN,
		EMapTile_Type::GYM_DOOR_LEFTDOWN, EMapTile_Type::GYM_DOOR_RIGHTDOWN, EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::BUILDING_MIDDLEDOWN,
		EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::BUILDING_RIGHTDOWN,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		// 상점 벽 아래, 문 아래, 표지판 아래
		EMapTile_Type::BUILDING_LEFTDOWN, EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::SHOP_DOOR_LEFTDOWN, EMapTile_Type::SHOP_DOOR_RIGHTDOWN,
		EMapTile_Type::SIGN_DOWN, EMapTile_Type::SIGN_DOWN, EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::BUILDING_RIGHTDOWN,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		// 포켓몬 센터 벽 아래, 문 아래, 표지판 아래
		EMapTile_Type::BUILDING_LEFTDOWN, EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::POKETMONCENTER_DOOR_LEFTDOWN, EMapTile_Type::POKETMONCENTER_DOOR_RIGHTDOWN,
		EMapTile_Type::SIGN_DOWN, EMapTile_Type::SIGN_DOWN, EMapTile_Type::BUILDING_MIDDLEDOWN, EMapTile_Type::BUILDING_RIGHTDOWN
	};

	*(m_eMapTile_Type + 8) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 9) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 10) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 11) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 12) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 13) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 14) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 15) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 16) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 잔디
		EMapTile_Type::ROAD_GRASS, EMapTile_Type::ROAD_GRASS,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 17) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		// 잔디
		EMapTile_Type::ROAD_GRASS, EMapTile_Type::ROAD_GRASS,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 18) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 잔디
		EMapTile_Type::ROAD_GRASS, EMapTile_Type::ROAD_GRASS,

		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		// 길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 19) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 잔디
		EMapTile_Type::ROAD_GRASS, EMapTile_Type::ROAD_GRASS,

		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		//길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 20) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 잔디
		EMapTile_Type::ROAD_GRASS, EMapTile_Type::ROAD_GRASS,

		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		//길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 21) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 잔디
		EMapTile_Type::ROAD_GRASS, EMapTile_Type::ROAD_GRASS,

		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		//길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 22) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 잔디
		EMapTile_Type::ROAD_GRASS, EMapTile_Type::ROAD_GRASS,

		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		//길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 23) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 잔디
		EMapTile_Type::ROAD_GRASS, EMapTile_Type::ROAD_GRASS,

		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		//길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 24) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 잔디
		EMapTile_Type::ROAD_GRASS, EMapTile_Type::ROAD_GRASS,

		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 나무 위
		EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP, EMapTile_Type::TREE_LEFTUP, EMapTile_Type::TREE_RIGHTUP,

		//길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	*(m_eMapTile_Type + 25) = new EMapTile_Type[VILLAGE_MAP_SIZE_X]
	{
		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 잔디
		EMapTile_Type::ROAD_GRASS, EMapTile_Type::ROAD_GRASS,

		// 포켓몬 출현 잔디
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,
		EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS, EMapTile_Type::POKETMON_GRASS,

		// 나무 아래
		EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN, EMapTile_Type::TREE_LEFTDOWN, EMapTile_Type::TREE_RIGHTDOWN,

		//길
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE,
		EMapTile_Type::ROAD_STONE, EMapTile_Type::ROAD_STONE
	};

	m_chArrMap = new char* [VILLAGE_MAP_SIZE_MAX_Y];
	for (int i = 0; i < VILLAGE_MAP_SIZE_Y; i++)
	{
		*(m_chArrMap + 0 + i * TILE_SIZE_Y) = new char[VILLAGE_MAP_SIZE_MAX_X];
		*(m_chArrMap + 1 + i * TILE_SIZE_Y) = new char[VILLAGE_MAP_SIZE_MAX_X];
		*(m_chArrMap + 2 + i * TILE_SIZE_Y) = new char[VILLAGE_MAP_SIZE_MAX_X];
		*(m_chArrMap + 3 + i * TILE_SIZE_Y) = new char[VILLAGE_MAP_SIZE_MAX_X];
		*(m_chArrMap + 4 + i * TILE_SIZE_Y) = new char[VILLAGE_MAP_SIZE_MAX_X];
		*(m_chArrMap + 5 + i * TILE_SIZE_Y) = new char[VILLAGE_MAP_SIZE_MAX_X];
		*(m_chArrMap + 6 + i * TILE_SIZE_Y) = new char[VILLAGE_MAP_SIZE_MAX_X];
		*(m_chArrMap + 7 + i * TILE_SIZE_Y) = new char[VILLAGE_MAP_SIZE_MAX_X];

		for (int j = 0; j < VILLAGE_MAP_SIZE_X; j++)
		{
			switch (*(*(m_eMapTile_Type + i) + j))
			{
				// 지나갈 수 있는 것들
			case EMapTile_Type::ROAD_STONE:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrStoneRoad + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROAD_GRASS:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGrassRoad + y) + x);
					}
				}
				break;

			case EMapTile_Type::POKETMON_GRASS:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketmonGrass + y) + x);
					}
				}
				break;


				// 지나가고 트리거
			case EMapTile_Type::POKETMONCENTER_DOOR_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::POKETMONCENTER_DOOR_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorUp + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::POKETMONCENTER_DOOR_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::POKETMONCENTER_DOOR_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorDown + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::SHOP_DOOR_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_DOOR_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorUp + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::SHOP_DOOR_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_DOOR_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorDown + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::GYM_DOOR_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_DOOR_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorUp + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::GYM_DOOR_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_DOOR_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrDoorDown + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;


				// 지나가지 못하는 것들
			case EMapTile_Type::TREE_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrTreeLeftUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::TREE_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrTreeRightUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::TREE_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrTreeLeftDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::TREE_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrTreeRightDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::BUILDING_LEFTWALL:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrBuildingOutsideWall + y) + x);
					}
				}
				break;

			case EMapTile_Type::BUILDING_MIDDLEWALL:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrBuildingMiddleWall + y) + x);
					}
				}
				break;

			case EMapTile_Type::BUILDING_RIGHTWALL:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrBuildingOutsideWall + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::BUILDING_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrBuildingOutsideDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::BUILDING_MIDDLEDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrBuildingMiddleDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::BUILDING_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrBuildingOutsideDown + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::POKET_SIGN_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketSignLeft + y) + x);
					}
				}
				break;

			case EMapTile_Type::POKET_SIGN_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketSignRight + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_SIGN_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopSignLeft + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_SIGN_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopSignRight + y) + x);
					}
				}
				break;

			case EMapTile_Type::SIGN_DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrSignDown + y) + x);
					}
				}
				break;



			case EMapTile_Type::ROOF_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrRoofLeftUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROOF_MIDDLEUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrRoofMiddleUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROOF_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrRoofRightUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROOF_LEFTMIDDLE:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrRoofLeftMiddle + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROOF_MIDDLEMIDDLE:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrRoofMiddleMiddle + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROOF_RIGHTMIDDLE:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrRoofRightMiddle + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROOF_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrRoofLeftDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROOF_MIDDLEDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrRoofMiddleDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROOF_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrRoofRightDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_SIGN_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymSignLeft + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_SIGN_MIDDLE:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymSignMiddle + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_SIGN_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymSignRight + y) + x);
					}
				}
				break;
			}
		}
	}
}