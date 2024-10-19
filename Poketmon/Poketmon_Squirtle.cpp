#include "Poketmon_Squirtle.h"

Poketmon_Squirtle::Poketmon_Squirtle(int nLevel)
{
	Init(nLevel);
}

Poketmon_Squirtle::~Poketmon_Squirtle()
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

void Poketmon_Squirtle::Init(int nLevel)
{
	m_strName[0] = "部何扁";
	m_strName[1] = "绢聪何扁";
	m_strName[2] = "芭合空";
	m_nWidth[0] = 21;
	m_nHeight[0] = 17;
	m_nWidth[1] = 23;
	m_nHeight[1] = 20;
	m_nWidth[2] = 23;
	m_nHeight[2] = 21;


	if (nLevel < 16)
	{
		m_nCurrentEvolutionStep = 0;

		m_nHP = 44 + 4 * (nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 48 + 4 * (nLevel - 1);
		m_nDefense = 65 + 6 * (nLevel - 1);
		m_nSpecialAttack = 50 + 5 * (nLevel - 1);
		m_nSpecialDefense = 64 + 6 * (nLevel - 1);
		m_nSpeed = 43 + 4 * (nLevel - 1);
		this->m_nLevel = nLevel;
		m_nCurrentExp = 0.0f;
		m_nTotalExp = 100.0f + 10 * (nLevel - 1) + 1 * (nLevel - 1);
		m_vePoketmonType.push_back(EPoketmon_Type::WATER);
		m_isLearnSkill = false;
	}

	else if (nLevel < 36)
	{
		m_nCurrentEvolutionStep = 1;

		m_nHP = 59 + 5 * (nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 63 + 6 * (nLevel - 1);
		m_nDefense = 80 + 8 * (nLevel - 1);
		m_nSpecialAttack = 65 + 6 * (nLevel - 1);
		m_nSpecialDefense = 80 + 8 * (nLevel - 1);
		m_nSpeed = 58 + 5 * (nLevel - 1);
		this->m_nLevel = nLevel;
		m_nCurrentExp = 0.0f;
		m_nTotalExp = 100.0f + 10 * (nLevel - 1) + (nLevel - 1);
		m_vePoketmonType.push_back(EPoketmon_Type::WATER);
	}

	else
	{
		m_nCurrentEvolutionStep = 2;

		m_nHP = 79 + 7 * (nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 83 + 8 * (nLevel - 1);
		m_nDefense = 100 + 10 * (nLevel - 1) + (nLevel - 1);
		m_nSpecialAttack = 85 + 8 * (nLevel - 1);
		m_nSpecialDefense = 105 + 8 * (nLevel - 1) + (nLevel - 1);
		m_nSpeed = 78 + 7 * (nLevel - 1);
		this->m_nLevel = nLevel;
		m_nCurrentExp = 0.0f;
		m_nTotalExp = 100.0f + 10 * (nLevel - 1) + (nLevel - 1);
		m_vePoketmonType.push_back(EPoketmon_Type::WATER);
		m_isLearnSkill = false;
	}


	NormalSkill::STBodySlam bodyslam;
	m_vSkill.push_back(new Skill(bodyslam.m_strName, bodyslam.m_nPower, bodyslam.m_nAccuracy,
		bodyslam.m_nSkillRemainCount, bodyslam.m_eSkillType, bodyslam.m_eSkillAttackType));

	WaterSkill::STBubble bubble;
	WaterSkill::STWaterGun waterGun;
	WaterSkill::STHydroPump hydroPump;

	if (m_nLevel >= 7)
	{
		m_vSkill.push_back(new Skill(bubble.m_strName, bubble.m_nPower, bubble.m_nAccuracy,
			bubble.m_nSkillRemainCount, bubble.m_eSkillType, bubble.m_eSkillAttackType));
	}

	if (m_nLevel >= 13)
	{
		m_vSkill.push_back(new Skill(waterGun.m_strName, waterGun.m_nPower, waterGun.m_nAccuracy,
			waterGun.m_nSkillRemainCount, waterGun.m_eSkillType, waterGun.m_eSkillAttackType));
	}

	if (m_nLevel >= 47)
	{
		m_vSkill.push_back(new Skill(hydroPump.m_strName, hydroPump.m_nPower, hydroPump.m_nAccuracy,
			hydroPump.m_nSkillRemainCount, hydroPump.m_eSkillType, hydroPump.m_eSkillAttackType));
	}

	m_vSkillLearnLevel.push_back(std::make_pair(7, new Skill(bubble.m_strName, bubble.m_nPower, bubble.m_nAccuracy,
		bubble.m_nSkillRemainCount, bubble.m_eSkillType, bubble.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(13, new Skill(waterGun.m_strName, waterGun.m_nPower, waterGun.m_nAccuracy,
		waterGun.m_nSkillRemainCount, waterGun.m_eSkillType, waterGun.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(47, new Skill(hydroPump.m_strName, hydroPump.m_nPower, hydroPump.m_nAccuracy,
		hydroPump.m_nSkillRemainCount, hydroPump.m_eSkillType, hydroPump.m_eSkillAttackType)));

	m_chArrSprite[0] = new char[m_nWidth[0] * m_nHeight[0]]
	{
		15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15,
		15, 0, 9, 9, 9, 0, 15, 15, 15, 15, 15, 15, 0, 0, 1, 9, 9, 9, 0, 15, 15,
		0, 1, 1, 9, 9, 0, 15, 15, 15, 15, 0, 0, 1, 9, 9, 9, 9, 9, 9, 0, 15,
		0, 1, 0, 1, 9, 9, 0, 0, 0, 0, 6, 0, 9, 9, 9, 9, 9, 9, 9, 0, 15,
		0, 1, 1, 0, 1, 9, 9, 0, 6, 6, 6, 1, 9, 9, 9, 9, 9, 9, 9, 6, 0,
		15, 0, 1, 0, 1, 1, 0, 6, 6, 6, 15, 1, 9, 9, 0, 15, 9, 9, 9, 9, 0,
		15, 15, 0, 0, 0, 1, 0, 6, 6, 6, 15, 1, 1, 9, 6, 0, 9, 9, 9, 1, 0,
		15, 15, 15, 15, 0, 0, 6, 6, 6, 15, 0, 1, 1, 1, 6, 0, 1, 1, 1, 0, 15,
		15, 15, 15, 15, 15, 0, 6, 6, 15, 9, 9, 0, 0, 1, 1, 1, 1, 0, 0, 15, 15,
		15, 15, 15, 15, 15, 0, 6, 6, 15, 1, 9, 0, 1, 0, 0, 0, 0, 1, 0, 15, 15,
		15, 15, 15, 15, 15, 0, 6, 6, 15, 0, 1, 9, 9, 0, 14, 14, 0, 0, 0, 15, 15,
		15, 15, 15, 15, 15, 0, 6, 6, 15, 0, 0, 0, 0, 14, 14, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 9, 0, 6, 14, 14, 14, 6, 0, 1, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 9, 0, 9, 6, 6, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 0, 9, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 1, 1, 1, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};

	m_chArrSprite[1] = new char[m_nWidth[1] * m_nHeight[1]]
	{
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 0, 9, 9, 15, 0, 15, 15,
		15, 0, 0, 0, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 0, 0, 0, 0, 1, 15, 0, 15, 15,
		0, 9, 15, 15, 0, 15, 15, 15, 15, 0, 9, 9, 15, 0, 1, 1, 1, 9, 9, 1, 0, 15, 15,
		0, 9, 0, 9, 15, 0, 15, 15, 15, 0, 9, 9, 9, 15, 0, 1, 9, 9, 9, 9, 1, 0, 15,
		0, 1, 1, 0, 15, 0, 15, 15, 15, 0, 0, 9, 9, 15, 0, 1, 9, 9, 9, 9, 9, 0, 15,
		15, 0, 0, 1, 9, 15, 0, 15, 0, 6, 6, 0, 0, 0, 1, 1, 0, 9, 9, 9, 9, 12, 0,
		15, 0, 1, 1, 9, 9, 0, 0, 6, 6, 6, 7, 1, 1, 1, 1, 15, 0, 9, 9, 9, 9, 0,
		15, 0, 9, 9, 1, 9, 9, 0, 6, 6, 6, 15, 1, 1, 1, 1, 15, 12, 0, 9, 9, 1, 0,
		15, 0, 1, 9, 9, 1, 0, 6, 6, 6, 15, 0, 1, 1, 7, 7, 15, 12, 1, 1, 1, 0, 15,
		15, 15, 0, 1, 9, 9, 0, 6, 6, 15, 9, 9, 0, 0, 1, 1, 1, 1, 15, 0, 0, 15, 15,
		15, 15, 15, 0, 0, 1, 0, 6, 6, 15, 1, 9, 9, 15, 0, 1, 0, 0, 0, 1, 0, 15, 15,
		15, 15, 15, 15, 15, 0, 0, 6, 6, 15, 0, 1, 9, 9, 0, 14, 14, 14, 0, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 6, 6, 7, 0, 0, 0, 0, 14, 14, 14, 0, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 7, 0, 0, 14, 14, 14, 14, 0, 0, 1, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 7, 0, 9, 0, 14, 14, 0, 0, 0, 0, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 0, 1, 9, 9, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 0, 1, 1, 9, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};

	m_chArrSprite[2] = new char[m_nWidth[2] * m_nHeight[2]]
	{
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 7, 0, 0, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 0, 0, 0, 7, 7, 15, 0, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 7, 7, 0, 0, 0, 6, 6, 6, 6, 15, 0, 15, 0, 0, 15, 15, 15,
		15, 15, 15, 15, 0, 7, 0, 0, 15, 0, 6, 6, 6, 6, 6, 6, 0, 0, 9, 0, 15, 15, 15,
		15, 15, 15, 15, 0, 7, 0, 0, 15, 15, 6, 0, 0, 6, 0, 0, 1, 9, 9, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 7, 7, 7, 15, 6, 0, 1, 0, 1, 1, 9, 9, 9, 9, 0, 15, 15,
		15, 15, 15, 15, 0, 6, 0, 7, 7, 6, 6, 0, 1, 1, 1, 9, 9, 9, 9, 9, 1, 0, 15,
		15, 15, 15, 15, 0, 6, 6, 0, 0, 7, 7, 7, 0, 1, 1, 0, 1, 9, 9, 9, 9, 0, 15,
		0, 0, 0, 0, 6, 6, 7, 0, 0, 0, 0, 0, 1, 1, 1, 15, 0, 1, 9, 9, 9, 9, 0,
		0, 1, 9, 0, 6, 7, 0, 1, 1, 1, 0, 0, 1, 14, 1, 9, 0, 0, 9, 9, 9, 9, 0,
		15, 0, 9, 0, 6, 7, 0, 1, 1, 9, 0, 7, 0, 14, 14, 1, 9, 9, 9, 9, 9, 15, 0,
		15, 15, 0, 0, 7, 7, 0, 1, 9, 9, 9, 0, 7, 0, 14, 14, 14, 9, 9, 14, 14, 0, 15,
		15, 15, 15, 15, 0, 0, 9, 0, 1, 9, 1, 9, 0, 14, 0, 0, 14, 14, 15, 0, 0, 15, 15,
		15, 15, 15, 15, 0, 1, 9, 9, 0, 1, 9, 9, 15, 0, 14, 14, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 0, 1, 1, 9, 9, 9, 0, 9, 9, 0, 0, 14, 14, 0, 0, 15, 15, 15, 15, 15,
		15, 15, 15, 0, 1, 9, 9, 0, 0, 0, 0, 15, 0, 14, 14, 0, 0, 0, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 1, 9, 9, 1, 0, 14, 0, 14, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 15, 9, 9, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};
}

void Poketmon_Squirtle::LevelUp(float fRemainExp)
{
	m_nLevel++;

	if (m_nLevel == 16)
	{
		m_nCurrentEvolutionStep = 1;

		m_nHP = 59 + 5 * (m_nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 63 + 6 * (m_nLevel - 1);
		m_nDefense = 80 + 8 * (m_nLevel - 1);
		m_nSpecialAttack = 65 + 6 * (m_nLevel - 1);
		m_nSpecialDefense = 80 + 8 * (m_nLevel - 1);
		m_nSpeed = 58 + 5 * (m_nLevel - 1);
		this->m_nCurrentExp = fRemainExp;
		m_nTotalExp = 100.0f + 10 * (m_nLevel - 1) + (m_nLevel - 1);
	}

	else if (m_nLevel == 36)
	{
		m_nCurrentEvolutionStep = 2;

		m_nHP = 79 + 7 * (m_nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 83 + 8 * (m_nLevel - 1);
		m_nDefense = 100 + 10 * (m_nLevel - 1) + (m_nLevel - 1);
		m_nSpecialAttack = 85 + 8 * (m_nLevel - 1);
		m_nSpecialDefense = 105 + 8 * (m_nLevel - 1) + (m_nLevel - 1);
		m_nSpeed = 78 + 7 * (m_nLevel - 1);
		this->m_nCurrentExp = fRemainExp;
		m_nTotalExp = 100.0f + 10 * (m_nLevel - 1) + (m_nLevel - 1);
		m_isLearnSkill = false;
	}

	else
	{
		m_nHP += m_nHP / 10;
		m_nCurrentHP += m_nHP / 10;
		m_nAttack += m_nAttack / 10;
		m_nDefense += m_nDefense / 10;
		m_nSpecialAttack += m_nSpecialAttack / 10;
		m_nSpecialDefense += m_nSpecialDefense / 10;
		m_nSpeed += m_nSpeed / 10;
		this->m_nCurrentExp = fRemainExp;
		m_nTotalExp += m_nTotalExp / 10;
	}


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

int Poketmon_Squirtle::Hit(int nSkillDamage, ESkillAttack_Type eSkillAttackType, ESkill_Type eSkillType)
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
		nDamage = (nSkillDamage / 2) / nDef;
		nEffect = -1;
		break;

	case ESkill_Type::WATER:
		nDamage = (nSkillDamage / 2) / nDef;
		nEffect = -1;
		break;

	case ESkill_Type::GRASS:
		nDamage = (nSkillDamage * 2) / nDef;
		nEffect = 1;
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

int Poketmon_Squirtle::GetSkillDamage(int nSkillIndex)
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

bool Poketmon_Squirtle::IsEvolution()
{
	if (m_nLevel + 1 == 16 || m_nLevel + 1 == 36)
	{
		return true;
	}

	else
	{
		return false;
	}
}