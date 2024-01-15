#include "Monster.h"
#include "ContentsEnum.h"


void Monster::Update()
{
	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (nullptr != CollisionObject)
	{
		Destroy();
		CollisionObject->Destroy();
	}

	//AddPos(Right);

	// {1.0 }
	// Dir
	AddPos(Dir);

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
		Value = 10;
		AddPos(Down);
	}
}