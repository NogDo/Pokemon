#pragma once
#include "SkillType.h"

namespace FireSkill
{
	struct STEmber
	{
		const char* m_strName = "불꽃세례";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 25;
		ESkill_Type m_eSkillType = ESkill_Type::FIRE;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STFlameWheel
	{
		const char* m_strName = "화염 자동차";
		int m_nPower = 60;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 25;
		ESkill_Type m_eSkillType = ESkill_Type::FIRE;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STFlameThrower
	{
		const char* m_strName = "화염 방사";
		int m_nPower = 95;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 15;
		ESkill_Type m_eSkillType = ESkill_Type::FIRE;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};
}

namespace GrassSkill
{
	struct STVineWhip
	{
		const char* m_strName = "덩굴 채찍";
		int m_nPower = 35;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 10;
		ESkill_Type m_eSkillType = ESkill_Type::GRASS;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};

	struct STRazorLeaf
	{
		const char* m_strName = "잎날가르기";
		int m_nPower = 55;
		int m_nAccuracy = 95;
		int m_nSkillRemainCount = 25;
		ESkill_Type m_eSkillType = ESkill_Type::GRASS;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};

	struct STSolarBeam
	{
		const char* m_strName = "솔라빔";
		int m_nPower = 120;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 10;
		ESkill_Type m_eSkillType = ESkill_Type::GRASS;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};
}

namespace WaterSkill
{
	struct STBubble
	{
		const char* m_strName = "거품";
		int m_nPower = 20;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 30;
		ESkill_Type m_eSkillType = ESkill_Type::WATER;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STWaterGun
	{
		const char* m_strName = "물대포";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 25;
		ESkill_Type m_eSkillType = ESkill_Type::WATER;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STHydroPump
	{
		const char* m_strName = "하이드로펌프";
		int m_nPower = 120;
		int m_nAccuracy = 80;
		int m_nSkillRemainCount = 5;
		ESkill_Type m_eSkillType = ESkill_Type::WATER;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};
}

namespace ElectricSkill
{
	struct STThunderShock
	{
		const char* m_strName = "전기 쇼크";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 30;
		ESkill_Type m_eSkillType = ESkill_Type::ELECTRIC;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STThunderbolt
	{
		const char* m_strName = "10만 볼트";
		int m_nPower = 95;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 15;
		ESkill_Type m_eSkillType = ESkill_Type::ELECTRIC;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STThunder
	{
		const char* m_strName = "번개";
		int m_nPower = 120;
		int m_nAccuracy = 70;
		int m_nSkillRemainCount = 10;
		ESkill_Type m_eSkillType = ESkill_Type::ELECTRIC;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};
}

namespace FlyingSkill
{
	struct STGust
	{
		const char* m_strName = "바람일으키기";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 35;
		ESkill_Type m_eSkillType = ESkill_Type::FLYING;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STWingAttack
	{
		const char* m_strName = "날개 치기";
		int m_nPower = 60;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 35;
		ESkill_Type m_eSkillType = ESkill_Type::FLYING;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};
}

namespace DarkSkill
{
	struct STPursuit
	{
		const char* m_strName = "따라가 때리기";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 20;
		ESkill_Type m_eSkillType = ESkill_Type::DARK;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};
}

namespace NormalSkill
{
	struct STBodySlam
	{
		const char* m_strName = "몸통 박치기";
		int m_nPower = 35;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 30;
		ESkill_Type m_eSkillType = ESkill_Type::NORMAL;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};

	struct STQuickAttack
	{
		const char* m_strName = "전광석화";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 30;
		ESkill_Type m_eSkillType = ESkill_Type::NORMAL;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};

	struct STHyperFang
	{
		const char* m_strName = "필살 앞니";
		int m_nPower = 80;
		int m_nAccuracy = 90;
		int m_nSkillRemainCount = 15;
		ESkill_Type m_eSkillType = ESkill_Type::NORMAL;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};
}