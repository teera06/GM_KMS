#include "EngineCore.h"
#include "EngineDebug.h"

void EngineCore::Init(int2 _ScreenSize) // 화면 크기 생성
{
    LeakCheck; // 릭 체크

    Screen.CreateScreen(/*&NewScreen => this, */_ScreenSize.Y, _ScreenSize.X); // 화면 크기 생성
}

void EngineCore::Start()
{
    while (EngineUpdate)
    {
        // 밀리세컨드 단위
        Sleep(100); // 0.1 초 정지

        // 업데이트
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin(); 
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter) // 맵 순환
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second; // 맵의 value값 : list값을 받음

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                for (; StartIter != EndIter; ++StartIter) // 리스트 순환
                {
                    ConsoleObject* Object = *StartIter; // 오브젝트의 값을 받음

                    if (nullptr == Object) // 오브젝트가 없는 경우를 검사
                    {
                        MsgBoxAssert("오브젝트가 nullptr인 경우가 존재합니다.");
                    }

                    Object->Update(); // 오브젝트 즉 플레이어의 움직임, 몬스터의 움직임, 총알의 움직음을 반복문 안에서 업데이트
                }
            }
        }

        // 랜더링
        {// 업데이트랑 같은 원리
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllRenderObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllRenderObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                for (; StartIter != EndIter; ++StartIter)
                {
                    ConsoleObject* Object = *StartIter;

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("오브젝트가 nullptr인 경우가 존재합니다.");
                    }

                    Screen.SetChar(Object); // 오브젝트의 위치와 랜더링을 화면에 보여줌
                }
            }
        }

        Screen.PrintScreen(); // 화면 출력


        //// 랜더 릴리즈 구조
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllRenderObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllRenderObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // 리스트의 삭제 방식을 배우셔야 합니다.
                for (; StartIter != EndIter; )
                {
                    ConsoleObject* Object = *StartIter;

                    if (false == Object->IsPendingKill())
                    {
                        ++StartIter;
                        continue;
                    }

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("오브젝트가 nullptr인 경우가 존재합니다.");
                    }

                    // 노드를 지운것.
                    StartIter = ObjectList.erase(StartIter); 
                }
            }
        }

        //// 업데이트 릴리즈 구조
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // 리스트의 삭제 방식을 배우셔야 합니다.
                for (; StartIter != EndIter; )
                {
                    ConsoleObject* Object = *StartIter;

                    if (false == Object->IsPendingKill())
                    {
                        ++StartIter;
                        continue;
                    }

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("오브젝트가 nullptr인 경우가 존재합니다.");
                    }

                    //  같이 힙에 생성된 오브젝트를 가리키고 있기에 랜더링 릴리즈 구조에서는 노드만 지워주고 그후 실행되는 업데이트 릴리즈 구조에서는 먼저 오브젝트를 지우고 가리키고 있던 노드를 지운다.
                    delete Object;
                    Object = nullptr;

                    // 노드를 지운것.
                    StartIter = ObjectList.erase(StartIter);
                }
            }
        }
    }

    {// 반복문 탈출후
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // 리스트의 삭제 방식을 배우셔야 합니다.
                for (; StartIter != EndIter; ++StartIter) // 리스트 릭 정리
                {
                    ConsoleObject* Object = *StartIter;
                    if (nullptr != Object)
                    {
                        delete Object;
                        Object = nullptr;
                    }
                }
            }
        }
        AllUpdateObject.clear(); // 맵 릭 정리
    }
}