#include "Item_MonsterBall.h"

Item_MonsterBall::Item_MonsterBall()
{
	Init();
}

Item_MonsterBall::~Item_MonsterBall()
{
	delete[] m_chArrSprite;
	delete[] m_chArrStringSprite;
}

void Item_MonsterBall::Init()
{
	m_chName = "몬스터볼";
	m_nWidth = 8;
	m_nHeight = 8;
	m_StringWidth = 32;
	m_StringHeight = 8;
	m_nPrice = 500;
	m_nRemainCount = 1;

	m_chArrSprite = new char[m_nWidth * m_nHeight]
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

	m_chArrStringSprite = new char[m_StringWidth * m_StringHeight]
	{
		15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 0, 0, 0, 15, 0, 15, 15, 15, 15, 0, 15, 0, 15, 15, 15,
		15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 0, 15, 0, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15,
		15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 0, 15, 0, 15, 15, 15, 15, 0, 0, 15, 0, 0, 15, 15, 15, 15, 0, 15, 0, 15, 15, 15,
		15, 15, 15, 0, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15,
		15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 0, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 0, 0, 0, 0, 15, 15,
		15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15,
		15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15
	};
}

/// <summary>
/// 몬스터볼 사용
/// </summary>
/// <param name="poketmon"></param>
/// <returns></returns>
bool Item_MonsterBall::Use(Poketmon* poketmon)
{
	int nHpRatio, nCatchChance;
	if ((poketmon->GetCurrentHP() / poketmon->GetHP() * 100 - 50) > 0)
	{
		nHpRatio = poketmon->GetCurrentHP() / poketmon->GetHP() * 100 - 50;
	}

	else
	{
		nHpRatio = 0;
	}

	nCatchChance = rand() % (3 + nHpRatio);

	if (nCatchChance == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}