#include "Bullet.h"

Bullet::Bullet()
{
	SetRenderChar('|');
}

void Bullet::Move() // true �ΰ�� �� �߻��� ���¿����� ����
{
	if (false == IsFire)
	{
		return;
	}

	AddPos(Up); // ���� �̵�
}