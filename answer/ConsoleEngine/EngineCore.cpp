#include "EngineCore.h"
#include "EngineDebug.h"

void EngineCore::Init(int2 _ScreenSize) // ȭ�� ũ�� ����
{
    LeakCheck; // �� üũ

    Screen.CreateScreen(/*&NewScreen => this, */_ScreenSize.Y, _ScreenSize.X); // ȭ�� ũ�� ����
}

void EngineCore::Start()
{
    while (EngineUpdate)
    {
        // �и������� ����
        Sleep(100); // 0.1 �� ����

        // ������Ʈ
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin(); 
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter) // �� ��ȯ
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second; // ���� value�� : list���� ����

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                for (; StartIter != EndIter; ++StartIter) // ����Ʈ ��ȯ
                {
                    ConsoleObject* Object = *StartIter; // ������Ʈ�� ���� ����

                    if (nullptr == Object) // ������Ʈ�� ���� ��츦 �˻�
                    {
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    Object->Update(); // ������Ʈ �� �÷��̾��� ������, ������ ������, �Ѿ��� �������� �ݺ��� �ȿ��� ������Ʈ
                }
            }
        }

        // ������
        {// ������Ʈ�� ���� ����
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
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    Screen.SetChar(Object); // ������Ʈ�� ��ġ�� �������� ȭ�鿡 ������
                }
            }
        }

        Screen.PrintScreen(); // ȭ�� ���


        //// ���� ������ ����
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllRenderObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllRenderObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // ����Ʈ�� ���� ����� ���ž� �մϴ�.
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
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    // ��带 �����.
                    StartIter = ObjectList.erase(StartIter); 
                }
            }
        }

        //// ������Ʈ ������ ����
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // ����Ʈ�� ���� ����� ���ž� �մϴ�.
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
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    //  ���� ���� ������ ������Ʈ�� ����Ű�� �ֱ⿡ ������ ������ ���������� ��常 �����ְ� ���� ����Ǵ� ������Ʈ ������ ���������� ���� ������Ʈ�� ����� ����Ű�� �ִ� ��带 �����.
                    delete Object;
                    Object = nullptr;

                    // ��带 �����.
                    StartIter = ObjectList.erase(StartIter);
                }
            }
        }
    }

    {// �ݺ��� Ż����
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // ����Ʈ�� ���� ����� ���ž� �մϴ�.
                for (; StartIter != EndIter; ++StartIter) // ����Ʈ �� ����
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
        AllUpdateObject.clear(); // �� �� ����
    }
}