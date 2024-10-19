#pragma once
#include <iostream>
#include <vector>
#include "Inventory.h"
#include "Poketmon_Charmander.h"
#include "Poketmon_Bulbasaur.h"
#include "Poketmon_Squirtle.h"
#include "Poketmon_Pikachu.h"
#include "Poketmon_Pidgey.h"
#include "Poketmon_Rattata.h"

#define PLAYER_SPRITE_WIDTH		14
#define PLAYER_SPRITE_HEIGHT	16

enum class EPlayerState_Type : uint16_t
{
	IDLE_UP,
	IDLE_DOWN,
	IDLE_LEFT,
	IDLE_RIGHT,
	WALK_UP,
	WALK_DOWN,
	WALK_LEFT,
	WALK_RIGHT
};

class Player
{
private:
	std::vector<Poketmon*> m_vPoketmon;
	std::vector<Poketmon*>::iterator m_viPoketmon;
	Inventory* m_Inventory;
	EPlayerState_Type m_ePlayerState;

	char* m_chArrSprite[7];
	int m_nAnimationCount;
	int m_nMoney;

public:
	void Init();

	std::vector<Poketmon*> GetPoketmonVector() { return m_vPoketmon; }
	Poketmon* GetPoketmon(int nIndex) { return m_vPoketmon.at(nIndex); }
	Inventory* GetInventory() { return m_Inventory; }
	EPlayerState_Type GetPlayerState() { return m_ePlayerState; }
	int GetPoketmonCount() { return m_vPoketmon.size(); }
	int GetAnimationCount() { return m_nAnimationCount; }
	int GetMoney() { return m_nMoney; }
	int GetHavePoketmonCount() { return m_vPoketmon.size(); }

	void SetPlayerState(EPlayerState_Type PlayerState) { this->m_ePlayerState = PlayerState; }
	void SetAnimationCount(int nAnimationCount) { this->m_nAnimationCount = nAnimationCount; }
	void SetMoney(int nMoney) { this->m_nMoney = nMoney; }

	char* GetSprite();
	bool IsCanFight();
	void HealPoketmon();
	void AddPoketmon(Poketmon* poketmon);

	Player();
	~Player();
};