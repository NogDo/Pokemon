#pragma once
#include "Npc.h"

class NpcBoss : public Npc
{
private:

public:
	void Init() override;

	bool IsCanFight();

	NpcBoss();
	~NpcBoss();
};

