#pragma once
#include "INPC.h"
#include "Poketmon_Charmander.h"
#include "Poketmon_Bulbasaur.h"
#include "Poketmon_Squirtle.h"
#include "Poketmon_Pikachu.h"
#include "Poketmon_Pidgey.h"
#include "Poketmon_Rattata.h"

class Npc : public INpc
{
protected:
	std::vector<Poketmon*> m_vPoketmon;
	std::vector<Poketmon*>::iterator m_viPoketmon;

	int m_nWidth;
	int m_nHeight;
	int m_nLevel;
	int m_nPoketmonIndex;
	char* m_chArrSprite;
	bool isCatch;

public:
	virtual void Init() PURE;
	virtual void SetLevel(int nLevel);

	std::vector<Poketmon*> GetPoketmonVector() { return m_vPoketmon; }
	Poketmon* GetPoketmon(int nIndex) { return m_vPoketmon.at(nIndex); }
	int GetPoketmonCount() { return m_vPoketmon.size(); }
	int GetPoketmonIndex() { return m_nPoketmonIndex; }
	int GetWidth() { return m_nWidth; }
	int GetHeight() { return m_nHeight; }
	char* GetSprite() { return m_chArrSprite; }
	
	void SetIsCatch(bool isCatch) { this->isCatch = isCatch; }
	void SetPoketmonIndex(int nIndex) { this->m_nPoketmonIndex = nIndex; }

	Npc();
	virtual ~Npc();
};

