// Galaga.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ConsoleEngine/ConsoleScreen.h>
#include <ConsoleEngine/EngineDebug.h>
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"

// 선생님이 말하는 대충과 여러분들의 대충이 다를것이고
// 선생님이 (아무문제 없이) 눈에 보이게 만들기만 된다.
// 이게임은 심각한 문제가 있습니다.

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
    // 5분 이상 걸릴수 없다.
    LeckCheck;

    int Value = 0;
    Test NewTest;
    // int* Ptr = &Value;
    // *Ptr = 20;
    NewTest.Ptr = &Value;
    NewTest.TestFunction();

    ConsoleScreen NewScreen = ConsoleScreen();
    NewScreen.CreateScreen(/*&NewScreen => this, */20, 20);


    // 2가지로 나뉜다.
    // 동적할당 할거냐?
    // 정적으로 할거냐?

    const int MonsterCount = NewScreen.GetScreenX() / 2;

    // 모든건 객체가 될수 있다.
    // 모든건 클래스가 될수 있다.
    // 배열이라는 것 조차 클래스가 되어야 하는게 객체지향입니다.
    // 크기 알수 없다.
    // 크기??
    // 자료구조를 배울수 있는 기본을 익히기 위해서는 템플릿을 익혀야 한다.
    //ConsoleObjectPtrArray Array;

    // 동적배열이든 정적배열이든 불편하기 짝이 없다.
    // 
    // 
    // 깊은 복사 얕은 복사도 배워야 합니다.
    std::vector<ConsoleObject*> AllObject;
    AllObject.reserve(1000);

    // 업캐스팅
    Player* NewPlayer = new Player();
    NewPlayer->SetPos({ NewScreen.GetScreenX() / 2, NewScreen.GetScreenY() - 2 });
    NewPlayer->SetAllObject(&AllObject);
    AllObject.push_back(NewPlayer);


    // ConsoleObject** ArrMonster = new ConsoleObject*[MonsterCount];
    for (int i = 0; i < MonsterCount; i++)
    {
        // 내가 new를 햇다면
        Monster* NewMonsterPtr = new Monster();
        NewMonsterPtr->SetPos({ i, 0 });
        NewMonsterPtr->SetRenderChar('&');
        AllObject.push_back(NewMonsterPtr);
    }

    while (true)
    {
        // 밀리세컨드 단위
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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
