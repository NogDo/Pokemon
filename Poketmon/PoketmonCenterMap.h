#pragma once
#include "Map.h"

#define POKETMONCENTER_MAP_SIZE_X			24
#define POKETMONCENTER_MAP_SIZE_Y			16
#define POKETMONCENTER_MAP_SIZE_MAX_X		TILE_SIZE_X * POKETMONCENTER_MAP_SIZE_X
#define POKETMONCENTER_MAP_SIZE_MAX_Y		TILE_SIZE_Y * POKETMONCENTER_MAP_SIZE_Y
#define HEAL_STRING_WIDTH					72
#define HEAL_STRING_HEIGHT					8

class PoketmonCenterMap : public Map
{
private:
	char** m_chArrPoketmonCenterRoad;
	char** m_chArrPoketmonCenterWall;
	char** m_chArrHealingMachine1Outside;
	char** m_chArrHealingMachine1Middle;
	char** m_chArrHealingMachine2Outside;
	char** m_chArrHealingMachine2Middle;
	char** m_chArrHealingMachine3Outside;
	char** m_chArrHealingMachine3Middle;
	char** m_chArrHealingMachine4Outside;
	char** m_chArrHealingMachine4Middle;
	char** m_chArrHealingMachine5LeftUp;
	char** m_chArrHealingMachine5LeftDown;
	char** m_chArrHealingMachine5RightUp;
	char** m_chArrHealingMachine5RightDown;
	char** m_chArrHealingMachine6LeftUp;
	char** m_chArrHealingMachine6LeftDown;
	char** m_chArrHealingMachine6RightUp;
	char** m_chArrHealingMachine6RightDown;
	char** m_chArrPoketmonCenterTableUp;
	char** m_chArrPoketmonCenterTableDown;
	char** m_chArrPoketmonCenterTableBell;
	char** m_chArrPoketmonCenterTableVertical;
	char** m_chArrPoketmonCenterCarpet;

	char* m_chArrHealString;

public:
	void Init();

	char* GetHealString() { return m_chArrHealString; }

	PoketmonCenterMap();
	~PoketmonCenterMap();
};

