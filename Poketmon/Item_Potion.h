#pragma once
#include "Item.h"

class Item_Potion : public Item
{
private:
	int m_nHealAmount;

public:
	void Init() override;
	bool Use(Poketmon* poketmon) override;

	Item_Potion();
	~Item_Potion();
};