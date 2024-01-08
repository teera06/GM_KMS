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

int main()
{
    // 5�� �̻� �ɸ��� ����.
    LeckCheck; // �� �˻� 


    // ��üȭ �� ���� �Ҵ�
    ConsoleScreen NewScreen = ConsoleScreen(); // ConsoleScreen ��üȭ
    NewScreen.CreateScreen(/*&NewScreen => this, */20, 20); // �� ũ�� ���� (X,Y)

    Player NewPlayer; // Player ��üȭ
    // ����Ʈ �̴ϼȶ�����
    // int2 PlayerStartPos = { NewScreen.GetScreenX() / 2, NewScreen.GetScreenY() };
    NewPlayer.SetPos({ NewScreen.GetScreenX() / 2, NewScreen.GetScreenY() - 2 }); // �÷��̾� ��ġ ����

    // 2������ ������.
    // �����Ҵ� �Ұų�?
    // �������� �Ұų�?

    const int MonsterCount = NewScreen.GetScreenX() / 2; // ���� �� 

    ConsoleObject** ArrMonster = new ConsoleObject * [MonsterCount]; // ���� �� ��ŭ ConsoleObject �����Ҵ� (���� ������)
    // �޸� �׷�����
    for (int i = 0; i < MonsterCount; i++)
    {
        ArrMonster[i] = new Monster(); // ArrMoster[i]�� Monster�� ���� �Ҵ� 
        ArrMonster[i]->SetPos({ i, 0 }); // i���� ���� ��ġ ����
        ArrMonster[i]->SetRenderChar('&'); // ������ &
    }

    const int BulletCount = NewScreen.GetScreenY() * 2; // Y�� �������� źȯ ���� ����
    Bullet* NewBullet = new Bullet[BulletCount]; // ���� ź�� ������ŭ Bullet ���� �Ҵ�

    int CurBullet = 0; // �߻��� �Ѿ� ���� üũ��
    // ---------------------------------------

    // while ������ ������ ���� ���
    while (true)
    {
        // �и������� ����
        Sleep(100); // 0.1 �� ����

        NewPlayer.KeyInput(); // �÷��̾� Ű �Է�

        if (true == NewPlayer.GetIsEnd()) // GetIsEnd���� true�� �Ǹ� ���� ����
        {
            break;
        }

        if (true == NewPlayer.GetIsFire())
        {
            NewBullet[CurBullet].SetPos(NewPlayer.GetPos());
            NewBullet[CurBullet].Fire();
            // �Ѿ��� ������ �������� �ʴ�.
            ++CurBullet;

            if (BulletCount <= CurBullet)
            {
                CurBullet = 0;
            }

        }

        for (int i = 0; i < MonsterCount; i++)
        {
            NewScreen.SetChar(ArrMonster[i]);
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
