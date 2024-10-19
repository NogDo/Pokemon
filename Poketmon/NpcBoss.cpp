#include "NpcBoss.h"

NpcBoss::NpcBoss()
{
	Init();
}

NpcBoss::~NpcBoss()
{
	delete[] m_chArrSprite;
}

void NpcBoss::Init()
{
	m_vPoketmon.push_back(new Poketmon_Rattata(35));
	m_vPoketmon.push_back(new Poketmon_Pikachu(40));
	m_vPoketmon.push_back(new Poketmon_Charmander(45));

	m_nWidth = 14;
	m_nHeight = 16;
	m_nPoketmonIndex = 0;

	m_chArrSprite = new char[m_nWidth * m_nHeight]
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
}

bool NpcBoss::IsCanFight()
{
	m_viPoketmon = m_vPoketmon.begin();
	for (m_viPoketmon; m_viPoketmon != m_vPoketmon.end(); ++m_viPoketmon)
	{
		if ((*m_viPoketmon)->GetCurrentHP() > 0)
		{
			m_nPoketmonIndex++;
			return true;
		}
	}
}