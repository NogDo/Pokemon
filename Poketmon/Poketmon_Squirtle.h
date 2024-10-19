#pragma once
#include "Poketmon.h"

class Poketmon_Squirtle : public Poketmon
{
private:

public:
	void Init(int nLevel) override;
	void LevelUp(float fRemainExp) override;
	int Hit(int nSkillDamage, ESkillAttack_Type eSkillAttackType, ESkill_Type eSkillType) override;
	int GetSkillDamage(int nSkillIndex) override;
	bool IsEvolution() override;

	Poketmon_Squirtle(int nLevel);
	~Poketmon_Squirtle();
};