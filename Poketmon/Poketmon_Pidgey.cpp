#include "Poketmon_Pidgey.h"

Poketmon_Pidgey::Poketmon_Pidgey(int nLevel)
{
	Init(nLevel);
}

Poketmon_Pidgey::~Poketmon_Pidgey()
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

void Poketmon_Pidgey::Init(int nLevel)
{
	m_strName[0] = "±¸±¸";
	m_nWidth[0] = 18;
	m_nHeight[0] = 17;
	m_nCurrentEvolutionStep = 0;

	m_nHP = 40 + 4 * (nLevel - 1);
	m_nCurrentHP = m_nHP;
	m_nAttack = 45 + 4 * (nLevel - 1);
	m_nDefense = 40 + 4 * (nLevel - 1);
	m_nSpecialAttack = 35 + 3 * (nLevel - 1);
	m_nSpecialDefense = 35 + 3 * (nLevel - 1);
	m_nSpeed = 56 + 5 * (nLevel - 1);
	this->m_nLevel = nLevel;
	m_nCurrentExp = 0.0f;
	m_nTotalExp = 100.0f + 10 * (nLevel - 1) + 1 * (nLevel - 1);
	m_vePoketmonType.push_back(EPoketmon_Type::FLYING);
	m_vePoketmonType.push_back(EPoketmon_Type::NORMAL);
	m_isLearnSkill = false;

	NormalSkill::STBodySlam bodySlam;
	m_vSkill.push_back(new Skill(bodySlam.m_strName, bodySlam.m_nPower, bodySlam.m_nAccuracy,
		bodySlam.m_nSkillRemainCount, bodySlam.m_eSkillType, bodySlam.m_eSkillAttackType));

	FlyingSkill::STGust gust;
	NormalSkill::STQuickAttack quickAttack;
	FlyingSkill::STWingAttack wingAttack;

	if (m_nLevel >= 9)
	{
		m_vSkill.push_back(new Skill(gust.m_strName, gust.m_nPower, gust.m_nAccuracy,
			gust.m_nSkillRemainCount, gust.m_eSkillType, gust.m_eSkillAttackType));
	}

	if (m_nLevel >= 15)
	{
		m_vSkill.push_back(new Skill(quickAttack.m_strName, quickAttack.m_nPower, quickAttack.m_nAccuracy,
			quickAttack.m_nSkillRemainCount, quickAttack.m_eSkillType, quickAttack.m_eSkillAttackType));
	}

	if (m_nLevel >= 29)
	{
		m_vSkill.push_back(new Skill(wingAttack.m_strName, wingAttack.m_nPower, wingAttack.m_nAccuracy,
			wingAttack.m_nSkillRemainCount, wingAttack.m_eSkillType, wingAttack.m_eSkillAttackType));
	}

	m_vSkillLearnLevel.push_back(std::make_pair(9, new Skill(gust.m_strName, gust.m_nPower, gust.m_nAccuracy,
		gust.m_nSkillRemainCount, gust.m_eSkillType, gust.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(15, new Skill(quickAttack.m_strName, quickAttack.m_nPower, quickAttack.m_nAccuracy,
		quickAttack.m_nSkillRemainCount, quickAttack.m_eSkillType, quickAttack.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(29, new Skill(wingAttack.m_strName, wingAttack.m_nPower, wingAttack.m_nAccuracy,
		wingAttack.m_nSkillRemainCount, wingAttack.m_eSkillType, wingAttack.m_eSkillAttackType)));


	m_chArrSprite[0] = new char[m_nWidth[0] * m_nHeight[0]]
	{
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 14, 0, 15, 15, 15, 15, 15,
		15, 0, 0, 0, 15, 15, 15, 0, 0, 15, 0, 14, 0, 15, 15, 15, 15, 15,
		0, 0, 6, 6, 0, 15, 15, 0, 15, 0, 0, 6, 14, 0, 0, 15, 15, 15,
		0, 6, 0, 6, 0, 15, 15, 0, 15, 15, 0, 6, 14, 0, 15, 0, 15, 15,
		0, 6, 6, 0, 6, 0, 0, 15, 15, 15, 15, 0, 6, 14, 15, 0, 15, 15,
		15, 0, 6, 0, 0, 6, 0, 0, 15, 15, 15, 15, 6, 14, 14, 15, 0, 15,
		15, 15, 0, 15, 0, 6, 6, 6, 0, 0, 15, 15, 15, 6, 14, 15, 0, 15,
		15, 0, 15, 15, 15, 0, 6, 6, 6, 0, 0, 15, 15, 15, 0, 0, 0, 15,
		15, 0, 15, 15, 15, 14, 0, 0, 6, 0, 0, 15, 0, 0, 7, 7, 0, 15,
		15, 15, 0, 15, 6, 14, 14, 14, 0, 0, 0, 0, 0, 7, 7, 7, 7, 0,
		15, 15, 0, 6, 6, 6, 14, 14, 0, 15, 15, 15, 0, 0, 0, 0, 7, 0,
		15, 15, 15, 0, 6, 6, 6, 6, 0, 15, 15, 15, 0, 15, 0, 0, 0, 15,
		15, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 7, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15
	};
}

void Poketmon_Pidgey::LevelUp(float fRemainExp)
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

int Poketmon_Pidgey::Hit(int nSkillDamage, ESkillAttack_Type eSkillAttackType, ESkill_Type eSkillType)
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
		nDamage = (nSkillDamage / 2) / nDef;
		nEffect = -1;
		break;

	case ESkill_Type::ELECTRIC:
		nDamage = (nSkillDamage * 2) / nDef;
		nEffect = 1;
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

int Poketmon_Pidgey::GetSkillDamage(int nSkillIndex)
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

bool Poketmon_Pidgey::IsEvolution()
{
	return false;
}