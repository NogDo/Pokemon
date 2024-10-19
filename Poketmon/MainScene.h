#pragma once
#include "GameScene.h"

#define TITLE_START_X				26
#define TITLE_START_Y				3
#define GAMESTART_TEXT_START_X		94
#define GAMESTART_TEXT_START_Y		34
#define GAMEQUIT_TEXT_START_X		94
#define GAMEQUIT_TEXT_START_Y		39

class MainScene : public GameScene
{
private:
	DoubleBuffering* m_DoubleBuffering;

	char* m_chArrTitleSprite;

	int m_nArrowIndex;

public:
	void Init() override;
	void Draw() override;

	int GetArrowIndex() { return m_nArrowIndex; }
	void SetArrowPosition(int nPos);

	MainScene();
	~MainScene();
};

