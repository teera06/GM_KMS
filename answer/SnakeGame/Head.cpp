#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

// 
// 1. ���� Ư�� �������� �����ߴٸ� ���� �Է¶��� �� �ݴ�������δ� ������ ����.
//    ���� �̵��ϴ� ������ �ݴ�������δ� ���� �ȵȴ�.
// 2. ���� �̵��� �ؼ� CurBody�� ȹ���ߴٸ� �� �������� �� �ٵ�� ���� ����;� �Ѵ�.

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
	headsave = GetPos();
	switch (Select)
	{
	case 'A':
	case 'a':
		dir = Left;
		if (nextdir != dir) {
			AddPos(dir);
		
			nextdir = Right;
		}
		break;
	case 'S':
	case 's':
		dir = Down;
		if (nextdir != dir) {
			AddPos(dir);
			
			nextdir = Up;
		}
		break;
	case 'W':
	case 'w':
		dir = Up;
		if (nextdir != dir) {
			AddPos(dir);
			
			nextdir = Down;
		}
		break;
	case 'D':
	case 'd':
		dir = Right;
		if (nextdir != dir) {
			AddPos(dir);
			
			nextdir = Left;
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
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}

	if (Back!=nullptr)
	{
		Back->SetPos(headsave);

	}

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		Back= CurBody;
		this->SetPos(Back->GetPos());
		CurBody->SetPos(headsave);
		BodyManager::ResetBody();
	}

	

	

}