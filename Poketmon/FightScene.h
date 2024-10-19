#pragma once
#include <vector>
#include "GameScene.h"
#include "Poketmon.h"
#include "Player.h"

#define PANEL_START_X				0
#define PANEL_START_Y				37
#define PLAYER_POKETMON_START_X		20
#define PLAYER_POKETMON_START_Y		10
#define ENEMY_POKETMON_START_X		130
#define ENEMY_POKETMON_START_Y		10
#define TEXT_START_X				20
#define TEXT_START_Y				43
#define TEXT_INCREASE_X(i)			TEXT_START_X + 48 * i
#define CHANGE_TEXT_START_X			10
#define CHANGE_TEXT_START_Y			43
#define CHANGE_TEXT_INCREASE_X(i)	CHANGE_TEXT_START_X + 32 * i

enum class EPanel_Type
{
	CHOICE_PANEL,
	FIGHT_PANEL,
	INVENTORY_PANEL,
	POKETMON_PANEL,
	PLAYER_RESULT_PANEL,
	ENEMY_RESULT_PANEL,
	RESULT_PANEL
};

class FightScene : public GameScene
{
private:
	EPanel_Type m_ePanelType;
	EPanel_Type m_ePrevPanelType;
	DoubleBuffering* m_DoubleBuffering;
	Poketmon* m_Poketmon[2];
	Player* m_Player;

	const char* m_strChoicePanelWords[4];
	char* m_strComment[10];
	char* m_strPlayerPoketmonInfo;
	char* m_strPlayerPoketmonHP;
	char* m_strEnemyPoketmonInfo;
	char* m_strEnemyPoketmonHP;
	char* m_strItemInfo;
	char* m_strChangePoketmonInfo;
	char* m_strChangePoketmonHp;

	int m_nArrowPos;
	int m_nPanelWidth;
	int m_nPanelHeight;
	char* m_chArrPanelSprite;
	char* m_chArrPlayerHpSprite;
	char* m_chArrEnemyHpSprite;
	char* m_chArrMonsterBallSprite;

	int m_nResultWordCount;
	int m_nCurrentResultWordindex;

	bool m_isPlayerAnimation;
	bool m_isEnemyAnimation;
	bool m_isMonsterBallAnimation;
	bool m_isCatch;
	int m_nMonsterBallAnimationCount;

public:
	void Init() override;
	void Draw() override;

	void DrawPlayerPoketmonInfo();
	void DrawEnemyPoketmonInfo();
	void DrawChoicePanel();
	void DrawFightPanel();
	void DrawInventoryPanel();
	void DrawPoketmonPanel();
	void DrawPlayerResultPanel();
	void DrawEnemyResultPanel();
	void DrawResultPanel();

	EPanel_Type GetPanelType() { return m_ePanelType; }
	EPanel_Type GetPrevPanelType() { return m_ePrevPanelType; }

	int GetArrowPosition() { return m_nArrowPos; }
	int GetResultWordCount() { return m_nResultWordCount; }
	int GetCurrentResultWordIndex() { return m_nCurrentResultWordindex; }

	void SetCurrentPlayerPoketmon(Poketmon* poketmon) { this->m_Poketmon[0] = poketmon; }
	void SetCurrentEnemyPoketmon(Poketmon* poketmon) { this->m_Poketmon[1] = poketmon; }

	void SetComment(const char* strPoketmonName, const char* strSkillName, int nIndex);
	void SetComment(const char* strComment, int nIndex);
	void SetLearnComment(const char* strSkillname, int nIndex);
	void SetItemUseComment(const char* strItemName, int nIndex);
	void SetCatchPoketmonComment(int nIndex);
	void SetChangePoketmonComment(const char* strPoketmonName, int nIndex);
	void SetDownPoketmonComment(const char* strPoketmonName, int nIndex);
	void SetMoneyGainComment(int nMoney, int nIndex);
	void SetEvolutionPrevComment(const char* strPoketmonName, int nIndex);
	void SetEvolutionComment(const char* strPoketmonName, int nIndex);

	void SetPanelType(EPanel_Type nPanelType) { this->m_ePanelType = nPanelType; }
	void SetPrevPanelType(EPanel_Type nPanelType) { this->m_ePrevPanelType = nPanelType; }
	void SetPlayer(Player* player) { this->m_Player = player; }

	void SetResultWordCount(int nCount) { this->m_nResultWordCount = nCount; }
	void SetCurrentResultWordIndex(int nIndex) { this->m_nCurrentResultWordindex = nIndex; }
	void SetArrowPosition(int nPos) { this->m_nArrowPos = nPos; }
	void MoveArrowPosition(int nPos);

	void SetIsPlayerAnimation(bool isPlayerAnimation) { this->m_isPlayerAnimation = isPlayerAnimation; }
	void SetIsEnemyAnimation(bool isEnemyAnimation) { this->m_isEnemyAnimation = isEnemyAnimation; }
	void SetIsMonsterBallAnimation(bool isMonsterBallAnimation) { this->m_isMonsterBallAnimation = isMonsterBallAnimation; }
	void SetIsCatch(bool isCatch) { this->m_isCatch = isCatch; }
	void SetMonsterBallAnimationCount(int nCount) { this->m_nMonsterBallAnimationCount = nCount; }

	FightScene(Poketmon* PlayerPoketmon, Poketmon* EnemyPoketmon);
	~FightScene();
};

