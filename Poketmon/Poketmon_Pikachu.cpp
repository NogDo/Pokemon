#include "Poketmon_Pikachu.h"

Poketmon_Pikachu::Poketmon_Pikachu(int nLevel)
{
	Init(nLevel);
}

Poketmon_Pikachu::~Poketmon_Pikachu()
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

void Poketmon_Pikachu::Init(int nLevel)
{
	m_strName[0] = "ÇÇÄ«Ãò";
	m_nWidth[0] = 19;
	m_nHeight[0] = 20;
	m_nCurrentEvolutionStep = 0;

	m_nHP = 35 + 3 * (nLevel - 1);
	m_nCurrentHP = m_nHP;
	m_nAttack = 55 + 5 * (nLevel - 1);
	m_nDefense = 40 + 4 * (nLevel - 1);
	m_nSpecialAttack = 50 + 5 * (nLevel - 1);
	m_nSpecialDefense = 50 + 5 * (nLevel - 1);
	m_nSpeed = 90 + 9 * (nLevel - 1);
	this->m_nLevel = nLevel;
	m_nCurrentExp = 0.0f;
	m_nTotalExp = 100.0f + 10 * (nLevel - 1) + 1 * (nLevel - 1);
	m_vePoketmonType.push_back(EPoketmon_Type::ELECTRIC);
	m_isLearnSkill = false;

	ElectricSkill::STThunderShock thunderShock;
	m_vSkill.push_back(new Skill(thunderShock.m_strName, thunderShock.m_nPower, thunderShock.m_nAccuracy,
		thunderShock.m_nSkillRemainCount, thunderShock.m_eSkillType, thunderShock.m_eSkillAttackType));

	NormalSkill::STQuickAttack quickAttack;
	ElectricSkill::STThunderbolt thunderBolt;
	ElectricSkill::STThunder thunder;

	if (m_nLevel >= 11)
	{
		m_vSkill.push_back(new Skill(quickAttack.m_strName, quickAttack.m_nPower, quickAttack.m_nAccuracy,
			quickAttack.m_nSkillRemainCount, quickAttack.m_eSkillType, quickAttack.m_eSkillAttackType));
	}

	if (m_nLevel >= 26)
	{
		m_vSkill.push_back(new Skill(thunderBolt.m_strName, thunderBolt.m_nPower, thunderBolt.m_nAccuracy,
			thunderBolt.m_nSkillRemainCount, thunderBolt.m_eSkillType, thunderBolt.m_eSkillAttackType));
	}

	if (m_nLevel >= 41)
	{
		m_vSkill.push_back(new Skill(thunder.m_strName, thunder.m_nPower, thunder.m_nAccuracy,
			thunder.m_nSkillRemainCount, thunder.m_eSkillType, thunder.m_eSkillAttackType));
	}

	m_vSkillLearnLevel.push_back(std::make_pair(11, new Skill(quickAttack.m_strName, quickAttack.m_nPower, quickAttack.m_nAccuracy,
		quickAttack.m_nSkillRemainCount, quickAttack.m_eSkillType, quickAttack.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(26, new Skill(thunderBolt.m_strName, thunderBolt.m_nPower, thunderBolt.m_nAccuracy,
		thunderBolt.m_nSkillRemainCount, thunderBolt.m_eSkillType, thunderBolt.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(41, new Skill(thunder.m_strName, thunder.m_nPower, thunder.m_nAccuracy,
		thunder.m_nSkillRemainCount, thunder.m_eSkillType, thunder.m_eSkillAttackType)));


	m_chArrSprite[0] = new char[m_nWidth[0] * m_nHeight[0]]
	{
		15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15,
		15, 0, 14, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15,
		0, 14, 14, 14, 0, 15, 15, 15, 15, 15, 15, 15, 0, 14, 0, 15, 15, 15, 15,
		0, 14, 14, 14, 14, 0, 0, 0, 15, 15, 15, 15, 0, 14, 14, 0, 15, 15, 15,
		15, 0, 14, 14, 14, 0, 0, 0, 0, 0, 15, 15, 0, 14, 14, 0, 15, 15, 15,
		15, 15, 0, 14, 14, 14, 0, 0, 14, 14, 0, 0, 14, 14, 14, 14, 0, 15, 15,
		15, 15, 15, 0, 14, 14, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 15,
		15, 15, 0, 6, 14, 0, 15, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 0,
		15, 15, 0, 6, 0, 15, 15, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0,
		15, 15, 15, 0, 6, 0, 0, 14, 14, 14, 14, 14, 0, 15, 14, 14, 14, 14, 0,
		15, 15, 15, 15, 0, 0, 0, 14, 14, 14, 12, 12, 0, 0, 14, 14, 14, 0, 15,
		15, 15, 15, 15, 15, 0, 6, 6, 14, 14, 14, 12, 14, 14, 14, 14, 0, 15, 15,
		15, 15, 15, 15, 15, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 15,
		15, 15, 15, 15, 15, 0, 6, 14, 14, 0, 14, 14, 14, 14, 14, 0, 0, 15, 15,
		15, 15, 15, 15, 15, 0, 14, 14, 14, 14, 0, 14, 14, 14, 14, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 14, 14, 14, 0, 14, 14, 14, 14, 0, 14, 0, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 0, 14, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 14, 14, 14, 0, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};
}

void Poketmon_Pikachu::LevelUp(float fRemainExp)
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

int Poketmon_Pikachu::Hit(int nSkillDamage, ESkillAttack_Type eSkillAttackType, ESkill_Type eSkillType)
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
		nDamage = (nSkillDamage / 2) / nDef;
		nEffect = -1;
		break;

	case ESkill_Type::FLYING:
		nDamage = (nSkillDamage / 2) / nDef;
		nEffect = -1;
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

int Poketmon_Pikachu::GetSkillDamage(int nSkillIndex)
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

bool Poketmon_Pikachu::IsEvolution()
{
	return false;
}