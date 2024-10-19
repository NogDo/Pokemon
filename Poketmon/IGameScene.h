#pragma once
#include <Windows.h>

__interface IGameScene
{
public:
	virtual void Init() PURE;
	virtual void Draw() PURE;
};