#include "Poketmon_Bulbasaur.h"

Poketmon_Bulbasaur::Poketmon_Bulbasaur(int nLevel)
{
	Init(nLevel);
}

Poketmon_Bulbasaur::~Poketmon_Bulbasaur()
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

void Poketmon_Bulbasaur::Init(int nLevel)
{
	m_strName[0] = "이상해씨";
	m_strName[1] = "이상해풀";
	m_strName[2] = "이상해꽃";
	m_nWidth[0] = 20;
	m_nHeight[0] = 17;
	m_nWidth[1] = 21;
	m_nHeight[1] = 18;
	m_nWidth[2] = 27;
	m_nHeight[2] = 22;


	if (nLevel < 16)
	{
		m_nCurrentEvolutionStep = 0;

		m_nHP = 45 + 4 * (nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 49 + 4 * (nLevel - 1);
		m_nDefense = 49 + 4 * (nLevel - 1);
		m_nSpecialAttack = 65 + 6 * (nLevel - 1);
		m_nSpecialDefense = 65 + 6 * (nLevel - 1);
		m_nSpeed = 45 + 4 * (nLevel - 1);
		this->m_nLevel = nLevel;
		m_nCurrentExp = 0.0f;
		m_nTotalExp = 100.0f + 10 * (nLevel - 1) + (nLevel - 1);
		m_vePoketmonType.push_back(EPoketmon_Type::GRASS);
		m_isLearnSkill = false;
	}

	else if (nLevel < 32)
	{
		m_nCurrentEvolutionStep = 1;

		m_nHP = 60 + 6 * (nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 62 + 6 * (nLevel - 1);
		m_nDefense = 63 + 6 * (nLevel - 1);
		m_nSpecialAttack = 80 + 8 * (nLevel - 1);
		m_nSpecialDefense = 80 + 8 * (nLevel - 1);
		m_nSpeed = 60 + 6 * (nLevel - 1);
		this->m_nLevel = nLevel;
		m_nCurrentExp = 0.0f;
		m_nTotalExp = 100.0f + 10 * (nLevel - 1) + (nLevel - 1);
		m_vePoketmonType.push_back(EPoketmon_Type::GRASS);
	}

	else
	{
		m_nCurrentEvolutionStep = 2;

		m_nHP = 80 + 8 * (nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 82 + 8 * (nLevel - 1);
		m_nDefense = 83 + 8 * (nLevel - 1);
		m_nSpecialAttack = 100 + 10 * (nLevel - 1) + (nLevel - 1);
		m_nSpecialDefense = 100 + 8 * (nLevel - 1) + (nLevel - 1);
		m_nSpeed = 80 + 8 * (nLevel - 1);
		this->m_nLevel = nLevel;
		m_nCurrentExp = 0.0f;
		m_nTotalExp = 100.0f + 10 * (nLevel - 1) + (nLevel - 1);
		m_vePoketmonType.push_back(EPoketmon_Type::GRASS);
		m_isLearnSkill = false;
	}


	NormalSkill::STBodySlam bodyslam;
	m_vSkill.push_back(new Skill(bodyslam.m_strName, bodyslam.m_nPower, bodyslam.m_nAccuracy,
		bodyslam.m_nSkillRemainCount, bodyslam.m_eSkillType, bodyslam.m_eSkillAttackType));

	GrassSkill::STVineWhip vineWhip;
	GrassSkill::STRazorLeaf razorLeaf;
	GrassSkill::STSolarBeam solarBeam;

	if (m_nLevel >= 10)
	{
		m_vSkill.push_back(new Skill(vineWhip.m_strName, vineWhip.m_nPower, vineWhip.m_nAccuracy,
			vineWhip.m_nSkillRemainCount, vineWhip.m_eSkillType, vineWhip.m_eSkillAttackType));
	}

	if (m_nLevel >= 20)
	{
		m_vSkill.push_back(new Skill(razorLeaf.m_strName, razorLeaf.m_nPower, razorLeaf.m_nAccuracy,
			razorLeaf.m_nSkillRemainCount, razorLeaf.m_eSkillType, razorLeaf.m_eSkillAttackType));
	}

	if (m_nLevel >= 46)
	{
		m_vSkill.push_back(new Skill(solarBeam.m_strName, solarBeam.m_nPower, solarBeam.m_nAccuracy,
			solarBeam.m_nSkillRemainCount, solarBeam.m_eSkillType, solarBeam.m_eSkillAttackType));
	}

	m_vSkillLearnLevel.push_back(std::make_pair(10, new Skill(vineWhip.m_strName, vineWhip.m_nPower, vineWhip.m_nAccuracy,
		vineWhip.m_nSkillRemainCount, vineWhip.m_eSkillType, vineWhip.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(20, new Skill(razorLeaf.m_strName, razorLeaf.m_nPower, razorLeaf.m_nAccuracy,
		razorLeaf.m_nSkillRemainCount, razorLeaf.m_eSkillType, razorLeaf.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(46, new Skill(solarBeam.m_strName, solarBeam.m_nPower, solarBeam.m_nAccuracy,
		solarBeam.m_nSkillRemainCount, solarBeam.m_eSkillType, solarBeam.m_eSkillAttackType)));

	m_chArrSprite[0] = new char[m_nWidth[0] * m_nHeight[0]]
	{
		15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 10, 10, 10, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 10, 2, 10, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 0, 0, 10, 2, 10, 2, 10, 2, 10, 0, 0, 15, 15, 15, 15, 15, 15, 15,
		15, 0, 10, 10, 10, 2, 10, 2, 10, 10, 2, 10, 10, 0, 15, 15, 0, 15, 15, 15,
		0, 10, 10, 10, 2, 10, 10, 2, 10, 10, 10, 2, 10, 0, 0, 0, 11, 0, 15, 15,
		0, 10, 10, 2, 10, 10, 10, 10, 2, 10, 10, 0, 0, 11, 11, 11, 11, 0, 15, 15,
		0, 10, 10, 2, 10, 10, 10, 10, 2, 10, 0, 3, 3, 11, 11, 11, 11, 0, 15, 15,
		15, 0, 10, 2, 10, 10, 10, 0, 0, 0, 11, 11, 3, 3, 11, 3, 11, 11, 0, 15,
		0, 3, 0, 0, 0, 10, 10, 0, 11, 11, 11, 11, 11, 11, 11, 11, 11, 3, 0, 0,
		0, 3, 3, 3, 0, 0, 0, 3, 0, 11, 11, 11, 11, 3, 11, 11, 11, 3, 0, 0,
		0, 15, 3, 0, 3, 3, 3, 3, 3, 11, 11, 0, 0, 11, 3, 11, 11, 11, 11, 0,
		15, 0, 0, 0, 15, 0, 3, 0, 3, 11, 15, 15, 12, 0, 11, 11, 11, 11, 3, 0,
		15, 15, 15, 15, 0, 3, 3, 3, 0, 3, 11, 15, 12, 0, 11, 11, 11, 3, 0, 15,
		15, 15, 15, 15, 0, 3, 3, 3, 3, 0, 3, 3, 3, 3, 3, 3, 0, 0, 15, 15,
		15, 15, 15, 15, 0, 15, 3, 15, 0, 0, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};

	m_chArrSprite[1] = new char[m_nWidth[1] * m_nHeight[1]]
	{
		15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 13, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 0, 0, 13, 0, 13, 13, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 0, 2, 2, 0, 13, 0, 13, 13, 13, 0, 0, 0, 15, 15, 15, 15, 15, 15,
		15, 15, 0, 2, 0, 0, 0, 13, 13, 0, 13, 13, 0, 2, 2, 0, 15, 0, 15, 15, 15,
		15, 15, 0, 0, 2, 2, 2, 0, 13, 13, 13, 0, 0, 0, 2, 2, 0, 11, 0, 15, 15,
		15, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 11, 11, 0, 15, 15,
		15, 0, 0, 0, 0, 10, 10, 2, 0, 2, 2, 0, 0, 0, 3, 3, 3, 11, 0, 15, 15,
		0, 10, 0, 10, 10, 0, 10, 2, 0, 0, 0, 3, 11, 11, 11, 3, 3, 11, 11, 0, 15,
		0, 0, 10, 0, 2, 0, 2, 0, 11, 11, 11, 11, 3, 11, 11, 11, 11, 11, 3, 0, 15,
		0, 2, 2, 0, 0, 0, 0, 0, 0, 3, 11, 11, 11, 11, 3, 3, 11, 11, 3, 0, 0,
		15, 0, 0, 0, 3, 3, 3, 3, 0, 0, 3, 11, 11, 11, 3, 11, 11, 11, 11, 0, 0,
		15, 0, 15, 3, 3, 3, 3, 3, 3, 3, 11, 11, 0, 0, 11, 3, 11, 11, 11, 11, 0,
		15, 15, 0, 0, 0, 3, 0, 3, 3, 3, 3, 11, 15, 12, 0, 11, 11, 11, 11, 3, 0,
		15, 15, 15, 15, 15, 0, 3, 3, 3, 0, 3, 3, 15, 12, 12, 0, 11, 11, 3, 0, 15,
		15, 15, 15, 15, 15, 0, 3, 3, 3, 3, 0, 3, 3, 3, 3, 3, 3, 0, 0, 15, 15,
		15, 15, 15, 15, 15, 0, 15, 3, 15, 0, 0, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};

	m_chArrSprite[2] = new char[m_nWidth[2] * m_nHeight[2]]
	{
		15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 0, 13, 14, 14, 13, 0, 14, 14, 13, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 0, 12, 14, 14, 12, 12, 0, 0, 0, 12, 12, 13, 14, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 0, 12, 12, 0, 0, 0, 0, 14, 14, 14, 0, 0, 12, 12, 12, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 0, 0, 0, 14, 13, 0, 14, 14, 0, 0, 13, 13, 0, 0, 12, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 0, 12, 12, 13, 13, 13, 0, 12, 13, 13, 13, 14, 14, 12, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 0, 12, 12, 12, 14, 14, 0, 12, 12, 13, 13, 13, 12, 12, 12, 0, 10, 0, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 0, 0, 12, 12, 12, 12, 12, 0, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 15, 0, 15, 15, 15, 15,
		15, 0, 0, 2, 0, 0, 0, 0, 0, 0, 12, 12, 12, 0, 0, 0, 2, 10, 0, 10, 0, 0, 11, 0, 15, 15, 15,
		0, 10, 10, 0, 0, 2, 2, 2, 0, 2, 0, 0, 0, 2, 10, 0, 0, 10, 0, 0, 0, 11, 11, 0, 15, 15, 15,
		0, 0, 10, 0, 10, 10, 0, 2, 0, 0, 2, 0, 2, 2, 0, 0, 0, 0, 3, 11, 11, 11, 11, 0, 15, 15, 15,
		0, 10, 0, 10, 0, 2, 0, 0, 3, 0, 0, 0, 0, 0, 3, 11, 11, 11, 11, 11, 11, 11, 11, 11, 0, 15, 15,
		0, 2, 0, 10, 0, 0, 3, 3, 3, 0, 3, 3, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 3, 11, 0, 15,
		15, 0, 0, 0, 3, 3, 3, 0, 3, 0, 12, 12, 3, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 3, 0, 0,
		15, 15, 0, 15, 3, 3, 0, 3, 3, 3, 0, 12, 12, 11, 11, 11, 3, 3, 11, 11, 11, 11, 11, 11, 3, 0, 0,
		15, 15, 15, 0, 15, 3, 0, 3, 0, 3, 0, 3, 3, 3, 11, 0, 0, 11, 3, 11, 11, 11, 11, 11, 11, 11, 0,
		15, 15, 15, 15, 0, 0, 15, 0, 3, 3, 3, 3, 3, 3, 3, 15, 12, 0, 3, 11, 11, 11, 11, 11, 11, 0, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 3, 3, 3, 0, 3, 3, 3, 11, 15, 15, 0, 11, 11, 11, 11, 11, 0, 0, 15,
		15, 15, 15, 15, 15, 15, 0, 3, 3, 3, 3, 0, 0, 3, 3, 3, 3, 3, 11, 11, 11, 0, 11, 3, 0, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 15, 3, 3, 3, 3, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 0, 0, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 0, 15, 3, 15, 0, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};
}

void Poketmon_Bulbasaur::LevelUp(float fRemainExp)
{
	m_nLevel++;

	if (m_nLevel == 16)
	{
		m_nCurrentEvolutionStep = 1;

		m_nHP = 60 + 6 * (m_nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 62 + 6 * (m_nLevel - 1);
		m_nDefense = 63 + 6 * (m_nLevel - 1);
		m_nSpecialAttack = 80 + 8 * (m_nLevel - 1);
		m_nSpecialDefense = 80 + 8 * (m_nLevel - 1);
		m_nSpeed = 60 + 6 * (m_nLevel - 1);
		this->m_nCurrentExp = fRemainExp;
		m_nTotalExp = 100.0f + 10 * (m_nLevel - 1) + (m_nLevel - 1);
	}

	else if (m_nLevel == 32)
	{
		m_nCurrentEvolutionStep = 2;

		m_nHP = 80 + 8 * (m_nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 82 + 8 * (m_nLevel - 1);
		m_nDefense = 83 + 8 * (m_nLevel - 1);
		m_nSpecialAttack = 100 + 10 * (m_nLevel - 1) + (m_nLevel - 1);
		m_nSpecialDefense = 100 + 10 * (m_nLevel - 1) + (m_nLevel - 1);
		m_nSpeed = 80 + 8 * (m_nLevel - 1);
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

int Poketmon_Bulbasaur::Hit(int nSkillDamage, ESkillAttack_Type eSkillAttackType, ESkill_Type eSkillType)
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
		nDamage = (nSkillDamage * 2) / nDef;
		nEffect = 1;
		break;

	case ESkill_Type::WATER:
		nDamage = (nSkillDamage / 2) / nDef;
		nEffect = -1;
		break;

	case ESkill_Type::GRASS:
		nDamage = (nSkillDamage / 4) / nDef;
		nEffect = -1;
		break;

	case ESkill_Type::ELECTRIC:
		nDamage = (nSkillDamage / 2) / nDef;
		nEffect = -1;
		break;

	case ESkill_Type::FLYING:
		nDamage = (nSkillDamage * 2) / nDef;
		nEffect = 1;
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

int Poketmon_Bulbasaur::GetSkillDamage(int nSkillIndex)
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

bool Poketmon_Bulbasaur::IsEvolution()
{
	if (m_nLevel + 1 == 16 || m_nLevel + 1 == 32)
	{
		return true;
	}

	else
	{
		return false;
	}
}
