#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"

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
	headsave = GetPos(); // �̵��ϱ����� ���� ����� ��ġ�� �̸� �����Ѵ�.
	switch (Select)
	{
	case 'A':
	case 'a':
		dir = Left;
		if (nextdir != dir) { // ���� ���� Ű�� ����Ű�� ���Ƽ��� �ȵȴ�
			if ((GetPos() + dir).X != 0) // ���� ��ġ�� ���� �ִ� ��ġ�� �ƴ� ��쿡�� �̵� ����
			{
				AddPos(dir);
				nextdir = Right; // Left�� ��� nextdir=Right ����
			}
			else
			{
				return;
			}
		}
		else { // nextdir==dir�� ���� ��� ����
			return;
		}
		break;
		// �Ʒ��� ���� ��Ģ ����
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
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}

	if (Back!=nullptr) // Back�� nullptr�� �ƴ� ��� 
	{
		std::list<Body*>::iterator StartIter = bodylist.begin();
		std::list<Body*>::iterator EndIter = bodylist.end();
		for (/*std::list<int>::iterator StartIter = NewList.begin()*/
			; StartIter != EndIter
			; ++StartIter) // ����Ʈ�� ��� �ִ� �� ��ŭ ����Ʈ ��ȸ
		{
			Back=*StartIter;
			bodysave = Back->GetPos(); // bodysave�� ������ ���� ��ġ ����(��ġ���� ���ϱ����� �̸� ����)
			Back->SetPos(headsave); // ���� headsave�� ��ġ���� back(Curbody)�� ����
			headsave = bodysave; // headsave�� �Ʊ� ������ ������ ���� ��ġ�� ����
			// �۵� ���� 
			// �̵��Ҷ� �̵��ϱ����� ��ġ�� ���� ����Ʈ���� �˷���� �Ѵ�. -> ����Ʈ ��ȸ�� ������ ������ �������� for�� �ݺ�
		}
	}

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos()) // �浹�� �Ͼ ���
	{
		bodylist.push_back(CurBody); // list�� ���� ���� ���� �κ��� ����
		
		// ���� ���� ��ġ ����
		Back = CurBody; 
		SetPos(Back->GetPos());  
		Back->SetPos(headsave);
		BodyManager::ResetBody();
	}

	

	

}