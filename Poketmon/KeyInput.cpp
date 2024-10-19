#include "KeyInput.h"

KeyInput::KeyInput()
{

}

KeyInput::~KeyInput()
{

}

/// <summary>
/// 키 입력 됐는지 확인 후 키 값 받아오기
/// </summary>
/// <returns></returns>
EKey_Type KeyInput::GetKey()
{
	if (_kbhit())
	{
		char c = _getch();
		EKey_Type key = static_cast<EKey_Type>(c);

		switch (key)
		{
		case EKey_Type::UP_ARROW:
			return EKey_Type::UP_ARROW;

		case EKey_Type::LEFT_ARROW:
			return EKey_Type::LEFT_ARROW;

		case EKey_Type::RIGHT_ARROW:
			return EKey_Type::RIGHT_ARROW;

		case EKey_Type::DOWN_ARROW:
			return EKey_Type::DOWN_ARROW;

		case EKey_Type::X:
			return EKey_Type::X;

		case EKey_Type::Z:
			return EKey_Type::Z;
		}
	}

	else
	{
		return EKey_Type::NONE;
	}
}
