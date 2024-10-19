#include "Player.h"

Player::Player()
{
	Init();
}

Player::~Player()
{
	delete[] m_chArrSprite[0];
	delete[] m_chArrSprite[1];
	delete[] m_chArrSprite[2];
	delete[] m_chArrSprite[3];
	delete m_Inventory;

	m_viPoketmon = m_vPoketmon.begin();
	for (m_viPoketmon; m_viPoketmon != m_vPoketmon.end(); ++m_viPoketmon)
	{
		delete* m_viPoketmon;
	}

	m_vPoketmon.clear();
}

void Player::Init()
{
	m_ePlayerState = EPlayerState_Type::IDLE_DOWN;
	m_nMoney = 10000;

	/*int randNum = rand() % 3;
	if (randNum == 0)
	{
		AddPoketmon(new Poketmon_Charmander(5));
	}

	else if (randNum == 1)
	{
		AddPoketmon(new Poketmon_Bulbasaur(5));
	}

	else
	{
		AddPoketmon(new Poketmon_Squirtle(5));
	}*/

	AddPoketmon(new Poketmon_Charmander(45));
	AddPoketmon(new Poketmon_Squirtle(45));
	AddPoketmon(new Poketmon_Bulbasaur(45));

	m_Inventory = new Inventory;


	// 0 >> IDLE_UP
	m_chArrSprite[0] = new char[PLAYER_SPRITE_WIDTH * PLAYER_SPRITE_HEIGHT]
	{
		15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 0, 12, 14, 14, 14, 14, 12, 0, 15, 15, 15,
		15, 15, 0, 12, 12, 14, 14, 14, 14, 12, 12, 0, 15, 15,
		15, 15, 0, 12, 12, 14, 14, 14, 14, 12, 12, 0, 15, 15,
		15, 0, 0, 12, 12, 14, 14, 14, 14, 12, 12, 0, 0, 15,
		15, 0, 0, 0, 12, 14, 14, 14, 14, 12, 0, 0, 0, 15,
		0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0,
		0, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 0,
		15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15,
		15, 15, 0, 14, 12, 0, 0, 0, 0, 12, 14, 0, 15, 15,
		15, 0, 12, 0, 0, 14, 14, 14, 14, 0, 0, 12, 0, 15,
		0, 14, 0, 12, 0, 12, 12, 12, 12, 0, 12, 0, 14, 0,
		0, 14, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 14, 0,
		15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15,
		15, 15, 0, 12, 12, 0, 0, 0, 0, 12, 12, 0, 15, 15,
		15, 15, 15, 0, 0, 0, 15, 15, 0, 0, 0, 15, 15, 15,
	};

	// 1 >> IDLE_DOWN
	m_chArrSprite[1] = new char[PLAYER_SPRITE_WIDTH * PLAYER_SPRITE_HEIGHT]
	{
		15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 0, 12, 14, 14, 14, 14, 12, 0, 15, 15, 15,
		15, 15, 0, 12, 12, 14, 14, 14, 14, 12, 12, 0, 15, 15,
		15, 15, 0, 12, 12, 0, 0, 0, 14, 12, 12, 0, 15, 15,
		15, 0, 0, 12, 0, 0, 0, 0, 0, 12, 12, 0, 0, 15,
		15, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 15,
		0, 14, 0, 0, 0, 14, 14, 14, 14, 14, 14, 0, 14, 0,
		0, 14, 14, 14, 14, 0, 14, 14, 0, 14, 14, 14, 14, 0,
		15, 0, 0, 14, 14, 0, 14, 14, 0, 14, 14, 0, 0, 15,
		15, 15, 0, 0, 14, 14, 12, 12, 14, 14, 0, 0, 15, 15,
		15, 0, 0, 14, 12, 0, 0, 0, 0, 12, 14, 0, 0, 15,
		0, 14, 14, 0, 14, 14, 0, 0, 14, 14, 0, 14, 14, 0,
		0, 14, 14, 0, 12, 12, 12, 12, 12, 12, 0, 14, 14, 0,
		15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15,
		15, 15, 0, 12, 12, 0, 0, 0, 0, 12, 12, 0, 15, 15,
		15, 15, 15, 0, 0, 0, 15, 15, 0, 0, 0, 15, 15, 15,
	};

	// 2 >> IDLE_LEFT, IDLE_RIGHT (DoubleBuffering에 sprite반전 기능이 있기 때문에 Sprite하나로 두개의 상태를 정의)
	m_chArrSprite[2] = new char[PLAYER_SPRITE_WIDTH * PLAYER_SPRITE_HEIGHT]
	{
		15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 0, 12, 12, 12, 12, 12, 12, 0, 15, 15, 15,
		15, 15, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 15, 15,
		15, 0, 0, 14, 12, 12, 12, 12, 12, 12, 0, 0, 15, 15,
		0, 14, 14, 14, 14, 12, 12, 12, 12, 12, 0, 0, 0, 15,
		15, 0, 0, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 15,
		15, 0, 0, 0, 0, 0, 0, 14, 14, 0, 14, 0, 15, 15,
		15, 15, 0, 0, 14, 14, 0, 14, 14, 0, 14, 0, 15, 15,
		15, 15, 15, 0, 14, 14, 14, 14, 14, 14, 14, 0, 15, 15,
		15, 15, 15, 0, 0, 0, 14, 14, 14, 12, 0, 15, 15, 15,
		15, 15, 0, 14, 14, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 0, 12, 12, 0, 0, 0, 12, 0, 15, 15, 15, 15,
		15, 15, 0, 14, 14, 0, 14, 14, 0, 15, 15, 15, 15, 15,
		15, 15, 15, 0, 0, 0, 14, 14, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 12, 0, 0, 12, 12, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 0, 0, 0, 0, 15, 15, 15, 15,
	};

	// 3 >> WALK_UP
	m_chArrSprite[3] = new char[PLAYER_SPRITE_WIDTH * PLAYER_SPRITE_HEIGHT]
	{
		15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 0, 12, 14, 14, 14, 14, 12, 0, 15, 15, 15,
		15, 15, 0, 12, 12, 14, 14, 14, 14, 12, 12, 0, 15, 15,
		15, 15, 0, 12, 12, 14, 14, 14, 14, 12, 12, 0, 15, 15,
		15, 0, 0, 12, 12, 14, 14, 14, 14, 12, 12, 0, 0, 15,
		15, 0, 0, 0, 12, 14, 14, 14, 14, 12, 0, 0, 0, 15,
		0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0,
		0, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 0,
		15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		15, 15, 0, 0, 12, 0, 0, 0, 0, 12, 14, 0, 14, 0,
		15, 0, 14, 14, 0, 14, 14, 14, 14, 0, 0, 0, 0, 15,
		15, 0, 14, 14, 0, 12, 12, 12, 12, 0, 0, 0, 15, 15,
		15, 15, 0, 0, 0, 14, 14, 14, 14, 0, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 0, 0, 0, 12, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};

	// 4, 5 >> WALK_DOWN (머리카락 도트가 다르기 때문에 sprite반전 하면 안됨)
	m_chArrSprite[4] = new char[PLAYER_SPRITE_WIDTH * PLAYER_SPRITE_HEIGHT]
	{
		15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 0, 12, 14, 14, 14, 14, 12, 0, 15, 15, 15,
		15, 15, 0, 12, 12, 14, 14, 14, 14, 12, 12, 0, 15, 15,
		15, 15, 0, 12, 12, 0, 0, 0, 14, 12, 12, 0, 15, 15,
		15, 0, 0, 12, 0, 0, 0, 0, 0, 12, 12, 0, 0, 15,
		15, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 15,
		0, 14, 0, 0, 0, 14, 14, 14, 14, 14, 14, 0, 14, 0,
		0, 14, 14, 14, 14, 0, 14, 14, 0, 14, 14, 14, 14, 0,
		0, 0, 0, 14, 14, 0, 14, 14, 0, 14, 14, 0, 0, 15,
		0, 14, 0, 0, 14, 14, 12, 12, 14, 14, 0, 0, 0, 15,
		15, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 12, 0, 15,
		15, 15, 0, 0, 12, 12, 0, 0, 0, 14, 14, 0, 15, 15,
		15, 15, 15, 0, 0, 0, 12, 12, 0, 14, 14, 0, 15, 15,
		15, 15, 15, 0, 12, 12, 0, 0, 0, 0, 0, 15, 15, 15,
		15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};

	m_chArrSprite[5] = new char[PLAYER_SPRITE_WIDTH * PLAYER_SPRITE_HEIGHT]
	{
		15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 0, 12, 14, 14, 14, 14, 12, 0, 15, 15, 15,
		15, 15, 0, 12, 12, 14, 14, 14, 14, 12, 12, 0, 15, 15,
		15, 15, 0, 12, 12, 0, 0, 0, 14, 12, 12, 0, 15, 15,
		15, 0, 0, 12, 0, 0, 0, 0, 0, 12, 12, 0, 0, 15,
		15, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 15,
		0, 14, 0, 0, 0, 14, 14, 14, 14, 14, 14, 0, 14, 0,
		0, 14, 14, 14, 14, 0, 14, 14, 0, 14, 14, 14, 14, 0,
		15, 0, 0, 14, 14, 0, 14, 14, 0, 14, 14, 0, 0, 0,
		15, 0, 0, 0, 14, 14, 12, 12, 14, 14, 0, 0, 14, 0,
		15, 0, 12, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 15,
		15, 15, 0, 14, 14, 0, 0, 0, 12, 12, 0, 0, 15, 15,
		15, 15, 0, 14, 14, 0, 12, 12, 0, 0, 0, 15, 15, 15,
		15, 15, 15, 0, 0, 0, 0, 0, 12, 12, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};

	// 6 >> WALK_LEFT, WALK_RIGHT
	m_chArrSprite[6] = new char[PLAYER_SPRITE_WIDTH * PLAYER_SPRITE_HEIGHT]
	{
		15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 0, 12, 12, 12, 12, 12, 12, 0, 15, 15, 15,
		15, 15, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 15, 15,
		15, 0, 0, 14, 12, 12, 12, 12, 12, 12, 0, 0, 15, 15,
		0, 14, 14, 14, 14, 12, 12, 12, 12, 12, 0, 0, 0, 15,
		15, 0, 0, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 15,
		15, 0, 0, 0, 0, 0, 0, 14, 14, 0, 14, 0, 15, 15,
		15, 15, 0, 0, 14, 14, 0, 14, 14, 0, 14, 0, 15, 15,
		15, 15, 15, 0, 14, 14, 14, 14, 14, 14, 14, 0, 15, 15,
		15, 15, 15, 0, 0, 0, 14, 14, 14, 12, 0, 15, 15, 15,
		15, 15, 0, 14, 0, 0, 12, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 0, 0, 14, 14, 0, 12, 12, 0, 0, 0, 15, 15,
		15, 0, 12, 0, 14, 14, 0, 14, 0, 0, 12, 12, 0, 15,
		15, 0, 12, 12, 0, 0, 12, 0, 0, 12, 12, 0, 15, 15,
		15, 15, 0, 0, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};


}

char* Player::GetSprite()
{
	switch (m_ePlayerState)
	{
	case EPlayerState_Type::IDLE_UP:
		return m_chArrSprite[0];

	case EPlayerState_Type::IDLE_DOWN:
		return m_chArrSprite[1];

	case EPlayerState_Type::IDLE_LEFT:
	case EPlayerState_Type::IDLE_RIGHT:
		return m_chArrSprite[2];

	case EPlayerState_Type::WALK_UP:
		if (m_nAnimationCount % 4 == 0)
		{
			return m_chArrSprite[3];
		}

		else if (m_nAnimationCount % 4 == 1 || m_nAnimationCount % 4 == 3)
		{
			return m_chArrSprite[0];
		}

		else if (m_nAnimationCount % 4 == 2)
		{
			return m_chArrSprite[3];
		}

	case EPlayerState_Type::WALK_DOWN:
		if (m_nAnimationCount % 4 == 0)
		{
			return m_chArrSprite[4];
		}

		else if (m_nAnimationCount % 4 == 1 || m_nAnimationCount % 4 == 3)
		{
			return m_chArrSprite[1];
		}

		else if (m_nAnimationCount % 4 == 2)
		{
			return m_chArrSprite[5];
		}

	case EPlayerState_Type::WALK_LEFT:
		if (m_nAnimationCount % 2 == 0)
		{
			return m_chArrSprite[2];
		}

		else if (m_nAnimationCount % 2 == 1)
		{
			return m_chArrSprite[6];
		}

	case EPlayerState_Type::WALK_RIGHT:
		if (m_nAnimationCount % 2 == 0)
		{
			return m_chArrSprite[2];
		}

		else if (m_nAnimationCount % 2 == 1)
		{
			return m_chArrSprite[6];
		}
	}
}

bool Player::IsCanFight()
{
	m_viPoketmon = m_vPoketmon.begin();

	for (m_viPoketmon; m_viPoketmon != m_vPoketmon.end(); ++m_viPoketmon)
	{
		if ((*m_viPoketmon)->GetCurrentHP() > 0)
		{
			return true;
		}
	}

	return false;
}

void Player::HealPoketmon()
{
	m_viPoketmon = m_vPoketmon.begin();

	for (m_viPoketmon; m_viPoketmon != m_vPoketmon.end(); ++m_viPoketmon)
	{
		(*m_viPoketmon)->SetCurrentHp((*m_viPoketmon)->GetHP());
	}
}

void Player::AddPoketmon(Poketmon* poketmon)
{
	m_vPoketmon.push_back(poketmon);
}