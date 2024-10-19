#pragma once
#include "Npc.h"

class NpcNurse : public Npc
{
private:

public:
	void Init() override;

	NpcNurse();
	~NpcNurse();
};