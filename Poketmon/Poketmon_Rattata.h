#pragma once
#include "Poketmon.h"

class Poketmon_Rattata : public Poketmon
{
private:

public:
	void Init(int nLevel) override;
	void LevelUp(float fRemainExp) override;
	int Hit(int nSkillDamage, ESkillAttack_Type eSkillAttackType, ESkill_Type eSkillType) override;
	int GetSkillDamage(int nSkillIndex) override;
	bool IsEvolution() override;

	Poketmon_Rattata(int nLevel);
	~Poketmon_Rattata();
};

