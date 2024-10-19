#include "Poketmon_Rattata.h"

Poketmon_Rattata::Poketmon_Rattata(int nLevel)
{
	Init(nLevel);
}

Poketmon_Rattata::~Poketmon_Rattata()
{
	delete[] m_chArrSprite[0];
	delete[] m_chArrSprite[1];
	delete[] m_chArrSprite[2];

	m_viSkill = m_vSkill.begin();
	for (m_viSkill; m_viSkill != m_vSkill.end(); ++m_viSkill)
	{
		delete* m_viSkill;
	}
	m_vSkill.clear();
}

void Poketmon_Rattata::Init(int nLevel)
{
	m_strName[0] = "²¿·¿";
	m_nWidth[0] = 18;
	m_nHeight[0] = 21;
	m_nCurrentEvolutionStep = 0;

	m_nHP = 30 + 3 * (nLevel - 1);
	m_nCurrentHP = m_nHP;
	m_nAttack = 56 + 5 * (nLevel - 1);
	m_nDefense = 35 + 3 * (nLevel - 1);
	m_nSpecialAttack = 25 + 2 * (nLevel - 1);
	m_nSpecialDefense = 35 + 3 * (nLevel - 1);
	m_nSpeed = 72 + 7 * (nLevel - 1);
	this->m_nLevel = nLevel;
	m_nCurrentExp = 0.0f;
	m_nTotalExp = 100.0f + 10 * (nLevel - 1) + 1 * (nLevel - 1);
	m_vePoketmonType.push_back(EPoketmon_Type::NORMAL);
	m_isLearnSkill = false;

	NormalSkill::STBodySlam bodySlam;
	m_vSkill.push_back(new Skill(bodySlam.m_strName, bodySlam.m_nPower, bodySlam.m_nAccuracy,
		bodySlam.m_nSkillRemainCount, bodySlam.m_eSkillType, bodySlam.m_eSkillAttackType));

	NormalSkill::STQuickAttack quickAttack;
	NormalSkill::STHyperFang hyperFang;
	DarkSkill::STPursuit pursuit;

	if (m_nLevel >= 7)
	{
		m_vSkill.push_back(new Skill(quickAttack.m_strName, quickAttack.m_nPower, quickAttack.m_nAccuracy,
			quickAttack.m_nSkillRemainCount, quickAttack.m_eSkillType, quickAttack.m_eSkillAttackType));
	}

	if (m_nLevel >= 13)
	{
		m_vSkill.push_back(new Skill(hyperFang.m_strName, hyperFang.m_nPower, hyperFang.m_nAccuracy,
			hyperFang.m_nSkillRemainCount, hyperFang.m_eSkillType, hyperFang.m_eSkillAttackType));
	}

	if (m_nLevel >= 27)
	{
		m_vSkill.push_back(new Skill(pursuit.m_strName, pursuit.m_nPower, pursuit.m_nAccuracy,
			pursuit.m_nSkillRemainCount, pursuit.m_eSkillType, pursuit.m_eSkillAttackType));
	}

	m_vSkillLearnLevel.push_back(std::make_pair(7, new Skill(quickAttack.m_strName, quickAttack.m_nPower, quickAttack.m_nAccuracy,
		quickAttack.m_nSkillRemainCount, quickAttack.m_eSkillType, quickAttack.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(13, new Skill(hyperFang.m_strName, hyperFang.m_nPower, hyperFang.m_nAccuracy,
		hyperFang.m_nSkillRemainCount, hyperFang.m_eSkillType, hyperFang.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(27, new Skill(pursuit.m_strName, pursuit.m_nPower, pursuit.m_nAccuracy,
		pursuit.m_nSkillRemainCount, pursuit.m_eSkillType, pursuit.m_eSkillAttackType)));


	m_chArrSprite[0] = new char[m_nWidth[0] * m_nHeight[0]]
	{
		15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		0, 0, 13, 13, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		0, 5, 0, 0, 13, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		0, 5, 0, 13, 13, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		0, 5, 5, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 0, 5, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 0, 5, 0, 0, 0, 0, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15,
		15, 15, 15, 0, 13, 13, 13, 13, 0, 0, 15, 0, 13, 0, 15, 15, 15, 15,
		15, 15, 0, 13, 13, 13, 0, 0, 5, 5, 0, 0, 13, 0, 15, 15, 15, 15,
		15, 0, 5, 5, 13, 0, 13, 13, 0, 0, 13, 13, 13, 13, 0, 15, 15, 15,
		15, 0, 5, 5, 5, 0, 14, 13, 0, 13, 13, 13, 13, 13, 13, 0, 15, 15,
		15, 0, 5, 0, 5, 13, 0, 14, 13, 13, 13, 13, 13, 13, 13, 0, 15, 15,
		15, 0, 5, 5, 0, 5, 5, 5, 5, 13, 13, 13, 13, 13, 13, 0, 0, 15,
		15, 15, 0, 5, 0, 5, 5, 5, 5, 5, 0, 13, 13, 13, 13, 0, 15, 0,
		15, 15, 0, 15, 0, 0, 5, 5, 0, 5, 15, 0, 13, 13, 13, 15, 0, 15,
		15, 15, 15, 0, 0, 0, 5, 0, 15, 15, 15, 12, 0, 15, 15, 15, 0, 15,
		15, 15, 15, 15, 15, 15, 0, 5, 0, 0, 0, 15, 15, 15, 15, 0, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 5, 5, 0, 0, 0, 0, 0, 15, 0, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 5, 13, 0, 0, 15, 0, 15, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15,
	};
}

void Poketmon_Rattata::LevelUp(float fRemainExp)
{
	m_nLevel++;
	m_nHP += m_nHP / 10;
	m_nCurrentHP += m_nHP / 10;
	m_nAttack += m_nAttack / 10;
	m_nDefense += m_nDefense / 10;
	m_nSpecialAttack += m_nSpecialAttack / 10;
	m_nSpecialDefense += m_nSpecialDefense / 10;
	m_nSpeed += m_nSpeed / 10;
	this->m_nCurrentExp = fRemainExp;
	m_nTotalExp += m_nTotalExp / 10;

	m_viSkillLearnLevel = m_vSkillLearnLevel.begin();
	for (m_viSkillLearnLevel; m_viSkillLearnLevel != m_vSkillLearnLevel.end(); ++m_viSkillLearnLevel)
	{
		if (m_viSkillLearnLevel->first == m_nLevel)
		{
			m_vSkill.push_back((*m_viSkillLearnLevel).second);
			m_isLearnSkill = true;
			m_strLearnSkillName = m_viSkillLearnLevel->second->GetName();
			break;
		}

		else
		{
			m_isLearnSkill = false;
		}
	}
}

int Poketmon_Rattata::Hit(int nSkillDamage, ESkillAttack_Type eSkillAttackType, ESkill_Type eSkillType)
{
	int nDef, nEffect;

	switch (eSkillAttackType)
	{
	case ESkillAttack_Type::PHISICAL:
		nDef = m_nDefense;
		break;

	case ESkillAttack_Type::SPECIAL:
		nDef = m_nSpecialDefense;
		break;

	case ESkillAttack_Type::STATUS:
		break;
	}

	int nDamage;
	switch (eSkillType)
	{
	case ESkill_Type::FIRE:
		nDamage = nSkillDamage / nDef;
		nEffect = 0;
		break;

	case ESkill_Type::WATER:
		nDamage = nSkillDamage / nDef;
		nEffect = 0;
		break;

	case ESkill_Type::GRASS:
		nDamage = nSkillDamage / nDef;
		nEffect = 0;
		break;

	case ESkill_Type::ELECTRIC:
		nDamage = nSkillDamage/ nDef;
		nEffect = 0;
		break;

	case ESkill_Type::FLYING:
		nDamage = nSkillDamage / nDef;
		nEffect = 0;
		break;

	case ESkill_Type::DARK:
		nDamage = nSkillDamage / nDef;
		nEffect = 0;
		break;

	case ESkill_Type::NORMAL:
		nDamage = nSkillDamage / nDef;
		nEffect = 0;
		break;
	}

	m_nCurrentHP -= nDamage;

	if (m_nCurrentHP < 0)
	{
		m_nCurrentHP = 0;
	}

	return nEffect;
}

int Poketmon_Rattata::GetSkillDamage(int nSkillIndex)
{
	int nAccuracy = rand() % 100;

	if (nAccuracy < m_vSkill.at(nSkillIndex)->GetAccuracy())
	{
		switch (m_vSkill.at(nSkillIndex)->GetSkillAttackType())
		{
		case ESkillAttack_Type::PHISICAL:
			return m_nAttack * m_vSkill.at(nSkillIndex)->GetPower();

		case ESkillAttack_Type::SPECIAL:
			return m_nSpecialAttack * m_vSkill.at(nSkillIndex)->GetPower();

		case ESkillAttack_Type::STATUS:
			return 0;
		}
	}

	else
	{
		return 0;
	}
}

bool Poketmon_Rattata::IsEvolution()
{
	return false;
}