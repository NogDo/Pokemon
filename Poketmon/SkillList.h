#pragma once
#include "SkillType.h"

namespace FireSkill
{
	struct STEmber
	{
		const char* m_strName = "�Ҳɼ���";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 25;
		ESkill_Type m_eSkillType = ESkill_Type::FIRE;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STFlameWheel
	{
		const char* m_strName = "ȭ�� �ڵ���";
		int m_nPower = 60;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 25;
		ESkill_Type m_eSkillType = ESkill_Type::FIRE;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STFlameThrower
	{
		const char* m_strName = "ȭ�� ���";
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
		const char* m_strName = "���� ä��";
		int m_nPower = 35;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 10;
		ESkill_Type m_eSkillType = ESkill_Type::GRASS;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};

	struct STRazorLeaf
	{
		const char* m_strName = "�ٳ�������";
		int m_nPower = 55;
		int m_nAccuracy = 95;
		int m_nSkillRemainCount = 25;
		ESkill_Type m_eSkillType = ESkill_Type::GRASS;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};

	struct STSolarBeam
	{
		const char* m_strName = "�ֶ��";
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
		const char* m_strName = "��ǰ";
		int m_nPower = 20;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 30;
		ESkill_Type m_eSkillType = ESkill_Type::WATER;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STWaterGun
	{
		const char* m_strName = "������";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 25;
		ESkill_Type m_eSkillType = ESkill_Type::WATER;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STHydroPump
	{
		const char* m_strName = "���̵������";
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
		const char* m_strName = "���� ��ũ";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 30;
		ESkill_Type m_eSkillType = ESkill_Type::ELECTRIC;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STThunderbolt
	{
		const char* m_strName = "10�� ��Ʈ";
		int m_nPower = 95;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 15;
		ESkill_Type m_eSkillType = ESkill_Type::ELECTRIC;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STThunder
	{
		const char* m_strName = "����";
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
		const char* m_strName = "�ٶ�����Ű��";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 35;
		ESkill_Type m_eSkillType = ESkill_Type::FLYING;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::SPECIAL;
	};

	struct STWingAttack
	{
		const char* m_strName = "���� ġ��";
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
		const char* m_strName = "���� ������";
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
		const char* m_strName = "���� ��ġ��";
		int m_nPower = 35;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 30;
		ESkill_Type m_eSkillType = ESkill_Type::NORMAL;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};

	struct STQuickAttack
	{
		const char* m_strName = "������ȭ";
		int m_nPower = 40;
		int m_nAccuracy = 100;
		int m_nSkillRemainCount = 30;
		ESkill_Type m_eSkillType = ESkill_Type::NORMAL;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};

	struct STHyperFang
	{
		const char* m_strName = "�ʻ� �մ�";
		int m_nPower = 80;
		int m_nAccuracy = 90;
		int m_nSkillRemainCount = 15;
		ESkill_Type m_eSkillType = ESkill_Type::NORMAL;
		ESkillAttack_Type m_eSkillAttackType = ESkillAttack_Type::PHISICAL;
	};
}