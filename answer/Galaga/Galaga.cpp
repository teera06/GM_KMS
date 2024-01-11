// Galaga.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <ConsoleEngine/ConsoleScreen.h>
#include <ConsoleEngine/EngineDebug.h>
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"

// �������� ���ϴ� ����� �����е��� ������ �ٸ����̰�
// �������� (�ƹ����� ����) ���� ���̰� ����⸸ �ȴ�.
// �̰����� �ɰ��� ������ �ֽ��ϴ�.

class Test
{
public:
    void TestFunction()
    {
        *Ptr = 20;
    }

public:
    int* Ptr;
};

int main()
{
    // 5�� �̻� �ɸ��� ����.
    LeckCheck;

    int Value = 0;
    Test NewTest;
    // int* Ptr = &Value;
    // *Ptr = 20;
    NewTest.Ptr = &Value;
    NewTest.TestFunction();

    ConsoleScreen NewScreen = ConsoleScreen();
    NewScreen.CreateScreen(/*&NewScreen => this, */20, 20);


    // 2������ ������.
    // �����Ҵ� �Ұų�?
    // �������� �Ұų�?

    const int MonsterCount = NewScreen.GetScreenX() / 2;

    // ���� ��ü�� �ɼ� �ִ�.
    // ���� Ŭ������ �ɼ� �ִ�.
    // �迭�̶�� �� ���� Ŭ������ �Ǿ�� �ϴ°� ��ü�����Դϴ�.
    // ũ�� �˼� ����.
    // ũ��??
    // �ڷᱸ���� ���� �ִ� �⺻�� ������ ���ؼ��� ���ø��� ������ �Ѵ�.
    //ConsoleObjectPtrArray Array;

    // �����迭�̵� �����迭�̵� �����ϱ� ¦�� ����.
    // 
    // 
    // ���� ���� ���� ���絵 ����� �մϴ�.
    std::vector<ConsoleObject*> AllObject;
    AllObject.reserve(1000);

    // ��ĳ����
    Player* NewPlayer = new Player();
    NewPlayer->SetPos({ NewScreen.GetScreenX() / 2, NewScreen.GetScreenY() - 2 });
    NewPlayer->SetAllObject(&AllObject);
    AllObject.push_back(NewPlayer);


    // ConsoleObject** ArrMonster = new ConsoleObject*[MonsterCount];
    for (int i = 0; i < MonsterCount; i++)
    {
        // ���� new�� �޴ٸ�
        Monster* NewMonsterPtr = new Monster();
        NewMonsterPtr->SetPos({ i, 0 });
        NewMonsterPtr->SetRenderChar('&');
        AllObject.push_back(NewMonsterPtr);
    }

    while (true)
    {
        // �и������� ����
        Sleep(100);

        for (size_t i = 0; i < AllObject.size(); i++)
        {
            AllObject[i]->Update();
        }

        for (size_t i = 0; i < AllObject.size(); i++)
        {
            NewScreen.SetChar(AllObject[i]);
        }

        if (true == NewPlayer->GetIsEnd())
        {
            break;
        }
        NewScreen.PrintScreen();
    }

    for (size_t i = 0; i < AllObject.size(); i++)
    {
        if (nullptr != AllObject[i])
        {
            delete AllObject[i];
            AllObject[i] = nullptr;
        }
    }
}

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
