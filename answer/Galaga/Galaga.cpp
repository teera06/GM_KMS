// Galaga.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <ConsoleEngine/ConsoleScreen.h>
#include <ConsoleEngine/EngineDebug.h>
#include "Player.h"
#include "Bullet.h"


int main()
{
    LeckCheck;

    ConsoleScreen NewScreen = ConsoleScreen();
    NewScreen.CreateScreen(/*&NewScreen => this, */30, 10);

    Player NewPlayer;

    const int BulletCount = 1000;
    Bullet* NewBullet = new Bullet[BulletCount];

    int CurBullet = 0;

    while (true)
    {
        // �и������� ����
        Sleep(100);

        NewPlayer.KeyInput();

        if (true == NewPlayer.GetIsFire())
        {
            NewBullet[CurBullet].SetPos(NewPlayer.GetPos());
            NewBullet[CurBullet].Fire();
            ++CurBullet;
        }

        for (int i = 0; i < BulletCount; i++)
        {
            if (false == NewBullet[i].GetIsFire())
            {
                continue;
            }

            NewBullet[i].Move();
            NewScreen.SetChar(NewBullet[i]);
        }

        NewScreen.SetChar(NewPlayer);
        NewScreen.PrintScreen();
    }

    if (NewBullet)
    {
        delete[] NewBullet;
        NewBullet = nullptr;
    }

    NewScreen.ReleaseScreen();
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
