#include "Poketmon_Charmander.h"

Poketmon_Charmander::Poketmon_Charmander(int nLevel)
{
	Init(nLevel);
}

Poketmon_Charmander::~Poketmon_Charmander()
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

void Poketmon_Charmander::Init(int nLevel)
{
	m_strName[0] = "파이리";
	m_strName[1] = "리자드";
	m_strName[2] = "리자몽";
	m_nWidth[0] = 21;
	m_nHeight[0] = 18;
	m_nWidth[1] = 22;
	m_nHeight[1] = 22;
	m_nWidth[2] = 30;
	m_nHeight[2] = 22;

	if (nLevel < 16)
	{
		m_nCurrentEvolutionStep = 0;

		m_nHP = 39 + 3 * (nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 52 + 5 * (nLevel - 1);
		m_nDefense = 43 + 4 * (nLevel - 1);
		m_nSpecialAttack = 60 + 6 * (nLevel - 1);
		m_nSpecialDefense = 50 + 5 * (nLevel - 1);
		m_nSpeed = 65 + 6 * (nLevel - 1);
		this->m_nLevel = nLevel;
		m_nCurrentExp = 0.0f;
		m_nTotalExp = 100.0f + 10 * (nLevel - 1) + (nLevel - 1);
		m_vePoketmonType.push_back(EPoketmon_Type::FIRE);
		m_isLearnSkill = false;
	}

	else if (nLevel < 36)
	{
		m_nCurrentEvolutionStep = 1;

		m_nHP = 58 + 8 * (nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 64 + 6 * (nLevel - 1);
		m_nDefense = 58 + 5 * (nLevel - 1);
		m_nSpecialAttack = 80 + 8 * (nLevel - 1);
		m_nSpecialDefense = 65 + 6 * (nLevel - 1);
		m_nSpeed = 80 + 8 * (nLevel - 1);
		this->m_nLevel = nLevel;
		m_nCurrentExp = 0.0f;
		m_nTotalExp = 100.0f + 10 * (nLevel - 1) + (nLevel - 1);
		m_vePoketmonType.push_back(EPoketmon_Type::FIRE);
		m_isLearnSkill = false;
	}

	else
	{
		m_nCurrentEvolutionStep = 2;

		m_nHP = 78 + 7 * (nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 84 + 8 * (nLevel - 1);
		m_nDefense = 78 + 7 * (nLevel - 1);
		m_nSpecialAttack = 109 + 10 * (nLevel - 1) + (nLevel - 1);
		m_nSpecialDefense = 85 + 8 * (nLevel - 1);
		m_nSpeed = 100 + 10 * (nLevel - 1) + (nLevel - 1);
		this->m_nLevel = nLevel;
		m_nCurrentExp = 0.0f;
		m_nTotalExp = 100.0f + 10 * (nLevel - 1) + (nLevel - 1);
		m_vePoketmonType.push_back(EPoketmon_Type::FIRE);
		m_vePoketmonType.push_back(EPoketmon_Type::FLYING);
		m_isLearnSkill = false;
	}

	NormalSkill::STBodySlam bodyslam;
	m_vSkill.push_back(new Skill(bodyslam.m_strName, bodyslam.m_nPower, bodyslam.m_nAccuracy,
		bodyslam.m_nSkillRemainCount, bodyslam.m_eSkillType, bodyslam.m_eSkillAttackType));

	FireSkill::STEmber ember;
	FireSkill::STFlameWheel flameWheel;
	FireSkill::STFlameThrower flameThrower;

	if (m_nLevel >= 7)
	{
		m_vSkill.push_back(new Skill(ember.m_strName, ember.m_nPower, ember.m_nAccuracy,
			ember.m_nSkillRemainCount, ember.m_eSkillType, ember.m_eSkillAttackType));
	}

	if (m_nLevel >= 19)
	{
		m_vSkill.push_back(new Skill(flameWheel.m_strName, flameWheel.m_nPower, flameWheel.m_nAccuracy,
			flameWheel.m_nSkillRemainCount, flameWheel.m_eSkillType, flameWheel.m_eSkillAttackType));
	}

	if (m_nLevel >= 31)
	{
		m_vSkill.push_back(new Skill(flameThrower.m_strName, flameThrower.m_nPower, flameThrower.m_nAccuracy,
			flameThrower.m_nSkillRemainCount, flameThrower.m_eSkillType, flameThrower.m_eSkillAttackType));
	}

	m_vSkillLearnLevel.push_back(std::make_pair(7, new Skill(ember.m_strName, ember.m_nPower, ember.m_nAccuracy,
		ember.m_nSkillRemainCount, ember.m_eSkillType, ember.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(19, new Skill(flameWheel.m_strName, flameWheel.m_nPower, flameWheel.m_nAccuracy,
		flameWheel.m_nSkillRemainCount, flameWheel.m_eSkillType, flameWheel.m_eSkillAttackType)));
	m_vSkillLearnLevel.push_back(std::make_pair(31, new Skill(flameThrower.m_strName, flameThrower.m_nPower, flameThrower.m_nAccuracy,
		flameThrower.m_nSkillRemainCount, flameThrower.m_eSkillType, flameThrower.m_eSkillAttackType)));

	m_chArrSprite[0] = new char[m_nWidth[0] * m_nHeight[0]]
	{
		15, 15, 15,  0, 15, 15, 15, 15, 15, 15, 15, 15, 15,  0,  0,  0,  0, 15, 15, 15, 15,
		15, 15,  0, 12,  0, 15, 15, 15, 15, 15, 15, 15,  0,  4,  4,  4,  4,  0, 15, 15, 15,
		15,  0, 12, 12,  0, 15, 15, 15, 15, 15, 15,  0,  4,  4,  4,  4,  4,  4,  0, 15, 15,
		15,  0, 12, 12,  0, 15, 15, 15, 15, 15, 15,  0,  4,  4,  4,  4,  4,  4,  0, 15, 15,
		 0, 12, 12, 12, 12,  0, 15, 15, 15, 15,  0,  4,  4,  4,  4,  4,  4,  4,  4,  0, 15,
		 0, 12, 14, 12, 12,  0, 15, 15, 15, 15,  0,  4,  4,  4,  0, 15,  4,  4,  4,  4,  0,
		 0, 12, 14, 14, 12,  0, 15, 15, 15,  0,  4,  4,  4,  4,  0,  0,  4,  4,  4,  4,  0,
		15,  0,  0, 14,  0, 15, 15, 15, 15,  0,  4,  4,  4,  4,  0,  0,  4,  4,  4,  4,  0,
		15, 15,  0,  4,  0, 15, 15, 15,  0,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  0, 15,
		15, 15,  0,  4,  4,  0, 15,  0,  4,  4,  4,  4,  4,  4,  4,  4,  4,  0,  0, 15, 15,
		15, 15, 15,  0,  4,  4,  0,  0,  4,  4,  4,  0,  4,  4,  0,  0,  0, 15, 15, 15, 15,
		15, 15, 15,  0,  4,  4,  0,  4,  4,  4,  4,  4,  0, 14, 14,  0, 15, 15, 15, 15, 15,
		15, 15, 15, 15,  0,  4,  0,  4,  4,  4,  0,  0, 14, 14, 14,  0, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15,  0,  0,  4,  4,  4,  4, 14, 14, 14,  0, 15,  0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15,  0,  0,  4,  4,  4, 14, 14,  0,  0,  0, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15,  0,  0,  4,  0,  0,  0, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15,  0, 15,  4, 15,  0, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 15,  0,  0,  0,  0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15
	};

	m_chArrSprite[1] = new char[m_nWidth[1] * m_nHeight[1]]
	{
		15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 12, 0, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 12, 12, 0, 15, 15, 0, 4, 4, 0, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 12, 12, 12, 0, 15, 15, 0, 4, 4, 4, 0, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 12, 12, 12, 0, 15, 15, 15, 0, 4, 4, 0, 0, 0, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 14, 12, 0, 15, 15, 15, 0, 0, 4, 4, 0, 4, 0, 15, 15, 15,
		15, 15, 15, 0, 0, 4, 14, 0, 15, 15, 15, 0, 4, 4, 4, 4, 4, 4, 4, 0, 15, 15,
		15, 15, 0, 0, 4, 4, 0, 15, 15, 15, 0, 4, 4, 4, 4, 4, 4, 4, 4, 0, 15, 15,
		15, 0, 4, 4, 4, 0, 15, 15, 15, 15, 0, 4, 4, 4, 0, 4, 4, 4, 4, 4, 0, 15,
		0, 4, 4, 4, 0, 15, 15, 15, 15, 0, 0, 4, 4, 4, 15, 0, 4, 4, 4, 4, 4, 0,
		0, 4, 4, 4, 0, 15, 15, 0, 0, 4, 4, 0, 4, 0, 15, 0, 0, 4, 4, 4, 4, 0,
		0, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 4, 4, 0, 15,
		0, 0, 4, 4, 4, 0, 4, 4, 4, 0, 4, 4, 4, 4, 0, 0, 4, 4, 0, 0, 15, 15,
		15, 0, 4, 4, 4, 4, 4, 4, 4, 0, 4, 4, 14, 14, 0, 0, 0, 0, 4, 4, 0, 15,
		15, 15, 0, 4, 0, 4, 4, 4, 4, 15, 0, 14, 14, 14, 0, 15, 15, 0, 4, 4, 15, 0,
		15, 15, 15, 0, 0, 4, 4, 4, 4, 4, 4, 0, 14, 0, 15, 15, 15, 15, 0, 15, 4, 0,
		15, 15, 15, 15, 0, 4, 4, 4, 4, 4, 15, 0, 14, 0, 0, 15, 15, 15, 15, 0, 0, 15,
		15, 15, 15, 15, 0, 0, 4, 4, 4, 0, 0, 14, 0, 4, 15, 0, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 0, 4, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 15, 4, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};

	m_chArrSprite[2] = new char[m_nWidth[2] * m_nHeight[2]]
	{
		15, 15, 15, 15, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 0, 12, 12, 12, 12, 12, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 0, 12, 14, 14, 12, 12, 12, 12, 12, 0, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15,
		15, 15, 0, 14, 14, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 15, 15, 15, 0, 4, 0, 15, 15, 15, 15, 15,
		15, 0, 4, 4, 0, 12, 12, 0, 0, 4, 4, 4, 0, 4, 4, 4, 4, 0, 0, 15, 15, 15, 0, 4, 0, 15, 15, 15, 15, 15,
		15, 0, 4, 0, 4, 0, 0, 4, 4, 13, 13, 4, 0, 4, 4, 4, 0, 0, 4, 0, 15, 15, 15, 0, 4, 0, 15, 15, 15, 15,
		0, 4, 4, 0, 0, 4, 4, 13, 13, 13, 13, 0, 4, 4, 4, 0, 15, 0, 4, 4, 0, 15, 15, 0, 4, 0, 15, 15, 15, 15,
		0, 4, 0, 4, 4, 13, 13, 13, 13, 13, 0, 0, 0, 4, 0, 15, 15, 15, 0, 4, 4, 0, 0, 0, 0, 4, 0, 15, 15, 15,
		15, 0, 4, 13, 13, 13, 13, 13, 13, 0, 0, 4, 4, 0, 0, 15, 15, 0, 0, 0, 4, 4, 0, 4, 4, 4, 0, 15, 15, 15,
		0, 4, 13, 13, 13, 13, 13, 13, 0, 13, 0, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 15, 15,
		15, 0, 0, 0, 0, 13, 13, 13, 13, 13, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 15, 15,
		0, 4, 4, 4, 4, 0, 0, 4, 13, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 4, 4, 0, 4, 4, 4, 4, 0, 15, 15,
		0, 0, 4, 4, 0, 4, 4, 4, 0, 4, 0, 4, 0, 4, 4, 4, 4, 0, 15, 0, 4, 4, 15, 0, 4, 4, 4, 4, 0, 15,
		15, 0, 4, 4, 0, 4, 4, 4, 0, 4, 4, 0, 15, 0, 4, 4, 0, 15, 15, 15, 0, 4, 15, 0, 0, 4, 4, 4, 4, 0,
		15, 15, 0, 0, 4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 0, 0, 4, 0, 15, 15, 15, 0, 0, 4, 4, 4, 4, 4, 4, 0,
		15, 15, 15, 0, 4, 4, 4, 4, 4, 4, 0, 4, 4, 15, 0, 4, 4, 0, 15, 15, 15, 15, 15, 0, 0, 4, 4, 4, 0, 15,
		15, 15, 15, 0, 4, 4, 4, 4, 4, 0, 4, 0, 0, 0, 4, 4, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15,
		15, 15, 15, 15, 0, 4, 4, 4, 4, 4, 0, 14, 14, 4, 0, 0, 4, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 0, 4, 4, 4, 4, 4, 0, 4, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 4, 4, 4, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 0, 4, 15, 4, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	};
}

int Poketmon_Charmander::GetSkillDamage(int nSkillIndex)
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

int Poketmon_Charmander::Hit(int nSkillDamage, ESkillAttack_Type eSkillAttackType, ESkill_Type eSkillType)
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
		nDamage = (nSkillDamage * 2) / nDef;
		nEffect = 1;
		break;

	case ESkill_Type::GRASS:
		nDamage = (nSkillDamage / 2) / nDef;
		nEffect = -1;
		break;

	case ESkill_Type::ELECTRIC:
		nDamage = nSkillDamage / nDef;
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

void Poketmon_Charmander::LevelUp(float fRemainExp)
{
	m_nLevel++;

	if (m_nLevel == 16)
	{
		m_nCurrentEvolutionStep = 1;

		m_nHP = 58 + 8 * (m_nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 64 + 6 * (m_nLevel - 1);
		m_nDefense = 58 + 5 * (m_nLevel - 1);
		m_nSpecialAttack = 80 + 8 * (m_nLevel - 1);
		m_nSpecialDefense = 65 + 6 * (m_nLevel - 1);
		m_nSpeed = 80 + 8 * (m_nLevel - 1);
		this->m_nCurrentExp = fRemainExp;
		m_nTotalExp = 100.0f + 10 * (m_nLevel - 1) + (m_nLevel - 1);
	}

	else if (m_nLevel == 36)
	{
		m_nCurrentEvolutionStep = 2;

		m_nHP = 78 + 7 * (m_nLevel - 1);
		m_nCurrentHP = m_nHP;
		m_nAttack = 84 + 8 * (m_nLevel - 1);
		m_nDefense = 78 + 7 * (m_nLevel - 1);
		m_nSpecialAttack = 109 + 10 * (m_nLevel - 1) + (m_nLevel - 1);
		m_nSpecialDefense = 85 + 8 * (m_nLevel - 1);
		m_nSpeed = 100 + 10 * (m_nLevel - 1) + (m_nLevel - 1);
		this->m_nCurrentExp = fRemainExp;
		m_nTotalExp = 100.0f + 10 * (m_nLevel - 1) + (m_nLevel - 1);
		m_vePoketmonType.push_back(EPoketmon_Type::FLYING);
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

bool Poketmon_Charmander::IsEvolution()
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