#include "Inventory.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{
	m_viItem = m_vItem.begin();

	for (m_viItem; m_viItem != m_vItem.end(); ++m_viItem)
	{
		delete* m_viItem;
	}

	m_vItem.clear();
}

/// <summary>
/// 아이템 추가
/// </summary>
/// <param name="item"></param>
void Inventory::AddItem(Item* item)
{
	bool isExist = false;
	m_viItem = m_vItem.begin();

	for (m_viItem; m_viItem != m_vItem.end(); ++m_viItem)
	{
		if (strcmp((*m_viItem)->GetName(), item->GetName()) == 0)
		{
			(*m_viItem)->IncreaseRemainCount();
			isExist = true;
			break;
		}
	}

	if (!isExist)
	{
		m_vItem.push_back(item);
	}

	else
	{
		delete item;
	}
}

/// <summary>
/// 아이템 남은 개수 확인
/// </summary>
void Inventory::CheckItemRemainCount()
{
	m_viItem = m_vItem.begin();

	for (m_viItem; m_viItem != m_vItem.end();)
	{
		if ((*m_viItem)->GetRemainCount() == 0)
		{
			delete* m_viItem;
			m_viItem = m_vItem.erase(m_viItem);
			break;
		}

		else
		{
			++m_viItem;
		}
	}
}