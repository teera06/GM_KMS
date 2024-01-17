// SnakeGame.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <ConsoleEngine/EngineCore.h>
#include "Head.h"
#include "BodyManager.h"
#include "GlobalValue.h"
#include "Wall.h"

enum class SnakeOrder
{
    Body,
    Head,
};

int main()
{
    EngineCore EngineCore;
    EngineCore.Init({ 20, 20 });

    {
        Wall* NewWall; // �� ����
        for (int y = 0; y < EngineCore.Screen.GetScreenY(); y++)
        {
            for (int x = 0; x < EngineCore.Screen.GetScreenX(); x++)
            {
                if (y == 0 || x == 0 || y == EngineCore.Screen.GetScreenY() - 1 || x == EngineCore.Screen.GetScreenX() - 1)
                {
                    NewWall = EngineCore.CreateObject<Wall>();
                    NewWall->SetPos({x,y});
                    NewWall->SetRenderChar('!');

                }
            }
        }
    }

    {
        // Player* NewObject = new Player();
        GBodyManager = EngineCore.CreateManager<BodyManager>(0);
    }

    { 
        // Player* NewObject = new Player();
        Head* NewPlayer = EngineCore.CreateObject<Head>();
        NewPlayer->SetPos({ EngineCore.Screen.GetScreenX() / 2, EngineCore.Screen.GetScreenY() - 2 });
        NewPlayer->Setscreenxy(EngineCore.Screen.GetScreenX(), EngineCore.Screen.GetScreenY()); // ��ũ�� x,y ũ�� �ޱ�
    }

    EngineCore.Start();
}
