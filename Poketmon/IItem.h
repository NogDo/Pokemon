#pragma once
#include <Windows.h>
#include "Poketmon.h"

__interface IItem
{
public:
	virtual void Init() PURE;
	virtual bool Use(Poketmon* poketmon) PURE;
};