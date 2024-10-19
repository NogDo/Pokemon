#include "GameController.h"

GameController::GameController()
{
	srand(time(NULL));
	SetConsoleTitle(TEXT("포켓몬스터"));

	m_KeyInput = new KeyInput;
	m_Player = new Player;
	m_SoundManager = new SoundManager;

	QueryPerformanceFrequency(&m_LIfrequency);
	QueryPerformanceCounter(&m_LIprev);
	m_fDeltaTime = 0;
	m_fFPS = 0;
	m_fTime = 0;

	ChageScene(EScene_Type::MAIN);
}

GameController::~GameController()
{
	delete m_KeyInput;
	delete m_GameScene;
	delete m_Player;
	delete m_SoundManager;

	if (m_MapScene != nullptr)
	{
		delete m_MapScene;
	}
}

/// <summary>
/// Scene 바꾸기
/// </summary>
/// <param name="newScene"></param>
void GameController::ChageScene(EScene_Type newScene)
{
	if (newScene != EScene_Type::MAIN && m_GameScene == m_MapScene)
	{
		delete m_MapScene->GetDoubleBuffering();
	}

	else if (m_GameScene != nullptr)
	{
		delete m_GameScene;
	}

	switch (newScene)
	{
	case EScene_Type::MAIN:
		PlayMainScene();
		break;

	case EScene_Type::FIGHT:
		PlayFightScene();
		break;

	case EScene_Type::MAP:
		PlayMapScene();
		break;
	}
}

/// <summary>
/// MainScene 플레이
/// </summary>
void GameController::PlayMainScene()
{
	m_SoundManager->PlayTitleBGM();

	m_GameScene = new MainScene;
	MainScene* mainScene = (MainScene*)m_GameScene;

	while (true)
	{
		m_GameScene->Draw();

		EKey_Type eNowKeyType = m_KeyInput->GetKey();
		if (eNowKeyType == EKey_Type::Z)
		{
			if (mainScene->GetArrowIndex() == 0)
			{
				return ChageScene(EScene_Type::MAP);
			}

			else
			{
				GameQuit();
			}

			break;
		}

		else if (eNowKeyType == EKey_Type::UP_ARROW)
		{
			mainScene->SetArrowPosition(-1);
		}

		else if (eNowKeyType == EKey_Type::DOWN_ARROW)
		{
			mainScene->SetArrowPosition(1);
		}
	}
}

/// <summary>
/// MapScene 플레이
/// </summary>
void GameController::PlayMapScene()
{
	if (m_MapScene == nullptr)
	{
		m_MapScene = new MapScene;
	}

	else
	{
		m_MapScene->SetDoubleBuffering(new DoubleBuffering(static_cast<int>(EColor_Type::WHITE), 360, 100, 8));
	}

	m_GameScene = m_MapScene;

	if (m_MapScene->GetIsTalk())
	{
		m_SoundManager->PlayChampionBGM();
		m_MapScene->SetIsTalk(false);
	}

	else
	{
		m_SoundManager->PlayVillageBGM();
	}

	int nVerticalMovePos = 4;
	int nHorizonMovePos = 4;
	float swapTime = 0.0f;

	m_MapScene->SetPlayerSprite(m_Player->GetSprite());
	while (true)
	{
		QueryPerformanceCounter(&m_LIcurrent);
		//m_fFPS++;

		m_GameScene->Draw();

		m_fDeltaTime = (m_LIcurrent.QuadPart - m_LIprev.QuadPart) / static_cast<float>(m_LIfrequency.QuadPart);
		m_fTime += m_fDeltaTime;
		m_LIprev = m_LIcurrent;

		switch (m_KeyInput->GetKey())
		{
		case EKey_Type::UP_ARROW:
			if (m_MapScene->GetIsTalk())
			{

			}

			else
			{
				m_Player->SetPlayerState(EPlayerState_Type::WALK_UP);
				m_MapScene->SetPlayerSprite(m_Player->GetSprite());


				if (m_MapScene->IsCanMove(0, -nVerticalMovePos))
				{
					m_MapScene->SetPosition(0, -nVerticalMovePos);
				}


				if (m_Player->GetAnimationCount() % 4 == 2)
				{
					m_MapScene->SetReverse(true);
				}

				else
				{
					m_MapScene->SetReverse(false);
				}


				swapTime += m_fDeltaTime;
				if (swapTime > 0.1f)
				{
					m_Player->SetAnimationCount(m_Player->GetAnimationCount() + 1);
					Sleep(3);
					swapTime = 0.0f;
				}


				if (m_MapScene->IsInPoketmonGrass() && m_Player->IsCanFight())
				{
					int randNum = rand() % 10;

					if (randNum == 0)
					{
						// 전투 BGM 싱크 맞추기
						m_SoundManager->PlayBattleBGM();
						Sleep(2500);

						ChageScene(EScene_Type::FIGHT);
					}
				}
			}
			break;

		case EKey_Type::DOWN_ARROW:
			if (m_MapScene->GetIsTalk())
			{

			}

			else
			{
				m_Player->SetPlayerState(EPlayerState_Type::WALK_DOWN);

				m_MapScene->SetPlayerSprite(m_Player->GetSprite());
				m_MapScene->SetReverse(false);


				if (m_MapScene->IsCanMove(0, nVerticalMovePos))
				{
					m_MapScene->SetPosition(0, nVerticalMovePos);
				}


				swapTime += m_fDeltaTime;
				if (swapTime > 0.1f)
				{
					m_Player->SetAnimationCount(m_Player->GetAnimationCount() + 1);
					Sleep(3);
					swapTime = 0.0f;
				}


				if (m_MapScene->IsInPoketmonGrass() && m_Player->IsCanFight())
				{
					int randNum = rand() % 10;

					if (randNum == 0)
					{
						// 전투 BGM 싱크 맞추기
						m_SoundManager->PlayBattleBGM();
						Sleep(2500);

						ChageScene(EScene_Type::FIGHT);
					}
				}
			}
			break;

		case EKey_Type::LEFT_ARROW:
			if (m_MapScene->GetIsTalk())
			{
				m_MapScene->SetArrowIndex(-1);
			}

			else
			{
				m_Player->SetPlayerState(EPlayerState_Type::WALK_LEFT);

				m_MapScene->SetPlayerSprite(m_Player->GetSprite());
				m_MapScene->SetReverse(true);


				if (m_MapScene->IsCanMove(-nHorizonMovePos, 0))
				{
					m_MapScene->SetPosition(-nHorizonMovePos, 0);
				}


				swapTime += m_fDeltaTime;
				if (swapTime > 0.05f)
				{
					m_Player->SetAnimationCount(m_Player->GetAnimationCount() + 1);
					Sleep(3);
					swapTime = 0.0f;
				}


				if (m_MapScene->IsInPoketmonGrass() && m_Player->IsCanFight())
				{
					int randNum = rand() % 10;

					if (randNum == 0)
					{
						// 전투 BGM 싱크 맞추기
						m_SoundManager->PlayBattleBGM();
						Sleep(2500);

						ChageScene(EScene_Type::FIGHT);
					}
				}
			}
			break;

		case EKey_Type::RIGHT_ARROW:
			if (m_MapScene->GetIsTalk())
			{
				m_MapScene->SetArrowIndex(1);
			}

			else
			{
				m_Player->SetPlayerState(EPlayerState_Type::WALK_RIGHT);

				m_MapScene->SetPlayerSprite(m_Player->GetSprite());
				m_MapScene->SetReverse(false);


				if (m_MapScene->IsCanMove(nHorizonMovePos, 0))
				{
					m_MapScene->SetPosition(nHorizonMovePos, 0);
				}


				swapTime += m_fDeltaTime;
				if (swapTime > 0.05f)
				{
					m_Player->SetAnimationCount(m_Player->GetAnimationCount() + 1);
					Sleep(3);
					swapTime = 0.0f;
				}


				if (m_MapScene->IsInPoketmonGrass() && m_Player->IsCanFight())
				{
					int randNum = rand() % 10;

					if (randNum == 0)
					{
						// 전투 BGM 싱크 맞추기
						m_SoundManager->PlayBattleBGM();
						Sleep(2500);

						ChageScene(EScene_Type::FIGHT);
					}
				}
			}
			break;

		case EKey_Type::Z:
			if (m_MapScene->GetIsTalk())
			{
				switch (m_MapScene->GetCurrnetMapType())
				{
				case EMap_Type::POKETMONCENTER:
					if (m_MapScene->GetArrowIndex() == 0)
					{
						// 힐 효과음 틀고 다시 포켓몬센터 BGM
						m_SoundManager->PlayPoketmonHeal();
						Sleep(2500);
						m_SoundManager->PlayPoketmonCenterBGM();

						m_Player->HealPoketmon();
						m_MapScene->SetIsTalk(false);
					}

					else
					{
						m_MapScene->SetIsTalk(false);
					}
					break;

				case EMap_Type::SHOP:
					if (m_Player->GetMoney() >= m_MapScene->GetSelectItem()->GetPrice())
					{
						m_Player->SetMoney(m_Player->GetMoney() - m_MapScene->GetSelectItem()->GetPrice());
						m_MapScene->SetPlayerMoney(m_Player->GetMoney());
						m_Player->GetInventory()->AddItem(m_MapScene->GetSelectItem());
					}
					break;

				case EMap_Type::GYM:
					ChageScene(EScene_Type::FIGHT);
					break;
				}
				break;
			}

			else
			{
				m_MapScene->TalkToNpc();

				if (m_MapScene->GetCurrnetMapType() == EMap_Type::SHOP)
				{
					m_MapScene->SetPlayerMoney(m_Player->GetMoney());
				}
			}
			break;



		case EKey_Type::X:
			if (m_MapScene->GetIsTalk())
			{
				m_MapScene->SetIsTalk(false);
			}
			break;



		case EKey_Type::NONE:
			switch (m_Player->GetPlayerState())
			{
			case EPlayerState_Type::WALK_UP:
				m_Player->SetPlayerState(EPlayerState_Type::IDLE_UP);
				m_Player->SetAnimationCount(0);

				m_MapScene->SetPlayerSprite(m_Player->GetSprite());
				break;

			case EPlayerState_Type::WALK_DOWN:
				m_Player->SetPlayerState(EPlayerState_Type::IDLE_DOWN);
				m_Player->SetAnimationCount(0);

				m_MapScene->SetPlayerSprite(m_Player->GetSprite());
				break;

			case EPlayerState_Type::WALK_LEFT:
				m_Player->SetPlayerState(EPlayerState_Type::IDLE_LEFT);
				m_Player->SetAnimationCount(0);

				m_MapScene->SetPlayerSprite(m_Player->GetSprite());
				break;

			case EPlayerState_Type::WALK_RIGHT:
				m_Player->SetPlayerState(EPlayerState_Type::IDLE_RIGHT);
				m_Player->SetAnimationCount(0);

				m_MapScene->SetPlayerSprite(m_Player->GetSprite());
				break;
			}

			break;
		}
	}
}

/// <summary>
/// FighScene 플레이
/// </summary>
void GameController::PlayFightScene()
{


	bool isPlayerTurn, isCatch, isChange, isDown, isEscape, isEvolution;
	int nEnemySkillNum;
	int nCurrnetOutPoketmonIndex = 0;
	int nGainExp, nRemainExp;

	std::vector<Poketmon*> vPlayerPoketmon = m_Player->GetPoketmonVector();
	std::vector<Poketmon*>::iterator viPlayerPoketmon = vPlayerPoketmon.begin();
	for (viPlayerPoketmon; viPlayerPoketmon != vPlayerPoketmon.end(); ++viPlayerPoketmon)
	{
		if ((*viPlayerPoketmon)->GetCurrentHP() != 0)
		{
			m_PlayerPoketmon = (*viPlayerPoketmon);
			break;
		}

		else
		{
			nCurrnetOutPoketmonIndex++;
		}
	}

	if (m_MapScene->GetIsTalk())
	{
		m_NpcEnemy = m_MapScene->GetNpcBoss();
	}

	else
	{
		m_NpcEnemy = new NpcEnemy;
		m_NpcEnemy->SetLevel(m_PlayerPoketmon->GetLevel());
	}
	m_EnemyPoketmon = m_NpcEnemy->GetPoketmon(0);


	m_GameScene = new FightScene(m_PlayerPoketmon, m_EnemyPoketmon);
	FightScene* fightscene = (FightScene*)m_GameScene;
	fightscene->SetPlayer(m_Player);

	isPlayerTurn = true;
	isCatch = false;
	isChange = false;
	isDown = false;
	isEscape = false;
	isEvolution = false;


	// 전투
	while (true)
	{
		m_GameScene->Draw();

		if (isPlayerTurn)
		{
			switch (m_KeyInput->GetKey())
			{
			case EKey_Type::Z:
				switch (fightscene->GetPanelType())
				{
				case EPanel_Type::CHOICE_PANEL:
					if (fightscene->GetArrowPosition() == 0)
					{
						fightscene->SetPanelType(EPanel_Type::FIGHT_PANEL);
						fightscene->SetArrowPosition(0);
					}

					else if (fightscene->GetArrowPosition() == 1)
					{
						fightscene->SetPanelType(EPanel_Type::INVENTORY_PANEL);
						fightscene->SetArrowPosition(0);
					}

					else if (fightscene->GetArrowPosition() == 2)
					{
						fightscene->SetPanelType(EPanel_Type::POKETMON_PANEL);
						fightscene->SetArrowPosition(0);
					}

					else if (fightscene->GetArrowPosition() == 3)
					{
						int randNum = ((4 - (m_PlayerPoketmon->GetLevel() - m_EnemyPoketmon->GetLevel())) > 1) ? (5 - (m_PlayerPoketmon->GetLevel() - m_EnemyPoketmon->GetLevel())) : 1;
						int nEscapePercent = rand() % randNum;

						if (nEscapePercent <= 0)
						{
							fightscene->SetResultWordCount(1);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment("도망쳤다!", 0);
							isEscape = true;
							fightscene->SetPanelType(EPanel_Type::RESULT_PANEL);
						}

						else
						{
							fightscene->SetResultWordCount(1);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment("도망치는데 실패했다!", 0);
							fightscene->SetPrevPanelType(EPanel_Type::PLAYER_RESULT_PANEL);
							fightscene->SetPanelType(EPanel_Type::PLAYER_RESULT_PANEL);
						}
					}
					break;

				case EPanel_Type::FIGHT_PANEL:
				{
					fightscene->SetIsPlayerAnimation(true);

					if (m_PlayerPoketmon->GetSkillDamage(fightscene->GetArrowPosition()) == 0)
					{
						fightscene->SetResultWordCount(1);
						fightscene->SetCurrentResultWordIndex(0);
						fightscene->SetComment("공격이 빗나갔다!", 0);
					}

					else
					{
						int nEffectNum = m_EnemyPoketmon->Hit(m_PlayerPoketmon->GetSkillDamage(fightscene->GetArrowPosition()),
							m_PlayerPoketmon->GetSkill(fightscene->GetArrowPosition())->GetSkillAttackType(),
							m_PlayerPoketmon->GetSkill(fightscene->GetArrowPosition())->GetSkillType());

						if (nEffectNum == -1)
						{
							fightscene->SetResultWordCount(2);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment(m_PlayerPoketmon->GetName(), m_PlayerPoketmon->GetSkill(fightscene->GetArrowPosition())->GetName(), 0);
							fightscene->SetComment("효과가 별로였다.", 1);
						}

						else if (nEffectNum == 1)
						{
							fightscene->SetResultWordCount(2);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment(m_PlayerPoketmon->GetName(), m_PlayerPoketmon->GetSkill(fightscene->GetArrowPosition())->GetName(), 0);
							fightscene->SetComment("효과가 굉장했다.", 1);
						}

						else
						{
							fightscene->SetResultWordCount(1);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment(m_PlayerPoketmon->GetName(), m_PlayerPoketmon->GetSkill(fightscene->GetArrowPosition())->GetName(), 0);
						}
					}

					fightscene->SetPrevPanelType(fightscene->GetPanelType());
					fightscene->SetPanelType(EPanel_Type::PLAYER_RESULT_PANEL);

					m_GameScene->Draw();
					Sleep(100);
					break;
				}


				case EPanel_Type::INVENTORY_PANEL:
					if (strcmp(m_Player->GetInventory()->GetItem(fightscene->GetArrowPosition())->GetName(), "상처약") == 0)
					{
						if (m_PlayerPoketmon->GetCurrentHP() == m_PlayerPoketmon->GetHP())
						{
							fightscene->SetResultWordCount(1);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment("체력이 가득 차 사용할 수 없습니다.", 0);
							fightscene->SetPrevPanelType(fightscene->GetPanelType());
							fightscene->SetPanelType(EPanel_Type::PLAYER_RESULT_PANEL);
						}

						else
						{
							m_Player->GetInventory()->GetItem(fightscene->GetArrowPosition())->Use(m_PlayerPoketmon);

							fightscene->SetResultWordCount(1);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetItemUseComment(m_Player->GetInventory()->GetItem(fightscene->GetArrowPosition())->GetName(), 0);
							fightscene->SetPrevPanelType(fightscene->GetPanelType());
							fightscene->SetPanelType(EPanel_Type::PLAYER_RESULT_PANEL);

							m_Player->GetInventory()->GetItem(fightscene->GetArrowPosition())->DecreaseRamainCount();
							m_Player->GetInventory()->CheckItemRemainCount();
						}
					}

					else if (strcmp(m_Player->GetInventory()->GetItem(fightscene->GetArrowPosition())->GetName(), "몬스터볼") == 0)
					{
						fightscene->SetIsMonsterBallAnimation(true);

						if (m_Player->GetInventory()->GetItem(fightscene->GetArrowPosition())->Use(m_EnemyPoketmon))
						{
							fightscene->SetResultWordCount(2);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetItemUseComment(m_Player->GetInventory()->GetItem(fightscene->GetArrowPosition())->GetName(), 0);
							fightscene->SetCatchPoketmonComment(1);
							fightscene->SetPanelType(EPanel_Type::RESULT_PANEL);
							isCatch = true;
						}

						else
						{
							fightscene->SetResultWordCount(2);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetItemUseComment(m_Player->GetInventory()->GetItem(fightscene->GetArrowPosition())->GetName(), 0);
							fightscene->SetComment("이런! 몬스터볼을 빠져나왔다!", 1);
							fightscene->SetPrevPanelType(fightscene->GetPanelType());
							fightscene->SetPanelType(EPanel_Type::PLAYER_RESULT_PANEL);
						}

						m_Player->GetInventory()->GetItem(fightscene->GetArrowPosition())->DecreaseRamainCount();
						m_Player->GetInventory()->CheckItemRemainCount();

						// 몬스터볼 애니메이션
						for (int i = 0; i < 10; i++)
						{
							m_GameScene->Draw();
							Sleep(10);
						}
						m_GameScene->Draw();
						fightscene->SetIsCatch(isCatch);
						Sleep(1000);

						fightscene->SetIsMonsterBallAnimation(false);

						if (!isCatch)
						{
							fightscene->SetMonsterBallAnimationCount(0);
						}
					}

					break;

				case EPanel_Type::POKETMON_PANEL:
					if (fightscene->GetArrowPosition() != nCurrnetOutPoketmonIndex)
					{
						if (m_Player->GetPoketmon(fightscene->GetArrowPosition())->GetCurrentHP() == 0)
						{
							isChange = false;

							fightscene->SetResultWordCount(1);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment("기력을 다해 싸울 수 없다!", 0);
							fightscene->SetPrevPanelType(fightscene->GetPanelType());
							fightscene->SetPanelType(EPanel_Type::PLAYER_RESULT_PANEL);
						}

						else
						{
							m_PlayerPoketmon = m_Player->GetPoketmon(fightscene->GetArrowPosition());
							fightscene->SetCurrentPlayerPoketmon(m_PlayerPoketmon);
							nCurrnetOutPoketmonIndex = fightscene->GetArrowPosition();
							isChange = true;

							fightscene->SetResultWordCount(1);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetChangePoketmonComment(m_PlayerPoketmon->GetName(), 0);
							fightscene->SetPrevPanelType(fightscene->GetPanelType());
							fightscene->SetPanelType(EPanel_Type::PLAYER_RESULT_PANEL);
						}
					}

					else
					{
						isChange = false;

						fightscene->SetResultWordCount(1);
						fightscene->SetCurrentResultWordIndex(0);
						fightscene->SetComment("이미 출전중인 포켓몬입니다.", 0);
						fightscene->SetPrevPanelType(fightscene->GetPanelType());
						fightscene->SetPanelType(EPanel_Type::PLAYER_RESULT_PANEL);
					}
					break;

				case EPanel_Type::PLAYER_RESULT_PANEL:
					switch (fightscene->GetPrevPanelType())
					{
					case EPanel_Type::FIGHT_PANEL:
						if (fightscene->GetCurrentResultWordIndex() < fightscene->GetResultWordCount() - 1)
						{
							fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
						}

						else
						{
							fightscene->SetArrowPosition(0);
							isPlayerTurn = false;
							fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
						}
						break;

					case EPanel_Type::INVENTORY_PANEL:
						if (fightscene->GetCurrentResultWordIndex() < fightscene->GetResultWordCount() - 1)
						{
							fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
						}

						else
						{
							fightscene->SetArrowPosition(0);
							isPlayerTurn = false;
							fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
						}
						break;

					case EPanel_Type::POKETMON_PANEL:
						if (fightscene->GetCurrentResultWordIndex() < fightscene->GetResultWordCount() - 1)
						{
							fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
						}

						else
						{
							if (isChange)
							{
								fightscene->SetArrowPosition(0);

								if (isDown)
								{
									if (m_PlayerPoketmon->GetSpeed() >= m_EnemyPoketmon->GetSpeed())
									{
										isPlayerTurn = true;
										fightscene->SetPanelType(EPanel_Type::CHOICE_PANEL);
									}

									else
									{
										isPlayerTurn = false;
									}

									isDown = false;
								}

								else
								{
									isPlayerTurn = false;
								}

							}

							else
							{
								fightscene->SetArrowPosition(0);
								fightscene->SetPanelType(EPanel_Type::POKETMON_PANEL);
							}

							fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
						}
						break;

					case EPanel_Type::PLAYER_RESULT_PANEL:
						if (fightscene->GetCurrentResultWordIndex() < fightscene->GetResultWordCount() - 1)
						{
							fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
						}

						else
						{
							fightscene->SetArrowPosition(0);
							isPlayerTurn = false;
							fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
						}
						break;
					}
					break;

				case EPanel_Type::ENEMY_RESULT_PANEL:
					if (fightscene->GetCurrentResultWordIndex() < fightscene->GetResultWordCount() - 1)
					{
						fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
					}

					else
					{
						fightscene->SetArrowPosition(0);
						fightscene->SetPanelType(EPanel_Type::CHOICE_PANEL);
						fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
					}

					break;
				}
				break;


			case EKey_Type::X:
				switch (fightscene->GetPanelType())
				{
				case EPanel_Type::FIGHT_PANEL:
				case EPanel_Type::INVENTORY_PANEL:
				case EPanel_Type::POKETMON_PANEL:
					fightscene->SetArrowPosition(0);
					fightscene->SetPanelType(EPanel_Type::CHOICE_PANEL);
					break;
				}
				break;


			case EKey_Type::LEFT_ARROW:
				fightscene->MoveArrowPosition(-1);
				break;


			case EKey_Type::RIGHT_ARROW:
				fightscene->MoveArrowPosition(1);
				break;
			}
		}

		else
		{
			fightscene->SetIsEnemyAnimation(true);

			nEnemySkillNum = rand() % m_EnemyPoketmon->GetSkillCount();

			int nEffectNum = m_PlayerPoketmon->Hit(m_EnemyPoketmon->GetSkillDamage(nEnemySkillNum),
				m_EnemyPoketmon->GetSkill(nEnemySkillNum)->GetSkillAttackType(),
				m_EnemyPoketmon->GetSkill(nEnemySkillNum)->GetSkillType());

			if (nEffectNum == -1)
			{
				fightscene->SetResultWordCount(2);
				fightscene->SetCurrentResultWordIndex(0);
				fightscene->SetComment(m_EnemyPoketmon->GetName(), m_EnemyPoketmon->GetSkill(nEnemySkillNum)->GetName(), 0);
				fightscene->SetComment("효과가 별로였다.", 1);
			}

			else if (nEffectNum == 1)
			{
				fightscene->SetResultWordCount(2);
				fightscene->SetCurrentResultWordIndex(0);
				fightscene->SetComment(m_EnemyPoketmon->GetName(), m_EnemyPoketmon->GetSkill(nEnemySkillNum)->GetName(), 0);
				fightscene->SetComment("효과가 굉장했다.", 1);
			}

			else
			{
				fightscene->SetResultWordCount(1);
				fightscene->SetCurrentResultWordIndex(0);
				fightscene->SetComment(m_EnemyPoketmon->GetName(), m_EnemyPoketmon->GetSkill(nEnemySkillNum)->GetName(), 0);
			}

			isPlayerTurn = true;
			fightscene->SetPanelType(EPanel_Type::ENEMY_RESULT_PANEL);

			m_GameScene->Draw();
			Sleep(100);
		}


		// 패배 or 승리 판단
		if (m_PlayerPoketmon->GetCurrentHP() == 0 && fightscene->GetResultWordCount() == fightscene->GetCurrentResultWordIndex() && !isDown)
		{
			if (m_Player->IsCanFight())
			{
				fightscene->SetResultWordCount(2);
				fightscene->SetCurrentResultWordIndex(0);
				fightscene->SetDownPoketmonComment(m_PlayerPoketmon->GetName(), 0);
				fightscene->SetComment("교체할 포켓몬을 선택해주세요.", 1);

				fightscene->SetPrevPanelType(EPanel_Type::POKETMON_PANEL);
				fightscene->SetPanelType(EPanel_Type::PLAYER_RESULT_PANEL);

				isChange = false;
				isDown = true;
			}

			else
			{
				fightscene->SetResultWordCount(3);
				fightscene->SetCurrentResultWordIndex(0);
				fightscene->SetDownPoketmonComment(m_PlayerPoketmon->GetName(), 0);
				fightscene->SetComment("싸울 수 있는 포켓몬이 없다!", 1);
				fightscene->SetComment("눈앞이 캄캄해진다...", 2);

				fightscene->SetPanelType(EPanel_Type::RESULT_PANEL);
				break;
			}
		}

		else if (m_EnemyPoketmon->GetCurrentHP() == 0 && fightscene->GetResultWordCount() == fightscene->GetCurrentResultWordIndex())
		{
			if (m_NpcEnemy->GetPoketmonIndex() != m_NpcEnemy->GetPoketmonCount() - 1)
			{
				m_NpcEnemy->SetPoketmonIndex(m_NpcEnemy->GetPoketmonIndex() + 1);
				m_EnemyPoketmon = m_NpcEnemy->GetPoketmon(m_NpcEnemy->GetPoketmonIndex());
				fightscene->SetCurrentEnemyPoketmon(m_EnemyPoketmon);

				isPlayerTurn = true;

				fightscene->SetResultWordCount(1);
				fightscene->SetCurrentResultWordIndex(0);
				fightscene->SetComment("상대가 포켓몬을 교체했다.", 0);

				fightscene->SetPanelType(EPanel_Type::ENEMY_RESULT_PANEL);
			}

			else
			{
				if (m_EnemyPoketmon->GetLevel() <= 10)
				{
					nGainExp = m_EnemyPoketmon->GetLevel() * (10 + rand() % 6);
				}

				else if (m_EnemyPoketmon->GetLevel() <= 20)
				{
					nGainExp = m_EnemyPoketmon->GetLevel() * (5 + rand() % 6);
				}

				else if (m_EnemyPoketmon->GetLevel() <= 30)
				{
					nGainExp = m_EnemyPoketmon->GetLevel() * (3 + rand() % 6);
				}

				else
				{
					nGainExp = m_EnemyPoketmon->GetLevel() * (2 + rand() % 6);
				}

				int nGainMoney = rand() % 900 + 100;
				m_Player->SetMoney(m_Player->GetMoney() + nGainMoney);

				// 레벨업 하는지 판단
				if (m_PlayerPoketmon->GetTotalExp() > m_PlayerPoketmon->GetCurrnetExp() + nGainExp)
				{
					fightscene->SetResultWordCount(3);
					fightscene->SetCurrentResultWordIndex(0);
					fightscene->SetComment("이겼습니다!", 0);
					fightscene->SetComment("경험치를 획득했습니다.", 1);
					fightscene->SetMoneyGainComment(nGainMoney, 2);

					m_PlayerPoketmon->SetCurrentExp(m_PlayerPoketmon->GetCurrnetExp() + nGainExp);
				}

				else
				{
					nRemainExp = m_PlayerPoketmon->GetCurrnetExp() + nGainExp - m_PlayerPoketmon->GetTotalExp();
					isEvolution = m_PlayerPoketmon->IsEvolution();

					// 진화하는지 판단
					if (isEvolution)
					{
						// 레벨업 했을 때 스킬을 배우는지 판단
						if (m_PlayerPoketmon->GetIsLearnSkill())
						{
							fightscene->SetResultWordCount(6);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment("이겼습니다!", 0);
							fightscene->SetComment("경험치를 획득했습니다.  레벨업!", 1);
							fightscene->SetMoneyGainComment(nGainMoney, 2);
							fightscene->SetLearnComment(m_PlayerPoketmon->GetLearnSkillName(), 3);
							fightscene->SetEvolutionPrevComment(m_PlayerPoketmon->GetName(), 4);
						}

						else
						{
							fightscene->SetResultWordCount(5);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment("이겼습니다!", 0);
							fightscene->SetComment("경험치를 획득했습니다.  레벨업!", 1);
							fightscene->SetMoneyGainComment(nGainMoney, 2);
							fightscene->SetEvolutionPrevComment(m_PlayerPoketmon->GetName(), 3);
						}
					}

					else
					{
						m_PlayerPoketmon->LevelUp(nRemainExp);

						// 레벨업 했을 때 스킬을 배우는지 판단
						if (m_PlayerPoketmon->GetIsLearnSkill())
						{
							fightscene->SetResultWordCount(4);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment("이겼습니다!", 0);
							fightscene->SetComment("경험치를 획득했습니다.  레벨업!", 1);
							fightscene->SetMoneyGainComment(nGainMoney, 2);
							fightscene->SetLearnComment(m_PlayerPoketmon->GetLearnSkillName(), 3);
						}

						else
						{
							fightscene->SetResultWordCount(3);
							fightscene->SetCurrentResultWordIndex(0);
							fightscene->SetComment("이겼습니다!", 0);
							fightscene->SetComment("경험치를 획득했습니다.  레벨업!", 1);
							fightscene->SetMoneyGainComment(nGainMoney, 2);
						}
					}
				}

				fightscene->SetPanelType(EPanel_Type::RESULT_PANEL);
				break;
			}
		}

		else if (isCatch)
		{
			break;
		}

		else if (isEscape)
		{
			break;
		}
	}


	// 최종 결과
	if (m_PlayerPoketmon->GetCurrentHP() != 0)
	{
		m_SoundManager->PlayVitory();
	}

	while (fightscene->GetCurrentResultWordIndex() < fightscene->GetResultWordCount())
	{
		m_GameScene->Draw();

		if (m_KeyInput->GetKey() == EKey_Type::Z)
		{
			if (isEvolution)
			{
				if (fightscene->GetCurrentResultWordIndex() == fightscene->GetResultWordCount() - 2)
				{
					m_PlayerPoketmon->LevelUp(nRemainExp);
					fightscene->SetEvolutionComment(m_PlayerPoketmon->GetName(), fightscene->GetCurrentResultWordIndex() + 1);
				}

				fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
			}

			else
			{
				fightscene->SetCurrentResultWordIndex(fightscene->GetCurrentResultWordIndex() + 1);
			}
		}
	}


	// 진화


	// 사용한 객체 반환
	if (isCatch && m_Player->GetPoketmonCount() < 6)
	{
		m_Player->AddPoketmon(m_EnemyPoketmon);
		m_NpcEnemy->SetIsCatch(true);
	}

	delete m_NpcEnemy;


	// 다시 원래 씬으로
	return ChageScene(EScene_Type::MAP);
}

/// <summary>
/// 게임 종료
/// </summary>
void GameController::GameQuit()
{
	cout << "게임을 종료합니다.\n";
}