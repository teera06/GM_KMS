// Galaga.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
    EngineCore EngineCore; // 엔진 코어 선언 

    EngineCore.Init({ 20, 20 }); // Y,X 크기 결정


    {
        // Player* NewObject = new Player();
        Player* NewObject = EngineCore.CreateObject<Player>(GalagaUpdateType::Player, GalagaRenderType::Player); // 플레이어 생성
        NewObject->SetPos({ EngineCore.Screen.GetScreenX() / 2, EngineCore.Screen.GetScreenY() - 2 }); // Playe 위치 설정
    }

    {
        const int MonsterCount = EngineCore.Screen.GetScreenX() / 2; // Monster 마리수
        for (int i = 0; i < MonsterCount; i++) // 몬스터 마리수 만큼 몬스터 생성
        {
            Monster* NewObject = EngineCore.CreateObject<Monster>(GalagaUpdateType::Monster, GalagaRenderType::Monster); // Monster Create (안에서 동적할당)
            NewObject->SetPos({ i, 0 }); // 몬스터 생성 위치 설정
            NewObject->SetRenderChar('&'); // 몬스터 랜더링 결정
        }
    }

    EngineCore.Start(); // 엔진 스타트

}