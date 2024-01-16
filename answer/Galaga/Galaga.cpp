// Galaga.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <ConsoleEngine/ConsoleScreen.h>
#include <ConsoleEngine/EngineDebug.h>
#include <list>
#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"

#include "ContentsEnum.h"
#include <ConsoleEngine/EngineCore.h>

int main()
{
    EngineCore EngineCore; // ���� �ھ� ���� 

    EngineCore.Init({ 20, 20 }); // Y,X ũ�� ����


    {
        // Player* NewObject = new Player();
        Player* NewObject = EngineCore.CreateObject<Player>(GalagaUpdateType::Player, GalagaRenderType::Player); // �÷��̾� ����
        NewObject->SetPos({ EngineCore.Screen.GetScreenX() / 2, EngineCore.Screen.GetScreenY() - 2 }); // Playe ��ġ ����
    }

    {
        const int MonsterCount = EngineCore.Screen.GetScreenX() / 2; // Monster ������
        for (int i = 0; i < MonsterCount; i++) // ���� ������ ��ŭ ���� ����
        {
            Monster* NewObject = EngineCore.CreateObject<Monster>(GalagaUpdateType::Monster, GalagaRenderType::Monster); // Monster Create (�ȿ��� �����Ҵ�)
            NewObject->SetPos({ i, 0 }); // ���� ���� ��ġ ����
            NewObject->SetRenderChar('&'); // ���� ������ ����
        }
    }

    EngineCore.Start(); // ���� ��ŸƮ

}