#pragma once
#include "IItem.h"

class Item : public IItem
{
protected:
	const char* m_chName;

	char* m_chArrSprite;
	char* m_chArrStringSprite;

	int m_nWidth;
	int m_nHeight;
	int m_StringWidth;
	int m_StringHeight;
	int m_nPrice;
	int m_nRemainCount;

public:
	virtual void Init() PURE;
	virtual bool Use(Poketmon* poketmon) PURE;

	const char* GetName() { return m_chName; }
	char* GetSprite() { return m_chArrSprite; }
	char* GetStringSprite() { return m_chArrStringSprite; }
	int GetWidth() { return m_nWidth; }
	int GetHeight() { return m_nHeight; }
	int GetStringWidth() { return m_StringWidth; }
	int GetStringHeight() { return m_StringHeight; }
	int GetPrice() { return m_nPrice; }
	int GetRemainCount() { return m_nRemainCount; }

	void IncreaseRemainCount() { this->m_nRemainCount++; }
	void DecreaseRamainCount() { this->m_nRemainCount--; }

	Item();
	virtual ~Item();
};