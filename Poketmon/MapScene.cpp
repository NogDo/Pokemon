#include "MapScene.h"


MapScene::MapScene()
{
	Init();
}

MapScene::~MapScene()
{
	delete m_SoundManager;
	delete m_VillageMap;
	delete m_PoketmonCenterMap;
	delete m_ShopMap;
	delete m_GymMap;
	delete m_DoubleBuffering;
	delete m_NpcNurse;
	delete m_NpcSeller;
	delete[] m_chArrPlayerSprite;
	delete[] m_chArrTalkPanel;
	delete[] m_chArrYes;
	delete[] m_chArrNo;
	delete[] m_chArrArrow;
}

void MapScene::Init()
{
	m_strCommand = new char[30];
	sprintf_s(m_strCommand, 30, "mode con: cols=%d lines=%d", m_nWidth, m_nHeight);
	system(m_strCommand);

	m_SoundManager = new SoundManager;
	m_DoubleBuffering = new DoubleBuffering(static_cast<int>(EColor_Type::WHITE), m_nWidth, m_nHeight, 8);

	m_VillageMap = new VillageMap;
	m_PoketmonCenterMap = new PoketmonCenterMap;
	m_ShopMap = new ShopMap;
	m_GymMap = new GymMap;
	m_Shop = new Shop;

	m_CurrentMap = m_VillageMap;
	m_eCurrnetMapType = m_VillageMap->GetMapType();

	m_NpcNurse = new NpcNurse;
	m_NpcSeller = new NpcSeller;
	m_NpcBoss = new NpcBoss;

	m_nMapSizeMaxX = VILLAGE_MAP_SIZE_MAX_X;
	m_nMapSizeMaxY = VILLAGE_MAP_SIZE_MAX_Y;

	m_nStartX = 156;
	m_nStartY = 32;
	m_nEndX = m_nStartX + m_nWidth / 2;
	m_nEndY = m_nStartY + m_nHeight;
	m_nMiddleX = (m_nEndX + m_nStartX) / 2;
	m_nMiddleY = (m_nEndY + m_nStartY) / 2;
	m_nPlayerX = m_nMiddleX - 10;
	m_nPlayerY = m_nMiddleY - 4;

	m_isTalk = false;


	m_chArrTalkPanel = new char[TALK_PANEL_WIDTH * TALK_PANEL_HEIGHT];
	for (int i = 0; i < TALK_PANEL_WIDTH * TALK_PANEL_HEIGHT; i++)
	{
		if (i / TALK_PANEL_WIDTH == 0 || i / TALK_PANEL_WIDTH == TALK_PANEL_HEIGHT - 1)
		{
			*(m_chArrTalkPanel + i) = 0;
		}

		else if (i % TALK_PANEL_WIDTH == 0 || i % TALK_PANEL_WIDTH == TALK_PANEL_WIDTH - 1)
		{
			*(m_chArrTalkPanel + i) = 0;
		}

		else
		{
			*(m_chArrTalkPanel + i) = 15;
		}
	}

	m_chArrYes = new char[YES_STRING_WIDTH * YES_STRING_HEIGHT]
	{
		0, 15, 15, 15, 0, 15, 0, 15,
		0, 15, 15, 15, 0, 15, 0, 15,
		0, 15, 0, 0, 0, 15, 0, 15,
		0, 15, 15, 15, 0, 15, 0, 15,
		0, 0, 0, 15, 0, 15, 0, 15,
		15, 15, 15, 15, 0, 15, 0, 15,
		15, 15, 15, 15, 15, 15, 0, 15,
		15, 15, 15, 15, 15, 15, 15, 15
	};

	m_chArrNo = new char[NO_STRING_WIDTH * NO_STRING_HEIGHT]
	{
		15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15,
		15, 0, 0, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 0, 15, 0, 15, 15, 15, 0, 15,
		0, 15, 15, 0, 15, 0, 15, 15, 0, 15, 15, 15, 15, 0, 15, 0, 15, 15, 15, 0, 15,
		0, 15, 15, 0, 15, 0, 0, 15, 0, 15, 15, 15, 15, 0, 15, 15, 0, 0, 0, 15, 15,
		0, 15, 15, 0, 15, 0, 15, 15, 0, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15,
		15, 0, 0, 15, 15, 0, 15, 15, 0, 0, 0, 0, 15, 0, 15, 15, 15, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 0, 15, 0, 0, 0, 0, 0, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15
	};

	m_chArrArrow = new char[YESNO_ARROW_WIDTH * YESNO_ARROW_HEIGHT]
	{
		0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0,
		15, 0, 0, 0, 0, 0, 15,
		15, 0, 0, 0, 0, 0, 15,
		15, 15, 0, 0, 0, 15, 15,
		15, 15, 15, 0, 15, 15, 15
	};
}

/// <summary>
/// MapScene 그리기
/// </summary>
void MapScene::Draw()
{
	m_DoubleBuffering->FillScreen(m_nStartX, m_nStartY, m_CurrentMap->GetMap(), m_nEndX, m_nEndY);

	switch (m_eCurrnetMapType)
	{
	case EMap_Type::POKETMONCENTER:
		if (m_nNpcNurseY - m_nStartY > -m_NpcNurse->GetHeight())
		{
			m_DoubleBuffering->FillScreen(m_nNpcNurseX - m_nStartX * 2, m_nNpcNurseY - m_nStartY, m_NpcNurse->GetSprite(), m_NpcNurse->GetWidth(), m_NpcNurse->GetHeight(), false, 15);
		}

		if (m_isTalk)
		{
			m_DoubleBuffering->FillScreen(TALK_PANEL_START_X, TALK_PANEL_START_Y, m_chArrTalkPanel, TALK_PANEL_WIDTH, TALK_PANEL_HEIGHT, false);
			m_DoubleBuffering->FillScreen(TALK_PANEL_START_X + 10, TALK_PANEL_START_Y + 11, m_PoketmonCenterMap->GetHealString(), HEAL_STRING_WIDTH, HEAL_STRING_HEIGHT, false);

			m_DoubleBuffering->FillScreen(YES_STRING_START_X, YES_STRING_START_Y, m_chArrYes, YES_STRING_WIDTH, YES_STRING_HEIGHT, false);
			m_DoubleBuffering->FillScreen(NO_STRING_START_X, NO_STRING_START_Y, m_chArrNo, NO_STRING_WIDTH, NO_STRING_HEIGHT, false);
			m_DoubleBuffering->FillScreen(YESNO_ARROW_START_X(YES_STRING_START_X, YESNO_ARROW_MOVE_X * m_nArrowIndex), YESNO_ARROW_START_Y(YES_STRING_START_Y, -8), m_chArrArrow, YESNO_ARROW_WIDTH, YESNO_ARROW_HEIGHT, false);
		}
		break;

	case EMap_Type::SHOP:
		if (m_nNpcSellerY - m_nStartY > -m_NpcSeller->GetHeight())
		{
			m_DoubleBuffering->FillScreen(m_nNpcSellerX - m_nStartX * 2, m_nNpcSellerY - m_nStartY, m_NpcSeller->GetSprite(), m_NpcSeller->GetWidth(), m_NpcSeller->GetHeight(), false, 15);
		}

		if (m_isTalk)
		{
			m_DoubleBuffering->FillScreen(TALK_PANEL_START_X, TALK_PANEL_START_Y, m_chArrTalkPanel, TALK_PANEL_WIDTH, TALK_PANEL_HEIGHT, false);
			m_DoubleBuffering->FillScreen(PLAYERMONEY_PANEL_START_X, PLAYERMONEY_PANEL_START_Y, m_Shop->GetPlayerMoneyPanelSprite(), PLAYERMONEY_PANEL_WIDTH, PLAYERMONEY_PANEL_HEIGHT, false);

			m_DoubleBuffering->FillScreen(PLAYERMONEY_START_X, PLAYERMONEY_START_Y, m_Shop->GetPlayerMoneyStringSprite(), PLAYERMONEY_WIDTH, PLAYERMONEY_HEIGHT, false);
			m_DoubleBuffering->FillScreen(PLAYERMONEY_START_X - 16, PLAYERMONEY_START_Y + 8, m_Shop->GetPriceStringSprite(), 8, 8, false);

			int nPrice = m_nPlayerMoeny;
			int nUnit;

			if (nPrice >= 100000)
			{
				nUnit = 100000;
			}

			else if (nPrice >= 10000)
			{
				nUnit = 10000;
			}

			else if (nPrice >= 1000)
			{
				nUnit = 1000;
			}

			else if(nPrice >= 100)
			{
				nUnit = 100;
			}
			else
			{
				nUnit = 10;
			}

			for (int j = 0; nUnit >= 1; nUnit /= 10, j += 8)
			{
				m_DoubleBuffering->FillScreen(PLAYERMONEY_START_X + j, PLAYERMONEY_START_Y + 10, m_Shop->GetNumberStringSprite(nPrice / nUnit), 3, 5, false);
				nPrice -= nUnit * (nPrice / nUnit);
			}


			m_DoubleBuffering->FillScreen(MONSTERBALL_START_X, MONSTERBALL_START_Y, m_Shop->GetMonsterBallStringSprite(), MONSTERBALL_WIDTH, MONSTERBALL_HEIGHT, false);
			m_DoubleBuffering->FillScreen(MONSTERBALL_START_X, MONSTERBALL_START_Y + 9, m_Shop->GetPriceStringSprite(), 8, 8, false);

			nPrice = m_Shop->GetMonsterBallPrice();
			if (nPrice < 1000)
			{
				nUnit = 100;
			}

			else
			{
				nUnit = 1000;
			}

			for (int j = 16; nUnit >= 1; nUnit /= 10, j += 8)
			{
				m_DoubleBuffering->FillScreen(MONSTERBALL_START_X + j, MONSTERBALL_START_Y + 11, m_Shop->GetNumberStringSprite(nPrice / nUnit), 3, 5, false);
				nPrice -= nUnit * (nPrice / nUnit);
			}


			m_DoubleBuffering->FillScreen(POTION_START_X, POTION_START_Y, m_Shop->GetPotionStringSprite(), POTION_WIDTH, POTION_HEIGHT, false);
			m_DoubleBuffering->FillScreen(POTION_START_X, POTION_START_Y + 9, m_Shop->GetPriceStringSprite(), 8, 8, false);

			nPrice = m_Shop->GetPotionPrice();
			if (nPrice < 1000)
			{
				nUnit = 100;
			}

			else
			{
				nUnit = 1000;
			}

			for (int j = 16; nUnit >= 1; nUnit /= 10, j += 8)
			{
				m_DoubleBuffering->FillScreen(POTION_START_X + j, POTION_START_Y + 11, m_Shop->GetNumberStringSprite(nPrice / nUnit), 3, 5, false);
				nPrice -= nUnit * (nPrice / nUnit);
			}

			m_DoubleBuffering->FillScreen(SHOP_ARROW_START_X(MONSTERBALL_START_X, SHOP_ARROW_MOVE_X * m_nArrowIndex), SHOP_ARROW_START_Y(MONSTERBALL_START_Y, -7), m_chArrArrow, SHOP_ARROW_WIDTH, SHOP_ARROW_HEIGHT, false);
		}
		break;

	case EMap_Type::GYM:
		if (m_nNpcBossY - m_nStartY > -m_NpcBoss->GetHeight())
		{
			m_DoubleBuffering->FillScreen(m_nNpcBossX - m_nStartX * 2, m_nNpcBossY - m_nStartY, m_NpcBoss->GetSprite(), m_NpcBoss->GetWidth(), m_NpcBoss->GetHeight(), false, 15);
		}

		if (m_isTalk)
		{
			m_DoubleBuffering->FillScreen(TALK_PANEL_START_X, TALK_PANEL_START_Y, m_chArrTalkPanel, TALK_PANEL_WIDTH, TALK_PANEL_HEIGHT, false);
			m_DoubleBuffering->FillScreen(TALK_PANEL_START_X + 20, TALK_PANEL_START_Y + 15, m_GymMap->GetPointString(), POINT_STRING_WIDTH, POINT_STRING_HEIGHT, false);
		}
		break;
	}

	m_DoubleBuffering->FillScreen((m_nPlayerX - m_nStartX) * 2, m_nPlayerY - m_nStartY, m_chArrPlayerSprite, 14, 16, m_isReverse, 15);

	m_DoubleBuffering->DrawScreen();
	m_DoubleBuffering->ClearScreen();
	m_DoubleBuffering->ChangeScreen();
}

/// <summary>
/// 플레이어 및 맵 포지션 변경
/// </summary>
/// <param name="nPosX"></param>
/// <param name="nPosY"></param>
void MapScene::SetPosition(int nPosX, int nPosY)
{
	if (m_nStartX + nPosX < 0 || m_nEndX + nPosX > m_nMapSizeMaxX)
	{
		m_nPlayerX += nPosX;

		return;
	}

	else if (m_nStartY + nPosY < 0 || m_nEndY + nPosY > m_nMapSizeMaxY)
	{
		m_nPlayerY += nPosY;

		return;
	}

	else
	{
		if (m_nMiddleX == m_nPlayerX + 10)
		{
			m_nStartX += nPosX;
			m_nEndX += nPosX;
			m_nPlayerX += nPosX;
			m_nMiddleX += nPosX;
		}

		else
		{
			m_nPlayerX += nPosX;
		}


		if (m_nMiddleY == m_nPlayerY + 4)
		{
			m_nStartY += nPosY;
			m_nEndY += nPosY;
			m_nPlayerY += nPosY;
			m_nMiddleY += nPosY;
		}

		else
		{
			m_nPlayerY += nPosY;
		}
	}
}

/// <summary>
/// 화살표 위치 옮기기
/// </summary>
/// <param name="nPos"></param>
void MapScene::SetArrowIndex(int nPos)
{
	if (m_nArrowIndex + nPos < 0 || m_nArrowIndex + nPos > 1)
	{
		return;
	}

	else
	{
		m_nArrowIndex += nPos;
	}
}

/// <summary>
/// 마을맵 들어가기
/// </summary>
void MapScene::EnterVillageMap()
{
	m_SoundManager->PlayVillageBGM();

	m_CurrentMap = m_VillageMap;
	m_eCurrnetMapType = m_VillageMap->GetMapType();

	m_nStartX = m_nPrevStartX;
	m_nStartY = m_nPrevStartY;
	m_nEndX = m_nPrevEndX;
	m_nEndY = m_nPrevEndY;
	m_nMiddleX = m_nPrevMiddleX;
	m_nMiddleY = m_nPrevMiddleY;
	m_nPlayerX = m_nPrevPlayerX;
	m_nPlayerY = m_nPrevPlayerY;

	m_nMapSizeMaxX = VILLAGE_MAP_SIZE_MAX_X;
	m_nMapSizeMaxY = VILLAGE_MAP_SIZE_MAX_Y;
}

/// <summary>
/// 포켓몬 센터맵 들어가기
/// </summary>
void MapScene::EnterPoketmonCenter()
{
	m_SoundManager->PlayPoketmonCenterBGM();

	m_CurrentMap = m_PoketmonCenterMap;
	m_eCurrnetMapType = m_PoketmonCenterMap->GetMapType();

	m_nPrevStartX = m_nStartX;
	m_nPrevStartY = m_nStartY;
	m_nPrevEndX = m_nEndX;
	m_nPrevEndY = m_nEndY;
	m_nPrevMiddleX = m_nMiddleX;
	m_nPrevMiddleY = m_nMiddleY;
	m_nPrevPlayerX = m_nPlayerX;
	m_nPrevPlayerY = m_nPlayerY;

	m_nStartX = 0;
	m_nStartY = 28;
	m_nEndX = m_nStartX + m_nWidth / 2;
	m_nEndY = m_nStartY + m_nHeight;
	m_nMiddleX = (m_nEndX + m_nStartX) / 2;
	m_nMiddleY = (m_nEndY + m_nStartY) / 2;
	m_nPlayerX = m_nMiddleX - 10;
	m_nPlayerY = m_nMiddleY + 32;

	m_nNpcNurseX = 104;
	m_nNpcNurseY = 12;

	m_nArrowIndex = 0;

	m_nMapSizeMaxX = POKETMONCENTER_MAP_SIZE_MAX_X;
	m_nMapSizeMaxY = POKETMONCENTER_MAP_SIZE_MAX_Y;
}

/// <summary>
/// 상점 맵 들어가기
/// </summary>
void MapScene::EnterShop()
{
	m_SoundManager->PlayPoketmonCenterBGM();

	m_CurrentMap = m_ShopMap;
	m_eCurrnetMapType = m_ShopMap->GetMapType();

	m_nPrevStartX = m_nStartX;
	m_nPrevStartY = m_nStartY;
	m_nPrevEndX = m_nEndX;
	m_nPrevEndY = m_nEndY;
	m_nPrevMiddleX = m_nMiddleX;
	m_nPrevMiddleY = m_nMiddleY;
	m_nPrevPlayerX = m_nPlayerX;
	m_nPrevPlayerY = m_nPlayerY;

	m_nStartX = 0;
	m_nStartY = 28;
	m_nEndX = m_nStartX + m_nWidth / 2;
	m_nEndY = m_nStartY + m_nHeight;
	m_nMiddleX = (m_nEndX + m_nStartX) / 2;
	m_nMiddleY = (m_nEndY + m_nStartY) / 2;
	m_nPlayerX = m_nMiddleX - 46;
	m_nPlayerY = m_nMiddleY + 32;

	m_nNpcSellerX = 36;
	m_nNpcSellerY = 34;

	m_nArrowIndex = 0;

	m_nMapSizeMaxX = SHOP_MAP_SIZE_MAX_X;
	m_nMapSizeMaxY = SHOP_MAP_SIZE_MAX_Y;
}

/// <summary>
/// 체육관 맵 들어가기
/// </summary>
void MapScene::EnterGym()
{
	m_SoundManager->PlayChampionBGM();

	m_CurrentMap = m_GymMap;
	m_eCurrnetMapType = m_GymMap->GetMapType();

	m_nPrevStartX = m_nStartX;
	m_nPrevStartY = m_nStartY;
	m_nPrevEndX = m_nEndX;
	m_nPrevEndY = m_nEndY;
	m_nPrevMiddleX = m_nMiddleX;
	m_nPrevMiddleY = m_nMiddleY;
	m_nPrevPlayerX = m_nPlayerX;
	m_nPrevPlayerY = m_nPlayerY;

	m_nStartX = 0;
	m_nStartY = 92;
	m_nEndX = m_nStartX + m_nWidth / 2;
	m_nEndY = m_nStartY + m_nHeight;
	m_nMiddleX = (m_nEndX + m_nStartX) / 2;
	m_nMiddleY = (m_nEndY + m_nStartY) / 2;
	m_nPlayerX = m_nMiddleX - 10;
	m_nPlayerY = m_nMiddleY + 32;

	m_nNpcBossX = 192;
	m_nNpcBossY = 28;

	m_nArrowIndex = 0;

	m_nMapSizeMaxX = GYM_MAP_SIZE_MAX_X;
	m_nMapSizeMaxY = GYM_MAP_SIZE_MAX_Y;
}

/// <summary>
/// Npc말걸기
/// </summary>
void MapScene::TalkToNpc()
{
	switch (m_eCurrnetMapType)
	{
	case EMap_Type::POKETMONCENTER:
		if (m_nPlayerX == m_nNpcNurseX / 2 && m_nPlayerY - m_nNpcNurseY <= 26)
		{
			m_isTalk = true;
		}
		break;

	case EMap_Type::SHOP:
		if (m_nPlayerY == m_nNpcSellerY && m_nPlayerX - m_nNpcSellerX / 2 <= 30)
		{
			m_isTalk = true;
		}
		break;

	case EMap_Type::GYM:
		if (m_nPlayerX == m_nNpcBossX / 2 && m_nPlayerY - m_nNpcBossY <= 16)
		{
			m_isTalk = true;
		}
		break;
	}
}

/// <summary>
/// 움직일 수 있는지 판단
/// </summary>
/// <param name="nPosX"></param>
/// <param name="nPosY"></param>
/// <returns></returns>
bool MapScene::IsCanMove(int nPosX, int nPosY)
{
	if (m_nPlayerX + nPosX < 0 || m_nPlayerX + nPosX + 14 > m_nMapSizeMaxX)
	{
		return false;
	}

	if (m_nPlayerY + nPosY < 0 || m_nPlayerY + nPosY + 16 > m_nMapSizeMaxY)
	{
		return false;
	}

	int nX, nY;

	if (nPosX < 0)
	{
		int nNextY = (m_nPlayerY + 16) / 8;
		nX = (m_nPlayerX + nPosX) / 8;
		nY = (m_nPlayerY + 12) / 8;

		if (*(*(m_CurrentMap->GetMapTile() + nY) + nX) >= EMapTile_Type::TREE_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nY) + nX) <= EMapTile_Type::GYM_STATUE_RIGHTDOWN)
		{
			return false;
		}

		else if (*(*(m_CurrentMap->GetMapTile() + nNextY) + nX) >= EMapTile_Type::TREE_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nNextY) + nX) <= EMapTile_Type::GYM_STATUE_RIGHTDOWN)
		{
			return false;
		}

		else
		{
			return true;
		}
	}

	else if (nPosX > 0)
	{
		int nNextY = (m_nPlayerY + 16) / 8;
		nX = (m_nPlayerX + nPosX + 10) / 8;
		nY = (m_nPlayerY + 12) / 8;

		if (*(*(m_CurrentMap->GetMapTile() + nY) + nX) >= EMapTile_Type::TREE_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nY) + nX) <= EMapTile_Type::GYM_STATUE_RIGHTDOWN)
		{
			return false;
		}

		else if (*(*(m_CurrentMap->GetMapTile() + nNextY) + nX) >= EMapTile_Type::TREE_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nNextY) + nX) <= EMapTile_Type::GYM_STATUE_RIGHTDOWN)
		{
			return false;
		}

		else
		{
			return true;
		}
	}

	else if (nPosY < 0)
	{
		int nNextX = (m_nPlayerX + 8) / 8;
		nX = m_nPlayerX / 8;
		nY = (m_nPlayerY + nPosY + 12) / 8;

		if (*(*(m_CurrentMap->GetMapTile() + nY) + nX) >= EMapTile_Type::TREE_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nY) + nX) <= EMapTile_Type::GYM_STATUE_RIGHTDOWN)
		{
			return false;
		}

		else if (*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) >= EMapTile_Type::TREE_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) <= EMapTile_Type::GYM_STATUE_RIGHTDOWN)
		{
			return false;
		}

		else if (*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) >= EMapTile_Type::POKETMONCENTER_DOOR_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) <= EMapTile_Type::POKETMONCENTER_DOOR_RIGHTDOWN)
		{
			EnterPoketmonCenter();
			return false;
		}

		else if (*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) >= EMapTile_Type::SHOP_DOOR_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) <= EMapTile_Type::SHOP_DOOR_RIGHTDOWN)
		{
			EnterShop();
			return false;
		}

		else if (*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) >= EMapTile_Type::GYM_DOOR_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) <= EMapTile_Type::GYM_DOOR_RIGHTDOWN)
		{
			EnterGym();
			return false;
		}

		else
		{
			return true;
		}
	}

	else
	{
		int nNextX = (m_nPlayerX + 8) / 8;
		nX = m_nPlayerX / 8;
		nY = (m_nPlayerY + nPosY + 16) / 8;

		if (*(*(m_CurrentMap->GetMapTile() + nY) + nX) >= EMapTile_Type::TREE_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nY) + nX) <= EMapTile_Type::GYM_STATUE_RIGHTDOWN)
		{
			return false;
		}

		else if (*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) >= EMapTile_Type::TREE_LEFTUP &&
			*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) <= EMapTile_Type::GYM_STATUE_RIGHTDOWN)
		{
			return false;
		}

		else if (*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) >= EMapTile_Type::ROAD_CARPET_DOWN &&
			*(*(m_CurrentMap->GetMapTile() + nY) + nNextX) <= EMapTile_Type::ROAD_CARPET_DOWN)
		{
			EnterVillageMap();
			return false;
		}

		else
		{
			return true;
		}
	}
}

/// <summary>
/// 지금 있는 곳이 포켓몬 풀인지 확인
/// </summary>
/// <returns></returns>
bool MapScene::IsInPoketmonGrass()
{
	int nX, nY;
	nX = m_nPlayerX / 8;
	nY = (m_nPlayerY + 12) / 8;

	if (*(*(m_CurrentMap->GetMapTile() + nY) + nX) == EMapTile_Type::POKETMON_GRASS)
	{
		return true;
	}

	else
	{
		return false;
	}
}