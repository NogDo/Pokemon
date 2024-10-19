#include "Shop.h"

Shop::Shop()
{
	Init();
}

Shop::~Shop()
{
	delete m_ItemMonsterBall;
	delete m_ItemPotion;
	delete[] m_chArrPlayerMoneyString;
	delete[] m_chArrPriceString;

	for (int i = 0; i < 10; i++)
	{
		delete[] m_chArrNumberString[i];
	}
}

void Shop::Init()
{
	m_ItemMonsterBall = new Item_MonsterBall;
	m_ItemPotion = new Item_Potion;

	m_chArrPlayerMoneyString = new char[PLAYERMONEY_WIDTH * PLAYERMONEY_HEIGHT]
	{
		15, 15, 15, 0, 15, 15, 15, 15, 15, 0, 0, 0, 0, 15, 0, 15 ,15, 0, 0, 0, 0, 0, 15, 15,
		15, 15, 0, 15, 0, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 0, 15, 15,
		15, 15, 0, 15, 0, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 0, 15, 15,
		15, 0, 15, 15, 15, 0, 15, 15, 15, 0, 15, 0, 15, 15, 0, 15, 0, 0, 0, 0, 0, 0, 0, 15,
		15, 15, 15, 0, 15, 15, 15, 15, 15, 0, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		0, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 0, 0, 0, 0, 0, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 0, 15, 15
	};

	m_chArrPlayerMoneyPanel = new char[PLAYERMONEY_PANEL_WIDTH * PLAYERMONEY_PANEL_HEIGHT];
	for (int i = 0; i < PLAYERMONEY_PANEL_WIDTH * PLAYERMONEY_PANEL_HEIGHT; i++)
	{
		if (i / PLAYERMONEY_PANEL_WIDTH == 0 || i / PLAYERMONEY_PANEL_WIDTH == PLAYERMONEY_PANEL_HEIGHT - 1)
		{
			*(m_chArrPlayerMoneyPanel + i) = 0;
		}

		else if (i % PLAYERMONEY_PANEL_WIDTH == 0 || i % PLAYERMONEY_PANEL_WIDTH == PLAYERMONEY_PANEL_WIDTH - 1)
		{
			*(m_chArrPlayerMoneyPanel + i) = 0;
		}

		else
		{
			*(m_chArrPlayerMoneyPanel + i) = 15;
		}
	}

	m_chArrPriceString = new char[64]
	{
		15, 15, 15, 15, 0, 15, 15, 15,
		15, 15, 0, 0, 0, 0, 15, 15,
		15, 0, 15, 15, 15, 15, 0, 15,
		15, 15, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 0, 15, 15,
		15, 0, 15, 15, 15, 15, 0, 15,
		15, 15, 0, 0, 0, 0, 15, 15,
		15, 15, 15, 0, 15, 15, 15, 15
	};

	m_chArrNumberString[0] = new char[15]
	{
		0, 0, 0,
		0, 15, 0,
		0, 15, 0,
		0, 15, 0,
		0, 0, 0
	};

	m_chArrNumberString[1] = new char[15]
	{
		15, 0, 15,
		15, 0, 15,
		15, 0, 15,
		15, 0, 15,
		15, 0, 15
	};

	m_chArrNumberString[2] = new char[15]
	{
		0, 0, 0, 
		15, 15, 0,
		0, 0, 0, 
		0, 15, 15,
		0, 0, 0
	};

	m_chArrNumberString[3] = new char[15]
	{
		0, 0, 0,
		15, 15, 0,
		0, 0, 0,
		15, 15, 0,
		0, 0, 0
	};

	m_chArrNumberString[4] = new char[15]
	{
		0, 15, 0, 
		0, 15, 0,
		0, 0, 0, 
		15, 15, 0,
		15, 15, 0
	};

	m_chArrNumberString[5] = new char[15]
	{
		0, 0, 0,
		0, 15, 15,
		0, 0, 0,
		15, 15, 0,
		0, 0, 0
	};

	m_chArrNumberString[6] = new char[15]
	{
		0, 0, 0,
		0, 15, 15,
		0, 0, 0,
		0, 15, 0,
		0, 0, 0
	};

	m_chArrNumberString[7] = new char[15]
	{
		0, 0, 0,
		0, 15, 0,
		0, 15, 0,
		15, 15, 0,
		15, 15, 0
	};

	m_chArrNumberString[8] = new char[15]
	{
		0, 0, 0,
		0, 15, 0,
		0, 0, 0,
		0, 15, 0,
		0, 0, 0
	};

	m_chArrNumberString[9] = new char[15]
	{
		0, 0, 0,
		0, 15, 0,
		0, 0, 0,
		15, 15, 0,
		15, 15, 0
	};
}

/// <summary>
/// 고른 아이템 반환
/// </summary>
/// <param name="nIndex"></param>
/// <returns></returns>
Item* Shop::GetSelectedItem(int nIndex)
{
	switch (nIndex)
	{
	case 0:
		return new Item_MonsterBall;
		break;

	case 1:
		return new Item_Potion;
		break;
	}
}