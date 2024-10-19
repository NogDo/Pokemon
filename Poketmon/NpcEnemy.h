#pragma once
#include "Npc.h"

class NpcEnemy : public Npc
{
private:

public:
	void Init() override;
	void SetLevel(int nLevel) override;

	NpcEnemy();
	~NpcEnemy();
};

