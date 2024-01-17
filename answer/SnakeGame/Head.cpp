#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"

// 
// 1. 내가 특정 방향으로 진행했다면 다음 입력때는 그 반대방향으로는 갈수가 없다.
//    내가 이동하는 방향의 반대방향으로는 가면 안된다.
// 2. 내가 이동을 해서 CurBody를 획득했다면 그 다음부터 그 바디는 나를 따라와야 한다.

void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	// X Y
	// 1 0
	headsave = GetPos(); // 이동하기전의 현재 헤드의 위치를 미리 저장한다.
	switch (Select)
	{
	case 'A':
	case 'a':
		dir = Left;
		if (nextdir != dir) { // 다음 누를 키와 현재키가 같아서는 안된다
			if ((GetPos() + dir).X != 0) // 다음 위치가 벽이 있는 위치가 아닌 경우에만 이동 가능
			{
				AddPos(dir);
				nextdir = Right; // Left인 경우 nextdir=Right 저장
			}
			else
			{
				return;
			}
		}
		else { // nextdir==dir이 같은 경우 리턴
			return;
		}
		break;
		// 아래도 같은 규칙 적용
	case 'S':
	case 's':
		dir = Down;
		if (nextdir != dir) {
			if ((GetPos() + dir).Y != y - 1)
			{
				AddPos(dir);
				nextdir = Up; 
			}
			else
			{
				return;
			}
		}
		else {
			return;
		}
		break;
	case 'W':
	case 'w':
		dir = Up;
		if (nextdir != dir) {
			if ((GetPos() + dir).Y != 0)
			{
				AddPos(dir);
				nextdir = Down; 
			}
			else
			{
				return;
			}
		}
		else {
			return;
		}
		break;
	case 'D':
	case 'd':
		dir = Right;
		if (nextdir != dir) {
			if ((GetPos() + dir).X != x-1)
			{
				AddPos(dir);
				nextdir = Left; 
			}
			else
			{
				return;
			}
		}
		else {
			return;
		}
		
		break;
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}

	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("먹을수 있는 바디가 존재하지 않습니다.");
		return;
	}

	if (Back!=nullptr) // Back이 nullptr이 아닌 경우 
	{
		std::list<Body*>::iterator StartIter = bodylist.begin();
		std::list<Body*>::iterator EndIter = bodylist.end();
		for (/*std::list<int>::iterator StartIter = NewList.begin()*/
			; StartIter != EndIter
			; ++StartIter) // 리스트에 들어 있는 수 만큼 리스트 순회
		{
			Back=*StartIter;
			bodysave = Back->GetPos(); // bodysave에 몸통의 현재 위치 저장(위치값이 변하기전에 미리 저장)
			Back->SetPos(headsave); // 현재 headsave의 위치값을 back(Curbody)에 적용
			headsave = bodysave; // headsave에 아까 저장한 몸통의 현재 위치를 저장
			// 작동 원리 
			// 이동할때 이동하기전의 위치를 다음 리스트에게 알려줘야 한다. -> 리스트 순회를 돌리며 마지막 순번까지 for문 반복
		}
	}

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos()) // 충돌이 일어날 경우
	{
		bodylist.push_back(CurBody); // list에 현재 생긴 몸통 부분을 저장
		
		// 헤드와 몸통 위치 변경
		Back = CurBody; 
		SetPos(Back->GetPos());  
		Back->SetPos(headsave);
		BodyManager::ResetBody();
	}

	

	

}