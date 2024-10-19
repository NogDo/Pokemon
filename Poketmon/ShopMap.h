#pragma once
#include "Map.h"

#define SHOP_MAP_SIZE_X			24
#define SHOP_MAP_SIZE_Y			16
#define SHOP_MAP_SIZE_MAX_X		TILE_SIZE_X * SHOP_MAP_SIZE_X
#define SHOP_MAP_SIZE_MAX_Y		TILE_SIZE_Y * SHOP_MAP_SIZE_Y

class ShopMap : public Map
{
private:
	char** m_chArrShopRoad;
	char** m_chArrShopCarpet;
	char** m_chArrShopSofa1Left;
	char** m_chArrShopSofa1Right;
	char** m_chArrShopSofa2Left;
	char** m_chArrShopSofa2Right;
	char** m_chArrShopSofa3Left;
	char** m_chArrShopSofa3Right;
	char** m_chArrShopSofa4Left;
	char** m_chArrShopSofa4Right;
	char** m_chArrShopIceBox1Left;
	char** m_chArrShopIceBox1MiddleLeft;
	char** m_chArrShopIceBox1MiddleRight;
	char** m_chArrShopIceBox1Right;
	char** m_chArrShopIceBox2Left;
	char** m_chArrShopIceBox2MiddleLeft;
	char** m_chArrShopIceBox2MiddleRight;
	char** m_chArrShopIceBox2Right;
	char** m_chArrShopIceBox3Left;
	char** m_chArrShopIceBox3MiddleLeft;
	char** m_chArrShopIceBox3MiddleRight;
	char** m_chArrShopIceBox3Right;
	char** m_chArrShopIceBox4Left;
	char** m_chArrShopIceBox4MiddleLeft;
	char** m_chArrShopIceBox4MiddleRight;
	char** m_chArrShopIceBox4Right;
	char** m_chArrShopDrinking1;
	char** m_chArrShopDrinking2Left;
	char** m_chArrShopDrinking2Right;
	char** m_chArrShopDrinking3Left;
	char** m_chArrShopDrinking3Right;
	char** m_chArrShopDrinking4Left;
	char** m_chArrShopDrinking4Right;
	char** m_chArrShopWall;
	char** m_chArrShopTableUp;
	char** m_chArrShopTableMiddle;
	char** m_chArrShopTableOutside1Down;
	char** m_chArrShopTableMiddle1Down;
	char** m_chArrShopTableOutside2Down;
	char** m_chArrShopTableMiddle2Down;
	char** m_chArrShopCounterLeftUp;
	char** m_chArrShopCounterRightUp;
	char** m_chArrShopCounterLeftDown;
	char** m_chArrShopCounterRightDown;

public:
	void Init();
	
	ShopMap();
	~ShopMap();
};