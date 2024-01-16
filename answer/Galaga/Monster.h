#pragma once
#include <ConsoleEngine/ConsoleObject.h>
#include <ConsoleEngine/EngineCore.h>
class Monster : public ConsoleObject
{
protected:
	void Update() override;

	int2 Dir = Right;
	int Value = 10;
	int count = 0;
};

