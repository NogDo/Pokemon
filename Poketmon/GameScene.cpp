#include "GameScene.h"

GameScene::GameScene() : m_nWidth(360), m_nHeight(100)
{
	
}

GameScene::~GameScene()
{
	delete[] m_strCommand;
}