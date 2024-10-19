#include "Item_Potion.h"

Item_Potion::Item_Potion()
{
	Init();
}

Item_Potion::~Item_Potion()
{
	delete[] m_chArrStringSprite;
}

void Item_Potion::Init()
{
	m_chName = "상처약";
	m_nWidth = 0;
	m_nHeight = 0;
	m_StringWidth = 24;
	m_StringHeight = 8;
	m_nPrice = 1000;
	m_nRemainCount = 1;
	m_nHealAmount = 100;

	m_chArrStringSprite = new char[m_StringWidth * m_StringHeight]
	{
		15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15, 15, 0, 0, 15, 15, 0, 15,
		15, 0, 15, 0, 15, 0, 15, 15, 0, 0, 0, 0, 15, 15, 0, 15, 15, 0, 15, 15, 0, 15, 0, 0,
		15, 0, 15, 0, 15, 0, 0, 15, 15, 15, 0, 15, 0, 0, 0, 15, 15, 0, 15, 15, 0, 15, 0, 15,
		0, 15, 15, 15, 0, 0, 15, 15, 15, 0, 15, 0, 15, 15, 0, 15, 15, 15, 0, 0, 15, 15, 0, 0,
		15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 0, 15,
		15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 0, 0, 15, 15, 15,
		15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15,
		15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15
	};
}

/// <summary>
/// 상처약 사용
/// </summary>
/// <param name="poketmon"></param>
/// <returns></returns>
bool Item_Potion::Use(Poketmon* poketmon)
{
	if (poketmon->GetCurrentHP() == poketmon->GetHP())
	{
		return false;
	}

	else if (poketmon->GetCurrentHP() + m_nHealAmount > poketmon->GetHP())
	{
		poketmon->SetCurrentHp(poketmon->GetHP());
		return true;
	}

	else
	{
		poketmon->SetCurrentHp(poketmon->GetCurrentHP() + m_nHealAmount);
		return true;
	}
}