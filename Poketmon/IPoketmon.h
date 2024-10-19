#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <vector>
#include "SkillType.h"
#include "ConsoleColor.h"

enum class EPoketmon_Type : uint16_t
{
	FIRE,
	WATER,
	GRASS,
	ELECTRIC,
	FLYING,
	DARK,
	NORMAL
};

enum class EPoketmon_Number : uint16_t
{
	BULBASAUR,
	CHAMANDER,
	SQUIRTLE,
	PIKACHU,
	PIDGEY,
	RATTATA
};

__interface IPoketmon
{
public:
	virtual void Init(int nLevel) PURE;
	virtual void LevelUp(float fRemainExp) PURE;
	virtual int Hit(int nSkillDamage, ESkillAttack_Type eSkillAttackType, ESkill_Type eSkillType) PURE;
	virtual int GetSkillDamage(int nSkillIndex) PURE;
};