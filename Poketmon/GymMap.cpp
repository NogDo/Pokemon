#include "GymMap.h"

GymMap::GymMap()
{
	Init();
}

GymMap::~GymMap()
{
	for (int i = 0; i < TILE_SIZE_X; i++)
	{
		delete[] * (m_chArrBlank);
		delete[] * (m_chArrGymRoad);
		delete[] * (m_chArrGymFallRoadUp);
		delete[] * (m_chArrGymFallRoadDown);
		delete[] * (m_chArrGymWall);
		delete[] * (m_chArrGymWall2);
		delete[] * (m_chArrGymStatueUp);
		delete[] * (m_chArrGymStatueMiddle1);
		delete[] * (m_chArrGymStatueMiddle2);
		delete[] * (m_chArrGymStatueDown);
		delete[] * (m_chArrGymCarpet);
	}

	delete[] m_chArrBlank;
	delete[] m_chArrGymRoad;
	delete[] m_chArrGymFallRoadUp;
	delete[] m_chArrGymFallRoadDown;
	delete[] m_chArrGymWall;
	delete[] m_chArrGymWall2;
	delete[] m_chArrGymStatueUp;
	delete[] m_chArrGymStatueMiddle1;
	delete[] m_chArrGymStatueMiddle2;
	delete[] m_chArrGymStatueDown;
	delete[] m_chArrGymCarpet;
}

/// <summary>
/// Å¸ÀÏ ¹× ¸Ê ÃÊ±âÈ­
/// </summary>
void GymMap::Init()
{
	m_MapType = EMap_Type::GYM;

	m_chArrBlank = new char* [TILE_SIZE_Y];
	*(m_chArrBlank + 0) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrBlank + 1) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrBlank + 2) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrBlank + 3) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrBlank + 4) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrBlank + 5) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrBlank + 6) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrBlank + 7) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};

	m_chArrGymRoad = new char* [TILE_SIZE_Y];
	*(m_chArrGymRoad + 0) = new char[TILE_SIZE_X] {3, 11, 11, 11, 11, 11, 11, 3};
	*(m_chArrGymRoad + 1) = new char[TILE_SIZE_X] {11, 11, 11, 11, 11, 11, 11, 3};
	*(m_chArrGymRoad + 2) = new char[TILE_SIZE_X] {11, 11, 11, 11, 11, 11, 11, 3};
	*(m_chArrGymRoad + 3) = new char[TILE_SIZE_X] {3, 3, 3, 3, 3, 3, 3, 3};
	*(m_chArrGymRoad + 4) = new char[TILE_SIZE_X] {11, 11, 11, 3, 11, 11, 11, 3};
	*(m_chArrGymRoad + 5) = new char[TILE_SIZE_X] {11, 11, 11, 3, 11, 11, 11, 3};
	*(m_chArrGymRoad + 6) = new char[TILE_SIZE_X] {11, 11, 11, 3, 11, 11, 11, 3};
	*(m_chArrGymRoad + 7) = new char[TILE_SIZE_X] {3, 3, 3, 3, 3, 3, 3, 3};

	m_chArrGymFallRoadUp = new char* [TILE_SIZE_Y];
	*(m_chArrGymFallRoadUp + 0) = new char[TILE_SIZE_X] {11, 11, 11, 11, 11, 11, 11, 1};
	*(m_chArrGymFallRoadUp + 1) = new char[TILE_SIZE_X] {9, 9, 9, 9, 9, 9, 9, 1};
	*(m_chArrGymFallRoadUp + 2) = new char[TILE_SIZE_X] {9, 9, 9, 9, 9, 9, 9, 1};
	*(m_chArrGymFallRoadUp + 3) = new char[TILE_SIZE_X] {1, 1, 1, 1, 1, 1, 1, 1};
	*(m_chArrGymFallRoadUp + 4) = new char[TILE_SIZE_X] {9, 9, 9, 1, 9, 9, 9, 9};
	*(m_chArrGymFallRoadUp + 5) = new char[TILE_SIZE_X] {9, 9, 9, 1, 9, 9, 9, 9};
	*(m_chArrGymFallRoadUp + 6) = new char[TILE_SIZE_X] {1, 9, 1, 1, 1, 9, 1, 9};
	*(m_chArrGymFallRoadUp + 7) = new char[TILE_SIZE_X] {9, 1, 9, 1, 9, 1, 9, 1};

	m_chArrGymFallRoadDown = new char* [TILE_SIZE_Y];
	*(m_chArrGymFallRoadDown + 0) = new char[TILE_SIZE_X] {0, 9, 0, 0, 0, 0, 0, 9};
	*(m_chArrGymFallRoadDown + 1) = new char[TILE_SIZE_X] {0, 0, 0, 0, 9, 0, 9, 0};
	*(m_chArrGymFallRoadDown + 2) = new char[TILE_SIZE_X] {0, 0, 9, 0, 0, 0, 0, 0};
	*(m_chArrGymFallRoadDown + 3) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 9, 0, 0};
	*(m_chArrGymFallRoadDown + 4) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrGymFallRoadDown + 5) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrGymFallRoadDown + 6) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrGymFallRoadDown + 7) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};

	m_chArrGymWall = new char* [TILE_SIZE_Y];
	*(m_chArrGymWall + 0) = new char[TILE_SIZE_X] {8, 0, 0, 0, 0, 0, 8, 0};
	*(m_chArrGymWall + 1) = new char[TILE_SIZE_X] {7, 8, 8, 8, 8, 8, 7, 0};
	*(m_chArrGymWall + 2) = new char[TILE_SIZE_X] {15, 7, 7, 7, 7, 7, 15, 0};
	*(m_chArrGymWall + 3) = new char[TILE_SIZE_X] {8, 15, 15, 7, 15, 7, 8, 0};
	*(m_chArrGymWall + 4) = new char[TILE_SIZE_X] {8, 8, 8, 8, 8, 8, 8, 0};
	*(m_chArrGymWall + 5) = new char[TILE_SIZE_X] {0, 8, 8, 8, 8, 8, 0, 0};
	*(m_chArrGymWall + 6) = new char[TILE_SIZE_X] {8, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrGymWall + 7) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};

	m_chArrGymWall2 = new char* [TILE_SIZE_Y];
	*(m_chArrGymWall2 + 0) = new char[TILE_SIZE_X] {0, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrGymWall2 + 1) = new char[TILE_SIZE_X] {0, 7, 7, 7, 7, 7, 7, 7};
	*(m_chArrGymWall2 + 2) = new char[TILE_SIZE_X] {0, 7, 8, 8, 8, 8, 8, 8};
	*(m_chArrGymWall2 + 3) = new char[TILE_SIZE_X] {0, 7, 8, 7, 7, 7, 7, 7};
	*(m_chArrGymWall2 + 4) = new char[TILE_SIZE_X] {0, 7, 8, 7, 8, 8, 8, 8};
	*(m_chArrGymWall2 + 5) = new char[TILE_SIZE_X] {0, 7, 8, 7, 8, 8, 8, 8};
	*(m_chArrGymWall2 + 6) = new char[TILE_SIZE_X] {0, 7, 8, 7, 8, 8, 8, 8};
	*(m_chArrGymWall2 + 7) = new char[TILE_SIZE_X] {0, 7, 8, 7, 8, 8, 8, 8};

	m_chArrGymStatueUp = new char* [TILE_SIZE_Y];
	*(m_chArrGymStatueUp + 0) = new char[TILE_SIZE_X] {15, 0, 0, 0, 0, 0, 0, 0};
	*(m_chArrGymStatueUp + 1) = new char[TILE_SIZE_X] {0, 0, 15, 15, 0, 0, 12, 12};
	*(m_chArrGymStatueUp + 2) = new char[TILE_SIZE_X] {0, 15, 15, 0, 12, 12, 12, 15};
	*(m_chArrGymStatueUp + 3) = new char[TILE_SIZE_X] {0, 15, 0, 12, 12, 12, 15, 15};
	*(m_chArrGymStatueUp + 4) = new char[TILE_SIZE_X] {0, 15, 0, 12, 12, 12, 12, 15};
	*(m_chArrGymStatueUp + 5) = new char[TILE_SIZE_X] {0, 0, 12, 12, 12, 12, 12, 12};
	*(m_chArrGymStatueUp + 6) = new char[TILE_SIZE_X] {0, 0, 12, 12, 12, 12, 12, 12};
	*(m_chArrGymStatueUp + 7) = new char[TILE_SIZE_X] {0, 0, 0, 12, 12, 12, 12, 12};

	m_chArrGymStatueMiddle1 = new char* [TILE_SIZE_Y];
	*(m_chArrGymStatueMiddle1 + 0) = new char[TILE_SIZE_X] {0, 0, 15, 0, 0, 12, 12, 0};
	*(m_chArrGymStatueMiddle1 + 1) = new char[TILE_SIZE_X] {0, 0, 15, 15, 0, 0, 0, 15};
	*(m_chArrGymStatueMiddle1 + 2) = new char[TILE_SIZE_X] {0, 0, 0, 15, 15, 15, 0, 15};
	*(m_chArrGymStatueMiddle1 + 3) = new char[TILE_SIZE_X] {0, 15, 0, 0, 15, 15, 15, 0};
	*(m_chArrGymStatueMiddle1 + 4) = new char[TILE_SIZE_X] {0, 15, 0, 0, 0, 0, 15, 15};
	*(m_chArrGymStatueMiddle1 + 5) = new char[TILE_SIZE_X] {0, 15, 0, 0, 0, 0, 0, 0};
	*(m_chArrGymStatueMiddle1 + 6) = new char[TILE_SIZE_X] {0, 15, 15, 0, 0, 0, 0, 0};
	*(m_chArrGymStatueMiddle1 + 7) = new char[TILE_SIZE_X] {0, 15, 15, 15, 15, 15, 15, 15};

	m_chArrGymStatueMiddle2 = new char* [TILE_SIZE_Y];
	*(m_chArrGymStatueMiddle2 + 0) = new char[TILE_SIZE_X] {0, 15, 15, 15, 15, 15, 15, 15};
	*(m_chArrGymStatueMiddle2 + 1) = new char[TILE_SIZE_X] {0, 15, 15, 7, 7, 7, 7, 7};
	*(m_chArrGymStatueMiddle2 + 2) = new char[TILE_SIZE_X] {0, 15, 15, 7, 7, 7, 7, 7};
	*(m_chArrGymStatueMiddle2 + 3) = new char[TILE_SIZE_X] {0, 15, 15, 7, 7, 7, 7, 7};
	*(m_chArrGymStatueMiddle2 + 4) = new char[TILE_SIZE_X] {0, 15, 15, 7, 8, 8, 8, 8};
	*(m_chArrGymStatueMiddle2 + 5) = new char[TILE_SIZE_X] {0, 15, 15, 7, 8, 7, 7, 7};
	*(m_chArrGymStatueMiddle2 + 6) = new char[TILE_SIZE_X] {0, 8, 15, 7, 8, 7, 8, 8};
	*(m_chArrGymStatueMiddle2 + 7) = new char[TILE_SIZE_X] {0, 15, 8, 8, 8, 7, 7, 7};

	m_chArrGymStatueDown = new char* [TILE_SIZE_Y];
	*(m_chArrGymStatueDown + 0) = new char[TILE_SIZE_X] {0, 8, 15, 7, 8, 7, 8, 7};
	*(m_chArrGymStatueDown + 1) = new char[TILE_SIZE_X] {0, 15, 8, 8, 8, 7, 7, 7};
	*(m_chArrGymStatueDown + 2) = new char[TILE_SIZE_X] {0, 15, 15, 7, 8, 7, 8, 8};
	*(m_chArrGymStatueDown + 3) = new char[TILE_SIZE_X] {0, 15, 15, 7, 8, 7, 7, 7};
	*(m_chArrGymStatueDown + 4) = new char[TILE_SIZE_X] {0, 15, 15, 7, 15, 15, 15, 15};
	*(m_chArrGymStatueDown + 5) = new char[TILE_SIZE_X] {0, 15, 15, 7, 7, 7, 7, 7};
	*(m_chArrGymStatueDown + 6) = new char[TILE_SIZE_X] {8, 0, 15, 7, 7, 7, 7, 7};
	*(m_chArrGymStatueDown + 7) = new char[TILE_SIZE_X] {8, 8, 0, 0, 0, 0, 0, 0};

	m_chArrGymCarpet = new char* [TILE_SIZE_Y];
	*(m_chArrGymCarpet + 0) = new char[TILE_SIZE_X] { 15, 15, 15, 15, 15, 15, 15, 15 };
	*(m_chArrGymCarpet + 1) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrGymCarpet + 2) = new char[TILE_SIZE_X] { 13, 13, 13, 13, 13, 13, 13, 13 };
	*(m_chArrGymCarpet + 3) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrGymCarpet + 4) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrGymCarpet + 5) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrGymCarpet + 6) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };
	*(m_chArrGymCarpet + 7) = new char[TILE_SIZE_X] { 12, 12, 12, 12, 12, 12, 12, 12 };

	m_chArrPointString = new char[POINT_STRING_WIDTH * POINT_STRING_HEIGHT]
	{
		0, 0, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 0, 0,
		0, 0, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 0, 0
	};


	m_eMapTile_Type = new EMapTile_Type * [GYM_MAP_SIZE_Y];
	*(m_eMapTile_Type + 0) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// º®
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 1) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// º®
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 2) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// º®
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,
		EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL, EMapTile_Type::GYM_WALL,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 3) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 4) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// º®2
		EMapTile_Type::GYM_WALL2_LEFTUP, EMapTile_Type::GYM_WALL2_RIGHTUP, EMapTile_Type::GYM_WALL2_LEFTUP, EMapTile_Type::GYM_WALL2_RIGHTUP,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// º®2
		EMapTile_Type::GYM_WALL2_LEFTUP, EMapTile_Type::GYM_WALL2_RIGHTUP, EMapTile_Type::GYM_WALL2_LEFTUP, EMapTile_Type::GYM_WALL2_RIGHTUP,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 5) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// º®2
		EMapTile_Type::GYM_WALL2_LEFTDOWN, EMapTile_Type::GYM_WALL2_RIGHTDOWN, EMapTile_Type::GYM_WALL2_LEFTDOWN, EMapTile_Type::GYM_WALL2_RIGHTDOWN,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// º®2
		EMapTile_Type::GYM_WALL2_LEFTDOWN, EMapTile_Type::GYM_WALL2_RIGHTDOWN, EMapTile_Type::GYM_WALL2_LEFTDOWN, EMapTile_Type::GYM_WALL2_RIGHTDOWN,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 6) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 7) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 8) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 9) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 10) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ³¶¶°·¯Áö
		EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP,
		EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ³¶¶°·¯Áö
		EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP,
		EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP, EMapTile_Type::GYM_FALLROAD_UP,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 11) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ³¶¶°·¯Áö
		EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN,
		EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ³¶¶°·¯Áö
		EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN,
		EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN, EMapTile_Type::GYM_FALLROAD_DOWN,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 12) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 13) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 14) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 15) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 16) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ¼®»ó
		EMapTile_Type::GYM_STATUE_LEFTUP, EMapTile_Type::GYM_STATUE_RIGHTUP,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ¼®»ó
		EMapTile_Type::GYM_STATUE_LEFTUP, EMapTile_Type::GYM_STATUE_RIGHTUP,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 17) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ¼®»ó
		EMapTile_Type::GYM_STATUE_LEFTMIDDLE1, EMapTile_Type::GYM_STATUE_RIGHTMIDDLE1,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ¼®»ó
		EMapTile_Type::GYM_STATUE_LEFTMIDDLE1, EMapTile_Type::GYM_STATUE_RIGHTMIDDLE1,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 18) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ¼®»ó
		EMapTile_Type::GYM_STATUE_LEFTMIDDLE2, EMapTile_Type::GYM_STATUE_RIGHTMIDDLE2,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ¼®»ó
		EMapTile_Type::GYM_STATUE_LEFTMIDDLE2, EMapTile_Type::GYM_STATUE_RIGHTMIDDLE2,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 19) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ¼®»ó
		EMapTile_Type::GYM_STATUE_LEFTDOWN, EMapTile_Type::GYM_STATUE_RIGHTDOWN,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ¼®»ó
		EMapTile_Type::GYM_STATUE_LEFTDOWN, EMapTile_Type::GYM_STATUE_RIGHTDOWN,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 20) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 21) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 22) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// Ä«Æê
		EMapTile_Type::ROAD_CARPET_UP, EMapTile_Type::ROAD_CARPET_UP, EMapTile_Type::ROAD_CARPET_UP, EMapTile_Type::ROAD_CARPET_UP,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};

	*(m_eMapTile_Type + 23) = new EMapTile_Type[GYM_MAP_SIZE_X]
	{
		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// Ä«Æê
		EMapTile_Type::ROAD_CARPET_DOWN, EMapTile_Type::ROAD_CARPET_DOWN, EMapTile_Type::ROAD_CARPET_DOWN, EMapTile_Type::ROAD_CARPET_DOWN,

		// ±æ
		EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM, EMapTile_Type::ROAD_GYM,

		// ºí·©Å©
		EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK, EMapTile_Type::BLANK,
		EMapTile_Type::BLANK, EMapTile_Type::BLANK
	};


	m_chArrMap = new char* [GYM_MAP_SIZE_MAX_Y];
	for (int i = 0; i < GYM_MAP_SIZE_Y; i++)
	{
		*(m_chArrMap + 0 + i * TILE_SIZE_Y) = new char[GYM_MAP_SIZE_MAX_X];
		*(m_chArrMap + 1 + i * TILE_SIZE_Y) = new char[GYM_MAP_SIZE_MAX_X];
		*(m_chArrMap + 2 + i * TILE_SIZE_Y) = new char[GYM_MAP_SIZE_MAX_X];
		*(m_chArrMap + 3 + i * TILE_SIZE_Y) = new char[GYM_MAP_SIZE_MAX_X];
		*(m_chArrMap + 4 + i * TILE_SIZE_Y) = new char[GYM_MAP_SIZE_MAX_X];
		*(m_chArrMap + 5 + i * TILE_SIZE_Y) = new char[GYM_MAP_SIZE_MAX_X];
		*(m_chArrMap + 6 + i * TILE_SIZE_Y) = new char[GYM_MAP_SIZE_MAX_X];
		*(m_chArrMap + 7 + i * TILE_SIZE_Y) = new char[GYM_MAP_SIZE_MAX_X];

		for (int j = 0; j < GYM_MAP_SIZE_X; j++)
		{
			switch (*(*(m_eMapTile_Type + i) + j))
			{
			case EMapTile_Type::BLANK:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrBlank + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROAD_GYM:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymRoad + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_FALLROAD_UP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymFallRoadUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_FALLROAD_DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymFallRoadDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_WALL:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymWall + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_WALL2_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymWall2 + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_WALL2_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymWall2 + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::GYM_WALL2_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymWall2 + (TILE_SIZE_Y - y - 1)) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_WALL2_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymWall2 + (TILE_SIZE_Y - y - 1)) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::GYM_STATUE_LEFTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymStatueUp + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_STATUE_RIGHTUP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymStatueUp + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::GYM_STATUE_LEFTMIDDLE1:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymStatueMiddle1 + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_STATUE_RIGHTMIDDLE1:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymStatueMiddle1 + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::GYM_STATUE_LEFTMIDDLE2:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymStatueMiddle2 + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_STATUE_RIGHTMIDDLE2:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymStatueMiddle2 + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::GYM_STATUE_LEFTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymStatueDown + y) + x);
					}
				}
				break;

			case EMapTile_Type::GYM_STATUE_RIGHTDOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymStatueDown + y) + (TILE_SIZE_X - x - 1));
					}
				}
				break;

			case EMapTile_Type::ROAD_CARPET_UP:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymCarpet + y) + x);
					}
				}
				break;

			case EMapTile_Type::ROAD_CARPET_DOWN:
				for (int y = 0; y < TILE_SIZE_Y; y++)
				{
					for (int x = 0; x < TILE_SIZE_X; x++)
					{
						*(*(m_chArrMap + y + i * TILE_SIZE_Y) + x + j * TILE_SIZE_X) = *(*(m_chArrGymCarpet + (TILE_SIZE_Y - y - 1)) + x);
					}
				}
				break;
			}
		}
	}
}