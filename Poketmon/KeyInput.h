#pragma once
#include <conio.h>

enum class EKey_Type
{
	NONE = 0,
	ENTER = 13,
	UP_ARROW = 72,
	LEFT_ARROW = 75,
	RIGHT_ARROW = 77,
	DOWN_ARROW = 80,
	X = 120,
	Z = 122
};

class KeyInput
{
private:

public:
	EKey_Type GetKey();

	KeyInput();
	~KeyInput();
};

