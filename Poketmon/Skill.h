#pragma once
#include "SKillList.h"

class Skill
{
private:
	const char* m_strName;
	int m_nPower;
	int m_nAccuracy;
	int m_nSkillRemainCount;
	ESkill_Type m_eSkillType;
	ESkillAttack_Type m_eSkillAttackType;

public:
	const char* GetName() { return m_strName; }
	int GetPower() { return m_nPower; }
	int GetAccuracy() { return m_nAccuracy; }
	int GetSkillRemainCount() { return m_nSkillRemainCount; }
	ESkill_Type GetSkillType() { return m_eSkillType; }
	ESkillAttack_Type GetSkillAttackType() { return m_eSkillAttackType; }

	void DecreaseSkillRemainCount() { m_nSkillRemainCount--; }
	void SetSkillRemainCount(int nCount) { this->m_nSkillRemainCount = nCount; }

	Skill(const char* strName, int nPower, int nAccuracy, int nSkillRemainCount, ESkill_Type eSkillType, ESkillAttack_Type eSkillAttackType);
	~Skill();
};

