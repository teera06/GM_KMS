#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Player : public ConsoleObject
{
public:
	void KeyInput();

	bool GetIsFire()
	{
		return IsFire;
	}

private:
	bool IsFire = false;
};

