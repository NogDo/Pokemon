#include "Skill.h"

Skill::Skill(const char* strName, int nPower, int nAccuracy, int nSkillRemainCount, ESkill_Type eSkillType, ESkillAttack_Type eSkillAttackType)
{
	this->m_strName = strName;
	this->m_nPower = nPower;
	this->m_nAccuracy = nAccuracy;
	this->m_nSkillRemainCount = nSkillRemainCount;
	this->m_eSkillType = eSkillType;
	this->m_eSkillAttackType = eSkillAttackType;
}

Skill::~Skill()
{

}