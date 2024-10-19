#include "FightScene.h"

FightScene::FightScene(Poketmon* PlayerPoketmon, Poketmon* EnemyPoketmon)
{
	m_Poketmon[0] = PlayerPoketmon;
	m_Poketmon[1] = EnemyPoketmon;

	Init();
}

FightScene::~FightScene()
{
	for (int i = 0; i < 10; i++)
	{
		delete[] m_strComment[i];
	}
	delete[] m_strPlayerPoketmonInfo;
	delete[] m_strEnemyPoketmonInfo;
	delete[] m_strPlayerPoketmonHP;
	delete[] m_strEnemyPoketmonHP;
	delete[] m_strItemInfo;
	delete[] m_strChangePoketmonInfo;
	delete[] m_strChangePoketmonHp;
	delete[] m_chArrPanelSprite;
	delete[] m_chArrPlayerHpSprite;
	delete[] m_chArrEnemyHpSprite;
	delete[] m_chArrMonsterBallSprite;
	delete m_DoubleBuffering;
}

/// <summary>
/// FightScene �ʱ�ȭ
/// </summary>
void FightScene::Init()
{
	m_strCommand = new char[30];
	sprintf_s(m_strCommand, 30, "mode con: cols=%d lines=%d", m_nWidth - 160, m_nHeight / 2);
	system(m_strCommand);

	m_DoubleBuffering = new DoubleBuffering(static_cast<int>(EColor_Type::WHITE), m_nWidth - 160, m_nHeight / 2, 16);

	m_strChoicePanelWords[0] = "�ο��";
	m_strChoicePanelWords[1] = "����";
	m_strChoicePanelWords[2] = "���ϸ�";
	m_strChoicePanelWords[3] = "����ġ��";

	for (int i = 0; i < 10; i++)
	{
		m_strComment[i] = new char[200];
	}
	m_strPlayerPoketmonInfo = new char[100];
	m_strPlayerPoketmonHP = new char[30];
	m_strEnemyPoketmonInfo = new char[50];
	m_strEnemyPoketmonHP = new char[30];
	m_strItemInfo = new char[20];
	m_strChangePoketmonInfo = new char[30];
	m_strChangePoketmonHp = new char[50];

	m_chArrPlayerHpSprite = new char[20]{ 15 };
	m_chArrEnemyHpSprite = new char[20]{ 15 };
	m_chArrMonsterBallSprite = new char[64]
	{
		1, 1, 0, 0, 0, 0, 1, 1,
		1, 0, 12, 12, 12, 12, 0, 1,
		0, 12, 12, 0, 0, 12, 12, 0,
		0, 12, 0, 15, 15, 0, 12, 0,
		0, 0, 0, 15, 15, 0, 0, 0,
		0, 15, 15, 0, 0, 15, 15, 0,
		1, 0, 15, 15, 15, 15, 0, 1,
		1, 1, 0, 0, 0, 0, 1, 1
	};

	m_nArrowPos = 0;
	m_ePanelType = EPanel_Type::CHOICE_PANEL;
	m_ePrevPanelType = m_ePanelType;

	m_nPanelWidth = 100;
	m_nPanelHeight = 13;
	m_chArrPanelSprite = new char[m_nPanelWidth * m_nPanelHeight];

	m_isPlayerAnimation = false;
	m_isEnemyAnimation = false;
	m_isMonsterBallAnimation = false;
	m_isCatch = false;
	m_nMonsterBallAnimationCount = 0;

	for (int i = 0; i < m_nPanelHeight; i++)
	{
		for (int j = 0; j < m_nPanelWidth; j++)
		{
			if (i == 0 || i == m_nPanelHeight - 1)
			{
				*(m_chArrPanelSprite + i * m_nPanelWidth + j) = 0;
			}

			else
			{
				if (j == 0 || j == m_nPanelWidth - 1)
				{
					*(m_chArrPanelSprite + i * m_nPanelWidth + j) = 0;
				}

				else
				{
					*(m_chArrPanelSprite + i * m_nPanelWidth + j) = 15;
				}
			}
		}
	}
}

/// <summary>
/// FighScene �׸���
/// </summary>
void FightScene::Draw()
{
	DrawPlayerPoketmonInfo();
	DrawEnemyPoketmonInfo();
	m_DoubleBuffering->FillScreen(PANEL_START_X, PANEL_START_Y, m_chArrPanelSprite, m_nPanelWidth, m_nPanelHeight, false);

	switch (m_ePanelType)
	{
	case EPanel_Type::CHOICE_PANEL:
		DrawChoicePanel();
		break;

	case EPanel_Type::FIGHT_PANEL:
		DrawFightPanel();
		break;

	case EPanel_Type::INVENTORY_PANEL:
		DrawInventoryPanel();
		break;

	case EPanel_Type::POKETMON_PANEL:
		DrawPoketmonPanel();
		break;

	case EPanel_Type::PLAYER_RESULT_PANEL:
		DrawPlayerResultPanel();
		break;

	case EPanel_Type::ENEMY_RESULT_PANEL:
		DrawEnemyResultPanel();
		break;

	case EPanel_Type::RESULT_PANEL:
		DrawResultPanel();
		break;
	}

	m_DoubleBuffering->DrawScreen();
	m_DoubleBuffering->ClearScreen();
	m_DoubleBuffering->ChangeScreen();
}

/// <summary>
/// �÷��̾� ���ϸ� ���� �׸���
/// </summary>
void FightScene::DrawPlayerPoketmonInfo()
{
	sprintf_s(m_strPlayerPoketmonInfo, 100,
		"%s LV.%d  EXP : %d / %d", m_Poketmon[0]->GetName(), m_Poketmon[0]->GetLevel(), m_Poketmon[0]->GetCurrnetExp(), m_Poketmon[0]->GetTotalExp());

	m_DoubleBuffering->FillScreen(PLAYER_POKETMON_START_X, PLAYER_POKETMON_START_Y - 4, m_strPlayerPoketmonInfo,
		strlen(m_strPlayerPoketmonInfo));


	sprintf_s(m_strPlayerPoketmonHP, 30,
		"%d / %d", m_Poketmon[0]->GetCurrentHP(), m_Poketmon[0]->GetHP());

	m_DoubleBuffering->FillScreen(PLAYER_POKETMON_START_X, PLAYER_POKETMON_START_Y - 3, m_strPlayerPoketmonHP,
		strlen(m_strPlayerPoketmonHP));


	int nHpBarCount = m_Poketmon[0]->GetCurrentHP() / (float)m_Poketmon[0]->GetHP() * 20;
	for (int i = 0; i < nHpBarCount; i++)
	{
		m_chArrPlayerHpSprite[i] = static_cast<int>(EColor_Type::DARK_GREEN);
	}

	for (int i = nHpBarCount; i < 20; i++)
	{
		m_chArrPlayerHpSprite[i] = static_cast<int>(EColor_Type::WHITE);
	}
	m_DoubleBuffering->FillScreen(PLAYER_POKETMON_START_X, PLAYER_POKETMON_START_Y - 2, m_chArrPlayerHpSprite,
		20, 1, false);


	if (m_isPlayerAnimation)
	{
		m_DoubleBuffering->FillScreen(PLAYER_POKETMON_START_X + 2, PLAYER_POKETMON_START_Y, m_Poketmon[0]->GetSprite(),
			m_Poketmon[0]->GetWidth(), m_Poketmon[0]->GetHeight(), false);

		m_isPlayerAnimation = false;
	}

	else
	{
		m_DoubleBuffering->FillScreen(PLAYER_POKETMON_START_X, PLAYER_POKETMON_START_Y, m_Poketmon[0]->GetSprite(),
			m_Poketmon[0]->GetWidth(), m_Poketmon[0]->GetHeight(), false);
	}
}

/// <summary>
/// �� ���ϸ� ���� �׸���
/// </summary>
void FightScene::DrawEnemyPoketmonInfo()
{
	sprintf_s(m_strEnemyPoketmonInfo, 50,
		"%s LV.%d", m_Poketmon[1]->GetName(), m_Poketmon[1]->GetLevel());

	m_DoubleBuffering->FillScreen(ENEMY_POKETMON_START_X, ENEMY_POKETMON_START_Y - 4, m_strEnemyPoketmonInfo,
		strlen(m_strEnemyPoketmonInfo));


	sprintf_s(m_strEnemyPoketmonHP, 30,
		"%d / %d", m_Poketmon[1]->GetCurrentHP(), m_Poketmon[1]->GetHP());

	m_DoubleBuffering->FillScreen(ENEMY_POKETMON_START_X, ENEMY_POKETMON_START_Y - 3, m_strEnemyPoketmonHP,
		strlen(m_strEnemyPoketmonHP));


	int nHpBarCount = m_Poketmon[1]->GetCurrentHP() / (float)m_Poketmon[1]->GetHP() * 20;
	for (int i = 0; i < nHpBarCount; i++)
	{
		m_chArrEnemyHpSprite[i] = static_cast<int>(EColor_Type::DARK_GREEN);
	}

	for (int i = nHpBarCount; i < 20; i++)
	{
		m_chArrEnemyHpSprite[i] = static_cast<int>(EColor_Type::WHITE);
	}
	m_DoubleBuffering->FillScreen(ENEMY_POKETMON_START_X, ENEMY_POKETMON_START_Y - 2, m_chArrEnemyHpSprite,
		20, 1, false);


	if (m_isEnemyAnimation)
	{
		m_DoubleBuffering->FillScreen(ENEMY_POKETMON_START_X - 2, ENEMY_POKETMON_START_Y, m_Poketmon[1]->GetSprite(),
			m_Poketmon[1]->GetWidth(), m_Poketmon[1]->GetHeight(), true);

		m_isEnemyAnimation = false;
	}

	else if (m_isMonsterBallAnimation && m_nMonsterBallAnimationCount != 10)
	{
		m_DoubleBuffering->FillScreen(PLAYER_POKETMON_START_X + 30 + m_nMonsterBallAnimationCount * 8, PLAYER_POKETMON_START_Y + 5,
			m_chArrMonsterBallSprite, 8, 8, false, 1);

		m_DoubleBuffering->FillScreen(ENEMY_POKETMON_START_X, ENEMY_POKETMON_START_Y, m_Poketmon[1]->GetSprite(),
			m_Poketmon[1]->GetWidth(), m_Poketmon[1]->GetHeight(), true);

		m_nMonsterBallAnimationCount++;
	}


	else if (m_isMonsterBallAnimation)
	{
		m_DoubleBuffering->FillScreen(PLAYER_POKETMON_START_X + 30 + m_nMonsterBallAnimationCount * 8, PLAYER_POKETMON_START_Y + 5,
			m_chArrMonsterBallSprite, 8, 8, false, 1);
	}

	else
	{
		if (m_isCatch)
		{
			m_DoubleBuffering->FillScreen(PLAYER_POKETMON_START_X + 30 + m_nMonsterBallAnimationCount * 8, PLAYER_POKETMON_START_Y + 5,
				m_chArrMonsterBallSprite, 8, 8, false, 1);
		}

		else
		{
			m_DoubleBuffering->FillScreen(ENEMY_POKETMON_START_X, ENEMY_POKETMON_START_Y, m_Poketmon[1]->GetSprite(),
				m_Poketmon[1]->GetWidth(), m_Poketmon[1]->GetHeight(), true);
		}
	}
}

/// <summary>
/// �ο�� ���� ���ϸ� ����ġ�� �г� �׸���
/// </summary>
void FightScene::DrawChoicePanel()
{
	const int strChoicePanelWordCount = sizeof(m_strChoicePanelWords) / sizeof(m_strChoicePanelWords[0]);

	m_DoubleBuffering->FillScreen(TEXT_INCREASE_X(m_nArrowPos), TEXT_START_Y - 1, "��", strlen("��"));
	for (int i = 0; i < strChoicePanelWordCount; i++)
	{
		m_DoubleBuffering->FillScreen(TEXT_INCREASE_X(i), TEXT_START_Y, m_strChoicePanelWords[i], strlen(m_strChoicePanelWords[i]));
	}
}

/// <summary>
/// �ο�� �г� �׸���
/// </summary>
void FightScene::DrawFightPanel()
{
	m_DoubleBuffering->FillScreen(TEXT_INCREASE_X(m_nArrowPos), TEXT_START_Y - 1, "��", strlen("��"));

	std::vector<Skill*> vPlayerPoketmonSkill = m_Poketmon[0]->GetSkillVector();
	std::vector<Skill*>::iterator viPlayerPoketmonSkill = vPlayerPoketmonSkill.begin();

	int i = 0;
	for (viPlayerPoketmonSkill; viPlayerPoketmonSkill != vPlayerPoketmonSkill.end(); ++viPlayerPoketmonSkill, i++)
	{
		m_DoubleBuffering->FillScreen(TEXT_INCREASE_X(i), TEXT_START_Y, (*viPlayerPoketmonSkill)->GetName(), strlen((*viPlayerPoketmonSkill)->GetName()));
	}
}

/// <summary>
/// ���� �г� �׸���
/// </summary>
void FightScene::DrawInventoryPanel()
{
	std::vector<Item*> vPlayerItem = m_Player->GetInventory()->GetVector();
	std::vector<Item*>::iterator viPlayerItem = vPlayerItem.begin();

	int i = 0;
	for (viPlayerItem; viPlayerItem != vPlayerItem.end(); ++viPlayerItem, i++)
	{
		sprintf_s(m_strItemInfo, 20, "%s X%d", (*viPlayerItem)->GetName(), (*viPlayerItem)->GetRemainCount());
		m_DoubleBuffering->FillScreen(TEXT_INCREASE_X(i), TEXT_START_Y, m_strItemInfo, strlen(m_strItemInfo));
	}

	m_DoubleBuffering->FillScreen(TEXT_INCREASE_X(m_nArrowPos), TEXT_START_Y - 1, "��", strlen("��"));
}

/// <summary>
/// ���ϸ� �г� �׸���
/// </summary>
void FightScene::DrawPoketmonPanel()
{
	std::vector<Poketmon*> vPlayerPoketmon = m_Player->GetPoketmonVector();
	std::vector<Poketmon*>::iterator viPlayerPoketmon = vPlayerPoketmon.begin();

	int i = 0;
	for (viPlayerPoketmon; viPlayerPoketmon != vPlayerPoketmon.end(); ++viPlayerPoketmon, i++)
	{
		sprintf_s(m_strChangePoketmonInfo, 30, "%s LV. %d", (*viPlayerPoketmon)->GetName(), (*viPlayerPoketmon)->GetLevel());
		sprintf_s(m_strChangePoketmonHp, 50, "HP : %d / %d", (*viPlayerPoketmon)->GetCurrentHP(), (*viPlayerPoketmon)->GetHP());
		m_DoubleBuffering->FillScreen(CHANGE_TEXT_INCREASE_X(i), CHANGE_TEXT_START_Y, m_strChangePoketmonInfo, strlen(m_strChangePoketmonInfo));
		m_DoubleBuffering->FillScreen(CHANGE_TEXT_INCREASE_X(i), CHANGE_TEXT_START_Y + 1, m_strChangePoketmonHp, strlen(m_strChangePoketmonHp));
	}

	m_DoubleBuffering->FillScreen(CHANGE_TEXT_INCREASE_X(m_nArrowPos), CHANGE_TEXT_START_Y - 1, "��", strlen("��"));
}

/// <summary>
/// �÷��̾� �Է� �Ϸ� �� ��� �г�
/// </summary>
void FightScene::DrawPlayerResultPanel()
{
	m_DoubleBuffering->FillScreen(TEXT_START_X, TEXT_START_Y, m_strComment[m_nCurrentResultWordindex], strlen(m_strComment[m_nCurrentResultWordindex]));
}

/// <summary>
/// �� �Է� �Ϸ� �� ��� �г�
/// </summary>
void FightScene::DrawEnemyResultPanel()
{
	m_DoubleBuffering->FillScreen(TEXT_START_X, TEXT_START_Y, m_strComment[m_nCurrentResultWordindex], strlen(m_strComment[m_nCurrentResultWordindex]));
}

/// <summary>
/// ���� ��� �г�
/// </summary>
void FightScene::DrawResultPanel()
{
	m_DoubleBuffering->FillScreen(TEXT_START_X, TEXT_START_Y, m_strComment[m_nCurrentResultWordindex], strlen(m_strComment[m_nCurrentResultWordindex]));
}

/// <summary>
/// ���ݿ� ���� ���ڿ� �Ҵ�
/// </summary>
/// <param name="strPoketmonName"></param>
/// <param name="strSkillName"></param>
/// <param name="nIndex"></param>
void FightScene::SetComment(const char* strPoketmonName, const char* strSkillName, int nIndex)
{
	sprintf_s(m_strComment[nIndex], 200, "%s�� %s ����!", strPoketmonName, strSkillName);
}

/// <summary>
/// ���ڿ� �Ҵ�
/// </summary>
/// <param name="strComment"></param>
/// <param name="nIndex"></param>
void FightScene::SetComment(const char* strComment, int nIndex)
{
	sprintf_s(m_strComment[nIndex], 200, "%s", strComment);
}

/// <summary>
/// ��� ���� ���ڿ� �Ҵ�
/// </summary>
/// <param name="strSkillname"></param>
/// <param name="nIndex"></param>
void FightScene::SetLearnComment(const char* strSkillname, int nIndex)
{
	sprintf_s(m_strComment[nIndex], 200, "%s��(��) %s��(��) �����!", m_Poketmon[0]->GetName(), strSkillname);
}

/// <summary>
/// ������ ��� ���ڿ� �Ҵ�
/// </summary>
/// <param name="strItemName"></param>
/// <param name="nIndex"></param>
void FightScene::SetItemUseComment(const char* strItemName, int nIndex)
{
	sprintf_s(m_strComment[nIndex], 200, "%s�� ����߽��ϴ�.", strItemName);
}

/// <summary>
/// ���ϸ� ��ȹ ���� ���ڿ� �Ҵ�
/// </summary>
/// <param name="nIndex"></param>
void FightScene::SetCatchPoketmonComment(int nIndex)
{
	sprintf_s(m_strComment[nIndex], 200, "�ų���!! %s��(��) ��Ҵ�! %s, �� ������!", m_Poketmon[1]->GetName(), m_Poketmon[1]->GetName());
}

/// <summary>
/// ���ϸ� ��ü ���ڿ� �Ҵ�
/// </summary>
/// <param name="strPoketmonName"></param>
/// <param name="nIndex"></param>
void FightScene::SetChangePoketmonComment(const char* strPoketmonName, int nIndex)
{
	sprintf_s(m_strComment[nIndex], 200, "%s ������!!", strPoketmonName);
}

/// <summary>
/// ���ϸ� ������ ���ڿ� �Ҵ�
/// </summary>
/// <param name="strPoketmonName"></param>
/// <param name="nIndex"></param>
void FightScene::SetDownPoketmonComment(const char* strPoketmonName, int nIndex)
{
	sprintf_s(m_strComment[nIndex], 200, "%s��(��) ��������!", strPoketmonName);
}

/// <summary>
/// �� ���ڿ� �Ҵ�
/// </summary>
/// <param name="nMoney"></param>
/// <param name="nIndex"></param>
void FightScene::SetMoneyGainComment(int nMoney, int nIndex)
{
	sprintf_s(m_strComment[nIndex], 200, "%d���� ȹ���߽��ϴ�!", nMoney);
}

/// <summary>
/// ��ȭ �� ���ڿ� �Ҵ�
/// </summary>
/// <param name="strPoketmonName"></param>
/// <param name="nIndex"></param>
void FightScene::SetEvolutionPrevComment(const char* strPoketmonName, int nIndex)
{
	sprintf_s(m_strComment[nIndex], 200, "����? %s�� ���°�?", strPoketmonName);
}

/// <summary>
/// ��ȭ ���ڿ� �Ҵ�
/// </summary>
/// <param name="strPoketmonName"></param>
/// <param name="nIndex"></param>
void FightScene::SetEvolutionComment(const char* strPoketmonName, int nIndex)
{
	sprintf_s(m_strComment[nIndex], 200, "�����մϴ�! %s(��)�� ��ȭ�߽��ϴ�!", strPoketmonName);
}

/// <summary>
/// �гο� �ִ� ȭ��ǥ ��ġ �ű��
/// </summary>
/// <param name="nPos"></param>
void FightScene::MoveArrowPosition(int nPos)
{

	switch (m_ePanelType)
	{
	case EPanel_Type::CHOICE_PANEL:
		if (m_nArrowPos + nPos < 0 || m_nArrowPos + nPos > 3)
		{
			return;
		}

		else
		{
			m_nArrowPos += nPos;
		}
		break;

	case EPanel_Type::FIGHT_PANEL:
		if (m_nArrowPos + nPos < 0 || m_nArrowPos + nPos >= m_Poketmon[0]->GetSkillCount())
		{
			return;
		}

		else
		{
			m_nArrowPos += nPos;
		}
		break;

	case EPanel_Type::INVENTORY_PANEL:
		if (m_nArrowPos + nPos < 0 || m_nArrowPos + nPos >= m_Player->GetInventory()->GetItemTypeCount())
		{
			return;
		}

		else
		{
			m_nArrowPos += nPos;
		}
		break;

	case EPanel_Type::POKETMON_PANEL:
		if (m_nArrowPos + nPos < 0 || m_nArrowPos + nPos >= m_Player->GetPoketmonCount())
		{
			return;
		}

		else
		{
			m_nArrowPos += nPos;
		}
		break;

	case EPanel_Type::PLAYER_RESULT_PANEL:
		return;

	case EPanel_Type::ENEMY_RESULT_PANEL:
		return;

	case EPanel_Type::RESULT_PANEL:
		return;
	}
}