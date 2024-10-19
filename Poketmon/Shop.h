#pragma once
#include "Item_MonsterBall.h"
#include "Item_Potion.h"

#define SHOP_ARROW_WIDTH					7
#define SHOP_ARROW_HEIGHT					6
#define SHOP_ARROW_START_X(startX, PosX)	startX + PosX
#define SHOP_ARROW_START_Y(startY, PosY)	startY + PosY
#define SHOP_ARROW_MOVE_X					100

#define MONSTERBALL_WIDTH					32
#define MONSTERBALL_HEIGHT					8
#define MONSTERBALL_START_X					10
#define MONSTERBALL_START_Y					79

#define POTION_WIDTH						24
#define POTION_HEIGHT						8
#define POTION_START_X						MONSTERBALL_START_X + MONSTERBALL_WIDTH * 2 + 30
#define POTION_START_Y						79

#define PLAYERMONEY_WIDTH					24
#define PLAYERMONEY_HEIGHT					8
#define PLAYERMONEY_START_X					26
#define PLAYERMONEY_START_Y					52

#define PLAYERMONEY_PANEL_WIDTH				50
#define PLAYERMONEY_PANEL_HEIGHT			20
#define PLAYERMONEY_PANEL_START_X			0
#define PLAYERMONEY_PANEL_START_Y			50

class Shop
{
private:
	Item_MonsterBall* m_ItemMonsterBall;
	Item_Potion* m_ItemPotion;

	char* m_chArrPlayerMoneyString;
	char* m_chArrPlayerMoneyPanel;
	char* m_chArrPriceString;
	char* m_chArrNumberString[10];

public:
	void Init();

	char* GetMonsterBallStringSprite() { return m_ItemMonsterBall->GetStringSprite(); }
	char* GetPotionStringSprite() { return m_ItemPotion->GetStringSprite(); }
	char* GetPlayerMoneyStringSprite() { return m_chArrPlayerMoneyString; }
	char* GetPlayerMoneyPanelSprite() { return m_chArrPlayerMoneyPanel; }
	char* GetPriceStringSprite() { return m_chArrPriceString; }
	char* GetNumberStringSprite(int nNumber) { return m_chArrNumberString[nNumber]; }
	int GetMonsterBallPrice() { return m_ItemMonsterBall->GetPrice(); }
	int GetPotionPrice() { return m_ItemPotion->GetPrice(); }
	Item* GetSelectedItem(int nIndex);

	Shop();
	~Shop();
};