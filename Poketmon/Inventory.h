#pragma once
#include <vector>
#include "Item.h"
#include "Item_MonsterBall.h"
#include "Item_Potion.h"

class Inventory
{
private:
	std::vector<Item*> m_vItem;
	std::vector<Item*>::iterator m_viItem;

public:
	std::vector<Item*> GetVector() { return m_vItem; }
	Item* GetItem(int nIndex) { return m_vItem.at(nIndex); }
	int GetItemTypeCount() { return m_vItem.size(); }

	void AddItem(Item* item);
	void CheckItemRemainCount();


	Inventory();
	~Inventory();
};

