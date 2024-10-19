#pragma once
#include "GameScene.h"
#include "VillageMap.h"
#include "PoketmonCenterMap.h"
#include "ShopMap.h"
#include "GymMap.h"
#include "Shop.h"
#include "NpcNurse.h"
#include "NpcSeller.h"
#include "NpcBoss.h"
#include "SoundManager.h"

#define TALK_PANEL_WIDTH					180
#define TALK_PANEL_HEIGHT					30
#define TALK_PANEL_START_X					0
#define TALK_PANEL_START_Y					70

#define YES_STRING_WIDTH					8
#define YES_STRING_HEIGHT					8
#define YES_STRING_START_X					TALK_PANEL_START_X + 270
#define YES_STRING_START_Y					TALK_PANEL_START_Y + 11

#define NO_STRING_WIDTH						21
#define NO_STRING_HEIGHT					8
#define NO_STRING_START_X					TALK_PANEL_START_X + 300
#define NO_STRING_START_Y					TALK_PANEL_START_Y + 11

#define YESNO_ARROW_WIDTH					7
#define YESNO_ARROW_HEIGHT					6
#define YESNO_ARROW_START_X(startX, PosX)	startX + PosX
#define YESNO_ARROW_START_Y(startY, PosY)	startY + PosY
#define YESNO_ARROW_MOVE_X					42


class MapScene : public GameScene
{
private:
#pragma region 게임관리
	SoundManager* m_SoundManager;
	DoubleBuffering* m_DoubleBuffering;
#pragma endregion

#pragma region 맵
	VillageMap* m_VillageMap;
	PoketmonCenterMap* m_PoketmonCenterMap;
	ShopMap* m_ShopMap;
	Shop* m_Shop;
	GymMap* m_GymMap;
	Map* m_CurrentMap;
	EMap_Type m_eCurrnetMapType;

	int m_nMapSizeMaxX;
	int m_nMapSizeMaxY;
	int m_nStartX;
	int m_nStartY;
	int m_nEndX;
	int m_nEndY;
	int m_nMiddleX;
	int m_nMiddleY;
	int m_nPrevStartX;
	int m_nPrevStartY;
	int m_nPrevEndX;
	int m_nPrevEndY;
	int m_nPrevMiddleX;
	int m_nPrevMiddleY;
#pragma endregion

#pragma region NPC
	NpcNurse* m_NpcNurse;
	NpcSeller* m_NpcSeller;
	NpcBoss* m_NpcBoss;

	int m_nNpcNurseX;
	int m_nNpcNurseY;
	int m_nNpcSellerX;
	int m_nNpcSellerY;
	int m_nNpcBossX;
	int m_nNpcBossY;
#pragma endregion

#pragma region 플레이어 관련
	char* m_chArrPlayerSprite;

	bool m_isReverse;

	int m_nPlayerX;
	int m_nPlayerY;
	int m_nPrevPlayerX;
	int m_nPrevPlayerY;
	int m_nPlayerMoeny;
#pragma endregion

#pragma region 대화 패널 관련
	char* m_chArrTalkPanel;
	char* m_chArrYes;
	char* m_chArrNo;
	char* m_chArrArrow;

	bool m_isTalk;

	int m_nArrowIndex;
#pragma endregion


public:
	void Init() override;
	void Draw() override;

	DoubleBuffering* GetDoubleBuffering() { return m_DoubleBuffering; }
	EMap_Type GetCurrnetMapType() { return m_eCurrnetMapType; }
	bool GetIsTalk() { return m_isTalk; }
	int GetArrowIndex() { return m_nArrowIndex; }
	Item* GetSelectItem() { return m_Shop->GetSelectedItem(m_nArrowIndex); }
	Npc* GetNpcBoss() { return m_NpcBoss; }

	void SetDoubleBuffering(DoubleBuffering* doubleBuffering) { this->m_DoubleBuffering = doubleBuffering; }
	void SetPosition(int nPosX, int nPosY);
	void SetPlayerSprite(char* chArrPlayerSprite) { this->m_chArrPlayerSprite = chArrPlayerSprite; }
	void SetReverse(bool isReverse) { this->m_isReverse = isReverse; }
	void SetArrowIndex(int nPos);
	void SetIsTalk(bool isTalk) { this->m_isTalk = isTalk; }
	void SetPlayerMoney(int nMoney) { this->m_nPlayerMoeny = nMoney; }

	void EnterVillageMap();
	void EnterPoketmonCenter();
	void EnterShop();
	void EnterGym();
	void TalkToNpc();

	bool IsCanMove(int nPosX, int nPosY);
	bool IsInPoketmonGrass();

	MapScene();
	~MapScene();
};

