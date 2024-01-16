#include "Monster.h"
#include "ContentsEnum.h"
#include <iostream>

void Monster::Update()
{
	ConsoleObject* CollisionObject1 = Collision(GalagaUpdateType::Bullet);
	ConsoleObject* CollisionObject2 = Collision(GalagaUpdateType::Player);

	if (nullptr != CollisionObject1)
	{
		Destroy();
		CollisionObject1->Destroy();
	}

	if (nullptr != CollisionObject2)
	{
		Destroy();
		CollisionObject2->Destroy();
		GetCore()->EngineEnd();
	}

	//AddPos(Right);

	// {1.0 }
	// Dir
	--Value;
	if (0 >= Value) // 0Àº ´Ù¿î
	{
		if (Dir == Right)
		{
			Dir = Left;
		}
		else {
			Dir = Right;
		}
		Value = 11;
		AddPos(Down);
		++count;

		if (count == 19)
		{
			GetCore()->EngineEnd();
		}
	}
	else {
		AddPos(Dir);
	}
}