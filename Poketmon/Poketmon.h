#pragma once
#include "IPoketmon.h"
#include "Skill.h"

class Poketmon : public IPoketmon
{
protected:
#pragma region 포켓몬 정보
	const char* m_strName[3];
	const char* m_strLearnSkillName;
	char* m_chArrSprite[3];
	int m_nWidth[3];
	int m_nHeight[3];
	int m_nCurrentEvolutionStep;
	int m_nHP;
	int m_nCurrentHP;
	int m_nAttack;
	int m_nDefense;
	int m_nSpecialAttack;
	int m_nSpecialDefense;
	int m_nSpeed;
	int m_nLevel;
	int m_nCurrentExp;
	int m_nTotalExp;
	bool m_isLearnSkill;
#pragma endregion

#pragma region 포켓몬 타입, 스킬, 배울 스킬
	std::vector<EPoketmon_Type> m_vePoketmonType;
	std::vector<Skill*> m_vSkill;
	std::vector<Skill*>::iterator m_viSkill;
	std::vector<std::pair<int, Skill*>> m_vSkillLearnLevel;
	std::vector<std::pair<int, Skill*>>::iterator m_viSkillLearnLevel;
#pragma endregion

	

public:
	virtual void Init(int nLevel) PURE;
	virtual void LevelUp(float fRemainExp) PURE;
	virtual int Hit(int nSkillDamage, ESkillAttack_Type eSkillAttackType, ESkill_Type eSkillType) PURE;
	virtual int GetSkillDamage(int nSkillIndex) PURE;
	virtual bool IsEvolution();

	const char* GetName() { return m_strName[m_nCurrentEvolutionStep]; }
	const char* GetLearnSkillName() { return m_strLearnSkillName; }
	char* GetSprite() { return m_chArrSprite[m_nCurrentEvolutionStep]; }
	int GetWidth() { return m_nWidth[m_nCurrentEvolutionStep]; }
	int GetHeight() { return m_nHeight[m_nCurrentEvolutionStep]; }
	int GetHP() { return m_nHP; }
	int GetCurrentHP() { return m_nCurrentHP; }
	int GetSkillCount() { return m_vSkill.size(); }
	int GetSpeed() { return m_nSpeed; }
	int GetLevel() { return m_nLevel; }
	int GetCurrnetExp() { return m_nCurrentExp; }
	int GetTotalExp() { return m_nTotalExp; }
	bool GetIsLearnSkill() { return m_isLearnSkill; }
	Skill* GetSkill(int nSkillIndex) { return m_vSkill.at(nSkillIndex); }
	std::vector<Skill*> GetSkillVector() { return m_vSkill; }

	void SetCurrentExp(int exp) { this->m_nCurrentExp = exp; }
	void SetCurrentHp(int hp) { this->m_nCurrentHP = hp; }


	Poketmon();
	virtual ~Poketmon();
};

