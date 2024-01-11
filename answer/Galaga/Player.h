#pragma once
#include <ConsoleEngine/ConsoleObject.h>
#include <vector>

class Player : public ConsoleObject
{
public:

	bool GetIsFire()
	{
		return IsFire;
	}

	bool GetIsEnd()
	{
		return IsGameEnd;
	}

	void SetAllObject(std::vector<ConsoleObject*>* _AllObjectPtr)
	{
		AllObjectPtr = _AllObjectPtr;
	}

protected:
	void Update() override;

private:
	std::vector<ConsoleObject*>* AllObjectPtr = nullptr;

	bool IsFire = false;
	bool IsGameEnd = false;
};

