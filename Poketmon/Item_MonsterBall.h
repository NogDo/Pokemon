#pragma once
#include "Item.h"

class Item_MonsterBall : public Item
{
private:

public:
	void Init() override;
	bool Use(Poketmon* poketmon) override;

	Item_MonsterBall();
	~Item_MonsterBall();
};