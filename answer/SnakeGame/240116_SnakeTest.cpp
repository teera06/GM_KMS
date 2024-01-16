// SnakeGame.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <ConsoleEngine/EngineCore.h>
#include "Head.h"

int main()
{
    EngineCore EngineCore;
    EngineCore.Init({ 20, 20 });

    {
        // Player* NewObject = new Player();
        Head* NewPlayer = EngineCore.CreateObject<Head>();
        NewPlayer->SetPos({ EngineCore.Screen.GetScreenX() / 2, EngineCore.Screen.GetScreenY() - 2 });
    }


    EngineCore.Start();
}
