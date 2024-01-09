#include "Bullet.h"

Bullet::Bullet()
{
	SetRenderChar('|');
}

void Bullet::Move() // true 인경우 즉 발사한 상태에서만 실행
{
	if (false == IsFire)
	{
		return;
	}

	AddPos(Up); // 위로 이동
}