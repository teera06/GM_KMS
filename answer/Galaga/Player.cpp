#include "Player.h"

#include <ConsoleEngine/EngineCore.h>

#include <list>
#include <conio.h>

#include "ContentsEnum.h"
#include "Bullet.h"

void Player::Update()
{
	// SetCore(nullptr);

	IsFire = false;

	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	switch (Select)
	{
	case 'A':
	case 'a':
		AddPos(Left);
		break;
	case 'S':
	case 's':
		AddPos(Down);
		break;
	case 'W':
	case 'w':
		AddPos(Up);
		break;
	case 'D':
	case 'd':
		AddPos(Right);
		break;
	case 'Q':
	case 'q':
	{
		// Q를 누를때 총알 생성
		Bullet* NewBullet = GetCore()->CreateObject<Bullet>(GalagaUpdateType::Bullet, GalagaRenderType::Bullet); 
		NewBullet->SetPos(GetPos()); // 총알 위치 설정
		break;
	}
	case '1':
		GetCore()->EngineEnd(); // 1번 누르면 게임 종료
		break;
	default:
		break;
	}
}