#include "NpcEnemy.h"

NpcEnemy::NpcEnemy()
{
	Init();
}

NpcEnemy::~NpcEnemy()
{
	if (!isCatch)
	{
		m_viPoketmon = m_vPoketmon.begin();
		for (m_viPoketmon; m_viPoketmon != m_vPoketmon.end(); ++m_viPoketmon)
		{
			delete* m_viPoketmon;
		}

		m_vPoketmon.clear();
	}
}

void NpcEnemy::Init()
{
	m_nWidth = 0;
	m_nHeight = 0;
	m_nPoketmonIndex = 0;

	isCatch = false;
}

void NpcEnemy::SetLevel(int nLevel)
{
	int nRandLevel;
	if (nLevel - 5 > 0)
	{
		nRandLevel = rand() % 5 + (nLevel - 5);
	}

	else
	{
		nRandLevel = rand() % 5 + 1;
	}

	EPoketmon_Number nPoketmonRandNum = static_cast<EPoketmon_Number>(rand() % 6);
	switch (nPoketmonRandNum)
	{
	case EPoketmon_Number::BULBASAUR:
		m_vPoketmon.push_back(new Poketmon_Bulbasaur(nRandLevel));
		break;

	case EPoketmon_Number::CHAMANDER:
		m_vPoketmon.push_back(new Poketmon_Charmander(nRandLevel));
		break;

	case EPoketmon_Number::SQUIRTLE:
		m_vPoketmon.push_back(new Poketmon_Squirtle(nRandLevel));
		break;

	case EPoketmon_Number::PIKACHU:
		m_vPoketmon.push_back(new Poketmon_Pikachu(nRandLevel));
		break;

	case EPoketmon_Number::PIDGEY:
		m_vPoketmon.push_back(new Poketmon_Pidgey(nRandLevel));
		break;

	case EPoketmon_Number::RATTATA:
		m_vPoketmon.push_back(new Poketmon_Rattata(nRandLevel));
		break;
	}
}