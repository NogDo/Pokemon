#include "PoketmonCenterMap.h"

PoketmonCenterMap::PoketmonCenterMap()
{
	Init();
}

PoketmonCenterMap::~PoketmonCenterMap()
{
	for (int i = 0; i < TILE_SIZE_X; i++)
	{
		delete[] * (m_chArrPoketmonCenterRoad + i);
		delete[] * (m_chArrPoketmonCenterWall + i);
		delete[] * (m_chArrHealingMachine1Outside + i);
		delete[] * (m_chArrHealingMachine1Middle + i);
		delete[] * (m_chArrHealingMachine2Outside + i);
		delete[] * (m_chArrHealingMachine2Middle + i);
		delete[] * (m_chArrHealingMachine3Outside + i);
		delete[] * (m_chArrHealingMachine3Middle + i);
		delete[] * (m_chArrHealingMachine4Outside + i);
		delete[] * (m_chArrHealingMachine4Middle + i);
		delete[] * (m_chArrHealingMachine5LeftUp + i);
		delete[] * (m_chArrHealingMachine5LeftDown + i);
		delete[] * (m_chArrHealingMachine5RightUp + i);
		delete[] * (m_chArrHealingMachine5RightDown + i);
		delete[] * (m_chArrHealingMachine6LeftUp + i);
		delete[] * (m_chArrHealingMachine6LeftDown + i);
		delete[] * (m_chArrHealingMachine6RightUp + i);
		delete[] * (m_chArrHealingMachine6RightDown + i);
		delete[] * (m_chArrPoketmonCenterTableUp + i);
		delete[] * (m_chArrPoketmonCenterTableDown + i);
		delete[] * (m_chArrPoketmonCenterTableBell + i);
		delete[] * (m_chArrPoketmonCenterTableVertical + i);
		delete[] * (m_chArrPoketmonCenterCarpet + i);
	}

	delete[] m_chArrPoketmonCenterRoad;
	delete[] m_chArrPoketmonCenterWall;
	delete[] m_chArrHealingMachine1Outside;
	delete[] m_chArrHealingMachine1Middle;
	delete[] m_chArrHealingMachine2Outside;
	delete[] m_chArrHealingMachine2Middle;
	delete[] m_chArrHealingMachine3Outside;
	delete[] m_chArrHealingMachine3Middle;
	delete[] m_chArrHealingMachine4Outside;
	delete[] m_chArrHealingMachine4Middle;
	delete[] m_chArrHealingMachine5LeftUp;
	delete[] m_chArrHealingMachine5LeftDown;
	delete[] m_chArrHealingMachine5RightUp;
	delete[] m_chArrHealingMachine5RightDown;
	delete[] m_chArrHealingMachine6LeftUp;
	delete[] m_chArrHealingMachine6LeftDown;
	delete[] m_chArrHealingMachine6RightUp;
	delete[] m_chArrHealingMachine6RightDown;
	delete[] m_chArrPoketmonCenterTableUp;
	delete[] m_chArrPoketmonCenterTableDown;
	delete[] m_chArrPoketmonCenterTableBell;
	delete[] m_chArrPoketmonCenterTableVertical;
	delete[] m_chArrPoketmonCenterCarpet;
}

/// <summary>
/// 타일 및 맵 초기화
/// </summary>
void PoketmonCenterMap::Init()
{
	m_MapType = EMap_Type::POKETMONCENTER;

	m_chArrPoketmonCenterRoad = new char* [TILE_SIZE_Y];
	*(m_chArrPoketmonCenterRoad + 0) = new char[TILE_SIZE_X] { 15, 13, 13, 13, 13, 13, 13, 15 };
	*(m_chArrPoketmonCenterRoad + 1) = new char[TILE_SIZE_X] { 13, 15, 13, 13, 13, 13, 15, 13 };
	*(m_chArrPoketmonCenterRoad + 2) = new char[TILE_SIZE_X] { 13, 13, 15, 13, 13, 15, 13, 13 };
	*(m_chArrPoketmonCenterRoad + 3) = new char[TILE_SIZE_X] { 13, 13, 13, 15, 15, 13, 13, 13 };
	*(m_chArrPoketmonCenterRoad + 4) = new char[TILE_SIZE_X] { 13, 13, 13, 15, 15, 13, 13, 13 };
	*(m_chArrPoketmonCenterRoad + 5) = new char[TILE_SIZE_X] { 13, 13, 15, 13, 13, 15, 13, 13 };
	*(m_chArrPoketmonCenterRoad + 6) = new char[TILE_SIZE_X] { 13, 15, 13, 13, 13, 13, 15, 13 };
	*(m_chArrPoketmonCenterRoad + 7) = new char[TILE_SIZE_X] { 15, 13, 13, 13, 13, 13, 13, 15 };

	m_chArrPoketmonCenterWall = new char* [TILE_SIZE_Y];
	*(m_chArrPoketmonCenterWall + 0) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrPoketmonCenterWall + 1) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrPoketmonCenterWall + 2) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrPoketmonCenterWall + 3) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrPoketmonCenterWall + 4) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrPoketmonCenterWall + 5) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrPoketmonCenterWall + 6) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrPoketmonCenterWall + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrHealingMachine1Outside = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine1Outside + 0) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 8 };
	*(m_chArrHealingMachine1Outside + 1) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 8 };
	*(m_chArrHealingMachine1Outside + 2) = new char[TILE_SIZE_X] { 8, 7, 7, 8, 8, 8, 8, 15 };
	*(m_chArrHealingMachine1Outside + 3) = new char[TILE_SIZE_X] { 8, 7, 8, 15, 7, 15, 7, 15 };
	*(m_chArrHealingMachine1Outside + 4) = new char[TILE_SIZE_X] { 8, 8, 7, 15, 7, 15, 7, 15 };
	*(m_chArrHealingMachine1Outside + 5) = new char[TILE_SIZE_X] { 8, 8, 15, 7, 8, 8, 8, 15 };
	*(m_chArrHealingMachine1Outside + 6) = new char[TILE_SIZE_X] { 8, 8, 15, 15, 8, 8, 7, 8 };
	*(m_chArrHealingMachine1Outside + 7) = new char[TILE_SIZE_X] { 8, 8, 7, 8, 7, 8, 8, 8 };

	m_chArrHealingMachine1Middle = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine1Middle + 0) = new char[TILE_SIZE_X] { 8, 10, 10, 10, 10, 10, 10, 8 };
	*(m_chArrHealingMachine1Middle + 1) = new char[TILE_SIZE_X] { 8, 10, 10, 10, 10, 10, 10, 8 };
	*(m_chArrHealingMachine1Middle + 2) = new char[TILE_SIZE_X] { 8, 10, 2, 2, 2, 2, 2, 2 };
	*(m_chArrHealingMachine1Middle + 3) = new char[TILE_SIZE_X] { 8, 10, 2, 2, 2, 15, 2, 2 };
	*(m_chArrHealingMachine1Middle + 4) = new char[TILE_SIZE_X] { 8, 10, 2, 2, 15, 2, 15, 15 };
	*(m_chArrHealingMachine1Middle + 5) = new char[TILE_SIZE_X] { 8, 10, 2, 2, 2, 2, 2, 2 };
	*(m_chArrHealingMachine1Middle + 6) = new char[TILE_SIZE_X] { 8, 8, 2, 2, 2, 2, 2, 2 };
	*(m_chArrHealingMachine1Middle + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrHealingMachine2Outside = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine2Outside + 0) = new char[TILE_SIZE_X] { 7, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine2Outside + 1) = new char[TILE_SIZE_X] { 7, 7, 8, 8, 8, 7, 7, 7 };
	*(m_chArrHealingMachine2Outside + 2) = new char[TILE_SIZE_X] { 7, 7, 8, 7, 7, 7, 7, 7 };
	*(m_chArrHealingMachine2Outside + 3) = new char[TILE_SIZE_X] { 7, 8, 7, 7, 15, 15, 8, 8 };
	*(m_chArrHealingMachine2Outside + 4) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 15, 15, 8, 15 };
	*(m_chArrHealingMachine2Outside + 5) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 8, 15 };
	*(m_chArrHealingMachine2Outside + 6) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 8, 8 };
	*(m_chArrHealingMachine2Outside + 7) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 7, 8 };

	m_chArrHealingMachine2Middle = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine2Middle + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 7, 15, 15 };
	*(m_chArrHealingMachine2Middle + 1) = new char[TILE_SIZE_X] { 8, 7, 7, 15, 7, 7, 15, 15 };
	*(m_chArrHealingMachine2Middle + 2) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 8, 7, 7, 7 };
	*(m_chArrHealingMachine2Middle + 3) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine2Middle + 4) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine2Middle + 5) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine2Middle + 6) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine2Middle + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrHealingMachine3Outside = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine3Outside + 0) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 7, 8 };
	*(m_chArrHealingMachine3Outside + 1) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 7, 8 };
	*(m_chArrHealingMachine3Outside + 2) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 7, 8 };
	*(m_chArrHealingMachine3Outside + 3) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 8, 8 };
	*(m_chArrHealingMachine3Outside + 4) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 8, 15 };
	*(m_chArrHealingMachine3Outside + 5) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 8, 15 };
	*(m_chArrHealingMachine3Outside + 6) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 8, 8 };
	*(m_chArrHealingMachine3Outside + 7) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 15, 15, 7, 7 };

	m_chArrHealingMachine3Middle = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine3Middle + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8};
	*(m_chArrHealingMachine3Middle + 1) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine3Middle + 2) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine3Middle + 3) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine3Middle + 4) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine3Middle + 5) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine3Middle + 6) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine3Middle + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrHealingMachine4Outside = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine4Outside + 0) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrHealingMachine4Outside + 1) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 8, 8, 8 };
	*(m_chArrHealingMachine4Outside + 2) = new char[TILE_SIZE_X] { 8, 7, 7, 8, 8, 8, 8, 7 };
	*(m_chArrHealingMachine4Outside + 3) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 8, 7, 15, 15 };
	*(m_chArrHealingMachine4Outside + 4) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 7, 15, 8, 8 };
	*(m_chArrHealingMachine4Outside + 5) = new char[TILE_SIZE_X] { 7, 7, 7, 8, 15, 15, 8, 8 };
	*(m_chArrHealingMachine4Outside + 6) = new char[TILE_SIZE_X] { 7, 7, 7, 8, 15, 15, 15, 15 };
	*(m_chArrHealingMachine4Outside + 7) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 8, 8, 8, 8 };

	m_chArrHealingMachine4Middle = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine4Middle + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8};
	*(m_chArrHealingMachine4Middle + 1) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 15, 15, 15, 12 };
	*(m_chArrHealingMachine4Middle + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 8, 15, 15, 15, 12 };
	*(m_chArrHealingMachine4Middle + 3) = new char[TILE_SIZE_X] { 15, 15, 15, 8, 15, 12, 12, 12 };
	*(m_chArrHealingMachine4Middle + 4) = new char[TILE_SIZE_X] { 8, 15, 15, 8, 15, 12, 12, 12 };
	*(m_chArrHealingMachine4Middle + 5) = new char[TILE_SIZE_X] { 8, 15, 15, 8, 15, 15, 15, 12 };
	*(m_chArrHealingMachine4Middle + 6) = new char[TILE_SIZE_X] { 15, 15, 15, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine4Middle + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrHealingMachine5LeftUp = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine5LeftUp + 0) = new char[TILE_SIZE_X] { 8, 8, 9, 15, 3, 3, 8, 8 };
	*(m_chArrHealingMachine5LeftUp + 1) = new char[TILE_SIZE_X] { 8, 9, 15, 3, 3, 3, 15, 15 };
	*(m_chArrHealingMachine5LeftUp + 2) = new char[TILE_SIZE_X] { 8, 9, 3, 3, 15, 3, 3, 3 };
	*(m_chArrHealingMachine5LeftUp + 3) = new char[TILE_SIZE_X] { 8, 9, 3, 15, 3, 3, 3, 3 };
	*(m_chArrHealingMachine5LeftUp + 4) = new char[TILE_SIZE_X] { 8, 9, 3, 3, 3, 3, 3, 3 };
	*(m_chArrHealingMachine5LeftUp + 5) = new char[TILE_SIZE_X] { 8, 9, 9, 9, 9, 9, 9, 9 };
	*(m_chArrHealingMachine5LeftUp + 6) = new char[TILE_SIZE_X] { 8, 9, 1, 1, 1, 1, 1, 1 };
	*(m_chArrHealingMachine5LeftUp + 7) = new char[TILE_SIZE_X] { 8, 9, 1, 9, 9, 9, 9, 9 };

	m_chArrHealingMachine5LeftDown = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine5LeftDown + 0) = new char[TILE_SIZE_X] { 8, 9, 1, 9, 9, 9, 9, 15 };
	*(m_chArrHealingMachine5LeftDown + 1) = new char[TILE_SIZE_X] { 8, 9, 1, 9, 9, 9, 15, 15 };
	*(m_chArrHealingMachine5LeftDown + 2) = new char[TILE_SIZE_X] { 8, 9, 1, 9, 9, 15, 15, 15 };
	*(m_chArrHealingMachine5LeftDown + 3) = new char[TILE_SIZE_X] { 8, 9, 1, 9, 15, 15, 15, 9 };
	*(m_chArrHealingMachine5LeftDown + 4) = new char[TILE_SIZE_X] { 8, 9, 1, 15, 15, 15, 9, 15 };
	*(m_chArrHealingMachine5LeftDown + 5) = new char[TILE_SIZE_X] { 8, 9, 9, 1, 1, 1, 1, 1 };
	*(m_chArrHealingMachine5LeftDown + 6) = new char[TILE_SIZE_X] { 8, 8, 9, 9, 9, 9, 9, 9 };
	*(m_chArrHealingMachine5LeftDown + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrHealingMachine5RightUp = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine5RightUp + 0) = new char[TILE_SIZE_X] { 8, 8, 3, 3, 15, 9, 8, 8 };
	*(m_chArrHealingMachine5RightUp + 1) = new char[TILE_SIZE_X] { 15, 3, 3, 3, 9, 15, 9, 8 };
	*(m_chArrHealingMachine5RightUp + 2) = new char[TILE_SIZE_X] { 3, 3, 3, 3, 3, 3, 3, 8 };
	*(m_chArrHealingMachine5RightUp + 3) = new char[TILE_SIZE_X] { 3, 3, 3, 3, 3, 3, 9, 8 };
	*(m_chArrHealingMachine5RightUp + 4) = new char[TILE_SIZE_X] { 3, 3, 3, 3, 3, 3, 9, 8 };
	*(m_chArrHealingMachine5RightUp + 5) = new char[TILE_SIZE_X] { 9, 9, 9, 9, 9, 9, 9, 8 };
	*(m_chArrHealingMachine5RightUp + 6) = new char[TILE_SIZE_X] { 1, 1, 1, 1, 1, 1, 9, 8 };
	*(m_chArrHealingMachine5RightUp + 7) = new char[TILE_SIZE_X] { 15, 15, 15, 9, 15, 1, 9, 8 };

	m_chArrHealingMachine5RightDown = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine5RightDown + 0) = new char[TILE_SIZE_X] { 15, 15, 9, 15, 9, 1, 9, 8 };
	*(m_chArrHealingMachine5RightDown + 1) = new char[TILE_SIZE_X] { 15, 9, 15, 9, 9, 1, 9, 8 };
	*(m_chArrHealingMachine5RightDown + 2) = new char[TILE_SIZE_X] { 9, 15, 9, 9, 9, 1, 9, 8 };
	*(m_chArrHealingMachine5RightDown + 3) = new char[TILE_SIZE_X] { 15, 9, 9, 9, 9, 1, 9, 8 };
	*(m_chArrHealingMachine5RightDown + 4) = new char[TILE_SIZE_X] { 9, 9, 9, 9, 9, 1, 9, 8 };
	*(m_chArrHealingMachine5RightDown + 5) = new char[TILE_SIZE_X] { 1, 1, 1, 1, 1, 9, 9, 8 };
	*(m_chArrHealingMachine5RightDown + 6) = new char[TILE_SIZE_X] { 9, 9, 9, 9, 9, 9, 8, 8 };
	*(m_chArrHealingMachine5RightDown + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrHealingMachine6LeftUp = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine6LeftUp + 0) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine6LeftUp + 1) = new char[TILE_SIZE_X] { 8, 7, 8, 14, 14, 14, 14, 14 };
	*(m_chArrHealingMachine6LeftUp + 2) = new char[TILE_SIZE_X] { 8, 7, 8, 14, 14, 14, 14, 14 };
	*(m_chArrHealingMachine6LeftUp + 3) = new char[TILE_SIZE_X] { 8, 7, 8, 14, 14, 14, 14, 14 };
	*(m_chArrHealingMachine6LeftUp + 4) = new char[TILE_SIZE_X] { 8, 7, 8, 14, 14, 14, 14, 14 };
	*(m_chArrHealingMachine6LeftUp + 5) = new char[TILE_SIZE_X] { 8, 7, 8, 14, 14, 14, 14, 14 };
	*(m_chArrHealingMachine6LeftUp + 6) = new char[TILE_SIZE_X] { 8, 7, 8, 14, 14, 14, 14, 14 };
	*(m_chArrHealingMachine6LeftUp + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 14, 14, 14, 14, 14 };

	m_chArrHealingMachine6LeftDown = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine6LeftDown + 0) = new char[TILE_SIZE_X] { 8, 8, 7, 8, 8, 8, 7, 8 };
	*(m_chArrHealingMachine6LeftDown + 1) = new char[TILE_SIZE_X] { 8, 7, 7, 14, 7, 14, 7, 8 };
	*(m_chArrHealingMachine6LeftDown + 2) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 8 };
	*(m_chArrHealingMachine6LeftDown + 3) = new char[TILE_SIZE_X] { 8, 7, 7, 14, 7, 14, 7, 8 };
	*(m_chArrHealingMachine6LeftDown + 4) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 14, 7, 8 };
	*(m_chArrHealingMachine6LeftDown + 5) = new char[TILE_SIZE_X] { 8, 7, 7, 14, 7, 14, 7, 8 };
	*(m_chArrHealingMachine6LeftDown + 6) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 14, 7, 8 };
	*(m_chArrHealingMachine6LeftDown + 7) = new char[TILE_SIZE_X] { 8, 7, 7, 14, 7, 7, 7, 8 };

	m_chArrHealingMachine6RightUp = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine6RightUp + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine6RightUp + 1) = new char[TILE_SIZE_X] { 8, 7, 8, 7, 8, 14, 7, 8 };
	*(m_chArrHealingMachine6RightUp + 2) = new char[TILE_SIZE_X] { 8, 7, 8, 7, 7, 7, 7, 7 };
	*(m_chArrHealingMachine6RightUp + 3) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine6RightUp + 4) = new char[TILE_SIZE_X] { 8, 7, 8, 7, 7, 7, 7, 7 };
	*(m_chArrHealingMachine6RightUp + 5) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine6RightUp + 6) = new char[TILE_SIZE_X] { 8, 7, 7, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine6RightUp + 7) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 7 };

	m_chArrHealingMachine6RightDown = new char* [TILE_SIZE_Y];
	*(m_chArrHealingMachine6RightDown + 0) = new char[TILE_SIZE_X] { 8, 7, 7, 14, 14, 14, 7, 8 };
	*(m_chArrHealingMachine6RightDown + 1) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine6RightDown + 2) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 8 };
	*(m_chArrHealingMachine6RightDown + 3) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine6RightDown + 4) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 8 };
	*(m_chArrHealingMachine6RightDown + 5) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrHealingMachine6RightDown + 6) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 7 };
	*(m_chArrHealingMachine6RightDown + 7) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };

	m_chArrPoketmonCenterTableUp = new char* [TILE_SIZE_Y];
	*(m_chArrPoketmonCenterTableUp + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrPoketmonCenterTableUp + 1) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrPoketmonCenterTableUp + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrPoketmonCenterTableUp + 3) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrPoketmonCenterTableUp + 4) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrPoketmonCenterTableUp + 5) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrPoketmonCenterTableUp + 6) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrPoketmonCenterTableUp + 7) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };

	m_chArrPoketmonCenterTableDown = new char* [TILE_SIZE_Y];
	*(m_chArrPoketmonCenterTableDown + 0) = new char[TILE_SIZE_X] { 3, 3, 3, 3, 3, 3, 3, 3 };
	*(m_chArrPoketmonCenterTableDown + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrPoketmonCenterTableDown + 2) = new char[TILE_SIZE_X] { 1, 1, 1, 1, 1, 1, 1, 1 };
	*(m_chArrPoketmonCenterTableDown + 3) = new char[TILE_SIZE_X] { 9, 9, 9, 9, 9, 9, 9, 9 };
	*(m_chArrPoketmonCenterTableDown + 4) = new char[TILE_SIZE_X] { 9, 9, 9, 9, 9, 9, 9, 9 };
	*(m_chArrPoketmonCenterTableDown + 5) = new char[TILE_SIZE_X] { 9, 9, 9, 9, 9, 9, 9, 9 };
	*(m_chArrPoketmonCenterTableDown + 6) = new char[TILE_SIZE_X] { 9, 9, 9, 9, 9, 9, 9, 9 };
	*(m_chArrPoketmonCenterTableDown + 7) = new char[TILE_SIZE_X] { 1, 1, 1, 1, 1, 1, 1, 1 };

	m_chArrPoketmonCenterTableBell = new char* [TILE_SIZE_Y];
	*(m_chArrPoketmonCenterTableBell + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrPoketmonCenterTableBell + 1) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrPoketmonCenterTableBell + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 0, 0, 0, 15, 15 };
	*(m_chArrPoketmonCenterTableBell + 3) = new char[TILE_SIZE_X] { 15, 15, 0, 0, 15, 0, 0, 15 };
	*(m_chArrPoketmonCenterTableBell + 4) = new char[TILE_SIZE_X] { 15, 0, 15, 0, 0, 0, 15, 0 };
	*(m_chArrPoketmonCenterTableBell + 5) = new char[TILE_SIZE_X] { 15, 0, 7, 15, 15, 15, 7, 0 };
	*(m_chArrPoketmonCenterTableBell + 6) = new char[TILE_SIZE_X] { 15, 15, 0, 7, 7, 7, 0, 15 };
	*(m_chArrPoketmonCenterTableBell + 7) = new char[TILE_SIZE_X] { 15, 15, 15, 0, 0, 0, 15, 15 };

	m_chArrPoketmonCenterTableVertical = new char* [TILE_SIZE_Y];
	*(m_chArrPoketmonCenterTableVertical + 0) = new char[TILE_SIZE_X] { 1, 9, 15, 15, 15, 15, 15, 3 };
	*(m_chArrPoketmonCenterTableVertical + 1) = new char[TILE_SIZE_X] { 1, 9, 15, 15, 15, 15, 15, 3 };
	*(m_chArrPoketmonCenterTableVertical + 2) = new char[TILE_SIZE_X] { 1, 9, 15, 15, 15, 15, 15, 3 };
	*(m_chArrPoketmonCenterTableVertical + 3) = new char[TILE_SIZE_X] { 1, 9, 15, 15, 15, 15, 15, 3 };
	*(m_chArrPoketmonCenterTableVertical + 4) = new char[TILE_SIZE_X] { 1, 9, 15, 15, 15, 15, 15, 3 };
	*(m_chArrPoketmonCenterTableVertical + 5) = new char[TILE_SIZE_X] { 1, 9, 15, 15, 15, 15, 15, 3 };
	*(m_chArrPoketmonCenterTableVertical + 6) = new char[TILE_SIZE_X] { 1, 9, 15, 15, 15, 15, 15, 3 };
	*(m_chArrPoketmonCenterTableVertical + 7) = new char[TILE_SIZE_X] { 1, 9, 15, 15, 15, 15, 15, 3 };

	m_chArrPoketmonCenterCarpet = new char* [TILE_SIZE_Y];
	*(m_chArrPoketmonCenterCarpet + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrPoketmonCenterCarpet + 1) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrPoketmonCenterCarpet + 2) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 13 };
	*(m_chArrPoketmonCenterCarpet + 3) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrPoketmonCenterCarpet + 4) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrPoketmonCenterCarpet + 5) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrPoketmonCenterCarpet + 6) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrPoketmonCenterCarpet + 7) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };

	m_chArrHealString = new char[HEAL_STRING_WIDTH * HEAL_STRING_HEIGHT]
	{
		15, 15, 0, 15, 15, 15, 0, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 0, 0, 0, 0, 15, 0, 15, 0, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 0, 0, 15, 15,
		0, 0, 0, 0, 0, 15, 0, 15, 15, 15, 15, 15, 15, 0, 15, 15, 0, 0, 0, 0, 0, 15, 0, 15, 15, 15, 0, 15, 0, 15, 15, 0, 15, 15, 15, 15, 0, 15, 0, 15, 0, 15, 15, 0, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 0, 15, 0, 0, 0, 0, 0, 0, 15, 0, 15, 15, 15, 0, 15, 15, 0, 15,
		15, 15, 0, 15, 15, 15, 0, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 0, 15, 15, 0, 15, 15, 15, 0, 15, 0, 0, 15, 0, 15, 15, 0, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 0, 15, 15, 15, 15, 0, 15, 0, 15, 0, 15, 15, 15, 15, 15, 15, 0, 15,
		15, 0, 15, 0, 15, 15, 0, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 0, 0, 15, 0, 15, 15, 15, 0, 15, 0, 15, 15, 15, 0, 15, 15, 0, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 0, 15, 15, 0, 0, 0, 15, 15, 0, 0, 15, 15,
		0, 15, 15, 15, 0, 15, 0, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 0, 15, 0, 15, 15, 0, 15, 15, 0, 15, 15, 15, 0, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 0, 15, 0, 0, 0, 0, 0, 0, 15, 0, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 0, 15, 15, 0, 15, 15, 15, 15, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 0, 0, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 0, 15, 0, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 0, 0, 0, 0, 15, 0, 15, 15, 0, 15, 0, 15, 15, 15, 0, 15, 15, 15, 15, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 0, 15, 0, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 0, 15, 0, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15 ,15, 15
	};

	m_eMapTile_Type = new EMapTile_Type * [POKETMONCENTER_MAP_SIZE_Y];
	*(m_eMapTile_Type + 0) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 포켓몬 회복 기계
		EMapTile_Type::HEALING_MACHINE_1_LEFT, EMapTile_Type::HEALING_MACHINE_1_MIDDLE_LEFT, EMapTile_Type::HEALING_MACHINE_1_MIDDLE_RIGHT, EMapTile_Type::HEALING_MACHINE_1_RIGHT,
		EMapTile_Type::HEALING_MACHINE_5_LEFTUP, EMapTile_Type::HEALING_MACHINE_5_RIGHTUP,

		// 벽
		EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER,
		EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER,
		EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER,
		EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER,
		EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER
	};

	*(m_eMapTile_Type + 1) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 포켓몬 회복 기계
		EMapTile_Type::HEALING_MACHINE_2_LEFT, EMapTile_Type::HEALING_MACHINE_2_MIDDLE_LEFT, EMapTile_Type::HEALING_MACHINE_2_MIDDLE_RIGHT, EMapTile_Type::HEALING_MACHINE_2_RIGHT,
		EMapTile_Type::HEALING_MACHINE_5_LEFTDOWN, EMapTile_Type::HEALING_MACHINE_5_RIGHTDOWN,

		// 벽
		EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER,
		EMapTile_Type::WALL_POKETMONCENTER,

		// 테이블 세로
		EMapTile_Type::CENTER_TABLE_VERTICAL,

		// 벽
		EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER,
		EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER,
		EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER, EMapTile_Type::WALL_POKETMONCENTER
	};

	*(m_eMapTile_Type + 2) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 포켓몬 회복 기계
		EMapTile_Type::HEALING_MACHINE_3_LEFT, EMapTile_Type::HEALING_MACHINE_3_MIDDLE, EMapTile_Type::HEALING_MACHINE_3_MIDDLE, EMapTile_Type::HEALING_MACHINE_3_RIGHT,
		EMapTile_Type::HEALING_MACHINE_6_LEFTUP, EMapTile_Type::HEALING_MACHINE_6_RIGHTUP,

		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER,

		// 테이블 세로
		EMapTile_Type::CENTER_TABLE_VERTICAL,

		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 3) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 포켓몬 회복 기계
		EMapTile_Type::HEALING_MACHINE_4_LEFT, EMapTile_Type::HEALING_MACHINE_4_MIDDLE_LEFT, EMapTile_Type::HEALING_MACHINE_4_MIDDLE_RIGHT, EMapTile_Type::HEALING_MACHINE_4_RIGHT,
		EMapTile_Type::HEALING_MACHINE_6_LEFTDOWN, EMapTile_Type::HEALING_MACHINE_6_RIGHTDOWN,

		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER,

		// 테이블 세로
		EMapTile_Type::CENTER_TABLE_VERTICAL,

		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 4) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 테이블 위
		EMapTile_Type::CENTER_TABLE_UP, EMapTile_Type::CENTER_TABLE_UP, EMapTile_Type::CENTER_TABLE_UP, EMapTile_Type::CENTER_TABLE_UP,

		// 테이블 종
		EMapTile_Type::CENTER_TABLE_BELL, EMapTile_Type::CENTER_TABLE_BELL,

		// 테이블 위
		EMapTile_Type::CENTER_TABLE_UP, EMapTile_Type::CENTER_TABLE_UP, EMapTile_Type::CENTER_TABLE_UP, EMapTile_Type::CENTER_TABLE_UP,

		// 테이블 종
		EMapTile_Type::CENTER_TABLE_BELL,

		// 테이블 세로
		EMapTile_Type::CENTER_TABLE_VERTICAL,

		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 5) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 테이블 아래
		EMapTile_Type::CENTER_TABLE_DOWN, EMapTile_Type::CENTER_TABLE_DOWN, EMapTile_Type::CENTER_TABLE_DOWN, EMapTile_Type::CENTER_TABLE_DOWN,
		EMapTile_Type::CENTER_TABLE_DOWN, EMapTile_Type::CENTER_TABLE_DOWN, EMapTile_Type::CENTER_TABLE_DOWN, EMapTile_Type::CENTER_TABLE_DOWN,
		EMapTile_Type::CENTER_TABLE_DOWN, EMapTile_Type::CENTER_TABLE_DOWN, EMapTile_Type::CENTER_TABLE_DOWN, EMapTile_Type::CENTER_TABLE_DOWN,

		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 6) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 7) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 8) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 9) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 10) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 11) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 12) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 13) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 14) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,

		// 카펫
		EMapTile_Type::ROAD_CARPET_UP, EMapTile_Type::ROAD_CARPET_UP, EMapTile_Type::ROAD_CARPET_UP, EMapTile_Type::ROAD_CARPET_UP,

		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};

	*(m_eMapTile_Type + 15) = new EMapTile_Type[POKETMONCENTER_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,

		// 카펫
		EMapTile_Type::ROAD_CARPET_DOWN, EMapTile_Type::ROAD_CARPET_DOWN, EMapTile_Type::ROAD_CARPET_DOWN, EMapTile_Type::ROAD_CARPET_DOWN,

		// 길
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER,
		EMapTile_Type::ROAD_POKETMONCENTER, EMapTile_Type::ROAD_POKETMONCENTER
	};


	m_chArrMap = new char* [POKETMONCENTER_MAP_SIZE_MAX_Y];
	for (int i = 0; i < POKETMONCENTER_MAP_SIZE_Y; i++)
	{
		*(m_chArrMap + 0 + i * TILE_SIZE_Y) = new char[POKETMONCENTER_MAP_SIZE_MAX_X];
		*(m_chArrMap + 1 + i * TILE_SIZE_Y) = new char[POKETMONCENTER_MAP_SIZE_MAX_X];
		*(m_chArrMap + 2 + i * TILE_SIZE_Y) = new char[POKETMONCENTER_MAP_SIZE_MAX_X];
		*(m_chArrMap + 3 + i * TILE_SIZE_Y) = new char[POKETMONCENTER_MAP_SIZE_MAX_X];
		*(m_chArrMap + 4 + i * TILE_SIZE_Y) = new char[POKETMONCENTER_MAP_SIZE_MAX_X];
		*(m_chArrMap + 5 + i * TILE_SIZE_Y) = new char[POKETMONCENTER_MAP_SIZE_MAX_X];
		*(m_chArrMap + 6 + i * TILE_SIZE_Y) = new char[POKETMONCENTER_MAP_SIZE_MAX_X];
		*(m_chArrMap + 7 + i * TILE_SIZE_Y) = new char[POKETMONCENTER_MAP_SIZE_MAX_X];

		for (int j = 0; j < POKETMONCENTER_MAP_SIZE_X; j++)
		{
			switch (*(*(m_eMapTile_Type + i) + j))
			{
			case EMapTile_Type::ROAD_POKETMONCENTER:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketmonCenterRoad + y) + x);
					}
				}
				break;

			case EMapTile_Type::WALL_POKETMONCENTER:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketmonCenterWall + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_1_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine1Outside + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_1_MIDDLE_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine1Middle + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_1_MIDDLE_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine1Middle + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_1_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine1Outside + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_2_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine2Outside + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_2_MIDDLE_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine2Middle + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_2_MIDDLE_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine2Middle + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_2_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine2Outside + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_3_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine3Outside + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_3_MIDDLE:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine3Middle + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_3_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine3Outside + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_4_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine4Outside + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_4_MIDDLE_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine4Middle + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_4_MIDDLE_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine4Middle + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_4_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine4Outside + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_5_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine5LeftUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_5_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine5RightUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_5_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine5LeftDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_5_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine5RightDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_6_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine6LeftUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_6_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine6LeftDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_6_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine6RightUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::HEALING_MACHINE_6_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrHealingMachine6RightDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::CENTER_TABLE_UP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketmonCenterTableUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::CENTER_TABLE_DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketmonCenterTableDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::CENTER_TABLE_BELL:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketmonCenterTableBell + y) + x);
					}
				}
				break;

			case EMapTile_Type::CENTER_TABLE_VERTICAL:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketmonCenterTableVertical + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROAD_CARPET_UP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketmonCenterCarpet + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROAD_CARPET_DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrPoketmonCenterCarpet + (TILE_SIZE_Y - y - 1)) + x);
					}
				}
				break;
			}
		}
	}
}