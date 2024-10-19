#pragma once
#include <iostream>
#include "IGameScene.h"
#include "ConsoleColor.h"
#include "DoubleBuffering.h"

using std::cout;
using std::cin;

class GameScene : public IGameScene
{
protected:
	char* m_strCommand;

	const int m_nWidth;
	const int m_nHeight;

public:
	virtual void Init() PURE;
	virtual void Draw() PURE;

	GameScene();
	virtual ~GameScene();
};

