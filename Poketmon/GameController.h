#pragma once
#include "MainScene.h"
#include "MapScene.h"
#include "FightScene.h"
#include "KeyInput.h"
#include "Player.h"
#include "NpcEnemy.h"
#include "SoundManager.h"

enum class EScene_Type
{
	MAIN,
	FIGHT,
	MAP
};

class GameController
{
private:
	SoundManager* m_SoundManager;
	MapScene* m_MapScene;
	GameScene* m_GameScene;
	KeyInput* m_KeyInput;
	Player* m_Player;
	Npc* m_NpcEnemy;

	Poketmon* m_PlayerPoketmon;
	Poketmon* m_EnemyPoketmon;

	LARGE_INTEGER m_LIfrequency;
	LARGE_INTEGER m_LIcurrent;
	LARGE_INTEGER m_LIprev;
	float m_fDeltaTime;
	float m_fFPS;
	float m_fTime;

	int m_nPlayerX;
	int m_nPlayerY;
	int m_nComputerX;
	int m_nComputerY;

public:
	void ChageScene(EScene_Type newScene);
	void PlayMainScene();
	void PlayMapScene();
	void PlayFightScene();
	void GameQuit();

	GameController();
	~GameController();
};

