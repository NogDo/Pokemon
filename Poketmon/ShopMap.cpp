#include "ShopMap.h"

ShopMap::ShopMap()
{
	Init();
}

ShopMap::~ShopMap()
{
	for (int i = 0; i < TILE_SIZE_X; i++)
	{
		delete[] * (m_chArrShopRoad + i);
		delete[] * (m_chArrShopCarpet + i);
		delete[] * (m_chArrShopSofa1Left + i);
		delete[] * (m_chArrShopSofa1Right + i);
		delete[] * (m_chArrShopSofa2Left + i);
		delete[] * (m_chArrShopSofa2Right + i);
		delete[] * (m_chArrShopSofa3Left + i);
		delete[] * (m_chArrShopSofa3Right + i);
		delete[] * (m_chArrShopSofa4Left + i);
		delete[] * (m_chArrShopSofa4Right + i);
		delete[] * (m_chArrShopIceBox1Left + i);
		delete[] * (m_chArrShopIceBox1MiddleLeft + i);
		delete[] * (m_chArrShopIceBox1MiddleRight + i);
		delete[] * (m_chArrShopIceBox1Right + i);
		delete[] * (m_chArrShopIceBox2Left + i);
		delete[] * (m_chArrShopIceBox2MiddleLeft + i);
		delete[] * (m_chArrShopIceBox2MiddleRight + i);
		delete[] * (m_chArrShopIceBox2Right + i);
		delete[] * (m_chArrShopIceBox3Left + i);
		delete[] * (m_chArrShopIceBox3MiddleLeft + i);
		delete[] * (m_chArrShopIceBox3MiddleRight + i);
		delete[] * (m_chArrShopIceBox3Right + i);
		delete[] * (m_chArrShopIceBox4Left + i);
		delete[] * (m_chArrShopIceBox4MiddleLeft + i);
		delete[] * (m_chArrShopIceBox4MiddleRight + i);
		delete[] * (m_chArrShopIceBox4Right + i);
		delete[] * (m_chArrShopDrinking1 + i);
		delete[] * (m_chArrShopDrinking2Left + i);
		delete[] * (m_chArrShopDrinking2Right + i);
		delete[] * (m_chArrShopDrinking3Left + i);
		delete[] * (m_chArrShopDrinking3Right + i);
		delete[] * (m_chArrShopDrinking4Left + i);
		delete[] * (m_chArrShopDrinking4Right + i);
		delete[] * (m_chArrShopWall + i);
		delete[] * (m_chArrShopTableUp + i);
		delete[] * (m_chArrShopTableMiddle + i);
		delete[] * (m_chArrShopTableOutside1Down + i);
		delete[] * (m_chArrShopTableMiddle1Down + i);
		delete[] * (m_chArrShopTableOutside2Down + i);
		delete[] * (m_chArrShopTableMiddle2Down + i);
		delete[] * (m_chArrShopCounterLeftUp + i);
		delete[] * (m_chArrShopCounterRightUp + i);
		delete[] * (m_chArrShopCounterLeftDown + i);
		delete[] * (m_chArrShopCounterRightDown + i);
	}

	delete[] m_chArrShopRoad;
	delete[] m_chArrShopCarpet;
	delete[] m_chArrShopSofa1Left;
	delete[] m_chArrShopSofa1Right;
	delete[] m_chArrShopSofa2Left;
	delete[] m_chArrShopSofa2Right;
	delete[] m_chArrShopSofa3Left;
	delete[] m_chArrShopSofa3Right;
	delete[] m_chArrShopSofa4Left;
	delete[] m_chArrShopSofa4Right;
	delete[] m_chArrShopIceBox1Left;
	delete[] m_chArrShopIceBox1MiddleLeft;
	delete[] m_chArrShopIceBox1MiddleRight;
	delete[] m_chArrShopIceBox1Right;
	delete[] m_chArrShopIceBox2Left;
	delete[] m_chArrShopIceBox2MiddleLeft;
	delete[] m_chArrShopIceBox2MiddleRight;
	delete[] m_chArrShopIceBox2Right;
	delete[] m_chArrShopIceBox3Left;
	delete[] m_chArrShopIceBox3MiddleLeft;
	delete[] m_chArrShopIceBox3MiddleRight;
	delete[] m_chArrShopIceBox3Right;
	delete[] m_chArrShopIceBox4Left;
	delete[] m_chArrShopIceBox4MiddleLeft;
	delete[] m_chArrShopIceBox4MiddleRight;
	delete[] m_chArrShopIceBox4Right;
	delete[] m_chArrShopDrinking1;
	delete[] m_chArrShopDrinking2Left;
	delete[] m_chArrShopDrinking2Right;
	delete[] m_chArrShopDrinking3Left;
	delete[] m_chArrShopDrinking3Right;
	delete[] m_chArrShopDrinking4Left;
	delete[] m_chArrShopDrinking4Right;
	delete[] m_chArrShopWall;
	delete[] m_chArrShopTableUp;
	delete[] m_chArrShopTableMiddle;
	delete[] m_chArrShopTableOutside1Down;
	delete[] m_chArrShopTableMiddle1Down;
	delete[] m_chArrShopTableOutside2Down;
	delete[] m_chArrShopTableMiddle2Down;
	delete[] m_chArrShopCounterLeftUp;
	delete[] m_chArrShopCounterRightUp;
	delete[] m_chArrShopCounterLeftDown;
	delete[] m_chArrShopCounterRightDown;
}

/// <summary>
/// 타일 및 맵 초기화
/// </summary>
void ShopMap::Init()
{
	m_MapType = EMap_Type::SHOP;

	m_chArrShopRoad = new char* [TILE_SIZE_Y];
	*(m_chArrShopRoad + 0) = new char[TILE_SIZE_X] { 2, 2, 2, 10, 2, 2, 2, 2 };
	*(m_chArrShopRoad + 1) = new char[TILE_SIZE_X] { 2, 2, 2, 10, 2, 2, 2, 2 };
	*(m_chArrShopRoad + 2) = new char[TILE_SIZE_X] { 2, 2, 10, 10, 10, 10, 2, 2 };
	*(m_chArrShopRoad + 3) = new char[TILE_SIZE_X] { 2, 2, 10, 10, 2, 10, 10, 10 };
	*(m_chArrShopRoad + 4) = new char[TILE_SIZE_X] { 10, 10, 10, 2, 10, 10, 2, 2 };
	*(m_chArrShopRoad + 5) = new char[TILE_SIZE_X] { 2, 2, 10, 10, 10, 10, 2, 2 };
	*(m_chArrShopRoad + 6) = new char[TILE_SIZE_X] { 2, 2, 2, 2, 10, 2, 2, 2 };
	*(m_chArrShopRoad + 7) = new char[TILE_SIZE_X] { 2, 2, 2, 2, 10, 2, 2, 2 };

	m_chArrShopCarpet = new char* [TILE_SIZE_Y];
	*(m_chArrShopCarpet + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopCarpet + 1) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrShopCarpet + 2) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 13 };
	*(m_chArrShopCarpet + 3) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrShopCarpet + 4) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrShopCarpet + 5) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrShopCarpet + 6) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrShopCarpet + 7) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };

	m_chArrShopSofa1Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopSofa1Left + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 7, 8, 8, 8, 8 };
	*(m_chArrShopSofa1Left + 1) = new char[TILE_SIZE_X] { 8, 15, 9, 1, 8, 15, 15, 15 };
	*(m_chArrShopSofa1Left + 2) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa1Left + 3) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa1Left + 4) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa1Left + 5) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa1Left + 6) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa1Left + 7) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };

	m_chArrShopSofa1Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopSofa1Right + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 7, 8, 8, 8 };
	*(m_chArrShopSofa1Right + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa1Right + 2) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa1Right + 3) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa1Right + 4) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa1Right + 5) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa1Right + 6) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa1Right + 7) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };

	m_chArrShopSofa2Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopSofa2Left + 0) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa2Left + 1) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa2Left + 2) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa2Left + 3) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa2Left + 4) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa2Left + 5) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 8, 8, 8 };
	*(m_chArrShopSofa2Left + 6) = new char[TILE_SIZE_X] { 8, 8, 9, 9, 8, 15, 15, 15 };
	*(m_chArrShopSofa2Left + 7) = new char[TILE_SIZE_X] { 8, 15, 9, 8, 8, 15, 9, 9 };

	m_chArrShopSofa2Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopSofa2Right + 0) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa2Right + 1) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa2Right + 2) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa2Right + 3) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa2Right + 4) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa2Right + 5) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa2Right + 6) = new char[TILE_SIZE_X] { 15, 15, 15, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa2Right + 7) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 8, 9, 9, 8 };

	m_chArrShopSofa3Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopSofa3Left + 0) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa3Left + 1) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa3Left + 2) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa3Left + 3) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa3Left + 4) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa3Left + 5) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa3Left + 6) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };
	*(m_chArrShopSofa3Left + 7) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 15, 9, 9 };

	m_chArrShopSofa3Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopSofa3Right + 0) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa3Right + 1) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa3Right + 2) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa3Right + 3) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa3Right + 4) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa3Right + 5) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa3Right + 6) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };
	*(m_chArrShopSofa3Right + 7) = new char[TILE_SIZE_X] { 9, 9, 9, 8, 1, 9, 9, 8 };

	m_chArrShopSofa4Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopSofa4Left + 0) = new char[TILE_SIZE_X] { 8, 15, 9, 9, 8, 8, 8, 8 };
	*(m_chArrShopSofa4Left + 1) = new char[TILE_SIZE_X] { 8, 8, 8, 9, 8, 1, 1, 1 };
	*(m_chArrShopSofa4Left + 2) = new char[TILE_SIZE_X] { 8, 15, 15, 8, 8, 1, 1, 1 };
	*(m_chArrShopSofa4Left + 3) = new char[TILE_SIZE_X] { 8, 15, 1, 1, 1, 1, 1, 1 };
	*(m_chArrShopSofa4Left + 4) = new char[TILE_SIZE_X] { 8, 15, 1, 1, 1, 1, 1, 1 };
	*(m_chArrShopSofa4Left + 5) = new char[TILE_SIZE_X] { 8, 15, 1, 1, 1, 1, 1, 1 };
	*(m_chArrShopSofa4Left + 6) = new char[TILE_SIZE_X] { 8, 15, 1, 1, 1, 1, 1, 1 };
	*(m_chArrShopSofa4Left + 7) = new char[TILE_SIZE_X] { 8, 15, 1, 1, 1, 1, 1, 1 };

	m_chArrShopSofa4Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopSofa4Right + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 9, 15, 15, 8 };
	*(m_chArrShopSofa4Right + 1) = new char[TILE_SIZE_X] { 1, 1, 1, 8, 9, 8, 8, 8 };
	*(m_chArrShopSofa4Right + 2) = new char[TILE_SIZE_X] { 1, 1, 1, 8, 8, 1, 15, 8 };
	*(m_chArrShopSofa4Right + 3) = new char[TILE_SIZE_X] { 1, 1, 1, 1, 1, 1, 1, 8 };
	*(m_chArrShopSofa4Right + 4) = new char[TILE_SIZE_X] { 1, 1, 1, 1, 1, 1, 1, 8 };
	*(m_chArrShopSofa4Right + 5) = new char[TILE_SIZE_X] { 1, 1, 1, 1, 1, 1, 1, 8 };
	*(m_chArrShopSofa4Right + 6) = new char[TILE_SIZE_X] { 1, 1, 1, 1, 1, 1, 1, 8 };
	*(m_chArrShopSofa4Right + 7) = new char[TILE_SIZE_X] { 1, 1, 1, 1, 1, 1, 1, 8 };

	m_chArrShopIceBox1Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox1Left + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopIceBox1Left + 1) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopIceBox1Left + 2) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox1Left + 3) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 7 };
	*(m_chArrShopIceBox1Left + 4) = new char[TILE_SIZE_X] { 8, 7, 15, 7, 7, 7, 7, 8 };
	*(m_chArrShopIceBox1Left + 5) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox1Left + 6) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopIceBox1Left + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrShopIceBox1MiddleLeft = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox1MiddleLeft + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopIceBox1MiddleLeft + 1) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopIceBox1MiddleLeft + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox1MiddleLeft + 3) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 7, 15, 15 };
	*(m_chArrShopIceBox1MiddleLeft + 4) = new char[TILE_SIZE_X] { 15, 7, 7, 7, 7, 8, 15, 15 };
	*(m_chArrShopIceBox1MiddleLeft + 5) = new char[TILE_SIZE_X] { 8, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox1MiddleLeft + 6) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopIceBox1MiddleLeft + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrShopIceBox1MiddleRight = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox1MiddleRight + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopIceBox1MiddleRight + 1) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopIceBox1MiddleRight + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox1MiddleRight + 3) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox1MiddleRight + 4) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox1MiddleRight + 5) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox1MiddleRight + 6) = new char[TILE_SIZE_X] { 7, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox1MiddleRight + 7) = new char[TILE_SIZE_X] { 7, 15, 15, 15, 15, 15, 15, 15 };

	m_chArrShopIceBox1Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox1Right + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopIceBox1Right + 1) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopIceBox1Right + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 7, 8 };
	*(m_chArrShopIceBox1Right + 3) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 7, 8 };
	*(m_chArrShopIceBox1Right + 4) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 7, 8 };
	*(m_chArrShopIceBox1Right + 5) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 7, 8 };
	*(m_chArrShopIceBox1Right + 6) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 7, 8 };
	*(m_chArrShopIceBox1Right + 7) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 7, 8 };

	m_chArrShopIceBox2Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox2Left + 0) = new char[TILE_SIZE_X] { 8, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox2Left + 1) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopIceBox2Left + 2) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopIceBox2Left + 3) = new char[TILE_SIZE_X] { 8, 8, 8, 7, 7, 8, 7, 7 };
	*(m_chArrShopIceBox2Left + 4) = new char[TILE_SIZE_X] { 8, 7, 8, 7, 7, 8, 7, 7 };
	*(m_chArrShopIceBox2Left + 5) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopIceBox2Left + 6) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 7, 8 };
	*(m_chArrShopIceBox2Left + 7) = new char[TILE_SIZE_X] { 8, 8, 7, 7, 7, 7, 7, 7 };

	m_chArrShopIceBox2MiddleLeft = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox2MiddleLeft + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 7, 4 };
	*(m_chArrShopIceBox2MiddleLeft + 1) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 4 };
	*(m_chArrShopIceBox2MiddleLeft + 2) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 4 };
	*(m_chArrShopIceBox2MiddleLeft + 3) = new char[TILE_SIZE_X] { 8, 7, 7, 8, 7, 7, 8, 4 };
	*(m_chArrShopIceBox2MiddleLeft + 4) = new char[TILE_SIZE_X] { 8, 7, 7, 8, 7, 7, 8, 4 };
	*(m_chArrShopIceBox2MiddleLeft + 5) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 15 };
	*(m_chArrShopIceBox2MiddleLeft + 6) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 7, 4 };
	*(m_chArrShopIceBox2MiddleLeft + 7) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 4 };

	m_chArrShopIceBox2MiddleRight = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox2MiddleRight + 0) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 13 };
	*(m_chArrShopIceBox2MiddleRight + 1) = new char[TILE_SIZE_X] { 4, 4, 4, 4, 4, 4, 4, 4 };
	*(m_chArrShopIceBox2MiddleRight + 2) = new char[TILE_SIZE_X] { 13, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrShopIceBox2MiddleRight + 3) = new char[TILE_SIZE_X] { 13, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrShopIceBox2MiddleRight + 4) = new char[TILE_SIZE_X] { 13, 12, 12, 12, 12, 13, 13, 13 };
	*(m_chArrShopIceBox2MiddleRight + 5) = new char[TILE_SIZE_X] { 12, 12, 12, 13, 13, 13, 13, 13 };
	*(m_chArrShopIceBox2MiddleRight + 6) = new char[TILE_SIZE_X] { 4, 12, 12, 13, 13, 13, 13, 13 };
	*(m_chArrShopIceBox2MiddleRight + 7) = new char[TILE_SIZE_X] { 13, 12, 13, 13, 13, 13, 13, 13 };

	m_chArrShopIceBox2Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox2Right + 0) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 4 };
	*(m_chArrShopIceBox2Right + 1) = new char[TILE_SIZE_X] { 4, 4, 4, 4, 4, 4, 4, 4 };
	*(m_chArrShopIceBox2Right + 2) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 4 };
	*(m_chArrShopIceBox2Right + 3) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 4 };
	*(m_chArrShopIceBox2Right + 4) = new char[TILE_SIZE_X] { 13, 13, 12, 12, 12, 12, 12, 4 };
	*(m_chArrShopIceBox2Right + 5) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 12, 12, 12, 4 };
	*(m_chArrShopIceBox2Right + 6) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 12, 12, 12, 4 };
	*(m_chArrShopIceBox2Right + 7) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 12, 12, 4 };

	m_chArrShopIceBox3Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox3Left + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopIceBox3Left + 1) = new char[TILE_SIZE_X] { 8, 8, 8, 7, 7, 7, 8, 8 };
	*(m_chArrShopIceBox3Left + 2) = new char[TILE_SIZE_X] { 8, 7, 8, 7, 15, 7, 8, 7 };
	*(m_chArrShopIceBox3Left + 3) = new char[TILE_SIZE_X] { 8, 7, 8, 15, 15, 15, 7, 7 };
	*(m_chArrShopIceBox3Left + 4) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopIceBox3Left + 5) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopIceBox3Left + 6) = new char[TILE_SIZE_X] { 8, 8, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopIceBox3Left + 7) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };

	m_chArrShopIceBox3MiddleLeft = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox3MiddleLeft + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 4 };
	*(m_chArrShopIceBox3MiddleLeft + 1) = new char[TILE_SIZE_X] { 8, 7, 7, 8, 8, 8, 8, 4 };
	*(m_chArrShopIceBox3MiddleLeft + 2) = new char[TILE_SIZE_X] { 8, 7, 7, 8, 7, 7, 8, 4 };
	*(m_chArrShopIceBox3MiddleLeft + 3) = new char[TILE_SIZE_X] { 8, 7, 7, 8, 15, 15, 8, 15 };
	*(m_chArrShopIceBox3MiddleLeft + 4) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 4 };
	*(m_chArrShopIceBox3MiddleLeft + 5) = new char[TILE_SIZE_X] { 15, 15, 15, 7, 7, 7, 15, 4 };
	*(m_chArrShopIceBox3MiddleLeft + 6) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 4 };
	*(m_chArrShopIceBox3MiddleLeft + 7) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 4 };

	m_chArrShopIceBox3MiddleRight = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox3MiddleRight + 0) = new char[TILE_SIZE_X] { 13, 12, 13, 13, 13, 13, 12, 12 };
	*(m_chArrShopIceBox3MiddleRight + 1) = new char[TILE_SIZE_X] { 13, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrShopIceBox3MiddleRight + 2) = new char[TILE_SIZE_X] { 13, 12, 14, 14, 14, 14, 12, 12 };
	*(m_chArrShopIceBox3MiddleRight + 3) = new char[TILE_SIZE_X] { 12, 12, 12, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox3MiddleRight + 4) = new char[TILE_SIZE_X] { 4, 12, 12, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox3MiddleRight + 5) = new char[TILE_SIZE_X] { 13, 12, 12, 12, 12, 14, 14, 14 };
	*(m_chArrShopIceBox3MiddleRight + 6) = new char[TILE_SIZE_X] { 13, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrShopIceBox3MiddleRight + 7) = new char[TILE_SIZE_X] { 13, 12, 12, 12, 12, 12, 12, 12 };

	m_chArrShopIceBox3Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox3Right + 0) = new char[TILE_SIZE_X] { 12, 13, 13, 13, 13, 12, 12, 4 };
	*(m_chArrShopIceBox3Right + 1) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 4 };
	*(m_chArrShopIceBox3Right + 2) = new char[TILE_SIZE_X] { 12, 14, 14, 14, 14, 12, 12, 4 };
	*(m_chArrShopIceBox3Right + 3) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 4, 12, 12, 4 };
	*(m_chArrShopIceBox3Right + 4) = new char[TILE_SIZE_X] { 14, 14, 14, 4, 12, 4, 12, 4 };
	*(m_chArrShopIceBox3Right + 5) = new char[TILE_SIZE_X] { 14, 14, 12, 4, 12, 4, 12, 4 };
	*(m_chArrShopIceBox3Right + 6) = new char[TILE_SIZE_X] { 12, 12, 12, 4, 4, 4, 12, 4 };
	*(m_chArrShopIceBox3Right + 7) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 4 };

	m_chArrShopIceBox4Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox4Left + 0) = new char[TILE_SIZE_X] { 6, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4Left + 1) = new char[TILE_SIZE_X] { 6, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4Left + 2) = new char[TILE_SIZE_X] { 6, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4Left + 3) = new char[TILE_SIZE_X] { 6, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4Left + 4) = new char[TILE_SIZE_X] { 6, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4Left + 5) = new char[TILE_SIZE_X] { 6, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4Left + 6) = new char[TILE_SIZE_X] { 6, 6, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4Left + 7) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };

	m_chArrShopIceBox4MiddleLeft = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox4MiddleLeft + 0) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 6 };
	*(m_chArrShopIceBox4MiddleLeft + 1) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleLeft + 2) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleLeft + 3) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleLeft + 4) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleLeft + 5) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleLeft + 6) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleLeft + 7) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };

	m_chArrShopIceBox4MiddleRight = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox4MiddleRight + 0) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopIceBox4MiddleRight + 1) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleRight + 2) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleRight + 3) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleRight + 4) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleRight + 5) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleRight + 6) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 14 };
	*(m_chArrShopIceBox4MiddleRight + 7) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };

	m_chArrShopIceBox4Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopIceBox4Right + 0) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopIceBox4Right + 1) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 6 };
	*(m_chArrShopIceBox4Right + 2) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 6 };
	*(m_chArrShopIceBox4Right + 3) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 6 };
	*(m_chArrShopIceBox4Right + 4) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 6 };
	*(m_chArrShopIceBox4Right + 5) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 14, 6 };
	*(m_chArrShopIceBox4Right + 6) = new char[TILE_SIZE_X] { 14, 14, 14, 14, 14, 14, 6, 6 };
	*(m_chArrShopIceBox4Right + 7) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };

	m_chArrShopDrinking1 = new char* [TILE_SIZE_Y];
	*(m_chArrShopDrinking1 + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopDrinking1 + 1) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopDrinking1 + 2) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 7, 8, 8 };
	*(m_chArrShopDrinking1 + 3) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopDrinking1 + 4) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 7, 8, 8 };
	*(m_chArrShopDrinking1 + 5) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopDrinking1 + 6) = new char[TILE_SIZE_X] { 8, 8, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopDrinking1 + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrShopDrinking2Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopDrinking2Left + 0) = new char[TILE_SIZE_X] { 8, 9, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopDrinking2Left + 1) = new char[TILE_SIZE_X] { 8, 15, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopDrinking2Left + 2) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 9, 9, 15, 15 };
	*(m_chArrShopDrinking2Left + 3) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 9, 15, 15, 15 };
	*(m_chArrShopDrinking2Left + 4) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 15, 15, 15, 15 };
	*(m_chArrShopDrinking2Left + 5) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 15, 15, 15, 15 };
	*(m_chArrShopDrinking2Left + 6) = new char[TILE_SIZE_X] { 8, 15, 8, 15, 15, 15, 9, 15 };
	*(m_chArrShopDrinking2Left + 7) = new char[TILE_SIZE_X] { 8, 15, 8, 15, 15, 15, 15, 15 };

	m_chArrShopDrinking2Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopDrinking2Right + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 9, 8 };
	*(m_chArrShopDrinking2Right + 1) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 15, 8 };
	*(m_chArrShopDrinking2Right + 2) = new char[TILE_SIZE_X] { 15, 15, 9, 15, 9, 8, 15, 8 };
	*(m_chArrShopDrinking2Right + 3) = new char[TILE_SIZE_X] { 15, 9, 15, 15, 15, 15, 15, 8 };
	*(m_chArrShopDrinking2Right + 4) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 8, 15, 8 };
	*(m_chArrShopDrinking2Right + 5) = new char[TILE_SIZE_X] { 15, 9, 15, 15, 15, 8, 15, 8 };
	*(m_chArrShopDrinking2Right + 6) = new char[TILE_SIZE_X] { 9, 9, 9, 15, 9, 8, 9, 8 };
	*(m_chArrShopDrinking2Right + 7) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 8, 15, 8 };

	m_chArrShopDrinking3Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopDrinking3Left + 0) = new char[TILE_SIZE_X] { 8, 15, 8, 15, 9, 15, 9, 9 };
	*(m_chArrShopDrinking3Left + 1) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 15, 15, 15, 9 };
	*(m_chArrShopDrinking3Left + 2) = new char[TILE_SIZE_X] { 8, 15, 8, 15, 15, 15, 15, 15 };
	*(m_chArrShopDrinking3Left + 3) = new char[TILE_SIZE_X] { 8, 15, 8, 15, 9, 15, 15, 9 };
	*(m_chArrShopDrinking3Left + 4) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 9, 15, 15, 9 };
	*(m_chArrShopDrinking3Left + 5) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 9, 9, 9, 9 };
	*(m_chArrShopDrinking3Left + 6) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 15, 15, 15, 15 };
	*(m_chArrShopDrinking3Left + 7) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 9, 9, 9, 9 };

	m_chArrShopDrinking3Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopDrinking3Right + 0) = new char[TILE_SIZE_X] { 9, 9, 15, 15, 15, 8, 15, 8 };
	*(m_chArrShopDrinking3Right + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 8, 8, 8, 8 };
	*(m_chArrShopDrinking3Right + 2) = new char[TILE_SIZE_X] { 9, 15, 15, 8, 15, 15, 15, 8 };
	*(m_chArrShopDrinking3Right + 3) = new char[TILE_SIZE_X] { 9, 15, 15, 8, 15, 8, 15, 8 };
	*(m_chArrShopDrinking3Right + 4) = new char[TILE_SIZE_X] { 9, 15, 15, 8, 15, 8, 15, 8 };
	*(m_chArrShopDrinking3Right + 5) = new char[TILE_SIZE_X] { 9, 9, 15, 8, 15, 15, 15, 8 };
	*(m_chArrShopDrinking3Right + 6) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 8, 8, 8, 8 };
	*(m_chArrShopDrinking3Right + 7) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 8, 8, 8 };

	m_chArrShopDrinking4Left = new char* [TILE_SIZE_Y];
	*(m_chArrShopDrinking4Left + 0) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 9, 15, 15, 15 };
	*(m_chArrShopDrinking4Left + 1) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 9, 15, 15, 15 };
	*(m_chArrShopDrinking4Left + 2) = new char[TILE_SIZE_X] { 8, 15, 8, 9, 15, 15, 15, 15 };
	*(m_chArrShopDrinking4Left + 3) = new char[TILE_SIZE_X] { 8, 15, 8, 15, 15, 15, 15, 15 };
	*(m_chArrShopDrinking4Left + 4) = new char[TILE_SIZE_X] { 8, 15, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopDrinking4Left + 5) = new char[TILE_SIZE_X] { 8, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopDrinking4Left + 6) = new char[TILE_SIZE_X] { 8, 1, 1, 1, 1, 1, 1, 1 };
	*(m_chArrShopDrinking4Left + 7) = new char[TILE_SIZE_X] { 7, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrShopDrinking4Right = new char* [TILE_SIZE_Y];
	*(m_chArrShopDrinking4Right + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 8, 15, 8 };
	*(m_chArrShopDrinking4Right + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 8, 15, 8 };
	*(m_chArrShopDrinking4Right + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 8, 15, 8 };
	*(m_chArrShopDrinking4Right + 3) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 8, 15, 8 };
	*(m_chArrShopDrinking4Right + 4) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 15, 8 };
	*(m_chArrShopDrinking4Right + 5) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 8 };
	*(m_chArrShopDrinking4Right + 6) = new char[TILE_SIZE_X] { 1, 1, 1, 1, 1, 1, 1, 8 };
	*(m_chArrShopDrinking4Right + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 7 };

	m_chArrShopWall = new char* [TILE_SIZE_Y];
	*(m_chArrShopWall + 0) = new char[TILE_SIZE_X] { 15, 7, 7, 8, 15, 7, 7, 8 };
	*(m_chArrShopWall + 1) = new char[TILE_SIZE_X] { 15, 7, 7, 8, 15, 7, 7, 8 };
	*(m_chArrShopWall + 2) = new char[TILE_SIZE_X] { 15, 7, 7, 8, 15, 7, 7, 8 };
	*(m_chArrShopWall + 3) = new char[TILE_SIZE_X] { 15, 7, 7, 8, 15, 7, 7, 8 };
	*(m_chArrShopWall + 4) = new char[TILE_SIZE_X] { 15, 7, 7, 8, 15, 7, 7, 8 };
	*(m_chArrShopWall + 5) = new char[TILE_SIZE_X] { 15, 7, 7, 8, 15, 7, 7, 8 };
	*(m_chArrShopWall + 6) = new char[TILE_SIZE_X] { 15, 7, 7, 8, 15, 7, 7, 8 };
	*(m_chArrShopWall + 7) = new char[TILE_SIZE_X] { 15, 7, 7, 8, 15, 7, 7, 8 };

	m_chArrShopTableUp = new char* [TILE_SIZE_Y];
	*(m_chArrShopTableUp + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopTableUp + 1) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopTableUp + 2) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableUp + 3) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableUp + 4) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableUp + 5) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableUp + 6) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableUp + 7) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };

	m_chArrShopTableMiddle = new char* [TILE_SIZE_Y];
	*(m_chArrShopTableMiddle + 0) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle + 1) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle + 2) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle + 3) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle + 4) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle + 5) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle + 6) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle + 7) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };

	m_chArrShopTableOutside1Down = new char* [TILE_SIZE_Y];
	*(m_chArrShopTableOutside1Down + 0) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableOutside1Down + 1) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableOutside1Down + 2) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableOutside1Down + 3) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableOutside1Down + 4) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableOutside1Down + 5) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableOutside1Down + 6) = new char[TILE_SIZE_X] { 8, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopTableOutside1Down + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrShopTableMiddle1Down = new char* [TILE_SIZE_Y];
	*(m_chArrShopTableMiddle1Down + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle1Down + 1) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle1Down + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle1Down + 3) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle1Down + 4) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle1Down + 5) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrShopTableMiddle1Down + 6) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 7, 7, 7, 7 };
	*(m_chArrShopTableMiddle1Down + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrShopTableOutside2Down = new char* [TILE_SIZE_Y];
	*(m_chArrShopTableOutside2Down + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopTableOutside2Down + 1) = new char[TILE_SIZE_X] { 8, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopTableOutside2Down + 2) = new char[TILE_SIZE_X] { 8, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopTableOutside2Down + 3) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopTableOutside2Down + 4) = new char[TILE_SIZE_X] { 8, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopTableOutside2Down + 5) = new char[TILE_SIZE_X] { 8, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopTableOutside2Down + 6) = new char[TILE_SIZE_X] { 8, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopTableOutside2Down + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrShopTableMiddle2Down = new char* [TILE_SIZE_Y];
	*(m_chArrShopTableMiddle2Down + 0) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopTableMiddle2Down + 1) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopTableMiddle2Down + 2) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopTableMiddle2Down + 3) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopTableMiddle2Down + 4) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopTableMiddle2Down + 5) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopTableMiddle2Down + 6) = new char[TILE_SIZE_X] { 6, 6, 6, 6, 6, 6, 6, 6 };
	*(m_chArrShopTableMiddle2Down + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 8, 8 };

	m_chArrShopCounterLeftUp = new char* [TILE_SIZE_Y];
	*(m_chArrShopCounterLeftUp + 0) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 8, 8, 8, 15 };
	*(m_chArrShopCounterLeftUp + 1) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 7, 7, 8, 8 };
	*(m_chArrShopCounterLeftUp + 2) = new char[TILE_SIZE_X] { 8, 7, 15, 8, 7, 7, 8, 8 };
	*(m_chArrShopCounterLeftUp + 3) = new char[TILE_SIZE_X] { 8, 7, 15, 8, 8, 8, 8, 8 };
	*(m_chArrShopCounterLeftUp + 4) = new char[TILE_SIZE_X] { 8, 7, 15, 8, 8, 8, 8, 8 };
	*(m_chArrShopCounterLeftUp + 5) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 15, 15, 7, 8 };
	*(m_chArrShopCounterLeftUp + 6) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 8, 8, 8, 8 };
	*(m_chArrShopCounterLeftUp + 7) = new char[TILE_SIZE_X] { 8, 7, 15, 8, 7, 7, 7, 8 };

	m_chArrShopCounterRightUp = new char* [TILE_SIZE_Y];
	*(m_chArrShopCounterRightUp + 0) = new char[TILE_SIZE_X] { 15, 15, 8, 8, 15, 15, 7, 8 };
	*(m_chArrShopCounterRightUp + 1) = new char[TILE_SIZE_X] { 7, 8, 7, 15, 8, 15, 7, 8 };
	*(m_chArrShopCounterRightUp + 2) = new char[TILE_SIZE_X] { 7, 8, 7, 8, 15, 8, 7, 8 };
	*(m_chArrShopCounterRightUp + 3) = new char[TILE_SIZE_X] { 7, 8, 15, 8, 8, 15, 8, 8 };
	*(m_chArrShopCounterRightUp + 4) = new char[TILE_SIZE_X] { 7, 8, 8, 15, 8, 7, 8, 8 };
	*(m_chArrShopCounterRightUp + 5) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 15, 7, 8, 8 };
	*(m_chArrShopCounterRightUp + 6) = new char[TILE_SIZE_X] { 7, 8, 8, 8, 7, 8, 7, 8 };
	*(m_chArrShopCounterRightUp + 7) = new char[TILE_SIZE_X] { 7, 8, 8, 8, 8, 8, 7, 8 };

	m_chArrShopCounterLeftDown = new char* [TILE_SIZE_Y];
	*(m_chArrShopCounterLeftDown + 0) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 15, 7, 15, 8 };
	*(m_chArrShopCounterLeftDown + 1) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 7, 7, 8, 8 };
	*(m_chArrShopCounterLeftDown + 2) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 15, 7, 8, 15 };
	*(m_chArrShopCounterLeftDown + 3) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 8, 8, 7, 15 };
	*(m_chArrShopCounterLeftDown + 4) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 15, 15, 15, 15 };
	*(m_chArrShopCounterLeftDown + 5) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 8, 8, 8, 8 };
	*(m_chArrShopCounterLeftDown + 6) = new char[TILE_SIZE_X] { 8, 7, 8, 7, 7, 7, 7, 7 };
	*(m_chArrShopCounterLeftDown + 7) = new char[TILE_SIZE_X] { 8, 7, 8, 8, 8, 8, 8, 8 };

	m_chArrShopCounterRightDown = new char* [TILE_SIZE_Y];
	*(m_chArrShopCounterRightDown + 0) = new char[TILE_SIZE_X] { 8, 8, 15, 15, 7, 8, 7, 8 };
	*(m_chArrShopCounterRightDown + 1) = new char[TILE_SIZE_X] { 8, 7, 15, 15, 7, 8, 7, 8 };
	*(m_chArrShopCounterRightDown + 2) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 7, 8, 7, 8 };
	*(m_chArrShopCounterRightDown + 3) = new char[TILE_SIZE_X] { 15, 15, 8, 8, 7, 8, 7, 8 };
	*(m_chArrShopCounterRightDown + 4) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 7, 8, 7, 8 };
	*(m_chArrShopCounterRightDown + 5) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 8, 7, 8 };
	*(m_chArrShopCounterRightDown + 6) = new char[TILE_SIZE_X] { 7, 7, 7, 7, 8, 8, 7, 8 };
	*(m_chArrShopCounterRightDown + 7) = new char[TILE_SIZE_X] { 8, 8, 8, 8, 8, 7, 7, 8 };


	/*m_eMapTile_Type = new EMapTile_Type * [SHOP_MAP_SIZE_Y];
	for (int i = 0; i < SHOP_MAP_SIZE_Y / 4; i++)
	{
		*(m_eMapTile_Type + 0 + i * 4) = new EMapTile_Type[SHOP_MAP_SIZE_X]
		{
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::SHOP_TABLE_LEFTUP, EMapTile_Type::SHOP_TABLE_RIGHTUP,
			EMapTile_Type::SHOP_WALL, EMapTile_Type::SHOP_WALL, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::SHOP_ICEBOX_1_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_1_RIGHT,
			EMapTile_Type::SHOP_DRINGKING1_LEFT, EMapTile_Type::SHOP_DRINGKING1_RIGHT, EMapTile_Type::SHOP_SOFA_1_LEFT, EMapTile_Type::SHOP_SOFA_1_RIGHT
		};

		*(m_eMapTile_Type + 1 + i * 4) = new EMapTile_Type[SHOP_MAP_SIZE_X]
		{
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::SHOP_COUNTER_LEFTUP, EMapTile_Type::SHOP_COUNTER_RIGHTUP,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::SHOP_ICEBOX_2_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_2_RIGHT,
			EMapTile_Type::SHOP_DRINGKING2_LEFT, EMapTile_Type::SHOP_DRINGKING2_RIGHT, EMapTile_Type::SHOP_SOFA_2_LEFT, EMapTile_Type::SHOP_SOFA_2_RIGHT
		};

		*(m_eMapTile_Type + 2 + i * 4) = new EMapTile_Type[SHOP_MAP_SIZE_X]
		{
			EMapTile_Type::SHOP_TABLE_LEFT1DOWN, EMapTile_Type::SHOP_TABLE_MIDDLE1DOWN, EMapTile_Type::SHOP_COUNTER_LEFTDOWN, EMapTile_Type::SHOP_COUNTER_RIGHTDOWN,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::SHOP_ICEBOX_3_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_3_RIGHT,
			EMapTile_Type::SHOP_DRINGKING3_LEFT, EMapTile_Type::SHOP_DRINGKING3_RIGHT, EMapTile_Type::SHOP_SOFA_3_LEFT, EMapTile_Type::SHOP_SOFA_3_RIGHT
		};

		*(m_eMapTile_Type + 3 + i * 4) = new EMapTile_Type[SHOP_MAP_SIZE_X]
		{
			EMapTile_Type::SHOP_TABLE_LEFT2DOWN, EMapTile_Type::SHOP_TABLE_MIDDLE2DOWN, EMapTile_Type::SHOP_TABLE_MIDDLE2DOWN, EMapTile_Type::SHOP_TABLE_RIGHT2DOWN,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
			EMapTile_Type::SHOP_ICEBOX_4_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_4_RIGHT,
			EMapTile_Type::SHOP_DRINGKING4_LEFT, EMapTile_Type::SHOP_DRINGKING4_RIGHT, EMapTile_Type::SHOP_SOFA_4_LEFT, EMapTile_Type::SHOP_SOFA_4_RIGHT
		};
	}*/


	m_eMapTile_Type = new EMapTile_Type * [SHOP_MAP_SIZE_Y];
	*(m_eMapTile_Type + 0) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 음료수
		EMapTile_Type::SHOP_DRINGKING1_LEFT, EMapTile_Type::SHOP_DRINGKING1_RIGHT, EMapTile_Type::SHOP_DRINGKING1_LEFT, EMapTile_Type::SHOP_DRINGKING1_RIGHT,

		// 벽
		EMapTile_Type::SHOP_WALL, EMapTile_Type::SHOP_WALL,

		// 냉장고
		EMapTile_Type::SHOP_ICEBOX_1_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_1_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_1_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_1_RIGHT,

		// 벽
		EMapTile_Type::SHOP_WALL, EMapTile_Type::SHOP_WALL,

		// 음료수
		EMapTile_Type::SHOP_DRINGKING1_LEFT, EMapTile_Type::SHOP_DRINGKING1_RIGHT, EMapTile_Type::SHOP_DRINGKING1_LEFT, EMapTile_Type::SHOP_DRINGKING1_RIGHT,
		EMapTile_Type::SHOP_DRINGKING1_LEFT, EMapTile_Type::SHOP_DRINGKING1_RIGHT, EMapTile_Type::SHOP_DRINGKING1_LEFT, EMapTile_Type::SHOP_DRINGKING1_RIGHT
	};

	*(m_eMapTile_Type + 1) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 음료수
		EMapTile_Type::SHOP_DRINGKING2_LEFT, EMapTile_Type::SHOP_DRINGKING2_RIGHT, EMapTile_Type::SHOP_DRINGKING2_LEFT, EMapTile_Type::SHOP_DRINGKING2_RIGHT,

		// 테이블
		EMapTile_Type::SHOP_TABLE_LEFTMIDDLE, EMapTile_Type::SHOP_TABLE_RIGHTMIDDLE,

		// 냉장고
		EMapTile_Type::SHOP_ICEBOX_2_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_2_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_2_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_2_RIGHT,

		// 벽
		EMapTile_Type::SHOP_WALL, EMapTile_Type::SHOP_WALL,

		// 음료수
		EMapTile_Type::SHOP_DRINGKING2_LEFT, EMapTile_Type::SHOP_DRINGKING2_RIGHT, EMapTile_Type::SHOP_DRINGKING2_LEFT, EMapTile_Type::SHOP_DRINGKING2_RIGHT,
		EMapTile_Type::SHOP_DRINGKING2_LEFT, EMapTile_Type::SHOP_DRINGKING2_RIGHT, EMapTile_Type::SHOP_DRINGKING2_LEFT, EMapTile_Type::SHOP_DRINGKING2_RIGHT
	};

	*(m_eMapTile_Type + 2) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 음료수
		EMapTile_Type::SHOP_DRINGKING3_LEFT, EMapTile_Type::SHOP_DRINGKING3_RIGHT, EMapTile_Type::SHOP_DRINGKING3_LEFT, EMapTile_Type::SHOP_DRINGKING3_RIGHT,

		// 테이블
		EMapTile_Type::SHOP_TABLE_LEFTMIDDLE, EMapTile_Type::SHOP_TABLE_RIGHTMIDDLE,

		// 냉장고
		EMapTile_Type::SHOP_ICEBOX_3_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_3_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_3_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_3_RIGHT,

		// 벽
		EMapTile_Type::SHOP_WALL, EMapTile_Type::SHOP_WALL,

		// 음료수
		EMapTile_Type::SHOP_DRINGKING3_LEFT, EMapTile_Type::SHOP_DRINGKING3_RIGHT, EMapTile_Type::SHOP_DRINGKING3_LEFT, EMapTile_Type::SHOP_DRINGKING3_RIGHT,
		EMapTile_Type::SHOP_DRINGKING3_LEFT, EMapTile_Type::SHOP_DRINGKING3_RIGHT, EMapTile_Type::SHOP_DRINGKING3_LEFT, EMapTile_Type::SHOP_DRINGKING3_RIGHT
	};

	*(m_eMapTile_Type + 3) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 음료수
		EMapTile_Type::SHOP_DRINGKING4_LEFT, EMapTile_Type::SHOP_DRINGKING4_RIGHT, EMapTile_Type::SHOP_DRINGKING4_LEFT, EMapTile_Type::SHOP_DRINGKING4_RIGHT,

		// 테이블
		EMapTile_Type::SHOP_TABLE_LEFTMIDDLE, EMapTile_Type::SHOP_TABLE_RIGHTMIDDLE,

		// 냉장고
		EMapTile_Type::SHOP_ICEBOX_4_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_4_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_4_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_4_RIGHT,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 음료수
		EMapTile_Type::SHOP_DRINGKING4_LEFT, EMapTile_Type::SHOP_DRINGKING4_RIGHT, EMapTile_Type::SHOP_DRINGKING4_LEFT, EMapTile_Type::SHOP_DRINGKING4_RIGHT,
		EMapTile_Type::SHOP_DRINGKING4_LEFT, EMapTile_Type::SHOP_DRINGKING4_RIGHT, EMapTile_Type::SHOP_DRINGKING4_LEFT, EMapTile_Type::SHOP_DRINGKING4_RIGHT
	};

	*(m_eMapTile_Type + 4) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 테이블 계산대
		EMapTile_Type::SHOP_COUNTER_LEFTUP, EMapTile_Type::SHOP_COUNTER_RIGHTUP,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP
	};

	*(m_eMapTile_Type + 5) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 테이블 계산대
		EMapTile_Type::SHOP_COUNTER_LEFTDOWN, EMapTile_Type::SHOP_COUNTER_RIGHTDOWN,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP
	};

	*(m_eMapTile_Type + 6) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 테이블
		EMapTile_Type::SHOP_TABLE_LEFTMIDDLE, EMapTile_Type::SHOP_TABLE_RIGHTMIDDLE,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP
	};

	*(m_eMapTile_Type + 7) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 테이블
		EMapTile_Type::SHOP_TABLE_LEFTMIDDLE, EMapTile_Type::SHOP_TABLE_RIGHTMIDDLE,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP
	};

	*(m_eMapTile_Type + 8) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 테이블 가로
		EMapTile_Type::SHOP_TABLE_LEFT1DOWN, EMapTile_Type::SHOP_TABLE_MIDDLE1DOWN, EMapTile_Type::SHOP_TABLE_MIDDLE1DOWN, EMapTile_Type::SHOP_TABLE_MIDDLE1DOWN,
		EMapTile_Type::SHOP_TABLE_MIDDLE1DOWN, EMapTile_Type::SHOP_TABLE_RIGHT1DOWN,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 냉장고
		EMapTile_Type::SHOP_ICEBOX_1_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_1_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_1_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_1_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_1_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_1_RIGHT,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 소파
		EMapTile_Type::SHOP_SOFA_1_LEFT, EMapTile_Type::SHOP_SOFA_1_RIGHT
	};

	*(m_eMapTile_Type + 9) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 테이블 가로
		EMapTile_Type::SHOP_TABLE_LEFT2DOWN, EMapTile_Type::SHOP_TABLE_MIDDLE2DOWN, EMapTile_Type::SHOP_TABLE_MIDDLE2DOWN, EMapTile_Type::SHOP_TABLE_MIDDLE2DOWN,
		EMapTile_Type::SHOP_TABLE_MIDDLE2DOWN, EMapTile_Type::SHOP_TABLE_RIGHT2DOWN,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 냉장고
		EMapTile_Type::SHOP_ICEBOX_2_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_2_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_2_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_2_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_2_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_2_RIGHT,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 소파
		EMapTile_Type::SHOP_SOFA_2_LEFT, EMapTile_Type::SHOP_SOFA_2_RIGHT
	};

	*(m_eMapTile_Type + 10) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 냉장고
		EMapTile_Type::SHOP_ICEBOX_3_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_3_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_3_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_3_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_3_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_3_RIGHT,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 소파
		EMapTile_Type::SHOP_SOFA_3_LEFT, EMapTile_Type::SHOP_SOFA_3_RIGHT
	};

	*(m_eMapTile_Type + 11) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 냉장고
		EMapTile_Type::SHOP_ICEBOX_4_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_4_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_4_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_4_RIGHT,
		EMapTile_Type::SHOP_ICEBOX_4_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_LEFT, EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_RIGHT, EMapTile_Type::SHOP_ICEBOX_4_RIGHT,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 소파
		EMapTile_Type::SHOP_SOFA_4_LEFT, EMapTile_Type::SHOP_SOFA_4_RIGHT
	};

	*(m_eMapTile_Type + 12) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 소파
		EMapTile_Type::SHOP_SOFA_1_LEFT, EMapTile_Type::SHOP_SOFA_1_RIGHT
	};

	*(m_eMapTile_Type + 13) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 소파
		EMapTile_Type::SHOP_SOFA_2_LEFT, EMapTile_Type::SHOP_SOFA_2_RIGHT
	};

	*(m_eMapTile_Type + 14) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 카펫
		EMapTile_Type::ROAD_CARPET_UP, EMapTile_Type::ROAD_CARPET_UP, EMapTile_Type::ROAD_CARPET_UP, EMapTile_Type::ROAD_CARPET_UP,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 소파
		EMapTile_Type::SHOP_SOFA_3_LEFT, EMapTile_Type::SHOP_SOFA_3_RIGHT
	};

	*(m_eMapTile_Type + 15) = new EMapTile_Type[SHOP_MAP_SIZE_X]
	{
		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 카펫
		EMapTile_Type::ROAD_CARPET_DOWN, EMapTile_Type::ROAD_CARPET_DOWN, EMapTile_Type::ROAD_CARPET_DOWN, EMapTile_Type::ROAD_CARPET_DOWN,

		// 길
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,
		EMapTile_Type::ROAD_SHOP, EMapTile_Type::ROAD_SHOP,

		// 소파
		EMapTile_Type::SHOP_SOFA_4_LEFT, EMapTile_Type::SHOP_SOFA_4_RIGHT
	};


	m_chArrMap = new char* [SHOP_MAP_SIZE_MAX_Y];
	for (int i = 0; i < SHOP_MAP_SIZE_Y; i++)
	{
		*(m_chArrMap + 0 + i * TILE_SIZE_Y) = new char[SHOP_MAP_SIZE_MAX_X];
		*(m_chArrMap + 1 + i * TILE_SIZE_Y) = new char[SHOP_MAP_SIZE_MAX_X];
		*(m_chArrMap + 2 + i * TILE_SIZE_Y) = new char[SHOP_MAP_SIZE_MAX_X];
		*(m_chArrMap + 3 + i * TILE_SIZE_Y) = new char[SHOP_MAP_SIZE_MAX_X];
		*(m_chArrMap + 4 + i * TILE_SIZE_Y) = new char[SHOP_MAP_SIZE_MAX_X];
		*(m_chArrMap + 5 + i * TILE_SIZE_Y) = new char[SHOP_MAP_SIZE_MAX_X];
		*(m_chArrMap + 6 + i * TILE_SIZE_Y) = new char[SHOP_MAP_SIZE_MAX_X];
		*(m_chArrMap + 7 + i * TILE_SIZE_Y) = new char[SHOP_MAP_SIZE_MAX_X];

		for (int j = 0; j < SHOP_MAP_SIZE_X; j++)
		{
			switch (*(*(m_eMapTile_Type + i) + j))
			{
			case EMapTile_Type::ROAD_SHOP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopRoad + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROAD_CARPET_UP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopCarpet + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROAD_CARPET_DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopCarpet + (TILE_SIZE_Y - y - 1)) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_SOFA_1_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopSofa1Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_SOFA_1_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopSofa1Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_SOFA_2_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopSofa2Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_SOFA_2_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopSofa2Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_SOFA_3_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopSofa3Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_SOFA_3_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopSofa3Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_SOFA_4_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopSofa4Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_SOFA_4_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopSofa4Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_1_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox1Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox1MiddleLeft + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_1_MIDDLE_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox1MiddleRight + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_1_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox1Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_2_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox2Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox2MiddleLeft + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_2_MIDDLE_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox2MiddleRight + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_2_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox2Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_3_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox3Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox3MiddleLeft + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_3_MIDDLE_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox3MiddleRight + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_3_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox3Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_4_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox4Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox4MiddleLeft + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_4_MIDDLE_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox4MiddleRight + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_ICEBOX_4_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopIceBox4Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_DRINGKING1_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopDrinking1 + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_DRINGKING1_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopDrinking1 + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::SHOP_DRINGKING2_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopDrinking2Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_DRINGKING2_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopDrinking2Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_DRINGKING3_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopDrinking3Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_DRINGKING3_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopDrinking3Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_DRINGKING4_LEFT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopDrinking4Left + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_DRINGKING4_RIGHT:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopDrinking4Right + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_WALL:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopWall + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_TABLE_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopTableUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_TABLE_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopTableUp + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::SHOP_TABLE_LEFTMIDDLE:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopTableMiddle + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_TABLE_RIGHTMIDDLE:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopTableMiddle + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::SHOP_TABLE_LEFT1DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopTableOutside1Down + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_TABLE_MIDDLE1DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopTableMiddle1Down + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_TABLE_RIGHT1DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopTableOutside1Down + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::SHOP_TABLE_LEFT2DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopTableOutside2Down + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_TABLE_MIDDLE2DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopTableMiddle2Down + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_TABLE_RIGHT2DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopTableOutside2Down + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::SHOP_COUNTER_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopCounterLeftUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_COUNTER_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopCounterRightUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_COUNTER_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopCounterLeftDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::SHOP_COUNTER_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrShopCounterRightDown + y) + x);
					}
				}
				break;
			}
		}
	}
}